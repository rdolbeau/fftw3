SIMD_HEADER=simd-generic128d.h

include $(top_srcdir)/dft/simd/codlist.mk
include $(top_srcdir)/dft/simd/simd.mk

if HAVE_GENERIC128D

BUILT_SOURCES = $(EXTRA_DIST)
noinst_LTLIBRARIES = libdft_generic128d_codelets.la
libdft_generic128d_codelets_la_SOURCES = $(BUILT_SOURCES)

endif
