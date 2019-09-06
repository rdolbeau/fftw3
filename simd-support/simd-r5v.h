/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
 *
 * RISC-V V support implemented by Romain Dolbeau. (c) 2017 Romain Dolbeau
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#if defined(FFTW_LDOUBLE) || defined(FFTW_QUAD)
#error "RISC-V V vector instructions only works in single or double precision"
#endif

#ifdef FFTW_SINGLE
#  define DS(d,s) s /* single-precision option */
#  define TYPE(name) __builtin_epi_ ## name ## _2xf32
#  define TYPESUF(name,suf) name ## _f32 ## suf
#else /* !FFTW_SINGLE */
#  define DS(d,s) d /* double-precision option */
#  define TYPE(name) __builtin_epi_ ## name ## _1xf64
#  define TYPESUF(name,suf) name ## _f64 ## suf
#endif /* FFTW_SINGLE */

#define SIMD_SUFFIX  _r5v  /* for renaming */
/* FIXME: this hardwire to 512 bits */
#define R5V_SIZE 512
#define VL DS(4, 8)        /* SIMD complex vector length */
#define SIMD_VSTRIDE_OKA(x) ((x) == 2) 
#define SIMD_STRIDE_OKPAIR SIMD_STRIDE_OK

//#if defined(__GNUC__) && !defined(???) /* sanity check */
//#error "compiling simd-r5v.h without RISC-V V support"
//#endif

typedef DS(__epi_1xf64, __epi_2xf32) V;

//##define VLIT(re, im) DS(svdupq_n_f64(re,im),svdupq_n_f32(re,im,re,im))
#ifdef FFTW_SINGLE
#error "VLIT F32 TODO"
#else
static inline V VLIT(const R re, const R im) {
  __epi_1xi64 idx = __builtin_epi_vid_1xi64(VL); // (0, 1, 2, 3, ...)
  __epi_1xi64 vone = __builtin_epi_vbroadcast_1xi64(1, 2*VL);
  __epi_1xf64 vre = __builtin_epi_vbroadcast_1xf64(re, 2*VL);
  __epi_1xf64 vim = __builtin_epi_vbroadcast_1xf64(im, 2*VL);
  __epi_1xi64 mask = __builtin_epi_vand_1xi64(idx, vone, 2*VL); // (0, 1, 0, 1, 0, ...)
  __epi_1xi1 mmask = __builtin_epi_cast_1xi1_1xi64(mask); // idem, as mask
  return  (__epi_1xf64)__builtin_epi_vmerge_1xi64((__epi_1xi64)vre, (__epi_1xi64)vim, mmask, 2*VL);
}
#endif

#define VLIT1(val) TYPE(vbroadcast)(val, 2*VL)
#define LDK(x) x
#define DVK(var, val) V var = VLIT1(val)
#define VZERO VLIT1(DS(0.,0.f))
#define VRONE VLIT(DS(1.,1.f),DS(0.,0.f))
#define VCI VLIT(DS(0.,0.f),DS(1.,1.f))
#define VCONEMI VLIT(DS(1.,1.f),DS(-1.,-1.f))
#define VONE  VLIT1(DS(1.,1.f))
#define VMINUSONE VLIT1(DS(-1.,-1.f))

static inline V VDUPL(const V x) {
	__epi_1xi64 idx = __builtin_epi_vid_1xi64(VL); // (0, 1, 2, 3, ...)
	__epi_1xi64 vnotone = __builtin_epi_vbroadcast_1xi64(~1ull, 2*VL);
	__epi_1xi64 hidx = __builtin_epi_vand_1xi64(idx, vnotone, 2*VL); // (0, 0, 2, 2, ...)
	return __builtin_epi_vrgather_1xf64(x, hidx, 2*VL);
}
static inline V VDUPH(const V x) {
	__epi_1xi64 idx = __builtin_epi_vid_1xi64(VL); // (0, 1, 2, 3, ...)
	__epi_1xi64 vone = __builtin_epi_vbroadcast_1xi64(1, 2*VL);
	__epi_1xi64 hidx = __builtin_epi_vor_1xi64(idx, vone, 2*VL); // (1, 1, 3, 3, ...)
	return __builtin_epi_vrgather_1xf64(x, hidx, 2*VL);
}


