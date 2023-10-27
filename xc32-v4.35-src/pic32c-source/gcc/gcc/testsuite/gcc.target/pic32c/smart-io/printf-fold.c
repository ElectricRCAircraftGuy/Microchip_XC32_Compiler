/* smart-io folding test: fprintf-fold.c
   Compile fprintf folding case with smart-io enabled and ensure we fold to fputs.
*/
/* { dg-do compile } */
/* { dg-additional-options "-O -msmart-io" { target pic32c-*-* } } */

#include <stdio.h>

void test()
{
  printf("%s\n", "a string");
  printf("a string\n");
  printf("a");
}

/* { dg-final { scan-assembler-times "puts" 2 } } */
/* { dg-final { scan-assembler-times "putchar" 1 } } */
/* { dg-final { scan-assembler-not "bl\s*printf" } } */
