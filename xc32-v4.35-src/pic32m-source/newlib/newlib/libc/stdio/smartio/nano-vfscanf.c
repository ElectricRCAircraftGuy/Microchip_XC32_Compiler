/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
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

/*
FUNCTION
<<vfscanf>>, <<vscanf>>, <<vsscanf>>---format argument list

INDEX
	vfscanf
INDEX
	_vfscanf_r
INDEX
	vscanf
INDEX
	_vscanf_r
INDEX
	vsscanf
INDEX
	_vsscanf_r

ANSI_SYNOPSIS
	#include <stdio.h>
	#include <stdarg.h>
	int vscanf(const char *<[fmt]>, va_list <[list]>);
	int vfscanf(FILE *<[fp]>, const char *<[fmt]>, va_list <[list]>);
	int vsscanf(const char *<[str]>, const char *<[fmt]>, va_list <[list]>);

	int _vscanf_r(struct _reent *<[reent]>, const char *<[fmt]>,
                       va_list <[list]>);
	int _vfscanf_r(struct _reent *<[reent]>, FILE *<[fp]>, const char *<[fmt]>,
                       va_list <[list]>);
	int _vsscanf_r(struct _reent *<[reent]>, const char *<[str]>,
                       const char *<[fmt]>, va_list <[list]>);

TRAD_SYNOPSIS
	#include <stdio.h>
	#include <varargs.h>
	int vscanf( <[fmt]>, <[ist]>)
	char *<[fmt]>;
	va_list <[list]>;

	int vfscanf( <[fp]>, <[fmt]>, <[list]>)
	FILE *<[fp]>;
	char *<[fmt]>;
	va_list <[list]>;

	int vsscanf( <[str]>, <[fmt]>, <[list]>)
	char *<[str]>;
	char *<[fmt]>;
	va_list <[list]>;

	int _vscanf_r( <[reent]>, <[fmt]>, <[ist]>)
	struct _reent *<[reent]>;
	char *<[fmt]>;
	va_list <[list]>;

	int _vfscanf_r( <[reent]>, <[fp]>, <[fmt]>, <[list]>)
	struct _reent *<[reent]>;
	FILE *<[fp]>;
	char *<[fmt]>;
	va_list <[list]>;

	int _vsscanf_r( <[reent]>, <[str]>, <[fmt]>, <[list]>)
	struct _reent *<[reent]>;
	char *<[str]>;
	char *<[fmt]>;
	va_list <[list]>;

DESCRIPTION
<<vscanf>>, <<vfscanf>>, and <<vsscanf>> are (respectively) variants
of <<scanf>>, <<fscanf>>, and <<sscanf>>.  They differ only in
allowing their caller to pass the variable argument list as a
<<va_list>> object (initialized by <<va_start>>) rather than
directly accepting a variable number of arguments.

RETURNS
The return values are consistent with the corresponding functions:
<<vscanf>> returns the number of input fields successfully scanned,
converted, and stored; the return value does not include scanned
fields which were not stored.

If <<vscanf>> attempts to read at end-of-file, the return value
is <<EOF>>.

If no fields were stored, the return value is <<0>>.

The routines <<_vscanf_r>>, <<_vfscanf_f>>, and <<_vsscanf_r>> are
reentrant versions which take an additional first parameter which points to the
reentrancy structure.

PORTABILITY
These are GNU extensions.

Supporting OS subroutines required:
*/

#include <_ansi.h>
#include <reent.h>
#include <newlib.h>
#include <ctype.h>
#include <wctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <wchar.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include "local.h"
#include "../stdlib/local.h"
#include "nano-vfscanf_local.h"

#define VFSCANF FUNC(vfscanf)
#define _VFSCANF_R FUNC(_vfscanf_r)
#define __SVFSCANF_R FUNC(__svfscanf_r)

