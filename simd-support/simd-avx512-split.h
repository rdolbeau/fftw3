/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
 *
 * AVX-512 support implemented by Romain Dolbeau.
 * Romain Dolbeau hereby places his modifications in the public domain.
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
#error "AVX-512 vector instructions only works in single or double precision"
#endif

#ifdef FFTW_SINGLE
#  define DS(d,s) s /* single-precision option */
#  define SUFF(name) name ## _ps
#  define SCAL(x) x ## f
#else /* !FFTW_SINGLE */
#  define DS(d,s) d /* double-precision option */
#  define SUFF(name) name ## _pd
#  define SCAL(x) x
#endif /* FFTW_SINGLE */

#define SIMD_SUFFIX  _avx512split  /* for renaming */
#define VL DS(8, 16)        /* SIMD complex vector length */
#define SIMD_VSTRIDE_OKA(x) ((x) == 2) // fixme: ???
#define SIMD_STRIDE_OKPAIR SIMD_STRIDE_OK

#if defined(__GNUC__) && !defined(__AVX512F__) /* sanity check */
#error "compiling simd-avx512.h without avx-512f support"
#endif

#if !defined(HAVE_AVX2)
#warning "You should probably enable AVX2 with --enable-avx2 for AVX-512"
#endif

#include <immintrin.h>

struct fftw_avx512_complex {
	DS(__m512d, __m512) re;
	DS(__m512d, __m512) im;
};

typedef struct fftw_avx512_complex V;

static inline V VLIT(const R re, const R im) {
	V v;
	v.re = SUFF(_mm512_set1)(re);
	v.im = SUFF(_mm512_set1)(im);
	return v;
}

static inline V VLIT1(const R val) {
	V v;
	v.re = SUFF(_mm512_set1)(val);
	v.im = v.re;
	return v;
}

#define LDK(x) x
#define DVK(var, val) V var = VLIT1(val)

static inline V VZERO(void) {
	V v;
	v.re = SUFF(_mm512_setzero)();
	v.im = SUFF(_mm512_setzero)();
	return v;
}

static inline V VDUPL(const V x) {
        V v;
	v.re = x.re;
        v.im = x.re;
        return v;
}

static inline V VDUPH(const V x) {
        V v;
        v.re = x.im;
        v.im = x.im;
        return v;
}

static inline V FLIP_RI(const V x) {
        V v;
        v.re = x.im;
        v.im = x.re;
        return v;
}

static inline V VCONJ(const V x) {
        V v;
        v.re = x.re;
        v.im = SUFF(_mm512_sub)(SUFF(_mm512_setzero)(), x.im); // fixme:improve?
        return v;
}

static inline V VNEG(const V x) {
        V v;
        v.re = SUFF(_mm512_sub)(SUFF(_mm512_setzero)(), x.re); // fixme:improve?;
        v.im = SUFF(_mm512_sub)(SUFF(_mm512_setzero)(), x.im); // fixme:improve?
        return v;
}

static inline V VBYI(V x) {
//     return FLIP_RI(VCONJ(x));
	V v;
	v.re = SUFF(_mm512_sub)(SUFF(_mm512_setzero)(), x.im);
	v.im = x.re;
	return v;
}

#define BINOP(X,x) \
static inline V X(const V a, const V b) {\
        V v;\
        v.re = SUFF(x)(a.re, b.re);\
        v.im = SUFF(x)(a.im, b.im);\
        return v;\
}

BINOP(VADD,_mm512_add)
BINOP(VSUB,_mm512_sub)
BINOP(VMUL,_mm512_mul)

#define TERNOP(X,x) \
static inline V X(const V a, const V b, const V c) {\
        V v;\
        v.re = SUFF(x)(a.re, b.re, c.re);\
        v.im = SUFF(x)(a.im, b.im, c.im);\
        return v;\
}

TERNOP(VFMA,_mm512_fmadd)
TERNOP(VFMS,_mm512_fmsub)
TERNOP(VFNMS,_mm512_fnmadd)

#define VFMAI(b, c) VADD(c, VBYI(b)) // fixme: improve?
#define VFNMSI(b, c) VSUB(c, VBYI(b)) // fixme: improve?
#define VFMACONJ(b,c)  VADD(VCONJ(b),c) // fixme: improve?
#define VFMSCONJ(b,c)  VFMACONJ(b,VNEG(c)) // fixme: improve?
#define VFNMSCONJ(b,c) VNEG(VFMSCONJ(b,c)) // fixme: improve?

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


