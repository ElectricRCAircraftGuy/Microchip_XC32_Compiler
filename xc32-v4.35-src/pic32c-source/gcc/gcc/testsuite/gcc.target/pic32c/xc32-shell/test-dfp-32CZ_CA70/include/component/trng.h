/**
 * \brief Component description for PIC32CZ/CA70 TRNG
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
#ifndef _PIC32CZ_CA70_TRNG_COMPONENT_H_
#define _PIC32CZ_CA70_TRNG_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_TRNG True Random Number Generator
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR TRNG */
/* ========================================================================== */

/* -------- TRNG_CR : (TRNG Offset: 0x00) (/W 32) Control Register -------- */

typedef union
{
  struct
  {
    uint32_t ENABLE:1;                  /**< bit:      0  Enables the TRNG to Provide Random Values     */
    uint32_t :7;                        /**< bit:   1..7  Reserved                                      */
    uint32_t KEY:24;                    /**< bit:  8..31  Security Key                                  */
  };
  uint32_t w;
} __TRNG_CR_bits_t;

#define TRNG_CR_ENABLE_Pos                    (0)                                            /**< (TRNG_CR) Enables the TRNG to Provide Random Values Position */
#define TRNG_CR_ENABLE_Msk                    (0x1U << TRNG_CR_ENABLE_Pos)                   /**< (TRNG_CR) Enables the TRNG to Provide Random Values Mask */
#define TRNG_CR_KEY_Pos                       (8)                                            /**< (TRNG_CR) Security Key Position */
#define TRNG_CR_KEY_Msk                       (0xFFFFFFU << TRNG_CR_KEY_Pos)                 /**< (TRNG_CR) Security Key Mask */
#define TRNG_CR_KEY(value)                    (TRNG_CR_KEY_Msk & ((value) << TRNG_CR_KEY_Pos))
#define   TRNG_CR_KEY_PASSWD_Val              (0x524E47U)                                    /**< (TRNG_CR) Writing any other value in this field aborts the write operation.  */
#define TRNG_CR_KEY_PASSWD                    (TRNG_CR_KEY_PASSWD_Val << TRNG_CR_KEY_Pos)    /**< (TRNG_CR) Writing any other value in this field aborts the write operation. Position  */
#define TRNG_CR_Msk                           (0xFFFFFF01UL)                                 /**< (TRNG_CR) Register Mask  */

/* -------- TRNG_IER : (TRNG Offset: 0x10) (/W 32) Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t DATRDY:1;                  /**< bit:      0  Data Ready Interrupt Enable                   */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __TRNG_IER_bits_t;

#define TRNG_IER_DATRDY_Pos                   (0)                                            /**< (TRNG_IER) Data Ready Interrupt Enable Position */
#define TRNG_IER_DATRDY_Msk                   (0x1U << TRNG_IER_DATRDY_Pos)                  /**< (TRNG_IER) Data Ready Interrupt Enable Mask */
#define TRNG_IER_Msk                          (0x00000001UL)                                 /**< (TRNG_IER) Register Mask  */

/* -------- TRNG_IDR : (TRNG Offset: 0x14) (/W 32) Interrupt Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t DATRDY:1;                  /**< bit:      0  Data Ready Interrupt Disable                  */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __TRNG_IDR_bits_t;

#define TRNG_IDR_DATRDY_Pos                   (0)                                            /**< (TRNG_IDR) Data Ready Interrupt Disable Position */
#define TRNG_IDR_DATRDY_Msk                   (0x1U << TRNG_IDR_DATRDY_Pos)                  /**< (TRNG_IDR) Data Ready Interrupt Disable Mask */
#define TRNG_IDR_Msk                          (0x00000001UL)                                 /**< (TRNG_IDR) Register Mask  */

/* -------- TRNG_IMR : (TRNG Offset: 0x18) (R/ 32) Interrupt Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t DATRDY:1;                  /**< bit:      0  Data Ready Interrupt Mask                     */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __TRNG_IMR_bits_t;

