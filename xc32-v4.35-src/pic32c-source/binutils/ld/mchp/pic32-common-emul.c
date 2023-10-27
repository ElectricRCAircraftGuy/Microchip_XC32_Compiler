#include "sysdep.h"
#include "bfd.h"
#include "ldmisc.h" // xmalloc prototype

#include "pic32-common-emul.h"

extern bfd_boolean pic32_debug;
/*
** Create a new symbol list
*/
void
pic32_init_symbol_list (struct pic32_symbol_list **lst)
{
  static const int PIC32_INIT_SYM_COUNT = 10;
  *lst = (struct pic32_symbol_list *)xmalloc (sizeof (struct pic32_symbol_list)
                                              * PIC32_INIT_SYM_COUNT);
  (*lst)->syms = ((struct pic32_symbol *)xmalloc (sizeof (struct pic32_symbol)
                                                  * PIC32_INIT_SYM_COUNT));
  (*lst)->pic32_max_symbols = PIC32_INIT_SYM_COUNT;
  (*lst)->pic32_symbol_count = 0;
}

/*
** Append to a symbol list
*/
void
pic32_add_to_symbol_list (struct pic32_symbol_list **lst, const char *name,
                          bfd_vma value)
{
  static const int PIC32_GROW_SYM_COUNT = 20;
  if ((*lst)->pic32_symbol_count >= (*lst)->pic32_max_symbols)
    {
      (*lst)->pic32_max_symbols += PIC32_GROW_SYM_COUNT;
      (*lst)->syms = ((struct pic32_symbol *)xrealloc (
          (*lst)->syms,
          sizeof (struct pic32_symbol) * (*lst)->pic32_max_symbols));
    }

  (*lst)->syms[(*lst)->pic32_symbol_count].name = (char *)name;
  (*lst)->syms[(*lst)->pic32_symbol_count].value = value;
  ++(*lst)->pic32_symbol_count;
}

/*
** Build a symbol list for a bfd
*/
struct pic32_symbol_list *
bfd_pic32_fill_symbol_list (bfd *abfd)
{
  const char *sym_name;
  asymbol **symbols = 0;
  bfd_boolean has_extended_attributes = FALSE;
  struct pic32_symbol_list *pic32_symbol_list = NULL;

  /*
   ** loop through the symbols in this bfd
   */
  long size, num, i;

  size = bfd_get_symtab_upper_bound (abfd);
  if (size < 0)
    abort ();

  symbols = (asymbol **)xmalloc (size);
  if (!symbols)
    abort ();

  num = bfd_canonicalize_symtab (abfd, symbols);
  if (num < 0)
    abort ();

  for (i = 0; i < num; i++)
    {

      char *ext_attr_prefix = "__ext_attr_";

      /*
       * Look for extended section attributes. If we find any,
       * store the info in a list for use below, where we loop
       * through the sections in this bfd.
       */
      sym_name = bfd_asymbol_name (symbols[i]);
      if (strstr (sym_name, ext_attr_prefix))
        {
          char *sec_name = (char *)&sym_name[strlen (ext_attr_prefix)];
          bfd_vma attr = bfd_asymbol_value (symbols[i]);

          if (!has_extended_attributes)
            {
              pic32_init_symbol_list (&pic32_symbol_list);
              has_extended_attributes = TRUE;
            }

          pic32_add_to_symbol_list (&pic32_symbol_list, sec_name, attr);
          if (pic32_debug)
            fprintf (stderr,
                     "    extended attributes for section %s: 0x%lx %s\n",
                     sec_name, attr, bfd_asymbol_name (symbols[i]));
        }
    }

  return pic32_symbol_list;
}