#ifdef FFTW_SINGLE
#error "FLIP_RI F32 TODO"
#define FLIP_RI(x) svreinterpret_f32_u64(svrevw_u64_z(ALLA,svreinterpret_u64_f32(x)))
#else
static inline V FLIP_RI(const V x) {
	__epi_1xi64 idx = __builtin_epi_vid_1xi64(VL); // (0, 1, 2, 3, ...)
	__epi_1xi64 vone = __builtin_epi_vbroadcast_1xi64(1, 2*VL);
	__epi_1xi64 hidx = __builtin_epi_vxor_1xi64(idx, vone, 2*VL); // (1, 0, 3, 2, ...)
	return __builtin_epi_vrgather_1xf64(x, hidx, 2*VL);
}
#endif
#ifdef FFTW_SINGLE
#error "VCONJ F32 TODO"
#else
static inline V VCONJ(const V x) {
	__epi_1xi64 idx = __builtin_epi_vid_1xi64(VL); // (0, 1, 2, 3, ...)
	__epi_1xi64 vone = __builtin_epi_vbroadcast_1xi64(1, 2*VL);
	__epi_1xi64 hidx = __builtin_epi_vand_1xi64(idx, vone, 2*VL); // (0, 1, 0, 1, 0, 1)
	return __builtin_epi_vfsgnjn_1xf64_mask(x, x, x, __builtin_epi_cast_1xi1_1xi64(hidx), 2*VL);
}
#endif

/* can probably be done better */
static inline V VBYI(V x)
{
  x = VCONJ(x);
  x = FLIP_RI(x);
  return x;
}


#define VNEG(a)   TYPE(vfsgnjn)(a,a,2*VL)
#define VADD(a,b) TYPE(vfadd)(a,b,2*VL)
#define VSUB(a,b) TYPE(vfsub)(a,b,2*VL)
#define VMUL(a,b) TYPE(vfmul)(a,b,2*VL)
#define VFMA(a, b, c)  TYPE(vfmacc)(c,a,b,2*VL) // or vfmadd
#define VFMS(a, b, c)  TYPE(vfmsac)(c,a,b,2*VL)
//#define VFNMS(a, b, c) TYPE(vfnmsac)(c,a,b,2*VL)  // or vfnmsub
#define VFNMS(a, b, c) VNEG(VFMS(a, b, c)) // workaround until vfmsac is implemented
#define VFMAI(b, c) VADD(c, VBYI(b)) // fixme: improve
#define VFNMSI(b, c) VSUB(c, VBYI(b)) // fixme: improve
#define VFMACONJ(b,c)  VADD(VCONJ(b),c) // fixme: improve
#define VFMSCONJ(b,c)  VFMACONJ(b,VNEG(c)) // fixme: improve
#define VFNMSCONJ(b,c) VNEG(VFMSCONJ(b,c)) // fixme: improve

static inline V VZMUL(V tx, V sr) // fixme: improve
{
  V tr = VDUPL(tx);
  V ti = VDUPH(tx);
  tr = VMUL(sr, tr);
  sr = VBYI(sr);
  return VFMA(ti, sr, tr);
}

static inline V VZMULJ(V tx, V sr) // fixme: improve
{
  V tr = VDUPL(tx);
  V ti = VDUPH(tx);
  tr = VMUL(sr, tr);
  sr = VBYI(sr);
  return VFNMS(ti, sr, tr);
}

static inline V VZMULI(V tx, V sr) // fixme: improve
{
  V tr = VDUPL(tx);
  V ti = VDUPH(tx);
  ti = VMUL(ti, sr);
  sr = VBYI(sr);
  return VFMS(tr, sr, ti);
}

static inline V VZMULIJ(V tx, V sr) // fixme: improve
{
  V tr = VDUPL(tx);
  V ti = VDUPH(tx);
  ti = VMUL(ti, sr);
  sr = VBYI(sr);
  return VFMA(tr, sr, ti);
}

static inline V LDA(const R *x, INT ivs, const R *aligned_like) {
  (void)aligned_like; /* UNUSED */
  (void)ivs; /* UNUSED */
  return TYPE(vload)(x, 2*VL);
}
static inline void STA(R *x, V v, INT ovs, const R *aligned_like) {
  (void)aligned_like; /* UNUSED */
  (void)ovs; /* UNUSED */
  TYPE(vstore)(x,v,2*VL);
}

