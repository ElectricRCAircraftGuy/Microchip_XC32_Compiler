/* Common code for comparison cases. Allow macro definitions to generate
   various flavours of functions. */

/* ROOT: root name, default printf */
#ifndef ROOT
# define ROOT printf
#endif

/* PREFIX: flavour to test (v, s, vsn etc), required */
#ifndef PREFIX
# error __FILE__: PREFIX undefined
#endif

/* SUFFIX: optional _r, etc., default empty */
#ifndef SUFFIX
# define SUFFIX
#endif

#define _eval(x,y) _eval2(_cat(x,_,y))
#define _evalf(x,y,...) _eval2( _eval(x,y) (__VA_ARGS__) )
#define _eval2(x) _eval3(x)
#define _eval3(...) __VA_ARGS__
#define _cat(x,y,z) _cat2(x,y,z)
#define _cat2(x,y,z) x##y##z
#define _quot(...) _quot2(__VA_ARGS__)
#define _quot2(...) #__VA_ARGS__
#define _newline \n

/* function name */
#define _funcname _cat(PREFIX,ROOT,SUFFIX)

/* function name with user suffix and preceding __ */
#define _rawname(sfx) _cat(_,PREFIX,_cat(ROOT,_,sfx))

/* buffer length */
#define _buflen 512

/* Initial arguments/types by prefix */
#define ARGS_ 
#define ARGT_
#define ARGS_f stdout,
#define ARGT_f FILE* fp,
#define ARGS_s _buf,
#define ARGT_s char* _buf,
#define ARGS_sn _buf, buflen, 
#define ARGT_sn char* _buf, size_t buflen,
#define ARGS_v
#define ARGT_v 
#define ARGS_vf ARGS_f
#define ARGT_vf ARGT_f
#define ARGS_vs ARGS_s
#define ARGT_vs ARGT_s
#define ARGS_vsn ARGS_sn
#define ARGT_vsn ARGT_sn

/* trailing argument types by prefix */
#define ARGF_ ...
#define ARGF_f ARGF_
#define ARGF_s ARGF_
#define ARGF_sn ARGF_
#define ARGF_v va_list
#define ARGF_vf ARGF_v
#define ARGF_vs ARGF_v
#define ARGF_vsn ARGF_v

/* calling convention by prefix */
#define CALL_(name,fmt,...) \
  do { name (_eval(ARGS,PREFIX) fmt, __VA_ARGS__); } while (0)
#define CALL_f(...) CALL_(__VA_ARGS__)
#define CALL_s(...) CALL_(__VA_ARGS__)
#define CALL_sn(...) CALL_(__VA_ARGS__)

#define CALL_v(name,fmt,...) \
  void _cat(_cat(wrap,_,__LINE__),_,name) (_eval(ARGT,PREFIX) int dummy, ...) \
  { \
    va_list _va; \
    va_start (_va,dummy); \
    name (_eval(ARGS,PREFIX) fmt, _va); \
  } \
  do { \
    _cat(_cat(wrap,_,__LINE__),_,name)(_eval(ARGS,PREFIX) 0, __VA_ARGS__); \
  } while (0)
#define CALL_vf(...) CALL_v(__VA_ARGS__)
#define CALL_vs(...) CALL_v(__VA_ARGS__)
#define CALL_vsn(...) CALL_v(__VA_ARGS__)

/* Macros to define format strings and argument lists by suffix components. */
#define FMT_c %c %d %o %p %x %X
#define ARG_c , arg_char, arg_int, arg_int, arg_ptr, arg_int, arg_int

#define FMT_s %s
#define ARG_s , arg_str

#define FMT_eE %e %E
#define ARG_eE , arg_flt, arg_flt

#define FMT_fF %f 
#define ARG_fF , arg_flt

#define FMT_gG %g %G
#define ARG_gG , arg_flt, arg_flt

/* Argument declarations corresponding to the above FMT/ARG defs. */
#define FN_ARG_DECL \
  char arg_char = 'c'; \
  int arg_int = -0x123; \
  int arg_intp = 0; \
  char *arg_ptr = &arg_char; \
  float arg_flt = 0.125; \
  static const char *arg_str = "string"; \
  size_t buflen = _buflen 

/* Main function call macro. */
#define FUNC(...) \
  _evalf(CALL,PREFIX,_funcname,__VA_ARGS__)

/* Explicit library call macro. */
#define LIBFUNC(sfx,...) \
  _evalf(CALL,PREFIX,_rawname(sfx),__VA_ARGS__)

#define DECL(sfx) \
  extern void _rawname(sfx) (_eval(ARGT,PREFIX) const char *, _eval(ARGF,PREFIX))

#include <stdio.h>
#include <stdarg.h>

static int failed = 0;
static char _buf[_buflen]; 
static void test (void);

int
main (void)
{
  test(); 
  if (failed)
    return 1;
  fflush(stdout);
  return 0;
}

