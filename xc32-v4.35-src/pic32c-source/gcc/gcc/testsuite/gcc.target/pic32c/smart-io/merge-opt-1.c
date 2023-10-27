/* Test for proper merging of smart-io enabled functions */
/* { dg-do link } */
/* { dg-additional-options "-msmart-io=1 -Wl,-M=map,-defsym,_min_heap_size=400" } */
#include <stdio.h>
int main()
{
  char buf[20];
  fprintf (stderr, "%f\n", 1.0f);
  sprintf (buf, "%d %x\n", 1, 2);
  return 0;
}
/* { dg-final { scan-map "map" "(_vfprintf_\[a-zA-Z\]*d\[a-zA-Z\]*fF\[a-zA-Z\]*)" } } */
