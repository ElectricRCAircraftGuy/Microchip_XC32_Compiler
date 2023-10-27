/**
 * \brief Component description for PIC32CZ/CA70 PORT
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
#ifndef _PIC32CZ_CA70_PORT_COMPONENT_H_
#define _PIC32CZ_CA70_PORT_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_PORT Port
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR PORT */
/* ========================================================================== */

/* -------- PORT_PER : (PORT Offset: 0x00) (/W 32) PORT Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  PORT Enable                                   */
    uint32_t P1:1;                      /**< bit:      1  PORT Enable                                   */
    uint32_t P2:1;                      /**< bit:      2  PORT Enable                                   */
    uint32_t P3:1;                      /**< bit:      3  PORT Enable                                   */
    uint32_t P4:1;                      /**< bit:      4  PORT Enable                                   */
    uint32_t P5:1;                      /**< bit:      5  PORT Enable                                   */
    uint32_t P6:1;                      /**< bit:      6  PORT Enable                                   */
    uint32_t P7:1;                      /**< bit:      7  PORT Enable                                   */
    uint32_t P8:1;                      /**< bit:      8  PORT Enable                                   */
    uint32_t P9:1;                      /**< bit:      9  PORT Enable                                   */
    uint32_t P10:1;                     /**< bit:     10  PORT Enable                                   */
    uint32_t P11:1;                     /**< bit:     11  PORT Enable                                   */
    uint32_t P12:1;                     /**< bit:     12  PORT Enable                                   */
    uint32_t P13:1;                     /**< bit:     13  PORT Enable                                   */
    uint32_t P14:1;                     /**< bit:     14  PORT Enable                                   */
    uint32_t P15:1;                     /**< bit:     15  PORT Enable                                   */
    uint32_t P16:1;                     /**< bit:     16  PORT Enable                                   */
    uint32_t P17:1;                     /**< bit:     17  PORT Enable                                   */
    uint32_t P18:1;                     /**< bit:     18  PORT Enable                                   */
    uint32_t P19:1;                     /**< bit:     19  PORT Enable                                   */
    uint32_t P20:1;                     /**< bit:     20  PORT Enable                                   */
    uint32_t P21:1;                     /**< bit:     21  PORT Enable                                   */
    uint32_t P22:1;                     /**< bit:     22  PORT Enable                                   */
    uint32_t P23:1;                     /**< bit:     23  PORT Enable                                   */
    uint32_t P24:1;                     /**< bit:     24  PORT Enable                                   */
    uint32_t P25:1;                     /**< bit:     25  PORT Enable                                   */
    uint32_t P26:1;                     /**< bit:     26  PORT Enable                                   */
    uint32_t P27:1;                     /**< bit:     27  PORT Enable                                   */
    uint32_t P28:1;                     /**< bit:     28  PORT Enable                                   */
    uint32_t P29:1;                     /**< bit:     29  PORT Enable                                   */
    uint32_t P30:1;                     /**< bit:     30  PORT Enable                                   */
    uint32_t P31:1;                     /**< bit:     31  PORT Enable                                   */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  PORT Enable                                   */
  };
  uint32_t w;
} __PORT_PER_bits_t;

#define PORT_PER_P0_Pos                       (0)                                            /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P0_Msk                       (0x1U << PORT_PER_P0_Pos)                      /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P1_Pos                       (1)                                            /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P1_Msk                       (0x1U << PORT_PER_P1_Pos)                      /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P2_Pos                       (2)                                            /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P2_Msk                       (0x1U << PORT_PER_P2_Pos)                      /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P3_Pos                       (3)                                            /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P3_Msk                       (0x1U << PORT_PER_P3_Pos)                      /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P4_Pos                       (4)                                            /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P4_Msk                       (0x1U << PORT_PER_P4_Pos)                      /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P5_Pos                       (5)                                            /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P5_Msk                       (0x1U << PORT_PER_P5_Pos)                      /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P6_Pos                       (6)                                            /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P6_Msk                       (0x1U << PORT_PER_P6_Pos)                      /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P7_Pos                       (7)                                            /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P7_Msk                       (0x1U << PORT_PER_P7_Pos)                      /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P8_Pos                       (8)                                            /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P8_Msk                       (0x1U << PORT_PER_P8_Pos)                      /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P9_Pos                       (9)                                            /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P9_Msk                       (0x1U << PORT_PER_P9_Pos)                      /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P10_Pos                      (10)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P10_Msk                      (0x1U << PORT_PER_P10_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P11_Pos                      (11)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P11_Msk                      (0x1U << PORT_PER_P11_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P12_Pos                      (12)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P12_Msk                      (0x1U << PORT_PER_P12_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P13_Pos                      (13)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P13_Msk                      (0x1U << PORT_PER_P13_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P14_Pos                      (14)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P14_Msk                      (0x1U << PORT_PER_P14_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P15_Pos                      (15)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P15_Msk                      (0x1U << PORT_PER_P15_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P16_Pos                      (16)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P16_Msk                      (0x1U << PORT_PER_P16_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P17_Pos                      (17)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P17_Msk                      (0x1U << PORT_PER_P17_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P18_Pos                      (18)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P18_Msk                      (0x1U << PORT_PER_P18_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P19_Pos                      (19)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P19_Msk                      (0x1U << PORT_PER_P19_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P20_Pos                      (20)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P20_Msk                      (0x1U << PORT_PER_P20_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P21_Pos                      (21)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P21_Msk                      (0x1U << PORT_PER_P21_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P22_Pos                      (22)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P22_Msk                      (0x1U << PORT_PER_P22_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P23_Pos                      (23)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P23_Msk                      (0x1U << PORT_PER_P23_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P24_Pos                      (24)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P24_Msk                      (0x1U << PORT_PER_P24_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P25_Pos                      (25)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P25_Msk                      (0x1U << PORT_PER_P25_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P26_Pos                      (26)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P26_Msk                      (0x1U << PORT_PER_P26_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P27_Pos                      (27)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P27_Msk                      (0x1U << PORT_PER_P27_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P28_Pos                      (28)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P28_Msk                      (0x1U << PORT_PER_P28_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P29_Pos                      (29)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P29_Msk                      (0x1U << PORT_PER_P29_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P30_Pos                      (30)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P30_Msk                      (0x1U << PORT_PER_P30_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_P31_Pos                      (31)                                           /**< (PORT_PER) PORT Enable Position */
#define PORT_PER_P31_Msk                      (0x1U << PORT_PER_P31_Pos)                     /**< (PORT_PER) PORT Enable Mask */
#define PORT_PER_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_PER) Register Mask  */
#define PORT_PER_P_Pos                        (0)                                            /**< (PORT_PER Position) PORT Enable */
#define PORT_PER_P_Msk                        (0xFFFFFFFFU << PORT_PER_P_Pos)                /**< (PORT_PER Mask) P */
#define PORT_PER_P(value)                     (PORT_PER_P_Msk & ((value) << PORT_PER_P_Pos))

/* -------- PORT_PDR : (PORT Offset: 0x04) (/W 32) PORT Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  PORT Disable                                  */
    uint32_t P1:1;                      /**< bit:      1  PORT Disable                                  */
    uint32_t P2:1;                      /**< bit:      2  PORT Disable                                  */
    uint32_t P3:1;                      /**< bit:      3  PORT Disable                                  */
    uint32_t P4:1;                      /**< bit:      4  PORT Disable                                  */
    uint32_t P5:1;                      /**< bit:      5  PORT Disable                                  */
    uint32_t P6:1;                      /**< bit:      6  PORT Disable                                  */
    uint32_t P7:1;                      /**< bit:      7  PORT Disable                                  */
    uint32_t P8:1;                      /**< bit:      8  PORT Disable                                  */
    uint32_t P9:1;                      /**< bit:      9  PORT Disable                                  */
    uint32_t P10:1;                     /**< bit:     10  PORT Disable                                  */
    uint32_t P11:1;                     /**< bit:     11  PORT Disable                                  */
    uint32_t P12:1;                     /**< bit:     12  PORT Disable                                  */
    uint32_t P13:1;                     /**< bit:     13  PORT Disable                                  */
    uint32_t P14:1;                     /**< bit:     14  PORT Disable                                  */
    uint32_t P15:1;                     /**< bit:     15  PORT Disable                                  */
    uint32_t P16:1;                     /**< bit:     16  PORT Disable                                  */
    uint32_t P17:1;                     /**< bit:     17  PORT Disable                                  */
    uint32_t P18:1;                     /**< bit:     18  PORT Disable                                  */
    uint32_t P19:1;                     /**< bit:     19  PORT Disable                                  */
    uint32_t P20:1;                     /**< bit:     20  PORT Disable                                  */
    uint32_t P21:1;                     /**< bit:     21  PORT Disable                                  */
    uint32_t P22:1;                     /**< bit:     22  PORT Disable                                  */
    uint32_t P23:1;                     /**< bit:     23  PORT Disable                                  */
    uint32_t P24:1;                     /**< bit:     24  PORT Disable                                  */
    uint32_t P25:1;                     /**< bit:     25  PORT Disable                                  */
    uint32_t P26:1;                     /**< bit:     26  PORT Disable                                  */
    uint32_t P27:1;                     /**< bit:     27  PORT Disable                                  */
    uint32_t P28:1;                     /**< bit:     28  PORT Disable                                  */
    uint32_t P29:1;                     /**< bit:     29  PORT Disable                                  */
    uint32_t P30:1;                     /**< bit:     30  PORT Disable                                  */
    uint32_t P31:1;                     /**< bit:     31  PORT Disable                                  */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  PORT Disable                                  */
  };
  uint32_t w;
} __PORT_PDR_bits_t;

#define PORT_PDR_P0_Pos                       (0)                                            /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P0_Msk                       (0x1U << PORT_PDR_P0_Pos)                      /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P1_Pos                       (1)                                            /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P1_Msk                       (0x1U << PORT_PDR_P1_Pos)                      /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P2_Pos                       (2)                                            /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P2_Msk                       (0x1U << PORT_PDR_P2_Pos)                      /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P3_Pos                       (3)                                            /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P3_Msk                       (0x1U << PORT_PDR_P3_Pos)                      /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P4_Pos                       (4)                                            /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P4_Msk                       (0x1U << PORT_PDR_P4_Pos)                      /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P5_Pos                       (5)                                            /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P5_Msk                       (0x1U << PORT_PDR_P5_Pos)                      /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P6_Pos                       (6)                                            /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P6_Msk                       (0x1U << PORT_PDR_P6_Pos)                      /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P7_Pos                       (7)                                            /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P7_Msk                       (0x1U << PORT_PDR_P7_Pos)                      /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P8_Pos                       (8)                                            /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P8_Msk                       (0x1U << PORT_PDR_P8_Pos)                      /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P9_Pos                       (9)                                            /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P9_Msk                       (0x1U << PORT_PDR_P9_Pos)                      /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P10_Pos                      (10)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P10_Msk                      (0x1U << PORT_PDR_P10_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P11_Pos                      (11)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P11_Msk                      (0x1U << PORT_PDR_P11_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P12_Pos                      (12)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P12_Msk                      (0x1U << PORT_PDR_P12_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P13_Pos                      (13)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P13_Msk                      (0x1U << PORT_PDR_P13_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P14_Pos                      (14)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P14_Msk                      (0x1U << PORT_PDR_P14_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P15_Pos                      (15)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P15_Msk                      (0x1U << PORT_PDR_P15_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P16_Pos                      (16)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P16_Msk                      (0x1U << PORT_PDR_P16_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P17_Pos                      (17)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P17_Msk                      (0x1U << PORT_PDR_P17_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P18_Pos                      (18)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P18_Msk                      (0x1U << PORT_PDR_P18_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P19_Pos                      (19)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P19_Msk                      (0x1U << PORT_PDR_P19_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P20_Pos                      (20)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P20_Msk                      (0x1U << PORT_PDR_P20_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P21_Pos                      (21)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P21_Msk                      (0x1U << PORT_PDR_P21_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P22_Pos                      (22)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P22_Msk                      (0x1U << PORT_PDR_P22_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P23_Pos                      (23)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P23_Msk                      (0x1U << PORT_PDR_P23_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P24_Pos                      (24)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P24_Msk                      (0x1U << PORT_PDR_P24_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P25_Pos                      (25)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P25_Msk                      (0x1U << PORT_PDR_P25_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P26_Pos                      (26)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P26_Msk                      (0x1U << PORT_PDR_P26_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P27_Pos                      (27)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P27_Msk                      (0x1U << PORT_PDR_P27_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P28_Pos                      (28)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P28_Msk                      (0x1U << PORT_PDR_P28_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P29_Pos                      (29)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P29_Msk                      (0x1U << PORT_PDR_P29_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P30_Pos                      (30)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P30_Msk                      (0x1U << PORT_PDR_P30_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_P31_Pos                      (31)                                           /**< (PORT_PDR) PORT Disable Position */
#define PORT_PDR_P31_Msk                      (0x1U << PORT_PDR_P31_Pos)                     /**< (PORT_PDR) PORT Disable Mask */
#define PORT_PDR_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_PDR) Register Mask  */
#define PORT_PDR_P_Pos                        (0)                                            /**< (PORT_PDR Position) PORT Disable */
#define PORT_PDR_P_Msk                        (0xFFFFFFFFU << PORT_PDR_P_Pos)                /**< (PORT_PDR Mask) P */
#define PORT_PDR_P(value)                     (PORT_PDR_P_Msk & ((value) << PORT_PDR_P_Pos))

/* -------- PORT_PSR : (PORT Offset: 0x08) (R/ 32) PORT Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  PORT Status                                   */
    uint32_t P1:1;                      /**< bit:      1  PORT Status                                   */
    uint32_t P2:1;                      /**< bit:      2  PORT Status                                   */
    uint32_t P3:1;                      /**< bit:      3  PORT Status                                   */
    uint32_t P4:1;                      /**< bit:      4  PORT Status                                   */
    uint32_t P5:1;                      /**< bit:      5  PORT Status                                   */
    uint32_t P6:1;                      /**< bit:      6  PORT Status                                   */
    uint32_t P7:1;                      /**< bit:      7  PORT Status                                   */
    uint32_t P8:1;                      /**< bit:      8  PORT Status                                   */
    uint32_t P9:1;                      /**< bit:      9  PORT Status                                   */
    uint32_t P10:1;                     /**< bit:     10  PORT Status                                   */
    uint32_t P11:1;                     /**< bit:     11  PORT Status                                   */
    uint32_t P12:1;                     /**< bit:     12  PORT Status                                   */
    uint32_t P13:1;                     /**< bit:     13  PORT Status                                   */
    uint32_t P14:1;                     /**< bit:     14  PORT Status                                   */
    uint32_t P15:1;                     /**< bit:     15  PORT Status                                   */
    uint32_t P16:1;                     /**< bit:     16  PORT Status                                   */
    uint32_t P17:1;                     /**< bit:     17  PORT Status                                   */
    uint32_t P18:1;                     /**< bit:     18  PORT Status                                   */
    uint32_t P19:1;                     /**< bit:     19  PORT Status                                   */
    uint32_t P20:1;                     /**< bit:     20  PORT Status                                   */
    uint32_t P21:1;                     /**< bit:     21  PORT Status                                   */
    uint32_t P22:1;                     /**< bit:     22  PORT Status                                   */
    uint32_t P23:1;                     /**< bit:     23  PORT Status                                   */
    uint32_t P24:1;                     /**< bit:     24  PORT Status                                   */
    uint32_t P25:1;                     /**< bit:     25  PORT Status                                   */
    uint32_t P26:1;                     /**< bit:     26  PORT Status                                   */
    uint32_t P27:1;                     /**< bit:     27  PORT Status                                   */
    uint32_t P28:1;                     /**< bit:     28  PORT Status                                   */
    uint32_t P29:1;                     /**< bit:     29  PORT Status                                   */
    uint32_t P30:1;                     /**< bit:     30  PORT Status                                   */
    uint32_t P31:1;                     /**< bit:     31  PORT Status                                   */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  PORT Status                                   */
  };
  uint32_t w;
} __PORT_PSR_bits_t;

#define PORT_PSR_P0_Pos                       (0)                                            /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P0_Msk                       (0x1U << PORT_PSR_P0_Pos)                      /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P1_Pos                       (1)                                            /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P1_Msk                       (0x1U << PORT_PSR_P1_Pos)                      /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P2_Pos                       (2)                                            /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P2_Msk                       (0x1U << PORT_PSR_P2_Pos)                      /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P3_Pos                       (3)                                            /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P3_Msk                       (0x1U << PORT_PSR_P3_Pos)                      /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P4_Pos                       (4)                                            /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P4_Msk                       (0x1U << PORT_PSR_P4_Pos)                      /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P5_Pos                       (5)                                            /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P5_Msk                       (0x1U << PORT_PSR_P5_Pos)                      /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P6_Pos                       (6)                                            /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P6_Msk                       (0x1U << PORT_PSR_P6_Pos)                      /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P7_Pos                       (7)                                            /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P7_Msk                       (0x1U << PORT_PSR_P7_Pos)                      /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P8_Pos                       (8)                                            /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P8_Msk                       (0x1U << PORT_PSR_P8_Pos)                      /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P9_Pos                       (9)                                            /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P9_Msk                       (0x1U << PORT_PSR_P9_Pos)                      /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P10_Pos                      (10)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P10_Msk                      (0x1U << PORT_PSR_P10_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P11_Pos                      (11)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P11_Msk                      (0x1U << PORT_PSR_P11_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P12_Pos                      (12)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P12_Msk                      (0x1U << PORT_PSR_P12_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P13_Pos                      (13)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P13_Msk                      (0x1U << PORT_PSR_P13_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P14_Pos                      (14)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P14_Msk                      (0x1U << PORT_PSR_P14_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P15_Pos                      (15)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P15_Msk                      (0x1U << PORT_PSR_P15_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P16_Pos                      (16)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P16_Msk                      (0x1U << PORT_PSR_P16_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P17_Pos                      (17)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P17_Msk                      (0x1U << PORT_PSR_P17_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P18_Pos                      (18)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P18_Msk                      (0x1U << PORT_PSR_P18_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P19_Pos                      (19)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P19_Msk                      (0x1U << PORT_PSR_P19_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P20_Pos                      (20)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P20_Msk                      (0x1U << PORT_PSR_P20_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P21_Pos                      (21)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P21_Msk                      (0x1U << PORT_PSR_P21_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P22_Pos                      (22)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P22_Msk                      (0x1U << PORT_PSR_P22_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P23_Pos                      (23)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P23_Msk                      (0x1U << PORT_PSR_P23_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P24_Pos                      (24)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P24_Msk                      (0x1U << PORT_PSR_P24_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P25_Pos                      (25)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P25_Msk                      (0x1U << PORT_PSR_P25_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P26_Pos                      (26)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P26_Msk                      (0x1U << PORT_PSR_P26_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P27_Pos                      (27)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P27_Msk                      (0x1U << PORT_PSR_P27_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P28_Pos                      (28)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P28_Msk                      (0x1U << PORT_PSR_P28_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P29_Pos                      (29)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P29_Msk                      (0x1U << PORT_PSR_P29_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P30_Pos                      (30)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P30_Msk                      (0x1U << PORT_PSR_P30_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_P31_Pos                      (31)                                           /**< (PORT_PSR) PORT Status Position */
#define PORT_PSR_P31_Msk                      (0x1U << PORT_PSR_P31_Pos)                     /**< (PORT_PSR) PORT Status Mask */
#define PORT_PSR_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_PSR) Register Mask  */
#define PORT_PSR_P_Pos                        (0)                                            /**< (PORT_PSR Position) PORT Status */
#define PORT_PSR_P_Msk                        (0xFFFFFFFFU << PORT_PSR_P_Pos)                /**< (PORT_PSR Mask) P */
#define PORT_PSR_P(value)                     (PORT_PSR_P_Msk & ((value) << PORT_PSR_P_Pos))

/* -------- PORT_OER : (PORT Offset: 0x10) (/W 32) Output Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Output Enable                                 */
    uint32_t P1:1;                      /**< bit:      1  Output Enable                                 */
    uint32_t P2:1;                      /**< bit:      2  Output Enable                                 */
    uint32_t P3:1;                      /**< bit:      3  Output Enable                                 */
    uint32_t P4:1;                      /**< bit:      4  Output Enable                                 */
    uint32_t P5:1;                      /**< bit:      5  Output Enable                                 */
    uint32_t P6:1;                      /**< bit:      6  Output Enable                                 */
    uint32_t P7:1;                      /**< bit:      7  Output Enable                                 */
    uint32_t P8:1;                      /**< bit:      8  Output Enable                                 */
    uint32_t P9:1;                      /**< bit:      9  Output Enable                                 */
    uint32_t P10:1;                     /**< bit:     10  Output Enable                                 */
    uint32_t P11:1;                     /**< bit:     11  Output Enable                                 */
    uint32_t P12:1;                     /**< bit:     12  Output Enable                                 */
    uint32_t P13:1;                     /**< bit:     13  Output Enable                                 */
    uint32_t P14:1;                     /**< bit:     14  Output Enable                                 */
    uint32_t P15:1;                     /**< bit:     15  Output Enable                                 */
    uint32_t P16:1;                     /**< bit:     16  Output Enable                                 */
    uint32_t P17:1;                     /**< bit:     17  Output Enable                                 */
    uint32_t P18:1;                     /**< bit:     18  Output Enable                                 */
    uint32_t P19:1;                     /**< bit:     19  Output Enable                                 */
    uint32_t P20:1;                     /**< bit:     20  Output Enable                                 */
    uint32_t P21:1;                     /**< bit:     21  Output Enable                                 */
    uint32_t P22:1;                     /**< bit:     22  Output Enable                                 */
    uint32_t P23:1;                     /**< bit:     23  Output Enable                                 */
    uint32_t P24:1;                     /**< bit:     24  Output Enable                                 */
    uint32_t P25:1;                     /**< bit:     25  Output Enable                                 */
    uint32_t P26:1;                     /**< bit:     26  Output Enable                                 */
    uint32_t P27:1;                     /**< bit:     27  Output Enable                                 */
    uint32_t P28:1;                     /**< bit:     28  Output Enable                                 */
    uint32_t P29:1;                     /**< bit:     29  Output Enable                                 */
    uint32_t P30:1;                     /**< bit:     30  Output Enable                                 */
    uint32_t P31:1;                     /**< bit:     31  Output Enable                                 */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Output Enable                                 */
  };
  uint32_t w;
} __PORT_OER_bits_t;

#define PORT_OER_P0_Pos                       (0)                                            /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P0_Msk                       (0x1U << PORT_OER_P0_Pos)                      /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P1_Pos                       (1)                                            /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P1_Msk                       (0x1U << PORT_OER_P1_Pos)                      /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P2_Pos                       (2)                                            /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P2_Msk                       (0x1U << PORT_OER_P2_Pos)                      /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P3_Pos                       (3)                                            /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P3_Msk                       (0x1U << PORT_OER_P3_Pos)                      /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P4_Pos                       (4)                                            /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P4_Msk                       (0x1U << PORT_OER_P4_Pos)                      /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P5_Pos                       (5)                                            /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P5_Msk                       (0x1U << PORT_OER_P5_Pos)                      /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P6_Pos                       (6)                                            /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P6_Msk                       (0x1U << PORT_OER_P6_Pos)                      /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P7_Pos                       (7)                                            /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P7_Msk                       (0x1U << PORT_OER_P7_Pos)                      /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P8_Pos                       (8)                                            /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P8_Msk                       (0x1U << PORT_OER_P8_Pos)                      /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P9_Pos                       (9)                                            /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P9_Msk                       (0x1U << PORT_OER_P9_Pos)                      /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P10_Pos                      (10)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P10_Msk                      (0x1U << PORT_OER_P10_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P11_Pos                      (11)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P11_Msk                      (0x1U << PORT_OER_P11_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P12_Pos                      (12)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P12_Msk                      (0x1U << PORT_OER_P12_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P13_Pos                      (13)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P13_Msk                      (0x1U << PORT_OER_P13_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P14_Pos                      (14)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P14_Msk                      (0x1U << PORT_OER_P14_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P15_Pos                      (15)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P15_Msk                      (0x1U << PORT_OER_P15_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P16_Pos                      (16)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P16_Msk                      (0x1U << PORT_OER_P16_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P17_Pos                      (17)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P17_Msk                      (0x1U << PORT_OER_P17_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P18_Pos                      (18)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P18_Msk                      (0x1U << PORT_OER_P18_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P19_Pos                      (19)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P19_Msk                      (0x1U << PORT_OER_P19_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P20_Pos                      (20)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P20_Msk                      (0x1U << PORT_OER_P20_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P21_Pos                      (21)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P21_Msk                      (0x1U << PORT_OER_P21_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P22_Pos                      (22)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P22_Msk                      (0x1U << PORT_OER_P22_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P23_Pos                      (23)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P23_Msk                      (0x1U << PORT_OER_P23_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P24_Pos                      (24)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P24_Msk                      (0x1U << PORT_OER_P24_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P25_Pos                      (25)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P25_Msk                      (0x1U << PORT_OER_P25_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P26_Pos                      (26)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P26_Msk                      (0x1U << PORT_OER_P26_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P27_Pos                      (27)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P27_Msk                      (0x1U << PORT_OER_P27_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P28_Pos                      (28)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P28_Msk                      (0x1U << PORT_OER_P28_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P29_Pos                      (29)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P29_Msk                      (0x1U << PORT_OER_P29_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P30_Pos                      (30)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P30_Msk                      (0x1U << PORT_OER_P30_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_P31_Pos                      (31)                                           /**< (PORT_OER) Output Enable Position */
#define PORT_OER_P31_Msk                      (0x1U << PORT_OER_P31_Pos)                     /**< (PORT_OER) Output Enable Mask */
#define PORT_OER_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_OER) Register Mask  */
#define PORT_OER_P_Pos                        (0)                                            /**< (PORT_OER Position) Output Enable */
#define PORT_OER_P_Msk                        (0xFFFFFFFFU << PORT_OER_P_Pos)                /**< (PORT_OER Mask) P */
#define PORT_OER_P(value)                     (PORT_OER_P_Msk & ((value) << PORT_OER_P_Pos))

/* -------- PORT_ODR : (PORT Offset: 0x14) (/W 32) Output Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Output Disable                                */
    uint32_t P1:1;                      /**< bit:      1  Output Disable                                */
    uint32_t P2:1;                      /**< bit:      2  Output Disable                                */
    uint32_t P3:1;                      /**< bit:      3  Output Disable                                */
    uint32_t P4:1;                      /**< bit:      4  Output Disable                                */
    uint32_t P5:1;                      /**< bit:      5  Output Disable                                */
    uint32_t P6:1;                      /**< bit:      6  Output Disable                                */
    uint32_t P7:1;                      /**< bit:      7  Output Disable                                */
    uint32_t P8:1;                      /**< bit:      8  Output Disable                                */
    uint32_t P9:1;                      /**< bit:      9  Output Disable                                */
    uint32_t P10:1;                     /**< bit:     10  Output Disable                                */
    uint32_t P11:1;                     /**< bit:     11  Output Disable                                */
    uint32_t P12:1;                     /**< bit:     12  Output Disable                                */
    uint32_t P13:1;                     /**< bit:     13  Output Disable                                */
    uint32_t P14:1;                     /**< bit:     14  Output Disable                                */
    uint32_t P15:1;                     /**< bit:     15  Output Disable                                */
    uint32_t P16:1;                     /**< bit:     16  Output Disable                                */
    uint32_t P17:1;                     /**< bit:     17  Output Disable                                */
    uint32_t P18:1;                     /**< bit:     18  Output Disable                                */
    uint32_t P19:1;                     /**< bit:     19  Output Disable                                */
    uint32_t P20:1;                     /**< bit:     20  Output Disable                                */
    uint32_t P21:1;                     /**< bit:     21  Output Disable                                */
    uint32_t P22:1;                     /**< bit:     22  Output Disable                                */
    uint32_t P23:1;                     /**< bit:     23  Output Disable                                */
    uint32_t P24:1;                     /**< bit:     24  Output Disable                                */
    uint32_t P25:1;                     /**< bit:     25  Output Disable                                */
    uint32_t P26:1;                     /**< bit:     26  Output Disable                                */
    uint32_t P27:1;                     /**< bit:     27  Output Disable                                */
    uint32_t P28:1;                     /**< bit:     28  Output Disable                                */
    uint32_t P29:1;                     /**< bit:     29  Output Disable                                */
    uint32_t P30:1;                     /**< bit:     30  Output Disable                                */
    uint32_t P31:1;                     /**< bit:     31  Output Disable                                */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Output Disable                                */
  };
  uint32_t w;
} __PORT_ODR_bits_t;

#define PORT_ODR_P0_Pos                       (0)                                            /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P0_Msk                       (0x1U << PORT_ODR_P0_Pos)                      /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P1_Pos                       (1)                                            /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P1_Msk                       (0x1U << PORT_ODR_P1_Pos)                      /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P2_Pos                       (2)                                            /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P2_Msk                       (0x1U << PORT_ODR_P2_Pos)                      /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P3_Pos                       (3)                                            /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P3_Msk                       (0x1U << PORT_ODR_P3_Pos)                      /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P4_Pos                       (4)                                            /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P4_Msk                       (0x1U << PORT_ODR_P4_Pos)                      /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P5_Pos                       (5)                                            /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P5_Msk                       (0x1U << PORT_ODR_P5_Pos)                      /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P6_Pos                       (6)                                            /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P6_Msk                       (0x1U << PORT_ODR_P6_Pos)                      /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P7_Pos                       (7)                                            /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P7_Msk                       (0x1U << PORT_ODR_P7_Pos)                      /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P8_Pos                       (8)                                            /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P8_Msk                       (0x1U << PORT_ODR_P8_Pos)                      /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P9_Pos                       (9)                                            /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P9_Msk                       (0x1U << PORT_ODR_P9_Pos)                      /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P10_Pos                      (10)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P10_Msk                      (0x1U << PORT_ODR_P10_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P11_Pos                      (11)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P11_Msk                      (0x1U << PORT_ODR_P11_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P12_Pos                      (12)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P12_Msk                      (0x1U << PORT_ODR_P12_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P13_Pos                      (13)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P13_Msk                      (0x1U << PORT_ODR_P13_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P14_Pos                      (14)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P14_Msk                      (0x1U << PORT_ODR_P14_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P15_Pos                      (15)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P15_Msk                      (0x1U << PORT_ODR_P15_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P16_Pos                      (16)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P16_Msk                      (0x1U << PORT_ODR_P16_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P17_Pos                      (17)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P17_Msk                      (0x1U << PORT_ODR_P17_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P18_Pos                      (18)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P18_Msk                      (0x1U << PORT_ODR_P18_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P19_Pos                      (19)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P19_Msk                      (0x1U << PORT_ODR_P19_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P20_Pos                      (20)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P20_Msk                      (0x1U << PORT_ODR_P20_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P21_Pos                      (21)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P21_Msk                      (0x1U << PORT_ODR_P21_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P22_Pos                      (22)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P22_Msk                      (0x1U << PORT_ODR_P22_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P23_Pos                      (23)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P23_Msk                      (0x1U << PORT_ODR_P23_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P24_Pos                      (24)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P24_Msk                      (0x1U << PORT_ODR_P24_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P25_Pos                      (25)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P25_Msk                      (0x1U << PORT_ODR_P25_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P26_Pos                      (26)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P26_Msk                      (0x1U << PORT_ODR_P26_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P27_Pos                      (27)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P27_Msk                      (0x1U << PORT_ODR_P27_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P28_Pos                      (28)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P28_Msk                      (0x1U << PORT_ODR_P28_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P29_Pos                      (29)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P29_Msk                      (0x1U << PORT_ODR_P29_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P30_Pos                      (30)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P30_Msk                      (0x1U << PORT_ODR_P30_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_P31_Pos                      (31)                                           /**< (PORT_ODR) Output Disable Position */
#define PORT_ODR_P31_Msk                      (0x1U << PORT_ODR_P31_Pos)                     /**< (PORT_ODR) Output Disable Mask */
#define PORT_ODR_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_ODR) Register Mask  */
#define PORT_ODR_P_Pos                        (0)                                            /**< (PORT_ODR Position) Output Disable */
#define PORT_ODR_P_Msk                        (0xFFFFFFFFU << PORT_ODR_P_Pos)                /**< (PORT_ODR Mask) P */
#define PORT_ODR_P(value)                     (PORT_ODR_P_Msk & ((value) << PORT_ODR_P_Pos))

/* -------- PORT_OSR : (PORT Offset: 0x18) (R/ 32) Output Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Output Status                                 */
    uint32_t P1:1;                      /**< bit:      1  Output Status                                 */
    uint32_t P2:1;                      /**< bit:      2  Output Status                                 */
    uint32_t P3:1;                      /**< bit:      3  Output Status                                 */
    uint32_t P4:1;                      /**< bit:      4  Output Status                                 */
    uint32_t P5:1;                      /**< bit:      5  Output Status                                 */
    uint32_t P6:1;                      /**< bit:      6  Output Status                                 */
    uint32_t P7:1;                      /**< bit:      7  Output Status                                 */
    uint32_t P8:1;                      /**< bit:      8  Output Status                                 */
    uint32_t P9:1;                      /**< bit:      9  Output Status                                 */
    uint32_t P10:1;                     /**< bit:     10  Output Status                                 */
    uint32_t P11:1;                     /**< bit:     11  Output Status                                 */
    uint32_t P12:1;                     /**< bit:     12  Output Status                                 */
    uint32_t P13:1;                     /**< bit:     13  Output Status                                 */
    uint32_t P14:1;                     /**< bit:     14  Output Status                                 */
    uint32_t P15:1;                     /**< bit:     15  Output Status                                 */
    uint32_t P16:1;                     /**< bit:     16  Output Status                                 */
    uint32_t P17:1;                     /**< bit:     17  Output Status                                 */
    uint32_t P18:1;                     /**< bit:     18  Output Status                                 */
    uint32_t P19:1;                     /**< bit:     19  Output Status                                 */
    uint32_t P20:1;                     /**< bit:     20  Output Status                                 */
    uint32_t P21:1;                     /**< bit:     21  Output Status                                 */
    uint32_t P22:1;                     /**< bit:     22  Output Status                                 */
    uint32_t P23:1;                     /**< bit:     23  Output Status                                 */
    uint32_t P24:1;                     /**< bit:     24  Output Status                                 */
    uint32_t P25:1;                     /**< bit:     25  Output Status                                 */
    uint32_t P26:1;                     /**< bit:     26  Output Status                                 */
    uint32_t P27:1;                     /**< bit:     27  Output Status                                 */
    uint32_t P28:1;                     /**< bit:     28  Output Status                                 */
    uint32_t P29:1;                     /**< bit:     29  Output Status                                 */
    uint32_t P30:1;                     /**< bit:     30  Output Status                                 */
    uint32_t P31:1;                     /**< bit:     31  Output Status                                 */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Output Status                                 */
  };
  uint32_t w;
} __PORT_OSR_bits_t;

#define PORT_OSR_P0_Pos                       (0)                                            /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P0_Msk                       (0x1U << PORT_OSR_P0_Pos)                      /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P1_Pos                       (1)                                            /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P1_Msk                       (0x1U << PORT_OSR_P1_Pos)                      /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P2_Pos                       (2)                                            /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P2_Msk                       (0x1U << PORT_OSR_P2_Pos)                      /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P3_Pos                       (3)                                            /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P3_Msk                       (0x1U << PORT_OSR_P3_Pos)                      /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P4_Pos                       (4)                                            /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P4_Msk                       (0x1U << PORT_OSR_P4_Pos)                      /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P5_Pos                       (5)                                            /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P5_Msk                       (0x1U << PORT_OSR_P5_Pos)                      /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P6_Pos                       (6)                                            /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P6_Msk                       (0x1U << PORT_OSR_P6_Pos)                      /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P7_Pos                       (7)                                            /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P7_Msk                       (0x1U << PORT_OSR_P7_Pos)                      /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P8_Pos                       (8)                                            /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P8_Msk                       (0x1U << PORT_OSR_P8_Pos)                      /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P9_Pos                       (9)                                            /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P9_Msk                       (0x1U << PORT_OSR_P9_Pos)                      /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P10_Pos                      (10)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P10_Msk                      (0x1U << PORT_OSR_P10_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P11_Pos                      (11)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P11_Msk                      (0x1U << PORT_OSR_P11_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P12_Pos                      (12)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P12_Msk                      (0x1U << PORT_OSR_P12_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P13_Pos                      (13)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P13_Msk                      (0x1U << PORT_OSR_P13_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P14_Pos                      (14)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P14_Msk                      (0x1U << PORT_OSR_P14_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P15_Pos                      (15)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P15_Msk                      (0x1U << PORT_OSR_P15_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P16_Pos                      (16)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P16_Msk                      (0x1U << PORT_OSR_P16_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P17_Pos                      (17)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P17_Msk                      (0x1U << PORT_OSR_P17_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P18_Pos                      (18)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P18_Msk                      (0x1U << PORT_OSR_P18_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P19_Pos                      (19)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P19_Msk                      (0x1U << PORT_OSR_P19_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P20_Pos                      (20)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P20_Msk                      (0x1U << PORT_OSR_P20_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P21_Pos                      (21)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P21_Msk                      (0x1U << PORT_OSR_P21_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P22_Pos                      (22)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P22_Msk                      (0x1U << PORT_OSR_P22_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P23_Pos                      (23)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P23_Msk                      (0x1U << PORT_OSR_P23_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P24_Pos                      (24)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P24_Msk                      (0x1U << PORT_OSR_P24_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P25_Pos                      (25)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P25_Msk                      (0x1U << PORT_OSR_P25_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P26_Pos                      (26)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P26_Msk                      (0x1U << PORT_OSR_P26_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P27_Pos                      (27)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P27_Msk                      (0x1U << PORT_OSR_P27_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P28_Pos                      (28)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P28_Msk                      (0x1U << PORT_OSR_P28_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P29_Pos                      (29)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P29_Msk                      (0x1U << PORT_OSR_P29_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P30_Pos                      (30)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P30_Msk                      (0x1U << PORT_OSR_P30_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_P31_Pos                      (31)                                           /**< (PORT_OSR) Output Status Position */
#define PORT_OSR_P31_Msk                      (0x1U << PORT_OSR_P31_Pos)                     /**< (PORT_OSR) Output Status Mask */
#define PORT_OSR_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_OSR) Register Mask  */
#define PORT_OSR_P_Pos                        (0)                                            /**< (PORT_OSR Position) Output Status */
#define PORT_OSR_P_Msk                        (0xFFFFFFFFU << PORT_OSR_P_Pos)                /**< (PORT_OSR Mask) P */
#define PORT_OSR_P(value)                     (PORT_OSR_P_Msk & ((value) << PORT_OSR_P_Pos))

/* -------- PORT_IFER : (PORT Offset: 0x20) (/W 32) Glitch Input Filter Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Input Filter Enable                           */
    uint32_t P1:1;                      /**< bit:      1  Input Filter Enable                           */
    uint32_t P2:1;                      /**< bit:      2  Input Filter Enable                           */
    uint32_t P3:1;                      /**< bit:      3  Input Filter Enable                           */
    uint32_t P4:1;                      /**< bit:      4  Input Filter Enable                           */
    uint32_t P5:1;                      /**< bit:      5  Input Filter Enable                           */
    uint32_t P6:1;                      /**< bit:      6  Input Filter Enable                           */
    uint32_t P7:1;                      /**< bit:      7  Input Filter Enable                           */
    uint32_t P8:1;                      /**< bit:      8  Input Filter Enable                           */
    uint32_t P9:1;                      /**< bit:      9  Input Filter Enable                           */
    uint32_t P10:1;                     /**< bit:     10  Input Filter Enable                           */
    uint32_t P11:1;                     /**< bit:     11  Input Filter Enable                           */
    uint32_t P12:1;                     /**< bit:     12  Input Filter Enable                           */
    uint32_t P13:1;                     /**< bit:     13  Input Filter Enable                           */
    uint32_t P14:1;                     /**< bit:     14  Input Filter Enable                           */
    uint32_t P15:1;                     /**< bit:     15  Input Filter Enable                           */
    uint32_t P16:1;                     /**< bit:     16  Input Filter Enable                           */
    uint32_t P17:1;                     /**< bit:     17  Input Filter Enable                           */
    uint32_t P18:1;                     /**< bit:     18  Input Filter Enable                           */
    uint32_t P19:1;                     /**< bit:     19  Input Filter Enable                           */
    uint32_t P20:1;                     /**< bit:     20  Input Filter Enable                           */
    uint32_t P21:1;                     /**< bit:     21  Input Filter Enable                           */
    uint32_t P22:1;                     /**< bit:     22  Input Filter Enable                           */
    uint32_t P23:1;                     /**< bit:     23  Input Filter Enable                           */
    uint32_t P24:1;                     /**< bit:     24  Input Filter Enable                           */
    uint32_t P25:1;                     /**< bit:     25  Input Filter Enable                           */
    uint32_t P26:1;                     /**< bit:     26  Input Filter Enable                           */
    uint32_t P27:1;                     /**< bit:     27  Input Filter Enable                           */
    uint32_t P28:1;                     /**< bit:     28  Input Filter Enable                           */
    uint32_t P29:1;                     /**< bit:     29  Input Filter Enable                           */
    uint32_t P30:1;                     /**< bit:     30  Input Filter Enable                           */
    uint32_t P31:1;                     /**< bit:     31  Input Filter Enable                           */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Input Filter Enable                           */
  };
  uint32_t w;
} __PORT_IFER_bits_t;

#define PORT_IFER_P0_Pos                      (0)                                            /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P0_Msk                      (0x1U << PORT_IFER_P0_Pos)                     /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P1_Pos                      (1)                                            /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P1_Msk                      (0x1U << PORT_IFER_P1_Pos)                     /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P2_Pos                      (2)                                            /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P2_Msk                      (0x1U << PORT_IFER_P2_Pos)                     /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P3_Pos                      (3)                                            /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P3_Msk                      (0x1U << PORT_IFER_P3_Pos)                     /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P4_Pos                      (4)                                            /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P4_Msk                      (0x1U << PORT_IFER_P4_Pos)                     /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P5_Pos                      (5)                                            /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P5_Msk                      (0x1U << PORT_IFER_P5_Pos)                     /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P6_Pos                      (6)                                            /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P6_Msk                      (0x1U << PORT_IFER_P6_Pos)                     /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P7_Pos                      (7)                                            /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P7_Msk                      (0x1U << PORT_IFER_P7_Pos)                     /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P8_Pos                      (8)                                            /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P8_Msk                      (0x1U << PORT_IFER_P8_Pos)                     /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P9_Pos                      (9)                                            /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P9_Msk                      (0x1U << PORT_IFER_P9_Pos)                     /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P10_Pos                     (10)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P10_Msk                     (0x1U << PORT_IFER_P10_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P11_Pos                     (11)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P11_Msk                     (0x1U << PORT_IFER_P11_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P12_Pos                     (12)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P12_Msk                     (0x1U << PORT_IFER_P12_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P13_Pos                     (13)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P13_Msk                     (0x1U << PORT_IFER_P13_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P14_Pos                     (14)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P14_Msk                     (0x1U << PORT_IFER_P14_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P15_Pos                     (15)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P15_Msk                     (0x1U << PORT_IFER_P15_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P16_Pos                     (16)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P16_Msk                     (0x1U << PORT_IFER_P16_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P17_Pos                     (17)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P17_Msk                     (0x1U << PORT_IFER_P17_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P18_Pos                     (18)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P18_Msk                     (0x1U << PORT_IFER_P18_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P19_Pos                     (19)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P19_Msk                     (0x1U << PORT_IFER_P19_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P20_Pos                     (20)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P20_Msk                     (0x1U << PORT_IFER_P20_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P21_Pos                     (21)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P21_Msk                     (0x1U << PORT_IFER_P21_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P22_Pos                     (22)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P22_Msk                     (0x1U << PORT_IFER_P22_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P23_Pos                     (23)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P23_Msk                     (0x1U << PORT_IFER_P23_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P24_Pos                     (24)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P24_Msk                     (0x1U << PORT_IFER_P24_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P25_Pos                     (25)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P25_Msk                     (0x1U << PORT_IFER_P25_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P26_Pos                     (26)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P26_Msk                     (0x1U << PORT_IFER_P26_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P27_Pos                     (27)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P27_Msk                     (0x1U << PORT_IFER_P27_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P28_Pos                     (28)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P28_Msk                     (0x1U << PORT_IFER_P28_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P29_Pos                     (29)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P29_Msk                     (0x1U << PORT_IFER_P29_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P30_Pos                     (30)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P30_Msk                     (0x1U << PORT_IFER_P30_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_P31_Pos                     (31)                                           /**< (PORT_IFER) Input Filter Enable Position */
#define PORT_IFER_P31_Msk                     (0x1U << PORT_IFER_P31_Pos)                    /**< (PORT_IFER) Input Filter Enable Mask */
#define PORT_IFER_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_IFER) Register Mask  */
#define PORT_IFER_P_Pos                       (0)                                            /**< (PORT_IFER Position) Input Filter Enable */
#define PORT_IFER_P_Msk                       (0xFFFFFFFFU << PORT_IFER_P_Pos)               /**< (PORT_IFER Mask) P */
#define PORT_IFER_P(value)                    (PORT_IFER_P_Msk & ((value) << PORT_IFER_P_Pos))

/* -------- PORT_IFDR : (PORT Offset: 0x24) (/W 32) Glitch Input Filter Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Input Filter Disable                          */
    uint32_t P1:1;                      /**< bit:      1  Input Filter Disable                          */
    uint32_t P2:1;                      /**< bit:      2  Input Filter Disable                          */
    uint32_t P3:1;                      /**< bit:      3  Input Filter Disable                          */
    uint32_t P4:1;                      /**< bit:      4  Input Filter Disable                          */
    uint32_t P5:1;                      /**< bit:      5  Input Filter Disable                          */
    uint32_t P6:1;                      /**< bit:      6  Input Filter Disable                          */
    uint32_t P7:1;                      /**< bit:      7  Input Filter Disable                          */
    uint32_t P8:1;                      /**< bit:      8  Input Filter Disable                          */
    uint32_t P9:1;                      /**< bit:      9  Input Filter Disable                          */
    uint32_t P10:1;                     /**< bit:     10  Input Filter Disable                          */
    uint32_t P11:1;                     /**< bit:     11  Input Filter Disable                          */
    uint32_t P12:1;                     /**< bit:     12  Input Filter Disable                          */
    uint32_t P13:1;                     /**< bit:     13  Input Filter Disable                          */
    uint32_t P14:1;                     /**< bit:     14  Input Filter Disable                          */
    uint32_t P15:1;                     /**< bit:     15  Input Filter Disable                          */
    uint32_t P16:1;                     /**< bit:     16  Input Filter Disable                          */
    uint32_t P17:1;                     /**< bit:     17  Input Filter Disable                          */
    uint32_t P18:1;                     /**< bit:     18  Input Filter Disable                          */
    uint32_t P19:1;                     /**< bit:     19  Input Filter Disable                          */
    uint32_t P20:1;                     /**< bit:     20  Input Filter Disable                          */
    uint32_t P21:1;                     /**< bit:     21  Input Filter Disable                          */
    uint32_t P22:1;                     /**< bit:     22  Input Filter Disable                          */
    uint32_t P23:1;                     /**< bit:     23  Input Filter Disable                          */
    uint32_t P24:1;                     /**< bit:     24  Input Filter Disable                          */
    uint32_t P25:1;                     /**< bit:     25  Input Filter Disable                          */
    uint32_t P26:1;                     /**< bit:     26  Input Filter Disable                          */
    uint32_t P27:1;                     /**< bit:     27  Input Filter Disable                          */
    uint32_t P28:1;                     /**< bit:     28  Input Filter Disable                          */
    uint32_t P29:1;                     /**< bit:     29  Input Filter Disable                          */
    uint32_t P30:1;                     /**< bit:     30  Input Filter Disable                          */
    uint32_t P31:1;                     /**< bit:     31  Input Filter Disable                          */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Input Filter Disable                          */
  };
  uint32_t w;
} __PORT_IFDR_bits_t;

#define PORT_IFDR_P0_Pos                      (0)                                            /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P0_Msk                      (0x1U << PORT_IFDR_P0_Pos)                     /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P1_Pos                      (1)                                            /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P1_Msk                      (0x1U << PORT_IFDR_P1_Pos)                     /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P2_Pos                      (2)                                            /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P2_Msk                      (0x1U << PORT_IFDR_P2_Pos)                     /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P3_Pos                      (3)                                            /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P3_Msk                      (0x1U << PORT_IFDR_P3_Pos)                     /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P4_Pos                      (4)                                            /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P4_Msk                      (0x1U << PORT_IFDR_P4_Pos)                     /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P5_Pos                      (5)                                            /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P5_Msk                      (0x1U << PORT_IFDR_P5_Pos)                     /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P6_Pos                      (6)                                            /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P6_Msk                      (0x1U << PORT_IFDR_P6_Pos)                     /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P7_Pos                      (7)                                            /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P7_Msk                      (0x1U << PORT_IFDR_P7_Pos)                     /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P8_Pos                      (8)                                            /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P8_Msk                      (0x1U << PORT_IFDR_P8_Pos)                     /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P9_Pos                      (9)                                            /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P9_Msk                      (0x1U << PORT_IFDR_P9_Pos)                     /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P10_Pos                     (10)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P10_Msk                     (0x1U << PORT_IFDR_P10_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P11_Pos                     (11)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P11_Msk                     (0x1U << PORT_IFDR_P11_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P12_Pos                     (12)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P12_Msk                     (0x1U << PORT_IFDR_P12_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P13_Pos                     (13)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P13_Msk                     (0x1U << PORT_IFDR_P13_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P14_Pos                     (14)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P14_Msk                     (0x1U << PORT_IFDR_P14_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P15_Pos                     (15)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P15_Msk                     (0x1U << PORT_IFDR_P15_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P16_Pos                     (16)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P16_Msk                     (0x1U << PORT_IFDR_P16_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P17_Pos                     (17)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P17_Msk                     (0x1U << PORT_IFDR_P17_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P18_Pos                     (18)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P18_Msk                     (0x1U << PORT_IFDR_P18_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P19_Pos                     (19)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P19_Msk                     (0x1U << PORT_IFDR_P19_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P20_Pos                     (20)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P20_Msk                     (0x1U << PORT_IFDR_P20_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P21_Pos                     (21)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P21_Msk                     (0x1U << PORT_IFDR_P21_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P22_Pos                     (22)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P22_Msk                     (0x1U << PORT_IFDR_P22_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P23_Pos                     (23)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P23_Msk                     (0x1U << PORT_IFDR_P23_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P24_Pos                     (24)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P24_Msk                     (0x1U << PORT_IFDR_P24_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P25_Pos                     (25)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P25_Msk                     (0x1U << PORT_IFDR_P25_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P26_Pos                     (26)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P26_Msk                     (0x1U << PORT_IFDR_P26_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P27_Pos                     (27)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P27_Msk                     (0x1U << PORT_IFDR_P27_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P28_Pos                     (28)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P28_Msk                     (0x1U << PORT_IFDR_P28_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P29_Pos                     (29)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P29_Msk                     (0x1U << PORT_IFDR_P29_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P30_Pos                     (30)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P30_Msk                     (0x1U << PORT_IFDR_P30_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_P31_Pos                     (31)                                           /**< (PORT_IFDR) Input Filter Disable Position */
#define PORT_IFDR_P31_Msk                     (0x1U << PORT_IFDR_P31_Pos)                    /**< (PORT_IFDR) Input Filter Disable Mask */
#define PORT_IFDR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_IFDR) Register Mask  */
#define PORT_IFDR_P_Pos                       (0)                                            /**< (PORT_IFDR Position) Input Filter Disable */
#define PORT_IFDR_P_Msk                       (0xFFFFFFFFU << PORT_IFDR_P_Pos)               /**< (PORT_IFDR Mask) P */
#define PORT_IFDR_P(value)                    (PORT_IFDR_P_Msk & ((value) << PORT_IFDR_P_Pos))

/* -------- PORT_IFSR : (PORT Offset: 0x28) (R/ 32) Glitch Input Filter Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Input Filter Status                           */
    uint32_t P1:1;                      /**< bit:      1  Input Filter Status                           */
    uint32_t P2:1;                      /**< bit:      2  Input Filter Status                           */
    uint32_t P3:1;                      /**< bit:      3  Input Filter Status                           */
    uint32_t P4:1;                      /**< bit:      4  Input Filter Status                           */
    uint32_t P5:1;                      /**< bit:      5  Input Filter Status                           */
    uint32_t P6:1;                      /**< bit:      6  Input Filter Status                           */
    uint32_t P7:1;                      /**< bit:      7  Input Filter Status                           */
    uint32_t P8:1;                      /**< bit:      8  Input Filter Status                           */
    uint32_t P9:1;                      /**< bit:      9  Input Filter Status                           */
    uint32_t P10:1;                     /**< bit:     10  Input Filter Status                           */
    uint32_t P11:1;                     /**< bit:     11  Input Filter Status                           */
    uint32_t P12:1;                     /**< bit:     12  Input Filter Status                           */
    uint32_t P13:1;                     /**< bit:     13  Input Filter Status                           */
    uint32_t P14:1;                     /**< bit:     14  Input Filter Status                           */
    uint32_t P15:1;                     /**< bit:     15  Input Filter Status                           */
    uint32_t P16:1;                     /**< bit:     16  Input Filter Status                           */
    uint32_t P17:1;                     /**< bit:     17  Input Filter Status                           */
    uint32_t P18:1;                     /**< bit:     18  Input Filter Status                           */
    uint32_t P19:1;                     /**< bit:     19  Input Filter Status                           */
    uint32_t P20:1;                     /**< bit:     20  Input Filter Status                           */
    uint32_t P21:1;                     /**< bit:     21  Input Filter Status                           */
    uint32_t P22:1;                     /**< bit:     22  Input Filter Status                           */
    uint32_t P23:1;                     /**< bit:     23  Input Filter Status                           */
    uint32_t P24:1;                     /**< bit:     24  Input Filter Status                           */
    uint32_t P25:1;                     /**< bit:     25  Input Filter Status                           */
    uint32_t P26:1;                     /**< bit:     26  Input Filter Status                           */
    uint32_t P27:1;                     /**< bit:     27  Input Filter Status                           */
    uint32_t P28:1;                     /**< bit:     28  Input Filter Status                           */
    uint32_t P29:1;                     /**< bit:     29  Input Filter Status                           */
    uint32_t P30:1;                     /**< bit:     30  Input Filter Status                           */
    uint32_t P31:1;                     /**< bit:     31  Input Filter Status                           */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Input Filter Status                           */
  };
  uint32_t w;
} __PORT_IFSR_bits_t;

#define PORT_IFSR_P0_Pos                      (0)                                            /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P0_Msk                      (0x1U << PORT_IFSR_P0_Pos)                     /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P1_Pos                      (1)                                            /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P1_Msk                      (0x1U << PORT_IFSR_P1_Pos)                     /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P2_Pos                      (2)                                            /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P2_Msk                      (0x1U << PORT_IFSR_P2_Pos)                     /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P3_Pos                      (3)                                            /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P3_Msk                      (0x1U << PORT_IFSR_P3_Pos)                     /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P4_Pos                      (4)                                            /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P4_Msk                      (0x1U << PORT_IFSR_P4_Pos)                     /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P5_Pos                      (5)                                            /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P5_Msk                      (0x1U << PORT_IFSR_P5_Pos)                     /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P6_Pos                      (6)                                            /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P6_Msk                      (0x1U << PORT_IFSR_P6_Pos)                     /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P7_Pos                      (7)                                            /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P7_Msk                      (0x1U << PORT_IFSR_P7_Pos)                     /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P8_Pos                      (8)                                            /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P8_Msk                      (0x1U << PORT_IFSR_P8_Pos)                     /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P9_Pos                      (9)                                            /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P9_Msk                      (0x1U << PORT_IFSR_P9_Pos)                     /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P10_Pos                     (10)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P10_Msk                     (0x1U << PORT_IFSR_P10_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P11_Pos                     (11)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P11_Msk                     (0x1U << PORT_IFSR_P11_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P12_Pos                     (12)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P12_Msk                     (0x1U << PORT_IFSR_P12_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P13_Pos                     (13)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P13_Msk                     (0x1U << PORT_IFSR_P13_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P14_Pos                     (14)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P14_Msk                     (0x1U << PORT_IFSR_P14_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P15_Pos                     (15)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P15_Msk                     (0x1U << PORT_IFSR_P15_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P16_Pos                     (16)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P16_Msk                     (0x1U << PORT_IFSR_P16_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P17_Pos                     (17)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P17_Msk                     (0x1U << PORT_IFSR_P17_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P18_Pos                     (18)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P18_Msk                     (0x1U << PORT_IFSR_P18_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P19_Pos                     (19)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P19_Msk                     (0x1U << PORT_IFSR_P19_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P20_Pos                     (20)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P20_Msk                     (0x1U << PORT_IFSR_P20_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P21_Pos                     (21)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P21_Msk                     (0x1U << PORT_IFSR_P21_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P22_Pos                     (22)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P22_Msk                     (0x1U << PORT_IFSR_P22_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P23_Pos                     (23)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P23_Msk                     (0x1U << PORT_IFSR_P23_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P24_Pos                     (24)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P24_Msk                     (0x1U << PORT_IFSR_P24_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P25_Pos                     (25)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P25_Msk                     (0x1U << PORT_IFSR_P25_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P26_Pos                     (26)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P26_Msk                     (0x1U << PORT_IFSR_P26_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P27_Pos                     (27)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P27_Msk                     (0x1U << PORT_IFSR_P27_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P28_Pos                     (28)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P28_Msk                     (0x1U << PORT_IFSR_P28_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P29_Pos                     (29)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P29_Msk                     (0x1U << PORT_IFSR_P29_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P30_Pos                     (30)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P30_Msk                     (0x1U << PORT_IFSR_P30_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_P31_Pos                     (31)                                           /**< (PORT_IFSR) Input Filter Status Position */
#define PORT_IFSR_P31_Msk                     (0x1U << PORT_IFSR_P31_Pos)                    /**< (PORT_IFSR) Input Filter Status Mask */
#define PORT_IFSR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_IFSR) Register Mask  */
#define PORT_IFSR_P_Pos                       (0)                                            /**< (PORT_IFSR Position) Input Filter Status */
#define PORT_IFSR_P_Msk                       (0xFFFFFFFFU << PORT_IFSR_P_Pos)               /**< (PORT_IFSR Mask) P */
#define PORT_IFSR_P(value)                    (PORT_IFSR_P_Msk & ((value) << PORT_IFSR_P_Pos))

/* -------- PORT_SODR : (PORT Offset: 0x30) (/W 32) Set Output Data Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Set Output Data                               */
    uint32_t P1:1;                      /**< bit:      1  Set Output Data                               */
    uint32_t P2:1;                      /**< bit:      2  Set Output Data                               */
    uint32_t P3:1;                      /**< bit:      3  Set Output Data                               */
    uint32_t P4:1;                      /**< bit:      4  Set Output Data                               */
    uint32_t P5:1;                      /**< bit:      5  Set Output Data                               */
    uint32_t P6:1;                      /**< bit:      6  Set Output Data                               */
    uint32_t P7:1;                      /**< bit:      7  Set Output Data                               */
    uint32_t P8:1;                      /**< bit:      8  Set Output Data                               */
    uint32_t P9:1;                      /**< bit:      9  Set Output Data                               */
    uint32_t P10:1;                     /**< bit:     10  Set Output Data                               */
    uint32_t P11:1;                     /**< bit:     11  Set Output Data                               */
    uint32_t P12:1;                     /**< bit:     12  Set Output Data                               */
    uint32_t P13:1;                     /**< bit:     13  Set Output Data                               */
    uint32_t P14:1;                     /**< bit:     14  Set Output Data                               */
    uint32_t P15:1;                     /**< bit:     15  Set Output Data                               */
    uint32_t P16:1;                     /**< bit:     16  Set Output Data                               */
    uint32_t P17:1;                     /**< bit:     17  Set Output Data                               */
    uint32_t P18:1;                     /**< bit:     18  Set Output Data                               */
    uint32_t P19:1;                     /**< bit:     19  Set Output Data                               */
    uint32_t P20:1;                     /**< bit:     20  Set Output Data                               */
    uint32_t P21:1;                     /**< bit:     21  Set Output Data                               */
    uint32_t P22:1;                     /**< bit:     22  Set Output Data                               */
    uint32_t P23:1;                     /**< bit:     23  Set Output Data                               */
    uint32_t P24:1;                     /**< bit:     24  Set Output Data                               */
    uint32_t P25:1;                     /**< bit:     25  Set Output Data                               */
    uint32_t P26:1;                     /**< bit:     26  Set Output Data                               */
    uint32_t P27:1;                     /**< bit:     27  Set Output Data                               */
    uint32_t P28:1;                     /**< bit:     28  Set Output Data                               */
    uint32_t P29:1;                     /**< bit:     29  Set Output Data                               */
    uint32_t P30:1;                     /**< bit:     30  Set Output Data                               */
    uint32_t P31:1;                     /**< bit:     31  Set Output Data                               */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Set Output Data                               */
  };
  uint32_t w;
} __PORT_SODR_bits_t;

#define PORT_SODR_P0_Pos                      (0)                                            /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P0_Msk                      (0x1U << PORT_SODR_P0_Pos)                     /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P1_Pos                      (1)                                            /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P1_Msk                      (0x1U << PORT_SODR_P1_Pos)                     /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P2_Pos                      (2)                                            /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P2_Msk                      (0x1U << PORT_SODR_P2_Pos)                     /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P3_Pos                      (3)                                            /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P3_Msk                      (0x1U << PORT_SODR_P3_Pos)                     /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P4_Pos                      (4)                                            /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P4_Msk                      (0x1U << PORT_SODR_P4_Pos)                     /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P5_Pos                      (5)                                            /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P5_Msk                      (0x1U << PORT_SODR_P5_Pos)                     /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P6_Pos                      (6)                                            /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P6_Msk                      (0x1U << PORT_SODR_P6_Pos)                     /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P7_Pos                      (7)                                            /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P7_Msk                      (0x1U << PORT_SODR_P7_Pos)                     /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P8_Pos                      (8)                                            /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P8_Msk                      (0x1U << PORT_SODR_P8_Pos)                     /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P9_Pos                      (9)                                            /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P9_Msk                      (0x1U << PORT_SODR_P9_Pos)                     /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P10_Pos                     (10)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P10_Msk                     (0x1U << PORT_SODR_P10_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P11_Pos                     (11)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P11_Msk                     (0x1U << PORT_SODR_P11_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P12_Pos                     (12)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P12_Msk                     (0x1U << PORT_SODR_P12_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P13_Pos                     (13)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P13_Msk                     (0x1U << PORT_SODR_P13_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P14_Pos                     (14)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P14_Msk                     (0x1U << PORT_SODR_P14_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P15_Pos                     (15)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P15_Msk                     (0x1U << PORT_SODR_P15_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P16_Pos                     (16)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P16_Msk                     (0x1U << PORT_SODR_P16_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P17_Pos                     (17)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P17_Msk                     (0x1U << PORT_SODR_P17_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P18_Pos                     (18)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P18_Msk                     (0x1U << PORT_SODR_P18_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P19_Pos                     (19)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P19_Msk                     (0x1U << PORT_SODR_P19_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P20_Pos                     (20)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P20_Msk                     (0x1U << PORT_SODR_P20_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P21_Pos                     (21)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P21_Msk                     (0x1U << PORT_SODR_P21_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P22_Pos                     (22)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P22_Msk                     (0x1U << PORT_SODR_P22_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P23_Pos                     (23)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P23_Msk                     (0x1U << PORT_SODR_P23_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P24_Pos                     (24)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P24_Msk                     (0x1U << PORT_SODR_P24_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P25_Pos                     (25)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P25_Msk                     (0x1U << PORT_SODR_P25_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P26_Pos                     (26)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P26_Msk                     (0x1U << PORT_SODR_P26_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P27_Pos                     (27)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P27_Msk                     (0x1U << PORT_SODR_P27_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P28_Pos                     (28)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P28_Msk                     (0x1U << PORT_SODR_P28_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P29_Pos                     (29)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P29_Msk                     (0x1U << PORT_SODR_P29_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P30_Pos                     (30)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P30_Msk                     (0x1U << PORT_SODR_P30_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_P31_Pos                     (31)                                           /**< (PORT_SODR) Set Output Data Position */
#define PORT_SODR_P31_Msk                     (0x1U << PORT_SODR_P31_Pos)                    /**< (PORT_SODR) Set Output Data Mask */
#define PORT_SODR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_SODR) Register Mask  */
#define PORT_SODR_P_Pos                       (0)                                            /**< (PORT_SODR Position) Set Output Data */
#define PORT_SODR_P_Msk                       (0xFFFFFFFFU << PORT_SODR_P_Pos)               /**< (PORT_SODR Mask) P */
#define PORT_SODR_P(value)                    (PORT_SODR_P_Msk & ((value) << PORT_SODR_P_Pos))

/* -------- PORT_CODR : (PORT Offset: 0x34) (/W 32) Clear Output Data Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Clear Output Data                             */
    uint32_t P1:1;                      /**< bit:      1  Clear Output Data                             */
    uint32_t P2:1;                      /**< bit:      2  Clear Output Data                             */
    uint32_t P3:1;                      /**< bit:      3  Clear Output Data                             */
    uint32_t P4:1;                      /**< bit:      4  Clear Output Data                             */
    uint32_t P5:1;                      /**< bit:      5  Clear Output Data                             */
    uint32_t P6:1;                      /**< bit:      6  Clear Output Data                             */
    uint32_t P7:1;                      /**< bit:      7  Clear Output Data                             */
    uint32_t P8:1;                      /**< bit:      8  Clear Output Data                             */
    uint32_t P9:1;                      /**< bit:      9  Clear Output Data                             */
    uint32_t P10:1;                     /**< bit:     10  Clear Output Data                             */
    uint32_t P11:1;                     /**< bit:     11  Clear Output Data                             */
    uint32_t P12:1;                     /**< bit:     12  Clear Output Data                             */
    uint32_t P13:1;                     /**< bit:     13  Clear Output Data                             */
    uint32_t P14:1;                     /**< bit:     14  Clear Output Data                             */
    uint32_t P15:1;                     /**< bit:     15  Clear Output Data                             */
    uint32_t P16:1;                     /**< bit:     16  Clear Output Data                             */
    uint32_t P17:1;                     /**< bit:     17  Clear Output Data                             */
    uint32_t P18:1;                     /**< bit:     18  Clear Output Data                             */
    uint32_t P19:1;                     /**< bit:     19  Clear Output Data                             */
    uint32_t P20:1;                     /**< bit:     20  Clear Output Data                             */
    uint32_t P21:1;                     /**< bit:     21  Clear Output Data                             */
    uint32_t P22:1;                     /**< bit:     22  Clear Output Data                             */
    uint32_t P23:1;                     /**< bit:     23  Clear Output Data                             */
    uint32_t P24:1;                     /**< bit:     24  Clear Output Data                             */
    uint32_t P25:1;                     /**< bit:     25  Clear Output Data                             */
    uint32_t P26:1;                     /**< bit:     26  Clear Output Data                             */
    uint32_t P27:1;                     /**< bit:     27  Clear Output Data                             */
    uint32_t P28:1;                     /**< bit:     28  Clear Output Data                             */
    uint32_t P29:1;                     /**< bit:     29  Clear Output Data                             */
    uint32_t P30:1;                     /**< bit:     30  Clear Output Data                             */
    uint32_t P31:1;                     /**< bit:     31  Clear Output Data                             */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Clear Output Data                             */
  };
  uint32_t w;
} __PORT_CODR_bits_t;

#define PORT_CODR_P0_Pos                      (0)                                            /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P0_Msk                      (0x1U << PORT_CODR_P0_Pos)                     /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P1_Pos                      (1)                                            /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P1_Msk                      (0x1U << PORT_CODR_P1_Pos)                     /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P2_Pos                      (2)                                            /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P2_Msk                      (0x1U << PORT_CODR_P2_Pos)                     /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P3_Pos                      (3)                                            /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P3_Msk                      (0x1U << PORT_CODR_P3_Pos)                     /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P4_Pos                      (4)                                            /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P4_Msk                      (0x1U << PORT_CODR_P4_Pos)                     /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P5_Pos                      (5)                                            /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P5_Msk                      (0x1U << PORT_CODR_P5_Pos)                     /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P6_Pos                      (6)                                            /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P6_Msk                      (0x1U << PORT_CODR_P6_Pos)                     /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P7_Pos                      (7)                                            /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P7_Msk                      (0x1U << PORT_CODR_P7_Pos)                     /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P8_Pos                      (8)                                            /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P8_Msk                      (0x1U << PORT_CODR_P8_Pos)                     /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P9_Pos                      (9)                                            /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P9_Msk                      (0x1U << PORT_CODR_P9_Pos)                     /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P10_Pos                     (10)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P10_Msk                     (0x1U << PORT_CODR_P10_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P11_Pos                     (11)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P11_Msk                     (0x1U << PORT_CODR_P11_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P12_Pos                     (12)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P12_Msk                     (0x1U << PORT_CODR_P12_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P13_Pos                     (13)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P13_Msk                     (0x1U << PORT_CODR_P13_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P14_Pos                     (14)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P14_Msk                     (0x1U << PORT_CODR_P14_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P15_Pos                     (15)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P15_Msk                     (0x1U << PORT_CODR_P15_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P16_Pos                     (16)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P16_Msk                     (0x1U << PORT_CODR_P16_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P17_Pos                     (17)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P17_Msk                     (0x1U << PORT_CODR_P17_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P18_Pos                     (18)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P18_Msk                     (0x1U << PORT_CODR_P18_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P19_Pos                     (19)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P19_Msk                     (0x1U << PORT_CODR_P19_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P20_Pos                     (20)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P20_Msk                     (0x1U << PORT_CODR_P20_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P21_Pos                     (21)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P21_Msk                     (0x1U << PORT_CODR_P21_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P22_Pos                     (22)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P22_Msk                     (0x1U << PORT_CODR_P22_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P23_Pos                     (23)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P23_Msk                     (0x1U << PORT_CODR_P23_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P24_Pos                     (24)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P24_Msk                     (0x1U << PORT_CODR_P24_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P25_Pos                     (25)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P25_Msk                     (0x1U << PORT_CODR_P25_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P26_Pos                     (26)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P26_Msk                     (0x1U << PORT_CODR_P26_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P27_Pos                     (27)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P27_Msk                     (0x1U << PORT_CODR_P27_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P28_Pos                     (28)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P28_Msk                     (0x1U << PORT_CODR_P28_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P29_Pos                     (29)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P29_Msk                     (0x1U << PORT_CODR_P29_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P30_Pos                     (30)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P30_Msk                     (0x1U << PORT_CODR_P30_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_P31_Pos                     (31)                                           /**< (PORT_CODR) Clear Output Data Position */
#define PORT_CODR_P31_Msk                     (0x1U << PORT_CODR_P31_Pos)                    /**< (PORT_CODR) Clear Output Data Mask */
#define PORT_CODR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_CODR) Register Mask  */
#define PORT_CODR_P_Pos                       (0)                                            /**< (PORT_CODR Position) Clear Output Data */
#define PORT_CODR_P_Msk                       (0xFFFFFFFFU << PORT_CODR_P_Pos)               /**< (PORT_CODR Mask) P */
#define PORT_CODR_P(value)                    (PORT_CODR_P_Msk & ((value) << PORT_CODR_P_Pos))

/* -------- PORT_ODSR : (PORT Offset: 0x38) (R/W 32) Output Data Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Output Data Status                            */
    uint32_t P1:1;                      /**< bit:      1  Output Data Status                            */
    uint32_t P2:1;                      /**< bit:      2  Output Data Status                            */
    uint32_t P3:1;                      /**< bit:      3  Output Data Status                            */
    uint32_t P4:1;                      /**< bit:      4  Output Data Status                            */
    uint32_t P5:1;                      /**< bit:      5  Output Data Status                            */
    uint32_t P6:1;                      /**< bit:      6  Output Data Status                            */
    uint32_t P7:1;                      /**< bit:      7  Output Data Status                            */
    uint32_t P8:1;                      /**< bit:      8  Output Data Status                            */
    uint32_t P9:1;                      /**< bit:      9  Output Data Status                            */
    uint32_t P10:1;                     /**< bit:     10  Output Data Status                            */
    uint32_t P11:1;                     /**< bit:     11  Output Data Status                            */
    uint32_t P12:1;                     /**< bit:     12  Output Data Status                            */
    uint32_t P13:1;                     /**< bit:     13  Output Data Status                            */
    uint32_t P14:1;                     /**< bit:     14  Output Data Status                            */
    uint32_t P15:1;                     /**< bit:     15  Output Data Status                            */
    uint32_t P16:1;                     /**< bit:     16  Output Data Status                            */
    uint32_t P17:1;                     /**< bit:     17  Output Data Status                            */
    uint32_t P18:1;                     /**< bit:     18  Output Data Status                            */
    uint32_t P19:1;                     /**< bit:     19  Output Data Status                            */
    uint32_t P20:1;                     /**< bit:     20  Output Data Status                            */
    uint32_t P21:1;                     /**< bit:     21  Output Data Status                            */
    uint32_t P22:1;                     /**< bit:     22  Output Data Status                            */
    uint32_t P23:1;                     /**< bit:     23  Output Data Status                            */
    uint32_t P24:1;                     /**< bit:     24  Output Data Status                            */
    uint32_t P25:1;                     /**< bit:     25  Output Data Status                            */
    uint32_t P26:1;                     /**< bit:     26  Output Data Status                            */
    uint32_t P27:1;                     /**< bit:     27  Output Data Status                            */
    uint32_t P28:1;                     /**< bit:     28  Output Data Status                            */
    uint32_t P29:1;                     /**< bit:     29  Output Data Status                            */
    uint32_t P30:1;                     /**< bit:     30  Output Data Status                            */
    uint32_t P31:1;                     /**< bit:     31  Output Data Status                            */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Output Data Status                            */
  };
  uint32_t w;
} __PORT_ODSR_bits_t;

#define PORT_ODSR_P0_Pos                      (0)                                            /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P0_Msk                      (0x1U << PORT_ODSR_P0_Pos)                     /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P1_Pos                      (1)                                            /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P1_Msk                      (0x1U << PORT_ODSR_P1_Pos)                     /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P2_Pos                      (2)                                            /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P2_Msk                      (0x1U << PORT_ODSR_P2_Pos)                     /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P3_Pos                      (3)                                            /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P3_Msk                      (0x1U << PORT_ODSR_P3_Pos)                     /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P4_Pos                      (4)                                            /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P4_Msk                      (0x1U << PORT_ODSR_P4_Pos)                     /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P5_Pos                      (5)                                            /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P5_Msk                      (0x1U << PORT_ODSR_P5_Pos)                     /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P6_Pos                      (6)                                            /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P6_Msk                      (0x1U << PORT_ODSR_P6_Pos)                     /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P7_Pos                      (7)                                            /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P7_Msk                      (0x1U << PORT_ODSR_P7_Pos)                     /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P8_Pos                      (8)                                            /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P8_Msk                      (0x1U << PORT_ODSR_P8_Pos)                     /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P9_Pos                      (9)                                            /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P9_Msk                      (0x1U << PORT_ODSR_P9_Pos)                     /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P10_Pos                     (10)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P10_Msk                     (0x1U << PORT_ODSR_P10_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P11_Pos                     (11)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P11_Msk                     (0x1U << PORT_ODSR_P11_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P12_Pos                     (12)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P12_Msk                     (0x1U << PORT_ODSR_P12_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P13_Pos                     (13)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P13_Msk                     (0x1U << PORT_ODSR_P13_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P14_Pos                     (14)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P14_Msk                     (0x1U << PORT_ODSR_P14_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P15_Pos                     (15)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P15_Msk                     (0x1U << PORT_ODSR_P15_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P16_Pos                     (16)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P16_Msk                     (0x1U << PORT_ODSR_P16_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P17_Pos                     (17)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P17_Msk                     (0x1U << PORT_ODSR_P17_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P18_Pos                     (18)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P18_Msk                     (0x1U << PORT_ODSR_P18_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P19_Pos                     (19)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P19_Msk                     (0x1U << PORT_ODSR_P19_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P20_Pos                     (20)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P20_Msk                     (0x1U << PORT_ODSR_P20_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P21_Pos                     (21)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P21_Msk                     (0x1U << PORT_ODSR_P21_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P22_Pos                     (22)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P22_Msk                     (0x1U << PORT_ODSR_P22_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P23_Pos                     (23)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P23_Msk                     (0x1U << PORT_ODSR_P23_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P24_Pos                     (24)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P24_Msk                     (0x1U << PORT_ODSR_P24_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P25_Pos                     (25)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P25_Msk                     (0x1U << PORT_ODSR_P25_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P26_Pos                     (26)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P26_Msk                     (0x1U << PORT_ODSR_P26_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P27_Pos                     (27)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P27_Msk                     (0x1U << PORT_ODSR_P27_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P28_Pos                     (28)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P28_Msk                     (0x1U << PORT_ODSR_P28_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P29_Pos                     (29)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P29_Msk                     (0x1U << PORT_ODSR_P29_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P30_Pos                     (30)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P30_Msk                     (0x1U << PORT_ODSR_P30_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_P31_Pos                     (31)                                           /**< (PORT_ODSR) Output Data Status Position */
#define PORT_ODSR_P31_Msk                     (0x1U << PORT_ODSR_P31_Pos)                    /**< (PORT_ODSR) Output Data Status Mask */
#define PORT_ODSR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_ODSR) Register Mask  */
#define PORT_ODSR_P_Pos                       (0)                                            /**< (PORT_ODSR Position) Output Data Status */
#define PORT_ODSR_P_Msk                       (0xFFFFFFFFU << PORT_ODSR_P_Pos)               /**< (PORT_ODSR Mask) P */
#define PORT_ODSR_P(value)                    (PORT_ODSR_P_Msk & ((value) << PORT_ODSR_P_Pos))

/* -------- PORT_PDSR : (PORT Offset: 0x3c) (R/ 32) Pin Data Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Output Data Status                            */
    uint32_t P1:1;                      /**< bit:      1  Output Data Status                            */
    uint32_t P2:1;                      /**< bit:      2  Output Data Status                            */
    uint32_t P3:1;                      /**< bit:      3  Output Data Status                            */
    uint32_t P4:1;                      /**< bit:      4  Output Data Status                            */
    uint32_t P5:1;                      /**< bit:      5  Output Data Status                            */
    uint32_t P6:1;                      /**< bit:      6  Output Data Status                            */
    uint32_t P7:1;                      /**< bit:      7  Output Data Status                            */
    uint32_t P8:1;                      /**< bit:      8  Output Data Status                            */
    uint32_t P9:1;                      /**< bit:      9  Output Data Status                            */
    uint32_t P10:1;                     /**< bit:     10  Output Data Status                            */
    uint32_t P11:1;                     /**< bit:     11  Output Data Status                            */
    uint32_t P12:1;                     /**< bit:     12  Output Data Status                            */
    uint32_t P13:1;                     /**< bit:     13  Output Data Status                            */
    uint32_t P14:1;                     /**< bit:     14  Output Data Status                            */
    uint32_t P15:1;                     /**< bit:     15  Output Data Status                            */
    uint32_t P16:1;                     /**< bit:     16  Output Data Status                            */
    uint32_t P17:1;                     /**< bit:     17  Output Data Status                            */
    uint32_t P18:1;                     /**< bit:     18  Output Data Status                            */
    uint32_t P19:1;                     /**< bit:     19  Output Data Status                            */
    uint32_t P20:1;                     /**< bit:     20  Output Data Status                            */
    uint32_t P21:1;                     /**< bit:     21  Output Data Status                            */
    uint32_t P22:1;                     /**< bit:     22  Output Data Status                            */
    uint32_t P23:1;                     /**< bit:     23  Output Data Status                            */
    uint32_t P24:1;                     /**< bit:     24  Output Data Status                            */
    uint32_t P25:1;                     /**< bit:     25  Output Data Status                            */
    uint32_t P26:1;                     /**< bit:     26  Output Data Status                            */
    uint32_t P27:1;                     /**< bit:     27  Output Data Status                            */
    uint32_t P28:1;                     /**< bit:     28  Output Data Status                            */
    uint32_t P29:1;                     /**< bit:     29  Output Data Status                            */
    uint32_t P30:1;                     /**< bit:     30  Output Data Status                            */
    uint32_t P31:1;                     /**< bit:     31  Output Data Status                            */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Output Data Status                            */
  };
  uint32_t w;
} __PORT_PDSR_bits_t;

#define PORT_PDSR_P0_Pos                      (0)                                            /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P0_Msk                      (0x1U << PORT_PDSR_P0_Pos)                     /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P1_Pos                      (1)                                            /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P1_Msk                      (0x1U << PORT_PDSR_P1_Pos)                     /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P2_Pos                      (2)                                            /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P2_Msk                      (0x1U << PORT_PDSR_P2_Pos)                     /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P3_Pos                      (3)                                            /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P3_Msk                      (0x1U << PORT_PDSR_P3_Pos)                     /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P4_Pos                      (4)                                            /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P4_Msk                      (0x1U << PORT_PDSR_P4_Pos)                     /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P5_Pos                      (5)                                            /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P5_Msk                      (0x1U << PORT_PDSR_P5_Pos)                     /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P6_Pos                      (6)                                            /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P6_Msk                      (0x1U << PORT_PDSR_P6_Pos)                     /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P7_Pos                      (7)                                            /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P7_Msk                      (0x1U << PORT_PDSR_P7_Pos)                     /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P8_Pos                      (8)                                            /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P8_Msk                      (0x1U << PORT_PDSR_P8_Pos)                     /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P9_Pos                      (9)                                            /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P9_Msk                      (0x1U << PORT_PDSR_P9_Pos)                     /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P10_Pos                     (10)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P10_Msk                     (0x1U << PORT_PDSR_P10_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P11_Pos                     (11)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P11_Msk                     (0x1U << PORT_PDSR_P11_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P12_Pos                     (12)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P12_Msk                     (0x1U << PORT_PDSR_P12_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P13_Pos                     (13)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P13_Msk                     (0x1U << PORT_PDSR_P13_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P14_Pos                     (14)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P14_Msk                     (0x1U << PORT_PDSR_P14_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P15_Pos                     (15)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P15_Msk                     (0x1U << PORT_PDSR_P15_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P16_Pos                     (16)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P16_Msk                     (0x1U << PORT_PDSR_P16_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P17_Pos                     (17)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P17_Msk                     (0x1U << PORT_PDSR_P17_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P18_Pos                     (18)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P18_Msk                     (0x1U << PORT_PDSR_P18_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P19_Pos                     (19)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P19_Msk                     (0x1U << PORT_PDSR_P19_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P20_Pos                     (20)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P20_Msk                     (0x1U << PORT_PDSR_P20_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P21_Pos                     (21)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P21_Msk                     (0x1U << PORT_PDSR_P21_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P22_Pos                     (22)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P22_Msk                     (0x1U << PORT_PDSR_P22_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P23_Pos                     (23)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P23_Msk                     (0x1U << PORT_PDSR_P23_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P24_Pos                     (24)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P24_Msk                     (0x1U << PORT_PDSR_P24_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P25_Pos                     (25)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P25_Msk                     (0x1U << PORT_PDSR_P25_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P26_Pos                     (26)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P26_Msk                     (0x1U << PORT_PDSR_P26_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P27_Pos                     (27)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P27_Msk                     (0x1U << PORT_PDSR_P27_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P28_Pos                     (28)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P28_Msk                     (0x1U << PORT_PDSR_P28_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P29_Pos                     (29)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P29_Msk                     (0x1U << PORT_PDSR_P29_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P30_Pos                     (30)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P30_Msk                     (0x1U << PORT_PDSR_P30_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_P31_Pos                     (31)                                           /**< (PORT_PDSR) Output Data Status Position */
#define PORT_PDSR_P31_Msk                     (0x1U << PORT_PDSR_P31_Pos)                    /**< (PORT_PDSR) Output Data Status Mask */
#define PORT_PDSR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_PDSR) Register Mask  */
#define PORT_PDSR_P_Pos                       (0)                                            /**< (PORT_PDSR Position) Output Data Status */
#define PORT_PDSR_P_Msk                       (0xFFFFFFFFU << PORT_PDSR_P_Pos)               /**< (PORT_PDSR Mask) P */
#define PORT_PDSR_P(value)                    (PORT_PDSR_P_Msk & ((value) << PORT_PDSR_P_Pos))

/* -------- PORT_IER : (PORT Offset: 0x40) (/W 32) Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Input Change Interrupt Enable                 */
    uint32_t P1:1;                      /**< bit:      1  Input Change Interrupt Enable                 */
    uint32_t P2:1;                      /**< bit:      2  Input Change Interrupt Enable                 */
    uint32_t P3:1;                      /**< bit:      3  Input Change Interrupt Enable                 */
    uint32_t P4:1;                      /**< bit:      4  Input Change Interrupt Enable                 */
    uint32_t P5:1;                      /**< bit:      5  Input Change Interrupt Enable                 */
    uint32_t P6:1;                      /**< bit:      6  Input Change Interrupt Enable                 */
    uint32_t P7:1;                      /**< bit:      7  Input Change Interrupt Enable                 */
    uint32_t P8:1;                      /**< bit:      8  Input Change Interrupt Enable                 */
    uint32_t P9:1;                      /**< bit:      9  Input Change Interrupt Enable                 */
    uint32_t P10:1;                     /**< bit:     10  Input Change Interrupt Enable                 */
    uint32_t P11:1;                     /**< bit:     11  Input Change Interrupt Enable                 */
    uint32_t P12:1;                     /**< bit:     12  Input Change Interrupt Enable                 */
    uint32_t P13:1;                     /**< bit:     13  Input Change Interrupt Enable                 */
    uint32_t P14:1;                     /**< bit:     14  Input Change Interrupt Enable                 */
    uint32_t P15:1;                     /**< bit:     15  Input Change Interrupt Enable                 */
    uint32_t P16:1;                     /**< bit:     16  Input Change Interrupt Enable                 */
    uint32_t P17:1;                     /**< bit:     17  Input Change Interrupt Enable                 */
    uint32_t P18:1;                     /**< bit:     18  Input Change Interrupt Enable                 */
    uint32_t P19:1;                     /**< bit:     19  Input Change Interrupt Enable                 */
    uint32_t P20:1;                     /**< bit:     20  Input Change Interrupt Enable                 */
    uint32_t P21:1;                     /**< bit:     21  Input Change Interrupt Enable                 */
    uint32_t P22:1;                     /**< bit:     22  Input Change Interrupt Enable                 */
    uint32_t P23:1;                     /**< bit:     23  Input Change Interrupt Enable                 */
    uint32_t P24:1;                     /**< bit:     24  Input Change Interrupt Enable                 */
    uint32_t P25:1;                     /**< bit:     25  Input Change Interrupt Enable                 */
    uint32_t P26:1;                     /**< bit:     26  Input Change Interrupt Enable                 */
    uint32_t P27:1;                     /**< bit:     27  Input Change Interrupt Enable                 */
    uint32_t P28:1;                     /**< bit:     28  Input Change Interrupt Enable                 */
    uint32_t P29:1;                     /**< bit:     29  Input Change Interrupt Enable                 */
    uint32_t P30:1;                     /**< bit:     30  Input Change Interrupt Enable                 */
    uint32_t P31:1;                     /**< bit:     31  Input Change Interrupt Enable                 */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Input Change Interrupt Enable                 */
  };
  uint32_t w;
} __PORT_IER_bits_t;

#define PORT_IER_P0_Pos                       (0)                                            /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P0_Msk                       (0x1U << PORT_IER_P0_Pos)                      /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P1_Pos                       (1)                                            /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P1_Msk                       (0x1U << PORT_IER_P1_Pos)                      /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P2_Pos                       (2)                                            /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P2_Msk                       (0x1U << PORT_IER_P2_Pos)                      /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P3_Pos                       (3)                                            /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P3_Msk                       (0x1U << PORT_IER_P3_Pos)                      /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P4_Pos                       (4)                                            /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P4_Msk                       (0x1U << PORT_IER_P4_Pos)                      /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P5_Pos                       (5)                                            /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P5_Msk                       (0x1U << PORT_IER_P5_Pos)                      /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P6_Pos                       (6)                                            /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P6_Msk                       (0x1U << PORT_IER_P6_Pos)                      /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P7_Pos                       (7)                                            /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P7_Msk                       (0x1U << PORT_IER_P7_Pos)                      /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P8_Pos                       (8)                                            /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P8_Msk                       (0x1U << PORT_IER_P8_Pos)                      /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P9_Pos                       (9)                                            /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P9_Msk                       (0x1U << PORT_IER_P9_Pos)                      /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P10_Pos                      (10)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P10_Msk                      (0x1U << PORT_IER_P10_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P11_Pos                      (11)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P11_Msk                      (0x1U << PORT_IER_P11_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P12_Pos                      (12)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P12_Msk                      (0x1U << PORT_IER_P12_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P13_Pos                      (13)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P13_Msk                      (0x1U << PORT_IER_P13_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P14_Pos                      (14)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P14_Msk                      (0x1U << PORT_IER_P14_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P15_Pos                      (15)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P15_Msk                      (0x1U << PORT_IER_P15_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P16_Pos                      (16)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P16_Msk                      (0x1U << PORT_IER_P16_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P17_Pos                      (17)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P17_Msk                      (0x1U << PORT_IER_P17_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P18_Pos                      (18)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P18_Msk                      (0x1U << PORT_IER_P18_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P19_Pos                      (19)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P19_Msk                      (0x1U << PORT_IER_P19_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P20_Pos                      (20)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P20_Msk                      (0x1U << PORT_IER_P20_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P21_Pos                      (21)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P21_Msk                      (0x1U << PORT_IER_P21_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P22_Pos                      (22)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P22_Msk                      (0x1U << PORT_IER_P22_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P23_Pos                      (23)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P23_Msk                      (0x1U << PORT_IER_P23_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P24_Pos                      (24)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P24_Msk                      (0x1U << PORT_IER_P24_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P25_Pos                      (25)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P25_Msk                      (0x1U << PORT_IER_P25_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P26_Pos                      (26)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P26_Msk                      (0x1U << PORT_IER_P26_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P27_Pos                      (27)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P27_Msk                      (0x1U << PORT_IER_P27_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P28_Pos                      (28)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P28_Msk                      (0x1U << PORT_IER_P28_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P29_Pos                      (29)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P29_Msk                      (0x1U << PORT_IER_P29_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P30_Pos                      (30)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P30_Msk                      (0x1U << PORT_IER_P30_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_P31_Pos                      (31)                                           /**< (PORT_IER) Input Change Interrupt Enable Position */
#define PORT_IER_P31_Msk                      (0x1U << PORT_IER_P31_Pos)                     /**< (PORT_IER) Input Change Interrupt Enable Mask */
#define PORT_IER_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_IER) Register Mask  */
#define PORT_IER_P_Pos                        (0)                                            /**< (PORT_IER Position) Input Change Interrupt Enable */
#define PORT_IER_P_Msk                        (0xFFFFFFFFU << PORT_IER_P_Pos)                /**< (PORT_IER Mask) P */
#define PORT_IER_P(value)                     (PORT_IER_P_Msk & ((value) << PORT_IER_P_Pos))

/* -------- PORT_IDR : (PORT Offset: 0x44) (/W 32) Interrupt Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Input Change Interrupt Disable                */
    uint32_t P1:1;                      /**< bit:      1  Input Change Interrupt Disable                */
    uint32_t P2:1;                      /**< bit:      2  Input Change Interrupt Disable                */
    uint32_t P3:1;                      /**< bit:      3  Input Change Interrupt Disable                */
    uint32_t P4:1;                      /**< bit:      4  Input Change Interrupt Disable                */
    uint32_t P5:1;                      /**< bit:      5  Input Change Interrupt Disable                */
    uint32_t P6:1;                      /**< bit:      6  Input Change Interrupt Disable                */
    uint32_t P7:1;                      /**< bit:      7  Input Change Interrupt Disable                */
    uint32_t P8:1;                      /**< bit:      8  Input Change Interrupt Disable                */
    uint32_t P9:1;                      /**< bit:      9  Input Change Interrupt Disable                */
    uint32_t P10:1;                     /**< bit:     10  Input Change Interrupt Disable                */
    uint32_t P11:1;                     /**< bit:     11  Input Change Interrupt Disable                */
    uint32_t P12:1;                     /**< bit:     12  Input Change Interrupt Disable                */
    uint32_t P13:1;                     /**< bit:     13  Input Change Interrupt Disable                */
    uint32_t P14:1;                     /**< bit:     14  Input Change Interrupt Disable                */
    uint32_t P15:1;                     /**< bit:     15  Input Change Interrupt Disable                */
    uint32_t P16:1;                     /**< bit:     16  Input Change Interrupt Disable                */
    uint32_t P17:1;                     /**< bit:     17  Input Change Interrupt Disable                */
    uint32_t P18:1;                     /**< bit:     18  Input Change Interrupt Disable                */
    uint32_t P19:1;                     /**< bit:     19  Input Change Interrupt Disable                */
    uint32_t P20:1;                     /**< bit:     20  Input Change Interrupt Disable                */
    uint32_t P21:1;                     /**< bit:     21  Input Change Interrupt Disable                */
    uint32_t P22:1;                     /**< bit:     22  Input Change Interrupt Disable                */
    uint32_t P23:1;                     /**< bit:     23  Input Change Interrupt Disable                */
    uint32_t P24:1;                     /**< bit:     24  Input Change Interrupt Disable                */
    uint32_t P25:1;                     /**< bit:     25  Input Change Interrupt Disable                */
    uint32_t P26:1;                     /**< bit:     26  Input Change Interrupt Disable                */
    uint32_t P27:1;                     /**< bit:     27  Input Change Interrupt Disable                */
    uint32_t P28:1;                     /**< bit:     28  Input Change Interrupt Disable                */
    uint32_t P29:1;                     /**< bit:     29  Input Change Interrupt Disable                */
    uint32_t P30:1;                     /**< bit:     30  Input Change Interrupt Disable                */
    uint32_t P31:1;                     /**< bit:     31  Input Change Interrupt Disable                */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Input Change Interrupt Disable                */
  };
  uint32_t w;
} __PORT_IDR_bits_t;

#define PORT_IDR_P0_Pos                       (0)                                            /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P0_Msk                       (0x1U << PORT_IDR_P0_Pos)                      /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P1_Pos                       (1)                                            /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P1_Msk                       (0x1U << PORT_IDR_P1_Pos)                      /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P2_Pos                       (2)                                            /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P2_Msk                       (0x1U << PORT_IDR_P2_Pos)                      /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P3_Pos                       (3)                                            /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P3_Msk                       (0x1U << PORT_IDR_P3_Pos)                      /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P4_Pos                       (4)                                            /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P4_Msk                       (0x1U << PORT_IDR_P4_Pos)                      /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P5_Pos                       (5)                                            /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P5_Msk                       (0x1U << PORT_IDR_P5_Pos)                      /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P6_Pos                       (6)                                            /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P6_Msk                       (0x1U << PORT_IDR_P6_Pos)                      /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P7_Pos                       (7)                                            /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P7_Msk                       (0x1U << PORT_IDR_P7_Pos)                      /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P8_Pos                       (8)                                            /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P8_Msk                       (0x1U << PORT_IDR_P8_Pos)                      /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P9_Pos                       (9)                                            /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P9_Msk                       (0x1U << PORT_IDR_P9_Pos)                      /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P10_Pos                      (10)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P10_Msk                      (0x1U << PORT_IDR_P10_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P11_Pos                      (11)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P11_Msk                      (0x1U << PORT_IDR_P11_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P12_Pos                      (12)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P12_Msk                      (0x1U << PORT_IDR_P12_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P13_Pos                      (13)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P13_Msk                      (0x1U << PORT_IDR_P13_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P14_Pos                      (14)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P14_Msk                      (0x1U << PORT_IDR_P14_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P15_Pos                      (15)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P15_Msk                      (0x1U << PORT_IDR_P15_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P16_Pos                      (16)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P16_Msk                      (0x1U << PORT_IDR_P16_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P17_Pos                      (17)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P17_Msk                      (0x1U << PORT_IDR_P17_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P18_Pos                      (18)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P18_Msk                      (0x1U << PORT_IDR_P18_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P19_Pos                      (19)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P19_Msk                      (0x1U << PORT_IDR_P19_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P20_Pos                      (20)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P20_Msk                      (0x1U << PORT_IDR_P20_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P21_Pos                      (21)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P21_Msk                      (0x1U << PORT_IDR_P21_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P22_Pos                      (22)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P22_Msk                      (0x1U << PORT_IDR_P22_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P23_Pos                      (23)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P23_Msk                      (0x1U << PORT_IDR_P23_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P24_Pos                      (24)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P24_Msk                      (0x1U << PORT_IDR_P24_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P25_Pos                      (25)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P25_Msk                      (0x1U << PORT_IDR_P25_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P26_Pos                      (26)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P26_Msk                      (0x1U << PORT_IDR_P26_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P27_Pos                      (27)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P27_Msk                      (0x1U << PORT_IDR_P27_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P28_Pos                      (28)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P28_Msk                      (0x1U << PORT_IDR_P28_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P29_Pos                      (29)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P29_Msk                      (0x1U << PORT_IDR_P29_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P30_Pos                      (30)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P30_Msk                      (0x1U << PORT_IDR_P30_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_P31_Pos                      (31)                                           /**< (PORT_IDR) Input Change Interrupt Disable Position */
#define PORT_IDR_P31_Msk                      (0x1U << PORT_IDR_P31_Pos)                     /**< (PORT_IDR) Input Change Interrupt Disable Mask */
#define PORT_IDR_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_IDR) Register Mask  */
#define PORT_IDR_P_Pos                        (0)                                            /**< (PORT_IDR Position) Input Change Interrupt Disable */
#define PORT_IDR_P_Msk                        (0xFFFFFFFFU << PORT_IDR_P_Pos)                /**< (PORT_IDR Mask) P */
#define PORT_IDR_P(value)                     (PORT_IDR_P_Msk & ((value) << PORT_IDR_P_Pos))

/* -------- PORT_IMR : (PORT Offset: 0x48) (R/ 32) Interrupt Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Input Change Interrupt Mask                   */
    uint32_t P1:1;                      /**< bit:      1  Input Change Interrupt Mask                   */
    uint32_t P2:1;                      /**< bit:      2  Input Change Interrupt Mask                   */
    uint32_t P3:1;                      /**< bit:      3  Input Change Interrupt Mask                   */
    uint32_t P4:1;                      /**< bit:      4  Input Change Interrupt Mask                   */
    uint32_t P5:1;                      /**< bit:      5  Input Change Interrupt Mask                   */
    uint32_t P6:1;                      /**< bit:      6  Input Change Interrupt Mask                   */
    uint32_t P7:1;                      /**< bit:      7  Input Change Interrupt Mask                   */
    uint32_t P8:1;                      /**< bit:      8  Input Change Interrupt Mask                   */
    uint32_t P9:1;                      /**< bit:      9  Input Change Interrupt Mask                   */
    uint32_t P10:1;                     /**< bit:     10  Input Change Interrupt Mask                   */
    uint32_t P11:1;                     /**< bit:     11  Input Change Interrupt Mask                   */
    uint32_t P12:1;                     /**< bit:     12  Input Change Interrupt Mask                   */
    uint32_t P13:1;                     /**< bit:     13  Input Change Interrupt Mask                   */
    uint32_t P14:1;                     /**< bit:     14  Input Change Interrupt Mask                   */
    uint32_t P15:1;                     /**< bit:     15  Input Change Interrupt Mask                   */
    uint32_t P16:1;                     /**< bit:     16  Input Change Interrupt Mask                   */
    uint32_t P17:1;                     /**< bit:     17  Input Change Interrupt Mask                   */
    uint32_t P18:1;                     /**< bit:     18  Input Change Interrupt Mask                   */
    uint32_t P19:1;                     /**< bit:     19  Input Change Interrupt Mask                   */
    uint32_t P20:1;                     /**< bit:     20  Input Change Interrupt Mask                   */
    uint32_t P21:1;                     /**< bit:     21  Input Change Interrupt Mask                   */
    uint32_t P22:1;                     /**< bit:     22  Input Change Interrupt Mask                   */
    uint32_t P23:1;                     /**< bit:     23  Input Change Interrupt Mask                   */
    uint32_t P24:1;                     /**< bit:     24  Input Change Interrupt Mask                   */
    uint32_t P25:1;                     /**< bit:     25  Input Change Interrupt Mask                   */
    uint32_t P26:1;                     /**< bit:     26  Input Change Interrupt Mask                   */
    uint32_t P27:1;                     /**< bit:     27  Input Change Interrupt Mask                   */
    uint32_t P28:1;                     /**< bit:     28  Input Change Interrupt Mask                   */
    uint32_t P29:1;                     /**< bit:     29  Input Change Interrupt Mask                   */
    uint32_t P30:1;                     /**< bit:     30  Input Change Interrupt Mask                   */
    uint32_t P31:1;                     /**< bit:     31  Input Change Interrupt Mask                   */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Input Change Interrupt Mask                   */
  };
  uint32_t w;
} __PORT_IMR_bits_t;

#define PORT_IMR_P0_Pos                       (0)                                            /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P0_Msk                       (0x1U << PORT_IMR_P0_Pos)                      /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P1_Pos                       (1)                                            /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P1_Msk                       (0x1U << PORT_IMR_P1_Pos)                      /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P2_Pos                       (2)                                            /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P2_Msk                       (0x1U << PORT_IMR_P2_Pos)                      /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P3_Pos                       (3)                                            /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P3_Msk                       (0x1U << PORT_IMR_P3_Pos)                      /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P4_Pos                       (4)                                            /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P4_Msk                       (0x1U << PORT_IMR_P4_Pos)                      /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P5_Pos                       (5)                                            /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P5_Msk                       (0x1U << PORT_IMR_P5_Pos)                      /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P6_Pos                       (6)                                            /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P6_Msk                       (0x1U << PORT_IMR_P6_Pos)                      /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P7_Pos                       (7)                                            /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P7_Msk                       (0x1U << PORT_IMR_P7_Pos)                      /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P8_Pos                       (8)                                            /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P8_Msk                       (0x1U << PORT_IMR_P8_Pos)                      /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P9_Pos                       (9)                                            /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P9_Msk                       (0x1U << PORT_IMR_P9_Pos)                      /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P10_Pos                      (10)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P10_Msk                      (0x1U << PORT_IMR_P10_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P11_Pos                      (11)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P11_Msk                      (0x1U << PORT_IMR_P11_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P12_Pos                      (12)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P12_Msk                      (0x1U << PORT_IMR_P12_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P13_Pos                      (13)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P13_Msk                      (0x1U << PORT_IMR_P13_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P14_Pos                      (14)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P14_Msk                      (0x1U << PORT_IMR_P14_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P15_Pos                      (15)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P15_Msk                      (0x1U << PORT_IMR_P15_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P16_Pos                      (16)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P16_Msk                      (0x1U << PORT_IMR_P16_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P17_Pos                      (17)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P17_Msk                      (0x1U << PORT_IMR_P17_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P18_Pos                      (18)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P18_Msk                      (0x1U << PORT_IMR_P18_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P19_Pos                      (19)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P19_Msk                      (0x1U << PORT_IMR_P19_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P20_Pos                      (20)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P20_Msk                      (0x1U << PORT_IMR_P20_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P21_Pos                      (21)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P21_Msk                      (0x1U << PORT_IMR_P21_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P22_Pos                      (22)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P22_Msk                      (0x1U << PORT_IMR_P22_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P23_Pos                      (23)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P23_Msk                      (0x1U << PORT_IMR_P23_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P24_Pos                      (24)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P24_Msk                      (0x1U << PORT_IMR_P24_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P25_Pos                      (25)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P25_Msk                      (0x1U << PORT_IMR_P25_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P26_Pos                      (26)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P26_Msk                      (0x1U << PORT_IMR_P26_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P27_Pos                      (27)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P27_Msk                      (0x1U << PORT_IMR_P27_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P28_Pos                      (28)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P28_Msk                      (0x1U << PORT_IMR_P28_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P29_Pos                      (29)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P29_Msk                      (0x1U << PORT_IMR_P29_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P30_Pos                      (30)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P30_Msk                      (0x1U << PORT_IMR_P30_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_P31_Pos                      (31)                                           /**< (PORT_IMR) Input Change Interrupt Mask Position */
#define PORT_IMR_P31_Msk                      (0x1U << PORT_IMR_P31_Pos)                     /**< (PORT_IMR) Input Change Interrupt Mask Mask */
#define PORT_IMR_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_IMR) Register Mask  */
#define PORT_IMR_P_Pos                        (0)                                            /**< (PORT_IMR Position) Input Change Interrupt Mask */
#define PORT_IMR_P_Msk                        (0xFFFFFFFFU << PORT_IMR_P_Pos)                /**< (PORT_IMR Mask) P */
#define PORT_IMR_P(value)                     (PORT_IMR_P_Msk & ((value) << PORT_IMR_P_Pos))

/* -------- PORT_ISR : (PORT Offset: 0x4c) (R/ 32) Interrupt Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Input Change Interrupt Status                 */
    uint32_t P1:1;                      /**< bit:      1  Input Change Interrupt Status                 */
    uint32_t P2:1;                      /**< bit:      2  Input Change Interrupt Status                 */
    uint32_t P3:1;                      /**< bit:      3  Input Change Interrupt Status                 */
    uint32_t P4:1;                      /**< bit:      4  Input Change Interrupt Status                 */
    uint32_t P5:1;                      /**< bit:      5  Input Change Interrupt Status                 */
    uint32_t P6:1;                      /**< bit:      6  Input Change Interrupt Status                 */
    uint32_t P7:1;                      /**< bit:      7  Input Change Interrupt Status                 */
    uint32_t P8:1;                      /**< bit:      8  Input Change Interrupt Status                 */
    uint32_t P9:1;                      /**< bit:      9  Input Change Interrupt Status                 */
    uint32_t P10:1;                     /**< bit:     10  Input Change Interrupt Status                 */
    uint32_t P11:1;                     /**< bit:     11  Input Change Interrupt Status                 */
    uint32_t P12:1;                     /**< bit:     12  Input Change Interrupt Status                 */
    uint32_t P13:1;                     /**< bit:     13  Input Change Interrupt Status                 */
    uint32_t P14:1;                     /**< bit:     14  Input Change Interrupt Status                 */
    uint32_t P15:1;                     /**< bit:     15  Input Change Interrupt Status                 */
    uint32_t P16:1;                     /**< bit:     16  Input Change Interrupt Status                 */
    uint32_t P17:1;                     /**< bit:     17  Input Change Interrupt Status                 */
    uint32_t P18:1;                     /**< bit:     18  Input Change Interrupt Status                 */
    uint32_t P19:1;                     /**< bit:     19  Input Change Interrupt Status                 */
    uint32_t P20:1;                     /**< bit:     20  Input Change Interrupt Status                 */
    uint32_t P21:1;                     /**< bit:     21  Input Change Interrupt Status                 */
    uint32_t P22:1;                     /**< bit:     22  Input Change Interrupt Status                 */
    uint32_t P23:1;                     /**< bit:     23  Input Change Interrupt Status                 */
    uint32_t P24:1;                     /**< bit:     24  Input Change Interrupt Status                 */
    uint32_t P25:1;                     /**< bit:     25  Input Change Interrupt Status                 */
    uint32_t P26:1;                     /**< bit:     26  Input Change Interrupt Status                 */
    uint32_t P27:1;                     /**< bit:     27  Input Change Interrupt Status                 */
    uint32_t P28:1;                     /**< bit:     28  Input Change Interrupt Status                 */
    uint32_t P29:1;                     /**< bit:     29  Input Change Interrupt Status                 */
    uint32_t P30:1;                     /**< bit:     30  Input Change Interrupt Status                 */
    uint32_t P31:1;                     /**< bit:     31  Input Change Interrupt Status                 */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Input Change Interrupt Status                 */
  };
  uint32_t w;
} __PORT_ISR_bits_t;

#define PORT_ISR_P0_Pos                       (0)                                            /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P0_Msk                       (0x1U << PORT_ISR_P0_Pos)                      /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P1_Pos                       (1)                                            /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P1_Msk                       (0x1U << PORT_ISR_P1_Pos)                      /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P2_Pos                       (2)                                            /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P2_Msk                       (0x1U << PORT_ISR_P2_Pos)                      /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P3_Pos                       (3)                                            /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P3_Msk                       (0x1U << PORT_ISR_P3_Pos)                      /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P4_Pos                       (4)                                            /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P4_Msk                       (0x1U << PORT_ISR_P4_Pos)                      /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P5_Pos                       (5)                                            /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P5_Msk                       (0x1U << PORT_ISR_P5_Pos)                      /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P6_Pos                       (6)                                            /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P6_Msk                       (0x1U << PORT_ISR_P6_Pos)                      /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P7_Pos                       (7)                                            /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P7_Msk                       (0x1U << PORT_ISR_P7_Pos)                      /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P8_Pos                       (8)                                            /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P8_Msk                       (0x1U << PORT_ISR_P8_Pos)                      /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P9_Pos                       (9)                                            /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P9_Msk                       (0x1U << PORT_ISR_P9_Pos)                      /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P10_Pos                      (10)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P10_Msk                      (0x1U << PORT_ISR_P10_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P11_Pos                      (11)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P11_Msk                      (0x1U << PORT_ISR_P11_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P12_Pos                      (12)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P12_Msk                      (0x1U << PORT_ISR_P12_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P13_Pos                      (13)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P13_Msk                      (0x1U << PORT_ISR_P13_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P14_Pos                      (14)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P14_Msk                      (0x1U << PORT_ISR_P14_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P15_Pos                      (15)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P15_Msk                      (0x1U << PORT_ISR_P15_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P16_Pos                      (16)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P16_Msk                      (0x1U << PORT_ISR_P16_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P17_Pos                      (17)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P17_Msk                      (0x1U << PORT_ISR_P17_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P18_Pos                      (18)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P18_Msk                      (0x1U << PORT_ISR_P18_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P19_Pos                      (19)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P19_Msk                      (0x1U << PORT_ISR_P19_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P20_Pos                      (20)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P20_Msk                      (0x1U << PORT_ISR_P20_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P21_Pos                      (21)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P21_Msk                      (0x1U << PORT_ISR_P21_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P22_Pos                      (22)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P22_Msk                      (0x1U << PORT_ISR_P22_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P23_Pos                      (23)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P23_Msk                      (0x1U << PORT_ISR_P23_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P24_Pos                      (24)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P24_Msk                      (0x1U << PORT_ISR_P24_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P25_Pos                      (25)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P25_Msk                      (0x1U << PORT_ISR_P25_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P26_Pos                      (26)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P26_Msk                      (0x1U << PORT_ISR_P26_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P27_Pos                      (27)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P27_Msk                      (0x1U << PORT_ISR_P27_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P28_Pos                      (28)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P28_Msk                      (0x1U << PORT_ISR_P28_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P29_Pos                      (29)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P29_Msk                      (0x1U << PORT_ISR_P29_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P30_Pos                      (30)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P30_Msk                      (0x1U << PORT_ISR_P30_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_P31_Pos                      (31)                                           /**< (PORT_ISR) Input Change Interrupt Status Position */
#define PORT_ISR_P31_Msk                      (0x1U << PORT_ISR_P31_Pos)                     /**< (PORT_ISR) Input Change Interrupt Status Mask */
#define PORT_ISR_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_ISR) Register Mask  */
#define PORT_ISR_P_Pos                        (0)                                            /**< (PORT_ISR Position) Input Change Interrupt Status */
#define PORT_ISR_P_Msk                        (0xFFFFFFFFU << PORT_ISR_P_Pos)                /**< (PORT_ISR Mask) P */
#define PORT_ISR_P(value)                     (PORT_ISR_P_Msk & ((value) << PORT_ISR_P_Pos))

/* -------- PORT_MDER : (PORT Offset: 0x50) (/W 32) Multi-driver Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Multi-drive Enable                            */
    uint32_t P1:1;                      /**< bit:      1  Multi-drive Enable                            */
    uint32_t P2:1;                      /**< bit:      2  Multi-drive Enable                            */
    uint32_t P3:1;                      /**< bit:      3  Multi-drive Enable                            */
    uint32_t P4:1;                      /**< bit:      4  Multi-drive Enable                            */
    uint32_t P5:1;                      /**< bit:      5  Multi-drive Enable                            */
    uint32_t P6:1;                      /**< bit:      6  Multi-drive Enable                            */
    uint32_t P7:1;                      /**< bit:      7  Multi-drive Enable                            */
    uint32_t P8:1;                      /**< bit:      8  Multi-drive Enable                            */
    uint32_t P9:1;                      /**< bit:      9  Multi-drive Enable                            */
    uint32_t P10:1;                     /**< bit:     10  Multi-drive Enable                            */
    uint32_t P11:1;                     /**< bit:     11  Multi-drive Enable                            */
    uint32_t P12:1;                     /**< bit:     12  Multi-drive Enable                            */
    uint32_t P13:1;                     /**< bit:     13  Multi-drive Enable                            */
    uint32_t P14:1;                     /**< bit:     14  Multi-drive Enable                            */
    uint32_t P15:1;                     /**< bit:     15  Multi-drive Enable                            */
    uint32_t P16:1;                     /**< bit:     16  Multi-drive Enable                            */
    uint32_t P17:1;                     /**< bit:     17  Multi-drive Enable                            */
    uint32_t P18:1;                     /**< bit:     18  Multi-drive Enable                            */
    uint32_t P19:1;                     /**< bit:     19  Multi-drive Enable                            */
    uint32_t P20:1;                     /**< bit:     20  Multi-drive Enable                            */
    uint32_t P21:1;                     /**< bit:     21  Multi-drive Enable                            */
    uint32_t P22:1;                     /**< bit:     22  Multi-drive Enable                            */
    uint32_t P23:1;                     /**< bit:     23  Multi-drive Enable                            */
    uint32_t P24:1;                     /**< bit:     24  Multi-drive Enable                            */
    uint32_t P25:1;                     /**< bit:     25  Multi-drive Enable                            */
    uint32_t P26:1;                     /**< bit:     26  Multi-drive Enable                            */
    uint32_t P27:1;                     /**< bit:     27  Multi-drive Enable                            */
    uint32_t P28:1;                     /**< bit:     28  Multi-drive Enable                            */
    uint32_t P29:1;                     /**< bit:     29  Multi-drive Enable                            */
    uint32_t P30:1;                     /**< bit:     30  Multi-drive Enable                            */
    uint32_t P31:1;                     /**< bit:     31  Multi-drive Enable                            */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Multi-drive Enable                            */
  };
  uint32_t w;
} __PORT_MDER_bits_t;

#define PORT_MDER_P0_Pos                      (0)                                            /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P0_Msk                      (0x1U << PORT_MDER_P0_Pos)                     /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P1_Pos                      (1)                                            /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P1_Msk                      (0x1U << PORT_MDER_P1_Pos)                     /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P2_Pos                      (2)                                            /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P2_Msk                      (0x1U << PORT_MDER_P2_Pos)                     /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P3_Pos                      (3)                                            /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P3_Msk                      (0x1U << PORT_MDER_P3_Pos)                     /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P4_Pos                      (4)                                            /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P4_Msk                      (0x1U << PORT_MDER_P4_Pos)                     /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P5_Pos                      (5)                                            /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P5_Msk                      (0x1U << PORT_MDER_P5_Pos)                     /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P6_Pos                      (6)                                            /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P6_Msk                      (0x1U << PORT_MDER_P6_Pos)                     /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P7_Pos                      (7)                                            /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P7_Msk                      (0x1U << PORT_MDER_P7_Pos)                     /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P8_Pos                      (8)                                            /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P8_Msk                      (0x1U << PORT_MDER_P8_Pos)                     /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P9_Pos                      (9)                                            /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P9_Msk                      (0x1U << PORT_MDER_P9_Pos)                     /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P10_Pos                     (10)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P10_Msk                     (0x1U << PORT_MDER_P10_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P11_Pos                     (11)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P11_Msk                     (0x1U << PORT_MDER_P11_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P12_Pos                     (12)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P12_Msk                     (0x1U << PORT_MDER_P12_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P13_Pos                     (13)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P13_Msk                     (0x1U << PORT_MDER_P13_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P14_Pos                     (14)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P14_Msk                     (0x1U << PORT_MDER_P14_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P15_Pos                     (15)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P15_Msk                     (0x1U << PORT_MDER_P15_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P16_Pos                     (16)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P16_Msk                     (0x1U << PORT_MDER_P16_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P17_Pos                     (17)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P17_Msk                     (0x1U << PORT_MDER_P17_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P18_Pos                     (18)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P18_Msk                     (0x1U << PORT_MDER_P18_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P19_Pos                     (19)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P19_Msk                     (0x1U << PORT_MDER_P19_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P20_Pos                     (20)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P20_Msk                     (0x1U << PORT_MDER_P20_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P21_Pos                     (21)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P21_Msk                     (0x1U << PORT_MDER_P21_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P22_Pos                     (22)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P22_Msk                     (0x1U << PORT_MDER_P22_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P23_Pos                     (23)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P23_Msk                     (0x1U << PORT_MDER_P23_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P24_Pos                     (24)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P24_Msk                     (0x1U << PORT_MDER_P24_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P25_Pos                     (25)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P25_Msk                     (0x1U << PORT_MDER_P25_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P26_Pos                     (26)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P26_Msk                     (0x1U << PORT_MDER_P26_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P27_Pos                     (27)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P27_Msk                     (0x1U << PORT_MDER_P27_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P28_Pos                     (28)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P28_Msk                     (0x1U << PORT_MDER_P28_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P29_Pos                     (29)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P29_Msk                     (0x1U << PORT_MDER_P29_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P30_Pos                     (30)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P30_Msk                     (0x1U << PORT_MDER_P30_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_P31_Pos                     (31)                                           /**< (PORT_MDER) Multi-drive Enable Position */
#define PORT_MDER_P31_Msk                     (0x1U << PORT_MDER_P31_Pos)                    /**< (PORT_MDER) Multi-drive Enable Mask */
#define PORT_MDER_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_MDER) Register Mask  */
#define PORT_MDER_P_Pos                       (0)                                            /**< (PORT_MDER Position) Multi-drive Enable */
#define PORT_MDER_P_Msk                       (0xFFFFFFFFU << PORT_MDER_P_Pos)               /**< (PORT_MDER Mask) P */
#define PORT_MDER_P(value)                    (PORT_MDER_P_Msk & ((value) << PORT_MDER_P_Pos))

/* -------- PORT_MDDR : (PORT Offset: 0x54) (/W 32) Multi-driver Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Multi-drive Disable                           */
    uint32_t P1:1;                      /**< bit:      1  Multi-drive Disable                           */
    uint32_t P2:1;                      /**< bit:      2  Multi-drive Disable                           */
    uint32_t P3:1;                      /**< bit:      3  Multi-drive Disable                           */
    uint32_t P4:1;                      /**< bit:      4  Multi-drive Disable                           */
    uint32_t P5:1;                      /**< bit:      5  Multi-drive Disable                           */
    uint32_t P6:1;                      /**< bit:      6  Multi-drive Disable                           */
    uint32_t P7:1;                      /**< bit:      7  Multi-drive Disable                           */
    uint32_t P8:1;                      /**< bit:      8  Multi-drive Disable                           */
    uint32_t P9:1;                      /**< bit:      9  Multi-drive Disable                           */
    uint32_t P10:1;                     /**< bit:     10  Multi-drive Disable                           */
    uint32_t P11:1;                     /**< bit:     11  Multi-drive Disable                           */
    uint32_t P12:1;                     /**< bit:     12  Multi-drive Disable                           */
    uint32_t P13:1;                     /**< bit:     13  Multi-drive Disable                           */
    uint32_t P14:1;                     /**< bit:     14  Multi-drive Disable                           */
    uint32_t P15:1;                     /**< bit:     15  Multi-drive Disable                           */
    uint32_t P16:1;                     /**< bit:     16  Multi-drive Disable                           */
    uint32_t P17:1;                     /**< bit:     17  Multi-drive Disable                           */
    uint32_t P18:1;                     /**< bit:     18  Multi-drive Disable                           */
    uint32_t P19:1;                     /**< bit:     19  Multi-drive Disable                           */
    uint32_t P20:1;                     /**< bit:     20  Multi-drive Disable                           */
    uint32_t P21:1;                     /**< bit:     21  Multi-drive Disable                           */
    uint32_t P22:1;                     /**< bit:     22  Multi-drive Disable                           */
    uint32_t P23:1;                     /**< bit:     23  Multi-drive Disable                           */
    uint32_t P24:1;                     /**< bit:     24  Multi-drive Disable                           */
    uint32_t P25:1;                     /**< bit:     25  Multi-drive Disable                           */
    uint32_t P26:1;                     /**< bit:     26  Multi-drive Disable                           */
    uint32_t P27:1;                     /**< bit:     27  Multi-drive Disable                           */
    uint32_t P28:1;                     /**< bit:     28  Multi-drive Disable                           */
    uint32_t P29:1;                     /**< bit:     29  Multi-drive Disable                           */
    uint32_t P30:1;                     /**< bit:     30  Multi-drive Disable                           */
    uint32_t P31:1;                     /**< bit:     31  Multi-drive Disable                           */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Multi-drive Disable                           */
  };
  uint32_t w;
} __PORT_MDDR_bits_t;

#define PORT_MDDR_P0_Pos                      (0)                                            /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P0_Msk                      (0x1U << PORT_MDDR_P0_Pos)                     /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P1_Pos                      (1)                                            /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P1_Msk                      (0x1U << PORT_MDDR_P1_Pos)                     /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P2_Pos                      (2)                                            /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P2_Msk                      (0x1U << PORT_MDDR_P2_Pos)                     /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P3_Pos                      (3)                                            /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P3_Msk                      (0x1U << PORT_MDDR_P3_Pos)                     /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P4_Pos                      (4)                                            /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P4_Msk                      (0x1U << PORT_MDDR_P4_Pos)                     /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P5_Pos                      (5)                                            /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P5_Msk                      (0x1U << PORT_MDDR_P5_Pos)                     /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P6_Pos                      (6)                                            /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P6_Msk                      (0x1U << PORT_MDDR_P6_Pos)                     /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P7_Pos                      (7)                                            /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P7_Msk                      (0x1U << PORT_MDDR_P7_Pos)                     /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P8_Pos                      (8)                                            /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P8_Msk                      (0x1U << PORT_MDDR_P8_Pos)                     /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P9_Pos                      (9)                                            /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P9_Msk                      (0x1U << PORT_MDDR_P9_Pos)                     /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P10_Pos                     (10)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P10_Msk                     (0x1U << PORT_MDDR_P10_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P11_Pos                     (11)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P11_Msk                     (0x1U << PORT_MDDR_P11_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P12_Pos                     (12)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P12_Msk                     (0x1U << PORT_MDDR_P12_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P13_Pos                     (13)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P13_Msk                     (0x1U << PORT_MDDR_P13_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P14_Pos                     (14)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P14_Msk                     (0x1U << PORT_MDDR_P14_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P15_Pos                     (15)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P15_Msk                     (0x1U << PORT_MDDR_P15_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P16_Pos                     (16)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P16_Msk                     (0x1U << PORT_MDDR_P16_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P17_Pos                     (17)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P17_Msk                     (0x1U << PORT_MDDR_P17_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P18_Pos                     (18)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P18_Msk                     (0x1U << PORT_MDDR_P18_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P19_Pos                     (19)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P19_Msk                     (0x1U << PORT_MDDR_P19_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P20_Pos                     (20)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P20_Msk                     (0x1U << PORT_MDDR_P20_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P21_Pos                     (21)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P21_Msk                     (0x1U << PORT_MDDR_P21_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P22_Pos                     (22)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P22_Msk                     (0x1U << PORT_MDDR_P22_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P23_Pos                     (23)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P23_Msk                     (0x1U << PORT_MDDR_P23_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P24_Pos                     (24)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P24_Msk                     (0x1U << PORT_MDDR_P24_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P25_Pos                     (25)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P25_Msk                     (0x1U << PORT_MDDR_P25_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P26_Pos                     (26)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P26_Msk                     (0x1U << PORT_MDDR_P26_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P27_Pos                     (27)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P27_Msk                     (0x1U << PORT_MDDR_P27_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P28_Pos                     (28)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P28_Msk                     (0x1U << PORT_MDDR_P28_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P29_Pos                     (29)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P29_Msk                     (0x1U << PORT_MDDR_P29_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P30_Pos                     (30)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P30_Msk                     (0x1U << PORT_MDDR_P30_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_P31_Pos                     (31)                                           /**< (PORT_MDDR) Multi-drive Disable Position */
#define PORT_MDDR_P31_Msk                     (0x1U << PORT_MDDR_P31_Pos)                    /**< (PORT_MDDR) Multi-drive Disable Mask */
#define PORT_MDDR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_MDDR) Register Mask  */
#define PORT_MDDR_P_Pos                       (0)                                            /**< (PORT_MDDR Position) Multi-drive Disable */
#define PORT_MDDR_P_Msk                       (0xFFFFFFFFU << PORT_MDDR_P_Pos)               /**< (PORT_MDDR Mask) P */
#define PORT_MDDR_P(value)                    (PORT_MDDR_P_Msk & ((value) << PORT_MDDR_P_Pos))

/* -------- PORT_MDSR : (PORT Offset: 0x58) (R/ 32) Multi-driver Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Multi-drive Status                            */
    uint32_t P1:1;                      /**< bit:      1  Multi-drive Status                            */
    uint32_t P2:1;                      /**< bit:      2  Multi-drive Status                            */
    uint32_t P3:1;                      /**< bit:      3  Multi-drive Status                            */
    uint32_t P4:1;                      /**< bit:      4  Multi-drive Status                            */
    uint32_t P5:1;                      /**< bit:      5  Multi-drive Status                            */
    uint32_t P6:1;                      /**< bit:      6  Multi-drive Status                            */
    uint32_t P7:1;                      /**< bit:      7  Multi-drive Status                            */
    uint32_t P8:1;                      /**< bit:      8  Multi-drive Status                            */
    uint32_t P9:1;                      /**< bit:      9  Multi-drive Status                            */
    uint32_t P10:1;                     /**< bit:     10  Multi-drive Status                            */
    uint32_t P11:1;                     /**< bit:     11  Multi-drive Status                            */
    uint32_t P12:1;                     /**< bit:     12  Multi-drive Status                            */
    uint32_t P13:1;                     /**< bit:     13  Multi-drive Status                            */
    uint32_t P14:1;                     /**< bit:     14  Multi-drive Status                            */
    uint32_t P15:1;                     /**< bit:     15  Multi-drive Status                            */
    uint32_t P16:1;                     /**< bit:     16  Multi-drive Status                            */
    uint32_t P17:1;                     /**< bit:     17  Multi-drive Status                            */
    uint32_t P18:1;                     /**< bit:     18  Multi-drive Status                            */
    uint32_t P19:1;                     /**< bit:     19  Multi-drive Status                            */
    uint32_t P20:1;                     /**< bit:     20  Multi-drive Status                            */
    uint32_t P21:1;                     /**< bit:     21  Multi-drive Status                            */
    uint32_t P22:1;                     /**< bit:     22  Multi-drive Status                            */
    uint32_t P23:1;                     /**< bit:     23  Multi-drive Status                            */
    uint32_t P24:1;                     /**< bit:     24  Multi-drive Status                            */
    uint32_t P25:1;                     /**< bit:     25  Multi-drive Status                            */
    uint32_t P26:1;                     /**< bit:     26  Multi-drive Status                            */
    uint32_t P27:1;                     /**< bit:     27  Multi-drive Status                            */
    uint32_t P28:1;                     /**< bit:     28  Multi-drive Status                            */
    uint32_t P29:1;                     /**< bit:     29  Multi-drive Status                            */
    uint32_t P30:1;                     /**< bit:     30  Multi-drive Status                            */
    uint32_t P31:1;                     /**< bit:     31  Multi-drive Status                            */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Multi-drive Status                            */
  };
  uint32_t w;
} __PORT_MDSR_bits_t;

#define PORT_MDSR_P0_Pos                      (0)                                            /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P0_Msk                      (0x1U << PORT_MDSR_P0_Pos)                     /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P1_Pos                      (1)                                            /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P1_Msk                      (0x1U << PORT_MDSR_P1_Pos)                     /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P2_Pos                      (2)                                            /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P2_Msk                      (0x1U << PORT_MDSR_P2_Pos)                     /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P3_Pos                      (3)                                            /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P3_Msk                      (0x1U << PORT_MDSR_P3_Pos)                     /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P4_Pos                      (4)                                            /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P4_Msk                      (0x1U << PORT_MDSR_P4_Pos)                     /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P5_Pos                      (5)                                            /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P5_Msk                      (0x1U << PORT_MDSR_P5_Pos)                     /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P6_Pos                      (6)                                            /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P6_Msk                      (0x1U << PORT_MDSR_P6_Pos)                     /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P7_Pos                      (7)                                            /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P7_Msk                      (0x1U << PORT_MDSR_P7_Pos)                     /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P8_Pos                      (8)                                            /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P8_Msk                      (0x1U << PORT_MDSR_P8_Pos)                     /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P9_Pos                      (9)                                            /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P9_Msk                      (0x1U << PORT_MDSR_P9_Pos)                     /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P10_Pos                     (10)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P10_Msk                     (0x1U << PORT_MDSR_P10_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P11_Pos                     (11)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P11_Msk                     (0x1U << PORT_MDSR_P11_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P12_Pos                     (12)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P12_Msk                     (0x1U << PORT_MDSR_P12_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P13_Pos                     (13)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P13_Msk                     (0x1U << PORT_MDSR_P13_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P14_Pos                     (14)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P14_Msk                     (0x1U << PORT_MDSR_P14_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P15_Pos                     (15)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P15_Msk                     (0x1U << PORT_MDSR_P15_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P16_Pos                     (16)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P16_Msk                     (0x1U << PORT_MDSR_P16_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P17_Pos                     (17)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P17_Msk                     (0x1U << PORT_MDSR_P17_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P18_Pos                     (18)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P18_Msk                     (0x1U << PORT_MDSR_P18_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P19_Pos                     (19)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P19_Msk                     (0x1U << PORT_MDSR_P19_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P20_Pos                     (20)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P20_Msk                     (0x1U << PORT_MDSR_P20_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P21_Pos                     (21)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P21_Msk                     (0x1U << PORT_MDSR_P21_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P22_Pos                     (22)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P22_Msk                     (0x1U << PORT_MDSR_P22_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P23_Pos                     (23)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P23_Msk                     (0x1U << PORT_MDSR_P23_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P24_Pos                     (24)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P24_Msk                     (0x1U << PORT_MDSR_P24_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P25_Pos                     (25)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P25_Msk                     (0x1U << PORT_MDSR_P25_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P26_Pos                     (26)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P26_Msk                     (0x1U << PORT_MDSR_P26_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P27_Pos                     (27)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P27_Msk                     (0x1U << PORT_MDSR_P27_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P28_Pos                     (28)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P28_Msk                     (0x1U << PORT_MDSR_P28_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P29_Pos                     (29)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P29_Msk                     (0x1U << PORT_MDSR_P29_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P30_Pos                     (30)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P30_Msk                     (0x1U << PORT_MDSR_P30_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_P31_Pos                     (31)                                           /**< (PORT_MDSR) Multi-drive Status Position */
#define PORT_MDSR_P31_Msk                     (0x1U << PORT_MDSR_P31_Pos)                    /**< (PORT_MDSR) Multi-drive Status Mask */
#define PORT_MDSR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_MDSR) Register Mask  */
#define PORT_MDSR_P_Pos                       (0)                                            /**< (PORT_MDSR Position) Multi-drive Status */
#define PORT_MDSR_P_Msk                       (0xFFFFFFFFU << PORT_MDSR_P_Pos)               /**< (PORT_MDSR Mask) P */
#define PORT_MDSR_P(value)                    (PORT_MDSR_P_Msk & ((value) << PORT_MDSR_P_Pos))

/* -------- PORT_PUDR : (PORT Offset: 0x60) (/W 32) Pull-up Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Pull-Up Disable                               */
    uint32_t P1:1;                      /**< bit:      1  Pull-Up Disable                               */
    uint32_t P2:1;                      /**< bit:      2  Pull-Up Disable                               */
    uint32_t P3:1;                      /**< bit:      3  Pull-Up Disable                               */
    uint32_t P4:1;                      /**< bit:      4  Pull-Up Disable                               */
    uint32_t P5:1;                      /**< bit:      5  Pull-Up Disable                               */
    uint32_t P6:1;                      /**< bit:      6  Pull-Up Disable                               */
    uint32_t P7:1;                      /**< bit:      7  Pull-Up Disable                               */
    uint32_t P8:1;                      /**< bit:      8  Pull-Up Disable                               */
    uint32_t P9:1;                      /**< bit:      9  Pull-Up Disable                               */
    uint32_t P10:1;                     /**< bit:     10  Pull-Up Disable                               */
    uint32_t P11:1;                     /**< bit:     11  Pull-Up Disable                               */
    uint32_t P12:1;                     /**< bit:     12  Pull-Up Disable                               */
    uint32_t P13:1;                     /**< bit:     13  Pull-Up Disable                               */
    uint32_t P14:1;                     /**< bit:     14  Pull-Up Disable                               */
    uint32_t P15:1;                     /**< bit:     15  Pull-Up Disable                               */
    uint32_t P16:1;                     /**< bit:     16  Pull-Up Disable                               */
    uint32_t P17:1;                     /**< bit:     17  Pull-Up Disable                               */
    uint32_t P18:1;                     /**< bit:     18  Pull-Up Disable                               */
    uint32_t P19:1;                     /**< bit:     19  Pull-Up Disable                               */
    uint32_t P20:1;                     /**< bit:     20  Pull-Up Disable                               */
    uint32_t P21:1;                     /**< bit:     21  Pull-Up Disable                               */
    uint32_t P22:1;                     /**< bit:     22  Pull-Up Disable                               */
    uint32_t P23:1;                     /**< bit:     23  Pull-Up Disable                               */
    uint32_t P24:1;                     /**< bit:     24  Pull-Up Disable                               */
    uint32_t P25:1;                     /**< bit:     25  Pull-Up Disable                               */
    uint32_t P26:1;                     /**< bit:     26  Pull-Up Disable                               */
    uint32_t P27:1;                     /**< bit:     27  Pull-Up Disable                               */
    uint32_t P28:1;                     /**< bit:     28  Pull-Up Disable                               */
    uint32_t P29:1;                     /**< bit:     29  Pull-Up Disable                               */
    uint32_t P30:1;                     /**< bit:     30  Pull-Up Disable                               */
    uint32_t P31:1;                     /**< bit:     31  Pull-Up Disable                               */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Pull-Up Disable                               */
  };
  uint32_t w;
} __PORT_PUDR_bits_t;

#define PORT_PUDR_P0_Pos                      (0)                                            /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P0_Msk                      (0x1U << PORT_PUDR_P0_Pos)                     /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P1_Pos                      (1)                                            /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P1_Msk                      (0x1U << PORT_PUDR_P1_Pos)                     /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P2_Pos                      (2)                                            /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P2_Msk                      (0x1U << PORT_PUDR_P2_Pos)                     /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P3_Pos                      (3)                                            /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P3_Msk                      (0x1U << PORT_PUDR_P3_Pos)                     /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P4_Pos                      (4)                                            /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P4_Msk                      (0x1U << PORT_PUDR_P4_Pos)                     /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P5_Pos                      (5)                                            /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P5_Msk                      (0x1U << PORT_PUDR_P5_Pos)                     /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P6_Pos                      (6)                                            /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P6_Msk                      (0x1U << PORT_PUDR_P6_Pos)                     /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P7_Pos                      (7)                                            /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P7_Msk                      (0x1U << PORT_PUDR_P7_Pos)                     /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P8_Pos                      (8)                                            /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P8_Msk                      (0x1U << PORT_PUDR_P8_Pos)                     /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P9_Pos                      (9)                                            /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P9_Msk                      (0x1U << PORT_PUDR_P9_Pos)                     /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P10_Pos                     (10)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P10_Msk                     (0x1U << PORT_PUDR_P10_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P11_Pos                     (11)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P11_Msk                     (0x1U << PORT_PUDR_P11_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P12_Pos                     (12)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P12_Msk                     (0x1U << PORT_PUDR_P12_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P13_Pos                     (13)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P13_Msk                     (0x1U << PORT_PUDR_P13_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P14_Pos                     (14)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P14_Msk                     (0x1U << PORT_PUDR_P14_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P15_Pos                     (15)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P15_Msk                     (0x1U << PORT_PUDR_P15_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P16_Pos                     (16)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P16_Msk                     (0x1U << PORT_PUDR_P16_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P17_Pos                     (17)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P17_Msk                     (0x1U << PORT_PUDR_P17_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P18_Pos                     (18)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P18_Msk                     (0x1U << PORT_PUDR_P18_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P19_Pos                     (19)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P19_Msk                     (0x1U << PORT_PUDR_P19_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P20_Pos                     (20)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P20_Msk                     (0x1U << PORT_PUDR_P20_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P21_Pos                     (21)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P21_Msk                     (0x1U << PORT_PUDR_P21_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P22_Pos                     (22)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P22_Msk                     (0x1U << PORT_PUDR_P22_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P23_Pos                     (23)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P23_Msk                     (0x1U << PORT_PUDR_P23_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P24_Pos                     (24)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P24_Msk                     (0x1U << PORT_PUDR_P24_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P25_Pos                     (25)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P25_Msk                     (0x1U << PORT_PUDR_P25_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P26_Pos                     (26)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P26_Msk                     (0x1U << PORT_PUDR_P26_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P27_Pos                     (27)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P27_Msk                     (0x1U << PORT_PUDR_P27_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P28_Pos                     (28)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P28_Msk                     (0x1U << PORT_PUDR_P28_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P29_Pos                     (29)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P29_Msk                     (0x1U << PORT_PUDR_P29_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P30_Pos                     (30)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P30_Msk                     (0x1U << PORT_PUDR_P30_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_P31_Pos                     (31)                                           /**< (PORT_PUDR) Pull-Up Disable Position */
#define PORT_PUDR_P31_Msk                     (0x1U << PORT_PUDR_P31_Pos)                    /**< (PORT_PUDR) Pull-Up Disable Mask */
#define PORT_PUDR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_PUDR) Register Mask  */
#define PORT_PUDR_P_Pos                       (0)                                            /**< (PORT_PUDR Position) Pull-Up Disable */
#define PORT_PUDR_P_Msk                       (0xFFFFFFFFU << PORT_PUDR_P_Pos)               /**< (PORT_PUDR Mask) P */
#define PORT_PUDR_P(value)                    (PORT_PUDR_P_Msk & ((value) << PORT_PUDR_P_Pos))

/* -------- PORT_PUER : (PORT Offset: 0x64) (/W 32) Pull-up Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Pull-Up Enable                                */
    uint32_t P1:1;                      /**< bit:      1  Pull-Up Enable                                */
    uint32_t P2:1;                      /**< bit:      2  Pull-Up Enable                                */
    uint32_t P3:1;                      /**< bit:      3  Pull-Up Enable                                */
    uint32_t P4:1;                      /**< bit:      4  Pull-Up Enable                                */
    uint32_t P5:1;                      /**< bit:      5  Pull-Up Enable                                */
    uint32_t P6:1;                      /**< bit:      6  Pull-Up Enable                                */
    uint32_t P7:1;                      /**< bit:      7  Pull-Up Enable                                */
    uint32_t P8:1;                      /**< bit:      8  Pull-Up Enable                                */
    uint32_t P9:1;                      /**< bit:      9  Pull-Up Enable                                */
    uint32_t P10:1;                     /**< bit:     10  Pull-Up Enable                                */
    uint32_t P11:1;                     /**< bit:     11  Pull-Up Enable                                */
    uint32_t P12:1;                     /**< bit:     12  Pull-Up Enable                                */
    uint32_t P13:1;                     /**< bit:     13  Pull-Up Enable                                */
    uint32_t P14:1;                     /**< bit:     14  Pull-Up Enable                                */
    uint32_t P15:1;                     /**< bit:     15  Pull-Up Enable                                */
    uint32_t P16:1;                     /**< bit:     16  Pull-Up Enable                                */
    uint32_t P17:1;                     /**< bit:     17  Pull-Up Enable                                */
    uint32_t P18:1;                     /**< bit:     18  Pull-Up Enable                                */
    uint32_t P19:1;                     /**< bit:     19  Pull-Up Enable                                */
    uint32_t P20:1;                     /**< bit:     20  Pull-Up Enable                                */
    uint32_t P21:1;                     /**< bit:     21  Pull-Up Enable                                */
    uint32_t P22:1;                     /**< bit:     22  Pull-Up Enable                                */
    uint32_t P23:1;                     /**< bit:     23  Pull-Up Enable                                */
    uint32_t P24:1;                     /**< bit:     24  Pull-Up Enable                                */
    uint32_t P25:1;                     /**< bit:     25  Pull-Up Enable                                */
    uint32_t P26:1;                     /**< bit:     26  Pull-Up Enable                                */
    uint32_t P27:1;                     /**< bit:     27  Pull-Up Enable                                */
    uint32_t P28:1;                     /**< bit:     28  Pull-Up Enable                                */
    uint32_t P29:1;                     /**< bit:     29  Pull-Up Enable                                */
    uint32_t P30:1;                     /**< bit:     30  Pull-Up Enable                                */
    uint32_t P31:1;                     /**< bit:     31  Pull-Up Enable                                */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Pull-Up Enable                                */
  };
  uint32_t w;
} __PORT_PUER_bits_t;

#define PORT_PUER_P0_Pos                      (0)                                            /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P0_Msk                      (0x1U << PORT_PUER_P0_Pos)                     /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P1_Pos                      (1)                                            /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P1_Msk                      (0x1U << PORT_PUER_P1_Pos)                     /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P2_Pos                      (2)                                            /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P2_Msk                      (0x1U << PORT_PUER_P2_Pos)                     /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P3_Pos                      (3)                                            /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P3_Msk                      (0x1U << PORT_PUER_P3_Pos)                     /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P4_Pos                      (4)                                            /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P4_Msk                      (0x1U << PORT_PUER_P4_Pos)                     /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P5_Pos                      (5)                                            /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P5_Msk                      (0x1U << PORT_PUER_P5_Pos)                     /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P6_Pos                      (6)                                            /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P6_Msk                      (0x1U << PORT_PUER_P6_Pos)                     /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P7_Pos                      (7)                                            /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P7_Msk                      (0x1U << PORT_PUER_P7_Pos)                     /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P8_Pos                      (8)                                            /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P8_Msk                      (0x1U << PORT_PUER_P8_Pos)                     /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P9_Pos                      (9)                                            /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P9_Msk                      (0x1U << PORT_PUER_P9_Pos)                     /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P10_Pos                     (10)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P10_Msk                     (0x1U << PORT_PUER_P10_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P11_Pos                     (11)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P11_Msk                     (0x1U << PORT_PUER_P11_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P12_Pos                     (12)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P12_Msk                     (0x1U << PORT_PUER_P12_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P13_Pos                     (13)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P13_Msk                     (0x1U << PORT_PUER_P13_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P14_Pos                     (14)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P14_Msk                     (0x1U << PORT_PUER_P14_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P15_Pos                     (15)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P15_Msk                     (0x1U << PORT_PUER_P15_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P16_Pos                     (16)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P16_Msk                     (0x1U << PORT_PUER_P16_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P17_Pos                     (17)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P17_Msk                     (0x1U << PORT_PUER_P17_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P18_Pos                     (18)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P18_Msk                     (0x1U << PORT_PUER_P18_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P19_Pos                     (19)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P19_Msk                     (0x1U << PORT_PUER_P19_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P20_Pos                     (20)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P20_Msk                     (0x1U << PORT_PUER_P20_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P21_Pos                     (21)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P21_Msk                     (0x1U << PORT_PUER_P21_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P22_Pos                     (22)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P22_Msk                     (0x1U << PORT_PUER_P22_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P23_Pos                     (23)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P23_Msk                     (0x1U << PORT_PUER_P23_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P24_Pos                     (24)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P24_Msk                     (0x1U << PORT_PUER_P24_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P25_Pos                     (25)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P25_Msk                     (0x1U << PORT_PUER_P25_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P26_Pos                     (26)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P26_Msk                     (0x1U << PORT_PUER_P26_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P27_Pos                     (27)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P27_Msk                     (0x1U << PORT_PUER_P27_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P28_Pos                     (28)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P28_Msk                     (0x1U << PORT_PUER_P28_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P29_Pos                     (29)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P29_Msk                     (0x1U << PORT_PUER_P29_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P30_Pos                     (30)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P30_Msk                     (0x1U << PORT_PUER_P30_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_P31_Pos                     (31)                                           /**< (PORT_PUER) Pull-Up Enable Position */
#define PORT_PUER_P31_Msk                     (0x1U << PORT_PUER_P31_Pos)                    /**< (PORT_PUER) Pull-Up Enable Mask */
#define PORT_PUER_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_PUER) Register Mask  */
#define PORT_PUER_P_Pos                       (0)                                            /**< (PORT_PUER Position) Pull-Up Enable */
#define PORT_PUER_P_Msk                       (0xFFFFFFFFU << PORT_PUER_P_Pos)               /**< (PORT_PUER Mask) P */
#define PORT_PUER_P(value)                    (PORT_PUER_P_Msk & ((value) << PORT_PUER_P_Pos))

/* -------- PORT_PUSR : (PORT Offset: 0x68) (R/ 32) Pad Pull-up Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Pull-Up Status                                */
    uint32_t P1:1;                      /**< bit:      1  Pull-Up Status                                */
    uint32_t P2:1;                      /**< bit:      2  Pull-Up Status                                */
    uint32_t P3:1;                      /**< bit:      3  Pull-Up Status                                */
    uint32_t P4:1;                      /**< bit:      4  Pull-Up Status                                */
    uint32_t P5:1;                      /**< bit:      5  Pull-Up Status                                */
    uint32_t P6:1;                      /**< bit:      6  Pull-Up Status                                */
    uint32_t P7:1;                      /**< bit:      7  Pull-Up Status                                */
    uint32_t P8:1;                      /**< bit:      8  Pull-Up Status                                */
    uint32_t P9:1;                      /**< bit:      9  Pull-Up Status                                */
    uint32_t P10:1;                     /**< bit:     10  Pull-Up Status                                */
    uint32_t P11:1;                     /**< bit:     11  Pull-Up Status                                */
    uint32_t P12:1;                     /**< bit:     12  Pull-Up Status                                */
    uint32_t P13:1;                     /**< bit:     13  Pull-Up Status                                */
    uint32_t P14:1;                     /**< bit:     14  Pull-Up Status                                */
    uint32_t P15:1;                     /**< bit:     15  Pull-Up Status                                */
    uint32_t P16:1;                     /**< bit:     16  Pull-Up Status                                */
    uint32_t P17:1;                     /**< bit:     17  Pull-Up Status                                */
    uint32_t P18:1;                     /**< bit:     18  Pull-Up Status                                */
    uint32_t P19:1;                     /**< bit:     19  Pull-Up Status                                */
    uint32_t P20:1;                     /**< bit:     20  Pull-Up Status                                */
    uint32_t P21:1;                     /**< bit:     21  Pull-Up Status                                */
    uint32_t P22:1;                     /**< bit:     22  Pull-Up Status                                */
    uint32_t P23:1;                     /**< bit:     23  Pull-Up Status                                */
    uint32_t P24:1;                     /**< bit:     24  Pull-Up Status                                */
    uint32_t P25:1;                     /**< bit:     25  Pull-Up Status                                */
    uint32_t P26:1;                     /**< bit:     26  Pull-Up Status                                */
    uint32_t P27:1;                     /**< bit:     27  Pull-Up Status                                */
    uint32_t P28:1;                     /**< bit:     28  Pull-Up Status                                */
    uint32_t P29:1;                     /**< bit:     29  Pull-Up Status                                */
    uint32_t P30:1;                     /**< bit:     30  Pull-Up Status                                */
    uint32_t P31:1;                     /**< bit:     31  Pull-Up Status                                */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Pull-Up Status                                */
  };
  uint32_t w;
} __PORT_PUSR_bits_t;

#define PORT_PUSR_P0_Pos                      (0)                                            /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P0_Msk                      (0x1U << PORT_PUSR_P0_Pos)                     /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P1_Pos                      (1)                                            /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P1_Msk                      (0x1U << PORT_PUSR_P1_Pos)                     /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P2_Pos                      (2)                                            /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P2_Msk                      (0x1U << PORT_PUSR_P2_Pos)                     /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P3_Pos                      (3)                                            /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P3_Msk                      (0x1U << PORT_PUSR_P3_Pos)                     /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P4_Pos                      (4)                                            /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P4_Msk                      (0x1U << PORT_PUSR_P4_Pos)                     /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P5_Pos                      (5)                                            /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P5_Msk                      (0x1U << PORT_PUSR_P5_Pos)                     /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P6_Pos                      (6)                                            /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P6_Msk                      (0x1U << PORT_PUSR_P6_Pos)                     /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P7_Pos                      (7)                                            /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P7_Msk                      (0x1U << PORT_PUSR_P7_Pos)                     /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P8_Pos                      (8)                                            /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P8_Msk                      (0x1U << PORT_PUSR_P8_Pos)                     /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P9_Pos                      (9)                                            /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P9_Msk                      (0x1U << PORT_PUSR_P9_Pos)                     /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P10_Pos                     (10)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P10_Msk                     (0x1U << PORT_PUSR_P10_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P11_Pos                     (11)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P11_Msk                     (0x1U << PORT_PUSR_P11_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P12_Pos                     (12)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P12_Msk                     (0x1U << PORT_PUSR_P12_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P13_Pos                     (13)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P13_Msk                     (0x1U << PORT_PUSR_P13_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P14_Pos                     (14)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P14_Msk                     (0x1U << PORT_PUSR_P14_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P15_Pos                     (15)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P15_Msk                     (0x1U << PORT_PUSR_P15_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P16_Pos                     (16)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P16_Msk                     (0x1U << PORT_PUSR_P16_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P17_Pos                     (17)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P17_Msk                     (0x1U << PORT_PUSR_P17_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P18_Pos                     (18)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P18_Msk                     (0x1U << PORT_PUSR_P18_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P19_Pos                     (19)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P19_Msk                     (0x1U << PORT_PUSR_P19_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P20_Pos                     (20)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P20_Msk                     (0x1U << PORT_PUSR_P20_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P21_Pos                     (21)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P21_Msk                     (0x1U << PORT_PUSR_P21_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P22_Pos                     (22)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P22_Msk                     (0x1U << PORT_PUSR_P22_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P23_Pos                     (23)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P23_Msk                     (0x1U << PORT_PUSR_P23_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P24_Pos                     (24)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P24_Msk                     (0x1U << PORT_PUSR_P24_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P25_Pos                     (25)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P25_Msk                     (0x1U << PORT_PUSR_P25_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P26_Pos                     (26)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P26_Msk                     (0x1U << PORT_PUSR_P26_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P27_Pos                     (27)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P27_Msk                     (0x1U << PORT_PUSR_P27_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P28_Pos                     (28)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P28_Msk                     (0x1U << PORT_PUSR_P28_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P29_Pos                     (29)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P29_Msk                     (0x1U << PORT_PUSR_P29_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P30_Pos                     (30)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P30_Msk                     (0x1U << PORT_PUSR_P30_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_P31_Pos                     (31)                                           /**< (PORT_PUSR) Pull-Up Status Position */
#define PORT_PUSR_P31_Msk                     (0x1U << PORT_PUSR_P31_Pos)                    /**< (PORT_PUSR) Pull-Up Status Mask */
#define PORT_PUSR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_PUSR) Register Mask  */
#define PORT_PUSR_P_Pos                       (0)                                            /**< (PORT_PUSR Position) Pull-Up Status */
#define PORT_PUSR_P_Msk                       (0xFFFFFFFFU << PORT_PUSR_P_Pos)               /**< (PORT_PUSR Mask) P */
#define PORT_PUSR_P(value)                    (PORT_PUSR_P_Msk & ((value) << PORT_PUSR_P_Pos))

/* -------- PORT_ABCDSR : (PORT Offset: 0x70) (R/W 32) Peripheral ABCD Select Register 0 -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Peripheral Select                             */
    uint32_t P1:1;                      /**< bit:      1  Peripheral Select                             */
    uint32_t P2:1;                      /**< bit:      2  Peripheral Select                             */
    uint32_t P3:1;                      /**< bit:      3  Peripheral Select                             */
    uint32_t P4:1;                      /**< bit:      4  Peripheral Select                             */
    uint32_t P5:1;                      /**< bit:      5  Peripheral Select                             */
    uint32_t P6:1;                      /**< bit:      6  Peripheral Select                             */
    uint32_t P7:1;                      /**< bit:      7  Peripheral Select                             */
    uint32_t P8:1;                      /**< bit:      8  Peripheral Select                             */
    uint32_t P9:1;                      /**< bit:      9  Peripheral Select                             */
    uint32_t P10:1;                     /**< bit:     10  Peripheral Select                             */
    uint32_t P11:1;                     /**< bit:     11  Peripheral Select                             */
    uint32_t P12:1;                     /**< bit:     12  Peripheral Select                             */
    uint32_t P13:1;                     /**< bit:     13  Peripheral Select                             */
    uint32_t P14:1;                     /**< bit:     14  Peripheral Select                             */
    uint32_t P15:1;                     /**< bit:     15  Peripheral Select                             */
    uint32_t P16:1;                     /**< bit:     16  Peripheral Select                             */
    uint32_t P17:1;                     /**< bit:     17  Peripheral Select                             */
    uint32_t P18:1;                     /**< bit:     18  Peripheral Select                             */
    uint32_t P19:1;                     /**< bit:     19  Peripheral Select                             */
    uint32_t P20:1;                     /**< bit:     20  Peripheral Select                             */
    uint32_t P21:1;                     /**< bit:     21  Peripheral Select                             */
    uint32_t P22:1;                     /**< bit:     22  Peripheral Select                             */
    uint32_t P23:1;                     /**< bit:     23  Peripheral Select                             */
    uint32_t P24:1;                     /**< bit:     24  Peripheral Select                             */
    uint32_t P25:1;                     /**< bit:     25  Peripheral Select                             */
    uint32_t P26:1;                     /**< bit:     26  Peripheral Select                             */
    uint32_t P27:1;                     /**< bit:     27  Peripheral Select                             */
    uint32_t P28:1;                     /**< bit:     28  Peripheral Select                             */
    uint32_t P29:1;                     /**< bit:     29  Peripheral Select                             */
    uint32_t P30:1;                     /**< bit:     30  Peripheral Select                             */
    uint32_t P31:1;                     /**< bit:     31  Peripheral Select                             */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Peripheral Select                             */
  };
  uint32_t w;
} __PORT_ABCDSR_bits_t;

#define PORT_ABCDSR_P0_Pos                    (0)                                            /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P0_Msk                    (0x1U << PORT_ABCDSR_P0_Pos)                   /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P1_Pos                    (1)                                            /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P1_Msk                    (0x1U << PORT_ABCDSR_P1_Pos)                   /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P2_Pos                    (2)                                            /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P2_Msk                    (0x1U << PORT_ABCDSR_P2_Pos)                   /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P3_Pos                    (3)                                            /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P3_Msk                    (0x1U << PORT_ABCDSR_P3_Pos)                   /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P4_Pos                    (4)                                            /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P4_Msk                    (0x1U << PORT_ABCDSR_P4_Pos)                   /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P5_Pos                    (5)                                            /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P5_Msk                    (0x1U << PORT_ABCDSR_P5_Pos)                   /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P6_Pos                    (6)                                            /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P6_Msk                    (0x1U << PORT_ABCDSR_P6_Pos)                   /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P7_Pos                    (7)                                            /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P7_Msk                    (0x1U << PORT_ABCDSR_P7_Pos)                   /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P8_Pos                    (8)                                            /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P8_Msk                    (0x1U << PORT_ABCDSR_P8_Pos)                   /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P9_Pos                    (9)                                            /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P9_Msk                    (0x1U << PORT_ABCDSR_P9_Pos)                   /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P10_Pos                   (10)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P10_Msk                   (0x1U << PORT_ABCDSR_P10_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P11_Pos                   (11)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P11_Msk                   (0x1U << PORT_ABCDSR_P11_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P12_Pos                   (12)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P12_Msk                   (0x1U << PORT_ABCDSR_P12_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P13_Pos                   (13)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P13_Msk                   (0x1U << PORT_ABCDSR_P13_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P14_Pos                   (14)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P14_Msk                   (0x1U << PORT_ABCDSR_P14_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P15_Pos                   (15)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P15_Msk                   (0x1U << PORT_ABCDSR_P15_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P16_Pos                   (16)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P16_Msk                   (0x1U << PORT_ABCDSR_P16_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P17_Pos                   (17)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P17_Msk                   (0x1U << PORT_ABCDSR_P17_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P18_Pos                   (18)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P18_Msk                   (0x1U << PORT_ABCDSR_P18_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P19_Pos                   (19)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P19_Msk                   (0x1U << PORT_ABCDSR_P19_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P20_Pos                   (20)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P20_Msk                   (0x1U << PORT_ABCDSR_P20_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P21_Pos                   (21)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P21_Msk                   (0x1U << PORT_ABCDSR_P21_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P22_Pos                   (22)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P22_Msk                   (0x1U << PORT_ABCDSR_P22_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P23_Pos                   (23)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P23_Msk                   (0x1U << PORT_ABCDSR_P23_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P24_Pos                   (24)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P24_Msk                   (0x1U << PORT_ABCDSR_P24_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P25_Pos                   (25)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P25_Msk                   (0x1U << PORT_ABCDSR_P25_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P26_Pos                   (26)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P26_Msk                   (0x1U << PORT_ABCDSR_P26_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P27_Pos                   (27)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P27_Msk                   (0x1U << PORT_ABCDSR_P27_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P28_Pos                   (28)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P28_Msk                   (0x1U << PORT_ABCDSR_P28_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P29_Pos                   (29)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P29_Msk                   (0x1U << PORT_ABCDSR_P29_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P30_Pos                   (30)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P30_Msk                   (0x1U << PORT_ABCDSR_P30_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_P31_Pos                   (31)                                           /**< (PORT_ABCDSR) Peripheral Select Position */
#define PORT_ABCDSR_P31_Msk                   (0x1U << PORT_ABCDSR_P31_Pos)                  /**< (PORT_ABCDSR) Peripheral Select Mask */
#define PORT_ABCDSR_Msk                       (0xFFFFFFFFUL)                                 /**< (PORT_ABCDSR) Register Mask  */
#define PORT_ABCDSR_P_Pos                     (0)                                            /**< (PORT_ABCDSR Position) Peripheral Select */
#define PORT_ABCDSR_P_Msk                     (0xFFFFFFFFU << PORT_ABCDSR_P_Pos)             /**< (PORT_ABCDSR Mask) P */
#define PORT_ABCDSR_P(value)                  (PORT_ABCDSR_P_Msk & ((value) << PORT_ABCDSR_P_Pos))

/* -------- PORT_IFSCDR : (PORT Offset: 0x80) (/W 32) Input Filter Slow Clock Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Peripheral Clock Glitch Filtering Select      */
    uint32_t P1:1;                      /**< bit:      1  Peripheral Clock Glitch Filtering Select      */
    uint32_t P2:1;                      /**< bit:      2  Peripheral Clock Glitch Filtering Select      */
    uint32_t P3:1;                      /**< bit:      3  Peripheral Clock Glitch Filtering Select      */
    uint32_t P4:1;                      /**< bit:      4  Peripheral Clock Glitch Filtering Select      */
    uint32_t P5:1;                      /**< bit:      5  Peripheral Clock Glitch Filtering Select      */
    uint32_t P6:1;                      /**< bit:      6  Peripheral Clock Glitch Filtering Select      */
    uint32_t P7:1;                      /**< bit:      7  Peripheral Clock Glitch Filtering Select      */
    uint32_t P8:1;                      /**< bit:      8  Peripheral Clock Glitch Filtering Select      */
    uint32_t P9:1;                      /**< bit:      9  Peripheral Clock Glitch Filtering Select      */
    uint32_t P10:1;                     /**< bit:     10  Peripheral Clock Glitch Filtering Select      */
    uint32_t P11:1;                     /**< bit:     11  Peripheral Clock Glitch Filtering Select      */
    uint32_t P12:1;                     /**< bit:     12  Peripheral Clock Glitch Filtering Select      */
    uint32_t P13:1;                     /**< bit:     13  Peripheral Clock Glitch Filtering Select      */
    uint32_t P14:1;                     /**< bit:     14  Peripheral Clock Glitch Filtering Select      */
    uint32_t P15:1;                     /**< bit:     15  Peripheral Clock Glitch Filtering Select      */
    uint32_t P16:1;                     /**< bit:     16  Peripheral Clock Glitch Filtering Select      */
    uint32_t P17:1;                     /**< bit:     17  Peripheral Clock Glitch Filtering Select      */
    uint32_t P18:1;                     /**< bit:     18  Peripheral Clock Glitch Filtering Select      */
    uint32_t P19:1;                     /**< bit:     19  Peripheral Clock Glitch Filtering Select      */
    uint32_t P20:1;                     /**< bit:     20  Peripheral Clock Glitch Filtering Select      */
    uint32_t P21:1;                     /**< bit:     21  Peripheral Clock Glitch Filtering Select      */
    uint32_t P22:1;                     /**< bit:     22  Peripheral Clock Glitch Filtering Select      */
    uint32_t P23:1;                     /**< bit:     23  Peripheral Clock Glitch Filtering Select      */
    uint32_t P24:1;                     /**< bit:     24  Peripheral Clock Glitch Filtering Select      */
    uint32_t P25:1;                     /**< bit:     25  Peripheral Clock Glitch Filtering Select      */
    uint32_t P26:1;                     /**< bit:     26  Peripheral Clock Glitch Filtering Select      */
    uint32_t P27:1;                     /**< bit:     27  Peripheral Clock Glitch Filtering Select      */
    uint32_t P28:1;                     /**< bit:     28  Peripheral Clock Glitch Filtering Select      */
    uint32_t P29:1;                     /**< bit:     29  Peripheral Clock Glitch Filtering Select      */
    uint32_t P30:1;                     /**< bit:     30  Peripheral Clock Glitch Filtering Select      */
    uint32_t P31:1;                     /**< bit:     31  Peripheral Clock Glitch Filtering Select      */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Peripheral Clock Glitch Filtering Select      */
  };
  uint32_t w;
} __PORT_IFSCDR_bits_t;

#define PORT_IFSCDR_P0_Pos                    (0)                                            /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P0_Msk                    (0x1U << PORT_IFSCDR_P0_Pos)                   /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P1_Pos                    (1)                                            /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P1_Msk                    (0x1U << PORT_IFSCDR_P1_Pos)                   /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P2_Pos                    (2)                                            /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P2_Msk                    (0x1U << PORT_IFSCDR_P2_Pos)                   /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P3_Pos                    (3)                                            /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P3_Msk                    (0x1U << PORT_IFSCDR_P3_Pos)                   /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P4_Pos                    (4)                                            /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P4_Msk                    (0x1U << PORT_IFSCDR_P4_Pos)                   /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P5_Pos                    (5)                                            /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P5_Msk                    (0x1U << PORT_IFSCDR_P5_Pos)                   /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P6_Pos                    (6)                                            /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P6_Msk                    (0x1U << PORT_IFSCDR_P6_Pos)                   /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P7_Pos                    (7)                                            /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P7_Msk                    (0x1U << PORT_IFSCDR_P7_Pos)                   /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P8_Pos                    (8)                                            /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P8_Msk                    (0x1U << PORT_IFSCDR_P8_Pos)                   /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P9_Pos                    (9)                                            /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P9_Msk                    (0x1U << PORT_IFSCDR_P9_Pos)                   /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P10_Pos                   (10)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P10_Msk                   (0x1U << PORT_IFSCDR_P10_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P11_Pos                   (11)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P11_Msk                   (0x1U << PORT_IFSCDR_P11_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P12_Pos                   (12)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P12_Msk                   (0x1U << PORT_IFSCDR_P12_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P13_Pos                   (13)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P13_Msk                   (0x1U << PORT_IFSCDR_P13_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P14_Pos                   (14)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P14_Msk                   (0x1U << PORT_IFSCDR_P14_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P15_Pos                   (15)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P15_Msk                   (0x1U << PORT_IFSCDR_P15_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P16_Pos                   (16)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P16_Msk                   (0x1U << PORT_IFSCDR_P16_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P17_Pos                   (17)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P17_Msk                   (0x1U << PORT_IFSCDR_P17_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P18_Pos                   (18)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P18_Msk                   (0x1U << PORT_IFSCDR_P18_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P19_Pos                   (19)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P19_Msk                   (0x1U << PORT_IFSCDR_P19_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P20_Pos                   (20)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P20_Msk                   (0x1U << PORT_IFSCDR_P20_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P21_Pos                   (21)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P21_Msk                   (0x1U << PORT_IFSCDR_P21_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P22_Pos                   (22)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P22_Msk                   (0x1U << PORT_IFSCDR_P22_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P23_Pos                   (23)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P23_Msk                   (0x1U << PORT_IFSCDR_P23_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P24_Pos                   (24)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P24_Msk                   (0x1U << PORT_IFSCDR_P24_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P25_Pos                   (25)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P25_Msk                   (0x1U << PORT_IFSCDR_P25_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P26_Pos                   (26)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P26_Msk                   (0x1U << PORT_IFSCDR_P26_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P27_Pos                   (27)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P27_Msk                   (0x1U << PORT_IFSCDR_P27_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P28_Pos                   (28)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P28_Msk                   (0x1U << PORT_IFSCDR_P28_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P29_Pos                   (29)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P29_Msk                   (0x1U << PORT_IFSCDR_P29_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P30_Pos                   (30)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P30_Msk                   (0x1U << PORT_IFSCDR_P30_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_P31_Pos                   (31)                                           /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Position */
#define PORT_IFSCDR_P31_Msk                   (0x1U << PORT_IFSCDR_P31_Pos)                  /**< (PORT_IFSCDR) Peripheral Clock Glitch Filtering Select Mask */
#define PORT_IFSCDR_Msk                       (0xFFFFFFFFUL)                                 /**< (PORT_IFSCDR) Register Mask  */
#define PORT_IFSCDR_P_Pos                     (0)                                            /**< (PORT_IFSCDR Position) Peripheral Clock Glitch Filtering Select */
#define PORT_IFSCDR_P_Msk                     (0xFFFFFFFFU << PORT_IFSCDR_P_Pos)             /**< (PORT_IFSCDR Mask) P */
#define PORT_IFSCDR_P(value)                  (PORT_IFSCDR_P_Msk & ((value) << PORT_IFSCDR_P_Pos))

/* -------- PORT_IFSCER : (PORT Offset: 0x84) (/W 32) Input Filter Slow Clock Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Slow Clock Debouncing Filtering Select        */
    uint32_t P1:1;                      /**< bit:      1  Slow Clock Debouncing Filtering Select        */
    uint32_t P2:1;                      /**< bit:      2  Slow Clock Debouncing Filtering Select        */
    uint32_t P3:1;                      /**< bit:      3  Slow Clock Debouncing Filtering Select        */
    uint32_t P4:1;                      /**< bit:      4  Slow Clock Debouncing Filtering Select        */
    uint32_t P5:1;                      /**< bit:      5  Slow Clock Debouncing Filtering Select        */
    uint32_t P6:1;                      /**< bit:      6  Slow Clock Debouncing Filtering Select        */
    uint32_t P7:1;                      /**< bit:      7  Slow Clock Debouncing Filtering Select        */
    uint32_t P8:1;                      /**< bit:      8  Slow Clock Debouncing Filtering Select        */
    uint32_t P9:1;                      /**< bit:      9  Slow Clock Debouncing Filtering Select        */
    uint32_t P10:1;                     /**< bit:     10  Slow Clock Debouncing Filtering Select        */
    uint32_t P11:1;                     /**< bit:     11  Slow Clock Debouncing Filtering Select        */
    uint32_t P12:1;                     /**< bit:     12  Slow Clock Debouncing Filtering Select        */
    uint32_t P13:1;                     /**< bit:     13  Slow Clock Debouncing Filtering Select        */
    uint32_t P14:1;                     /**< bit:     14  Slow Clock Debouncing Filtering Select        */
    uint32_t P15:1;                     /**< bit:     15  Slow Clock Debouncing Filtering Select        */
    uint32_t P16:1;                     /**< bit:     16  Slow Clock Debouncing Filtering Select        */
    uint32_t P17:1;                     /**< bit:     17  Slow Clock Debouncing Filtering Select        */
    uint32_t P18:1;                     /**< bit:     18  Slow Clock Debouncing Filtering Select        */
    uint32_t P19:1;                     /**< bit:     19  Slow Clock Debouncing Filtering Select        */
    uint32_t P20:1;                     /**< bit:     20  Slow Clock Debouncing Filtering Select        */
    uint32_t P21:1;                     /**< bit:     21  Slow Clock Debouncing Filtering Select        */
    uint32_t P22:1;                     /**< bit:     22  Slow Clock Debouncing Filtering Select        */
    uint32_t P23:1;                     /**< bit:     23  Slow Clock Debouncing Filtering Select        */
    uint32_t P24:1;                     /**< bit:     24  Slow Clock Debouncing Filtering Select        */
    uint32_t P25:1;                     /**< bit:     25  Slow Clock Debouncing Filtering Select        */
    uint32_t P26:1;                     /**< bit:     26  Slow Clock Debouncing Filtering Select        */
    uint32_t P27:1;                     /**< bit:     27  Slow Clock Debouncing Filtering Select        */
    uint32_t P28:1;                     /**< bit:     28  Slow Clock Debouncing Filtering Select        */
    uint32_t P29:1;                     /**< bit:     29  Slow Clock Debouncing Filtering Select        */
    uint32_t P30:1;                     /**< bit:     30  Slow Clock Debouncing Filtering Select        */
    uint32_t P31:1;                     /**< bit:     31  Slow Clock Debouncing Filtering Select        */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Slow Clock Debouncing Filtering Select        */
  };
  uint32_t w;
} __PORT_IFSCER_bits_t;

#define PORT_IFSCER_P0_Pos                    (0)                                            /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P0_Msk                    (0x1U << PORT_IFSCER_P0_Pos)                   /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P1_Pos                    (1)                                            /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P1_Msk                    (0x1U << PORT_IFSCER_P1_Pos)                   /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P2_Pos                    (2)                                            /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P2_Msk                    (0x1U << PORT_IFSCER_P2_Pos)                   /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P3_Pos                    (3)                                            /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P3_Msk                    (0x1U << PORT_IFSCER_P3_Pos)                   /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P4_Pos                    (4)                                            /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P4_Msk                    (0x1U << PORT_IFSCER_P4_Pos)                   /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P5_Pos                    (5)                                            /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P5_Msk                    (0x1U << PORT_IFSCER_P5_Pos)                   /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P6_Pos                    (6)                                            /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P6_Msk                    (0x1U << PORT_IFSCER_P6_Pos)                   /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P7_Pos                    (7)                                            /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P7_Msk                    (0x1U << PORT_IFSCER_P7_Pos)                   /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P8_Pos                    (8)                                            /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P8_Msk                    (0x1U << PORT_IFSCER_P8_Pos)                   /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P9_Pos                    (9)                                            /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P9_Msk                    (0x1U << PORT_IFSCER_P9_Pos)                   /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P10_Pos                   (10)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P10_Msk                   (0x1U << PORT_IFSCER_P10_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P11_Pos                   (11)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P11_Msk                   (0x1U << PORT_IFSCER_P11_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P12_Pos                   (12)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P12_Msk                   (0x1U << PORT_IFSCER_P12_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P13_Pos                   (13)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P13_Msk                   (0x1U << PORT_IFSCER_P13_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P14_Pos                   (14)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P14_Msk                   (0x1U << PORT_IFSCER_P14_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P15_Pos                   (15)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P15_Msk                   (0x1U << PORT_IFSCER_P15_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P16_Pos                   (16)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P16_Msk                   (0x1U << PORT_IFSCER_P16_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P17_Pos                   (17)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P17_Msk                   (0x1U << PORT_IFSCER_P17_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P18_Pos                   (18)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P18_Msk                   (0x1U << PORT_IFSCER_P18_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P19_Pos                   (19)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P19_Msk                   (0x1U << PORT_IFSCER_P19_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P20_Pos                   (20)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P20_Msk                   (0x1U << PORT_IFSCER_P20_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P21_Pos                   (21)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P21_Msk                   (0x1U << PORT_IFSCER_P21_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P22_Pos                   (22)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P22_Msk                   (0x1U << PORT_IFSCER_P22_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P23_Pos                   (23)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P23_Msk                   (0x1U << PORT_IFSCER_P23_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P24_Pos                   (24)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P24_Msk                   (0x1U << PORT_IFSCER_P24_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P25_Pos                   (25)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P25_Msk                   (0x1U << PORT_IFSCER_P25_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P26_Pos                   (26)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P26_Msk                   (0x1U << PORT_IFSCER_P26_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P27_Pos                   (27)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P27_Msk                   (0x1U << PORT_IFSCER_P27_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P28_Pos                   (28)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P28_Msk                   (0x1U << PORT_IFSCER_P28_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P29_Pos                   (29)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P29_Msk                   (0x1U << PORT_IFSCER_P29_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P30_Pos                   (30)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P30_Msk                   (0x1U << PORT_IFSCER_P30_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_P31_Pos                   (31)                                           /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Position */
#define PORT_IFSCER_P31_Msk                   (0x1U << PORT_IFSCER_P31_Pos)                  /**< (PORT_IFSCER) Slow Clock Debouncing Filtering Select Mask */
#define PORT_IFSCER_Msk                       (0xFFFFFFFFUL)                                 /**< (PORT_IFSCER) Register Mask  */
#define PORT_IFSCER_P_Pos                     (0)                                            /**< (PORT_IFSCER Position) Slow Clock Debouncing Filtering Select */
#define PORT_IFSCER_P_Msk                     (0xFFFFFFFFU << PORT_IFSCER_P_Pos)             /**< (PORT_IFSCER Mask) P */
#define PORT_IFSCER_P(value)                  (PORT_IFSCER_P_Msk & ((value) << PORT_IFSCER_P_Pos))

/* -------- PORT_IFSCSR : (PORT Offset: 0x88) (R/ 32) Input Filter Slow Clock Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Glitch or Debouncing Filter Selection Status  */
    uint32_t P1:1;                      /**< bit:      1  Glitch or Debouncing Filter Selection Status  */
    uint32_t P2:1;                      /**< bit:      2  Glitch or Debouncing Filter Selection Status  */
    uint32_t P3:1;                      /**< bit:      3  Glitch or Debouncing Filter Selection Status  */
    uint32_t P4:1;                      /**< bit:      4  Glitch or Debouncing Filter Selection Status  */
    uint32_t P5:1;                      /**< bit:      5  Glitch or Debouncing Filter Selection Status  */
    uint32_t P6:1;                      /**< bit:      6  Glitch or Debouncing Filter Selection Status  */
    uint32_t P7:1;                      /**< bit:      7  Glitch or Debouncing Filter Selection Status  */
    uint32_t P8:1;                      /**< bit:      8  Glitch or Debouncing Filter Selection Status  */
    uint32_t P9:1;                      /**< bit:      9  Glitch or Debouncing Filter Selection Status  */
    uint32_t P10:1;                     /**< bit:     10  Glitch or Debouncing Filter Selection Status  */
    uint32_t P11:1;                     /**< bit:     11  Glitch or Debouncing Filter Selection Status  */
    uint32_t P12:1;                     /**< bit:     12  Glitch or Debouncing Filter Selection Status  */
    uint32_t P13:1;                     /**< bit:     13  Glitch or Debouncing Filter Selection Status  */
    uint32_t P14:1;                     /**< bit:     14  Glitch or Debouncing Filter Selection Status  */
    uint32_t P15:1;                     /**< bit:     15  Glitch or Debouncing Filter Selection Status  */
    uint32_t P16:1;                     /**< bit:     16  Glitch or Debouncing Filter Selection Status  */
    uint32_t P17:1;                     /**< bit:     17  Glitch or Debouncing Filter Selection Status  */
    uint32_t P18:1;                     /**< bit:     18  Glitch or Debouncing Filter Selection Status  */
    uint32_t P19:1;                     /**< bit:     19  Glitch or Debouncing Filter Selection Status  */
    uint32_t P20:1;                     /**< bit:     20  Glitch or Debouncing Filter Selection Status  */
    uint32_t P21:1;                     /**< bit:     21  Glitch or Debouncing Filter Selection Status  */
    uint32_t P22:1;                     /**< bit:     22  Glitch or Debouncing Filter Selection Status  */
    uint32_t P23:1;                     /**< bit:     23  Glitch or Debouncing Filter Selection Status  */
    uint32_t P24:1;                     /**< bit:     24  Glitch or Debouncing Filter Selection Status  */
    uint32_t P25:1;                     /**< bit:     25  Glitch or Debouncing Filter Selection Status  */
    uint32_t P26:1;                     /**< bit:     26  Glitch or Debouncing Filter Selection Status  */
    uint32_t P27:1;                     /**< bit:     27  Glitch or Debouncing Filter Selection Status  */
    uint32_t P28:1;                     /**< bit:     28  Glitch or Debouncing Filter Selection Status  */
    uint32_t P29:1;                     /**< bit:     29  Glitch or Debouncing Filter Selection Status  */
    uint32_t P30:1;                     /**< bit:     30  Glitch or Debouncing Filter Selection Status  */
    uint32_t P31:1;                     /**< bit:     31  Glitch or Debouncing Filter Selection Status  */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Glitch or Debouncing Filter Selection Status  */
  };
  uint32_t w;
} __PORT_IFSCSR_bits_t;

#define PORT_IFSCSR_P0_Pos                    (0)                                            /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P0_Msk                    (0x1U << PORT_IFSCSR_P0_Pos)                   /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P1_Pos                    (1)                                            /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P1_Msk                    (0x1U << PORT_IFSCSR_P1_Pos)                   /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P2_Pos                    (2)                                            /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P2_Msk                    (0x1U << PORT_IFSCSR_P2_Pos)                   /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P3_Pos                    (3)                                            /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P3_Msk                    (0x1U << PORT_IFSCSR_P3_Pos)                   /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P4_Pos                    (4)                                            /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P4_Msk                    (0x1U << PORT_IFSCSR_P4_Pos)                   /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P5_Pos                    (5)                                            /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P5_Msk                    (0x1U << PORT_IFSCSR_P5_Pos)                   /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P6_Pos                    (6)                                            /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P6_Msk                    (0x1U << PORT_IFSCSR_P6_Pos)                   /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P7_Pos                    (7)                                            /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P7_Msk                    (0x1U << PORT_IFSCSR_P7_Pos)                   /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P8_Pos                    (8)                                            /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P8_Msk                    (0x1U << PORT_IFSCSR_P8_Pos)                   /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P9_Pos                    (9)                                            /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P9_Msk                    (0x1U << PORT_IFSCSR_P9_Pos)                   /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P10_Pos                   (10)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P10_Msk                   (0x1U << PORT_IFSCSR_P10_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P11_Pos                   (11)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P11_Msk                   (0x1U << PORT_IFSCSR_P11_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P12_Pos                   (12)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P12_Msk                   (0x1U << PORT_IFSCSR_P12_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P13_Pos                   (13)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P13_Msk                   (0x1U << PORT_IFSCSR_P13_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P14_Pos                   (14)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P14_Msk                   (0x1U << PORT_IFSCSR_P14_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P15_Pos                   (15)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P15_Msk                   (0x1U << PORT_IFSCSR_P15_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P16_Pos                   (16)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P16_Msk                   (0x1U << PORT_IFSCSR_P16_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P17_Pos                   (17)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P17_Msk                   (0x1U << PORT_IFSCSR_P17_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P18_Pos                   (18)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P18_Msk                   (0x1U << PORT_IFSCSR_P18_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P19_Pos                   (19)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P19_Msk                   (0x1U << PORT_IFSCSR_P19_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P20_Pos                   (20)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P20_Msk                   (0x1U << PORT_IFSCSR_P20_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P21_Pos                   (21)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P21_Msk                   (0x1U << PORT_IFSCSR_P21_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P22_Pos                   (22)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P22_Msk                   (0x1U << PORT_IFSCSR_P22_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P23_Pos                   (23)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P23_Msk                   (0x1U << PORT_IFSCSR_P23_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P24_Pos                   (24)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P24_Msk                   (0x1U << PORT_IFSCSR_P24_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P25_Pos                   (25)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P25_Msk                   (0x1U << PORT_IFSCSR_P25_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P26_Pos                   (26)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P26_Msk                   (0x1U << PORT_IFSCSR_P26_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P27_Pos                   (27)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P27_Msk                   (0x1U << PORT_IFSCSR_P27_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P28_Pos                   (28)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P28_Msk                   (0x1U << PORT_IFSCSR_P28_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P29_Pos                   (29)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P29_Msk                   (0x1U << PORT_IFSCSR_P29_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P30_Pos                   (30)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P30_Msk                   (0x1U << PORT_IFSCSR_P30_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_P31_Pos                   (31)                                           /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Position */
#define PORT_IFSCSR_P31_Msk                   (0x1U << PORT_IFSCSR_P31_Pos)                  /**< (PORT_IFSCSR) Glitch or Debouncing Filter Selection Status Mask */
#define PORT_IFSCSR_Msk                       (0xFFFFFFFFUL)                                 /**< (PORT_IFSCSR) Register Mask  */
#define PORT_IFSCSR_P_Pos                     (0)                                            /**< (PORT_IFSCSR Position) Glitch or Debouncing Filter Selection Status */
#define PORT_IFSCSR_P_Msk                     (0xFFFFFFFFU << PORT_IFSCSR_P_Pos)             /**< (PORT_IFSCSR Mask) P */
#define PORT_IFSCSR_P(value)                  (PORT_IFSCSR_P_Msk & ((value) << PORT_IFSCSR_P_Pos))

/* -------- PORT_SCDR : (PORT Offset: 0x8c) (R/W 32) Slow Clock Divider Debouncing Register -------- */

typedef union
{
  struct
  {
    uint32_t DIV:14;                    /**< bit:  0..13  Slow Clock Divider Selection for Debouncing   */
    uint32_t :18;                       /**< bit: 14..31  Reserved                                      */
  };
  uint32_t w;
} __PORT_SCDR_bits_t;

#define PORT_SCDR_DIV_Pos                     (0)                                            /**< (PORT_SCDR) Slow Clock Divider Selection for Debouncing Position */
#define PORT_SCDR_DIV_Msk                     (0x3FFFU << PORT_SCDR_DIV_Pos)                 /**< (PORT_SCDR) Slow Clock Divider Selection for Debouncing Mask */
#define PORT_SCDR_DIV(value)                  (PORT_SCDR_DIV_Msk & ((value) << PORT_SCDR_DIV_Pos))
#define PORT_SCDR_Msk                         (0x00003FFFUL)                                 /**< (PORT_SCDR) Register Mask  */

/* -------- PORT_PPDDR : (PORT Offset: 0x90) (/W 32) Pad Pull-down Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Pull-Down Disable                             */
    uint32_t P1:1;                      /**< bit:      1  Pull-Down Disable                             */
    uint32_t P2:1;                      /**< bit:      2  Pull-Down Disable                             */
    uint32_t P3:1;                      /**< bit:      3  Pull-Down Disable                             */
    uint32_t P4:1;                      /**< bit:      4  Pull-Down Disable                             */
    uint32_t P5:1;                      /**< bit:      5  Pull-Down Disable                             */
    uint32_t P6:1;                      /**< bit:      6  Pull-Down Disable                             */
    uint32_t P7:1;                      /**< bit:      7  Pull-Down Disable                             */
    uint32_t P8:1;                      /**< bit:      8  Pull-Down Disable                             */
    uint32_t P9:1;                      /**< bit:      9  Pull-Down Disable                             */
    uint32_t P10:1;                     /**< bit:     10  Pull-Down Disable                             */
    uint32_t P11:1;                     /**< bit:     11  Pull-Down Disable                             */
    uint32_t P12:1;                     /**< bit:     12  Pull-Down Disable                             */
    uint32_t P13:1;                     /**< bit:     13  Pull-Down Disable                             */
    uint32_t P14:1;                     /**< bit:     14  Pull-Down Disable                             */
    uint32_t P15:1;                     /**< bit:     15  Pull-Down Disable                             */
    uint32_t P16:1;                     /**< bit:     16  Pull-Down Disable                             */
    uint32_t P17:1;                     /**< bit:     17  Pull-Down Disable                             */
    uint32_t P18:1;                     /**< bit:     18  Pull-Down Disable                             */
    uint32_t P19:1;                     /**< bit:     19  Pull-Down Disable                             */
    uint32_t P20:1;                     /**< bit:     20  Pull-Down Disable                             */
    uint32_t P21:1;                     /**< bit:     21  Pull-Down Disable                             */
    uint32_t P22:1;                     /**< bit:     22  Pull-Down Disable                             */
    uint32_t P23:1;                     /**< bit:     23  Pull-Down Disable                             */
    uint32_t P24:1;                     /**< bit:     24  Pull-Down Disable                             */
    uint32_t P25:1;                     /**< bit:     25  Pull-Down Disable                             */
    uint32_t P26:1;                     /**< bit:     26  Pull-Down Disable                             */
    uint32_t P27:1;                     /**< bit:     27  Pull-Down Disable                             */
    uint32_t P28:1;                     /**< bit:     28  Pull-Down Disable                             */
    uint32_t P29:1;                     /**< bit:     29  Pull-Down Disable                             */
    uint32_t P30:1;                     /**< bit:     30  Pull-Down Disable                             */
    uint32_t P31:1;                     /**< bit:     31  Pull-Down Disable                             */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Pull-Down Disable                             */
  };
  uint32_t w;
} __PORT_PPDDR_bits_t;

#define PORT_PPDDR_P0_Pos                     (0)                                            /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P0_Msk                     (0x1U << PORT_PPDDR_P0_Pos)                    /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P1_Pos                     (1)                                            /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P1_Msk                     (0x1U << PORT_PPDDR_P1_Pos)                    /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P2_Pos                     (2)                                            /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P2_Msk                     (0x1U << PORT_PPDDR_P2_Pos)                    /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P3_Pos                     (3)                                            /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P3_Msk                     (0x1U << PORT_PPDDR_P3_Pos)                    /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P4_Pos                     (4)                                            /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P4_Msk                     (0x1U << PORT_PPDDR_P4_Pos)                    /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P5_Pos                     (5)                                            /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P5_Msk                     (0x1U << PORT_PPDDR_P5_Pos)                    /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P6_Pos                     (6)                                            /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P6_Msk                     (0x1U << PORT_PPDDR_P6_Pos)                    /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P7_Pos                     (7)                                            /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P7_Msk                     (0x1U << PORT_PPDDR_P7_Pos)                    /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P8_Pos                     (8)                                            /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P8_Msk                     (0x1U << PORT_PPDDR_P8_Pos)                    /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P9_Pos                     (9)                                            /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P9_Msk                     (0x1U << PORT_PPDDR_P9_Pos)                    /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P10_Pos                    (10)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P10_Msk                    (0x1U << PORT_PPDDR_P10_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P11_Pos                    (11)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P11_Msk                    (0x1U << PORT_PPDDR_P11_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P12_Pos                    (12)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P12_Msk                    (0x1U << PORT_PPDDR_P12_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P13_Pos                    (13)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P13_Msk                    (0x1U << PORT_PPDDR_P13_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P14_Pos                    (14)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P14_Msk                    (0x1U << PORT_PPDDR_P14_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P15_Pos                    (15)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P15_Msk                    (0x1U << PORT_PPDDR_P15_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P16_Pos                    (16)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P16_Msk                    (0x1U << PORT_PPDDR_P16_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P17_Pos                    (17)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P17_Msk                    (0x1U << PORT_PPDDR_P17_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P18_Pos                    (18)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P18_Msk                    (0x1U << PORT_PPDDR_P18_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P19_Pos                    (19)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P19_Msk                    (0x1U << PORT_PPDDR_P19_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P20_Pos                    (20)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P20_Msk                    (0x1U << PORT_PPDDR_P20_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P21_Pos                    (21)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P21_Msk                    (0x1U << PORT_PPDDR_P21_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P22_Pos                    (22)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P22_Msk                    (0x1U << PORT_PPDDR_P22_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P23_Pos                    (23)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P23_Msk                    (0x1U << PORT_PPDDR_P23_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P24_Pos                    (24)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P24_Msk                    (0x1U << PORT_PPDDR_P24_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P25_Pos                    (25)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P25_Msk                    (0x1U << PORT_PPDDR_P25_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P26_Pos                    (26)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P26_Msk                    (0x1U << PORT_PPDDR_P26_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P27_Pos                    (27)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P27_Msk                    (0x1U << PORT_PPDDR_P27_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P28_Pos                    (28)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P28_Msk                    (0x1U << PORT_PPDDR_P28_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P29_Pos                    (29)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P29_Msk                    (0x1U << PORT_PPDDR_P29_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P30_Pos                    (30)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P30_Msk                    (0x1U << PORT_PPDDR_P30_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_P31_Pos                    (31)                                           /**< (PORT_PPDDR) Pull-Down Disable Position */
#define PORT_PPDDR_P31_Msk                    (0x1U << PORT_PPDDR_P31_Pos)                   /**< (PORT_PPDDR) Pull-Down Disable Mask */
#define PORT_PPDDR_Msk                        (0xFFFFFFFFUL)                                 /**< (PORT_PPDDR) Register Mask  */
#define PORT_PPDDR_P_Pos                      (0)                                            /**< (PORT_PPDDR Position) Pull-Down Disable */
#define PORT_PPDDR_P_Msk                      (0xFFFFFFFFU << PORT_PPDDR_P_Pos)              /**< (PORT_PPDDR Mask) P */
#define PORT_PPDDR_P(value)                   (PORT_PPDDR_P_Msk & ((value) << PORT_PPDDR_P_Pos))

/* -------- PORT_PPDER : (PORT Offset: 0x94) (/W 32) Pad Pull-down Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Pull-Down Enable                              */
    uint32_t P1:1;                      /**< bit:      1  Pull-Down Enable                              */
    uint32_t P2:1;                      /**< bit:      2  Pull-Down Enable                              */
    uint32_t P3:1;                      /**< bit:      3  Pull-Down Enable                              */
    uint32_t P4:1;                      /**< bit:      4  Pull-Down Enable                              */
    uint32_t P5:1;                      /**< bit:      5  Pull-Down Enable                              */
    uint32_t P6:1;                      /**< bit:      6  Pull-Down Enable                              */
    uint32_t P7:1;                      /**< bit:      7  Pull-Down Enable                              */
    uint32_t P8:1;                      /**< bit:      8  Pull-Down Enable                              */
    uint32_t P9:1;                      /**< bit:      9  Pull-Down Enable                              */
    uint32_t P10:1;                     /**< bit:     10  Pull-Down Enable                              */
    uint32_t P11:1;                     /**< bit:     11  Pull-Down Enable                              */
    uint32_t P12:1;                     /**< bit:     12  Pull-Down Enable                              */
    uint32_t P13:1;                     /**< bit:     13  Pull-Down Enable                              */
    uint32_t P14:1;                     /**< bit:     14  Pull-Down Enable                              */
    uint32_t P15:1;                     /**< bit:     15  Pull-Down Enable                              */
    uint32_t P16:1;                     /**< bit:     16  Pull-Down Enable                              */
    uint32_t P17:1;                     /**< bit:     17  Pull-Down Enable                              */
    uint32_t P18:1;                     /**< bit:     18  Pull-Down Enable                              */
    uint32_t P19:1;                     /**< bit:     19  Pull-Down Enable                              */
    uint32_t P20:1;                     /**< bit:     20  Pull-Down Enable                              */
    uint32_t P21:1;                     /**< bit:     21  Pull-Down Enable                              */
    uint32_t P22:1;                     /**< bit:     22  Pull-Down Enable                              */
    uint32_t P23:1;                     /**< bit:     23  Pull-Down Enable                              */
    uint32_t P24:1;                     /**< bit:     24  Pull-Down Enable                              */
    uint32_t P25:1;                     /**< bit:     25  Pull-Down Enable                              */
    uint32_t P26:1;                     /**< bit:     26  Pull-Down Enable                              */
    uint32_t P27:1;                     /**< bit:     27  Pull-Down Enable                              */
    uint32_t P28:1;                     /**< bit:     28  Pull-Down Enable                              */
    uint32_t P29:1;                     /**< bit:     29  Pull-Down Enable                              */
    uint32_t P30:1;                     /**< bit:     30  Pull-Down Enable                              */
    uint32_t P31:1;                     /**< bit:     31  Pull-Down Enable                              */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Pull-Down Enable                              */
  };
  uint32_t w;
} __PORT_PPDER_bits_t;

#define PORT_PPDER_P0_Pos                     (0)                                            /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P0_Msk                     (0x1U << PORT_PPDER_P0_Pos)                    /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P1_Pos                     (1)                                            /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P1_Msk                     (0x1U << PORT_PPDER_P1_Pos)                    /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P2_Pos                     (2)                                            /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P2_Msk                     (0x1U << PORT_PPDER_P2_Pos)                    /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P3_Pos                     (3)                                            /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P3_Msk                     (0x1U << PORT_PPDER_P3_Pos)                    /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P4_Pos                     (4)                                            /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P4_Msk                     (0x1U << PORT_PPDER_P4_Pos)                    /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P5_Pos                     (5)                                            /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P5_Msk                     (0x1U << PORT_PPDER_P5_Pos)                    /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P6_Pos                     (6)                                            /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P6_Msk                     (0x1U << PORT_PPDER_P6_Pos)                    /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P7_Pos                     (7)                                            /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P7_Msk                     (0x1U << PORT_PPDER_P7_Pos)                    /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P8_Pos                     (8)                                            /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P8_Msk                     (0x1U << PORT_PPDER_P8_Pos)                    /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P9_Pos                     (9)                                            /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P9_Msk                     (0x1U << PORT_PPDER_P9_Pos)                    /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P10_Pos                    (10)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P10_Msk                    (0x1U << PORT_PPDER_P10_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P11_Pos                    (11)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P11_Msk                    (0x1U << PORT_PPDER_P11_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P12_Pos                    (12)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P12_Msk                    (0x1U << PORT_PPDER_P12_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P13_Pos                    (13)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P13_Msk                    (0x1U << PORT_PPDER_P13_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P14_Pos                    (14)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P14_Msk                    (0x1U << PORT_PPDER_P14_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P15_Pos                    (15)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P15_Msk                    (0x1U << PORT_PPDER_P15_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P16_Pos                    (16)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P16_Msk                    (0x1U << PORT_PPDER_P16_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P17_Pos                    (17)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P17_Msk                    (0x1U << PORT_PPDER_P17_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P18_Pos                    (18)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P18_Msk                    (0x1U << PORT_PPDER_P18_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P19_Pos                    (19)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P19_Msk                    (0x1U << PORT_PPDER_P19_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P20_Pos                    (20)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P20_Msk                    (0x1U << PORT_PPDER_P20_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P21_Pos                    (21)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P21_Msk                    (0x1U << PORT_PPDER_P21_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P22_Pos                    (22)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P22_Msk                    (0x1U << PORT_PPDER_P22_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P23_Pos                    (23)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P23_Msk                    (0x1U << PORT_PPDER_P23_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P24_Pos                    (24)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P24_Msk                    (0x1U << PORT_PPDER_P24_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P25_Pos                    (25)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P25_Msk                    (0x1U << PORT_PPDER_P25_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P26_Pos                    (26)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P26_Msk                    (0x1U << PORT_PPDER_P26_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P27_Pos                    (27)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P27_Msk                    (0x1U << PORT_PPDER_P27_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P28_Pos                    (28)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P28_Msk                    (0x1U << PORT_PPDER_P28_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P29_Pos                    (29)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P29_Msk                    (0x1U << PORT_PPDER_P29_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P30_Pos                    (30)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P30_Msk                    (0x1U << PORT_PPDER_P30_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_P31_Pos                    (31)                                           /**< (PORT_PPDER) Pull-Down Enable Position */
#define PORT_PPDER_P31_Msk                    (0x1U << PORT_PPDER_P31_Pos)                   /**< (PORT_PPDER) Pull-Down Enable Mask */
#define PORT_PPDER_Msk                        (0xFFFFFFFFUL)                                 /**< (PORT_PPDER) Register Mask  */
#define PORT_PPDER_P_Pos                      (0)                                            /**< (PORT_PPDER Position) Pull-Down Enable */
#define PORT_PPDER_P_Msk                      (0xFFFFFFFFU << PORT_PPDER_P_Pos)              /**< (PORT_PPDER Mask) P */
#define PORT_PPDER_P(value)                   (PORT_PPDER_P_Msk & ((value) << PORT_PPDER_P_Pos))

/* -------- PORT_PPDSR : (PORT Offset: 0x98) (R/ 32) Pad Pull-down Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Pull-Down Status                              */
    uint32_t P1:1;                      /**< bit:      1  Pull-Down Status                              */
    uint32_t P2:1;                      /**< bit:      2  Pull-Down Status                              */
    uint32_t P3:1;                      /**< bit:      3  Pull-Down Status                              */
    uint32_t P4:1;                      /**< bit:      4  Pull-Down Status                              */
    uint32_t P5:1;                      /**< bit:      5  Pull-Down Status                              */
    uint32_t P6:1;                      /**< bit:      6  Pull-Down Status                              */
    uint32_t P7:1;                      /**< bit:      7  Pull-Down Status                              */
    uint32_t P8:1;                      /**< bit:      8  Pull-Down Status                              */
    uint32_t P9:1;                      /**< bit:      9  Pull-Down Status                              */
    uint32_t P10:1;                     /**< bit:     10  Pull-Down Status                              */
    uint32_t P11:1;                     /**< bit:     11  Pull-Down Status                              */
    uint32_t P12:1;                     /**< bit:     12  Pull-Down Status                              */
    uint32_t P13:1;                     /**< bit:     13  Pull-Down Status                              */
    uint32_t P14:1;                     /**< bit:     14  Pull-Down Status                              */
    uint32_t P15:1;                     /**< bit:     15  Pull-Down Status                              */
    uint32_t P16:1;                     /**< bit:     16  Pull-Down Status                              */
    uint32_t P17:1;                     /**< bit:     17  Pull-Down Status                              */
    uint32_t P18:1;                     /**< bit:     18  Pull-Down Status                              */
    uint32_t P19:1;                     /**< bit:     19  Pull-Down Status                              */
    uint32_t P20:1;                     /**< bit:     20  Pull-Down Status                              */
    uint32_t P21:1;                     /**< bit:     21  Pull-Down Status                              */
    uint32_t P22:1;                     /**< bit:     22  Pull-Down Status                              */
    uint32_t P23:1;                     /**< bit:     23  Pull-Down Status                              */
    uint32_t P24:1;                     /**< bit:     24  Pull-Down Status                              */
    uint32_t P25:1;                     /**< bit:     25  Pull-Down Status                              */
    uint32_t P26:1;                     /**< bit:     26  Pull-Down Status                              */
    uint32_t P27:1;                     /**< bit:     27  Pull-Down Status                              */
    uint32_t P28:1;                     /**< bit:     28  Pull-Down Status                              */
    uint32_t P29:1;                     /**< bit:     29  Pull-Down Status                              */
    uint32_t P30:1;                     /**< bit:     30  Pull-Down Status                              */
    uint32_t P31:1;                     /**< bit:     31  Pull-Down Status                              */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Pull-Down Status                              */
  };
  uint32_t w;
} __PORT_PPDSR_bits_t;

#define PORT_PPDSR_P0_Pos                     (0)                                            /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P0_Msk                     (0x1U << PORT_PPDSR_P0_Pos)                    /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P1_Pos                     (1)                                            /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P1_Msk                     (0x1U << PORT_PPDSR_P1_Pos)                    /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P2_Pos                     (2)                                            /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P2_Msk                     (0x1U << PORT_PPDSR_P2_Pos)                    /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P3_Pos                     (3)                                            /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P3_Msk                     (0x1U << PORT_PPDSR_P3_Pos)                    /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P4_Pos                     (4)                                            /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P4_Msk                     (0x1U << PORT_PPDSR_P4_Pos)                    /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P5_Pos                     (5)                                            /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P5_Msk                     (0x1U << PORT_PPDSR_P5_Pos)                    /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P6_Pos                     (6)                                            /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P6_Msk                     (0x1U << PORT_PPDSR_P6_Pos)                    /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P7_Pos                     (7)                                            /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P7_Msk                     (0x1U << PORT_PPDSR_P7_Pos)                    /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P8_Pos                     (8)                                            /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P8_Msk                     (0x1U << PORT_PPDSR_P8_Pos)                    /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P9_Pos                     (9)                                            /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P9_Msk                     (0x1U << PORT_PPDSR_P9_Pos)                    /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P10_Pos                    (10)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P10_Msk                    (0x1U << PORT_PPDSR_P10_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P11_Pos                    (11)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P11_Msk                    (0x1U << PORT_PPDSR_P11_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P12_Pos                    (12)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P12_Msk                    (0x1U << PORT_PPDSR_P12_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P13_Pos                    (13)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P13_Msk                    (0x1U << PORT_PPDSR_P13_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P14_Pos                    (14)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P14_Msk                    (0x1U << PORT_PPDSR_P14_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P15_Pos                    (15)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P15_Msk                    (0x1U << PORT_PPDSR_P15_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P16_Pos                    (16)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P16_Msk                    (0x1U << PORT_PPDSR_P16_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P17_Pos                    (17)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P17_Msk                    (0x1U << PORT_PPDSR_P17_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P18_Pos                    (18)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P18_Msk                    (0x1U << PORT_PPDSR_P18_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P19_Pos                    (19)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P19_Msk                    (0x1U << PORT_PPDSR_P19_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P20_Pos                    (20)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P20_Msk                    (0x1U << PORT_PPDSR_P20_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P21_Pos                    (21)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P21_Msk                    (0x1U << PORT_PPDSR_P21_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P22_Pos                    (22)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P22_Msk                    (0x1U << PORT_PPDSR_P22_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P23_Pos                    (23)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P23_Msk                    (0x1U << PORT_PPDSR_P23_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P24_Pos                    (24)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P24_Msk                    (0x1U << PORT_PPDSR_P24_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P25_Pos                    (25)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P25_Msk                    (0x1U << PORT_PPDSR_P25_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P26_Pos                    (26)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P26_Msk                    (0x1U << PORT_PPDSR_P26_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P27_Pos                    (27)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P27_Msk                    (0x1U << PORT_PPDSR_P27_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P28_Pos                    (28)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P28_Msk                    (0x1U << PORT_PPDSR_P28_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P29_Pos                    (29)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P29_Msk                    (0x1U << PORT_PPDSR_P29_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P30_Pos                    (30)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P30_Msk                    (0x1U << PORT_PPDSR_P30_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_P31_Pos                    (31)                                           /**< (PORT_PPDSR) Pull-Down Status Position */
#define PORT_PPDSR_P31_Msk                    (0x1U << PORT_PPDSR_P31_Pos)                   /**< (PORT_PPDSR) Pull-Down Status Mask */
#define PORT_PPDSR_Msk                        (0xFFFFFFFFUL)                                 /**< (PORT_PPDSR) Register Mask  */
#define PORT_PPDSR_P_Pos                      (0)                                            /**< (PORT_PPDSR Position) Pull-Down Status */
#define PORT_PPDSR_P_Msk                      (0xFFFFFFFFU << PORT_PPDSR_P_Pos)              /**< (PORT_PPDSR Mask) P */
#define PORT_PPDSR_P(value)                   (PORT_PPDSR_P_Msk & ((value) << PORT_PPDSR_P_Pos))

/* -------- PORT_OWER : (PORT Offset: 0xa0) (/W 32) Output Write Enable -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Output Write Enable                           */
    uint32_t P1:1;                      /**< bit:      1  Output Write Enable                           */
    uint32_t P2:1;                      /**< bit:      2  Output Write Enable                           */
    uint32_t P3:1;                      /**< bit:      3  Output Write Enable                           */
    uint32_t P4:1;                      /**< bit:      4  Output Write Enable                           */
    uint32_t P5:1;                      /**< bit:      5  Output Write Enable                           */
    uint32_t P6:1;                      /**< bit:      6  Output Write Enable                           */
    uint32_t P7:1;                      /**< bit:      7  Output Write Enable                           */
    uint32_t P8:1;                      /**< bit:      8  Output Write Enable                           */
    uint32_t P9:1;                      /**< bit:      9  Output Write Enable                           */
    uint32_t P10:1;                     /**< bit:     10  Output Write Enable                           */
    uint32_t P11:1;                     /**< bit:     11  Output Write Enable                           */
    uint32_t P12:1;                     /**< bit:     12  Output Write Enable                           */
    uint32_t P13:1;                     /**< bit:     13  Output Write Enable                           */
    uint32_t P14:1;                     /**< bit:     14  Output Write Enable                           */
    uint32_t P15:1;                     /**< bit:     15  Output Write Enable                           */
    uint32_t P16:1;                     /**< bit:     16  Output Write Enable                           */
    uint32_t P17:1;                     /**< bit:     17  Output Write Enable                           */
    uint32_t P18:1;                     /**< bit:     18  Output Write Enable                           */
    uint32_t P19:1;                     /**< bit:     19  Output Write Enable                           */
    uint32_t P20:1;                     /**< bit:     20  Output Write Enable                           */
    uint32_t P21:1;                     /**< bit:     21  Output Write Enable                           */
    uint32_t P22:1;                     /**< bit:     22  Output Write Enable                           */
    uint32_t P23:1;                     /**< bit:     23  Output Write Enable                           */
    uint32_t P24:1;                     /**< bit:     24  Output Write Enable                           */
    uint32_t P25:1;                     /**< bit:     25  Output Write Enable                           */
    uint32_t P26:1;                     /**< bit:     26  Output Write Enable                           */
    uint32_t P27:1;                     /**< bit:     27  Output Write Enable                           */
    uint32_t P28:1;                     /**< bit:     28  Output Write Enable                           */
    uint32_t P29:1;                     /**< bit:     29  Output Write Enable                           */
    uint32_t P30:1;                     /**< bit:     30  Output Write Enable                           */
    uint32_t P31:1;                     /**< bit:     31  Output Write Enable                           */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Output Write Enable                           */
  };
  uint32_t w;
} __PORT_OWER_bits_t;

#define PORT_OWER_P0_Pos                      (0)                                            /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P0_Msk                      (0x1U << PORT_OWER_P0_Pos)                     /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P1_Pos                      (1)                                            /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P1_Msk                      (0x1U << PORT_OWER_P1_Pos)                     /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P2_Pos                      (2)                                            /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P2_Msk                      (0x1U << PORT_OWER_P2_Pos)                     /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P3_Pos                      (3)                                            /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P3_Msk                      (0x1U << PORT_OWER_P3_Pos)                     /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P4_Pos                      (4)                                            /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P4_Msk                      (0x1U << PORT_OWER_P4_Pos)                     /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P5_Pos                      (5)                                            /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P5_Msk                      (0x1U << PORT_OWER_P5_Pos)                     /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P6_Pos                      (6)                                            /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P6_Msk                      (0x1U << PORT_OWER_P6_Pos)                     /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P7_Pos                      (7)                                            /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P7_Msk                      (0x1U << PORT_OWER_P7_Pos)                     /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P8_Pos                      (8)                                            /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P8_Msk                      (0x1U << PORT_OWER_P8_Pos)                     /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P9_Pos                      (9)                                            /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P9_Msk                      (0x1U << PORT_OWER_P9_Pos)                     /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P10_Pos                     (10)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P10_Msk                     (0x1U << PORT_OWER_P10_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P11_Pos                     (11)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P11_Msk                     (0x1U << PORT_OWER_P11_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P12_Pos                     (12)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P12_Msk                     (0x1U << PORT_OWER_P12_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P13_Pos                     (13)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P13_Msk                     (0x1U << PORT_OWER_P13_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P14_Pos                     (14)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P14_Msk                     (0x1U << PORT_OWER_P14_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P15_Pos                     (15)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P15_Msk                     (0x1U << PORT_OWER_P15_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P16_Pos                     (16)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P16_Msk                     (0x1U << PORT_OWER_P16_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P17_Pos                     (17)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P17_Msk                     (0x1U << PORT_OWER_P17_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P18_Pos                     (18)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P18_Msk                     (0x1U << PORT_OWER_P18_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P19_Pos                     (19)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P19_Msk                     (0x1U << PORT_OWER_P19_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P20_Pos                     (20)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P20_Msk                     (0x1U << PORT_OWER_P20_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P21_Pos                     (21)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P21_Msk                     (0x1U << PORT_OWER_P21_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P22_Pos                     (22)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P22_Msk                     (0x1U << PORT_OWER_P22_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P23_Pos                     (23)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P23_Msk                     (0x1U << PORT_OWER_P23_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P24_Pos                     (24)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P24_Msk                     (0x1U << PORT_OWER_P24_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P25_Pos                     (25)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P25_Msk                     (0x1U << PORT_OWER_P25_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P26_Pos                     (26)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P26_Msk                     (0x1U << PORT_OWER_P26_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P27_Pos                     (27)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P27_Msk                     (0x1U << PORT_OWER_P27_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P28_Pos                     (28)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P28_Msk                     (0x1U << PORT_OWER_P28_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P29_Pos                     (29)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P29_Msk                     (0x1U << PORT_OWER_P29_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P30_Pos                     (30)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P30_Msk                     (0x1U << PORT_OWER_P30_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_P31_Pos                     (31)                                           /**< (PORT_OWER) Output Write Enable Position */
#define PORT_OWER_P31_Msk                     (0x1U << PORT_OWER_P31_Pos)                    /**< (PORT_OWER) Output Write Enable Mask */
#define PORT_OWER_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_OWER) Register Mask  */
#define PORT_OWER_P_Pos                       (0)                                            /**< (PORT_OWER Position) Output Write Enable */
#define PORT_OWER_P_Msk                       (0xFFFFFFFFU << PORT_OWER_P_Pos)               /**< (PORT_OWER Mask) P */
#define PORT_OWER_P(value)                    (PORT_OWER_P_Msk & ((value) << PORT_OWER_P_Pos))

/* -------- PORT_OWDR : (PORT Offset: 0xa4) (/W 32) Output Write Disable -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Output Write Disable                          */
    uint32_t P1:1;                      /**< bit:      1  Output Write Disable                          */
    uint32_t P2:1;                      /**< bit:      2  Output Write Disable                          */
    uint32_t P3:1;                      /**< bit:      3  Output Write Disable                          */
    uint32_t P4:1;                      /**< bit:      4  Output Write Disable                          */
    uint32_t P5:1;                      /**< bit:      5  Output Write Disable                          */
    uint32_t P6:1;                      /**< bit:      6  Output Write Disable                          */
    uint32_t P7:1;                      /**< bit:      7  Output Write Disable                          */
    uint32_t P8:1;                      /**< bit:      8  Output Write Disable                          */
    uint32_t P9:1;                      /**< bit:      9  Output Write Disable                          */
    uint32_t P10:1;                     /**< bit:     10  Output Write Disable                          */
    uint32_t P11:1;                     /**< bit:     11  Output Write Disable                          */
    uint32_t P12:1;                     /**< bit:     12  Output Write Disable                          */
    uint32_t P13:1;                     /**< bit:     13  Output Write Disable                          */
    uint32_t P14:1;                     /**< bit:     14  Output Write Disable                          */
    uint32_t P15:1;                     /**< bit:     15  Output Write Disable                          */
    uint32_t P16:1;                     /**< bit:     16  Output Write Disable                          */
    uint32_t P17:1;                     /**< bit:     17  Output Write Disable                          */
    uint32_t P18:1;                     /**< bit:     18  Output Write Disable                          */
    uint32_t P19:1;                     /**< bit:     19  Output Write Disable                          */
    uint32_t P20:1;                     /**< bit:     20  Output Write Disable                          */
    uint32_t P21:1;                     /**< bit:     21  Output Write Disable                          */
    uint32_t P22:1;                     /**< bit:     22  Output Write Disable                          */
    uint32_t P23:1;                     /**< bit:     23  Output Write Disable                          */
    uint32_t P24:1;                     /**< bit:     24  Output Write Disable                          */
    uint32_t P25:1;                     /**< bit:     25  Output Write Disable                          */
    uint32_t P26:1;                     /**< bit:     26  Output Write Disable                          */
    uint32_t P27:1;                     /**< bit:     27  Output Write Disable                          */
    uint32_t P28:1;                     /**< bit:     28  Output Write Disable                          */
    uint32_t P29:1;                     /**< bit:     29  Output Write Disable                          */
    uint32_t P30:1;                     /**< bit:     30  Output Write Disable                          */
    uint32_t P31:1;                     /**< bit:     31  Output Write Disable                          */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Output Write Disable                          */
  };
  uint32_t w;
} __PORT_OWDR_bits_t;

#define PORT_OWDR_P0_Pos                      (0)                                            /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P0_Msk                      (0x1U << PORT_OWDR_P0_Pos)                     /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P1_Pos                      (1)                                            /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P1_Msk                      (0x1U << PORT_OWDR_P1_Pos)                     /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P2_Pos                      (2)                                            /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P2_Msk                      (0x1U << PORT_OWDR_P2_Pos)                     /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P3_Pos                      (3)                                            /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P3_Msk                      (0x1U << PORT_OWDR_P3_Pos)                     /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P4_Pos                      (4)                                            /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P4_Msk                      (0x1U << PORT_OWDR_P4_Pos)                     /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P5_Pos                      (5)                                            /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P5_Msk                      (0x1U << PORT_OWDR_P5_Pos)                     /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P6_Pos                      (6)                                            /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P6_Msk                      (0x1U << PORT_OWDR_P6_Pos)                     /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P7_Pos                      (7)                                            /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P7_Msk                      (0x1U << PORT_OWDR_P7_Pos)                     /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P8_Pos                      (8)                                            /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P8_Msk                      (0x1U << PORT_OWDR_P8_Pos)                     /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P9_Pos                      (9)                                            /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P9_Msk                      (0x1U << PORT_OWDR_P9_Pos)                     /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P10_Pos                     (10)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P10_Msk                     (0x1U << PORT_OWDR_P10_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P11_Pos                     (11)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P11_Msk                     (0x1U << PORT_OWDR_P11_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P12_Pos                     (12)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P12_Msk                     (0x1U << PORT_OWDR_P12_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P13_Pos                     (13)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P13_Msk                     (0x1U << PORT_OWDR_P13_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P14_Pos                     (14)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P14_Msk                     (0x1U << PORT_OWDR_P14_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P15_Pos                     (15)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P15_Msk                     (0x1U << PORT_OWDR_P15_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P16_Pos                     (16)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P16_Msk                     (0x1U << PORT_OWDR_P16_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P17_Pos                     (17)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P17_Msk                     (0x1U << PORT_OWDR_P17_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P18_Pos                     (18)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P18_Msk                     (0x1U << PORT_OWDR_P18_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P19_Pos                     (19)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P19_Msk                     (0x1U << PORT_OWDR_P19_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P20_Pos                     (20)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P20_Msk                     (0x1U << PORT_OWDR_P20_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P21_Pos                     (21)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P21_Msk                     (0x1U << PORT_OWDR_P21_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P22_Pos                     (22)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P22_Msk                     (0x1U << PORT_OWDR_P22_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P23_Pos                     (23)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P23_Msk                     (0x1U << PORT_OWDR_P23_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P24_Pos                     (24)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P24_Msk                     (0x1U << PORT_OWDR_P24_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P25_Pos                     (25)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P25_Msk                     (0x1U << PORT_OWDR_P25_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P26_Pos                     (26)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P26_Msk                     (0x1U << PORT_OWDR_P26_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P27_Pos                     (27)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P27_Msk                     (0x1U << PORT_OWDR_P27_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P28_Pos                     (28)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P28_Msk                     (0x1U << PORT_OWDR_P28_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P29_Pos                     (29)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P29_Msk                     (0x1U << PORT_OWDR_P29_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P30_Pos                     (30)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P30_Msk                     (0x1U << PORT_OWDR_P30_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_P31_Pos                     (31)                                           /**< (PORT_OWDR) Output Write Disable Position */
#define PORT_OWDR_P31_Msk                     (0x1U << PORT_OWDR_P31_Pos)                    /**< (PORT_OWDR) Output Write Disable Mask */
#define PORT_OWDR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_OWDR) Register Mask  */
#define PORT_OWDR_P_Pos                       (0)                                            /**< (PORT_OWDR Position) Output Write Disable */
#define PORT_OWDR_P_Msk                       (0xFFFFFFFFU << PORT_OWDR_P_Pos)               /**< (PORT_OWDR Mask) P */
#define PORT_OWDR_P(value)                    (PORT_OWDR_P_Msk & ((value) << PORT_OWDR_P_Pos))

/* -------- PORT_OWSR : (PORT Offset: 0xa8) (R/ 32) Output Write Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Output Write Status                           */
    uint32_t P1:1;                      /**< bit:      1  Output Write Status                           */
    uint32_t P2:1;                      /**< bit:      2  Output Write Status                           */
    uint32_t P3:1;                      /**< bit:      3  Output Write Status                           */
    uint32_t P4:1;                      /**< bit:      4  Output Write Status                           */
    uint32_t P5:1;                      /**< bit:      5  Output Write Status                           */
    uint32_t P6:1;                      /**< bit:      6  Output Write Status                           */
    uint32_t P7:1;                      /**< bit:      7  Output Write Status                           */
    uint32_t P8:1;                      /**< bit:      8  Output Write Status                           */
    uint32_t P9:1;                      /**< bit:      9  Output Write Status                           */
    uint32_t P10:1;                     /**< bit:     10  Output Write Status                           */
    uint32_t P11:1;                     /**< bit:     11  Output Write Status                           */
    uint32_t P12:1;                     /**< bit:     12  Output Write Status                           */
    uint32_t P13:1;                     /**< bit:     13  Output Write Status                           */
    uint32_t P14:1;                     /**< bit:     14  Output Write Status                           */
    uint32_t P15:1;                     /**< bit:     15  Output Write Status                           */
    uint32_t P16:1;                     /**< bit:     16  Output Write Status                           */
    uint32_t P17:1;                     /**< bit:     17  Output Write Status                           */
    uint32_t P18:1;                     /**< bit:     18  Output Write Status                           */
    uint32_t P19:1;                     /**< bit:     19  Output Write Status                           */
    uint32_t P20:1;                     /**< bit:     20  Output Write Status                           */
    uint32_t P21:1;                     /**< bit:     21  Output Write Status                           */
    uint32_t P22:1;                     /**< bit:     22  Output Write Status                           */
    uint32_t P23:1;                     /**< bit:     23  Output Write Status                           */
    uint32_t P24:1;                     /**< bit:     24  Output Write Status                           */
    uint32_t P25:1;                     /**< bit:     25  Output Write Status                           */
    uint32_t P26:1;                     /**< bit:     26  Output Write Status                           */
    uint32_t P27:1;                     /**< bit:     27  Output Write Status                           */
    uint32_t P28:1;                     /**< bit:     28  Output Write Status                           */
    uint32_t P29:1;                     /**< bit:     29  Output Write Status                           */
    uint32_t P30:1;                     /**< bit:     30  Output Write Status                           */
    uint32_t P31:1;                     /**< bit:     31  Output Write Status                           */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Output Write Status                           */
  };
  uint32_t w;
} __PORT_OWSR_bits_t;

#define PORT_OWSR_P0_Pos                      (0)                                            /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P0_Msk                      (0x1U << PORT_OWSR_P0_Pos)                     /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P1_Pos                      (1)                                            /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P1_Msk                      (0x1U << PORT_OWSR_P1_Pos)                     /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P2_Pos                      (2)                                            /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P2_Msk                      (0x1U << PORT_OWSR_P2_Pos)                     /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P3_Pos                      (3)                                            /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P3_Msk                      (0x1U << PORT_OWSR_P3_Pos)                     /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P4_Pos                      (4)                                            /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P4_Msk                      (0x1U << PORT_OWSR_P4_Pos)                     /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P5_Pos                      (5)                                            /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P5_Msk                      (0x1U << PORT_OWSR_P5_Pos)                     /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P6_Pos                      (6)                                            /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P6_Msk                      (0x1U << PORT_OWSR_P6_Pos)                     /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P7_Pos                      (7)                                            /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P7_Msk                      (0x1U << PORT_OWSR_P7_Pos)                     /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P8_Pos                      (8)                                            /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P8_Msk                      (0x1U << PORT_OWSR_P8_Pos)                     /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P9_Pos                      (9)                                            /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P9_Msk                      (0x1U << PORT_OWSR_P9_Pos)                     /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P10_Pos                     (10)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P10_Msk                     (0x1U << PORT_OWSR_P10_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P11_Pos                     (11)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P11_Msk                     (0x1U << PORT_OWSR_P11_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P12_Pos                     (12)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P12_Msk                     (0x1U << PORT_OWSR_P12_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P13_Pos                     (13)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P13_Msk                     (0x1U << PORT_OWSR_P13_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P14_Pos                     (14)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P14_Msk                     (0x1U << PORT_OWSR_P14_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P15_Pos                     (15)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P15_Msk                     (0x1U << PORT_OWSR_P15_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P16_Pos                     (16)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P16_Msk                     (0x1U << PORT_OWSR_P16_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P17_Pos                     (17)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P17_Msk                     (0x1U << PORT_OWSR_P17_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P18_Pos                     (18)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P18_Msk                     (0x1U << PORT_OWSR_P18_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P19_Pos                     (19)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P19_Msk                     (0x1U << PORT_OWSR_P19_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P20_Pos                     (20)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P20_Msk                     (0x1U << PORT_OWSR_P20_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P21_Pos                     (21)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P21_Msk                     (0x1U << PORT_OWSR_P21_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P22_Pos                     (22)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P22_Msk                     (0x1U << PORT_OWSR_P22_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P23_Pos                     (23)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P23_Msk                     (0x1U << PORT_OWSR_P23_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P24_Pos                     (24)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P24_Msk                     (0x1U << PORT_OWSR_P24_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P25_Pos                     (25)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P25_Msk                     (0x1U << PORT_OWSR_P25_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P26_Pos                     (26)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P26_Msk                     (0x1U << PORT_OWSR_P26_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P27_Pos                     (27)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P27_Msk                     (0x1U << PORT_OWSR_P27_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P28_Pos                     (28)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P28_Msk                     (0x1U << PORT_OWSR_P28_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P29_Pos                     (29)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P29_Msk                     (0x1U << PORT_OWSR_P29_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P30_Pos                     (30)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P30_Msk                     (0x1U << PORT_OWSR_P30_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_P31_Pos                     (31)                                           /**< (PORT_OWSR) Output Write Status Position */
#define PORT_OWSR_P31_Msk                     (0x1U << PORT_OWSR_P31_Pos)                    /**< (PORT_OWSR) Output Write Status Mask */
#define PORT_OWSR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_OWSR) Register Mask  */
#define PORT_OWSR_P_Pos                       (0)                                            /**< (PORT_OWSR Position) Output Write Status */
#define PORT_OWSR_P_Msk                       (0xFFFFFFFFU << PORT_OWSR_P_Pos)               /**< (PORT_OWSR Mask) P */
#define PORT_OWSR_P(value)                    (PORT_OWSR_P_Msk & ((value) << PORT_OWSR_P_Pos))

/* -------- PORT_AIMER : (PORT Offset: 0xb0) (/W 32) Additional Interrupt Modes Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Additional Interrupt Modes Enable             */
    uint32_t P1:1;                      /**< bit:      1  Additional Interrupt Modes Enable             */
    uint32_t P2:1;                      /**< bit:      2  Additional Interrupt Modes Enable             */
    uint32_t P3:1;                      /**< bit:      3  Additional Interrupt Modes Enable             */
    uint32_t P4:1;                      /**< bit:      4  Additional Interrupt Modes Enable             */
    uint32_t P5:1;                      /**< bit:      5  Additional Interrupt Modes Enable             */
    uint32_t P6:1;                      /**< bit:      6  Additional Interrupt Modes Enable             */
    uint32_t P7:1;                      /**< bit:      7  Additional Interrupt Modes Enable             */
    uint32_t P8:1;                      /**< bit:      8  Additional Interrupt Modes Enable             */
    uint32_t P9:1;                      /**< bit:      9  Additional Interrupt Modes Enable             */
    uint32_t P10:1;                     /**< bit:     10  Additional Interrupt Modes Enable             */
    uint32_t P11:1;                     /**< bit:     11  Additional Interrupt Modes Enable             */
    uint32_t P12:1;                     /**< bit:     12  Additional Interrupt Modes Enable             */
    uint32_t P13:1;                     /**< bit:     13  Additional Interrupt Modes Enable             */
    uint32_t P14:1;                     /**< bit:     14  Additional Interrupt Modes Enable             */
    uint32_t P15:1;                     /**< bit:     15  Additional Interrupt Modes Enable             */
    uint32_t P16:1;                     /**< bit:     16  Additional Interrupt Modes Enable             */
    uint32_t P17:1;                     /**< bit:     17  Additional Interrupt Modes Enable             */
    uint32_t P18:1;                     /**< bit:     18  Additional Interrupt Modes Enable             */
    uint32_t P19:1;                     /**< bit:     19  Additional Interrupt Modes Enable             */
    uint32_t P20:1;                     /**< bit:     20  Additional Interrupt Modes Enable             */
    uint32_t P21:1;                     /**< bit:     21  Additional Interrupt Modes Enable             */
    uint32_t P22:1;                     /**< bit:     22  Additional Interrupt Modes Enable             */
    uint32_t P23:1;                     /**< bit:     23  Additional Interrupt Modes Enable             */
    uint32_t P24:1;                     /**< bit:     24  Additional Interrupt Modes Enable             */
    uint32_t P25:1;                     /**< bit:     25  Additional Interrupt Modes Enable             */
    uint32_t P26:1;                     /**< bit:     26  Additional Interrupt Modes Enable             */
    uint32_t P27:1;                     /**< bit:     27  Additional Interrupt Modes Enable             */
    uint32_t P28:1;                     /**< bit:     28  Additional Interrupt Modes Enable             */
    uint32_t P29:1;                     /**< bit:     29  Additional Interrupt Modes Enable             */
    uint32_t P30:1;                     /**< bit:     30  Additional Interrupt Modes Enable             */
    uint32_t P31:1;                     /**< bit:     31  Additional Interrupt Modes Enable             */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Additional Interrupt Modes Enable             */
  };
  uint32_t w;
} __PORT_AIMER_bits_t;

#define PORT_AIMER_P0_Pos                     (0)                                            /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P0_Msk                     (0x1U << PORT_AIMER_P0_Pos)                    /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P1_Pos                     (1)                                            /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P1_Msk                     (0x1U << PORT_AIMER_P1_Pos)                    /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P2_Pos                     (2)                                            /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P2_Msk                     (0x1U << PORT_AIMER_P2_Pos)                    /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P3_Pos                     (3)                                            /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P3_Msk                     (0x1U << PORT_AIMER_P3_Pos)                    /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P4_Pos                     (4)                                            /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P4_Msk                     (0x1U << PORT_AIMER_P4_Pos)                    /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P5_Pos                     (5)                                            /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P5_Msk                     (0x1U << PORT_AIMER_P5_Pos)                    /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P6_Pos                     (6)                                            /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P6_Msk                     (0x1U << PORT_AIMER_P6_Pos)                    /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P7_Pos                     (7)                                            /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P7_Msk                     (0x1U << PORT_AIMER_P7_Pos)                    /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P8_Pos                     (8)                                            /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P8_Msk                     (0x1U << PORT_AIMER_P8_Pos)                    /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P9_Pos                     (9)                                            /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P9_Msk                     (0x1U << PORT_AIMER_P9_Pos)                    /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P10_Pos                    (10)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P10_Msk                    (0x1U << PORT_AIMER_P10_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P11_Pos                    (11)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P11_Msk                    (0x1U << PORT_AIMER_P11_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P12_Pos                    (12)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P12_Msk                    (0x1U << PORT_AIMER_P12_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P13_Pos                    (13)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P13_Msk                    (0x1U << PORT_AIMER_P13_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P14_Pos                    (14)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P14_Msk                    (0x1U << PORT_AIMER_P14_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P15_Pos                    (15)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P15_Msk                    (0x1U << PORT_AIMER_P15_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P16_Pos                    (16)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P16_Msk                    (0x1U << PORT_AIMER_P16_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P17_Pos                    (17)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P17_Msk                    (0x1U << PORT_AIMER_P17_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P18_Pos                    (18)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P18_Msk                    (0x1U << PORT_AIMER_P18_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P19_Pos                    (19)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P19_Msk                    (0x1U << PORT_AIMER_P19_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P20_Pos                    (20)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P20_Msk                    (0x1U << PORT_AIMER_P20_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P21_Pos                    (21)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P21_Msk                    (0x1U << PORT_AIMER_P21_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P22_Pos                    (22)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P22_Msk                    (0x1U << PORT_AIMER_P22_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P23_Pos                    (23)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P23_Msk                    (0x1U << PORT_AIMER_P23_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P24_Pos                    (24)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P24_Msk                    (0x1U << PORT_AIMER_P24_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P25_Pos                    (25)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P25_Msk                    (0x1U << PORT_AIMER_P25_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P26_Pos                    (26)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P26_Msk                    (0x1U << PORT_AIMER_P26_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P27_Pos                    (27)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P27_Msk                    (0x1U << PORT_AIMER_P27_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P28_Pos                    (28)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P28_Msk                    (0x1U << PORT_AIMER_P28_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P29_Pos                    (29)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P29_Msk                    (0x1U << PORT_AIMER_P29_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P30_Pos                    (30)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P30_Msk                    (0x1U << PORT_AIMER_P30_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_P31_Pos                    (31)                                           /**< (PORT_AIMER) Additional Interrupt Modes Enable Position */
#define PORT_AIMER_P31_Msk                    (0x1U << PORT_AIMER_P31_Pos)                   /**< (PORT_AIMER) Additional Interrupt Modes Enable Mask */
#define PORT_AIMER_Msk                        (0xFFFFFFFFUL)                                 /**< (PORT_AIMER) Register Mask  */
#define PORT_AIMER_P_Pos                      (0)                                            /**< (PORT_AIMER Position) Additional Interrupt Modes Enable */
#define PORT_AIMER_P_Msk                      (0xFFFFFFFFU << PORT_AIMER_P_Pos)              /**< (PORT_AIMER Mask) P */
#define PORT_AIMER_P(value)                   (PORT_AIMER_P_Msk & ((value) << PORT_AIMER_P_Pos))

/* -------- PORT_AIMDR : (PORT Offset: 0xb4) (/W 32) Additional Interrupt Modes Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Additional Interrupt Modes Disable            */
    uint32_t P1:1;                      /**< bit:      1  Additional Interrupt Modes Disable            */
    uint32_t P2:1;                      /**< bit:      2  Additional Interrupt Modes Disable            */
    uint32_t P3:1;                      /**< bit:      3  Additional Interrupt Modes Disable            */
    uint32_t P4:1;                      /**< bit:      4  Additional Interrupt Modes Disable            */
    uint32_t P5:1;                      /**< bit:      5  Additional Interrupt Modes Disable            */
    uint32_t P6:1;                      /**< bit:      6  Additional Interrupt Modes Disable            */
    uint32_t P7:1;                      /**< bit:      7  Additional Interrupt Modes Disable            */
    uint32_t P8:1;                      /**< bit:      8  Additional Interrupt Modes Disable            */
    uint32_t P9:1;                      /**< bit:      9  Additional Interrupt Modes Disable            */
    uint32_t P10:1;                     /**< bit:     10  Additional Interrupt Modes Disable            */
    uint32_t P11:1;                     /**< bit:     11  Additional Interrupt Modes Disable            */
    uint32_t P12:1;                     /**< bit:     12  Additional Interrupt Modes Disable            */
    uint32_t P13:1;                     /**< bit:     13  Additional Interrupt Modes Disable            */
    uint32_t P14:1;                     /**< bit:     14  Additional Interrupt Modes Disable            */
    uint32_t P15:1;                     /**< bit:     15  Additional Interrupt Modes Disable            */
    uint32_t P16:1;                     /**< bit:     16  Additional Interrupt Modes Disable            */
    uint32_t P17:1;                     /**< bit:     17  Additional Interrupt Modes Disable            */
    uint32_t P18:1;                     /**< bit:     18  Additional Interrupt Modes Disable            */
    uint32_t P19:1;                     /**< bit:     19  Additional Interrupt Modes Disable            */
    uint32_t P20:1;                     /**< bit:     20  Additional Interrupt Modes Disable            */
    uint32_t P21:1;                     /**< bit:     21  Additional Interrupt Modes Disable            */
    uint32_t P22:1;                     /**< bit:     22  Additional Interrupt Modes Disable            */
    uint32_t P23:1;                     /**< bit:     23  Additional Interrupt Modes Disable            */
    uint32_t P24:1;                     /**< bit:     24  Additional Interrupt Modes Disable            */
    uint32_t P25:1;                     /**< bit:     25  Additional Interrupt Modes Disable            */
    uint32_t P26:1;                     /**< bit:     26  Additional Interrupt Modes Disable            */
    uint32_t P27:1;                     /**< bit:     27  Additional Interrupt Modes Disable            */
    uint32_t P28:1;                     /**< bit:     28  Additional Interrupt Modes Disable            */
    uint32_t P29:1;                     /**< bit:     29  Additional Interrupt Modes Disable            */
    uint32_t P30:1;                     /**< bit:     30  Additional Interrupt Modes Disable            */
    uint32_t P31:1;                     /**< bit:     31  Additional Interrupt Modes Disable            */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Additional Interrupt Modes Disable            */
  };
  uint32_t w;
} __PORT_AIMDR_bits_t;

#define PORT_AIMDR_P0_Pos                     (0)                                            /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P0_Msk                     (0x1U << PORT_AIMDR_P0_Pos)                    /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P1_Pos                     (1)                                            /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P1_Msk                     (0x1U << PORT_AIMDR_P1_Pos)                    /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P2_Pos                     (2)                                            /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P2_Msk                     (0x1U << PORT_AIMDR_P2_Pos)                    /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P3_Pos                     (3)                                            /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P3_Msk                     (0x1U << PORT_AIMDR_P3_Pos)                    /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P4_Pos                     (4)                                            /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P4_Msk                     (0x1U << PORT_AIMDR_P4_Pos)                    /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P5_Pos                     (5)                                            /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P5_Msk                     (0x1U << PORT_AIMDR_P5_Pos)                    /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P6_Pos                     (6)                                            /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P6_Msk                     (0x1U << PORT_AIMDR_P6_Pos)                    /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P7_Pos                     (7)                                            /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P7_Msk                     (0x1U << PORT_AIMDR_P7_Pos)                    /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P8_Pos                     (8)                                            /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P8_Msk                     (0x1U << PORT_AIMDR_P8_Pos)                    /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P9_Pos                     (9)                                            /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P9_Msk                     (0x1U << PORT_AIMDR_P9_Pos)                    /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P10_Pos                    (10)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P10_Msk                    (0x1U << PORT_AIMDR_P10_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P11_Pos                    (11)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P11_Msk                    (0x1U << PORT_AIMDR_P11_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P12_Pos                    (12)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P12_Msk                    (0x1U << PORT_AIMDR_P12_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P13_Pos                    (13)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P13_Msk                    (0x1U << PORT_AIMDR_P13_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P14_Pos                    (14)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P14_Msk                    (0x1U << PORT_AIMDR_P14_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P15_Pos                    (15)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P15_Msk                    (0x1U << PORT_AIMDR_P15_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P16_Pos                    (16)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P16_Msk                    (0x1U << PORT_AIMDR_P16_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P17_Pos                    (17)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P17_Msk                    (0x1U << PORT_AIMDR_P17_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P18_Pos                    (18)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P18_Msk                    (0x1U << PORT_AIMDR_P18_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P19_Pos                    (19)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P19_Msk                    (0x1U << PORT_AIMDR_P19_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P20_Pos                    (20)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P20_Msk                    (0x1U << PORT_AIMDR_P20_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P21_Pos                    (21)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P21_Msk                    (0x1U << PORT_AIMDR_P21_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P22_Pos                    (22)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P22_Msk                    (0x1U << PORT_AIMDR_P22_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P23_Pos                    (23)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P23_Msk                    (0x1U << PORT_AIMDR_P23_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P24_Pos                    (24)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P24_Msk                    (0x1U << PORT_AIMDR_P24_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P25_Pos                    (25)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P25_Msk                    (0x1U << PORT_AIMDR_P25_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P26_Pos                    (26)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P26_Msk                    (0x1U << PORT_AIMDR_P26_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P27_Pos                    (27)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P27_Msk                    (0x1U << PORT_AIMDR_P27_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P28_Pos                    (28)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P28_Msk                    (0x1U << PORT_AIMDR_P28_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P29_Pos                    (29)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P29_Msk                    (0x1U << PORT_AIMDR_P29_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P30_Pos                    (30)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P30_Msk                    (0x1U << PORT_AIMDR_P30_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_P31_Pos                    (31)                                           /**< (PORT_AIMDR) Additional Interrupt Modes Disable Position */
#define PORT_AIMDR_P31_Msk                    (0x1U << PORT_AIMDR_P31_Pos)                   /**< (PORT_AIMDR) Additional Interrupt Modes Disable Mask */
#define PORT_AIMDR_Msk                        (0xFFFFFFFFUL)                                 /**< (PORT_AIMDR) Register Mask  */
#define PORT_AIMDR_P_Pos                      (0)                                            /**< (PORT_AIMDR Position) Additional Interrupt Modes Disable */
#define PORT_AIMDR_P_Msk                      (0xFFFFFFFFU << PORT_AIMDR_P_Pos)              /**< (PORT_AIMDR Mask) P */
#define PORT_AIMDR_P(value)                   (PORT_AIMDR_P_Msk & ((value) << PORT_AIMDR_P_Pos))

/* -------- PORT_AIMMR : (PORT Offset: 0xb8) (R/ 32) Additional Interrupt Modes Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  IO Line Index                                 */
    uint32_t P1:1;                      /**< bit:      1  IO Line Index                                 */
    uint32_t P2:1;                      /**< bit:      2  IO Line Index                                 */
    uint32_t P3:1;                      /**< bit:      3  IO Line Index                                 */
    uint32_t P4:1;                      /**< bit:      4  IO Line Index                                 */
    uint32_t P5:1;                      /**< bit:      5  IO Line Index                                 */
    uint32_t P6:1;                      /**< bit:      6  IO Line Index                                 */
    uint32_t P7:1;                      /**< bit:      7  IO Line Index                                 */
    uint32_t P8:1;                      /**< bit:      8  IO Line Index                                 */
    uint32_t P9:1;                      /**< bit:      9  IO Line Index                                 */
    uint32_t P10:1;                     /**< bit:     10  IO Line Index                                 */
    uint32_t P11:1;                     /**< bit:     11  IO Line Index                                 */
    uint32_t P12:1;                     /**< bit:     12  IO Line Index                                 */
    uint32_t P13:1;                     /**< bit:     13  IO Line Index                                 */
    uint32_t P14:1;                     /**< bit:     14  IO Line Index                                 */
    uint32_t P15:1;                     /**< bit:     15  IO Line Index                                 */
    uint32_t P16:1;                     /**< bit:     16  IO Line Index                                 */
    uint32_t P17:1;                     /**< bit:     17  IO Line Index                                 */
    uint32_t P18:1;                     /**< bit:     18  IO Line Index                                 */
    uint32_t P19:1;                     /**< bit:     19  IO Line Index                                 */
    uint32_t P20:1;                     /**< bit:     20  IO Line Index                                 */
    uint32_t P21:1;                     /**< bit:     21  IO Line Index                                 */
    uint32_t P22:1;                     /**< bit:     22  IO Line Index                                 */
    uint32_t P23:1;                     /**< bit:     23  IO Line Index                                 */
    uint32_t P24:1;                     /**< bit:     24  IO Line Index                                 */
    uint32_t P25:1;                     /**< bit:     25  IO Line Index                                 */
    uint32_t P26:1;                     /**< bit:     26  IO Line Index                                 */
    uint32_t P27:1;                     /**< bit:     27  IO Line Index                                 */
    uint32_t P28:1;                     /**< bit:     28  IO Line Index                                 */
    uint32_t P29:1;                     /**< bit:     29  IO Line Index                                 */
    uint32_t P30:1;                     /**< bit:     30  IO Line Index                                 */
    uint32_t P31:1;                     /**< bit:     31  IO Line Index                                 */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  IO Line Index                                 */
  };
  uint32_t w;
} __PORT_AIMMR_bits_t;

#define PORT_AIMMR_P0_Pos                     (0)                                            /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P0_Msk                     (0x1U << PORT_AIMMR_P0_Pos)                    /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P1_Pos                     (1)                                            /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P1_Msk                     (0x1U << PORT_AIMMR_P1_Pos)                    /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P2_Pos                     (2)                                            /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P2_Msk                     (0x1U << PORT_AIMMR_P2_Pos)                    /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P3_Pos                     (3)                                            /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P3_Msk                     (0x1U << PORT_AIMMR_P3_Pos)                    /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P4_Pos                     (4)                                            /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P4_Msk                     (0x1U << PORT_AIMMR_P4_Pos)                    /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P5_Pos                     (5)                                            /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P5_Msk                     (0x1U << PORT_AIMMR_P5_Pos)                    /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P6_Pos                     (6)                                            /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P6_Msk                     (0x1U << PORT_AIMMR_P6_Pos)                    /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P7_Pos                     (7)                                            /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P7_Msk                     (0x1U << PORT_AIMMR_P7_Pos)                    /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P8_Pos                     (8)                                            /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P8_Msk                     (0x1U << PORT_AIMMR_P8_Pos)                    /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P9_Pos                     (9)                                            /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P9_Msk                     (0x1U << PORT_AIMMR_P9_Pos)                    /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P10_Pos                    (10)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P10_Msk                    (0x1U << PORT_AIMMR_P10_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P11_Pos                    (11)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P11_Msk                    (0x1U << PORT_AIMMR_P11_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P12_Pos                    (12)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P12_Msk                    (0x1U << PORT_AIMMR_P12_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P13_Pos                    (13)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P13_Msk                    (0x1U << PORT_AIMMR_P13_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P14_Pos                    (14)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P14_Msk                    (0x1U << PORT_AIMMR_P14_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P15_Pos                    (15)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P15_Msk                    (0x1U << PORT_AIMMR_P15_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P16_Pos                    (16)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P16_Msk                    (0x1U << PORT_AIMMR_P16_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P17_Pos                    (17)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P17_Msk                    (0x1U << PORT_AIMMR_P17_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P18_Pos                    (18)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P18_Msk                    (0x1U << PORT_AIMMR_P18_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P19_Pos                    (19)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P19_Msk                    (0x1U << PORT_AIMMR_P19_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P20_Pos                    (20)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P20_Msk                    (0x1U << PORT_AIMMR_P20_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P21_Pos                    (21)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P21_Msk                    (0x1U << PORT_AIMMR_P21_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P22_Pos                    (22)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P22_Msk                    (0x1U << PORT_AIMMR_P22_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P23_Pos                    (23)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P23_Msk                    (0x1U << PORT_AIMMR_P23_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P24_Pos                    (24)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P24_Msk                    (0x1U << PORT_AIMMR_P24_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P25_Pos                    (25)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P25_Msk                    (0x1U << PORT_AIMMR_P25_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P26_Pos                    (26)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P26_Msk                    (0x1U << PORT_AIMMR_P26_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P27_Pos                    (27)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P27_Msk                    (0x1U << PORT_AIMMR_P27_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P28_Pos                    (28)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P28_Msk                    (0x1U << PORT_AIMMR_P28_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P29_Pos                    (29)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P29_Msk                    (0x1U << PORT_AIMMR_P29_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P30_Pos                    (30)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P30_Msk                    (0x1U << PORT_AIMMR_P30_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_P31_Pos                    (31)                                           /**< (PORT_AIMMR) IO Line Index Position */
#define PORT_AIMMR_P31_Msk                    (0x1U << PORT_AIMMR_P31_Pos)                   /**< (PORT_AIMMR) IO Line Index Mask */
#define PORT_AIMMR_Msk                        (0xFFFFFFFFUL)                                 /**< (PORT_AIMMR) Register Mask  */
#define PORT_AIMMR_P_Pos                      (0)                                            /**< (PORT_AIMMR Position) IO Line Index */
#define PORT_AIMMR_P_Msk                      (0xFFFFFFFFU << PORT_AIMMR_P_Pos)              /**< (PORT_AIMMR Mask) P */
#define PORT_AIMMR_P(value)                   (PORT_AIMMR_P_Msk & ((value) << PORT_AIMMR_P_Pos))

/* -------- PORT_ESR : (PORT Offset: 0xc0) (/W 32) Edge Select Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Edge Interrupt Selection                      */
    uint32_t P1:1;                      /**< bit:      1  Edge Interrupt Selection                      */
    uint32_t P2:1;                      /**< bit:      2  Edge Interrupt Selection                      */
    uint32_t P3:1;                      /**< bit:      3  Edge Interrupt Selection                      */
    uint32_t P4:1;                      /**< bit:      4  Edge Interrupt Selection                      */
    uint32_t P5:1;                      /**< bit:      5  Edge Interrupt Selection                      */
    uint32_t P6:1;                      /**< bit:      6  Edge Interrupt Selection                      */
    uint32_t P7:1;                      /**< bit:      7  Edge Interrupt Selection                      */
    uint32_t P8:1;                      /**< bit:      8  Edge Interrupt Selection                      */
    uint32_t P9:1;                      /**< bit:      9  Edge Interrupt Selection                      */
    uint32_t P10:1;                     /**< bit:     10  Edge Interrupt Selection                      */
    uint32_t P11:1;                     /**< bit:     11  Edge Interrupt Selection                      */
    uint32_t P12:1;                     /**< bit:     12  Edge Interrupt Selection                      */
    uint32_t P13:1;                     /**< bit:     13  Edge Interrupt Selection                      */
    uint32_t P14:1;                     /**< bit:     14  Edge Interrupt Selection                      */
    uint32_t P15:1;                     /**< bit:     15  Edge Interrupt Selection                      */
    uint32_t P16:1;                     /**< bit:     16  Edge Interrupt Selection                      */
    uint32_t P17:1;                     /**< bit:     17  Edge Interrupt Selection                      */
    uint32_t P18:1;                     /**< bit:     18  Edge Interrupt Selection                      */
    uint32_t P19:1;                     /**< bit:     19  Edge Interrupt Selection                      */
    uint32_t P20:1;                     /**< bit:     20  Edge Interrupt Selection                      */
    uint32_t P21:1;                     /**< bit:     21  Edge Interrupt Selection                      */
    uint32_t P22:1;                     /**< bit:     22  Edge Interrupt Selection                      */
    uint32_t P23:1;                     /**< bit:     23  Edge Interrupt Selection                      */
    uint32_t P24:1;                     /**< bit:     24  Edge Interrupt Selection                      */
    uint32_t P25:1;                     /**< bit:     25  Edge Interrupt Selection                      */
    uint32_t P26:1;                     /**< bit:     26  Edge Interrupt Selection                      */
    uint32_t P27:1;                     /**< bit:     27  Edge Interrupt Selection                      */
    uint32_t P28:1;                     /**< bit:     28  Edge Interrupt Selection                      */
    uint32_t P29:1;                     /**< bit:     29  Edge Interrupt Selection                      */
    uint32_t P30:1;                     /**< bit:     30  Edge Interrupt Selection                      */
    uint32_t P31:1;                     /**< bit:     31  Edge Interrupt Selection                      */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Edge Interrupt Selection                      */
  };
  uint32_t w;
} __PORT_ESR_bits_t;

#define PORT_ESR_P0_Pos                       (0)                                            /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P0_Msk                       (0x1U << PORT_ESR_P0_Pos)                      /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P1_Pos                       (1)                                            /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P1_Msk                       (0x1U << PORT_ESR_P1_Pos)                      /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P2_Pos                       (2)                                            /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P2_Msk                       (0x1U << PORT_ESR_P2_Pos)                      /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P3_Pos                       (3)                                            /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P3_Msk                       (0x1U << PORT_ESR_P3_Pos)                      /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P4_Pos                       (4)                                            /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P4_Msk                       (0x1U << PORT_ESR_P4_Pos)                      /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P5_Pos                       (5)                                            /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P5_Msk                       (0x1U << PORT_ESR_P5_Pos)                      /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P6_Pos                       (6)                                            /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P6_Msk                       (0x1U << PORT_ESR_P6_Pos)                      /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P7_Pos                       (7)                                            /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P7_Msk                       (0x1U << PORT_ESR_P7_Pos)                      /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P8_Pos                       (8)                                            /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P8_Msk                       (0x1U << PORT_ESR_P8_Pos)                      /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P9_Pos                       (9)                                            /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P9_Msk                       (0x1U << PORT_ESR_P9_Pos)                      /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P10_Pos                      (10)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P10_Msk                      (0x1U << PORT_ESR_P10_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P11_Pos                      (11)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P11_Msk                      (0x1U << PORT_ESR_P11_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P12_Pos                      (12)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P12_Msk                      (0x1U << PORT_ESR_P12_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P13_Pos                      (13)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P13_Msk                      (0x1U << PORT_ESR_P13_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P14_Pos                      (14)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P14_Msk                      (0x1U << PORT_ESR_P14_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P15_Pos                      (15)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P15_Msk                      (0x1U << PORT_ESR_P15_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P16_Pos                      (16)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P16_Msk                      (0x1U << PORT_ESR_P16_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P17_Pos                      (17)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P17_Msk                      (0x1U << PORT_ESR_P17_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P18_Pos                      (18)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P18_Msk                      (0x1U << PORT_ESR_P18_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P19_Pos                      (19)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P19_Msk                      (0x1U << PORT_ESR_P19_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P20_Pos                      (20)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P20_Msk                      (0x1U << PORT_ESR_P20_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P21_Pos                      (21)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P21_Msk                      (0x1U << PORT_ESR_P21_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P22_Pos                      (22)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P22_Msk                      (0x1U << PORT_ESR_P22_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P23_Pos                      (23)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P23_Msk                      (0x1U << PORT_ESR_P23_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P24_Pos                      (24)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P24_Msk                      (0x1U << PORT_ESR_P24_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P25_Pos                      (25)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P25_Msk                      (0x1U << PORT_ESR_P25_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P26_Pos                      (26)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P26_Msk                      (0x1U << PORT_ESR_P26_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P27_Pos                      (27)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P27_Msk                      (0x1U << PORT_ESR_P27_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P28_Pos                      (28)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P28_Msk                      (0x1U << PORT_ESR_P28_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P29_Pos                      (29)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P29_Msk                      (0x1U << PORT_ESR_P29_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P30_Pos                      (30)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P30_Msk                      (0x1U << PORT_ESR_P30_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_P31_Pos                      (31)                                           /**< (PORT_ESR) Edge Interrupt Selection Position */
#define PORT_ESR_P31_Msk                      (0x1U << PORT_ESR_P31_Pos)                     /**< (PORT_ESR) Edge Interrupt Selection Mask */
#define PORT_ESR_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_ESR) Register Mask  */
#define PORT_ESR_P_Pos                        (0)                                            /**< (PORT_ESR Position) Edge Interrupt Selection */
#define PORT_ESR_P_Msk                        (0xFFFFFFFFU << PORT_ESR_P_Pos)                /**< (PORT_ESR Mask) P */
#define PORT_ESR_P(value)                     (PORT_ESR_P_Msk & ((value) << PORT_ESR_P_Pos))

/* -------- PORT_LSR : (PORT Offset: 0xc4) (/W 32) Level Select Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Level Interrupt Selection                     */
    uint32_t P1:1;                      /**< bit:      1  Level Interrupt Selection                     */
    uint32_t P2:1;                      /**< bit:      2  Level Interrupt Selection                     */
    uint32_t P3:1;                      /**< bit:      3  Level Interrupt Selection                     */
    uint32_t P4:1;                      /**< bit:      4  Level Interrupt Selection                     */
    uint32_t P5:1;                      /**< bit:      5  Level Interrupt Selection                     */
    uint32_t P6:1;                      /**< bit:      6  Level Interrupt Selection                     */
    uint32_t P7:1;                      /**< bit:      7  Level Interrupt Selection                     */
    uint32_t P8:1;                      /**< bit:      8  Level Interrupt Selection                     */
    uint32_t P9:1;                      /**< bit:      9  Level Interrupt Selection                     */
    uint32_t P10:1;                     /**< bit:     10  Level Interrupt Selection                     */
    uint32_t P11:1;                     /**< bit:     11  Level Interrupt Selection                     */
    uint32_t P12:1;                     /**< bit:     12  Level Interrupt Selection                     */
    uint32_t P13:1;                     /**< bit:     13  Level Interrupt Selection                     */
    uint32_t P14:1;                     /**< bit:     14  Level Interrupt Selection                     */
    uint32_t P15:1;                     /**< bit:     15  Level Interrupt Selection                     */
    uint32_t P16:1;                     /**< bit:     16  Level Interrupt Selection                     */
    uint32_t P17:1;                     /**< bit:     17  Level Interrupt Selection                     */
    uint32_t P18:1;                     /**< bit:     18  Level Interrupt Selection                     */
    uint32_t P19:1;                     /**< bit:     19  Level Interrupt Selection                     */
    uint32_t P20:1;                     /**< bit:     20  Level Interrupt Selection                     */
    uint32_t P21:1;                     /**< bit:     21  Level Interrupt Selection                     */
    uint32_t P22:1;                     /**< bit:     22  Level Interrupt Selection                     */
    uint32_t P23:1;                     /**< bit:     23  Level Interrupt Selection                     */
    uint32_t P24:1;                     /**< bit:     24  Level Interrupt Selection                     */
    uint32_t P25:1;                     /**< bit:     25  Level Interrupt Selection                     */
    uint32_t P26:1;                     /**< bit:     26  Level Interrupt Selection                     */
    uint32_t P27:1;                     /**< bit:     27  Level Interrupt Selection                     */
    uint32_t P28:1;                     /**< bit:     28  Level Interrupt Selection                     */
    uint32_t P29:1;                     /**< bit:     29  Level Interrupt Selection                     */
    uint32_t P30:1;                     /**< bit:     30  Level Interrupt Selection                     */
    uint32_t P31:1;                     /**< bit:     31  Level Interrupt Selection                     */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Level Interrupt Selection                     */
  };
  uint32_t w;
} __PORT_LSR_bits_t;

#define PORT_LSR_P0_Pos                       (0)                                            /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P0_Msk                       (0x1U << PORT_LSR_P0_Pos)                      /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P1_Pos                       (1)                                            /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P1_Msk                       (0x1U << PORT_LSR_P1_Pos)                      /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P2_Pos                       (2)                                            /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P2_Msk                       (0x1U << PORT_LSR_P2_Pos)                      /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P3_Pos                       (3)                                            /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P3_Msk                       (0x1U << PORT_LSR_P3_Pos)                      /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P4_Pos                       (4)                                            /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P4_Msk                       (0x1U << PORT_LSR_P4_Pos)                      /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P5_Pos                       (5)                                            /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P5_Msk                       (0x1U << PORT_LSR_P5_Pos)                      /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P6_Pos                       (6)                                            /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P6_Msk                       (0x1U << PORT_LSR_P6_Pos)                      /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P7_Pos                       (7)                                            /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P7_Msk                       (0x1U << PORT_LSR_P7_Pos)                      /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P8_Pos                       (8)                                            /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P8_Msk                       (0x1U << PORT_LSR_P8_Pos)                      /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P9_Pos                       (9)                                            /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P9_Msk                       (0x1U << PORT_LSR_P9_Pos)                      /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P10_Pos                      (10)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P10_Msk                      (0x1U << PORT_LSR_P10_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P11_Pos                      (11)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P11_Msk                      (0x1U << PORT_LSR_P11_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P12_Pos                      (12)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P12_Msk                      (0x1U << PORT_LSR_P12_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P13_Pos                      (13)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P13_Msk                      (0x1U << PORT_LSR_P13_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P14_Pos                      (14)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P14_Msk                      (0x1U << PORT_LSR_P14_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P15_Pos                      (15)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P15_Msk                      (0x1U << PORT_LSR_P15_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P16_Pos                      (16)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P16_Msk                      (0x1U << PORT_LSR_P16_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P17_Pos                      (17)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P17_Msk                      (0x1U << PORT_LSR_P17_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P18_Pos                      (18)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P18_Msk                      (0x1U << PORT_LSR_P18_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P19_Pos                      (19)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P19_Msk                      (0x1U << PORT_LSR_P19_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P20_Pos                      (20)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P20_Msk                      (0x1U << PORT_LSR_P20_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P21_Pos                      (21)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P21_Msk                      (0x1U << PORT_LSR_P21_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P22_Pos                      (22)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P22_Msk                      (0x1U << PORT_LSR_P22_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P23_Pos                      (23)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P23_Msk                      (0x1U << PORT_LSR_P23_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P24_Pos                      (24)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P24_Msk                      (0x1U << PORT_LSR_P24_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P25_Pos                      (25)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P25_Msk                      (0x1U << PORT_LSR_P25_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P26_Pos                      (26)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P26_Msk                      (0x1U << PORT_LSR_P26_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P27_Pos                      (27)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P27_Msk                      (0x1U << PORT_LSR_P27_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P28_Pos                      (28)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P28_Msk                      (0x1U << PORT_LSR_P28_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P29_Pos                      (29)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P29_Msk                      (0x1U << PORT_LSR_P29_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P30_Pos                      (30)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P30_Msk                      (0x1U << PORT_LSR_P30_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_P31_Pos                      (31)                                           /**< (PORT_LSR) Level Interrupt Selection Position */
#define PORT_LSR_P31_Msk                      (0x1U << PORT_LSR_P31_Pos)                     /**< (PORT_LSR) Level Interrupt Selection Mask */
#define PORT_LSR_Msk                          (0xFFFFFFFFUL)                                 /**< (PORT_LSR) Register Mask  */
#define PORT_LSR_P_Pos                        (0)                                            /**< (PORT_LSR Position) Level Interrupt Selection */
#define PORT_LSR_P_Msk                        (0xFFFFFFFFU << PORT_LSR_P_Pos)                /**< (PORT_LSR Mask) P */
#define PORT_LSR_P(value)                     (PORT_LSR_P_Msk & ((value) << PORT_LSR_P_Pos))

/* -------- PORT_ELSR : (PORT Offset: 0xc8) (R/ 32) Edge/Level Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Edge/Level Interrupt Source Selection         */
    uint32_t P1:1;                      /**< bit:      1  Edge/Level Interrupt Source Selection         */
    uint32_t P2:1;                      /**< bit:      2  Edge/Level Interrupt Source Selection         */
    uint32_t P3:1;                      /**< bit:      3  Edge/Level Interrupt Source Selection         */
    uint32_t P4:1;                      /**< bit:      4  Edge/Level Interrupt Source Selection         */
    uint32_t P5:1;                      /**< bit:      5  Edge/Level Interrupt Source Selection         */
    uint32_t P6:1;                      /**< bit:      6  Edge/Level Interrupt Source Selection         */
    uint32_t P7:1;                      /**< bit:      7  Edge/Level Interrupt Source Selection         */
    uint32_t P8:1;                      /**< bit:      8  Edge/Level Interrupt Source Selection         */
    uint32_t P9:1;                      /**< bit:      9  Edge/Level Interrupt Source Selection         */
    uint32_t P10:1;                     /**< bit:     10  Edge/Level Interrupt Source Selection         */
    uint32_t P11:1;                     /**< bit:     11  Edge/Level Interrupt Source Selection         */
    uint32_t P12:1;                     /**< bit:     12  Edge/Level Interrupt Source Selection         */
    uint32_t P13:1;                     /**< bit:     13  Edge/Level Interrupt Source Selection         */
    uint32_t P14:1;                     /**< bit:     14  Edge/Level Interrupt Source Selection         */
    uint32_t P15:1;                     /**< bit:     15  Edge/Level Interrupt Source Selection         */
    uint32_t P16:1;                     /**< bit:     16  Edge/Level Interrupt Source Selection         */
    uint32_t P17:1;                     /**< bit:     17  Edge/Level Interrupt Source Selection         */
    uint32_t P18:1;                     /**< bit:     18  Edge/Level Interrupt Source Selection         */
    uint32_t P19:1;                     /**< bit:     19  Edge/Level Interrupt Source Selection         */
    uint32_t P20:1;                     /**< bit:     20  Edge/Level Interrupt Source Selection         */
    uint32_t P21:1;                     /**< bit:     21  Edge/Level Interrupt Source Selection         */
    uint32_t P22:1;                     /**< bit:     22  Edge/Level Interrupt Source Selection         */
    uint32_t P23:1;                     /**< bit:     23  Edge/Level Interrupt Source Selection         */
    uint32_t P24:1;                     /**< bit:     24  Edge/Level Interrupt Source Selection         */
    uint32_t P25:1;                     /**< bit:     25  Edge/Level Interrupt Source Selection         */
    uint32_t P26:1;                     /**< bit:     26  Edge/Level Interrupt Source Selection         */
    uint32_t P27:1;                     /**< bit:     27  Edge/Level Interrupt Source Selection         */
    uint32_t P28:1;                     /**< bit:     28  Edge/Level Interrupt Source Selection         */
    uint32_t P29:1;                     /**< bit:     29  Edge/Level Interrupt Source Selection         */
    uint32_t P30:1;                     /**< bit:     30  Edge/Level Interrupt Source Selection         */
    uint32_t P31:1;                     /**< bit:     31  Edge/Level Interrupt Source Selection         */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Edge/Level Interrupt Source Selection         */
  };
  uint32_t w;
} __PORT_ELSR_bits_t;

#define PORT_ELSR_P0_Pos                      (0)                                            /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P0_Msk                      (0x1U << PORT_ELSR_P0_Pos)                     /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P1_Pos                      (1)                                            /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P1_Msk                      (0x1U << PORT_ELSR_P1_Pos)                     /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P2_Pos                      (2)                                            /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P2_Msk                      (0x1U << PORT_ELSR_P2_Pos)                     /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P3_Pos                      (3)                                            /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P3_Msk                      (0x1U << PORT_ELSR_P3_Pos)                     /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P4_Pos                      (4)                                            /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P4_Msk                      (0x1U << PORT_ELSR_P4_Pos)                     /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P5_Pos                      (5)                                            /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P5_Msk                      (0x1U << PORT_ELSR_P5_Pos)                     /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P6_Pos                      (6)                                            /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P6_Msk                      (0x1U << PORT_ELSR_P6_Pos)                     /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P7_Pos                      (7)                                            /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P7_Msk                      (0x1U << PORT_ELSR_P7_Pos)                     /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P8_Pos                      (8)                                            /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P8_Msk                      (0x1U << PORT_ELSR_P8_Pos)                     /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P9_Pos                      (9)                                            /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P9_Msk                      (0x1U << PORT_ELSR_P9_Pos)                     /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P10_Pos                     (10)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P10_Msk                     (0x1U << PORT_ELSR_P10_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P11_Pos                     (11)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P11_Msk                     (0x1U << PORT_ELSR_P11_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P12_Pos                     (12)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P12_Msk                     (0x1U << PORT_ELSR_P12_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P13_Pos                     (13)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P13_Msk                     (0x1U << PORT_ELSR_P13_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P14_Pos                     (14)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P14_Msk                     (0x1U << PORT_ELSR_P14_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P15_Pos                     (15)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P15_Msk                     (0x1U << PORT_ELSR_P15_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P16_Pos                     (16)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P16_Msk                     (0x1U << PORT_ELSR_P16_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P17_Pos                     (17)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P17_Msk                     (0x1U << PORT_ELSR_P17_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P18_Pos                     (18)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P18_Msk                     (0x1U << PORT_ELSR_P18_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P19_Pos                     (19)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P19_Msk                     (0x1U << PORT_ELSR_P19_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P20_Pos                     (20)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P20_Msk                     (0x1U << PORT_ELSR_P20_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P21_Pos                     (21)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P21_Msk                     (0x1U << PORT_ELSR_P21_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P22_Pos                     (22)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P22_Msk                     (0x1U << PORT_ELSR_P22_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P23_Pos                     (23)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P23_Msk                     (0x1U << PORT_ELSR_P23_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P24_Pos                     (24)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P24_Msk                     (0x1U << PORT_ELSR_P24_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P25_Pos                     (25)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P25_Msk                     (0x1U << PORT_ELSR_P25_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P26_Pos                     (26)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P26_Msk                     (0x1U << PORT_ELSR_P26_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P27_Pos                     (27)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P27_Msk                     (0x1U << PORT_ELSR_P27_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P28_Pos                     (28)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P28_Msk                     (0x1U << PORT_ELSR_P28_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P29_Pos                     (29)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P29_Msk                     (0x1U << PORT_ELSR_P29_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P30_Pos                     (30)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P30_Msk                     (0x1U << PORT_ELSR_P30_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_P31_Pos                     (31)                                           /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Position */
#define PORT_ELSR_P31_Msk                     (0x1U << PORT_ELSR_P31_Pos)                    /**< (PORT_ELSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_ELSR_Msk                         (0xFFFFFFFFUL)                                 /**< (PORT_ELSR) Register Mask  */
#define PORT_ELSR_P_Pos                       (0)                                            /**< (PORT_ELSR Position) Edge/Level Interrupt Source Selection */
#define PORT_ELSR_P_Msk                       (0xFFFFFFFFU << PORT_ELSR_P_Pos)               /**< (PORT_ELSR Mask) P */
#define PORT_ELSR_P(value)                    (PORT_ELSR_P_Msk & ((value) << PORT_ELSR_P_Pos))

/* -------- PORT_FELLSR : (PORT Offset: 0xd0) (/W 32) Falling Edge/Low-Level Select Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P1:1;                      /**< bit:      1  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P2:1;                      /**< bit:      2  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P3:1;                      /**< bit:      3  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P4:1;                      /**< bit:      4  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P5:1;                      /**< bit:      5  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P6:1;                      /**< bit:      6  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P7:1;                      /**< bit:      7  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P8:1;                      /**< bit:      8  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P9:1;                      /**< bit:      9  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P10:1;                     /**< bit:     10  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P11:1;                     /**< bit:     11  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P12:1;                     /**< bit:     12  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P13:1;                     /**< bit:     13  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P14:1;                     /**< bit:     14  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P15:1;                     /**< bit:     15  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P16:1;                     /**< bit:     16  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P17:1;                     /**< bit:     17  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P18:1;                     /**< bit:     18  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P19:1;                     /**< bit:     19  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P20:1;                     /**< bit:     20  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P21:1;                     /**< bit:     21  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P22:1;                     /**< bit:     22  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P23:1;                     /**< bit:     23  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P24:1;                     /**< bit:     24  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P25:1;                     /**< bit:     25  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P26:1;                     /**< bit:     26  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P27:1;                     /**< bit:     27  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P28:1;                     /**< bit:     28  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P29:1;                     /**< bit:     29  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P30:1;                     /**< bit:     30  Falling Edge/Low-Level Interrupt Selection    */
    uint32_t P31:1;                     /**< bit:     31  Falling Edge/Low-Level Interrupt Selection    */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Falling Edge/Low-Level Interrupt Selection    */
  };
  uint32_t w;
} __PORT_FELLSR_bits_t;

#define PORT_FELLSR_P0_Pos                    (0)                                            /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P0_Msk                    (0x1U << PORT_FELLSR_P0_Pos)                   /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P1_Pos                    (1)                                            /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P1_Msk                    (0x1U << PORT_FELLSR_P1_Pos)                   /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P2_Pos                    (2)                                            /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P2_Msk                    (0x1U << PORT_FELLSR_P2_Pos)                   /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P3_Pos                    (3)                                            /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P3_Msk                    (0x1U << PORT_FELLSR_P3_Pos)                   /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P4_Pos                    (4)                                            /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P4_Msk                    (0x1U << PORT_FELLSR_P4_Pos)                   /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P5_Pos                    (5)                                            /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P5_Msk                    (0x1U << PORT_FELLSR_P5_Pos)                   /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P6_Pos                    (6)                                            /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P6_Msk                    (0x1U << PORT_FELLSR_P6_Pos)                   /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P7_Pos                    (7)                                            /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P7_Msk                    (0x1U << PORT_FELLSR_P7_Pos)                   /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P8_Pos                    (8)                                            /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P8_Msk                    (0x1U << PORT_FELLSR_P8_Pos)                   /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P9_Pos                    (9)                                            /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P9_Msk                    (0x1U << PORT_FELLSR_P9_Pos)                   /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P10_Pos                   (10)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P10_Msk                   (0x1U << PORT_FELLSR_P10_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P11_Pos                   (11)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P11_Msk                   (0x1U << PORT_FELLSR_P11_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P12_Pos                   (12)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P12_Msk                   (0x1U << PORT_FELLSR_P12_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P13_Pos                   (13)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P13_Msk                   (0x1U << PORT_FELLSR_P13_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P14_Pos                   (14)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P14_Msk                   (0x1U << PORT_FELLSR_P14_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P15_Pos                   (15)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P15_Msk                   (0x1U << PORT_FELLSR_P15_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P16_Pos                   (16)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P16_Msk                   (0x1U << PORT_FELLSR_P16_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P17_Pos                   (17)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P17_Msk                   (0x1U << PORT_FELLSR_P17_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P18_Pos                   (18)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P18_Msk                   (0x1U << PORT_FELLSR_P18_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P19_Pos                   (19)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P19_Msk                   (0x1U << PORT_FELLSR_P19_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P20_Pos                   (20)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P20_Msk                   (0x1U << PORT_FELLSR_P20_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P21_Pos                   (21)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P21_Msk                   (0x1U << PORT_FELLSR_P21_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P22_Pos                   (22)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P22_Msk                   (0x1U << PORT_FELLSR_P22_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P23_Pos                   (23)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P23_Msk                   (0x1U << PORT_FELLSR_P23_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P24_Pos                   (24)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P24_Msk                   (0x1U << PORT_FELLSR_P24_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P25_Pos                   (25)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P25_Msk                   (0x1U << PORT_FELLSR_P25_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P26_Pos                   (26)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P26_Msk                   (0x1U << PORT_FELLSR_P26_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P27_Pos                   (27)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P27_Msk                   (0x1U << PORT_FELLSR_P27_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P28_Pos                   (28)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P28_Msk                   (0x1U << PORT_FELLSR_P28_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P29_Pos                   (29)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P29_Msk                   (0x1U << PORT_FELLSR_P29_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P30_Pos                   (30)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P30_Msk                   (0x1U << PORT_FELLSR_P30_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_P31_Pos                   (31)                                           /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Position */
#define PORT_FELLSR_P31_Msk                   (0x1U << PORT_FELLSR_P31_Pos)                  /**< (PORT_FELLSR) Falling Edge/Low-Level Interrupt Selection Mask */
#define PORT_FELLSR_Msk                       (0xFFFFFFFFUL)                                 /**< (PORT_FELLSR) Register Mask  */
#define PORT_FELLSR_P_Pos                     (0)                                            /**< (PORT_FELLSR Position) Falling Edge/Low-Level Interrupt Selection */
#define PORT_FELLSR_P_Msk                     (0xFFFFFFFFU << PORT_FELLSR_P_Pos)             /**< (PORT_FELLSR Mask) P */
#define PORT_FELLSR_P(value)                  (PORT_FELLSR_P_Msk & ((value) << PORT_FELLSR_P_Pos))

/* -------- PORT_REHLSR : (PORT Offset: 0xd4) (/W 32) Rising Edge/High-Level Select Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P1:1;                      /**< bit:      1  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P2:1;                      /**< bit:      2  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P3:1;                      /**< bit:      3  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P4:1;                      /**< bit:      4  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P5:1;                      /**< bit:      5  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P6:1;                      /**< bit:      6  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P7:1;                      /**< bit:      7  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P8:1;                      /**< bit:      8  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P9:1;                      /**< bit:      9  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P10:1;                     /**< bit:     10  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P11:1;                     /**< bit:     11  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P12:1;                     /**< bit:     12  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P13:1;                     /**< bit:     13  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P14:1;                     /**< bit:     14  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P15:1;                     /**< bit:     15  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P16:1;                     /**< bit:     16  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P17:1;                     /**< bit:     17  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P18:1;                     /**< bit:     18  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P19:1;                     /**< bit:     19  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P20:1;                     /**< bit:     20  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P21:1;                     /**< bit:     21  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P22:1;                     /**< bit:     22  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P23:1;                     /**< bit:     23  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P24:1;                     /**< bit:     24  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P25:1;                     /**< bit:     25  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P26:1;                     /**< bit:     26  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P27:1;                     /**< bit:     27  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P28:1;                     /**< bit:     28  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P29:1;                     /**< bit:     29  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P30:1;                     /**< bit:     30  Rising Edge/High-Level Interrupt Selection    */
    uint32_t P31:1;                     /**< bit:     31  Rising Edge/High-Level Interrupt Selection    */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Rising Edge/High-Level Interrupt Selection    */
  };
  uint32_t w;
} __PORT_REHLSR_bits_t;

#define PORT_REHLSR_P0_Pos                    (0)                                            /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P0_Msk                    (0x1U << PORT_REHLSR_P0_Pos)                   /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P1_Pos                    (1)                                            /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P1_Msk                    (0x1U << PORT_REHLSR_P1_Pos)                   /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P2_Pos                    (2)                                            /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P2_Msk                    (0x1U << PORT_REHLSR_P2_Pos)                   /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P3_Pos                    (3)                                            /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P3_Msk                    (0x1U << PORT_REHLSR_P3_Pos)                   /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P4_Pos                    (4)                                            /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P4_Msk                    (0x1U << PORT_REHLSR_P4_Pos)                   /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P5_Pos                    (5)                                            /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P5_Msk                    (0x1U << PORT_REHLSR_P5_Pos)                   /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P6_Pos                    (6)                                            /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P6_Msk                    (0x1U << PORT_REHLSR_P6_Pos)                   /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P7_Pos                    (7)                                            /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P7_Msk                    (0x1U << PORT_REHLSR_P7_Pos)                   /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P8_Pos                    (8)                                            /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P8_Msk                    (0x1U << PORT_REHLSR_P8_Pos)                   /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P9_Pos                    (9)                                            /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P9_Msk                    (0x1U << PORT_REHLSR_P9_Pos)                   /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P10_Pos                   (10)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P10_Msk                   (0x1U << PORT_REHLSR_P10_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P11_Pos                   (11)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P11_Msk                   (0x1U << PORT_REHLSR_P11_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P12_Pos                   (12)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P12_Msk                   (0x1U << PORT_REHLSR_P12_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P13_Pos                   (13)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P13_Msk                   (0x1U << PORT_REHLSR_P13_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P14_Pos                   (14)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P14_Msk                   (0x1U << PORT_REHLSR_P14_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P15_Pos                   (15)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P15_Msk                   (0x1U << PORT_REHLSR_P15_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P16_Pos                   (16)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P16_Msk                   (0x1U << PORT_REHLSR_P16_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P17_Pos                   (17)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P17_Msk                   (0x1U << PORT_REHLSR_P17_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P18_Pos                   (18)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P18_Msk                   (0x1U << PORT_REHLSR_P18_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P19_Pos                   (19)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P19_Msk                   (0x1U << PORT_REHLSR_P19_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P20_Pos                   (20)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P20_Msk                   (0x1U << PORT_REHLSR_P20_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P21_Pos                   (21)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P21_Msk                   (0x1U << PORT_REHLSR_P21_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P22_Pos                   (22)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P22_Msk                   (0x1U << PORT_REHLSR_P22_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P23_Pos                   (23)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P23_Msk                   (0x1U << PORT_REHLSR_P23_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P24_Pos                   (24)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P24_Msk                   (0x1U << PORT_REHLSR_P24_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P25_Pos                   (25)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P25_Msk                   (0x1U << PORT_REHLSR_P25_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P26_Pos                   (26)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P26_Msk                   (0x1U << PORT_REHLSR_P26_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P27_Pos                   (27)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P27_Msk                   (0x1U << PORT_REHLSR_P27_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P28_Pos                   (28)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P28_Msk                   (0x1U << PORT_REHLSR_P28_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P29_Pos                   (29)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P29_Msk                   (0x1U << PORT_REHLSR_P29_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P30_Pos                   (30)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P30_Msk                   (0x1U << PORT_REHLSR_P30_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_P31_Pos                   (31)                                           /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Position */
#define PORT_REHLSR_P31_Msk                   (0x1U << PORT_REHLSR_P31_Pos)                  /**< (PORT_REHLSR) Rising Edge/High-Level Interrupt Selection Mask */
#define PORT_REHLSR_Msk                       (0xFFFFFFFFUL)                                 /**< (PORT_REHLSR) Register Mask  */
#define PORT_REHLSR_P_Pos                     (0)                                            /**< (PORT_REHLSR Position) Rising Edge/High-Level Interrupt Selection */
#define PORT_REHLSR_P_Msk                     (0xFFFFFFFFU << PORT_REHLSR_P_Pos)             /**< (PORT_REHLSR Mask) P */
#define PORT_REHLSR_P(value)                  (PORT_REHLSR_P_Msk & ((value) << PORT_REHLSR_P_Pos))

/* -------- PORT_FRLHSR : (PORT Offset: 0xd8) (R/ 32) Fall/Rise - Low/High Status Register -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Edge/Level Interrupt Source Selection         */
    uint32_t P1:1;                      /**< bit:      1  Edge/Level Interrupt Source Selection         */
    uint32_t P2:1;                      /**< bit:      2  Edge/Level Interrupt Source Selection         */
    uint32_t P3:1;                      /**< bit:      3  Edge/Level Interrupt Source Selection         */
    uint32_t P4:1;                      /**< bit:      4  Edge/Level Interrupt Source Selection         */
    uint32_t P5:1;                      /**< bit:      5  Edge/Level Interrupt Source Selection         */
    uint32_t P6:1;                      /**< bit:      6  Edge/Level Interrupt Source Selection         */
    uint32_t P7:1;                      /**< bit:      7  Edge/Level Interrupt Source Selection         */
    uint32_t P8:1;                      /**< bit:      8  Edge/Level Interrupt Source Selection         */
    uint32_t P9:1;                      /**< bit:      9  Edge/Level Interrupt Source Selection         */
    uint32_t P10:1;                     /**< bit:     10  Edge/Level Interrupt Source Selection         */
    uint32_t P11:1;                     /**< bit:     11  Edge/Level Interrupt Source Selection         */
    uint32_t P12:1;                     /**< bit:     12  Edge/Level Interrupt Source Selection         */
    uint32_t P13:1;                     /**< bit:     13  Edge/Level Interrupt Source Selection         */
    uint32_t P14:1;                     /**< bit:     14  Edge/Level Interrupt Source Selection         */
    uint32_t P15:1;                     /**< bit:     15  Edge/Level Interrupt Source Selection         */
    uint32_t P16:1;                     /**< bit:     16  Edge/Level Interrupt Source Selection         */
    uint32_t P17:1;                     /**< bit:     17  Edge/Level Interrupt Source Selection         */
    uint32_t P18:1;                     /**< bit:     18  Edge/Level Interrupt Source Selection         */
    uint32_t P19:1;                     /**< bit:     19  Edge/Level Interrupt Source Selection         */
    uint32_t P20:1;                     /**< bit:     20  Edge/Level Interrupt Source Selection         */
    uint32_t P21:1;                     /**< bit:     21  Edge/Level Interrupt Source Selection         */
    uint32_t P22:1;                     /**< bit:     22  Edge/Level Interrupt Source Selection         */
    uint32_t P23:1;                     /**< bit:     23  Edge/Level Interrupt Source Selection         */
    uint32_t P24:1;                     /**< bit:     24  Edge/Level Interrupt Source Selection         */
    uint32_t P25:1;                     /**< bit:     25  Edge/Level Interrupt Source Selection         */
    uint32_t P26:1;                     /**< bit:     26  Edge/Level Interrupt Source Selection         */
    uint32_t P27:1;                     /**< bit:     27  Edge/Level Interrupt Source Selection         */
    uint32_t P28:1;                     /**< bit:     28  Edge/Level Interrupt Source Selection         */
    uint32_t P29:1;                     /**< bit:     29  Edge/Level Interrupt Source Selection         */
    uint32_t P30:1;                     /**< bit:     30  Edge/Level Interrupt Source Selection         */
    uint32_t P31:1;                     /**< bit:     31  Edge/Level Interrupt Source Selection         */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Edge/Level Interrupt Source Selection         */
  };
  uint32_t w;
} __PORT_FRLHSR_bits_t;

#define PORT_FRLHSR_P0_Pos                    (0)                                            /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P0_Msk                    (0x1U << PORT_FRLHSR_P0_Pos)                   /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P1_Pos                    (1)                                            /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P1_Msk                    (0x1U << PORT_FRLHSR_P1_Pos)                   /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P2_Pos                    (2)                                            /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P2_Msk                    (0x1U << PORT_FRLHSR_P2_Pos)                   /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P3_Pos                    (3)                                            /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P3_Msk                    (0x1U << PORT_FRLHSR_P3_Pos)                   /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P4_Pos                    (4)                                            /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P4_Msk                    (0x1U << PORT_FRLHSR_P4_Pos)                   /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P5_Pos                    (5)                                            /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P5_Msk                    (0x1U << PORT_FRLHSR_P5_Pos)                   /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P6_Pos                    (6)                                            /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P6_Msk                    (0x1U << PORT_FRLHSR_P6_Pos)                   /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P7_Pos                    (7)                                            /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P7_Msk                    (0x1U << PORT_FRLHSR_P7_Pos)                   /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P8_Pos                    (8)                                            /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P8_Msk                    (0x1U << PORT_FRLHSR_P8_Pos)                   /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P9_Pos                    (9)                                            /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P9_Msk                    (0x1U << PORT_FRLHSR_P9_Pos)                   /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P10_Pos                   (10)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P10_Msk                   (0x1U << PORT_FRLHSR_P10_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P11_Pos                   (11)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P11_Msk                   (0x1U << PORT_FRLHSR_P11_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P12_Pos                   (12)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P12_Msk                   (0x1U << PORT_FRLHSR_P12_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P13_Pos                   (13)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P13_Msk                   (0x1U << PORT_FRLHSR_P13_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P14_Pos                   (14)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P14_Msk                   (0x1U << PORT_FRLHSR_P14_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P15_Pos                   (15)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P15_Msk                   (0x1U << PORT_FRLHSR_P15_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P16_Pos                   (16)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P16_Msk                   (0x1U << PORT_FRLHSR_P16_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P17_Pos                   (17)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P17_Msk                   (0x1U << PORT_FRLHSR_P17_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P18_Pos                   (18)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P18_Msk                   (0x1U << PORT_FRLHSR_P18_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P19_Pos                   (19)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P19_Msk                   (0x1U << PORT_FRLHSR_P19_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P20_Pos                   (20)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P20_Msk                   (0x1U << PORT_FRLHSR_P20_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P21_Pos                   (21)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P21_Msk                   (0x1U << PORT_FRLHSR_P21_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P22_Pos                   (22)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P22_Msk                   (0x1U << PORT_FRLHSR_P22_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P23_Pos                   (23)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P23_Msk                   (0x1U << PORT_FRLHSR_P23_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P24_Pos                   (24)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P24_Msk                   (0x1U << PORT_FRLHSR_P24_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P25_Pos                   (25)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P25_Msk                   (0x1U << PORT_FRLHSR_P25_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P26_Pos                   (26)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P26_Msk                   (0x1U << PORT_FRLHSR_P26_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P27_Pos                   (27)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P27_Msk                   (0x1U << PORT_FRLHSR_P27_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P28_Pos                   (28)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P28_Msk                   (0x1U << PORT_FRLHSR_P28_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P29_Pos                   (29)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P29_Msk                   (0x1U << PORT_FRLHSR_P29_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P30_Pos                   (30)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P30_Msk                   (0x1U << PORT_FRLHSR_P30_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_P31_Pos                   (31)                                           /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Position */
#define PORT_FRLHSR_P31_Msk                   (0x1U << PORT_FRLHSR_P31_Pos)                  /**< (PORT_FRLHSR) Edge/Level Interrupt Source Selection Mask */
#define PORT_FRLHSR_Msk                       (0xFFFFFFFFUL)                                 /**< (PORT_FRLHSR) Register Mask  */
#define PORT_FRLHSR_P_Pos                     (0)                                            /**< (PORT_FRLHSR Position) Edge/Level Interrupt Source Selection */
#define PORT_FRLHSR_P_Msk                     (0xFFFFFFFFU << PORT_FRLHSR_P_Pos)             /**< (PORT_FRLHSR Mask) P */
#define PORT_FRLHSR_P(value)                  (PORT_FRLHSR_P_Msk & ((value) << PORT_FRLHSR_P_Pos))

/* -------- PORT_LOCKSR : (PORT Offset: 0xe0) (R/ 32) Lock Status -------- */

typedef union
{
  struct
  {
    uint32_t P0:1;                      /**< bit:      0  Lock Status                                   */
    uint32_t P1:1;                      /**< bit:      1  Lock Status                                   */
    uint32_t P2:1;                      /**< bit:      2  Lock Status                                   */
    uint32_t P3:1;                      /**< bit:      3  Lock Status                                   */
    uint32_t P4:1;                      /**< bit:      4  Lock Status                                   */
    uint32_t P5:1;                      /**< bit:      5  Lock Status                                   */
    uint32_t P6:1;                      /**< bit:      6  Lock Status                                   */
    uint32_t P7:1;                      /**< bit:      7  Lock Status                                   */
    uint32_t P8:1;                      /**< bit:      8  Lock Status                                   */
    uint32_t P9:1;                      /**< bit:      9  Lock Status                                   */
    uint32_t P10:1;                     /**< bit:     10  Lock Status                                   */
    uint32_t P11:1;                     /**< bit:     11  Lock Status                                   */
    uint32_t P12:1;                     /**< bit:     12  Lock Status                                   */
    uint32_t P13:1;                     /**< bit:     13  Lock Status                                   */
    uint32_t P14:1;                     /**< bit:     14  Lock Status                                   */
    uint32_t P15:1;                     /**< bit:     15  Lock Status                                   */
    uint32_t P16:1;                     /**< bit:     16  Lock Status                                   */
    uint32_t P17:1;                     /**< bit:     17  Lock Status                                   */
    uint32_t P18:1;                     /**< bit:     18  Lock Status                                   */
    uint32_t P19:1;                     /**< bit:     19  Lock Status                                   */
    uint32_t P20:1;                     /**< bit:     20  Lock Status                                   */
    uint32_t P21:1;                     /**< bit:     21  Lock Status                                   */
    uint32_t P22:1;                     /**< bit:     22  Lock Status                                   */
    uint32_t P23:1;                     /**< bit:     23  Lock Status                                   */
    uint32_t P24:1;                     /**< bit:     24  Lock Status                                   */
    uint32_t P25:1;                     /**< bit:     25  Lock Status                                   */
    uint32_t P26:1;                     /**< bit:     26  Lock Status                                   */
    uint32_t P27:1;                     /**< bit:     27  Lock Status                                   */
    uint32_t P28:1;                     /**< bit:     28  Lock Status                                   */
    uint32_t P29:1;                     /**< bit:     29  Lock Status                                   */
    uint32_t P30:1;                     /**< bit:     30  Lock Status                                   */
    uint32_t P31:1;                     /**< bit:     31  Lock Status                                   */
  };
  struct
  {
    uint32_t P:32;                      /**< bit:  0..31  Lock Status                                   */
  };
  uint32_t w;
} __PORT_LOCKSR_bits_t;

#define PORT_LOCKSR_P0_Pos                    (0)                                            /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P0_Msk                    (0x1U << PORT_LOCKSR_P0_Pos)                   /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P1_Pos                    (1)                                            /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P1_Msk                    (0x1U << PORT_LOCKSR_P1_Pos)                   /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P2_Pos                    (2)                                            /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P2_Msk                    (0x1U << PORT_LOCKSR_P2_Pos)                   /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P3_Pos                    (3)                                            /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P3_Msk                    (0x1U << PORT_LOCKSR_P3_Pos)                   /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P4_Pos                    (4)                                            /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P4_Msk                    (0x1U << PORT_LOCKSR_P4_Pos)                   /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P5_Pos                    (5)                                            /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P5_Msk                    (0x1U << PORT_LOCKSR_P5_Pos)                   /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P6_Pos                    (6)                                            /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P6_Msk                    (0x1U << PORT_LOCKSR_P6_Pos)                   /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P7_Pos                    (7)                                            /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P7_Msk                    (0x1U << PORT_LOCKSR_P7_Pos)                   /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P8_Pos                    (8)                                            /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P8_Msk                    (0x1U << PORT_LOCKSR_P8_Pos)                   /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P9_Pos                    (9)                                            /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P9_Msk                    (0x1U << PORT_LOCKSR_P9_Pos)                   /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P10_Pos                   (10)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P10_Msk                   (0x1U << PORT_LOCKSR_P10_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P11_Pos                   (11)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P11_Msk                   (0x1U << PORT_LOCKSR_P11_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P12_Pos                   (12)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P12_Msk                   (0x1U << PORT_LOCKSR_P12_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P13_Pos                   (13)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P13_Msk                   (0x1U << PORT_LOCKSR_P13_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P14_Pos                   (14)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P14_Msk                   (0x1U << PORT_LOCKSR_P14_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P15_Pos                   (15)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P15_Msk                   (0x1U << PORT_LOCKSR_P15_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P16_Pos                   (16)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P16_Msk                   (0x1U << PORT_LOCKSR_P16_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P17_Pos                   (17)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P17_Msk                   (0x1U << PORT_LOCKSR_P17_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P18_Pos                   (18)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P18_Msk                   (0x1U << PORT_LOCKSR_P18_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P19_Pos                   (19)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P19_Msk                   (0x1U << PORT_LOCKSR_P19_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P20_Pos                   (20)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P20_Msk                   (0x1U << PORT_LOCKSR_P20_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P21_Pos                   (21)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P21_Msk                   (0x1U << PORT_LOCKSR_P21_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P22_Pos                   (22)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P22_Msk                   (0x1U << PORT_LOCKSR_P22_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P23_Pos                   (23)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P23_Msk                   (0x1U << PORT_LOCKSR_P23_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P24_Pos                   (24)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P24_Msk                   (0x1U << PORT_LOCKSR_P24_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P25_Pos                   (25)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P25_Msk                   (0x1U << PORT_LOCKSR_P25_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P26_Pos                   (26)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P26_Msk                   (0x1U << PORT_LOCKSR_P26_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P27_Pos                   (27)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P27_Msk                   (0x1U << PORT_LOCKSR_P27_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P28_Pos                   (28)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P28_Msk                   (0x1U << PORT_LOCKSR_P28_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P29_Pos                   (29)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P29_Msk                   (0x1U << PORT_LOCKSR_P29_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P30_Pos                   (30)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P30_Msk                   (0x1U << PORT_LOCKSR_P30_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_P31_Pos                   (31)                                           /**< (PORT_LOCKSR) Lock Status Position */
#define PORT_LOCKSR_P31_Msk                   (0x1U << PORT_LOCKSR_P31_Pos)                  /**< (PORT_LOCKSR) Lock Status Mask */
#define PORT_LOCKSR_Msk                       (0xFFFFFFFFUL)                                 /**< (PORT_LOCKSR) Register Mask  */
#define PORT_LOCKSR_P_Pos                     (0)                                            /**< (PORT_LOCKSR Position) Lock Status */
#define PORT_LOCKSR_P_Msk                     (0xFFFFFFFFU << PORT_LOCKSR_P_Pos)             /**< (PORT_LOCKSR Mask) P */
#define PORT_LOCKSR_P(value)                  (PORT_LOCKSR_P_Msk & ((value) << PORT_LOCKSR_P_Pos))

/* -------- PORT_WPMR : (PORT Offset: 0xe4) (R/W 32) Write Protection Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t WPEN:1;                    /**< bit:      0  Write Protection Enable                       */
    uint32_t :7;                        /**< bit:   1..7  Reserved                                      */
    uint32_t WPKEY:24;                  /**< bit:  8..31  Write Protection Key                          */
  };
  uint32_t w;
} __PORT_WPMR_bits_t;

#define PORT_WPMR_WPEN_Pos                    (0)                                            /**< (PORT_WPMR) Write Protection Enable Position */
#define PORT_WPMR_WPEN_Msk                    (0x1U << PORT_WPMR_WPEN_Pos)                   /**< (PORT_WPMR) Write Protection Enable Mask */
#define PORT_WPMR_WPKEY_Pos                   (8)                                            /**< (PORT_WPMR) Write Protection Key Position */
#define PORT_WPMR_WPKEY_Msk                   (0xFFFFFFU << PORT_WPMR_WPKEY_Pos)             /**< (PORT_WPMR) Write Protection Key Mask */
#define PORT_WPMR_WPKEY(value)                (PORT_WPMR_WPKEY_Msk & ((value) << PORT_WPMR_WPKEY_Pos))
#define   PORT_WPMR_WPKEY_PASSWD_Val          (0x50494FU)                                    /**< (PORT_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0.  */
#define PORT_WPMR_WPKEY_PASSWD                (PORT_WPMR_WPKEY_PASSWD_Val << PORT_WPMR_WPKEY_Pos)  /**< (PORT_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. Position  */
#define PORT_WPMR_Msk                         (0xFFFFFF01UL)                                 /**< (PORT_WPMR) Register Mask  */

/* -------- PORT_WPSR : (PORT Offset: 0xe8) (R/ 32) Write Protection Status Register -------- */

typedef union
{
  struct
  {
    uint32_t WPVS:1;                    /**< bit:      0  Write Protection Violation Status             */
    uint32_t :7;                        /**< bit:   1..7  Reserved                                      */
    uint32_t WPVSRC:16;                 /**< bit:  8..23  Write Protection Violation Source             */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __PORT_WPSR_bits_t;

#define PORT_WPSR_WPVS_Pos                    (0)                                            /**< (PORT_WPSR) Write Protection Violation Status Position */
#define PORT_WPSR_WPVS_Msk                    (0x1U << PORT_WPSR_WPVS_Pos)                   /**< (PORT_WPSR) Write Protection Violation Status Mask */
#define PORT_WPSR_WPVSRC_Pos                  (8)                                            /**< (PORT_WPSR) Write Protection Violation Source Position */
#define PORT_WPSR_WPVSRC_Msk                  (0xFFFFU << PORT_WPSR_WPVSRC_Pos)              /**< (PORT_WPSR) Write Protection Violation Source Mask */
#define PORT_WPSR_WPVSRC(value)               (PORT_WPSR_WPVSRC_Msk & ((value) << PORT_WPSR_WPVSRC_Pos))
#define PORT_WPSR_Msk                         (0x00FFFF01UL)                                 /**< (PORT_WPSR) Register Mask  */

/* -------- PORT_SCHMITT : (PORT Offset: 0x100) (R/W 32) Schmitt Trigger Register -------- */

typedef union
{
  struct
  {
    uint32_t SCHMITT0:1;                /**< bit:      0  Schmitt Trigger Control                       */
    uint32_t SCHMITT1:1;                /**< bit:      1  Schmitt Trigger Control                       */
    uint32_t SCHMITT2:1;                /**< bit:      2  Schmitt Trigger Control                       */
    uint32_t SCHMITT3:1;                /**< bit:      3  Schmitt Trigger Control                       */
    uint32_t SCHMITT4:1;                /**< bit:      4  Schmitt Trigger Control                       */
    uint32_t SCHMITT5:1;                /**< bit:      5  Schmitt Trigger Control                       */
    uint32_t SCHMITT6:1;                /**< bit:      6  Schmitt Trigger Control                       */
    uint32_t SCHMITT7:1;                /**< bit:      7  Schmitt Trigger Control                       */
    uint32_t SCHMITT8:1;                /**< bit:      8  Schmitt Trigger Control                       */
    uint32_t SCHMITT9:1;                /**< bit:      9  Schmitt Trigger Control                       */
    uint32_t SCHMITT10:1;               /**< bit:     10  Schmitt Trigger Control                       */
    uint32_t SCHMITT11:1;               /**< bit:     11  Schmitt Trigger Control                       */
    uint32_t SCHMITT12:1;               /**< bit:     12  Schmitt Trigger Control                       */
    uint32_t SCHMITT13:1;               /**< bit:     13  Schmitt Trigger Control                       */
    uint32_t SCHMITT14:1;               /**< bit:     14  Schmitt Trigger Control                       */
    uint32_t SCHMITT15:1;               /**< bit:     15  Schmitt Trigger Control                       */
    uint32_t SCHMITT16:1;               /**< bit:     16  Schmitt Trigger Control                       */
    uint32_t SCHMITT17:1;               /**< bit:     17  Schmitt Trigger Control                       */
    uint32_t SCHMITT18:1;               /**< bit:     18  Schmitt Trigger Control                       */
    uint32_t SCHMITT19:1;               /**< bit:     19  Schmitt Trigger Control                       */
    uint32_t SCHMITT20:1;               /**< bit:     20  Schmitt Trigger Control                       */
    uint32_t SCHMITT21:1;               /**< bit:     21  Schmitt Trigger Control                       */
    uint32_t SCHMITT22:1;               /**< bit:     22  Schmitt Trigger Control                       */
    uint32_t SCHMITT23:1;               /**< bit:     23  Schmitt Trigger Control                       */
    uint32_t SCHMITT24:1;               /**< bit:     24  Schmitt Trigger Control                       */
    uint32_t SCHMITT25:1;               /**< bit:     25  Schmitt Trigger Control                       */
    uint32_t SCHMITT26:1;               /**< bit:     26  Schmitt Trigger Control                       */
    uint32_t SCHMITT27:1;               /**< bit:     27  Schmitt Trigger Control                       */
    uint32_t SCHMITT28:1;               /**< bit:     28  Schmitt Trigger Control                       */
    uint32_t SCHMITT29:1;               /**< bit:     29  Schmitt Trigger Control                       */
    uint32_t SCHMITT30:1;               /**< bit:     30  Schmitt Trigger Control                       */
    uint32_t SCHMITT31:1;               /**< bit:     31  Schmitt Trigger Control                       */
  };
  struct
  {
    uint32_t SCHMITT:32;                /**< bit:  0..31  Schmitt Trigger Control                       */
  };
  uint32_t w;
} __PORT_SCHMITT_bits_t;

#define PORT_SCHMITT_SCHMITT0_Pos             (0)                                            /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT0_Msk             (0x1U << PORT_SCHMITT_SCHMITT0_Pos)            /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT1_Pos             (1)                                            /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT1_Msk             (0x1U << PORT_SCHMITT_SCHMITT1_Pos)            /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT2_Pos             (2)                                            /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT2_Msk             (0x1U << PORT_SCHMITT_SCHMITT2_Pos)            /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT3_Pos             (3)                                            /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT3_Msk             (0x1U << PORT_SCHMITT_SCHMITT3_Pos)            /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT4_Pos             (4)                                            /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT4_Msk             (0x1U << PORT_SCHMITT_SCHMITT4_Pos)            /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT5_Pos             (5)                                            /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT5_Msk             (0x1U << PORT_SCHMITT_SCHMITT5_Pos)            /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT6_Pos             (6)                                            /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT6_Msk             (0x1U << PORT_SCHMITT_SCHMITT6_Pos)            /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT7_Pos             (7)                                            /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT7_Msk             (0x1U << PORT_SCHMITT_SCHMITT7_Pos)            /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT8_Pos             (8)                                            /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT8_Msk             (0x1U << PORT_SCHMITT_SCHMITT8_Pos)            /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT9_Pos             (9)                                            /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT9_Msk             (0x1U << PORT_SCHMITT_SCHMITT9_Pos)            /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT10_Pos            (10)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT10_Msk            (0x1U << PORT_SCHMITT_SCHMITT10_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT11_Pos            (11)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT11_Msk            (0x1U << PORT_SCHMITT_SCHMITT11_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT12_Pos            (12)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT12_Msk            (0x1U << PORT_SCHMITT_SCHMITT12_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT13_Pos            (13)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT13_Msk            (0x1U << PORT_SCHMITT_SCHMITT13_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT14_Pos            (14)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT14_Msk            (0x1U << PORT_SCHMITT_SCHMITT14_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT15_Pos            (15)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT15_Msk            (0x1U << PORT_SCHMITT_SCHMITT15_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT16_Pos            (16)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT16_Msk            (0x1U << PORT_SCHMITT_SCHMITT16_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT17_Pos            (17)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT17_Msk            (0x1U << PORT_SCHMITT_SCHMITT17_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT18_Pos            (18)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT18_Msk            (0x1U << PORT_SCHMITT_SCHMITT18_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT19_Pos            (19)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT19_Msk            (0x1U << PORT_SCHMITT_SCHMITT19_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT20_Pos            (20)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT20_Msk            (0x1U << PORT_SCHMITT_SCHMITT20_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT21_Pos            (21)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT21_Msk            (0x1U << PORT_SCHMITT_SCHMITT21_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT22_Pos            (22)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT22_Msk            (0x1U << PORT_SCHMITT_SCHMITT22_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT23_Pos            (23)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT23_Msk            (0x1U << PORT_SCHMITT_SCHMITT23_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT24_Pos            (24)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT24_Msk            (0x1U << PORT_SCHMITT_SCHMITT24_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT25_Pos            (25)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT25_Msk            (0x1U << PORT_SCHMITT_SCHMITT25_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT26_Pos            (26)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT26_Msk            (0x1U << PORT_SCHMITT_SCHMITT26_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT27_Pos            (27)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT27_Msk            (0x1U << PORT_SCHMITT_SCHMITT27_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT28_Pos            (28)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT28_Msk            (0x1U << PORT_SCHMITT_SCHMITT28_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT29_Pos            (29)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT29_Msk            (0x1U << PORT_SCHMITT_SCHMITT29_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT30_Pos            (30)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT30_Msk            (0x1U << PORT_SCHMITT_SCHMITT30_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_SCHMITT31_Pos            (31)                                           /**< (PORT_SCHMITT) Schmitt Trigger Control Position */
#define PORT_SCHMITT_SCHMITT31_Msk            (0x1U << PORT_SCHMITT_SCHMITT31_Pos)           /**< (PORT_SCHMITT) Schmitt Trigger Control Mask */
#define PORT_SCHMITT_Msk                      (0xFFFFFFFFUL)                                 /**< (PORT_SCHMITT) Register Mask  */
#define PORT_SCHMITT_SCHMITT_Pos              (0)                                            /**< (PORT_SCHMITT Position) Schmitt Trigger Control */
#define PORT_SCHMITT_SCHMITT_Msk              (0xFFFFFFFFU << PORT_SCHMITT_SCHMITT_Pos)      /**< (PORT_SCHMITT Mask) SCHMITT */
#define PORT_SCHMITT_SCHMITT(value)           (PORT_SCHMITT_SCHMITT_Msk & ((value) << PORT_SCHMITT_SCHMITT_Pos))

/* -------- PORT_DRIVER : (PORT Offset: 0x118) (R/W 32) I/O Drive Register -------- */

typedef union
{
  struct
  {
    uint32_t LINE0:1;                   /**< bit:      0  Drive of PORT Line 0                          */
    uint32_t LINE1:1;                   /**< bit:      1  Drive of PORT Line 1                          */
    uint32_t LINE2:1;                   /**< bit:      2  Drive of PORT Line 2                          */
    uint32_t LINE3:1;                   /**< bit:      3  Drive of PORT Line 3                          */
    uint32_t LINE4:1;                   /**< bit:      4  Drive of PORT Line 4                          */
    uint32_t LINE5:1;                   /**< bit:      5  Drive of PORT Line 5                          */
    uint32_t LINE6:1;                   /**< bit:      6  Drive of PORT Line 6                          */
    uint32_t LINE7:1;                   /**< bit:      7  Drive of PORT Line 7                          */
    uint32_t LINE8:1;                   /**< bit:      8  Drive of PORT Line 8                          */
    uint32_t LINE9:1;                   /**< bit:      9  Drive of PORT Line 9                          */
    uint32_t LINE10:1;                  /**< bit:     10  Drive of PORT Line 10                         */
    uint32_t LINE11:1;                  /**< bit:     11  Drive of PORT Line 11                         */
    uint32_t LINE12:1;                  /**< bit:     12  Drive of PORT Line 12                         */
    uint32_t LINE13:1;                  /**< bit:     13  Drive of PORT Line 13                         */
    uint32_t LINE14:1;                  /**< bit:     14  Drive of PORT Line 14                         */
    uint32_t LINE15:1;                  /**< bit:     15  Drive of PORT Line 15                         */
    uint32_t LINE16:1;                  /**< bit:     16  Drive of PORT Line 16                         */
    uint32_t LINE17:1;                  /**< bit:     17  Drive of PORT Line 17                         */
    uint32_t LINE18:1;                  /**< bit:     18  Drive of PORT Line 18                         */
    uint32_t LINE19:1;                  /**< bit:     19  Drive of PORT Line 19                         */
    uint32_t LINE20:1;                  /**< bit:     20  Drive of PORT Line 20                         */
    uint32_t LINE21:1;                  /**< bit:     21  Drive of PORT Line 21                         */
    uint32_t LINE22:1;                  /**< bit:     22  Drive of PORT Line 22                         */
    uint32_t LINE23:1;                  /**< bit:     23  Drive of PORT Line 23                         */
    uint32_t LINE24:1;                  /**< bit:     24  Drive of PORT Line 24                         */
    uint32_t LINE25:1;                  /**< bit:     25  Drive of PORT Line 25                         */
    uint32_t LINE26:1;                  /**< bit:     26  Drive of PORT Line 26                         */
    uint32_t LINE27:1;                  /**< bit:     27  Drive of PORT Line 27                         */
    uint32_t LINE28:1;                  /**< bit:     28  Drive of PORT Line 28                         */
    uint32_t LINE29:1;                  /**< bit:     29  Drive of PORT Line 29                         */
    uint32_t LINE30:1;                  /**< bit:     30  Drive of PORT Line 30                         */
    uint32_t LINE31:1;                  /**< bit:     31  Drive of PORT Line 31                         */
  };
  struct
  {
    uint32_t LINE:32;                   /**< bit:  0..31  Drive of PORT Line 3x                         */
  };
  uint32_t w;
} __PORT_DRIVER_bits_t;

#define PORT_DRIVER_LINE0_Pos                 (0)                                            /**< (PORT_DRIVER) Drive of PORT Line 0 Position */
#define PORT_DRIVER_LINE0_Msk                 (0x1U << PORT_DRIVER_LINE0_Pos)                /**< (PORT_DRIVER) Drive of PORT Line 0 Mask */
#define   PORT_DRIVER_LINE0_LOW_DRIVE_Val     (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE0_HIGH_DRIVE_Val    (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE0_LOW_DRIVE           (PORT_DRIVER_LINE0_LOW_DRIVE_Val << PORT_DRIVER_LINE0_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE0_HIGH_DRIVE          (PORT_DRIVER_LINE0_HIGH_DRIVE_Val << PORT_DRIVER_LINE0_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE1_Pos                 (1)                                            /**< (PORT_DRIVER) Drive of PORT Line 1 Position */
#define PORT_DRIVER_LINE1_Msk                 (0x1U << PORT_DRIVER_LINE1_Pos)                /**< (PORT_DRIVER) Drive of PORT Line 1 Mask */
#define   PORT_DRIVER_LINE1_LOW_DRIVE_Val     (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE1_HIGH_DRIVE_Val    (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE1_LOW_DRIVE           (PORT_DRIVER_LINE1_LOW_DRIVE_Val << PORT_DRIVER_LINE1_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE1_HIGH_DRIVE          (PORT_DRIVER_LINE1_HIGH_DRIVE_Val << PORT_DRIVER_LINE1_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE2_Pos                 (2)                                            /**< (PORT_DRIVER) Drive of PORT Line 2 Position */
#define PORT_DRIVER_LINE2_Msk                 (0x1U << PORT_DRIVER_LINE2_Pos)                /**< (PORT_DRIVER) Drive of PORT Line 2 Mask */
#define   PORT_DRIVER_LINE2_LOW_DRIVE_Val     (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE2_HIGH_DRIVE_Val    (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE2_LOW_DRIVE           (PORT_DRIVER_LINE2_LOW_DRIVE_Val << PORT_DRIVER_LINE2_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE2_HIGH_DRIVE          (PORT_DRIVER_LINE2_HIGH_DRIVE_Val << PORT_DRIVER_LINE2_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE3_Pos                 (3)                                            /**< (PORT_DRIVER) Drive of PORT Line 3 Position */
#define PORT_DRIVER_LINE3_Msk                 (0x1U << PORT_DRIVER_LINE3_Pos)                /**< (PORT_DRIVER) Drive of PORT Line 3 Mask */
#define   PORT_DRIVER_LINE3_LOW_DRIVE_Val     (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE3_HIGH_DRIVE_Val    (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE3_LOW_DRIVE           (PORT_DRIVER_LINE3_LOW_DRIVE_Val << PORT_DRIVER_LINE3_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE3_HIGH_DRIVE          (PORT_DRIVER_LINE3_HIGH_DRIVE_Val << PORT_DRIVER_LINE3_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE4_Pos                 (4)                                            /**< (PORT_DRIVER) Drive of PORT Line 4 Position */
#define PORT_DRIVER_LINE4_Msk                 (0x1U << PORT_DRIVER_LINE4_Pos)                /**< (PORT_DRIVER) Drive of PORT Line 4 Mask */
#define   PORT_DRIVER_LINE4_LOW_DRIVE_Val     (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE4_HIGH_DRIVE_Val    (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE4_LOW_DRIVE           (PORT_DRIVER_LINE4_LOW_DRIVE_Val << PORT_DRIVER_LINE4_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE4_HIGH_DRIVE          (PORT_DRIVER_LINE4_HIGH_DRIVE_Val << PORT_DRIVER_LINE4_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE5_Pos                 (5)                                            /**< (PORT_DRIVER) Drive of PORT Line 5 Position */
#define PORT_DRIVER_LINE5_Msk                 (0x1U << PORT_DRIVER_LINE5_Pos)                /**< (PORT_DRIVER) Drive of PORT Line 5 Mask */
#define   PORT_DRIVER_LINE5_LOW_DRIVE_Val     (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE5_HIGH_DRIVE_Val    (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE5_LOW_DRIVE           (PORT_DRIVER_LINE5_LOW_DRIVE_Val << PORT_DRIVER_LINE5_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE5_HIGH_DRIVE          (PORT_DRIVER_LINE5_HIGH_DRIVE_Val << PORT_DRIVER_LINE5_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE6_Pos                 (6)                                            /**< (PORT_DRIVER) Drive of PORT Line 6 Position */
#define PORT_DRIVER_LINE6_Msk                 (0x1U << PORT_DRIVER_LINE6_Pos)                /**< (PORT_DRIVER) Drive of PORT Line 6 Mask */
#define   PORT_DRIVER_LINE6_LOW_DRIVE_Val     (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE6_HIGH_DRIVE_Val    (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE6_LOW_DRIVE           (PORT_DRIVER_LINE6_LOW_DRIVE_Val << PORT_DRIVER_LINE6_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE6_HIGH_DRIVE          (PORT_DRIVER_LINE6_HIGH_DRIVE_Val << PORT_DRIVER_LINE6_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE7_Pos                 (7)                                            /**< (PORT_DRIVER) Drive of PORT Line 7 Position */
#define PORT_DRIVER_LINE7_Msk                 (0x1U << PORT_DRIVER_LINE7_Pos)                /**< (PORT_DRIVER) Drive of PORT Line 7 Mask */
#define   PORT_DRIVER_LINE7_LOW_DRIVE_Val     (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE7_HIGH_DRIVE_Val    (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE7_LOW_DRIVE           (PORT_DRIVER_LINE7_LOW_DRIVE_Val << PORT_DRIVER_LINE7_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE7_HIGH_DRIVE          (PORT_DRIVER_LINE7_HIGH_DRIVE_Val << PORT_DRIVER_LINE7_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE8_Pos                 (8)                                            /**< (PORT_DRIVER) Drive of PORT Line 8 Position */
#define PORT_DRIVER_LINE8_Msk                 (0x1U << PORT_DRIVER_LINE8_Pos)                /**< (PORT_DRIVER) Drive of PORT Line 8 Mask */
#define   PORT_DRIVER_LINE8_LOW_DRIVE_Val     (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE8_HIGH_DRIVE_Val    (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE8_LOW_DRIVE           (PORT_DRIVER_LINE8_LOW_DRIVE_Val << PORT_DRIVER_LINE8_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE8_HIGH_DRIVE          (PORT_DRIVER_LINE8_HIGH_DRIVE_Val << PORT_DRIVER_LINE8_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE9_Pos                 (9)                                            /**< (PORT_DRIVER) Drive of PORT Line 9 Position */
#define PORT_DRIVER_LINE9_Msk                 (0x1U << PORT_DRIVER_LINE9_Pos)                /**< (PORT_DRIVER) Drive of PORT Line 9 Mask */
#define   PORT_DRIVER_LINE9_LOW_DRIVE_Val     (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE9_HIGH_DRIVE_Val    (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE9_LOW_DRIVE           (PORT_DRIVER_LINE9_LOW_DRIVE_Val << PORT_DRIVER_LINE9_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE9_HIGH_DRIVE          (PORT_DRIVER_LINE9_HIGH_DRIVE_Val << PORT_DRIVER_LINE9_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE10_Pos                (10)                                           /**< (PORT_DRIVER) Drive of PORT Line 10 Position */
#define PORT_DRIVER_LINE10_Msk                (0x1U << PORT_DRIVER_LINE10_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 10 Mask */
#define   PORT_DRIVER_LINE10_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE10_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE10_LOW_DRIVE          (PORT_DRIVER_LINE10_LOW_DRIVE_Val << PORT_DRIVER_LINE10_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE10_HIGH_DRIVE         (PORT_DRIVER_LINE10_HIGH_DRIVE_Val << PORT_DRIVER_LINE10_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE11_Pos                (11)                                           /**< (PORT_DRIVER) Drive of PORT Line 11 Position */
#define PORT_DRIVER_LINE11_Msk                (0x1U << PORT_DRIVER_LINE11_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 11 Mask */
#define   PORT_DRIVER_LINE11_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE11_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE11_LOW_DRIVE          (PORT_DRIVER_LINE11_LOW_DRIVE_Val << PORT_DRIVER_LINE11_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE11_HIGH_DRIVE         (PORT_DRIVER_LINE11_HIGH_DRIVE_Val << PORT_DRIVER_LINE11_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE12_Pos                (12)                                           /**< (PORT_DRIVER) Drive of PORT Line 12 Position */
#define PORT_DRIVER_LINE12_Msk                (0x1U << PORT_DRIVER_LINE12_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 12 Mask */
#define   PORT_DRIVER_LINE12_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE12_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE12_LOW_DRIVE          (PORT_DRIVER_LINE12_LOW_DRIVE_Val << PORT_DRIVER_LINE12_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE12_HIGH_DRIVE         (PORT_DRIVER_LINE12_HIGH_DRIVE_Val << PORT_DRIVER_LINE12_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE13_Pos                (13)                                           /**< (PORT_DRIVER) Drive of PORT Line 13 Position */
#define PORT_DRIVER_LINE13_Msk                (0x1U << PORT_DRIVER_LINE13_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 13 Mask */
#define   PORT_DRIVER_LINE13_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE13_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE13_LOW_DRIVE          (PORT_DRIVER_LINE13_LOW_DRIVE_Val << PORT_DRIVER_LINE13_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE13_HIGH_DRIVE         (PORT_DRIVER_LINE13_HIGH_DRIVE_Val << PORT_DRIVER_LINE13_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE14_Pos                (14)                                           /**< (PORT_DRIVER) Drive of PORT Line 14 Position */
#define PORT_DRIVER_LINE14_Msk                (0x1U << PORT_DRIVER_LINE14_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 14 Mask */
#define   PORT_DRIVER_LINE14_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE14_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE14_LOW_DRIVE          (PORT_DRIVER_LINE14_LOW_DRIVE_Val << PORT_DRIVER_LINE14_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE14_HIGH_DRIVE         (PORT_DRIVER_LINE14_HIGH_DRIVE_Val << PORT_DRIVER_LINE14_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE15_Pos                (15)                                           /**< (PORT_DRIVER) Drive of PORT Line 15 Position */
#define PORT_DRIVER_LINE15_Msk                (0x1U << PORT_DRIVER_LINE15_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 15 Mask */
#define   PORT_DRIVER_LINE15_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE15_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE15_LOW_DRIVE          (PORT_DRIVER_LINE15_LOW_DRIVE_Val << PORT_DRIVER_LINE15_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE15_HIGH_DRIVE         (PORT_DRIVER_LINE15_HIGH_DRIVE_Val << PORT_DRIVER_LINE15_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE16_Pos                (16)                                           /**< (PORT_DRIVER) Drive of PORT Line 16 Position */
#define PORT_DRIVER_LINE16_Msk                (0x1U << PORT_DRIVER_LINE16_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 16 Mask */
#define   PORT_DRIVER_LINE16_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE16_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE16_LOW_DRIVE          (PORT_DRIVER_LINE16_LOW_DRIVE_Val << PORT_DRIVER_LINE16_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE16_HIGH_DRIVE         (PORT_DRIVER_LINE16_HIGH_DRIVE_Val << PORT_DRIVER_LINE16_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE17_Pos                (17)                                           /**< (PORT_DRIVER) Drive of PORT Line 17 Position */
#define PORT_DRIVER_LINE17_Msk                (0x1U << PORT_DRIVER_LINE17_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 17 Mask */
#define   PORT_DRIVER_LINE17_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE17_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE17_LOW_DRIVE          (PORT_DRIVER_LINE17_LOW_DRIVE_Val << PORT_DRIVER_LINE17_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE17_HIGH_DRIVE         (PORT_DRIVER_LINE17_HIGH_DRIVE_Val << PORT_DRIVER_LINE17_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE18_Pos                (18)                                           /**< (PORT_DRIVER) Drive of PORT Line 18 Position */
#define PORT_DRIVER_LINE18_Msk                (0x1U << PORT_DRIVER_LINE18_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 18 Mask */
#define   PORT_DRIVER_LINE18_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE18_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE18_LOW_DRIVE          (PORT_DRIVER_LINE18_LOW_DRIVE_Val << PORT_DRIVER_LINE18_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE18_HIGH_DRIVE         (PORT_DRIVER_LINE18_HIGH_DRIVE_Val << PORT_DRIVER_LINE18_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE19_Pos                (19)                                           /**< (PORT_DRIVER) Drive of PORT Line 19 Position */
#define PORT_DRIVER_LINE19_Msk                (0x1U << PORT_DRIVER_LINE19_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 19 Mask */
#define   PORT_DRIVER_LINE19_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE19_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE19_LOW_DRIVE          (PORT_DRIVER_LINE19_LOW_DRIVE_Val << PORT_DRIVER_LINE19_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE19_HIGH_DRIVE         (PORT_DRIVER_LINE19_HIGH_DRIVE_Val << PORT_DRIVER_LINE19_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE20_Pos                (20)                                           /**< (PORT_DRIVER) Drive of PORT Line 20 Position */
#define PORT_DRIVER_LINE20_Msk                (0x1U << PORT_DRIVER_LINE20_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 20 Mask */
#define   PORT_DRIVER_LINE20_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE20_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE20_LOW_DRIVE          (PORT_DRIVER_LINE20_LOW_DRIVE_Val << PORT_DRIVER_LINE20_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE20_HIGH_DRIVE         (PORT_DRIVER_LINE20_HIGH_DRIVE_Val << PORT_DRIVER_LINE20_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE21_Pos                (21)                                           /**< (PORT_DRIVER) Drive of PORT Line 21 Position */
#define PORT_DRIVER_LINE21_Msk                (0x1U << PORT_DRIVER_LINE21_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 21 Mask */
#define   PORT_DRIVER_LINE21_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE21_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE21_LOW_DRIVE          (PORT_DRIVER_LINE21_LOW_DRIVE_Val << PORT_DRIVER_LINE21_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE21_HIGH_DRIVE         (PORT_DRIVER_LINE21_HIGH_DRIVE_Val << PORT_DRIVER_LINE21_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE22_Pos                (22)                                           /**< (PORT_DRIVER) Drive of PORT Line 22 Position */
#define PORT_DRIVER_LINE22_Msk                (0x1U << PORT_DRIVER_LINE22_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 22 Mask */
#define   PORT_DRIVER_LINE22_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE22_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE22_LOW_DRIVE          (PORT_DRIVER_LINE22_LOW_DRIVE_Val << PORT_DRIVER_LINE22_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE22_HIGH_DRIVE         (PORT_DRIVER_LINE22_HIGH_DRIVE_Val << PORT_DRIVER_LINE22_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE23_Pos                (23)                                           /**< (PORT_DRIVER) Drive of PORT Line 23 Position */
#define PORT_DRIVER_LINE23_Msk                (0x1U << PORT_DRIVER_LINE23_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 23 Mask */
#define   PORT_DRIVER_LINE23_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE23_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE23_LOW_DRIVE          (PORT_DRIVER_LINE23_LOW_DRIVE_Val << PORT_DRIVER_LINE23_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE23_HIGH_DRIVE         (PORT_DRIVER_LINE23_HIGH_DRIVE_Val << PORT_DRIVER_LINE23_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE24_Pos                (24)                                           /**< (PORT_DRIVER) Drive of PORT Line 24 Position */
#define PORT_DRIVER_LINE24_Msk                (0x1U << PORT_DRIVER_LINE24_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 24 Mask */
#define   PORT_DRIVER_LINE24_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE24_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE24_LOW_DRIVE          (PORT_DRIVER_LINE24_LOW_DRIVE_Val << PORT_DRIVER_LINE24_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE24_HIGH_DRIVE         (PORT_DRIVER_LINE24_HIGH_DRIVE_Val << PORT_DRIVER_LINE24_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE25_Pos                (25)                                           /**< (PORT_DRIVER) Drive of PORT Line 25 Position */
#define PORT_DRIVER_LINE25_Msk                (0x1U << PORT_DRIVER_LINE25_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 25 Mask */
#define   PORT_DRIVER_LINE25_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE25_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE25_LOW_DRIVE          (PORT_DRIVER_LINE25_LOW_DRIVE_Val << PORT_DRIVER_LINE25_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE25_HIGH_DRIVE         (PORT_DRIVER_LINE25_HIGH_DRIVE_Val << PORT_DRIVER_LINE25_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE26_Pos                (26)                                           /**< (PORT_DRIVER) Drive of PORT Line 26 Position */
#define PORT_DRIVER_LINE26_Msk                (0x1U << PORT_DRIVER_LINE26_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 26 Mask */
#define   PORT_DRIVER_LINE26_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE26_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE26_LOW_DRIVE          (PORT_DRIVER_LINE26_LOW_DRIVE_Val << PORT_DRIVER_LINE26_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE26_HIGH_DRIVE         (PORT_DRIVER_LINE26_HIGH_DRIVE_Val << PORT_DRIVER_LINE26_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE27_Pos                (27)                                           /**< (PORT_DRIVER) Drive of PORT Line 27 Position */
#define PORT_DRIVER_LINE27_Msk                (0x1U << PORT_DRIVER_LINE27_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 27 Mask */
#define   PORT_DRIVER_LINE27_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE27_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE27_LOW_DRIVE          (PORT_DRIVER_LINE27_LOW_DRIVE_Val << PORT_DRIVER_LINE27_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE27_HIGH_DRIVE         (PORT_DRIVER_LINE27_HIGH_DRIVE_Val << PORT_DRIVER_LINE27_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE28_Pos                (28)                                           /**< (PORT_DRIVER) Drive of PORT Line 28 Position */
#define PORT_DRIVER_LINE28_Msk                (0x1U << PORT_DRIVER_LINE28_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 28 Mask */
#define   PORT_DRIVER_LINE28_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE28_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE28_LOW_DRIVE          (PORT_DRIVER_LINE28_LOW_DRIVE_Val << PORT_DRIVER_LINE28_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE28_HIGH_DRIVE         (PORT_DRIVER_LINE28_HIGH_DRIVE_Val << PORT_DRIVER_LINE28_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE29_Pos                (29)                                           /**< (PORT_DRIVER) Drive of PORT Line 29 Position */
#define PORT_DRIVER_LINE29_Msk                (0x1U << PORT_DRIVER_LINE29_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 29 Mask */
#define   PORT_DRIVER_LINE29_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE29_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE29_LOW_DRIVE          (PORT_DRIVER_LINE29_LOW_DRIVE_Val << PORT_DRIVER_LINE29_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE29_HIGH_DRIVE         (PORT_DRIVER_LINE29_HIGH_DRIVE_Val << PORT_DRIVER_LINE29_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE30_Pos                (30)                                           /**< (PORT_DRIVER) Drive of PORT Line 30 Position */
#define PORT_DRIVER_LINE30_Msk                (0x1U << PORT_DRIVER_LINE30_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 30 Mask */
#define   PORT_DRIVER_LINE30_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE30_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE30_LOW_DRIVE          (PORT_DRIVER_LINE30_LOW_DRIVE_Val << PORT_DRIVER_LINE30_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE30_HIGH_DRIVE         (PORT_DRIVER_LINE30_HIGH_DRIVE_Val << PORT_DRIVER_LINE30_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_LINE31_Pos                (31)                                           /**< (PORT_DRIVER) Drive of PORT Line 31 Position */
#define PORT_DRIVER_LINE31_Msk                (0x1U << PORT_DRIVER_LINE31_Pos)               /**< (PORT_DRIVER) Drive of PORT Line 31 Mask */
#define   PORT_DRIVER_LINE31_LOW_DRIVE_Val    (0x0U)                                         /**< (PORT_DRIVER) Lowest drive  */
#define   PORT_DRIVER_LINE31_HIGH_DRIVE_Val   (0x1U)                                         /**< (PORT_DRIVER) Highest drive  */
#define PORT_DRIVER_LINE31_LOW_DRIVE          (PORT_DRIVER_LINE31_LOW_DRIVE_Val << PORT_DRIVER_LINE31_Pos)  /**< (PORT_DRIVER) Lowest drive Position  */
#define PORT_DRIVER_LINE31_HIGH_DRIVE         (PORT_DRIVER_LINE31_HIGH_DRIVE_Val << PORT_DRIVER_LINE31_Pos)  /**< (PORT_DRIVER) Highest drive Position  */
#define PORT_DRIVER_Msk                       (0xFFFFFFFFUL)                                 /**< (PORT_DRIVER) Register Mask  */
#define PORT_DRIVER_LINE_Pos                  (0)                                            /**< (PORT_DRIVER Position) Drive of PORT Line 3x */
#define PORT_DRIVER_LINE_Msk                  (0xFFFFFFFFU << PORT_DRIVER_LINE_Pos)          /**< (PORT_DRIVER Mask) LINE */
#define PORT_DRIVER_LINE(value)               (PORT_DRIVER_LINE_Msk & ((value) << PORT_DRIVER_LINE_Pos))

/* -------- PORT_PCMR : (PORT Offset: 0x150) (R/W 32) Parallel Capture Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t PCEN:1;                    /**< bit:      0  Parallel Capture Mode Enable                  */
    uint32_t :3;                        /**< bit:   1..3  Reserved                                      */
    uint32_t DSIZE:2;                   /**< bit:   4..5  Parallel Capture Mode Data Size               */
    uint32_t :3;                        /**< bit:   6..8  Reserved                                      */
    uint32_t ALWYS:1;                   /**< bit:      9  Parallel Capture Mode Always Sampling         */
    uint32_t HALFS:1;                   /**< bit:     10  Parallel Capture Mode Half Sampling           */
    uint32_t FRSTS:1;                   /**< bit:     11  Parallel Capture Mode First Sample            */
    uint32_t :20;                       /**< bit: 12..31  Reserved                                      */
  };
  uint32_t w;
} __PORT_PCMR_bits_t;

#define PORT_PCMR_PCEN_Pos                    (0)                                            /**< (PORT_PCMR) Parallel Capture Mode Enable Position */
#define PORT_PCMR_PCEN_Msk                    (0x1U << PORT_PCMR_PCEN_Pos)                   /**< (PORT_PCMR) Parallel Capture Mode Enable Mask */
#define PORT_PCMR_DSIZE_Pos                   (4)                                            /**< (PORT_PCMR) Parallel Capture Mode Data Size Position */
#define PORT_PCMR_DSIZE_Msk                   (0x3U << PORT_PCMR_DSIZE_Pos)                  /**< (PORT_PCMR) Parallel Capture Mode Data Size Mask */
#define PORT_PCMR_DSIZE(value)                (PORT_PCMR_DSIZE_Msk & ((value) << PORT_PCMR_DSIZE_Pos))
#define   PORT_PCMR_DSIZE_BYTE_Val            (0x0U)                                         /**< (PORT_PCMR) The reception data in the PORT_PCRHR is a byte (8-bit)  */
#define   PORT_PCMR_DSIZE_HALFWORD_Val        (0x1U)                                         /**< (PORT_PCMR) The reception data in the PORT_PCRHR is a half-word (16-bit)  */
#define   PORT_PCMR_DSIZE_WORD_Val            (0x2U)                                         /**< (PORT_PCMR) The reception data in the PORT_PCRHR is a word (32-bit)  */
#define PORT_PCMR_DSIZE_BYTE                  (PORT_PCMR_DSIZE_BYTE_Val << PORT_PCMR_DSIZE_Pos)  /**< (PORT_PCMR) The reception data in the PORT_PCRHR is a byte (8-bit) Position  */
#define PORT_PCMR_DSIZE_HALFWORD              (PORT_PCMR_DSIZE_HALFWORD_Val << PORT_PCMR_DSIZE_Pos)  /**< (PORT_PCMR) The reception data in the PORT_PCRHR is a half-word (16-bit) Position  */
#define PORT_PCMR_DSIZE_WORD                  (PORT_PCMR_DSIZE_WORD_Val << PORT_PCMR_DSIZE_Pos)  /**< (PORT_PCMR) The reception data in the PORT_PCRHR is a word (32-bit) Position  */
#define PORT_PCMR_ALWYS_Pos                   (9)                                            /**< (PORT_PCMR) Parallel Capture Mode Always Sampling Position */
#define PORT_PCMR_ALWYS_Msk                   (0x1U << PORT_PCMR_ALWYS_Pos)                  /**< (PORT_PCMR) Parallel Capture Mode Always Sampling Mask */
#define PORT_PCMR_HALFS_Pos                   (10)                                           /**< (PORT_PCMR) Parallel Capture Mode Half Sampling Position */
#define PORT_PCMR_HALFS_Msk                   (0x1U << PORT_PCMR_HALFS_Pos)                  /**< (PORT_PCMR) Parallel Capture Mode Half Sampling Mask */
#define PORT_PCMR_FRSTS_Pos                   (11)                                           /**< (PORT_PCMR) Parallel Capture Mode First Sample Position */
#define PORT_PCMR_FRSTS_Msk                   (0x1U << PORT_PCMR_FRSTS_Pos)                  /**< (PORT_PCMR) Parallel Capture Mode First Sample Mask */
#define PORT_PCMR_Msk                         (0x00000E31UL)                                 /**< (PORT_PCMR) Register Mask  */

/* -------- PORT_PCIER : (PORT Offset: 0x154) (/W 32) Parallel Capture Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t DRDY:1;                    /**< bit:      0  Parallel Capture Mode Data Ready Interrupt Enable */
    uint32_t OVRE:1;                    /**< bit:      1  Parallel Capture Mode Overrun Error Interrupt Enable */
    uint32_t ENDRX:1;                   /**< bit:      2  End of Reception Transfer Interrupt Enable    */
    uint32_t RXBUFF:1;                  /**< bit:      3  Reception Buffer Full Interrupt Enable        */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  uint32_t w;
} __PORT_PCIER_bits_t;

#define PORT_PCIER_DRDY_Pos                   (0)                                            /**< (PORT_PCIER) Parallel Capture Mode Data Ready Interrupt Enable Position */
#define PORT_PCIER_DRDY_Msk                   (0x1U << PORT_PCIER_DRDY_Pos)                  /**< (PORT_PCIER) Parallel Capture Mode Data Ready Interrupt Enable Mask */
#define PORT_PCIER_OVRE_Pos                   (1)                                            /**< (PORT_PCIER) Parallel Capture Mode Overrun Error Interrupt Enable Position */
#define PORT_PCIER_OVRE_Msk                   (0x1U << PORT_PCIER_OVRE_Pos)                  /**< (PORT_PCIER) Parallel Capture Mode Overrun Error Interrupt Enable Mask */
#define PORT_PCIER_ENDRX_Pos                  (2)                                            /**< (PORT_PCIER) End of Reception Transfer Interrupt Enable Position */
#define PORT_PCIER_ENDRX_Msk                  (0x1U << PORT_PCIER_ENDRX_Pos)                 /**< (PORT_PCIER) End of Reception Transfer Interrupt Enable Mask */
#define PORT_PCIER_RXBUFF_Pos                 (3)                                            /**< (PORT_PCIER) Reception Buffer Full Interrupt Enable Position */
#define PORT_PCIER_RXBUFF_Msk                 (0x1U << PORT_PCIER_RXBUFF_Pos)                /**< (PORT_PCIER) Reception Buffer Full Interrupt Enable Mask */
#define PORT_PCIER_Msk                        (0x0000000FUL)                                 /**< (PORT_PCIER) Register Mask  */

/* -------- PORT_PCIDR : (PORT Offset: 0x158) (/W 32) Parallel Capture Interrupt Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t DRDY:1;                    /**< bit:      0  Parallel Capture Mode Data Ready Interrupt Disable */
    uint32_t OVRE:1;                    /**< bit:      1  Parallel Capture Mode Overrun Error Interrupt Disable */
    uint32_t ENDRX:1;                   /**< bit:      2  End of Reception Transfer Interrupt Disable   */
    uint32_t RXBUFF:1;                  /**< bit:      3  Reception Buffer Full Interrupt Disable       */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  uint32_t w;
} __PORT_PCIDR_bits_t;

#define PORT_PCIDR_DRDY_Pos                   (0)                                            /**< (PORT_PCIDR) Parallel Capture Mode Data Ready Interrupt Disable Position */
#define PORT_PCIDR_DRDY_Msk                   (0x1U << PORT_PCIDR_DRDY_Pos)                  /**< (PORT_PCIDR) Parallel Capture Mode Data Ready Interrupt Disable Mask */
#define PORT_PCIDR_OVRE_Pos                   (1)                                            /**< (PORT_PCIDR) Parallel Capture Mode Overrun Error Interrupt Disable Position */
#define PORT_PCIDR_OVRE_Msk                   (0x1U << PORT_PCIDR_OVRE_Pos)                  /**< (PORT_PCIDR) Parallel Capture Mode Overrun Error Interrupt Disable Mask */
#define PORT_PCIDR_ENDRX_Pos                  (2)                                            /**< (PORT_PCIDR) End of Reception Transfer Interrupt Disable Position */
#define PORT_PCIDR_ENDRX_Msk                  (0x1U << PORT_PCIDR_ENDRX_Pos)                 /**< (PORT_PCIDR) End of Reception Transfer Interrupt Disable Mask */
#define PORT_PCIDR_RXBUFF_Pos                 (3)                                            /**< (PORT_PCIDR) Reception Buffer Full Interrupt Disable Position */
#define PORT_PCIDR_RXBUFF_Msk                 (0x1U << PORT_PCIDR_RXBUFF_Pos)                /**< (PORT_PCIDR) Reception Buffer Full Interrupt Disable Mask */
#define PORT_PCIDR_Msk                        (0x0000000FUL)                                 /**< (PORT_PCIDR) Register Mask  */

/* -------- PORT_PCIMR : (PORT Offset: 0x15c) (R/ 32) Parallel Capture Interrupt Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t DRDY:1;                    /**< bit:      0  Parallel Capture Mode Data Ready Interrupt Mask */
    uint32_t OVRE:1;                    /**< bit:      1  Parallel Capture Mode Overrun Error Interrupt Mask */
    uint32_t ENDRX:1;                   /**< bit:      2  End of Reception Transfer Interrupt Mask      */
    uint32_t RXBUFF:1;                  /**< bit:      3  Reception Buffer Full Interrupt Mask          */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  uint32_t w;
} __PORT_PCIMR_bits_t;

#define PORT_PCIMR_DRDY_Pos                   (0)                                            /**< (PORT_PCIMR) Parallel Capture Mode Data Ready Interrupt Mask Position */
#define PORT_PCIMR_DRDY_Msk                   (0x1U << PORT_PCIMR_DRDY_Pos)                  /**< (PORT_PCIMR) Parallel Capture Mode Data Ready Interrupt Mask Mask */
#define PORT_PCIMR_OVRE_Pos                   (1)                                            /**< (PORT_PCIMR) Parallel Capture Mode Overrun Error Interrupt Mask Position */
#define PORT_PCIMR_OVRE_Msk                   (0x1U << PORT_PCIMR_OVRE_Pos)                  /**< (PORT_PCIMR) Parallel Capture Mode Overrun Error Interrupt Mask Mask */
#define PORT_PCIMR_ENDRX_Pos                  (2)                                            /**< (PORT_PCIMR) End of Reception Transfer Interrupt Mask Position */
#define PORT_PCIMR_ENDRX_Msk                  (0x1U << PORT_PCIMR_ENDRX_Pos)                 /**< (PORT_PCIMR) End of Reception Transfer Interrupt Mask Mask */
#define PORT_PCIMR_RXBUFF_Pos                 (3)                                            /**< (PORT_PCIMR) Reception Buffer Full Interrupt Mask Position */
#define PORT_PCIMR_RXBUFF_Msk                 (0x1U << PORT_PCIMR_RXBUFF_Pos)                /**< (PORT_PCIMR) Reception Buffer Full Interrupt Mask Mask */
#define PORT_PCIMR_Msk                        (0x0000000FUL)                                 /**< (PORT_PCIMR) Register Mask  */

/* -------- PORT_PCISR : (PORT Offset: 0x160) (R/ 32) Parallel Capture Interrupt Status Register -------- */

typedef union
{
  struct
  {
    uint32_t DRDY:1;                    /**< bit:      0  Parallel Capture Mode Data Ready              */
    uint32_t OVRE:1;                    /**< bit:      1  Parallel Capture Mode Overrun Error           */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  uint32_t w;
} __PORT_PCISR_bits_t;

#define PORT_PCISR_DRDY_Pos                   (0)                                            /**< (PORT_PCISR) Parallel Capture Mode Data Ready Position */
#define PORT_PCISR_DRDY_Msk                   (0x1U << PORT_PCISR_DRDY_Pos)                  /**< (PORT_PCISR) Parallel Capture Mode Data Ready Mask */
#define PORT_PCISR_OVRE_Pos                   (1)                                            /**< (PORT_PCISR) Parallel Capture Mode Overrun Error Position */
#define PORT_PCISR_OVRE_Msk                   (0x1U << PORT_PCISR_OVRE_Pos)                  /**< (PORT_PCISR) Parallel Capture Mode Overrun Error Mask */
#define PORT_PCISR_Msk                        (0x00000003UL)                                 /**< (PORT_PCISR) Register Mask  */

/* -------- PORT_PCRHR : (PORT Offset: 0x164) (R/ 32) Parallel Capture Reception Holding Register -------- */

typedef union
{
  struct
  {
    uint32_t RDATA:32;                  /**< bit:  0..31  Parallel Capture Mode Reception Data          */
  };
  uint32_t w;
} __PORT_PCRHR_bits_t;

#define PORT_PCRHR_RDATA_Pos                  (0)                                            /**< (PORT_PCRHR) Parallel Capture Mode Reception Data Position */
#define PORT_PCRHR_RDATA_Msk                  (0xFFFFFFFFU << PORT_PCRHR_RDATA_Pos)          /**< (PORT_PCRHR) Parallel Capture Mode Reception Data Mask */
#define PORT_PCRHR_RDATA(value)               (PORT_PCRHR_RDATA_Msk & ((value) << PORT_PCRHR_RDATA_Pos))
#define PORT_PCRHR_Msk                        (0xFFFFFFFFUL)                                 /**< (PORT_PCRHR) Register Mask  */

/** \brief PORT register offsets definitions */
#define PORT_PER_OFFSET              (0x00)         /**< (PORT_PER) PORT Enable Register Offset */
#define PORT_PDR_OFFSET              (0x04)         /**< (PORT_PDR) PORT Disable Register Offset */
#define PORT_PSR_OFFSET              (0x08)         /**< (PORT_PSR) PORT Status Register Offset */
#define PORT_OER_OFFSET              (0x10)         /**< (PORT_OER) Output Enable Register Offset */
#define PORT_ODR_OFFSET              (0x14)         /**< (PORT_ODR) Output Disable Register Offset */
#define PORT_OSR_OFFSET              (0x18)         /**< (PORT_OSR) Output Status Register Offset */
#define PORT_IFER_OFFSET             (0x20)         /**< (PORT_IFER) Glitch Input Filter Enable Register Offset */
#define PORT_IFDR_OFFSET             (0x24)         /**< (PORT_IFDR) Glitch Input Filter Disable Register Offset */
#define PORT_IFSR_OFFSET             (0x28)         /**< (PORT_IFSR) Glitch Input Filter Status Register Offset */
#define PORT_SODR_OFFSET             (0x30)         /**< (PORT_SODR) Set Output Data Register Offset */
#define PORT_CODR_OFFSET             (0x34)         /**< (PORT_CODR) Clear Output Data Register Offset */
#define PORT_ODSR_OFFSET             (0x38)         /**< (PORT_ODSR) Output Data Status Register Offset */
#define PORT_PDSR_OFFSET             (0x3C)         /**< (PORT_PDSR) Pin Data Status Register Offset */
#define PORT_IER_OFFSET              (0x40)         /**< (PORT_IER) Interrupt Enable Register Offset */
#define PORT_IDR_OFFSET              (0x44)         /**< (PORT_IDR) Interrupt Disable Register Offset */
#define PORT_IMR_OFFSET              (0x48)         /**< (PORT_IMR) Interrupt Mask Register Offset */
#define PORT_ISR_OFFSET              (0x4C)         /**< (PORT_ISR) Interrupt Status Register Offset */
#define PORT_MDER_OFFSET             (0x50)         /**< (PORT_MDER) Multi-driver Enable Register Offset */
#define PORT_MDDR_OFFSET             (0x54)         /**< (PORT_MDDR) Multi-driver Disable Register Offset */
#define PORT_MDSR_OFFSET             (0x58)         /**< (PORT_MDSR) Multi-driver Status Register Offset */
#define PORT_PUDR_OFFSET             (0x60)         /**< (PORT_PUDR) Pull-up Disable Register Offset */
#define PORT_PUER_OFFSET             (0x64)         /**< (PORT_PUER) Pull-up Enable Register Offset */
#define PORT_PUSR_OFFSET             (0x68)         /**< (PORT_PUSR) Pad Pull-up Status Register Offset */
#define PORT_ABCDSR_OFFSET           (0x70)         /**< (PORT_ABCDSR) Peripheral ABCD Select Register 0 Offset */
#define PORT_IFSCDR_OFFSET           (0x80)         /**< (PORT_IFSCDR) Input Filter Slow Clock Disable Register Offset */
#define PORT_IFSCER_OFFSET           (0x84)         /**< (PORT_IFSCER) Input Filter Slow Clock Enable Register Offset */
#define PORT_IFSCSR_OFFSET           (0x88)         /**< (PORT_IFSCSR) Input Filter Slow Clock Status Register Offset */
#define PORT_SCDR_OFFSET             (0x8C)         /**< (PORT_SCDR) Slow Clock Divider Debouncing Register Offset */
#define PORT_PPDDR_OFFSET            (0x90)         /**< (PORT_PPDDR) Pad Pull-down Disable Register Offset */
#define PORT_PPDER_OFFSET            (0x94)         /**< (PORT_PPDER) Pad Pull-down Enable Register Offset */
#define PORT_PPDSR_OFFSET            (0x98)         /**< (PORT_PPDSR) Pad Pull-down Status Register Offset */
#define PORT_OWER_OFFSET             (0xA0)         /**< (PORT_OWER) Output Write Enable Offset */
#define PORT_OWDR_OFFSET             (0xA4)         /**< (PORT_OWDR) Output Write Disable Offset */
#define PORT_OWSR_OFFSET             (0xA8)         /**< (PORT_OWSR) Output Write Status Register Offset */
#define PORT_AIMER_OFFSET            (0xB0)         /**< (PORT_AIMER) Additional Interrupt Modes Enable Register Offset */
#define PORT_AIMDR_OFFSET            (0xB4)         /**< (PORT_AIMDR) Additional Interrupt Modes Disable Register Offset */
#define PORT_AIMMR_OFFSET            (0xB8)         /**< (PORT_AIMMR) Additional Interrupt Modes Mask Register Offset */
#define PORT_ESR_OFFSET              (0xC0)         /**< (PORT_ESR) Edge Select Register Offset */
#define PORT_LSR_OFFSET              (0xC4)         /**< (PORT_LSR) Level Select Register Offset */
#define PORT_ELSR_OFFSET             (0xC8)         /**< (PORT_ELSR) Edge/Level Status Register Offset */
#define PORT_FELLSR_OFFSET           (0xD0)         /**< (PORT_FELLSR) Falling Edge/Low-Level Select Register Offset */
#define PORT_REHLSR_OFFSET           (0xD4)         /**< (PORT_REHLSR) Rising Edge/High-Level Select Register Offset */
#define PORT_FRLHSR_OFFSET           (0xD8)         /**< (PORT_FRLHSR) Fall/Rise - Low/High Status Register Offset */
#define PORT_LOCKSR_OFFSET           (0xE0)         /**< (PORT_LOCKSR) Lock Status Offset */
#define PORT_WPMR_OFFSET             (0xE4)         /**< (PORT_WPMR) Write Protection Mode Register Offset */
#define PORT_WPSR_OFFSET             (0xE8)         /**< (PORT_WPSR) Write Protection Status Register Offset */
#define PORT_SCHMITT_OFFSET          (0x100)        /**< (PORT_SCHMITT) Schmitt Trigger Register Offset */
#define PORT_DRIVER_OFFSET           (0x118)        /**< (PORT_DRIVER) I/O Drive Register Offset */
#define PORT_PCMR_OFFSET             (0x150)        /**< (PORT_PCMR) Parallel Capture Mode Register Offset */
#define PORT_PCIER_OFFSET            (0x154)        /**< (PORT_PCIER) Parallel Capture Interrupt Enable Register Offset */
#define PORT_PCIDR_OFFSET            (0x158)        /**< (PORT_PCIDR) Parallel Capture Interrupt Disable Register Offset */
#define PORT_PCIMR_OFFSET            (0x15C)        /**< (PORT_PCIMR) Parallel Capture Interrupt Mask Register Offset */
#define PORT_PCISR_OFFSET            (0x160)        /**< (PORT_PCISR) Parallel Capture Interrupt Status Register Offset */
#define PORT_PCRHR_OFFSET            (0x164)        /**< (PORT_PCRHR) Parallel Capture Reception Holding Register Offset */

/** \brief PORT register API structure */
typedef struct
{
  __O   __PORT_PER_bits_t              PORT_PER;      /**< Offset: 0x00 ( /W  32) PORT Enable Register */
  __O   __PORT_PDR_bits_t              PORT_PDR;      /**< Offset: 0x04 ( /W  32) PORT Disable Register */
  __I   __PORT_PSR_bits_t              PORT_PSR;      /**< Offset: 0x08 (R/   32) PORT Status Register */
  __I   uint8_t                        Reserved1[0x04];
  __O   __PORT_OER_bits_t              PORT_OER;      /**< Offset: 0x10 ( /W  32) Output Enable Register */
  __O   __PORT_ODR_bits_t              PORT_ODR;      /**< Offset: 0x14 ( /W  32) Output Disable Register */
  __I   __PORT_OSR_bits_t              PORT_OSR;      /**< Offset: 0x18 (R/   32) Output Status Register */
  __I   uint8_t                        Reserved2[0x04];
  __O   __PORT_IFER_bits_t             PORT_IFER;     /**< Offset: 0x20 ( /W  32) Glitch Input Filter Enable Register */
  __O   __PORT_IFDR_bits_t             PORT_IFDR;     /**< Offset: 0x24 ( /W  32) Glitch Input Filter Disable Register */
  __I   __PORT_IFSR_bits_t             PORT_IFSR;     /**< Offset: 0x28 (R/   32) Glitch Input Filter Status Register */
  __I   uint8_t                        Reserved3[0x04];
  __O   __PORT_SODR_bits_t             PORT_SODR;     /**< Offset: 0x30 ( /W  32) Set Output Data Register */
  __O   __PORT_CODR_bits_t             PORT_CODR;     /**< Offset: 0x34 ( /W  32) Clear Output Data Register */
  __IO  __PORT_ODSR_bits_t             PORT_ODSR;     /**< Offset: 0x38 (R/W  32) Output Data Status Register */
  __I   __PORT_PDSR_bits_t             PORT_PDSR;     /**< Offset: 0x3C (R/   32) Pin Data Status Register */
  __O   __PORT_IER_bits_t              PORT_IER;      /**< Offset: 0x40 ( /W  32) Interrupt Enable Register */
  __O   __PORT_IDR_bits_t              PORT_IDR;      /**< Offset: 0x44 ( /W  32) Interrupt Disable Register */
  __I   __PORT_IMR_bits_t              PORT_IMR;      /**< Offset: 0x48 (R/   32) Interrupt Mask Register */
  __I   __PORT_ISR_bits_t              PORT_ISR;      /**< Offset: 0x4C (R/   32) Interrupt Status Register */
  __O   __PORT_MDER_bits_t             PORT_MDER;     /**< Offset: 0x50 ( /W  32) Multi-driver Enable Register */
  __O   __PORT_MDDR_bits_t             PORT_MDDR;     /**< Offset: 0x54 ( /W  32) Multi-driver Disable Register */
  __I   __PORT_MDSR_bits_t             PORT_MDSR;     /**< Offset: 0x58 (R/   32) Multi-driver Status Register */
  __I   uint8_t                        Reserved4[0x04];
  __O   __PORT_PUDR_bits_t             PORT_PUDR;     /**< Offset: 0x60 ( /W  32) Pull-up Disable Register */
  __O   __PORT_PUER_bits_t             PORT_PUER;     /**< Offset: 0x64 ( /W  32) Pull-up Enable Register */
  __I   __PORT_PUSR_bits_t             PORT_PUSR;     /**< Offset: 0x68 (R/   32) Pad Pull-up Status Register */
  __I   uint8_t                        Reserved5[0x04];
  __IO  __PORT_ABCDSR_bits_t           PORT_ABCDSR[2]; /**< Offset: 0x70 (R/W  32) Peripheral ABCD Select Register 0 */
  __I   uint8_t                        Reserved6[0x08];
  __O   __PORT_IFSCDR_bits_t           PORT_IFSCDR;   /**< Offset: 0x80 ( /W  32) Input Filter Slow Clock Disable Register */
  __O   __PORT_IFSCER_bits_t           PORT_IFSCER;   /**< Offset: 0x84 ( /W  32) Input Filter Slow Clock Enable Register */
  __I   __PORT_IFSCSR_bits_t           PORT_IFSCSR;   /**< Offset: 0x88 (R/   32) Input Filter Slow Clock Status Register */
  __IO  __PORT_SCDR_bits_t             PORT_SCDR;     /**< Offset: 0x8C (R/W  32) Slow Clock Divider Debouncing Register */
  __O   __PORT_PPDDR_bits_t            PORT_PPDDR;    /**< Offset: 0x90 ( /W  32) Pad Pull-down Disable Register */
  __O   __PORT_PPDER_bits_t            PORT_PPDER;    /**< Offset: 0x94 ( /W  32) Pad Pull-down Enable Register */
  __I   __PORT_PPDSR_bits_t            PORT_PPDSR;    /**< Offset: 0x98 (R/   32) Pad Pull-down Status Register */
  __I   uint8_t                        Reserved7[0x04];
  __O   __PORT_OWER_bits_t             PORT_OWER;     /**< Offset: 0xA0 ( /W  32) Output Write Enable */
  __O   __PORT_OWDR_bits_t             PORT_OWDR;     /**< Offset: 0xA4 ( /W  32) Output Write Disable */
  __I   __PORT_OWSR_bits_t             PORT_OWSR;     /**< Offset: 0xA8 (R/   32) Output Write Status Register */
  __I   uint8_t                        Reserved8[0x04];
  __O   __PORT_AIMER_bits_t            PORT_AIMER;    /**< Offset: 0xB0 ( /W  32) Additional Interrupt Modes Enable Register */
  __O   __PORT_AIMDR_bits_t            PORT_AIMDR;    /**< Offset: 0xB4 ( /W  32) Additional Interrupt Modes Disable Register */
  __I   __PORT_AIMMR_bits_t            PORT_AIMMR;    /**< Offset: 0xB8 (R/   32) Additional Interrupt Modes Mask Register */
  __I   uint8_t                        Reserved9[0x04];
  __O   __PORT_ESR_bits_t              PORT_ESR;      /**< Offset: 0xC0 ( /W  32) Edge Select Register */
  __O   __PORT_LSR_bits_t              PORT_LSR;      /**< Offset: 0xC4 ( /W  32) Level Select Register */
  __I   __PORT_ELSR_bits_t             PORT_ELSR;     /**< Offset: 0xC8 (R/   32) Edge/Level Status Register */
  __I   uint8_t                        Reserved10[0x04];
  __O   __PORT_FELLSR_bits_t           PORT_FELLSR;   /**< Offset: 0xD0 ( /W  32) Falling Edge/Low-Level Select Register */
  __O   __PORT_REHLSR_bits_t           PORT_REHLSR;   /**< Offset: 0xD4 ( /W  32) Rising Edge/High-Level Select Register */
  __I   __PORT_FRLHSR_bits_t           PORT_FRLHSR;   /**< Offset: 0xD8 (R/   32) Fall/Rise - Low/High Status Register */
  __I   uint8_t                        Reserved11[0x04];
  __I   __PORT_LOCKSR_bits_t           PORT_LOCKSR;   /**< Offset: 0xE0 (R/   32) Lock Status */
  __IO  __PORT_WPMR_bits_t             PORT_WPMR;     /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   __PORT_WPSR_bits_t             PORT_WPSR;     /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
  __I   uint8_t                        Reserved12[0x14];
  __IO  __PORT_SCHMITT_bits_t          PORT_SCHMITT;  /**< Offset: 0x100 (R/W  32) Schmitt Trigger Register */
  __I   uint8_t                        Reserved13[0x14];
  __IO  __PORT_DRIVER_bits_t           PORT_DRIVER;   /**< Offset: 0x118 (R/W  32) I/O Drive Register */
  __I   uint8_t                        Reserved14[0x34];
  __IO  __PORT_PCMR_bits_t             PORT_PCMR;     /**< Offset: 0x150 (R/W  32) Parallel Capture Mode Register */
  __O   __PORT_PCIER_bits_t            PORT_PCIER;    /**< Offset: 0x154 ( /W  32) Parallel Capture Interrupt Enable Register */
  __O   __PORT_PCIDR_bits_t            PORT_PCIDR;    /**< Offset: 0x158 ( /W  32) Parallel Capture Interrupt Disable Register */
  __I   __PORT_PCIMR_bits_t            PORT_PCIMR;    /**< Offset: 0x15C (R/   32) Parallel Capture Interrupt Mask Register */
  __I   __PORT_PCISR_bits_t            PORT_PCISR;    /**< Offset: 0x160 (R/   32) Parallel Capture Interrupt Status Register */
  __I   __PORT_PCRHR_bits_t            PORT_PCRHR;    /**< Offset: 0x164 (R/   32) Parallel Capture Reception Holding Register */
} port_registers_t;
/** @}  end of Port */

#endif /* _PIC32CZ_CA70_PORT_COMPONENT_H_ */
