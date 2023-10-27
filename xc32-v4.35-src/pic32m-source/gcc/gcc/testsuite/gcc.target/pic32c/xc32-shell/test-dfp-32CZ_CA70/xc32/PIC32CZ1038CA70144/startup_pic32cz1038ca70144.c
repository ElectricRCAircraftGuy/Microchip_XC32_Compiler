/**
 * \file
 *
 * \brief Startup code for PIC32CZ1038CA70144
 *
 * Copyright (c) 2018 Microchip Technology Inc.
 *
 * \license_start
 *
 * \page License
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
 * \license_stop
 *
 */

#include <xc.h>
#include <libpic32c.h>
#include <sys/cdefs.h>
#include <stdbool.h>

/*  
 *  Define the __XC32_RESET_HANDLER_NAME macro on the command line when you 
 *  want to use a different name for the Reset Handler function.
 */
#ifndef __XC32_RESET_HANDLER_NAME 
#define __XC32_RESET_HANDLER_NAME Reset_Handler
#endif /* __XC32_RESET_HANDLER_NAME */

__STATIC_INLINE void TCM_Disable(void);
__STATIC_INLINE void TCM_Enable(void);
__STATIC_INLINE void TCM_ConfigureSize(void);
__STATIC_INLINE void ICache_Enable(void);
__STATIC_INLINE void DCache_Enable(void);

/*
 *  The MPLAB X Simulator does not yet support simulation of programming the 
 *  GPNVM bits yet. We can remove this once it supports the FRDY bit.
 */
#ifdef __MPLAB_DEBUGGER_SIMULATOR
#define __XC32_SKIP_STARTUP_GPNVM_WAIT
#endif

/*
 *  This startup code relies on features that are specific to the MPLAB XC32
 *  toolchain. Do not use it with other toolchains.
 */
#ifndef __XC32
#warning This startup code is intended for use with the MPLAB XC32 Compiler only.
#endif

/** \brief  Instruction cache enable

 The function enables instruction caching.
 */
__STATIC_INLINE void ICache_Enable(void)
{
    SCB_EnableICache();
}

/** \brief  Data cache enable

 The function enables data caching.
 */
__STATIC_INLINE void DCache_Enable(void)
{
    SCB_EnableDCache();
}

/*
 *  Constants used for setting the GPNVM bits for TCM Size.
 */
#define GPNVM_TCM_SIZE_Pos        7u
#define GPNVM_TCM_SIZE_Msk        (0x3u << GPNVM_TCM_SIZE_Pos)
#define GPNVM_TCM_SIZE_0K_Val     (0x0u << GPNVM_TCM_SIZE_Pos)
#define GPNVM_TCM_SIZE_32K_Val    (0x1u << GPNVM_TCM_SIZE_Pos)
#define GPNVM_TCM_SIZE_64K_Val    (0x2u << GPNVM_TCM_SIZE_Pos)
#define GPNVM_TCM_SIZE_128K_Val   (0x3u << GPNVM_TCM_SIZE_Pos)

/** \brief  TCM memory enable

 The function enables TCM memories
 */
__STATIC_INLINE void __attribute__((optimize("-O1"))) TCM_Enable(void)
{
    __DSB();
    __ISB();
    SCB->ITCMCR = (SCB_ITCMCR_EN_Msk  | SCB_ITCMCR_RMW_Msk
                    | SCB_ITCMCR_RETEN_Msk);
    SCB->DTCMCR = (SCB_DTCMCR_EN_Msk | SCB_DTCMCR_RMW_Msk
                    | SCB_DTCMCR_RETEN_Msk);
    __DSB();
    __ISB();
}

/** \brief  TCM memory Disable
 
 The function disables TCM memories
 */
__STATIC_INLINE void __attribute__((optimize("-O1"))) TCM_Disable(void)
{
    /* Define the __XC32_SKIP_STARTUP_GPNVM preprocessor macro when you do not
     * want this code to modify the GPNVM bits at runtime.
     * Define the __XC32_SKIP_STARTUP_GPNVM_WAIT preprocessor macro when you do
     * not want the code to poll the FRDY bit before continuing.
     */
#if !defined(__XC32_SKIP_STARTUP_GPNVM)
    static uint32_t gpnvm_value;
    _EFC_REGS->EEFC_FCR.w = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_GGPB);
#if !defined(__XC32_SKIP_STARTUP_GPNVM_WAIT)
    while (!(_EFC_REGS->EEFC_FSR.w & EEFC_FSR_FRDY_Msk));
