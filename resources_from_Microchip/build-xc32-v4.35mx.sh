#!/bin/sh

# Location of XC32 4.35.
XC32DIR=/opt/microchip/xc32/v4.35
# Where the sources are located.
SRCDIR=${HOME}/Downloads/src/pic32m-source
# Where to store build artifacts.
BUILDDIR=${HOME}/Downloads/build/pic32m-build
# Where to install the compiler.
INSTALLDIR=${HOME}/Downloads/build/opt

######################################
# At this point, you don't need to change anything unless you are
# customizing.
libmchp_srcdir=${SRCDIR}/mchp
expat_srcdir=${SRCDIR}/expat-2.1.1
binutils_srcdir=${SRCDIR}/binutils
gcc_srcdir=${SRCDIR}/gcc

# This is needed to hold libraries and include files needed by
# binutils and gcc.
hostinstalldir=${BUILDDIR}/opt

libmchp_builddir=${BUILDDIR}/libmchp
expat_builddir=${BUILDDIR}/expat
binutils_builddir=${BUILDDIR}/binutils
gcc_builddir=${BUILDDIR}/gcc

# First, build libmchp.
PS4="[libmchp] "
(
    set -ex

    rm -rf ${libmchp_builddir}
    mkdir -p ${libmchp_builddir}
    cd ${libmchp_builddir}

    ${libmchp_srcdir}/configure \
                 --installdir=${hostinstalldir} \
                 --smart-io-suffixdir=${libmchp_srcdir}

    make -f ${libmchp_srcdir}/Makefile all
    make -f ${libmchp_srcdir}/Makefile install
)

# Next, build expat.
PS4="[expat] "
(
    set -ex

    rm -rf ${expat_builddir}
    mkdir -p ${expat_builddir}
    cd ${expat_builddir}

    ${expat_srcdir}/configure --prefix=${hostinstalldir} --disable-shared

    make install
)

# Now set some macros that everything will need and put them in a
# header.  Although they are defined in the binutils target
# configuration, sometimes it doesn't reach the every file.  Also,
# host-lm.h is needed by license manager code.
PS4="[macros] "
(
    set -ex

    cat >${hostinstalldir}/include/host-defs.h <<EOF
#ifndef _BUILD_MCHP_
#define _BUILD_MCHP_ 1
#endif
#ifndef _BUILD_XC32_
#define _BUILD_XC32_ 1
#endif
#ifndef MCHP_BUILD_DATE
#define MCHP_BUILD_DATE __DATE__
#endif
#ifndef _XC32_VERSION_
#define _XC32_VERSION_ 4300
#endif
#ifndef TARGET_MCHP_PIC32MX
#define TARGET_MCHP_PIC32MX 1
#endif
#ifndef TARGET_IS_PIC32MX
#define TARGET_IS_PIC32MX 1
#endif
#ifndef MCHP_VERSION
#define MCHP_VERSION 4.35
#endif
EOF

    cat >${hostinstalldir}/include/host-lm.h <<EOF
#ifndef SKIP_LICENSE_MANAGER
#define SKIP_LICENSE_MANAGER
#endif
EOF
)

# Now binutils.
PS4="[binutils] "
(
    set -ex

    rm -rf ${binutils_builddir}
    mkdir -p ${binutils_builddir}
    cd ${binutils_builddir}

    ${binutils_srcdir}/configure \
                      --target=pic32mx \
                      --prefix=${INSTALLDIR} \
                      --program-prefix=pic32m- \
                      --with-sysroot=${INSTALLDIR}/pic32mx \
                      --with-bugurl=http://example.com \
                      --with-pkgversion="Microchip XC32 Compiler v4.35 custom" \
                      --bindir=${INSTALLDIR}/bin/bin \
                      --infodir=${INSTALLDIR}/share/doc/xc32-pic32m-gcc/info \
                      --mandir=${INSTALLDIR}/share/doc/xc32-pic32m-gcc/man \
                      --libdir=${INSTALLDIR}/lib \
                      --disable-nls \
                      --disable-werror \
                      --disable-sim \
                      --disable-gdb \
                      --enable-interwork \
                      --enable-plugins \
                      --disable-64-bit-bfd \
                      CPPFLAGS="-I${hostinstalldir}/include -imacros host-defs.h" \
                      CFLAGS=-fcommon \
                      LDFLAGS=-L${hostinstalldir}/lib

    make all \
         CPPFLAGS="-I${hostinstalldir}/include -imacros host-defs.h" \
         CFLAGS=-fcommon \
         LDFLAGS=-L${hostinstalldir}/lib

    make install
    
)

# Finally, GCC.
PS4="[gcc] "
(
    set -ex

    rm -rf ${gcc_builddir}
    mkdir -p ${gcc_builddir}
    cd ${gcc_builddir}

    ${gcc_srcdir}/configure \
                 --target=pic32mx \
                 --prefix=${INSTALLDIR} \
                 --program-prefix=pic32m- \
                 --with-sysroot=${INSTALLDIR}/pic32mx \
                 --with-bugurl=http://example.com \
                 --with-pkgversion="Microchip XC32 Compiler v4.40 custom" \
                 --bindir=${INSTALLDIR}/bin/bin \
                 --infodir=${INSTALLDIR}/share/doc/xc32-pic32m-gcc/info \
                 --mandir=${INSTALLDIR}/share/doc/xc32-pic32m-gcc/man \
                 --libdir=${INSTALLDIR}/lib \
                 --libexecdir=${INSTALLDIR}/bin/bin \
                 --with-build-sysroot=${INSTALLDIR}/pic32mx \
                 --enable-stage1-languages=c \
                 --enable-languages=c,c++ \
                 --enable-target-optspace \
                 --disable-comdat \
                 --disable-libstdcxx-pch \
                 --disable-libstdcxx-verbose \
                 --disable-libssp \
                 --disable-libmudflap \
                 --disable-libffi \
                 --disable-libfortran \
                 --disable-bootstrap \
                 --disable-shared \
                 --disable-nls \
                 --disable-gdb \
                 --disable-libgomp \
                 --disable-threads \
                 --disable-tls \
                 --disable-sim \
                 --disable-decimal-float \
                 --disable-libquadmath \
                 --disable-shared \
                 --disable-checking \
                 --disable-maintainer-mode \
                 --enable-lto \
                 --enable-fixed-point \
                 --enable-gofast \
                 --enable-static \
                 --enable-sgxx-sde-multilibs \
                 --enable-sjlj-exceptions \
                 --enable-poison-system-directories \
                 --enable-obsolete \
                 --without-isl \
                 --without-cloog \
                 --without-headers \
                 --with-musl \
                 --with-dwarf2 \
                 --with-gnu-as \
                 --with-gnu-ld \
                 '--with-host-libstdcxx=-static-libgcc -static-libstdc++ -Wl,-lstdc++ -lm' \
                 CPPFLAGS="-I${hostinstalldir}/include -imacros host-defs.h" \
                 LDFLAGS=-L${hostinstalldir}/lib

    make all-gcc \
         STAGE1_LIBS="-lexpat -lmchp -Wl,-Bstatic -lstdc++ -Wl,-Bdynamic" \
         CPPFLAGS="-I${hostinstalldir}/include -imacros host-defs.h" \
         LDFLAGS=-L${hostinstalldir}/lib

    make install-gcc
)

# Copy in the resource info file from an existing compiler installation.
PS4="[resource] "
(
    set -ex

    mkdir -p ${INSTALLDIR}/bin
    cp ${XC32DIR}/bin/xc32_device.info ${INSTALLDIR}/bin/xc32_device.info
)