static int
__scanf_float (struct _reent *rptr,
	       struct _scan_data_t *pdata,
	       FILE *fp, va_list *ap)
{
#if SIO_FLOAT
  int c;
  char *p;
  float *flp;
  _LONG_DOUBLE *ldp;

  /* Scan a floating point number as if by strtod.  */
  /* This code used to assume that the number of digits is reasonable.
     However, ANSI / ISO C makes no such stipulation; we have to get
     exact results even when there is an unreasonable amount of leading
     zeroes.  */
  long leading_zeroes = 0;
  long zeroes, exp_adjust;
  char *exp_start = NULL;
  unsigned width_left = 0;
  char nancount = 0;
  char infcount = 0;
#ifdef hardway
  if (pdata->width == 0 || pdata->width > BUF - 1)
#else
  /* size_t is unsigned, hence this optimisation.  */
  if (pdata->width - 1 > BUF - 2)
#endif
    {
      width_left = pdata->width - (BUF - 1);
      pdata->width = BUF - 1;
    }
  pdata->flags |= SIGNOK | NDIGITS | DPTOK | EXPOK;
  zeroes = 0;
  exp_adjust = 0;
  for (p = pdata->buf; pdata->width; )
    {
      c = *fp->_p;
      /* This code mimicks the integer conversion code,
	 but is much simpler.  */
      switch (c)
	{
	case '0':
	  if (pdata->flags & NDIGITS)
	    {
	      pdata->flags &= ~SIGNOK;
	      zeroes++;
	      if (width_left)
		{
		  width_left--;
		  pdata->width++;
		}
	      goto fskip;
	    }
	/* Fall through.  */
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	  if (nancount + infcount == 0)
	    {
	      pdata->flags &= ~(SIGNOK | NDIGITS);
	      goto fok;
	    }
	  break;

	case '+':
	case '-':
	  if (pdata->flags & SIGNOK)
	    {
	      pdata->flags &= ~SIGNOK;
	      goto fok;
	    }
	  break;
	case 'n':
	case 'N':
	  if (nancount == 0 && zeroes == 0
	      && (pdata->flags & (NDIGITS | DPTOK | EXPOK)) ==
				  (NDIGITS | DPTOK | EXPOK))
	    {
	      pdata->flags &= ~(SIGNOK | DPTOK | EXPOK | NDIGITS);
	      nancount = 1;
	      goto fok;
	    }
	  if (nancount == 2)
	    {
	      nancount = 3;
	      goto fok;
	    }
	  if (infcount == 1 || infcount == 4)
	    {
	      infcount++;
	      goto fok;
	    }
	  break;
	case 'a':
	case 'A':
	  if (nancount == 1)
	    {
	      nancount = 2;
	      goto fok;
	    }
	  break;
	case 'i':
	case 'I':
	  if (infcount == 0 && zeroes == 0
	      && (pdata->flags & (NDIGITS | DPTOK | EXPOK)) ==
				  (NDIGITS | DPTOK | EXPOK))
	    {
	      pdata->flags &= ~(SIGNOK | DPTOK | EXPOK | NDIGITS);
	      infcount = 1;
	      goto fok;
	    }
	  if (infcount == 3 || infcount == 5)
	    {
	      infcount++;
	      goto fok;
	    }
	  break;
	case 'f':
	case 'F':
	  if (infcount == 2)
	    {
	      infcount = 3;
	      goto fok;
	    }
	  break;
	case 't':
	case 'T':
	  if (infcount == 6)
	    {
	      infcount = 7;
	      goto fok;
	    }
	  break;
	case 'y':
	case 'Y':
	  if (infcount == 7)
	    {
	      infcount = 8;
	      goto fok;
	    }
	  break;
	case '.':
	  if (pdata->flags & DPTOK)
	    {
	      pdata->flags &= ~(SIGNOK | DPTOK);
	      leading_zeroes = zeroes;
	      goto fok;
	    }
	  break;
	case 'e':
	case 'E':
	  /* No exponent without some digits.  */
	  if ((pdata->flags & (NDIGITS | EXPOK)) == EXPOK
	      || ((pdata->flags & EXPOK) && zeroes))
	    {
	      if (! (pdata->flags & DPTOK))
		{
		  exp_adjust = zeroes - leading_zeroes;
		  exp_start = p;
	        }
	      pdata->flags =
		(pdata->flags & ~(EXPOK | DPTOK)) | SIGNOK | NDIGITS;
	      zeroes = 0;
	      goto fok;
	    }
	  break;
	}
      break;
fok:
      *p++ = c;
fskip:
      pdata->width--;
      ++pdata->nread;
      if (--fp->_r > 0)
	fp->_p++;
      else if (pdata->pfn_refill (rptr, fp))
	/* "EOF".  */
	break;
    }
  if (zeroes)
    pdata->flags &= ~NDIGITS;
  /* We may have a 'N' or possibly even [sign] 'N' 'a' as the
     start of 'NaN', only to run out of chars before it was
     complete (or having encountered a non-matching char).  So
     check here if we have an outstanding nancount, and if so
     put back the chars we did swallow and treat as a failed
     match.

     FIXME - we still don't handle NAN([0xdigits]).  */
  if (nancount - 1U < 2U)
    {
      /* "nancount && nancount < 3".  */
      /* Newlib's ungetc works even if we called __srefill in
	 the middle of a partial parse, but POSIX does not
	 guarantee that in all implementations of ungetc.  */
      while (p > pdata->buf)
	{
	  pdata->pfn_ungetc (rptr, *--p, fp); /* "[-+nNaA]".  */
	  --pdata->nread;
	}
      return MATCH_FAILURE;
    }
  /* Likewise for 'inf' and 'infinity'.	 But be careful that
     'infinite' consumes only 3 characters, leaving the stream
     at the second 'i'.	 */
  if (infcount - 1U < 7U)
    {
      /* "infcount && infcount < 8".  */
      if (infcount >= 3) /* valid 'inf', but short of 'infinity'.  */
	while (infcount-- > 3)
	  {
	    pdata->pfn_ungetc (rptr, *--p, fp); /* "[iInNtT]".  */
	    --pdata->nread;
	  }
      else
        {
	  while (p > pdata->buf)
	    {
	      pdata->pfn_ungetc (rptr, *--p, fp); /* "[-+iInN]".  */
	      --pdata->nread;
	    }
	  return MATCH_FAILURE;
	}
    }
  /* If no digits, might be missing exponent digits
     (just give back the exponent) or might be missing
     regular digits, but had sign and/or decimal point.  */
  if (pdata->flags & NDIGITS)
    {
      if (pdata->flags & EXPOK)
	{
	  /* No digits at all.  */
	  while (p > pdata->buf)
	    {
	      pdata->pfn_ungetc (rptr, *--p, fp); /* "[-+.]".  */
	      --pdata->nread;
	    }
	  return MATCH_FAILURE;
	}
      /* Just a bad exponent (e and maybe sign).  */
      c = *--p;
      --pdata->nread;
      if (c != 'e' && c != 'E')
	{
	  pdata->pfn_ungetc (rptr, c, fp); /* "[-+]".  */
	  c = *--p;
	  --pdata->nread;
	}
      pdata->pfn_ungetc (rptr, c, fp); /* "[eE]".  */
    }
  if ((pdata->flags & SUPPRESS) == 0)
    {
      double fp;
      long new_exp = 0;

      *p = 0;
      if ((pdata->flags & (DPTOK | EXPOK)) == EXPOK)
	{
	  exp_adjust = zeroes - leading_zeroes;
	  new_exp = -exp_adjust;
	  exp_start = p;
	}
      else if (exp_adjust)
	new_exp = _strtol_r (rptr, (exp_start + 1), NULL, 10) - exp_adjust;

      if (exp_adjust)
	{
	  /* If there might not be enough space for the new exponent,
	     truncate some trailing digits to make room.  */
	  if (exp_start >= pdata->buf + BUF - MAX_LONG_LEN)
	    exp_start = pdata->buf + BUF - MAX_LONG_LEN - 1;
	  sprintf (exp_start, "e%ld", new_exp);
	}

      /* Current _strtold routine is markedly slower than
	 _strtod_r.  Only use it if we have a long double
	 result.  */
      fp = _strtod_r (rptr, pdata->buf, NULL);

      /* Do not support long double.  */
      if (pdata->flags & LONG)
	*GET_ARG (N, *ap, double *) = fp;
      else if (pdata->flags & LONGDBL)
	{
	  ldp = GET_ARG (N, *ap, _LONG_DOUBLE *);
	  *ldp = fp;
	}
      else
	{
	  flp = GET_ARG (N, *ap, float *);
	  if (isnan (fp))
	    *flp = nanf (NULL);
	  else
	    *flp = fp;
	}
      pdata->nassigned++;
    }
#endif /* SIO_FLOAT */
  return 0;
}

