/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Copyright (c) 2012-2014 ARM Ltd
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the company may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ARM LTD ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ARM LTD BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Modified for smartIO support. Define __SMARTIO_<c>__ to enable support for
   format specifier <c>. 
   The vanilla nano implementation attempts? to use a weak symbol for the 
   float-support function but it's not clear how that is brought in. In line
   with the smart-io approach, we include the integer and float functions
   here and subject them to the same guards.
*/

#ifndef __SMARTIOV2__
# define __SMARTIOV2__ 1
#endif
#include <stdio.h>
#include <stdarg.h>
#include "prefix.h"

/* the g and e paths converge in the float code. */
#if _SIO_gG
#undef _SIO_eE
#define _SIO_eE 1
#endif

/* bypass the usual nano controls for smart-io */
#ifndef NO_FLOATING_POINT
#ifndef FLOATING_POINT
#define FLOATING_POINT
#endif
#endif

/*
FUNCTION
<<vfprintf>>, <<vprintf>>, <<vsprintf>>, <<vsnprintf>>, <<vasprintf>>, <<vasnprintf>>---format argument list

INDEX
	vfprintf
INDEX
	_vfprintf_r
INDEX
	vprintf
INDEX
	_vprintf_r
INDEX
	vsprintf
INDEX
	_vsprintf_r
INDEX
	vsnprintf
INDEX
	_vsnprintf_r
INDEX
	vasprintf
INDEX
	_vasprintf_r
INDEX
	vasnprintf
INDEX
	_vasnprintf_r

ANSI_SYNOPSIS
	#include <stdio.h>
	#include <stdarg.h>
	int vprintf(const char *<[fmt]>, va_list <[list]>);
	int vfprintf(FILE *<[fp]>, const char *<[fmt]>, va_list <[list]>);
	int vsprintf(char *<[str]>, const char *<[fmt]>, va_list <[list]>);
	int vsnprintf(char *<[str]>, size_t <[size]>, const char *<[fmt]>,
                      va_list <[list]>);
	int vasprintf(char **<[strp]>, const char *<[fmt]>, va_list <[list]>);
	char *vasnprintf(char *<[str]>, size_t *<[size]>, const char *<[fmt]>,
                         va_list <[list]>);

	int _vprintf_r(struct _reent *<[reent]>, const char *<[fmt]>,
                        va_list <[list]>);
	int _vfprintf_r(struct _reent *<[reent]>, FILE *<[fp]>,
                        const char *<[fmt]>, va_list <[list]>);
	int _vsprintf_r(struct _reent *<[reent]>, char *<[str]>,
                        const char *<[fmt]>, va_list <[list]>);
	int _vasprintf_r(struct _reent *<[reent]>, char **<[str]>,
                         const char *<[fmt]>, va_list <[list]>);
	int _vsnprintf_r(struct _reent *<[reent]>, char *<[str]>,
                         size_t <[size]>, const char *<[fmt]>, va_list <[list]>);
	char *_vasnprintf_r(struct _reent *<[reent]>, char *<[str]>,
                            size_t *<[size]>, const char *<[fmt]>, va_list <[list]>);

DESCRIPTION
<<vprintf>>, <<vfprintf>>, <<vasprintf>>, <<vsprintf>>, <<vsnprintf>>,
and <<vasnprintf>> are (respectively) variants of <<printf>>,
<<fprintf>>, <<asprintf>>, <<sprintf>>, <<snprintf>>, and
<<asnprintf>>.  They differ only in allowing their caller to pass the
variable argument list as a <<va_list>> object (initialized by
<<va_start>>) rather than directly accepting a variable number of
arguments.  The caller is responsible for calling <<va_end>>.

<<_vprintf_r>>, <<_vfprintf_r>>, <<_vasprintf_r>>, <<_vsprintf_r>>,
<<_vsnprintf_r>>, and <<_vasnprintf_r>> are reentrant versions of the
above.

RETURNS
The return values are consistent with the corresponding functions.

PORTABILITY
ANSI C requires <<vprintf>>, <<vfprintf>>, <<vsprintf>>, and
<<vsnprintf>>.  The remaining functions are newlib extensions.

Supporting OS subroutines required: <<close>>, <<fstat>>, <<isatty>>,
<<lseek>>, <<read>>, <<sbrk>>, <<write>>.
*/

