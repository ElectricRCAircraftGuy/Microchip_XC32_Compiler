/**
 * \brief Header file for PIC32CZ1038CA70144
 *
 * Copyright (c) 2017 Microchip Technology Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description version 2017-07-14T18:00:00Z */
#ifndef _PIC32CZ1038CA70144_H_
#define _PIC32CZ1038CA70144_H_

/** \addtogroup PIC32CZ1038CA70144_definitions PIC32CZ1038CA70144 definitions
  This file defines all structures and symbols for PIC32CZ1038CA70144:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
 *  @{
 */

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

#define CAST(type, value) ((type *)(value)) /**< Pointer Type Conversion Macro for C/C++ */
#define VCAST(type, value) ((volatile type *)(value)) /**< Volatile Pointer Type Conversion Macro for C/C++ */

/** \addtogroup PIC32CZ1038CA70144_cmsis CMSIS Definitions
 *  @{
 */
/* ************************************************************************** */
/*   CMSIS DEFINITIONS FOR PIC32CZ1038CA70144                                 */
/* ************************************************************************** */
/** Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-M7 Processor Exceptions Numbers ******************************/
  Reset_IRQn                = -15, /**< 1   Reset Vector, invoked on Power up and warm reset  */
  NonMaskableInt_IRQn       = -14, /**< 2   Non maskable Interrupt, cannot be stopped or preempted  */
  HardFault_IRQn            = -13, /**< 3   Hard Fault, all classes of Fault     */
  MemoryManagement_IRQn     = -12, /**< 4   Memory Management, MPU mismatch, including Access Violation and No Match  */
  BusFault_IRQn             = -11, /**< 5   Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault  */
  UsageFault_IRQn           = -10, /**< 6   Usage Fault, i.e. Undef Instruction, Illegal State Transition  */
  SVCall_IRQn               = -5 , /**< 11  System Service Call via SVC instruction  */
  DebugMonitor_IRQn         = -4 , /**< 12  Debug Monitor                        */
  PendSV_IRQn               = -2 , /**< 14  Pendable request for system service  */
  SysTick_IRQn              = -1 , /**< 15  System Tick Timer                    */
/******  PIC32CZ1038CA70144 specific Interrupt Numbers ***********************************/
  SUPC_IRQn                 = 0  , /**< 0   Supply Controller (SUPC)            */
  RSTC_IRQn                 = 1  , /**< 1   Reset Controller (RSTC)             */
  RTC_IRQn                  = 2  , /**< 2   Real-time Clock (RTC)               */
  RTT_IRQn                  = 3  , /**< 3   Real-time Timer (RTT)               */
  WDT_IRQn                  = 4  , /**< 4   Watchdog Timer (WDT)                */
  PMC_IRQn                  = 5  , /**< 5   Power Management Controller (PMC)   */
  EFC_IRQn                  = 6  , /**< 6   Embedded Flash Controller (EFC)     */
  UART0_IRQn                = 7  , /**< 7   Universal Asynchronous Receiver Transmitter (UART0) */
  UART1_IRQn                = 8  , /**< 8   Universal Asynchronous Receiver Transmitter (UART1) */
  PORTA_IRQn                = 10 , /**< 10  Port (PORTA)                        */
  PORTB_IRQn                = 11 , /**< 11  Port (PORTB)                        */
  PORTC_IRQn                = 12 , /**< 12  Port (PORTC)                        */
  USART0_IRQn               = 13 , /**< 13  Universal Synchronous Asynchronous Receiver Transmitter (USART0) */
  USART1_IRQn               = 14 , /**< 14  Universal Synchronous Asynchronous Receiver Transmitter (USART1) */
  USART2_IRQn               = 15 , /**< 15  Universal Synchronous Asynchronous Receiver Transmitter (USART2) */
  PORTD_IRQn                = 16 , /**< 16  Port (PORTD)                        */
  PORTE_IRQn                = 17 , /**< 17  Port (PORTE)                        */
  HSMCI_IRQn                = 18 , /**< 18  High Speed MultiMedia Card Interface (HSMCI) */
  TWI0_IRQn                 = 19 , /**< 19  Two-wire Interface (TWI0)           */
  TWI1_IRQn                 = 20 , /**< 20  Two-wire Interface (TWI1)           */
  SPI0_IRQn                 = 21 , /**< 21  Serial Peripheral Interface (SPI0)  */
  SSC_IRQn                  = 22 , /**< 22  Synchronous Serial Controller (SSC) */
  TC0_CH0_IRQn              = 23 , /**< 23  Timer/Counter 0 Channel 0 (TC0)     */
  TC0_CH1_IRQn              = 24 , /**< 24  Timer/Counter 0 Channel 1 (TC0)     */
  TC0_CH2_IRQn              = 25 , /**< 25  Timer/Counter 0 Channel 2 (TC0)     */
  TC1_CH0_IRQn              = 26 , /**< 26  Timer/Counter 1 Channel 0 (TC1)     */
  TC1_CH1_IRQn              = 27 , /**< 27  Timer/Counter 1 Channel 1 (TC1)     */
  TC1_CH2_IRQn              = 28 , /**< 28  Timer/Counter 1 Channel 2 (TC1)     */
  AFEC0_IRQn                = 29 , /**< 29  Analog Front-End Controller (AFEC0) */
  DACC_IRQn                 = 30 , /**< 30  Digital-to-Analog Converter Controller (DACC) */
  PWMC0_IRQn                = 31 , /**< 31  Pulse Width Modulation Controller (PWMC0) */
  ICM_IRQn                  = 32 , /**< 32  Integrity Check Monitor (ICM)       */
  ACC_IRQn                  = 33 , /**< 33  Analog Comparator Controller (ACC)  */
  USBHS_IRQn                = 34 , /**< 34  USB High-Speed Interface (USBHS)    */
  MCAN0_IRQn                = 35 , /**< 35  Controller Area Network (MCAN0)     */
  MCAN1_IRQn                = 37 , /**< 37  Controller Area Network (MCAN1)     */
  GMAC_IRQn                 = 39 , /**< 39  Gigabit Ethernet MAC (GMAC)         */
  AFEC1_IRQn                = 40 , /**< 40  Analog Front-End Controller (AFEC1) */
  TWI2_IRQn                 = 41 , /**< 41  Two-wire Interface (TWI2)           */
  SPI1_IRQn                 = 42 , /**< 42  Serial Peripheral Interface (SPI1)  */
  QSPI_IRQn                 = 43 , /**< 43  Quad Serial Peripheral Interface (QSPI) */
  UART2_IRQn                = 44 , /**< 44  Universal Asynchronous Receiver Transmitter (UART2) */
  UART3_IRQn                = 45 , /**< 45  Universal Asynchronous Receiver Transmitter (UART3) */
  UART4_IRQn                = 46 , /**< 46  Universal Asynchronous Receiver Transmitter (UART4) */
  TC2_CH0_IRQn              = 47 , /**< 47  Timer/Counter 2 Channel 0 (TC2)     */
  TC2_CH1_IRQn              = 48 , /**< 48  Timer/Counter 2 Channel 1 (TC2)     */
  TC2_CH2_IRQn              = 49 , /**< 49  Timer/Counter 2 Channel 2 (TC2)     */
  TC3_CH0_IRQn              = 50 , /**< 50  Timer/Counter 3 Channel 0 (TC3)     */
  TC3_CH1_IRQn              = 51 , /**< 51  Timer/Counter 3 Channel 1 (TC3)     */
  TC3_CH2_IRQn              = 52 , /**< 52  Timer/Counter 3 Channel 2 (TC3)     */
  MLB_IRQn                  = 53 , /**< 53  MediaLB (MLB)                       */
  AES_IRQn                  = 56 , /**< 56  Advanced Encryption Standard (AES)  */
  TRNG_IRQn                 = 57 , /**< 57  True Random Number Generator (TRNG) */
  XDMAC_IRQn                = 58 , /**< 58  Extensible DMA Controller (XDMAC)   */
  ISI_IRQn                  = 59 , /**< 59  Image Sensor Interface (ISI)        */
  PWMC1_IRQn                = 60 , /**< 60  Pulse Width Modulation Controller (PWMC1) */
  RSWDT_IRQn                = 63 , /**< 63  Reinforced Safety Watchdog Timer (RSWDT) */
  I2SC0_IRQn                = 69 , /**< 69  Inter-IC Sound Controller (I2SC0)   */
  I2SC1_IRQn                = 70 , /**< 70  Inter-IC Sound Controller (I2SC1)   */
  SDRAMC_IRQn               = 62 , /**< 62  SDRAM Controller (SDRAMC)           */

  PERIPH_COUNT_IRQn        = 71  /**< Number of peripheral IDs */
} IRQn_Type;

typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* Cortex-M handlers */
  void* pfnReset_Handler;                        /* -15 Reset Vector, invoked on Power up and warm reset  */
  void* pfnNonMaskableInt_Handler;               /* -14 Non maskable Interrupt, cannot be stopped or preempted  */
  void* pfnHardFault_Handler;                    /* -13 Hard Fault, all classes of Fault     */
  void* pfnMemoryManagement_Handler;             /* -12 Memory Management, MPU mismatch, including Access Violation and No Match  */
  void* pfnBusFault_Handler;                     /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault  */
  void* pfnUsageFault_Handler;                   /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition  */
  void* pvReservedC9;
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pfnSVCall_Handler;                       /*  -5 System Service Call via SVC instruction  */
  void* pfnDebugMonitor_Handler;                 /*  -4 Debug Monitor                        */
  void* pvReservedC3;
  void* pfnPendSV_Handler;                       /*  -2 Pendable request for system service  */
  void* pfnSysTick_Handler;                      /*  -1 System Tick Timer                    */

  /* Peripheral handlers */
  void* pfnSUPC_Handler;                         /*   0 Supply Controller (SUPC) */
  void* pfnRSTC_Handler;                         /*   1 Reset Controller (RSTC) */
  void* pfnRTC_Handler;                          /*   2 Real-time Clock (RTC) */
  void* pfnRTT_Handler;                          /*   3 Real-time Timer (RTT) */
  void* pfnWDT_Handler;                          /*   4 Watchdog Timer (WDT) */
  void* pfnPMC_Handler;                          /*   5 Power Management Controller (PMC) */
  void* pfnEFC_Handler;                          /*   6 Embedded Flash Controller (EFC) */
  void* pfnUART0_Handler;                        /*   7 Universal Asynchronous Receiver Transmitter (UART0) */
  void* pfnUART1_Handler;                        /*   8 Universal Asynchronous Receiver Transmitter (UART1) */
  void* pvReserved9;
  void* pfnPORTA_Handler;                        /*  10 Port (PORTA) */
  void* pfnPORTB_Handler;                        /*  11 Port (PORTB) */
  void* pfnPORTC_Handler;                        /*  12 Port (PORTC) */
  void* pfnUSART0_Handler;                       /*  13 Universal Synchronous Asynchronous Receiver Transmitter (USART0) */
  void* pfnUSART1_Handler;                       /*  14 Universal Synchronous Asynchronous Receiver Transmitter (USART1) */
  void* pfnUSART2_Handler;                       /*  15 Universal Synchronous Asynchronous Receiver Transmitter (USART2) */
  void* pfnPORTD_Handler;                        /*  16 Port (PORTD) */
  void* pfnPORTE_Handler;                        /*  17 Port (PORTE) */
  void* pfnHSMCI_Handler;                        /*  18 High Speed MultiMedia Card Interface (HSMCI) */
  void* pfnTWI0_Handler;                         /*  19 Two-wire Interface (TWI0) */
  void* pfnTWI1_Handler;                         /*  20 Two-wire Interface (TWI1) */
  void* pfnSPI0_Handler;                         /*  21 Serial Peripheral Interface (SPI0) */
  void* pfnSSC_Handler;                          /*  22 Synchronous Serial Controller (SSC) */
  void* pfnTC0_CH0_Handler;                      /*  23 Timer Counter Channel 0 (TC0) */
  void* pfnTC0_CH1_Handler;                      /*  24 Timer Counter Channel 1 (TC0) */
  void* pfnTC0_CH2_Handler;                      /*  25 Timer Counter Channel 2 (TC0) */
  void* pfnTC1_CH0_Handler;                      /*  26 Timer Counter Channel 0 (TC1) */
  void* pfnTC1_CH1_Handler;                      /*  27 Timer Counter Channel 1 (TC1) */
  void* pfnTC1_CH2_Handler;                      /*  28 Timer Counter Channel 2 (TC1) */
  void* pfnAFEC0_Handler;                        /*  29 Analog Front-End Controller (AFEC0) */
  void* pfnDACC_Handler;                         /*  30 Digital-to-Analog Converter Controller (DACC) */
  void* pfnPWMC0_Handler;                        /*  31 Pulse Width Modulation Controller (PWMC0) */
  void* pfnICM_Handler;                          /*  32 Integrity Check Monitor (ICM) */
  void* pfnACC_Handler;                          /*  33 Analog Comparator Controller (ACC) */
  void* pfnUSBHS_Handler;                        /*  34 USB High-Speed Interface (USBHS) */
  void* pfnMCAN0_Handler;                        /*  35 Controller Area Network (MCAN0) */
  void* pvReserved36;
  void* pfnMCAN1_Handler;                        /*  37 Controller Area Network (MCAN1) */
  void* pvReserved38;
  void* pfnGMAC_Handler;                         /*  39 Gigabit Ethernet MAC (GMAC) */
  void* pfnAFEC1_Handler;                        /*  40 Analog Front-End Controller (AFEC1) */
  void* pfnTWI2_Handler;                         /*  41 Two-wire Interface (TWI2) */
  void* pfnSPI1_Handler;                         /*  42 Serial Peripheral Interface (SPI1) */
  void* pfnQSPI_Handler;                         /*  43 Quad Serial Peripheral Interface (QSPI) */
  void* pfnUART2_Handler;                        /*  44 Universal Asynchronous Receiver Transmitter (UART2) */
  void* pfnUART3_Handler;                        /*  45 Universal Asynchronous Receiver Transmitter (UART3) */
  void* pfnUART4_Handler;                        /*  46 Universal Asynchronous Receiver Transmitter (UART4) */
  void* pfnTC2_CH0_Handler;                      /*  47 Timer Counter Channel 0 (TC2) */
  void* pfnTC2_CH1_Handler;                      /*  48 Timer Counter Channel 1 (TC2) */
  void* pfnTC2_CH2_Handler;                      /*  49 Timer Counter Channel 2 (TC2) */
  void* pfnTC3_CH0_Handler;                      /*  50 Timer Counter Channel 0 (TC3) */
  void* pfnTC3_CH1_Handler;                      /*  51 Timer Counter Channel 1 (TC3) */
  void* pfnTC3_CH2_Handler;                      /*  52 Timer Counter Channel 2 (TC3) */
  void* pfnMLB_Handler;                          /*  53 MediaLB (MLB) */
  void* pvReserved54;
  void* pvReserved55;
  void* pfnAES_Handler;                          /*  56 Advanced Encryption Standard (AES) */
  void* pfnTRNG_Handler;                         /*  57 True Random Number Generator (TRNG) */
  void* pfnXDMAC_Handler;                        /*  58 Extensible DMA Controller (XDMAC) */
  void* pfnISI_Handler;                          /*  59 Image Sensor Interface (ISI) */
  void* pfnPWMC1_Handler;                        /*  60 Pulse Width Modulation Controller (PWMC1) */
  void* pvReserved61;
  void* pfnSDRAMC_Handler;                       /*  62 SDRAM Controller (SDRAMC) */
  void* pfnRSWDT_Handler;                        /*  63 Reinforced Safety Watchdog Timer (RSWDT) */
  void* pvReserved64;
  void* pvReserved65;
  void* pvReserved66;
  void* pvReserved67;
  void* pvReserved68;
  void* pfnI2SC0_Handler;                        /*  69 Inter-IC Sound Controller (I2SC0) */
  void* pfnI2SC1_Handler;                        /*  70 Inter-IC Sound Controller (I2SC1) */
} DeviceVectors;