static inline V LDA(const R *x, INT ivs, const R *aligned_like) { // fixme: improve
  (void)aligned_like; /* UNUSED */
  (void)ivs; /* UNUSED */
  V v;
#if 0
#if FFTW_SINGLE
  const __m512i index = _mm512_set_epi32(30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,0);
#else
  const __m256i index = _mm256_set_epi32(14,12,10,8,6,4,2,0);
#endif
  v.re = SUFF(_mm512_i32gather)(index, x, DS(8,4));
  v.im = SUFF(_mm512_i32gather)(index, x+1, DS(8,4));
#else
#if FFTW_SINGLE
  const __m512i indexE = _mm512_set_epi32(30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,0);
  const __m512i indexO = _mm512_set_epi32(31,29,27,25,23,21,19,17,15,13,11,9,7,5,3,1);
#else
  const __m512i indexE = _mm512_set_epi64(14,12,10,8,6,4,2,0);
  const __m512i indexO = _mm512_set_epi64(15,13,11,9,7,5,3,1);
#endif
  DS(__m512d, __m512) v1 = SUFF(_mm512_loadu)(x);
  DS(__m512d, __m512) v2 = SUFF(_mm512_loadu)(x+VL);
  v.re = SUFF(_mm512_permutex2var)(v1, indexE, v2);
  v.im = SUFF(_mm512_permutex2var)(v1, indexO, v2);
#endif
  return v;
}
static inline void STA(R *x, V v, INT ovs, const R *aligned_like) { // fixme: improve
  (void)aligned_like; /* UNUSED */
  (void)ovs; /* UNUSED */
#if 0
#if FFTW_SINGLE
  const __m512i index = _mm512_set_epi32(30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,0);
#else
  const __m256i index = _mm256_set_epi32(14,12,10,8,6,4,2,0);
#endif
  SUFF(_mm512_i32scatter)(x, index, v.re, DS(8,4));
  SUFF(_mm512_i32scatter)(x+1, index, v.im, DS(8,4));
#else
#if FFTW_SINGLE
  const __m512i indexL = _mm512_set_epi32(23,7,22,6,21,5,20,4,19,3,18,2,17,1,16,0);
  const __m512i indexH = _mm512_set_epi32(31,15,30,14,29,13,28,12,27,11,26,10,25,9,24,8);
#else
  const __m512i indexL = _mm512_set_epi64(11,3,10,2,9,1,8,0);
  const __m512i indexH = _mm512_set_epi64(15,7,14,6,13,5,12,4);
#endif
  DS(__m512d, __m512) vl = SUFF(_mm512_permutex2var)(v.re, indexL, v.im);
  DS(__m512d, __m512) vh = SUFF(_mm512_permutex2var)(v.re, indexH, v.im);
  SUFF(_mm512_storeu)(x, vl);
  SUFF(_mm512_storeu)(x+VL, vh);
#endif
}

static inline V LDu(const R *x, INT ivs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
  V v;
#if FFTW_SINGLE
  const __m512i bindex = _mm512_set_epi32(15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0);
  __m512i index = _mm512_mullo_epi32(bindex, _mm512_set1_epi32(ivs));
#else
  const __m256i bindex = _mm256_set_epi32(7,6,5,4,3,2,1,0);
  __m256i index = _mm256_mullo_epi32(bindex, _mm256_set1_epi32(ivs));
#endif
//  if (ivs == 0) {
//    v.re = _mm512_broadcastsd_pd(_mm_load_sd(x));
//    v.im = _mm512_broadcastsd_pd(_mm_load_sd(x+1));
//  } else {
    v.re = SUFF(_mm512_i32gather)(index, x, DS(8,4));
    v.im = SUFF(_mm512_i32gather)(index, x+1, DS(8,4));
//  }
  return v;
}

static inline void STu(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
#if FFTW_SINGLE
  const __m512i bindex = _mm512_set_epi32(15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0);
  __m512i index = _mm512_mullo_epi32(bindex, _mm512_set1_epi32(ovs));
#else
  const __m256i bindex = _mm256_set_epi32(7,6,5,4,3,2,1,0);
  __m256i index = _mm256_mullo_epi32(bindex, _mm256_set1_epi32(ovs));
#endif
//  if (ovs == 0) {
//    _mm512_mask_store_pd(x, 0x01, v.re);
//    _mm512_mask_store_pd(x+1, 0x01, v.im);
//  } else {
    SUFF(_mm512_i32scatter)(x, index, v.re, DS(8,4));
    SUFF(_mm512_i32scatter)(x+1, index, v.im, DS(8,4));
//  }
}

#define LD LDu
#define ST STu

