/* The call stack portion of the stack usage feature.

  This file is part of the GNU Binutils.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
  MA 02110-1301, USA. */

#include "sysdep.h"
#include "bfd.h"
#include "libiberty.h"
#include "libbfd.h"

#include <stdint.h>

#include "pic32-stack-usage.h"
#include "pic32-su-callstack.h"

extern bfd_boolean pic32_debug;

extern struct su_section *su_sections;


#define INIT_CALL_STACK	2
#ifndef NEXTPOW2
#define NEXTPOW2(X) ({ \
  uint32_t x = (X); x ? 1U << (32 - __builtin_clz (x)) : 1U; })
#endif


/* initialize stack */
su_callstack *
su_cstack_new (void)
{
  su_callstack *stack_ptr = (su_callstack *) xcalloc (1, sizeof (su_callstack));

  stack_ptr->max_size = INIT_CALL_STACK;
  stack_ptr->top = -1;
  stack_ptr->calls =
    (struct su_section **) xcalloc (stack_ptr->max_size,
                                    sizeof (struct su_section *));

  return stack_ptr;
}

/* get stack size */
int
su_cstack_get_size (su_callstack * stack_ptr)
{
  return stack_ptr->top + 1;
}

/* check if stack is empty */
int
su_cstack_is_empty (su_callstack * stack_ptr)
{
  return su_cstack_get_size (stack_ptr) == 0;
}

/* check if stack is full */
int
su_cstack_is_full (su_callstack * stack_ptr)
{
  return su_cstack_get_size (stack_ptr) == stack_ptr->max_size;
}

void
mark_as_recursive (su_callstack * stack_ptr, struct su_section *func)
{
  int i, pos = su_cstack_is_on_stack (stack_ptr, func);

  BFD_ASSERT ((pos != -1) && (pos <= stack_ptr->top));

  PIC32_DBG_PRINT ("Recursivity detected; functions involved:\n");

  for (i = pos; i <= stack_ptr->top; i++)
    {
      PIC32_DBG_PRINT ("\t%s\n", stack_ptr->calls[i]->fname);
      stack_ptr->calls[i]->flags |= SU_RECURSIVE;
    }
}

/* add an element on stack */
void
su_cstack_push (su_callstack * stack_ptr, struct su_section *call)
{
  /* check stack overflow */
  if (su_cstack_is_full (stack_ptr))
    {
      /* resize the stack */
      stack_ptr->max_size = NEXTPOW2 (stack_ptr->max_size);
      stack_ptr->calls =
        xrealloc (stack_ptr->calls,
                  stack_ptr->max_size * sizeof (struct su_section *));
    }

  stack_ptr->top++;
  stack_ptr->calls[stack_ptr->top] = call;
}

/* check if an element is already on stack
* return element position or -1
*/
int
su_cstack_is_on_stack (su_callstack * stack_ptr, struct su_section *const call)
{
  int i;

  for (i = 0; i <= stack_ptr->top; i++)
    if (stack_ptr->calls[i] == call)
      return i;
  return -1;
}

/* 
* get first stack element (without removing it from stack)
*/
struct su_section *
su_cstack_check_top (su_callstack * stack_ptr)
{
  if (su_cstack_is_empty (stack_ptr))
    return NULL;
  else
    return stack_ptr->calls[stack_ptr->top];
}

/*  
* pop top element from the stack
*/
struct su_section *
su_cstack_pop (su_callstack * stack_ptr)
{
  /* check for stack underflow */
  if (su_cstack_is_empty (stack_ptr))
    {
      return NULL;
    }

  stack_ptr->top--;
  return stack_ptr->calls[stack_ptr->top + 1];
}

void
print_callstack_entry (su_callstack * stack_ptr, FILE * f, int pos)
{
  if ((pos < 0) || (pos > stack_ptr->top))
    {
      if (pic32_debug)
        fprintf (stderr, "SU: Wrong callstack position %d\n", pos);
      return;
    }

  fprintf (f, "SU: <%s> <%d>\n", stack_ptr->calls[pos]->fname,
           stack_ptr->calls[pos]->used_stack);
}

void
su_cstack_free (su_callstack * stack_ptr)
{
  free (stack_ptr->calls);
  free (stack_ptr);
}
