This is a fork of the official FFTW3 repository at <https://github.com/FFTW/fftw3> including support for the Knight Corner Vector Instruction for the Xeon Phi, AVX2 (FMA, really) from Haswell and AVX-512 from the upcoming Knight Landing.

#How to use it

For the common case of using the newer FMA (Fused Multiply Add) instructions in the 'Haswell' family of processors http://ark.intel.com/products/codename/42174/Haswell, then you just need to add --enable-avx2 to the configure command line (and make sure you use a compiler with avx2 & FMA support). The official FFTW documentation is here: http://www.fftw.org/doc .

Example:
./configure --prefix=/usr/local/fftw3-avx2-bin --enable-shared --enable-sse2 --enable-avx --enable-avx2 --enable-fma --enable-maintainer-mode

Some benchmark results are at <http://www.dolbeau.name/dolbeau/fftw3/fftw3.html>
