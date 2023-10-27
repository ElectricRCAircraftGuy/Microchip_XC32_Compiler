# This shell script emits a C file. -*- C -*-
#   Copyright 2006, 2007, 2008, 2009 Free Software Foundation, Inc.
#
# This file is part of the GNU Binutils.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
# MA 02110-1301, USA.

fragment << EOF

#include "mchp/pic32m-emultempl.h"

struct pic32m_build_emulation_parameters EMULTEMPL = {
  "${EMULATION_NAME}",
  "${OUTPUT_FORMAT}"
};

static void
gld${EMULATION_NAME}_list_options (FILE *f)
{
  pic32m_list_options (f);
}

static int
gld${EMULATION_NAME}_parse_args (int argc, char **argv)
{
  return pic32m_parse_args (argc, argv);
}

static void
gld${EMULATION_NAME}_after_allocation (void)
{
  pic32m_after_allocation ();
}

static lang_output_section_statement_type *
gld${EMULATION_NAME}_place_orphan (lang_input_statement_type *file,
				   asection *sec, const char *secname,
				   int constraint)
{
  return pic32m_place_orphan (file, sec, secname, constraint);
}

void
emultempl_after_parse (void)
{
  /* Found in elf32.em */
  gld${EMULATION_NAME}_after_parse ();
}

void
emultempl_before_allocation (void)
{
  /* Found in elf32.em */
  gld${EMULATION_NAME}_before_allocation ();  
}

void
emultempl_after_open (void)
{
  /* Found in elf32.em */
  gld${EMULATION_NAME}_after_open ();
}

void
emultempl_map_segments (bfd_boolean need_layout)
{
  /* Found in elf-generic.em */
  gld${EMULATION_NAME}_map_segments (need_layout);
}

EOF


# Define some shell vars to insert bits of code into the standard elf
# parse_args and list_options functions.
#
PARSE_AND_LIST_PROLOGUE='
#define OPTION_INSN32			301
#define OPTION_NO_INSN32		(OPTION_INSN32 + 1)
#define OPTION_PCREL_EH_RELOC		303
'

PARSE_AND_LIST_LONGOPTS='
  { "insn32", no_argument, NULL, OPTION_INSN32 },
  { "no-insn32", no_argument, NULL, OPTION_NO_INSN32 },
  { "pcrel-eh-reloc", no_argument, NULL, OPTION_PCREL_EH_RELOC },
'

PARSE_AND_LIST_OPTIONS='
  fprintf (file, _("\
  --insn32                    Only generate 32-bit microMIPS instructions\n"
		   ));
  fprintf (file, _("\
  --no-insn32                 Generate all microMIPS instructions\n"
		   ));
'

PARSE_AND_LIST_ARGS_CASES='
    case OPTION_INSN32:
      insn32 = TRUE;
      break;

    case OPTION_NO_INSN32:
      insn32 = FALSE;
      break;

    case OPTION_PCREL_EH_RELOC:
      eh_reloc_type = R_MIPS_PC32;
      break;
'

LDEMUL_AFTER_OPEN=pic32_after_open
LDEMUL_FINISH=pic32_finish
LDEMUL_PARSE_ARGS=gldelf32pic32mx_parse_args
LDEMUL_LIST_OPTIONS=gldelf32pic32mx_list_options
LDEMUL_AFTER_PARSE=mips_after_parse
LDEMUL_BEFORE_ALLOCATION=mips_before_allocation
LDEMUL_PLACE_ORPHAN=gldelf32pic32mx_place_orphan
LDEMUL_CREATE_OUTPUT_SECTION_STATEMENTS=mips_create_output_section_statements
LDEMUL_AFTER_ALLOCATION=gldelf32pic32mx_after_allocation
