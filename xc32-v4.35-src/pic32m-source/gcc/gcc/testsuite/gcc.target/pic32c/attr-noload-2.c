/* Test the noload attribute (errors/warnings). */
/* { dg-do compile } */
/* { dg-additional-options "-Wattributes" } */

/* { dg-error "wrong number of arguments specified for 'noload' attribute" "" { target *-*-* } 6 } */
int i __attribute__((noload(0)));

/* { dg-warning "ignoring noload attribute applied to automatic i" "" { target *-*-* } 9 } */
void f (void) { int i __attribute__ ((noload)); }

/* { dg-warning "ignoring noload attribute applied to parameter x" "" { target *-*-* } 12 } */
void g (__attribute__ ((noload)) int x) { }

/* { dg-warning "ignoring noload attribute applied to member i" "" { target *-*-* } 15 } */
struct S { int i __attribute__ ((noload)); };

/* { dg-warning "Noload variable 'j' will not be initialized" "" { target *-*-*} 18 } */
__attribute__((noload)) int j = 42;