/* CORTEX-M7 exception handlers */
void Reset_Handler                 ( void );
void NonMaskableInt_Handler        ( void );
void HardFault_Handler             ( void );
void MemoryManagement_Handler      ( void );
void BusFault_Handler              ( void );
void UsageFault_Handler            ( void );
void SVCall_Handler                ( void );
void DebugMonitor_Handler          ( void );
void PendSV_Handler                ( void );
void SysTick_Handler               ( void );

/* Peripherals interrupt handlers */
void ACC_Handler                   ( void );
void AES_Handler                   ( void );
void AFEC0_Handler                 ( void );
void AFEC1_Handler                 ( void );
void DACC_Handler                  ( void );
void EFC_Handler                   ( void );
void GMAC_Handler                  ( void );
void HSMCI_Handler                 ( void );
void I2SC0_Handler                 ( void );
void I2SC1_Handler                 ( void );
void ICM_Handler                   ( void );
void ISI_Handler                   ( void );
void MCAN0_Handler                 ( void );
void MCAN1_Handler                 ( void );
void MLB_Handler                   ( void );
void PMC_Handler                   ( void );
void PORTA_Handler                 ( void );
void PORTB_Handler                 ( void );
void PORTC_Handler                 ( void );
void PORTD_Handler                 ( void );
void PORTE_Handler                 ( void );
void PWMC0_Handler                 ( void );
void PWMC1_Handler                 ( void );
void QSPI_Handler                  ( void );
void RSTC_Handler                  ( void );
void RSWDT_Handler                 ( void );
void RTC_Handler                   ( void );
void RTT_Handler                   ( void );
void SDRAMC_Handler                ( void );
void SPI0_Handler                  ( void );
void SPI1_Handler                  ( void );
void SSC_Handler                   ( void );
void SUPC_Handler                  ( void );
void TC0_CH0_Handler               ( void );
void TC0_CH1_Handler               ( void );
void TC0_CH2_Handler               ( void );
void TC1_CH0_Handler               ( void );
void TC1_CH1_Handler               ( void );
void TC1_CH2_Handler               ( void );
void TC2_CH0_Handler               ( void );
void TC2_CH1_Handler               ( void );
void TC2_CH2_Handler               ( void );
void TC3_CH0_Handler               ( void );
void TC3_CH1_Handler               ( void );
void TC3_CH2_Handler               ( void );
void TRNG_Handler                  ( void );
void TWI0_Handler                  ( void );
void TWI1_Handler                  ( void );
void TWI2_Handler                  ( void );
void UART0_Handler                 ( void );
void UART1_Handler                 ( void );
void UART2_Handler                 ( void );
void UART3_Handler                 ( void );
void UART4_Handler                 ( void );
void USART0_Handler                ( void );
void USART1_Handler                ( void );
void USART2_Handler                ( void );
void USBHS_Handler                 ( void );
void WDT_Handler                   ( void );
void XDMAC_Handler                 ( void );

/*
 * \brief Configuration of the CORTEX-M7 Processor and Core Peripherals
 */
#define __CM7_REV                 0x0101 /**< CM7 Core Revision                                                         */
#define __NVIC_PRIO_BITS               3 /**< Number of Bits used for Priority Levels                                   */
#define __Vendor_SysTickConfig         0 /**< Set to 1 if different SysTick Config is used                              */
#define __MPU_PRESENT                  1 /**< MPU present or not                                                        */
#define __VTOR_PRESENT                 1 /**< Vector Table Offset Register present or not                               */
#define __FPU_PRESENT                  1 /**< FPU present or not                                                        */
#define __FPU_DP                       1 /**< Double Precision FPU                                                      */
#define __ICACHE_PRESENT               1 /**< Instruction Cache present                                                 */
#define __DCACHE_PRESENT               1 /**< Data Cache present                                                        */
#define __ITCM_PRESENT                 1 /**< Instruction TCM present                                                   */
#define __DTCM_PRESENT                 1 /**< Data TCM present                                                          */
#define __ARCH_ARM                     1
#define __ARCH_ARM_CORTEX_M            1
#define __DEVICE_IS_PIC32C             1

/*
 * \brief CMSIS includes
 */
#include <core_cm7.h>
#if !defined DONT_USE_CMSIS_INIT
#include "system_ca70.h"
#endif /* DONT_USE_CMSIS_INIT */

/** @}  end of PIC32CZ1038CA70144_cmsis CMSIS Definitions */

/** \defgroup PIC32CZ1038CA70144_api Peripheral Software API
 *  @{
 */

/* ************************************************************************** */
/**  SOFTWARE PERIPHERAL API DEFINITION FOR PIC32CZ1038CA70144                */
/* ************************************************************************** */
#include "component/acc.h"
#include "component/aes.h"
#include "component/afec.h"
#include "component/chipid.h"
#include "component/dacc.h"
#include "component/efc.h"
#include "component/gmac.h"
#include "component/gpbr.h"
#include "component/hsmci.h"
#include "component/i2sc.h"
#include "component/icm.h"
#include "component/isi.h"
#include "component/matrix.h"
#include "component/mcan.h"
#include "component/mlb.h"
#include "component/port.h"
#include "component/pmc.h"
#include "component/pwmc.h"
#include "component/qspi.h"
#include "component/rstc.h"
#include "component/rswdt.h"
#include "component/rtc.h"
#include "component/rtt.h"
#include "component/sdramc.h"
#include "component/smc.h"
#include "component/spi.h"
#include "component/ssc.h"
#include "component/supc.h"
#include "component/tc.h"
#include "component/trng.h"
#include "component/twi.h"
#include "component/uart.h"
#include "component/usart.h"
#include "component/usbhs.h"
#include "component/utmi.h"
#include "component/wdt.h"
#include "component/xdmac.h"
/** @}  end of Peripheral Software API */

