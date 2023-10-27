/* pic32-stack-usage.h - Contributed by Microchip Corporation.
 * Written by Cosmin-Gabriel Samoila.
 */
#ifndef _PIC32_STACK_USAGE_H
#define _PIC32_STACK_USAGE_H

/* Section names for stack usage */
#define SU_SECTION              ".xc_stack_usage"
#define SU_SECTION_HDR          ".xc_stack_usage.hdr"
#define SU_VERSION              1

#define SU_INFO_HDR_SIZE        0xE

/* Stack Usage kind:
    - 0 (static)
    - 1 (dynamic,unbounded)
    - 2 (dynamic,bounded)
*/
#define SU_STATIC_T             0x0
#define SU_DYNAMIC_UNBOUNDED_T  0x1
#define SU_DYNAMIC_BOUNDED_T    0x2

/* Flags used per function */
#define SU_INDIRECT_CALLS       (1 << 0)
#define SU_INLINE_ASM           (1 << 1)
#define SU_MISSING_INFO         (1 << 2)
#define SU_INACCURATE           (1 << 3)
#define SU_INTERRUPT            (1 << 4)
#define SU_DISJOINT_FUNC        (1 << 5)
#define SU_UNINTERRUPTIBLE      (1 << 6)
#define SU_RECURSIVE            (1 << 7)
#define SU_ENTRY_FUNC           (1 << 8)

#define SU_NUM_FLAGS            9

/* Interrupt Priority Level - bits 24-31 */
#define SU_SET_IPL(flags, val)   ((flags) = (flags & ~(0xFF << 24)) | (((val) & 0xFF) << 24))
#define SU_GET_IPL(flags)        (((flags) >> 24) & 0xFF)

#ifndef IN_GCC

/* internal/private function flags
 * (used during the SU processing in the linker w/o any public meaning);
 * note that these are defined also as bits in the 'flags' field
 * starting with bit SU_NUM_FLAGS and can share the same bit if not needed
 * simultaneously */
#define SU_PROCESSED_NODE       (1 << (SU_NUM_FLAGS+0))
#define SU_EXPANDED_NODE        (1 << (SU_NUM_FLAGS+1))
#define SU_DISCARDED_NODE       (1 << (SU_NUM_FLAGS+2))

/* Stack Usage linker specific structures and API */
struct su_section *su_sections;
struct su_section **su_sections_arr;
unsigned int max_name_length;
unsigned int num_functions;

struct vec_type;

/* linked list to keep the stack usage section for each function */
struct su_section {
  uint32_t          faddr;        /* function address */
  char              *fname;       /* function name */
  struct vec_type   *aliases;     /* other possible names for this function */
  uint32_t          used_stack;   /* total used stack by this function */
  uint32_t          max_stack;    /* max stack usage in the subgraph having this node root */
  uint32_t          flags;        /* flags for this section */
  uint8_t           used_mem_type;/* type of memory used by this function */
  bfd               *the_bfd;     /* pointer to the bfd associated with this */
  struct su_section **callees;    /* list of callees */
  uint32_t          nb_callees;   /* number of callees */
  uint32_t          max_callees;  /* crt allocated slots for callees */
  struct su_section *next;
};

extern void add_su_sections_from_bfd(bfd *);
extern void free_su_sections(void);
extern void print_su_sections(void);
extern void pic32_print_su_report(FILE *);
extern struct su_section* add_su_section_node(bfd *, const char *,
                                uint32_t, uint32_t,
                                uint8_t, uint32_t);
struct su_section* get_function_by_name_bfd(const char *fname, bfd *abfd);
extern struct su_section* get_first_unprocessed_su_section(void);
extern void su_allocate_array(void);
extern intptr_t map_over_su_sections(intptr_t (*)(struct su_section *, void *), void *);
uint32_t value32_to_host (const bfd *, const uint32_t);

extern bfd_boolean pic32_pa_enabled (void);

/**
* 	structure to keep current call-stack layout
*	this one is part of the stack usage feature
*	the first role is to determine any type of recursivity
*	it can be used for others as well 
*		- print the max stack usage
*		- print any/all path starting from one node 
*/
typedef struct su_callstack
{
  int               max_size;
  int               top;
  struct su_section **calls;
} su_callstack;

su_callstack* 	su_cstack_new(void);
int su_cstack_get_size(su_callstack *stack_ptr);
int su_cstack_is_empty(su_callstack *stack_ptr);
int su_cstack_is_full(su_callstack *stack_ptr);
void su_cstack_push(su_callstack *stack_ptr, struct su_section* call);
int su_cstack_is_on_stack(su_callstack *stack_ptr, struct su_section* const call);
struct su_section* su_cstack_check_top(su_callstack *stack_ptr);
struct su_section* su_cstack_pop(su_callstack *stack_ptr);
void su_cstack_free(su_callstack *stack_ptr);

void mark_as_recursive(su_callstack *stack_ptr, struct su_section *func);

void su_note_smartio_replacement (const char *from, const char *to);

#define PIC32_DBG_PRINT(...) \
(__extension__ ({ \
  int __nchars = 0; \
  if (pic32_debug) __nchars = fprintf (stderr,__VA_ARGS__); \
  __nchars; \
}))

/* The 'st_value' of a Elf_Internal_Sym with the least significant bit cleared
 * (i.e. an even value / multiple of 2 bytes) */
#define ST_VALUE2(isym) ((isym)->st_value & ~(bfd_vma)1)

#endif /* IN_GCC */

#endif /*_PIC32_STACK_USAGE_H*/
