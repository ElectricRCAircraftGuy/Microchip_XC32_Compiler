/**
 * \brief Component description for PIC32CZ/CA70 ACC
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
#ifndef _PIC32CZ_CA70_ACC_COMPONENT_H_
#define _PIC32CZ_CA70_ACC_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_ACC Analog Comparator Controller
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR ACC */
/* ========================================================================== */

/* -------- ACC_CR : (ACC Offset: 0x00) (/W 32) Control Register -------- */

typedef union
{
  struct
  {
    uint32_t SWRST:1;                   /**< bit:      0  Software Reset                                */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __ACC_CR_bits_t;

#define ACC_CR_SWRST_Pos                      (0)                                            /**< (ACC_CR) Software Reset Position */
#define ACC_CR_SWRST_Msk                      (0x1U << ACC_CR_SWRST_Pos)                     /**< (ACC_CR) Software Reset Mask */
#define ACC_CR_Msk                            (0x00000001UL)                                 /**< (ACC_CR) Register Mask  */

/* -------- ACC_MR : (ACC Offset: 0x04) (R/W 32) Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t SELMINUS:3;                /**< bit:   0..2  Selection for Minus Comparator Input          */
    uint32_t :1;                        /**< bit:      3  Reserved                                      */
    uint32_t SELPLUS:3;                 /**< bit:   4..6  Selection For Plus Comparator Input           */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t ACEN:1;                    /**< bit:      8  Analog Comparator Enable                      */
    uint32_t EDGETYP:2;                 /**< bit:  9..10  Edge Type                                     */
    uint32_t :1;                        /**< bit:     11  Reserved                                      */
    uint32_t INV:1;                     /**< bit:     12  Invert Comparator Output                      */
    uint32_t SELFS:1;                   /**< bit:     13  Selection Of Fault Source                     */
    uint32_t FE:1;                      /**< bit:     14  Fault Enable                                  */
    uint32_t :17;                       /**< bit: 15..31  Reserved                                      */
  };
  uint32_t w;
} __ACC_MR_bits_t;

