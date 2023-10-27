/**
 * \brief Component description for PIC32CZ/CA70 DACC
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
#ifndef _PIC32CZ_CA70_DACC_COMPONENT_H_
#define _PIC32CZ_CA70_DACC_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_DACC Digital-to-Analog Converter Controller
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR DACC */
/* ========================================================================== */

/* -------- DACC_CR : (DACC Offset: 0x00) (/W 32) Control Register -------- */

typedef union
{
  struct
  {
    uint32_t SWRST:1;                   /**< bit:      0  Software Reset                                */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_CR_bits_t;

#define DACC_CR_SWRST_Pos                     (0)                                            /**< (DACC_CR) Software Reset Position */
#define DACC_CR_SWRST_Msk                     (0x1U << DACC_CR_SWRST_Pos)                    /**< (DACC_CR) Software Reset Mask */
#define DACC_CR_Msk                           (0x00000001UL)                                 /**< (DACC_CR) Register Mask  */

/* -------- DACC_MR : (DACC Offset: 0x04) (R/W 32) Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t MAXS0:1;                   /**< bit:      0  Max Speed Mode for Channel 0                  */
    uint32_t MAXS1:1;                   /**< bit:      1  Max Speed Mode for Channel 1                  */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t WORD:1;                    /**< bit:      4  Word Transfer Mode                            */
    uint32_t ZERO:1;                    /**< bit:      5  Must always be written to 0.                  */
    uint32_t :17;                       /**< bit:  6..22  Reserved                                      */
    uint32_t DIFF:1;                    /**< bit:     23  Differential Mode                             */
    uint32_t PRESCALER:4;               /**< bit: 24..27  Peripheral Clock to DAC Clock Ratio           */
    uint32_t :4;                        /**< bit: 28..31  Reserved                                      */
  };
  struct
  {
    uint32_t MAXS:2;                    /**< bit:   0..1  Max Speed Mode for Channel x                  */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_MR_bits_t;

#define DACC_MR_MAXS0_Pos                     (0)                                            /**< (DACC_MR) Max Speed Mode for Channel 0 Position */
#define DACC_MR_MAXS0_Msk                     (0x1U << DACC_MR_MAXS0_Pos)                    /**< (DACC_MR) Max Speed Mode for Channel 0 Mask */
#define   DACC_MR_MAXS0_TRIG_EVENT_Val        (0x0U)                                         /**< (DACC_MR) Trigger mode or Free-running mode enabled. (See TRGENx.DACC_TRIGR.)  */
#define   DACC_MR_MAXS0_MAXIMUM_Val           (0x1U)                                         /**< (DACC_MR) Max speed mode enabled.  */
#define DACC_MR_MAXS0_TRIG_EVENT              (DACC_MR_MAXS0_TRIG_EVENT_Val << DACC_MR_MAXS0_Pos)  /**< (DACC_MR) Trigger mode or Free-running mode enabled. (See TRGENx.DACC_TRIGR.) Position  */
#define DACC_MR_MAXS0_MAXIMUM                 (DACC_MR_MAXS0_MAXIMUM_Val << DACC_MR_MAXS0_Pos)  /**< (DACC_MR) Max speed mode enabled. Position  */
#define DACC_MR_MAXS1_Pos                     (1)                                            /**< (DACC_MR) Max Speed Mode for Channel 1 Position */
#define DACC_MR_MAXS1_Msk                     (0x1U << DACC_MR_MAXS1_Pos)                    /**< (DACC_MR) Max Speed Mode for Channel 1 Mask */
#define   DACC_MR_MAXS1_TRIG_EVENT_Val        (0x0U)                                         /**< (DACC_MR) Trigger mode or Free-running mode enabled. (See TRGENx.DACC_TRIGR.)  */
#define   DACC_MR_MAXS1_MAXIMUM_Val           (0x1U)                                         /**< (DACC_MR) Max speed mode enabled.  */
#define DACC_MR_MAXS1_TRIG_EVENT              (DACC_MR_MAXS1_TRIG_EVENT_Val << DACC_MR_MAXS1_Pos)  /**< (DACC_MR) Trigger mode or Free-running mode enabled. (See TRGENx.DACC_TRIGR.) Position  */
#define DACC_MR_MAXS1_MAXIMUM                 (DACC_MR_MAXS1_MAXIMUM_Val << DACC_MR_MAXS1_Pos)  /**< (DACC_MR) Max speed mode enabled. Position  */
#define DACC_MR_WORD_Pos                      (4)                                            /**< (DACC_MR) Word Transfer Mode Position */
#define DACC_MR_WORD_Msk                      (0x1U << DACC_MR_WORD_Pos)                     /**< (DACC_MR) Word Transfer Mode Mask */
#define   DACC_MR_WORD_DISABLED_Val           (0x0U)                                         /**< (DACC_MR) One data to convert is written to the FIFO per access to DACC.  */
#define   DACC_MR_WORD_ENABLED_Val            (0x1U)                                         /**< (DACC_MR) Two data to convert are written to the FIFO per access to DACC (reduces the number of requests to DMA and the number of system bus accesses).  */
#define DACC_MR_WORD_DISABLED                 (DACC_MR_WORD_DISABLED_Val << DACC_MR_WORD_Pos)  /**< (DACC_MR) One data to convert is written to the FIFO per access to DACC. Position  */
#define DACC_MR_WORD_ENABLED                  (DACC_MR_WORD_ENABLED_Val << DACC_MR_WORD_Pos)  /**< (DACC_MR) Two data to convert are written to the FIFO per access to DACC (reduces the number of requests to DMA and the number of system bus accesses). Position  */
#define DACC_MR_ZERO_Pos                      (5)                                            /**< (DACC_MR) Must always be written to 0. Position */
#define DACC_MR_ZERO_Msk                      (0x1U << DACC_MR_ZERO_Pos)                     /**< (DACC_MR) Must always be written to 0. Mask */
#define DACC_MR_DIFF_Pos                      (23)                                           /**< (DACC_MR) Differential Mode Position */
#define DACC_MR_DIFF_Msk                      (0x1U << DACC_MR_DIFF_Pos)                     /**< (DACC_MR) Differential Mode Mask */
#define   DACC_MR_DIFF_DISABLED_Val           (0x0U)                                         /**< (DACC_MR) DAC0 and DAC1 are single-ended outputs.  */
#define   DACC_MR_DIFF_ENABLED_Val            (0x1U)                                         /**< (DACC_MR) DACP and DACN are differential outputs. The differential level is configured by the channel 0 value.  */
#define DACC_MR_DIFF_DISABLED                 (DACC_MR_DIFF_DISABLED_Val << DACC_MR_DIFF_Pos)  /**< (DACC_MR) DAC0 and DAC1 are single-ended outputs. Position  */
#define DACC_MR_DIFF_ENABLED                  (DACC_MR_DIFF_ENABLED_Val << DACC_MR_DIFF_Pos)  /**< (DACC_MR) DACP and DACN are differential outputs. The differential level is configured by the channel 0 value. Position  */
#define DACC_MR_PRESCALER_Pos                 (24)                                           /**< (DACC_MR) Peripheral Clock to DAC Clock Ratio Position */
#define DACC_MR_PRESCALER_Msk                 (0xFU << DACC_MR_PRESCALER_Pos)                /**< (DACC_MR) Peripheral Clock to DAC Clock Ratio Mask */
#define DACC_MR_PRESCALER(value)              (DACC_MR_PRESCALER_Msk & ((value) << DACC_MR_PRESCALER_Pos))
#define DACC_MR_Msk                           (0x0F800033UL)                                 /**< (DACC_MR) Register Mask  */
#define DACC_MR_MAXS_Pos                      (0)                                            /**< (DACC_MR Position) Max Speed Mode for Channel x */
#define DACC_MR_MAXS_Msk                      (0x3U << DACC_MR_MAXS_Pos)                     /**< (DACC_MR Mask) MAXS */
#define DACC_MR_MAXS(value)                   (DACC_MR_MAXS_Msk & ((value) << DACC_MR_MAXS_Pos))

/* -------- DACC_TRIGR : (DACC Offset: 0x08) (R/W 32) Trigger Register -------- */

typedef union
{
  struct
  {
    uint32_t TRGEN0:1;                  /**< bit:      0  Trigger Enable of Channel 0                   */
    uint32_t TRGEN1:1;                  /**< bit:      1  Trigger Enable of Channel 1                   */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t TRGSEL0:3;                 /**< bit:   4..6  Trigger Selection of Channel 0                */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t TRGSEL1:3;                 /**< bit:  8..10  Trigger Selection of Channel 1                */
    uint32_t :5;                        /**< bit: 11..15  Reserved                                      */
    uint32_t OSR0:3;                    /**< bit: 16..18  Over Sampling Ratio of Channel 0              */
    uint32_t :1;                        /**< bit:     19  Reserved                                      */
    uint32_t OSR1:3;                    /**< bit: 20..22  Over Sampling Ratio of Channel 1              */
    uint32_t :9;                        /**< bit: 23..31  Reserved                                      */
  };
  struct
  {
    uint32_t TRGEN:2;                   /**< bit:   0..1  Trigger Enable of Channel x                   */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_TRIGR_bits_t;

#define DACC_TRIGR_TRGEN0_Pos                 (0)                                            /**< (DACC_TRIGR) Trigger Enable of Channel 0 Position */
#define DACC_TRIGR_TRGEN0_Msk                 (0x1U << DACC_TRIGR_TRGEN0_Pos)                /**< (DACC_TRIGR) Trigger Enable of Channel 0 Mask */
#define   DACC_TRIGR_TRGEN0_DIS_Val           (0x0U)                                         /**< (DACC_TRIGR) Trigger mode disabled. DACC is in Free-running mode or Max speed mode.  */
#define   DACC_TRIGR_TRGEN0_EN_Val            (0x1U)                                         /**< (DACC_TRIGR) Trigger mode enabled.  */
#define DACC_TRIGR_TRGEN0_DIS                 (DACC_TRIGR_TRGEN0_DIS_Val << DACC_TRIGR_TRGEN0_Pos)  /**< (DACC_TRIGR) Trigger mode disabled. DACC is in Free-running mode or Max speed mode. Position  */
#define DACC_TRIGR_TRGEN0_EN                  (DACC_TRIGR_TRGEN0_EN_Val << DACC_TRIGR_TRGEN0_Pos)  /**< (DACC_TRIGR) Trigger mode enabled. Position  */
#define DACC_TRIGR_TRGEN1_Pos                 (1)                                            /**< (DACC_TRIGR) Trigger Enable of Channel 1 Position */
#define DACC_TRIGR_TRGEN1_Msk                 (0x1U << DACC_TRIGR_TRGEN1_Pos)                /**< (DACC_TRIGR) Trigger Enable of Channel 1 Mask */
#define   DACC_TRIGR_TRGEN1_DIS_Val           (0x0U)                                         /**< (DACC_TRIGR) Trigger mode disabled. DACC is in Free-running mode or Max speed mode.  */
#define   DACC_TRIGR_TRGEN1_EN_Val            (0x1U)                                         /**< (DACC_TRIGR) Trigger mode enabled.  */
#define DACC_TRIGR_TRGEN1_DIS                 (DACC_TRIGR_TRGEN1_DIS_Val << DACC_TRIGR_TRGEN1_Pos)  /**< (DACC_TRIGR) Trigger mode disabled. DACC is in Free-running mode or Max speed mode. Position  */
#define DACC_TRIGR_TRGEN1_EN                  (DACC_TRIGR_TRGEN1_EN_Val << DACC_TRIGR_TRGEN1_Pos)  /**< (DACC_TRIGR) Trigger mode enabled. Position  */
#define DACC_TRIGR_TRGSEL0_Pos                (4)                                            /**< (DACC_TRIGR) Trigger Selection of Channel 0 Position */
#define DACC_TRIGR_TRGSEL0_Msk                (0x7U << DACC_TRIGR_TRGSEL0_Pos)               /**< (DACC_TRIGR) Trigger Selection of Channel 0 Mask */
#define DACC_TRIGR_TRGSEL0(value)             (DACC_TRIGR_TRGSEL0_Msk & ((value) << DACC_TRIGR_TRGSEL0_Pos))
#define   DACC_TRIGR_TRGSEL0_TRGSEL0_Val      (0x0U)                                         /**< (DACC_TRIGR) DATRG  */
#define   DACC_TRIGR_TRGSEL0_TRGSEL1_Val      (0x1U)                                         /**< (DACC_TRIGR) TC0 output  */
#define   DACC_TRIGR_TRGSEL0_TRGSEL2_Val      (0x2U)                                         /**< (DACC_TRIGR) TC1 output  */
#define   DACC_TRIGR_TRGSEL0_TRGSEL3_Val      (0x3U)                                         /**< (DACC_TRIGR) TC2 output  */
#define   DACC_TRIGR_TRGSEL0_TRGSEL4_Val      (0x4U)                                         /**< (DACC_TRIGR) PWM0 event 0  */
#define   DACC_TRIGR_TRGSEL0_TRGSEL5_Val      (0x5U)                                         /**< (DACC_TRIGR) PWM0 event 1  */
#define   DACC_TRIGR_TRGSEL0_TRGSEL6_Val      (0x6U)                                         /**< (DACC_TRIGR) PWM1 event 0  */
#define   DACC_TRIGR_TRGSEL0_TRGSEL7_Val      (0x7U)                                         /**< (DACC_TRIGR) PWM1 event 1  */
#define DACC_TRIGR_TRGSEL0_TRGSEL0            (DACC_TRIGR_TRGSEL0_TRGSEL0_Val << DACC_TRIGR_TRGSEL0_Pos)  /**< (DACC_TRIGR) DATRG Position  */
#define DACC_TRIGR_TRGSEL0_TRGSEL1            (DACC_TRIGR_TRGSEL0_TRGSEL1_Val << DACC_TRIGR_TRGSEL0_Pos)  /**< (DACC_TRIGR) TC0 output Position  */
#define DACC_TRIGR_TRGSEL0_TRGSEL2            (DACC_TRIGR_TRGSEL0_TRGSEL2_Val << DACC_TRIGR_TRGSEL0_Pos)  /**< (DACC_TRIGR) TC1 output Position  */
#define DACC_TRIGR_TRGSEL0_TRGSEL3            (DACC_TRIGR_TRGSEL0_TRGSEL3_Val << DACC_TRIGR_TRGSEL0_Pos)  /**< (DACC_TRIGR) TC2 output Position  */
#define DACC_TRIGR_TRGSEL0_TRGSEL4            (DACC_TRIGR_TRGSEL0_TRGSEL4_Val << DACC_TRIGR_TRGSEL0_Pos)  /**< (DACC_TRIGR) PWM0 event 0 Position  */
#define DACC_TRIGR_TRGSEL0_TRGSEL5            (DACC_TRIGR_TRGSEL0_TRGSEL5_Val << DACC_TRIGR_TRGSEL0_Pos)  /**< (DACC_TRIGR) PWM0 event 1 Position  */
#define DACC_TRIGR_TRGSEL0_TRGSEL6            (DACC_TRIGR_TRGSEL0_TRGSEL6_Val << DACC_TRIGR_TRGSEL0_Pos)  /**< (DACC_TRIGR) PWM1 event 0 Position  */
#define DACC_TRIGR_TRGSEL0_TRGSEL7            (DACC_TRIGR_TRGSEL0_TRGSEL7_Val << DACC_TRIGR_TRGSEL0_Pos)  /**< (DACC_TRIGR) PWM1 event 1 Position  */
#define DACC_TRIGR_TRGSEL1_Pos                (8)                                            /**< (DACC_TRIGR) Trigger Selection of Channel 1 Position */
#define DACC_TRIGR_TRGSEL1_Msk                (0x7U << DACC_TRIGR_TRGSEL1_Pos)               /**< (DACC_TRIGR) Trigger Selection of Channel 1 Mask */
#define DACC_TRIGR_TRGSEL1(value)             (DACC_TRIGR_TRGSEL1_Msk & ((value) << DACC_TRIGR_TRGSEL1_Pos))
#define   DACC_TRIGR_TRGSEL1_TRGSEL0_Val      (0x0U)                                         /**< (DACC_TRIGR) DATRG  */
#define   DACC_TRIGR_TRGSEL1_TRGSEL1_Val      (0x1U)                                         /**< (DACC_TRIGR) TC0 output  */
#define   DACC_TRIGR_TRGSEL1_TRGSEL2_Val      (0x2U)                                         /**< (DACC_TRIGR) TC1 output  */
#define   DACC_TRIGR_TRGSEL1_TRGSEL3_Val      (0x3U)                                         /**< (DACC_TRIGR) TC2 output  */
#define   DACC_TRIGR_TRGSEL1_TRGSEL4_Val      (0x4U)                                         /**< (DACC_TRIGR) PWM0 event 0  */
#define   DACC_TRIGR_TRGSEL1_TRGSEL5_Val      (0x5U)                                         /**< (DACC_TRIGR) PWM0 event 1  */
#define   DACC_TRIGR_TRGSEL1_TRGSEL6_Val      (0x6U)                                         /**< (DACC_TRIGR) PWM1 event 0  */
#define   DACC_TRIGR_TRGSEL1_TRGSEL7_Val      (0x7U)                                         /**< (DACC_TRIGR) PWM1 event 1  */
#define DACC_TRIGR_TRGSEL1_TRGSEL0            (DACC_TRIGR_TRGSEL1_TRGSEL0_Val << DACC_TRIGR_TRGSEL1_Pos)  /**< (DACC_TRIGR) DATRG Position  */
#define DACC_TRIGR_TRGSEL1_TRGSEL1            (DACC_TRIGR_TRGSEL1_TRGSEL1_Val << DACC_TRIGR_TRGSEL1_Pos)  /**< (DACC_TRIGR) TC0 output Position  */
#define DACC_TRIGR_TRGSEL1_TRGSEL2            (DACC_TRIGR_TRGSEL1_TRGSEL2_Val << DACC_TRIGR_TRGSEL1_Pos)  /**< (DACC_TRIGR) TC1 output Position  */
#define DACC_TRIGR_TRGSEL1_TRGSEL3            (DACC_TRIGR_TRGSEL1_TRGSEL3_Val << DACC_TRIGR_TRGSEL1_Pos)  /**< (DACC_TRIGR) TC2 output Position  */
#define DACC_TRIGR_TRGSEL1_TRGSEL4            (DACC_TRIGR_TRGSEL1_TRGSEL4_Val << DACC_TRIGR_TRGSEL1_Pos)  /**< (DACC_TRIGR) PWM0 event 0 Position  */
#define DACC_TRIGR_TRGSEL1_TRGSEL5            (DACC_TRIGR_TRGSEL1_TRGSEL5_Val << DACC_TRIGR_TRGSEL1_Pos)  /**< (DACC_TRIGR) PWM0 event 1 Position  */
#define DACC_TRIGR_TRGSEL1_TRGSEL6            (DACC_TRIGR_TRGSEL1_TRGSEL6_Val << DACC_TRIGR_TRGSEL1_Pos)  /**< (DACC_TRIGR) PWM1 event 0 Position  */
#define DACC_TRIGR_TRGSEL1_TRGSEL7            (DACC_TRIGR_TRGSEL1_TRGSEL7_Val << DACC_TRIGR_TRGSEL1_Pos)  /**< (DACC_TRIGR) PWM1 event 1 Position  */
#define DACC_TRIGR_OSR0_Pos                   (16)                                           /**< (DACC_TRIGR) Over Sampling Ratio of Channel 0 Position */
#define DACC_TRIGR_OSR0_Msk                   (0x7U << DACC_TRIGR_OSR0_Pos)                  /**< (DACC_TRIGR) Over Sampling Ratio of Channel 0 Mask */
#define DACC_TRIGR_OSR0(value)                (DACC_TRIGR_OSR0_Msk & ((value) << DACC_TRIGR_OSR0_Pos))
#define   DACC_TRIGR_OSR0_OSR_1_Val           (0x0U)                                         /**< (DACC_TRIGR) OSR = 1  */
#define   DACC_TRIGR_OSR0_OSR_2_Val           (0x1U)                                         /**< (DACC_TRIGR) OSR = 2  */
#define   DACC_TRIGR_OSR0_OSR_4_Val           (0x2U)                                         /**< (DACC_TRIGR) OSR = 4  */
#define   DACC_TRIGR_OSR0_OSR_8_Val           (0x3U)                                         /**< (DACC_TRIGR) OSR = 8  */
#define   DACC_TRIGR_OSR0_OSR_16_Val          (0x4U)                                         /**< (DACC_TRIGR) OSR = 16  */
#define   DACC_TRIGR_OSR0_OSR_32_Val          (0x5U)                                         /**< (DACC_TRIGR) OSR = 32  */
#define DACC_TRIGR_OSR0_OSR_1                 (DACC_TRIGR_OSR0_OSR_1_Val << DACC_TRIGR_OSR0_Pos)  /**< (DACC_TRIGR) OSR = 1 Position  */
#define DACC_TRIGR_OSR0_OSR_2                 (DACC_TRIGR_OSR0_OSR_2_Val << DACC_TRIGR_OSR0_Pos)  /**< (DACC_TRIGR) OSR = 2 Position  */
#define DACC_TRIGR_OSR0_OSR_4                 (DACC_TRIGR_OSR0_OSR_4_Val << DACC_TRIGR_OSR0_Pos)  /**< (DACC_TRIGR) OSR = 4 Position  */
#define DACC_TRIGR_OSR0_OSR_8                 (DACC_TRIGR_OSR0_OSR_8_Val << DACC_TRIGR_OSR0_Pos)  /**< (DACC_TRIGR) OSR = 8 Position  */
#define DACC_TRIGR_OSR0_OSR_16                (DACC_TRIGR_OSR0_OSR_16_Val << DACC_TRIGR_OSR0_Pos)  /**< (DACC_TRIGR) OSR = 16 Position  */
#define DACC_TRIGR_OSR0_OSR_32                (DACC_TRIGR_OSR0_OSR_32_Val << DACC_TRIGR_OSR0_Pos)  /**< (DACC_TRIGR) OSR = 32 Position  */
#define DACC_TRIGR_OSR1_Pos                   (20)                                           /**< (DACC_TRIGR) Over Sampling Ratio of Channel 1 Position */
#define DACC_TRIGR_OSR1_Msk                   (0x7U << DACC_TRIGR_OSR1_Pos)                  /**< (DACC_TRIGR) Over Sampling Ratio of Channel 1 Mask */
#define DACC_TRIGR_OSR1(value)                (DACC_TRIGR_OSR1_Msk & ((value) << DACC_TRIGR_OSR1_Pos))
#define   DACC_TRIGR_OSR1_OSR_1_Val           (0x0U)                                         /**< (DACC_TRIGR) OSR = 1  */
#define   DACC_TRIGR_OSR1_OSR_2_Val           (0x1U)                                         /**< (DACC_TRIGR) OSR = 2  */
#define   DACC_TRIGR_OSR1_OSR_4_Val           (0x2U)                                         /**< (DACC_TRIGR) OSR = 4  */
#define   DACC_TRIGR_OSR1_OSR_8_Val           (0x3U)                                         /**< (DACC_TRIGR) OSR = 8  */
#define   DACC_TRIGR_OSR1_OSR_16_Val          (0x4U)                                         /**< (DACC_TRIGR) OSR = 16  */
#define   DACC_TRIGR_OSR1_OSR_32_Val          (0x5U)                                         /**< (DACC_TRIGR) OSR = 32  */
#define DACC_TRIGR_OSR1_OSR_1                 (DACC_TRIGR_OSR1_OSR_1_Val << DACC_TRIGR_OSR1_Pos)  /**< (DACC_TRIGR) OSR = 1 Position  */
#define DACC_TRIGR_OSR1_OSR_2                 (DACC_TRIGR_OSR1_OSR_2_Val << DACC_TRIGR_OSR1_Pos)  /**< (DACC_TRIGR) OSR = 2 Position  */
#define DACC_TRIGR_OSR1_OSR_4                 (DACC_TRIGR_OSR1_OSR_4_Val << DACC_TRIGR_OSR1_Pos)  /**< (DACC_TRIGR) OSR = 4 Position  */
#define DACC_TRIGR_OSR1_OSR_8                 (DACC_TRIGR_OSR1_OSR_8_Val << DACC_TRIGR_OSR1_Pos)  /**< (DACC_TRIGR) OSR = 8 Position  */
#define DACC_TRIGR_OSR1_OSR_16                (DACC_TRIGR_OSR1_OSR_16_Val << DACC_TRIGR_OSR1_Pos)  /**< (DACC_TRIGR) OSR = 16 Position  */
#define DACC_TRIGR_OSR1_OSR_32                (DACC_TRIGR_OSR1_OSR_32_Val << DACC_TRIGR_OSR1_Pos)  /**< (DACC_TRIGR) OSR = 32 Position  */
#define DACC_TRIGR_Msk                        (0x00770773UL)                                 /**< (DACC_TRIGR) Register Mask  */
#define DACC_TRIGR_TRGEN_Pos                  (0)                                            /**< (DACC_TRIGR Position) Trigger Enable of Channel x */
#define DACC_TRIGR_TRGEN_Msk                  (0x3U << DACC_TRIGR_TRGEN_Pos)                 /**< (DACC_TRIGR Mask) TRGEN */
#define DACC_TRIGR_TRGEN(value)               (DACC_TRIGR_TRGEN_Msk & ((value) << DACC_TRIGR_TRGEN_Pos))

/* -------- DACC_CHER : (DACC Offset: 0x10) (/W 32) Channel Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t CH0:1;                     /**< bit:      0  Channel 0 Enable                              */
    uint32_t CH1:1;                     /**< bit:      1  Channel 1 Enable                              */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  struct
  {
    uint32_t CH:2;                      /**< bit:   0..1  Channel x Enable                              */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_CHER_bits_t;

#define DACC_CHER_CH0_Pos                     (0)                                            /**< (DACC_CHER) Channel 0 Enable Position */
#define DACC_CHER_CH0_Msk                     (0x1U << DACC_CHER_CH0_Pos)                    /**< (DACC_CHER) Channel 0 Enable Mask */
#define DACC_CHER_CH1_Pos                     (1)                                            /**< (DACC_CHER) Channel 1 Enable Position */
#define DACC_CHER_CH1_Msk                     (0x1U << DACC_CHER_CH1_Pos)                    /**< (DACC_CHER) Channel 1 Enable Mask */
#define DACC_CHER_Msk                         (0x00000003UL)                                 /**< (DACC_CHER) Register Mask  */
#define DACC_CHER_CH_Pos                      (0)                                            /**< (DACC_CHER Position) Channel x Enable */
#define DACC_CHER_CH_Msk                      (0x3U << DACC_CHER_CH_Pos)                     /**< (DACC_CHER Mask) CH */
#define DACC_CHER_CH(value)                   (DACC_CHER_CH_Msk & ((value) << DACC_CHER_CH_Pos))

/* -------- DACC_CHDR : (DACC Offset: 0x14) (/W 32) Channel Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t CH0:1;                     /**< bit:      0  Channel 0 Disable                             */
    uint32_t CH1:1;                     /**< bit:      1  Channel 1 Disable                             */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  struct
  {
    uint32_t CH:2;                      /**< bit:   0..1  Channel x Disable                             */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_CHDR_bits_t;

#define DACC_CHDR_CH0_Pos                     (0)                                            /**< (DACC_CHDR) Channel 0 Disable Position */
#define DACC_CHDR_CH0_Msk                     (0x1U << DACC_CHDR_CH0_Pos)                    /**< (DACC_CHDR) Channel 0 Disable Mask */
#define DACC_CHDR_CH1_Pos                     (1)                                            /**< (DACC_CHDR) Channel 1 Disable Position */
#define DACC_CHDR_CH1_Msk                     (0x1U << DACC_CHDR_CH1_Pos)                    /**< (DACC_CHDR) Channel 1 Disable Mask */
#define DACC_CHDR_Msk                         (0x00000003UL)                                 /**< (DACC_CHDR) Register Mask  */
#define DACC_CHDR_CH_Pos                      (0)                                            /**< (DACC_CHDR Position) Channel x Disable */
#define DACC_CHDR_CH_Msk                      (0x3U << DACC_CHDR_CH_Pos)                     /**< (DACC_CHDR Mask) CH */
#define DACC_CHDR_CH(value)                   (DACC_CHDR_CH_Msk & ((value) << DACC_CHDR_CH_Pos))

/* -------- DACC_CHSR : (DACC Offset: 0x18) (R/ 32) Channel Status Register -------- */

typedef union
{
  struct
  {
    uint32_t CH0:1;                     /**< bit:      0  Channel 0 Status                              */
    uint32_t CH1:1;                     /**< bit:      1  Channel 1 Status                              */
    uint32_t :6;                        /**< bit:   2..7  Reserved                                      */
    uint32_t DACRDY0:1;                 /**< bit:      8  DAC Ready Flag                                */
    uint32_t DACRDY1:1;                 /**< bit:      9  DAC Ready Flag                                */
    uint32_t :22;                       /**< bit: 10..31  Reserved                                      */
  };
  struct
  {
    uint32_t CH:2;                      /**< bit:   0..1  Channel x Status                              */
    uint32_t :6;                        /**< bit:   2..7  Reserved                                      */
    uint32_t DACRDY:2;                  /**< bit:   8..9  DAC Ready Flag                                */
    uint32_t :22;                       /**< bit: 10..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_CHSR_bits_t;

#define DACC_CHSR_CH0_Pos                     (0)                                            /**< (DACC_CHSR) Channel 0 Status Position */
#define DACC_CHSR_CH0_Msk                     (0x1U << DACC_CHSR_CH0_Pos)                    /**< (DACC_CHSR) Channel 0 Status Mask */
#define DACC_CHSR_CH1_Pos                     (1)                                            /**< (DACC_CHSR) Channel 1 Status Position */
#define DACC_CHSR_CH1_Msk                     (0x1U << DACC_CHSR_CH1_Pos)                    /**< (DACC_CHSR) Channel 1 Status Mask */
#define DACC_CHSR_DACRDY0_Pos                 (8)                                            /**< (DACC_CHSR) DAC Ready Flag Position */
#define DACC_CHSR_DACRDY0_Msk                 (0x1U << DACC_CHSR_DACRDY0_Pos)                /**< (DACC_CHSR) DAC Ready Flag Mask */
#define DACC_CHSR_DACRDY1_Pos                 (9)                                            /**< (DACC_CHSR) DAC Ready Flag Position */
#define DACC_CHSR_DACRDY1_Msk                 (0x1U << DACC_CHSR_DACRDY1_Pos)                /**< (DACC_CHSR) DAC Ready Flag Mask */
#define DACC_CHSR_Msk                         (0x00000303UL)                                 /**< (DACC_CHSR) Register Mask  */
#define DACC_CHSR_CH_Pos                      (0)                                            /**< (DACC_CHSR Position) Channel x Status */
#define DACC_CHSR_CH_Msk                      (0x3U << DACC_CHSR_CH_Pos)                     /**< (DACC_CHSR Mask) CH */
#define DACC_CHSR_CH(value)                   (DACC_CHSR_CH_Msk & ((value) << DACC_CHSR_CH_Pos))
#define DACC_CHSR_DACRDY_Pos                  (8)                                            /**< (DACC_CHSR Position) DAC Ready Flag */
#define DACC_CHSR_DACRDY_Msk                  (0x3U << DACC_CHSR_DACRDY_Pos)                 /**< (DACC_CHSR Mask) DACRDY */
#define DACC_CHSR_DACRDY(value)               (DACC_CHSR_DACRDY_Msk & ((value) << DACC_CHSR_DACRDY_Pos))

/* -------- DACC_CDR : (DACC Offset: 0x1c) (/W 32) Conversion Data Register 0 -------- */

typedef union
{
  struct
  {
    uint32_t DATA0:16;                  /**< bit:  0..15  Data to Convert for channel 0                 */
    uint32_t DATA1:16;                  /**< bit: 16..31  Data to Convert for channel 1                 */
  };
  uint32_t w;
} __DACC_CDR_bits_t;

#define DACC_CDR_DATA0_Pos                    (0)                                            /**< (DACC_CDR) Data to Convert for channel 0 Position */
#define DACC_CDR_DATA0_Msk                    (0xFFFFU << DACC_CDR_DATA0_Pos)                /**< (DACC_CDR) Data to Convert for channel 0 Mask */
#define DACC_CDR_DATA0(value)                 (DACC_CDR_DATA0_Msk & ((value) << DACC_CDR_DATA0_Pos))
#define DACC_CDR_DATA1_Pos                    (16)                                           /**< (DACC_CDR) Data to Convert for channel 1 Position */
#define DACC_CDR_DATA1_Msk                    (0xFFFFU << DACC_CDR_DATA1_Pos)                /**< (DACC_CDR) Data to Convert for channel 1 Mask */
#define DACC_CDR_DATA1(value)                 (DACC_CDR_DATA1_Msk & ((value) << DACC_CDR_DATA1_Pos))
#define DACC_CDR_Msk                          (0xFFFFFFFFUL)                                 /**< (DACC_CDR) Register Mask  */

/* -------- DACC_IER : (DACC Offset: 0x24) (/W 32) Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t TXRDY0:1;                  /**< bit:      0  Transmit Ready Interrupt Enable of channel 0  */
    uint32_t TXRDY1:1;                  /**< bit:      1  Transmit Ready Interrupt Enable of channel 1  */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t EOC0:1;                    /**< bit:      4  End of Conversion Interrupt Enable of channel 0 */
    uint32_t EOC1:1;                    /**< bit:      5  End of Conversion Interrupt Enable of channel 1 */
    uint32_t :26;                       /**< bit:  6..31  Reserved                                      */
  };
  struct
  {
    uint32_t TXRDY:2;                   /**< bit:   0..1  Transmit Ready Interrupt Enable of channel x  */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t EOC:2;                     /**< bit:   4..5  End of Conversion Interrupt Enable of channel x */
    uint32_t :26;                       /**< bit:  6..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_IER_bits_t;

#define DACC_IER_TXRDY0_Pos                   (0)                                            /**< (DACC_IER) Transmit Ready Interrupt Enable of channel 0 Position */
#define DACC_IER_TXRDY0_Msk                   (0x1U << DACC_IER_TXRDY0_Pos)                  /**< (DACC_IER) Transmit Ready Interrupt Enable of channel 0 Mask */
#define DACC_IER_TXRDY1_Pos                   (1)                                            /**< (DACC_IER) Transmit Ready Interrupt Enable of channel 1 Position */
#define DACC_IER_TXRDY1_Msk                   (0x1U << DACC_IER_TXRDY1_Pos)                  /**< (DACC_IER) Transmit Ready Interrupt Enable of channel 1 Mask */
#define DACC_IER_EOC0_Pos                     (4)                                            /**< (DACC_IER) End of Conversion Interrupt Enable of channel 0 Position */
#define DACC_IER_EOC0_Msk                     (0x1U << DACC_IER_EOC0_Pos)                    /**< (DACC_IER) End of Conversion Interrupt Enable of channel 0 Mask */
#define DACC_IER_EOC1_Pos                     (5)                                            /**< (DACC_IER) End of Conversion Interrupt Enable of channel 1 Position */
#define DACC_IER_EOC1_Msk                     (0x1U << DACC_IER_EOC1_Pos)                    /**< (DACC_IER) End of Conversion Interrupt Enable of channel 1 Mask */
#define DACC_IER_Msk                          (0x00000033UL)                                 /**< (DACC_IER) Register Mask  */
#define DACC_IER_TXRDY_Pos                    (0)                                            /**< (DACC_IER Position) Transmit Ready Interrupt Enable of channel x */
#define DACC_IER_TXRDY_Msk                    (0x3U << DACC_IER_TXRDY_Pos)                   /**< (DACC_IER Mask) TXRDY */
#define DACC_IER_TXRDY(value)                 (DACC_IER_TXRDY_Msk & ((value) << DACC_IER_TXRDY_Pos))
#define DACC_IER_EOC_Pos                      (4)                                            /**< (DACC_IER Position) End of Conversion Interrupt Enable of channel x */
#define DACC_IER_EOC_Msk                      (0x3U << DACC_IER_EOC_Pos)                     /**< (DACC_IER Mask) EOC */
#define DACC_IER_EOC(value)                   (DACC_IER_EOC_Msk & ((value) << DACC_IER_EOC_Pos))

/* -------- DACC_IDR : (DACC Offset: 0x28) (/W 32) Interrupt Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t TXRDY0:1;                  /**< bit:      0  Transmit Ready Interrupt Disable of channel 0 */
    uint32_t TXRDY1:1;                  /**< bit:      1  Transmit Ready Interrupt Disable of channel 1 */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t EOC0:1;                    /**< bit:      4  End of Conversion Interrupt Disable of channel 0 */
    uint32_t EOC1:1;                    /**< bit:      5  End of Conversion Interrupt Disable of channel 1 */
    uint32_t :26;                       /**< bit:  6..31  Reserved                                      */
  };
  struct
  {
    uint32_t TXRDY:2;                   /**< bit:   0..1  Transmit Ready Interrupt Disable of channel x */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t EOC:2;                     /**< bit:   4..5  End of Conversion Interrupt Disable of channel x */
    uint32_t :26;                       /**< bit:  6..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_IDR_bits_t;

#define DACC_IDR_TXRDY0_Pos                   (0)                                            /**< (DACC_IDR) Transmit Ready Interrupt Disable of channel 0 Position */
#define DACC_IDR_TXRDY0_Msk                   (0x1U << DACC_IDR_TXRDY0_Pos)                  /**< (DACC_IDR) Transmit Ready Interrupt Disable of channel 0 Mask */
#define DACC_IDR_TXRDY1_Pos                   (1)                                            /**< (DACC_IDR) Transmit Ready Interrupt Disable of channel 1 Position */
#define DACC_IDR_TXRDY1_Msk                   (0x1U << DACC_IDR_TXRDY1_Pos)                  /**< (DACC_IDR) Transmit Ready Interrupt Disable of channel 1 Mask */
#define DACC_IDR_EOC0_Pos                     (4)                                            /**< (DACC_IDR) End of Conversion Interrupt Disable of channel 0 Position */
#define DACC_IDR_EOC0_Msk                     (0x1U << DACC_IDR_EOC0_Pos)                    /**< (DACC_IDR) End of Conversion Interrupt Disable of channel 0 Mask */
#define DACC_IDR_EOC1_Pos                     (5)                                            /**< (DACC_IDR) End of Conversion Interrupt Disable of channel 1 Position */
#define DACC_IDR_EOC1_Msk                     (0x1U << DACC_IDR_EOC1_Pos)                    /**< (DACC_IDR) End of Conversion Interrupt Disable of channel 1 Mask */
#define DACC_IDR_Msk                          (0x00000033UL)                                 /**< (DACC_IDR) Register Mask  */
#define DACC_IDR_TXRDY_Pos                    (0)                                            /**< (DACC_IDR Position) Transmit Ready Interrupt Disable of channel x */
#define DACC_IDR_TXRDY_Msk                    (0x3U << DACC_IDR_TXRDY_Pos)                   /**< (DACC_IDR Mask) TXRDY */
#define DACC_IDR_TXRDY(value)                 (DACC_IDR_TXRDY_Msk & ((value) << DACC_IDR_TXRDY_Pos))
#define DACC_IDR_EOC_Pos                      (4)                                            /**< (DACC_IDR Position) End of Conversion Interrupt Disable of channel x */
#define DACC_IDR_EOC_Msk                      (0x3U << DACC_IDR_EOC_Pos)                     /**< (DACC_IDR Mask) EOC */
#define DACC_IDR_EOC(value)                   (DACC_IDR_EOC_Msk & ((value) << DACC_IDR_EOC_Pos))

/* -------- DACC_IMR : (DACC Offset: 0x2c) (R/ 32) Interrupt Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t TXRDY0:1;                  /**< bit:      0  Transmit Ready Interrupt Mask of channel 0    */
    uint32_t TXRDY1:1;                  /**< bit:      1  Transmit Ready Interrupt Mask of channel 1    */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t EOC0:1;                    /**< bit:      4  End of Conversion Interrupt Mask of channel 0 */
    uint32_t EOC1:1;                    /**< bit:      5  End of Conversion Interrupt Mask of channel 1 */
    uint32_t :26;                       /**< bit:  6..31  Reserved                                      */
  };
  struct
  {
    uint32_t TXRDY:2;                   /**< bit:   0..1  Transmit Ready Interrupt Mask of channel x    */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t EOC:2;                     /**< bit:   4..5  End of Conversion Interrupt Mask of channel x */
    uint32_t :26;                       /**< bit:  6..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_IMR_bits_t;

#define DACC_IMR_TXRDY0_Pos                   (0)                                            /**< (DACC_IMR) Transmit Ready Interrupt Mask of channel 0 Position */
#define DACC_IMR_TXRDY0_Msk                   (0x1U << DACC_IMR_TXRDY0_Pos)                  /**< (DACC_IMR) Transmit Ready Interrupt Mask of channel 0 Mask */
#define DACC_IMR_TXRDY1_Pos                   (1)                                            /**< (DACC_IMR) Transmit Ready Interrupt Mask of channel 1 Position */
#define DACC_IMR_TXRDY1_Msk                   (0x1U << DACC_IMR_TXRDY1_Pos)                  /**< (DACC_IMR) Transmit Ready Interrupt Mask of channel 1 Mask */
#define DACC_IMR_EOC0_Pos                     (4)                                            /**< (DACC_IMR) End of Conversion Interrupt Mask of channel 0 Position */
#define DACC_IMR_EOC0_Msk                     (0x1U << DACC_IMR_EOC0_Pos)                    /**< (DACC_IMR) End of Conversion Interrupt Mask of channel 0 Mask */
#define DACC_IMR_EOC1_Pos                     (5)                                            /**< (DACC_IMR) End of Conversion Interrupt Mask of channel 1 Position */
#define DACC_IMR_EOC1_Msk                     (0x1U << DACC_IMR_EOC1_Pos)                    /**< (DACC_IMR) End of Conversion Interrupt Mask of channel 1 Mask */
#define DACC_IMR_Msk                          (0x00000033UL)                                 /**< (DACC_IMR) Register Mask  */
#define DACC_IMR_TXRDY_Pos                    (0)                                            /**< (DACC_IMR Position) Transmit Ready Interrupt Mask of channel x */
#define DACC_IMR_TXRDY_Msk                    (0x3U << DACC_IMR_TXRDY_Pos)                   /**< (DACC_IMR Mask) TXRDY */
#define DACC_IMR_TXRDY(value)                 (DACC_IMR_TXRDY_Msk & ((value) << DACC_IMR_TXRDY_Pos))
#define DACC_IMR_EOC_Pos                      (4)                                            /**< (DACC_IMR Position) End of Conversion Interrupt Mask of channel x */
#define DACC_IMR_EOC_Msk                      (0x3U << DACC_IMR_EOC_Pos)                     /**< (DACC_IMR Mask) EOC */
#define DACC_IMR_EOC(value)                   (DACC_IMR_EOC_Msk & ((value) << DACC_IMR_EOC_Pos))

/* -------- DACC_ISR : (DACC Offset: 0x30) (R/ 32) Interrupt Status Register -------- */

typedef union
{
  struct
  {
    uint32_t TXRDY0:1;                  /**< bit:      0  Transmit Ready Interrupt Flag of channel 0    */
    uint32_t TXRDY1:1;                  /**< bit:      1  Transmit Ready Interrupt Flag of channel 1    */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t EOC0:1;                    /**< bit:      4  End of Conversion Interrupt Flag of channel 0 */
    uint32_t EOC1:1;                    /**< bit:      5  End of Conversion Interrupt Flag of channel 1 */
    uint32_t :26;                       /**< bit:  6..31  Reserved                                      */
  };
  struct
  {
    uint32_t TXRDY:2;                   /**< bit:   0..1  Transmit Ready Interrupt Flag of channel x    */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t EOC:2;                     /**< bit:   4..5  End of Conversion Interrupt Flag of channel x */
    uint32_t :26;                       /**< bit:  6..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_ISR_bits_t;

#define DACC_ISR_TXRDY0_Pos                   (0)                                            /**< (DACC_ISR) Transmit Ready Interrupt Flag of channel 0 Position */
#define DACC_ISR_TXRDY0_Msk                   (0x1U << DACC_ISR_TXRDY0_Pos)                  /**< (DACC_ISR) Transmit Ready Interrupt Flag of channel 0 Mask */
#define DACC_ISR_TXRDY1_Pos                   (1)                                            /**< (DACC_ISR) Transmit Ready Interrupt Flag of channel 1 Position */
#define DACC_ISR_TXRDY1_Msk                   (0x1U << DACC_ISR_TXRDY1_Pos)                  /**< (DACC_ISR) Transmit Ready Interrupt Flag of channel 1 Mask */
#define DACC_ISR_EOC0_Pos                     (4)                                            /**< (DACC_ISR) End of Conversion Interrupt Flag of channel 0 Position */
#define DACC_ISR_EOC0_Msk                     (0x1U << DACC_ISR_EOC0_Pos)                    /**< (DACC_ISR) End of Conversion Interrupt Flag of channel 0 Mask */
#define DACC_ISR_EOC1_Pos                     (5)                                            /**< (DACC_ISR) End of Conversion Interrupt Flag of channel 1 Position */
#define DACC_ISR_EOC1_Msk                     (0x1U << DACC_ISR_EOC1_Pos)                    /**< (DACC_ISR) End of Conversion Interrupt Flag of channel 1 Mask */
#define DACC_ISR_Msk                          (0x00000033UL)                                 /**< (DACC_ISR) Register Mask  */
#define DACC_ISR_TXRDY_Pos                    (0)                                            /**< (DACC_ISR Position) Transmit Ready Interrupt Flag of channel x */
#define DACC_ISR_TXRDY_Msk                    (0x3U << DACC_ISR_TXRDY_Pos)                   /**< (DACC_ISR Mask) TXRDY */
#define DACC_ISR_TXRDY(value)                 (DACC_ISR_TXRDY_Msk & ((value) << DACC_ISR_TXRDY_Pos))
#define DACC_ISR_EOC_Pos                      (4)                                            /**< (DACC_ISR Position) End of Conversion Interrupt Flag of channel x */
#define DACC_ISR_EOC_Msk                      (0x3U << DACC_ISR_EOC_Pos)                     /**< (DACC_ISR Mask) EOC */
#define DACC_ISR_EOC(value)                   (DACC_ISR_EOC_Msk & ((value) << DACC_ISR_EOC_Pos))

/* -------- DACC_ACR : (DACC Offset: 0x94) (R/W 32) Analog Current Register -------- */

typedef union
{
  struct
  {
    uint32_t IBCTLCH0:2;                /**< bit:   0..1  Analog Output Current Control                 */
    uint32_t IBCTLCH1:2;                /**< bit:   2..3  Analog Output Current Control                 */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_ACR_bits_t;

#define DACC_ACR_IBCTLCH0_Pos                 (0)                                            /**< (DACC_ACR) Analog Output Current Control Position */
#define DACC_ACR_IBCTLCH0_Msk                 (0x3U << DACC_ACR_IBCTLCH0_Pos)                /**< (DACC_ACR) Analog Output Current Control Mask */
#define DACC_ACR_IBCTLCH0(value)              (DACC_ACR_IBCTLCH0_Msk & ((value) << DACC_ACR_IBCTLCH0_Pos))
#define DACC_ACR_IBCTLCH1_Pos                 (2)                                            /**< (DACC_ACR) Analog Output Current Control Position */
#define DACC_ACR_IBCTLCH1_Msk                 (0x3U << DACC_ACR_IBCTLCH1_Pos)                /**< (DACC_ACR) Analog Output Current Control Mask */
#define DACC_ACR_IBCTLCH1(value)              (DACC_ACR_IBCTLCH1_Msk & ((value) << DACC_ACR_IBCTLCH1_Pos))
#define DACC_ACR_Msk                          (0x0000000FUL)                                 /**< (DACC_ACR) Register Mask  */

/* -------- DACC_WPMR : (DACC Offset: 0xe4) (R/W 32) Write Protection Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t WPEN:1;                    /**< bit:      0  Write Protection Enable                       */
    uint32_t :7;                        /**< bit:   1..7  Reserved                                      */
    uint32_t WPKEY:24;                  /**< bit:  8..31  Write Protect Key                             */
  };
  uint32_t w;
} __DACC_WPMR_bits_t;

#define DACC_WPMR_WPEN_Pos                    (0)                                            /**< (DACC_WPMR) Write Protection Enable Position */
#define DACC_WPMR_WPEN_Msk                    (0x1U << DACC_WPMR_WPEN_Pos)                   /**< (DACC_WPMR) Write Protection Enable Mask */
#define DACC_WPMR_WPKEY_Pos                   (8)                                            /**< (DACC_WPMR) Write Protect Key Position */
#define DACC_WPMR_WPKEY_Msk                   (0xFFFFFFU << DACC_WPMR_WPKEY_Pos)             /**< (DACC_WPMR) Write Protect Key Mask */
#define DACC_WPMR_WPKEY(value)                (DACC_WPMR_WPKEY_Msk & ((value) << DACC_WPMR_WPKEY_Pos))
#define   DACC_WPMR_WPKEY_PASSWD_Val          (0x444143U)                                    /**< (DACC_WPMR) Writing any other value in this field aborts the write operation of bit WPEN.Always reads as 0.  */
#define DACC_WPMR_WPKEY_PASSWD                (DACC_WPMR_WPKEY_PASSWD_Val << DACC_WPMR_WPKEY_Pos)  /**< (DACC_WPMR) Writing any other value in this field aborts the write operation of bit WPEN.Always reads as 0. Position  */
#define DACC_WPMR_Msk                         (0xFFFFFF01UL)                                 /**< (DACC_WPMR) Register Mask  */

/* -------- DACC_WPSR : (DACC Offset: 0xe8) (R/ 32) Write Protection Status Register -------- */

typedef union
{
  struct
  {
    uint32_t WPVS:1;                    /**< bit:      0  Write Protection Violation Status             */
    uint32_t :7;                        /**< bit:   1..7  Reserved                                      */
    uint32_t WPVSRC:8;                  /**< bit:  8..15  Write Protection Violation Source             */
    uint32_t :16;                       /**< bit: 16..31  Reserved                                      */
  };
  uint32_t w;
} __DACC_WPSR_bits_t;

#define DACC_WPSR_WPVS_Pos                    (0)                                            /**< (DACC_WPSR) Write Protection Violation Status Position */
#define DACC_WPSR_WPVS_Msk                    (0x1U << DACC_WPSR_WPVS_Pos)                   /**< (DACC_WPSR) Write Protection Violation Status Mask */
#define DACC_WPSR_WPVSRC_Pos                  (8)                                            /**< (DACC_WPSR) Write Protection Violation Source Position */
#define DACC_WPSR_WPVSRC_Msk                  (0xFFU << DACC_WPSR_WPVSRC_Pos)                /**< (DACC_WPSR) Write Protection Violation Source Mask */
#define DACC_WPSR_WPVSRC(value)               (DACC_WPSR_WPVSRC_Msk & ((value) << DACC_WPSR_WPVSRC_Pos))
#define DACC_WPSR_Msk                         (0x0000FF01UL)                                 /**< (DACC_WPSR) Register Mask  */

/** \brief DACC register offsets definitions */
#define DACC_CR_OFFSET               (0x00)         /**< (DACC_CR) Control Register Offset */
#define DACC_MR_OFFSET               (0x04)         /**< (DACC_MR) Mode Register Offset */
#define DACC_TRIGR_OFFSET            (0x08)         /**< (DACC_TRIGR) Trigger Register Offset */
#define DACC_CHER_OFFSET             (0x10)         /**< (DACC_CHER) Channel Enable Register Offset */
#define DACC_CHDR_OFFSET             (0x14)         /**< (DACC_CHDR) Channel Disable Register Offset */
#define DACC_CHSR_OFFSET             (0x18)         /**< (DACC_CHSR) Channel Status Register Offset */
#define DACC_CDR_OFFSET              (0x1C)         /**< (DACC_CDR) Conversion Data Register 0 Offset */
#define DACC_IER_OFFSET              (0x24)         /**< (DACC_IER) Interrupt Enable Register Offset */
#define DACC_IDR_OFFSET              (0x28)         /**< (DACC_IDR) Interrupt Disable Register Offset */
#define DACC_IMR_OFFSET              (0x2C)         /**< (DACC_IMR) Interrupt Mask Register Offset */
#define DACC_ISR_OFFSET              (0x30)         /**< (DACC_ISR) Interrupt Status Register Offset */
#define DACC_ACR_OFFSET              (0x94)         /**< (DACC_ACR) Analog Current Register Offset */
#define DACC_WPMR_OFFSET             (0xE4)         /**< (DACC_WPMR) Write Protection Mode Register Offset */
#define DACC_WPSR_OFFSET             (0xE8)         /**< (DACC_WPSR) Write Protection Status Register Offset */

/** \brief DACC register API structure */
typedef struct
{
  __O   __DACC_CR_bits_t               DACC_CR;       /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  __DACC_MR_bits_t               DACC_MR;       /**< Offset: 0x04 (R/W  32) Mode Register */
  __IO  __DACC_TRIGR_bits_t            DACC_TRIGR;    /**< Offset: 0x08 (R/W  32) Trigger Register */
  __I   uint8_t                        Reserved1[0x04];
  __O   __DACC_CHER_bits_t             DACC_CHER;     /**< Offset: 0x10 ( /W  32) Channel Enable Register */
  __O   __DACC_CHDR_bits_t             DACC_CHDR;     /**< Offset: 0x14 ( /W  32) Channel Disable Register */
  __I   __DACC_CHSR_bits_t             DACC_CHSR;     /**< Offset: 0x18 (R/   32) Channel Status Register */
  __O   __DACC_CDR_bits_t              DACC_CDR[2];   /**< Offset: 0x1C ( /W  32) Conversion Data Register 0 */
  __O   __DACC_IER_bits_t              DACC_IER;      /**< Offset: 0x24 ( /W  32) Interrupt Enable Register */
  __O   __DACC_IDR_bits_t              DACC_IDR;      /**< Offset: 0x28 ( /W  32) Interrupt Disable Register */
  __I   __DACC_IMR_bits_t              DACC_IMR;      /**< Offset: 0x2C (R/   32) Interrupt Mask Register */
  __I   __DACC_ISR_bits_t              DACC_ISR;      /**< Offset: 0x30 (R/   32) Interrupt Status Register */
  __I   uint8_t                        Reserved2[0x60];
  __IO  __DACC_ACR_bits_t              DACC_ACR;      /**< Offset: 0x94 (R/W  32) Analog Current Register */
  __I   uint8_t                        Reserved3[0x4C];
  __IO  __DACC_WPMR_bits_t             DACC_WPMR;     /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   __DACC_WPSR_bits_t             DACC_WPSR;     /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} dacc_registers_t;
/** @}  end of Digital-to-Analog Converter Controller */

#endif /* _PIC32CZ_CA70_DACC_COMPONENT_H_ */
