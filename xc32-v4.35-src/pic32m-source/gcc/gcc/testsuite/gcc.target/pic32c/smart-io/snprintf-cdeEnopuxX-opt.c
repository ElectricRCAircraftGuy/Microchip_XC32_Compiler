/* 
   smart-io merge test: snprintf-cdeEnopuxX-opt.c
   Invoke standard IO function snprintf and ensure the mangled symbol is generated.
   No checking of the actual mangling vs. arguments is performed.
*/
/* { dg-do compile } */
/* { dg-additional-options "-msmart-io=1" } */
#define PREFIX sn
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_c FMT_eE) _eval3( ARG_c ARG_eE));
}

/* { dg-final { scan-assembler "__snprintf_\[a-zA-Z\]*" } } */