#if defined(LIBC_SCCS) && !defined(lint)
/*static char *sccsid = "from: @(#)vfprintf.c	5.50 (Berkeley) 12/16/92";*/
static char *rcsid = "$Id$";
#endif /* LIBC_SCCS and not lint */

/* Actual printf innards.
   This code is large and complicated...  */
#include <newlib.h>

#define VFPRINTF FUNC(vfprintf)
#define _VFPRINTF_R FUNC(vfprintf_r)

#include <_ansi.h>
#include <reent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <wchar.h>
#include <sys/lock.h>
#include <stdarg.h>
#include "../local.h"
#include "../../stdlib/local.h"
#include "../fvwrite.h"
#include "../vfieeefp.h"
#include "../nano-vfprintf_local.h"

#ifdef SIO_FLOAT
/* support routines for __printf_float */
static int
__exponent(char *p0, int exp, int fmtch);

static char *
__cvt (struct _reent *data, _PRINTF_FLOAT_TYPE value, int ndigits, int flags,
       char *sign, int *decpt, int ch, int *length, char *buf);
#endif

/* Decode and print floating point number specified by "eEfgG".  */
static int
__printf_float (struct _reent *data,
	        struct _prt_data_t *pdata,
	        FILE * fp,
	        int (*pfunc) (struct _reent *, FILE *, const char *, size_t len), 
                va_list * ap)
{
#ifdef SIO_FLOAT
#define _fpvalue (pdata->_double_)

  char *decimal_point = _localeconv_r (data)->decimal_point;
  size_t decp_len = strlen (decimal_point);
  /* Temporary negative sign for floats.  */
  char softsign;
  /* Integer value of exponent.  */
  int expt;
  /* Character count for expstr.  */
  int expsize = 0;
  /* Actual number of digits returned by cvt.  */
  int ndig = 0;
  char *cp;
  int n;
  /* Field size expanded by dprec(not for _printf_float).  */
  int realsz;
  char code = pdata->code;

  if (pdata->flags & LONGDBL)
    {
      _fpvalue = (double) GET_ARG (N, *ap, _LONG_DOUBLE);
    }
  else
    {
      _fpvalue = GET_ARG (N, *ap, double);
    }

  /* Do this before tricky precision changes.

     If the output is infinite or NaN, leading
     zeros are not permitted.  Otherwise, scanf
     could not read what printf wrote.  */
  if (isinf (_fpvalue))
    {
      if (_fpvalue < 0)
	pdata->l_buf[0] = '-';
#if _SIO_UPPER && _SIO_LOWER
      if (code <= 'G')		/* 'A', 'E', 'F', or 'G'.  */
	cp = "INF";
      else
	cp = "inf";
#elif _SIO_UPPER
      cp = "INF";
#else
      cp = "inf";
#endif
      pdata->size = 3;
      pdata->flags &= ~ZEROPAD;
      goto print_float;
    }
  if (isnan (_fpvalue))
    {
#if _SIO_UPPER && _SIO_LOWER
      if (code <= 'G')		/* 'A', 'E', 'F', or 'G'.  */
	cp = "NAN";
      else
	cp = "nan";
#elif _SIO_UPPER
      cp = "NAN";
#else
      cp = "nan";
#endif
      pdata->size = 3;
      pdata->flags &= ~ZEROPAD;
      goto print_float;
    }

  if (pdata->prec == -1)
    {
      pdata->prec = DEFPREC;
    }
#if _SIO_gG
  else if ((code == 'g' || code == 'G') && pdata->prec == 0)
    {
      pdata->prec = 1;
    }
#endif

  pdata->flags |= FPT;

  cp = __cvt (data, _fpvalue, pdata->prec, pdata->flags, &softsign,
	      &expt, code, &ndig, cp);

#if _SIO_gG
  if (code == 'g' || code == 'G')
    {
      if (expt <= -4 || expt > pdata->prec)
	/* 'e' or 'E'.  */
	code -= 2;
      else
	code = 'g';
    }
#endif
#if _SIO_eE
  if (code <= 'e')
    {
      /* 'a', 'A', 'e', or 'E' fmt.  */
      --expt;
      expsize = __exponent (pdata->expstr, expt, code);
      pdata->size = expsize + ndig;
      if (ndig > 1 || pdata->flags & ALT)
	++pdata->size;
    }
  else
#endif
    {
#if _SIO_fF
      if (code == 'f')
	{
	  /* 'f' fmt.  */
	  if (expt > 0)
	    {
	      pdata->size = expt;
	      if (pdata->prec || pdata->flags & ALT)
		pdata->size += pdata->prec + 1;
	    }
	  else
	    /* "0.X".  */
	    pdata->size = (pdata->prec || pdata->flags & ALT)
	      ? pdata->prec + 2 : 1;
	}
      else 
#endif
      if (expt >= ndig)
	{
	  /* Fixed g fmt.  */
	  pdata->size = expt;
	  if (pdata->flags & ALT)
	    ++pdata->size;
	}
      else
	pdata->size = ndig + (expt > 0 ? 1 : 2 - expt);
      pdata->lead = expt;
    }

  if (softsign)
    pdata->l_buf[0] = '-';
print_float:
  if (_printf_common (data, pdata, &realsz, fp, pfunc) == -1)
    goto error;

  if ((pdata->flags & FPT) == 0)
    {
      PRINT (cp, pdata->size);
    }
  else
    {
      /* Glue together f_p fragments.  */
#if _SIO_fF || _SIO_gG
      if (code >= 'f')
	{
	  /* 'f' or 'g'.  */
	  if (_fpvalue == 0)
	    {
	      /* Kludge for __dtoa irregularity.  */
	      PRINT ("0", 1);
	      if (expt < ndig || pdata->flags & ALT)
		{
		  PRINT (decimal_point, decp_len);
		  PAD (ndig - 1, pdata->zero);
		}
	    }
	  else if (expt <= 0)
	    {
	      PRINT ("0", 1);
	      if (expt || ndig || pdata->flags & ALT)
		{
		  PRINT (decimal_point, decp_len);
		  PAD (-expt, pdata->zero);
		  PRINT (cp, ndig);
		}
	    }
	  else
	    {
	      char *convbuf = cp;
	      PRINTANDPAD (cp, convbuf + ndig, pdata->lead, pdata->zero);
	      cp += pdata->lead;
	      if (expt < ndig || pdata->flags & ALT)
		PRINT (decimal_point, decp_len);
	      PRINTANDPAD (cp, convbuf + ndig, ndig - expt, pdata->zero);
	    }
	}
      else
#endif
#if _SIO_aA || _SIO_eE
	{
	  /* 'a', 'A', 'e', or 'E'.  */
	  if (ndig > 1 || pdata->flags & ALT)
	    {
	      PRINT (cp, 1);
	      cp++;
	      PRINT (decimal_point, decp_len);
	      if (_fpvalue)
		{
		  PRINT (cp, ndig - 1);
		}
	      /* "0.[0..]".  */
	      else
		/* __dtoa irregularity.  */
		PAD (ndig - 1, pdata->zero);
	    }
	  else			/* "XeYYY".  */
	    PRINT (cp, 1);
	  PRINT (pdata->expstr, expsize);
	}
#endif
    }

  /* Left-adjusting padding (always blank).  */
  if (pdata->flags & LADJUST)
    PAD (pdata->width - realsz, pdata->blank);

  return (pdata->width > realsz ? pdata->width : realsz);
error:
#endif /* SIO_FLOAT */
  return -1;

#undef _fpvalue
}

