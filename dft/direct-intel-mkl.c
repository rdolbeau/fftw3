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

/* direct DFT solver, using the Intel MKL library */

#include "dft.h"

#ifdef HAVE_INTEL_MKL
#include <stdio.h>

#if defined(FFTW_SINGLE)
#define MKL_DFTI_TYPE DFTI_SINGLE
#elif defined(FFTW_LDOUBLE)
#error "MKL not supported with long double"
#else
#define MKL_DFTI_TYPE DFTI_DOUBLE
#endif

#define MKL_INT_TYPE long int

typedef struct {
     solver super;
     const kdft_desc *desc;
     kdft_intel_mkl k;
} S;

typedef struct {
     plan_dft super;

     stride is, os;
     INT n, vl, ivs, ovs;
     kdft_intel_mkl k;
     const S *slv;

     /* extra MKL stuff */
     DFTI_DESCRIPTOR *the_descriptor;
     /* to be freed */
     MKL_INT_TYPE *istride;
     MKL_INT_TYPE *ostride;
     MKL_INT_TYPE *ranks;
} P;

static void apply(const plan *ego_, R *ri, R *ii, R *ro, R *io)
{
     const P *ego = (const P *) ego_;
     ASSERT_ALIGNED_DOUBLE;
     ego->k(ego->the_descriptor, ri, ii, ro, io, ego->is, ego->os, ego->vl, ego->ivs, ego->ovs);
}

static void destroy(plan *ego_)
{
     P *ego = (P *) ego_;

     DftiFreeDescriptor(&ego->the_descriptor);

     X(ifree)(ego->istride);
     X(ifree)(ego->ostride);
     X(ifree)(ego->ranks);

     X(stride_destroy)(ego->is);
     X(stride_destroy)(ego->os);
}

static void print(const plan *ego_, printer *p)
{
     const P *ego = (const P *) ego_;
     const S *s = ego->slv;
     const kdft_desc *d = s->desc;

     p->print(p, "(dft-direct-mkl-%d%v-is%d-os%d-ivs%d-ovs%d \"%s\")", d->sz, ego->vl, ego->is, ego->os, ego->ivs, ego->ovs, d->nam);
}

static int applicable(const solver *ego_, const problem *p_,
		      const planner *plnr)
{
     /* if (DFTP(p_)) */ {
          const S *ego = (const S *) ego_;
          const problem_dft *p = (const problem_dft *) p_;
          const kdft_desc *d = ego->desc;
	  INT vl, ivs, ovs;

          return (
	       1
	       && p->sz->rnk <= 3
               && p->sz->rnk >= 1
	       && p->vecsz->rnk <= 1
               /* HEURISTIC */
               && (p->sz->dims[0].n >= 8)
               && ((p->sz->rnk <= 1) || (p->sz->dims[1].n >= 8))
               && ((p->sz->rnk <= 2) || (p->sz->dims[2].n >= 8))
	       /* check strides etc */
	       && X(tensor_tornk1)(p->vecsz, &vl, &ivs, &ovs)
               /* */
	       && (d->genus->okp(d, p->ri, p->ii, p->ro, p->io,
				 p->sz->dims[0].is, p->sz->dims[0].os,
				 vl, ivs, ovs, plnr))
	       && (0
		   /* can operate out-of-place */
		   || p->ri != p->ro

		   /*
		    * can compute one transform in-place, no matter
		    * what the strides are.
		    */
		   || p->vecsz->rnk == 0

		   /* can operate in-place as long as strides are the same */
		   || (X(tensor_inplace_strides2)(p->sz, p->vecsz))
		    )
	       );
     }

     return 0;
}

