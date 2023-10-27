/* 
   smart-io merge test: vsprintf-cdnopuxX-opt.c
   Invoke standard IO function vsprintf and ensure the mangled symbol is generated.
   No checking of the actual mangling vs. arguments is performed.
*/
/* { dg-do compile } */
/* { dg-additional-options "-msmart-io=1" } */
#define PREFIX vs
#define ROOT printf
#include <stdio.h>
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_c) _eval3( ARG_c));
}

/* { dg-final { scan-assembler "__vsprintf_\[a-zA-Z\]*" } } */