/** \addtogroup PIC32CZ1038CA70144_id Peripheral Ids Definitions
 *  @{
 */

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR PIC32CZ1038CA70144                          */
/* ************************************************************************** */
#define ID_SUPC          (  0) /**< \brief Supply Controller (SUPC) */
#define ID_RSTC          (  1) /**< \brief Reset Controller (RSTC) */
#define ID_RTC           (  2) /**< \brief Real-time Clock (RTC) */
#define ID_RTT           (  3) /**< \brief Real-time Timer (RTT) */
#define ID_WDT           (  4) /**< \brief Watchdog Timer (WDT) */
#define ID_PMC           (  5) /**< \brief Power Management Controller (PMC) */
#define ID_EFC           (  6) /**< \brief Embedded Flash Controller (EFC) */
#define ID_UART0         (  7) /**< \brief Universal Asynchronous Receiver Transmitter (UART0) */
#define ID_UART1         (  8) /**< \brief Universal Asynchronous Receiver Transmitter (UART1) */
#define ID_SMC           (  9) /**< \brief Static Memory Controller (SMC) */
#define ID_PORTA         ( 10) /**< \brief Port (PORTA) */
#define ID_PORTB         ( 11) /**< \brief Port (PORTB) */
#define ID_PORTC         ( 12) /**< \brief Port (PORTC) */
#define ID_USART0        ( 13) /**< \brief Universal Synchronous Asynchronous Receiver Transmitter (USART0) */
#define ID_USART1        ( 14) /**< \brief Universal Synchronous Asynchronous Receiver Transmitter (USART1) */
#define ID_USART2        ( 15) /**< \brief Universal Synchronous Asynchronous Receiver Transmitter (USART2) */
#define ID_PORTD         ( 16) /**< \brief Port (PORTD) */
#define ID_PORTE         ( 17) /**< \brief Port (PORTE) */
#define ID_HSMCI         ( 18) /**< \brief High Speed MultiMedia Card Interface (HSMCI) */
#define ID_TWI0          ( 19) /**< \brief Two-wire Interface (TWI0) */
#define ID_TWI1          ( 20) /**< \brief Two-wire Interface (TWI1) */
#define ID_SPI0          ( 21) /**< \brief Serial Peripheral Interface (SPI0) */
#define ID_SSC           ( 22) /**< \brief Synchronous Serial Controller (SSC) */
#define ID_TC0_CHANNEL0  ( 23) /**< \brief Timer Counter (TC0_CHANNEL0) */
#define ID_TC0_CHANNEL1  ( 24) /**< \brief Timer Counter (TC0_CHANNEL1) */
#define ID_TC0_CHANNEL2  ( 25) /**< \brief Timer Counter (TC0_CHANNEL2) */
#define ID_TC1_CHANNEL0  ( 26) /**< \brief Timer Counter (TC1_CHANNEL0) */
#define ID_TC1_CHANNEL1  ( 27) /**< \brief Timer Counter (TC1_CHANNEL1) */
#define ID_TC1_CHANNEL2  ( 28) /**< \brief Timer Counter (TC1_CHANNEL2) */
#define ID_AFEC0         ( 29) /**< \brief Analog Front-End Controller (AFEC0) */
#define ID_DACC          ( 30) /**< \brief Digital-to-Analog Converter Controller (DACC) */
#define ID_PWMC0         ( 31) /**< \brief Pulse Width Modulation Controller (PWMC0) */
#define ID_ICM           ( 32) /**< \brief Integrity Check Monitor (ICM) */
#define ID_ACC           ( 33) /**< \brief Analog Comparator Controller (ACC) */
#define ID_USBHS         ( 34) /**< \brief USB High-Speed Interface (USBHS) */
#define ID_MCAN0         ( 35) /**< \brief Controller Area Network (MCAN0) */
#define ID_MCAN1         ( 37) /**< \brief Controller Area Network (MCAN1) */
#define ID_GMAC          ( 39) /**< \brief Gigabit Ethernet MAC (GMAC) */
#define ID_AFEC1         ( 40) /**< \brief Analog Front-End Controller (AFEC1) */
#define ID_TWI2          ( 41) /**< \brief Two-wire Interface (TWI2) */
#define ID_SPI1          ( 42) /**< \brief Serial Peripheral Interface (SPI1) */
#define ID_QSPI          ( 43) /**< \brief Quad Serial Peripheral Interface (QSPI) */
#define ID_UART2         ( 44) /**< \brief Universal Asynchronous Receiver Transmitter (UART2) */
#define ID_UART3         ( 45) /**< \brief Universal Asynchronous Receiver Transmitter (UART3) */
#define ID_UART4         ( 46) /**< \brief Universal Asynchronous Receiver Transmitter (UART4) */
#define ID_TC2_CHANNEL0  ( 47) /**< \brief Timer Counter (TC2_CHANNEL0) */
#define ID_TC2_CHANNEL1  ( 48) /**< \brief Timer Counter (TC2_CHANNEL1) */
#define ID_TC2_CHANNEL2  ( 49) /**< \brief Timer Counter (TC2_CHANNEL2) */
#define ID_TC3_CHANNEL0  ( 50) /**< \brief Timer Counter (TC3_CHANNEL0) */
#define ID_TC3_CHANNEL1  ( 51) /**< \brief Timer Counter (TC3_CHANNEL1) */
#define ID_TC3_CHANNEL2  ( 52) /**< \brief Timer Counter (TC3_CHANNEL2) */
#define ID_MLB           ( 53) /**< \brief MediaLB (MLB) */
#define ID_AES           ( 56) /**< \brief Advanced Encryption Standard (AES) */
#define ID_TRNG          ( 57) /**< \brief True Random Number Generator (TRNG) */
#define ID_XDMAC         ( 58) /**< \brief Extensible DMA Controller (XDMAC) */
#define ID_ISI           ( 59) /**< \brief Image Sensor Interface (ISI) */
#define ID_PWMC1         ( 60) /**< \brief Pulse Width Modulation Controller (PWMC1) */
#define ID_SDRAMC        ( 62) /**< \brief SDRAM Controller (SDRAMC) */
#define ID_RSWDT         ( 63) /**< \brief Reinforced Safety Watchdog Timer (RSWDT) */
#define ID_I2SC0         ( 69) /**< \brief Inter-IC Sound Controller (I2SC0) */
#define ID_I2SC1         ( 70) /**< \brief Inter-IC Sound Controller (I2SC1) */

#define ID_PERIPH_COUNT  ( 71) /**< \brief Number of peripheral IDs */
/** @}  end of Peripheral Ids Definitions */

/** \addtogroup PIC32CZ1038CA70144_base Peripheral Base Address Definitions
 *  @{
 */

