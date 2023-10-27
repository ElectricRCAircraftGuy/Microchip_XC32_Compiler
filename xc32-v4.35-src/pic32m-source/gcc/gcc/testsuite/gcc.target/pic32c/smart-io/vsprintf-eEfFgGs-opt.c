/* 
   smart-io merge test: vsprintf-eEfFgGs-opt.c
   Invoke standard IO function vsprintf and ensure the mangled symbol is generated.
   No checking of the actual mangling vs. arguments is performed.
*/
/* { dg-do compile } */
/* { dg-additional-options "-msmart-io=1" } */
#define PREFIX vs
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_s FMT_eE FMT_fF FMT_gG) _eval3( ARG_s ARG_eE ARG_fF ARG_gG));
}

/* { dg-final { scan-assembler "__vsprintf_\[a-zA-Z\]*" } } */
