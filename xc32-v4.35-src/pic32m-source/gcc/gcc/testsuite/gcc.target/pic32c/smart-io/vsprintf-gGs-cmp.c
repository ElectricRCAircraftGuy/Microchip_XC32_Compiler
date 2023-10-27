/* smart-io output test: vsprintf-gGs-cmp.c 
   Invoke stdio function with appropriate arguments. To be compiled
   with and without -mno-smart-io. 
*/
#define PREFIX vs
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_s FMT_gG) _eval3( ARG_s ARG_gG));
}

