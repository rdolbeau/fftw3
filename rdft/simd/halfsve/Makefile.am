gM_CFLAGS = $(SVE_CFLAGS)
SIMD_HEADER=simd-support/simd-halfsve.h

include $(top_srcdir)/rdft/simd/codlist.mk
include $(top_srcdir)/rdft/simd/simd.mk

if HAVE_HALF_SVE

noinst_LTLIBRARIES = librdft_halfsve_codelets.la
BUILT_SOURCES = $(EXTRA_DIST)
librdft_halfsve_codelets_la_SOURCES = $(BUILT_SOURCES)

endif
