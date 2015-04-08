#include "ifftw.h"

#ifdef HAVE_INTEL_MKL

extern void X(codelet_n1mkl_generic)(planner *);


extern const solvtab X(solvtab_dft_mkl);
const solvtab X(solvtab_dft_mkl) = {
   SOLVTAB(X(codelet_n1mkl_generic)),
   SOLVTAB_END
};

#endif
