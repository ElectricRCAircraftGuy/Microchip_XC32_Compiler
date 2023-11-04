
[`checking size of mp_limb_t... 0` and `configure: error: Oops, mp_limb_t doesn't seem to work` when compiling the Microchip XC32 compiler from source](https://stackoverflow.com/q/77414776/4561887), especially the "**More leads to follow up on**" section at the bottom of the question.


## Description of files:

1. `build-xc32-v4.35m_mod1.sh`
    1. path where it was taken from: `Microchip_XC32_Compiler/build-xc32-v4.35m_mod1.sh`
1. `build-xc32-v4.35m_mod2.sh`
    1. path where it was taken from: `Microchip_XC32_Compiler/build-xc32-v4.35m_mod2.sh`
1. `command-line_output.txt`
    1. path where it was taken from: NA (terminal)
1. `Makefile`
    1. path where it was taken from: `Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/Makefile`
1. `config.log`
    1. path where it was taken from: `Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/gcc/gmp/config.log`


## Build steps to produce these files:

1. Follow my steps [described in my question here](https://stackoverflow.com/q/77414776/4561887), including installing dependencies in the MSYS2 UCRT64 terminal. 
1. Instead of running `time ./build-xc32-v4.35m.sh`, however, run this instead:
    ```bash
    # run until it fails
    time ./build-xc32-v4.35m_mod1.sh
    # then run this, where I have commented out the build parts that already passed, and 
    # changed the gcc build jobs from `-j$(nproc)` to `-j1`
    time ./build-xc32-v4.35m_mod2.sh
    ```

    Here is what the failure in `command-line_output.txt` looks like after running the `time ./build-xc32-v4.35m_mod2.sh` command:
    ```
    checking size of void *... 8
    checking size of unsigned short... 2
    checking size of unsigned... 4
    checking size of unsigned long... 4
    checking size of mp_limb_t... 0
    configure: error: Oops, mp_limb_t doesn't seem to work
    make: *** [Makefile:4701: configure-gmp] Error 1

    real    4m28.430s
    user    0m2.336s
    sys     0m35.019s
    Error: [gcc] failed to build!
    ```

1. Now, the Makefile above is created. Look in particular at this part:
    ```bash
    .PHONY: configure-gmp maybe-configure-gmp
    maybe-configure-gmp:
    maybe-configure-gmp: configure-gmp
    configure-gmp: 
        @r=`${PWD_COMMAND}`; export r; \
        s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \
        test ! -f $(HOST_SUBDIR)/gmp/Makefile || exit 0; \
        $(SHELL) $(srcdir)/mkinstalldirs $(HOST_SUBDIR)/gmp; \
        $(HOST_EXPORTS)  \
        echo Configuring in $(HOST_SUBDIR)/gmp; \
        cd "$(HOST_SUBDIR)/gmp" || exit 1; \
        case $(srcdir) in \
        /* | [A-Za-z]:[\\/]*) topdir=$(srcdir) ;; \
        *) topdir=`echo $(HOST_SUBDIR)/gmp/ | \
            sed -e 's,\./,,g' -e 's,[^/]*/,../,g' `$(srcdir) ;; \
        esac; \
        module_srcdir=gmp; \
        $(SHELL) \
        $$s/$$module_srcdir/configure \
        --srcdir=$${topdir}/$$module_srcdir \
        $(HOST_CONFIGARGS) --build=${build_alias} --host=none-${host_vendor}-${host_os} \
        --target=none-${host_vendor}-${host_os} --disable-shared LEX="touch lex.yy.c" \
        || exit 1
    ```
1. And in the `gmp/config.log` file, you can see that the include doesn't seem to work in GCC, _despite the fact that that file does exist!_:

    Note: I searched this file backwards (from the bottom up) for the word "error" in order to find this:
    ```
    configure:27432: gcc -c -g -O2 -D__USE_MINGW_ACCESS -DNO_ASM -I/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-build/opt/include -imacros host-defs.h conftest.c >&5
    conftest.c:80:10: fatal error: /c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/gmp/gmp-h.in: No such file or directory
    80 | #include "/c/Users/gabriel/GS/dev/Microchip_XC32_Compiler/xc32-v4.35-src/pic32m-source/gcc/gmp/gmp-h.in"
        |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    compilation terminated.
    ```


## Conclusions

So, I think the problem is that even though the MSYS2 _terminal_ works ok in Windows with absolute Linux-style paths, the MSYS2 gcc compiler does *not*! So, I should convert all paths to *relative* Linux-style paths in the `build-xc32-v4.35m.sh` script, and then I *think* it'll work. 

See also my thoughts in the **More leads to follow up on** section [at the bottom of my question here](https://stackoverflow.com/q/77414776/4561887).

