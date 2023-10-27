#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "diagnostic-core.h"
#include "toplev.h"

#include "rtl.h"
#include "tree.h"
#include "tm_p.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "flags.h"
#include "insn-config.h"
#include "recog.h"
#include "basic-block.h"
#include "function.h"
#include "expr.h"
#include "except.h"
#include "params.h"
#include "cselib.h"
#include "intl.h"
#include "tree-pass.h"
#include "hashtab.h"
#include "bitmap.h"
#include "basic-block.h"
#include "df.h"
#include "dbgcnt.h"
#include "target.h"
#include "cfgloop.h"

#include "stringpool.h"
#include "attribs.h"
#include "cfg.h"

#include "gimple-pretty-print.h"

#define HI_MASK 0xFFFF0000
#ifndef BITSET_P
/* True if bit BIT is set in VALUE.  */
#define BITSET_P(VALUE, BIT) (((VALUE) & (1 << (BIT))) != 0)
#endif
#define SYM_HASH_MAXSIZE 31

/* Holds a symbol ref entry into the hashtable
 * ADDR_HI is the high half word address of SYM */
struct sym_entry
{
    rtx sym;
    unsigned int addr_hi;

    struct sym_entry *next;
};

/* Hashtable for symbols with address attribute specified */
struct sym_hash_table_d
{
  struct sym_entry **table;

  unsigned int size;

  unsigned int n_elems;
};

static struct sym_hash_table_d sym_hash;


/* Extract HI half word of an address */
static unsigned int
extract_hi(long unsigned int addr)
{
    unsigned int hi;
    
    hi = (addr & HI_MASK) >> 16;
    /* Test if most significant bit from lo half word is set. If so,
     increment hi half word because this is how the hi addr is resolved 
     by the assembler in this case */
    if (BITSET_P (addr, 15))
        hi++;

    return hi;
}

/* Returns tree of the address attribute of a symbol decl */
static tree
get_mchp_absolute_address (tree decl)
{
    if (decl == NULL)
        return NULL_TREE;

    tree retval;
    retval = lookup_attribute ("address", DECL_ATTRIBUTES (decl));

    return retval;
}

/* Allocates heap for the hashtable */
static void
alloc_sym_hash_table (struct sym_hash_table_d *table)
{
    /* TODO change this to more robustly computed size */
    table->size = SYM_HASH_MAXSIZE;
    table->n_elems = 0;
    table->table = XNEWVAR (struct sym_entry *, table->size * sizeof(struct sym_entry *));
    memset (table->table, 0, table->size * sizeof(struct sym_entry *));
}

static void
free_sym_hash_table (struct sym_hash_table_d *table)
{
    struct sym_entry *e, *curr_e;
    unsigned int i;

    gcc_assert(table);
    gcc_assert(table->table);

    for (i = 0; i < table->size; i++) {
        for (e = table->table[i]; e;) {
            curr_e = e;
            e = e->next;
            free(curr_e);
        }
    }
    
    free (table->table);
}

/* Computes hash for a given hi address and hashtable size */
static unsigned int
mchp_hash_set (unsigned int addr_hi, unsigned int hash_table_size)
{
    return addr_hi % hash_table_size;
}

/* Searches TABLE for a symbol with the same HI addr */
static rtx
find_sym_base (unsigned int sym_addr_hi, struct sym_hash_table_d *table)
{
    unsigned int hash;
    struct sym_entry *e;

    gcc_assert(table);

    hash = mchp_hash_set (sym_addr_hi, table->size);

    for (e = table->table[hash]; e; e = e->next)
    {
        if (sym_addr_hi == e->addr_hi)
        {
            return e->sym;
        }
    }

    return NULL;
}

/* Inserts new entry into TABLE */
static void
insert_sym_in_hash (rtx new_sym, unsigned int new_sym_addr_hi,
    struct sym_hash_table_d *table)
{
    unsigned int hash;
    struct sym_entry *e;
    rtx found;

    gcc_assert(new_sym);
    gcc_assert(table);

    /* Check if already in the hashtable */
    found = find_sym_base (new_sym_addr_hi, table);
    if (found != NULL)
        return;

    hash = mchp_hash_set (new_sym_addr_hi, table->size);
    
