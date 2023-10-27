/* 
   smart-io symbol resolution test: vsprintf-all-chk-2.c
   Invoke variants of stdio function vsprintf and check for
   resolution to smart-io function via disassembly.
*/
/* { dg-do link } */
/* { dg-options "-msmart-io" } */
/* { dg-final { scan-disasm "bl\s.*\<_vsprintf_cdeEfFgGnopsuxX\>" } } */
#define PREFIX vs
#define ROOT printf
#include "harness.h"
static void test (void)
{
  FN_ARG_DECL;
  FUNC(_quot( FMT_c FMT_s FMT_eE FMT_fF FMT_gG) _eval3( ARG_c ARG_s ARG_eE ARG_fF ARG_gG));
  FUNC(_quot( FMT_c FMT_eE FMT_fF FMT_gG) _eval3( ARG_c ARG_eE ARG_fF ARG_gG));
  FUNC(_quot( FMT_c FMT_s FMT_eE FMT_fF) _eval3( ARG_c ARG_s ARG_eE ARG_fF));
  FUNC(_quot( FMT_c FMT_eE FMT_fF) _eval3( ARG_c ARG_eE ARG_fF));
  FUNC(_quot( FMT_c FMT_s FMT_eE FMT_gG) _eval3( ARG_c ARG_s ARG_eE ARG_gG));
  FUNC(_quot( FMT_c FMT_eE FMT_gG) _eval3( ARG_c ARG_eE ARG_gG));
  FUNC(_quot( FMT_c FMT_s FMT_eE) _eval3( ARG_c ARG_s ARG_eE));
  FUNC(_quot( FMT_c FMT_eE) _eval3( ARG_c ARG_eE));
  FUNC(_quot( FMT_c FMT_s FMT_fF FMT_gG) _eval3( ARG_c ARG_s ARG_fF ARG_gG));
  FUNC(_quot( FMT_c FMT_fF FMT_gG) _eval3( ARG_c ARG_fF ARG_gG));
  FUNC(_quot( FMT_c FMT_s FMT_fF) _eval3( ARG_c ARG_s ARG_fF));
  FUNC(_quot( FMT_c FMT_fF) _eval3( ARG_c ARG_fF));
  FUNC(_quot( FMT_c FMT_s FMT_gG) _eval3( ARG_c ARG_s ARG_gG));
  FUNC(_quot( FMT_c FMT_gG) _eval3( ARG_c ARG_gG));
  FUNC(_quot( FMT_c FMT_s) _eval3( ARG_c ARG_s));
  FUNC(_quot( FMT_c) _eval3( ARG_c));
  FUNC(_quot( FMT_eE) _eval3( ARG_eE));
  FUNC(_quot( FMT_eE FMT_fF) _eval3( ARG_eE ARG_fF));
  FUNC(_quot( FMT_eE FMT_fF FMT_gG) _eval3( ARG_eE ARG_fF ARG_gG));
  FUNC(_quot( FMT_s FMT_eE FMT_fF FMT_gG) _eval3( ARG_s ARG_eE ARG_fF ARG_gG));
  FUNC(_quot( FMT_s FMT_eE FMT_fF) _eval3( ARG_s ARG_eE ARG_fF));
  FUNC(_quot( FMT_eE FMT_gG) _eval3( ARG_eE ARG_gG));
  FUNC(_quot( FMT_s FMT_eE FMT_gG) _eval3( ARG_s ARG_eE ARG_gG));
  FUNC(_quot( FMT_s FMT_eE) _eval3( ARG_s ARG_eE));
  FUNC(_quot( FMT_fF) _eval3( ARG_fF));
  FUNC(_quot( FMT_fF FMT_gG) _eval3( ARG_fF ARG_gG));
  FUNC(_quot( FMT_s FMT_fF FMT_gG) _eval3( ARG_s ARG_fF ARG_gG));
  FUNC(_quot( FMT_s FMT_fF) _eval3( ARG_s ARG_fF));
  FUNC(_quot( FMT_gG) _eval3( ARG_gG));
  FUNC(_quot( FMT_s FMT_gG) _eval3( ARG_s ARG_gG));
  FUNC(_quot( FMT_s) _eval3( ARG_s));
}

