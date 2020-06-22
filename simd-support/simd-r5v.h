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
#  define TYPEINT(name) __builtin_epi_ ## name ## _2xi32
#  define TYPEMASK(name) __builtin_epi_ ## name ## _2xf32_mask
#ifdef USE_EPI_CUSTOM
#  define TYPE2(name) __builtin_epi_ ## name ## _2xf32x2
#  define TYPE2INT(name) __builtin_epi_ ## name ## _2xi32x2
#endif
#else /* !FFTW_SINGLE */
#  define DS(d,s) d /* double-precision option */
#  define TYPE(name) __builtin_epi_ ## name ## _1xf64
#  define TYPEINT(name) __builtin_epi_ ## name ## _1xi64
#  define TYPEMASK(name) __builtin_epi_ ## name ## _1xf64_mask
#ifdef USE_EPI_CUSTOM
#  define TYPE2(name) __builtin_epi_ ## name ## _1xf64x2
#  define TYPE2INT(name) __builtin_epi_ ## name ## _1xi64x2
#endif
#endif /* FFTW_SINGLE */

#if R5V_SIZE == 16384
#define VL DS(128, 256)        /* SIMD complex vector length */
#elif R5V_SIZE == 8192
#define VL DS(64, 128)        /* SIMD complex vector length */
#elif R5V_SIZE == 4096
#define VL DS(32, 64)        /* SIMD complex vector length */
#elif R5V_SIZE == 2048
#define VL DS(16, 32)        /* SIMD complex vector length */
#elif R5V_SIZE == 1024
#define VL DS(8, 16)        /* SIMD complex vector length */
#elif R5V_SIZE == 512
#define VL DS(4, 8)        /* SIMD complex vector length */
#elif R5V_SIZE == 256
#define VL DS(2, 4)        /* SIMD complex vector length */
#elif R5V_SIZE == 128
#define VL DS(1, 2)        /* SIMD complex vector length */
#else /* R5V_SIZE */
#error "R5V_SIZE must be a power of 2 between 128 and 16384 bits"
#endif /* R5V_SIZE */

#define SIMD_VSTRIDE_OKA(x) ((x) == 2) 
#define SIMD_STRIDE_OKPAIR SIMD_STRIDE_OK

//#if defined(__GNUC__) && !defined(???) /* sanity check */
//#error "compiling simd-r5v.h without RISC-V V support"
//#endif

typedef DS(__epi_1xf64, __epi_2xf32) V;
typedef DS(__epi_1xi64, __epi_2xi32) Vint;
typedef DS(__epi_1xi1, __epi_2xi1) Vmask;
#ifdef USE_EPI_CUSTOM
typedef DS(__epi_1xf64x2, __epi_2xf32x2) V2;
typedef DS(__epi_1xi64x2, __epi_2xi32x2) V2int;
#endif
#define INT2MASK(mask) DS(TYPEINT(cast_1xi1),TYPEINT(cast_2xi1))(mask)

//##define VLIT(re, im) DS(svdupq_n_f64(re,im),svdupq_n_f32(re,im,re,im))
#ifdef FFTW_SINGLE
#warning "VLIT F32 perhaps should broadcast 64 bits"
#endif
static inline V VLIT(const R re, const R im) {
  Vint idx = TYPEINT(vid)(2*VL); // (0, 1, 2, 3, ...)
  Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
  V vre = TYPE(vfmv_v_f)(re, 2*VL);
  V vim = TYPE(vfmv_v_f)(im, 2*VL);
  Vint mask = TYPEINT(vand)(idx, vone, 2*VL); // (0, 1, 0, 1, 0, ...)
  return  (V)TYPEINT(vmerge)((Vint)vre, (Vint)vim, INT2MASK(mask), 2*VL);
}

