AM_CFLAGS = $(SVE_CFLAGS)
SIMD_HEADER=simd-support/simd-halfsve.h

include $(top_srcdir)/dft/simd/codlist.mk
include $(top_srcdir)/dft/simd/simd.mk

if HAVE_HALF_SVE

BUILT_SOURCES = $(EXTRA_DIST)
noinst_LTLIBRARIES = libdft_halfsve_codelets.la
libdft_halfsve_codelets_la_SOURCES = $(BUILT_SOURCES)

endif