/* ************************************************************************** */
/*   REGISTER STRUCTURE ADDRESS DEFINITIONS FOR PIC32CZ1038CA70144            */
/* ************************************************************************** */
#define _ACC_REGS                        CAST(acc_registers_t, 0x40044000)             /**< \brief ACC Registers Address        */
#define _AES_REGS                        CAST(aes_registers_t, 0x4006c000)             /**< \brief AES Registers Address        */
#define _AFEC0_REGS                      CAST(afec_registers_t, 0x4003c000)            /**< \brief AFEC0 Registers Address      */
#define _AFEC1_REGS                      CAST(afec_registers_t, 0x40064000)            /**< \brief AFEC1 Registers Address      */
#define _CHIPID_REGS                     CAST(chipid_registers_t, 0x400e0940)          /**< \brief CHIPID Registers Address     */
#define _DACC_REGS                       CAST(dacc_registers_t, 0x40040000)            /**< \brief DACC Registers Address       */
#define _EFC_REGS                        CAST(efc_registers_t, 0x400e0c00)             /**< \brief EFC Registers Address        */
#define _GMAC_REGS                       CAST(gmac_registers_t, 0x40050000)            /**< \brief GMAC Registers Address       */
#define _GPBR_REGS                       CAST(gpbr_registers_t, 0x400e1890)            /**< \brief GPBR Registers Address       */
#define _HSMCI_REGS                      CAST(hsmci_registers_t, 0x40000000)           /**< \brief HSMCI Registers Address      */
#define _I2SC0_REGS                      CAST(i2sc_registers_t, 0x4008c000)            /**< \brief I2SC0 Registers Address      */
#define _I2SC1_REGS                      CAST(i2sc_registers_t, 0x40090000)            /**< \brief I2SC1 Registers Address      */
#define _ICM_REGS                        CAST(icm_registers_t, 0x40048000)             /**< \brief ICM Registers Address        */
#define _ISI_REGS                        CAST(isi_registers_t, 0x4004c000)             /**< \brief ISI Registers Address        */
#define _MATRIX_REGS                     CAST(matrix_registers_t, 0x40088000)          /**< \brief MATRIX Registers Address     */
#define _MCAN0_REGS                      CAST(mcan_registers_t, 0x40030000)            /**< \brief MCAN0 Registers Address      */
#define _MCAN1_REGS                      CAST(mcan_registers_t, 0x40034000)            /**< \brief MCAN1 Registers Address      */
#define _MLB_REGS                        CAST(mlb_registers_t, 0x40068000)             /**< \brief MLB Registers Address        */
#define _PORTA_REGS                      CAST(port_registers_t, 0x400e0e00)            /**< \brief PORTA Registers Address      */
#define _PORTB_REGS                      CAST(port_registers_t, 0x400e1000)            /**< \brief PORTB Registers Address      */
#define _PORTC_REGS                      CAST(port_registers_t, 0x400e1200)            /**< \brief PORTC Registers Address      */
#define _PORTD_REGS                      CAST(port_registers_t, 0x400e1400)            /**< \brief PORTD Registers Address      */
#define _PORTE_REGS                      CAST(port_registers_t, 0x400e1600)            /**< \brief PORTE Registers Address      */
#define _PMC_REGS                        CAST(pmc_registers_t, 0x400e0600)             /**< \brief PMC Registers Address        */
#define _PWMC0_REGS                      CAST(pwmc_registers_t, 0x40020000)            /**< \brief PWMC0 Registers Address      */
#define _PWMC1_REGS                      CAST(pwmc_registers_t, 0x4005c000)            /**< \brief PWMC1 Registers Address      */
#define _QSPI_REGS                       CAST(qspi_registers_t, 0x4007c000)            /**< \brief QSPI Registers Address       */
#define _RSTC_REGS                       CAST(rstc_registers_t, 0x400e1800)            /**< \brief RSTC Registers Address       */
#define _RSWDT_REGS                      CAST(rswdt_registers_t, 0x400e1900)           /**< \brief RSWDT Registers Address      */
#define _RTC_REGS                        CAST(rtc_registers_t, 0x400e1860)             /**< \brief RTC Registers Address        */
#define _RTT_REGS                        CAST(rtt_registers_t, 0x400e1830)             /**< \brief RTT Registers Address        */
#define _SDRAMC_REGS                     CAST(sdramc_registers_t, 0x40084000)          /**< \brief SDRAMC Registers Address     */
#define _SMC_REGS                        CAST(smc_registers_t, 0x40080000)             /**< \brief SMC Registers Address        */
#define _SPI0_REGS                       CAST(spi_registers_t, 0x40008000)             /**< \brief SPI0 Registers Address       */
#define _SPI1_REGS                       CAST(spi_registers_t, 0x40058000)             /**< \brief SPI1 Registers Address       */
#define _SSC_REGS                        CAST(ssc_registers_t, 0x40004000)             /**< \brief SSC Registers Address        */
#define _SUPC_REGS                       CAST(supc_registers_t, 0x400e1810)            /**< \brief SUPC Registers Address       */
#define _TC0_REGS                        CAST(tc_registers_t, 0x4000c000)              /**< \brief TC0 Registers Address        */
#define _TC1_REGS                        CAST(tc_registers_t, 0x40010000)              /**< \brief TC1 Registers Address        */
#define _TC2_REGS                        CAST(tc_registers_t, 0x40014000)              /**< \brief TC2 Registers Address        */
#define _TC3_REGS                        CAST(tc_registers_t, 0x40054000)              /**< \brief TC3 Registers Address        */
#define _TRNG_REGS                       CAST(trng_registers_t, 0x40070000)            /**< \brief TRNG Registers Address       */
#define _TWI0_REGS                       CAST(twi_registers_t, 0x40018000)             /**< \brief TWI0 Registers Address       */
#define _TWI1_REGS                       CAST(twi_registers_t, 0x4001c000)             /**< \brief TWI1 Registers Address       */
#define _TWI2_REGS                       CAST(twi_registers_t, 0x40060000)             /**< \brief TWI2 Registers Address       */
#define _UART0_REGS                      CAST(uart_registers_t, 0x400e0800)            /**< \brief UART0 Registers Address      */
#define _UART1_REGS                      CAST(uart_registers_t, 0x400e0a00)            /**< \brief UART1 Registers Address      */
#define _UART2_REGS                      CAST(uart_registers_t, 0x400e1a00)            /**< \brief UART2 Registers Address      */
#define _UART3_REGS                      CAST(uart_registers_t, 0x400e1c00)            /**< \brief UART3 Registers Address      */
#define _UART4_REGS                      CAST(uart_registers_t, 0x400e1e00)            /**< \brief UART4 Registers Address      */
#define _USART0_REGS                     CAST(usart_registers_t, 0x40024000)           /**< \brief USART0 Registers Address     */
#define _USART1_REGS                     CAST(usart_registers_t, 0x40028000)           /**< \brief USART1 Registers Address     */
#define _USART2_REGS                     CAST(usart_registers_t, 0x4002c000)           /**< \brief USART2 Registers Address     */
#define _USBHS_REGS                      CAST(usbhs_registers_t, 0x40038000)           /**< \brief USBHS Registers Address      */
#define _UTMI_REGS                       CAST(utmi_registers_t, 0x400e0400)            /**< \brief UTMI Registers Address       */
#define _WDT_REGS                        CAST(wdt_registers_t, 0x400e1850)             /**< \brief WDT Registers Address        */
#define _XDMAC_REGS                      CAST(xdmac_registers_t, 0x40078000)           /**< \brief XDMAC Registers Address      */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR PIC32CZ1038CA70144                          */
/* ************************************************************************** */