#if FFTW_SINGLE

static inline V LDu(const R *x, INT ivs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  svuint32_t  gvvl = svindex_u32(0, 1);
  gvvl = svmul_n_u32_z(svptrue_b32(), gvvl, sizeof(R)*ivs);
  gvvl = svzip1_u32(gvvl, gvvl);
  gvvl = svadd_u32_z(svptrue_b32(), gvvl, svdupq_n_u32(0,sizeof(R),0,sizeof(R)));
  
  return svld1_gather_u32offset_f32(ALLA, x, gvvl);
}

static inline void STu(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  if (ovs==0) { // FIXME: hack for extra_iter hack support
    v = svreinterpret_f32_f64(vdup_lane_f64(svreinterpret_f64_f32(v),0));
  }
  svuint32_t  gvvl = svindex_u32(0, 1);
  gvvl = svmul_n_u32_z(svptrue_b32(), gvvl, sizeof(R)*ovs);
  gvvl = svzip1_u32(gvvl, gvvl);
  gvvl = svadd_u32_z(svptrue_b32(), gvvl, svdupq_n_u32(0,sizeof(R),0,sizeof(R)));

  svst1_scatter_u32offset_f32(ALLA, x, gvvl, v);
}

#else /* !FFTW_SINGLE */

static inline V LDu(const R *x, INT ivs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  (void)aligned_like; /* UNUSED */
  __epi_1xi64 idx = __builtin_epi_vid_1xi64(VL); // (0, 1, 2, 3, ...)
  __epi_1xi64 vone = __builtin_epi_vbroadcast_1xi64(1, 2*VL);
  __epi_1xi64 hidx = __builtin_epi_vsrl_1xi64(idx, vone, 2*VL); // (0, 0, 1, 1, ...)
  hidx = __builtin_epi_vmul_1xi64(hidx, __builtin_epi_vbroadcast_1xi64(sizeof(R)*ivs, 2*VL), 2*VL);
  __epi_1xi64 idx2 = __builtin_epi_vand_1xi64(idx, vone, 2*VL); // (0, 1, 0, 1, ...)
  __epi_1xi64 hidx2 = __builtin_epi_vmul_1xi64(idx2, __builtin_epi_vbroadcast_1xi64(sizeof(R), 2*VL), 2*VL);
  hidx = __builtin_epi_vadd_1xi64(hidx, hidx2, 2*VL);
  return __builtin_epi_vload_indexed_1xf64(x, hidx, 2*VL);
}

static inline void STu(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  __epi_1xi64 idx = __builtin_epi_vid_1xi64(VL); // (0, 1, 2, 3, ...)
  __epi_1xi64 vone = __builtin_epi_vbroadcast_1xi64(1, 2*VL);
  __epi_1xi64 idx2 = __builtin_epi_vand_1xi64(idx, vone, 2*VL); // (0, 1, 0, 1, ...)
  if (ovs==0) { // FIXME: hack for extra_iter hack support
    v = __builtin_epi_vrgather_1xf64(v, idx2, 2*VL);
  }
  __epi_1xi64 hidx = __builtin_epi_vsrl_1xi64(idx, vone, 2*VL); // (0, 0, 1, 1, ...)
  hidx = __builtin_epi_vmul_1xi64(hidx, __builtin_epi_vbroadcast_1xi64(sizeof(R)*ovs, 2*VL), 2*VL);
  __epi_1xi64 hidx2 = __builtin_epi_vmul_1xi64(idx2, __builtin_epi_vbroadcast_1xi64(sizeof(R), 2*VL), 2*VL);
  hidx = __builtin_epi_vadd_1xi64(hidx, hidx2, 2*VL);
  __builtin_epi_vstore_indexed_1xf64(x, v, hidx, 2*VL);
}

#endif /* FFTW_SINGLE */

#define LD LDu
#define ST STu

#ifdef FFTW_SINGLE
#define STM2(x, v, ovs, a) ST(x, v, ovs, a)
#define STN2(x, v0, v1, ovs) /* nop */

