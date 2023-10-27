/* smart-io output test: vprintf-eEfF-cmp.c 
   Invoke stdio function with appropriate arguments. To be compiled
   with and without -mno-smart-io. 
*/
#define PREFIX v
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_eE FMT_fF) _eval3( ARG_eE ARG_fF));
}

