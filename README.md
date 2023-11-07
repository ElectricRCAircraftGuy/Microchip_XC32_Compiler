
_Tested on Linux Ubuntu 22.04 with `gcc --version` `gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0`_


## Build steps

Build Steps to build your own custom XC32 compiler with*out* having to buy a license. The "Licensed" code is, after-all, GPL, so we can build it ourselves.

1. Create a free Microchip account, and download the code here: https://www.microchip.com/en-us/tools-resources/archives/mplab-ecosystem#Source%20Archives --> go to the last page under "Source Archives" and download the latest version of the "MPLAB XC32 Compiler" source code--ex: v4.35.

1. Download and extract the source code

    ```bash
    # download the compiler source code zip file
    wget https://ww1.microchip.com/downloads/aemDocuments/documents/DEV/ProductDocuments/SoftwareTools/xc32-v4.35-src.zip

    # unzip it
    sudo apt install unar
    time unar xc32-v4.35-src.zip
    # delete the original zip file
    rm xc32-v4.35-src.zip 

    # Extract all 3 of the tar files in parallel
    cd xc32-v4.35-src
    # time tar -xf *.tar.bz2  # this does in series
    # See here for parallel: https://stackoverflow.com/a/76910116/4561887
    time find . -maxdepth 1 -type f -iname "*.tar.bz2" -print0 | xargs -0 -I{} \
        -n 1 -P $(nproc) tar -xf {}  # takes ~1min on a really fast machine with SSD

    # delete the tar files
    rm *.tar.bz2

    # check everything into git
    git add -A
    git commit
    ```

1. Install dependencies

    ```bash    
    # Build the PDF build manual
    # This produces:
    #
	#   How-to-build-toolchain.aux
	#   How-to-build-toolchain.log
	#   How-to-build-toolchain.pdf <== let's just commit this one
	#   How-to-build-toolchain.toc
    #
    cd xc32-v4.35-src/pic32m-source/build-manual/
    make

    # Now follow **some of** the steps outlined in How-to-build-toolchain.pdf

    sudo apt update
    sudo apt install -y \
        gcc-mingw-w64-i686 \
        g++-mingw-w64-i686 \
        binutils-mingw-w64-i686 \
        gcc-mingw-w64 \
        mingw-w64
    # Note: `gcc-mingw-64` includes: binutils-mingw-w64-x86-64 gcc-mingw-w64-x86-64
    # gcc-mingw-w64-x86-64-posix gcc-mingw-w64-x86-64-posix-runtime gcc-mingw-w64-x86-64-win32
    # gcc-mingw-w64-x86-64-win32-runtime mingw-w64-x86-64-dev

    # Use `-f` here to try to automatically "fix broken" packages
    sudo apt -f install -y \
        apt-src \
        autoconf \
        autogen \
        bison \
        dejagnu \
        flex \
        flip \
        gawk \
        git \
        gperf \
        gzip \
        nsis \
        openssh-client \
        p7zip-full \
        perl \
        libisl-dev \
        scons \
        tcl \
        texinfo \
        tofrodos \
        wget \
        zip \
        texlive \
        texlive-extra-utils
    
    ########### maybe not
    # GS: pretend that automake-1.15 is installed on your system, since the build wants it to exist
    automake-1.15 --version  # first, test if it exists
    # if it does NOT exist, create a symlink to pretend it does
    ln -si /usr/bin/automake ~/bin/automake-1.15
    # Test it; version should be whatever `automake --version` would return
    automake-1.15 --version

    # Do the same thing with some other tools too for which I'm gettin a `command now found` 
    # error during building
    ln -si /usr/bin/aclocal ~/bin/aclocal-1.14
    ln -si /usr/bin/automake ~/bin/automake-1.14
    ```

