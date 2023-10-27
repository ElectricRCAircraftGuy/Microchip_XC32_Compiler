# This shell script emits a C file. -*- C -*-
#   Copyright (C) 1991-2016 Free Software Foundation, Inc.
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
#

# This file is sourced from armelf.em, which is itself sourced from elf32.em, 
# and defines extra pic32c elf specific routines.
#
test -z "$TARGET2_TYPE" && TARGET2_TYPE="rel"
fragment <<EOF

#include "mchp/pic32c-emultempl.h"

/* Capture the values that come from the shell substitution/evaluation
   that are used in our emulation file. */
struct pic32c_build_emulation_parameters EMULTEMPL = {
  "${EMULATION_NAME}",
  0${TARGET1_IS_REL},
  "${TARGET2_TYPE}",
  "${ARCH}",
  ${DYNAMIC_LINK-TRUE},
  `if test -n "$GENERATE_SHLIB_SCRIPT" ; then echo TRUE ; else echo FALSE ; fi`,
  `if test "x${SEPARATE_CODE}" = xyes ; then echo TRUE ; else echo FALSE ; fi`,
  "${OUTPUT_FORMAT}"
};

static void
gld${EMULATION_NAME}_before_parse (void)
{
  pic32c_before_parse ();
}

static void
gld${EMULATION_NAME}_list_options (FILE *f)
{
  pic32c_list_options (f);
}

static int
gld${EMULATION_NAME}_parse_args (int argc, char **argv)
{
  return pic32c_parse_args (argc, argv);
}

static void
gld${EMULATION_NAME}_after_allocation (void)
{
  pic32c_after_allocation ();
}

static void
gld${EMULATION_NAME}_set_symbols (void)
{
  pic32c_set_symbols ();
}

static void
gld${EMULATION_NAME}_finish (void)
{
  pic32c_finish ();
}

void
emultempl_before_allocation (void)
{
  /* Found in elf32.em */
  gld${EMULATION_NAME}_before_allocation ();
}

void
emultempl_map_segments (bfd_boolean need_layout)
{
  /* Found in elf-generic.em */
  gld${EMULATION_NAME}_map_segments (need_layout);
}

void
emultempl_after_open (void)
{
  /* Found in elf32.em */
  gld${EMULATION_NAME}_after_open ();
}

lang_output_section_statement_type *
emultempl_place_orphan (asection *s, const char *secname,
			int constraint)
{
  /* Found in elf32.em */
  return gld${EMULATION_NAME}_place_orphan (s, secname, constraint);
}

EOF

# Define some shell vars to insert bits of code into the standard elf
# parse_args and list_options functions.
#
PARSE_AND_LIST_PROLOGUE='
#define OPTION_THUMB_ENTRY		301
#define OPTION_BE8			302
#define OPTION_TARGET1_REL		303
#define OPTION_TARGET1_ABS		304
#define OPTION_TARGET2			305
#define OPTION_FIX_V4BX			306
#define OPTION_USE_BLX			307
#define OPTION_VFP11_DENORM_FIX		308
#define OPTION_NO_ENUM_SIZE_WARNING	309
#define OPTION_PIC_VENEER		310
#define OPTION_FIX_V4BX_INTERWORKING	311
#define OPTION_STUBGROUP_SIZE		312
#define OPTION_NO_WCHAR_SIZE_WARNING	313
#define OPTION_FIX_CORTEX_A8		314
#define OPTION_NO_FIX_CORTEX_A8		315
#define OPTION_NO_MERGE_EXIDX_ENTRIES	316
#define OPTION_FIX_ARM1176		317
#define OPTION_NO_FIX_ARM1176		318
#define OPTION_LONG_PLT			319
#define OPTION_STM32L4XX_FIX		320
#define OPTION_CMSE_IMPLIB		321
#define OPTION_IN_IMPLIB		322
#define OPTION_DETAILED_MEM_USAGE  323
'

PARSE_AND_LIST_SHORTOPTS=p

