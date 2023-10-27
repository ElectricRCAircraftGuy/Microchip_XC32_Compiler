/* Test space attribute error/warning messages. */
/* { dg-do compile } */

int i1 __attribute__((space(prog)));
int i2 __attribute__((space(data)));

/* { dg-error "wrong number of arguments specified for 'space' attribute" "" { target *-*-* } 8 } */
int i3 __attribute__((space));

/* { dg-error "'data' undeclared here" "" { target *-*-* } 12 } */
/* { dg-error "wrong number of arguments specified for 'space' attribute" "" { target *-*-* } 12 } */
int i4 __attribute__((space(prog,data)));

/* { dg-error "'prog' undeclared here" "" { target *-*-* } 16 } */
/* { dg-error "wrong number of arguments specified for 'space' attribute" "" { target *-*-* } 16 } */
int i5 __attribute__((space(data,prog)));

__attribute__((space(data))) int foo_data_fn1(int a) {
	return a * 2;
}


/* { dg-error "wrong number of arguments specified for 'space' attribute" "" { target *-*-* } 24 } */
__attribute__((space(data,prog))) int foo_data_fn2(int a) { 
	return a * 2;
}
