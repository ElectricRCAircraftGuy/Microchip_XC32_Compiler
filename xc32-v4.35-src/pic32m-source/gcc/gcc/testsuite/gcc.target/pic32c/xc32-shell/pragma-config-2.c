/* Test pragma config error/warning messages for fixed data file. */
/* { dg-do compile } */
/* { dg-require-effective-target xc32_32CZ_CA70_ok } */
#pragma config /* { dg-error "configuration setting name expected in configuration pragma" } */
#pragma config BADVALUE /* { dg-error "'=' expected in configuration pragma" } */
#pragma config SECURITY_BIT = /* { dg-error "config-setting value must be a name or a constant integer" } */
#pragma config SECURITY_BIT = BADVALUE /* { dg-error "unknown value for configuration setting 'SECURITY_BIT': 'BADVALUE'" } */
#pragma config BADVALUE = 0x1 /* { dg-error "unknown configuration setting: 'BADVALUE'" } */
#pragma config SECURITY_BIT = 127 /* { dg-warning "Configuration value 0x7f masked to 0x1 for setting 'SECURITY_BIT'" } */
#pragma config SECURITY_BIT = 1 /* { dg-error "multiple definitions for configuration setting 'SECURITY_BIT'" } */
#pragma config TCM_CONFIGURATION = 0x2
#pragma config LOCK_REGION_0 = SET
#pragma config LOCK_REGION_1 = CLEAR
