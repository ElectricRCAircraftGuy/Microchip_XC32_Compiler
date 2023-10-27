/*********************************************************************
 *
 *              Macros for function and variable attributes
 *
 *********************************************************************
 * Filename:        sys/attribs.h
 *
 * Processor:       PIC32C/PIC32M
 *
 * Compiler:        MPLAB XC32
 *
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * Copyright (c) 2017, Microchip Technology Inc. and its subsidiaries ("Microchip")
 * All rights reserved.
 *
 * This software is developed by Microchip Technology Inc. and its
 * subsidiaries ("Microchip").
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1.      Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * 2.      Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * 3.      Microchip's name may not be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *-------------------------------------------------------------------------*/

#pragma once
#ifndef __ATTRIBS_H
#define __ATTRIBS_H

/*****************************************************************************
 * The following macro -- __section__ -- is used to specify a named section
 * for the attributed object. The object will be placed into that section.
 *
 * Example:
 *   int __section__(".fred") foo (void) { return bar; }
 * This creates a function named foo that will be placed into section
 * ".fred"
 *****************************************************************************/
#define __section__(n) __attribute__ ((section (n)))

/*****************************************************************************
 * The following macro -- __unique_section__ -- is used to specify that the
 * section name for the attributed object should be unique, just as if
 * the command line option -ffunction-sections or -fdata-sections had been
 * specified. In addition, if a "section" attribute is also present, the name
 * of the section will be used as the prefix for the unique section name
 * generated.
 *
 * Example:
 *   int __unique_section__ foo (void) { return bar; }
 * Function "foo" will be placed into a uniquely named text section just
 * as if the translation unit were compiled with -ffunction-sections.
 *****************************************************************************/
#define __unique_section__ __attribute__ ((unique_section))

#ifdef __mips__

/*****************************************************************************
 * The following macro -- __ramfunc__ -- is used to specify a function that
 * will execute from data memory.  This function may be called from other
 * functions located within data memory.
 *
 * Example:
 *   int __ramfunc__ foo (void);
 *   int __ramfunc__ foo (void) { return bar; }
 * This creates a function named foo that will execute from data memory.
 * This function may be called from other functions located within data
 * memory.
 *****************************************************************************/
#if (__C32_VERSION__ < 200)
#define __ramfunc__ __attribute__ ((section(".ramfunc"), unique_section,noinline))
#else
#define __ramfunc__ __attribute__ ((ramfunc,section(".ramfunc"),unique_section,noinline))
#endif

/*****************************************************************************
 * The following macro -- __longramfunc__ -- is used to specify a function
 * that will execute from data memory.  This function may be called by
 * functions located in either program or data memory.
 *
 * Example:
 *   int __longramfunc__ foo (void);
 *   int __longramfunc__ foo (void) { return bar; }
 * This creates a function named foo that will execute from data memory.
 * This function may be called from other functions located in either program
 * or data memory.
 *****************************************************************************/
#if (__C32_VERSION__ < 200)
#if !defined(far)
#define __longramfunc__ __attribute__ ((section(".ramfunc"), far,\
                                        unique_section,noinline))
#elif !defined(longcall)
#define __longramfunc__ __attribute__ ((section(".ramfunc"), longcall,\
                                        unique_section,noinline))
#elif !defined(long_call)
#define __longramfunc__ __attribute__ ((section(".ramfunc"), long_call,\
                                        unique_section,noinline))
#else
#error Cannot use __longramfunc__ macro because 'far', 'longcall', & 'long_call' are defined
#endif

#else /* __C32_VERSION__ */
#if !defined(far)
#define __longramfunc__ __attribute__ ((ramfunc,section(".ramfunc"),far,\
                                        unique_section,noinline))
#elif !defined(longcall)
#define __longramfunc__ __attribute__ ((ramfunc,section(".ramfunc"),longcall,\
                                        unique_section,noinline))
#elif !defined(long_call)
#define __longramfunc__ __attribute__ ((ramfunc,section(".ramfunc"),long_call,\
                                        unique_section,noinline))
#else
#error Cannot use __longramfunc__ macro because 'far', 'longcall', & 'long_call' are defined
#endif

#endif /* __C32_VERSION__ */

/*****************************************************************************
 * The following macro -- __longcall__ -- is used to specify a function
 * that will always be called by first loading its address into a register,
 * and then using the contents of that register.
 *
 * Example:
 *   int __longcall__ foo (void);
 *   int __longcall__ foo (void) { return bar; }
 * This creates a function named foo that will be called by first loading
 * its address into a registerm and then using the contents of that register.
 *****************************************************************************/
#define __longcall__ __attribute__ ((far))

/*****************************************************************************
 * The following macro -- __ISR(v, ipl) -- is used to assign the vector
 * number location and associate it with the software assigned interrupt
 * priority.  This will place a jump to the interrupt handler at the
 * associated vector location.
 *
 * Example:
 *   void __ISR(_CORE_TIMER_VECTOR, ipl2) CoreTimerHandler(void);
 * This creates an interrupt handler function for the core timer interrupt
 * that has an interrupt priority level of two.  To reach this function the
 * core timer interrupt flag and enable bits must be set, and the interrupt
 * priority should be set to a level of two.
 *****************************************************************************/