1. Try to configure and build gcc (for PIC32M mcus only, not PIC32C yet--that's in the other dir)

    From GitHub Copilot:

    > The `--target` option specifies the platform **for which** the software is being built [ex: PIC32 mcu], the `--build` option specifies the platform **on which** the software is being built [ex: Linux], and the `--host` option specifies the platform **on which** the software will be **run** [ex: Linux, mingw32, etc.].

    ```bash
    cd path/to/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source
    mkdir build
    cd build

    ../gcc/configure -h  # help menu

    # Configure cmd for Linux; takes ~1 sec
    # Note: I came up with `v4.35_custom` myself, since it's based on v4.35.
    time ../gcc/configure --prefix=$HOME/.local/gcc_xc32 \
        CFLAGS="-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4" \
        CXXFLAGS="-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4" \
        --target=pic32mx --build=x86_64-linux-gnu --host=x86_64-linux-gnu \
        --enable-languages=c,c++

    time ../gcc/configure --prefix=$HOME/.local/gcc_xc32 \
        CFLAGS='-DSKIP_LICENSE_MANAGER=1 -DMCHP_VERSION=v4.35-Custom -DNATIVE_SYSTEM_HEADER_DIR=/usr/include' \
        CXXFLAGS='-DSKIP_LICENSE_MANAGER=1 -DMCHP_VERSION=v4.35-Custom -DNATIVE_SYSTEM_HEADER_DIR=/usr/include' \
        --target=pic32mx --build=x86_64-linux-gnu --host=x86_64-linux-gnu \
        --enable-languages=c,c++

# -DMCHP_VERSION="v4.35-Custom":  <=== NEVERMIND!
https://embeddedfreak.wordpress.com/2008/10/10/compiling-mplab-c30-v311b-under-linux/

    time ../gcc/configure --prefix=$HOME/.local/gcc_xc32 \
        CFLAGS='-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4 -DNATIVE_SYSTEM_HEADER_DIR=/usr/include' \
        CXXFLAGS='-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4 -DNATIVE_SYSTEM_HEADER_DIR=/usr/include' \
        --target=pic32mx --build=x86_64-linux-gnu --host=x86_64-linux-gnu \
        --enable-languages=c,c++

cd gcc/mpfr
aclocal --force
automake

then reconfigure and rebuild

time make -j$(nproc)

Add more defines


# gcc `configure` manual: https://gcc.gnu.org/install/configure.html 

time ../gcc/configure --prefix=$HOME/.local/gcc_xc32 \
        CFLAGS='-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4' \
        CXXFLAGS='-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4' \
        --target=pic32mx --build=x86_64-linux-gnu --host=x86_64-linux-gnu \
        --enable-languages=c,c++  --with-native-system-header-dir=/usr/include


# Where to get the c30_resource dir?
https://forum.microchip.com/s/topic/a5C3l000000MFlyEAG/t290690


time ../gcc/configure --prefix=./opt \
        CFLAGS='-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4' \
        CXXFLAGS='-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4' \
        --target=pic32mx --build=x86_64-linux-gnu --host=x86_64-linux-gnu \
        --enable-languages=c,c++  --with-native-system-header-dir=/usr/include


# see how (with what options and defines) the existing compiler was built!
# (see below!)
xc32-gcc -v
xc32-g++ -v

time ../gcc/configure --prefix=$PWD/opt \
        CFLAGS='-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4' \
        CXXFLAGS='-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4' \
        --target=pic32mx --build=x86_64-linux-gnu --host=x86_64-linux-gnu \
        --enable-languages=c,c++  \
        --with-sysroot=$PWD/opt/pic32mx


# [ ] TODO: try removing `-D_XC32_VERSION_=4` and use `--with-pkgversion='Microchip XC32 Compiler v4.35 CUSTOM BUILD'` instead

# [ ] TODO: Remove `host-lm.h` references since the file doesn't seem to exist!
rg 'host-lm.h' ..

# Actually, let's just arbitrarily create a dummy version of this file instead!
echo "/* dummy file */" > path/to/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/gcc/config/pic32m/host-lm.h
# from in the build dir:
echo "/* dummy file */" > ../gcc/gcc/config/pic32m/host-lm.h
# into build dir directly (maybe this is all that's needed instead of the one above?)
echo "/* dummy file */" > host-lm.h

# nah...try removing this instead
rg 'host-lm.h' ..
# and
rg -iF 'license manager' ..
# Modify "../binutils/ld/mchp/rules.mk" to comment this out: <======
#       
#       # Needed for the license manager
#       ldlang.o: CPPFLAGS += -imacros host-lm.h
#       pic32-license-manager.o: CPPFLAGS += -imacros host-lm.h
#       
# comment out similar chunks in t-mchp and t-pic32c files  <======

# To make `#if defined(TARGET_MCHP_PIC32MX)` true on line 3396 of `gcc/gcc/config/mips/mips.h`, so that `vector_dispatch` gets defined in a particular struct
#       ../../gcc/gcc/config/mips/mips.c: In function ‘bool mips_can_use_return_insn()’:
#       ../../gcc/gcc/config/mips/mips.c:13160:22: error: ‘struct machine_function’ has no member named ‘vector_dispatch’
#       13160 |   if (cfun->machine->vector_dispatch)
#             |                      ^~~~~~~~~~~~~~~
#       

time ../gcc/configure --prefix=$PWD/opt \
        CFLAGS='-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4 -DTARGET_MCHP_PIC32MX' \
        CXXFLAGS='-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4 -DTARGET_MCHP_PIC32MX' \
        --target=pic32mx --build=x86_64-linux-gnu --host=x86_64-linux-gnu \
        --enable-languages=c,c++  \
        --with-sysroot=$PWD/opt/pic32mx


Error:
```
../../gcc/gcc/config/pic32m/mchp.c:119:10: fatal error: smartio_suffix.h: No such file or directory
  119 | #include "smartio_suffix.h"
      |          ^~~~~~~~~~~~~~~~~~
compilation terminated.
```
# solve with a -I include, like this maybe:

time ../gcc/configure --prefix=$PWD/opt \
        CFLAGS="-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4 -DTARGET_MCHP_PIC32MX \
            -I$PWD/../mchp" \
        CXXFLAGS="-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4 -DTARGET_MCHP_PIC32MX \
            -I$PWD/../mchp" \
        --target=pic32mx --build=x86_64-linux-gnu --host=x86_64-linux-gnu \
        --enable-languages=c,c++  \
        --with-sysroot=$PWD/opt/pic32mx

# My c30_resource dir is way out of date; get the new one. Perhaps here: https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/downloads-documentation#XC32 --> download "32-Bit Language Tools Libraries" and "MPLAB XC32 Users Guide for Embedded Engineers - Code Examples" maybe.

Get it here in the links in the posts: https://forum.microchip.com/s/topic/a5C3l000000MUP5EAO/t346931
Ex: "xc32-v4.30-c30_resource.tar": https://forum.microchip.com/s/topic/a5C3l000000MUP5EAO/t346931?comment=P-2926726

And for super old compiler 1.42, see JasonK's links here: https://forum.microchip.com/s/topic/a5C3l000000MXp7EAG/t360077?comment=P-2750661. Open a support ticket if you need to.

Support Case Number :  01358891 opened 28 Oct. 2023.
Subject: Need c30_resource directory for xc32 v4.35 compiler
I will post my file here when I get it: https://forum.microchip.com/s/topic/a5C3l000000MUP5EAO/t346931

# Fix this: 
../../gcc/gcc/config/pic32m/mchp.c: In function ‘unsigned int mchp_load_resource_info(const char*, char**, const char*)’:
../../gcc/gcc/config/pic32m/mchp.c:676:54: error: invalid conversion from ‘const char*’ to ‘char*’ [-fpermissive]
  676 |   rib = read_device_rib (mchp_resource_file_generic, id);
      |                                                      ^~
      |                                                      |
      |                                                      const char*

# like this (add a define for `TARGET_IS_PIC32MX`):

time ../gcc/configure --prefix=$PWD/opt \
        CFLAGS="-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4 \
            -DTARGET_MCHP_PIC32MX -DTARGET_IS_PIC32MX \
            -I$PWD/../mchp" \
        CXXFLAGS="-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=4 \
            -DTARGET_MCHP_PIC32MX -DTARGET_IS_PIC32MX \
            -I$PWD/../mchp" \
        --target=pic32mx --build=x86_64-linux-gnu --host=x86_64-linux-gnu \
        --enable-languages=c,c++  \
        --with-sysroot=$PWD/opt/pic32mx

# Archive (`ar`) error: 
x86_64-linux-gnu-ar: mchp-license-manager.o: No such file or directory

# Let's remove that `mchp-license-manager.o` file entry from `../gcc/gcc/config.gcc`:

# ...uh oh. Other code calls functions in these files. Linker fails. 
```
rochip_XC32_Compiler/xc32-v4.35-src/pic32m-source/build/./mpc/src/.libs -lmpc -lmpfr -lgmp -rdynamic  -L./../zlib -lz -lexpat
/usr/bin/ld: xc-coverage.o: in function `xccov_init_pdata()':
xc-coverage.c:(.text+0x774): undefined reference to `pic32_licensed_xccov_p()'
/usr/bin/ld: mips.o: in function `mips_option_override()':
mips.c:(.text+0x3d70a): undefined reference to `mchp_subtarget_override_options_license()'
/usr/bin/ld: mips.o:(.data+0x770): undefined reference to `mchp_override_options_after_change()'
/usr/bin/ld: mchp.o: in function `maybe_get_smartio_name(char const*)':
mchp.c:(.text+0xca4f): undefined reference to `get_suffix_info'
/usr/bin/ld: mchp.c:(.text+0xca81): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xca88): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcaa1): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcaa8): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcac1): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcac8): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcae1): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcae8): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcb01): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcb08): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcb21): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcb28): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcb41): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcb48): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcb61): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcb68): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcb81): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcb88): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcba1): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcba8): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcbc1): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcbc8): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcbe1): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcbe8): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcc01): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcc08): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcc21): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcc28): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcc41): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcc48): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcc61): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcc68): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcc81): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcc88): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcca1): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xcca8): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xccbb): undefined reference to `sio_map_char'
/usr/bin/ld: mchp.c:(.text+0xccc2): undefined reference to `sio_suffix_bit'
/usr/bin/ld: mchp.c:(.text+0xcccb): undefined reference to `num_suffixes'
collect2: error: ld returned 1 exit status
make[2]: *** [../../gcc/gcc/c/Make-lang.in:85: cc1] Error 1
make[2]: Leaving directory '/home/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/build/gcc'
make[1]: *** [Makefile:4283: all-gcc] Error 2
make[1]: Leaving directory '/home/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/build'
make: *** [Makefile:916: all] Error 2
```

