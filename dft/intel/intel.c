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

/* ***** MKL ***** */

#undef GENUS
#define GENUS X(dft_nmkl_genus)
extern const kdft_genus GENUS;

static int okp_mkl(const kdft_desc *d,
               const R *ri, const R *ii, 
               const R *ro, const R *io,
               int is, int os, int vl, int ivs, int ovs,
               const planner *plnr)
{
  int ok = (1
            && (ii == ri + 1)
            && (io == ro + 1)
            && (!d->is || (d->is == is))
            && (!d->os || (d->os == os))
            && (!d->ivs || (d->ivs == ivs))
            && (!d->ovs || (d->ovs == ovs))
            );
  return ok;
}

const kdft_genus GENUS = { okp_mkl, 1 };


#undef GENUS
#define GENUS X(dft_nmkl_inplace_genus)
extern const kdft_genus GENUS;

static int okp_mkl_inplace(const kdft_desc *d,
               const R *ri, const R *ii, 
               const R *ro, const R *io,
               int is, int os, int vl, int ivs, int ovs,
               const planner *plnr)
{
  int ok = (1
            && (ii == ri + 1)
            && (io == ro + 1)
            && (ri == ro)
            && (!d->is || (d->is == is))
            && (!d->os || (d->os == os))
            && (!d->ivs || (d->ivs == ivs))
            && (!d->ovs || (d->ovs == ovs))
            );
  return ok;
}

const kdft_genus GENUS = { okp_mkl_inplace, 1 };

#undef GENUS
#define GENUS X(dft_nmkl_outofplace_genus)
extern const kdft_genus GENUS;

static int okp_mkl_outofplace(const kdft_desc *d,
               const R *ri, const R *ii, 
               const R *ro, const R *io,
               int is, int os, int vl, int ivs, int ovs,
               const planner *plnr)
{
  int ok = (1
            && (ii == ri + 1)
            && (io == ro + 1)
            && (ri != ro)
            && (!d->is || (d->is == is))
            && (!d->os || (d->os == os))
            && (!d->ivs || (d->ivs == ivs))
            && (!d->ovs || (d->ovs == ovs))
            );
  return ok;
}

const kdft_genus GENUS = { okp_mkl_outofplace, 1 };

#endif
