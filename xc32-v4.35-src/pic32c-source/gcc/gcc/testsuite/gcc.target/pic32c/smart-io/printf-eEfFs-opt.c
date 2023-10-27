/* 
   smart-io merge test: printf-eEfFs-opt.c
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
  FUNC(_quot( FMT_s FMT_eE FMT_fF) _eval3( ARG_s ARG_eE ARG_fF));
}

/* { dg-final { scan-assembler "__printf_\[a-zA-Z\]*" } } */