/* provide definition of _scanf_float to support users using -u _scanf_float
   to enable float support. */
int
_scanf_float (struct _reent *rptr,
	       struct _scan_data_t *pdata,
	       FILE *fp, va_list *ap) _ATTRIBUTE((__weak__,__alias__("__scanf_float")));

#if _SIO_c || _SIO_p || _SIO_s
static int
__scanf_chars (struct _reent *rptr,
	      struct _scan_data_t *pdata,
	      FILE *fp, va_list *ap);
#endif
#if _SIO_HEX || _SIO_DEC || _SIO_OCT || _SIO_p
static int
__scanf_i (struct _reent *rptr,
	  struct _scan_data_t *pdata,
	  FILE *fp, va_list *ap);
#endif

/* vfscanf.  */

int
__SVFSCANF_R(struct _reent *rptr, register FILE *fp, char const *fmt0, va_list ap);

#ifndef _REENT_ONLY

int
VFSCANF (register FILE *fp, const char *fmt, va_list ap)
{
  CHECK_INIT(_REENT, fp);
  return __SVFSCANF_R (_REENT, fp, fmt, ap);
}

#endif

int
_VFSCANF_R (struct _reent *data, register FILE *fp, const char *fmt, va_list ap)
{
  CHECK_INIT(data, fp);
  return __SVFSCANF_R (data, fp, fmt, ap);
}

