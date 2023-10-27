/* Default linker script, for normal executables */
MEMORY
{
  rom (rx) : ORIGIN = 0x400000, LENGTH = 0x200000
  ram (rwx) : ORIGIN = 0x20400000, LENGTH = 0x60000 - (0 + 0)
     itcm (rwx) : ORIGIN = 0x0, LENGTH = 0
     dtcm (rwx) : ORIGIN = 0x20000000, LENGTH = 0
}
/* Copyright (C) 2014-2015 Free Software Foundation, Inc.
   Copying and distribution of this script, with or without modification,
   are permitted in any medium without royalty provided the copyright
   notice and this notice are preserved.  */
OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm",
	      "elf32-littlearm")
OUTPUT_ARCH(arm)
SECTIONS
{
  /* Read-only sections, merged into text segment: */
  PROVIDE (__executable_start = SEGMENT_START("text-segment", 0x400000)); . = SEGMENT_START("text-segment", 0x400000);
  .interp         : { *(.interp) }
  .note.gnu.build-id : { *(.note.gnu.build-id) }
  .hash           : { *(.hash) }
  .gnu.hash       : { *(.gnu.hash) }
  .dynsym         : { *(.dynsym) }
  .dynstr         : { *(.dynstr) }
  .gnu.version    : { *(.gnu.version) }
  .gnu.version_d  : { *(.gnu.version_d) }
  .gnu.version_r  : { *(.gnu.version_r) }
  .rel.init       : { *(.rel.init) }
  .rela.init      : { *(.rela.init) }
  .rel.text       : { *(.rel.text .rel.text.* .rel.gnu.linkonce.t.*) }
  .rela.text      : { *(.rela.text .rela.text.* .rela.gnu.linkonce.t.*) }
  .rel.fini       : { *(.rel.fini) }
  .rela.fini      : { *(.rela.fini) }
  .rel.rodata     : { *(.rel.rodata .rel.rodata.* .rel.gnu.linkonce.r.*) }
  .rela.rodata    : { *(.rela.rodata .rela.rodata.* .rela.gnu.linkonce.r.*) }
  .rel.data.rel.ro   : { *(.rel.data.rel.ro .rel.data.rel.ro.* .rel.gnu.linkonce.d.rel.ro.*) }
  .rela.data.rel.ro   : { *(.rela.data.rel.ro .rela.data.rel.ro.* .rela.gnu.linkonce.d.rel.ro.*) }
  .rel.data       : { *(.rel.data .rel.data.* .rel.gnu.linkonce.d.*) }
  .rela.data      : { *(.rela.data .rela.data.* .rela.gnu.linkonce.d.*) }
  .rel.tdata	  : { *(.rel.tdata .rel.tdata.* .rel.gnu.linkonce.td.*) }
  .rela.tdata	  : { *(.rela.tdata .rela.tdata.* .rela.gnu.linkonce.td.*) }
  .rel.tbss	  : { *(.rel.tbss .rel.tbss.* .rel.gnu.linkonce.tb.*) }
  .rela.tbss	  : { *(.rela.tbss .rela.tbss.* .rela.gnu.linkonce.tb.*) }
  .rel.ctors      : { *(.rel.ctors) }
  .rela.ctors     : { *(.rela.ctors) }
  .rel.dtors      : { *(.rel.dtors) }
  .rela.dtors     : { *(.rela.dtors) }
  .rel.got        : { *(.rel.got) }
  .rela.got       : { *(.rela.got) }
  .rel.bss        : { *(.rel.bss .rel.bss.* .rel.gnu.linkonce.b.*) }
  .rela.bss       : { *(.rela.bss .rela.bss.* .rela.gnu.linkonce.b.*) }
  .rel.iplt       :
    {
      PROVIDE_HIDDEN (__rel_iplt_start = .);
      *(.rel.iplt)
      PROVIDE_HIDDEN (__rel_iplt_end = .);
    }
  .rela.iplt      :
    {
      PROVIDE_HIDDEN (__rela_iplt_start = .);
      *(.rela.iplt)
      PROVIDE_HIDDEN (__rela_iplt_end = .);
    }
  .rel.plt        :
    {
      *(.rel.plt)
    }
  .rela.plt       :
    {
      *(.rela.plt)
    }
  .plt            : { *(.plt) }
  .iplt           : { *(.iplt) }
  .vectors        :
  {
    . = ALIGN(32 / 8);
    _sfixed = .;
    KEEP(*(.vectors .vectors.*))
  } >rom
  .text           :
  {
    . = ALIGN(32 / 8);
  *(.glue_7t) *(.glue_7)
  *(.rodata .rodata* .gnu.linkonce.r.*)
  *(.ARM.extab* .gnu.linkonce.armextab.*)
    . = ALIGN(32 / 8);
    KEEP (*(SORT_NONE(.init)))
    . = ALIGN(32 / 8);
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);
    . = ALIGN(32 / 8);
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array))
    PROVIDE_HIDDEN (__init_array_end = .);
    . = ALIGN(32 / 8);
    /* gcc uses crtbegin.o to find the start of
       the constructors, so we make sure it is
       first.  Because this is a wildcard, it
       doesn't matter if the user does not
       actually link against crtbegin.o; the
       linker won't look for a file to match a
       wildcard.  The wildcard also means that it
       doesn't matter which directory crtbegin.o
       is in.  */
    KEEP (*crtbegin.o(.ctors))
    KEEP (*crtbegin?.o(.ctors))
    /* We don't want to include the .ctor section from
       the crtend.o file until after the sorted ctors.
       The .ctor section from the crtend file contains the
       end of ctors marker and it must be last */
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
    . = ALIGN(32 / 8);
    KEEP (*(SORT_NONE(.fini)))
    . = ALIGN(32 / 8);
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array ))
    PROVIDE_HIDDEN (__fini_array_end = .);
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
  } >rom
  .rodata         : { *(.rodata .rodata.* .gnu.linkonce.r.*) }
  .rodata1        : { *(.rodata1) } >rom
   PROVIDE (__stack_start__ = _stack);
   PROVIDE (__stack_limit__ = _splim);
   PROVIDE (__exidx_start = .);


  .ARM.exidx   : { *(.ARM.exidx* .gnu.linkonce.armexidx.*) } >rom
   PROVIDE_HIDDEN (__exidx_end = .);
  . = ALIGN(32 / 8);
  PROVIDE (__etext = .);
  PROVIDE (_etext = .);
  PROVIDE (etext = .);
  /* Adjust the address for the data segment.  We want to adjust up to
     the same address within the page on the next page up.  */
  . = ALIGN(CONSTANT (MAXPAGESIZE)) + (. & (CONSTANT (MAXPAGESIZE) - 1));
  .data.rel.ro : { *(.data.rel.ro.local* .gnu.linkonce.d.rel.ro.local.*) *(.data.rel.ro .data.rel.ro.* .gnu.linkonce.d.rel.ro.*) }
  .dynamic        : { *(.dynamic) }
  .got            : { *(.got.plt) *(.igot.plt) *(.got) *(.igot) }
  .data           :
  {
    __data_start = . ;
    *(.data .data.* .gnu.linkonce.d.*)
    SORT(CONSTRUCTORS)
  } >ram
  .data1          : { *(.data1) } >ram
  _edata = .; PROVIDE (edata = .);
  . = .;
  __bss_start = .;
  __bss_start__ = .;
  .bss            :
  {
   . = ALIGN(32 / 8);
   *(.dynbss)
   *(.bss .bss.* .gnu.linkonce.b.*)
   *(COMMON)
   /* Align here to ensure that the .bss section occupies space up to
      _end.  Align after .bss to ensure correct alignment even if the
      .bss section disappears because there are no input sections.
      FIXME: Why do we need it? When there is no .bss section, we don't
      pad the .data section.  */
   . = ALIGN(. != 0 ? 32 / 8 : 1);
  } >ram
  _bss_end__ = . ; __bss_end__ = . ;
  . = ALIGN(32 / 8);
  . = SEGMENT_START("ldata-segment", .);
  . = ALIGN(32 / 8);
  __end__ = . ;
  _end = .; PROVIDE (end = .);
  .gnu.attributes 0 : { KEEP (*(.gnu.attributes)) }
  /DISCARD/ : { *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) *(.gnu.warning.*) }
}
