/**
 * \brief Component description for PIC32CZ/CA70 WDT
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
#ifndef _PIC32CZ_CA70_WDT_COMPONENT_H_
#define _PIC32CZ_CA70_WDT_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_WDT Watchdog Timer
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR WDT */
/* ========================================================================== */

/* -------- WDT_CR : (WDT Offset: 0x00) (/W 32) Control Register -------- */

typedef union
{
  struct
  {
    uint32_t WDRSTT:1;                  /**< bit:      0  Watchdog Restart                              */
    uint32_t :3;                        /**< bit:   1..3  Reserved                                      */
    uint32_t LOCKMR:1;                  /**< bit:      4  Lock Mode Register Write Access               */
    uint32_t :19;                       /**< bit:  5..23  Reserved                                      */
    uint32_t KEY:8;                     /**< bit: 24..31  Password                                      */
  };
  uint32_t w;
} __WDT_CR_bits_t;

#define WDT_CR_WDRSTT_Pos                     (0)                                            /**< (WDT_CR) Watchdog Restart Position */
#define WDT_CR_WDRSTT_Msk                     (0x1U << WDT_CR_WDRSTT_Pos)                    /**< (WDT_CR) Watchdog Restart Mask */
#define WDT_CR_LOCKMR_Pos                     (4)                                            /**< (WDT_CR) Lock Mode Register Write Access Position */
#define WDT_CR_LOCKMR_Msk                     (0x1U << WDT_CR_LOCKMR_Pos)                    /**< (WDT_CR) Lock Mode Register Write Access Mask */
#define WDT_CR_KEY_Pos                        (24)                                           /**< (WDT_CR) Password Position */
#define WDT_CR_KEY_Msk                        (0xFFU << WDT_CR_KEY_Pos)                      /**< (WDT_CR) Password Mask */
#define WDT_CR_KEY(value)                     (WDT_CR_KEY_Msk & ((value) << WDT_CR_KEY_Pos))
#define   WDT_CR_KEY_PASSWD_Val               (0xA5U)                                        /**< (WDT_CR) Writing any other value in this field aborts the write operation.  */
#define WDT_CR_KEY_PASSWD                     (WDT_CR_KEY_PASSWD_Val << WDT_CR_KEY_Pos)      /**< (WDT_CR) Writing any other value in this field aborts the write operation. Position  */
#define WDT_CR_Msk                            (0xFF000011UL)                                 /**< (WDT_CR) Register Mask  */

/* -------- WDT_MR : (WDT Offset: 0x04) (R/W 32) Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t WDV:12;                    /**< bit:  0..11  Watchdog Counter Value                        */
    uint32_t WDFIEN:1;                  /**< bit:     12  Watchdog Fault Interrupt Enable               */
    uint32_t WDRSTEN:1;                 /**< bit:     13  Watchdog Reset Enable                         */
    uint32_t :1;                        /**< bit:     14  Reserved                                      */
    uint32_t WDDIS:1;                   /**< bit:     15  Watchdog Disable                              */
    uint32_t WDD:12;                    /**< bit: 16..27  Watchdog Delta Value                          */
    uint32_t WDDBGHLT:1;                /**< bit:     28  Watchdog Debug Halt                           */
    uint32_t WDIDLEHLT:1;               /**< bit:     29  Watchdog Idle Halt                            */
    uint32_t :2;                        /**< bit: 30..31  Reserved                                      */
  };
  uint32_t w;
} __WDT_MR_bits_t;

