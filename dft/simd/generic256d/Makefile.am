SIMD_HEADER=simd-generic256d.h

include $(top_srcdir)/dft/simd/codlist.mk
include $(top_srcdir)/dft/simd/simd.mk

if HAVE_GENERIC256D

BUILT_SOURCES = $(EXTRA_DIST)
noinst_LTLIBRARIES = libdft_generic256d_codelets.la
libdft_generic256d_codelets_la_SOURCES = $(BUILT_SOURCES)

endif
