/* 
   smart-io merge test: vsnprintf-cdeEfFnopsuxX-opt.c
   Invoke standard IO function vsnprintf and ensure the mangled symbol is generated.
   No checking of the actual mangling vs. arguments is performed.
*/
/* { dg-do compile } */
/* { dg-additional-options "-msmart-io=1" } */
#define PREFIX vsn
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_c FMT_s FMT_eE FMT_fF) _eval3( ARG_c ARG_s ARG_eE ARG_fF));
}

/* { dg-final { scan-assembler "__vsnprintf_\[a-zA-Z\]*" } } */