/* provide definition of _printf_float to support users using -u _printf_float
   to enable float support. */
int _printf_float (struct _reent *data, struct _prt_data_t *pdata, FILE *fp,
		   int (*pfunc) (struct _reent *, FILE *, const char *, size_t len),
		   va_list *ap) _ATTRIBUTE((__weak__,__alias__("__printf_float")));

static int
__printf_i (struct _reent *data, struct _prt_data_t *pdata, FILE *fp,
	    int (*pfunc)(struct _reent *, FILE *, const char *, size_t len),
	    va_list *ap);

extern int _VFPRINTF_R (struct _reent *, FILE *, const char *, va_list);

int
VFPRINTF (FILE * fp, const char *fmt0, va_list ap)
{
  int result;
  result = _VFPRINTF_R (_REENT, fp, fmt0, ap);
  return result;
}

extern int __ssfputs_r (struct _reent *, FILE *, const char *, size_t);

#define __SPRINT __ssfputs_r

/* Do not need FLUSH for all sprintf functions.  */
#define FLUSH()

int
_VFPRINTF_R (struct _reent *data, FILE * fp, const char *fmt0, va_list ap)
{
  register char *fmt;	/* Format string.  */
  register int n, m;	/* Handy integers (short term usage).  */
  register char *cp;	/* Handy char pointer (short term usage).  */
  const char *flag_chars;
  struct _prt_data_t prt_data;	/* All data for decoding format string.  */

  /* Output function pointer.  */
  int (*pfunc)(struct _reent *, FILE *, const char *, size_t len);

  pfunc = __SPRINT;

  /* Initialize std streams if not dealing with sprintf family.  */
  CHECK_INIT (data, fp);
  _newlib_flockfile_start (fp);

  /* Sorry, fprintf(read_only_file, "") returns EOF, not 0.  */
  if (cantwrite (data, fp))
    {
      _newlib_flockfile_exit (fp);
      return (EOF);
    }

  fmt = (char *)fmt0;
  prt_data.ret = 0;
  prt_data.blank = ' ';
  prt_data.zero = '0';

  /* Scan the format for conversions (`%' character).  */
  for (;;)
    {
      cp = fmt;
      while (*fmt != '\0' && *fmt != '%')
	fmt += 1;

      if ((m = fmt - cp) != 0)
	{
	  PRINT (cp, m);
	  prt_data.ret += m;
	}
      if (*fmt == '\0')
	goto done;

      fmt++;		/* Skip over '%'.  */

      prt_data.flags = 0;
      prt_data.width = 0;
      prt_data.prec = -1;
      prt_data.dprec = 0;
      prt_data.l_buf[0] = '\0';
#ifdef FLOATING_POINT
      prt_data.lead = 0;
#endif
      /* The flags.  */
      /*
       * ``Note that 0 is taken as a flag, not as the
       * beginning of a field width.''
       *	-- ANSI X3J11
       */
      flag_chars = "#-0+ ";
      for (; cp = memchr (flag_chars, *fmt, 5); fmt++)
	prt_data.flags |= (1 << (cp - flag_chars));

      if (prt_data.flags & SPACESGN)
	prt_data.l_buf[0] = ' ';

      /*
       * ``If the space and + flags both appear, the space
       * flag will be ignored.''
       *	-- ANSI X3J11
       */
      if (prt_data.flags & PLUSSGN)
	prt_data.l_buf[0] = '+';

      /* The width.  */
      if (*fmt == '*')
	{
	  /*
	   * ``A negative field width argument is taken as a
	   * - flag followed by a positive field width.''
	   *	-- ANSI X3J11
	   * They don't exclude field widths read from args.
	   */
	  prt_data.width = GET_ARG (n, ap, int);
	  if (prt_data.width < 0)
	    {
	      prt_data.width = -prt_data.width;
	      prt_data.flags |= LADJUST;
	    }
	  fmt++;
	}
      else
        {
	  for (; is_digit (*fmt); fmt++)
	    prt_data.width = 10 * prt_data.width + to_digit (*fmt);
	}

      /* The precision.  */
      if (*fmt == '.')
	{
	  fmt++;
	  if (*fmt == '*')
	    {
	      fmt++;
	      prt_data.prec = GET_ARG (n, ap, int);
	      if (prt_data.prec < 0)
		prt_data.prec = -1;
	    }
	  else
	    {
	      prt_data.prec = 0;
	      for (; is_digit (*fmt); fmt++)
		prt_data.prec = 10 * prt_data.prec + to_digit (*fmt);
	    }
	}

      /* The length modifiers.  */
      flag_chars = "hlL";
      if ((cp = memchr (flag_chars, *fmt, 3)) != NULL)
	{
	  prt_data.flags |= (SHORTINT << (cp - flag_chars));
	  fmt++;
	}

      /* The conversion specifiers.  */
      prt_data.code = *fmt++;
      cp = memchr ("efgEFG", prt_data.code, 6);
#ifdef SIO_FLOAT
      /* If cp is not NULL, we are facing FLOATING POINT NUMBER.  */
      if (cp)
	n = _printf_float (data, &prt_data, fp, pfunc, &ap);
      else
#endif
	n = __printf_i (data, &prt_data, fp, pfunc, &ap);

      if (n == -1)
	goto error;

      prt_data.ret += n;
    }
done:
  FLUSH ();
error:
  _newlib_flockfile_end (fp);
  return (__sferror (fp) ? EOF : prt_data.ret);
}

