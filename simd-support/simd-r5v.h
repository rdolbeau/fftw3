/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
 *
 * RISC-V V support implemented by Romain Dolbeau. (c) 2019 Romain Dolbeau
 * Updated to standard intrinsics by Romain Dolbeau. (c) 2024 Romain Dolbeau
 * Some of the updated macros originally by Zheng Shuo. (c) 2022 Zheng Shuo
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
#  define TYPE(name) __riscv_ ## name ## _f32m1
#  define TYPEINT(name) __riscv_ ## name ## _u32m1
#  define TYPEMASK(name) __riscv_ ## name ## _f32m1_m
#  define TYPEINTERPRETF2U(name) __riscv_ ## name ## _f32m1_u32m1
#  define TYPEINTERPRETU2F(name) __riscv_ ## name ## _u32m1_f32m1
#else /* !FFTW_SINGLE */
#  define DS(d,s) d /* double-precision option */
#  define TYPE(name) __riscv_ ## name ## _f64m1
#  define TYPEINT(name) __riscv_ ## name ## _u64m1
#  define TYPEMASK(name) __riscv_ ## name ## _f64m1_m
#  define TYPEINTERPRETF2U(name) __riscv_ ## name ## _f64m1_u64m1
#  define TYPEINTERPRETU2F(name) __riscv_ ## name ## _u64m1_f64m1
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

#if defined(__GNUC__) && !defined(__riscv_vector) /* sanity check */
#error "compiling simd-r5v.h without RISC-V V support"
#endif

#include <riscv_vector.h>

typedef DS(vfloat64m1_t, vfloat32m1_t) V;
typedef DS(vuint64m1_t, vuint32m1_t) Vint;
typedef DS(vbool64_t, vbool32_t) Vmask;
/* that was wrorking nicely in V0.7.1, but the mask organization in V1.0 breaks it */
// #define INT2MASK(mask) DS(__riscv_vreinterpret_v_u64m1_b64,__riscv_vreinterpret_v_u32m1_b32)(mask)

/* unused */
/*
#ifdef FFTW_SINGLE
#warning "VLIT F32 perhaps should broadcast 64 bits"
#endif
static inline V VLIT(const R re, const R im) {
  Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
  Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
  V vre = TYPE(vfmv_v_f)(re, 2*VL);
  V vim = TYPE(vfmv_v_f)(im, 2*VL);
  Vint mask = TYPEINT(vand_vv)(idx, vone, 2*VL); // (0, 1, 0, 1, 0, ...)
  return  TYPE(vmerge_vvm)(vre, vim, INT2MASK(mask), 2*VL);
}
*/

#define VLIT1(val) TYPE(vfmv_v_f)(val, 2*VL)
#define LDK(x) x
#define DVK(var, val) V var = VLIT1(val)
#define VZERO VLIT1(DS(0.,0.f))
/* unused */
//#define VRONE VLIT(DS(1.,1.f),DS(0.,0.f))
//#define VCI VLIT(DS(0.,0.f),DS(1.,1.f))
//#define VCONEMI VLIT(DS(1.,1.f),DS(-1.,-1.f))
//#define VONE  VLIT1(DS(1.,1.f))
//#define VMINUSONE VLIT1(DS(-1.,-1.f))
// generate (all 1, 0, all 1, 0, ...) to split real and imagine parts
#define VPARTSPLIT TYPEINT(vsub_vx)(TYPEINT(vand_vx)(TYPEINT(vid_v)(2*VL), 1, 2*VL), 1, 2*VL)

static inline V VDUPL(const V x) {
	Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
	//Vint vnotone = TYPEINT(vmv_v_x)(DS(~1ull,~1), 2*VL);
	Vint hidx = TYPEINT(vand_vx)(idx, DS(~1ull,~1), 2*VL); // (0, 0, 2, 2, ...)
	return TYPE(vrgather_vv)(x, hidx, 2*VL);
}
static inline V VDUPH(const V x) {
	Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
	//Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
	Vint hidx = TYPEINT(vor_vx)(idx, 1, 2*VL); // (1, 1, 3, 3, ...)
	return TYPE(vrgather_vv)(x, hidx, 2*VL);
}

static inline V FLIP_RI(const V x) {
	Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
	//Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
	Vint hidx = TYPEINT(vxor_vx)(idx, 1, 2*VL); // (1, 0, 3, 2, ...)
	return TYPE(vrgather_vv)(x, hidx, 2*VL);
}

