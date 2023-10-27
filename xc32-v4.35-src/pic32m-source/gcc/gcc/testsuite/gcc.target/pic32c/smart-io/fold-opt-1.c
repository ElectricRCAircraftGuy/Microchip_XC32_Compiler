/* Test folding of stdio functions. */
/* { dg-do compile } */
/* { dg-options "-msmart-io=1 -O" } */
#include <stdio.h>
int main()
{
  fprintf (stdout, "string\n");
  return 0;
}

/* { dg-final { scan-assembler-not "fprintf" } } */
/* { dg-final { scan-assembler "fwrite" } } */
