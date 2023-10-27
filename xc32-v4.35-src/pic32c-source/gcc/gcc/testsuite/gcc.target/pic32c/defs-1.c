/* Test presence of all predefined macros, excluding device-specific ones. */
/* { dg-do compile } */

#ifndef PIC32
#warning "PIC32"
#endif

#ifndef PIC32C
#warning "PIC32C"
#endif

#ifndef __C32__
#warning "__C32__"
#endif

#ifndef __XC32
#warning "__XC32"
#endif

#ifndef __XC32__
#warning "__XC32__"
#endif

#ifndef __XC
#warning "__XC"
#endif

#ifndef __C32_VERSION__
#warning "__C32_VERSION__"
#endif

#ifndef __XC32_VERSION__
#warning "__XC32_VERSION__"
#endif

#ifndef __XC32_VERSION
#warning "__XC32_VERSION"
#endif

#ifndef __XC_VERSION__
#warning "__XC_VERSION__"
#endif

#ifndef __XC_VERSION
#warning "__XC_VERSION"
#endif

