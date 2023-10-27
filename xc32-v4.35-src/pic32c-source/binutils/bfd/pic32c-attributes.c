/*
** pic32c-attributes.c
**
** Copyright (c) 2016 Microchip Technology, Inc.
**
** This file is part of BFD, the Binary File Descriptor library.
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
** MA 02110-1301, USA.
**
** This file contains utilities for processing
** section attributes. It is included by the
** following omf-specific bfd utility files:
**
**   bfd/elfxx-arm.c
**
** A related chunk of code may be found
** in gas/config/tc-arm.c, in function
** pic32_attribute().
*/

#include "pic32c-utils.h"

#undef ATTR
#undef ATTR_IS
#undef MASK1
#undef MASK2
#undef MASK3
#undef MASK4
#define ATTR(a,b,c)  a,

  /* Create an id for each attribute */
 enum {
#include "pic32c-attributes.h"
 } ;

#define TYPE_ATTR_MASK ( 1<<code     \
                       | 1<<data     \
                       | 1<<bss      \
                       | 1<<persist  \
                       | 1<<memory   \
                       | 1<<heap     \
                       | 1<<stack    \
                       | 1<<ramfunc  \
                       | 1<<serial_mem)

#define INFO_ATTR_MASK ( 1<<info )

#define SECTION(s) \
  ((strlen(sec->name) == strlen(#s)) && \
           strcmp(sec->name, (#s)) == 0)

#define FIRST_EXT_ATTRIBUTE persist

/*
 * This function builds a bit map that represents all
 * standard section attributes as well as pic32-specific
 * attributes. The bit map is derived from a bfd section,
 * which is the cannonical representation.
 *
 */
unsigned int pic32_attribute_map(asection *sec)
{
  unsigned long result = 0;

#undef ATTR
#undef ATTR_IS
#undef MASK1
#undef MASK2
#undef MASK3
#undef MASK4
#define ATTR_IS(_id, _test_it)     \
  if (_test_it)                    \
    result |= (1 << _id);

   /* create a bit map */
#include "pic32c-attributes.h"

  return result;

} /* pic32_attribute_map() */

/*****************************************************************************/

/*
 * This function creates a bit map that represents
 * only the extended attributes. The bit map is derived
 * from a bfd section, which is the cannoical representation.
 *
 */
unsigned int pic32_extended_attribute_map(asection *sec)
{
  return (pic32_attribute_map(sec) >> FIRST_EXT_ATTRIBUTE);
}

/*****************************************************************************/

/*
 * This function sets attributes in a bfd section,
 * according to a bit mask. It does not provide
 * a way to set the arguments to attributes such
 * as align(), reverse(), and merge().
 *
 */
void
pic32_set_attributes(asection *sec, unsigned int mask, unsigned char flag_debug)
{
  unsigned int bit;

  if (flag_debug && pic32_debug)
    printf ("--> pic32_set_attributes::begin\n");

#undef ATTR
#undef ATTR_IS
#undef MASK1
#undef MASK2
#undef MASK3
#undef MASK4
#define ATTR(id, has_arg, set_it)                                \
  bit = (1<<id);                                                 \
  if ((mask & bit) == bit)   {                                   \
    if (flag_debug && pic32_debug)                               \
      printf("    pic32_set_attributes::setting bit %x\n", id);  \
    set_it; }

#define NO_ARGS 1
#include "pic32c-attributes.h"

  if (flag_debug && pic32_debug)
    printf ("<-- pic32_set_attributes::end\n");
}

/*****************************************************************************/

/*
 * This function sets the extended attributes
 * in a bfd section. Extended attributes are
 * derived from a bit mask that is encoded
 * as a symbol in the object file.
 *
 */
void
pic32_set_extended_attributes(asection *sec,
                              unsigned int mask,
                              unsigned char flag_debug)
{
  if (flag_debug && pic32_debug)
    printf ("--> pic32_set_extended_attributes::begin\n");

  pic32_set_attributes(sec, mask << FIRST_EXT_ATTRIBUTE, flag_debug);

  if (flag_debug && pic32_debug)
    printf ("<-- pic32_set_extended_attributes::end\n");
}

/*****************************************************************************/

/* Helper for pic32_set_implied attributes. returns true if the given
   section's name matches a reserved section name as defined by MASK4
   in pic32c-attributes.h.

   allow_prefix is set to true by the caller when the reserved name should 
   match as a prefix of the section name, e.g. a section .text.func will match 
   the reserved name .text. The reserved sections for which this is permitted 
   are defined in pic32c-attributes.h.
 */
static int 
section_matches_p (const asection *sec, const char *name, int allow_prefix)
{
  int len = strlen (name);

  if (allow_prefix) 
    {
      return len <= strlen (sec->name) && (strncmp (sec->name, name, len) == 0);
    }
  return (strcmp (sec->name, name) == 0);
}

/*
 *  This functions sets the implied attributes
 *  for a bfd section. If the section has a
 *  reserved name, some implied attributes
 *  may be required.
 *
 *  Implied attributes for .text, .data, .bss
 *  are set quietly. A non-reserved section
 *  with no attributes defaults to data, quietly.
 *
 *  Return codes:
 *    0 = no implied attribute(s) required
 *        (or they have been quietly set)
 *    1 = implied attribute(s) set, no conflicts
 *   -1 = implied attribute(s) conflict
 */

int
pic32_set_implied_attributes(asection *sec, unsigned char flag_debug)
{
  int result = 0;  /* default = quiet, no conflicts */
  unsigned int mask;
  long map = pic32_attribute_map(sec);

  if (flag_debug && pic32_debug)
    printf ("--> pic32_set_implied_attributes::begin\n");

  if (flag_debug && pic32_debug)
    printf ("    pic32_set_implied_attributes::map = %lx\n", map);

#undef ATTR
#undef ATTR_IS
#undef MASK1
#undef MASK2
#undef MASK3
#undef MASK4
#define MASK4(id, quiet, c, d, p)                                              \
  }                                                                            \
  else if (section_matches_p (sec, #id, p))                                    \
  {                                                                            \
    mask = (1 << c); /* set type */                                            \
    if (d)                                                                     \
      mask |= (1 << d); /* and modifier (if any) */                            \
    if (flag_debug && pic32_debug)                                             \
      {                                                                        \
	printf ("    pic32_set_implied_attributes::section = %s\n", #id);      \
	printf ("    pic32_set_implied_attributes::mask = %x\n", mask);        \
      }                                                                        \
    if ((map & mask) == mask)                                                  \
      {                                                                        \
      } /* do nothing */                                                       \
    else if (pic32_is_valid_attributes ((map | mask), flag_debug))             \
      { /* set the implied attributes */                                       \
	pic32_set_attributes (sec, mask, flag_debug);                          \
	result = !(quiet);                                                     \
      }                                                                        \
    else                                                                       \
      result = -1; /* report the conflict */

  if (0)
    {
#include "pic32c-attributes.h"
 } else                           /* a section by any other name... */
   if ((map &                     /* if no type attribute is set    */
        (TYPE_ATTR_MASK | INFO_ATTR_MASK)) == 0)
       PIC32_SET_DATA_ATTR(sec);  /* set the default, quietly       */

  if (flag_debug && pic32_debug)
    printf ("<-- pic32_set_implied_attributes::exit(%d)\n", result);

  return result;

} /* pic32_set_implied_attributes() */


/*****************************************************************************/

/*
 * This function validates a bit mask that represents
 * the attributes specified in a .section directive.
 *
 * The bit mask is derived from source code by the
 * assembler. This function makes heavy use of
 * pic32c-attributes.h, where all of the attribute
 * compatibilty information is encoded.
 *
 * The encoding of the bit mask is performed
 * by pic32_attribute() in gas/config/tc-mips.c,
 * which also uses pic32c-attributes.h.
 *
 *  Return codes:
 *
 *    1 = attribute mask is valid
 *    0 = attribute mask is not valid
 */
int
pic32_is_valid_attributes (unsigned int mask, unsigned char flag_debug)
{
  int valid_type = 0;
  int valid_modifiers = 0;
  int invalid_combo = 0;
  unsigned int idx,num,type,key;
  unsigned int type_mask,attr_mask;
  
  if (flag_debug && pic32_debug) {
    printf ("--> pic32_is_valid_attributes::begin\n");
    printf ("    pic32_is_valid_attributes::mask = %x\n",mask);
  }

  /* At most one attribute type should be set */
#undef ATTR
#undef ATTR_IS
#undef MASK1
#undef MASK2
#undef MASK3
#undef MASK4
#define MASK1(a,b,c,d,e,f,g,h)                                  \
   type_mask = (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<e)|(1<<f)        \
               |(1<<g) | (1<<h);
    
#define MAX_TYPES 32
#include "pic32c-attributes.h"

   type = mask & type_mask;

   if (flag_debug && pic32_debug)
     printf ("    pic32_is_valid_attributes::type = %x\n", type);
   for (num=0,idx=0; idx<MAX_TYPES; idx++) {
     if ((type) & (1<<idx)) num++;
   }
    
  /* XC32-1615: invalid attribute combination when using ramfunc
   * This was only reproducible on mips because it was "patched"
   * here to accept more than one section type for ramfunc...
   * which is not correct anyway. We removed the code type
   * for ramfunc sections.
   */
  if (num < 2)
    valid_type |= 1;

   /* if no type specified, the default is data */
   if (num == 0) {

     type = (1<<data);
     mask |= type;
     if (flag_debug && pic32_debug)
       printf ("    pic32_is_valid_attributes::no type specified, default = data\n");

   }

   if (flag_debug && pic32_debug)
     printf ("    pic32_is_valid_attributes::valid_type = %s\n",
             valid_type ? "true" : "false");

   /* Verify that modifiers are compatible with type */
#undef ATTR
#undef ATTR_IS
#undef MASK1
#undef MASK2
#undef MASK3
#undef MASK4
    /* lghica co-resident MASK2 -> m,n  MASK3 ->l,m*/
    
#define MASK2(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)                           \
   if (type & (1<<a)) {                                               \
     attr_mask = (1<<b)|(1<<c)|(1<<d)|(1<<e)|(1<<f)                    \
                 |(1<<g)|(1<<h)|(1<<i)|(1<<j)|(1<<k)|(1<<l)            \
                 |(1<<m)|(1<<n)|(1<<o);                                \
     if (flag_debug && pic32_debug)                                    \
       printf ("    pic32_is_valid_attributes::modifier_mask = %x\n",  \
               attr_mask);                                             \
     if ((mask & ~ (type_mask | attr_mask)) == 0)                      \
       valid_modifiers |= 1;                                           \
   }

#include "pic32c-attributes.h"
   if (flag_debug && pic32_debug)
     printf ("    pic32_is_valid_attributes::valid_modifiers = %s\n",
             valid_modifiers ? "true" : "false" );

   /* Verify that modifiers are compatible with each other */
#undef ATTR
#undef ATTR_IS
#undef MASK1
#undef MASK2
#undef MASK3
#undef MASK4
#define MASK3(a,b,c,d,e,f,g,h,i,j,k,l,m)                              \
   key = (1<<a);                                                  \
   attr_mask = (1<<b)|(1<<c)|(1<<d)|(1<<e)|(1<<f)                 \
               |(1<<g)|(1<<h)|(1<<i)|(1<<j)|(1<<k)                \
               |(1<<l)|(1<<m);                                    \
   if ((key & mask) &&                                            \
       ((mask & ~ (key | type_mask | attr_mask)) != 0))           \
     invalid_combo |= 1;;

#include "pic32c-attributes.h"
 if (flag_debug && pic32_debug)
   printf ("    pic32_is_valid_attributes::valid_combination = %s\n",
           invalid_combo ? "false" : "true" );

  if (flag_debug && pic32_debug)
    printf ("<-- pic32_is_valid_attributes::exit\n");

 return (valid_type &&
         valid_modifiers &&
         !invalid_combo);
} /* pic32_is_valid_attributes */


/*****************************************************************************/

/*
 * This function returns a string that
 * describes a section's attributes.
 */

#undef ATTR
#undef ATTR_IS
#undef MASK1
#undef MASK2
#undef MASK3
#undef MASK4
#define ATTR(_id, _has_arg, _set_it)  #_id ,

const char * names[] = {
#include "pic32c-attributes.h"
};

char * pic32_section_attr_string (asection *sec)
{
#undef MAX_LEN
#define MAX_LEN 120
#define A1 "attributes = "

  int i,b;
  unsigned int map = pic32_attribute_map(sec);
  char *result = (char *) bfd_malloc (MAX_LEN);

  if (result == (char *) NULL)
    return result;

  result[0] = 0; /* start with a null terminator */
  result = strcat( result, A1 );

  for (i = 0; i < 31; i++) {
    b = map & 1;
    if (b) {
      result = strncat( result, names[i], MAX_LEN - strlen(result) -2);
      result = strcat( result, " " );
    }
    map >>= 1;
  }

  return result;

}


/*****************************************************************************/

/*
 * This function returns a string that describes
 * a section's size, in proper units.
 */
char * pic32_section_size_string (asection *sec)
{
#undef MAX_LEN
#define MAX_LEN 80
#define S1 "size = "
#define S2 " bytes"
#define S3 " PC units"

  char *units;
  char *result = (char *) bfd_malloc (MAX_LEN);

  if (result == (char *) NULL)
    return result;

    units = S2;

  if (sec->rawsize != 0)
    snprintf(result, MAX_LEN, "%s%ld%s", S1, sec->rawsize, units);
  else
    snprintf(result, MAX_LEN, "%s%ld%s", S1, sec->size, units);
    
  return result;
}

/*****************************************************************************/
