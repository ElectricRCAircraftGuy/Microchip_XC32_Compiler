/* Test the unique_section attribute (errors/warnings). */
/* { dg-do compile } */
/* { dg-options "-Wall" */

/* { dg-error "wrong number of arguments specified for 'unique_section' attribute" "" { target *-*-* } 6 } */
int i __attribute__((unique_section(0)));

/* { dg-error "'unique_section' attribute cannot be specified for local variable 'i'" "" { target *-*-* } 9 } */
void f (void) { int i __attribute__ ((unique_section)); }

/* { dg-error "'unique_section' attribute not allowed for 'x'" "" { target *-*-* } 12 } */
void g (__attribute__ ((unique_section)) int x) { }

/* { dg-error "'unique_section' attribute not allowed for 'i'" "" { target *-*-* } 15 } */
struct S { int i __attribute__ ((unique_section)); };
