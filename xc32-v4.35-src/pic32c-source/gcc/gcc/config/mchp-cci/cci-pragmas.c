/* Subroutines used for Microchip PIC32 MCU support
   Copyright (C) 2017
   Microchip Technology, Inc.

This file is part of Microchip XC compiler tool-chain.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/*
 *  Common CCI definitions for Microchip Compilers
 */

#ifdef _BUILD_MCHP_

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "target.h"
#include "varasm.h"
#include "output.h"
#include "tree-core.h"
#include "tree.h"
#include "memmodel.h"
#include "gimple.h"
#include "cfghooks.h"
#include "df.h"
#include "tm_p.h"
#include "stringpool.h"
#include "cgraph.h"
#include "alias.h"
#include "fold-const.h"
#include "stor-layout.h"
#include "calls.h"
#include "explow.h"
#include "libfuncs.h"
#include "common/common-target.h"
#include "langhooks.h"
#include "cfgrtl.h"
#include "cfganal.h"
#include "sched-int.h"
#include "gimplify.h"
#include "tree-pass.h"
#include "context.h"
#include "target-globals.h"
#include "builtins.h"
#include "c-family/c-common.h"
#include "c-family/c-pragma.h"
#include "c/c-tree.h"
#include "diagnostic.h"

#define CCI_H "config/mchp-cci/cci.h"
#include CCI_H
#include "config/mchp-cci/cci-pragmas.h"

/* handler function for the config pragma */
void
mchp_handle_config_pragma (struct cpp_reader *pfile)
{
  enum cpp_ttype tok;
  tree tok_value;
  static int shown_no_config_warning = 0;

  if (!mchp_config_data_file)
    {
      error ("Configuration-word data file not specified "
             "but required for #pragma config directive; has a valid device "
             "been selected?");
      CLEAR_REST_OF_INPUT_LINE();
      return;
    }

  /* the first time we see a config pragma, we need to load the
     configuration word data from the definition file. */
  if (!mchp_configuration_values)
    {
      if (mchp_load_configuration_definition (mchp_config_data_file))
        {
          if (!shown_no_config_warning)
            {
              shown_no_config_warning = 1;
              warning (0, "Configuration word information not available for "
                       "this processor. #pragma config is ignored.");
            }
          CLEAR_REST_OF_INPUT_LINE();
          return;
        }
    }

  /* The payload for the config pragma is a comma delimited list of
     "setting = value" pairs. Both the setting and the value must
     be valid C identifiers. */
  tok = pragma_lex (&tok_value);
  while (1)
    {
      const cpp_token *raw_token;
      const char *setting_name;
      unsigned char *value_name;

      /* the current token should be the setting name */
      if (tok != CPP_NAME)
        {
          error ("configuration setting name expected in configuration pragma");
          break;
        }

      setting_name = IDENTIFIER_POINTER (tok_value);
      /* the next token should be the '=' */
      tok = pragma_lex (&tok_value);
      if (tok != CPP_EQ)
        {
          error ("'=' expected in configuration pragma");
          break;
        }
      /* now we have the value name. We don't use pragma_lex() to get this one
         since we don't want the additional interpretation going on there.
         i.e., converting integers from the string. */
      tok = pragma_lex (&tok_value);
      if (tok == CPP_NAME)
        value_name = (unsigned char *)IDENTIFIER_POINTER (tok_value);
      else if (tok == CPP_NUMBER)
        {
          if (tree_fits_uhwi_p (tok_value))
          {
            #define MAX_VALUE_NAME_LENGTH 22
            HOST_WIDE_INT i;
            i = tree_to_uhwi (tok_value);
            value_name = (unsigned char*)xcalloc(MAX_VALUE_NAME_LENGTH,1);
            snprintf((char *)value_name, MAX_VALUE_NAME_LENGTH, "%u", i);
            #undef MAX_VALUE_NAME_LENGTH
          }
          else
            {
              error ("config-setting value must be a valid integer constant");
              break;
            }
        }
      else
        {
          error ("config-setting value must be a name or a constant integer");
          break;
        }
      mchp_handle_configuration_setting (setting_name, value_name);

      /* if the next token is ',' then we have another setting. */
      tok = pragma_lex (&tok_value);
      if (tok == CPP_COMMA)
        tok = pragma_lex (&tok_value);
      /* if it's EOF, we're done */
      else if (tok == CPP_EOF)
        break;
      /* otherwise, we have spurious input */
      else
        {
          error ("',' or end of line expected in configuration pragma");
          break;
        }
    }
  /* if we ended for any reason other than end of line, we have an error.
     Any needed diagnostic should have already been issued, so just
     clear the rest of the data on the line. */
  if (tok != CPP_EOF)
    CLEAR_REST_OF_INPUT_LINE();
}