#define VLIT1(val) TYPE(vfmv_v_f)(val, 2*VL)
#define LDK(x) x
#define DVK(var, val) V var = VLIT1(val)
#define VZERO VLIT1(DS(0.,0.f))
#define VRONE VLIT(DS(1.,1.f),DS(0.,0.f))
#define VCI VLIT(DS(0.,0.f),DS(1.,1.f))
#define VCONEMI VLIT(DS(1.,1.f),DS(-1.,-1.f))
#define VONE  VLIT1(DS(1.,1.f))
#define VMINUSONE VLIT1(DS(-1.,-1.f))

#ifndef USE_EPI_CUSTOM
static inline V VDUPL(const V x) {
	Vint idx = TYPEINT(vid)(2*VL); // (0, 1, 2, 3, ...)
	Vint vnotone = TYPEINT(vmv_v_x)(DS(~1ull,~1), 2*VL);
	Vint hidx = TYPEINT(vand)(idx, vnotone, 2*VL); // (0, 0, 2, 2, ...)
	return TYPE(vrgather)(x, hidx, 2*VL);
}
static inline V VDUPH(const V x) {
	Vint idx = TYPEINT(vid)(2*VL); // (0, 1, 2, 3, ...)
	Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
	Vint hidx = TYPEINT(vor)(idx, vone, 2*VL); // (1, 1, 3, 3, ...)
	return TYPE(vrgather)(x, hidx, 2*VL);
}

static inline V FLIP_RI(const V x) {
	Vint idx = TYPEINT(vid)(2*VL); // (0, 1, 2, 3, ...)
	Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
	Vint hidx = TYPEINT(vxor)(idx, vone, 2*VL); // (1, 0, 3, 2, ...)
	return TYPE(vrgather)(x, hidx, 2*VL);
}
#else
static inline V VDUPL(const V x) {
	V2 temp = TYPE2(vtrn)(x, x, 2*VL);
	return temp.v0;
}
static inline V VDUPH(const V x) {
	V2 temp = TYPE2(vtrn)(x, x, 2*VL);
	return temp.v1;
}

static inline V FLIP_RI(const V x) {
	V2 xx = TYPE2(vtrn)(x, x, 2*VL);
	V2 temp = TYPE2(vtrn)(xx.v1, x, 2*VL);
	return temp.v0;
}
#endif

static inline V VCONJ(const V x) {
	Vint idx = TYPEINT(vid)(2*VL); // (0, 1, 2, 3, ...)
	Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
	Vint hidx = TYPEINT(vand)(idx, vone, 2*VL); // (0, 1, 0, 1, 0, 1)
	return TYPEMASK(vfsgnjn)(x, x, x, INT2MASK(hidx), 2*VL);
}

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
#define VFNMS(a, b, c) TYPE(vfnmsac)(c,a,b,2*VL)  // or vfnmsub
#define VFMAI(b, c) VADD(c, VBYI(b)) // fixme: improve
#define VFNMSI(b, c) VSUB(c, VBYI(b)) // fixme: improve
#define VFMACONJ(b,c)  VADD(VCONJ(b),c) // fixme: improve
#define VFMSCONJ(b,c)  VFMACONJ(b,VNEG(c)) // fixme: improve
#define VFNMSCONJ(b,c) VNEG(VFMSCONJ(b,c)) // fixme: improve

