/* pic32c option processing for the linker.

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
#include "getopt.h"
#include "bfd.h"
#include "libiberty.h"

#include "elf-bfd.h"
#include "elf/pic32.h"
#include "ld.h"     /* For the _() macro */
#include "ldmisc.h"
#include "pic32c-options.h"
#include "pic32-debug.h"

#define DEBUG_SCOPE "options"

//fixme   this is gone for now
#if 0
extern void pic32_processor_option(char *);
#endif
/* Emulation-specific Options */
const char * pic32_shortopts = "-Dp:"; /* note: leading "-" is important */

static struct option pic32_longopts[] =
{
  { "debug",            optional_argument,  NULL, PIC32C_DEBUG_OPTION },
  { "debug-sio",        no_argument,        NULL, PIC32C_DEBUG_SMARTIO_OPTION },
  { "smart-io",         no_argument,        NULL, SMART_IO_OPTION },
  { "no-smart-io",      no_argument,        NULL, NO_SMART_IO_OPTION },
  { "report-mem",       no_argument,        NULL, REPORT_MEM_OPTION },
  { "mafrlcsj",         no_argument,        NULL, REPORT_MAFRLCSJ_OPTION },
  { "mafrlcsj2",        no_argument,        NULL, REPORT_MAFRLCSJ2_OPTION },
  { "memorysummary",    required_argument,  NULL, MEMORY_SUMMARY },
  { "data-init",        no_argument,        NULL, DATA_INIT_OPTION },
  { "no-data-init",     no_argument,        NULL, NO_DATA_INIT_OPTION },
  { "fill",             required_argument,  NULL, FILL_OPTION },
  { "crypto",           required_argument,  NULL, CRYPTO_OPTION },
  { "mreserve",         required_argument,  NULL, MEMRESERVE_OPTION },
  { "hard-float",       no_argument,        NULL, HARDFLOAT_OPTION },
  { "soft-float",       no_argument,        NULL, SOFTFLOAT_OPTION },
  { "code-in-dinit",    no_argument,        NULL, CODE_IN_DINIT_OPTION },
  { "no-code-in-dinit", no_argument,        NULL, NO_CODE_IN_DINIT_OPTION },
#if 0 ///\ tmp removed
  { "dinit-in-serial-mem",    no_argument,  NULL,   DINIT_IN_SERIAL_MEM_OPTION },
  { "no-dinit-in-serial-mem", no_argument,  NULL,   NO_DINIT_IN_SERIAL_MEM_OPTION },
#endif
  { "dinit-address",    required_argument, NULL,    DINIT_ADDRESS_OPTION },
  { "tcm",              required_argument, NULL,    TCM_OPTION},
  { "itcm",             required_argument, NULL,    ITCM_OPTION},
  { "dtcm",             required_argument, NULL,    DTCM_OPTION},
  { "stack-in-tcm",     no_argument,       NULL,    STACK_IN_TCM_OPTION},
  { "vectors-in-tcm",   no_argument,       NULL,    VECTORS_IN_TCM_OPTION},
  /* need both of these for legacy reasons */
  { "no-vectors-in-tcm",   no_argument,    NULL,    NO_VECTORS_IN_TCM_OPTION},
  { "novectors-in-tcm",   no_argument,     NULL,    NO_VECTORS_IN_TCM_OPTION},
    /* lghica co-resident */
    { "memory-usage",           no_argument,        NULL, MEMORY_USAGE },
    { "reserve-const",          optional_argument,  NULL, RESERVE_CONST },
    { "pad-flash",              optional_argument,  NULL, PAD_FLASH },
    { "application-id",         required_argument,  NULL, APPLICATION_ID },
    { "coresident",             no_argument,        NULL, CORESIDENT },
    { "inherit-application-info", required_argument, NULL, INHERIT_APPLICATION_INFO },
  { "mchp-stack-usage",            no_argument,        NULL, MCHP_STACK_USAGE },
  {"dinit-compression", required_argument,  NULL, MCHP_DINIT_COMPRESS},
  {"dinit-self-check", no_argument, NULL, MCHP_DINIT_SELF_CHECK},
  { NULL,        no_argument,       NULL, 0                }
};

