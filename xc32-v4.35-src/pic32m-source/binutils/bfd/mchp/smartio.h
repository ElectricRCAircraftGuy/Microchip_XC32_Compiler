#if defined (TARGET_IS_PIC32C) || defined(TARGET_IS_PIC32MX)

/*
 * make common version of these symbols which will be initialized to NIL
 * unless we are creating the linker where an initialized definition will
 * be provided
 *
 * we only call these functions if it is a valid pointer
 */

void (*mchp_smartio_add_symbols) (struct bfd_link_info *) __attribute__((weak));
unsigned int (*mchp_force_keep_symbol)(char *, char *) __attribute__((weak)) ;

extern bfd_boolean pic32_smart_io;
extern bfd_boolean pic32_debug;

#endif

