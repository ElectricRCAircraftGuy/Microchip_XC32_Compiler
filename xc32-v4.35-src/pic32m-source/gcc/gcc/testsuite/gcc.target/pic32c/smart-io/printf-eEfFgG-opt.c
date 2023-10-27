/* 
   smart-io merge test: printf-eEfFgG-opt.c
   Invoke standard IO function printf and ensure the mangled symbol is generated.
   No checking of the actual mangling vs. arguments is performed.
*/
/* { dg-do compile } */
/* { dg-additional-options "-msmart-io=1" } */
#define PREFIX 
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_eE FMT_fF FMT_gG) _eval3( ARG_eE ARG_fF ARG_gG));
}

/* { dg-final { scan-assembler "__printf_\[a-zA-Z\]*" } } */