PARSE_AND_LIST_LONGOPTS='
  { "no-pipeline-knowledge", no_argument, NULL, '\'p\''},
  { "thumb-entry", required_argument, NULL, OPTION_THUMB_ENTRY},
  { "be8", no_argument, NULL, OPTION_BE8},
  { "target1-rel", no_argument, NULL, OPTION_TARGET1_REL},
  { "target1-abs", no_argument, NULL, OPTION_TARGET1_ABS},
  { "target2", required_argument, NULL, OPTION_TARGET2},
  { "fix-v4bx", no_argument, NULL, OPTION_FIX_V4BX},
  { "fix-v4bx-interworking", no_argument, NULL, OPTION_FIX_V4BX_INTERWORKING},
  { "use-blx", no_argument, NULL, OPTION_USE_BLX},
  { "vfp11-denorm-fix", required_argument, NULL, OPTION_VFP11_DENORM_FIX},
  { "fix-stm32l4xx-629360", optional_argument, NULL, OPTION_STM32L4XX_FIX},
  { "no-enum-size-warning", no_argument, NULL, OPTION_NO_ENUM_SIZE_WARNING},
  { "pic-veneer", no_argument, NULL, OPTION_PIC_VENEER},
  { "stub-group-size", required_argument, NULL, OPTION_STUBGROUP_SIZE },
  { "no-wchar-size-warning", no_argument, NULL, OPTION_NO_WCHAR_SIZE_WARNING},
  { "fix-cortex-a8", no_argument, NULL, OPTION_FIX_CORTEX_A8 },
  { "no-fix-cortex-a8", no_argument, NULL, OPTION_NO_FIX_CORTEX_A8 },
  { "no-merge-exidx-entries", no_argument, NULL, OPTION_NO_MERGE_EXIDX_ENTRIES },
  { "fix-arm1176", no_argument, NULL, OPTION_FIX_ARM1176 },
  { "no-fix-arm1176", no_argument, NULL, OPTION_NO_FIX_ARM1176 },
  { "long-plt", no_argument, NULL, OPTION_LONG_PLT },
  { "cmse-implib", no_argument, NULL, OPTION_CMSE_IMPLIB },
  { "in-implib", required_argument, NULL, OPTION_IN_IMPLIB },
  { "detailed-mem-usage", no_argument, NULL, OPTION_DETAILED_MEM_USAGE},
'

PARSE_AND_LIST_OPTIONS='
  fprintf (file, _("  --thumb-entry=<sym>         Set the entry point to be Thumb symbol <sym>\n"));
  fprintf (file, _("  --be8                       Output BE8 format image\n"));
  fprintf (file, _("  --target1-rel               Interpret R_ARM_TARGET1 as R_ARM_REL32\n"));
  fprintf (file, _("  --target1-abs               Interpret R_ARM_TARGET1 as R_ARM_ABS32\n"));
  fprintf (file, _("  --target2=<type>            Specify definition of R_ARM_TARGET2\n"));
  fprintf (file, _("  --fix-v4bx                  Rewrite BX rn as MOV pc, rn for ARMv4\n"));
  fprintf (file, _("  --fix-v4bx-interworking     Rewrite BX rn branch to ARMv4 interworking veneer\n"));
  fprintf (file, _("  --use-blx                   Enable use of BLX instructions\n"));
  fprintf (file, _("  --vfp11-denorm-fix          Specify how to fix VFP11 denorm erratum\n"));
  fprintf (file, _("  --fix-stm32l4xx-629360      Specify how to fix STM32L4XX 629360 erratum\n"));
  fprintf (file, _("  --no-enum-size-warning      Don'\''t warn about objects with incompatible\n"
		   "                                enum sizes\n"));
  fprintf (file, _("  --no-wchar-size-warning     Don'\''t warn about objects with incompatible\n"
		   "                                wchar_t sizes\n"));
  fprintf (file, _("  --pic-veneer                Always generate PIC interworking veneers\n"));
  fprintf (file, _("  --long-plt                  Generate long .plt entries\n"
           "                              to handle large .plt/.got displacements\n"));
  fprintf (file, _("  --cmse-implib               Make import library to be a secure gateway import\n"
                   "                                library as per ARMv8-M Security Extensions\n"));
  fprintf (file, _("  --in-implib                 Import library whose symbols address must\n"
                   "                                remain stable\n"));
  fprintf (file, _("\
  --stub-group-size=N         Maximum size of a group of input sections that\n\
                               can be handled by one stub section.  A negative\n\
                               value locates all stubs after their branches\n\
                               (with a group size of -N), while a positive\n\
                               value allows two groups of input sections, one\n\
                               before, and one after each stub section.\n\
                               Values of +/-1 indicate the linker should\n\
                               choose suitable defaults.\n"));
  fprintf (file, _("  --[no-]fix-cortex-a8        Disable/enable Cortex-A8 Thumb-2 branch erratum fix\n"));
  fprintf (file, _("  --no-merge-exidx-entries    Disable merging exidx entries\n"));
  fprintf (file, _("  --[no-]fix-arm1176          Disable/enable ARM1176 BLX immediate erratum fix\n"));
  fprintf (file, _("  --detailed-mem-usage        Output object file wise memory usage to map file\n"));
'