#define _ACC_BASE_ADDRESS                (0x40044000UL)                                /**< \brief ACC Base Address             */
#define _AES_BASE_ADDRESS                (0x4006c000UL)                                /**< \brief AES Base Address             */
#define _AFEC0_BASE_ADDRESS              (0x4003c000UL)                                /**< \brief AFEC0 Base Address           */
#define _AFEC1_BASE_ADDRESS              (0x40064000UL)                                /**< \brief AFEC1 Base Address           */
#define _CHIPID_BASE_ADDRESS             (0x400e0940UL)                                /**< \brief CHIPID Base Address          */
#define _DACC_BASE_ADDRESS               (0x40040000UL)                                /**< \brief DACC Base Address            */
#define _EFC_BASE_ADDRESS                (0x400e0c00UL)                                /**< \brief EFC Base Address             */
#define _GMAC_BASE_ADDRESS               (0x40050000UL)                                /**< \brief GMAC Base Address            */
#define _GPBR_BASE_ADDRESS               (0x400e1890UL)                                /**< \brief GPBR Base Address            */
#define _HSMCI_BASE_ADDRESS              (0x40000000UL)                                /**< \brief HSMCI Base Address           */
#define _I2SC0_BASE_ADDRESS              (0x4008c000UL)                                /**< \brief I2SC0 Base Address           */
#define _I2SC1_BASE_ADDRESS              (0x40090000UL)                                /**< \brief I2SC1 Base Address           */
#define _ICM_BASE_ADDRESS                (0x40048000UL)                                /**< \brief ICM Base Address             */
#define _ISI_BASE_ADDRESS                (0x4004c000UL)                                /**< \brief ISI Base Address             */
#define _MATRIX_BASE_ADDRESS             (0x40088000UL)                                /**< \brief MATRIX Base Address          */
#define _MCAN0_BASE_ADDRESS              (0x40030000UL)                                /**< \brief MCAN0 Base Address           */
#define _MCAN1_BASE_ADDRESS              (0x40034000UL)                                /**< \brief MCAN1 Base Address           */
#define _MLB_BASE_ADDRESS                (0x40068000UL)                                /**< \brief MLB Base Address             */
#define _PORTA_BASE_ADDRESS              (0x400e0e00UL)                                /**< \brief PORTA Base Address           */
#define _PORTB_BASE_ADDRESS              (0x400e1000UL)                                /**< \brief PORTB Base Address           */
#define _PORTC_BASE_ADDRESS              (0x400e1200UL)                                /**< \brief PORTC Base Address           */
#define _PORTD_BASE_ADDRESS              (0x400e1400UL)                                /**< \brief PORTD Base Address           */
#define _PORTE_BASE_ADDRESS              (0x400e1600UL)                                /**< \brief PORTE Base Address           */
#define _PMC_BASE_ADDRESS                (0x400e0600UL)                                /**< \brief PMC Base Address             */
#define _PWMC0_BASE_ADDRESS              (0x40020000UL)                                /**< \brief PWMC0 Base Address           */
#define _PWMC1_BASE_ADDRESS              (0x4005c000UL)                                /**< \brief PWMC1 Base Address           */
#define _QSPI_BASE_ADDRESS               (0x4007c000UL)                                /**< \brief QSPI Base Address            */
#define _RSTC_BASE_ADDRESS               (0x400e1800UL)                                /**< \brief RSTC Base Address            */
#define _RSWDT_BASE_ADDRESS              (0x400e1900UL)                                /**< \brief RSWDT Base Address           */
#define _RTC_BASE_ADDRESS                (0x400e1860UL)                                /**< \brief RTC Base Address             */
#define _RTT_BASE_ADDRESS                (0x400e1830UL)                                /**< \brief RTT Base Address             */
#define _SDRAMC_BASE_ADDRESS             (0x40084000UL)                                /**< \brief SDRAMC Base Address          */
#define _SMC_BASE_ADDRESS                (0x40080000UL)                                /**< \brief SMC Base Address             */
#define _SPI0_BASE_ADDRESS               (0x40008000UL)                                /**< \brief SPI0 Base Address            */
#define _SPI1_BASE_ADDRESS               (0x40058000UL)                                /**< \brief SPI1 Base Address            */
#define _SSC_BASE_ADDRESS                (0x40004000UL)                                /**< \brief SSC Base Address             */
#define _SUPC_BASE_ADDRESS               (0x400e1810UL)                                /**< \brief SUPC Base Address            */
#define _TC0_BASE_ADDRESS                (0x4000c000UL)                                /**< \brief TC0 Base Address             */
#define _TC1_BASE_ADDRESS                (0x40010000UL)                                /**< \brief TC1 Base Address             */
#define _TC2_BASE_ADDRESS                (0x40014000UL)                                /**< \brief TC2 Base Address             */
#define _TC3_BASE_ADDRESS                (0x40054000UL)                                /**< \brief TC3 Base Address             */
#define _TRNG_BASE_ADDRESS               (0x40070000UL)                                /**< \brief TRNG Base Address            */
#define _TWI0_BASE_ADDRESS               (0x40018000UL)                                /**< \brief TWI0 Base Address            */
#define _TWI1_BASE_ADDRESS               (0x4001c000UL)                                /**< \brief TWI1 Base Address            */
#define _TWI2_BASE_ADDRESS               (0x40060000UL)                                /**< \brief TWI2 Base Address            */
#define _UART0_BASE_ADDRESS              (0x400e0800UL)                                /**< \brief UART0 Base Address           */
#define _UART1_BASE_ADDRESS              (0x400e0a00UL)                                /**< \brief UART1 Base Address           */
#define _UART2_BASE_ADDRESS              (0x400e1a00UL)                                /**< \brief UART2 Base Address           */
#define _UART3_BASE_ADDRESS              (0x400e1c00UL)                                /**< \brief UART3 Base Address           */
#define _UART4_BASE_ADDRESS              (0x400e1e00UL)                                /**< \brief UART4 Base Address           */
#define _USART0_BASE_ADDRESS             (0x40024000UL)                                /**< \brief USART0 Base Address          */
#define _USART1_BASE_ADDRESS             (0x40028000UL)                                /**< \brief USART1 Base Address          */
#define _USART2_BASE_ADDRESS             (0x4002c000UL)                                /**< \brief USART2 Base Address          */
#define _USBHS_BASE_ADDRESS              (0x40038000UL)                                /**< \brief USBHS Base Address           */
#define _UTMI_BASE_ADDRESS               (0x400e0400UL)                                /**< \brief UTMI Base Address            */
#define _WDT_BASE_ADDRESS                (0x400e1850UL)                                /**< \brief WDT Base Address             */
#define _XDMAC_BASE_ADDRESS              (0x40078000UL)                                /**< \brief XDMAC Base Address           */

/* ************************************************************************** */
/*   HARMONY MODULES DEFINITIONS FOR PIC32CZ1038CA70144                       */
/* ************************************************************************** */

typedef enum
{
  ACC_ID_0 = ((uint32_t)_ACC_BASE_ADDRESS),
  ACC_NUMBER_OF_MODULES = 1
} ACC_MODULE_ID;

typedef enum
{
  AES_ID_0 = ((uint32_t)_AES_BASE_ADDRESS),
  AES_NUMBER_OF_MODULES = 1
} AES_MODULE_ID;

typedef enum
{
  AFEC_ID_0 = ((uint32_t)_AFEC0_BASE_ADDRESS),
  AFEC_ID_1 = ((uint32_t)_AFEC1_BASE_ADDRESS),
  AFEC_NUMBER_OF_MODULES = 2
} AFEC_MODULE_ID;

