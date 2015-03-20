/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
 * Generic256d added by Romain Dolbeau.
 * Romain Dolbeau hereby places his modifications in the public domain.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#if defined(FFTW_SINGLE) || defined(FFTW_LDOUBLE) || defined(FFTW_QUAD)
#  error "Generic256d only works in double precision"
#endif

#define SIMD_SUFFIX  _generic256d  /* for renaming */
#define VL 2
#define SIMD_VSTRIDE_OKA(x) ((x) == 2) 
#define SIMD_STRIDE_OKPAIR SIMD_STRIDE_OK

typedef double V __attribute__ ((vector_size(32)));

#define VADD(a,b) ((a)+(b))
#define VSUB(a,b) ((a)-(b))
#define VMUL(a,b) ((a)*(b))

#define VDUPL(x) ((V){x[0],x[0],x[2],x[2]})
#define VDUPH(x) ((V){x[1],x[1],x[3],x[3]})

#define VLIT(x0, x1) {x0, x1, x0, x1}
#define DVK(var, val) V var = VLIT(val, val)
#define LDK(x) x

static inline V LDA(const R *x, INT ivs, const R *aligned_like)
{
#if 0
     (void)aligned_like; /* UNUSED */
     (void)ivs; /* UNUSED */
     return *(const V *)x;
#else
     V var;
     (void)aligned_like; /* UNUSED */
     var = (V){x[0],x[1],x[2],x[3]};
     return var;
#endif
}

static inline void STA(R *x, V v, INT ovs, const R *aligned_like)
{
#if 0
     (void)aligned_like; /* UNUSED */
     (void)ovs; /* UNUSED */
     *(V *)x = v;
#else
     (void)aligned_like; /* UNUSED */
     *(x + 2) = v[2];
     *(x + 3) = v[3];
     *(x    ) = v[0];
     *(x + 1) = v[1];
#endif
}

static inline V LD(const R *x, INT ivs, const R *aligned_like)
{
     V var;
     (void)aligned_like; /* UNUSED */
     var = (V){x[0],x[1],x[ivs],x[ivs+1]};
     return var;
}

static inline void ST(R *x, V v, INT ovs, const R *aligned_like)
{
     (void)aligned_like; /* UNUSED */
     *(x + ovs    ) = v[2];
     *(x + ovs + 1) = v[3];
     *(x    ) = v[0];
     *(x + 1) = v[1];
}


#define STM2 ST
#define STN2(x, v0, v1, ovs) /* nop */
#define STM4(x, v, ovs, aligned_like) /* no-op */

static inline void STN4(R *x, V v0, V v1, V v2, V v3, INT ovs) {
  *(x              ) = v0[0];
  *(x           + 1) = v1[0];
  *(x           + 2) = v2[0];
  *(x           + 3) = v3[0];
  *(x     + ovs    ) = v0[0]; /* ? */
  *(x     + ovs + 1) = v1[1];
  *(x     + ovs + 2) = v2[1];
  *(x     + ovs + 3) = v3[1];
  *(x + 2 * ovs    ) = v0[2];
  *(x + 2 * ovs + 1) = v1[2];
  *(x + 2 * ovs + 2) = v2[2];
  *(x + 2 * ovs + 3) = v3[2];
  *(x + 3 * ovs    ) = v0[3];
  *(x + 3 * ovs + 1) = v1[3];
  *(x + 3 * ovs + 2) = v2[3];
  *(x + 3 * ovs + 3) = v3[3];
}

static inline V FLIP_RI(V x)
{
  return ((V){x[1],x[0],x[3],x[2]});
}

static inline V VCONJ(V x)
{
  
  return (x * (V){1.,-1.,1.,-1.});
}

static inline V VBYI(V x)
{
     return FLIP_RI(VCONJ(x));
}

/* FMA support */
#define VFMA(a, b, c) VADD(c, VMUL(a, b))
#define VFNMS(a, b, c) VSUB(c, VMUL(a, b))
#define VFMS(a, b, c) VSUB(VMUL(a, b), c)
#define VFMAI(b, c) VADD(c, VBYI(b))
#define VFNMSI(b, c) VSUB(c, VBYI(b))
#define VFMACONJ(b,c)  VADD(VCONJ(b),c)
#define VFMSCONJ(b,c)  VSUB(VCONJ(b),c)
#define VFNMSCONJ(b,c) VSUB(c, VCONJ(b))

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

/* twiddle storage #1: compact, slower */
#define VTW1(v,x) {TW_CEXP, v, x}, {TW_CEXP, v+1, x}
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
#define VTW2(v,x)							\
   {TW_COS, v, x}, {TW_COS, v, x}, {TW_COS, v+1, x}, {TW_COS, v+1, x},	\
   {TW_SIN, v, -x}, {TW_SIN, v, x}, {TW_SIN, v+1, -x}, {TW_SIN, v+1, x}
#define TWVL2 (2 * VL)

static inline V BYTW2(const R *t, V sr)
{
     const V *twp = (const V *)t;
     V si = FLIP_RI(sr);
     V tr = twp[0], ti = twp[1];
     return VFMA(tr, sr, VMUL(ti, si));
}

static inline V BYTWJ2(const R *t, V sr)
{
     const V *twp = (const V *)t;
     V si = FLIP_RI(sr);
     V tr = twp[0], ti = twp[1];
     return VFNMS(ti, si, VMUL(tr, sr));
}

/* twiddle storage #3 */
#define VTW3 VTW1
#define TWVL3 TWVL1

/* twiddle storage for split arrays */
# define VTWS(v,x)							\
  {TW_COS, v, x}, {TW_COS, v+1, x}, {TW_COS, v+2, x}, {TW_COS, v+3, x},	\
  {TW_SIN, v, x}, {TW_SIN, v+1, x}, {TW_SIN, v+2, x}, {TW_SIN, v+3, x}	
#define TWVLS (2 * VL)

#define VLEAVE() /* nothing */

#include "simd-common.h"
