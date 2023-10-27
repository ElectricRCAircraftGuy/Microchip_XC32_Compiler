/* smart-io folding test: fprintf-fold.c
   Compile fprintf folding case with smart-io enabled and ensure we fold to fputs.
*/
/* { dg-do compile } */
/* { dg-additional-options "-O -msmart-io" { target pic32c-*-* } } */

#include <stdio.h>

void test(const char *str)
{
  fprintf(stderr, "%s", str);
  fprintf(stdout, "a string\n");
  fprintf(stderr, "");
}

/* { dg-final { scan-assembler-times "fputs" 1 } } */
/* { dg-final { scan-assembler-times "fwrite" 1 } } */
/* { dg-final { scan-assembler-not "bl\s*fprintf" } } */