int
__printf_i (struct _reent *data, struct _prt_data_t *pdata, FILE *fp,
	    int (*pfunc)(struct _reent *, FILE *, const char *, size_t len),
	    va_list *ap)
{
  /* Field size expanded by dprec.  */
  int realsz;
  u_quad_t _uquad;
  int base;
  int n;
  char *cp = pdata->buf + BUF;
#if _SIO_HEX || _SIO_p
  char *xdigs = "0123456789ABCDEF";
#endif

  /* Decoding the conversion specifier.  */
  switch (pdata->code)
    {
#if _SIO_c
    case 'c':
      *--cp = GET_ARG (N, *ap, int);
      pdata->size = 1;
      goto non_number_nosign;
#endif
#if _SIO_DEC
    case 'd':
    case 'i':
      _uquad = SARG (pdata->flags);
      if ((long) _uquad < 0)
	{
	  _uquad = -_uquad;
	  pdata->l_buf[0] = '-';
	}
      base = 10;
      goto number;
#endif
#ifdef SIO_LONG
    case 'u':
    case 'o':
      _uquad = UARG (pdata->flags);
      base = (pdata->code == 'o') ? 8 : 10;
      goto nosign;
#if _SIO_HEX
    case 'X':
      pdata->l_buf[2] = 'X';
      goto hex;
#endif
#if _SIO_p
    case 'p':
      /*
       * ``The argument shall be a pointer to void.  The
       * value of the pointer is converted to a sequence
       * of printable characters, in an implementation-
       * defined manner.''
       *	-- ANSI X3J11
       */
      pdata->flags |= HEXPREFIX;
      if (sizeof (void*) > sizeof (int))
	pdata->flags |= LONGINT;
      /* NOSTRICT.  */
#endif
#if _SIO_p || _SIO_HEX
    case 'x':
      pdata->l_buf[2] = 'x';
      xdigs = "0123456789abcdef";
hex:
      _uquad = UARG (pdata->flags);
      base = 16;
      if (pdata->flags & ALT)
	pdata->flags |= HEXPREFIX;

      /* Leading 0x/X only if non-zero.  */
      if (_uquad == 0)
	pdata->flags &= ~HEXPREFIX;
#endif
      /* Unsigned conversions.  */
nosign:
      pdata->l_buf[0] = '\0';
      /*
       * ``... diouXx conversions ... if a precision is
       * specified, the 0 flag will be ignored.''
       *	-- ANSI X3J11
       */
number:
      if ((pdata->dprec = pdata->prec) >= 0)
	pdata->flags &= ~ZEROPAD;

      /*
       * ``The result of converting a zero value with an
       * explicit precision of zero is no characters.''
       *	-- ANSI X3J11
       */
      if (_uquad != 0 || pdata->prec != 0)
	{
	  do
	    {
	      *--cp = xdigs[_uquad % base];
	      _uquad /= base;
	    }
	  while (_uquad);
	}
      /* For 'o' conversion, '#' increases the precision to force the first
	 digit of the result to be zero.  */
      if (base == 8 && (pdata->flags & ALT) && pdata->prec <= pdata->size)
	*--cp = '0';

      pdata->size = pdata->buf + BUF - cp;
      break;
#endif /* SIO_LONG */
#if _SIO_n
    case 'n':
      if (pdata->flags & LONGINT)
	*GET_ARG (N, *ap, long_ptr_t) = pdata->ret;
      else if (pdata->flags & SHORTINT)
	*GET_ARG (N, *ap, short_ptr_t) = pdata->ret;
      else
	*GET_ARG (N, *ap, int_ptr_t) = pdata->ret;
#endif
    case '\0':
      pdata->size = 0;
      break;
#if _SIO_s
    case 's':
      cp = GET_ARG (N, *ap, char_ptr_t);
      /* Precision gives the maximum number of chars to be written from a
	 string, and take prec == -1 into consideration.
	 Use normal Newlib approach here to support case where cp is not
	 nul-terminated.  */
      char *p = memchr (cp, 0, pdata->prec);

      if (p != NULL)
	pdata->prec = p - cp;

      pdata->size = pdata->prec;
      goto non_number_nosign;
#endif
    default:
      /* "%?" prints ?, unless ? is NUL.  */
      /* Pretend it was %c with argument ch.  */
      *--cp = pdata->code;
      pdata->size = 1;
non_number_nosign:
      pdata->l_buf[0] = '\0';
      break;
    }

    /* Output.  */
    n = _printf_common (data, pdata, &realsz, fp, pfunc);
    if (n == -1)
      goto error;

    PRINT (cp, pdata->size);
    /* Left-adjusting padding (always blank).  */
    if (pdata->flags & LADJUST)
      PAD (pdata->width - realsz, pdata->blank);

    return (pdata->width > realsz ? pdata->width : realsz);
error:
    return -1;
}

