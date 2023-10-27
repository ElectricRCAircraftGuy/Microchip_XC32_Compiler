/* Test folding of stdio functions. */
/* { dg-do compile } */
/* { dg-options "-msmart-io=1 -O" } */
#include <stdio.h>
const char *str = "hello";
int main()
{
  printf ("%s\n", str);
  return 0;
}

/* { dg-final { scan-assembler-not "printf" } } */
/* { dg-final { scan-assembler "puts" } } */
