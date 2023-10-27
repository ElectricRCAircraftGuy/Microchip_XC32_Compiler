#ifndef PIC32_COMMON_EMUL_H
#define PIC32_COMMON_EMUL_H

/* This header is for common functions between pic32c/pic32m emulation files */

/* Symbol Lists */
struct pic32_symbol
{
  char *name;
  bfd_vma value;
};

struct pic32_symbol_list
{
  int pic32_symbol_count;
  int pic32_max_symbols;
  struct pic32_symbol *syms;
};

void pic32_init_symbol_list (struct pic32_symbol_list **);
void pic32_add_to_symbol_list
  (struct pic32_symbol_list **, const char *, bfd_vma);
struct pic32_symbol_list * bfd_pic32_fill_symbol_list(bfd *abfd);
bfd * bfd_pic32_create_data_init_bfd(bfd *);
asection * bfd_pic32_create_section (bfd *, const char *, int, int);

#endif