#ifdef SIO_FLOAT
int
__exponent(char *p0, int exp, int fmtch)
{
	register char *p, *t;
	char expbuf[MAXEXPLEN];
# ifdef _WANT_IO_C99_FORMATS
	int isa = fmtch == 'a' || fmtch == 'A';
# else
#  define isa 0
# endif

	p = p0;
	*p++ = isa ? 'p' - 'a' + fmtch : fmtch;
	if (exp < 0) {
		exp = -exp;
		*p++ = '-';
	}
	else
		*p++ = '+';
	t = expbuf + MAXEXPLEN;
	if (exp > 9) {
		do {
			*--t = to_char (exp % 10);
		} while ((exp /= 10) > 9);
		*--t = to_char (exp);
		for (; t < expbuf + MAXEXPLEN; *p++ = *t++);
	}
	else {
		if (!isa)
			*p++ = '0';
		*p++ = to_char (exp);
	}
	return (p - p0);
}

/* Using reentrant DATA, convert finite VALUE into a string of digits
   with no decimal point, using NDIGITS precision and FLAGS as guides
   to whether trailing zeros must be included.  Set *SIGN to nonzero
   if VALUE was negative.  Set *DECPT to the exponent plus one.  Set
   *LENGTH to the length of the returned string.  CH must be one of
   [aAeEfFgG]; if it is [aA], then the return string lives in BUF,
   otherwise the return value shares the mprec reentrant storage.  */
