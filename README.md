
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

1. 