int
__SVFSCANF_R (struct _reent *rptr, register FILE *fp, char const *fmt0, va_list ap)
{
  register u_char *fmt = (u_char *) fmt0;
  register int c;		/* Character from format, or conversion.  */
  register char *p;		/* Points into all kinds of strings.  */
  char ccltab[256];		/* Character class table for %[...].  */

  int ret;
  char *cp;

  struct _scan_data_t scan_data;
  int (*scan_func)(struct _reent*, struct _scan_data_t*, FILE *, va_list *);

  _newlib_flockfile_start (fp);

  scan_data.nassigned = 0;
  scan_data.nread = 0;
  scan_data.ccltab = ccltab;
  scan_data.pfn_ungetc = _ungetc_r;
  scan_data.pfn_refill = __srefill_r;

  for (;;)
    {
      if (*fmt == 0)
	goto all_done;

      if (isspace (*fmt))
	{
	  while ((fp->_r > 0 || !scan_data.pfn_refill(rptr, fp))
		 && isspace (*fp->_p))
	    {
	      scan_data.nread++;
	      fp->_r--;
	      fp->_p++;
	    }
	  fmt++;
	  continue;
	}
      if ((c = *fmt++) != '%')
	goto literal;

      scan_data.width = 0;
      scan_data.flags = 0;

      if (*fmt == '*')
	{
	  scan_data.flags |= SUPPRESS;
	  fmt++;
	}

      for (; is_digit (*fmt); fmt++)
	scan_data.width = 10 * scan_data.width + to_digit (*fmt);

      /* The length modifiers.  */
      p = "hlL";
      if ((cp = memchr (p, *fmt, 3)) != NULL) {
	scan_data.flags |= (SHORT << (cp - p));
	fmt++;
      }

      /* Switch on the format.  continue if done; break once format
	 type is derived.  */
      c = *fmt++;
      switch (c)
	{
	case '%':
	literal:
	  if ((fp->_r <= 0 && scan_data.pfn_refill(rptr, fp)))
	    goto input_failure;
	  if (*fp->_p != c)
	    goto match_failure;
	  fp->_r--, fp->_p++;
	  scan_data.nread++;
	  continue;
#if _SIO_p || _SIO_HEX
	case 'p':
	  scan_data.flags |= POINTER;
	_SIO_CASE('x','X'):
	  scan_data.flags |= PFXOK;
	  scan_data.base = 16;
	  goto number;
#endif
#if _SIO_OCT
	case 'o':
	  scan_data.base = 8;
	  goto number;
#endif
#if _SIO_DEC
	case 'd':
	case 'u':
	  scan_data.base = 10;
	  goto number;
	case 'i':
	  scan_data.base = 0;
	  goto number;
#endif
#if _SIO_p || _SIO_HEX || _SIO_OCT || _SIO_DEC
	number:
	  scan_data.code = (c < 'o') ? CT_INT : CT_UINT;
	  break;
#endif
	case '[':
	  fmt = (u_char *) __sccl (ccltab, (unsigned char *) fmt);
	  scan_data.flags |= NOSKIP;
	  scan_data.code = CT_CCL;
	  break;
#if _SIO_c
	case 'c':
	  scan_data.flags |= NOSKIP;
	  scan_data.code = CT_CHAR;
	  break;
#endif
#if _SIO_s
	case 's':
	  scan_data.code = CT_STRING;
	  break;
#endif
	case 'n':
	  if (scan_data.flags & SUPPRESS)	/* ???  */
	    continue;

	  if (scan_data.flags & SHORT)
	    *GET_ARG (N, ap, short *) = scan_data.nread;
	  else if (scan_data.flags & LONG)
	    *GET_ARG (N, ap, long *) = scan_data.nread;
	  else
	    *GET_ARG (N, ap, int *) = scan_data.nread;

	  continue;

	/* Disgusting backwards compatibility hacks.	XXX.  */
	case '\0':		/* compat.  */
	  _newlib_flockfile_exit (fp);
	  return EOF;

#ifdef FLOATING_POINT
	/* nb: 'F' is actually a C99 extension, which are supposed to be 
	   excluded from nano. but the case is in the vanilla nano-vfprintf, so
	   it's preserved here as well. */
#if _SIO_eE
        _SIO_CASE('e','E'):
#endif
#if _SIO_gG
        _SIO_CASE('g','G'):
#endif
#if _SIO_fF
	_SIO_CASE('f','F'):
#endif
	  scan_data.code = CT_FLOAT;
	  break;
#endif
	default:		/* compat.  */
	  scan_data.code = CT_INT;
	  scan_data.base = 10;
	  break;
	}

      /* We have a conversion that requires input.  */
      if ((fp->_r <= 0 && scan_data.pfn_refill (rptr, fp)))
	goto input_failure;

      /* Consume leading white space, except for formats that
	 suppress this.  */
      if ((scan_data.flags & NOSKIP) == 0)
	{
	  while (isspace (*fp->_p))
	    {
	      scan_data.nread++;
	      if (--fp->_r > 0)
		fp->_p++;
	      else if (scan_data.pfn_refill (rptr, fp))
		goto input_failure;
	    }
	  /* Note that there is at least one character in the
	     buffer, so conversions that do not set NOSKIP ca
	     no longer result in an input failure.  */
	}
      ret = 0;
      if (0) { /* just to help with the syntax below.. */ }
#if _SIO_c || _SIO_s
      else if (scan_data.code < CT_INT)
	ret = __scanf_chars (rptr, &scan_data, fp, &ap);
#endif
#if _SIO_DEC || _SIO_HEX || _SIO_OCT || _SIO_p
      else if (scan_data.code < CT_FLOAT)
	ret = __scanf_i (rptr, &scan_data, fp, &ap);
#endif
#if SIO_FLOAT
      else
	ret = _scanf_float (rptr, &scan_data, fp, &ap);
#endif

      if (ret == MATCH_FAILURE)
	goto match_failure;
      else if (ret == INPUT_FAILURE)
	goto input_failure;
    }
input_failure:
  /* On read failure, return EOF failure regardless of matches; errno
     should have been set prior to here.  On EOF failure (including
     invalid format string), return EOF if no matches yet, else number
     of matches made prior to failure.  */
  _newlib_flockfile_exit (fp);
  return scan_data.nassigned && !(fp->_flags & __SERR) ? scan_data.nassigned
						       : EOF;
match_failure:
all_done:
  /* Return number of matches, which can be 0 on match failure.  */
  _newlib_flockfile_end (fp);
  return scan_data.nassigned;
}

