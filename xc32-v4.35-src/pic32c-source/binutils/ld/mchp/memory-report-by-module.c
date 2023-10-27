/* Report for memory used per module.

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
#include "bfdlink.h"

#include "ld.h"
#include "ldmain.h"
#include "ldmisc.h"

#include "ldexp.h"
#include "ldlang.h"

#include "elf-bfd.h"

#include "libiberty.h"

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "pic32-utils.h"

extern bfd_boolean pic32_debug;

#define MISC_ENTRY  0

#define PIC32_IS_ALLOCATED_BUT_MISC(sec) \
  (((sec)->flags & (SEC_ALLOC | SEC_HAS_CONTENTS | SEC_KEEP)) \
      == (SEC_ALLOC | SEC_HAS_CONTENTS | SEC_KEEP))

typedef struct memory_entry {
  char *filename; /* the whole filename that keeps the path or lib name */
  char *basename; /* the object name */
  int text;       /* size of text sections */
  int data;       /* size of data sections */
  int bss;        /* size of bss sections */
  int total;      /* size of text + data + bss used by qsort */
} memory_entry_t;

/*
 * Utility routine: memory_entry_compare
 *
 * Called by: qsort
 *
 * - returns the total_mem compare result between two memory_entries
 */
static int memory_entry_compare(const void *p, const void *q)
{
  int l = ((memory_entry_t *)p)->total;
  int r = ((memory_entry_t *)q)->total;

  return (l - r);
}

/*
 * Utility routine: pic32_basename
 *
 * Called by: bfd_pic32_report_memory_usage_by_module
 *
 * - returns the basename of a filepath using both slash and
 * backslash separators
 */
static char *pic32_basename(char const *path)
{
    char *s1 = strrchr(path, '/');
    char *s2 = strrchr(path, '\\');
    char *s = s1 > s2 ? s1 : s2;
    if (!s)
        return strdup(path);
    else
        return strdup(s + 1);
}

/*
 * Utility routine: bfd_pic32_report_memory_usage_by_module
 *
 * - print the used memory by input object
 */
