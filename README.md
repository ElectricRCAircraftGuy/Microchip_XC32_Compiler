
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

1. Try to configure and build gcc

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
        CFLAGS="-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=v4.35_custom" \
        CXXFLAGS="-DSKIP_LICENSE_MANAGER=1 -D_XC32_VERSION_=v4.35_custom" \
        --target=pic32mx --build=x86_64-linux-gnu --host=x86_64-linux-gnu \
        --enable-languages=c,c++

    # Takes ~??
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