#define TRNG_IMR_DATRDY_Pos                   (0)                                            /**< (TRNG_IMR) Data Ready Interrupt Mask Position */
#define TRNG_IMR_DATRDY_Msk                   (0x1U << TRNG_IMR_DATRDY_Pos)                  /**< (TRNG_IMR) Data Ready Interrupt Mask Mask */
#define TRNG_IMR_Msk                          (0x00000001UL)                                 /**< (TRNG_IMR) Register Mask  */

/* -------- TRNG_ISR : (TRNG Offset: 0x1c) (R/ 32) Interrupt Status Register -------- */

typedef union
{
  struct
  {
    uint32_t DATRDY:1;                  /**< bit:      0  Data Ready                                    */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __TRNG_ISR_bits_t;

#define TRNG_ISR_DATRDY_Pos                   (0)                                            /**< (TRNG_ISR) Data Ready Position */
#define TRNG_ISR_DATRDY_Msk                   (0x1U << TRNG_ISR_DATRDY_Pos)                  /**< (TRNG_ISR) Data Ready Mask */
#define TRNG_ISR_Msk                          (0x00000001UL)                                 /**< (TRNG_ISR) Register Mask  */

/* -------- TRNG_ODATA : (TRNG Offset: 0x50) (R/ 32) Output Data Register -------- */

typedef union
{
  struct
  {
    uint32_t ODATA:32;                  /**< bit:  0..31  Output Data                                   */
  };
  uint32_t w;
} __TRNG_ODATA_bits_t;

#define TRNG_ODATA_ODATA_Pos                  (0)                                            /**< (TRNG_ODATA) Output Data Position */
#define TRNG_ODATA_ODATA_Msk                  (0xFFFFFFFFU << TRNG_ODATA_ODATA_Pos)          /**< (TRNG_ODATA) Output Data Mask */
#define TRNG_ODATA_ODATA(value)               (TRNG_ODATA_ODATA_Msk & ((value) << TRNG_ODATA_ODATA_Pos))
#define TRNG_ODATA_Msk                        (0xFFFFFFFFUL)                                 /**< (TRNG_ODATA) Register Mask  */

/** \brief TRNG register offsets definitions */
#define TRNG_CR_OFFSET               (0x00)         /**< (TRNG_CR) Control Register Offset */
#define TRNG_IER_OFFSET              (0x10)         /**< (TRNG_IER) Interrupt Enable Register Offset */
#define TRNG_IDR_OFFSET              (0x14)         /**< (TRNG_IDR) Interrupt Disable Register Offset */
#define TRNG_IMR_OFFSET              (0x18)         /**< (TRNG_IMR) Interrupt Mask Register Offset */
#define TRNG_ISR_OFFSET              (0x1C)         /**< (TRNG_ISR) Interrupt Status Register Offset */
#define TRNG_ODATA_OFFSET            (0x50)         /**< (TRNG_ODATA) Output Data Register Offset */

/** \brief TRNG register API structure */
typedef struct
{
  __O   __TRNG_CR_bits_t               TRNG_CR;       /**< Offset: 0x00 ( /W  32) Control Register */
  __I   uint8_t                        Reserved1[0x0C];
  __O   __TRNG_IER_bits_t              TRNG_IER;      /**< Offset: 0x10 ( /W  32) Interrupt Enable Register */
  __O   __TRNG_IDR_bits_t              TRNG_IDR;      /**< Offset: 0x14 ( /W  32) Interrupt Disable Register */
  __I   __TRNG_IMR_bits_t              TRNG_IMR;      /**< Offset: 0x18 (R/   32) Interrupt Mask Register */
  __I   __TRNG_ISR_bits_t              TRNG_ISR;      /**< Offset: 0x1C (R/   32) Interrupt Status Register */
  __I   uint8_t                        Reserved2[0x30];
  __I   __TRNG_ODATA_bits_t            TRNG_ODATA;    /**< Offset: 0x50 (R/   32) Output Data Register */
} trng_registers_t;
/** @}  end of True Random Number Generator */

#endif /* _PIC32CZ_CA70_TRNG_COMPONENT_H_ */