typedef enum
{
  CHIPID_ID_0 = ((uint32_t)_CHIPID_BASE_ADDRESS),
  CHIPID_NUMBER_OF_MODULES = 1
} CHIPID_MODULE_ID;

typedef enum
{
  DACC_ID_0 = ((uint32_t)_DACC_BASE_ADDRESS),
  DACC_NUMBER_OF_MODULES = 1
} DACC_MODULE_ID;

typedef enum
{
  EFC_ID_0 = ((uint32_t)_EFC_BASE_ADDRESS),
  EFC_NUMBER_OF_MODULES = 1
} EFC_MODULE_ID;

typedef enum
{
  GMAC_ID_0 = ((uint32_t)_GMAC_BASE_ADDRESS),
  GMAC_NUMBER_OF_MODULES = 1
} GMAC_MODULE_ID;

typedef enum
{
  GPBR_ID_0 = ((uint32_t)_GPBR_BASE_ADDRESS),
  GPBR_NUMBER_OF_MODULES = 1
} GPBR_MODULE_ID;

typedef enum
{
  HSMCI_ID_0 = ((uint32_t)_HSMCI_BASE_ADDRESS),
  HSMCI_NUMBER_OF_MODULES = 1
} HSMCI_MODULE_ID;

typedef enum
{
  I2SC_ID_0 = ((uint32_t)_I2SC0_BASE_ADDRESS),
  I2SC_ID_1 = ((uint32_t)_I2SC1_BASE_ADDRESS),
  I2SC_NUMBER_OF_MODULES = 2
} I2SC_MODULE_ID;

typedef enum
{
  ICM_ID_0 = ((uint32_t)_ICM_BASE_ADDRESS),
  ICM_NUMBER_OF_MODULES = 1
} ICM_MODULE_ID;

typedef enum
{
  ISI_ID_0 = ((uint32_t)_ISI_BASE_ADDRESS),
  ISI_NUMBER_OF_MODULES = 1
} ISI_MODULE_ID;

typedef enum
{
  MATRIX_ID_0 = ((uint32_t)_MATRIX_BASE_ADDRESS),
  MATRIX_NUMBER_OF_MODULES = 1
} MATRIX_MODULE_ID;

typedef enum
{
  MCAN_ID_0 = ((uint32_t)_MCAN0_BASE_ADDRESS),
  MCAN_ID_1 = ((uint32_t)_MCAN1_BASE_ADDRESS),
  MCAN_NUMBER_OF_MODULES = 2
} MCAN_MODULE_ID;

typedef enum
{
  MLB_ID_0 = ((uint32_t)_MLB_BASE_ADDRESS),
  MLB_NUMBER_OF_MODULES = 1
} MLB_MODULE_ID;

typedef enum
{
  PORTS_ID_0 = ((uint32_t)_PORTA_BASE_ADDRESS),
  PORTS_ID_1 = ((uint32_t)_PORTB_BASE_ADDRESS),
  PORTS_ID_2 = ((uint32_t)_PORTC_BASE_ADDRESS),
  PORTS_ID_3 = ((uint32_t)_PORTD_BASE_ADDRESS),
  PORTS_ID_4 = ((uint32_t)_PORTE_BASE_ADDRESS),
  PORTS_NUMBER_OF_MODULES = 5
} PORTS_MODULE_ID;

typedef enum
{
  PMC_ID_0 = ((uint32_t)_PMC_BASE_ADDRESS),
  PMC_NUMBER_OF_MODULES = 1
} PMC_MODULE_ID;

typedef enum
{
  PWMC_ID_0 = ((uint32_t)_PWMC0_BASE_ADDRESS),
  PWMC_ID_1 = ((uint32_t)_PWMC1_BASE_ADDRESS),
  PWMC_NUMBER_OF_MODULES = 2
} PWMC_MODULE_ID;

typedef enum
{
  QSPI_ID_0 = ((uint32_t)_QSPI_BASE_ADDRESS),
  QSPI_NUMBER_OF_MODULES = 1
} QSPI_MODULE_ID;

typedef enum
{
  RSTC_ID_0 = ((uint32_t)_RSTC_BASE_ADDRESS),
  RSTC_NUMBER_OF_MODULES = 1
} RSTC_MODULE_ID;

typedef enum
{
  RSWDT_ID_0 = ((uint32_t)_RSWDT_BASE_ADDRESS),
  RSWDT_NUMBER_OF_MODULES = 1
} RSWDT_MODULE_ID;

typedef enum
{
  RTC_ID_0 = ((uint32_t)_RTC_BASE_ADDRESS),
  RTC_NUMBER_OF_MODULES = 1
} RTC_MODULE_ID;

typedef enum
{
  RTT_ID_0 = ((uint32_t)_RTT_BASE_ADDRESS),
  RTT_NUMBER_OF_MODULES = 1
} RTT_MODULE_ID;

typedef enum
{
  SDRAMC_ID_0 = ((uint32_t)_SDRAMC_BASE_ADDRESS),
  SDRAMC_NUMBER_OF_MODULES = 1
} SDRAMC_MODULE_ID;

typedef enum
{
  SMC_ID_0 = ((uint32_t)_SMC_BASE_ADDRESS),
  SMC_NUMBER_OF_MODULES = 1
} SMC_MODULE_ID;

typedef enum
{
  SPI_ID_0 = ((uint32_t)_SPI0_BASE_ADDRESS),
  SPI_ID_1 = ((uint32_t)_SPI1_BASE_ADDRESS),
  SPI_NUMBER_OF_MODULES = 2
} SPI_MODULE_ID;

typedef enum
{
  SSC_ID_0 = ((uint32_t)_SSC_BASE_ADDRESS),
  SSC_NUMBER_OF_MODULES = 1
} SSC_MODULE_ID;

typedef enum
{
  SUPC_ID_0 = ((uint32_t)_SUPC_BASE_ADDRESS),
  SUPC_NUMBER_OF_MODULES = 1
} SUPC_MODULE_ID;

typedef enum
{
  TC_ID_0 = ((uint32_t)_TC0_BASE_ADDRESS),
  TC_ID_1 = ((uint32_t)_TC1_BASE_ADDRESS),
  TC_ID_2 = ((uint32_t)_TC2_BASE_ADDRESS),
  TC_ID_3 = ((uint32_t)_TC3_BASE_ADDRESS),
  TC_NUMBER_OF_MODULES = 4
} TC_MODULE_ID;

typedef enum
{
  TRNG_ID_0 = ((uint32_t)_TRNG_BASE_ADDRESS),
  TRNG_NUMBER_OF_MODULES = 1
} TRNG_MODULE_ID;

typedef enum
{
  TWI_ID_0 = ((uint32_t)_TWI0_BASE_ADDRESS),
  TWI_ID_1 = ((uint32_t)_TWI1_BASE_ADDRESS),
  TWI_ID_2 = ((uint32_t)_TWI2_BASE_ADDRESS),
  TWI_NUMBER_OF_MODULES = 3
} TWI_MODULE_ID;

typedef enum
{
  UART_ID_0 = ((uint32_t)_UART0_BASE_ADDRESS),
  UART_ID_1 = ((uint32_t)_UART1_BASE_ADDRESS),
  UART_ID_2 = ((uint32_t)_UART2_BASE_ADDRESS),
  UART_ID_3 = ((uint32_t)_UART3_BASE_ADDRESS),
  UART_ID_4 = ((uint32_t)_UART4_BASE_ADDRESS),
  UART_NUMBER_OF_MODULES = 5
} UART_MODULE_ID;