#if _SIO_c || _SIO_s
int
__scanf_chars (struct _reent *rptr,
	      struct _scan_data_t *pdata,
	      FILE *fp, va_list *ap)
{
  int n;
  char *p;

  if (pdata->width == 0)
    pdata->width = (pdata->code == CT_CHAR) ? 1 : (size_t)~0;

  n = 0;
  if ((pdata->flags & SUPPRESS) == 0)
    p = GET_ARG (N, *ap, char *);

  /* It's impossible to have EOF when we get here.  */
  while ((pdata->code == CT_CHAR)
	 || (pdata->code == CT_CCL && pdata->ccltab[*fp->_p])
	 || (pdata->code == CT_STRING && !isspace (*fp->_p)))
    {
      n++;
      if ((pdata->flags & SUPPRESS) == 0)
	*p++ = *fp->_p;
	
      fp->_r--, fp->_p++;
      if (--pdata->width == 0)
	break;

      if ((fp->_r <= 0 && pdata->pfn_refill (rptr, fp)))
	break;
    }
  /* For CT_CHAR, it is impossible to have input_failure(n == 0) here.
     For CT_CCL, it is impossible to have input_failure here.
     For CT_STRING, it is possible to have empty string.  */
  if (n == 0 && pdata->code == CT_CCL)
    return MATCH_FAILURE;

  if ((pdata->flags & SUPPRESS) == 0)
    {
      pdata->nassigned++;
      if (pdata->code != CT_CHAR)
	*p = 0;
    }
  pdata->nread += n;
  return 0;
}
#endif /* SIO_{c,s} */

