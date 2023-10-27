/* smart-io output test: vfprintf-cdeEgGnopuxX-cmp.c 
   Invoke stdio function with appropriate arguments. To be compiled
   with and without -mno-smart-io. 
*/
#define PREFIX vf
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_c FMT_eE FMT_gG) _eval3( ARG_c ARG_eE ARG_gG));
}

