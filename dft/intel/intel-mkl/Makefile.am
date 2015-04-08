###########################################################################
AM_CPPFLAGS = -I$(top_srcdir)/kernel -I$(top_srcdir)/dft
noinst_LTLIBRARIES = libdft_codelets_mkl.la

###########################################################################
N1MKL_CODELETS=n1mkl_generic.c


###########################################################################
MKL_CODELETS = $(N1MKL_CODELETS)

if HAVE_INTEL_MKL
ALL_CODELETS = $(MKL_CODELETS)
else
ALL_CODELETS = 
endif

EXTRA_DIST = $(MKL_CODELETS)
BUILT_SOURCES= $(ALL_CODELETS) $(CODLIST)

libdft_codelets_mkl_la_SOURCES = $(BUILT_SOURCES)

libdft_codelets_mkl_la_CFLAGS  = @MKL_INCDIR@

XRENAME=X
SOLVTAB_NAME = X(solvtab_dft_mkl)

# special rules for regenerating codelets.
include $(top_srcdir)/support/Makefile.codelets