#define VNEG(a)   TYPE(vfsgnjn_vv)(a,a,2*VL)
#define VADD(a,b) TYPE(vfadd_vv)(a,b,2*VL)
#define VSUB(a,b) TYPE(vfsub_vv)(a,b,2*VL)
#define VMUL(a,b) TYPE(vfmul_vv)(a,b,2*VL)
#define VFMA(a, b, c)  TYPE(vfmacc_vv)(c,a,b,2*VL) // or vfmadd
#define VFMS(a, b, c)  TYPE(vfmsac_vv)(c,a,b,2*VL)
#define VFNMS(a, b, c) TYPE(vfnmsac_vv)(c,a,b,2*VL)  // or vfnmsub
#define VFMAI(b, c) VADD(c, VBYI(b)) // fixme: improve
#define VFNMSI(b, c) VSUB(c, VBYI(b)) // fixme: improve
#define VFMACONJ(b,c)  VADD(VCONJ(b),c) // fixme: improve
#define VFMSCONJ(b,c)  VFMACONJ(b,VNEG(c)) // fixme: improve
#define VFNMSCONJ(b,c) VNEG(VFMSCONJ(b,c)) // fixme: improve

#if 0
/* broken by INT2MASK ?*/
static inline V VCONJ(const V x) {
	Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
	//Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
	Vint hidx = TYPEINT(vand_vx)(idx, 1, 2*VL); // (0, 1, 0, 1, 0, 1)
	//return TYPEMASK(vfsgnjn_vv)(x, x, x, INT2MASK(hidx), 2*VL);
	return TYPEMASK(vfsgnjn_vv)(INT2MASK(hidx), x, x, 2*VL);
}
#else
static inline V VCONJ(const V x)
{
	Vint partr = VPARTSPLIT; // (all 1, 0, all 1, 0, ...)
	V xl = TYPEINTERPRETU2F(vreinterpret_v)(TYPEINT(vand_vv)(TYPEINTERPRETF2U(vreinterpret_v)(x), partr, 2*VL)); // set odd elements to 0
	Vint parti = TYPEINT(vnot_v)(partr, 2*VL); // (0, all 1, 0, all 1, ...)
	V xh = TYPEINTERPRETU2F(vreinterpret_v)(TYPEINT(vand_vv)(TYPEINTERPRETF2U(vreinterpret_v)(x), parti, 2*VL)); // set even elements to 0
	return VADD(xl, VNEG(xh));
}
#endif

/* can probably be done better */
static inline V VBYI(V x)
{
  x = VCONJ(x);
  x = FLIP_RI(x);
  return x;
}

#if 1
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

static inline V VZMULI(V tx, V sr)
{
    V tr = VDUPL(tx);
    V ti = VDUPH(tx);
    ti = VMUL(ti, sr);
    sr = VBYI(sr);
    return VFMS(tr, sr, ti);
}