/*
** list_options()
**
** This function is called by the --help option.
*/
void
pic32c_list_options (FILE * file)
{
/*  -D or --debug is intended for internal use. It is not for use by end customers.
    So, don't output the option in the help screen.
*/
  fprintf (file, _("  --hard-float         Use library objects utilizing FR64 floating-point"
                   "instructions\n"));
  fprintf (file, _("  --soft-float         Use library objects utilizing software floating-"
                   "point emulation\n"));
  fprintf (file, _("  -p,--processor PROC  Specify the target processor"
                   " (e.g., 32MX795F512L)\n"));
  fprintf (file, _("  --report-mem         Report memory usage to console\n"));
  fprintf (file, _("  --smart-io           Merge I/O library functions (default)\n"));
  fprintf (file, _("  --itcm = x          Allocate x bytes of ITCM\n"));
  fprintf (file, _("  --dtcm = x          Allocate x bytes of DTCM\n"));
  fprintf (file, _("  --tcm = x           Allocate x bytes of combined TCM\n"));
  fprintf (file, _("  --stack-in-tcm       Allocate the stack in TCM\n"));
  fprintf (file, _("  --no-vectors-in-tcm   Don't allocate the interrupt vectors in TCM\n"));
  
} /* static void elf32pic32c_list_options () */

static void pic32_init_fill_option_list (struct pic32_fill_option **lst)
{
  *lst = ((struct pic32_fill_option *)
         xmalloc(sizeof(struct pic32_fill_option)));
  (*lst)->next = 0;
  (*lst)->expr.values_range = NULL;
  (*lst)->expr.base_value = 0;
  (*lst)->expr.addened = 0;
  (*lst)->loc.unused = TRUE;
  (*lst)->loc.address = 0;
  (*lst)->loc.end_address = 0;
  (*lst)->fill_section_list = NULL;
}

static void pic32_create_fill_option (struct pic32_fill_option *option)
{
  option->next = 0;
  option->expr.values_range = 0;
  option->expr.base_value = 0;
  option->expr.addened = 0;
  option->loc.unused = TRUE;
  option->loc.address = 0;
  option->loc.end_address = 0;
  option->fill_section_list = NULL;
  option->fill_width = 4;
  option->range_size = 0;
}

static void pic32_append_option_to_list (struct pic32_fill_option *lst,
                                         struct pic32_fill_option *option)
{
  struct pic32_fill_option *o, *tail;
  if (!(lst))
    return;
  /* find the tail */
  for (o = lst; o != NULL; o = o->next)
    tail = o;
  /* append the new option */
  tail->next = option;
}