#if !defined(__STRICT_ANSI__)
#define __ISR(v,...) __attribute__((vector(v), interrupt(__VA_ARGS__), nomips16))
#else
#define __ISR(v,ipl) __attribute__((vector(v), interrupt(ipl), nomips16))
#endif

/*****************************************************************************
 * The following macro -- __ISR_AT_VECTOR(v, ipl) -- is used to place the
 * entire interrupt handler at the vector location and associate it with the
 * software assigned interrupt priority. The user is responsible for making
 * sure that the vector spacing is set to accomodate the size of the handler.
 *
 * Example:
 *   void __ISR_AT_VECTOR(_CORE_TIMER_VECTOR, ipl2) CoreTimerHandler(void);
 * This creates an interrupt handler function for the core timer interrupt
 * that has an interrupt priority level of two.  To reach this function the
 * core timer interrupt flag and enable bits must be set, and the interrupt
 * priority should be set to a level of two.
 *****************************************************************************/
#if !defined(__STRICT_ANSI__)
#define __ISR_AT_VECTOR(v,...) __attribute__((at_vector(v), interrupt(__VA_ARGS__), nomips16))
#else
#define __ISR_AT_VECTOR(v,ipl) __attribute__((at_vector(v), interrupt(ipl), nomips16))
#endif

/*****************************************************************************
 * The following macro -- __ISR_SINGLE__ -- is used to specify a function as
 * an interrupt-service routine in single-vector mode. This will place a jump
 * at the single-vector location to the interrupt handler.
 *
 * Example:
 *   void __ISR_SINGLE__ ISRHandler(void);
 * This places a jump at the single-vector address to the ISRHandler()
 * interrupt-service function. To reach this function, the interrupt
 * controller must be configured for Single Vector mode and an interrupt flag
 * for an enabled interrupt must be set.
 *****************************************************************************/
#define __ISR_SINGLE__ __attribute__((interrupt(single),vector(0),nomips16))
#define __ISR_SINGLE() __ISR_SINGLE__

/*****************************************************************************
 * The following macro -- __ISR_SINGLE_AT_VECTOR__ -- is used to place the
 * entire single-vector interrupt handler at the vector 0 location. The user
 * is responsible for ensuring that the vector spacing is set to accommodate
 * the size of the handler.
 *
 * Example:
 *   void __ISR_SINGLE_AT_VECTOR__ ISRHandler(void);
 * This creates a single-vector mode interrupt handler function located at
 * vector 0. To reach this function, the interrupt controller must be
 * configured for Single Vector mode and an interrupt flag for an enabled
 * interrupt must be set.
 *****************************************************************************/
#define __ISR_SINGLE_AT_VECTOR__ __attribute__((interrupt(single),\
                                                at_vector(0), nomips16))
#define __ISR_SINGLE_AT_VECTOR() __ISR_SINGLE_AT_VECTOR__

#else /* !__mips__ */

/*****************************************************************************
 * The following macro -- __ramfunc__ -- is used to specify a function that
 * will execute from data memory.  This function may be called from other
 * functions located within data memory.
 *
 * Example:
 *   int __ramfunc__ foo (void);
 *   int __ramfunc__ foo (void) { return bar; }
 * This creates a function named foo that will execute from data memory.
 * This function may be called from other functions located within data
 * memory.
 *****************************************************************************/
#if (__C32_VERSION__ < 200)
#define __ramfunc__ __attribute__ ((section(".ramfunc"),unique_section,noinline))
#else
#define __ramfunc__ __attribute__ ((ramfunc,section(".ramfunc"),unique_section,noinline))
#endif

/*****************************************************************************
 * The following macro -- __longramfunc__ -- is used to specify a function
 * that will execute from data memory.  This function may be called by
 * functions located in either program or data memory.
 *
 * Example:
 *   int __longramfunc__ foo (void);
 *   int __longramfunc__ foo (void) { return bar; }
 * This creates a function named foo that will execute from data memory.
 * This function may be called from other functions located in either program
 * or data memory.
 *****************************************************************************/
#if (__C32_VERSION__ < 200)
#if !defined(long_call)
#define __longramfunc__ __attribute__ ((section(".ramfunc"), long_call,\
                                        unique_section,noinline))
#else
#error Cannot use __longramfunc__ macro because 'long_call' is defined
#endif

#else /* __C32_VERSION__ */
#if !defined(long_call)
#define __longramfunc__ __attribute__ ((ramfunc,section(".ramfunc"),long_call,\
                                        unique_section,noinline))
#else
#error Cannot use __longramfunc__ macro 'long_call' is defined
#endif

#endif /* __C32_VERSION__ */

#endif /* __mips__ */
#endif /* __ATTRIBS_H */