# So, let's *undo* the mods above and put this license stuff back in, but hard code any necessary functions to just say we have the license; ex: `return true;` or whatever.







    # Takes ~?? (several minutes)
    time make -j$(nproc)

    sudo make install
    ```

```bash
# UPDATE: DO THIS INSTEAD! Script straight from Microchip!
# - takes only 3.5 min. on a really fast machine!
time ./build-xc32-v4.35.sh
```



## Scratch notes

```bash
# Install dependencies (I'm not 100% sure if all of these are needed, nor if I'm
# missing any in this list)
sudo apt update
sudo apt install \
    build-essential \
    libxml2-utils \
    libgmp-dev \
    flex \
    bison++
```

Install autoconf 2.64 from here: https://ftp.gnu.org/gnu/autoconf/
```bash
./configure
make
make distcheck  # run tests on your system
# bin is in /home/gabriel/Downloads/Install_Files/gcc/autoconf-2.64/bin/autoreconf
```

cd into gcc dir, then:
time /home/gabriel/Downloads/Install_Files/gcc/autoconf-2.64/bin/autoreconf -vfi

```bash
$ /opt/microchip/xc32/v4.35/bin/xc32-gcc -v
Microchip Language Tool Shell Version 4.35 (Build date: Aug 28 2023).
Copyright (c) 2012-2017 Microchip Technology Inc. All rights reserved
Using built-in specs.
Reading specs from /opt/microchip/xc32/v4.35/bin/bin/../../lib/gcc/pic32mx/8.3.1/../../../../pic32mx/lib/pic32m.musl.specs
rename spec link to old_link
COLLECT_GCC=/opt/microchip/xc32/v4.35/bin/bin/pic32m-gcc
COLLECT_LTO_WRAPPER=/opt/microchip/xc32/v4.35/bin/bin/gcc/pic32mx/8.3.1/lto-wrapper
Target: pic32mx
Configured with: /home/jenkins/agent/workspace/XC32/release-XC32_4.35/src/xc32-gcc/gcc/configure --target=pic32mx --prefix=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt --program-prefix=pic32m- --with-sysroot=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/pic32mx --with-bugurl=http://www.microchip.com/support --with-pkgversion='Microchip XC32 Compiler v4.35' --bindir=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/bin/bin --infodir=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/share/doc/xc32-pic32m-gcc/info --mandir=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/share/doc/xc32-pic32m-gcc/man --libdir=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/lib --libexecdir=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/bin/bin --with-build-sysroot=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/pic32mx --enable-stage1-languages=c --enable-languages=c,c++ --enable-target-optspace --disable-comdat --disable-libstdcxx-pch --disable-libstdcxx-verbose --disable-libssp --disable-libmudflap --disable-libffi --disable-libfortran --disable-bootstrap --disable-shared --disable-nls --disable-gdb --disable-libgomp --disable-threads --disable-sim --disable-decimal-float --disable-libquadmath --disable-shared --disable-checking --disable-maintainer-mode --enable-lto --enable-fixed-point --enable-gofast --enable-static --enable-sgxx-sde-multilibs --enable-sjlj-exceptions --enable-poison-system-directories --enable-obsolete --without-isl --without-cloog --without-headers --with-musl --with-dwarf2 --with-gnu-as --with-gnu-ld --with-host-libstdcxx='-static-libgcc -static-libstdc++ -Wl,-lstdc++ -lm' CC_FOR_TARGET=pic32m-gcc CXX_FOR_TARGET=pic32m-g++ AS_FOR_TARGET=pic32m-as AR_FOR_TARGET=pic32m-ar LD_FOR_TARGET=pic32m-ld NM_FOR_TARGET=pic32m-nm OBJCOPY_FOR_TARGET=pic32m-objcopy OBJDUMP_FOR_TARGET=pic32m-objdump RANLIB_FOR_TARGET=pic32m-ranlib READELF_FOR_TARGET=pic32m-readelf STRIP_FOR_TARGET=pic32m-strip 'XGCC_FLAGS_FOR_TARGET=-fno-enforce-eh-specs -mno-smart-io' 'CFLAGS_FOR_TARGET=-O2 -mno-smart-io -fomit-frame-pointer -mchp-stack-usage' 'CXXFLAGS_FOR_TARGET=-O2 -mno-smart-io -fomit-frame-pointer -mchp-stack-usage -frtti -fexceptions -fno-enforce-eh-specs' CXX=g++ CC=gcc CPP=cpp CPPFLAGS='-I/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/pic32m-build/opt/include -imacros host-defs.h' CFLAGS='-m64 -g -fdebug-prefix-map=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/src=/xc32/src -fdebug-prefix-map=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/pic32m-build=/xc32/pic32m-build' CXXFLAGS='-m64 -g -fdebug-prefix-map=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/src=/xc32/src -fdebug-prefix-map=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/pic32m-build=/xc32/pic32m-build' LDFLAGS=-L/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/pic32m-build/opt/lib
Thread model: single
gcc version 8.3.1 (Microchip XC32 Compiler v4.35) 
```

```bash
$ /opt/microchip/xc32/v4.35/bin/xc32-g++ -v
Microchip Language Tool Shell Version 4.35 (Build date: Aug 28 2023).
Copyright (c) 2012-2017 Microchip Technology Inc. All rights reserved
Using built-in specs.
Reading specs from /opt/microchip/xc32/v4.35/bin/bin/../../lib/gcc/pic32mx/8.3.1/../../../../pic32mx/lib/pic32m.musl.specs
rename spec link to old_link
COLLECT_GCC=/opt/microchip/xc32/v4.35/bin/bin/pic32m-g++
COLLECT_LTO_WRAPPER=/opt/microchip/xc32/v4.35/bin/bin/gcc/pic32mx/8.3.1/lto-wrapper
Target: pic32mx
Configured with: /home/jenkins/agent/workspace/XC32/release-XC32_4.35/src/xc32-gcc/gcc/configure --target=pic32mx --prefix=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt --program-prefix=pic32m- --with-sysroot=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/pic32mx --with-bugurl=http://www.microchip.com/support --with-pkgversion='Microchip XC32 Compiler v4.35' --bindir=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/bin/bin --infodir=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/share/doc/xc32-pic32m-gcc/info --mandir=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/share/doc/xc32-pic32m-gcc/man --libdir=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/lib --libexecdir=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/bin/bin --with-build-sysroot=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/opt/pic32mx --enable-stage1-languages=c --enable-languages=c,c++ --enable-target-optspace --disable-comdat --disable-libstdcxx-pch --disable-libstdcxx-verbose --disable-libssp --disable-libmudflap --disable-libffi --disable-libfortran --disable-bootstrap --disable-shared --disable-nls --disable-gdb --disable-libgomp --disable-threads --disable-sim --disable-decimal-float --disable-libquadmath --disable-shared --disable-checking --disable-maintainer-mode --enable-lto --enable-fixed-point --enable-gofast --enable-static --enable-sgxx-sde-multilibs --enable-sjlj-exceptions --enable-poison-system-directories --enable-obsolete --without-isl --without-cloog --without-headers --with-musl --with-dwarf2 --with-gnu-as --with-gnu-ld --with-host-libstdcxx='-static-libgcc -static-libstdc++ -Wl,-lstdc++ -lm' CC_FOR_TARGET=pic32m-gcc CXX_FOR_TARGET=pic32m-g++ AS_FOR_TARGET=pic32m-as AR_FOR_TARGET=pic32m-ar LD_FOR_TARGET=pic32m-ld NM_FOR_TARGET=pic32m-nm OBJCOPY_FOR_TARGET=pic32m-objcopy OBJDUMP_FOR_TARGET=pic32m-objdump RANLIB_FOR_TARGET=pic32m-ranlib READELF_FOR_TARGET=pic32m-readelf STRIP_FOR_TARGET=pic32m-strip 'XGCC_FLAGS_FOR_TARGET=-fno-enforce-eh-specs -mno-smart-io' 'CFLAGS_FOR_TARGET=-O2 -mno-smart-io -fomit-frame-pointer -mchp-stack-usage' 'CXXFLAGS_FOR_TARGET=-O2 -mno-smart-io -fomit-frame-pointer -mchp-stack-usage -frtti -fexceptions -fno-enforce-eh-specs' CXX=g++ CC=gcc CPP=cpp CPPFLAGS='-I/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/pic32m-build/opt/include -imacros host-defs.h' CFLAGS='-m64 -g -fdebug-prefix-map=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/src=/xc32/src -fdebug-prefix-map=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/pic32m-build=/xc32/pic32m-build' CXXFLAGS='-m64 -g -fdebug-prefix-map=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/src=/xc32/src -fdebug-prefix-map=/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/pic32m-build=/xc32/pic32m-build' LDFLAGS=-L/home/jenkins/agent/workspace/XC32/release-XC32_4.35/build/pic32m-build/opt/lib
Thread model: single
gcc version 8.3.1 (Microchip XC32 Compiler v4.35)
```

https://gist.github.com/kimushu/9d30c2e83a248d1b17c8806fa222354d


========================

Windows build instructions:

Install MSYS2: https://stackoverflow.com/a/77407282/4561887

Install Git Bash

```bash
# In a Git Bash terminal, clone the repo
# - takes 7~8 minutes on a really fast computer and internet connection
time git clone https://github.com/ElectricRCAircraftGuy/Microchip_XC32_Compiler.git


