AM_CPPFLAGS = -I$(top_srcdir)/kernel -I$(top_srcdir)/dft
SUBDIRS = intel-mkl

noinst_LTLIBRARIES = libdft_intel.la

libdft_intel_la_SOURCES = intel.c
libdft_intel_la_CFLAGS= @MKL_INCDIR@

