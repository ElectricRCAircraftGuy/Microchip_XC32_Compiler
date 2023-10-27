/* Test address attribute error/warning messages. */
/* { dg-do compile } */

/* { dg-error "wrong number of arguments specified for 'address' attribute" "" { target *-*-* } 5 } */
int i1 __attribute__((address));

/* { dg-warning "invalid address argument" "" { target *-*-* } 10 }  */
/* { dg-warning "unaligned addresses are not yet permitted" "" { target *-*-* } 10 } */
/* { dg-error "is outside of the 32-bit address range" "" { target *-*-* } 10 } */
int i2 __attribute__((address(-1)));