    /* Create new entry and insert in table */
    e = (struct sym_entry *)xmalloc (sizeof(struct sym_entry));
    e->sym = new_sym;
    e->addr_hi = new_sym_addr_hi;
    e->next = table->table[hash];
    table->table[hash] = e;
    table->n_elems++;
}

/* Replaces FROM with TO in INSN */
static void
replace_sym (rtx from, rtx to, rtx insn)
{
    rtx new_src;
    rtx p;

    p = NULL;

    if (!INSN_P(insn))
        return;

    p = PATTERN(insn);
    if (GET_CODE(p) != SET)
        return;

    new_src = simplify_replace_rtx(SET_SRC(p), from, to);
    if (new_src)
    {
        validate_change (insn, &SET_SRC(p), new_src, false);
    }
}

/* Pass implementation */ 
static void
hi_addr_analyze (void)
{
    basic_block bb;
    rtx_insn *insn = NULL;

    alloc_sym_hash_table (&sym_hash);

    FOR_EACH_BB_FN (bb, cfun)
    {
      FOR_BB_INSNS (bb, insn)
      {
         if (!INSN_P (insn))
            continue;

         rtx p = PATTERN (insn);
         if (p == NULL)
            continue;

         /* Check only SET insns */
         if (GET_CODE (p) != SET)
            continue;

         rtx dest = SET_DEST (p);
         rtx src = SET_SRC (p);

         if (dest == NULL || src == NULL)
            continue;

         /* Check if source is HI addr of a symbol */
         if (REG_P (dest) && GET_CODE (src) == HIGH)
         {
            rtx hi_op = XEXP (src, 0);
            if (hi_op == NULL)
                continue;

            if (GET_CODE (hi_op) == SYMBOL_REF)
            {
                tree sym_decl = SYMBOL_REF_DECL (hi_op);

                if (sym_decl == NULL)
                    continue;
                
                tree addr_tree = get_mchp_absolute_address (sym_decl);

                /* If address attribute is specified, we know what the address
                of the symbol is and can check if we can optimize its access */
                if (addr_tree != NULL)
                {
                    unsigned int addr_hi = extract_hi ((long unsigned int)TREE_INT_CST_LOW (TREE_VALUE (TREE_VALUE (addr_tree))));

                    /* Search for a symbol with the same HI addr */
                    rtx sym_base = find_sym_base (addr_hi, &sym_hash);

                    if (sym_base != NULL)
                    {
                        /* If found replace sym ref with the base sym */
                        replace_sym (hi_op, sym_base, insn);
                    }
                    else
                    {
                        /* The current symbol ref will be the base sym
                        for this HI addr */
                        insert_sym_in_hash (hi_op, addr_hi, &sym_hash);
                    }
                }
            }
         }
      }
    }
    free_sym_hash_table (&sym_hash);
}

static bool
gate_hi_addr (void)
{
  return (!TARGET_MCHP_DISABLE_HI_ADDR_OPT && optimize > 1);
}

static unsigned int
execute_hi_addr_analysis (void)
{
  hi_addr_analyze ();

  return 0;
}

namespace {

const pass_data pass_data_mchp_hi_addr_analysis =
{
  RTL_PASS,                 /* type */
  "mchp_hi_addr_analysis",  /* name */
  OPTGROUP_NONE,            /* optinfo_flags */
  TV_NONE,                  /* tv_id */
  0,                        /* properties_required */
  0,                        /* properties_provided */
  0,                        /* properties_destroyed */
  0,                        /* todo_flags_start */
  0                         /* todo_flags_finish */
};

class pass_mchp_hi_addr_analysis : public rtl_opt_pass {
public:
  pass_mchp_hi_addr_analysis (gcc::context *ctxt): rtl_opt_pass (pass_data_mchp_hi_addr_analysis, ctxt) {}
  virtual bool gate (function *) { return gate_hi_addr (); }
  virtual unsigned int execute (function *) { return execute_hi_addr_analysis (); }
};

} /* anon namespace */

rtl_opt_pass *
make_pass_rtl_mchp_hi_addr_analysis (gcc::context *ctxt)
{
  return new pass_mchp_hi_addr_analysis (ctxt);
}
