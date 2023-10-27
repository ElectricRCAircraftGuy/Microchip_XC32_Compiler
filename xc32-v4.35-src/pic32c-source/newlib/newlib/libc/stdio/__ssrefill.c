/* PIC32C: moved from vfscanf.c */
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

/* String only version of __srefill_r for sscanf family.  */
int
__ssrefill_r (struct _reent * ptr, register FILE * fp)
{
  /*
   * Our only hope of further input is the ungetc buffer.
   * If there is anything in that buffer to read, return.
   */
  if (HASUB (fp))
    {
      FREEUB (ptr, fp);
      if ((fp->_r = fp->_ur) != 0)
        {
          fp->_p = fp->_up;
	  return 0;
        }
    }

  /* Otherwise we are out of character input.  */
  fp->_p = fp->_bf._base;
  fp->_r = 0;
  fp->_flags |= __SEOF;
  return EOF;
}

