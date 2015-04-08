SIMD_HEADER=simd-generic128d.h

include $(top_srcdir)/rdft/simd/codlist.mk
include $(top_srcdir)/rdft/simd/simd.mk

if HAVE_GENERIC128D

noinst_LTLIBRARIES = librdft_generic128d_codelets.la
BUILT_SOURCES = $(EXTRA_DIST)
librdft_generic128d_codelets_la_SOURCES = $(BUILT_SOURCES)

endif
