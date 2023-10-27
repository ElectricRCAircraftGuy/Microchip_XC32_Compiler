/* 
   smart-io presence test: fprintf-all-chk-1.c
   Invoke all variants of smartio function _fprintf and check
   for compilation or link errors.
*/
/* { dg-do link } */ 
/* { dg-options "-mno-smart-io" } */
#define PREFIX f
#define ROOT printf
#include "harness.h"
DECL(cdeEfFgGnopsuxX);
DECL(cdeEfFgGnopuxX);
DECL(cdeEfFnopsuxX);
DECL(cdeEfFnopuxX);
DECL(cdeEgGnopsuxX);
DECL(cdeEgGnopuxX);
DECL(cdeEnopsuxX);
DECL(cdeEnopuxX);
DECL(cdfFgGnopsuxX);
DECL(cdfFgGnopuxX);
DECL(cdfFnopsuxX);
DECL(cdfFnopuxX);
DECL(cdgGnopsuxX);
DECL(cdgGnopuxX);
DECL(cdnopsuxX);
DECL(cdnopuxX);
DECL(eE);
DECL(eEfF);
DECL(eEfFgG);
DECL(eEfFgGs);
DECL(eEfFs);
DECL(eEgG);
DECL(eEgGs);
DECL(eEs);
DECL(fF);
DECL(fFgG);
DECL(fFgGs);
DECL(fFs);
DECL(gG);
DECL(gGs);
DECL(s);
static void test (void)
{
  FN_ARG_DECL;
  LIBFUNC(cdeEfFgGnopsuxX, _quot( FMT_c FMT_s FMT_eE FMT_fF FMT_gG) _eval3( ARG_c ARG_s ARG_eE ARG_fF ARG_gG));
  LIBFUNC(cdeEfFgGnopuxX, _quot( FMT_c FMT_eE FMT_fF FMT_gG) _eval3( ARG_c ARG_eE ARG_fF ARG_gG));
  LIBFUNC(cdeEfFnopsuxX, _quot( FMT_c FMT_s FMT_eE FMT_fF) _eval3( ARG_c ARG_s ARG_eE ARG_fF));
  LIBFUNC(cdeEfFnopuxX, _quot( FMT_c FMT_eE FMT_fF) _eval3( ARG_c ARG_eE ARG_fF));
  LIBFUNC(cdeEgGnopsuxX, _quot( FMT_c FMT_s FMT_eE FMT_gG) _eval3( ARG_c ARG_s ARG_eE ARG_gG));
  LIBFUNC(cdeEgGnopuxX, _quot( FMT_c FMT_eE FMT_gG) _eval3( ARG_c ARG_eE ARG_gG));
  LIBFUNC(cdeEnopsuxX, _quot( FMT_c FMT_s FMT_eE) _eval3( ARG_c ARG_s ARG_eE));
  LIBFUNC(cdeEnopuxX, _quot( FMT_c FMT_eE) _eval3( ARG_c ARG_eE));
  LIBFUNC(cdfFgGnopsuxX, _quot( FMT_c FMT_s FMT_fF FMT_gG) _eval3( ARG_c ARG_s ARG_fF ARG_gG));
  LIBFUNC(cdfFgGnopuxX, _quot( FMT_c FMT_fF FMT_gG) _eval3( ARG_c ARG_fF ARG_gG));
  LIBFUNC(cdfFnopsuxX, _quot( FMT_c FMT_s FMT_fF) _eval3( ARG_c ARG_s ARG_fF));
  LIBFUNC(cdfFnopuxX, _quot( FMT_c FMT_fF) _eval3( ARG_c ARG_fF));
  LIBFUNC(cdgGnopsuxX, _quot( FMT_c FMT_s FMT_gG) _eval3( ARG_c ARG_s ARG_gG));
  LIBFUNC(cdgGnopuxX, _quot( FMT_c FMT_gG) _eval3( ARG_c ARG_gG));
  LIBFUNC(cdnopsuxX, _quot( FMT_c FMT_s) _eval3( ARG_c ARG_s));
  LIBFUNC(cdnopuxX, _quot( FMT_c) _eval3( ARG_c));
  LIBFUNC(eE, _quot( FMT_eE) _eval3( ARG_eE));
  LIBFUNC(eEfF, _quot( FMT_eE FMT_fF) _eval3( ARG_eE ARG_fF));
  LIBFUNC(eEfFgG, _quot( FMT_eE FMT_fF FMT_gG) _eval3( ARG_eE ARG_fF ARG_gG));
  LIBFUNC(eEfFgGs, _quot( FMT_s FMT_eE FMT_fF FMT_gG) _eval3( ARG_s ARG_eE ARG_fF ARG_gG));
  LIBFUNC(eEfFs, _quot( FMT_s FMT_eE FMT_fF) _eval3( ARG_s ARG_eE ARG_fF));
  LIBFUNC(eEgG, _quot( FMT_eE FMT_gG) _eval3( ARG_eE ARG_gG));
  LIBFUNC(eEgGs, _quot( FMT_s FMT_eE FMT_gG) _eval3( ARG_s ARG_eE ARG_gG));
  LIBFUNC(eEs, _quot( FMT_s FMT_eE) _eval3( ARG_s ARG_eE));
  LIBFUNC(fF, _quot( FMT_fF) _eval3( ARG_fF));
  LIBFUNC(fFgG, _quot( FMT_fF FMT_gG) _eval3( ARG_fF ARG_gG));
  LIBFUNC(fFgGs, _quot( FMT_s FMT_fF FMT_gG) _eval3( ARG_s ARG_fF ARG_gG));
  LIBFUNC(fFs, _quot( FMT_s FMT_fF) _eval3( ARG_s ARG_fF));
  LIBFUNC(gG, _quot( FMT_gG) _eval3( ARG_gG));
  LIBFUNC(gGs, _quot( FMT_s FMT_gG) _eval3( ARG_s ARG_gG));
  LIBFUNC(s, _quot( FMT_s) _eval3( ARG_s));
}