#endif
    gpnvm_value=_EFC_REGS->EEFC_FRR.w;

    /* 0K size of ITCM and DTCM */
    /* GPNVM bits[8:7] == b'00 */
    if ((gpnvm_value & GPNVM_TCM_SIZE_Msk) != GPNVM_TCM_SIZE_0K_Val)
    {
            _EFC_REGS->EEFC_FCR.w = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB
                            | EEFC_FCR_FARG(8));
#if !defined(__XC32_SKIP_STARTUP_GPNVM_WAIT)
            while (!(_EFC_REGS->EEFC_FSR.w & EEFC_FSR_FRDY_Msk));
#endif
            _EFC_REGS->EEFC_FCR.w = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB
                            | EEFC_FCR_FARG(7));
#if !defined(__XC32_SKIP_STARTUP_GPNVM_WAIT)
            while (!(_EFC_REGS->EEFC_FSR.w & EEFC_FSR_FRDY_Msk));
            _RSTC_REGS->RSTC_CR.w = RSTC_CR_KEY_PASSWD | RSTC_CR_PROCRST_Msk;
#endif
    }
#endif /* !defined(__XC32_SKIP_STARTUP_GPNVM) */
    __DSB();
    __ISB();
    SCB->ITCMCR &= ~(uint32_t)SCB_ITCMCR_EN_Msk;
    SCB->DTCMCR &= ~(uint32_t)SCB_ITCMCR_EN_Msk;
    __DSB();
    __ISB();
}

/** \brief  TCM memory configure size
 
 The function configures size of TCM memory based on __XC32_ITCM_LENGTH macro
 */
__STATIC_INLINE void __attribute__((optimize("-O1"))) TCM_ConfigureSize(void)
{
    /* Define the __XC32_SKIP_STARTUP_GPNVM preprocessor macro when you do not
     * want this code to modify the GPNVM bits at runtime.
     * Define the __XC32_SKIP_STARTUP_GPNVM_WAIT preprocessor macro when you do
     * not want the code to poll the FRDY bit before continuing.
     */
#if !defined(__XC32_SKIP_STARTUP_GPNVM)
#if defined(__XC32_ITCM_LENGTH)
    static uint32_t gpnvm_value;
    _EFC_REGS->EEFC_FCR.w = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_GGPB);
#if !defined(__XC32_SKIP_STARTUP_GPNVM_WAIT)
    while (!(_EFC_REGS->EEFC_FSR.w & EEFC_FSR_FRDY_Msk));
#endif
    gpnvm_value=_EFC_REGS->EEFC_FRR.w;

# if (__XC32_ITCM_LENGTH == 0x8000)
    /* 32K default size of ITCM and DTCM */
    /* GPNVM bits[8:7] == b'01 */
    if ((gpnvm_value & GPNVM_TCM_SIZE_Msk) != GPNVM_TCM_SIZE_32K_Val)
    {
      _EFC_REGS->EEFC_FCR.w = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB
                              | EEFC_FCR_FARG(8));
#if !defined(__XC32_SKIP_STARTUP_GPNVM_WAIT)
      while (!(_EFC_REGS->EEFC_FSR.w & EEFC_FSR_FRDY_Msk));
#endif
      _EFC_REGS->EEFC_FCR.w = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_SGPB
                              | EEFC_FCR_FARG(7));
#if !defined(__XC32_SKIP_STARTUP_GPNVM_WAIT)
      while (!(_EFC_REGS->EEFC_FSR.w & EEFC_FSR_FRDY_Msk));
      _RSTC_REGS->RSTC_CR.w = RSTC_CR_KEY_PASSWD | RSTC_CR_PROCRST_Msk;
#endif
    }
# elif (__XC32_ITCM_LENGTH == 0x10000)
    /* 64K */
    /* GPNVM bits[8:7] == b'10 */
    if ((gpnvm_value & GPNVM_TCM_SIZE_Msk) != GPNVM_TCM_SIZE_64K_Val)
    {
      _EFC_REGS->EEFC_FCR.w = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_SGPB
                              | EEFC_FCR_FARG(8));
#if !defined(__XC32_SKIP_STARTUP_GPNVM_WAIT)
      while (!(_EFC_REGS->EEFC_FSR.w & EEFC_FSR_FRDY_Msk));
#endif
      _EFC_REGS->EEFC_FCR.w = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB
                              | EEFC_FCR_FARG(7));
