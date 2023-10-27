/* Test rejection of negative forms for mchp options */
/* { dg-do compile } */
/* { dg-options "-mno-print-builtins -mno-print-mchp-search-dirs -mno-no-fallback" } */
/* { dg-error "-mno-print-builtins" "" { target *-*-* } 0 } */
/* { dg-error "-mno-print-mchp-search-dirs" "" { target *-*-* } 0 } */
/* { dg-error "-mno-no-fallback" "" { target *-*-* } 0 } */