#define STM2(x, v, ovs, a) ST(x, v, ovs, a)
#define STN2(x, v0, v1, ovs) /* nop */

static inline void STM4(R *x, V v, INT ovs, const R *aligned_like)
{
  (void)aligned_like; /* UNUSED */
#if FFTW_SINGLE
  const __m512i bindex = _mm512_set_epi32(30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,0);
  __m512i index = _mm512_mullo_epi32(bindex, _mm512_set1_epi32(ovs));
#else
  const __m256i bindex = _mm256_set_epi32(14,12,10,8,6,4,2,0);
  __m256i index = _mm256_mullo_epi32(bindex, _mm256_set1_epi32(ovs));
#endif
  SUFF(_mm512_i32scatter)(x, index, v.re, DS(8,4));
  SUFF(_mm512_i32scatter)(x+ovs, index, v.im, DS(8,4));
}
#define STN4(x, v0, v1, v2, v3, ovs)  /* no-op */

/* twiddle storage #1: compact, slower */
#ifdef FFTW_SINGLE
#define VTW1(v,x) {TW_CEXP, v+0, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}, \
        {TW_CEXP, v+4, x}, {TW_CEXP, v+5, x}, {TW_CEXP, v+6, x}, {TW_CEXP, v+7, x}, \
        {TW_CEXP, v+8, x}, {TW_CEXP, v+9, x}, {TW_CEXP, v+10, x}, {TW_CEXP, v+11, x}, \
        {TW_CEXP, v+12, x}, {TW_CEXP, v+13, x}, {TW_CEXP, v+14, x}, {TW_CEXP, v+15, x} 
#else /* !FFTW_SINGLE */
# define VTW1(v,x) {TW_CEXP, v, x}, {TW_CEXP, v+1, x}, {TW_CEXP, v+2, x}, {TW_CEXP, v+3, x}, {TW_CEXP, v+4, x}, {TW_CEXP, v+5, x}, {TW_CEXP, v+6, x}, {TW_CEXP, v+7, x}
#endif /* FFTW_SINGLE */
#define TWVL1 (VL)

static inline V BYTW1(const R *t, V sr)
{
     return VZMUL(LDA(t, 2, t), sr);
}

static inline V BYTWJ1(const R *t, V sr)
{
     return VZMULJ(LDA(t, 2, t), sr);
}