#if !defined(__XC32_SKIP_STARTUP_GPNVM_WAIT)
      while (!(_EFC_REGS->EEFC_FSR.w & EEFC_FSR_FRDY_Msk));
      _RSTC_REGS->RSTC_CR.w = RSTC_CR_KEY_PASSWD | RSTC_CR_PROCRST_Msk;
#endif
    }
# elif (__XC32_ITCM_LENGTH == 0x20000)
    /* 128K */
    /* GPNVM bits[8:7] == b'11 */
    if ((gpnvm_value & GPNVM_TCM_SIZE_Msk) != GPNVM_TCM_SIZE_128K_Val)
    {
      _EFC_REGS->EEFC_FCR.w = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_SGPB
                              | EEFC_FCR_FARG(8));
#if !defined(__XC32_SKIP_STARTUP_GPNVM_WAIT)
      while (!(_EFC_REGS->EEFC_FSR.w & EEFC_FSR_FRDY_Msk));
#endif
      _EFC_REGS->EEFC_FCR.w = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_SGPB
                              | EEFC_FCR_FARG(7));
#if !defined(__XC32_SKIP_STARTUP_GPNVM_WAIT)
      while (!(_EFC_REGS->EEFC_FSR.w & EEFC_FSR_FRDY_Msk));
      _RSTC_REGS->RSTC_CR.w = RSTC_CR_KEY_PASSWD | RSTC_CR_PROCRST_Msk;
#endif
    }
# endif /* __XC32_ITCM_LENGTH == value */
#endif /* defined(__XC32_ITCM_LENGTH) */
#endif /* !defined(__XC32_SKIP_STARTUP_GPNVM) */
}


/* Initialize segments */
extern uint32_t __svectors;
extern uint32_t _stack;
extern uint32_t _dinit_size;
extern uint32_t _dinit_addr;

/** \cond DOXYGEN_SHOULD_SKIP_THIS */
int main(void);
/** \endcond */

extern void __attribute__((long_call)) __libc_init_array(void);

/* Default empty handler */
void __attribute__((weak, optimize("-O1"), long_call)) Dummy_Handler(void);

/* Reset handler and application-provided reset handler */
void __attribute__((weak, optimize("-O1"), long_call)) Reset_Handler(void);
extern void __attribute__((weak, long_call)) __XC32_RESET_HANDLER_NAME(void);

/* Cortex-M7 core handlers */
void NonMaskableInt_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void HardFault_Handler    ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void MemoryManagement_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void BusFault_Handler     ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UsageFault_Handler   ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SVCall_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DebugMonitor_Handler ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PendSV_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SysTick_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

/* Peripherals handlers */
void SUPC_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RSTC_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RTC_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RTT_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void WDT_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PMC_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EFC_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART0_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART1_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PORTA_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PORTB_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PORTC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART0_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART1_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USART2_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PORTD_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PORTE_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void HSMCI_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI0_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI1_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SPI0_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SSC_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_CH0_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_CH1_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_CH2_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_CH0_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_CH1_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_CH2_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AFEC0_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DACC_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWMC0_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ICM_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ACC_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USBHS_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void MCAN0_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void MCAN1_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void GMAC_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AFEC1_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TWI2_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SPI1_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void QSPI_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART2_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART3_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void UART4_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_CH0_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_CH1_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_CH2_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC3_CH0_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC3_CH1_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC3_CH2_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void MLB_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AES_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TRNG_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void XDMAC_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ISI_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PWMC1_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SDRAMC_Handler       ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RSWDT_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void I2SC0_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void I2SC1_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