#define ACC_MR_SELMINUS_Pos                   (0)                                            /**< (ACC_MR) Selection for Minus Comparator Input Position */
#define ACC_MR_SELMINUS_Msk                   (0x7U << ACC_MR_SELMINUS_Pos)                  /**< (ACC_MR) Selection for Minus Comparator Input Mask */
#define ACC_MR_SELMINUS(value)                (ACC_MR_SELMINUS_Msk & ((value) << ACC_MR_SELMINUS_Pos))
#define   ACC_MR_SELMINUS_TS_Val              (0x0U)                                         /**< (ACC_MR) Select TS  */
#define   ACC_MR_SELMINUS_VREFP_Val           (0x1U)                                         /**< (ACC_MR) Select VREFP  */
#define   ACC_MR_SELMINUS_DAC0_Val            (0x2U)                                         /**< (ACC_MR) Select DAC0  */
#define   ACC_MR_SELMINUS_DAC1_Val            (0x3U)                                         /**< (ACC_MR) Select DAC1  */
#define   ACC_MR_SELMINUS_AFE0_AD0_Val        (0x4U)                                         /**< (ACC_MR) Select AFE0_AD0  */
#define   ACC_MR_SELMINUS_AFE0_AD1_Val        (0x5U)                                         /**< (ACC_MR) Select AFE0_AD1  */
#define   ACC_MR_SELMINUS_AFE0_AD2_Val        (0x6U)                                         /**< (ACC_MR) Select AFE0_AD2  */
#define   ACC_MR_SELMINUS_AFE0_AD3_Val        (0x7U)                                         /**< (ACC_MR) Select AFE0_AD3  */
#define ACC_MR_SELMINUS_TS                    (ACC_MR_SELMINUS_TS_Val << ACC_MR_SELMINUS_Pos)  /**< (ACC_MR) Select TS Position  */
#define ACC_MR_SELMINUS_VREFP                 (ACC_MR_SELMINUS_VREFP_Val << ACC_MR_SELMINUS_Pos)  /**< (ACC_MR) Select VREFP Position  */
#define ACC_MR_SELMINUS_DAC0                  (ACC_MR_SELMINUS_DAC0_Val << ACC_MR_SELMINUS_Pos)  /**< (ACC_MR) Select DAC0 Position  */
#define ACC_MR_SELMINUS_DAC1                  (ACC_MR_SELMINUS_DAC1_Val << ACC_MR_SELMINUS_Pos)  /**< (ACC_MR) Select DAC1 Position  */
#define ACC_MR_SELMINUS_AFE0_AD0              (ACC_MR_SELMINUS_AFE0_AD0_Val << ACC_MR_SELMINUS_Pos)  /**< (ACC_MR) Select AFE0_AD0 Position  */
#define ACC_MR_SELMINUS_AFE0_AD1              (ACC_MR_SELMINUS_AFE0_AD1_Val << ACC_MR_SELMINUS_Pos)  /**< (ACC_MR) Select AFE0_AD1 Position  */
#define ACC_MR_SELMINUS_AFE0_AD2              (ACC_MR_SELMINUS_AFE0_AD2_Val << ACC_MR_SELMINUS_Pos)  /**< (ACC_MR) Select AFE0_AD2 Position  */
#define ACC_MR_SELMINUS_AFE0_AD3              (ACC_MR_SELMINUS_AFE0_AD3_Val << ACC_MR_SELMINUS_Pos)  /**< (ACC_MR) Select AFE0_AD3 Position  */
#define ACC_MR_SELPLUS_Pos                    (4)                                            /**< (ACC_MR) Selection For Plus Comparator Input Position */
#define ACC_MR_SELPLUS_Msk                    (0x7U << ACC_MR_SELPLUS_Pos)                   /**< (ACC_MR) Selection For Plus Comparator Input Mask */
#define ACC_MR_SELPLUS(value)                 (ACC_MR_SELPLUS_Msk & ((value) << ACC_MR_SELPLUS_Pos))
#define   ACC_MR_SELPLUS_AFE0_AD0_Val         (0x0U)                                         /**< (ACC_MR) Select AFE0_AD0  */
#define   ACC_MR_SELPLUS_AFE0_AD1_Val         (0x1U)                                         /**< (ACC_MR) Select AFE0_AD1  */
#define   ACC_MR_SELPLUS_AFE0_AD2_Val         (0x2U)                                         /**< (ACC_MR) Select AFE0_AD2  */
#define   ACC_MR_SELPLUS_AFE0_AD3_Val         (0x3U)                                         /**< (ACC_MR) Select AFE0_AD3  */
#define   ACC_MR_SELPLUS_AFE0_AD4_Val         (0x4U)                                         /**< (ACC_MR) Select AFE0_AD4  */
#define   ACC_MR_SELPLUS_AFE0_AD5_Val         (0x5U)                                         /**< (ACC_MR) Select AFE0_AD5  */
#define   ACC_MR_SELPLUS_AFE1_AD0_Val         (0x6U)                                         /**< (ACC_MR) Select AFE1_AD0  */
#define   ACC_MR_SELPLUS_AFE1_AD1_Val         (0x7U)                                         /**< (ACC_MR) Select AFE1_AD1  */
#define ACC_MR_SELPLUS_AFE0_AD0               (ACC_MR_SELPLUS_AFE0_AD0_Val << ACC_MR_SELPLUS_Pos)  /**< (ACC_MR) Select AFE0_AD0 Position  */
#define ACC_MR_SELPLUS_AFE0_AD1               (ACC_MR_SELPLUS_AFE0_AD1_Val << ACC_MR_SELPLUS_Pos)  /**< (ACC_MR) Select AFE0_AD1 Position  */
#define ACC_MR_SELPLUS_AFE0_AD2               (ACC_MR_SELPLUS_AFE0_AD2_Val << ACC_MR_SELPLUS_Pos)  /**< (ACC_MR) Select AFE0_AD2 Position  */
#define ACC_MR_SELPLUS_AFE0_AD3               (ACC_MR_SELPLUS_AFE0_AD3_Val << ACC_MR_SELPLUS_Pos)  /**< (ACC_MR) Select AFE0_AD3 Position  */
#define ACC_MR_SELPLUS_AFE0_AD4               (ACC_MR_SELPLUS_AFE0_AD4_Val << ACC_MR_SELPLUS_Pos)  /**< (ACC_MR) Select AFE0_AD4 Position  */
#define ACC_MR_SELPLUS_AFE0_AD5               (ACC_MR_SELPLUS_AFE0_AD5_Val << ACC_MR_SELPLUS_Pos)  /**< (ACC_MR) Select AFE0_AD5 Position  */
#define ACC_MR_SELPLUS_AFE1_AD0               (ACC_MR_SELPLUS_AFE1_AD0_Val << ACC_MR_SELPLUS_Pos)  /**< (ACC_MR) Select AFE1_AD0 Position  */
#define ACC_MR_SELPLUS_AFE1_AD1               (ACC_MR_SELPLUS_AFE1_AD1_Val << ACC_MR_SELPLUS_Pos)  /**< (ACC_MR) Select AFE1_AD1 Position  */
#define ACC_MR_ACEN_Pos                       (8)                                            /**< (ACC_MR) Analog Comparator Enable Position */
#define ACC_MR_ACEN_Msk                       (0x1U << ACC_MR_ACEN_Pos)                      /**< (ACC_MR) Analog Comparator Enable Mask */
#define   ACC_MR_ACEN_DIS_Val                 (0x0U)                                         /**< (ACC_MR) Analog comparator disabled.  */
#define   ACC_MR_ACEN_EN_Val                  (0x1U)                                         /**< (ACC_MR) Analog comparator enabled.  */
#define ACC_MR_ACEN_DIS                       (ACC_MR_ACEN_DIS_Val << ACC_MR_ACEN_Pos)       /**< (ACC_MR) Analog comparator disabled. Position  */
#define ACC_MR_ACEN_EN                        (ACC_MR_ACEN_EN_Val << ACC_MR_ACEN_Pos)        /**< (ACC_MR) Analog comparator enabled. Position  */
#define ACC_MR_EDGETYP_Pos                    (9)                                            /**< (ACC_MR) Edge Type Position */
#define ACC_MR_EDGETYP_Msk                    (0x3U << ACC_MR_EDGETYP_Pos)                   /**< (ACC_MR) Edge Type Mask */
#define ACC_MR_EDGETYP(value)                 (ACC_MR_EDGETYP_Msk & ((value) << ACC_MR_EDGETYP_Pos))
#define   ACC_MR_EDGETYP_RISING_Val           (0x0U)                                         /**< (ACC_MR) Only rising edge of comparator output  */
#define   ACC_MR_EDGETYP_FALLING_Val          (0x1U)                                         /**< (ACC_MR) Falling edge of comparator output  */
#define   ACC_MR_EDGETYP_ANY_Val              (0x2U)                                         /**< (ACC_MR) Any edge of comparator output  */
#define ACC_MR_EDGETYP_RISING                 (ACC_MR_EDGETYP_RISING_Val << ACC_MR_EDGETYP_Pos)  /**< (ACC_MR) Only rising edge of comparator output Position  */
#define ACC_MR_EDGETYP_FALLING                (ACC_MR_EDGETYP_FALLING_Val << ACC_MR_EDGETYP_Pos)  /**< (ACC_MR) Falling edge of comparator output Position  */
#define ACC_MR_EDGETYP_ANY                    (ACC_MR_EDGETYP_ANY_Val << ACC_MR_EDGETYP_Pos)  /**< (ACC_MR) Any edge of comparator output Position  */
#define ACC_MR_INV_Pos                        (12)                                           /**< (ACC_MR) Invert Comparator Output Position */
#define ACC_MR_INV_Msk                        (0x1U << ACC_MR_INV_Pos)                       /**< (ACC_MR) Invert Comparator Output Mask */
#define   ACC_MR_INV_DIS_Val                  (0x0U)                                         /**< (ACC_MR) Analog comparator output is directly processed.  */
#define   ACC_MR_INV_EN_Val                   (0x1U)                                         /**< (ACC_MR) Analog comparator output is inverted prior to being processed.  */
#define ACC_MR_INV_DIS                        (ACC_MR_INV_DIS_Val << ACC_MR_INV_Pos)         /**< (ACC_MR) Analog comparator output is directly processed. Position  */
#define ACC_MR_INV_EN                         (ACC_MR_INV_EN_Val << ACC_MR_INV_Pos)          /**< (ACC_MR) Analog comparator output is inverted prior to being processed. Position  */
#define ACC_MR_SELFS_Pos                      (13)                                           /**< (ACC_MR) Selection Of Fault Source Position */
#define ACC_MR_SELFS_Msk                      (0x1U << ACC_MR_SELFS_Pos)                     /**< (ACC_MR) Selection Of Fault Source Mask */
#define   ACC_MR_SELFS_CE_Val                 (0x0U)                                         /**< (ACC_MR) The CE flag is used to drive the FAULT output.  */
#define   ACC_MR_SELFS_OUTPUT_Val             (0x1U)                                         /**< (ACC_MR) The output of the analog comparator flag is used to drive the FAULT output.  */
#define ACC_MR_SELFS_CE                       (ACC_MR_SELFS_CE_Val << ACC_MR_SELFS_Pos)      /**< (ACC_MR) The CE flag is used to drive the FAULT output. Position  */
#define ACC_MR_SELFS_OUTPUT                   (ACC_MR_SELFS_OUTPUT_Val << ACC_MR_SELFS_Pos)  /**< (ACC_MR) The output of the analog comparator flag is used to drive the FAULT output. Position  */
#define ACC_MR_FE_Pos                         (14)                                           /**< (ACC_MR) Fault Enable Position */
#define ACC_MR_FE_Msk                         (0x1U << ACC_MR_FE_Pos)                        /**< (ACC_MR) Fault Enable Mask */
#define   ACC_MR_FE_DIS_Val                   (0x0U)                                         /**< (ACC_MR) The FAULT output is tied to 0.  */
#define   ACC_MR_FE_EN_Val                    (0x1U)                                         /**< (ACC_MR) The FAULT output is driven by the signal defined by SELFS.  */
#define ACC_MR_FE_DIS                         (ACC_MR_FE_DIS_Val << ACC_MR_FE_Pos)           /**< (ACC_MR) The FAULT output is tied to 0. Position  */
#define ACC_MR_FE_EN                          (ACC_MR_FE_EN_Val << ACC_MR_FE_Pos)            /**< (ACC_MR) The FAULT output is driven by the signal defined by SELFS. Position  */
#define ACC_MR_Msk                            (0x00007777UL)                                 /**< (ACC_MR) Register Mask  */