# In an MSYS UCRT64 terminal, cd into the repo and run the build script

cd path/to/Microchip_XC32_Compiler

gcc --version  # fails

# install build tools
# Read this page here: https://www.msys2.org/
# - takes ~1 min.
time pacman -S mingw-w64-ucrt-x86_64-gcc

# gcc --version now shows this:
$ gcc --version
gcc.exe (Rev2, Built by MSYS2 project) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# install make
time pacman -S make

# try to build; it works!??????
# - takes ~xx min.
time ./build-xc32-v4.35m.sh



# failed after 7m19 sec. 
  $restore $backupdir/* `echo "./bfd.info" | sed 's|[^/]*$||'`; \
fi; \
rm -rf $backupdir; exit $rc
/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/binutils/missing: line 81: makeinfo: command not found
WARNING: 'makeinfo' is missing on your system.
         You should only need it if you modified a '.texi' file, or
         any other file indirectly affecting the aspect of the manual.
         You might want to install the Texinfo package:
         <http://www.gnu.org/software/texinfo/>
         The spurious makeinfo call might also be the consequence of
         using a buggy 'make' (AIX, DU, IRIX), in which case you might
         want to install GNU make:
         <http://www.gnu.org/software/make/>
make[3]: *** [Makefile:541: bfd.info] Error 127
make[3]: Leaving directory '/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/binutils/bfd/doc'
make[2]: *** [Makefile:1642: info-recursive] Error 1
make[2]: Leaving directory '/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/binutils/bfd'
make[1]: *** [Makefile:2707: all-bfd] Error 2
make[1]: Leaving directory '/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/binutils'
make: *** [Makefile:865: all] Error 2

real    5m11.693s
user    0m15.065s
sys     2m24.404s
Error: [binutils] failed to build!

real    7m19.054s
user    0m18.238s
sys     2m49.267s

# try installing this
pacman -S binutils
# still no `makeinfo --help` cmd

pacman -S texinfo
# good! `makeinfo --help` works now!

# try again
time ./build-xc32-v4.35m.sh

# failed to build binutils; needs bison

# install bison
pacman -S bison

# try again
time ./build-xc32-v4.35m.sh

# Install dependencies

pacman -Ss autoconf
pacman -Ss autogen
pacman -Ss bison
pacman -Ss dejagnu
pacman -Ss flex
pacman -Ss gawk
pacman -Ss gperf
pacman -Ss gzip

pacman -Ss nsis
pacman -Ss openssh-client
pacman -Ss p7zip-full
pacman -Ss perl
pacman -Ss libisl-dev
pacman -Ss scons
pacman -Ss tcl
pacman -Ss texinfo
pacman -Ss tofrodos
pacman -Ss wget
pacman -Ss zip
pacman -Ss texlive
pacman -Ss texlive-extra-utils

package_list=(
    "autoconf"
    "autogen"
    "bison"
    "dejagnu"
    "flex"
    "gawk"
    "gperf"
    "gzip"
    "nsis"
    "openssh-client"
    "p7zip-full"
    "perl"
    "libisl-dev"
    "scons"
    "tcl"
    "texinfo"
    "tofrodos"
    "wget"
    "zip"
    "texlive"
    "texlive-extra-utils"
)

for package in "${package_list[@]}"; do
    if pacman -Ss $package > /dev/null; then
        echo "$package exists."
    else
        echo "$package does not exist."
    fi
done

# ============= DO THIS TO INSTALL ALL DEPENDENCIES AT ONCE! =============
# UCRT64
if [ "$MSYSTEM" != "UCRT64" ]; then
    echo "ERROR: You must run this script in an MSYS2 ucrt64 terminal!"
    exit 1
fi
package_list=(
    "mingw-w64-ucrt-x86_64-gcc" # specific version for MSYS2 ucrt64
    "mingw-w64-ucrt-x86_64-gmp" # specific version for MSYS2 ucrt64
    "gmp"
    "make"
    "binutils"
    "autoconf"
    "autogen"
    "bison"
    "dejagnu"
    "flex"
    "gawk"
    "gperf"
    "gzip"
    # "nsis" # generic; must be specific; hence the line below
    "mingw-w64-ucrt-x86_64-nsis" # specific version for MSYS2 ucrt64
    "perl"
    "scons"
    "tcl"
    "texinfo"
    "wget"
    "zip"
    # "texlive" # generic; must be specific; hence the line below
    "mingw-w64-ucrt-x86_64-texlive-core" # specific version for MSYS2 ucrt64
    # "texlive-extra-utils" # generic; must be specific; hence the line below
    "mingw-w64-ucrt-x86_64-texlive-extra-utils" # specific version for MSYS2 ucrt64
)

# Only install packages if tHey are NOT already installed. 
for package in "${package_list[@]}"; do
    if ! pacman -Qs $package > /dev/null; then
        echo -e "\n=== $package is not installed. Installing... ==="
        pacman -S --noconfirm $package
    else
        echo -e "\n=== $package is already installed. ==="
    fi
done
echo -e "\n=== Done installing packages! ===\n"

# 16 minutes in:
# binutils passed! But gcc failed to build :(
checking for processor_info... no
checking for pstat_getprocessor... no
checking for raise... yes
checking for read_real_time... no
checking for sigaction... no
checking for sigaltstack... no
checking for sigstack... no
checking for syssgi... no
checking for strchr... yes
checking for strerror... yes
checking for strnlen... yes
checking for strtol... yes
checking for strtoul... yes
checking for sysconf... no
checking for sysctl... no
checking for sysctlbyname... no
checking for times... no
checking for library containing clock_gettime... none required
checking for vsnprintf... yes
checking whether vsnprintf works... probably
configure: WARNING: cannot check for properly working vsnprintf when cross compiling, will assume it's ok
checking whether sscanf needs writable input... no
checking for struct pst_processor.psp_iticksperclktick... no
checking size of void *... 8
checking size of unsigned short... 2
checking size of unsigned... 4
checking size of unsigned long... 4
checking size of mp_limb_t... 0                  <=============== ITS SIZE IS 0!
configure: error: Oops, mp_limb_t doesn't seem to work
make: *** [Makefile:4701: configure-gmp] Error 1

real    2m54.851s
user    0m7.225s
sys     1m10.362s
Error: [gcc] failed to build!

real    2m57.085s
user    0m7.225s
sys     1m10.499s

# Let's try adding this to the gcc configure command!:
--build=x86_64-w64-mingw64 \

# trying again...
# NO CHANGE! SAME PROBLEM!

# But...running this manually *passed* that step!
UCRT64 ~/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/gmp
$ ../../../pic32m-source/gmp-6.1.0/configure

# try the quote in this answer here: https://stackoverflow.com/a/33875619/4561887
--build=x86_64-w64-mingw32 \
# Nah...that's the default! Just remove it. 

############

# Try building in the MSYS2 mingw64 terminal instead of the UCRT64 terminal

# ============= DO THIS TO INSTALL ALL DEPENDENCIES AT ONCE! =============
# mingw64
if [ "$MSYSTEM" != "MINGW64" ]; then
    echo "ERROR: You must run this script in an MSYS2 mingw64 terminal!"
    exit 1
fi
package_list=(
    "mingw-w64-x86_64-gcc" # specific version for MSYS2 mingw64
    "mingw-w64-x86_64-gmp" # specific version for MSYS2 mingw64
    "gmp"
    "make"
    "binutils"
    "autoconf"
    "autogen"
    "bison"
    "dejagnu"
    "flex"
    "gawk"
    "gperf"
    "gzip"
    # "nsis" # generic; must be specific; hence the line below
    "mingw-w64-x86_64-nsis" # specific version for MSYS2 mingw64
    "perl"
    "scons"
    "tcl"
    "texinfo"
    "wget"
    "zip"
    # "texlive" # generic; must be specific; hence the line below
    "mingw-w64-x86_64-texlive-core" # specific version for MSYS2 mingw64
    # "texlive-extra-utils" # generic; must be specific; hence the line below
    "mingw-w64-x86_64-texlive-extra-utils" # specific version for MSYS2 mingw64
)

# Only install packages if tHey are NOT already installed. 
for package in "${package_list[@]}"; do
    if ! pacman -Qs $package > /dev/null; then
        echo -e "\n=== $package is not installed. Installing... ==="
        pacman -S --noconfirm $package
    else
        echo -e "\n=== $package is already installed. ==="
    fi
done
echo -e "\n=== Done installing packages! ===\n"


# No change when building for `--build=x86_64-w64-mingw32`
# in the MINGW64 environment! Same error as before: 
checking for mprotect... yes
checking for nl_langinfo... no
checking for obstack_vprintf... no
checking for popen... yes
checking for processor_info... no
checking for pstat_getprocessor... no
checking for raise... yes
checking for read_real_time... no
checking for sigaction... no
checking for sigaltstack... no
checking for sigstack... no
checking for syssgi... no
checking for strchr... yes
checking for strerror... yes
checking for strnlen... yes
checking for strtol... yes
checking for strtoul... yes
checking for sysconf... no
checking for sysctl... no
checking for sysctlbyname... no
checking for times... no
checking for library containing clock_gettime... none required
checking for vsnprintf... yes
checking whether vsnprintf works... probably
configure: WARNING: cannot check for properly working vsnprintf when cross compiling, will assume it's ok
checking whether sscanf needs writable input... no
checking for struct pst_processor.psp_iticksperclktick... no
checking size of void *... 8
checking size of unsigned short... 2
checking size of unsigned... 4
checking size of unsigned long... 4
checking size of mp_limb_t... 0
configure: error: Oops, mp_limb_t doesn't seem to work
make: *** [Makefile:4701: configure-gmp] Error 1

real    2m48.255s
user    0m4.447s
sys     0m46.481s
Error: [gcc] failed to build!

real    2m48.486s
user    0m4.462s
sys     0m46.511s

# So, let's go back to the UCRT64 environment and try installing the 
# GMP 6.1.0 library from source, then try building again!
# Look for bugs & stuff: 
# 
# https://gmplib.org/#DOWNLOAD
# 
mkdir ~/Downloads/Install_Files/GMP
cd ~/Downloads/Install_Files/GMP
wget https://gmplib.org/download/gmp/gmp-6.1.2.tar.xz
tar -xvf gmp-6.1.2.tar.xz
cd gmp-6.1.2
mkdir build
cd build
time ../configure --build=x86_64-w64-mingw32
time make -j$(nproc)
time make check
# sudo make install

# At the end of `time ../configure`, you'll see this:
config.status: linking ../mpn/x86_64/aorrlsh2_n.asm to mpn/rsblsh2_n.asm
config.status: linking ../mpn/x86_64/k8/aorrlsh_n.asm to mpn/addlsh_n.asm
config.status: linking ../mpn/x86_64/k8/aorrlsh_n.asm to mpn/rsblsh_n.asm
config.status: linking ../mpn/generic/add_n_sub_n.c to mpn/add_n_sub_n.c
config.status: linking ../mpn/x86_64/k8/gmp-mparam.h to gmp-mparam.h
config.status: executing libtool commands
configure: summary of build options:

  Version:           GNU MP 6.1.2
  Host type:         x86_64-w64-mingw32
  ABI:               64
  Install prefix:    /ucrt64
  Compiler:          gcc
  Static libraries:  yes
  Shared libraries:  no


real    5m3.385s
user    0m4.486s
sys     0m34.609s

# make fails! Some problem with "C:/Program" not being found.
# UGH! Found it. It was my stupid alias hack in my ~/.bashrc file. I commented 
# it out:
#
# # alias make="'/c/Program Files/Microchip/MPLABX/v6.10/gnuBins/GnuWin32/bin/make.exe'"
time make -j$(nproc)

# I deleted the entire Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build dir and the output install dir, and am trying again now from scratch, this time with the right version of `make`, in the UCRT64 environment.
# Here are my detected `--build` and `--host` system types:
checking build system type... x86_64-w64-mingw32
checking host system type... x86_64-w64-mingw32

# I still get the same error when configuring gmp:
checking for sigaction... no
checking for sigaltstack... no
checking for sigstack... no
checking for syssgi... no
checking for strchr... yes
checking for strerror... yes
checking for strnlen... yes
checking for strtol... yes
checking for strtoul... yes
checking for sysconf... no
checking for sysctl... no
checking for sysctlbyname... no
checking for times... no
checking for library containing clock_gettime... none required
checking for vsnprintf... yes
checking whether vsnprintf works... probably
configure: WARNING: cannot check for properly working vsnprintf when cross compiling, will assume it's ok
checking whether sscanf needs writable input... no
checking for struct pst_processor.psp_iticksperclktick... no
checking size of void *... 8
checking size of unsigned short... 2
checking size of unsigned... 4
checking size of unsigned long... 4
checking size of mp_limb_t... 0
configure: error: Oops, mp_limb_t doesn't seem to work
make: *** [Makefile:4701: configure-gmp] Error 1

real    2m45.026s
user    0m0.137s
sys     0m2.398s
Error: [gcc] failed to build!

real    2m45.212s
user    0m0.137s
sys     0m2.413s

# possibly helpful:
# 1. https://www.google.com/search?q=checking+size+of+mp_limb_t...+0+configure%3A+error%3A+Oops%2C+mp_limb_t+doesn%27t+seem+to+work&oq=checking+size+of+mp_limb_t...+0+configure%3A+error%3A+Oops%2C+mp_limb_t+doesn%27t+seem+to+work&gs_lcrp=EgZjaHJvbWUyBggAEEUYOdIBBzY3OGowajeoAgCwAgA&sourceid=chrome&ie=UTF-8
# 1. https://github.com/JuliaLang/julia/issues/13206
#   1. https://github.com/JuliaLang/julia/issues/13206#issuecomment-141453337

# I think I found the problem!:
C:\Users\gabriel\GS\dev\Microchip_XC32_Compiler\xc32-v4.35-src\pic32m-build\gcc\gmp\config.log
# It shows:
configure:27426: checking size of mp_limb_t
configure:27431: gcc -c -g -O2 -D__USE_MINGW_ACCESS -DNO_ASM -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/opt/include -imacros host-defs.h conftest.c >&5
conftest.c:80:10: fatal error: /c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/gmp/gmp-h.in: No such file or directory
   80 | #include "/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/gmp/gmp-h.in"
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.

# Notice this!:
fatal error: /c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/gmp/gmp-h.in: No such file or directory

# I think it's a Windows symlink problem, since the gcc\gmp dir is a symlink to the gmp dir up one level!

# I'm going to try copying the gmp dir into the gcc dir and see if that fixes it. I should probably write a program that recreates symlinks in Windows, or something. Windows is dumb.

# This is useful
find . -type l | grep -vE 'pic32.*-build|\/installed\/' | sort -V

# ==> I put a comment here too: https://github.com/JuliaLang/julia/issues/13206#issuecomment-1791823912

pacman -S mingw-w64-ucrt-x86_64-gmp
pacman -S gmp

# add:
--build=x86_64-w64-mingw32 \
--host=x86_64-w64-mingw32 \

cp /c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/gmp/gmp-h.in /c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/opt/include

# in: C:\Users\gabriel\GS\dev\Microchip_XC32_Compiler\xc32-v4.35-src\pic32m-source\gcc\gmp\configure:
#
// #include "$srcdir/gmp-h.in"
#include "C:\Users\gabriel\GS\dev\Microchip_XC32_Compiler\xc32-v4.35-src\pic32m-source\gcc\gmp\gmp-h.in"

in aclocal.m4 and acinclude.m4: 
"C:\Users\gabriel\GS\dev\Microchip_XC32_Compiler\xc32-v4.35-src\pic32m-source\gcc\gmp\gmp-h.in"

finish the manual gmp install from source, and try again

../../pic32m-source/gcc/gmp

# I got pastthe gmp configure error I was on forever! This line is my fix inside `C:\Users\gabriel\GS\dev\Microchip_XC32_Compiler\xc32-v4.35-src\pic32m-build\gcc\Makefile`: make the path **relative**:
--srcdir="../../../pic32m-source/gcc/gmp" \

# NEXT:
# 1. [x] examine the original Microchip build script and see if it uses absolute or relative paths, and where; fix my script to follow suit. I may be going off in the wrong direction here accidentally having used absolute instead of relative paths. 
#   I checked: they use absolute too. 
# 1. [x] try to add the `realpath --relative-to=` thing to the build script itself, to convert all absolute paths to relative, where needed!
# 1. [no] Consider adding -I includes to the CPPFLAGS in the GCC build section of the script, to make sure it can find the gmp-h.in and other files.
# 1. [ ] UNDO THE Windows path thing I did, since I think it broke stuff (save it in a temp dir somewhere in the repo). 
# 1. [ ] make the absolute to relative path fix permanent in the build script somehow
    See: 
    ```bash
    /Microchip_XC32_Compiler
    $ /c/ProgramData/chocolatey/bin/rg -ilF 'topdir=$(srcdir)'
    ```

    Probably just forcefully edit it in the Makefile after generating it, by using 
        --srcdir=`realpath --relative-to="$(HOST_SUBDIR)/gmp" "$${topdir}/$$module_srcdir"` \
    instead of 
        --srcdir=$${topdir}/$$module_srcdir \



# -------[WORKED]--------
# trying to build on Windows now with this file: 
time ./build-xc32-v4.35m_relative_paths.sh

# IT GOT PAST THE GMP ERRORS! The fix was this to the build script:
    gcc_srcdir_RELATIVE=$(realpath --relative-to="." "${gcc_srcdir}")
    # ...
    ${gcc_srcdir_RELATIVE}/configure \ 
    # ...

# IMPORTANT (MAYBE???) I had done this too. Was this mistakenly part of the fix? I'll find out later when I try to build it again!
# In `xc32-v4.35-src/pic32m-source/gmp-6.1.0/acinclude.m4`, I made these changes manually too (changing just the `gmp-h.in` include in two places): 
$ git diff 'xc32-v4.35-src/pic32m-source/gmp-6.1.0/acinclude.m4'
diff --git a/xc32-v4.35-src/pic32m-source/gmp-6.1.0/acinclude.m4 b/xc32-v4.35-src/pic32m-source/gmp-6.1.0/acinclude.m4
index f6e8940ac..ec06c2af1 100644
--- a/xc32-v4.35-src/pic32m-source/gmp-6.1.0/acinclude.m4
+++ b/xc32-v4.35-src/pic32m-source/gmp-6.1.0/acinclude.m4
@@ -136,7 +136,7 @@ define(GMP_INCLUDE_GMP_H,
 #define GMP_NAIL_BITS $GMP_NAIL_BITS
 #define GMP_LIMB_BITS 123
 $DEFN_LONG_LONG_LIMB
-#include "$srcdir/gmp-h.in"]
+#include "C:\Users\gabriel\GS\dev\Microchip_XC32_Compiler\xc32-v4.35-src\pic32m-source\gcc\gmp\gmp-h.in"]
 ])


@@ -3563,7 +3563,7 @@ AC_CACHE_CHECK([for alloca (via gmp-impl.h)],
                gmp_cv_func_alloca,
 [AC_TRY_LINK(
 GMP_INCLUDE_GMP_H
-[#include "$srcdir/gmp-impl.h"
+[#include "C:\Users\gabriel\GS\dev\Microchip_XC32_Compiler\xc32-v4.35-src\pic32m-source\gcc\gmp\gmp-h.in"
 ],
   [char *p = (char *) alloca (1);],
   gmp_cv_func_alloca=yes,




# New compile error ~24 min. into building just gcc! (the stuff before gcc in the build script was already successfully built):
      |               ^~~~~
../../../pic32m-source/gcc/gcc/config/pic32m/mchp.c: In function 'const char* default_section_name(tree, uint64_t)':
../../../pic32m-source/gcc/gcc/config/pic32m/mchp.c:5583:39: error: cast from 'tree' {aka 'tree_node*'} to 'long unsigned int' loses precision [-fpermissive]
 5583 |                                       (unsigned long) decl, current_time);
      |                                       ^~~~~~~~~~~~~~~~~~~~

# -------[WORKED]--------
# solution (I think): in mchp.c (2 files: one for m and one for c chip type): cast ptr to `uintptr_t` instead of to `unsigned long`:

#include <stdint.h>
      len_this_default_name = sprintf(this_default_name,"*_%8.8lx%lx",
                                      (uintptr_t) decl, current_time);

# Note my gcc version on Windows in MSYS2 UCRT64 terminal:
$ gcc --version
gcc.exe (Rev2, Built by MSYS2 project) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


# New error:
# Compile command:
g++ -fno-PIE -c  -DPREFIX=\"/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/installed/opt\" -DBASEVER="\"8.3.1\"" -g -O2 -DIN_GCC  -DCROSS_DIRECTORY_STRUCTURE   -fno-exceptions -fno-rtti -fasynchronous-unwind-tables -W -Wall -Wno-narrowing -Wwrite-strings -Wcast-qual -Wmissing-format-attribute -Woverloaded-virtual -pedantic -Wno-long-long -Wno-variadic-macros -Wno-overlength-strings   -DHAVE_CONFIG_H -I. -I. -I../../../pic32m-source/gcc/gcc -I../../../pic32m-source/gcc/gcc/. -I../../../pic32m-source/gcc/gcc/../include -I../../../pic32m-source/gcc/gcc/../libcpp/include -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/./gmp -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/gmp -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/./mpfr/src -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/mpfr/src -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/mpc/src  -I../../../pic32m-source/gcc/gcc/../libdecnumber -I../../../pic32m-source/gcc/gcc/../libdecnumber/dpd -I../libdecnumber -I../../../pic32m-source/gcc/gcc/../libbacktrace  -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/opt/include -imacros host-defs.h -o prefix.o -MT prefix.o -MMD -MP -MF ./.deps/prefix.TPo ../../../pic32m-source/gcc/gcc/prefix.c

# Error:
./../../pic32m-source/gcc/gcc/prefix.c
../../../pic32m-source/gcc/gcc/system.h:737:30: error: expected identifier before string constant
  737 | #define abort() fancy_abort (__FILE__, __LINE__, __FUNCTION__)
      |                              ^~~~~~~~
../../../pic32m-source/gcc/gcc/system.h:737:30: error: expected ',' or '...' before string constant
../../../pic32m-source/gcc/gcc/system.h:737:30: error: expected identifier before string constant
  737 | #define abort() fancy_abort (__FILE__, __LINE__, __FUNCTION__)
      |                              ^~~~~~~~
../../../pic32m-source/gcc/gcc/system.h:737:30: error: expected ',' or '...' before string constant
make[1]: *** [Makefile:1112: prefix.o] Error 1
make[1]: Leaving directory '/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/gcc'
make: *** [Makefile:4290: all-gcc] Error 2

# -------[NOPE!]--------
# attempted fix in gcc/gcc/system.h:
# - what inspired me to try this was seeing it here: https://github.com/gcc-mirror/gcc/blob/master/gcc/system.h#L851C75-L851C75

# change FROM:
#define abort() fancy_abort (__FILE__, __LINE__, __FUNCTION__)

# TO:
#define abort() (fancy_abort (__FILE__, __LINE__, __FUNCTION__))


# Failed 21 min. later on a -j1 build:
g++ -fno-PIE -c  -DPREFIX=\"/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/installed/opt\" -DBASEVER="\"8.3.1\"" -g -O2 -DIN_GCC  -DCROSS_DIRECTORY_STRUCTURE   -fno-exceptions -fno-rtti -fasynchronous-unwind-tables -W -Wall -Wno-narrowing -Wwrite-strings -Wcast-qual -Wmissing-format-attribute -Woverloaded-virtual -pedantic -Wno-long-long -Wno-variadic-macros -Wno-overlength-strings   -DHAVE_CONFIG_H -I. -I. -I../../../pic32m-source/gcc/gcc -I../../../pic32m-source/gcc/gcc/. -I../../../pic32m-source/gcc/gcc/../include -I../../../pic32m-source/gcc/gcc/../libcpp/include -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/./gmp -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/gmp -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/./mpfr/src -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/mpfr/src -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/mpc/src  -I../../../pic32m-source/gcc/gcc/../libdecnumber -I../../../pic32m-source/gcc/gcc/../libdecnumber/dpd -I../libdecnumber -I../../../pic32m-source/gcc/gcc/../libbacktrace  -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/opt/include -imacros host-defs.h -o prefix.o -MT prefix.o -MMD -MP -MF ./.deps/prefix.TPo ../../../pic32m-source/gcc/gcc/prefix.c
../../../pic32m-source/gcc/gcc/system.h:737:31: error: expected identifier before string constant
  737 | #define abort() (fancy_abort (__FILE__, __LINE__, __FUNCTION__))
      |                               ^~~~~~~~
../../../pic32m-source/gcc/gcc/system.h:737:31: error: expected ',' or '...' before string constant
In file included from ../../../pic32m-source/gcc/gcc/prefix.c:67:
../../../pic32m-source/gcc/gcc/system.h:737:17: warning: unnecessary parentheses in declaration of 'fancy_abort' [-Wparentheses]
  737 | #define abort() (fancy_abort (__FILE__, __LINE__, __FUNCTION__))
      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../../../pic32m-source/gcc/gcc/system.h:737:17: note: remove parentheses
../../../pic32m-source/gcc/gcc/system.h:737:31: error: expected identifier before string constant
  737 | #define abort() (fancy_abort (__FILE__, __LINE__, __FUNCTION__))
      |                               ^~~~~~~~
../../../pic32m-source/gcc/gcc/system.h:737:31: error: expected ',' or '...' before string constant
../../../pic32m-source/gcc/gcc/system.h:737:17: warning: unnecessary parentheses in declaration of 'fancy_abort' [-Wparentheses]
  737 | #define abort() (fancy_abort (__FILE__, __LINE__, __FUNCTION__))
      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../../../pic32m-source/gcc/gcc/system.h:737:17: note: remove parentheses
make[1]: *** [Makefile:1112: prefix.o] Error 1
make[1]: Leaving directory '/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/gcc'
make: *** [Makefile:4290: all-gcc] Error 2

# total guess: try this instead (moved the left parenthesis):
#define abort() fancy_abort ((__FILE__, __LINE__, __FUNCTION__))

# FAILED IN 1 min. But, at least I get to see *where* it is failing from now! Failing on line 460 in fibonacci_heap.h may be due to `abort()` being called inside a C++ template class!
g++ -fno-PIE -c   -g -O2 -DIN_GCC  -DCROSS_DIRECTORY_STRUCTURE   -fno-exceptions -fno-rtti -fasynchronous-unwind-tables -W -Wall -Wno-narrowing -Wwrite-strings -Wcast-qual -Wmissing-format-attribute -Woverloaded-virtual -pedantic -Wno-long-long -Wno-variadic-macros -Wno-overlength-strings   -DHAVE_CONFIG_H -I. -I. -I../../../pic32m-source/gcc/gcc -I../../../pic32m-source/gcc/gcc/. -I../../../pic32m-source/gcc/gcc/../include -I../../../pic32m-source/gcc/gcc/../libcpp/include -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/./gmp -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/gmp -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/./mpfr/src -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/mpfr/src -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/mpc/src  -I../../../pic32m-source/gcc/gcc/../libdecnumber -I../../../pic32m-source/gcc/gcc/../libdecnumber/dpd -I../libdecnumber -I../../../pic32m-source/gcc/gcc/../libbacktrace  -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/opt/include -imacros host-defs.h -o bb-reorder.o -MT bb-reorder.o -MMD -MP -MF ./.deps/bb-reorder.TPo ../../../pic32m-source/gcc/gcc/bb-reorder.c
../../../pic32m-source/gcc/gcc/fibonacci_heap.h: In instantiation of 'V* fibonacci_heap<K, V>::delete_node(fibonacci_node<K, V>*, bool) [with K = long int; V = basic_block_def]':
../../../pic32m-source/gcc/gcc/bb-reorder.c:230:40:   required from here
../../../pic32m-source/gcc/gcc/system.h:737:31: warning: left operand of comma operator has no effect [-Wunused-value]
  737 | #define abort() fancy_abort ((__FILE__, __LINE__, __FUNCTION__))
      |                               ^~~~~~~~
../../../pic32m-source/gcc/gcc/fibonacci_heap.h:460:7: note: in expansion of macro 'abort'
  460 |       abort ();
      |       ^~~~~
In file included from ../../../pic32m-source/gcc/gcc/bb-reorder.c:95:
../../../pic32m-source/gcc/gcc/system.h:737:49: warning: right operand of comma operator has no effect [-Wunused-value]
  737 | #define abort() fancy_abort ((__FILE__, __LINE__, __FUNCTION__))
      |                              ~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~
../../../pic32m-source/gcc/gcc/fibonacci_heap.h:460:7: note: in expansion of macro 'abort'
  460 |       abort ();
      |       ^~~~~
../../../pic32m-source/gcc/gcc/system.h:737:29: error: too few arguments to function 'void fancy_abort(const char*, int, const char*)'
  737 | #define abort() fancy_abort ((__FILE__, __LINE__, __FUNCTION__))
      |                 ~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../../../pic32m-source/gcc/gcc/fibonacci_heap.h:460:7: note: in expansion of macro 'abort'
  460 |       abort ();
      |       ^~~~~
../../../pic32m-source/gcc/gcc/system.h:735:13: note: declared here
  735 | extern void fancy_abort (const char *, int, const char *)
      |             ^~~~~~~~~~~
make[1]: *** [Makefile:1112: bb-reorder.o] Error 1
make[1]: Leaving directory '/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/gcc'
make: *** [Makefile:4290: all-gcc] Error 2

real    0m45.201s
user    0m0.695s
sys     0m2.956s
Error: [gcc] failed to build!


# A chat with GitHub Copilot reminds me: 
# > In this example, __FUNCTION__ inside myMethod() expands to void MyClass<int, double>::myMethod(). The exact output may vary slightly depending on the compiler, but it will always include the class name with its template parameters and the method name.
#
# This puts a comma inside the macro, which may be causing the error? But, how could it? The whole thing is a string!


# My question: https://stackoverflow.com/q/77435355/4561887

# -------[WORKED]--------
# Attempted fix: just comment out that line in `system.h`:
#
# from this on line 737:
#define abort() fancy_abort (__FILE__, __LINE__, __FUNCTION__)
#
# to this:
# - @Tim Roberts thinks it's a safe change: https://stackoverflow.com/questions/77435355/c-error-expected-or-before-string-constant-before-file-in#comment136515046_77435355
/* #define abort() fancy_abort (__FILE__, __LINE__, __FUNCTION__) */