/* Exception Table */
__attribute__ ((section(".vectors"),weak))
const DeviceVectors exception_table=
{
        /* Configure Initial Stack Pointer, using linker-generated symbols */
        .pvStack = (void*) (&_stack),

        .pfnReset_Handler              = (void*) __XC32_RESET_HANDLER_NAME,
        .pfnNonMaskableInt_Handler     = (void*) NonMaskableInt_Handler,
        .pfnHardFault_Handler          = (void*) HardFault_Handler,
        .pfnMemoryManagement_Handler   = (void*) MemoryManagement_Handler,
        .pfnBusFault_Handler           = (void*) BusFault_Handler,
        .pfnUsageFault_Handler         = (void*) UsageFault_Handler,
        .pvReservedC9                  = (void*) (0UL), /* Reserved */
        .pvReservedC8                  = (void*) (0UL), /* Reserved */
        .pvReservedC7                  = (void*) (0UL), /* Reserved */
        .pvReservedC6                  = (void*) (0UL), /* Reserved */
        .pfnSVCall_Handler             = (void*) SVCall_Handler,
        .pfnDebugMonitor_Handler       = (void*) DebugMonitor_Handler,
        .pvReservedC3                  = (void*) (0UL), /* Reserved */
        .pfnPendSV_Handler             = (void*) PendSV_Handler,
        .pfnSysTick_Handler            = (void*) SysTick_Handler,

        /* Configurable interrupts */
        .pfnSUPC_Handler               = (void*) SUPC_Handler,   /* 0  Supply Controller */
        .pfnRSTC_Handler               = (void*) RSTC_Handler,   /* 1  Reset Controller */
        .pfnRTC_Handler                = (void*) RTC_Handler,    /* 2  Real-time Clock */
        .pfnRTT_Handler                = (void*) RTT_Handler,    /* 3  Real-time Timer */
        .pfnWDT_Handler                = (void*) WDT_Handler,    /* 4  Watchdog Timer */
        .pfnPMC_Handler                = (void*) PMC_Handler,    /* 5  Power Management Controller */
        .pfnEFC_Handler                = (void*) EFC_Handler,    /* 6  Embedded Flash Controller */
        .pfnUART0_Handler              = (void*) UART0_Handler,  /* 7  Universal Asynchronous Receiver Transmitter */
        .pfnUART1_Handler              = (void*) UART1_Handler,  /* 8  Universal Asynchronous Receiver Transmitter */
        .pvReserved9                   = (void*) (0UL),          /* 9  Reserved */
        .pfnPORTA_Handler              = (void*) PORTA_Handler,  /* 10 Port */
        .pfnPORTB_Handler              = (void*) PORTB_Handler,  /* 11 Port */
        .pfnPORTC_Handler              = (void*) PORTC_Handler,  /* 12 Port */
        .pfnUSART0_Handler             = (void*) USART0_Handler, /* 13 Universal Synchronous Asynchronous Receiver Transmitter */
        .pfnUSART1_Handler             = (void*) USART1_Handler, /* 14 Universal Synchronous Asynchronous Receiver Transmitter */
        .pfnUSART2_Handler             = (void*) USART2_Handler, /* 15 Universal Synchronous Asynchronous Receiver Transmitter */
        .pfnPORTD_Handler              = (void*) PORTD_Handler,  /* 16 Port */
        .pfnPORTE_Handler              = (void*) PORTE_Handler,  /* 17 Port */
        .pfnHSMCI_Handler              = (void*) HSMCI_Handler,  /* 18 High Speed MultiMedia Card Interface */
        .pfnTWI0_Handler               = (void*) TWI0_Handler,   /* 19 Two-wire Interface */
        .pfnTWI1_Handler               = (void*) TWI1_Handler,   /* 20 Two-wire Interface */
        .pfnSPI0_Handler               = (void*) SPI0_Handler,   /* 21 Serial Peripheral Interface */
        .pfnSSC_Handler                = (void*) SSC_Handler,    /* 22 Synchronous Serial Controller */
        .pfnTC0_CH0_Handler            = (void*) TC0_CH0_Handler, /* 23 Timer Counter */
        .pfnTC0_CH1_Handler            = (void*) TC0_CH1_Handler, /* 24 Timer Counter */
        .pfnTC0_CH2_Handler            = (void*) TC0_CH2_Handler, /* 25 Timer Counter */
        .pfnTC1_CH0_Handler            = (void*) TC1_CH0_Handler, /* 26 Timer Counter */
        .pfnTC1_CH1_Handler            = (void*) TC1_CH1_Handler, /* 27 Timer Counter */
        .pfnTC1_CH2_Handler            = (void*) TC1_CH2_Handler, /* 28 Timer Counter */
        .pfnAFEC0_Handler              = (void*) AFEC0_Handler,  /* 29 Analog Front-End Controller */
        .pfnDACC_Handler               = (void*) DACC_Handler,   /* 30 Digital-to-Analog Converter Controller */
        .pfnPWMC0_Handler              = (void*) PWMC0_Handler,  /* 31 Pulse Width Modulation Controller */
        .pfnICM_Handler                = (void*) ICM_Handler,    /* 32 Integrity Check Monitor */
        .pfnACC_Handler                = (void*) ACC_Handler,    /* 33 Analog Comparator Controller */
        .pfnUSBHS_Handler              = (void*) USBHS_Handler,  /* 34 USB High-Speed Interface */
        .pfnMCAN0_Handler              = (void*) MCAN0_Handler,  /* 35 Controller Area Network */
        .pvReserved36                  = (void*) (0UL),          /* 36 Reserved */
        .pfnMCAN1_Handler              = (void*) MCAN1_Handler,  /* 37 Controller Area Network */
        .pvReserved38                  = (void*) (0UL),          /* 38 Reserved */
        .pfnGMAC_Handler               = (void*) GMAC_Handler,   /* 39 Gigabit Ethernet MAC */
        .pfnAFEC1_Handler              = (void*) AFEC1_Handler,  /* 40 Analog Front-End Controller */
        .pfnTWI2_Handler               = (void*) TWI2_Handler,   /* 41 Two-wire Interface */
        .pfnSPI1_Handler               = (void*) SPI1_Handler,   /* 42 Serial Peripheral Interface */
        .pfnQSPI_Handler               = (void*) QSPI_Handler,   /* 43 Quad Serial Peripheral Interface */
        .pfnUART2_Handler              = (void*) UART2_Handler,  /* 44 Universal Asynchronous Receiver Transmitter */
        .pfnUART3_Handler              = (void*) UART3_Handler,  /* 45 Universal Asynchronous Receiver Transmitter */
        .pfnUART4_Handler              = (void*) UART4_Handler,  /* 46 Universal Asynchronous Receiver Transmitter */
        .pfnTC2_CH0_Handler            = (void*) TC2_CH0_Handler, /* 47 Timer Counter */
        .pfnTC2_CH1_Handler            = (void*) TC2_CH1_Handler, /* 48 Timer Counter */
        .pfnTC2_CH2_Handler            = (void*) TC2_CH2_Handler, /* 49 Timer Counter */
        .pfnTC3_CH0_Handler            = (void*) TC3_CH0_Handler, /* 50 Timer Counter */
        .pfnTC3_CH1_Handler            = (void*) TC3_CH1_Handler, /* 51 Timer Counter */
        .pfnTC3_CH2_Handler            = (void*) TC3_CH2_Handler, /* 52 Timer Counter */
        .pfnMLB_Handler                = (void*) MLB_Handler,    /* 53 MediaLB */
        .pvReserved54                  = (void*) (0UL),          /* 54 Reserved */
        .pvReserved55                  = (void*) (0UL),          /* 55 Reserved */
        .pfnAES_Handler                = (void*) AES_Handler,    /* 56 Advanced Encryption Standard */
        .pfnTRNG_Handler               = (void*) TRNG_Handler,   /* 57 True Random Number Generator */
        .pfnXDMAC_Handler              = (void*) XDMAC_Handler,  /* 58 Extensible DMA Controller */
        .pfnISI_Handler                = (void*) ISI_Handler,    /* 59 Image Sensor Interface */
        .pfnPWMC1_Handler              = (void*) PWMC1_Handler,  /* 60 Pulse Width Modulation Controller */
        .pvReserved61                  = (void*) (0UL),          /* 61 Reserved */
        .pfnSDRAMC_Handler             = (void*) SDRAMC_Handler, /* 62 SDRAM Controller */
        .pfnRSWDT_Handler              = (void*) RSWDT_Handler,  /* 63 Reinforced Safety Watchdog Timer */
        .pvReserved64                  = (void*) (0UL),          /* 64 Reserved */
        .pvReserved65                  = (void*) (0UL),          /* 65 Reserved */
        .pvReserved66                  = (void*) (0UL),          /* 66 Reserved */
        .pvReserved67                  = (void*) (0UL),          /* 67 Reserved */
        .pvReserved68                  = (void*) (0UL),          /* 68 Reserved */
        .pfnI2SC0_Handler              = (void*) I2SC0_Handler,  /* 69 Inter-IC Sound Controller */
        .pfnI2SC1_Handler              = (void*) I2SC1_Handler   /* 70 Inter-IC Sound Controller */
};