static inline V VZMULIJ(V tx, V sr)
{
    V tr = VDUPL(tx);
    V ti = VDUPH(tx);
    ti = VMUL(ti, sr);
    sr = VBYI(sr);
    return VFMA(tr, sr, ti);
}
#else
/* broken by INT2MASK ? */
static inline V VZMUL(V tx, V sr) // fixme: improve
{
  V tr;
  V ti;
  Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
  //Vint vnotone = TYPEINT(vmv_v_x)(DS(~1ull,~1), 2*VL);
  //Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
  Vint hidx;
	
  hidx = TYPEINT(vand_vv)(idx, DS(-1ull,-1), 2*VL); // (0, 0, 2, 2, ...)
  tr = TYPE(vrgather_vv)(tx, hidx, 2*VL); // Real, Real of tx
  hidx = TYPEINT(vor_vx)(idx, 1, 2*VL); // (1, 1, 3, 3, ...)  // could be hidx + vone, ...
  ti = TYPE(vrgather_vv)(tx, hidx, 2*VL); // Imag, Imag of tx
  tr = TYPE(vfmul_vv)(sr,tr,2*VL); // (Real, Real)[tx] * (Real,Imag)[sr]
  hidx = TYPEINT(vand_vx)(idx, 1, 2*VL); // (0, 1, 0, 1, 0, 1)
  //sr = TYPEMASK(vfsgnjn)(sr, sr, sr, INT2MASK(hidx), 2*VL); // conjugate of sr
  sr = TYPEMASK(vfsgnjn_vv)(INT2MASK(hidx), sr, sr, 2*VL); // conjugate of sr
  hidx = TYPEINT(vxor_vx)(idx, 1, 2*VL); // (1, 0, 3, 2, ...)
  sr = TYPE(vrgather_vv)(sr, hidx, 2*VL); // Imag, Real of (conjugate of) sr
  return TYPE(vfmacc_vv)(tr,ti,sr,2*VL); // (-Imag, Real)[sr] * (Imag, Imag)[tx] + (Real, Real)[tx] * (Real,Imag)[sr]
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
#endif

static inline V LDA(const R *x, INT ivs, const R *aligned_like) {
  (void)aligned_like; /* UNUSED */
  (void)ivs; /* UNUSED */
  return DS(__riscv_vle64_v_f64m1, __riscv_vle32_v_f32m1)(x, 2*VL);
}
static inline void STA(R *x, V v, INT ovs, const R *aligned_like) {
  (void)aligned_like; /* UNUSED */
  (void)ovs; /* UNUSED */
  DS(__riscv_vse64_v_f64m1,__riscv_vse32_v_f32m1)(x,v,2*VL);
}

#if FFTW_SINGLE
#warning "Should be optimized with strided 64 bits access"

static inline V LDu(const R *x, INT ivs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
  //Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
  Vint hidx = TYPEINT(vsrl_vx)(idx, 1, 2*VL); // (0, 0, 1, 1, ...)
  hidx = TYPEINT(vmul_vx)(hidx, sizeof(R)*ivs, 2*VL);
  Vint idx2 = TYPEINT(vand_vx)(idx, 1, 2*VL); // (0, 1, 0, 1, ...)
  Vint hidx2 = TYPEINT(vmul_vx)(idx2, sizeof(R), 2*VL);
  hidx = TYPEINT(vadd_vv)(hidx, hidx2, 2*VL);
  return __riscv_vloxei32_v_f32m1(x, hidx, 2*VL);
}

static inline void STu(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
  //Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
  Vint idx2 = TYPEINT(vand_vx)(idx, 1, 2*VL); // (0, 1, 0, 1, ...)
  if (ovs==0) { // FIXME: hack for extra_iter hack support
    v = TYPE(vrgather_vv)(v, idx2, 2*VL);
  }
  Vint hidx = TYPEINT(vsrl_vx)(idx, 1, 2*VL); // (0, 0, 1, 1, ...)
  hidx = TYPEINT(vmul_vx)(hidx, sizeof(R)*ovs, 2*VL);
  Vint hidx2 = TYPEINT(vmul_vx)(idx2, sizeof(R), 2*VL);
  hidx = TYPEINT(vadd_vv)(hidx, hidx2, 2*VL);
  __riscv_vsoxei32_v_f32m1(x, hidx, v, 2*VL);
}

#else /* !FFTW_SINGLE */

static inline V LDu(const R *x, INT ivs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
  //Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
  Vint hidx = TYPEINT(vsrl_vx)(idx, 1, 2*VL); // (0, 0, 1, 1, ...)
  hidx = TYPEINT(vmul_vx)(hidx, sizeof(R)*ivs, 2*VL);
  Vint idx2 = TYPEINT(vand_vx)(idx, 1, 2*VL); // (0, 1, 0, 1, ...)
  Vint hidx2 = TYPEINT(vmul_vx)(idx2, sizeof(R), 2*VL);
  hidx = TYPEINT(vadd_vv)(hidx, hidx2, 2*VL);
  return __riscv_vloxei64_v_f64m1(x, hidx, 2*VL);
}

static inline void STu(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
  //Vint vone = TYPEINT(vmv_v_x)(1, 2*VL);
  Vint idx2 = TYPEINT(vand_vx)(idx, 1, 2*VL); // (0, 1, 0, 1, ...)
  if (ovs==0) { // FIXME: hack for extra_iter hack support
    v = TYPE(vrgather_vv)(v, idx2, 2*VL);
  }
  Vint hidx = TYPEINT(vsrl_vx)(idx, 1, 2*VL); // (0, 0, 1, 1, ...)
  hidx = TYPEINT(vmul_vx)(hidx, sizeof(R)*ovs, 2*VL);
  Vint hidx2 = TYPEINT(vmul_vx)(idx2, sizeof(R), 2*VL);
  hidx = TYPEINT(vadd_vv)(hidx, hidx2, 2*VL);
  __riscv_vsoxei64_v_f64m1(x, hidx, v, 2*VL);
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
  Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
  Vint hidx = TYPEINT(vmul_vx)(idx, sizeof(R)*ovs, 2*VL);
  __riscv_vsoxei32_v_f32m1(x, hidx, v, 2*VL);
}
#define STN4(x, v0, v1, v2, v3, ovs)  /* no-op */
#else /* !FFTW_SINGLE */
#define STM2(x, v, ovs, a) ST(x, v, ovs, a)
#define STN2(x, v0, v1, ovs) /* nop */

static inline void STM4(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  (void)aligned_like; /* UNUSED */
  Vint idx = TYPEINT(vid_v)(2*VL); // (0, 1, 2, 3, ...)
  Vint hidx = TYPEINT(vmul_vx)(idx, sizeof(R)*ovs, 2*VL);
  __riscv_vsoxei64_v_f64m1(x, hidx, v, 2*VL);
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