static inline void STM4(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  (void)aligned_like; /* UNUSED */
  __epi_2xi32 idx = __builtin_epi_vid_2xi32(VL); // (0, 1, 2, 3, ...)
  __epi_2xi32 hidx = __builtin_epi_vmul_2xi32(idx, __builtin_epi_vbroadcast_2xi32(sizeof(R)*ovs, 2*VL), 2*VL);
  __builtin_epi_vstore_indexed_2xf32(x, v, hidx, 2*VL);
}
#define STN4(x, v0, v1, v2, v3, ovs)  /* no-op */
#else /* !FFTW_SINGLE */
#define STM2(x, v, ovs, a) ST(x, v, ovs, a)
#define STN2(x, v0, v1, ovs) /* nop */

static inline void STM4(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  (void)aligned_like; /* UNUSED */
  __epi_1xi64 idx = __builtin_epi_vid_1xi64(VL); // (0, 1, 2, 3, ...)
  __epi_1xi64 hidx = __builtin_epi_vmul_1xi64(idx, __builtin_epi_vbroadcast_1xi64(sizeof(R)*ovs, 2*VL), 2*VL);
  __builtin_epi_vstore_indexed_1xf64(x, v, hidx, 2*VL);
}
#define STN4(x, v0, v1, v2, v3, ovs)  /* no-op */
#endif /* FFTW_SINGLE */

/* twiddle storage #1: compact, slower */
#if R5V_SIZE == 512
#ifdef FFTW_SINGLE
# define VTW1(v,x) {TW_CEXP, v, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}, \
                   {TW_CEXP, v+4, x}, {TW_CEXP, v+5, x}, {TW_CEXP, v+6, x}, {TW_CEXP, v+7, x}
#else /* !FFTW_SINGLE */
# define VTW1(v,x) {TW_CEXP, v, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}
#endif /* FFTW_SINGLE */
#define TWVL1 (VL)
#elif R5V_SIZE == 256
#ifdef FFTW_SINGLE
# define VTW1(v,x) {TW_CEXP, v, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}
#else /* !FFTW_SINGLE */
# define VTW1(v,x) {TW_CEXP, v, x}, {TW_CEXP, v+1, x}
#endif /* FFTW_SINGLE */
#define TWVL1 (VL)
#else /* R5V_SIZE */
#error "R5V_SIZE must be 256 or 512 bits"
#endif /* R5V_SIZE */


static inline V BYTW1(const R *t, V sr)
{
     return VZMUL(LDA(t, 2, t), sr);
}

static inline V BYTWJ1(const R *t, V sr)
{
     return VZMULJ(LDA(t, 2, t), sr);
}

