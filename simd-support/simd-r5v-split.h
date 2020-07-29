/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
 *
 * RISC-V V support implemented by Romain Dolbeau. (c) 2019 Romain Dolbeau
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
#  define TYPE2(name) __builtin_epi_ ## name ## _2xf32x2
#  define TYPEINT(name) __builtin_epi_ ## name ## _2xi32
#  define TYPEMASK(name) __builtin_epi_ ## name ## _2xf32_mask
#else /* !FFTW_SINGLE */
#  define DS(d,s) d /* double-precision option */
#  define TYPE(name) __builtin_epi_ ## name ## _1xf64
#  define TYPE2(name) __builtin_epi_ ## name ## _1xf64x2
#  define TYPEINT(name) __builtin_epi_ ## name ## _1xi64
#  define TYPEMASK(name) __builtin_epi_ ## name ## _1xf64_mask
#endif /* FFTW_SINGLE */

/* FIXME: this hardwire to 512 bits */
#if R5V_SIZE == 16384
#define VL DS(256, 512)        /* SIMD complex vector length */
#elif R5V_SIZE == 8192
#define VL DS(128, 256)        /* SIMD complex vector length */
#elif R5V_SIZE == 4096
#define VL DS(64, 128)        /* SIMD complex vector length */
#elif R5V_SIZE == 2048
#define VL DS(32, 64)        /* SIMD complex vector length */
#elif R5V_SIZE == 1024
#define VL DS(16, 32)        /* SIMD complex vector length */
#elif R5V_SIZE == 512
#define VL DS(8, 16)        /* SIMD complex vector length */
#elif R5V_SIZE == 256
#define VL DS(4, 8)        /* SIMD complex vector length */
#elif R5V_SIZE == 128
#define VL DS(2, 4)        /* SIMD complex vector length */
#else /* R5V_SIZE */
#error "R5V_SIZE must be a power of 2 between 128 and 16384 bits"
#endif /* R5V_SIZE */

#define SIMD_VSTRIDE_OKA(x) ((x) == 2) 
#define SIMD_STRIDE_OKPAIR SIMD_STRIDE_OK

//#if defined(__GNUC__) && !defined(???) /* sanity check */
//#error "compiling simd-r5v.h without RISC-V V support"
//#endif

typedef DS(__epi_1xf64x2, __epi_2x32x2) V;
typedef DS(__epi_1xi64, __epi_2xi32) Vint;
typedef DS(__epi_1xi1, __epi_2xi1) Vmask;
#define INT2MASK(mask) DS(TYPEINT(cast_1xi1),TYPEINT(cast_2xi1))(mask)

static inline V VLIT(const R re, const R im) {
  V v;
  v.v0 = TYPE(vfmv_v_f)(re, VL);
  v.v1 = TYPE(vfmv_v_f)(im, VL);
  return v;
}

static inline V VLIT1(const R val) {
  V v;
  v.v0 = TYPE(vfmv_v_f)(val, VL);
  v.v1 = v.v0;
  return v;
}

#define LDK(x) x
#define DVK(var, val) V var = VLIT1(val)
#define VZERO VLIT1(DS(0.,0.f))
#define VRONE VLIT(DS(1.,1.f),DS(0.,0.f))
#define VCI VLIT(DS(0.,0.f),DS(1.,1.f))
#define VCONEMI VLIT(DS(1.,1.f),DS(-1.,-1.f))
#define VONE  VLIT1(DS(1.,1.f))
#define VMINUSONE VLIT1(DS(-1.,-1.f))

static inline V VDUPL(const V x) {
	V v = x;
	v.v1 = v.v0;
	return v;
}
static inline V VDUPH(const V x) {
	V v = x;
        v.v0 = v.v1;
        return v;
}

static inline V FLIP_RI(const V x) {
	V v;
	v.v0 = x.v1;
	v.v1 = x.v0;
	return v;
}

