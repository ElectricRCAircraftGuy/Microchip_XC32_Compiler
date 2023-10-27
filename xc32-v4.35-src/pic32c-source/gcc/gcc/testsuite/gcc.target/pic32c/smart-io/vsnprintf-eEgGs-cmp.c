/* smart-io output test: vsnprintf-eEgGs-cmp.c 
   Invoke stdio function with appropriate arguments. To be compiled
   with and without -mno-smart-io. 
*/
#define PREFIX vsn
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_s FMT_eE FMT_gG) _eval3( ARG_s ARG_eE ARG_gG));
}

