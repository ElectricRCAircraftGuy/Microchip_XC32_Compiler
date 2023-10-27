MACHINE=
SCRIPT_NAME=elf32pic32c
OUTPUT_FORMAT="elf32-littlearm"
BIG_OUTPUT_FORMAT="elf32-bigarm"
LITTLE_OUTPUT_FORMAT="elf32-littlearm"
TEMPLATE_NAME=elf32
EXTRA_EM_FILE=elf32pic32c

ENABLE_INITFINI_ARRAY=no
ENABLE_TCM=yes

TEXT_REGION=rom
DATA_REGION=ram

# MERGE_NOTES: these values are 'defaults' set for initial SAMV71 work. 
# we should revisit what the 'default' script should look like.
TEXT_START_ADDR="0x400000"
DATA_START_ADDR="0x20400000"
TEXT_LENGTH="0x200000"
DATA_LENGTH="0x60000"
TEXT_TCM_START_ADDR="0x0"
TEXT_TCM_LENGTH="0"
DATA_TCM_START_ADDR="0x20000000"
DATA_TCM_LENGTH="0"

TEXT_START_SYMBOLS="_sfixed = .;"
OTHER_TEXT_SECTIONS="
  *(.glue_7t) *(.glue_7)
  *(.rodata ${RELOCATING+.rodata* .gnu.linkonce.r.*})
  *(.ARM.extab${RELOCATING+* .gnu.linkonce.armextab.*})"

OTHER_BSS_SYMBOLS='__bss_start__ = .;'
OTHER_BSS_END_SYMBOLS='_bss_end__ = . ; __bss_end__ = . ;'
OTHER_END_SYMBOLS='__end__ = . ;'

OTHER_READONLY_SECTIONS="
  ${RELOCATING+ PROVIDE_HIDDEN (__exidx_start = .); }
  .ARM.exidx ${RELOCATING-0} : { *(.ARM.exidx${RELOCATING+* .gnu.linkonce.armexidx.*}) } >${TEXT_REGION}
  ${RELOCATING+ PROVIDE_HIDDEN (__exidx_end = .); }"

#OTHER_SECTIONS='.note.gnu.arm.ident 0 : { KEEP (*(.note.gnu.arm.ident)) }'
#ATTRS_SECTIONS='.ARM.attributes 0 : { KEEP (*(.ARM.attributes)) KEEP (*(.gnu.attributes)) }'

DATA_START_SYMBOLS='__data_start = . ;';

GENERATE_SHLIB_SCRIPT=yes

ARCH=arm
MACHINE=
MAXPAGESIZE="CONSTANT (MAXPAGESIZE)"
ENTRY=_start
EMBEDDED=yes

# ARM does not support .s* sections.
NO_SMALL_DATA=yes
