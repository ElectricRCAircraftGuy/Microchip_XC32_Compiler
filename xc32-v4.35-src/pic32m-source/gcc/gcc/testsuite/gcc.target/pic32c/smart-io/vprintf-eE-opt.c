/* 
   smart-io merge test: vprintf-eE-opt.c
   Invoke standard IO function vprintf and ensure the mangled symbol is generated.
   No checking of the actual mangling vs. arguments is performed.
*/
/* { dg-do compile } */
/* { dg-additional-options "-msmart-io=1" } */
#define PREFIX v
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_eE) _eval3( ARG_eE));
}

/* { dg-final { scan-assembler "__vprintf_\[a-zA-Z\]*" } } */
