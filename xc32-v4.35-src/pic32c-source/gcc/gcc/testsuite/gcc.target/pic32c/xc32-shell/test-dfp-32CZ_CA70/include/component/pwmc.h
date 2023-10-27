/**
 * \brief Component description for PIC32CZ/CA70 PWMC
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
#ifndef _PIC32CZ_CA70_PWMC_COMPONENT_H_
#define _PIC32CZ_CA70_PWMC_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_PWMC Pulse Width Modulation Controller
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR PWMC */
/* ========================================================================== */

/* -------- PWMC_CMR : (PWMC Offset: 0x00) (R/W 32) PWMC Channel Mode Register (ch_num = 0) -------- */

typedef union
{
  struct
  {
    uint32_t CPRE:4;                    /**< bit:   0..3  Channel Pre-scaler                            */
    uint32_t :4;                        /**< bit:   4..7  Reserved                                      */
    uint32_t CALG:1;                    /**< bit:      8  Channel Alignment                             */
    uint32_t CPOL:1;                    /**< bit:      9  Channel Polarity                              */
    uint32_t CES:1;                     /**< bit:     10  Counter Event Selection                       */
    uint32_t UPDS:1;                    /**< bit:     11  Update Selection                              */
    uint32_t DPOLI:1;                   /**< bit:     12  Disabled Polarity Inverted                    */
    uint32_t TCTS:1;                    /**< bit:     13  Timer Counter Trigger Selection               */
    uint32_t :2;                        /**< bit: 14..15  Reserved                                      */
    uint32_t DTE:1;                     /**< bit:     16  Dead-Time Generator Enable                    */
    uint32_t DTHI:1;                    /**< bit:     17  Dead-Time PWMHx Output Inverted               */
    uint32_t DTLI:1;                    /**< bit:     18  Dead-Time PWMLx Output Inverted               */
    uint32_t PPM:1;                     /**< bit:     19  Push-Pull Mode                                */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CMR_bits_t;

#define PWMC_CMR_CPRE_Pos                     (0)                                            /**< (PWMC_CMR) Channel Pre-scaler Position */
#define PWMC_CMR_CPRE_Msk                     (0xFU << PWMC_CMR_CPRE_Pos)                    /**< (PWMC_CMR) Channel Pre-scaler Mask */
#define PWMC_CMR_CPRE(value)                  (PWMC_CMR_CPRE_Msk & ((value) << PWMC_CMR_CPRE_Pos))
#define   PWMC_CMR_CPRE_MCK_Val               (0x0U)                                         /**< (PWMC_CMR) Peripheral clock  */
#define   PWMC_CMR_CPRE_MCK_DIV_2_Val         (0x1U)                                         /**< (PWMC_CMR) Peripheral clock/2  */
#define   PWMC_CMR_CPRE_MCK_DIV_4_Val         (0x2U)                                         /**< (PWMC_CMR) Peripheral clock/4  */
#define   PWMC_CMR_CPRE_MCK_DIV_8_Val         (0x3U)                                         /**< (PWMC_CMR) Peripheral clock/8  */
#define   PWMC_CMR_CPRE_MCK_DIV_16_Val        (0x4U)                                         /**< (PWMC_CMR) Peripheral clock/16  */
#define   PWMC_CMR_CPRE_MCK_DIV_32_Val        (0x5U)                                         /**< (PWMC_CMR) Peripheral clock/32  */
#define   PWMC_CMR_CPRE_MCK_DIV_64_Val        (0x6U)                                         /**< (PWMC_CMR) Peripheral clock/64  */
#define   PWMC_CMR_CPRE_MCK_DIV_128_Val       (0x7U)                                         /**< (PWMC_CMR) Peripheral clock/128  */
#define   PWMC_CMR_CPRE_MCK_DIV_256_Val       (0x8U)                                         /**< (PWMC_CMR) Peripheral clock/256  */
#define   PWMC_CMR_CPRE_MCK_DIV_512_Val       (0x9U)                                         /**< (PWMC_CMR) Peripheral clock/512  */
#define   PWMC_CMR_CPRE_MCK_DIV_1024_Val      (0xAU)                                         /**< (PWMC_CMR) Peripheral clock/1024  */
#define   PWMC_CMR_CPRE_CLKA_Val              (0xBU)                                         /**< (PWMC_CMR) Clock A  */
#define   PWMC_CMR_CPRE_CLKB_Val              (0xCU)                                         /**< (PWMC_CMR) Clock B  */
#define PWMC_CMR_CPRE_MCK                     (PWMC_CMR_CPRE_MCK_Val << PWMC_CMR_CPRE_Pos)   /**< (PWMC_CMR) Peripheral clock Position  */
#define PWMC_CMR_CPRE_MCK_DIV_2               (PWMC_CMR_CPRE_MCK_DIV_2_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Peripheral clock/2 Position  */
#define PWMC_CMR_CPRE_MCK_DIV_4               (PWMC_CMR_CPRE_MCK_DIV_4_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Peripheral clock/4 Position  */
#define PWMC_CMR_CPRE_MCK_DIV_8               (PWMC_CMR_CPRE_MCK_DIV_8_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Peripheral clock/8 Position  */
#define PWMC_CMR_CPRE_MCK_DIV_16              (PWMC_CMR_CPRE_MCK_DIV_16_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Peripheral clock/16 Position  */
#define PWMC_CMR_CPRE_MCK_DIV_32              (PWMC_CMR_CPRE_MCK_DIV_32_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Peripheral clock/32 Position  */
#define PWMC_CMR_CPRE_MCK_DIV_64              (PWMC_CMR_CPRE_MCK_DIV_64_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Peripheral clock/64 Position  */
#define PWMC_CMR_CPRE_MCK_DIV_128             (PWMC_CMR_CPRE_MCK_DIV_128_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Peripheral clock/128 Position  */
#define PWMC_CMR_CPRE_MCK_DIV_256             (PWMC_CMR_CPRE_MCK_DIV_256_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Peripheral clock/256 Position  */
#define PWMC_CMR_CPRE_MCK_DIV_512             (PWMC_CMR_CPRE_MCK_DIV_512_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Peripheral clock/512 Position  */
#define PWMC_CMR_CPRE_MCK_DIV_1024            (PWMC_CMR_CPRE_MCK_DIV_1024_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Peripheral clock/1024 Position  */
#define PWMC_CMR_CPRE_CLKA                    (PWMC_CMR_CPRE_CLKA_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Clock A Position  */
#define PWMC_CMR_CPRE_CLKB                    (PWMC_CMR_CPRE_CLKB_Val << PWMC_CMR_CPRE_Pos)  /**< (PWMC_CMR) Clock B Position  */
#define PWMC_CMR_CALG_Pos                     (8)                                            /**< (PWMC_CMR) Channel Alignment Position */
#define PWMC_CMR_CALG_Msk                     (0x1U << PWMC_CMR_CALG_Pos)                    /**< (PWMC_CMR) Channel Alignment Mask */
#define PWMC_CMR_CPOL_Pos                     (9)                                            /**< (PWMC_CMR) Channel Polarity Position */
#define PWMC_CMR_CPOL_Msk                     (0x1U << PWMC_CMR_CPOL_Pos)                    /**< (PWMC_CMR) Channel Polarity Mask */
#define PWMC_CMR_CES_Pos                      (10)                                           /**< (PWMC_CMR) Counter Event Selection Position */
#define PWMC_CMR_CES_Msk                      (0x1U << PWMC_CMR_CES_Pos)                     /**< (PWMC_CMR) Counter Event Selection Mask */
#define PWMC_CMR_UPDS_Pos                     (11)                                           /**< (PWMC_CMR) Update Selection Position */
#define PWMC_CMR_UPDS_Msk                     (0x1U << PWMC_CMR_UPDS_Pos)                    /**< (PWMC_CMR) Update Selection Mask */
#define PWMC_CMR_DPOLI_Pos                    (12)                                           /**< (PWMC_CMR) Disabled Polarity Inverted Position */
#define PWMC_CMR_DPOLI_Msk                    (0x1U << PWMC_CMR_DPOLI_Pos)                   /**< (PWMC_CMR) Disabled Polarity Inverted Mask */
#define PWMC_CMR_TCTS_Pos                     (13)                                           /**< (PWMC_CMR) Timer Counter Trigger Selection Position */
#define PWMC_CMR_TCTS_Msk                     (0x1U << PWMC_CMR_TCTS_Pos)                    /**< (PWMC_CMR) Timer Counter Trigger Selection Mask */
#define PWMC_CMR_DTE_Pos                      (16)                                           /**< (PWMC_CMR) Dead-Time Generator Enable Position */
#define PWMC_CMR_DTE_Msk                      (0x1U << PWMC_CMR_DTE_Pos)                     /**< (PWMC_CMR) Dead-Time Generator Enable Mask */
#define PWMC_CMR_DTHI_Pos                     (17)                                           /**< (PWMC_CMR) Dead-Time PWMHx Output Inverted Position */
#define PWMC_CMR_DTHI_Msk                     (0x1U << PWMC_CMR_DTHI_Pos)                    /**< (PWMC_CMR) Dead-Time PWMHx Output Inverted Mask */
#define PWMC_CMR_DTLI_Pos                     (18)                                           /**< (PWMC_CMR) Dead-Time PWMLx Output Inverted Position */
#define PWMC_CMR_DTLI_Msk                     (0x1U << PWMC_CMR_DTLI_Pos)                    /**< (PWMC_CMR) Dead-Time PWMLx Output Inverted Mask */
#define PWMC_CMR_PPM_Pos                      (19)                                           /**< (PWMC_CMR) Push-Pull Mode Position */
#define PWMC_CMR_PPM_Msk                      (0x1U << PWMC_CMR_PPM_Pos)                     /**< (PWMC_CMR) Push-Pull Mode Mask */
#define PWMC_CMR_Msk                          (0x000F3F0FUL)                                 /**< (PWMC_CMR) Register Mask  */

/* -------- PWMC_CDTY : (PWMC Offset: 0x04) (R/W 32) PWMC Channel Duty Cycle Register (ch_num = 0) -------- */

typedef union
{
  struct
  {
    uint32_t CDTY:24;                   /**< bit:  0..23  Channel Duty-Cycle                            */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CDTY_bits_t;

#define PWMC_CDTY_CDTY_Pos                    (0)                                            /**< (PWMC_CDTY) Channel Duty-Cycle Position */
#define PWMC_CDTY_CDTY_Msk                    (0xFFFFFFU << PWMC_CDTY_CDTY_Pos)              /**< (PWMC_CDTY) Channel Duty-Cycle Mask */
#define PWMC_CDTY_CDTY(value)                 (PWMC_CDTY_CDTY_Msk & ((value) << PWMC_CDTY_CDTY_Pos))
#define PWMC_CDTY_Msk                         (0x00FFFFFFUL)                                 /**< (PWMC_CDTY) Register Mask  */

/* -------- PWMC_CDTYUPD : (PWMC Offset: 0x08) (/W 32) PWMC Channel Duty Cycle Update Register (ch_num = 0) -------- */

typedef union
{
  struct
  {
    uint32_t CDTYUPD:24;                /**< bit:  0..23  Channel Duty-Cycle Update                     */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CDTYUPD_bits_t;

#define PWMC_CDTYUPD_CDTYUPD_Pos              (0)                                            /**< (PWMC_CDTYUPD) Channel Duty-Cycle Update Position */
#define PWMC_CDTYUPD_CDTYUPD_Msk              (0xFFFFFFU << PWMC_CDTYUPD_CDTYUPD_Pos)        /**< (PWMC_CDTYUPD) Channel Duty-Cycle Update Mask */
#define PWMC_CDTYUPD_CDTYUPD(value)           (PWMC_CDTYUPD_CDTYUPD_Msk & ((value) << PWMC_CDTYUPD_CDTYUPD_Pos))
#define PWMC_CDTYUPD_Msk                      (0x00FFFFFFUL)                                 /**< (PWMC_CDTYUPD) Register Mask  */

/* -------- PWMC_CPRD : (PWMC Offset: 0x0c) (R/W 32) PWMC Channel Period Register (ch_num = 0) -------- */

typedef union
{
  struct
  {
    uint32_t CPRD:24;                   /**< bit:  0..23  Channel Period                                */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CPRD_bits_t;

#define PWMC_CPRD_CPRD_Pos                    (0)                                            /**< (PWMC_CPRD) Channel Period Position */
#define PWMC_CPRD_CPRD_Msk                    (0xFFFFFFU << PWMC_CPRD_CPRD_Pos)              /**< (PWMC_CPRD) Channel Period Mask */
#define PWMC_CPRD_CPRD(value)                 (PWMC_CPRD_CPRD_Msk & ((value) << PWMC_CPRD_CPRD_Pos))
#define PWMC_CPRD_Msk                         (0x00FFFFFFUL)                                 /**< (PWMC_CPRD) Register Mask  */

/* -------- PWMC_CPRDUPD : (PWMC Offset: 0x10) (/W 32) PWMC Channel Period Update Register (ch_num = 0) -------- */

typedef union
{
  struct
  {
    uint32_t CPRDUPD:24;                /**< bit:  0..23  Channel Period Update                         */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CPRDUPD_bits_t;

#define PWMC_CPRDUPD_CPRDUPD_Pos              (0)                                            /**< (PWMC_CPRDUPD) Channel Period Update Position */
#define PWMC_CPRDUPD_CPRDUPD_Msk              (0xFFFFFFU << PWMC_CPRDUPD_CPRDUPD_Pos)        /**< (PWMC_CPRDUPD) Channel Period Update Mask */
#define PWMC_CPRDUPD_CPRDUPD(value)           (PWMC_CPRDUPD_CPRDUPD_Msk & ((value) << PWMC_CPRDUPD_CPRDUPD_Pos))
#define PWMC_CPRDUPD_Msk                      (0x00FFFFFFUL)                                 /**< (PWMC_CPRDUPD) Register Mask  */

/* -------- PWMC_CCNT : (PWMC Offset: 0x14) (R/ 32) PWMC Channel Counter Register (ch_num = 0) -------- */

typedef union
{
  struct
  {
    uint32_t CNT:24;                    /**< bit:  0..23  Channel Counter Register                      */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CCNT_bits_t;

#define PWMC_CCNT_CNT_Pos                     (0)                                            /**< (PWMC_CCNT) Channel Counter Register Position */
#define PWMC_CCNT_CNT_Msk                     (0xFFFFFFU << PWMC_CCNT_CNT_Pos)               /**< (PWMC_CCNT) Channel Counter Register Mask */
#define PWMC_CCNT_CNT(value)                  (PWMC_CCNT_CNT_Msk & ((value) << PWMC_CCNT_CNT_Pos))
#define PWMC_CCNT_Msk                         (0x00FFFFFFUL)                                 /**< (PWMC_CCNT) Register Mask  */

/* -------- PWMC_DT : (PWMC Offset: 0x18) (R/W 32) PWMC Channel Dead Time Register (ch_num = 0) -------- */

typedef union
{
  struct
  {
    uint32_t DTH:16;                    /**< bit:  0..15  Dead-Time Value for PWMHx Output              */
    uint32_t DTL:16;                    /**< bit: 16..31  Dead-Time Value for PWMLx Output              */
  };
  uint32_t w;
} __PWMC_DT_bits_t;

#define PWMC_DT_DTH_Pos                       (0)                                            /**< (PWMC_DT) Dead-Time Value for PWMHx Output Position */
#define PWMC_DT_DTH_Msk                       (0xFFFFU << PWMC_DT_DTH_Pos)                   /**< (PWMC_DT) Dead-Time Value for PWMHx Output Mask */
#define PWMC_DT_DTH(value)                    (PWMC_DT_DTH_Msk & ((value) << PWMC_DT_DTH_Pos))
#define PWMC_DT_DTL_Pos                       (16)                                           /**< (PWMC_DT) Dead-Time Value for PWMLx Output Position */
#define PWMC_DT_DTL_Msk                       (0xFFFFU << PWMC_DT_DTL_Pos)                   /**< (PWMC_DT) Dead-Time Value for PWMLx Output Mask */
#define PWMC_DT_DTL(value)                    (PWMC_DT_DTL_Msk & ((value) << PWMC_DT_DTL_Pos))
#define PWMC_DT_Msk                           (0xFFFFFFFFUL)                                 /**< (PWMC_DT) Register Mask  */

/* -------- PWMC_DTUPD : (PWMC Offset: 0x1c) (/W 32) PWMC Channel Dead Time Update Register (ch_num = 0) -------- */

typedef union
{
  struct
  {
    uint32_t DTHUPD:16;                 /**< bit:  0..15  Dead-Time Value Update for PWMHx Output       */
    uint32_t DTLUPD:16;                 /**< bit: 16..31  Dead-Time Value Update for PWMLx Output       */
  };
  uint32_t w;
} __PWMC_DTUPD_bits_t;

#define PWMC_DTUPD_DTHUPD_Pos                 (0)                                            /**< (PWMC_DTUPD) Dead-Time Value Update for PWMHx Output Position */
#define PWMC_DTUPD_DTHUPD_Msk                 (0xFFFFU << PWMC_DTUPD_DTHUPD_Pos)             /**< (PWMC_DTUPD) Dead-Time Value Update for PWMHx Output Mask */
#define PWMC_DTUPD_DTHUPD(value)              (PWMC_DTUPD_DTHUPD_Msk & ((value) << PWMC_DTUPD_DTHUPD_Pos))
#define PWMC_DTUPD_DTLUPD_Pos                 (16)                                           /**< (PWMC_DTUPD) Dead-Time Value Update for PWMLx Output Position */
#define PWMC_DTUPD_DTLUPD_Msk                 (0xFFFFU << PWMC_DTUPD_DTLUPD_Pos)             /**< (PWMC_DTUPD) Dead-Time Value Update for PWMLx Output Mask */
#define PWMC_DTUPD_DTLUPD(value)              (PWMC_DTUPD_DTLUPD_Msk & ((value) << PWMC_DTUPD_DTLUPD_Pos))
#define PWMC_DTUPD_Msk                        (0xFFFFFFFFUL)                                 /**< (PWMC_DTUPD) Register Mask  */

/* -------- PWMC_CMPV : (PWMC Offset: 0x00) (R/W 32) PWMC Comparison 0 Value Register -------- */

typedef union
{
  struct
  {
    uint32_t CV:24;                     /**< bit:  0..23  Comparison x Value                            */
    uint32_t CVM:1;                     /**< bit:     24  Comparison x Value Mode                       */
    uint32_t :7;                        /**< bit: 25..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CMPV_bits_t;

#define PWMC_CMPV_CV_Pos                      (0)                                            /**< (PWMC_CMPV) Comparison x Value Position */
#define PWMC_CMPV_CV_Msk                      (0xFFFFFFU << PWMC_CMPV_CV_Pos)                /**< (PWMC_CMPV) Comparison x Value Mask */
#define PWMC_CMPV_CV(value)                   (PWMC_CMPV_CV_Msk & ((value) << PWMC_CMPV_CV_Pos))
#define PWMC_CMPV_CVM_Pos                     (24)                                           /**< (PWMC_CMPV) Comparison x Value Mode Position */
#define PWMC_CMPV_CVM_Msk                     (0x1U << PWMC_CMPV_CVM_Pos)                    /**< (PWMC_CMPV) Comparison x Value Mode Mask */
#define PWMC_CMPV_Msk                         (0x01FFFFFFUL)                                 /**< (PWMC_CMPV) Register Mask  */

/* -------- PWMC_CMPVUPD : (PWMC Offset: 0x04) (/W 32) PWMC Comparison 0 Value Update Register -------- */

typedef union
{
  struct
  {
    uint32_t CVUPD:24;                  /**< bit:  0..23  Comparison x Value Update                     */
    uint32_t CVMUPD:1;                  /**< bit:     24  Comparison x Value Mode Update                */
    uint32_t :7;                        /**< bit: 25..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CMPVUPD_bits_t;

#define PWMC_CMPVUPD_CVUPD_Pos                (0)                                            /**< (PWMC_CMPVUPD) Comparison x Value Update Position */
#define PWMC_CMPVUPD_CVUPD_Msk                (0xFFFFFFU << PWMC_CMPVUPD_CVUPD_Pos)          /**< (PWMC_CMPVUPD) Comparison x Value Update Mask */
#define PWMC_CMPVUPD_CVUPD(value)             (PWMC_CMPVUPD_CVUPD_Msk & ((value) << PWMC_CMPVUPD_CVUPD_Pos))
#define PWMC_CMPVUPD_CVMUPD_Pos               (24)                                           /**< (PWMC_CMPVUPD) Comparison x Value Mode Update Position */
#define PWMC_CMPVUPD_CVMUPD_Msk               (0x1U << PWMC_CMPVUPD_CVMUPD_Pos)              /**< (PWMC_CMPVUPD) Comparison x Value Mode Update Mask */
#define PWMC_CMPVUPD_Msk                      (0x01FFFFFFUL)                                 /**< (PWMC_CMPVUPD) Register Mask  */

/* -------- PWMC_CMPM : (PWMC Offset: 0x08) (R/W 32) PWMC Comparison 0 Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t CEN:1;                     /**< bit:      0  Comparison x Enable                           */
    uint32_t :3;                        /**< bit:   1..3  Reserved                                      */
    uint32_t CTR:4;                     /**< bit:   4..7  Comparison x Trigger                          */
    uint32_t CPR:4;                     /**< bit:  8..11  Comparison x Period                           */
    uint32_t CPRCNT:4;                  /**< bit: 12..15  Comparison x Period Counter                   */
    uint32_t CUPR:4;                    /**< bit: 16..19  Comparison x Update Period                    */
    uint32_t CUPRCNT:4;                 /**< bit: 20..23  Comparison x Update Period Counter            */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CMPM_bits_t;

#define PWMC_CMPM_CEN_Pos                     (0)                                            /**< (PWMC_CMPM) Comparison x Enable Position */
#define PWMC_CMPM_CEN_Msk                     (0x1U << PWMC_CMPM_CEN_Pos)                    /**< (PWMC_CMPM) Comparison x Enable Mask */
#define PWMC_CMPM_CTR_Pos                     (4)                                            /**< (PWMC_CMPM) Comparison x Trigger Position */
#define PWMC_CMPM_CTR_Msk                     (0xFU << PWMC_CMPM_CTR_Pos)                    /**< (PWMC_CMPM) Comparison x Trigger Mask */
#define PWMC_CMPM_CTR(value)                  (PWMC_CMPM_CTR_Msk & ((value) << PWMC_CMPM_CTR_Pos))
#define PWMC_CMPM_CPR_Pos                     (8)                                            /**< (PWMC_CMPM) Comparison x Period Position */
#define PWMC_CMPM_CPR_Msk                     (0xFU << PWMC_CMPM_CPR_Pos)                    /**< (PWMC_CMPM) Comparison x Period Mask */
#define PWMC_CMPM_CPR(value)                  (PWMC_CMPM_CPR_Msk & ((value) << PWMC_CMPM_CPR_Pos))
#define PWMC_CMPM_CPRCNT_Pos                  (12)                                           /**< (PWMC_CMPM) Comparison x Period Counter Position */
#define PWMC_CMPM_CPRCNT_Msk                  (0xFU << PWMC_CMPM_CPRCNT_Pos)                 /**< (PWMC_CMPM) Comparison x Period Counter Mask */
#define PWMC_CMPM_CPRCNT(value)               (PWMC_CMPM_CPRCNT_Msk & ((value) << PWMC_CMPM_CPRCNT_Pos))
#define PWMC_CMPM_CUPR_Pos                    (16)                                           /**< (PWMC_CMPM) Comparison x Update Period Position */
#define PWMC_CMPM_CUPR_Msk                    (0xFU << PWMC_CMPM_CUPR_Pos)                   /**< (PWMC_CMPM) Comparison x Update Period Mask */
#define PWMC_CMPM_CUPR(value)                 (PWMC_CMPM_CUPR_Msk & ((value) << PWMC_CMPM_CUPR_Pos))
#define PWMC_CMPM_CUPRCNT_Pos                 (20)                                           /**< (PWMC_CMPM) Comparison x Update Period Counter Position */
#define PWMC_CMPM_CUPRCNT_Msk                 (0xFU << PWMC_CMPM_CUPRCNT_Pos)                /**< (PWMC_CMPM) Comparison x Update Period Counter Mask */
#define PWMC_CMPM_CUPRCNT(value)              (PWMC_CMPM_CUPRCNT_Msk & ((value) << PWMC_CMPM_CUPRCNT_Pos))
#define PWMC_CMPM_Msk                         (0x00FFFFF1UL)                                 /**< (PWMC_CMPM) Register Mask  */

/* -------- PWMC_CMPMUPD : (PWMC Offset: 0x0c) (/W 32) PWMC Comparison 0 Mode Update Register -------- */

typedef union
{
  struct
  {
    uint32_t CENUPD:1;                  /**< bit:      0  Comparison x Enable Update                    */
    uint32_t :3;                        /**< bit:   1..3  Reserved                                      */
    uint32_t CTRUPD:4;                  /**< bit:   4..7  Comparison x Trigger Update                   */
    uint32_t CPRUPD:4;                  /**< bit:  8..11  Comparison x Period Update                    */
    uint32_t :4;                        /**< bit: 12..15  Reserved                                      */
    uint32_t CUPRUPD:4;                 /**< bit: 16..19  Comparison x Update Period Update             */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CMPMUPD_bits_t;

#define PWMC_CMPMUPD_CENUPD_Pos               (0)                                            /**< (PWMC_CMPMUPD) Comparison x Enable Update Position */
#define PWMC_CMPMUPD_CENUPD_Msk               (0x1U << PWMC_CMPMUPD_CENUPD_Pos)              /**< (PWMC_CMPMUPD) Comparison x Enable Update Mask */
#define PWMC_CMPMUPD_CTRUPD_Pos               (4)                                            /**< (PWMC_CMPMUPD) Comparison x Trigger Update Position */
#define PWMC_CMPMUPD_CTRUPD_Msk               (0xFU << PWMC_CMPMUPD_CTRUPD_Pos)              /**< (PWMC_CMPMUPD) Comparison x Trigger Update Mask */
#define PWMC_CMPMUPD_CTRUPD(value)            (PWMC_CMPMUPD_CTRUPD_Msk & ((value) << PWMC_CMPMUPD_CTRUPD_Pos))
#define PWMC_CMPMUPD_CPRUPD_Pos               (8)                                            /**< (PWMC_CMPMUPD) Comparison x Period Update Position */
#define PWMC_CMPMUPD_CPRUPD_Msk               (0xFU << PWMC_CMPMUPD_CPRUPD_Pos)              /**< (PWMC_CMPMUPD) Comparison x Period Update Mask */
#define PWMC_CMPMUPD_CPRUPD(value)            (PWMC_CMPMUPD_CPRUPD_Msk & ((value) << PWMC_CMPMUPD_CPRUPD_Pos))
#define PWMC_CMPMUPD_CUPRUPD_Pos              (16)                                           /**< (PWMC_CMPMUPD) Comparison x Update Period Update Position */
#define PWMC_CMPMUPD_CUPRUPD_Msk              (0xFU << PWMC_CMPMUPD_CUPRUPD_Pos)             /**< (PWMC_CMPMUPD) Comparison x Update Period Update Mask */
#define PWMC_CMPMUPD_CUPRUPD(value)           (PWMC_CMPMUPD_CUPRUPD_Msk & ((value) << PWMC_CMPMUPD_CUPRUPD_Pos))
#define PWMC_CMPMUPD_Msk                      (0x000F0FF1UL)                                 /**< (PWMC_CMPMUPD) Register Mask  */

/* -------- PWMC_CLK : (PWMC Offset: 0x00) (R/W 32) PWMC Clock Register -------- */

typedef union
{
  struct
  {
    uint32_t DIVA:8;                    /**< bit:   0..7  CLKA Divide Factor                            */
    uint32_t PREA:4;                    /**< bit:  8..11  CLKA Source Clock Selection                   */
    uint32_t :4;                        /**< bit: 12..15  Reserved                                      */
    uint32_t DIVB:8;                    /**< bit: 16..23  CLKB Divide Factor                            */
    uint32_t PREB:4;                    /**< bit: 24..27  CLKB Source Clock Selection                   */
    uint32_t :4;                        /**< bit: 28..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CLK_bits_t;

#define PWMC_CLK_DIVA_Pos                     (0)                                            /**< (PWMC_CLK) CLKA Divide Factor Position */
#define PWMC_CLK_DIVA_Msk                     (0xFFU << PWMC_CLK_DIVA_Pos)                   /**< (PWMC_CLK) CLKA Divide Factor Mask */
#define PWMC_CLK_DIVA(value)                  (PWMC_CLK_DIVA_Msk & ((value) << PWMC_CLK_DIVA_Pos))
#define   PWMC_CLK_DIVA_CLKA_POFF_Val         (0x0U)                                         /**< (PWMC_CLK) CLKA clock is turned off  */
#define   PWMC_CLK_DIVA_PREA_Val              (0x1U)                                         /**< (PWMC_CLK) CLKA clock is clock selected by PREA  */
#define PWMC_CLK_DIVA_CLKA_POFF               (PWMC_CLK_DIVA_CLKA_POFF_Val << PWMC_CLK_DIVA_Pos)  /**< (PWMC_CLK) CLKA clock is turned off Position  */
#define PWMC_CLK_DIVA_PREA                    (PWMC_CLK_DIVA_PREA_Val << PWMC_CLK_DIVA_Pos)  /**< (PWMC_CLK) CLKA clock is clock selected by PREA Position  */
#define PWMC_CLK_PREA_Pos                     (8)                                            /**< (PWMC_CLK) CLKA Source Clock Selection Position */
#define PWMC_CLK_PREA_Msk                     (0xFU << PWMC_CLK_PREA_Pos)                    /**< (PWMC_CLK) CLKA Source Clock Selection Mask */
#define PWMC_CLK_PREA(value)                  (PWMC_CLK_PREA_Msk & ((value) << PWMC_CLK_PREA_Pos))
#define   PWMC_CLK_PREA_CLK_Val               (0x0U)                                         /**< (PWMC_CLK) Peripheral clock  */
#define   PWMC_CLK_PREA_CLK_DIV2_Val          (0x1U)                                         /**< (PWMC_CLK) Peripheral clock/2  */
#define   PWMC_CLK_PREA_CLK_DIV4_Val          (0x2U)                                         /**< (PWMC_CLK) Peripheral clock/4  */
#define   PWMC_CLK_PREA_CLK_DIV8_Val          (0x3U)                                         /**< (PWMC_CLK) Peripheral clock/8  */
#define   PWMC_CLK_PREA_CLK_DIV16_Val         (0x4U)                                         /**< (PWMC_CLK) Peripheral clock/16  */
#define   PWMC_CLK_PREA_CLK_DIV32_Val         (0x5U)                                         /**< (PWMC_CLK) Peripheral clock/32  */
#define   PWMC_CLK_PREA_CLK_DIV64_Val         (0x6U)                                         /**< (PWMC_CLK) Peripheral clock/64  */
#define   PWMC_CLK_PREA_CLK_DIV128_Val        (0x7U)                                         /**< (PWMC_CLK) Peripheral clock/128  */
#define   PWMC_CLK_PREA_CLK_DIV256_Val        (0x8U)                                         /**< (PWMC_CLK) Peripheral clock/256  */
#define   PWMC_CLK_PREA_CLK_DIV512_Val        (0x9U)                                         /**< (PWMC_CLK) Peripheral clock/512  */
#define   PWMC_CLK_PREA_CLK_DIV1024_Val       (0xAU)                                         /**< (PWMC_CLK) Peripheral clock/1024  */
#define PWMC_CLK_PREA_CLK                     (PWMC_CLK_PREA_CLK_Val << PWMC_CLK_PREA_Pos)   /**< (PWMC_CLK) Peripheral clock Position  */
#define PWMC_CLK_PREA_CLK_DIV2                (PWMC_CLK_PREA_CLK_DIV2_Val << PWMC_CLK_PREA_Pos)  /**< (PWMC_CLK) Peripheral clock/2 Position  */
#define PWMC_CLK_PREA_CLK_DIV4                (PWMC_CLK_PREA_CLK_DIV4_Val << PWMC_CLK_PREA_Pos)  /**< (PWMC_CLK) Peripheral clock/4 Position  */
#define PWMC_CLK_PREA_CLK_DIV8                (PWMC_CLK_PREA_CLK_DIV8_Val << PWMC_CLK_PREA_Pos)  /**< (PWMC_CLK) Peripheral clock/8 Position  */
#define PWMC_CLK_PREA_CLK_DIV16               (PWMC_CLK_PREA_CLK_DIV16_Val << PWMC_CLK_PREA_Pos)  /**< (PWMC_CLK) Peripheral clock/16 Position  */
#define PWMC_CLK_PREA_CLK_DIV32               (PWMC_CLK_PREA_CLK_DIV32_Val << PWMC_CLK_PREA_Pos)  /**< (PWMC_CLK) Peripheral clock/32 Position  */
#define PWMC_CLK_PREA_CLK_DIV64               (PWMC_CLK_PREA_CLK_DIV64_Val << PWMC_CLK_PREA_Pos)  /**< (PWMC_CLK) Peripheral clock/64 Position  */
#define PWMC_CLK_PREA_CLK_DIV128              (PWMC_CLK_PREA_CLK_DIV128_Val << PWMC_CLK_PREA_Pos)  /**< (PWMC_CLK) Peripheral clock/128 Position  */
#define PWMC_CLK_PREA_CLK_DIV256              (PWMC_CLK_PREA_CLK_DIV256_Val << PWMC_CLK_PREA_Pos)  /**< (PWMC_CLK) Peripheral clock/256 Position  */
#define PWMC_CLK_PREA_CLK_DIV512              (PWMC_CLK_PREA_CLK_DIV512_Val << PWMC_CLK_PREA_Pos)  /**< (PWMC_CLK) Peripheral clock/512 Position  */
#define PWMC_CLK_PREA_CLK_DIV1024             (PWMC_CLK_PREA_CLK_DIV1024_Val << PWMC_CLK_PREA_Pos)  /**< (PWMC_CLK) Peripheral clock/1024 Position  */
#define PWMC_CLK_DIVB_Pos                     (16)                                           /**< (PWMC_CLK) CLKB Divide Factor Position */
#define PWMC_CLK_DIVB_Msk                     (0xFFU << PWMC_CLK_DIVB_Pos)                   /**< (PWMC_CLK) CLKB Divide Factor Mask */
#define PWMC_CLK_DIVB(value)                  (PWMC_CLK_DIVB_Msk & ((value) << PWMC_CLK_DIVB_Pos))
#define   PWMC_CLK_DIVB_CLKB_POFF_Val         (0x0U)                                         /**< (PWMC_CLK) CLKB clock is turned off  */
#define   PWMC_CLK_DIVB_PREB_Val              (0x1U)                                         /**< (PWMC_CLK) CLKB clock is clock selected by PREB  */
#define PWMC_CLK_DIVB_CLKB_POFF               (PWMC_CLK_DIVB_CLKB_POFF_Val << PWMC_CLK_DIVB_Pos)  /**< (PWMC_CLK) CLKB clock is turned off Position  */
#define PWMC_CLK_DIVB_PREB                    (PWMC_CLK_DIVB_PREB_Val << PWMC_CLK_DIVB_Pos)  /**< (PWMC_CLK) CLKB clock is clock selected by PREB Position  */
#define PWMC_CLK_PREB_Pos                     (24)                                           /**< (PWMC_CLK) CLKB Source Clock Selection Position */
#define PWMC_CLK_PREB_Msk                     (0xFU << PWMC_CLK_PREB_Pos)                    /**< (PWMC_CLK) CLKB Source Clock Selection Mask */
#define PWMC_CLK_PREB(value)                  (PWMC_CLK_PREB_Msk & ((value) << PWMC_CLK_PREB_Pos))
#define   PWMC_CLK_PREB_CLK_Val               (0x0U)                                         /**< (PWMC_CLK) Peripheral clock  */
#define   PWMC_CLK_PREB_CLK_DIV2_Val          (0x1U)                                         /**< (PWMC_CLK) Peripheral clock/2  */
#define   PWMC_CLK_PREB_CLK_DIV4_Val          (0x2U)                                         /**< (PWMC_CLK) Peripheral clock/4  */
#define   PWMC_CLK_PREB_CLK_DIV8_Val          (0x3U)                                         /**< (PWMC_CLK) Peripheral clock/8  */
#define   PWMC_CLK_PREB_CLK_DIV16_Val         (0x4U)                                         /**< (PWMC_CLK) Peripheral clock/16  */
#define   PWMC_CLK_PREB_CLK_DIV32_Val         (0x5U)                                         /**< (PWMC_CLK) Peripheral clock/32  */
#define   PWMC_CLK_PREB_CLK_DIV64_Val         (0x6U)                                         /**< (PWMC_CLK) Peripheral clock/64  */
#define   PWMC_CLK_PREB_CLK_DIV128_Val        (0x7U)                                         /**< (PWMC_CLK) Peripheral clock/128  */
#define   PWMC_CLK_PREB_CLK_DIV256_Val        (0x8U)                                         /**< (PWMC_CLK) Peripheral clock/256  */
#define   PWMC_CLK_PREB_CLK_DIV512_Val        (0x9U)                                         /**< (PWMC_CLK) Peripheral clock/512  */
#define   PWMC_CLK_PREB_CLK_DIV1024_Val       (0xAU)                                         /**< (PWMC_CLK) Peripheral clock/1024  */
#define PWMC_CLK_PREB_CLK                     (PWMC_CLK_PREB_CLK_Val << PWMC_CLK_PREB_Pos)   /**< (PWMC_CLK) Peripheral clock Position  */
#define PWMC_CLK_PREB_CLK_DIV2                (PWMC_CLK_PREB_CLK_DIV2_Val << PWMC_CLK_PREB_Pos)  /**< (PWMC_CLK) Peripheral clock/2 Position  */
#define PWMC_CLK_PREB_CLK_DIV4                (PWMC_CLK_PREB_CLK_DIV4_Val << PWMC_CLK_PREB_Pos)  /**< (PWMC_CLK) Peripheral clock/4 Position  */
#define PWMC_CLK_PREB_CLK_DIV8                (PWMC_CLK_PREB_CLK_DIV8_Val << PWMC_CLK_PREB_Pos)  /**< (PWMC_CLK) Peripheral clock/8 Position  */
#define PWMC_CLK_PREB_CLK_DIV16               (PWMC_CLK_PREB_CLK_DIV16_Val << PWMC_CLK_PREB_Pos)  /**< (PWMC_CLK) Peripheral clock/16 Position  */
#define PWMC_CLK_PREB_CLK_DIV32               (PWMC_CLK_PREB_CLK_DIV32_Val << PWMC_CLK_PREB_Pos)  /**< (PWMC_CLK) Peripheral clock/32 Position  */
#define PWMC_CLK_PREB_CLK_DIV64               (PWMC_CLK_PREB_CLK_DIV64_Val << PWMC_CLK_PREB_Pos)  /**< (PWMC_CLK) Peripheral clock/64 Position  */
#define PWMC_CLK_PREB_CLK_DIV128              (PWMC_CLK_PREB_CLK_DIV128_Val << PWMC_CLK_PREB_Pos)  /**< (PWMC_CLK) Peripheral clock/128 Position  */
#define PWMC_CLK_PREB_CLK_DIV256              (PWMC_CLK_PREB_CLK_DIV256_Val << PWMC_CLK_PREB_Pos)  /**< (PWMC_CLK) Peripheral clock/256 Position  */
#define PWMC_CLK_PREB_CLK_DIV512              (PWMC_CLK_PREB_CLK_DIV512_Val << PWMC_CLK_PREB_Pos)  /**< (PWMC_CLK) Peripheral clock/512 Position  */
#define PWMC_CLK_PREB_CLK_DIV1024             (PWMC_CLK_PREB_CLK_DIV1024_Val << PWMC_CLK_PREB_Pos)  /**< (PWMC_CLK) Peripheral clock/1024 Position  */
#define PWMC_CLK_Msk                          (0x0FFF0FFFUL)                                 /**< (PWMC_CLK) Register Mask  */

/* -------- PWMC_ENA : (PWMC Offset: 0x04) (/W 32) PWMC Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t CHID0:1;                   /**< bit:      0  Channel ID                                    */
    uint32_t CHID1:1;                   /**< bit:      1  Channel ID                                    */
    uint32_t CHID2:1;                   /**< bit:      2  Channel ID                                    */
    uint32_t CHID3:1;                   /**< bit:      3  Channel ID                                    */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  struct
  {
    uint32_t CHID:4;                    /**< bit:   0..3  Channel ID                                    */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_ENA_bits_t;

#define PWMC_ENA_CHID0_Pos                    (0)                                            /**< (PWMC_ENA) Channel ID Position */
#define PWMC_ENA_CHID0_Msk                    (0x1U << PWMC_ENA_CHID0_Pos)                   /**< (PWMC_ENA) Channel ID Mask */
#define PWMC_ENA_CHID1_Pos                    (1)                                            /**< (PWMC_ENA) Channel ID Position */
#define PWMC_ENA_CHID1_Msk                    (0x1U << PWMC_ENA_CHID1_Pos)                   /**< (PWMC_ENA) Channel ID Mask */
#define PWMC_ENA_CHID2_Pos                    (2)                                            /**< (PWMC_ENA) Channel ID Position */
#define PWMC_ENA_CHID2_Msk                    (0x1U << PWMC_ENA_CHID2_Pos)                   /**< (PWMC_ENA) Channel ID Mask */
#define PWMC_ENA_CHID3_Pos                    (3)                                            /**< (PWMC_ENA) Channel ID Position */
#define PWMC_ENA_CHID3_Msk                    (0x1U << PWMC_ENA_CHID3_Pos)                   /**< (PWMC_ENA) Channel ID Mask */
#define PWMC_ENA_Msk                          (0x0000000FUL)                                 /**< (PWMC_ENA) Register Mask  */
#define PWMC_ENA_CHID_Pos                     (0)                                            /**< (PWMC_ENA Position) Channel ID */
#define PWMC_ENA_CHID_Msk                     (0xFU << PWMC_ENA_CHID_Pos)                    /**< (PWMC_ENA Mask) CHID */
#define PWMC_ENA_CHID(value)                  (PWMC_ENA_CHID_Msk & ((value) << PWMC_ENA_CHID_Pos))

/* -------- PWMC_DIS : (PWMC Offset: 0x08) (/W 32) PWMC Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t CHID0:1;                   /**< bit:      0  Channel ID                                    */
    uint32_t CHID1:1;                   /**< bit:      1  Channel ID                                    */
    uint32_t CHID2:1;                   /**< bit:      2  Channel ID                                    */
    uint32_t CHID3:1;                   /**< bit:      3  Channel ID                                    */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  struct
  {
    uint32_t CHID:4;                    /**< bit:   0..3  Channel ID                                    */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_DIS_bits_t;

#define PWMC_DIS_CHID0_Pos                    (0)                                            /**< (PWMC_DIS) Channel ID Position */
#define PWMC_DIS_CHID0_Msk                    (0x1U << PWMC_DIS_CHID0_Pos)                   /**< (PWMC_DIS) Channel ID Mask */
#define PWMC_DIS_CHID1_Pos                    (1)                                            /**< (PWMC_DIS) Channel ID Position */
#define PWMC_DIS_CHID1_Msk                    (0x1U << PWMC_DIS_CHID1_Pos)                   /**< (PWMC_DIS) Channel ID Mask */
#define PWMC_DIS_CHID2_Pos                    (2)                                            /**< (PWMC_DIS) Channel ID Position */
#define PWMC_DIS_CHID2_Msk                    (0x1U << PWMC_DIS_CHID2_Pos)                   /**< (PWMC_DIS) Channel ID Mask */
#define PWMC_DIS_CHID3_Pos                    (3)                                            /**< (PWMC_DIS) Channel ID Position */
#define PWMC_DIS_CHID3_Msk                    (0x1U << PWMC_DIS_CHID3_Pos)                   /**< (PWMC_DIS) Channel ID Mask */
#define PWMC_DIS_Msk                          (0x0000000FUL)                                 /**< (PWMC_DIS) Register Mask  */
#define PWMC_DIS_CHID_Pos                     (0)                                            /**< (PWMC_DIS Position) Channel ID */
#define PWMC_DIS_CHID_Msk                     (0xFU << PWMC_DIS_CHID_Pos)                    /**< (PWMC_DIS Mask) CHID */
#define PWMC_DIS_CHID(value)                  (PWMC_DIS_CHID_Msk & ((value) << PWMC_DIS_CHID_Pos))

/* -------- PWMC_SR : (PWMC Offset: 0x0c) (R/ 32) PWMC Status Register -------- */

typedef union
{
  struct
  {
    uint32_t CHID0:1;                   /**< bit:      0  Channel ID                                    */
    uint32_t CHID1:1;                   /**< bit:      1  Channel ID                                    */
    uint32_t CHID2:1;                   /**< bit:      2  Channel ID                                    */
    uint32_t CHID3:1;                   /**< bit:      3  Channel ID                                    */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  struct
  {
    uint32_t CHID:4;                    /**< bit:   0..3  Channel ID                                    */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_SR_bits_t;

#define PWMC_SR_CHID0_Pos                     (0)                                            /**< (PWMC_SR) Channel ID Position */
#define PWMC_SR_CHID0_Msk                     (0x1U << PWMC_SR_CHID0_Pos)                    /**< (PWMC_SR) Channel ID Mask */
#define PWMC_SR_CHID1_Pos                     (1)                                            /**< (PWMC_SR) Channel ID Position */
#define PWMC_SR_CHID1_Msk                     (0x1U << PWMC_SR_CHID1_Pos)                    /**< (PWMC_SR) Channel ID Mask */
#define PWMC_SR_CHID2_Pos                     (2)                                            /**< (PWMC_SR) Channel ID Position */
#define PWMC_SR_CHID2_Msk                     (0x1U << PWMC_SR_CHID2_Pos)                    /**< (PWMC_SR) Channel ID Mask */
#define PWMC_SR_CHID3_Pos                     (3)                                            /**< (PWMC_SR) Channel ID Position */
#define PWMC_SR_CHID3_Msk                     (0x1U << PWMC_SR_CHID3_Pos)                    /**< (PWMC_SR) Channel ID Mask */
#define PWMC_SR_Msk                           (0x0000000FUL)                                 /**< (PWMC_SR) Register Mask  */
#define PWMC_SR_CHID_Pos                      (0)                                            /**< (PWMC_SR Position) Channel ID */
#define PWMC_SR_CHID_Msk                      (0xFU << PWMC_SR_CHID_Pos)                     /**< (PWMC_SR Mask) CHID */
#define PWMC_SR_CHID(value)                   (PWMC_SR_CHID_Msk & ((value) << PWMC_SR_CHID_Pos))

/* -------- PWMC_IER1 : (PWMC Offset: 0x10) (/W 32) PWMC Interrupt Enable Register 1 -------- */

typedef union
{
  struct
  {
    uint32_t CHID0:1;                   /**< bit:      0  Counter Event on Channel 0 Interrupt Enable   */
    uint32_t CHID1:1;                   /**< bit:      1  Counter Event on Channel 1 Interrupt Enable   */
    uint32_t CHID2:1;                   /**< bit:      2  Counter Event on Channel 2 Interrupt Enable   */
    uint32_t CHID3:1;                   /**< bit:      3  Counter Event on Channel 3 Interrupt Enable   */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FCHID0:1;                  /**< bit:     16  Fault Protection Trigger on Channel 0 Interrupt Enable */
    uint32_t FCHID1:1;                  /**< bit:     17  Fault Protection Trigger on Channel 1 Interrupt Enable */
    uint32_t FCHID2:1;                  /**< bit:     18  Fault Protection Trigger on Channel 2 Interrupt Enable */
    uint32_t FCHID3:1;                  /**< bit:     19  Fault Protection Trigger on Channel 3 Interrupt Enable */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t CHID:4;                    /**< bit:   0..3  Counter Event on Channel x Interrupt Enable   */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FCHID:4;                   /**< bit: 16..19  Fault Protection Trigger on Channel 3 Interrupt Enable */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_IER1_bits_t;

#define PWMC_IER1_CHID0_Pos                   (0)                                            /**< (PWMC_IER1) Counter Event on Channel 0 Interrupt Enable Position */
#define PWMC_IER1_CHID0_Msk                   (0x1U << PWMC_IER1_CHID0_Pos)                  /**< (PWMC_IER1) Counter Event on Channel 0 Interrupt Enable Mask */
#define PWMC_IER1_CHID1_Pos                   (1)                                            /**< (PWMC_IER1) Counter Event on Channel 1 Interrupt Enable Position */
#define PWMC_IER1_CHID1_Msk                   (0x1U << PWMC_IER1_CHID1_Pos)                  /**< (PWMC_IER1) Counter Event on Channel 1 Interrupt Enable Mask */
#define PWMC_IER1_CHID2_Pos                   (2)                                            /**< (PWMC_IER1) Counter Event on Channel 2 Interrupt Enable Position */
#define PWMC_IER1_CHID2_Msk                   (0x1U << PWMC_IER1_CHID2_Pos)                  /**< (PWMC_IER1) Counter Event on Channel 2 Interrupt Enable Mask */
#define PWMC_IER1_CHID3_Pos                   (3)                                            /**< (PWMC_IER1) Counter Event on Channel 3 Interrupt Enable Position */
#define PWMC_IER1_CHID3_Msk                   (0x1U << PWMC_IER1_CHID3_Pos)                  /**< (PWMC_IER1) Counter Event on Channel 3 Interrupt Enable Mask */
#define PWMC_IER1_FCHID0_Pos                  (16)                                           /**< (PWMC_IER1) Fault Protection Trigger on Channel 0 Interrupt Enable Position */
#define PWMC_IER1_FCHID0_Msk                  (0x1U << PWMC_IER1_FCHID0_Pos)                 /**< (PWMC_IER1) Fault Protection Trigger on Channel 0 Interrupt Enable Mask */
#define PWMC_IER1_FCHID1_Pos                  (17)                                           /**< (PWMC_IER1) Fault Protection Trigger on Channel 1 Interrupt Enable Position */
#define PWMC_IER1_FCHID1_Msk                  (0x1U << PWMC_IER1_FCHID1_Pos)                 /**< (PWMC_IER1) Fault Protection Trigger on Channel 1 Interrupt Enable Mask */
#define PWMC_IER1_FCHID2_Pos                  (18)                                           /**< (PWMC_IER1) Fault Protection Trigger on Channel 2 Interrupt Enable Position */
#define PWMC_IER1_FCHID2_Msk                  (0x1U << PWMC_IER1_FCHID2_Pos)                 /**< (PWMC_IER1) Fault Protection Trigger on Channel 2 Interrupt Enable Mask */
#define PWMC_IER1_FCHID3_Pos                  (19)                                           /**< (PWMC_IER1) Fault Protection Trigger on Channel 3 Interrupt Enable Position */
#define PWMC_IER1_FCHID3_Msk                  (0x1U << PWMC_IER1_FCHID3_Pos)                 /**< (PWMC_IER1) Fault Protection Trigger on Channel 3 Interrupt Enable Mask */
#define PWMC_IER1_Msk                         (0x000F000FUL)                                 /**< (PWMC_IER1) Register Mask  */
#define PWMC_IER1_CHID_Pos                    (0)                                            /**< (PWMC_IER1 Position) Counter Event on Channel x Interrupt Enable */
#define PWMC_IER1_CHID_Msk                    (0xFU << PWMC_IER1_CHID_Pos)                   /**< (PWMC_IER1 Mask) CHID */
#define PWMC_IER1_CHID(value)                 (PWMC_IER1_CHID_Msk & ((value) << PWMC_IER1_CHID_Pos))
#define PWMC_IER1_FCHID_Pos                   (16)                                           /**< (PWMC_IER1 Position) Fault Protection Trigger on Channel 3 Interrupt Enable */
#define PWMC_IER1_FCHID_Msk                   (0xFU << PWMC_IER1_FCHID_Pos)                  /**< (PWMC_IER1 Mask) FCHID */
#define PWMC_IER1_FCHID(value)                (PWMC_IER1_FCHID_Msk & ((value) << PWMC_IER1_FCHID_Pos))

/* -------- PWMC_IDR1 : (PWMC Offset: 0x14) (/W 32) PWMC Interrupt Disable Register 1 -------- */

typedef union
{
  struct
  {
    uint32_t CHID0:1;                   /**< bit:      0  Counter Event on Channel 0 Interrupt Disable  */
    uint32_t CHID1:1;                   /**< bit:      1  Counter Event on Channel 1 Interrupt Disable  */
    uint32_t CHID2:1;                   /**< bit:      2  Counter Event on Channel 2 Interrupt Disable  */
    uint32_t CHID3:1;                   /**< bit:      3  Counter Event on Channel 3 Interrupt Disable  */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FCHID0:1;                  /**< bit:     16  Fault Protection Trigger on Channel 0 Interrupt Disable */
    uint32_t FCHID1:1;                  /**< bit:     17  Fault Protection Trigger on Channel 1 Interrupt Disable */
    uint32_t FCHID2:1;                  /**< bit:     18  Fault Protection Trigger on Channel 2 Interrupt Disable */
    uint32_t FCHID3:1;                  /**< bit:     19  Fault Protection Trigger on Channel 3 Interrupt Disable */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t CHID:4;                    /**< bit:   0..3  Counter Event on Channel x Interrupt Disable  */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FCHID:4;                   /**< bit: 16..19  Fault Protection Trigger on Channel 3 Interrupt Disable */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_IDR1_bits_t;

#define PWMC_IDR1_CHID0_Pos                   (0)                                            /**< (PWMC_IDR1) Counter Event on Channel 0 Interrupt Disable Position */
#define PWMC_IDR1_CHID0_Msk                   (0x1U << PWMC_IDR1_CHID0_Pos)                  /**< (PWMC_IDR1) Counter Event on Channel 0 Interrupt Disable Mask */
#define PWMC_IDR1_CHID1_Pos                   (1)                                            /**< (PWMC_IDR1) Counter Event on Channel 1 Interrupt Disable Position */
#define PWMC_IDR1_CHID1_Msk                   (0x1U << PWMC_IDR1_CHID1_Pos)                  /**< (PWMC_IDR1) Counter Event on Channel 1 Interrupt Disable Mask */
#define PWMC_IDR1_CHID2_Pos                   (2)                                            /**< (PWMC_IDR1) Counter Event on Channel 2 Interrupt Disable Position */
#define PWMC_IDR1_CHID2_Msk                   (0x1U << PWMC_IDR1_CHID2_Pos)                  /**< (PWMC_IDR1) Counter Event on Channel 2 Interrupt Disable Mask */
#define PWMC_IDR1_CHID3_Pos                   (3)                                            /**< (PWMC_IDR1) Counter Event on Channel 3 Interrupt Disable Position */
#define PWMC_IDR1_CHID3_Msk                   (0x1U << PWMC_IDR1_CHID3_Pos)                  /**< (PWMC_IDR1) Counter Event on Channel 3 Interrupt Disable Mask */
#define PWMC_IDR1_FCHID0_Pos                  (16)                                           /**< (PWMC_IDR1) Fault Protection Trigger on Channel 0 Interrupt Disable Position */
#define PWMC_IDR1_FCHID0_Msk                  (0x1U << PWMC_IDR1_FCHID0_Pos)                 /**< (PWMC_IDR1) Fault Protection Trigger on Channel 0 Interrupt Disable Mask */
#define PWMC_IDR1_FCHID1_Pos                  (17)                                           /**< (PWMC_IDR1) Fault Protection Trigger on Channel 1 Interrupt Disable Position */
#define PWMC_IDR1_FCHID1_Msk                  (0x1U << PWMC_IDR1_FCHID1_Pos)                 /**< (PWMC_IDR1) Fault Protection Trigger on Channel 1 Interrupt Disable Mask */
#define PWMC_IDR1_FCHID2_Pos                  (18)                                           /**< (PWMC_IDR1) Fault Protection Trigger on Channel 2 Interrupt Disable Position */
#define PWMC_IDR1_FCHID2_Msk                  (0x1U << PWMC_IDR1_FCHID2_Pos)                 /**< (PWMC_IDR1) Fault Protection Trigger on Channel 2 Interrupt Disable Mask */
#define PWMC_IDR1_FCHID3_Pos                  (19)                                           /**< (PWMC_IDR1) Fault Protection Trigger on Channel 3 Interrupt Disable Position */
#define PWMC_IDR1_FCHID3_Msk                  (0x1U << PWMC_IDR1_FCHID3_Pos)                 /**< (PWMC_IDR1) Fault Protection Trigger on Channel 3 Interrupt Disable Mask */
#define PWMC_IDR1_Msk                         (0x000F000FUL)                                 /**< (PWMC_IDR1) Register Mask  */
#define PWMC_IDR1_CHID_Pos                    (0)                                            /**< (PWMC_IDR1 Position) Counter Event on Channel x Interrupt Disable */
#define PWMC_IDR1_CHID_Msk                    (0xFU << PWMC_IDR1_CHID_Pos)                   /**< (PWMC_IDR1 Mask) CHID */
#define PWMC_IDR1_CHID(value)                 (PWMC_IDR1_CHID_Msk & ((value) << PWMC_IDR1_CHID_Pos))
#define PWMC_IDR1_FCHID_Pos                   (16)                                           /**< (PWMC_IDR1 Position) Fault Protection Trigger on Channel 3 Interrupt Disable */
#define PWMC_IDR1_FCHID_Msk                   (0xFU << PWMC_IDR1_FCHID_Pos)                  /**< (PWMC_IDR1 Mask) FCHID */
#define PWMC_IDR1_FCHID(value)                (PWMC_IDR1_FCHID_Msk & ((value) << PWMC_IDR1_FCHID_Pos))

/* -------- PWMC_IMR1 : (PWMC Offset: 0x18) (R/ 32) PWMC Interrupt Mask Register 1 -------- */

typedef union
{
  struct
  {
    uint32_t CHID0:1;                   /**< bit:      0  Counter Event on Channel 0 Interrupt Mask     */
    uint32_t CHID1:1;                   /**< bit:      1  Counter Event on Channel 1 Interrupt Mask     */
    uint32_t CHID2:1;                   /**< bit:      2  Counter Event on Channel 2 Interrupt Mask     */
    uint32_t CHID3:1;                   /**< bit:      3  Counter Event on Channel 3 Interrupt Mask     */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FCHID0:1;                  /**< bit:     16  Fault Protection Trigger on Channel 0 Interrupt Mask */
    uint32_t FCHID1:1;                  /**< bit:     17  Fault Protection Trigger on Channel 1 Interrupt Mask */
    uint32_t FCHID2:1;                  /**< bit:     18  Fault Protection Trigger on Channel 2 Interrupt Mask */
    uint32_t FCHID3:1;                  /**< bit:     19  Fault Protection Trigger on Channel 3 Interrupt Mask */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t CHID:4;                    /**< bit:   0..3  Counter Event on Channel x Interrupt Mask     */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FCHID:4;                   /**< bit: 16..19  Fault Protection Trigger on Channel 3 Interrupt Mask */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_IMR1_bits_t;

#define PWMC_IMR1_CHID0_Pos                   (0)                                            /**< (PWMC_IMR1) Counter Event on Channel 0 Interrupt Mask Position */
#define PWMC_IMR1_CHID0_Msk                   (0x1U << PWMC_IMR1_CHID0_Pos)                  /**< (PWMC_IMR1) Counter Event on Channel 0 Interrupt Mask Mask */
#define PWMC_IMR1_CHID1_Pos                   (1)                                            /**< (PWMC_IMR1) Counter Event on Channel 1 Interrupt Mask Position */
#define PWMC_IMR1_CHID1_Msk                   (0x1U << PWMC_IMR1_CHID1_Pos)                  /**< (PWMC_IMR1) Counter Event on Channel 1 Interrupt Mask Mask */
#define PWMC_IMR1_CHID2_Pos                   (2)                                            /**< (PWMC_IMR1) Counter Event on Channel 2 Interrupt Mask Position */
#define PWMC_IMR1_CHID2_Msk                   (0x1U << PWMC_IMR1_CHID2_Pos)                  /**< (PWMC_IMR1) Counter Event on Channel 2 Interrupt Mask Mask */
#define PWMC_IMR1_CHID3_Pos                   (3)                                            /**< (PWMC_IMR1) Counter Event on Channel 3 Interrupt Mask Position */
#define PWMC_IMR1_CHID3_Msk                   (0x1U << PWMC_IMR1_CHID3_Pos)                  /**< (PWMC_IMR1) Counter Event on Channel 3 Interrupt Mask Mask */
#define PWMC_IMR1_FCHID0_Pos                  (16)                                           /**< (PWMC_IMR1) Fault Protection Trigger on Channel 0 Interrupt Mask Position */
#define PWMC_IMR1_FCHID0_Msk                  (0x1U << PWMC_IMR1_FCHID0_Pos)                 /**< (PWMC_IMR1) Fault Protection Trigger on Channel 0 Interrupt Mask Mask */
#define PWMC_IMR1_FCHID1_Pos                  (17)                                           /**< (PWMC_IMR1) Fault Protection Trigger on Channel 1 Interrupt Mask Position */
#define PWMC_IMR1_FCHID1_Msk                  (0x1U << PWMC_IMR1_FCHID1_Pos)                 /**< (PWMC_IMR1) Fault Protection Trigger on Channel 1 Interrupt Mask Mask */
#define PWMC_IMR1_FCHID2_Pos                  (18)                                           /**< (PWMC_IMR1) Fault Protection Trigger on Channel 2 Interrupt Mask Position */
#define PWMC_IMR1_FCHID2_Msk                  (0x1U << PWMC_IMR1_FCHID2_Pos)                 /**< (PWMC_IMR1) Fault Protection Trigger on Channel 2 Interrupt Mask Mask */
#define PWMC_IMR1_FCHID3_Pos                  (19)                                           /**< (PWMC_IMR1) Fault Protection Trigger on Channel 3 Interrupt Mask Position */
#define PWMC_IMR1_FCHID3_Msk                  (0x1U << PWMC_IMR1_FCHID3_Pos)                 /**< (PWMC_IMR1) Fault Protection Trigger on Channel 3 Interrupt Mask Mask */
#define PWMC_IMR1_Msk                         (0x000F000FUL)                                 /**< (PWMC_IMR1) Register Mask  */
#define PWMC_IMR1_CHID_Pos                    (0)                                            /**< (PWMC_IMR1 Position) Counter Event on Channel x Interrupt Mask */
#define PWMC_IMR1_CHID_Msk                    (0xFU << PWMC_IMR1_CHID_Pos)                   /**< (PWMC_IMR1 Mask) CHID */
#define PWMC_IMR1_CHID(value)                 (PWMC_IMR1_CHID_Msk & ((value) << PWMC_IMR1_CHID_Pos))
#define PWMC_IMR1_FCHID_Pos                   (16)                                           /**< (PWMC_IMR1 Position) Fault Protection Trigger on Channel 3 Interrupt Mask */
#define PWMC_IMR1_FCHID_Msk                   (0xFU << PWMC_IMR1_FCHID_Pos)                  /**< (PWMC_IMR1 Mask) FCHID */
#define PWMC_IMR1_FCHID(value)                (PWMC_IMR1_FCHID_Msk & ((value) << PWMC_IMR1_FCHID_Pos))

/* -------- PWMC_ISR1 : (PWMC Offset: 0x1c) (R/ 32) PWMC Interrupt Status Register 1 -------- */

typedef union
{
  struct
  {
    uint32_t CHID0:1;                   /**< bit:      0  Counter Event on Channel 0                    */
    uint32_t CHID1:1;                   /**< bit:      1  Counter Event on Channel 1                    */
    uint32_t CHID2:1;                   /**< bit:      2  Counter Event on Channel 2                    */
    uint32_t CHID3:1;                   /**< bit:      3  Counter Event on Channel 3                    */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FCHID0:1;                  /**< bit:     16  Fault Protection Trigger on Channel 0         */
    uint32_t FCHID1:1;                  /**< bit:     17  Fault Protection Trigger on Channel 1         */
    uint32_t FCHID2:1;                  /**< bit:     18  Fault Protection Trigger on Channel 2         */
    uint32_t FCHID3:1;                  /**< bit:     19  Fault Protection Trigger on Channel 3         */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t CHID:4;                    /**< bit:   0..3  Counter Event on Channel x                    */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FCHID:4;                   /**< bit: 16..19  Fault Protection Trigger on Channel 3         */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_ISR1_bits_t;

#define PWMC_ISR1_CHID0_Pos                   (0)                                            /**< (PWMC_ISR1) Counter Event on Channel 0 Position */
#define PWMC_ISR1_CHID0_Msk                   (0x1U << PWMC_ISR1_CHID0_Pos)                  /**< (PWMC_ISR1) Counter Event on Channel 0 Mask */
#define PWMC_ISR1_CHID1_Pos                   (1)                                            /**< (PWMC_ISR1) Counter Event on Channel 1 Position */
#define PWMC_ISR1_CHID1_Msk                   (0x1U << PWMC_ISR1_CHID1_Pos)                  /**< (PWMC_ISR1) Counter Event on Channel 1 Mask */
#define PWMC_ISR1_CHID2_Pos                   (2)                                            /**< (PWMC_ISR1) Counter Event on Channel 2 Position */
#define PWMC_ISR1_CHID2_Msk                   (0x1U << PWMC_ISR1_CHID2_Pos)                  /**< (PWMC_ISR1) Counter Event on Channel 2 Mask */
#define PWMC_ISR1_CHID3_Pos                   (3)                                            /**< (PWMC_ISR1) Counter Event on Channel 3 Position */
#define PWMC_ISR1_CHID3_Msk                   (0x1U << PWMC_ISR1_CHID3_Pos)                  /**< (PWMC_ISR1) Counter Event on Channel 3 Mask */
#define PWMC_ISR1_FCHID0_Pos                  (16)                                           /**< (PWMC_ISR1) Fault Protection Trigger on Channel 0 Position */
#define PWMC_ISR1_FCHID0_Msk                  (0x1U << PWMC_ISR1_FCHID0_Pos)                 /**< (PWMC_ISR1) Fault Protection Trigger on Channel 0 Mask */
#define PWMC_ISR1_FCHID1_Pos                  (17)                                           /**< (PWMC_ISR1) Fault Protection Trigger on Channel 1 Position */
#define PWMC_ISR1_FCHID1_Msk                  (0x1U << PWMC_ISR1_FCHID1_Pos)                 /**< (PWMC_ISR1) Fault Protection Trigger on Channel 1 Mask */
#define PWMC_ISR1_FCHID2_Pos                  (18)                                           /**< (PWMC_ISR1) Fault Protection Trigger on Channel 2 Position */
#define PWMC_ISR1_FCHID2_Msk                  (0x1U << PWMC_ISR1_FCHID2_Pos)                 /**< (PWMC_ISR1) Fault Protection Trigger on Channel 2 Mask */
#define PWMC_ISR1_FCHID3_Pos                  (19)                                           /**< (PWMC_ISR1) Fault Protection Trigger on Channel 3 Position */
#define PWMC_ISR1_FCHID3_Msk                  (0x1U << PWMC_ISR1_FCHID3_Pos)                 /**< (PWMC_ISR1) Fault Protection Trigger on Channel 3 Mask */
#define PWMC_ISR1_Msk                         (0x000F000FUL)                                 /**< (PWMC_ISR1) Register Mask  */
#define PWMC_ISR1_CHID_Pos                    (0)                                            /**< (PWMC_ISR1 Position) Counter Event on Channel x */
#define PWMC_ISR1_CHID_Msk                    (0xFU << PWMC_ISR1_CHID_Pos)                   /**< (PWMC_ISR1 Mask) CHID */
#define PWMC_ISR1_CHID(value)                 (PWMC_ISR1_CHID_Msk & ((value) << PWMC_ISR1_CHID_Pos))
#define PWMC_ISR1_FCHID_Pos                   (16)                                           /**< (PWMC_ISR1 Position) Fault Protection Trigger on Channel 3 */
#define PWMC_ISR1_FCHID_Msk                   (0xFU << PWMC_ISR1_FCHID_Pos)                  /**< (PWMC_ISR1 Mask) FCHID */
#define PWMC_ISR1_FCHID(value)                (PWMC_ISR1_FCHID_Msk & ((value) << PWMC_ISR1_FCHID_Pos))

/* -------- PWMC_SCM : (PWMC Offset: 0x20) (R/W 32) PWMC Sync Channels Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t SYNC0:1;                   /**< bit:      0  Synchronous Channel 0                         */
    uint32_t SYNC1:1;                   /**< bit:      1  Synchronous Channel 1                         */
    uint32_t SYNC2:1;                   /**< bit:      2  Synchronous Channel 2                         */
    uint32_t SYNC3:1;                   /**< bit:      3  Synchronous Channel 3                         */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t UPDM:2;                    /**< bit: 16..17  Synchronous Channels Update Mode              */
    uint32_t :2;                        /**< bit: 18..19  Reserved                                      */
    uint32_t PTRM:1;                    /**< bit:     20  DMA Controller Transfer Request Mode          */
    uint32_t PTRCS:3;                   /**< bit: 21..23  DMA Controller Transfer Request Comparison Selection */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  struct
  {
    uint32_t SYNC:4;                    /**< bit:   0..3  Synchronous Channel x                         */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_SCM_bits_t;

#define PWMC_SCM_SYNC0_Pos                    (0)                                            /**< (PWMC_SCM) Synchronous Channel 0 Position */
#define PWMC_SCM_SYNC0_Msk                    (0x1U << PWMC_SCM_SYNC0_Pos)                   /**< (PWMC_SCM) Synchronous Channel 0 Mask */
#define PWMC_SCM_SYNC1_Pos                    (1)                                            /**< (PWMC_SCM) Synchronous Channel 1 Position */
#define PWMC_SCM_SYNC1_Msk                    (0x1U << PWMC_SCM_SYNC1_Pos)                   /**< (PWMC_SCM) Synchronous Channel 1 Mask */
#define PWMC_SCM_SYNC2_Pos                    (2)                                            /**< (PWMC_SCM) Synchronous Channel 2 Position */
#define PWMC_SCM_SYNC2_Msk                    (0x1U << PWMC_SCM_SYNC2_Pos)                   /**< (PWMC_SCM) Synchronous Channel 2 Mask */
#define PWMC_SCM_SYNC3_Pos                    (3)                                            /**< (PWMC_SCM) Synchronous Channel 3 Position */
#define PWMC_SCM_SYNC3_Msk                    (0x1U << PWMC_SCM_SYNC3_Pos)                   /**< (PWMC_SCM) Synchronous Channel 3 Mask */
#define PWMC_SCM_UPDM_Pos                     (16)                                           /**< (PWMC_SCM) Synchronous Channels Update Mode Position */
#define PWMC_SCM_UPDM_Msk                     (0x3U << PWMC_SCM_UPDM_Pos)                    /**< (PWMC_SCM) Synchronous Channels Update Mode Mask */
#define PWMC_SCM_UPDM(value)                  (PWMC_SCM_UPDM_Msk & ((value) << PWMC_SCM_UPDM_Pos))
#define PWMC_SCM_PTRM_Pos                     (20)                                           /**< (PWMC_SCM) DMA Controller Transfer Request Mode Position */
#define PWMC_SCM_PTRM_Msk                     (0x1U << PWMC_SCM_PTRM_Pos)                    /**< (PWMC_SCM) DMA Controller Transfer Request Mode Mask */
#define PWMC_SCM_PTRCS_Pos                    (21)                                           /**< (PWMC_SCM) DMA Controller Transfer Request Comparison Selection Position */
#define PWMC_SCM_PTRCS_Msk                    (0x7U << PWMC_SCM_PTRCS_Pos)                   /**< (PWMC_SCM) DMA Controller Transfer Request Comparison Selection Mask */
#define PWMC_SCM_PTRCS(value)                 (PWMC_SCM_PTRCS_Msk & ((value) << PWMC_SCM_PTRCS_Pos))
#define PWMC_SCM_Msk                          (0x00F3000FUL)                                 /**< (PWMC_SCM) Register Mask  */
#define PWMC_SCM_SYNC_Pos                     (0)                                            /**< (PWMC_SCM Position) Synchronous Channel x */
#define PWMC_SCM_SYNC_Msk                     (0xFU << PWMC_SCM_SYNC_Pos)                    /**< (PWMC_SCM Mask) SYNC */
#define PWMC_SCM_SYNC(value)                  (PWMC_SCM_SYNC_Msk & ((value) << PWMC_SCM_SYNC_Pos))

/* -------- PWMC_DMAR : (PWMC Offset: 0x24) (/W 32) PWMC DMA Register -------- */

typedef union
{
  struct
  {
    uint32_t DMADUTY:24;                /**< bit:  0..23  Duty-Cycle Holding Register for DMA Access    */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_DMAR_bits_t;

#define PWMC_DMAR_DMADUTY_Pos                 (0)                                            /**< (PWMC_DMAR) Duty-Cycle Holding Register for DMA Access Position */
#define PWMC_DMAR_DMADUTY_Msk                 (0xFFFFFFU << PWMC_DMAR_DMADUTY_Pos)           /**< (PWMC_DMAR) Duty-Cycle Holding Register for DMA Access Mask */
#define PWMC_DMAR_DMADUTY(value)              (PWMC_DMAR_DMADUTY_Msk & ((value) << PWMC_DMAR_DMADUTY_Pos))
#define PWMC_DMAR_Msk                         (0x00FFFFFFUL)                                 /**< (PWMC_DMAR) Register Mask  */

/* -------- PWMC_SCUC : (PWMC Offset: 0x28) (R/W 32) PWMC Sync Channels Update Control Register -------- */

typedef union
{
  struct
  {
    uint32_t UPDULOCK:1;                /**< bit:      0  Synchronous Channels Update Unlock            */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_SCUC_bits_t;

#define PWMC_SCUC_UPDULOCK_Pos                (0)                                            /**< (PWMC_SCUC) Synchronous Channels Update Unlock Position */
#define PWMC_SCUC_UPDULOCK_Msk                (0x1U << PWMC_SCUC_UPDULOCK_Pos)               /**< (PWMC_SCUC) Synchronous Channels Update Unlock Mask */
#define PWMC_SCUC_Msk                         (0x00000001UL)                                 /**< (PWMC_SCUC) Register Mask  */

/* -------- PWMC_SCUP : (PWMC Offset: 0x2c) (R/W 32) PWMC Sync Channels Update Period Register -------- */

typedef union
{
  struct
  {
    uint32_t UPR:4;                     /**< bit:   0..3  Update Period                                 */
    uint32_t UPRCNT:4;                  /**< bit:   4..7  Update Period Counter                         */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_SCUP_bits_t;

#define PWMC_SCUP_UPR_Pos                     (0)                                            /**< (PWMC_SCUP) Update Period Position */
#define PWMC_SCUP_UPR_Msk                     (0xFU << PWMC_SCUP_UPR_Pos)                    /**< (PWMC_SCUP) Update Period Mask */
#define PWMC_SCUP_UPR(value)                  (PWMC_SCUP_UPR_Msk & ((value) << PWMC_SCUP_UPR_Pos))
#define PWMC_SCUP_UPRCNT_Pos                  (4)                                            /**< (PWMC_SCUP) Update Period Counter Position */
#define PWMC_SCUP_UPRCNT_Msk                  (0xFU << PWMC_SCUP_UPRCNT_Pos)                 /**< (PWMC_SCUP) Update Period Counter Mask */
#define PWMC_SCUP_UPRCNT(value)               (PWMC_SCUP_UPRCNT_Msk & ((value) << PWMC_SCUP_UPRCNT_Pos))
#define PWMC_SCUP_Msk                         (0x000000FFUL)                                 /**< (PWMC_SCUP) Register Mask  */

/* -------- PWMC_SCUPUPD : (PWMC Offset: 0x30) (/W 32) PWMC Sync Channels Update Period Update Register -------- */

typedef union
{
  struct
  {
    uint32_t UPRUPD:4;                  /**< bit:   0..3  Update Period Update                          */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_SCUPUPD_bits_t;

#define PWMC_SCUPUPD_UPRUPD_Pos               (0)                                            /**< (PWMC_SCUPUPD) Update Period Update Position */
#define PWMC_SCUPUPD_UPRUPD_Msk               (0xFU << PWMC_SCUPUPD_UPRUPD_Pos)              /**< (PWMC_SCUPUPD) Update Period Update Mask */
#define PWMC_SCUPUPD_UPRUPD(value)            (PWMC_SCUPUPD_UPRUPD_Msk & ((value) << PWMC_SCUPUPD_UPRUPD_Pos))
#define PWMC_SCUPUPD_Msk                      (0x0000000FUL)                                 /**< (PWMC_SCUPUPD) Register Mask  */

/* -------- PWMC_IER2 : (PWMC Offset: 0x34) (/W 32) PWMC Interrupt Enable Register 2 -------- */

typedef union
{
  struct
  {
    uint32_t WRDY:1;                    /**< bit:      0  Write Ready for Synchronous Channels Update Interrupt Enable */
    uint32_t :2;                        /**< bit:   1..2  Reserved                                      */
    uint32_t UNRE:1;                    /**< bit:      3  Synchronous Channels Update Underrun Error Interrupt Enable */
    uint32_t :4;                        /**< bit:   4..7  Reserved                                      */
    uint32_t CMPM0:1;                   /**< bit:      8  Comparison 0 Match Interrupt Enable           */
    uint32_t CMPM1:1;                   /**< bit:      9  Comparison 1 Match Interrupt Enable           */
    uint32_t CMPM2:1;                   /**< bit:     10  Comparison 2 Match Interrupt Enable           */
    uint32_t CMPM3:1;                   /**< bit:     11  Comparison 3 Match Interrupt Enable           */
    uint32_t CMPM4:1;                   /**< bit:     12  Comparison 4 Match Interrupt Enable           */
    uint32_t CMPM5:1;                   /**< bit:     13  Comparison 5 Match Interrupt Enable           */
    uint32_t CMPM6:1;                   /**< bit:     14  Comparison 6 Match Interrupt Enable           */
    uint32_t CMPM7:1;                   /**< bit:     15  Comparison 7 Match Interrupt Enable           */
    uint32_t CMPU0:1;                   /**< bit:     16  Comparison 0 Update Interrupt Enable          */
    uint32_t CMPU1:1;                   /**< bit:     17  Comparison 1 Update Interrupt Enable          */
    uint32_t CMPU2:1;                   /**< bit:     18  Comparison 2 Update Interrupt Enable          */
    uint32_t CMPU3:1;                   /**< bit:     19  Comparison 3 Update Interrupt Enable          */
    uint32_t CMPU4:1;                   /**< bit:     20  Comparison 4 Update Interrupt Enable          */
    uint32_t CMPU5:1;                   /**< bit:     21  Comparison 5 Update Interrupt Enable          */
    uint32_t CMPU6:1;                   /**< bit:     22  Comparison 6 Update Interrupt Enable          */
    uint32_t CMPU7:1;                   /**< bit:     23  Comparison 7 Update Interrupt Enable          */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  struct
  {
    uint32_t :8;                        /**< bit:   0..7  Reserved                                      */
    uint32_t CMPM:8;                    /**< bit:  8..15  Comparison x Match Interrupt Enable           */
    uint32_t CMPU:8;                    /**< bit: 16..23  Comparison 7 Update Interrupt Enable          */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_IER2_bits_t;

#define PWMC_IER2_WRDY_Pos                    (0)                                            /**< (PWMC_IER2) Write Ready for Synchronous Channels Update Interrupt Enable Position */
#define PWMC_IER2_WRDY_Msk                    (0x1U << PWMC_IER2_WRDY_Pos)                   /**< (PWMC_IER2) Write Ready for Synchronous Channels Update Interrupt Enable Mask */
#define PWMC_IER2_UNRE_Pos                    (3)                                            /**< (PWMC_IER2) Synchronous Channels Update Underrun Error Interrupt Enable Position */
#define PWMC_IER2_UNRE_Msk                    (0x1U << PWMC_IER2_UNRE_Pos)                   /**< (PWMC_IER2) Synchronous Channels Update Underrun Error Interrupt Enable Mask */
#define PWMC_IER2_CMPM0_Pos                   (8)                                            /**< (PWMC_IER2) Comparison 0 Match Interrupt Enable Position */
#define PWMC_IER2_CMPM0_Msk                   (0x1U << PWMC_IER2_CMPM0_Pos)                  /**< (PWMC_IER2) Comparison 0 Match Interrupt Enable Mask */
#define PWMC_IER2_CMPM1_Pos                   (9)                                            /**< (PWMC_IER2) Comparison 1 Match Interrupt Enable Position */
#define PWMC_IER2_CMPM1_Msk                   (0x1U << PWMC_IER2_CMPM1_Pos)                  /**< (PWMC_IER2) Comparison 1 Match Interrupt Enable Mask */
#define PWMC_IER2_CMPM2_Pos                   (10)                                           /**< (PWMC_IER2) Comparison 2 Match Interrupt Enable Position */
#define PWMC_IER2_CMPM2_Msk                   (0x1U << PWMC_IER2_CMPM2_Pos)                  /**< (PWMC_IER2) Comparison 2 Match Interrupt Enable Mask */
#define PWMC_IER2_CMPM3_Pos                   (11)                                           /**< (PWMC_IER2) Comparison 3 Match Interrupt Enable Position */
#define PWMC_IER2_CMPM3_Msk                   (0x1U << PWMC_IER2_CMPM3_Pos)                  /**< (PWMC_IER2) Comparison 3 Match Interrupt Enable Mask */
#define PWMC_IER2_CMPM4_Pos                   (12)                                           /**< (PWMC_IER2) Comparison 4 Match Interrupt Enable Position */
#define PWMC_IER2_CMPM4_Msk                   (0x1U << PWMC_IER2_CMPM4_Pos)                  /**< (PWMC_IER2) Comparison 4 Match Interrupt Enable Mask */
#define PWMC_IER2_CMPM5_Pos                   (13)                                           /**< (PWMC_IER2) Comparison 5 Match Interrupt Enable Position */
#define PWMC_IER2_CMPM5_Msk                   (0x1U << PWMC_IER2_CMPM5_Pos)                  /**< (PWMC_IER2) Comparison 5 Match Interrupt Enable Mask */
#define PWMC_IER2_CMPM6_Pos                   (14)                                           /**< (PWMC_IER2) Comparison 6 Match Interrupt Enable Position */
#define PWMC_IER2_CMPM6_Msk                   (0x1U << PWMC_IER2_CMPM6_Pos)                  /**< (PWMC_IER2) Comparison 6 Match Interrupt Enable Mask */
#define PWMC_IER2_CMPM7_Pos                   (15)                                           /**< (PWMC_IER2) Comparison 7 Match Interrupt Enable Position */
#define PWMC_IER2_CMPM7_Msk                   (0x1U << PWMC_IER2_CMPM7_Pos)                  /**< (PWMC_IER2) Comparison 7 Match Interrupt Enable Mask */
#define PWMC_IER2_CMPU0_Pos                   (16)                                           /**< (PWMC_IER2) Comparison 0 Update Interrupt Enable Position */
#define PWMC_IER2_CMPU0_Msk                   (0x1U << PWMC_IER2_CMPU0_Pos)                  /**< (PWMC_IER2) Comparison 0 Update Interrupt Enable Mask */
#define PWMC_IER2_CMPU1_Pos                   (17)                                           /**< (PWMC_IER2) Comparison 1 Update Interrupt Enable Position */
#define PWMC_IER2_CMPU1_Msk                   (0x1U << PWMC_IER2_CMPU1_Pos)                  /**< (PWMC_IER2) Comparison 1 Update Interrupt Enable Mask */
#define PWMC_IER2_CMPU2_Pos                   (18)                                           /**< (PWMC_IER2) Comparison 2 Update Interrupt Enable Position */
#define PWMC_IER2_CMPU2_Msk                   (0x1U << PWMC_IER2_CMPU2_Pos)                  /**< (PWMC_IER2) Comparison 2 Update Interrupt Enable Mask */
#define PWMC_IER2_CMPU3_Pos                   (19)                                           /**< (PWMC_IER2) Comparison 3 Update Interrupt Enable Position */
#define PWMC_IER2_CMPU3_Msk                   (0x1U << PWMC_IER2_CMPU3_Pos)                  /**< (PWMC_IER2) Comparison 3 Update Interrupt Enable Mask */
#define PWMC_IER2_CMPU4_Pos                   (20)                                           /**< (PWMC_IER2) Comparison 4 Update Interrupt Enable Position */
#define PWMC_IER2_CMPU4_Msk                   (0x1U << PWMC_IER2_CMPU4_Pos)                  /**< (PWMC_IER2) Comparison 4 Update Interrupt Enable Mask */
#define PWMC_IER2_CMPU5_Pos                   (21)                                           /**< (PWMC_IER2) Comparison 5 Update Interrupt Enable Position */
#define PWMC_IER2_CMPU5_Msk                   (0x1U << PWMC_IER2_CMPU5_Pos)                  /**< (PWMC_IER2) Comparison 5 Update Interrupt Enable Mask */
#define PWMC_IER2_CMPU6_Pos                   (22)                                           /**< (PWMC_IER2) Comparison 6 Update Interrupt Enable Position */
#define PWMC_IER2_CMPU6_Msk                   (0x1U << PWMC_IER2_CMPU6_Pos)                  /**< (PWMC_IER2) Comparison 6 Update Interrupt Enable Mask */
#define PWMC_IER2_CMPU7_Pos                   (23)                                           /**< (PWMC_IER2) Comparison 7 Update Interrupt Enable Position */
#define PWMC_IER2_CMPU7_Msk                   (0x1U << PWMC_IER2_CMPU7_Pos)                  /**< (PWMC_IER2) Comparison 7 Update Interrupt Enable Mask */
#define PWMC_IER2_Msk                         (0x00FFFF09UL)                                 /**< (PWMC_IER2) Register Mask  */
#define PWMC_IER2_CMPM_Pos                    (8)                                            /**< (PWMC_IER2 Position) Comparison x Match Interrupt Enable */
#define PWMC_IER2_CMPM_Msk                    (0xFFU << PWMC_IER2_CMPM_Pos)                  /**< (PWMC_IER2 Mask) CMPM */
#define PWMC_IER2_CMPM(value)                 (PWMC_IER2_CMPM_Msk & ((value) << PWMC_IER2_CMPM_Pos))
#define PWMC_IER2_CMPU_Pos                    (16)                                           /**< (PWMC_IER2 Position) Comparison 7 Update Interrupt Enable */
#define PWMC_IER2_CMPU_Msk                    (0xFFU << PWMC_IER2_CMPU_Pos)                  /**< (PWMC_IER2 Mask) CMPU */
#define PWMC_IER2_CMPU(value)                 (PWMC_IER2_CMPU_Msk & ((value) << PWMC_IER2_CMPU_Pos))

/* -------- PWMC_IDR2 : (PWMC Offset: 0x38) (/W 32) PWMC Interrupt Disable Register 2 -------- */

typedef union
{
  struct
  {
    uint32_t WRDY:1;                    /**< bit:      0  Write Ready for Synchronous Channels Update Interrupt Disable */
    uint32_t :2;                        /**< bit:   1..2  Reserved                                      */
    uint32_t UNRE:1;                    /**< bit:      3  Synchronous Channels Update Underrun Error Interrupt Disable */
    uint32_t :4;                        /**< bit:   4..7  Reserved                                      */
    uint32_t CMPM0:1;                   /**< bit:      8  Comparison 0 Match Interrupt Disable          */
    uint32_t CMPM1:1;                   /**< bit:      9  Comparison 1 Match Interrupt Disable          */
    uint32_t CMPM2:1;                   /**< bit:     10  Comparison 2 Match Interrupt Disable          */
    uint32_t CMPM3:1;                   /**< bit:     11  Comparison 3 Match Interrupt Disable          */
    uint32_t CMPM4:1;                   /**< bit:     12  Comparison 4 Match Interrupt Disable          */
    uint32_t CMPM5:1;                   /**< bit:     13  Comparison 5 Match Interrupt Disable          */
    uint32_t CMPM6:1;                   /**< bit:     14  Comparison 6 Match Interrupt Disable          */
    uint32_t CMPM7:1;                   /**< bit:     15  Comparison 7 Match Interrupt Disable          */
    uint32_t CMPU0:1;                   /**< bit:     16  Comparison 0 Update Interrupt Disable         */
    uint32_t CMPU1:1;                   /**< bit:     17  Comparison 1 Update Interrupt Disable         */
    uint32_t CMPU2:1;                   /**< bit:     18  Comparison 2 Update Interrupt Disable         */
    uint32_t CMPU3:1;                   /**< bit:     19  Comparison 3 Update Interrupt Disable         */
    uint32_t CMPU4:1;                   /**< bit:     20  Comparison 4 Update Interrupt Disable         */
    uint32_t CMPU5:1;                   /**< bit:     21  Comparison 5 Update Interrupt Disable         */
    uint32_t CMPU6:1;                   /**< bit:     22  Comparison 6 Update Interrupt Disable         */
    uint32_t CMPU7:1;                   /**< bit:     23  Comparison 7 Update Interrupt Disable         */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  struct
  {
    uint32_t :8;                        /**< bit:   0..7  Reserved                                      */
    uint32_t CMPM:8;                    /**< bit:  8..15  Comparison x Match Interrupt Disable          */
    uint32_t CMPU:8;                    /**< bit: 16..23  Comparison 7 Update Interrupt Disable         */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_IDR2_bits_t;

#define PWMC_IDR2_WRDY_Pos                    (0)                                            /**< (PWMC_IDR2) Write Ready for Synchronous Channels Update Interrupt Disable Position */
#define PWMC_IDR2_WRDY_Msk                    (0x1U << PWMC_IDR2_WRDY_Pos)                   /**< (PWMC_IDR2) Write Ready for Synchronous Channels Update Interrupt Disable Mask */
#define PWMC_IDR2_UNRE_Pos                    (3)                                            /**< (PWMC_IDR2) Synchronous Channels Update Underrun Error Interrupt Disable Position */
#define PWMC_IDR2_UNRE_Msk                    (0x1U << PWMC_IDR2_UNRE_Pos)                   /**< (PWMC_IDR2) Synchronous Channels Update Underrun Error Interrupt Disable Mask */
#define PWMC_IDR2_CMPM0_Pos                   (8)                                            /**< (PWMC_IDR2) Comparison 0 Match Interrupt Disable Position */
#define PWMC_IDR2_CMPM0_Msk                   (0x1U << PWMC_IDR2_CMPM0_Pos)                  /**< (PWMC_IDR2) Comparison 0 Match Interrupt Disable Mask */
#define PWMC_IDR2_CMPM1_Pos                   (9)                                            /**< (PWMC_IDR2) Comparison 1 Match Interrupt Disable Position */
#define PWMC_IDR2_CMPM1_Msk                   (0x1U << PWMC_IDR2_CMPM1_Pos)                  /**< (PWMC_IDR2) Comparison 1 Match Interrupt Disable Mask */
#define PWMC_IDR2_CMPM2_Pos                   (10)                                           /**< (PWMC_IDR2) Comparison 2 Match Interrupt Disable Position */
#define PWMC_IDR2_CMPM2_Msk                   (0x1U << PWMC_IDR2_CMPM2_Pos)                  /**< (PWMC_IDR2) Comparison 2 Match Interrupt Disable Mask */
#define PWMC_IDR2_CMPM3_Pos                   (11)                                           /**< (PWMC_IDR2) Comparison 3 Match Interrupt Disable Position */
#define PWMC_IDR2_CMPM3_Msk                   (0x1U << PWMC_IDR2_CMPM3_Pos)                  /**< (PWMC_IDR2) Comparison 3 Match Interrupt Disable Mask */
#define PWMC_IDR2_CMPM4_Pos                   (12)                                           /**< (PWMC_IDR2) Comparison 4 Match Interrupt Disable Position */
#define PWMC_IDR2_CMPM4_Msk                   (0x1U << PWMC_IDR2_CMPM4_Pos)                  /**< (PWMC_IDR2) Comparison 4 Match Interrupt Disable Mask */
#define PWMC_IDR2_CMPM5_Pos                   (13)                                           /**< (PWMC_IDR2) Comparison 5 Match Interrupt Disable Position */
#define PWMC_IDR2_CMPM5_Msk                   (0x1U << PWMC_IDR2_CMPM5_Pos)                  /**< (PWMC_IDR2) Comparison 5 Match Interrupt Disable Mask */
#define PWMC_IDR2_CMPM6_Pos                   (14)                                           /**< (PWMC_IDR2) Comparison 6 Match Interrupt Disable Position */
#define PWMC_IDR2_CMPM6_Msk                   (0x1U << PWMC_IDR2_CMPM6_Pos)                  /**< (PWMC_IDR2) Comparison 6 Match Interrupt Disable Mask */
#define PWMC_IDR2_CMPM7_Pos                   (15)                                           /**< (PWMC_IDR2) Comparison 7 Match Interrupt Disable Position */
#define PWMC_IDR2_CMPM7_Msk                   (0x1U << PWMC_IDR2_CMPM7_Pos)                  /**< (PWMC_IDR2) Comparison 7 Match Interrupt Disable Mask */
#define PWMC_IDR2_CMPU0_Pos                   (16)                                           /**< (PWMC_IDR2) Comparison 0 Update Interrupt Disable Position */
#define PWMC_IDR2_CMPU0_Msk                   (0x1U << PWMC_IDR2_CMPU0_Pos)                  /**< (PWMC_IDR2) Comparison 0 Update Interrupt Disable Mask */
#define PWMC_IDR2_CMPU1_Pos                   (17)                                           /**< (PWMC_IDR2) Comparison 1 Update Interrupt Disable Position */
#define PWMC_IDR2_CMPU1_Msk                   (0x1U << PWMC_IDR2_CMPU1_Pos)                  /**< (PWMC_IDR2) Comparison 1 Update Interrupt Disable Mask */
#define PWMC_IDR2_CMPU2_Pos                   (18)                                           /**< (PWMC_IDR2) Comparison 2 Update Interrupt Disable Position */
#define PWMC_IDR2_CMPU2_Msk                   (0x1U << PWMC_IDR2_CMPU2_Pos)                  /**< (PWMC_IDR2) Comparison 2 Update Interrupt Disable Mask */
#define PWMC_IDR2_CMPU3_Pos                   (19)                                           /**< (PWMC_IDR2) Comparison 3 Update Interrupt Disable Position */
#define PWMC_IDR2_CMPU3_Msk                   (0x1U << PWMC_IDR2_CMPU3_Pos)                  /**< (PWMC_IDR2) Comparison 3 Update Interrupt Disable Mask */
#define PWMC_IDR2_CMPU4_Pos                   (20)                                           /**< (PWMC_IDR2) Comparison 4 Update Interrupt Disable Position */
#define PWMC_IDR2_CMPU4_Msk                   (0x1U << PWMC_IDR2_CMPU4_Pos)                  /**< (PWMC_IDR2) Comparison 4 Update Interrupt Disable Mask */
#define PWMC_IDR2_CMPU5_Pos                   (21)                                           /**< (PWMC_IDR2) Comparison 5 Update Interrupt Disable Position */
#define PWMC_IDR2_CMPU5_Msk                   (0x1U << PWMC_IDR2_CMPU5_Pos)                  /**< (PWMC_IDR2) Comparison 5 Update Interrupt Disable Mask */
#define PWMC_IDR2_CMPU6_Pos                   (22)                                           /**< (PWMC_IDR2) Comparison 6 Update Interrupt Disable Position */
#define PWMC_IDR2_CMPU6_Msk                   (0x1U << PWMC_IDR2_CMPU6_Pos)                  /**< (PWMC_IDR2) Comparison 6 Update Interrupt Disable Mask */
#define PWMC_IDR2_CMPU7_Pos                   (23)                                           /**< (PWMC_IDR2) Comparison 7 Update Interrupt Disable Position */
#define PWMC_IDR2_CMPU7_Msk                   (0x1U << PWMC_IDR2_CMPU7_Pos)                  /**< (PWMC_IDR2) Comparison 7 Update Interrupt Disable Mask */
#define PWMC_IDR2_Msk                         (0x00FFFF09UL)                                 /**< (PWMC_IDR2) Register Mask  */
#define PWMC_IDR2_CMPM_Pos                    (8)                                            /**< (PWMC_IDR2 Position) Comparison x Match Interrupt Disable */
#define PWMC_IDR2_CMPM_Msk                    (0xFFU << PWMC_IDR2_CMPM_Pos)                  /**< (PWMC_IDR2 Mask) CMPM */
#define PWMC_IDR2_CMPM(value)                 (PWMC_IDR2_CMPM_Msk & ((value) << PWMC_IDR2_CMPM_Pos))
#define PWMC_IDR2_CMPU_Pos                    (16)                                           /**< (PWMC_IDR2 Position) Comparison 7 Update Interrupt Disable */
#define PWMC_IDR2_CMPU_Msk                    (0xFFU << PWMC_IDR2_CMPU_Pos)                  /**< (PWMC_IDR2 Mask) CMPU */
#define PWMC_IDR2_CMPU(value)                 (PWMC_IDR2_CMPU_Msk & ((value) << PWMC_IDR2_CMPU_Pos))

/* -------- PWMC_IMR2 : (PWMC Offset: 0x3c) (R/ 32) PWMC Interrupt Mask Register 2 -------- */

typedef union
{
  struct
  {
    uint32_t WRDY:1;                    /**< bit:      0  Write Ready for Synchronous Channels Update Interrupt Mask */
    uint32_t :2;                        /**< bit:   1..2  Reserved                                      */
    uint32_t UNRE:1;                    /**< bit:      3  Synchronous Channels Update Underrun Error Interrupt Mask */
    uint32_t :4;                        /**< bit:   4..7  Reserved                                      */
    uint32_t CMPM0:1;                   /**< bit:      8  Comparison 0 Match Interrupt Mask             */
    uint32_t CMPM1:1;                   /**< bit:      9  Comparison 1 Match Interrupt Mask             */
    uint32_t CMPM2:1;                   /**< bit:     10  Comparison 2 Match Interrupt Mask             */
    uint32_t CMPM3:1;                   /**< bit:     11  Comparison 3 Match Interrupt Mask             */
    uint32_t CMPM4:1;                   /**< bit:     12  Comparison 4 Match Interrupt Mask             */
    uint32_t CMPM5:1;                   /**< bit:     13  Comparison 5 Match Interrupt Mask             */
    uint32_t CMPM6:1;                   /**< bit:     14  Comparison 6 Match Interrupt Mask             */
    uint32_t CMPM7:1;                   /**< bit:     15  Comparison 7 Match Interrupt Mask             */
    uint32_t CMPU0:1;                   /**< bit:     16  Comparison 0 Update Interrupt Mask            */
    uint32_t CMPU1:1;                   /**< bit:     17  Comparison 1 Update Interrupt Mask            */
    uint32_t CMPU2:1;                   /**< bit:     18  Comparison 2 Update Interrupt Mask            */
    uint32_t CMPU3:1;                   /**< bit:     19  Comparison 3 Update Interrupt Mask            */
    uint32_t CMPU4:1;                   /**< bit:     20  Comparison 4 Update Interrupt Mask            */
    uint32_t CMPU5:1;                   /**< bit:     21  Comparison 5 Update Interrupt Mask            */
    uint32_t CMPU6:1;                   /**< bit:     22  Comparison 6 Update Interrupt Mask            */
    uint32_t CMPU7:1;                   /**< bit:     23  Comparison 7 Update Interrupt Mask            */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  struct
  {
    uint32_t :8;                        /**< bit:   0..7  Reserved                                      */
    uint32_t CMPM:8;                    /**< bit:  8..15  Comparison x Match Interrupt Mask             */
    uint32_t CMPU:8;                    /**< bit: 16..23  Comparison 7 Update Interrupt Mask            */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_IMR2_bits_t;

#define PWMC_IMR2_WRDY_Pos                    (0)                                            /**< (PWMC_IMR2) Write Ready for Synchronous Channels Update Interrupt Mask Position */
#define PWMC_IMR2_WRDY_Msk                    (0x1U << PWMC_IMR2_WRDY_Pos)                   /**< (PWMC_IMR2) Write Ready for Synchronous Channels Update Interrupt Mask Mask */
#define PWMC_IMR2_UNRE_Pos                    (3)                                            /**< (PWMC_IMR2) Synchronous Channels Update Underrun Error Interrupt Mask Position */
#define PWMC_IMR2_UNRE_Msk                    (0x1U << PWMC_IMR2_UNRE_Pos)                   /**< (PWMC_IMR2) Synchronous Channels Update Underrun Error Interrupt Mask Mask */
#define PWMC_IMR2_CMPM0_Pos                   (8)                                            /**< (PWMC_IMR2) Comparison 0 Match Interrupt Mask Position */
#define PWMC_IMR2_CMPM0_Msk                   (0x1U << PWMC_IMR2_CMPM0_Pos)                  /**< (PWMC_IMR2) Comparison 0 Match Interrupt Mask Mask */
#define PWMC_IMR2_CMPM1_Pos                   (9)                                            /**< (PWMC_IMR2) Comparison 1 Match Interrupt Mask Position */
#define PWMC_IMR2_CMPM1_Msk                   (0x1U << PWMC_IMR2_CMPM1_Pos)                  /**< (PWMC_IMR2) Comparison 1 Match Interrupt Mask Mask */
#define PWMC_IMR2_CMPM2_Pos                   (10)                                           /**< (PWMC_IMR2) Comparison 2 Match Interrupt Mask Position */
#define PWMC_IMR2_CMPM2_Msk                   (0x1U << PWMC_IMR2_CMPM2_Pos)                  /**< (PWMC_IMR2) Comparison 2 Match Interrupt Mask Mask */
#define PWMC_IMR2_CMPM3_Pos                   (11)                                           /**< (PWMC_IMR2) Comparison 3 Match Interrupt Mask Position */
#define PWMC_IMR2_CMPM3_Msk                   (0x1U << PWMC_IMR2_CMPM3_Pos)                  /**< (PWMC_IMR2) Comparison 3 Match Interrupt Mask Mask */
#define PWMC_IMR2_CMPM4_Pos                   (12)                                           /**< (PWMC_IMR2) Comparison 4 Match Interrupt Mask Position */
#define PWMC_IMR2_CMPM4_Msk                   (0x1U << PWMC_IMR2_CMPM4_Pos)                  /**< (PWMC_IMR2) Comparison 4 Match Interrupt Mask Mask */
#define PWMC_IMR2_CMPM5_Pos                   (13)                                           /**< (PWMC_IMR2) Comparison 5 Match Interrupt Mask Position */
#define PWMC_IMR2_CMPM5_Msk                   (0x1U << PWMC_IMR2_CMPM5_Pos)                  /**< (PWMC_IMR2) Comparison 5 Match Interrupt Mask Mask */
#define PWMC_IMR2_CMPM6_Pos                   (14)                                           /**< (PWMC_IMR2) Comparison 6 Match Interrupt Mask Position */
#define PWMC_IMR2_CMPM6_Msk                   (0x1U << PWMC_IMR2_CMPM6_Pos)                  /**< (PWMC_IMR2) Comparison 6 Match Interrupt Mask Mask */
#define PWMC_IMR2_CMPM7_Pos                   (15)                                           /**< (PWMC_IMR2) Comparison 7 Match Interrupt Mask Position */
#define PWMC_IMR2_CMPM7_Msk                   (0x1U << PWMC_IMR2_CMPM7_Pos)                  /**< (PWMC_IMR2) Comparison 7 Match Interrupt Mask Mask */
#define PWMC_IMR2_CMPU0_Pos                   (16)                                           /**< (PWMC_IMR2) Comparison 0 Update Interrupt Mask Position */
#define PWMC_IMR2_CMPU0_Msk                   (0x1U << PWMC_IMR2_CMPU0_Pos)                  /**< (PWMC_IMR2) Comparison 0 Update Interrupt Mask Mask */
#define PWMC_IMR2_CMPU1_Pos                   (17)                                           /**< (PWMC_IMR2) Comparison 1 Update Interrupt Mask Position */
#define PWMC_IMR2_CMPU1_Msk                   (0x1U << PWMC_IMR2_CMPU1_Pos)                  /**< (PWMC_IMR2) Comparison 1 Update Interrupt Mask Mask */
#define PWMC_IMR2_CMPU2_Pos                   (18)                                           /**< (PWMC_IMR2) Comparison 2 Update Interrupt Mask Position */
#define PWMC_IMR2_CMPU2_Msk                   (0x1U << PWMC_IMR2_CMPU2_Pos)                  /**< (PWMC_IMR2) Comparison 2 Update Interrupt Mask Mask */
#define PWMC_IMR2_CMPU3_Pos                   (19)                                           /**< (PWMC_IMR2) Comparison 3 Update Interrupt Mask Position */
#define PWMC_IMR2_CMPU3_Msk                   (0x1U << PWMC_IMR2_CMPU3_Pos)                  /**< (PWMC_IMR2) Comparison 3 Update Interrupt Mask Mask */
#define PWMC_IMR2_CMPU4_Pos                   (20)                                           /**< (PWMC_IMR2) Comparison 4 Update Interrupt Mask Position */
#define PWMC_IMR2_CMPU4_Msk                   (0x1U << PWMC_IMR2_CMPU4_Pos)                  /**< (PWMC_IMR2) Comparison 4 Update Interrupt Mask Mask */
#define PWMC_IMR2_CMPU5_Pos                   (21)                                           /**< (PWMC_IMR2) Comparison 5 Update Interrupt Mask Position */
#define PWMC_IMR2_CMPU5_Msk                   (0x1U << PWMC_IMR2_CMPU5_Pos)                  /**< (PWMC_IMR2) Comparison 5 Update Interrupt Mask Mask */
#define PWMC_IMR2_CMPU6_Pos                   (22)                                           /**< (PWMC_IMR2) Comparison 6 Update Interrupt Mask Position */
#define PWMC_IMR2_CMPU6_Msk                   (0x1U << PWMC_IMR2_CMPU6_Pos)                  /**< (PWMC_IMR2) Comparison 6 Update Interrupt Mask Mask */
#define PWMC_IMR2_CMPU7_Pos                   (23)                                           /**< (PWMC_IMR2) Comparison 7 Update Interrupt Mask Position */
#define PWMC_IMR2_CMPU7_Msk                   (0x1U << PWMC_IMR2_CMPU7_Pos)                  /**< (PWMC_IMR2) Comparison 7 Update Interrupt Mask Mask */
#define PWMC_IMR2_Msk                         (0x00FFFF09UL)                                 /**< (PWMC_IMR2) Register Mask  */
#define PWMC_IMR2_CMPM_Pos                    (8)                                            /**< (PWMC_IMR2 Position) Comparison x Match Interrupt Mask */
#define PWMC_IMR2_CMPM_Msk                    (0xFFU << PWMC_IMR2_CMPM_Pos)                  /**< (PWMC_IMR2 Mask) CMPM */
#define PWMC_IMR2_CMPM(value)                 (PWMC_IMR2_CMPM_Msk & ((value) << PWMC_IMR2_CMPM_Pos))
#define PWMC_IMR2_CMPU_Pos                    (16)                                           /**< (PWMC_IMR2 Position) Comparison 7 Update Interrupt Mask */
#define PWMC_IMR2_CMPU_Msk                    (0xFFU << PWMC_IMR2_CMPU_Pos)                  /**< (PWMC_IMR2 Mask) CMPU */
#define PWMC_IMR2_CMPU(value)                 (PWMC_IMR2_CMPU_Msk & ((value) << PWMC_IMR2_CMPU_Pos))

/* -------- PWMC_ISR2 : (PWMC Offset: 0x40) (R/ 32) PWMC Interrupt Status Register 2 -------- */

typedef union
{
  struct
  {
    uint32_t WRDY:1;                    /**< bit:      0  Write Ready for Synchronous Channels Update   */
    uint32_t :2;                        /**< bit:   1..2  Reserved                                      */
    uint32_t UNRE:1;                    /**< bit:      3  Synchronous Channels Update Underrun Error    */
    uint32_t :4;                        /**< bit:   4..7  Reserved                                      */
    uint32_t CMPM0:1;                   /**< bit:      8  Comparison 0 Match                            */
    uint32_t CMPM1:1;                   /**< bit:      9  Comparison 1 Match                            */
    uint32_t CMPM2:1;                   /**< bit:     10  Comparison 2 Match                            */
    uint32_t CMPM3:1;                   /**< bit:     11  Comparison 3 Match                            */
    uint32_t CMPM4:1;                   /**< bit:     12  Comparison 4 Match                            */
    uint32_t CMPM5:1;                   /**< bit:     13  Comparison 5 Match                            */
    uint32_t CMPM6:1;                   /**< bit:     14  Comparison 6 Match                            */
    uint32_t CMPM7:1;                   /**< bit:     15  Comparison 7 Match                            */
    uint32_t CMPU0:1;                   /**< bit:     16  Comparison 0 Update                           */
    uint32_t CMPU1:1;                   /**< bit:     17  Comparison 1 Update                           */
    uint32_t CMPU2:1;                   /**< bit:     18  Comparison 2 Update                           */
    uint32_t CMPU3:1;                   /**< bit:     19  Comparison 3 Update                           */
    uint32_t CMPU4:1;                   /**< bit:     20  Comparison 4 Update                           */
    uint32_t CMPU5:1;                   /**< bit:     21  Comparison 5 Update                           */
    uint32_t CMPU6:1;                   /**< bit:     22  Comparison 6 Update                           */
    uint32_t CMPU7:1;                   /**< bit:     23  Comparison 7 Update                           */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  struct
  {
    uint32_t :8;                        /**< bit:   0..7  Reserved                                      */
    uint32_t CMPM:8;                    /**< bit:  8..15  Comparison x Match                            */
    uint32_t CMPU:8;                    /**< bit: 16..23  Comparison 7 Update                           */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_ISR2_bits_t;

#define PWMC_ISR2_WRDY_Pos                    (0)                                            /**< (PWMC_ISR2) Write Ready for Synchronous Channels Update Position */
#define PWMC_ISR2_WRDY_Msk                    (0x1U << PWMC_ISR2_WRDY_Pos)                   /**< (PWMC_ISR2) Write Ready for Synchronous Channels Update Mask */
#define PWMC_ISR2_UNRE_Pos                    (3)                                            /**< (PWMC_ISR2) Synchronous Channels Update Underrun Error Position */
#define PWMC_ISR2_UNRE_Msk                    (0x1U << PWMC_ISR2_UNRE_Pos)                   /**< (PWMC_ISR2) Synchronous Channels Update Underrun Error Mask */
#define PWMC_ISR2_CMPM0_Pos                   (8)                                            /**< (PWMC_ISR2) Comparison 0 Match Position */
#define PWMC_ISR2_CMPM0_Msk                   (0x1U << PWMC_ISR2_CMPM0_Pos)                  /**< (PWMC_ISR2) Comparison 0 Match Mask */
#define PWMC_ISR2_CMPM1_Pos                   (9)                                            /**< (PWMC_ISR2) Comparison 1 Match Position */
#define PWMC_ISR2_CMPM1_Msk                   (0x1U << PWMC_ISR2_CMPM1_Pos)                  /**< (PWMC_ISR2) Comparison 1 Match Mask */
#define PWMC_ISR2_CMPM2_Pos                   (10)                                           /**< (PWMC_ISR2) Comparison 2 Match Position */
#define PWMC_ISR2_CMPM2_Msk                   (0x1U << PWMC_ISR2_CMPM2_Pos)                  /**< (PWMC_ISR2) Comparison 2 Match Mask */
#define PWMC_ISR2_CMPM3_Pos                   (11)                                           /**< (PWMC_ISR2) Comparison 3 Match Position */
#define PWMC_ISR2_CMPM3_Msk                   (0x1U << PWMC_ISR2_CMPM3_Pos)                  /**< (PWMC_ISR2) Comparison 3 Match Mask */
#define PWMC_ISR2_CMPM4_Pos                   (12)                                           /**< (PWMC_ISR2) Comparison 4 Match Position */
#define PWMC_ISR2_CMPM4_Msk                   (0x1U << PWMC_ISR2_CMPM4_Pos)                  /**< (PWMC_ISR2) Comparison 4 Match Mask */
#define PWMC_ISR2_CMPM5_Pos                   (13)                                           /**< (PWMC_ISR2) Comparison 5 Match Position */
#define PWMC_ISR2_CMPM5_Msk                   (0x1U << PWMC_ISR2_CMPM5_Pos)                  /**< (PWMC_ISR2) Comparison 5 Match Mask */
#define PWMC_ISR2_CMPM6_Pos                   (14)                                           /**< (PWMC_ISR2) Comparison 6 Match Position */
#define PWMC_ISR2_CMPM6_Msk                   (0x1U << PWMC_ISR2_CMPM6_Pos)                  /**< (PWMC_ISR2) Comparison 6 Match Mask */
#define PWMC_ISR2_CMPM7_Pos                   (15)                                           /**< (PWMC_ISR2) Comparison 7 Match Position */
#define PWMC_ISR2_CMPM7_Msk                   (0x1U << PWMC_ISR2_CMPM7_Pos)                  /**< (PWMC_ISR2) Comparison 7 Match Mask */
#define PWMC_ISR2_CMPU0_Pos                   (16)                                           /**< (PWMC_ISR2) Comparison 0 Update Position */
#define PWMC_ISR2_CMPU0_Msk                   (0x1U << PWMC_ISR2_CMPU0_Pos)                  /**< (PWMC_ISR2) Comparison 0 Update Mask */
#define PWMC_ISR2_CMPU1_Pos                   (17)                                           /**< (PWMC_ISR2) Comparison 1 Update Position */
#define PWMC_ISR2_CMPU1_Msk                   (0x1U << PWMC_ISR2_CMPU1_Pos)                  /**< (PWMC_ISR2) Comparison 1 Update Mask */
#define PWMC_ISR2_CMPU2_Pos                   (18)                                           /**< (PWMC_ISR2) Comparison 2 Update Position */
#define PWMC_ISR2_CMPU2_Msk                   (0x1U << PWMC_ISR2_CMPU2_Pos)                  /**< (PWMC_ISR2) Comparison 2 Update Mask */
#define PWMC_ISR2_CMPU3_Pos                   (19)                                           /**< (PWMC_ISR2) Comparison 3 Update Position */
#define PWMC_ISR2_CMPU3_Msk                   (0x1U << PWMC_ISR2_CMPU3_Pos)                  /**< (PWMC_ISR2) Comparison 3 Update Mask */
#define PWMC_ISR2_CMPU4_Pos                   (20)                                           /**< (PWMC_ISR2) Comparison 4 Update Position */
#define PWMC_ISR2_CMPU4_Msk                   (0x1U << PWMC_ISR2_CMPU4_Pos)                  /**< (PWMC_ISR2) Comparison 4 Update Mask */
#define PWMC_ISR2_CMPU5_Pos                   (21)                                           /**< (PWMC_ISR2) Comparison 5 Update Position */
#define PWMC_ISR2_CMPU5_Msk                   (0x1U << PWMC_ISR2_CMPU5_Pos)                  /**< (PWMC_ISR2) Comparison 5 Update Mask */
#define PWMC_ISR2_CMPU6_Pos                   (22)                                           /**< (PWMC_ISR2) Comparison 6 Update Position */
#define PWMC_ISR2_CMPU6_Msk                   (0x1U << PWMC_ISR2_CMPU6_Pos)                  /**< (PWMC_ISR2) Comparison 6 Update Mask */
#define PWMC_ISR2_CMPU7_Pos                   (23)                                           /**< (PWMC_ISR2) Comparison 7 Update Position */
#define PWMC_ISR2_CMPU7_Msk                   (0x1U << PWMC_ISR2_CMPU7_Pos)                  /**< (PWMC_ISR2) Comparison 7 Update Mask */
#define PWMC_ISR2_Msk                         (0x00FFFF09UL)                                 /**< (PWMC_ISR2) Register Mask  */
#define PWMC_ISR2_CMPM_Pos                    (8)                                            /**< (PWMC_ISR2 Position) Comparison x Match */
#define PWMC_ISR2_CMPM_Msk                    (0xFFU << PWMC_ISR2_CMPM_Pos)                  /**< (PWMC_ISR2 Mask) CMPM */
#define PWMC_ISR2_CMPM(value)                 (PWMC_ISR2_CMPM_Msk & ((value) << PWMC_ISR2_CMPM_Pos))
#define PWMC_ISR2_CMPU_Pos                    (16)                                           /**< (PWMC_ISR2 Position) Comparison 7 Update */
#define PWMC_ISR2_CMPU_Msk                    (0xFFU << PWMC_ISR2_CMPU_Pos)                  /**< (PWMC_ISR2 Mask) CMPU */
#define PWMC_ISR2_CMPU(value)                 (PWMC_ISR2_CMPU_Msk & ((value) << PWMC_ISR2_CMPU_Pos))

/* -------- PWMC_OOV : (PWMC Offset: 0x44) (R/W 32) PWMC Output Override Value Register -------- */

typedef union
{
  struct
  {
    uint32_t OOVH0:1;                   /**< bit:      0  Output Override Value for PWMH output of the channel 0 */
    uint32_t OOVH1:1;                   /**< bit:      1  Output Override Value for PWMH output of the channel 1 */
    uint32_t OOVH2:1;                   /**< bit:      2  Output Override Value for PWMH output of the channel 2 */
    uint32_t OOVH3:1;                   /**< bit:      3  Output Override Value for PWMH output of the channel 3 */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OOVL0:1;                   /**< bit:     16  Output Override Value for PWML output of the channel 0 */
    uint32_t OOVL1:1;                   /**< bit:     17  Output Override Value for PWML output of the channel 1 */
    uint32_t OOVL2:1;                   /**< bit:     18  Output Override Value for PWML output of the channel 2 */
    uint32_t OOVL3:1;                   /**< bit:     19  Output Override Value for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t OOVH:4;                    /**< bit:   0..3  Output Override Value for PWMH output of the channel x */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OOVL:4;                    /**< bit: 16..19  Output Override Value for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_OOV_bits_t;

#define PWMC_OOV_OOVH0_Pos                    (0)                                            /**< (PWMC_OOV) Output Override Value for PWMH output of the channel 0 Position */
#define PWMC_OOV_OOVH0_Msk                    (0x1U << PWMC_OOV_OOVH0_Pos)                   /**< (PWMC_OOV) Output Override Value for PWMH output of the channel 0 Mask */
#define PWMC_OOV_OOVH1_Pos                    (1)                                            /**< (PWMC_OOV) Output Override Value for PWMH output of the channel 1 Position */
#define PWMC_OOV_OOVH1_Msk                    (0x1U << PWMC_OOV_OOVH1_Pos)                   /**< (PWMC_OOV) Output Override Value for PWMH output of the channel 1 Mask */
#define PWMC_OOV_OOVH2_Pos                    (2)                                            /**< (PWMC_OOV) Output Override Value for PWMH output of the channel 2 Position */
#define PWMC_OOV_OOVH2_Msk                    (0x1U << PWMC_OOV_OOVH2_Pos)                   /**< (PWMC_OOV) Output Override Value for PWMH output of the channel 2 Mask */
#define PWMC_OOV_OOVH3_Pos                    (3)                                            /**< (PWMC_OOV) Output Override Value for PWMH output of the channel 3 Position */
#define PWMC_OOV_OOVH3_Msk                    (0x1U << PWMC_OOV_OOVH3_Pos)                   /**< (PWMC_OOV) Output Override Value for PWMH output of the channel 3 Mask */
#define PWMC_OOV_OOVL0_Pos                    (16)                                           /**< (PWMC_OOV) Output Override Value for PWML output of the channel 0 Position */
#define PWMC_OOV_OOVL0_Msk                    (0x1U << PWMC_OOV_OOVL0_Pos)                   /**< (PWMC_OOV) Output Override Value for PWML output of the channel 0 Mask */
#define PWMC_OOV_OOVL1_Pos                    (17)                                           /**< (PWMC_OOV) Output Override Value for PWML output of the channel 1 Position */
#define PWMC_OOV_OOVL1_Msk                    (0x1U << PWMC_OOV_OOVL1_Pos)                   /**< (PWMC_OOV) Output Override Value for PWML output of the channel 1 Mask */
#define PWMC_OOV_OOVL2_Pos                    (18)                                           /**< (PWMC_OOV) Output Override Value for PWML output of the channel 2 Position */
#define PWMC_OOV_OOVL2_Msk                    (0x1U << PWMC_OOV_OOVL2_Pos)                   /**< (PWMC_OOV) Output Override Value for PWML output of the channel 2 Mask */
#define PWMC_OOV_OOVL3_Pos                    (19)                                           /**< (PWMC_OOV) Output Override Value for PWML output of the channel 3 Position */
#define PWMC_OOV_OOVL3_Msk                    (0x1U << PWMC_OOV_OOVL3_Pos)                   /**< (PWMC_OOV) Output Override Value for PWML output of the channel 3 Mask */
#define PWMC_OOV_Msk                          (0x000F000FUL)                                 /**< (PWMC_OOV) Register Mask  */
#define PWMC_OOV_OOVH_Pos                     (0)                                            /**< (PWMC_OOV Position) Output Override Value for PWMH output of the channel x */
#define PWMC_OOV_OOVH_Msk                     (0xFU << PWMC_OOV_OOVH_Pos)                    /**< (PWMC_OOV Mask) OOVH */
#define PWMC_OOV_OOVH(value)                  (PWMC_OOV_OOVH_Msk & ((value) << PWMC_OOV_OOVH_Pos))
#define PWMC_OOV_OOVL_Pos                     (16)                                           /**< (PWMC_OOV Position) Output Override Value for PWML output of the channel 3 */
#define PWMC_OOV_OOVL_Msk                     (0xFU << PWMC_OOV_OOVL_Pos)                    /**< (PWMC_OOV Mask) OOVL */
#define PWMC_OOV_OOVL(value)                  (PWMC_OOV_OOVL_Msk & ((value) << PWMC_OOV_OOVL_Pos))

/* -------- PWMC_OS : (PWMC Offset: 0x48) (R/W 32) PWMC Output Selection Register -------- */

typedef union
{
  struct
  {
    uint32_t OSH0:1;                    /**< bit:      0  Output Selection for PWMH output of the channel 0 */
    uint32_t OSH1:1;                    /**< bit:      1  Output Selection for PWMH output of the channel 1 */
    uint32_t OSH2:1;                    /**< bit:      2  Output Selection for PWMH output of the channel 2 */
    uint32_t OSH3:1;                    /**< bit:      3  Output Selection for PWMH output of the channel 3 */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OSL0:1;                    /**< bit:     16  Output Selection for PWML output of the channel 0 */
    uint32_t OSL1:1;                    /**< bit:     17  Output Selection for PWML output of the channel 1 */
    uint32_t OSL2:1;                    /**< bit:     18  Output Selection for PWML output of the channel 2 */
    uint32_t OSL3:1;                    /**< bit:     19  Output Selection for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t OSH:4;                     /**< bit:   0..3  Output Selection for PWMH output of the channel x */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OSL:4;                     /**< bit: 16..19  Output Selection for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_OS_bits_t;

#define PWMC_OS_OSH0_Pos                      (0)                                            /**< (PWMC_OS) Output Selection for PWMH output of the channel 0 Position */
#define PWMC_OS_OSH0_Msk                      (0x1U << PWMC_OS_OSH0_Pos)                     /**< (PWMC_OS) Output Selection for PWMH output of the channel 0 Mask */
#define PWMC_OS_OSH1_Pos                      (1)                                            /**< (PWMC_OS) Output Selection for PWMH output of the channel 1 Position */
#define PWMC_OS_OSH1_Msk                      (0x1U << PWMC_OS_OSH1_Pos)                     /**< (PWMC_OS) Output Selection for PWMH output of the channel 1 Mask */
#define PWMC_OS_OSH2_Pos                      (2)                                            /**< (PWMC_OS) Output Selection for PWMH output of the channel 2 Position */
#define PWMC_OS_OSH2_Msk                      (0x1U << PWMC_OS_OSH2_Pos)                     /**< (PWMC_OS) Output Selection for PWMH output of the channel 2 Mask */
#define PWMC_OS_OSH3_Pos                      (3)                                            /**< (PWMC_OS) Output Selection for PWMH output of the channel 3 Position */
#define PWMC_OS_OSH3_Msk                      (0x1U << PWMC_OS_OSH3_Pos)                     /**< (PWMC_OS) Output Selection for PWMH output of the channel 3 Mask */
#define PWMC_OS_OSL0_Pos                      (16)                                           /**< (PWMC_OS) Output Selection for PWML output of the channel 0 Position */
#define PWMC_OS_OSL0_Msk                      (0x1U << PWMC_OS_OSL0_Pos)                     /**< (PWMC_OS) Output Selection for PWML output of the channel 0 Mask */
#define PWMC_OS_OSL1_Pos                      (17)                                           /**< (PWMC_OS) Output Selection for PWML output of the channel 1 Position */
#define PWMC_OS_OSL1_Msk                      (0x1U << PWMC_OS_OSL1_Pos)                     /**< (PWMC_OS) Output Selection for PWML output of the channel 1 Mask */
#define PWMC_OS_OSL2_Pos                      (18)                                           /**< (PWMC_OS) Output Selection for PWML output of the channel 2 Position */
#define PWMC_OS_OSL2_Msk                      (0x1U << PWMC_OS_OSL2_Pos)                     /**< (PWMC_OS) Output Selection for PWML output of the channel 2 Mask */
#define PWMC_OS_OSL3_Pos                      (19)                                           /**< (PWMC_OS) Output Selection for PWML output of the channel 3 Position */
#define PWMC_OS_OSL3_Msk                      (0x1U << PWMC_OS_OSL3_Pos)                     /**< (PWMC_OS) Output Selection for PWML output of the channel 3 Mask */
#define PWMC_OS_Msk                           (0x000F000FUL)                                 /**< (PWMC_OS) Register Mask  */
#define PWMC_OS_OSH_Pos                       (0)                                            /**< (PWMC_OS Position) Output Selection for PWMH output of the channel x */
#define PWMC_OS_OSH_Msk                       (0xFU << PWMC_OS_OSH_Pos)                      /**< (PWMC_OS Mask) OSH */
#define PWMC_OS_OSH(value)                    (PWMC_OS_OSH_Msk & ((value) << PWMC_OS_OSH_Pos))
#define PWMC_OS_OSL_Pos                       (16)                                           /**< (PWMC_OS Position) Output Selection for PWML output of the channel 3 */
#define PWMC_OS_OSL_Msk                       (0xFU << PWMC_OS_OSL_Pos)                      /**< (PWMC_OS Mask) OSL */
#define PWMC_OS_OSL(value)                    (PWMC_OS_OSL_Msk & ((value) << PWMC_OS_OSL_Pos))

/* -------- PWMC_OSS : (PWMC Offset: 0x4c) (/W 32) PWMC Output Selection Set Register -------- */

typedef union
{
  struct
  {
    uint32_t OSSH0:1;                   /**< bit:      0  Output Selection Set for PWMH output of the channel 0 */
    uint32_t OSSH1:1;                   /**< bit:      1  Output Selection Set for PWMH output of the channel 1 */
    uint32_t OSSH2:1;                   /**< bit:      2  Output Selection Set for PWMH output of the channel 2 */
    uint32_t OSSH3:1;                   /**< bit:      3  Output Selection Set for PWMH output of the channel 3 */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OSSL0:1;                   /**< bit:     16  Output Selection Set for PWML output of the channel 0 */
    uint32_t OSSL1:1;                   /**< bit:     17  Output Selection Set for PWML output of the channel 1 */
    uint32_t OSSL2:1;                   /**< bit:     18  Output Selection Set for PWML output of the channel 2 */
    uint32_t OSSL3:1;                   /**< bit:     19  Output Selection Set for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t OSSH:4;                    /**< bit:   0..3  Output Selection Set for PWMH output of the channel x */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OSSL:4;                    /**< bit: 16..19  Output Selection Set for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_OSS_bits_t;

#define PWMC_OSS_OSSH0_Pos                    (0)                                            /**< (PWMC_OSS) Output Selection Set for PWMH output of the channel 0 Position */
#define PWMC_OSS_OSSH0_Msk                    (0x1U << PWMC_OSS_OSSH0_Pos)                   /**< (PWMC_OSS) Output Selection Set for PWMH output of the channel 0 Mask */
#define PWMC_OSS_OSSH1_Pos                    (1)                                            /**< (PWMC_OSS) Output Selection Set for PWMH output of the channel 1 Position */
#define PWMC_OSS_OSSH1_Msk                    (0x1U << PWMC_OSS_OSSH1_Pos)                   /**< (PWMC_OSS) Output Selection Set for PWMH output of the channel 1 Mask */
#define PWMC_OSS_OSSH2_Pos                    (2)                                            /**< (PWMC_OSS) Output Selection Set for PWMH output of the channel 2 Position */
#define PWMC_OSS_OSSH2_Msk                    (0x1U << PWMC_OSS_OSSH2_Pos)                   /**< (PWMC_OSS) Output Selection Set for PWMH output of the channel 2 Mask */
#define PWMC_OSS_OSSH3_Pos                    (3)                                            /**< (PWMC_OSS) Output Selection Set for PWMH output of the channel 3 Position */
#define PWMC_OSS_OSSH3_Msk                    (0x1U << PWMC_OSS_OSSH3_Pos)                   /**< (PWMC_OSS) Output Selection Set for PWMH output of the channel 3 Mask */
#define PWMC_OSS_OSSL0_Pos                    (16)                                           /**< (PWMC_OSS) Output Selection Set for PWML output of the channel 0 Position */
#define PWMC_OSS_OSSL0_Msk                    (0x1U << PWMC_OSS_OSSL0_Pos)                   /**< (PWMC_OSS) Output Selection Set for PWML output of the channel 0 Mask */
#define PWMC_OSS_OSSL1_Pos                    (17)                                           /**< (PWMC_OSS) Output Selection Set for PWML output of the channel 1 Position */
#define PWMC_OSS_OSSL1_Msk                    (0x1U << PWMC_OSS_OSSL1_Pos)                   /**< (PWMC_OSS) Output Selection Set for PWML output of the channel 1 Mask */
#define PWMC_OSS_OSSL2_Pos                    (18)                                           /**< (PWMC_OSS) Output Selection Set for PWML output of the channel 2 Position */
#define PWMC_OSS_OSSL2_Msk                    (0x1U << PWMC_OSS_OSSL2_Pos)                   /**< (PWMC_OSS) Output Selection Set for PWML output of the channel 2 Mask */
#define PWMC_OSS_OSSL3_Pos                    (19)                                           /**< (PWMC_OSS) Output Selection Set for PWML output of the channel 3 Position */
#define PWMC_OSS_OSSL3_Msk                    (0x1U << PWMC_OSS_OSSL3_Pos)                   /**< (PWMC_OSS) Output Selection Set for PWML output of the channel 3 Mask */
#define PWMC_OSS_Msk                          (0x000F000FUL)                                 /**< (PWMC_OSS) Register Mask  */
#define PWMC_OSS_OSSH_Pos                     (0)                                            /**< (PWMC_OSS Position) Output Selection Set for PWMH output of the channel x */
#define PWMC_OSS_OSSH_Msk                     (0xFU << PWMC_OSS_OSSH_Pos)                    /**< (PWMC_OSS Mask) OSSH */
#define PWMC_OSS_OSSH(value)                  (PWMC_OSS_OSSH_Msk & ((value) << PWMC_OSS_OSSH_Pos))
#define PWMC_OSS_OSSL_Pos                     (16)                                           /**< (PWMC_OSS Position) Output Selection Set for PWML output of the channel 3 */
#define PWMC_OSS_OSSL_Msk                     (0xFU << PWMC_OSS_OSSL_Pos)                    /**< (PWMC_OSS Mask) OSSL */
#define PWMC_OSS_OSSL(value)                  (PWMC_OSS_OSSL_Msk & ((value) << PWMC_OSS_OSSL_Pos))

/* -------- PWMC_OSC : (PWMC Offset: 0x50) (/W 32) PWMC Output Selection Clear Register -------- */

typedef union
{
  struct
  {
    uint32_t OSCH0:1;                   /**< bit:      0  Output Selection Clear for PWMH output of the channel 0 */
    uint32_t OSCH1:1;                   /**< bit:      1  Output Selection Clear for PWMH output of the channel 1 */
    uint32_t OSCH2:1;                   /**< bit:      2  Output Selection Clear for PWMH output of the channel 2 */
    uint32_t OSCH3:1;                   /**< bit:      3  Output Selection Clear for PWMH output of the channel 3 */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OSCL0:1;                   /**< bit:     16  Output Selection Clear for PWML output of the channel 0 */
    uint32_t OSCL1:1;                   /**< bit:     17  Output Selection Clear for PWML output of the channel 1 */
    uint32_t OSCL2:1;                   /**< bit:     18  Output Selection Clear for PWML output of the channel 2 */
    uint32_t OSCL3:1;                   /**< bit:     19  Output Selection Clear for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t OSCH:4;                    /**< bit:   0..3  Output Selection Clear for PWMH output of the channel x */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OSCL:4;                    /**< bit: 16..19  Output Selection Clear for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_OSC_bits_t;

#define PWMC_OSC_OSCH0_Pos                    (0)                                            /**< (PWMC_OSC) Output Selection Clear for PWMH output of the channel 0 Position */
#define PWMC_OSC_OSCH0_Msk                    (0x1U << PWMC_OSC_OSCH0_Pos)                   /**< (PWMC_OSC) Output Selection Clear for PWMH output of the channel 0 Mask */
#define PWMC_OSC_OSCH1_Pos                    (1)                                            /**< (PWMC_OSC) Output Selection Clear for PWMH output of the channel 1 Position */
#define PWMC_OSC_OSCH1_Msk                    (0x1U << PWMC_OSC_OSCH1_Pos)                   /**< (PWMC_OSC) Output Selection Clear for PWMH output of the channel 1 Mask */
#define PWMC_OSC_OSCH2_Pos                    (2)                                            /**< (PWMC_OSC) Output Selection Clear for PWMH output of the channel 2 Position */
#define PWMC_OSC_OSCH2_Msk                    (0x1U << PWMC_OSC_OSCH2_Pos)                   /**< (PWMC_OSC) Output Selection Clear for PWMH output of the channel 2 Mask */
#define PWMC_OSC_OSCH3_Pos                    (3)                                            /**< (PWMC_OSC) Output Selection Clear for PWMH output of the channel 3 Position */
#define PWMC_OSC_OSCH3_Msk                    (0x1U << PWMC_OSC_OSCH3_Pos)                   /**< (PWMC_OSC) Output Selection Clear for PWMH output of the channel 3 Mask */
#define PWMC_OSC_OSCL0_Pos                    (16)                                           /**< (PWMC_OSC) Output Selection Clear for PWML output of the channel 0 Position */
#define PWMC_OSC_OSCL0_Msk                    (0x1U << PWMC_OSC_OSCL0_Pos)                   /**< (PWMC_OSC) Output Selection Clear for PWML output of the channel 0 Mask */
#define PWMC_OSC_OSCL1_Pos                    (17)                                           /**< (PWMC_OSC) Output Selection Clear for PWML output of the channel 1 Position */
#define PWMC_OSC_OSCL1_Msk                    (0x1U << PWMC_OSC_OSCL1_Pos)                   /**< (PWMC_OSC) Output Selection Clear for PWML output of the channel 1 Mask */
#define PWMC_OSC_OSCL2_Pos                    (18)                                           /**< (PWMC_OSC) Output Selection Clear for PWML output of the channel 2 Position */
#define PWMC_OSC_OSCL2_Msk                    (0x1U << PWMC_OSC_OSCL2_Pos)                   /**< (PWMC_OSC) Output Selection Clear for PWML output of the channel 2 Mask */
#define PWMC_OSC_OSCL3_Pos                    (19)                                           /**< (PWMC_OSC) Output Selection Clear for PWML output of the channel 3 Position */
#define PWMC_OSC_OSCL3_Msk                    (0x1U << PWMC_OSC_OSCL3_Pos)                   /**< (PWMC_OSC) Output Selection Clear for PWML output of the channel 3 Mask */
#define PWMC_OSC_Msk                          (0x000F000FUL)                                 /**< (PWMC_OSC) Register Mask  */
#define PWMC_OSC_OSCH_Pos                     (0)                                            /**< (PWMC_OSC Position) Output Selection Clear for PWMH output of the channel x */
#define PWMC_OSC_OSCH_Msk                     (0xFU << PWMC_OSC_OSCH_Pos)                    /**< (PWMC_OSC Mask) OSCH */
#define PWMC_OSC_OSCH(value)                  (PWMC_OSC_OSCH_Msk & ((value) << PWMC_OSC_OSCH_Pos))
#define PWMC_OSC_OSCL_Pos                     (16)                                           /**< (PWMC_OSC Position) Output Selection Clear for PWML output of the channel 3 */
#define PWMC_OSC_OSCL_Msk                     (0xFU << PWMC_OSC_OSCL_Pos)                    /**< (PWMC_OSC Mask) OSCL */
#define PWMC_OSC_OSCL(value)                  (PWMC_OSC_OSCL_Msk & ((value) << PWMC_OSC_OSCL_Pos))

/* -------- PWMC_OSSUPD : (PWMC Offset: 0x54) (/W 32) PWMC Output Selection Set Update Register -------- */

typedef union
{
  struct
  {
    uint32_t OSSUPH0:1;                 /**< bit:      0  Output Selection Set for PWMH output of the channel 0 */
    uint32_t OSSUPH1:1;                 /**< bit:      1  Output Selection Set for PWMH output of the channel 1 */
    uint32_t OSSUPH2:1;                 /**< bit:      2  Output Selection Set for PWMH output of the channel 2 */
    uint32_t OSSUPH3:1;                 /**< bit:      3  Output Selection Set for PWMH output of the channel 3 */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OSSUPL0:1;                 /**< bit:     16  Output Selection Set for PWML output of the channel 0 */
    uint32_t OSSUPL1:1;                 /**< bit:     17  Output Selection Set for PWML output of the channel 1 */
    uint32_t OSSUPL2:1;                 /**< bit:     18  Output Selection Set for PWML output of the channel 2 */
    uint32_t OSSUPL3:1;                 /**< bit:     19  Output Selection Set for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t OSSUPH:4;                  /**< bit:   0..3  Output Selection Set for PWMH output of the channel x */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OSSUPL:4;                  /**< bit: 16..19  Output Selection Set for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_OSSUPD_bits_t;

#define PWMC_OSSUPD_OSSUPH0_Pos               (0)                                            /**< (PWMC_OSSUPD) Output Selection Set for PWMH output of the channel 0 Position */
#define PWMC_OSSUPD_OSSUPH0_Msk               (0x1U << PWMC_OSSUPD_OSSUPH0_Pos)              /**< (PWMC_OSSUPD) Output Selection Set for PWMH output of the channel 0 Mask */
#define PWMC_OSSUPD_OSSUPH1_Pos               (1)                                            /**< (PWMC_OSSUPD) Output Selection Set for PWMH output of the channel 1 Position */
#define PWMC_OSSUPD_OSSUPH1_Msk               (0x1U << PWMC_OSSUPD_OSSUPH1_Pos)              /**< (PWMC_OSSUPD) Output Selection Set for PWMH output of the channel 1 Mask */
#define PWMC_OSSUPD_OSSUPH2_Pos               (2)                                            /**< (PWMC_OSSUPD) Output Selection Set for PWMH output of the channel 2 Position */
#define PWMC_OSSUPD_OSSUPH2_Msk               (0x1U << PWMC_OSSUPD_OSSUPH2_Pos)              /**< (PWMC_OSSUPD) Output Selection Set for PWMH output of the channel 2 Mask */
#define PWMC_OSSUPD_OSSUPH3_Pos               (3)                                            /**< (PWMC_OSSUPD) Output Selection Set for PWMH output of the channel 3 Position */
#define PWMC_OSSUPD_OSSUPH3_Msk               (0x1U << PWMC_OSSUPD_OSSUPH3_Pos)              /**< (PWMC_OSSUPD) Output Selection Set for PWMH output of the channel 3 Mask */
#define PWMC_OSSUPD_OSSUPL0_Pos               (16)                                           /**< (PWMC_OSSUPD) Output Selection Set for PWML output of the channel 0 Position */
#define PWMC_OSSUPD_OSSUPL0_Msk               (0x1U << PWMC_OSSUPD_OSSUPL0_Pos)              /**< (PWMC_OSSUPD) Output Selection Set for PWML output of the channel 0 Mask */
#define PWMC_OSSUPD_OSSUPL1_Pos               (17)                                           /**< (PWMC_OSSUPD) Output Selection Set for PWML output of the channel 1 Position */
#define PWMC_OSSUPD_OSSUPL1_Msk               (0x1U << PWMC_OSSUPD_OSSUPL1_Pos)              /**< (PWMC_OSSUPD) Output Selection Set for PWML output of the channel 1 Mask */
#define PWMC_OSSUPD_OSSUPL2_Pos               (18)                                           /**< (PWMC_OSSUPD) Output Selection Set for PWML output of the channel 2 Position */
#define PWMC_OSSUPD_OSSUPL2_Msk               (0x1U << PWMC_OSSUPD_OSSUPL2_Pos)              /**< (PWMC_OSSUPD) Output Selection Set for PWML output of the channel 2 Mask */
#define PWMC_OSSUPD_OSSUPL3_Pos               (19)                                           /**< (PWMC_OSSUPD) Output Selection Set for PWML output of the channel 3 Position */
#define PWMC_OSSUPD_OSSUPL3_Msk               (0x1U << PWMC_OSSUPD_OSSUPL3_Pos)              /**< (PWMC_OSSUPD) Output Selection Set for PWML output of the channel 3 Mask */
#define PWMC_OSSUPD_Msk                       (0x000F000FUL)                                 /**< (PWMC_OSSUPD) Register Mask  */
#define PWMC_OSSUPD_OSSUPH_Pos                (0)                                            /**< (PWMC_OSSUPD Position) Output Selection Set for PWMH output of the channel x */
#define PWMC_OSSUPD_OSSUPH_Msk                (0xFU << PWMC_OSSUPD_OSSUPH_Pos)               /**< (PWMC_OSSUPD Mask) OSSUPH */
#define PWMC_OSSUPD_OSSUPH(value)             (PWMC_OSSUPD_OSSUPH_Msk & ((value) << PWMC_OSSUPD_OSSUPH_Pos))
#define PWMC_OSSUPD_OSSUPL_Pos                (16)                                           /**< (PWMC_OSSUPD Position) Output Selection Set for PWML output of the channel 3 */
#define PWMC_OSSUPD_OSSUPL_Msk                (0xFU << PWMC_OSSUPD_OSSUPL_Pos)               /**< (PWMC_OSSUPD Mask) OSSUPL */
#define PWMC_OSSUPD_OSSUPL(value)             (PWMC_OSSUPD_OSSUPL_Msk & ((value) << PWMC_OSSUPD_OSSUPL_Pos))

/* -------- PWMC_OSCUPD : (PWMC Offset: 0x58) (/W 32) PWMC Output Selection Clear Update Register -------- */

typedef union
{
  struct
  {
    uint32_t OSCUPH0:1;                 /**< bit:      0  Output Selection Clear for PWMH output of the channel 0 */
    uint32_t OSCUPH1:1;                 /**< bit:      1  Output Selection Clear for PWMH output of the channel 1 */
    uint32_t OSCUPH2:1;                 /**< bit:      2  Output Selection Clear for PWMH output of the channel 2 */
    uint32_t OSCUPH3:1;                 /**< bit:      3  Output Selection Clear for PWMH output of the channel 3 */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OSCUPL0:1;                 /**< bit:     16  Output Selection Clear for PWML output of the channel 0 */
    uint32_t OSCUPL1:1;                 /**< bit:     17  Output Selection Clear for PWML output of the channel 1 */
    uint32_t OSCUPL2:1;                 /**< bit:     18  Output Selection Clear for PWML output of the channel 2 */
    uint32_t OSCUPL3:1;                 /**< bit:     19  Output Selection Clear for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t OSCUPH:4;                  /**< bit:   0..3  Output Selection Clear for PWMH output of the channel x */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t OSCUPL:4;                  /**< bit: 16..19  Output Selection Clear for PWML output of the channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_OSCUPD_bits_t;

#define PWMC_OSCUPD_OSCUPH0_Pos               (0)                                            /**< (PWMC_OSCUPD) Output Selection Clear for PWMH output of the channel 0 Position */
#define PWMC_OSCUPD_OSCUPH0_Msk               (0x1U << PWMC_OSCUPD_OSCUPH0_Pos)              /**< (PWMC_OSCUPD) Output Selection Clear for PWMH output of the channel 0 Mask */
#define PWMC_OSCUPD_OSCUPH1_Pos               (1)                                            /**< (PWMC_OSCUPD) Output Selection Clear for PWMH output of the channel 1 Position */
#define PWMC_OSCUPD_OSCUPH1_Msk               (0x1U << PWMC_OSCUPD_OSCUPH1_Pos)              /**< (PWMC_OSCUPD) Output Selection Clear for PWMH output of the channel 1 Mask */
#define PWMC_OSCUPD_OSCUPH2_Pos               (2)                                            /**< (PWMC_OSCUPD) Output Selection Clear for PWMH output of the channel 2 Position */
#define PWMC_OSCUPD_OSCUPH2_Msk               (0x1U << PWMC_OSCUPD_OSCUPH2_Pos)              /**< (PWMC_OSCUPD) Output Selection Clear for PWMH output of the channel 2 Mask */
#define PWMC_OSCUPD_OSCUPH3_Pos               (3)                                            /**< (PWMC_OSCUPD) Output Selection Clear for PWMH output of the channel 3 Position */
#define PWMC_OSCUPD_OSCUPH3_Msk               (0x1U << PWMC_OSCUPD_OSCUPH3_Pos)              /**< (PWMC_OSCUPD) Output Selection Clear for PWMH output of the channel 3 Mask */
#define PWMC_OSCUPD_OSCUPL0_Pos               (16)                                           /**< (PWMC_OSCUPD) Output Selection Clear for PWML output of the channel 0 Position */
#define PWMC_OSCUPD_OSCUPL0_Msk               (0x1U << PWMC_OSCUPD_OSCUPL0_Pos)              /**< (PWMC_OSCUPD) Output Selection Clear for PWML output of the channel 0 Mask */
#define PWMC_OSCUPD_OSCUPL1_Pos               (17)                                           /**< (PWMC_OSCUPD) Output Selection Clear for PWML output of the channel 1 Position */
#define PWMC_OSCUPD_OSCUPL1_Msk               (0x1U << PWMC_OSCUPD_OSCUPL1_Pos)              /**< (PWMC_OSCUPD) Output Selection Clear for PWML output of the channel 1 Mask */
#define PWMC_OSCUPD_OSCUPL2_Pos               (18)                                           /**< (PWMC_OSCUPD) Output Selection Clear for PWML output of the channel 2 Position */
#define PWMC_OSCUPD_OSCUPL2_Msk               (0x1U << PWMC_OSCUPD_OSCUPL2_Pos)              /**< (PWMC_OSCUPD) Output Selection Clear for PWML output of the channel 2 Mask */
#define PWMC_OSCUPD_OSCUPL3_Pos               (19)                                           /**< (PWMC_OSCUPD) Output Selection Clear for PWML output of the channel 3 Position */
#define PWMC_OSCUPD_OSCUPL3_Msk               (0x1U << PWMC_OSCUPD_OSCUPL3_Pos)              /**< (PWMC_OSCUPD) Output Selection Clear for PWML output of the channel 3 Mask */
#define PWMC_OSCUPD_Msk                       (0x000F000FUL)                                 /**< (PWMC_OSCUPD) Register Mask  */
#define PWMC_OSCUPD_OSCUPH_Pos                (0)                                            /**< (PWMC_OSCUPD Position) Output Selection Clear for PWMH output of the channel x */
#define PWMC_OSCUPD_OSCUPH_Msk                (0xFU << PWMC_OSCUPD_OSCUPH_Pos)               /**< (PWMC_OSCUPD Mask) OSCUPH */
#define PWMC_OSCUPD_OSCUPH(value)             (PWMC_OSCUPD_OSCUPH_Msk & ((value) << PWMC_OSCUPD_OSCUPH_Pos))
#define PWMC_OSCUPD_OSCUPL_Pos                (16)                                           /**< (PWMC_OSCUPD Position) Output Selection Clear for PWML output of the channel 3 */
#define PWMC_OSCUPD_OSCUPL_Msk                (0xFU << PWMC_OSCUPD_OSCUPL_Pos)               /**< (PWMC_OSCUPD Mask) OSCUPL */
#define PWMC_OSCUPD_OSCUPL(value)             (PWMC_OSCUPD_OSCUPL_Msk & ((value) << PWMC_OSCUPD_OSCUPL_Pos))

/* -------- PWMC_FMR : (PWMC Offset: 0x5c) (R/W 32) PWMC Fault Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t FPOL:8;                    /**< bit:   0..7  Fault Polarity                                */
    uint32_t FMOD:8;                    /**< bit:  8..15  Fault Activation Mode                         */
    uint32_t FFIL:8;                    /**< bit: 16..23  Fault Filtering                               */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_FMR_bits_t;

#define PWMC_FMR_FPOL_Pos                     (0)                                            /**< (PWMC_FMR) Fault Polarity Position */
#define PWMC_FMR_FPOL_Msk                     (0xFFU << PWMC_FMR_FPOL_Pos)                   /**< (PWMC_FMR) Fault Polarity Mask */
#define PWMC_FMR_FPOL(value)                  (PWMC_FMR_FPOL_Msk & ((value) << PWMC_FMR_FPOL_Pos))
#define PWMC_FMR_FMOD_Pos                     (8)                                            /**< (PWMC_FMR) Fault Activation Mode Position */
#define PWMC_FMR_FMOD_Msk                     (0xFFU << PWMC_FMR_FMOD_Pos)                   /**< (PWMC_FMR) Fault Activation Mode Mask */
#define PWMC_FMR_FMOD(value)                  (PWMC_FMR_FMOD_Msk & ((value) << PWMC_FMR_FMOD_Pos))
#define PWMC_FMR_FFIL_Pos                     (16)                                           /**< (PWMC_FMR) Fault Filtering Position */
#define PWMC_FMR_FFIL_Msk                     (0xFFU << PWMC_FMR_FFIL_Pos)                   /**< (PWMC_FMR) Fault Filtering Mask */
#define PWMC_FMR_FFIL(value)                  (PWMC_FMR_FFIL_Msk & ((value) << PWMC_FMR_FFIL_Pos))
#define PWMC_FMR_Msk                          (0x00FFFFFFUL)                                 /**< (PWMC_FMR) Register Mask  */

/* -------- PWMC_FSR : (PWMC Offset: 0x60) (R/ 32) PWMC Fault Status Register -------- */

typedef union
{
  struct
  {
    uint32_t FIV:8;                     /**< bit:   0..7  Fault Input Value                             */
    uint32_t FS:8;                      /**< bit:  8..15  Fault Status                                  */
    uint32_t :16;                       /**< bit: 16..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_FSR_bits_t;

#define PWMC_FSR_FIV_Pos                      (0)                                            /**< (PWMC_FSR) Fault Input Value Position */
#define PWMC_FSR_FIV_Msk                      (0xFFU << PWMC_FSR_FIV_Pos)                    /**< (PWMC_FSR) Fault Input Value Mask */
#define PWMC_FSR_FIV(value)                   (PWMC_FSR_FIV_Msk & ((value) << PWMC_FSR_FIV_Pos))
#define PWMC_FSR_FS_Pos                       (8)                                            /**< (PWMC_FSR) Fault Status Position */
#define PWMC_FSR_FS_Msk                       (0xFFU << PWMC_FSR_FS_Pos)                     /**< (PWMC_FSR) Fault Status Mask */
#define PWMC_FSR_FS(value)                    (PWMC_FSR_FS_Msk & ((value) << PWMC_FSR_FS_Pos))
#define PWMC_FSR_Msk                          (0x0000FFFFUL)                                 /**< (PWMC_FSR) Register Mask  */

/* -------- PWMC_FCR : (PWMC Offset: 0x64) (/W 32) PWMC Fault Clear Register -------- */

typedef union
{
  struct
  {
    uint32_t FCLR:8;                    /**< bit:   0..7  Fault Clear                                   */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_FCR_bits_t;

#define PWMC_FCR_FCLR_Pos                     (0)                                            /**< (PWMC_FCR) Fault Clear Position */
#define PWMC_FCR_FCLR_Msk                     (0xFFU << PWMC_FCR_FCLR_Pos)                   /**< (PWMC_FCR) Fault Clear Mask */
#define PWMC_FCR_FCLR(value)                  (PWMC_FCR_FCLR_Msk & ((value) << PWMC_FCR_FCLR_Pos))
#define PWMC_FCR_Msk                          (0x000000FFUL)                                 /**< (PWMC_FCR) Register Mask  */

/* -------- PWMC_FPV1 : (PWMC Offset: 0x68) (R/W 32) PWMC Fault Protection Value Register 1 -------- */

typedef union
{
  struct
  {
    uint32_t FPVH0:1;                   /**< bit:      0  Fault Protection Value for PWMH output on channel 0 */
    uint32_t FPVH1:1;                   /**< bit:      1  Fault Protection Value for PWMH output on channel 1 */
    uint32_t FPVH2:1;                   /**< bit:      2  Fault Protection Value for PWMH output on channel 2 */
    uint32_t FPVH3:1;                   /**< bit:      3  Fault Protection Value for PWMH output on channel 3 */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FPVL0:1;                   /**< bit:     16  Fault Protection Value for PWML output on channel 0 */
    uint32_t FPVL1:1;                   /**< bit:     17  Fault Protection Value for PWML output on channel 1 */
    uint32_t FPVL2:1;                   /**< bit:     18  Fault Protection Value for PWML output on channel 2 */
    uint32_t FPVL3:1;                   /**< bit:     19  Fault Protection Value for PWML output on channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t FPVH:4;                    /**< bit:   0..3  Fault Protection Value for PWMH output on channel x */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FPVL:4;                    /**< bit: 16..19  Fault Protection Value for PWML output on channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_FPV1_bits_t;

#define PWMC_FPV1_FPVH0_Pos                   (0)                                            /**< (PWMC_FPV1) Fault Protection Value for PWMH output on channel 0 Position */
#define PWMC_FPV1_FPVH0_Msk                   (0x1U << PWMC_FPV1_FPVH0_Pos)                  /**< (PWMC_FPV1) Fault Protection Value for PWMH output on channel 0 Mask */
#define PWMC_FPV1_FPVH1_Pos                   (1)                                            /**< (PWMC_FPV1) Fault Protection Value for PWMH output on channel 1 Position */
#define PWMC_FPV1_FPVH1_Msk                   (0x1U << PWMC_FPV1_FPVH1_Pos)                  /**< (PWMC_FPV1) Fault Protection Value for PWMH output on channel 1 Mask */
#define PWMC_FPV1_FPVH2_Pos                   (2)                                            /**< (PWMC_FPV1) Fault Protection Value for PWMH output on channel 2 Position */
#define PWMC_FPV1_FPVH2_Msk                   (0x1U << PWMC_FPV1_FPVH2_Pos)                  /**< (PWMC_FPV1) Fault Protection Value for PWMH output on channel 2 Mask */
#define PWMC_FPV1_FPVH3_Pos                   (3)                                            /**< (PWMC_FPV1) Fault Protection Value for PWMH output on channel 3 Position */
#define PWMC_FPV1_FPVH3_Msk                   (0x1U << PWMC_FPV1_FPVH3_Pos)                  /**< (PWMC_FPV1) Fault Protection Value for PWMH output on channel 3 Mask */
#define PWMC_FPV1_FPVL0_Pos                   (16)                                           /**< (PWMC_FPV1) Fault Protection Value for PWML output on channel 0 Position */
#define PWMC_FPV1_FPVL0_Msk                   (0x1U << PWMC_FPV1_FPVL0_Pos)                  /**< (PWMC_FPV1) Fault Protection Value for PWML output on channel 0 Mask */
#define PWMC_FPV1_FPVL1_Pos                   (17)                                           /**< (PWMC_FPV1) Fault Protection Value for PWML output on channel 1 Position */
#define PWMC_FPV1_FPVL1_Msk                   (0x1U << PWMC_FPV1_FPVL1_Pos)                  /**< (PWMC_FPV1) Fault Protection Value for PWML output on channel 1 Mask */
#define PWMC_FPV1_FPVL2_Pos                   (18)                                           /**< (PWMC_FPV1) Fault Protection Value for PWML output on channel 2 Position */
#define PWMC_FPV1_FPVL2_Msk                   (0x1U << PWMC_FPV1_FPVL2_Pos)                  /**< (PWMC_FPV1) Fault Protection Value for PWML output on channel 2 Mask */
#define PWMC_FPV1_FPVL3_Pos                   (19)                                           /**< (PWMC_FPV1) Fault Protection Value for PWML output on channel 3 Position */
#define PWMC_FPV1_FPVL3_Msk                   (0x1U << PWMC_FPV1_FPVL3_Pos)                  /**< (PWMC_FPV1) Fault Protection Value for PWML output on channel 3 Mask */
#define PWMC_FPV1_Msk                         (0x000F000FUL)                                 /**< (PWMC_FPV1) Register Mask  */
#define PWMC_FPV1_FPVH_Pos                    (0)                                            /**< (PWMC_FPV1 Position) Fault Protection Value for PWMH output on channel x */
#define PWMC_FPV1_FPVH_Msk                    (0xFU << PWMC_FPV1_FPVH_Pos)                   /**< (PWMC_FPV1 Mask) FPVH */
#define PWMC_FPV1_FPVH(value)                 (PWMC_FPV1_FPVH_Msk & ((value) << PWMC_FPV1_FPVH_Pos))
#define PWMC_FPV1_FPVL_Pos                    (16)                                           /**< (PWMC_FPV1 Position) Fault Protection Value for PWML output on channel 3 */
#define PWMC_FPV1_FPVL_Msk                    (0xFU << PWMC_FPV1_FPVL_Pos)                   /**< (PWMC_FPV1 Mask) FPVL */
#define PWMC_FPV1_FPVL(value)                 (PWMC_FPV1_FPVL_Msk & ((value) << PWMC_FPV1_FPVL_Pos))

/* -------- PWMC_FPE : (PWMC Offset: 0x6c) (R/W 32) PWMC Fault Protection Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t FPE0:8;                    /**< bit:   0..7  Fault Protection Enable for channel 0         */
    uint32_t FPE1:8;                    /**< bit:  8..15  Fault Protection Enable for channel 1         */
    uint32_t FPE2:8;                    /**< bit: 16..23  Fault Protection Enable for channel 2         */
    uint32_t FPE3:8;                    /**< bit: 24..31  Fault Protection Enable for channel 3         */
  };
  uint32_t w;
} __PWMC_FPE_bits_t;

#define PWMC_FPE_FPE0_Pos                     (0)                                            /**< (PWMC_FPE) Fault Protection Enable for channel 0 Position */
#define PWMC_FPE_FPE0_Msk                     (0xFFU << PWMC_FPE_FPE0_Pos)                   /**< (PWMC_FPE) Fault Protection Enable for channel 0 Mask */
#define PWMC_FPE_FPE0(value)                  (PWMC_FPE_FPE0_Msk & ((value) << PWMC_FPE_FPE0_Pos))
#define PWMC_FPE_FPE1_Pos                     (8)                                            /**< (PWMC_FPE) Fault Protection Enable for channel 1 Position */
#define PWMC_FPE_FPE1_Msk                     (0xFFU << PWMC_FPE_FPE1_Pos)                   /**< (PWMC_FPE) Fault Protection Enable for channel 1 Mask */
#define PWMC_FPE_FPE1(value)                  (PWMC_FPE_FPE1_Msk & ((value) << PWMC_FPE_FPE1_Pos))
#define PWMC_FPE_FPE2_Pos                     (16)                                           /**< (PWMC_FPE) Fault Protection Enable for channel 2 Position */
#define PWMC_FPE_FPE2_Msk                     (0xFFU << PWMC_FPE_FPE2_Pos)                   /**< (PWMC_FPE) Fault Protection Enable for channel 2 Mask */
#define PWMC_FPE_FPE2(value)                  (PWMC_FPE_FPE2_Msk & ((value) << PWMC_FPE_FPE2_Pos))
#define PWMC_FPE_FPE3_Pos                     (24)                                           /**< (PWMC_FPE) Fault Protection Enable for channel 3 Position */
#define PWMC_FPE_FPE3_Msk                     (0xFFU << PWMC_FPE_FPE3_Pos)                   /**< (PWMC_FPE) Fault Protection Enable for channel 3 Mask */
#define PWMC_FPE_FPE3(value)                  (PWMC_FPE_FPE3_Msk & ((value) << PWMC_FPE_FPE3_Pos))
#define PWMC_FPE_Msk                          (0xFFFFFFFFUL)                                 /**< (PWMC_FPE) Register Mask  */

/* -------- PWMC_ELMR : (PWMC Offset: 0x7c) (R/W 32) PWMC Event Line 0 Mode Register 0 -------- */

typedef union
{
  struct
  {
    uint32_t CSEL0:1;                   /**< bit:      0  Comparison 0 Selection                        */
    uint32_t CSEL1:1;                   /**< bit:      1  Comparison 1 Selection                        */
    uint32_t CSEL2:1;                   /**< bit:      2  Comparison 2 Selection                        */
    uint32_t CSEL3:1;                   /**< bit:      3  Comparison 3 Selection                        */
    uint32_t CSEL4:1;                   /**< bit:      4  Comparison 4 Selection                        */
    uint32_t CSEL5:1;                   /**< bit:      5  Comparison 5 Selection                        */
    uint32_t CSEL6:1;                   /**< bit:      6  Comparison 6 Selection                        */
    uint32_t CSEL7:1;                   /**< bit:      7  Comparison 7 Selection                        */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  struct
  {
    uint32_t CSEL:8;                    /**< bit:   0..7  Comparison 7 Selection                        */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_ELMR_bits_t;

#define PWMC_ELMR_CSEL0_Pos                   (0)                                            /**< (PWMC_ELMR) Comparison 0 Selection Position */
#define PWMC_ELMR_CSEL0_Msk                   (0x1U << PWMC_ELMR_CSEL0_Pos)                  /**< (PWMC_ELMR) Comparison 0 Selection Mask */
#define PWMC_ELMR_CSEL1_Pos                   (1)                                            /**< (PWMC_ELMR) Comparison 1 Selection Position */
#define PWMC_ELMR_CSEL1_Msk                   (0x1U << PWMC_ELMR_CSEL1_Pos)                  /**< (PWMC_ELMR) Comparison 1 Selection Mask */
#define PWMC_ELMR_CSEL2_Pos                   (2)                                            /**< (PWMC_ELMR) Comparison 2 Selection Position */
#define PWMC_ELMR_CSEL2_Msk                   (0x1U << PWMC_ELMR_CSEL2_Pos)                  /**< (PWMC_ELMR) Comparison 2 Selection Mask */
#define PWMC_ELMR_CSEL3_Pos                   (3)                                            /**< (PWMC_ELMR) Comparison 3 Selection Position */
#define PWMC_ELMR_CSEL3_Msk                   (0x1U << PWMC_ELMR_CSEL3_Pos)                  /**< (PWMC_ELMR) Comparison 3 Selection Mask */
#define PWMC_ELMR_CSEL4_Pos                   (4)                                            /**< (PWMC_ELMR) Comparison 4 Selection Position */
#define PWMC_ELMR_CSEL4_Msk                   (0x1U << PWMC_ELMR_CSEL4_Pos)                  /**< (PWMC_ELMR) Comparison 4 Selection Mask */
#define PWMC_ELMR_CSEL5_Pos                   (5)                                            /**< (PWMC_ELMR) Comparison 5 Selection Position */
#define PWMC_ELMR_CSEL5_Msk                   (0x1U << PWMC_ELMR_CSEL5_Pos)                  /**< (PWMC_ELMR) Comparison 5 Selection Mask */
#define PWMC_ELMR_CSEL6_Pos                   (6)                                            /**< (PWMC_ELMR) Comparison 6 Selection Position */
#define PWMC_ELMR_CSEL6_Msk                   (0x1U << PWMC_ELMR_CSEL6_Pos)                  /**< (PWMC_ELMR) Comparison 6 Selection Mask */
#define PWMC_ELMR_CSEL7_Pos                   (7)                                            /**< (PWMC_ELMR) Comparison 7 Selection Position */
#define PWMC_ELMR_CSEL7_Msk                   (0x1U << PWMC_ELMR_CSEL7_Pos)                  /**< (PWMC_ELMR) Comparison 7 Selection Mask */
#define PWMC_ELMR_Msk                         (0x000000FFUL)                                 /**< (PWMC_ELMR) Register Mask  */
#define PWMC_ELMR_CSEL_Pos                    (0)                                            /**< (PWMC_ELMR Position) Comparison 7 Selection */
#define PWMC_ELMR_CSEL_Msk                    (0xFFU << PWMC_ELMR_CSEL_Pos)                  /**< (PWMC_ELMR Mask) CSEL */
#define PWMC_ELMR_CSEL(value)                 (PWMC_ELMR_CSEL_Msk & ((value) << PWMC_ELMR_CSEL_Pos))

/* -------- PWMC_SSPR : (PWMC Offset: 0xa0) (R/W 32) PWMC Spread Spectrum Register -------- */

typedef union
{
  struct
  {
    uint32_t SPRD:24;                   /**< bit:  0..23  Spread Spectrum Limit Value                   */
    uint32_t SPRDM:1;                   /**< bit:     24  Spread Spectrum Counter Mode                  */
    uint32_t :7;                        /**< bit: 25..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_SSPR_bits_t;

#define PWMC_SSPR_SPRD_Pos                    (0)                                            /**< (PWMC_SSPR) Spread Spectrum Limit Value Position */
#define PWMC_SSPR_SPRD_Msk                    (0xFFFFFFU << PWMC_SSPR_SPRD_Pos)              /**< (PWMC_SSPR) Spread Spectrum Limit Value Mask */
#define PWMC_SSPR_SPRD(value)                 (PWMC_SSPR_SPRD_Msk & ((value) << PWMC_SSPR_SPRD_Pos))
#define PWMC_SSPR_SPRDM_Pos                   (24)                                           /**< (PWMC_SSPR) Spread Spectrum Counter Mode Position */
#define PWMC_SSPR_SPRDM_Msk                   (0x1U << PWMC_SSPR_SPRDM_Pos)                  /**< (PWMC_SSPR) Spread Spectrum Counter Mode Mask */
#define PWMC_SSPR_Msk                         (0x01FFFFFFUL)                                 /**< (PWMC_SSPR) Register Mask  */

/* -------- PWMC_SSPUP : (PWMC Offset: 0xa4) (/W 32) PWMC Spread Spectrum Update Register -------- */

typedef union
{
  struct
  {
    uint32_t SPRDUP:24;                 /**< bit:  0..23  Spread Spectrum Limit Value Update            */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_SSPUP_bits_t;

#define PWMC_SSPUP_SPRDUP_Pos                 (0)                                            /**< (PWMC_SSPUP) Spread Spectrum Limit Value Update Position */
#define PWMC_SSPUP_SPRDUP_Msk                 (0xFFFFFFU << PWMC_SSPUP_SPRDUP_Pos)           /**< (PWMC_SSPUP) Spread Spectrum Limit Value Update Mask */
#define PWMC_SSPUP_SPRDUP(value)              (PWMC_SSPUP_SPRDUP_Msk & ((value) << PWMC_SSPUP_SPRDUP_Pos))
#define PWMC_SSPUP_Msk                        (0x00FFFFFFUL)                                 /**< (PWMC_SSPUP) Register Mask  */

/* -------- PWMC_SMMR : (PWMC Offset: 0xb0) (R/W 32) PWMC Stepper Motor Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t GCEN0:1;                   /**< bit:      0  Gray Count ENable                             */
    uint32_t GCEN1:1;                   /**< bit:      1  Gray Count ENable                             */
    uint32_t :14;                       /**< bit:  2..15  Reserved                                      */
    uint32_t DOWN0:1;                   /**< bit:     16  DOWN Count                                    */
    uint32_t DOWN1:1;                   /**< bit:     17  DOWN Count                                    */
    uint32_t :14;                       /**< bit: 18..31  Reserved                                      */
  };
  struct
  {
    uint32_t GCEN:2;                    /**< bit:   0..1  Gray Count ENable                             */
    uint32_t :14;                       /**< bit:  2..15  Reserved                                      */
    uint32_t DOWN:2;                    /**< bit: 16..17  DOWN Count                                    */
    uint32_t :14;                       /**< bit: 18..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_SMMR_bits_t;

#define PWMC_SMMR_GCEN0_Pos                   (0)                                            /**< (PWMC_SMMR) Gray Count ENable Position */
#define PWMC_SMMR_GCEN0_Msk                   (0x1U << PWMC_SMMR_GCEN0_Pos)                  /**< (PWMC_SMMR) Gray Count ENable Mask */
#define PWMC_SMMR_GCEN1_Pos                   (1)                                            /**< (PWMC_SMMR) Gray Count ENable Position */
#define PWMC_SMMR_GCEN1_Msk                   (0x1U << PWMC_SMMR_GCEN1_Pos)                  /**< (PWMC_SMMR) Gray Count ENable Mask */
#define PWMC_SMMR_DOWN0_Pos                   (16)                                           /**< (PWMC_SMMR) DOWN Count Position */
#define PWMC_SMMR_DOWN0_Msk                   (0x1U << PWMC_SMMR_DOWN0_Pos)                  /**< (PWMC_SMMR) DOWN Count Mask */
#define PWMC_SMMR_DOWN1_Pos                   (17)                                           /**< (PWMC_SMMR) DOWN Count Position */
#define PWMC_SMMR_DOWN1_Msk                   (0x1U << PWMC_SMMR_DOWN1_Pos)                  /**< (PWMC_SMMR) DOWN Count Mask */
#define PWMC_SMMR_Msk                         (0x00030003UL)                                 /**< (PWMC_SMMR) Register Mask  */
#define PWMC_SMMR_GCEN_Pos                    (0)                                            /**< (PWMC_SMMR Position) Gray Count ENable */
#define PWMC_SMMR_GCEN_Msk                    (0x3U << PWMC_SMMR_GCEN_Pos)                   /**< (PWMC_SMMR Mask) GCEN */
#define PWMC_SMMR_GCEN(value)                 (PWMC_SMMR_GCEN_Msk & ((value) << PWMC_SMMR_GCEN_Pos))
#define PWMC_SMMR_DOWN_Pos                    (16)                                           /**< (PWMC_SMMR Position) DOWN Count */
#define PWMC_SMMR_DOWN_Msk                    (0x3U << PWMC_SMMR_DOWN_Pos)                   /**< (PWMC_SMMR Mask) DOWN */
#define PWMC_SMMR_DOWN(value)                 (PWMC_SMMR_DOWN_Msk & ((value) << PWMC_SMMR_DOWN_Pos))

/* -------- PWMC_FPV2 : (PWMC Offset: 0xc0) (R/W 32) PWMC Fault Protection Value 2 Register -------- */

typedef union
{
  struct
  {
    uint32_t FPZH0:1;                   /**< bit:      0  Fault Protection to Hi-Z for PWMH output on channel 0 */
    uint32_t FPZH1:1;                   /**< bit:      1  Fault Protection to Hi-Z for PWMH output on channel 1 */
    uint32_t FPZH2:1;                   /**< bit:      2  Fault Protection to Hi-Z for PWMH output on channel 2 */
    uint32_t FPZH3:1;                   /**< bit:      3  Fault Protection to Hi-Z for PWMH output on channel 3 */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FPZL0:1;                   /**< bit:     16  Fault Protection to Hi-Z for PWML output on channel 0 */
    uint32_t FPZL1:1;                   /**< bit:     17  Fault Protection to Hi-Z for PWML output on channel 1 */
    uint32_t FPZL2:1;                   /**< bit:     18  Fault Protection to Hi-Z for PWML output on channel 2 */
    uint32_t FPZL3:1;                   /**< bit:     19  Fault Protection to Hi-Z for PWML output on channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  {
    uint32_t FPZH:4;                    /**< bit:   0..3  Fault Protection to Hi-Z for PWMH output on channel x */
    uint32_t :12;                       /**< bit:  4..15  Reserved                                      */
    uint32_t FPZL:4;                    /**< bit: 16..19  Fault Protection to Hi-Z for PWML output on channel 3 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_FPV2_bits_t;

#define PWMC_FPV2_FPZH0_Pos                   (0)                                            /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWMH output on channel 0 Position */
#define PWMC_FPV2_FPZH0_Msk                   (0x1U << PWMC_FPV2_FPZH0_Pos)                  /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWMH output on channel 0 Mask */
#define PWMC_FPV2_FPZH1_Pos                   (1)                                            /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWMH output on channel 1 Position */
#define PWMC_FPV2_FPZH1_Msk                   (0x1U << PWMC_FPV2_FPZH1_Pos)                  /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWMH output on channel 1 Mask */
#define PWMC_FPV2_FPZH2_Pos                   (2)                                            /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWMH output on channel 2 Position */
#define PWMC_FPV2_FPZH2_Msk                   (0x1U << PWMC_FPV2_FPZH2_Pos)                  /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWMH output on channel 2 Mask */
#define PWMC_FPV2_FPZH3_Pos                   (3)                                            /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWMH output on channel 3 Position */
#define PWMC_FPV2_FPZH3_Msk                   (0x1U << PWMC_FPV2_FPZH3_Pos)                  /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWMH output on channel 3 Mask */
#define PWMC_FPV2_FPZL0_Pos                   (16)                                           /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWML output on channel 0 Position */
#define PWMC_FPV2_FPZL0_Msk                   (0x1U << PWMC_FPV2_FPZL0_Pos)                  /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWML output on channel 0 Mask */
#define PWMC_FPV2_FPZL1_Pos                   (17)                                           /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWML output on channel 1 Position */
#define PWMC_FPV2_FPZL1_Msk                   (0x1U << PWMC_FPV2_FPZL1_Pos)                  /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWML output on channel 1 Mask */
#define PWMC_FPV2_FPZL2_Pos                   (18)                                           /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWML output on channel 2 Position */
#define PWMC_FPV2_FPZL2_Msk                   (0x1U << PWMC_FPV2_FPZL2_Pos)                  /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWML output on channel 2 Mask */
#define PWMC_FPV2_FPZL3_Pos                   (19)                                           /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWML output on channel 3 Position */
#define PWMC_FPV2_FPZL3_Msk                   (0x1U << PWMC_FPV2_FPZL3_Pos)                  /**< (PWMC_FPV2) Fault Protection to Hi-Z for PWML output on channel 3 Mask */
#define PWMC_FPV2_Msk                         (0x000F000FUL)                                 /**< (PWMC_FPV2) Register Mask  */
#define PWMC_FPV2_FPZH_Pos                    (0)                                            /**< (PWMC_FPV2 Position) Fault Protection to Hi-Z for PWMH output on channel x */
#define PWMC_FPV2_FPZH_Msk                    (0xFU << PWMC_FPV2_FPZH_Pos)                   /**< (PWMC_FPV2 Mask) FPZH */
#define PWMC_FPV2_FPZH(value)                 (PWMC_FPV2_FPZH_Msk & ((value) << PWMC_FPV2_FPZH_Pos))
#define PWMC_FPV2_FPZL_Pos                    (16)                                           /**< (PWMC_FPV2 Position) Fault Protection to Hi-Z for PWML output on channel 3 */
#define PWMC_FPV2_FPZL_Msk                    (0xFU << PWMC_FPV2_FPZL_Pos)                   /**< (PWMC_FPV2 Mask) FPZL */
#define PWMC_FPV2_FPZL(value)                 (PWMC_FPV2_FPZL_Msk & ((value) << PWMC_FPV2_FPZL_Pos))

/* -------- PWMC_WPCR : (PWMC Offset: 0xe4) (/W 32) PWMC Write Protection Control Register -------- */

typedef union
{
  struct
  {
    uint32_t WPCMD:2;                   /**< bit:   0..1  Write Protection Command                      */
    uint32_t WPRG0:1;                   /**< bit:      2  Write Protection Register Group 0             */
    uint32_t WPRG1:1;                   /**< bit:      3  Write Protection Register Group 1             */
    uint32_t WPRG2:1;                   /**< bit:      4  Write Protection Register Group 2             */
    uint32_t WPRG3:1;                   /**< bit:      5  Write Protection Register Group 3             */
    uint32_t WPRG4:1;                   /**< bit:      6  Write Protection Register Group 4             */
    uint32_t WPRG5:1;                   /**< bit:      7  Write Protection Register Group 5             */
    uint32_t WPKEY:24;                  /**< bit:  8..31  Write Protection Key                          */
  };
  struct
  {
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t WPRG:6;                    /**< bit:   2..7  Write Protection Register Group x             */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_WPCR_bits_t;

#define PWMC_WPCR_WPCMD_Pos                   (0)                                            /**< (PWMC_WPCR) Write Protection Command Position */
#define PWMC_WPCR_WPCMD_Msk                   (0x3U << PWMC_WPCR_WPCMD_Pos)                  /**< (PWMC_WPCR) Write Protection Command Mask */
#define PWMC_WPCR_WPCMD(value)                (PWMC_WPCR_WPCMD_Msk & ((value) << PWMC_WPCR_WPCMD_Pos))
#define   PWMC_WPCR_WPCMD_DISABLE_SW_PROT_Val (0x0U)                                         /**< (PWMC_WPCR) Disables the software write protection of the register groups of which the bit WPRGx is at '1'.  */
#define   PWMC_WPCR_WPCMD_ENABLE_SW_PROT_Val  (0x1U)                                         /**< (PWMC_WPCR) Enables the software write protection of the register groups of which the bit WPRGx is at '1'.  */
#define   PWMC_WPCR_WPCMD_ENABLE_HW_PROT_Val  (0x2U)                                         /**< (PWMC_WPCR) Enables the hardware write protection of the register groups of which the bit WPRGx is at '1'. Only a hardware reset of the PWM controller can disable the hardware write protection. Moreover, to meet security requirements, the PORT lines associated with the PWM can not be configured through the PORT interface.  */
#define PWMC_WPCR_WPCMD_DISABLE_SW_PROT       (PWMC_WPCR_WPCMD_DISABLE_SW_PROT_Val << PWMC_WPCR_WPCMD_Pos)  /**< (PWMC_WPCR) Disables the software write protection of the register groups of which the bit WPRGx is at '1'. Position  */
#define PWMC_WPCR_WPCMD_ENABLE_SW_PROT        (PWMC_WPCR_WPCMD_ENABLE_SW_PROT_Val << PWMC_WPCR_WPCMD_Pos)  /**< (PWMC_WPCR) Enables the software write protection of the register groups of which the bit WPRGx is at '1'. Position  */
#define PWMC_WPCR_WPCMD_ENABLE_HW_PROT        (PWMC_WPCR_WPCMD_ENABLE_HW_PROT_Val << PWMC_WPCR_WPCMD_Pos)  /**< (PWMC_WPCR) Enables the hardware write protection of the register groups of which the bit WPRGx is at '1'. Only a hardware reset of the PWM controller can disable the hardware write protection. Moreover, to meet security requirements, the PORT lines associated with the PWM can not be configured through the PORT interface. Position  */
#define PWMC_WPCR_WPRG0_Pos                   (2)                                            /**< (PWMC_WPCR) Write Protection Register Group 0 Position */
#define PWMC_WPCR_WPRG0_Msk                   (0x1U << PWMC_WPCR_WPRG0_Pos)                  /**< (PWMC_WPCR) Write Protection Register Group 0 Mask */
#define PWMC_WPCR_WPRG1_Pos                   (3)                                            /**< (PWMC_WPCR) Write Protection Register Group 1 Position */
#define PWMC_WPCR_WPRG1_Msk                   (0x1U << PWMC_WPCR_WPRG1_Pos)                  /**< (PWMC_WPCR) Write Protection Register Group 1 Mask */
#define PWMC_WPCR_WPRG2_Pos                   (4)                                            /**< (PWMC_WPCR) Write Protection Register Group 2 Position */
#define PWMC_WPCR_WPRG2_Msk                   (0x1U << PWMC_WPCR_WPRG2_Pos)                  /**< (PWMC_WPCR) Write Protection Register Group 2 Mask */
#define PWMC_WPCR_WPRG3_Pos                   (5)                                            /**< (PWMC_WPCR) Write Protection Register Group 3 Position */
#define PWMC_WPCR_WPRG3_Msk                   (0x1U << PWMC_WPCR_WPRG3_Pos)                  /**< (PWMC_WPCR) Write Protection Register Group 3 Mask */
#define PWMC_WPCR_WPRG4_Pos                   (6)                                            /**< (PWMC_WPCR) Write Protection Register Group 4 Position */
#define PWMC_WPCR_WPRG4_Msk                   (0x1U << PWMC_WPCR_WPRG4_Pos)                  /**< (PWMC_WPCR) Write Protection Register Group 4 Mask */
#define PWMC_WPCR_WPRG5_Pos                   (7)                                            /**< (PWMC_WPCR) Write Protection Register Group 5 Position */
#define PWMC_WPCR_WPRG5_Msk                   (0x1U << PWMC_WPCR_WPRG5_Pos)                  /**< (PWMC_WPCR) Write Protection Register Group 5 Mask */
#define PWMC_WPCR_WPKEY_Pos                   (8)                                            /**< (PWMC_WPCR) Write Protection Key Position */
#define PWMC_WPCR_WPKEY_Msk                   (0xFFFFFFU << PWMC_WPCR_WPKEY_Pos)             /**< (PWMC_WPCR) Write Protection Key Mask */
#define PWMC_WPCR_WPKEY(value)                (PWMC_WPCR_WPKEY_Msk & ((value) << PWMC_WPCR_WPKEY_Pos))
#define   PWMC_WPCR_WPKEY_PASSWD_Val          (0x50574DU)                                    /**< (PWMC_WPCR) Writing any other value in this field aborts the write operation of the WPCMD field.Always reads as 0  */
#define PWMC_WPCR_WPKEY_PASSWD                (PWMC_WPCR_WPKEY_PASSWD_Val << PWMC_WPCR_WPKEY_Pos)  /**< (PWMC_WPCR) Writing any other value in this field aborts the write operation of the WPCMD field.Always reads as 0 Position  */
#define PWMC_WPCR_Msk                         (0xFFFFFFFFUL)                                 /**< (PWMC_WPCR) Register Mask  */
#define PWMC_WPCR_WPRG_Pos                    (2)                                            /**< (PWMC_WPCR Position) Write Protection Register Group x */
#define PWMC_WPCR_WPRG_Msk                    (0x3FU << PWMC_WPCR_WPRG_Pos)                  /**< (PWMC_WPCR Mask) WPRG */
#define PWMC_WPCR_WPRG(value)                 (PWMC_WPCR_WPRG_Msk & ((value) << PWMC_WPCR_WPRG_Pos))

/* -------- PWMC_PWM_WPSR : (PWMC Offset: 0xe8) (R/ 32) PWMC Write Protection Status Register -------- */

typedef union
{
  struct
  {
    uint32_t WPSWS0:1;                  /**< bit:      0  Write Protect SW Status                       */
    uint32_t WPSWS1:1;                  /**< bit:      1  Write Protect SW Status                       */
    uint32_t WPSWS2:1;                  /**< bit:      2  Write Protect SW Status                       */
    uint32_t WPSWS3:1;                  /**< bit:      3  Write Protect SW Status                       */
    uint32_t WPSWS4:1;                  /**< bit:      4  Write Protect SW Status                       */
    uint32_t WPSWS5:1;                  /**< bit:      5  Write Protect SW Status                       */
    uint32_t :1;                        /**< bit:      6  Reserved                                      */
    uint32_t WPVS:1;                    /**< bit:      7  Write Protect Violation Status                */
    uint32_t WPHWS0:1;                  /**< bit:      8  Write Protect HW Status                       */
    uint32_t WPHWS1:1;                  /**< bit:      9  Write Protect HW Status                       */
    uint32_t WPHWS2:1;                  /**< bit:     10  Write Protect HW Status                       */
    uint32_t WPHWS3:1;                  /**< bit:     11  Write Protect HW Status                       */
    uint32_t WPHWS4:1;                  /**< bit:     12  Write Protect HW Status                       */
    uint32_t WPHWS5:1;                  /**< bit:     13  Write Protect HW Status                       */
    uint32_t :2;                        /**< bit: 14..15  Reserved                                      */
    uint32_t WPVSRC:16;                 /**< bit: 16..31  Write Protect Violation Source                */
  };
  struct
  {
    uint32_t WPSWS:6;                   /**< bit:   0..5  Write Protect SW Status                       */
    uint32_t :2;                        /**< bit:   6..7  Reserved                                      */
    uint32_t WPHWS:6;                   /**< bit:  8..13  Write Protect HW Status                       */
    uint32_t :18;                       /**< bit: 14..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_PWM_WPSR_bits_t;

#define PWMC_PWM_WPSR_WPSWS0_Pos              (0)                                            /**< (PWMC_PWM_WPSR) Write Protect SW Status Position */
#define PWMC_PWM_WPSR_WPSWS0_Msk              (0x1U << PWMC_PWM_WPSR_WPSWS0_Pos)             /**< (PWMC_PWM_WPSR) Write Protect SW Status Mask */
#define PWMC_PWM_WPSR_WPSWS1_Pos              (1)                                            /**< (PWMC_PWM_WPSR) Write Protect SW Status Position */
#define PWMC_PWM_WPSR_WPSWS1_Msk              (0x1U << PWMC_PWM_WPSR_WPSWS1_Pos)             /**< (PWMC_PWM_WPSR) Write Protect SW Status Mask */
#define PWMC_PWM_WPSR_WPSWS2_Pos              (2)                                            /**< (PWMC_PWM_WPSR) Write Protect SW Status Position */
#define PWMC_PWM_WPSR_WPSWS2_Msk              (0x1U << PWMC_PWM_WPSR_WPSWS2_Pos)             /**< (PWMC_PWM_WPSR) Write Protect SW Status Mask */
#define PWMC_PWM_WPSR_WPSWS3_Pos              (3)                                            /**< (PWMC_PWM_WPSR) Write Protect SW Status Position */
#define PWMC_PWM_WPSR_WPSWS3_Msk              (0x1U << PWMC_PWM_WPSR_WPSWS3_Pos)             /**< (PWMC_PWM_WPSR) Write Protect SW Status Mask */
#define PWMC_PWM_WPSR_WPSWS4_Pos              (4)                                            /**< (PWMC_PWM_WPSR) Write Protect SW Status Position */
#define PWMC_PWM_WPSR_WPSWS4_Msk              (0x1U << PWMC_PWM_WPSR_WPSWS4_Pos)             /**< (PWMC_PWM_WPSR) Write Protect SW Status Mask */
#define PWMC_PWM_WPSR_WPSWS5_Pos              (5)                                            /**< (PWMC_PWM_WPSR) Write Protect SW Status Position */
#define PWMC_PWM_WPSR_WPSWS5_Msk              (0x1U << PWMC_PWM_WPSR_WPSWS5_Pos)             /**< (PWMC_PWM_WPSR) Write Protect SW Status Mask */
#define PWMC_PWM_WPSR_WPVS_Pos                (7)                                            /**< (PWMC_PWM_WPSR) Write Protect Violation Status Position */
#define PWMC_PWM_WPSR_WPVS_Msk                (0x1U << PWMC_PWM_WPSR_WPVS_Pos)               /**< (PWMC_PWM_WPSR) Write Protect Violation Status Mask */
#define PWMC_PWM_WPSR_WPHWS0_Pos              (8)                                            /**< (PWMC_PWM_WPSR) Write Protect HW Status Position */
#define PWMC_PWM_WPSR_WPHWS0_Msk              (0x1U << PWMC_PWM_WPSR_WPHWS0_Pos)             /**< (PWMC_PWM_WPSR) Write Protect HW Status Mask */
#define PWMC_PWM_WPSR_WPHWS1_Pos              (9)                                            /**< (PWMC_PWM_WPSR) Write Protect HW Status Position */
#define PWMC_PWM_WPSR_WPHWS1_Msk              (0x1U << PWMC_PWM_WPSR_WPHWS1_Pos)             /**< (PWMC_PWM_WPSR) Write Protect HW Status Mask */
#define PWMC_PWM_WPSR_WPHWS2_Pos              (10)                                           /**< (PWMC_PWM_WPSR) Write Protect HW Status Position */
#define PWMC_PWM_WPSR_WPHWS2_Msk              (0x1U << PWMC_PWM_WPSR_WPHWS2_Pos)             /**< (PWMC_PWM_WPSR) Write Protect HW Status Mask */
#define PWMC_PWM_WPSR_WPHWS3_Pos              (11)                                           /**< (PWMC_PWM_WPSR) Write Protect HW Status Position */
#define PWMC_PWM_WPSR_WPHWS3_Msk              (0x1U << PWMC_PWM_WPSR_WPHWS3_Pos)             /**< (PWMC_PWM_WPSR) Write Protect HW Status Mask */
#define PWMC_PWM_WPSR_WPHWS4_Pos              (12)                                           /**< (PWMC_PWM_WPSR) Write Protect HW Status Position */
#define PWMC_PWM_WPSR_WPHWS4_Msk              (0x1U << PWMC_PWM_WPSR_WPHWS4_Pos)             /**< (PWMC_PWM_WPSR) Write Protect HW Status Mask */
#define PWMC_PWM_WPSR_WPHWS5_Pos              (13)                                           /**< (PWMC_PWM_WPSR) Write Protect HW Status Position */
#define PWMC_PWM_WPSR_WPHWS5_Msk              (0x1U << PWMC_PWM_WPSR_WPHWS5_Pos)             /**< (PWMC_PWM_WPSR) Write Protect HW Status Mask */
#define PWMC_PWM_WPSR_WPVSRC_Pos              (16)                                           /**< (PWMC_PWM_WPSR) Write Protect Violation Source Position */
#define PWMC_PWM_WPSR_WPVSRC_Msk              (0xFFFFU << PWMC_PWM_WPSR_WPVSRC_Pos)          /**< (PWMC_PWM_WPSR) Write Protect Violation Source Mask */
#define PWMC_PWM_WPSR_WPVSRC(value)           (PWMC_PWM_WPSR_WPVSRC_Msk & ((value) << PWMC_PWM_WPSR_WPVSRC_Pos))
#define PWMC_PWM_WPSR_Msk                     (0xFFFF3FBFUL)                                 /**< (PWMC_PWM_WPSR) Register Mask  */
#define PWMC_PWM_WPSR_WPSWS_Pos               (0)                                            /**< (PWMC_PWM_WPSR Position) Write Protect SW Status */
#define PWMC_PWM_WPSR_WPSWS_Msk               (0x3FU << PWMC_PWM_WPSR_WPSWS_Pos)             /**< (PWMC_PWM_WPSR Mask) WPSWS */
#define PWMC_PWM_WPSR_WPSWS(value)            (PWMC_PWM_WPSR_WPSWS_Msk & ((value) << PWMC_PWM_WPSR_WPSWS_Pos))
#define PWMC_PWM_WPSR_WPHWS_Pos               (8)                                            /**< (PWMC_PWM_WPSR Position) Write Protect HW Status */
#define PWMC_PWM_WPSR_WPHWS_Msk               (0x3FU << PWMC_PWM_WPSR_WPHWS_Pos)             /**< (PWMC_PWM_WPSR Mask) WPHWS */
#define PWMC_PWM_WPSR_WPHWS(value)            (PWMC_PWM_WPSR_WPHWS_Msk & ((value) << PWMC_PWM_WPSR_WPHWS_Pos))

/* -------- PWMC_CMUPD0 : (PWMC Offset: 0x400) (/W 32) PWMC Channel Mode Update Register (ch_num = 0) -------- */

typedef union
{
  struct
  {
    uint32_t :9;                        /**< bit:   0..8  Reserved                                      */
    uint32_t CPOLUP:1;                  /**< bit:      9  Channel Polarity Update                       */
    uint32_t :3;                        /**< bit: 10..12  Reserved                                      */
    uint32_t CPOLINVUP:1;               /**< bit:     13  Channel Polarity Inversion Update             */
    uint32_t :18;                       /**< bit: 14..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CMUPD0_bits_t;

#define PWMC_CMUPD0_CPOLUP_Pos                (9)                                            /**< (PWMC_CMUPD0) Channel Polarity Update Position */
#define PWMC_CMUPD0_CPOLUP_Msk                (0x1U << PWMC_CMUPD0_CPOLUP_Pos)               /**< (PWMC_CMUPD0) Channel Polarity Update Mask */
#define PWMC_CMUPD0_CPOLINVUP_Pos             (13)                                           /**< (PWMC_CMUPD0) Channel Polarity Inversion Update Position */
#define PWMC_CMUPD0_CPOLINVUP_Msk             (0x1U << PWMC_CMUPD0_CPOLINVUP_Pos)            /**< (PWMC_CMUPD0) Channel Polarity Inversion Update Mask */
#define PWMC_CMUPD0_Msk                       (0x00002200UL)                                 /**< (PWMC_CMUPD0) Register Mask  */

/* -------- PWMC_CMUPD1 : (PWMC Offset: 0x420) (/W 32) PWMC Channel Mode Update Register (ch_num = 1) -------- */

typedef union
{
  struct
  {
    uint32_t :9;                        /**< bit:   0..8  Reserved                                      */
    uint32_t CPOLUP:1;                  /**< bit:      9  Channel Polarity Update                       */
    uint32_t :3;                        /**< bit: 10..12  Reserved                                      */
    uint32_t CPOLINVUP:1;               /**< bit:     13  Channel Polarity Inversion Update             */
    uint32_t :18;                       /**< bit: 14..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CMUPD1_bits_t;

#define PWMC_CMUPD1_CPOLUP_Pos                (9)                                            /**< (PWMC_CMUPD1) Channel Polarity Update Position */
#define PWMC_CMUPD1_CPOLUP_Msk                (0x1U << PWMC_CMUPD1_CPOLUP_Pos)               /**< (PWMC_CMUPD1) Channel Polarity Update Mask */
#define PWMC_CMUPD1_CPOLINVUP_Pos             (13)                                           /**< (PWMC_CMUPD1) Channel Polarity Inversion Update Position */
#define PWMC_CMUPD1_CPOLINVUP_Msk             (0x1U << PWMC_CMUPD1_CPOLINVUP_Pos)            /**< (PWMC_CMUPD1) Channel Polarity Inversion Update Mask */
#define PWMC_CMUPD1_Msk                       (0x00002200UL)                                 /**< (PWMC_CMUPD1) Register Mask  */

/* -------- PWMC_ETRG1 : (PWMC Offset: 0x42c) (R/W 32) PWMC External Trigger Register (trg_num = 1) -------- */

typedef union
{
  struct
  {
    uint32_t MAXCNT:24;                 /**< bit:  0..23  Maximum Counter value                         */
    uint32_t TRGMODE:2;                 /**< bit: 24..25  External Trigger Mode                         */
    uint32_t :2;                        /**< bit: 26..27  Reserved                                      */
    uint32_t TRGEDGE:1;                 /**< bit:     28  Edge Selection                                */
    uint32_t TRGFILT:1;                 /**< bit:     29  Filtered input                                */
    uint32_t TRGSRC:1;                  /**< bit:     30  Trigger Source                                */
    uint32_t RFEN:1;                    /**< bit:     31  Recoverable Fault Enable                      */
  };
  uint32_t w;
} __PWMC_ETRG1_bits_t;

#define PWMC_ETRG1_MAXCNT_Pos                 (0)                                            /**< (PWMC_ETRG1) Maximum Counter value Position */
#define PWMC_ETRG1_MAXCNT_Msk                 (0xFFFFFFU << PWMC_ETRG1_MAXCNT_Pos)           /**< (PWMC_ETRG1) Maximum Counter value Mask */
#define PWMC_ETRG1_MAXCNT(value)              (PWMC_ETRG1_MAXCNT_Msk & ((value) << PWMC_ETRG1_MAXCNT_Pos))
#define PWMC_ETRG1_TRGMODE_Pos                (24)                                           /**< (PWMC_ETRG1) External Trigger Mode Position */
#define PWMC_ETRG1_TRGMODE_Msk                (0x3U << PWMC_ETRG1_TRGMODE_Pos)               /**< (PWMC_ETRG1) External Trigger Mode Mask */
#define PWMC_ETRG1_TRGMODE(value)             (PWMC_ETRG1_TRGMODE_Msk & ((value) << PWMC_ETRG1_TRGMODE_Pos))
#define   PWMC_ETRG1_TRGMODE_OFF_Val          (0x0U)                                         /**< (PWMC_ETRG1) External trigger is not enabled.  */
#define   PWMC_ETRG1_TRGMODE_MODE1_Val        (0x1U)                                         /**< (PWMC_ETRG1) External PWM Reset Mode  */
#define   PWMC_ETRG1_TRGMODE_MODE2_Val        (0x2U)                                         /**< (PWMC_ETRG1) External PWM Start Mode  */
#define   PWMC_ETRG1_TRGMODE_MODE3_Val        (0x3U)                                         /**< (PWMC_ETRG1) Cycle-by-cycle Duty Mode  */
#define PWMC_ETRG1_TRGMODE_OFF                (PWMC_ETRG1_TRGMODE_OFF_Val << PWMC_ETRG1_TRGMODE_Pos)  /**< (PWMC_ETRG1) External trigger is not enabled. Position  */
#define PWMC_ETRG1_TRGMODE_MODE1              (PWMC_ETRG1_TRGMODE_MODE1_Val << PWMC_ETRG1_TRGMODE_Pos)  /**< (PWMC_ETRG1) External PWM Reset Mode Position  */
#define PWMC_ETRG1_TRGMODE_MODE2              (PWMC_ETRG1_TRGMODE_MODE2_Val << PWMC_ETRG1_TRGMODE_Pos)  /**< (PWMC_ETRG1) External PWM Start Mode Position  */
#define PWMC_ETRG1_TRGMODE_MODE3              (PWMC_ETRG1_TRGMODE_MODE3_Val << PWMC_ETRG1_TRGMODE_Pos)  /**< (PWMC_ETRG1) Cycle-by-cycle Duty Mode Position  */
#define PWMC_ETRG1_TRGEDGE_Pos                (28)                                           /**< (PWMC_ETRG1) Edge Selection Position */
#define PWMC_ETRG1_TRGEDGE_Msk                (0x1U << PWMC_ETRG1_TRGEDGE_Pos)               /**< (PWMC_ETRG1) Edge Selection Mask */
#define   PWMC_ETRG1_TRGEDGE_FALLING_ZERO_Val (0x0U)                                         /**< (PWMC_ETRG1) TRGMODE = 1: TRGINx event detection on falling edge.TRGMODE = 2, 3: TRGINx active level is 0  */
#define   PWMC_ETRG1_TRGEDGE_RISING_ONE_Val   (0x1U)                                         /**< (PWMC_ETRG1) TRGMODE = 1: TRGINx event detection on rising edge.TRGMODE = 2, 3: TRGINx active level is 1  */
#define PWMC_ETRG1_TRGEDGE_FALLING_ZERO       (PWMC_ETRG1_TRGEDGE_FALLING_ZERO_Val << PWMC_ETRG1_TRGEDGE_Pos)  /**< (PWMC_ETRG1) TRGMODE = 1: TRGINx event detection on falling edge.TRGMODE = 2, 3: TRGINx active level is 0 Position  */
#define PWMC_ETRG1_TRGEDGE_RISING_ONE         (PWMC_ETRG1_TRGEDGE_RISING_ONE_Val << PWMC_ETRG1_TRGEDGE_Pos)  /**< (PWMC_ETRG1) TRGMODE = 1: TRGINx event detection on rising edge.TRGMODE = 2, 3: TRGINx active level is 1 Position  */
#define PWMC_ETRG1_TRGFILT_Pos                (29)                                           /**< (PWMC_ETRG1) Filtered input Position */
#define PWMC_ETRG1_TRGFILT_Msk                (0x1U << PWMC_ETRG1_TRGFILT_Pos)               /**< (PWMC_ETRG1) Filtered input Mask */
#define PWMC_ETRG1_TRGSRC_Pos                 (30)                                           /**< (PWMC_ETRG1) Trigger Source Position */
#define PWMC_ETRG1_TRGSRC_Msk                 (0x1U << PWMC_ETRG1_TRGSRC_Pos)                /**< (PWMC_ETRG1) Trigger Source Mask */
#define PWMC_ETRG1_RFEN_Pos                   (31)                                           /**< (PWMC_ETRG1) Recoverable Fault Enable Position */
#define PWMC_ETRG1_RFEN_Msk                   (0x1U << PWMC_ETRG1_RFEN_Pos)                  /**< (PWMC_ETRG1) Recoverable Fault Enable Mask */
#define PWMC_ETRG1_Msk                        (0xF3FFFFFFUL)                                 /**< (PWMC_ETRG1) Register Mask  */

/* -------- PWMC_LEBR1 : (PWMC Offset: 0x430) (R/W 32) PWMC Leading-Edge Blanking Register (trg_num = 1) -------- */

typedef union
{
  struct
  {
    uint32_t LEBDELAY:7;                /**< bit:   0..6  Leading-Edge Blanking Delay for TRGINx        */
    uint32_t :9;                        /**< bit:  7..15  Reserved                                      */
    uint32_t PWMLFEN:1;                 /**< bit:     16  PWML Falling Edge Enable                      */
    uint32_t PWMLREN:1;                 /**< bit:     17  PWML Rising Edge Enable                       */
    uint32_t PWMHFEN:1;                 /**< bit:     18  PWMH Falling Edge Enable                      */
    uint32_t PWMHREN:1;                 /**< bit:     19  PWMH Rising Edge Enable                       */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_LEBR1_bits_t;

#define PWMC_LEBR1_LEBDELAY_Pos               (0)                                            /**< (PWMC_LEBR1) Leading-Edge Blanking Delay for TRGINx Position */
#define PWMC_LEBR1_LEBDELAY_Msk               (0x7FU << PWMC_LEBR1_LEBDELAY_Pos)             /**< (PWMC_LEBR1) Leading-Edge Blanking Delay for TRGINx Mask */
#define PWMC_LEBR1_LEBDELAY(value)            (PWMC_LEBR1_LEBDELAY_Msk & ((value) << PWMC_LEBR1_LEBDELAY_Pos))
#define PWMC_LEBR1_PWMLFEN_Pos                (16)                                           /**< (PWMC_LEBR1) PWML Falling Edge Enable Position */
#define PWMC_LEBR1_PWMLFEN_Msk                (0x1U << PWMC_LEBR1_PWMLFEN_Pos)               /**< (PWMC_LEBR1) PWML Falling Edge Enable Mask */
#define PWMC_LEBR1_PWMLREN_Pos                (17)                                           /**< (PWMC_LEBR1) PWML Rising Edge Enable Position */
#define PWMC_LEBR1_PWMLREN_Msk                (0x1U << PWMC_LEBR1_PWMLREN_Pos)               /**< (PWMC_LEBR1) PWML Rising Edge Enable Mask */
#define PWMC_LEBR1_PWMHFEN_Pos                (18)                                           /**< (PWMC_LEBR1) PWMH Falling Edge Enable Position */
#define PWMC_LEBR1_PWMHFEN_Msk                (0x1U << PWMC_LEBR1_PWMHFEN_Pos)               /**< (PWMC_LEBR1) PWMH Falling Edge Enable Mask */
#define PWMC_LEBR1_PWMHREN_Pos                (19)                                           /**< (PWMC_LEBR1) PWMH Rising Edge Enable Position */
#define PWMC_LEBR1_PWMHREN_Msk                (0x1U << PWMC_LEBR1_PWMHREN_Pos)               /**< (PWMC_LEBR1) PWMH Rising Edge Enable Mask */
#define PWMC_LEBR1_Msk                        (0x000F007FUL)                                 /**< (PWMC_LEBR1) Register Mask  */

/* -------- PWMC_CMUPD2 : (PWMC Offset: 0x440) (/W 32) PWMC Channel Mode Update Register (ch_num = 2) -------- */

typedef union
{
  struct
  {
    uint32_t :9;                        /**< bit:   0..8  Reserved                                      */
    uint32_t CPOLUP:1;                  /**< bit:      9  Channel Polarity Update                       */
    uint32_t :3;                        /**< bit: 10..12  Reserved                                      */
    uint32_t CPOLINVUP:1;               /**< bit:     13  Channel Polarity Inversion Update             */
    uint32_t :18;                       /**< bit: 14..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CMUPD2_bits_t;

#define PWMC_CMUPD2_CPOLUP_Pos                (9)                                            /**< (PWMC_CMUPD2) Channel Polarity Update Position */
#define PWMC_CMUPD2_CPOLUP_Msk                (0x1U << PWMC_CMUPD2_CPOLUP_Pos)               /**< (PWMC_CMUPD2) Channel Polarity Update Mask */
#define PWMC_CMUPD2_CPOLINVUP_Pos             (13)                                           /**< (PWMC_CMUPD2) Channel Polarity Inversion Update Position */
#define PWMC_CMUPD2_CPOLINVUP_Msk             (0x1U << PWMC_CMUPD2_CPOLINVUP_Pos)            /**< (PWMC_CMUPD2) Channel Polarity Inversion Update Mask */
#define PWMC_CMUPD2_Msk                       (0x00002200UL)                                 /**< (PWMC_CMUPD2) Register Mask  */

/* -------- PWMC_ETRG2 : (PWMC Offset: 0x44c) (R/W 32) PWMC External Trigger Register (trg_num = 2) -------- */

typedef union
{
  struct
  {
    uint32_t MAXCNT:24;                 /**< bit:  0..23  Maximum Counter value                         */
    uint32_t TRGMODE:2;                 /**< bit: 24..25  External Trigger Mode                         */
    uint32_t :2;                        /**< bit: 26..27  Reserved                                      */
    uint32_t TRGEDGE:1;                 /**< bit:     28  Edge Selection                                */
    uint32_t TRGFILT:1;                 /**< bit:     29  Filtered input                                */
    uint32_t TRGSRC:1;                  /**< bit:     30  Trigger Source                                */
    uint32_t RFEN:1;                    /**< bit:     31  Recoverable Fault Enable                      */
  };
  uint32_t w;
} __PWMC_ETRG2_bits_t;

#define PWMC_ETRG2_MAXCNT_Pos                 (0)                                            /**< (PWMC_ETRG2) Maximum Counter value Position */
#define PWMC_ETRG2_MAXCNT_Msk                 (0xFFFFFFU << PWMC_ETRG2_MAXCNT_Pos)           /**< (PWMC_ETRG2) Maximum Counter value Mask */
#define PWMC_ETRG2_MAXCNT(value)              (PWMC_ETRG2_MAXCNT_Msk & ((value) << PWMC_ETRG2_MAXCNT_Pos))
#define PWMC_ETRG2_TRGMODE_Pos                (24)                                           /**< (PWMC_ETRG2) External Trigger Mode Position */
#define PWMC_ETRG2_TRGMODE_Msk                (0x3U << PWMC_ETRG2_TRGMODE_Pos)               /**< (PWMC_ETRG2) External Trigger Mode Mask */
#define PWMC_ETRG2_TRGMODE(value)             (PWMC_ETRG2_TRGMODE_Msk & ((value) << PWMC_ETRG2_TRGMODE_Pos))
#define   PWMC_ETRG2_TRGMODE_OFF_Val          (0x0U)                                         /**< (PWMC_ETRG2) External trigger is not enabled.  */
#define   PWMC_ETRG2_TRGMODE_MODE1_Val        (0x1U)                                         /**< (PWMC_ETRG2) External PWM Reset Mode  */
#define   PWMC_ETRG2_TRGMODE_MODE2_Val        (0x2U)                                         /**< (PWMC_ETRG2) External PWM Start Mode  */
#define   PWMC_ETRG2_TRGMODE_MODE3_Val        (0x3U)                                         /**< (PWMC_ETRG2) Cycle-by-cycle Duty Mode  */
#define PWMC_ETRG2_TRGMODE_OFF                (PWMC_ETRG2_TRGMODE_OFF_Val << PWMC_ETRG2_TRGMODE_Pos)  /**< (PWMC_ETRG2) External trigger is not enabled. Position  */
#define PWMC_ETRG2_TRGMODE_MODE1              (PWMC_ETRG2_TRGMODE_MODE1_Val << PWMC_ETRG2_TRGMODE_Pos)  /**< (PWMC_ETRG2) External PWM Reset Mode Position  */
#define PWMC_ETRG2_TRGMODE_MODE2              (PWMC_ETRG2_TRGMODE_MODE2_Val << PWMC_ETRG2_TRGMODE_Pos)  /**< (PWMC_ETRG2) External PWM Start Mode Position  */
#define PWMC_ETRG2_TRGMODE_MODE3              (PWMC_ETRG2_TRGMODE_MODE3_Val << PWMC_ETRG2_TRGMODE_Pos)  /**< (PWMC_ETRG2) Cycle-by-cycle Duty Mode Position  */
#define PWMC_ETRG2_TRGEDGE_Pos                (28)                                           /**< (PWMC_ETRG2) Edge Selection Position */
#define PWMC_ETRG2_TRGEDGE_Msk                (0x1U << PWMC_ETRG2_TRGEDGE_Pos)               /**< (PWMC_ETRG2) Edge Selection Mask */
#define   PWMC_ETRG2_TRGEDGE_FALLING_ZERO_Val (0x0U)                                         /**< (PWMC_ETRG2) TRGMODE = 1: TRGINx event detection on falling edge.TRGMODE = 2, 3: TRGINx active level is 0  */
#define   PWMC_ETRG2_TRGEDGE_RISING_ONE_Val   (0x1U)                                         /**< (PWMC_ETRG2) TRGMODE = 1: TRGINx event detection on rising edge.TRGMODE = 2, 3: TRGINx active level is 1  */
#define PWMC_ETRG2_TRGEDGE_FALLING_ZERO       (PWMC_ETRG2_TRGEDGE_FALLING_ZERO_Val << PWMC_ETRG2_TRGEDGE_Pos)  /**< (PWMC_ETRG2) TRGMODE = 1: TRGINx event detection on falling edge.TRGMODE = 2, 3: TRGINx active level is 0 Position  */
#define PWMC_ETRG2_TRGEDGE_RISING_ONE         (PWMC_ETRG2_TRGEDGE_RISING_ONE_Val << PWMC_ETRG2_TRGEDGE_Pos)  /**< (PWMC_ETRG2) TRGMODE = 1: TRGINx event detection on rising edge.TRGMODE = 2, 3: TRGINx active level is 1 Position  */
#define PWMC_ETRG2_TRGFILT_Pos                (29)                                           /**< (PWMC_ETRG2) Filtered input Position */
#define PWMC_ETRG2_TRGFILT_Msk                (0x1U << PWMC_ETRG2_TRGFILT_Pos)               /**< (PWMC_ETRG2) Filtered input Mask */
#define PWMC_ETRG2_TRGSRC_Pos                 (30)                                           /**< (PWMC_ETRG2) Trigger Source Position */
#define PWMC_ETRG2_TRGSRC_Msk                 (0x1U << PWMC_ETRG2_TRGSRC_Pos)                /**< (PWMC_ETRG2) Trigger Source Mask */
#define PWMC_ETRG2_RFEN_Pos                   (31)                                           /**< (PWMC_ETRG2) Recoverable Fault Enable Position */
#define PWMC_ETRG2_RFEN_Msk                   (0x1U << PWMC_ETRG2_RFEN_Pos)                  /**< (PWMC_ETRG2) Recoverable Fault Enable Mask */
#define PWMC_ETRG2_Msk                        (0xF3FFFFFFUL)                                 /**< (PWMC_ETRG2) Register Mask  */

/* -------- PWMC_LEBR2 : (PWMC Offset: 0x450) (R/W 32) PWMC Leading-Edge Blanking Register (trg_num = 2) -------- */

typedef union
{
  struct
  {
    uint32_t LEBDELAY:7;                /**< bit:   0..6  Leading-Edge Blanking Delay for TRGINx        */
    uint32_t :9;                        /**< bit:  7..15  Reserved                                      */
    uint32_t PWMLFEN:1;                 /**< bit:     16  PWML Falling Edge Enable                      */
    uint32_t PWMLREN:1;                 /**< bit:     17  PWML Rising Edge Enable                       */
    uint32_t PWMHFEN:1;                 /**< bit:     18  PWMH Falling Edge Enable                      */
    uint32_t PWMHREN:1;                 /**< bit:     19  PWMH Rising Edge Enable                       */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_LEBR2_bits_t;

#define PWMC_LEBR2_LEBDELAY_Pos               (0)                                            /**< (PWMC_LEBR2) Leading-Edge Blanking Delay for TRGINx Position */
#define PWMC_LEBR2_LEBDELAY_Msk               (0x7FU << PWMC_LEBR2_LEBDELAY_Pos)             /**< (PWMC_LEBR2) Leading-Edge Blanking Delay for TRGINx Mask */
#define PWMC_LEBR2_LEBDELAY(value)            (PWMC_LEBR2_LEBDELAY_Msk & ((value) << PWMC_LEBR2_LEBDELAY_Pos))
#define PWMC_LEBR2_PWMLFEN_Pos                (16)                                           /**< (PWMC_LEBR2) PWML Falling Edge Enable Position */
#define PWMC_LEBR2_PWMLFEN_Msk                (0x1U << PWMC_LEBR2_PWMLFEN_Pos)               /**< (PWMC_LEBR2) PWML Falling Edge Enable Mask */
#define PWMC_LEBR2_PWMLREN_Pos                (17)                                           /**< (PWMC_LEBR2) PWML Rising Edge Enable Position */
#define PWMC_LEBR2_PWMLREN_Msk                (0x1U << PWMC_LEBR2_PWMLREN_Pos)               /**< (PWMC_LEBR2) PWML Rising Edge Enable Mask */
#define PWMC_LEBR2_PWMHFEN_Pos                (18)                                           /**< (PWMC_LEBR2) PWMH Falling Edge Enable Position */
#define PWMC_LEBR2_PWMHFEN_Msk                (0x1U << PWMC_LEBR2_PWMHFEN_Pos)               /**< (PWMC_LEBR2) PWMH Falling Edge Enable Mask */
#define PWMC_LEBR2_PWMHREN_Pos                (19)                                           /**< (PWMC_LEBR2) PWMH Rising Edge Enable Position */
#define PWMC_LEBR2_PWMHREN_Msk                (0x1U << PWMC_LEBR2_PWMHREN_Pos)               /**< (PWMC_LEBR2) PWMH Rising Edge Enable Mask */
#define PWMC_LEBR2_Msk                        (0x000F007FUL)                                 /**< (PWMC_LEBR2) Register Mask  */

/* -------- PWMC_CMUPD3 : (PWMC Offset: 0x460) (/W 32) PWMC Channel Mode Update Register (ch_num = 3) -------- */

typedef union
{
  struct
  {
    uint32_t :9;                        /**< bit:   0..8  Reserved                                      */
    uint32_t CPOLUP:1;                  /**< bit:      9  Channel Polarity Update                       */
    uint32_t :3;                        /**< bit: 10..12  Reserved                                      */
    uint32_t CPOLINVUP:1;               /**< bit:     13  Channel Polarity Inversion Update             */
    uint32_t :18;                       /**< bit: 14..31  Reserved                                      */
  };
  uint32_t w;
} __PWMC_CMUPD3_bits_t;

#define PWMC_CMUPD3_CPOLUP_Pos                (9)                                            /**< (PWMC_CMUPD3) Channel Polarity Update Position */
#define PWMC_CMUPD3_CPOLUP_Msk                (0x1U << PWMC_CMUPD3_CPOLUP_Pos)               /**< (PWMC_CMUPD3) Channel Polarity Update Mask */
#define PWMC_CMUPD3_CPOLINVUP_Pos             (13)                                           /**< (PWMC_CMUPD3) Channel Polarity Inversion Update Position */
#define PWMC_CMUPD3_CPOLINVUP_Msk             (0x1U << PWMC_CMUPD3_CPOLINVUP_Pos)            /**< (PWMC_CMUPD3) Channel Polarity Inversion Update Mask */
#define PWMC_CMUPD3_Msk                       (0x00002200UL)                                 /**< (PWMC_CMUPD3) Register Mask  */

/** \brief PWMC_CH_NUM register offsets definitions */
#define PWMC_CMR_OFFSET              (0x00)         /**< (PWMC_CMR) PWMC Channel Mode Register (ch_num = 0) Offset */
#define PWMC_CDTY_OFFSET             (0x04)         /**< (PWMC_CDTY) PWMC Channel Duty Cycle Register (ch_num = 0) Offset */
#define PWMC_CDTYUPD_OFFSET          (0x08)         /**< (PWMC_CDTYUPD) PWMC Channel Duty Cycle Update Register (ch_num = 0) Offset */
#define PWMC_CPRD_OFFSET             (0x0C)         /**< (PWMC_CPRD) PWMC Channel Period Register (ch_num = 0) Offset */
#define PWMC_CPRDUPD_OFFSET          (0x10)         /**< (PWMC_CPRDUPD) PWMC Channel Period Update Register (ch_num = 0) Offset */
#define PWMC_CCNT_OFFSET             (0x14)         /**< (PWMC_CCNT) PWMC Channel Counter Register (ch_num = 0) Offset */
#define PWMC_DT_OFFSET               (0x18)         /**< (PWMC_DT) PWMC Channel Dead Time Register (ch_num = 0) Offset */
#define PWMC_DTUPD_OFFSET            (0x1C)         /**< (PWMC_DTUPD) PWMC Channel Dead Time Update Register (ch_num = 0) Offset */
/** \brief PWMC_CMP register offsets definitions */
#define PWMC_CMPV_OFFSET             (0x00)         /**< (PWMC_CMPV) PWMC Comparison 0 Value Register Offset */
#define PWMC_CMPVUPD_OFFSET          (0x04)         /**< (PWMC_CMPVUPD) PWMC Comparison 0 Value Update Register Offset */
#define PWMC_CMPM_OFFSET             (0x08)         /**< (PWMC_CMPM) PWMC Comparison 0 Mode Register Offset */
#define PWMC_CMPMUPD_OFFSET          (0x0C)         /**< (PWMC_CMPMUPD) PWMC Comparison 0 Mode Update Register Offset */
/** \brief PWMC register offsets definitions */
#define PWMC_CLK_OFFSET              (0x00)         /**< (PWMC_CLK) PWMC Clock Register Offset */
#define PWMC_ENA_OFFSET              (0x04)         /**< (PWMC_ENA) PWMC Enable Register Offset */
#define PWMC_DIS_OFFSET              (0x08)         /**< (PWMC_DIS) PWMC Disable Register Offset */
#define PWMC_SR_OFFSET               (0x0C)         /**< (PWMC_SR) PWMC Status Register Offset */
#define PWMC_IER1_OFFSET             (0x10)         /**< (PWMC_IER1) PWMC Interrupt Enable Register 1 Offset */
#define PWMC_IDR1_OFFSET             (0x14)         /**< (PWMC_IDR1) PWMC Interrupt Disable Register 1 Offset */
#define PWMC_IMR1_OFFSET             (0x18)         /**< (PWMC_IMR1) PWMC Interrupt Mask Register 1 Offset */
#define PWMC_ISR1_OFFSET             (0x1C)         /**< (PWMC_ISR1) PWMC Interrupt Status Register 1 Offset */
#define PWMC_SCM_OFFSET              (0x20)         /**< (PWMC_SCM) PWMC Sync Channels Mode Register Offset */
#define PWMC_DMAR_OFFSET             (0x24)         /**< (PWMC_DMAR) PWMC DMA Register Offset */
#define PWMC_SCUC_OFFSET             (0x28)         /**< (PWMC_SCUC) PWMC Sync Channels Update Control Register Offset */
#define PWMC_SCUP_OFFSET             (0x2C)         /**< (PWMC_SCUP) PWMC Sync Channels Update Period Register Offset */
#define PWMC_SCUPUPD_OFFSET          (0x30)         /**< (PWMC_SCUPUPD) PWMC Sync Channels Update Period Update Register Offset */
#define PWMC_IER2_OFFSET             (0x34)         /**< (PWMC_IER2) PWMC Interrupt Enable Register 2 Offset */
#define PWMC_IDR2_OFFSET             (0x38)         /**< (PWMC_IDR2) PWMC Interrupt Disable Register 2 Offset */
#define PWMC_IMR2_OFFSET             (0x3C)         /**< (PWMC_IMR2) PWMC Interrupt Mask Register 2 Offset */
#define PWMC_ISR2_OFFSET             (0x40)         /**< (PWMC_ISR2) PWMC Interrupt Status Register 2 Offset */
#define PWMC_OOV_OFFSET              (0x44)         /**< (PWMC_OOV) PWMC Output Override Value Register Offset */
#define PWMC_OS_OFFSET               (0x48)         /**< (PWMC_OS) PWMC Output Selection Register Offset */
#define PWMC_OSS_OFFSET              (0x4C)         /**< (PWMC_OSS) PWMC Output Selection Set Register Offset */
#define PWMC_OSC_OFFSET              (0x50)         /**< (PWMC_OSC) PWMC Output Selection Clear Register Offset */
#define PWMC_OSSUPD_OFFSET           (0x54)         /**< (PWMC_OSSUPD) PWMC Output Selection Set Update Register Offset */
#define PWMC_OSCUPD_OFFSET           (0x58)         /**< (PWMC_OSCUPD) PWMC Output Selection Clear Update Register Offset */
#define PWMC_FMR_OFFSET              (0x5C)         /**< (PWMC_FMR) PWMC Fault Mode Register Offset */
#define PWMC_FSR_OFFSET              (0x60)         /**< (PWMC_FSR) PWMC Fault Status Register Offset */
#define PWMC_FCR_OFFSET              (0x64)         /**< (PWMC_FCR) PWMC Fault Clear Register Offset */
#define PWMC_FPV1_OFFSET             (0x68)         /**< (PWMC_FPV1) PWMC Fault Protection Value Register 1 Offset */
#define PWMC_FPE_OFFSET              (0x6C)         /**< (PWMC_FPE) PWMC Fault Protection Enable Register Offset */
#define PWMC_ELMR_OFFSET             (0x7C)         /**< (PWMC_ELMR) PWMC Event Line 0 Mode Register 0 Offset */
#define PWMC_SSPR_OFFSET             (0xA0)         /**< (PWMC_SSPR) PWMC Spread Spectrum Register Offset */
#define PWMC_SSPUP_OFFSET            (0xA4)         /**< (PWMC_SSPUP) PWMC Spread Spectrum Update Register Offset */
#define PWMC_SMMR_OFFSET             (0xB0)         /**< (PWMC_SMMR) PWMC Stepper Motor Mode Register Offset */
#define PWMC_FPV2_OFFSET             (0xC0)         /**< (PWMC_FPV2) PWMC Fault Protection Value 2 Register Offset */
#define PWMC_WPCR_OFFSET             (0xE4)         /**< (PWMC_WPCR) PWMC Write Protection Control Register Offset */
#define PWMC_PWM_WPSR_OFFSET         (0xE8)         /**< (PWMC_PWM_WPSR) PWMC Write Protection Status Register Offset */
#define PWMC_CMUPD0_OFFSET           (0x400)        /**< (PWMC_CMUPD0) PWMC Channel Mode Update Register (ch_num = 0) Offset */
#define PWMC_CMUPD1_OFFSET           (0x420)        /**< (PWMC_CMUPD1) PWMC Channel Mode Update Register (ch_num = 1) Offset */
#define PWMC_ETRG1_OFFSET            (0x42C)        /**< (PWMC_ETRG1) PWMC External Trigger Register (trg_num = 1) Offset */
#define PWMC_LEBR1_OFFSET            (0x430)        /**< (PWMC_LEBR1) PWMC Leading-Edge Blanking Register (trg_num = 1) Offset */
#define PWMC_CMUPD2_OFFSET           (0x440)        /**< (PWMC_CMUPD2) PWMC Channel Mode Update Register (ch_num = 2) Offset */
#define PWMC_ETRG2_OFFSET            (0x44C)        /**< (PWMC_ETRG2) PWMC External Trigger Register (trg_num = 2) Offset */
#define PWMC_LEBR2_OFFSET            (0x450)        /**< (PWMC_LEBR2) PWMC Leading-Edge Blanking Register (trg_num = 2) Offset */
#define PWMC_CMUPD3_OFFSET           (0x460)        /**< (PWMC_CMUPD3) PWMC Channel Mode Update Register (ch_num = 3) Offset */

/** \brief PWMC_CH_NUM register API structure */
typedef struct
{
  __IO  __PWMC_CMR_bits_t              PWMC_CMR;      /**< Offset: 0x00 (R/W  32) PWMC Channel Mode Register (ch_num = 0) */
  __IO  __PWMC_CDTY_bits_t             PWMC_CDTY;     /**< Offset: 0x04 (R/W  32) PWMC Channel Duty Cycle Register (ch_num = 0) */
  __O   __PWMC_CDTYUPD_bits_t          PWMC_CDTYUPD;  /**< Offset: 0x08 ( /W  32) PWMC Channel Duty Cycle Update Register (ch_num = 0) */
  __IO  __PWMC_CPRD_bits_t             PWMC_CPRD;     /**< Offset: 0x0C (R/W  32) PWMC Channel Period Register (ch_num = 0) */
  __O   __PWMC_CPRDUPD_bits_t          PWMC_CPRDUPD;  /**< Offset: 0x10 ( /W  32) PWMC Channel Period Update Register (ch_num = 0) */
  __I   __PWMC_CCNT_bits_t             PWMC_CCNT;     /**< Offset: 0x14 (R/   32) PWMC Channel Counter Register (ch_num = 0) */
  __IO  __PWMC_DT_bits_t               PWMC_DT;       /**< Offset: 0x18 (R/W  32) PWMC Channel Dead Time Register (ch_num = 0) */
  __O   __PWMC_DTUPD_bits_t            PWMC_DTUPD;    /**< Offset: 0x1C ( /W  32) PWMC Channel Dead Time Update Register (ch_num = 0) */
} pwmcchnum_registers_t;

/** \brief PWMC_CMP register API structure */
typedef struct
{
  __IO  __PWMC_CMPV_bits_t             PWMC_CMPV;     /**< Offset: 0x00 (R/W  32) PWMC Comparison 0 Value Register */
  __O   __PWMC_CMPVUPD_bits_t          PWMC_CMPVUPD;  /**< Offset: 0x04 ( /W  32) PWMC Comparison 0 Value Update Register */
  __IO  __PWMC_CMPM_bits_t             PWMC_CMPM;     /**< Offset: 0x08 (R/W  32) PWMC Comparison 0 Mode Register */
  __O   __PWMC_CMPMUPD_bits_t          PWMC_CMPMUPD;  /**< Offset: 0x0C ( /W  32) PWMC Comparison 0 Mode Update Register */
} pwmccmp_registers_t;

#define PWMCCMP_NUMBER 8
#define PWMCCHNUM_NUMBER 4
/** \brief PWMC register API structure */
typedef struct
{
  __IO  __PWMC_CLK_bits_t              PWMC_CLK;      /**< Offset: 0x00 (R/W  32) PWMC Clock Register */
  __O   __PWMC_ENA_bits_t              PWMC_ENA;      /**< Offset: 0x04 ( /W  32) PWMC Enable Register */
  __O   __PWMC_DIS_bits_t              PWMC_DIS;      /**< Offset: 0x08 ( /W  32) PWMC Disable Register */
  __I   __PWMC_SR_bits_t               PWMC_SR;       /**< Offset: 0x0C (R/   32) PWMC Status Register */
  __O   __PWMC_IER1_bits_t             PWMC_IER1;     /**< Offset: 0x10 ( /W  32) PWMC Interrupt Enable Register 1 */
  __O   __PWMC_IDR1_bits_t             PWMC_IDR1;     /**< Offset: 0x14 ( /W  32) PWMC Interrupt Disable Register 1 */
  __I   __PWMC_IMR1_bits_t             PWMC_IMR1;     /**< Offset: 0x18 (R/   32) PWMC Interrupt Mask Register 1 */
  __I   __PWMC_ISR1_bits_t             PWMC_ISR1;     /**< Offset: 0x1C (R/   32) PWMC Interrupt Status Register 1 */
  __IO  __PWMC_SCM_bits_t              PWMC_SCM;      /**< Offset: 0x20 (R/W  32) PWMC Sync Channels Mode Register */
  __O   __PWMC_DMAR_bits_t             PWMC_DMAR;     /**< Offset: 0x24 ( /W  32) PWMC DMA Register */
  __IO  __PWMC_SCUC_bits_t             PWMC_SCUC;     /**< Offset: 0x28 (R/W  32) PWMC Sync Channels Update Control Register */
  __IO  __PWMC_SCUP_bits_t             PWMC_SCUP;     /**< Offset: 0x2C (R/W  32) PWMC Sync Channels Update Period Register */
  __O   __PWMC_SCUPUPD_bits_t          PWMC_SCUPUPD;  /**< Offset: 0x30 ( /W  32) PWMC Sync Channels Update Period Update Register */
  __O   __PWMC_IER2_bits_t             PWMC_IER2;     /**< Offset: 0x34 ( /W  32) PWMC Interrupt Enable Register 2 */
  __O   __PWMC_IDR2_bits_t             PWMC_IDR2;     /**< Offset: 0x38 ( /W  32) PWMC Interrupt Disable Register 2 */
  __I   __PWMC_IMR2_bits_t             PWMC_IMR2;     /**< Offset: 0x3C (R/   32) PWMC Interrupt Mask Register 2 */
  __I   __PWMC_ISR2_bits_t             PWMC_ISR2;     /**< Offset: 0x40 (R/   32) PWMC Interrupt Status Register 2 */
  __IO  __PWMC_OOV_bits_t              PWMC_OOV;      /**< Offset: 0x44 (R/W  32) PWMC Output Override Value Register */
  __IO  __PWMC_OS_bits_t               PWMC_OS;       /**< Offset: 0x48 (R/W  32) PWMC Output Selection Register */
  __O   __PWMC_OSS_bits_t              PWMC_OSS;      /**< Offset: 0x4C ( /W  32) PWMC Output Selection Set Register */
  __O   __PWMC_OSC_bits_t              PWMC_OSC;      /**< Offset: 0x50 ( /W  32) PWMC Output Selection Clear Register */
  __O   __PWMC_OSSUPD_bits_t           PWMC_OSSUPD;   /**< Offset: 0x54 ( /W  32) PWMC Output Selection Set Update Register */
  __O   __PWMC_OSCUPD_bits_t           PWMC_OSCUPD;   /**< Offset: 0x58 ( /W  32) PWMC Output Selection Clear Update Register */
  __IO  __PWMC_FMR_bits_t              PWMC_FMR;      /**< Offset: 0x5C (R/W  32) PWMC Fault Mode Register */
  __I   __PWMC_FSR_bits_t              PWMC_FSR;      /**< Offset: 0x60 (R/   32) PWMC Fault Status Register */
  __O   __PWMC_FCR_bits_t              PWMC_FCR;      /**< Offset: 0x64 ( /W  32) PWMC Fault Clear Register */
  __IO  __PWMC_FPV1_bits_t             PWMC_FPV1;     /**< Offset: 0x68 (R/W  32) PWMC Fault Protection Value Register 1 */
  __IO  __PWMC_FPE_bits_t              PWMC_FPE;      /**< Offset: 0x6C (R/W  32) PWMC Fault Protection Enable Register */
  __I   uint8_t                        Reserved1[0x0C];
  __IO  __PWMC_ELMR_bits_t             PWMC_ELMR[2];  /**< Offset: 0x7C (R/W  32) PWMC Event Line 0 Mode Register 0 */
  __I   uint8_t                        Reserved2[0x1C];
  __IO  __PWMC_SSPR_bits_t             PWMC_SSPR;     /**< Offset: 0xA0 (R/W  32) PWMC Spread Spectrum Register */
  __O   __PWMC_SSPUP_bits_t            PWMC_SSPUP;    /**< Offset: 0xA4 ( /W  32) PWMC Spread Spectrum Update Register */
  __I   uint8_t                        Reserved3[0x08];
  __IO  __PWMC_SMMR_bits_t             PWMC_SMMR;     /**< Offset: 0xB0 (R/W  32) PWMC Stepper Motor Mode Register */
  __I   uint8_t                        Reserved4[0x0C];
  __IO  __PWMC_FPV2_bits_t             PWMC_FPV2;     /**< Offset: 0xC0 (R/W  32) PWMC Fault Protection Value 2 Register */
  __I   uint8_t                        Reserved5[0x20];
  __O   __PWMC_WPCR_bits_t             PWMC_WPCR;     /**< Offset: 0xE4 ( /W  32) PWMC Write Protection Control Register */
  __I   __PWMC_PWM_WPSR_bits_t         PWM_WPSR;      /**< Offset: 0xE8 (R/   32) PWMC Write Protection Status Register */
  __I   uint8_t                        Reserved6[0x44];
        pwmccmp_registers_t            PWMC_CMP[PWMCCMP_NUMBER]; /**< Offset: 0x130 PWMC Comparison 0 Value Register */
  __I   uint8_t                        Reserved7[0x50];
        pwmcchnum_registers_t          PWMC_CH_NUM[PWMCCHNUM_NUMBER]; /**< Offset: 0x200 PWMC Channel Mode Register (ch_num = 0) */
  __I   uint8_t                        Reserved8[0x180];
  __O   __PWMC_CMUPD0_bits_t           PWMC_CMUPD0;   /**< Offset: 0x400 ( /W  32) PWMC Channel Mode Update Register (ch_num = 0) */
  __I   uint8_t                        Reserved9[0x1C];
  __O   __PWMC_CMUPD1_bits_t           PWMC_CMUPD1;   /**< Offset: 0x420 ( /W  32) PWMC Channel Mode Update Register (ch_num = 1) */
  __I   uint8_t                        Reserved10[0x08];
  __IO  __PWMC_ETRG1_bits_t            PWMC_ETRG1;    /**< Offset: 0x42C (R/W  32) PWMC External Trigger Register (trg_num = 1) */
  __IO  __PWMC_LEBR1_bits_t            PWMC_LEBR1;    /**< Offset: 0x430 (R/W  32) PWMC Leading-Edge Blanking Register (trg_num = 1) */
  __I   uint8_t                        Reserved11[0x0C];
  __O   __PWMC_CMUPD2_bits_t           PWMC_CMUPD2;   /**< Offset: 0x440 ( /W  32) PWMC Channel Mode Update Register (ch_num = 2) */
  __I   uint8_t                        Reserved12[0x08];
  __IO  __PWMC_ETRG2_bits_t            PWMC_ETRG2;    /**< Offset: 0x44C (R/W  32) PWMC External Trigger Register (trg_num = 2) */
  __IO  __PWMC_LEBR2_bits_t            PWMC_LEBR2;    /**< Offset: 0x450 (R/W  32) PWMC Leading-Edge Blanking Register (trg_num = 2) */
  __I   uint8_t                        Reserved13[0x0C];
  __O   __PWMC_CMUPD3_bits_t           PWMC_CMUPD3;   /**< Offset: 0x460 ( /W  32) PWMC Channel Mode Update Register (ch_num = 3) */
} pwmc_registers_t;
/** @}  end of Pulse Width Modulation Controller */

#endif /* _PIC32CZ_CA70_PWMC_COMPONENT_H_ */
