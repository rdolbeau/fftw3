SIMD_HEADER=simd-generic256d.h

include $(top_srcdir)/rdft/simd/codlist.mk
include $(top_srcdir)/rdft/simd/simd.mk

if HAVE_GENERIC256D

noinst_LTLIBRARIES = librdft_generic256d_codelets.la
BUILT_SOURCES = $(EXTRA_DIST)
librdft_generic256d_codelets_la_SOURCES = $(BUILT_SOURCES)

endif