#if (__ARM_FP==14) || (__ARM_FP==4)
/* These functions are used only when compiling with -mfloat-abi=softfp or -mfloat-abi=hard */
/* Save and restore IRQs */
typedef uint32_t irqflags_t;
static bool g_interrupt_enabled;
#define cpu_irq_is_enabled()    (__get_PRIMASK() == 0)
#  define cpu_irq_enable()                             \
        do {                                           \
                g_interrupt_enabled = true;            \
                __DMB();                               \
                __enable_irq();                        \
        } while (0)
#  define cpu_irq_disable()                            \
        do {                                           \
                __disable_irq();                       \
                __DMB();                               \
                g_interrupt_enabled = false;           \
        } while (0)
__always_inline __STATIC_INLINE bool __attribute__((optimize("-O1"))) cpu_irq_is_enabled_flags(irqflags_t flags)
{
        return (flags);
}
__always_inline __STATIC_INLINE void __attribute__((optimize("-O1"))) cpu_irq_restore(irqflags_t flags)
{
        if (cpu_irq_is_enabled_flags(flags))
                cpu_irq_enable();
}
__always_inline __STATIC_INLINE __attribute__((optimize("-O1"))) irqflags_t cpu_irq_save(void)
{
        volatile irqflags_t flags = cpu_irq_is_enabled();
        cpu_irq_disable();
        return flags;
}

