AM_CPPFLAGS = -I$(top_srcdir)/kernel
SUBDIRS = scalar simd intel

noinst_LTLIBRARIES = libdft.la

# pkgincludedir = $(includedir)/fftw3@PREC_SUFFIX@
# pkginclude_HEADERS = codelet-dft.h dft.h

if HAVE_INTEL_MKL
MKL_SOURCES=direct-intel-mkl.c kdft-intel-mkl.c
else
MKL_SOURCES=
endif

libdft_la_SOURCES = bluestein.c buffered.c conf.c ct.c dftw-direct.c	\
dftw-directsq.c dftw-generic.c dftw-genericbuf.c direct.c generic.c	\
indirect.c indirect-transpose.c kdft-dif.c kdft-difsq.c kdft-dit.c	\
kdft.c nop.c plan.c problem.c rader.c rank-geq2.c solve.c vrank-geq1.c	\
zero.c codelet-dft.h ct.h dft.h $(MKL_SOURCES)

libdft_la_CFLAGS= @MKL_INCDIR@