char *
__cvt (struct _reent *data, _PRINTF_FLOAT_TYPE value, int ndigits, int flags,
       char *sign, int *decpt, int ch, int *length, char *buf)
{
  int mode, dsgn;
  char *digits, *bp, *rve;
  union double_union tmp;

  tmp.d = value;
  /* This will check for "< 0" and "-0.0".  */
  if (word0 (tmp) & Sign_bit)
    {
      value = -value;
      *sign = '-';
    }
  else
    *sign = '\000';

#if _SIO_fF
  if (ch == 'f' || ch == 'F')
    {
      /* Ndigits after the decimal point.  */
      mode = 3;
    }
  else
#endif
    {
      /* To obtain ndigits after the decimal point for the 'e'
	 and 'E' formats, round to ndigits + 1 significant figures.  */
#if _SIO_eE
      if (ch == 'e' || ch == 'E')
	{
	  ndigits++;
	}
#endif
      /* Ndigits significant digits.  */
      mode = 2;
    }

  digits = _DTOA_R (data, value, mode, ndigits, decpt, &dsgn, &rve);

  /* Print trailing zeros.  */
  if (
#if _SIO_gG && (_SIO_eE || _SIO_fF || _SIO_aA)
      (ch != 'g' && ch != 'G') || 
#endif
      flags & ALT)
    {
      bp = digits + ndigits;
#ifdef _SIO_fF
      if (ch == 'f' || ch == 'F')
	{
	  if (*digits == '0' && value)
	    *decpt = -ndigits + 1;
	  bp += *decpt;
	}
#endif
      /* Kludge for __dtoa irregularity.  */
      if (value == 0)
	rve = bp;
      while (rve < bp)
	*rve++ = '0';
    }
  *length = rve - digits;
  return (digits);
}
#endif /* SIO_FLOAT */