static plan *mkplan(const solver *ego_, const problem *p_, planner *plnr)
{
     const S *ego = (const S *) ego_;
     P *pln;
     const problem_dft *p;
     iodim *d;
     const kdft_desc *e = ego->desc;
     INT bufsz;
     INT i;

     static const plan_adt padt = {
	  X(dft_solve), X(null_awake), print, destroy
     };

     if (!applicable(ego, p_, plnr))
          return (plan *)0;

     p = (const problem_dft *) p_;

     pln = MKPLAN_DFT(P, &padt, apply);

     {
       INT vl, ivs, ovs;
       DFTI_DESCRIPTOR *the_descriptor = NULL;
       long status = DFTI_NO_ERROR;
       MKL_INT_TYPE *istride = MALLOC(4*sizeof(MKL_INT_TYPE), BUFFERS);
       MKL_INT_TYPE *ostride = MALLOC(4*sizeof(MKL_INT_TYPE), BUFFERS);
       MKL_INT_TYPE *ranks = MALLOC(3*sizeof(MKL_INT_TYPE), BUFFERS); 
       istride[0] = 0;
       ostride[0] = 0;
       for (i = 0 ; i < p->sz->rnk ; i++) {
         istride[i+1] = p->sz->dims[i].is / 2;
         ostride[i+1] = p->sz->dims[i].os / 2;
       }
       for (i = 0 ; i < p->sz->rnk ; i++) {
         ranks[i] = p->sz->dims[i].n;
       }

       X(tensor_tornk1)(p->vecsz, &vl, &ivs, &ovs);

       if (status == DFTI_NO_ERROR)
         status = DftiCreateDescriptor(&the_descriptor, MKL_DFTI_TYPE, DFTI_COMPLEX,
                                       p->sz->rnk, p->sz->rnk == 1 ? p->sz->dims[0].n : ranks);
       if (status == DFTI_NO_ERROR) {
         if (status == DFTI_NO_ERROR)
           status = DftiSetValue(the_descriptor, DFTI_INPUT_STRIDES, istride);
         if ((p->ri != p->ro)) {
           if (status == DFTI_NO_ERROR)
             status = DftiSetValue(the_descriptor, DFTI_OUTPUT_STRIDES, ostride);
         }
         if (vl > 1) {
           if (status == DFTI_NO_ERROR)
             status = DftiSetValue(the_descriptor, DFTI_NUMBER_OF_TRANSFORMS, vl);
           if (status == DFTI_NO_ERROR)
             status = DftiSetValue(the_descriptor, DFTI_INPUT_DISTANCE, ivs / 2);
           if (p->ri != p->ro)
             if (status == DFTI_NO_ERROR)
               status = DftiSetValue(the_descriptor, DFTI_OUTPUT_DISTANCE, ovs / 2);
         }
         if (status == DFTI_NO_ERROR)
           status = DftiSetValue(the_descriptor, DFTI_PLACEMENT, (p->ri == p->ro ? DFTI_INPLACE : DFTI_NOT_INPLACE));
         if (status == DFTI_NO_ERROR)
           status = DftiCommitDescriptor(the_descriptor);
         if (status != DFTI_NO_ERROR) {
           status = DftiFreeDescriptor(&the_descriptor);
           X(ifree)(istride);
           X(ifree)(ostride);
           X(ifree)(ranks);
           return NULL;
         }
       } else {
         X(ifree)(istride);
         X(ifree)(ostride);
         X(ifree)(ranks);
         return NULL;
       }

       pln->the_descriptor = the_descriptor;
       pln->istride = istride;
       pln->ostride = ostride;
       pln->ranks = ranks;
     }

     d = p->sz->dims;

     pln->k = ego->k;
     pln->n = d[0].n;
     pln->is = X(mkstride)(e->sz, d[0].is);
     pln->os = X(mkstride)(e->sz, d[0].os);

     X(tensor_tornk1)(p->vecsz, &pln->vl, &pln->ivs, &pln->ovs);
     pln->slv = ego;

     X(ops_zero)(&pln->super.super.ops);
     X(ops_madd2)(pln->vl / e->genus->vl, &e->ops, &pln->super.super.ops);
     //printf("%s (%d): I have a plan\n", __PRETTY_FUNCTION__, __LINE__);
     return &(pln->super.super);
}

solver *X(mksolver_dft_direct_intel_mkl)(kdft_intel_mkl k, const kdft_desc *desc)
{
     static const solver_adt sadt = { PROBLEM_DFT, mkplan, 0 };
     S *slv = MKSOLVER(S, &sadt);
     slv->k = k;
     slv->desc = desc;
     return &(slv->super);
}
#endif

