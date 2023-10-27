* The GCC/binutils/newlib monorepo for ARM and MIPS

Initially based on commits from arm-gcc release:

```
*************************************************
GNU Tools for Arm Embedded Processors 8
                               - Q3 2019
*************************************************

This release includes the following items:
* Bare metal EABI pre-built binaries for running on a Windows host
* Bare metal EABI pre-built binaries for running on a Linux host
* Bare metal EABI pre-built binaries for running on a Mac OS X host
* Source code package (together with build scripts and instructions to setup
  build environment), composed of:

  * gcc : gcc-8-branch revision 273027
    svn://gcc.gnu.org/svn/gcc/branches/gcc-8-branch

  * binutils : 2.32 with mainline backports
    git://sourceware.org/git/binutils-gdb.git commit 2ab3145b4fae077dccd8a93078eeaec038f7126d

  * newlib and newlib-nano :
    git://sourceware.org/git/newlib-cygwin.git commit fff17ad73f6ae6b75ef293e17a837f23f6134753

  * gdb : 8.3 without target sim support
    git://sourceware.org/git/binutils-gdb.git commit 66263c8cdba32ef18ae0dfabde0867b9b850c441

Note that some or all of the following prerequisites are downloaded when
building from source:

  * EnvVarUpdate NSIS script :
    http://nsis.sourceforge.net/mediawiki/images/a/ad/EnvVarUpdate.7z

  * expat 2.1.1 :
    http://jaist.dl.sourceforge.net/project/expat/expat/2.1.1/expat-2.1.1.tar.bz2

  * gmp 6.1.0 : ftp://gcc.gnu.org/pub/gcc/infrastructure/gmp-6.1.0.tar.bz2

  * isl 0.15 : ftp://gcc.gnu.org/pub/gcc/infrastructure/isl-0.15.tar.bz2

  * libelf 0.8.13 : https://fossies.org/linux/misc/old/libelf-0.8.13.tar.gz

  * libiconv 1.14 :
    http://ftp.gnu.org/gnu/libiconv/libiconv-1.14.tar.gz

  * mpc 1.0.3 : ftp://gcc.gnu.org/pub/gcc/infrastructure/mpc-1.0.3.tar.gz

  * mpfr 3.1.4 : ftp://gcc.gnu.org/pub/gcc/infrastructure/mpfr-3.1.4.tar.bz2

  * python 2.7.13 : https://www.python.org/ftp/python/2.7.13/python-2.7.13.msi

  * zlib 1.2.8
    http://sourceforge.net/projects/libpng/files/zlib/1.2.8/zlib-1.2.8.tar.gz/download

```


