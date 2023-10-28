
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
        binutils-mingw-w64-i686

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

