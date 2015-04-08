/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 * Copyright (c) 2015 Romain Dolbeau
 * Romain Dolbeau hereby places this code in the public domain.
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

#include "codelet-dft.h"

#ifdef HAVE_INTEL_MKL

#include <mkl_dfti.h>
#include <stdio.h>

#define GENUS X(dft_nmkl_genus)
extern const kdft_genus GENUS;

static void n1mkl_generic(DFTI_DESCRIPTOR *the_descriptor, const R *ri, const R *ii, R *ro, R *io, stride is, stride os, int v, int ivs, int ovs)
{
  if (ri != ro)
    DftiComputeForward(the_descriptor, ri, ro);
  else
    DftiComputeForward(the_descriptor, ri);
}







static const kdft_desc desc = { 0, "n1mkl_generic", {0, 0, 0, 0}, &GENUS, 0, 0, 0, 0 };
void X(codelet_n1mkl_generic) (planner *p) {
  X(kdft_intel_mkl_register) (p, n1mkl_generic, &desc);
}

#undef GENUS

#endif
