/**
 * \brief Component description for PIC32CZ/CA70 UTMI
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
#ifndef _PIC32CZ_CA70_UTMI_COMPONENT_H_
#define _PIC32CZ_CA70_UTMI_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_UTMI USB Transmitter Interface Macrocell
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR UTMI */
/* ========================================================================== */

/* -------- UTMI_OHCIICR : (UTMI Offset: 0x10) (R/W 32) OHCI Interrupt Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t RES0:1;                    /**< bit:      0  USB PORTx Reset                               */
    uint32_t :3;                        /**< bit:   1..3  Reserved                                      */
    uint32_t ARIE:1;                    /**< bit:      4  OHCI Asynchronous Resume Interrupt Enable     */
    uint32_t APPSTART:1;                /**< bit:      5  Reserved                                      */
    uint32_t :17;                       /**< bit:  6..22  Reserved                                      */
    uint32_t UDPPUDIS:1;                /**< bit:     23  USB Device Pull-up Disable                    */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __UTMI_OHCIICR_bits_t;

#define UTMI_OHCIICR_RES0_Pos                 (0)                                            /**< (UTMI_OHCIICR) USB PORTx Reset Position */
#define UTMI_OHCIICR_RES0_Msk                 (0x1U << UTMI_OHCIICR_RES0_Pos)                /**< (UTMI_OHCIICR) USB PORTx Reset Mask */
#define UTMI_OHCIICR_ARIE_Pos                 (4)                                            /**< (UTMI_OHCIICR) OHCI Asynchronous Resume Interrupt Enable Position */
#define UTMI_OHCIICR_ARIE_Msk                 (0x1U << UTMI_OHCIICR_ARIE_Pos)                /**< (UTMI_OHCIICR) OHCI Asynchronous Resume Interrupt Enable Mask */
#define UTMI_OHCIICR_APPSTART_Pos             (5)                                            /**< (UTMI_OHCIICR) Reserved Position */
#define UTMI_OHCIICR_APPSTART_Msk             (0x1U << UTMI_OHCIICR_APPSTART_Pos)            /**< (UTMI_OHCIICR) Reserved Mask */
#define UTMI_OHCIICR_UDPPUDIS_Pos             (23)                                           /**< (UTMI_OHCIICR) USB Device Pull-up Disable Position */
#define UTMI_OHCIICR_UDPPUDIS_Msk             (0x1U << UTMI_OHCIICR_UDPPUDIS_Pos)            /**< (UTMI_OHCIICR) USB Device Pull-up Disable Mask */
#define UTMI_OHCIICR_Msk                      (0x00800031UL)                                 /**< (UTMI_OHCIICR) Register Mask  */

/* -------- UTMI_CKTRIM : (UTMI Offset: 0x30) (R/W 32) UTMI Clock Trimming Register -------- */

typedef union
{
  struct
  {
    uint32_t FREQ:2;                    /**< bit:   0..1  UTMI Reference Clock Frequency                */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  uint32_t w;
} __UTMI_CKTRIM_bits_t;

#define UTMI_CKTRIM_FREQ_Pos                  (0)                                            /**< (UTMI_CKTRIM) UTMI Reference Clock Frequency Position */
#define UTMI_CKTRIM_FREQ_Msk                  (0x3U << UTMI_CKTRIM_FREQ_Pos)                 /**< (UTMI_CKTRIM) UTMI Reference Clock Frequency Mask */
#define UTMI_CKTRIM_FREQ(value)               (UTMI_CKTRIM_FREQ_Msk & ((value) << UTMI_CKTRIM_FREQ_Pos))
#define   UTMI_CKTRIM_FREQ_XTAL12_Val         (0x0U)                                         /**< (UTMI_CKTRIM) 12 MHz reference clock  */
#define   UTMI_CKTRIM_FREQ_XTAL16_Val         (0x1U)                                         /**< (UTMI_CKTRIM) 16 MHz reference clock  */
#define UTMI_CKTRIM_FREQ_XTAL12               (UTMI_CKTRIM_FREQ_XTAL12_Val << UTMI_CKTRIM_FREQ_Pos)  /**< (UTMI_CKTRIM) 12 MHz reference clock Position  */
#define UTMI_CKTRIM_FREQ_XTAL16               (UTMI_CKTRIM_FREQ_XTAL16_Val << UTMI_CKTRIM_FREQ_Pos)  /**< (UTMI_CKTRIM) 16 MHz reference clock Position  */
#define UTMI_CKTRIM_Msk                       (0x00000003UL)                                 /**< (UTMI_CKTRIM) Register Mask  */

/** \brief UTMI register offsets definitions */
#define UTMI_OHCIICR_OFFSET          (0x10)         /**< (UTMI_OHCIICR) OHCI Interrupt Configuration Register Offset */
#define UTMI_CKTRIM_OFFSET           (0x30)         /**< (UTMI_CKTRIM) UTMI Clock Trimming Register Offset */

/** \brief UTMI register API structure */
typedef struct
{
  __I   uint8_t                        Reserved1[0x10];
  __IO  __UTMI_OHCIICR_bits_t          UTMI_OHCIICR;  /**< Offset: 0x10 (R/W  32) OHCI Interrupt Configuration Register */
  __I   uint8_t                        Reserved2[0x1C];
  __IO  __UTMI_CKTRIM_bits_t           UTMI_CKTRIM;   /**< Offset: 0x30 (R/W  32) UTMI Clock Trimming Register */
} utmi_registers_t;
/** @}  end of USB Transmitter Interface Macrocell */

#endif /* _PIC32CZ_CA70_UTMI_COMPONENT_H_ */