/* -------- ACC_IER : (ACC Offset: 0x24) (/W 32) Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t CE:1;                      /**< bit:      0  Comparison Edge                               */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __ACC_IER_bits_t;

#define ACC_IER_CE_Pos                        (0)                                            /**< (ACC_IER) Comparison Edge Position */
#define ACC_IER_CE_Msk                        (0x1U << ACC_IER_CE_Pos)                       /**< (ACC_IER) Comparison Edge Mask */
#define ACC_IER_Msk                           (0x00000001UL)                                 /**< (ACC_IER) Register Mask  */

/* -------- ACC_IDR : (ACC Offset: 0x28) (/W 32) Interrupt Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t CE:1;                      /**< bit:      0  Comparison Edge                               */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __ACC_IDR_bits_t;

#define ACC_IDR_CE_Pos                        (0)                                            /**< (ACC_IDR) Comparison Edge Position */
#define ACC_IDR_CE_Msk                        (0x1U << ACC_IDR_CE_Pos)                       /**< (ACC_IDR) Comparison Edge Mask */
#define ACC_IDR_Msk                           (0x00000001UL)                                 /**< (ACC_IDR) Register Mask  */

/* -------- ACC_IMR : (ACC Offset: 0x2c) (R/ 32) Interrupt Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t CE:1;                      /**< bit:      0  Comparison Edge                               */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __ACC_IMR_bits_t;