#define WDT_MR_WDV_Pos                        (0)                                            /**< (WDT_MR) Watchdog Counter Value Position */
#define WDT_MR_WDV_Msk                        (0xFFFU << WDT_MR_WDV_Pos)                     /**< (WDT_MR) Watchdog Counter Value Mask */
#define WDT_MR_WDV(value)                     (WDT_MR_WDV_Msk & ((value) << WDT_MR_WDV_Pos))
#define WDT_MR_WDFIEN_Pos                     (12)                                           /**< (WDT_MR) Watchdog Fault Interrupt Enable Position */
#define WDT_MR_WDFIEN_Msk                     (0x1U << WDT_MR_WDFIEN_Pos)                    /**< (WDT_MR) Watchdog Fault Interrupt Enable Mask */
#define WDT_MR_WDRSTEN_Pos                    (13)                                           /**< (WDT_MR) Watchdog Reset Enable Position */
#define WDT_MR_WDRSTEN_Msk                    (0x1U << WDT_MR_WDRSTEN_Pos)                   /**< (WDT_MR) Watchdog Reset Enable Mask */
#define WDT_MR_WDDIS_Pos                      (15)                                           /**< (WDT_MR) Watchdog Disable Position */
#define WDT_MR_WDDIS_Msk                      (0x1U << WDT_MR_WDDIS_Pos)                     /**< (WDT_MR) Watchdog Disable Mask */
#define WDT_MR_WDD_Pos                        (16)                                           /**< (WDT_MR) Watchdog Delta Value Position */
#define WDT_MR_WDD_Msk                        (0xFFFU << WDT_MR_WDD_Pos)                     /**< (WDT_MR) Watchdog Delta Value Mask */
#define WDT_MR_WDD(value)                     (WDT_MR_WDD_Msk & ((value) << WDT_MR_WDD_Pos))
#define WDT_MR_WDDBGHLT_Pos                   (28)                                           /**< (WDT_MR) Watchdog Debug Halt Position */
#define WDT_MR_WDDBGHLT_Msk                   (0x1U << WDT_MR_WDDBGHLT_Pos)                  /**< (WDT_MR) Watchdog Debug Halt Mask */
#define WDT_MR_WDIDLEHLT_Pos                  (29)                                           /**< (WDT_MR) Watchdog Idle Halt Position */
#define WDT_MR_WDIDLEHLT_Msk                  (0x1U << WDT_MR_WDIDLEHLT_Pos)                 /**< (WDT_MR) Watchdog Idle Halt Mask */
#define WDT_MR_Msk                            (0x3FFFBFFFUL)                                 /**< (WDT_MR) Register Mask  */

/* -------- WDT_SR : (WDT Offset: 0x08) (R/ 32) Status Register -------- */

typedef union
{
  struct
  {
    uint32_t WDUNF:1;                   /**< bit:      0  Watchdog Underflow (cleared on read)          */
    uint32_t WDERR:1;                   /**< bit:      1  Watchdog Error (cleared on read)              */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  uint32_t w;
} __WDT_SR_bits_t;

#define WDT_SR_WDUNF_Pos                      (0)                                            /**< (WDT_SR) Watchdog Underflow (cleared on read) Position */
#define WDT_SR_WDUNF_Msk                      (0x1U << WDT_SR_WDUNF_Pos)                     /**< (WDT_SR) Watchdog Underflow (cleared on read) Mask */
#define WDT_SR_WDERR_Pos                      (1)                                            /**< (WDT_SR) Watchdog Error (cleared on read) Position */
#define WDT_SR_WDERR_Msk                      (0x1U << WDT_SR_WDERR_Pos)                     /**< (WDT_SR) Watchdog Error (cleared on read) Mask */
#define WDT_SR_Msk                            (0x00000003UL)                                 /**< (WDT_SR) Register Mask  */

/** \brief WDT register offsets definitions */
#define WDT_CR_OFFSET                (0x00)         /**< (WDT_CR) Control Register Offset */
#define WDT_MR_OFFSET                (0x04)         /**< (WDT_MR) Mode Register Offset */
#define WDT_SR_OFFSET                (0x08)         /**< (WDT_SR) Status Register Offset */

/** \brief WDT register API structure */
typedef struct
{
  __O   __WDT_CR_bits_t                WDT_CR;        /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  __WDT_MR_bits_t                WDT_MR;        /**< Offset: 0x04 (R/W  32) Mode Register */
  __I   __WDT_SR_bits_t                WDT_SR;        /**< Offset: 0x08 (R/   32) Status Register */
} wdt_registers_t;
/** @}  end of Watchdog Timer */

#endif /* _PIC32CZ_CA70_WDT_COMPONENT_H_ */