static inline V VCONJ(const V x) {
	V v;
	v.v0 = x.v0;
	v.v1 = TYPE(vfsgnjn)(x.v1, x.v1, VL);
	return v;
}

static inline V VBYI(const V x)
{
  V v;
  v = VCONJ(x);
  v = FLIP_RI(v);
  return v;
}

static inline V VNEG(const V x) {
	V v;
	v.v0 = TYPE(vfsgnjn)(x.v0, x.v0, VL);
	v.v1 = TYPE(vfsgnjn)(x.v1, x.v1, VL);
	return v;
}

#define BINOP(X,x) \
static inline V X(const V a, const V b) {\
        V v;\
        v.v0 = TYPE(x)(a.v0, b.v0, VL);\
        v.v1 = TYPE(x)(a.v1, b.v1, VL);\
        return v;\
}

BINOP(VADD,vfadd)
BINOP(VSUB,vfsub)
BINOP(VMUL,vfmul)

#define TERNOP(X,x) \
static inline V X(const V a, const V b, const V c) {\
	V v;\
	v.v0 = TYPE(x)(c.v0, a.v0, b.v0, VL);\
	v.v1 = TYPE(x)(c.v1, a.v1, b.v1, VL);\
	return v;\
}

TERNOP(VFMA,vfmacc) // or vfmadd
TERNOP(VFMS,vfmsac)
TERNOP(VFNMS,vfnmsac)

#define VFMAI(b, c) VADD(c, VBYI(b)) // fixme: improve
#define VFNMSI(b, c) VSUB(c, VBYI(b)) // fixme: improve
#define VFMACONJ(b,c)  VADD(VCONJ(b),c) // fixme: improve
#define VFMSCONJ(b,c)  VFMACONJ(b,VNEG(c)) // fixme: improve
#define VFNMSCONJ(b,c) VNEG(VFMSCONJ(b,c)) // fixme: improve

static inline V VZMUL(V tx, V sr)
{
     V tr = VDUPL(tx);
     V ti = VDUPH(tx);
     tr = VMUL(sr, tr);
     sr = VBYI(sr);
     return VFMA(ti, sr, tr);
}

static inline V VZMULJ(V tx, V sr)
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
  V v;
/* can be done with Zvlsseg instead */
#if 0
  v.v0 = TYPE(vload_strided)(x, 2*sizeof(R), VL);
  v.v1 = TYPE(vload_strided)(x+1, 2*sizeof(R), VL);
#else
  v = TYPE2(vlseg2)(x, VL);
#endif
  return v;
}
static inline void STA(R *x, const V v, INT ovs, const R *aligned_like) {
  (void)aligned_like; /* UNUSED */
  (void)ovs; /* UNUSED */
/* can be done with Zvlsseg instead */
#if 0
  TYPE(vstore_strided)(x, v.v0, 2*sizeof(R), VL);
  TYPE(vstore_strided)(x+1, v.v1, 2*sizeof(R), VL);
#else
  TYPE2(vsseg2)(x, v, VL);
#endif
}

#if FFTW_SINGLE
#warning "Should be optimized with strided 64 bits access"
#error "not implemented yet"

static inline V LDu(const R *x, INT ivs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  Vint idx = TYPEINT(vid)(2*VL); // (0, 1, 2, 3, ...)
  Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
  Vint hidx = TYPEINT(vsrl)(idx, vone, 2*VL); // (0, 0, 1, 1, ...)
  hidx = TYPEINT(vmul)(hidx, TYPEINT(vmv_v_x)(sizeof(R)*ivs, 2*VL), 2*VL);
  Vint idx2 = TYPEINT(vand)(idx, vone, 2*VL); // (0, 1, 0, 1, ...)
  Vint hidx2 = TYPEINT(vmul)(idx2, TYPEINT(vmv_v_x)(sizeof(R), 2*VL), 2*VL);
  hidx = TYPEINT(vadd)(hidx, hidx2, 2*VL);
  return TYPE(vload_indexed)(x, hidx, 2*VL);
}

