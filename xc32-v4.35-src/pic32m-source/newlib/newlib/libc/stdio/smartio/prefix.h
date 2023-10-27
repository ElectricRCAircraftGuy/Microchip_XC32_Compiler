#ifndef PREFIX_H
#define PREFIX_H 1

#include <newlib.h>

/* We'll control this macro to allow ll to be excluded. */
#ifdef _WANT_IO_LONG_LONG
# undef _WANT_IO_LONG_LONG
#endif

#define XCAT(x,y) x ## y
#define CAT(x,y) XCAT(x,y)
#ifndef PREFIX
#define PREFIX
#endif
#ifndef SUFFIX
#define SUFFIX
#endif
#define FUNC0(x) CAT(CAT(PREFIX,x),_0)
#define FUNC(x) CAT(CAT(PREFIX,x),SUFFIX)
#define FUNC_(x) CAT(CAT(_,PREFIX),CAT(x,SUFFIX))
#define STRINGIZE2(X) #X
#define STRINGIZE(X) STRINGIZE2(X)

/* The following are required for FILE struct differences from the
   original HTC code. */
#define SET_FILE_SIZE(fp,x) do{ (fp)._bf._size = (fp)._w = (x); } while(0)
#define SET_FILE_CNT(fp,x) do{ ; } while(0)
#define SET_FILE_PTR(fp,x) do{ (fp)._bf._base = (fp)._p = (x); } while(0)
#define SET_FILE_FLAGS(fp) do { (fp)._flags = __SWR | __SSTR; } while(0)
#define SET_FILE(fp,x) do { (fp)._file = (x); } while(0)

#if defined(__C32_VERSION__)
/* C32 supports a no-float multilib variant */
# if defined (__NO_FLOAT)
#   undef SIO_FLOAT
#   ifndef INTEGER_IO
#     define INTEGER_IO
#   endif
# endif
#endif /* __C32_VERSION__ */

#ifdef __SMARTIOV2__
# define CUSTOM_PRINTF
/*
 * defines that are controlled by SMARTIO
 * These are bsaed on the SMARTIO macros defined in the command line
 * to control enabled features, based on the HTC implementation for MIPS.
 * All symbols have been given the SIO_ prefix to avoid collisions with
 * common macros like CHAR, LONG etc.
 *
 */
# if defined(__SMARTIO_E__) || \
     defined(__SMARTIO_G__) || defined(__SMARTIO_X__)
#   define SIO_UPCASE
# endif
# if defined(__SMARTIO_e__) || defined(__SMARTIO_f__) || \
     defined(__SMARTIO_g__) || defined(__SMARTIO_x__)
#   define SIO_LOWCASE
# endif
# if defined(__SMARTIO_X__)
#   define SIO_HEXUPCASE
# endif
# if defined(__SMARTIO_x__)
#   define SIO_HEXLOWCASE
# endif
# if defined(__SMARTIO_e__) || defined(__SMARTIO_E__)
#   define SIO_EFMT 
# endif
# if defined(__SMARTIO_f__) || defined(__SMARTIO_F__)
#   define SIO_FFMT 
# endif
# if defined(__SMARTIO_g__) || defined(__SMARTIO_G__)
#   define SIO_GFMT 
# endif
# if defined(__SMARTIO_i__) || defined(__SMARTIO_d__)
#   define SIO_TEN 
# endif
# if defined(__SMARTIO_o__)
#   define SIO_EIGHT 
# endif
# if defined(__SMARTIO_p__)
#   define SIO_POINTER 
# endif
# if defined(__SMARTIO_x__) || defined(__SMARTIO_X__)
#   define SIO_SIXTEEN 
# endif
# ifndef __XC32 /* LLONG only controlled by macro for XC16 */
#   ifdef  __SMARTIO_L__
#     define SIO_LLONG
#   endif
# endif

/*
 * defines that are not (yet?) controlled by SMARTIO
 *
 */
# define SIO_OPTSIGN
# define SIO_SPCSIGN
# define SIO_MANSIGN
# define SIO_NEGSIGN
# define SIO_FILL
# define SIO_LEFT
# ifdef __XC32
#   define SIO_LLONG
#   define __SMARTIO_L__
# endif
# define SIO_UNSIGN
# define SIO_PRECISION
# define SIO_WIDTH   1               // width used
# define SIO_STAR    1               // width or precision as an arg
# define SIO_PERCPERC        1       // %% used
# define SIO_SPRINTF 1               // sprintf is used
# define SIO_PRINTF  1               // printf is used
# define SIO_MULTRAD 1               // handle multiple radices
# define SIO_RETVALUE        1       // return value is needed

# if defined(__SMARTIO_s__)
#   define SIO_STRING 1
# endif

# if defined(__SMARTIO_c__)
#   define SIO_CHAR 1
# endif

# if defined(__SMARTIO_e__) || defined(__SMARTIO_E__) || \
     defined(__SMARTIO_f__) || defined(__SMARTIO_F__) || \
     defined(__SMARTIO_g__) || defined(__SMARTIO_G__) && !defined(INTEGER_IO)
#   define	SIO_FLOAT		1

#   if defined(__XC32) /* 64-bit float only controlled by macro for XC16 */
#     if defined(__FLOAT)
#       define SIO_FLOAT64       1
#       define SIO_LONG          1
#       define SIO_LONG64        1
#     endif
#   else
#     define SIO_FLOAT64      __SMARTIO_L__ 
#   endif
# endif

# if defined(__SMARTIO_i__) || defined(__SMARTIO_d__) || \
     defined(__SMARTIO_x__) || defined(__SMARTIO_X__) || \
     defined(__SMARTIO_o__) || defined(__SMARTIO_o__)