/* twiddle storage #2: twice the space, faster (when in cache) */
#if R5V_SIZE == 512
#ifdef FFTW_SINGLE
# define VTW2(v,x)							     \
   {TW_COS, v  ,  x}, {TW_COS, v  , x}, {TW_COS, v+1,  x}, {TW_COS, v+1, x}, \
   {TW_COS, v+2,  x}, {TW_COS, v+2, x}, {TW_COS, v+3,  x}, {TW_COS, v+3, x}, \
   {TW_COS, v+4,  x}, {TW_COS, v+4, x}, {TW_COS, v+5,  x}, {TW_COS, v+5, x}, \
   {TW_COS, v+6,  x}, {TW_COS, v+6, x}, {TW_COS, v+7,  x}, {TW_COS, v+7, x}, \
   {TW_SIN, v  , -x}, {TW_SIN, v  , x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
   {TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x}, \
   {TW_SIN, v+4, -x}, {TW_SIN, v+4, x}, {TW_SIN, v+5, -x}, {TW_SIN, v+5, x}, \
   {TW_SIN, v+6, -x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, -x}, {TW_SIN, v+7, x}
#else /* !FFTW_SINGLE */
# define VTW2(v,x)							     \
   {TW_COS, v  ,  x}, {TW_COS, v  , x}, {TW_COS, v+1,  x}, {TW_COS, v+1, x}, \
   {TW_COS, v+2,  x}, {TW_COS, v+2, x}, {TW_COS, v+3,  x}, {TW_COS, v+3, x}, \
   {TW_SIN, v  , -x}, {TW_SIN, v  , x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
   {TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x}
#endif /* FFTW_SINGLE */
#define TWVL2 (2 * VL)
#elif R5V_SIZE == 256
#ifdef FFTW_SINGLE
# define VTW2(v,x)                                                           \
   {TW_COS, v  ,  x}, {TW_COS, v  , x}, {TW_COS, v+1,  x}, {TW_COS, v+1, x}, \
   {TW_COS, v+2,  x}, {TW_COS, v+2, x}, {TW_COS, v+3,  x}, {TW_COS, v+3, x}, \
   {TW_SIN, v  , -x}, {TW_SIN, v  , x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
   {TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x}
#else /* !FFTW_SINGLE */
# define VTW2(v,x)                                                           \
   {TW_COS, v  ,  x}, {TW_COS, v  , x}, {TW_COS, v+1,  x}, {TW_COS, v+1, x}, \
   {TW_SIN, v  , -x}, {TW_SIN, v  , x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}
#endif /* FFTW_SINGLE */
#define TWVL2 (2 * VL)
#else /* R5V_SIZE */
#error "R5V_SIZE must be 256 or 512 bits"
#endif /* R5V_SIZE */

static inline V BYTW2(const R *t, V sr)
{
     V si = FLIP_RI(sr);
     V ti = LDA(t + 2*VL, 2, t + 4*VL);
     V tr = LDA(t, 2, t);
     return VFMA(tr, sr, VMUL(ti, si));
}

static inline V BYTWJ2(const R *t, V sr)
{
     V si = FLIP_RI(sr);
     V ti = LDA(t + 2*VL, 2, t + 4*VL);
     V tr = LDA(t, 2, t);
     return VFNMS(ti, si, VMUL(tr, sr));
}

/* twiddle storage #3 */
#define VTW3(v,x) VTW1(v,x)
#define TWVL3 TWVL1

/* twiddle storage for split arrays */
#if R5V_SIZE == 512
#ifdef FFTW_SINGLE
# define VTWS(v,x)                                                            \
  {TW_COS, v   , x}, {TW_COS, v+1 , x}, {TW_COS, v+2 , x}, {TW_COS, v+3 , x}, \
  {TW_COS, v+4 , x}, {TW_COS, v+5 , x}, {TW_COS, v+6 , x}, {TW_COS, v+7 , x}, \
  {TW_COS, v+8 , x}, {TW_COS, v+9 , x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, \
  {TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, \
  {TW_SIN, v   , x}, {TW_SIN, v+1 , x}, {TW_SIN, v+2 , x}, {TW_SIN, v+3 , x}, \
  {TW_SIN, v+4 , x}, {TW_SIN, v+5 , x}, {TW_SIN, v+6 , x}, {TW_SIN, v+7 , x}, \
  {TW_SIN, v+8 , x}, {TW_SIN, v+9 , x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, x}, \
  {TW_SIN, v+12, x}, {TW_SIN, v+13, x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, x}
#else /* !FFTW_SINGLE */
# define VTWS(v,x)							  \
  {TW_COS, v  , x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, \
  {TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, \
  {TW_SIN, v  , x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x}, \
  {TW_SIN, v+4, x}, {TW_SIN, v+5, x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, x}
#endif /* FFTW_SINGLE */
#define TWVLS (2 * VL)
#elif R5V_SIZE == 256
#ifdef FFTW_SINGLE
# define VTWS(v,x)                                                            \
  {TW_COS, v   , x}, {TW_COS, v+1 , x}, {TW_COS, v+2 , x}, {TW_COS, v+3 , x}, \
  {TW_COS, v+4 , x}, {TW_COS, v+5 , x}, {TW_COS, v+6 , x}, {TW_COS, v+7 , x}, \
  {TW_SIN, v   , x}, {TW_SIN, v+1 , x}, {TW_SIN, v+2 , x}, {TW_SIN, v+3 , x}, \
  {TW_SIN, v+4 , x}, {TW_SIN, v+5 , x}, {TW_SIN, v+6 , x}, {TW_SIN, v+7 , x}
#else /* !FFTW_SINGLE */
# define VTWS(v,x)                                                        \
  {TW_COS, v  , x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, \
  {TW_SIN, v  , x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x}
#endif /* FFTW_SINGLE */
#define TWVLS (2 * VL)
#else /* R5V_SIZE */
#error "R5V_SIZE must be 256 or 512 bits"
#endif


#define VLEAVE() /* nothing */

#include "simd-common.h"
