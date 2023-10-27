/* smart-io folding test: fprintf-fold.c
   Compile fprintf folding case with smart-io enabled and ensure we fold to fputs.
*/
/* { dg-do compile } */
/* { dg-additional-options "-O -msmart-io" { target pic32c-*-* } } */

#include <stdio.h>

void test(char *buf)
{
  sprintf(buf, "%s", "a string");
  sprintf(buf, "a string\n");
}

/* We'd like to scan for strcpy, but would need options to guarantee that
   strcpy won't be inlined. So settle for not having sprintf. */
/* { dg-final { scan-assembler-not "bl\s*sprintf" } } */