/* twiddle storage #2: twice the space, faster (when in cache) */
#ifdef FFTW_SINGLE
#define VTW2(v,x) {TW_COS, v+0, x}, {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+1, x}, \
        {TW_COS, v+2, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, {TW_COS, v+3, x}, \
        {TW_COS, v+4, x}, {TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+5, x}, \
        {TW_COS, v+6, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, {TW_COS, v+7, x}, \
        {TW_COS, v+8, x}, {TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+9, x}, \
        {TW_COS, v+10, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, {TW_COS, v+11, x}, \
        {TW_COS, v+12, x}, {TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+13, x}, \
        {TW_COS, v+14, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, {TW_COS, v+15, x}, \
        {TW_SIN, v+0, -x}, {TW_SIN, v+0, x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
        {TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x}, \
        {TW_SIN, v+4, -x}, {TW_SIN, v+4, x}, {TW_SIN, v+5, -x}, {TW_SIN, v+5, x}, \
        {TW_SIN, v+6, -x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, -x}, {TW_SIN, v+7, x}, \
        {TW_SIN, v+8, -x}, {TW_SIN, v+8, x}, {TW_SIN, v+9, -x}, {TW_SIN, v+9, x}, \
        {TW_SIN, v+10, -x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, -x}, {TW_SIN, v+11, x}, \
        {TW_SIN, v+12, -x}, {TW_SIN, v+12, x}, {TW_SIN, v+13, -x}, {TW_SIN, v+13, x}, \
        {TW_SIN, v+14, -x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, -x}, {TW_SIN, v+15, x} 
#else /* !FFTW_SINGLE */
# define VTW2(v,x)							     \
   {TW_COS, v  ,  x}, {TW_COS, v  , x}, {TW_COS, v+1,  x}, {TW_COS, v+1, x}, \
   {TW_COS, v+2,  x}, {TW_COS, v+2, x}, {TW_COS, v+3,  x}, {TW_COS, v+3, x}, \
   {TW_COS, v+4,  x}, {TW_COS, v+4, x}, {TW_COS, v+5,  x}, {TW_COS, v+5, x}, \
   {TW_COS, v+6,  x}, {TW_COS, v+6, x}, {TW_COS, v+7,  x}, {TW_COS, v+7, x}, \
   {TW_SIN, v  , -x}, {TW_SIN, v  , x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}, \
   {TW_SIN, v+2, -x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, -x}, {TW_SIN, v+3, x}, \
   {TW_SIN, v+4, -x}, {TW_SIN, v+4, x}, {TW_SIN, v+5, -x}, {TW_SIN, v+5, x}, \
   {TW_SIN, v+6, -x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, -x}, {TW_SIN, v+7, x}
#endif /* FFTW_SINGLE */
#define TWVL2 (2 * VL)

static inline V BYTW2(const R *t, V sr)
{
     V si = FLIP_RI(sr);
     V tr = LDA(t, 2, t), ti = LDA(t + 2*VL, 2, t);
     return VFMA(tr, sr, VMUL(ti, si));
}

static inline V BYTWJ2(const R *t, V sr)
{
     V si = FLIP_RI(sr);
     V tr = LDA(t, 2, t), ti = LDA(t + 2*VL, 2, t);
     return VFNMS(ti, si, VMUL(tr, sr));
}

/* twiddle storage #3 */
#define VTW3(v,x) VTW1(v,x)
#define TWVL3 TWVL1

/* twiddle storage for split arrays */
#ifdef FFTW_SINGLE
#define VTWS(v,x) {TW_COS, v+0, x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x}, \
        {TW_COS, v+4, x}, {TW_COS, v+5, x}, {TW_COS, v+6, x}, {TW_COS, v+7, x}, \
        {TW_COS, v+8, x}, {TW_COS, v+9, x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, \
        {TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, \
        {TW_COS, v+16, x}, {TW_COS, v+17, x}, {TW_COS, v+18, x}, {TW_COS, v+19, x}, \
        {TW_COS, v+20, x}, {TW_COS, v+21, x}, {TW_COS, v+22, x}, {TW_COS, v+23, x}, \
        {TW_COS, v+24, x}, {TW_COS, v+25, x}, {TW_COS, v+26, x}, {TW_COS, v+27, x}, \
        {TW_COS, v+28, x}, {TW_COS, v+29, x}, {TW_COS, v+30, x}, {TW_COS, v+31, x}, \
        {TW_SIN, v+0, x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x}, \
        {TW_SIN, v+4, x}, {TW_SIN, v+5, x}, {TW_SIN, v+6, x}, {TW_SIN, v+7, x}, \
        {TW_SIN, v+8, x}, {TW_SIN, v+9, x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, x}, \
        {TW_SIN, v+12, x}, {TW_SIN, v+13, x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, x}, \
        {TW_SIN, v+16, x}, {TW_SIN, v+17, x}, {TW_SIN, v+18, x}, {TW_SIN, v+19, x}, \
        {TW_SIN, v+20, x}, {TW_SIN, v+21, x}, {TW_SIN, v+22, x}, {TW_SIN, v+23, x}, \
        {TW_SIN, v+24, x}, {TW_SIN, v+25, x}, {TW_SIN, v+26, x}, {TW_SIN, v+27, x}, \
        {TW_SIN, v+28, x}, {TW_SIN, v+29, x}, {TW_SIN, v+30, x}, {TW_SIN, v+31, x} 
#else /* !FFTW_SINGLE */
# define VTWS(v,x)                                                            \
  {TW_COS, v   , x}, {TW_COS, v+1 , x}, {TW_COS, v+2 , x}, {TW_COS, v+3 , x}, \
  {TW_COS, v+4 , x}, {TW_COS, v+5 , x}, {TW_COS, v+6 , x}, {TW_COS, v+7 , x}, \
  {TW_COS, v+8 , x}, {TW_COS, v+9 , x}, {TW_COS, v+10, x}, {TW_COS, v+11, x}, \
  {TW_COS, v+12, x}, {TW_COS, v+13, x}, {TW_COS, v+14, x}, {TW_COS, v+15, x}, \
  {TW_SIN, v   , x}, {TW_SIN, v+1 , x}, {TW_SIN, v+2 , x}, {TW_SIN, v+3 , x}, \
  {TW_SIN, v+4 , x}, {TW_SIN, v+5 , x}, {TW_SIN, v+6 , x}, {TW_SIN, v+7 , x}, \
  {TW_SIN, v+8 , x}, {TW_SIN, v+9 , x}, {TW_SIN, v+10, x}, {TW_SIN, v+11, x}, \
  {TW_SIN, v+12, x}, {TW_SIN, v+13, x}, {TW_SIN, v+14, x}, {TW_SIN, v+15, x}
#endif /* FFTW_SINGLE */
#define TWVLS (2 * VL)

#define VLEAVE _mm256_zeroupper

#include "simd-common.h"