#define ACC_IMR_CE_Pos                        (0)                                            /**< (ACC_IMR) Comparison Edge Position */
#define ACC_IMR_CE_Msk                        (0x1U << ACC_IMR_CE_Pos)                       /**< (ACC_IMR) Comparison Edge Mask */
#define ACC_IMR_Msk                           (0x00000001UL)                                 /**< (ACC_IMR) Register Mask  */

/* -------- ACC_ISR : (ACC Offset: 0x30) (R/ 32) Interrupt Status Register -------- */

typedef union
{
  struct
  {
    uint32_t CE:1;                      /**< bit:      0  Comparison Edge (cleared on read)             */
    uint32_t SCO:1;                     /**< bit:      1  Synchronized Comparator Output                */
    uint32_t :29;                       /**< bit:  2..30  Reserved                                      */
    uint32_t MASK:1;                    /**< bit:     31  Flag Mask                                     */
  };
  uint32_t w;
} __ACC_ISR_bits_t;

#define ACC_ISR_CE_Pos                        (0)                                            /**< (ACC_ISR) Comparison Edge (cleared on read) Position */
#define ACC_ISR_CE_Msk                        (0x1U << ACC_ISR_CE_Pos)                       /**< (ACC_ISR) Comparison Edge (cleared on read) Mask */
#define ACC_ISR_SCO_Pos                       (1)                                            /**< (ACC_ISR) Synchronized Comparator Output Position */
#define ACC_ISR_SCO_Msk                       (0x1U << ACC_ISR_SCO_Pos)                      /**< (ACC_ISR) Synchronized Comparator Output Mask */
#define ACC_ISR_MASK_Pos                      (31)                                           /**< (ACC_ISR) Flag Mask Position */
#define ACC_ISR_MASK_Msk                      (0x1U << ACC_ISR_MASK_Pos)                     /**< (ACC_ISR) Flag Mask Mask */
#define ACC_ISR_Msk                           (0x80000003UL)                                 /**< (ACC_ISR) Register Mask  */

