This is a fork of the official FFTW3 repository at <https://github.com/FFTW/fftw3> including support for the Knight Corner Vector Instruction for the Xeon Phi, AVX2 (FMA, really) from Haswell and AVX-512 from the upcoming Knight Landing.

# How to use it

## 4th Gen Core Processor a.k.a. "Haswell"

For the common case of using the newer FMA (Fused Multiply Add) instructions in the 'Haswell' family of processors http://ark.intel.com/products/codename/42174/Haswell, then you just need to add --enable-avx2 to the configure command line (and make sure you use a compiler with avx2 & FMA support). The official FFTW documentation is here: http://www.fftw.org/doc .

Example:
./configure --prefix=/usr/local/fftw3-avx2-bin --enable-shared --enable-sse2 --enable-avx --enable-avx2 --enable-fma --enable-maintainer-mode

Some benchmark results are at <http://www.dolbeau.name/dolbeau/fftw3/fftw3.html>

## Knights Landing 

For the upcoming AVX3.1 / AVX-512F instruction set from Knights Landing, things are a bit more complicated. First you need tools with AVX-512F support, and second you need either the hardware or an emulator. For all of that but the hardware, there is
the Intel Software Development Emulator at <http://software.intel.com/en-us/articles/intel-software-development-emulator>.

1. download the sde, the binutils and gcc with AVX-512F support;
2. configure and install the binutils with something like this:

        ./configure --prefix=/usr/local/binutils-avx512-mpx-sha --with-sysroot && make && make install

3. configure and install gcc with something like this:

        PATH=/usr/local/binutils-avx512-mpx-sha/bin:$PATH ../gcc/configure --prefix=/usr/local/gcc-avx512-mpx-sha --enable-languages=c,c++,fortran && make bootstrap && make install

4. build FFTW3 using the newly installed tools, like this:

        PATH=/usr/local/binutils-avx512-mpx-sha/bin:$PATH CC='/usr/local/gcc-avx512-mpx-sha/bin/gcc' CXX='/usr/local/gcc-avx512-mpx-sha/bin/g++' F77='/usr/local/gcc-avx512-mpx-sha/bin/gfortran' F90='/usr/local/gcc-avx512-mpx-sha/bin/gfortran' ./configure --prefix=/tmp/fftw3-avx512-bin --enable-shared --enable-avx512 --enable-fma --enable-maintainer-mode && PATH=/usr/local/binutils-avx512-mpx-sha/bin:$PATH make -j 5

5. extract the SDE somewhere

At that point, you should be able to run the recently built fftw-wisdom under the SDE, simulating a Knights Landing:

    /path/to/sde64 --knl -- ./tools/fftw-wisdom cof1024

But this will completely ignore the AVX-512F instructions, and return something looking like this:

    (fftw-3.3.4 fftw_wisdom #x2f603bcd #x662b1c27 #x17444b23 #xb984e420
      (fftw_codelet_t1_16 0 #x11048 #x11048 #x0 #x9208a52b #x2d2ad097 #x6067ffe4 #xcda7baf8)
      (fftw_codelet_n1_64 0 #x11048 #x11048 #x0 #x4fa8b2f3 #xd93af2ba #xec419f5a #xae14e9fd)
    )

That's because the emulated instructions are slow, and the 'patient' planner ignore them. If you force to use 'estimate' instead:

    /path/to/sde64 -knl -- ./tools/fftw-wisdom -e cof1024
    (fftw-3.3.4 fftw_wisdom #x2f603bcd #x662b1c27 #x17444b23 #xb984e420
      (fftw_codelet_n2fv_32_avx512 0 #x31bff #x31bff #x0 #xfacc7de5 #x6d194dae #x7a176acb #x2f7c1f25)
      (fftw_codelet_t3fv_32_avx512 0 #x31bff #x31bff #x0 #x9208a52b #x2d2ad097 #x6067ffe4 #xcda7baf8)
    )