static inline void STu(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  Vint idx = TYPEINT(vid)(2*VL); // (0, 1, 2, 3, ...)
  Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
  Vint idx2 = TYPEINT(vand)(idx, vone, 2*VL); // (0, 1, 0, 1, ...)
  if (ovs==0) { // FIXME: hack for extra_iter hack support
    v = TYPE(vrgather)(v, idx2, 2*VL);
  }
  Vint hidx = TYPEINT(vsrl)(idx, vone, 2*VL); // (0, 0, 1, 1, ...)
  hidx = TYPEINT(vmul)(hidx, TYPEINT(vmv_v_x)(sizeof(R)*ovs, 2*VL), 2*VL);
  Vint hidx2 = TYPEINT(vmul)(idx2, TYPEINT(vmv_v_x)(sizeof(R), 2*VL), 2*VL);
  hidx = TYPEINT(vadd)(hidx, hidx2, 2*VL);
  TYPE(vstore_indexed)(x, v, hidx, 2*VL);
}

#else /* !FFTW_SINGLE */

static inline V LDu(const R *x, INT ivs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  V v;
  v.v0 = TYPE(vload_strided)(x, ivs*sizeof(R), VL);
  v.v1 = TYPE(vload_strided)(x+1, ivs*sizeof(R), VL);
  return v;
}

static inline void STu(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  TYPE(vstore_strided)(x, v.v0, ovs*sizeof(R), VL); // fixme: check ovs == 0 ...
  TYPE(vstore_strided)(x+1, v.v1, ovs*sizeof(R), VL);
}

#endif /* FFTW_SINGLE */

#define LD LDu
#define ST STu

#ifdef FFTW_SINGLE
#error "not implemented yet"
#define STM2(x, v, ovs, a) ST(x, v, ovs, a)
#define STN2(x, v0, v1, ovs) /* nop */

static inline void STM4(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  (void)aligned_like; /* UNUSED */
  Vint idx = TYPEINT(vid)(2*VL); // (0, 1, 2, 3, ...)
  Vint hidx = TYPEINT(vmul)(idx, TYPEINT(vmv_v_x)(sizeof(R)*ovs, 2*VL), 2*VL);
  TYPE(vstore_indexed)(x, v, hidx, 2*VL);
}
#define STN4(x, v0, v1, v2, v3, ovs)  /* no-op */
#else /* !FFTW_SINGLE */
#define STM2(x, v, ovs, a) ST(x, v, ovs, a)
#define STN2(x, v0, v1, ovs) /* nop */

static inline void STM4(R *x, V v, INT ovs, const R *aligned_like)
{
  TYPE(vstore_strided)(x, v.v0, 2*ovs*sizeof(R), VL); // fixme: check ovs == 0 ...
  TYPE(vstore_strided)(x+ovs, v.v1, 2*ovs*sizeof(R), VL);
}
#define STN4(x, v0, v1, v2, v3, ovs)  /* no-op */
#endif /* FFTW_SINGLE */

/* twiddle storage #1: compact, slower */
#define REQ_VTW1
#define VTW_SIZE VL
#include "vtw.h"
#define TWVL1 (VL)
#undef VTW_SIZE
#undef REQ_VTW1

static inline V BYTW1(const R *t, V sr)
{
     return VZMUL(LDA(t, 2, t), sr);
}

static inline V BYTWJ1(const R *t, V sr)
{
     return VZMULJ(LDA(t, 2, t), sr);
}

/* twiddle storage #2: twice the space, faster (when in cache) */
#define REQ_VTW2
#define VTW_SIZE (2*VL)
#include "vtw.h"
#define TWVL2 (2*VL)
#undef VTW_SIZE
#undef REQ_VTW2

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
#define REQ_VTWS
#define VTW_SIZE (2*VL)
#include "vtw.h"
#define TWVLS (2*VL)
#undef VTW_SIZE
#undef REQ_VTWS

#define VLEAVE() /* nothing */

#include "simd-common.h"