/* -------- ACC_ACR : (ACC Offset: 0x94) (R/W 32) Analog Control Register -------- */

typedef union
{
  struct
  {
    uint32_t ISEL:1;                    /**< bit:      0  Current Selection                             */
    uint32_t HYST:2;                    /**< bit:   1..2  Hysteresis Selection                          */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  uint32_t w;
} __ACC_ACR_bits_t;

#define ACC_ACR_ISEL_Pos                      (0)                                            /**< (ACC_ACR) Current Selection Position */
#define ACC_ACR_ISEL_Msk                      (0x1U << ACC_ACR_ISEL_Pos)                     /**< (ACC_ACR) Current Selection Mask */
#define   ACC_ACR_ISEL_LOPW_Val               (0x0U)                                         /**< (ACC_ACR) Low-power option.  */
#define   ACC_ACR_ISEL_HISP_Val               (0x1U)                                         /**< (ACC_ACR) High-speed option.  */
#define ACC_ACR_ISEL_LOPW                     (ACC_ACR_ISEL_LOPW_Val << ACC_ACR_ISEL_Pos)    /**< (ACC_ACR) Low-power option. Position  */
#define ACC_ACR_ISEL_HISP                     (ACC_ACR_ISEL_HISP_Val << ACC_ACR_ISEL_Pos)    /**< (ACC_ACR) High-speed option. Position  */
#define ACC_ACR_HYST_Pos                      (1)                                            /**< (ACC_ACR) Hysteresis Selection Position */
#define ACC_ACR_HYST_Msk                      (0x3U << ACC_ACR_HYST_Pos)                     /**< (ACC_ACR) Hysteresis Selection Mask */
#define ACC_ACR_HYST(value)                   (ACC_ACR_HYST_Msk & ((value) << ACC_ACR_HYST_Pos))
#define ACC_ACR_Msk                           (0x00000007UL)                                 /**< (ACC_ACR) Register Mask  */

/* -------- ACC_WPMR : (ACC Offset: 0xe4) (R/W 32) Write Protection Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t WPEN:1;                    /**< bit:      0  Write Protection Enable                       */
    uint32_t :7;                        /**< bit:   1..7  Reserved                                      */
    uint32_t WPKEY:24;                  /**< bit:  8..31  Write Protection Key                          */
  };
  uint32_t w;
} __ACC_WPMR_bits_t;