/** Address for ARM CPACR */
#define ADDR_CPACR 0xE000ED88
/** CPACR Register */
#define REG_CPACR  (*((volatile uint32_t *)ADDR_CPACR))

/**
* \brief Enable FPU
*/
__always_inline __STATIC_INLINE void __attribute__((optimize("-O1"))) fpu_enable(void)
{
    irqflags_t flags;
    flags = cpu_irq_save();
    REG_CPACR |=  (0xFu << 20);
    __DSB();
    __ISB();
    cpu_irq_restore(flags);
}
#endif /* (__ARM_FP==14) || (__ARM_FP==4) */
 
/* Optional application-provided functions */
extern void __attribute__((weak,long_call)) _on_reset(void);
extern void __attribute__((weak,long_call)) _on_bootstrap(void);

/**
 * \brief This is the code that gets called on processor reset.
 * To initialize the device, and call the main() routine.
 */
void __attribute__((weak, optimize("-O1"), section(".text.Reset_Handler"), long_call)) 
Reset_Handler(void)
{
    uint32_t *pSrc;

    /* Call the optional application-provided _on_reset() function. */
    if (_on_reset)
      _on_reset();

#if (__ARM_FP==14) || (__ARM_FP==4)
    /* Enable the FPU iff the application is built with -mfloat-abi=softfp or -mfloat-abi=hard */
    fpu_enable();
#endif
 
#if !defined(__XC32_SKIP_CACHE_INIT)
    /* Enable Caches */
# if (__ICACHE_PRESENT==1U)
    ICache_Enable();
#endif
# if (__DCACHE_PRESENT==1U)
    DCache_Enable();
#endif
#endif

    /* TCM config and init */
#if (__ITCM_PRESENT==1)
#ifdef __XC32_ENABLE_TCM
    TCM_ConfigureSize();
    TCM_Enable();
#else
    TCM_Disable();
#endif /* __XC32_ENABLE_TCM */
#endif /* (__ITCM_PRESENT==1) */
    /* Initialize data after TCM is enabled */
 
    /* Data initialization from the XC32 .dinit template */
    __pic32c_data_initialization();
#if defined(__XC32_STACK_IN_TCM)
    __pic32c_TCM_StackInit();
#endif
 
#ifdef SCB_VTOR_TBLOFF_Msk
    /*  Set the vector-table base address. This may be in flash or TCM. 
     *  The __svectors symbol is created by the XC32 linker.
     */
    pSrc = (uint32_t *) & __svectors;
    SCB->VTOR = ((uint32_t) pSrc & SCB_VTOR_TBLOFF_Msk);
#endif 
 
    /* Initialize the C library */
    __libc_init_array();
    
    /* Call the optional application-provided _on_bootstrap() function. */
    if (_on_bootstrap)
      _on_bootstrap();

    /* Branch to application's main function */
    main();

#if (defined(__DEBUG) || defined(__DEBUG_D)) && defined(__THUMB2__)
    __builtin_software_breakpoint();
#endif
    /* Infinite loop */
    while (1) {}
}

/**
* \brief Default interrupt handler for unused IRQs.
*/
void __attribute__((weak,optimize("-O1"),section(".text.Dummy_Handler"),long_call)) 
Dummy_Handler(void)
{
#if (defined(__DEBUG) || defined(__DEBUG_D)) && defined(__THUMB2__)
    __builtin_software_breakpoint();
#endif
    while (1) {}
}