#ifndef USE_EPI_CUSTOM
static inline V VZMUL(V tx, V sr) // fixme: improve
{
  V tr;
  V ti;
  Vint idx = TYPEINT(vid)(2*VL); // (0, 1, 2, 3, ...)
  Vint vnotone = TYPEINT(vmv_v_x)(DS(~1ull,~1), 2*VL);
  Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
  Vint hidx;
	
  hidx = TYPEINT(vand)(idx, vnotone, 2*VL); // (0, 0, 2, 2, ...)
  tr = TYPE(vrgather)(tx, hidx, 2*VL); // Real, Real of tx
  hidx = TYPEINT(vor)(idx, vone, 2*VL); // (1, 1, 3, 3, ...)  // could be hidx + vone, ...
  ti = TYPE(vrgather)(tx, hidx, 2*VL); // Imag, Imag of tx
  tr = TYPE(vfmul)(sr,tr,2*VL); // (Real, Real)[tx] * (Real,Imag)[sr]
  hidx = TYPEINT(vand)(idx, vone, 2*VL); // (0, 1, 0, 1, 0, 1)
  sr = TYPEMASK(vfsgnjn)(sr, sr, sr, INT2MASK(hidx), 2*VL); // conjugate of sr
  hidx = TYPEINT(vxor)(idx, vone, 2*VL); // (1, 0, 3, 2, ...)
  sr = TYPE(vrgather)(sr, hidx, 2*VL); // Imag, Real of (conjugate of) sr
  return TYPE(vfmacc)(tr,ti,sr,2*VL); // (-Imag, Real)[sr] * (Imag, Imag)[tx] + (Real, Real)[tx] * (Real,Imag)[sr]
}
#else
static inline V VZMUL(V tx, V sr)
{
  V tr = VDUPL(tx);
  V ti = VDUPH(tx);
  tr = VMUL(sr, tr);
  sr = VBYI(sr);
  return VFMA(ti, sr, tr);
}
#endif

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
#warning "Should be optimized with strided 64 bits access"

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
  Vint idx = TYPEINT(vid)(2*VL); // (0, 1, 2, 3, ...)
#ifndef USE_EPI_CUSTOM
  Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
  Vint hidx = TYPEINT(vsrl)(idx, vone, 2*VL); // (0, 0, 1, 1, ...)
  hidx = TYPEINT(vmul)(hidx, TYPEINT(vmv_v_x)(sizeof(R)*ivs, 2*VL), 2*VL);
  Vint idx2 = TYPEINT(vand)(idx, vone, 2*VL); // (0, 1, 0, 1, ...)
  Vint hidx2 = TYPEINT(vmul)(idx2, TYPEINT(vmv_v_x)(sizeof(R), 2*VL), 2*VL);
  hidx = TYPEINT(vadd)(hidx, hidx2, 2*VL);
#else
  Vint hidx = TYPEINT(vmul)(idx, TYPEINT(vmv_v_x)(sizeof(R)*ivs, 2*VL), 2*VL);
  Vint hidxp1 = TYPEINT(vadd)(hidx, TYPEINT(vmv_v_x)(sizeof(R), 2*VL), 2*VL);
  V2int hidx2 = TYPE2INT(vzip2)(hidx, hidxp1, 2*VL);
  hidx = hidx2.v0;
#endif
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
#ifndef USE_EPI_CUSTOM
  Vint hidx = TYPEINT(vsrl)(idx, vone, 2*VL); // (0, 0, 1, 1, ...)
  hidx = TYPEINT(vmul)(hidx, TYPEINT(vmv_v_x)(sizeof(R)*ovs, 2*VL), 2*VL);
  Vint hidx2 = TYPEINT(vmul)(idx2, TYPEINT(vmv_v_x)(sizeof(R), 2*VL), 2*VL);
  hidx = TYPEINT(vadd)(hidx, hidx2, 2*VL);
#else
  Vint hidx = TYPEINT(vmul)(idx, TYPEINT(vmv_v_x)(sizeof(R)*ovs, 2*VL), 2*VL);
  Vint hidxp1 = TYPEINT(vadd)(hidx, TYPEINT(vmv_v_x)(sizeof(R), 2*VL), 2*VL);
  V2int hidx2 = TYPE2INT(vzip2)(hidx, hidxp1, 2*VL);
  hidx = hidx2.v0;
#endif
  TYPE(vstore_indexed)(x, v, hidx, 2*VL);
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
  (void)aligned_like; /* UNUSED */
  (void)aligned_like; /* UNUSED */
  Vint idx = TYPEINT(vid)(2*VL); // (0, 1, 2, 3, ...)
  Vint hidx = TYPEINT(vmul)(idx, TYPEINT(vmv_v_x)(sizeof(R)*ovs, 2*VL), 2*VL);
  TYPE(vstore_indexed)(x, v, hidx, 2*VL);
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
