/* Test folding of stdio functions. */
/* { dg-do compile } */
/* { dg-options "-msmart-io=1 -O" } */
#include <stdio.h>
const char str = 'h';
int main()
{
  printf ("%c", str);
  return 0;
}

/* { dg-final { scan-assembler-not "printf" } } */
/* { dg-final { scan-assembler "putchar" } } */