#   define SIO_LONG          1
#   ifdef __SMARTIO_L__
#     define SIO_LONG64        1
#   endif
# endif

#else /* !__SMARTIOV2__ */

# ifndef	INTEGER_IO
#   define	SIO_FLOAT		1
#   if defined(__XC32)
#     if defined(SIO_FLOAT)
#       define	SIO_FLOAT64	1
#     endif
#   else
#     ifdef __SMARTIO_L__
#       define SIO_FLOAT64      1
#     endif
#   endif
# endif
# define SIO_LONG          1
# ifdef __XC32
#   define SIO_LONG64        1
# endif

#endif /* __SMARTIOV2__ */

/* indicate if any % was specified. note that this shouldn't be useful; a puts
   call should be generated instead. */
#if defined(SIO_LONG) || defined(SIO_FLOAT) || defined(SIO_STRING) || defined(SIO_CHAR) || defined(SIO_POINTER)
# define SIO_FORMAT 1
#endif

/* 
 * The following maps the HTC-based definitions above to common macros
 * for use in the newlib-based vfprintf and vfscanf implementations.
 * They are renamed to be a bit more clear on the usage and to use a consistent
 * '#if _SIO_xxx' syntax. 
 * One day soon this can be cleaned up to define the _SIO macros directly
 * from the command line controls...
 */
#if (defined(__NO_FLOAT) || !defined(SIO_FLOAT)) && !defined(INTEGER_IO)
# define NO_FLOATING_POINT 1
#endif
#if defined(INTEGER_IO)
# define INTEGER_ONLY 1
#endif
#ifdef SIO_LONG64
# define _WANT_IO_LONG_LONG
#endif
#define _SIO_UPPER              defined(SIO_UPCASE)
#define _SIO_LOWER              defined(SIO_LOWCASE)
#define _SIO_UPPER_HEX          defined(SIO_HEXUPCASE)
#define _SIO_LOWER_HEX          defined(SIO_HEXLOWCASE)
#define _SIO_eE                 defined(SIO_EFMT)
#define _SIO_fF                 defined(SIO_FFMT)
#define _SIO_gG                 defined(SIO_GFMT)
#define _SIO_p                  defined(SIO_POINTER)
#define _SIO_s                  defined(SIO_STRING)
#define _SIO_c                  defined(SIO_CHAR)
#define _SIO_DEC                defined(SIO_TEN)
#define _SIO_OCT                defined(SIO_EIGHT)
#define _SIO_HEX                defined(SIO_SIXTEEN)
#define _SIO_fmt                defined(SIO_FORMAT)

/* The following definitions of _SIO_RADIX are tied to the 'base' enum in
   vfprint_r. */
#ifdef _SIO_RADIX
# undef _SIO_RADIX
#endif
#if (_SIO_OCT) && !(_SIO_DEC) && !(_SIO_HEX)
# define _SIO_RADIX    OCT
#elif (_SIO_DEC) && !(_SIO_OCT) && !(_SIO_HEX)
# define _SIO_RADIX    DEC 
#elif (_SIO_HEX) && !(_SIO_OCT) && !(_SIO_DEC)
# define _SIO_RADIX    HEX
#endif
/* TODO: otherwise must be string only? */

/* The following macros clean up some code for checking uppercase/lowercase
   variants.
*/
#if _SIO_UPPER && _SIO_LOWER
# define _SIO_CHAR_IS(var,lower,upper) (lower == (var) || upper == (var))
# define _SIO_CASE(lower,upper)        case lower: case upper
# define _SIO_SEL(cond,lower,upper)    ((cond) ? upper : lower) 
#elif _SIO_UPPER
# define _SIO_CHAR_IS(var,lower,upper) (upper == (var))
# define _SIO_CASE(lower,upper)        case upper
# define _SIO_SEL(cond,lower,upper)    upper
#else
# define _SIO_CHAR_IS(var,lower,upper) (lower == (var))
# define _SIO_CASE(lower,upper)        case lower
# define _SIO_SEL(cond,lower,upper)    lower
#endif

/* TODO: map __FLOAT && !__FLOAT64 to control for 32-bit only? */
/* TODO: support _NO_POS_ARGS? */

/* Turn some stuff on/off always for smartIO
 * NOTE: C99 formats have not been modified assuming they are never enabled.
 */
#ifdef _WANT_IO_C99_FORMATS
# warning "_WANT_IO_C99 FORMATS unsupported with smartIO"
# undef _WANT_IO_C99_FORMATS
#endif
#ifndef __SINGLE_THREAD__
# define __SINGLE_THREAD__
#endif
#ifdef _WANT_IO_LONG_DOUBLE
# warning "_WANT_IO_LONG_DOUBLE unsupported with smartIO"
# undef _WANT_IO_LONG_DOUBLE
#endif
#ifdef _MB_CAPABLE
# warning "_MB_CAPABLE unsupported with smartIO"
# undef _MB_CAPABLE
#endif
#ifdef _GLIBC_EXTENSION
# warning "_GLIB_EXTENSION unsupported with smartIO"
# undef _GLIBC_EXTENSION
#endif
#ifndef __OPTIMIZE_SIZE__
# define __OPTIMIZE_SIZE__ 1 /* hey, why not? */
#endif

/* set to nonzero to control support for 'n' parameter to store string length */
#define _SIO_n 0

/* set to nonzero to control support for 'a' parameter for hex float */
#define _SIO_aA (SIO_FLOAT)

/* set to nonzero to enable unspecified 'extensions' */
#define _SIO_EXT 0

/* Ubiquitous forward declaration of core print/scan routines */
#include <stdarg.h>
extern int FUNC(vfprintf)(FILE *, const char *, register va_list);
extern int FUNC(vfscanf)(FILE *, const char *, register va_list);

#endif /* PREFIX_H */