/* handler function for the 'nocodecov' pragma (sets mchp_pragma_nocodecov) */
void
mchp_handle_nocodecov_pragma (struct cpp_reader *pfile ATTRIBUTE_UNUSED)
{
  tree tok_value;

  if (pragma_lex (&tok_value) != CPP_EOF)
    {
      warning (OPT_Wpragmas, "junk at end of %<#pragma nocodecov%>, ignored");
      CLEAR_REST_OF_INPUT_LINE();
    }

  mchp_pragma_nocodecov = 1;
}

/* handler function for the 'nopa' pragma (sets mchp_pragma_nopa) */
void
mchp_handle_nopa_pragma (struct cpp_reader *pfile ATTRIBUTE_UNUSED)
{
  tree tok_value;

  if (pragma_lex (&tok_value) != CPP_EOF)
    {
      warning (OPT_Wpragmas, "junk at end of %<#pragma nopa%>, ignored");
      CLEAR_REST_OF_INPUT_LINE();
    }

  mchp_pragma_nopa = 1;
}

static void
mchp_handle_default_pragmas (char** sectionName, const char* errorMessage);

void
mchp_handle_default_variable_attributes_pragma (struct cpp_reader *pfile
    ATTRIBUTE_UNUSED)
{
  mchp_handle_default_pragmas(&mchp_pragma_default_variable_section,
                              "default_variable_attributes");
}

void
mchp_handle_default_function_attributes_pragma (struct cpp_reader *pfile
    ATTRIBUTE_UNUSED)
{
  mchp_handle_default_pragmas(&mchp_pragma_default_function_section,
                              "default_function_attributes");
}

void
mchp_handle_default_pragmas (char** sectionName,
    const char* errorMessage)
{
  tree tok_value;
  enum cpp_ttype tok;
  tok = pragma_lex (&tok_value);
  if (tok != CPP_EQ)
    {
      error("missing '=' after %<#pragma %s%>", errorMessage);
      CLEAR_REST_OF_INPUT_LINE();
      return;
    }

  tok = pragma_lex(&tok_value);
  if (tok == CPP_EOF)
    {
       free(*sectionName);
       *sectionName = NULL;
       CLEAR_REST_OF_INPUT_LINE();
       return;
    }

  if (tok != CPP_ATSIGN)
    {
      error("missing '@' after %<#pragma %s = %>",
            errorMessage);
      CLEAR_REST_OF_INPUT_LINE();
      return;
    }

  tok = pragma_lex (&tok_value);
  if (tok != CPP_STRING)
    {
      error ("missing section name after %<#pragma %s = @ %>",
             errorMessage);
      return;
    }

  const char *setting_name;
  size_t section_name_len = TREE_STRING_LENGTH(tok_value);
  setting_name = TREE_STRING_POINTER (tok_value);
  *sectionName = (char*) xrealloc(*sectionName, section_name_len);
  memcpy((void*) *sectionName, setting_name, section_name_len);

  if (pragma_lex (&tok_value) != CPP_EOF)
    {
      warning (OPT_Wpragmas, "junk at end of %<#pragma %s%>, ignored",
               errorMessage);
      CLEAR_REST_OF_INPUT_LINE();
    }
}
#endif /* _BUILD_MCHP_ */