void bfd_pic32_report_memory_usage_by_module (FILE *fp)
{
  bfd *input_bfd;
  memory_entry_t *report;
  int i, j, num_input_bfds = 1;
  int total_text = 0;
  int total_data = 0;
  int total_bss = 0;
  int total_memory;
  size_t max_length = 0;
  asection **visited_sections;
  int count_visited = 0;
  int total_visited;
  int total_out_size = 0;
  int padding;

  /* Count how many input bfds we have so we can allocate memory
   * to store the report entries. Since it is a linked list, we
   * have to itterate through them.
   */
  for (input_bfd = link_info.input_bfds; input_bfd != NULL;
       input_bfd = input_bfd->link.next)
    num_input_bfds++;

  total_visited = num_input_bfds;

  /* Allocate the vector for report entries including misc*/
  report = xmalloc(num_input_bfds * sizeof(report[0]));

  /* Allocate a buffer for visited sections */
  visited_sections = xmalloc(num_input_bfds * sizeof(asection *));

  /* add first entry for misc */
  report[MISC_ENTRY].basename = strdup("misc");
  report[MISC_ENTRY].filename = strdup("misc");
  report[MISC_ENTRY].text = 0;
  report[MISC_ENTRY].data = 0;
  report[MISC_ENTRY].bss = 0;
  report[MISC_ENTRY].total = 0;

  /* We start from index 1 since report[0] is the "misc" entry */
  for (i = 1, input_bfd = link_info.input_bfds; input_bfd != NULL;
       input_bfd = input_bfd->link.next, i++)
    {
      asection *section;
      size_t filename_length = strlen(input_bfd->filename);

      report[i].basename = pic32_basename(input_bfd->filename);
      report[i].text = 0;
      report[i].data = 0;
      report[i].bss = 0;
      report[i].total = 0;

      /* If the input object comes from a lib, we will store the lib name
       * instead of object relative path in filename.
       */
      if (input_bfd->my_archive)
        {
          report[i].filename = pic32_basename(input_bfd->my_archive->filename);
        } else {
          report[i].filename = xmalloc((filename_length + 1) * sizeof(char));
          sprintf(report[i].filename, "%s", input_bfd->filename);
        }

      /* We track the maximum object basename so we can pretty-print the report */
      if (strlen(report[i].basename) > max_length)
          max_length = strlen(report[i].basename);

      for (section = input_bfd->sections; section != NULL; section = section->next)
        {
          /* skip input sections that are not linked to an output section */
          if (section->output_section == NULL)
              continue;

          /* skip input section if the owner of the output section is not the
           * output bfd
           */
          if (section->output_section->owner != link_info.output_bfd)
              continue;

          /* We are attempting to save the output sections that we've visited.
           * Before printing the report, we will walk through output bfd sections
           * and see if we've missed any.
           */
          if (count_visited == (total_visited - 1))
            {
              total_visited *= 2;
              visited_sections = xrealloc(visited_sections, total_visited * sizeof(asection *));
            }

          /* Multiple input sections will be mapped to one output section.
           * We will iterate through visited sections before deciding to add a new
           * entry in the array. This will save some memory and time by not having
           * to reallocate because of the duplicates.
           */
          for (j = 0; j < count_visited; j++)
            if (visited_sections[j] == section->output_section)
              break;

          if (j == count_visited)
            {
              visited_sections[count_visited] = section->output_section;
              count_visited ++;
            }

          /* this is a .text section */
          if (PIC32_IS_CODE_ATTR(section))
            {
              report[i].text += section->size;
              continue;
            }

          /* this is a .data section */
          if (PIC32_IS_DATA_ATTR(section))
            {
              report[i].data += section->size;
              continue;
            }

          /* this is a .bss section if it only has SEC_ALLOC */
          if (PIC32_IS_BSS_ATTR(section))
            {
              report[i].bss += section->size;
              continue;
            }

          /* XC32-2397: this is a ramfunc section */
          if (PIC32_IS_RAMFUNC_ATTR(section))
            {
              report[i].text += section->size;
              continue;
            }

          if (pic32_debug)
            {
              fprintf(stderr,"ignoring input section %s of size %d with flags %x\n", section->name, section->size, section->flags);
            }
        }
    }

    /* XC32-2382: calculate the final elf size by adding the output sections sizes
     * total_out_size will also include the padding since sections are alligned at this point.
     */
    asection *section;
    for (section = link_info.output_bfd->sections; section != NULL; section = section->next)
      {
         if (PIC32_IS_CODE_ATTR(section)
              || PIC32_IS_DATA_ATTR(section)
              || PIC32_IS_BSS_ATTR(section)
              || PIC32_IS_ALLOCATED_BUT_MISC(section))
              total_out_size += section->size;
      }

    /* Now check for sections that are only present in output_bfd and not referenced from any input_bfd.
     * If so, we are adding the section size to "misc" entry.
     */
    for (section = link_info.output_bfd->sections; section != NULL; section = section->next)
      {
        for (i = 0; i < count_visited; i++)
          if (visited_sections[i] == section)
            break;

        /* skip sections that were already visited */
        if (i != count_visited)
          continue;

        /* skip empty sections */
        if (section->size == 0)
          continue;

        /* this is a .text section */
        if (PIC32_IS_CODE_ATTR(section))
          {
            report[MISC_ENTRY].text += section->size;
            continue;
          }

        /* this is a .data section */
        if (PIC32_IS_DATA_ATTR(section))
          {
            report[MISC_ENTRY].data += section->size;
            continue;
          }

        /* this is a .bss section if it only has SEC_ALLOC */
        if (PIC32_IS_BSS_ATTR(section))
          {
            report[MISC_ENTRY].bss += section->size;
            continue;
          }

        /* this is a section with ALLOC & KEEP placed directly in output bfd
         * However, we do not know the type and we default to code.
         */
        if (PIC32_IS_ALLOCATED_BUT_MISC(section))
          {
            report[MISC_ENTRY].text += section->size;
            continue;
          }

        if (pic32_debug)
          fprintf(stderr, "ignoring output section %s of size %d with flags %x\n", section->name, section->size, section->flags);
      }

  /* sum total memory for report entries before sorting */
  for (i = 0; i < num_input_bfds; i++)
    {
      report[i].total = report[i].text + report[i].data + report[i].bss;
      total_text += report[i].text;
      total_bss += report[i].bss;
      total_data += report[i].data;
    }

  /* keeping track of total text, data and bss so we can print the elf
   * summary at the end of the report
   */
  total_memory = total_text + total_data + total_bss;

  /* sort the bfds by total used memory so we can print the
   * report in descending order. Leave misc entry at the end of the report.
   */
  qsort(report + 1, num_input_bfds - 1, sizeof(report[0]), memory_entry_compare);

  /* print the report and free all the mem used for reports */
  fflush (fp);

  /* Emit a note when LTO is enabled */
  if (link_info.lto_plugin_active)
    fprintf(fp, "\nNote: Microchip PIC32 Memory-Usage Report By Module might not be accurate when used in conjunction with LTO!");

  fprintf(fp, "\nMicrochip PIC32 Memory-Usage Report By Module\n\n");
  fprintf(fp, "%12s%12s%12s%12s%12s    %-*s%12s\n", "text", "data", "bss", "dec", "hex", (int)max_length, "basename", "filename");
  fprintf(fp,"--------------------------------------------------------------------------------\n");

  for (i = num_input_bfds - 1; i >= 0; i--)
    {
      /* stop printing when total reported memory is 0
       * but keep iterating to free the memory
       */
      if (report[i].total)
        fprintf(fp, "%12d%12d%12d%12d%12x    %-*s%s\n", report[i].text, report[i].data, report[i].bss,
                                               report[i].total, report[i].total, (int)max_length, report[i].basename, report[i].filename);

      free (report[i].filename);
      free (report[i].basename);
      report[i].filename = NULL;
      report[i].basename = NULL;
    }

  /* XC32-2382: Report the total memory as input-sections size + required padding.
   * If the padding is < 0, something fishy happened and we do not report it.
   */
  padding = total_out_size - total_memory;
  if (padding > 0)
    {
      fprintf(fp, "%12d%12d%12d%12d%12x    %-*s%s\n", 0, 0, 0, padding, padding, (int)max_length, "padding", "padding");
      total_memory = total_out_size;
    }
  else if (pic32_debug)
    {
      fprintf(stderr, "Warning: calculated padding is negative!\n");
    }

  fprintf(fp,"--------------------------------------------------------------------------------\n");
  fprintf(fp, "%12d%12d%12d%12d%12x    %s\n\n", total_text, total_data, total_bss,
                                         total_memory, total_memory, link_info.output_bfd->filename);
  fflush (fp);

  free (visited_sections);
  free (report);
}