#if _SIO_HEX || _SIO_DEC || _SIO_OCT || _SIO_p
int
__scanf_i (struct _reent *rptr,
	  struct _scan_data_t *pdata,
	  FILE *fp, va_list *ap)
{
#define CCFN_PARAMS (struct _reent *, const char *, char **, int)
  /* Conversion function (strtol/strtoul).  */
  u_long (*ccfn)CCFN_PARAMS=0;
  char *p;
  int n;
  char *xdigits = "A-Fa-f8901234567]";
  char *prefix_chars[3] = {"+-", "00", "xX"};

  /* Scan an integer as if by strtol/strtoul.  */
  unsigned width_left = 0;
  int skips = 0;

  ccfn = (pdata->code == CT_INT) ? (u_long (*)CCFN_PARAMS)_strtol_r : _strtoul_r;
#ifdef hardway
  if (pdata->width == 0 || pdata->width > BUF - 1)
#else
  /* size_t is unsigned, hence this optimisation.  */
  if (pdata->width - 1 > BUF - 2)
#endif
    {
      width_left = pdata->width - (BUF - 1);
      pdata->width = BUF - 1;
    }
  p = pdata->buf;
  pdata->flags |= NDIGITS | NZDIGITS | NNZDIGITS;

  /* Process [sign] [0] [xX] prefixes sequently.  */
  for (n = 0; n < 3; n++)
    {
      if (!memchr (prefix_chars[n], *fp->_p, 2))
	continue;

      if (n == 1)
	{
	  if (pdata->base == 0)
	    {
	      pdata->base = 8;
	      pdata->flags |= PFXOK;
	    }
	  pdata->flags &= ~(NZDIGITS | NDIGITS);
	}
      else if (n == 2)
	{
	  if ((pdata->flags & (PFXOK | NZDIGITS)) != PFXOK)
	    continue;
	  pdata->base = 16;

	  /* We must reset the NZDIGITS and NDIGITS
	     flags that would have been unset by seeing
	     the zero that preceded the X or x.

	     ??? It seems unnecessary to reset the NZDIGITS.  */
	  pdata->flags |= NDIGITS;
	}
      if (pdata->width-- > 0)
	{
	  *p++ = *fp->_p++;
	  fp->_r--;
	  if ((fp->_r <= 0 && pdata->pfn_refill (rptr, fp)))
	    goto match_end;
	}
    }

  if (pdata->base == 0)
    pdata->base = 10;

  /* The check is un-necessary if xdigits points to exactly the string:
     "A-Fa-f8901234567]".  The code is kept only for reading's sake.  */
#if 0
  if (pdata->base != 16)
#endif
  xdigits = xdigits + 16 - pdata->base;

  /* Initilize ccltab according to pdata->base.  */
  __sccl (pdata->ccltab, (unsigned char *) xdigits);
  for (; pdata->width; pdata->width--)
    {
      n = *fp->_p;
      if (pdata->ccltab[n] == 0)
	break;
      else if (n == '0' && (pdata->flags & NNZDIGITS))
	{
	  ++skips;
	  if (width_left)
	    {
	      width_left--;
	      pdata->width++;
	    }
	  goto skip;
	}
      pdata->flags &= ~(NDIGITS | NNZDIGITS);
      /* Char is legal: store it and look at the next.  */
      *p++ = *fp->_p;
skip:
      if (--fp->_r > 0)
	fp->_p++;
      else if (pdata->pfn_refill (rptr, fp))
	/* "EOF".  */
	break;
    }
  /* If we had only a sign, it is no good; push back the sign.
     If the number ends in `x', it was [sign] '0' 'x', so push back
     the x and treat it as [sign] '0'.
     Use of ungetc here and below assumes ASCII encoding; we are only
     pushing back 7-bit characters, so casting to unsigned char is
     not necessary.  */
match_end:
  if (pdata->flags & NDIGITS)
    {
      if (p > pdata->buf)
	pdata->pfn_ungetc (rptr, *--p, fp); /* "[-+xX]".  */

      if (p == pdata->buf)
	return MATCH_FAILURE;
    }
  if ((pdata->flags & SUPPRESS) == 0)
    {
      u_long ul;
      *p = 0;
      ul = (*ccfn) (rptr, pdata->buf, (char **) NULL, pdata->base);
      if (pdata->flags & POINTER)
	*GET_ARG (N, *ap, void **) = (void *) (uintptr_t) ul;
      else if (pdata->flags & SHORT)
	*GET_ARG (N, *ap, short *) = ul;
      else if (pdata->flags & LONG)
	*GET_ARG (N, *ap, long *) = ul;
      else
	*GET_ARG (N, *ap, int *) = ul;
      
      pdata->nassigned++;
    }
  pdata->nread += p - pdata->buf + skips;
  return 0;
}
#endif /* SIO_{HEX,OCT,DEC,_p} */

