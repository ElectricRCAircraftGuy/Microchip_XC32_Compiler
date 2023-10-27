/* Test pragma config output. Ideally these will be generated from the configuration data
   sources and specify the processor directly, but for now we use the commonality between
   devices. 
   */

/* { dg-do compile } */
/* { dg-require-effective-target xc32_32CZ_CA70_ok } */

#pragma config SECURITY_BIT = 1       /* offset 0 */
#pragma config LOCK_REGION_0 = SET    /* offset 4 */
#pragma config LOCK_REGION_1 = CLEAR  /* offset 8 */

void foo() {}

/* Each address with non-default value should appear as a type, size and label,
   of which there are two in this test. 
   */
/* { dg-final { scan-assembler-times "__config_D000000" 6 } } */
/* { dg-final { scan-assembler-times "Begin Microchip.*configuration words" 1 } } */
/* { dg-final { scan-assembler-times "End Microchip.*configuration words" 1 } } */

/* TODO: peek at settings for each word, check types and sizes. */
