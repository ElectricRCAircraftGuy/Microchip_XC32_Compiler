/* smart-io output test: snprintf-fFgG-cmp.c 
   Invoke stdio function with appropriate arguments. To be compiled
   with and without -mno-smart-io. 
*/
#define PREFIX sn
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_fF FMT_gG) _eval3( ARG_fF ARG_gG));
}