# IT WORKED! GCC HAS NOW COMPLETED BUILDING!
# It failed to copy the "resource" `xc32_device.info` file at the end, however, because I do not have the original XC32 v4.35 compiler installed. Install it. 

# open Command Prompt, and this works!:
C:\Users\gabriel\GS\dev\Microchip_XC32_Compiler\xc32-v4.35-src\installed\opt\bin\bin\pic32m-g++.exe --version
# Sample output:
pic32m-g++.exe (Microchip XC32 Compiler v4.35 custom) 8.3.1 Build date: Nov  6 2023
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.



```


# The final Windows fixes/manual file changes:

1. 



# TODO:

1. [ ] Change this version string in the build script from `Microchip XC32 Compiler v4.35 custom` to `Microchip XC32 Compiler v4.35 unlicensed manual build` or something.
1. [ ] clean up the build scripts in general, to make them nicer
    [ ] Adjust any output dir names or whatever to be sensible, too, and/or to have the word `unlicensed` (probably) or perhaps `custom` in them too. 
1. [ ] make all calls to the `configure` scripts use **relative** paths! I think this is just a good idea given the Windows MSYS2 situation which I describe here: https://stackoverflow.com/a/77435216/4561887
1. [ ] add echo statements after each major step **succeeds** in the build script. 
1. [ ] Don't try to copy the "resource" file at the end unless the compiler is installed. Just output a useful message to the user to install the compiler and copy the file manually instead. 
1. [ ] clean up the script and test it from scratch for the M chip only. 
1. [ ] fix the C chip's script
1. [ ] add an "ALL" script that calls both of those scripts. 
1. [ ] rename my build scripts to something more like this: 
    ```
    build_xc32_v4.35_pic32mx_Ubuntu.sh
    build_xc32_v4.35_pic32cx_Ubuntu.sh
    build_xc32_v4.35_ALL_Ubuntu.sh
    ---
    build_xc32_v4.35_pic32mx_Windows.sh
    build_xc32_v4.35_pic32cx_Windows.sh
    build_xc32_v4.35_ALL_Windows.sh
    ---
    ```
    [ ] [OR: if you can make the same script build on BOTH Ubuntu and Windows, then remove the "Ubuntu" name from the end and just have those 3 files!]
1. [ ] Test on Linux again, and save the binary build output and executables to a new repo, so others don't have to build from source:
    [ ] Create 1 new build *output* sub-repo:
        [ ] Microchip_XC32_Compiler_build
        With 2 dirs:
        [ ] 1. Ubuntu   # Ubuntu 22.04
        [ ] 2. Windows  # Windows 11, using the MSYS2 ucrt64 environment
1. [ ] go to the official XC32 compiler installed dir, and copy out the `xc32_device.info` file, and put it in the build output dir too. 
    [ ] Also obtain the many `/opt/microchip/xc32/v4.35/bin/device_files` files too.
    [ ] And get all of the linker scripts from places like this: `/opt/microchip/xc32/v4.35/pic32mx/lib/proc/32MX230F064D/p32MX230F064D_pic.ld`