#define ACC_WPMR_WPEN_Pos                     (0)                                            /**< (ACC_WPMR) Write Protection Enable Position */
#define ACC_WPMR_WPEN_Msk                     (0x1U << ACC_WPMR_WPEN_Pos)                    /**< (ACC_WPMR) Write Protection Enable Mask */
#define ACC_WPMR_WPKEY_Pos                    (8)                                            /**< (ACC_WPMR) Write Protection Key Position */
#define ACC_WPMR_WPKEY_Msk                    (0xFFFFFFU << ACC_WPMR_WPKEY_Pos)              /**< (ACC_WPMR) Write Protection Key Mask */
#define ACC_WPMR_WPKEY(value)                 (ACC_WPMR_WPKEY_Msk & ((value) << ACC_WPMR_WPKEY_Pos))
#define   ACC_WPMR_WPKEY_PASSWD_Val           (0x414343U)                                    /**< (ACC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0.  */
#define ACC_WPMR_WPKEY_PASSWD                 (ACC_WPMR_WPKEY_PASSWD_Val << ACC_WPMR_WPKEY_Pos)  /**< (ACC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. Position  */
#define ACC_WPMR_Msk                          (0xFFFFFF01UL)                                 /**< (ACC_WPMR) Register Mask  */

/* -------- ACC_WPSR : (ACC Offset: 0xe8) (R/ 32) Write Protection Status Register -------- */

typedef union
{
  struct
  {
    uint32_t WPVS:1;                    /**< bit:      0  Write Protection Violation Status             */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __ACC_WPSR_bits_t;

#define ACC_WPSR_WPVS_Pos                     (0)                                            /**< (ACC_WPSR) Write Protection Violation Status Position */
#define ACC_WPSR_WPVS_Msk                     (0x1U << ACC_WPSR_WPVS_Pos)                    /**< (ACC_WPSR) Write Protection Violation Status Mask */
#define ACC_WPSR_Msk                          (0x00000001UL)                                 /**< (ACC_WPSR) Register Mask  */

/** \brief ACC register offsets definitions */
#define ACC_CR_OFFSET                (0x00)         /**< (ACC_CR) Control Register Offset */
#define ACC_MR_OFFSET                (0x04)         /**< (ACC_MR) Mode Register Offset */
#define ACC_IER_OFFSET               (0x24)         /**< (ACC_IER) Interrupt Enable Register Offset */
#define ACC_IDR_OFFSET               (0x28)         /**< (ACC_IDR) Interrupt Disable Register Offset */
#define ACC_IMR_OFFSET               (0x2C)         /**< (ACC_IMR) Interrupt Mask Register Offset */
#define ACC_ISR_OFFSET               (0x30)         /**< (ACC_ISR) Interrupt Status Register Offset */
#define ACC_ACR_OFFSET               (0x94)         /**< (ACC_ACR) Analog Control Register Offset */
#define ACC_WPMR_OFFSET              (0xE4)         /**< (ACC_WPMR) Write Protection Mode Register Offset */
#define ACC_WPSR_OFFSET              (0xE8)         /**< (ACC_WPSR) Write Protection Status Register Offset */

/** \brief ACC register API structure */
typedef struct
{
  __O   __ACC_CR_bits_t                ACC_CR;        /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  __ACC_MR_bits_t                ACC_MR;        /**< Offset: 0x04 (R/W  32) Mode Register */
  __I   uint8_t                        Reserved1[0x1C];
  __O   __ACC_IER_bits_t               ACC_IER;       /**< Offset: 0x24 ( /W  32) Interrupt Enable Register */
  __O   __ACC_IDR_bits_t               ACC_IDR;       /**< Offset: 0x28 ( /W  32) Interrupt Disable Register */
  __I   __ACC_IMR_bits_t               ACC_IMR;       /**< Offset: 0x2C (R/   32) Interrupt Mask Register */
  __I   __ACC_ISR_bits_t               ACC_ISR;       /**< Offset: 0x30 (R/   32) Interrupt Status Register */
  __I   uint8_t                        Reserved2[0x60];
  __IO  __ACC_ACR_bits_t               ACC_ACR;       /**< Offset: 0x94 (R/W  32) Analog Control Register */
  __I   uint8_t                        Reserved3[0x4C];
  __IO  __ACC_WPMR_bits_t              ACC_WPMR;      /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   __ACC_WPSR_bits_t              ACC_WPSR;      /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} acc_registers_t;
/** @}  end of Analog Comparator Controller */

#endif /* _PIC32CZ_CA70_ACC_COMPONENT_H_ */