PARSE_AND_LIST_ARGS_CASES='
    case '\'p\'':
      /* Only here for backwards compatibility.  */
      break;

    case OPTION_THUMB_ENTRY:
      params.thumb_entry_symbol = optarg;
      break;

    case OPTION_BE8:
      params.byteswap_code = 1;
      break;

    case OPTION_TARGET1_REL:
      params.target1_is_rel = 1;
      break;

    case OPTION_TARGET1_ABS:
      params.target1_is_rel = 0;
      break;

    case OPTION_TARGET2:
      params.target2_type = optarg;
      break;

    case OPTION_FIX_V4BX:
      params.fix_v4bx = 1;
      break;

    case OPTION_FIX_V4BX_INTERWORKING:
      params.fix_v4bx = 2;
      break;

    case OPTION_USE_BLX:
      params.use_blx = 1;
      break;

    case OPTION_VFP11_DENORM_FIX:
      if (strcmp (optarg, "none") == 0)
        params.vfp11_denorm_fix = BFD_ARM_VFP11_FIX_NONE;
      else if (strcmp (optarg, "scalar") == 0)
        params.vfp11_denorm_fix = BFD_ARM_VFP11_FIX_SCALAR;
      else if (strcmp (optarg, "vector") == 0)
        params.vfp11_denorm_fix = BFD_ARM_VFP11_FIX_VECTOR;
      else
        einfo (_("Unrecognized VFP11 fix type '\''%s'\''.\n"), optarg);
      break;

    case OPTION_STM32L4XX_FIX:
      if (!optarg)
        params.stm32l4xx_fix = BFD_ARM_STM32L4XX_FIX_DEFAULT;
      else if (strcmp (optarg, "none") == 0)
        params.stm32l4xx_fix = BFD_ARM_STM32L4XX_FIX_NONE;
      else if (strcmp (optarg, "default") == 0)
        params.stm32l4xx_fix = BFD_ARM_STM32L4XX_FIX_DEFAULT;
      else if (strcmp (optarg, "all") == 0)
        params.stm32l4xx_fix = BFD_ARM_STM32L4XX_FIX_ALL;
      else
        einfo (_("Unrecognized STM32L4XX fix type '\''%s'\''.\n"), optarg);
      break;

    case OPTION_NO_ENUM_SIZE_WARNING:
      params.no_enum_size_warning = 1;
      break;

    case OPTION_NO_WCHAR_SIZE_WARNING:
      params.no_wchar_size_warning = 1;
      break;

    case OPTION_PIC_VENEER:
      params.pic_veneer = 1;
      break;

    case OPTION_STUBGROUP_SIZE:
      {
	const char *end;

        group_size = bfd_scan_vma (optarg, &end, 0);
        if (*end)
	  einfo (_("%P%F: invalid number `%s'\''\n"), optarg);
      }
      break;

    case OPTION_FIX_CORTEX_A8:
      params.fix_cortex_a8 = 1;
      break;

    case OPTION_NO_FIX_CORTEX_A8:
      params.fix_cortex_a8 = 0;
      break;

   case OPTION_NO_MERGE_EXIDX_ENTRIES:
      params.merge_exidx_entries = 0;
      break;

   case OPTION_FIX_ARM1176:
      params.fix_arm1176 = 1;
      break;

   case OPTION_NO_FIX_ARM1176:
      params.fix_arm1176 = 0;
      break;

   case OPTION_LONG_PLT:
      bfd_elf32_arm_use_long_plt ();
      break;

   case OPTION_CMSE_IMPLIB:
      params.cmse_implib = 1;
      break;

   case OPTION_IN_IMPLIB:
      in_implib_filename = optarg;
      break;

   case OPTION_DETAILED_MEM_USAGE:
      detailed_mem_usage_to_map = TRUE;
      break;
'




# We have our own before_allocation etc. functions, but they call
# the standard routines, so give them a different name.
LDEMUL_BEFORE_ALLOCATION=arm_elf_before_allocation
LDEMUL_CREATE_OUTPUT_SECTION_STATEMENTS=arm_elf_create_output_section_statements

# Replace the elf before_parse function with our own.
LDEMUL_BEFORE_PARSE=gld"${EMULATION_NAME}"_before_parse
LDEMUL_SET_SYMBOLS=gld"${EMULATION_NAME}"_set_symbols

# Call the extra arm-elf function (merged with the mips BFA code)
LDEMUL_FINISH=gld"${EMULATION_NAME}"_finish

# Add extra info to map file
LDEMUL_EXTRA_MAP_FILE_TEXT=arm_extra_map_file_text


LDEMUL_AFTER_OPEN=pic32c_after_open

# FIXME? these fail to include or handle any of the existing
# arm-specific emulation options.
LDEMUL_PARSE_ARGS=gldelf32pic32c_parse_args
LDEMUL_LIST_OPTIONS=gldelf32pic32c_list_options
# fixme:  not sure next one is right or even needed
#LDEMUL_AFTER_PARSE=arm_after_parse    

# Renamed because we may need to call the standard place_orphan.
LDEMUL_PLACE_ORPHAN=arm_elf_place_orphan

LDEMUL_AFTER_ALLOCATION=gldelf32pic32c_after_allocation