static void
pic32_process_fill_argument (char * fill_arg)
{
  char *expression = NULL;
  char *location = NULL;
  struct pic32_fill_option *option;
  char *LHS_operand = NULL;
  char *RHS_operand = NULL;
  char *addr = NULL;
  char *end_addr = NULL;
  char *width = NULL;
  long long value = 0;
  long long address = 0;
  const char *fill_warn = "Incorrect format for fill argument\n";
  
  /* check if there is no fill expression */ 
  if (strncmp(fill_arg, "@", 1) == 0)
    {
      einfo(_("%P: Warning: %s"), fill_warn);
      return;}

  expression = strtok(fill_arg, "@");
  location = strtok(NULL, "@");
  if (expression)
    {
      if (strchr(expression, ':'))
	{
	  width = strtok(expression, ":");
	  expression = strtok(NULL,":");
	}
      /* create the options list*/

      if (!pic32_fill_option_list)
	pic32_init_fill_option_list(&pic32_fill_option_list);
      option = ((struct pic32_fill_option *)
		xmalloc(sizeof(struct pic32_fill_option)));
      pic32_create_fill_option(option);
      if (width && (*width == 'w'))
	(void)sscanf((width+1), "%i", &(option->fill_width));

      if ((option->fill_width != 1) && (option->fill_width != 2) &&
	  (option->fill_width != 4) && (option->fill_width != 8)){
	einfo(_("%P: Warning: You cannot use a width_value of %d."
		"You must specify only one byte, 2 bytes, 8 bytes, or"
		" one instruction word (4 bytes, the default)."
		" The default width will be used.\n"),
	      option->fill_width);
	option->fill_width = 4;}

      pic32_init_section_list(&option->fill_section_list);

      /* expression is a changing value */
      char *inc = strstr(expression, "+=");
      char *dec = strstr(expression, "-=");
      if (inc || dec)
	{
	  RHS_operand = inc? inc + 2 : dec + 2;
	  if (inc) *inc = '\0'; else *dec = '\0';
	  LHS_operand = expression;
	  (void)sscanf(LHS_operand, "%lli", &(option->expr.base_value));
	  (void)sscanf(RHS_operand, "%lli", &(option->expr.addened));
	  if (dec)
	    option->expr.addened = -option->expr.addened;
	}

      /* expression is a range of values */
      else if (strchr(expression, ','))
        {
	  int count = 0;
	  char *token = ((char *) malloc(strlen(expression)+1));
	  char *value_token;
	  unsigned char *buff;
	  strcpy(token, (const char *)expression);
	  for (value_token = strtok(token, ","); value_token;
	       value_token = strtok(NULL, ","))
            count++; /*get the range size*/
	  option->range_size = count;
	  free(token);
	  buff = malloc((count * option->fill_width) * sizeof(unsigned char));
	  option->expr.values_range = buff;
	  for (value_token = strtok(expression, ","); value_token;
	       value_token = strtok(NULL, ","))
	    {
	      (void)sscanf(value_token, "%lli", &value);
	      if (option->fill_width == 1)
		*buff++ = value & 0xFF;
	      else if (option->fill_width == 2){
		*buff++ = value & 0xFF;
		*buff++ = (value >> 8) & 0xFF;
	      }
	      else if (option->fill_width == 8){
		*buff++ = value & 0xFF;
		*buff++ = (value >> 8) & 0xFF;
		*buff++ = (value >> 16) & 0xFF;
		*buff++ = (value >> 24) & 0xFF;
		*buff++ = (value >> 32) & 0xFF;
		*buff++ = (value >> 40) & 0xFF;
		*buff++ = (value >> 48) & 0xFF;
		*buff++ = (value >> 56) & 0xFF;
	      }
	      else{
		*buff++ = value & 0xFF;
		*buff++ = (value >> 8) & 0xFF;
		*buff++ = (value >> 16) & 0xFF;
		*buff++ = (value >> 24) & 0xFF;
	      }
	    }
        }
      /* expression is a single value */
      else 
        {
	  (void)sscanf(expression, "%lli", &value);
	  option->expr.base_value = value;
        }
      if (location)
	{
	  int read_val = 0;
	  if (strcmp(location, "unused") != 0)
	    { option->loc.unused = FALSE;

	      addr = strtok(location, ":");
	      end_addr = strtok(NULL, ":");
	      read_val = sscanf(addr, "%lli", &address);
	      option->loc.address = address & 0xFFFFFFFFu;
	      if (end_addr){
		read_val = sscanf(end_addr, "%lli", &address);
		option->loc.end_address = address & 0xFFFFFFFFu;
	      }
	      if (read_val == 0) {
		einfo(_("%P: Warning: Bad location specified for fill option. "
			"Option will be ignored.\n"));
		return;
	      }
	    }
	}
    }
  else 
    {
      einfo(_("%P: Warning: %s"), fill_warn);
      return;
    }
  pic32_append_option_to_list(pic32_fill_option_list, option);
  return;
}

