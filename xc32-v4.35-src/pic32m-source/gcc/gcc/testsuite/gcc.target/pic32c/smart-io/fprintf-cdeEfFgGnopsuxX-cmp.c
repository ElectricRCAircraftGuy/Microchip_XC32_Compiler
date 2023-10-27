/* smart-io output test: fprintf-cdeEfFgGnopsuxX-cmp.c 
   Invoke stdio function with appropriate arguments. To be compiled
   with and without -mno-smart-io. 
*/
#define PREFIX f
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_c FMT_s FMT_eE FMT_fF FMT_gG) _eval3( ARG_c ARG_s ARG_eE ARG_fF ARG_gG));
}