typedef enum
{
  USART_ID_0 = ((uint32_t)_USART0_BASE_ADDRESS),
  USART_ID_1 = ((uint32_t)_USART1_BASE_ADDRESS),
  USART_ID_2 = ((uint32_t)_USART2_BASE_ADDRESS),
  USART_NUMBER_OF_MODULES = 3
} USART_MODULE_ID;

typedef enum
{
  USBHS_ID_0 = ((uint32_t)_USBHS_BASE_ADDRESS),
  USBHS_NUMBER_OF_MODULES = 1
} USBHS_MODULE_ID;

typedef enum
{
  UTMI_ID_0 = ((uint32_t)_UTMI_BASE_ADDRESS),
  UTMI_NUMBER_OF_MODULES = 1
} UTMI_MODULE_ID;

typedef enum
{
  WDT_ID_0 = ((uint32_t)_WDT_BASE_ADDRESS),
  WDT_NUMBER_OF_MODULES = 1
} WDT_MODULE_ID;

typedef enum
{
  XDMAC_ID_0 = ((uint32_t)_XDMAC_BASE_ADDRESS),
  XDMAC_NUMBER_OF_MODULES = 1
} XDMAC_MODULE_ID;

/** @}  end of Peripheral Base Address Definitions */

/** \addtogroup PIC32CZ1038CA70144_pio Peripheral Pio Definitions
 *  @{
 */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR PIC32CZ1038CA70144                                   */
/* ************************************************************************** */
#include "pio/pic32cz1038ca70144.h"
/** @}  end of Peripheral Pio Definitions */

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR PIC32CZ1038CA70144                        */
/* ************************************************************************** */

#define PERIPHERALS_SIZE               (0x20000000U)       /* 524288kB Memory segment type: io */
#define SYSTEM_SIZE                    (0x10000000U)       /* 262144kB Memory segment type: io */
#define QSPIMEM_SIZE                   (0x20000000U)       /* 524288kB Memory segment type: other */
#define AXIMX_SIZE                     (0x00100000U)       /* 1024kB Memory segment type: other */
#define ITCM_SIZE                      (0x00200000U)       /* 2048kB Memory segment type: other */
#define IFLASH_SIZE                    (0x00100000U)       /* 1024kB Memory segment type: flash */
#define IFLASH_PAGE_SIZE                      (512U)
#define IFLASH_NB_OF_PAGES                   (2048U)

#define IROM_SIZE                      (0x00004000U)       /*   16kB Memory segment type: rom */
#define DTCM_SIZE                      (0x00020000U)       /*  128kB Memory segment type: other */
#define IRAM_SIZE                      (0x00060000U)       /*  384kB Memory segment type: ram */
#define EBI_CS0_SIZE                   (0x01000000U)       /* 16384kB Memory segment type: other */
#define EBI_CS1_SIZE                   (0x01000000U)       /* 16384kB Memory segment type: other */
#define EBI_CS2_SIZE                   (0x01000000U)       /* 16384kB Memory segment type: other */
#define EBI_CS3_SIZE                   (0x01000000U)       /* 16384kB Memory segment type: other */
#define SDRAM_CS_SIZE                  (0x10000000U)       /* 262144kB Memory segment type: other */

#define PERIPHERALS_ADDR               (0x40000000U)       /**< PERIPHERALS base address (type: io)*/
#define SYSTEM_ADDR                    (0xe0000000U)       /**< SYSTEM base address (type: io)*/
#define QSPIMEM_ADDR                   (0x80000000U)       /**< QSPIMEM base address (type: other)*/
#define AXIMX_ADDR                     (0xa0000000U)       /**< AXIMX base address (type: other)*/
#define ITCM_ADDR                      (0x00000000U)       /**< ITCM base address (type: other)*/
#define IFLASH_ADDR                    (0x00400000U)       /**< IFLASH base address (type: flash)*/
#define IROM_ADDR                      (0x00800000U)       /**< IROM base address (type: rom)*/
#define DTCM_ADDR                      (0x20000000U)       /**< DTCM base address (type: other)*/
#define IRAM_ADDR                      (0x20400000U)       /**< IRAM base address (type: ram)*/
#define EBI_CS0_ADDR                   (0x60000000U)       /**< EBI_CS0 base address (type: other)*/
#define EBI_CS1_ADDR                   (0x61000000U)       /**< EBI_CS1 base address (type: other)*/
#define EBI_CS2_ADDR                   (0x62000000U)       /**< EBI_CS2 base address (type: other)*/
#define EBI_CS3_ADDR                   (0x63000000U)       /**< EBI_CS3 base address (type: other)*/
#define SDRAM_CS_ADDR                  (0x70000000U)       /**< SDRAM_CS base address (type: other)*/

/* ************************************************************************** */
/**  DEVICE SIGNATURES FOR PIC32CZ1038CA70144                                 */
/* ************************************************************************** */
#define CHIP_JTAGID                    (0x05b3d03fUL)
#define CHIP_CIDR                      (0xa1020c00UL)
#define CHIP_EXID                      (0x00000002UL)

/* ************************************************************************** */
/**  ELECTRICAL DEFINITIONS FOR PIC32CZ1038CA70144 */
/* ************************************************************************** */
#define CHIP_FREQ_SLCK_RC_MIN               (20000UL)
#define CHIP_FREQ_SLCK_RC                   (32000UL)      /**< \brief Typical Slow Clock Internal RC frequency */
#define CHIP_FREQ_SLCK_RC_MAX               (44000UL)
#define CHIP_FREQ_MAINCK_RC_4MHZ          (4000000UL)
#define CHIP_FREQ_MAINCK_RC_8MHZ          (8000000UL)
#define CHIP_FREQ_MAINCK_RC_12MHZ        (12000000UL)
#define CHIP_FREQ_CPU_MAX               (300000000UL)
#define CHIP_FREQ_XTAL_32K                  (32768UL)
#define CHIP_FREQ_XTAL_12M               (12000000UL)
#define CHIP_FREQ_FWS_0                  (23000000UL)      /**< \brief Maximum operating frequency when FWS is 0 */
#define CHIP_FREQ_FWS_1                  (46000000UL)      /**< \brief Maximum operating frequency when FWS is 1 */
#define CHIP_FREQ_FWS_2                  (69000000UL)      /**< \brief Maximum operating frequency when FWS is 2 */
#define CHIP_FREQ_FWS_3                  (92000000UL)      /**< \brief Maximum operating frequency when FWS is 3 */
#define CHIP_FREQ_FWS_4                 (115000000UL)      /**< \brief Maximum operating frequency when FWS is 4 */
#define CHIP_FREQ_FWS_5                 (138000000UL)      /**< \brief Maximum operating frequency when FWS is 5 */
#define CHIP_FREQ_FWS_6                 (150000000UL)      /**< \brief Maximum operating frequency when FWS is 6 */
#define CHIP_FREQ_FWS_NUMBER                    (7UL)      /**< \brief Number of FWS ranges */

#ifdef __cplusplus
}
#endif

/** @}  end of PIC32CZ1038CA70144 definitions */


#endif /* _PIC32CZ1038CA70144_H_ */