/*
** parse_args()
**
** This function is called for each command-line option.
*/
int
pic32c_parse_args (int argc, char ** argv)
{
  int        longind;
  int        optc;
  int        prevoptind = optind;
  int        prevopterr = opterr;
  int        wanterror;
  static int lastoptind = -1;
  char* inv_char = NULL;

  const char *smart_io_option_err  = "--smart-io and --no-smart-io";
  const char *option_err = " options can not be used together\n";
  const char *hardsoftfloat_option_err  = "--hard-float and --soft-float";
  const char *data_init_option_err = "--data-init and --no-data-init";
#ifdef ENABLE_SERIAL_MEM
  const char *data_init_in_serial_mem_option_err = "--data-init_in_serial_mem and --no-data-init_in_serial_mem";
#endif
  const char *code_in_dinit_option_err = "--code-in-dinit and --no-code-in-dinit";
  const char *data_init_compress_option_warn = "Invalid value for dinit-compress option. Setting to " F_STR(DEFAULT_DINIT_LEVEL) " (default value).\n";

  if (lastoptind != optind)
    opterr = 0;

  wanterror  = opterr;
  lastoptind = optind;
  optc   = getopt_long_only (argc, argv, pic32_shortopts, pic32_longopts, & longind);
  opterr = prevopterr;
  
  switch (optc)
    {
    default:
      if (wanterror)
        xexit (1);
      optind =  prevoptind;
      return 0;
    case PIC32C_DEBUG_OPTION:
      pic32_debug = TRUE;
      pic32_debug_enable_scope (optarg);
      break;
    case PIC32C_DEBUG_SMARTIO_OPTION:
      pic32_debug_smartio = TRUE;
      break;
    case MCHP_STACK_USAGE:
      pic32_stack_usage = TRUE;
      break;
    case SMART_IO_OPTION:
      if (pic32_has_smart_io_option && (!pic32_smart_io))
        einfo(_("%P%F: Error: %s%s"), smart_io_option_err, option_err);
      pic32_smart_io = TRUE;
      pic32_has_smart_io_option = TRUE;
      break;
    case NO_SMART_IO_OPTION:
      if (pic32_has_smart_io_option && (pic32_smart_io))
        einfo(_("%P%F: Error: %s%s"), smart_io_option_err, option_err);
      pic32_smart_io = FALSE;
      pic32_has_smart_io_option = TRUE;
      break;
    case REPORT_MEM_OPTION:
      pic32_report_mem = TRUE;
      break;
    case REPORT_MAFRLCSJ_OPTION:
      pic32_mafrlcsj = TRUE;
      break;
    case REPORT_MAFRLCSJ2_OPTION:
      pic32_mafrlcsj2 = TRUE;
      break;
    case MEMORY_SUMMARY:
      pic32_memory_summary= TRUE;
      memory_summary_arg = optarg;
      break;
    case DATA_INIT_OPTION:
      if (pic32_has_data_init_option && (!pic32_data_init))
        einfo(_("%P%F: Error: %s%s"), data_init_option_err, option_err);
      pic32_data_init = TRUE;
      pic32_has_data_init_option = TRUE;
      break;
    case NO_DATA_INIT_OPTION:
      if (pic32_has_data_init_option && (pic32_data_init))
        einfo(_("%P%F: Error: %s%s"), data_init_option_err, option_err);
      pic32_data_init = FALSE;
      pic32_has_data_init_option = TRUE;
      break;

    case MEMORY_USAGE:
#if 0 ///\ to be enabled with coresident
      pic32_memory_usage = TRUE;
#endif
      break;
            
    case RESERVE_CONST:
#if 0 ///\ to be enabled with coresident
      pic32_reserve_const = TRUE;
      if (optarg)
        {
	  if ((strstr(optarg, "0x") == 0) && (strstr(optarg, "0X") == 0))
	    reserve_const_arg = atol(optarg);
	  else
	    (void) sscanf(optarg, "%lx", &reserve_const_arg);
        }
#endif
      break;
    case PAD_FLASH:
#if 0 ///\ to be enabled with coresident
      pic32_pad_flash_option = TRUE;
      if (optarg)
        {
	  if ((strstr(optarg, "0x") == 0) && (strstr(optarg, "0X") == 0))
	    pad_flash_arg = atol(optarg);
	  else
	    (void) sscanf(optarg, "%lx", &pad_flash_arg);
        }
#endif
      break;
    case APPLICATION_ID:
#if 0 ///\ to be enabled with coresident
      pic32_application_id = TRUE;
      application_id = optarg;
#endif
      break;
    case CORESIDENT:
#if 0 ///\ coresident not enabled
      pic32_coresident_app = TRUE;
#endif
      break;
    case INHERIT_APPLICATION_INFO:
#if 0 ///\ to be removed
      pic32_inherit_application_info = TRUE;
      inherited_application = optarg;
      lang_add_input_file (optarg, lang_input_file_is_file_enum,
			   (char *) NULL);
#endif
      break;
            
#ifdef TARGET_IS_PIC32C
    case FILL_OPTION:
      pic32_process_fill_argument (optarg);
      pic32_has_fill_option = TRUE;
      break;
    case CRYPTO_OPTION:
#if 0
      pic32_has_crypto_option = TRUE;
      crypto_file = (char *) malloc(strlen(optarg)+1);
      strcpy(crypto_file, optarg);
#endif
      break;
    case MEMRESERVE_OPTION:
      /* This option has already been handled by the xc32-sh shell */
      break;
    case 'p':
      //  pic32_processor_option(optarg);
      break;
    case HARDFLOAT_OPTION:
      if (pic32_has_softfloat_option)
        einfo(_("%P%F: Error: %s%s"), hardsoftfloat_option_err, option_err);
      pic32_has_hardfloat_option = TRUE;
      break;
    case SOFTFLOAT_OPTION:
      if (pic32_has_hardfloat_option)
        einfo(_("%P%F: Error: %s%s"), hardsoftfloat_option_err, option_err);
      pic32_has_softfloat_option = TRUE;
      break;    
    case CODE_IN_DINIT_OPTION:
      if (pic32_has_code_in_dinit_option && !pic32_code_in_dinit)
        einfo(_("%P%F: Error: %s%s"), code_in_dinit_option_err,
	      option_err);      
      pic32_code_in_dinit = TRUE;
      pic32_has_code_in_dinit_option = TRUE;
      break;
    case NO_CODE_IN_DINIT_OPTION:
      if (pic32_has_code_in_dinit_option && pic32_code_in_dinit)
        einfo(_("%P%F: Error: %s%s"), code_in_dinit_option_err,
	      option_err);
      pic32_code_in_dinit = FALSE;
      pic32_has_code_in_dinit_option = TRUE;
      break;
#if 0   ///\ tmp removed
    case DINIT_IN_SERIAL_MEM_OPTION:
      if (pic32_has_dinit_in_serial_mem_option && !pic32_dinit_in_serial_mem)
        einfo(_("%P%F: Error: %s%s"), data_init_in_serial_mem_option_err,
	      option_err);
      pic32_dinit_in_serial_mem = TRUE;
      pic32_has_dinit_in_serial_mem_option = TRUE;
      break;
    case NO_DINIT_IN_SERIAL_MEM_OPTION:
      if (pic32_has_dinit_in_serial_mem_option && pic32_dinit_in_serial_mem)
        einfo(_("%P%F: Error: %s%s"), data_init_in_serial_mem_option_err,
	      option_err);
      pic32_dinit_in_serial_mem = FALSE;
      pic32_has_dinit_in_serial_mem_option = TRUE;
      break;
#endif
    case DINIT_ADDRESS_OPTION:
      pic32_dinit_has_absolute_address = TRUE;
      if ((strstr(optarg, "0x") == 0) && (strstr(optarg, "0X") == 0))
        dinit_address = atol(optarg);
      else
        (void) sscanf(optarg, "%x", &dinit_address);
      break;

    case TCM_OPTION:
      pic32c_tcm_enabled = TRUE;
      if (optarg)
        {
	  pic32c_tcm_size = strtol(optarg, &inv_char, 0);
	  if ((inv_char!= NULL) && ((*inv_char) != 0))
            {
	      einfo(_("%P: Warning: Invalid value for tcm option. "
		      "Setting it to default value.\n"));
	      pic32c_tcm_size = DEFAULT_TCM_SIZE;
            }
        }
      else
	pic32c_tcm_size = DEFAULT_TCM_SIZE;
      break;
            
    case ITCM_OPTION:
      pic32c_tcm_enabled = TRUE;
      if (optarg)
        {
	  pic32c_itcm_size = strtol(optarg, &inv_char, 0);
	  if ((inv_char!= NULL) && ((*inv_char) != 0))
            {
	      einfo(_("%P: Warning: Invalid value for itcm option. "
		      "Setting it to default value.\n"));
	      pic32c_itcm_size = DEFAULT_TCM_SIZE;
            }
        }
      else
	pic32c_itcm_size = DEFAULT_TCM_SIZE;
      break;

    case DTCM_OPTION:
      pic32c_tcm_enabled = TRUE;
      if (optarg)
        {
	  pic32c_dtcm_size = strtol(optarg, &inv_char, 0);
	  if ((inv_char!= NULL) && ((*inv_char) != 0))
            {
	      einfo(_("%P: Warning: Invalid value for dtcm option. "
		      "Setting it to default value.\n"));
	      pic32c_dtcm_size = DEFAULT_TCM_SIZE;
            }
        }
      else
	pic32c_dtcm_size = DEFAULT_TCM_SIZE;
      break;
            
            
    case STACK_IN_TCM_OPTION:
      PIC32_DEBUG("Note: Enabled stack in tcm");
      pic32c_stack_in_tcm = TRUE;
      break;
	
    case VECTORS_IN_TCM_OPTION:
      pic32c_vectors_in_tcm = TRUE;
      break;
 
    case NO_VECTORS_IN_TCM_OPTION:
      PIC32_DEBUG("Note: Not placing interrupt vectors in tcm");
      pic32c_vectors_in_tcm = FALSE;
      break;
    case MCHP_DINIT_COMPRESS:
        /*
        ** -dinit-compress=0 (legacy)
        ** -dinit-compress=1 (merge data sections)
        ** -dinit-compress=2 (merge & repeated values)
        ** -dinit-compress=3 (merge & repeated values & compression)
        */
        dinit_compress_level = (unsigned int) strtol(optarg, &inv_char, 0);
        if (((inv_char!= NULL) && ((*inv_char) != 0))
            || dinit_compress_level > MAX_DINIT_OPTIMIZATION_LVL)
        {
	  einfo(_("%P: Warning: %s\n"), data_init_compress_option_warn);
	  dinit_compress_level = DEFAULT_DINIT_LEVEL;
        }
      break;
    case MCHP_DINIT_SELF_CHECK:
      dinit_self_check = TRUE;
      break;


#endif /* TARGET_IS_PIC32C */
    }

  return 1;
}
