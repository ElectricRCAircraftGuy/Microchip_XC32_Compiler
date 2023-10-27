/**
 * \brief Peripheral I/O description for PIC32CZ2038CA70064
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
#ifndef _PIC32CZ2038CA70064_GPIO_H_
#define _PIC32CZ2038CA70064_GPIO_H_

/* ========== Peripheral I/O pin numbers ========== */
#define PIN_PA0                     (  0)  /**< Pin Number for PA0 */
#define PIN_PA1                     (  1)  /**< Pin Number for PA1 */
#define PIN_PA2                     (  2)  /**< Pin Number for PA2 */
#define PIN_PA3                     (  3)  /**< Pin Number for PA3 */
#define PIN_PA4                     (  4)  /**< Pin Number for PA4 */
#define PIN_PA5                     (  5)  /**< Pin Number for PA5 */
#define PIN_PA6                     (  6)  /**< Pin Number for PA6 */
#define PIN_PA7                     (  7)  /**< Pin Number for PA7 */
#define PIN_PA8                     (  8)  /**< Pin Number for PA8 */
#define PIN_PA9                     (  9)  /**< Pin Number for PA9 */
#define PIN_PA10                    ( 10)  /**< Pin Number for PA10 */
#define PIN_PA11                    ( 11)  /**< Pin Number for PA11 */
#define PIN_PA12                    ( 12)  /**< Pin Number for PA12 */
#define PIN_PA13                    ( 13)  /**< Pin Number for PA13 */
#define PIN_PA14                    ( 14)  /**< Pin Number for PA14 */
#define PIN_PA15                    ( 15)  /**< Pin Number for PA15 */
#define PIN_PA16                    ( 16)  /**< Pin Number for PA16 */
#define PIN_PA17                    ( 17)  /**< Pin Number for PA17 */
#define PIN_PA18                    ( 18)  /**< Pin Number for PA18 */
#define PIN_PA19                    ( 19)  /**< Pin Number for PA19 */
#define PIN_PA20                    ( 20)  /**< Pin Number for PA20 */
#define PIN_PA21                    ( 21)  /**< Pin Number for PA21 */
#define PIN_PA22                    ( 22)  /**< Pin Number for PA22 */
#define PIN_PA23                    ( 23)  /**< Pin Number for PA23 */
#define PIN_PA24                    ( 24)  /**< Pin Number for PA24 */
#define PIN_PA25                    ( 25)  /**< Pin Number for PA25 */
#define PIN_PA26                    ( 26)  /**< Pin Number for PA26 */
#define PIN_PA27                    ( 27)  /**< Pin Number for PA27 */
#define PIN_PA28                    ( 28)  /**< Pin Number for PA28 */
#define PIN_PA29                    ( 29)  /**< Pin Number for PA29 */
#define PIN_PA30                    ( 30)  /**< Pin Number for PA30 */
#define PIN_PA31                    ( 31)  /**< Pin Number for PA31 */
#define PIN_PB0                     ( 32)  /**< Pin Number for PB0 */
#define PIN_PB1                     ( 33)  /**< Pin Number for PB1 */
#define PIN_PB2                     ( 34)  /**< Pin Number for PB2 */
#define PIN_PB3                     ( 35)  /**< Pin Number for PB3 */
#define PIN_PB4                     ( 36)  /**< Pin Number for PB4 */
#define PIN_PB5                     ( 37)  /**< Pin Number for PB5 */
#define PIN_PB6                     ( 38)  /**< Pin Number for PB6 */
#define PIN_PB7                     ( 39)  /**< Pin Number for PB7 */
#define PIN_PB8                     ( 40)  /**< Pin Number for PB8 */
#define PIN_PB9                     ( 41)  /**< Pin Number for PB9 */
#define PIN_PB12                    ( 44)  /**< Pin Number for PB12 */
#define PIN_PB13                    ( 45)  /**< Pin Number for PB13 */
#define PIN_PD0                     ( 96)  /**< Pin Number for PD0 */
#define PIN_PD1                     ( 97)  /**< Pin Number for PD1 */
#define PIN_PD2                     ( 98)  /**< Pin Number for PD2 */
#define PIN_PD3                     ( 99)  /**< Pin Number for PD3 */
#define PIN_PD4                     (100)  /**< Pin Number for PD4 */
#define PIN_PD5                     (101)  /**< Pin Number for PD5 */
#define PIN_PD6                     (102)  /**< Pin Number for PD6 */
#define PIN_PD7                     (103)  /**< Pin Number for PD7 */
#define PIN_PD8                     (104)  /**< Pin Number for PD8 */
#define PIN_PD9                     (105)  /**< Pin Number for PD9 */
#define PIN_PD10                    (106)  /**< Pin Number for PD10 */
#define PIN_PD11                    (107)  /**< Pin Number for PD11 */
#define PIN_PD12                    (108)  /**< Pin Number for PD12 */
#define PIN_PD13                    (109)  /**< Pin Number for PD13 */
#define PIN_PD14                    (110)  /**< Pin Number for PD14 */
#define PIN_PD15                    (111)  /**< Pin Number for PD15 */
#define PIN_PD16                    (112)  /**< Pin Number for PD16 */
#define PIN_PD17                    (113)  /**< Pin Number for PD17 */
#define PIN_PD18                    (114)  /**< Pin Number for PD18 */
#define PIN_PD19                    (115)  /**< Pin Number for PD19 */
#define PIN_PD20                    (116)  /**< Pin Number for PD20 */
#define PIN_PD21                    (117)  /**< Pin Number for PD21 */
#define PIN_PD22                    (118)  /**< Pin Number for PD22 */
#define PIN_PD23                    (119)  /**< Pin Number for PD23 */
#define PIN_PD24                    (120)  /**< Pin Number for PD24 */
#define PIN_PD25                    (121)  /**< Pin Number for PD25 */
#define PIN_PD26                    (122)  /**< Pin Number for PD26 */
#define PIN_PD27                    (123)  /**< Pin Number for PD27 */
#define PIN_PD28                    (124)  /**< Pin Number for PD28 */
#define PIN_PD29                    (125)  /**< Pin Number for PD29 */
#define PIN_PD30                    (126)  /**< Pin Number for PD30 */
#define PIN_PD31                    (127)  /**< Pin Number for PD31 */

/* ========== Peripheral I/O masks ========== */
#define PORT_PA0                    (1U << 0)  /**< PORT Mask for PA0 */
#define PORT_PA1                    (1U << 1)  /**< PORT Mask for PA1 */
#define PORT_PA2                    (1U << 2)  /**< PORT Mask for PA2 */
#define PORT_PA3                    (1U << 3)  /**< PORT Mask for PA3 */
#define PORT_PA4                    (1U << 4)  /**< PORT Mask for PA4 */
#define PORT_PA5                    (1U << 5)  /**< PORT Mask for PA5 */
#define PORT_PA6                    (1U << 6)  /**< PORT Mask for PA6 */
#define PORT_PA7                    (1U << 7)  /**< PORT Mask for PA7 */
#define PORT_PA8                    (1U << 8)  /**< PORT Mask for PA8 */
#define PORT_PA9                    (1U << 9)  /**< PORT Mask for PA9 */
#define PORT_PA10                   (1U << 10) /**< PORT Mask for PA10 */
#define PORT_PA11                   (1U << 11) /**< PORT Mask for PA11 */
#define PORT_PA12                   (1U << 12) /**< PORT Mask for PA12 */
#define PORT_PA13                   (1U << 13) /**< PORT Mask for PA13 */
#define PORT_PA14                   (1U << 14) /**< PORT Mask for PA14 */
#define PORT_PA15                   (1U << 15) /**< PORT Mask for PA15 */
#define PORT_PA16                   (1U << 16) /**< PORT Mask for PA16 */
#define PORT_PA17                   (1U << 17) /**< PORT Mask for PA17 */
#define PORT_PA18                   (1U << 18) /**< PORT Mask for PA18 */
#define PORT_PA19                   (1U << 19) /**< PORT Mask for PA19 */
#define PORT_PA20                   (1U << 20) /**< PORT Mask for PA20 */
#define PORT_PA21                   (1U << 21) /**< PORT Mask for PA21 */
#define PORT_PA22                   (1U << 22) /**< PORT Mask for PA22 */
#define PORT_PA23                   (1U << 23) /**< PORT Mask for PA23 */
#define PORT_PA24                   (1U << 24) /**< PORT Mask for PA24 */
#define PORT_PA25                   (1U << 25) /**< PORT Mask for PA25 */
#define PORT_PA26                   (1U << 26) /**< PORT Mask for PA26 */
#define PORT_PA27                   (1U << 27) /**< PORT Mask for PA27 */
#define PORT_PA28                   (1U << 28) /**< PORT Mask for PA28 */
#define PORT_PA29                   (1U << 29) /**< PORT Mask for PA29 */
#define PORT_PA30                   (1U << 30) /**< PORT Mask for PA30 */
#define PORT_PA31                   (1U << 31) /**< PORT Mask for PA31 */
#define PORT_PB0                    (1U << 0)  /**< PORT Mask for PB0 */
#define PORT_PB1                    (1U << 1)  /**< PORT Mask for PB1 */
#define PORT_PB2                    (1U << 2)  /**< PORT Mask for PB2 */
#define PORT_PB3                    (1U << 3)  /**< PORT Mask for PB3 */
#define PORT_PB4                    (1U << 4)  /**< PORT Mask for PB4 */
#define PORT_PB5                    (1U << 5)  /**< PORT Mask for PB5 */
#define PORT_PB6                    (1U << 6)  /**< PORT Mask for PB6 */
#define PORT_PB7                    (1U << 7)  /**< PORT Mask for PB7 */
#define PORT_PB8                    (1U << 8)  /**< PORT Mask for PB8 */
#define PORT_PB9                    (1U << 9)  /**< PORT Mask for PB9 */
#define PORT_PB12                   (1U << 12) /**< PORT Mask for PB12 */
#define PORT_PB13                   (1U << 13) /**< PORT Mask for PB13 */
#define PORT_PD0                    (1U << 0)  /**< PORT Mask for PD0 */
#define PORT_PD1                    (1U << 1)  /**< PORT Mask for PD1 */
#define PORT_PD2                    (1U << 2)  /**< PORT Mask for PD2 */
#define PORT_PD3                    (1U << 3)  /**< PORT Mask for PD3 */
#define PORT_PD4                    (1U << 4)  /**< PORT Mask for PD4 */
#define PORT_PD5                    (1U << 5)  /**< PORT Mask for PD5 */
#define PORT_PD6                    (1U << 6)  /**< PORT Mask for PD6 */
#define PORT_PD7                    (1U << 7)  /**< PORT Mask for PD7 */
#define PORT_PD8                    (1U << 8)  /**< PORT Mask for PD8 */
#define PORT_PD9                    (1U << 9)  /**< PORT Mask for PD9 */
#define PORT_PD10                   (1U << 10) /**< PORT Mask for PD10 */
#define PORT_PD11                   (1U << 11) /**< PORT Mask for PD11 */
#define PORT_PD12                   (1U << 12) /**< PORT Mask for PD12 */
#define PORT_PD13                   (1U << 13) /**< PORT Mask for PD13 */
#define PORT_PD14                   (1U << 14) /**< PORT Mask for PD14 */
#define PORT_PD15                   (1U << 15) /**< PORT Mask for PD15 */
#define PORT_PD16                   (1U << 16) /**< PORT Mask for PD16 */
#define PORT_PD17                   (1U << 17) /**< PORT Mask for PD17 */
#define PORT_PD18                   (1U << 18) /**< PORT Mask for PD18 */
#define PORT_PD19                   (1U << 19) /**< PORT Mask for PD19 */
#define PORT_PD20                   (1U << 20) /**< PORT Mask for PD20 */
#define PORT_PD21                   (1U << 21) /**< PORT Mask for PD21 */
#define PORT_PD22                   (1U << 22) /**< PORT Mask for PD22 */
#define PORT_PD23                   (1U << 23) /**< PORT Mask for PD23 */
#define PORT_PD24                   (1U << 24) /**< PORT Mask for PD24 */
#define PORT_PD25                   (1U << 25) /**< PORT Mask for PD25 */
#define PORT_PD26                   (1U << 26) /**< PORT Mask for PD26 */
#define PORT_PD27                   (1U << 27) /**< PORT Mask for PD27 */
#define PORT_PD28                   (1U << 28) /**< PORT Mask for PD28 */
#define PORT_PD29                   (1U << 29) /**< PORT Mask for PD29 */
#define PORT_PD30                   (1U << 30) /**< PORT Mask for PD30 */
#define PORT_PD31                   (1U << 31) /**< PORT Mask for PD31 */

/* ========== PIO definition for AFEC0 peripheral ========== */
#define PIN_PA8B_AFEC0_ADTRG                       (8L)         /**< AFEC0 signal: AFEC0_ADTRG on PA8 mux B*/
#define MUX_PA8B_AFEC0_ADTRG                       (1L)         /**< AFEC0 signal line function value: AFEC0_ADTRG */
#define PORT_PA8B_AFEC0_ADTRG                      (1UL << 8)
#define PIN_PD30X1_AFEC0_AD0                       (126L)       /**< AFEC0 signal: AFEC0_AD0 on PD30 mux X1*/
#define PORT_PD30X1_AFEC0_AD0                      (1UL << 30)
#define PIN_PA21X1_AFEC0_AD1                       (21L)        /**< AFEC0 signal: AFEC0_AD1 on PA21 mux X1*/
#define PORT_PA21X1_AFEC0_AD1                      (1UL << 21)
#define PIN_PB3X1_AFEC0_AD2                        (35L)        /**< AFEC0 signal: AFEC0_AD2 on PB3 mux X1*/
#define PORT_PB3X1_AFEC0_AD2                       (1UL << 3)
#define PIN_PB2X1_AFEC0_AD5                        (34L)        /**< AFEC0 signal: AFEC0_AD5 on PB2 mux X1*/
#define PORT_PB2X1_AFEC0_AD5                       (1UL << 2)
#define PIN_PA17X1_AFEC0_AD6                       (17L)        /**< AFEC0 signal: AFEC0_AD6 on PA17 mux X1*/
#define PORT_PA17X1_AFEC0_AD6                      (1UL << 17)
#define PIN_PA18X1_AFEC0_AD7                       (18L)        /**< AFEC0 signal: AFEC0_AD7 on PA18 mux X1*/
#define PORT_PA18X1_AFEC0_AD7                      (1UL << 18)
#define PIN_PA19X1_AFEC0_AD8                       (19L)        /**< AFEC0 signal: AFEC0_AD8 on PA19 mux X1*/
#define PORT_PA19X1_AFEC0_AD8                      (1UL << 19)
#define PIN_PA20X1_AFEC0_AD9                       (20L)        /**< AFEC0 signal: AFEC0_AD9 on PA20 mux X1*/
#define PORT_PA20X1_AFEC0_AD9                      (1UL << 20)
#define PIN_PB0X1_AFEC0_AD10                       (32L)        /**< AFEC0 signal: AFEC0_AD10 on PB0 mux X1*/
#define PORT_PB0X1_AFEC0_AD10                      (1UL << 0)
/* ========== PIO definition for AFEC1 peripheral ========== */
#define PIN_PD9C_AFEC1_ADTRG                       (105L)       /**< AFEC1 signal: AFEC1_ADTRG on PD9 mux C*/
#define MUX_PD9C_AFEC1_ADTRG                       (2L)         /**< AFEC1 signal line function value: AFEC1_ADTRG */
#define PORT_PD9C_AFEC1_ADTRG                      (1UL << 9)
#define PIN_PB1X1_AFEC1_AD0                        (33L)        /**< AFEC1 signal: AFEC1_AD0 on PB1 mux X1*/
#define PORT_PB1X1_AFEC1_AD0                       (1UL << 1)
/* ========== PIO definition for DACC peripheral ========== */
#define PIN_PB13X1_DACC_DAC0                       (45L)        /**< DACC signal: DAC0 on PB13 mux X1*/
#define PORT_PB13X1_DACC_DAC0                      (1UL << 13)
#define PIN_PD0X1_DACC_DAC1                        (96L)        /**< DACC signal: DAC1 on PD0 mux X1*/
#define PORT_PD0X1_DACC_DAC1                       (1UL << 0)
#define PIN_PA2C_DACC_DATRG                        (2L)         /**< DACC signal: DATRG on PA2 mux C*/
#define MUX_PA2C_DACC_DATRG                        (2L)         /**< DACC signal line function value: DATRG */
#define PORT_PA2C_DACC_DATRG                       (1UL << 2)
/* ========== PIO definition for GMAC peripheral ========== */
#define PIN_PD13A_GMAC_GCOL                        (109L)       /**< GMAC signal: GCOL on PD13 mux A*/
#define MUX_PD13A_GMAC_GCOL                        (0L)         /**< GMAC signal line function value: GCOL */
#define PORT_PD13A_GMAC_GCOL                       (1UL << 13)
#define PIN_PD10A_GMAC_GCRS                        (106L)       /**< GMAC signal: GCRS on PD10 mux A*/
#define MUX_PD10A_GMAC_GCRS                        (0L)         /**< GMAC signal line function value: GCRS */
#define PORT_PD10A_GMAC_GCRS                       (1UL << 10)
#define PIN_PD8A_GMAC_GMDC                         (104L)       /**< GMAC signal: GMDC on PD8 mux A*/
#define MUX_PD8A_GMAC_GMDC                         (0L)         /**< GMAC signal line function value: GMDC */
#define PORT_PD8A_GMAC_GMDC                        (1UL << 8)
#define PIN_PD9A_GMAC_GMDIO                        (105L)       /**< GMAC signal: GMDIO on PD9 mux A*/
#define MUX_PD9A_GMAC_GMDIO                        (0L)         /**< GMAC signal line function value: GMDIO */
#define PORT_PD9A_GMAC_GMDIO                       (1UL << 9)
#define PIN_PD14A_GMAC_GRXCK                       (110L)       /**< GMAC signal: GRXCK on PD14 mux A*/
#define MUX_PD14A_GMAC_GRXCK                       (0L)         /**< GMAC signal line function value: GRXCK */
#define PORT_PD14A_GMAC_GRXCK                      (1UL << 14)
#define PIN_PD4A_GMAC_GRXDV                        (100L)       /**< GMAC signal: GRXDV on PD4 mux A*/
#define MUX_PD4A_GMAC_GRXDV                        (0L)         /**< GMAC signal line function value: GRXDV */
#define PORT_PD4A_GMAC_GRXDV                       (1UL << 4)
#define PIN_PD7A_GMAC_GRXER                        (103L)       /**< GMAC signal: GRXER on PD7 mux A*/
#define MUX_PD7A_GMAC_GRXER                        (0L)         /**< GMAC signal line function value: GRXER */
#define PORT_PD7A_GMAC_GRXER                       (1UL << 7)
#define PIN_PD5A_GMAC_GRX0                         (101L)       /**< GMAC signal: GRX0 on PD5 mux A*/
#define MUX_PD5A_GMAC_GRX0                         (0L)         /**< GMAC signal line function value: GRX0 */
#define PORT_PD5A_GMAC_GRX0                        (1UL << 5)
#define PIN_PD6A_GMAC_GRX1                         (102L)       /**< GMAC signal: GRX1 on PD6 mux A*/
#define MUX_PD6A_GMAC_GRX1                         (0L)         /**< GMAC signal line function value: GRX1 */
#define PORT_PD6A_GMAC_GRX1                        (1UL << 6)
#define PIN_PD11A_GMAC_GRX2                        (107L)       /**< GMAC signal: GRX2 on PD11 mux A*/
#define MUX_PD11A_GMAC_GRX2                        (0L)         /**< GMAC signal line function value: GRX2 */
#define PORT_PD11A_GMAC_GRX2                       (1UL << 11)
#define PIN_PD12A_GMAC_GRX3                        (108L)       /**< GMAC signal: GRX3 on PD12 mux A*/
#define MUX_PD12A_GMAC_GRX3                        (0L)         /**< GMAC signal line function value: GRX3 */
#define PORT_PD12A_GMAC_GRX3                       (1UL << 12)
#define PIN_PB1B_GMAC_GTSUCOMP                     (33L)        /**< GMAC signal: GTSUCOMP on PB1 mux B*/
#define MUX_PB1B_GMAC_GTSUCOMP                     (1L)         /**< GMAC signal line function value: GTSUCOMP */
#define PORT_PB1B_GMAC_GTSUCOMP                    (1UL << 1)
#define PIN_PB12B_GMAC_GTSUCOMP                    (44L)        /**< GMAC signal: GTSUCOMP on PB12 mux B*/
#define MUX_PB12B_GMAC_GTSUCOMP                    (1L)         /**< GMAC signal line function value: GTSUCOMP */
#define PORT_PB12B_GMAC_GTSUCOMP                   (1UL << 12)
#define PIN_PD11C_GMAC_GTSUCOMP                    (107L)       /**< GMAC signal: GTSUCOMP on PD11 mux C*/
#define MUX_PD11C_GMAC_GTSUCOMP                    (2L)         /**< GMAC signal line function value: GTSUCOMP */
#define PORT_PD11C_GMAC_GTSUCOMP                   (1UL << 11)
#define PIN_PD20C_GMAC_GTSUCOMP                    (116L)       /**< GMAC signal: GTSUCOMP on PD20 mux C*/
#define MUX_PD20C_GMAC_GTSUCOMP                    (2L)         /**< GMAC signal line function value: GTSUCOMP */
#define PORT_PD20C_GMAC_GTSUCOMP                   (1UL << 20)
#define PIN_PD0A_GMAC_GTXCK                        (96L)        /**< GMAC signal: GTXCK on PD0 mux A*/
#define MUX_PD0A_GMAC_GTXCK                        (0L)         /**< GMAC signal line function value: GTXCK */
#define PORT_PD0A_GMAC_GTXCK                       (1UL << 0)
#define PIN_PD1A_GMAC_GTXEN                        (97L)        /**< GMAC signal: GTXEN on PD1 mux A*/
#define MUX_PD1A_GMAC_GTXEN                        (0L)         /**< GMAC signal line function value: GTXEN */
#define PORT_PD1A_GMAC_GTXEN                       (1UL << 1)
#define PIN_PD17A_GMAC_GTXER                       (113L)       /**< GMAC signal: GTXER on PD17 mux A*/
#define MUX_PD17A_GMAC_GTXER                       (0L)         /**< GMAC signal line function value: GTXER */
#define PORT_PD17A_GMAC_GTXER                      (1UL << 17)
#define PIN_PD2A_GMAC_GTX0                         (98L)        /**< GMAC signal: GTX0 on PD2 mux A*/
#define MUX_PD2A_GMAC_GTX0                         (0L)         /**< GMAC signal line function value: GTX0 */
#define PORT_PD2A_GMAC_GTX0                        (1UL << 2)
#define PIN_PD3A_GMAC_GTX1                         (99L)        /**< GMAC signal: GTX1 on PD3 mux A*/
#define MUX_PD3A_GMAC_GTX1                         (0L)         /**< GMAC signal line function value: GTX1 */
#define PORT_PD3A_GMAC_GTX1                        (1UL << 3)
#define PIN_PD15A_GMAC_GTX2                        (111L)       /**< GMAC signal: GTX2 on PD15 mux A*/
#define MUX_PD15A_GMAC_GTX2                        (0L)         /**< GMAC signal line function value: GTX2 */
#define PORT_PD15A_GMAC_GTX2                       (1UL << 15)
#define PIN_PD16A_GMAC_GTX3                        (112L)       /**< GMAC signal: GTX3 on PD16 mux A*/
#define MUX_PD16A_GMAC_GTX3                        (0L)         /**< GMAC signal line function value: GTX3 */
#define PORT_PD16A_GMAC_GTX3                       (1UL << 16)
/* ========== PIO definition for HSMCI peripheral ========== */
#define PIN_PA28C_HSMCI_MCCDA                      (28L)        /**< HSMCI signal: MCCDA on PA28 mux C*/
#define MUX_PA28C_HSMCI_MCCDA                      (2L)         /**< HSMCI signal line function value: MCCDA */
#define PORT_PA28C_HSMCI_MCCDA                     (1UL << 28)
#define PIN_PA25D_HSMCI_MCCK                       (25L)        /**< HSMCI signal: MCCK on PA25 mux D*/
#define MUX_PA25D_HSMCI_MCCK                       (3L)         /**< HSMCI signal line function value: MCCK */
#define PORT_PA25D_HSMCI_MCCK                      (1UL << 25)
#define PIN_PA30C_HSMCI_MCDA0                      (30L)        /**< HSMCI signal: MCDA0 on PA30 mux C*/
#define MUX_PA30C_HSMCI_MCDA0                      (2L)         /**< HSMCI signal line function value: MCDA0 */
#define PORT_PA30C_HSMCI_MCDA0                     (1UL << 30)
#define PIN_PA31C_HSMCI_MCDA1                      (31L)        /**< HSMCI signal: MCDA1 on PA31 mux C*/
#define MUX_PA31C_HSMCI_MCDA1                      (2L)         /**< HSMCI signal line function value: MCDA1 */
#define PORT_PA31C_HSMCI_MCDA1                     (1UL << 31)
#define PIN_PA26C_HSMCI_MCDA2                      (26L)        /**< HSMCI signal: MCDA2 on PA26 mux C*/
#define MUX_PA26C_HSMCI_MCDA2                      (2L)         /**< HSMCI signal line function value: MCDA2 */
#define PORT_PA26C_HSMCI_MCDA2                     (1UL << 26)
#define PIN_PA27C_HSMCI_MCDA3                      (27L)        /**< HSMCI signal: MCDA3 on PA27 mux C*/
#define MUX_PA27C_HSMCI_MCDA3                      (2L)         /**< HSMCI signal line function value: MCDA3 */
#define PORT_PA27C_HSMCI_MCDA3                     (1UL << 27)
/* ========== PIO definition for ISI peripheral ========== */
#define PIN_PD22D_ISI_D0                           (118L)       /**< ISI signal: ISI_D0 on PD22 mux D*/
#define MUX_PD22D_ISI_D0                           (3L)         /**< ISI signal line function value: ISI_D0 */
#define PORT_PD22D_ISI_D0                          (1UL << 22)
#define PIN_PD21D_ISI_D1                           (117L)       /**< ISI signal: ISI_D1 on PD21 mux D*/
#define MUX_PD21D_ISI_D1                           (3L)         /**< ISI signal line function value: ISI_D1 */
#define PORT_PD21D_ISI_D1                          (1UL << 21)
#define PIN_PB3D_ISI_D2                            (35L)        /**< ISI signal: ISI_D2 on PB3 mux D*/
#define MUX_PB3D_ISI_D2                            (3L)         /**< ISI signal line function value: ISI_D2 */
#define PORT_PB3D_ISI_D2                           (1UL << 3)
#define PIN_PA9B_ISI_D3                            (9L)         /**< ISI signal: ISI_D3 on PA9 mux B*/
#define MUX_PA9B_ISI_D3                            (1L)         /**< ISI signal line function value: ISI_D3 */
#define PORT_PA9B_ISI_D3                           (1UL << 9)
#define PIN_PA5B_ISI_D4                            (5L)         /**< ISI signal: ISI_D4 on PA5 mux B*/
#define MUX_PA5B_ISI_D4                            (1L)         /**< ISI signal line function value: ISI_D4 */
#define PORT_PA5B_ISI_D4                           (1UL << 5)
#define PIN_PD11D_ISI_D5                           (107L)       /**< ISI signal: ISI_D5 on PD11 mux D*/
#define MUX_PD11D_ISI_D5                           (3L)         /**< ISI signal line function value: ISI_D5 */
#define PORT_PD11D_ISI_D5                          (1UL << 11)
#define PIN_PD12D_ISI_D6                           (108L)       /**< ISI signal: ISI_D6 on PD12 mux D*/
#define MUX_PD12D_ISI_D6                           (3L)         /**< ISI signal line function value: ISI_D6 */
#define PORT_PD12D_ISI_D6                          (1UL << 12)
#define PIN_PA27D_ISI_D7                           (27L)        /**< ISI signal: ISI_D7 on PA27 mux D*/
#define MUX_PA27D_ISI_D7                           (3L)         /**< ISI signal line function value: ISI_D7 */
#define PORT_PA27D_ISI_D7                          (1UL << 27)
#define PIN_PD27D_ISI_D8                           (123L)       /**< ISI signal: ISI_D8 on PD27 mux D*/
#define MUX_PD27D_ISI_D8                           (3L)         /**< ISI signal line function value: ISI_D8 */
#define PORT_PD27D_ISI_D8                          (1UL << 27)
#define PIN_PD28D_ISI_D9                           (124L)       /**< ISI signal: ISI_D9 on PD28 mux D*/
#define MUX_PD28D_ISI_D9                           (3L)         /**< ISI signal line function value: ISI_D9 */
#define PORT_PD28D_ISI_D9                          (1UL << 28)
#define PIN_PD30D_ISI_D10                          (126L)       /**< ISI signal: ISI_D10 on PD30 mux D*/
#define MUX_PD30D_ISI_D10                          (3L)         /**< ISI signal line function value: ISI_D10 */
#define PORT_PD30D_ISI_D10                         (1UL << 30)
#define PIN_PD31D_ISI_D11                          (127L)       /**< ISI signal: ISI_D11 on PD31 mux D*/
#define MUX_PD31D_ISI_D11                          (3L)         /**< ISI signal line function value: ISI_D11 */
#define PORT_PD31D_ISI_D11                         (1UL << 31)
#define PIN_PD24D_ISI_HSYNC                        (120L)       /**< ISI signal: ISI_HSYNC on PD24 mux D*/
#define MUX_PD24D_ISI_HSYNC                        (3L)         /**< ISI signal line function value: ISI_HSYNC */
#define PORT_PD24D_ISI_HSYNC                       (1UL << 24)
#define PIN_PA24D_ISI_PCK                          (24L)        /**< ISI signal: ISI_PCK on PA24 mux D*/
#define MUX_PA24D_ISI_PCK                          (3L)         /**< ISI signal line function value: ISI_PCK */
#define PORT_PA24D_ISI_PCK                         (1UL << 24)
#define PIN_PD25D_ISI_VSYNC                        (121L)       /**< ISI signal: ISI_VSYNC on PD25 mux D*/
#define MUX_PD25D_ISI_VSYNC                        (3L)         /**< ISI signal line function value: ISI_VSYNC */
#define PORT_PD25D_ISI_VSYNC                       (1UL << 25)
/* ========== PIO definition for MCAN0 peripheral ========== */
#define PIN_PB3A_MCAN0_CANRX0                      (35L)        /**< MCAN0 signal: CANRX0 on PB3 mux A*/
#define MUX_PB3A_MCAN0_CANRX0                      (0L)         /**< MCAN0 signal line function value: CANRX0 */
#define PORT_PB3A_MCAN0_CANRX0                     (1UL << 3)
#define PIN_PB2A_MCAN0_CANTX0                      (34L)        /**< MCAN0 signal: CANTX0 on PB2 mux A*/
#define MUX_PB2A_MCAN0_CANTX0                      (0L)         /**< MCAN0 signal line function value: CANTX0 */
#define PORT_PB2A_MCAN0_CANTX0                     (1UL << 2)
/* ========== PIO definition for MCAN1 peripheral ========== */
#define PIN_PD28B_MCAN1_CANRX1                     (124L)       /**< MCAN1 signal: CANRX1 on PD28 mux B*/
#define MUX_PD28B_MCAN1_CANRX1                     (1L)         /**< MCAN1 signal line function value: CANRX1 */
#define PORT_PD28B_MCAN1_CANRX1                    (1UL << 28)
#define PIN_PD12B_MCAN1_CANTX1                     (108L)       /**< MCAN1 signal: CANTX1 on PD12 mux B*/
#define MUX_PD12B_MCAN1_CANTX1                     (1L)         /**< MCAN1 signal line function value: CANTX1 */
#define PORT_PD12B_MCAN1_CANTX1                    (1UL << 12)
/* ========== PIO definition for MLB peripheral ========== */
#define PIN_PB4C_MLB_MLBCLK                        (36L)        /**< MLB signal: MLBCLK on PB4 mux C*/
#define MUX_PB4C_MLB_MLBCLK                        (2L)         /**< MLB signal line function value: MLBCLK */
#define PORT_PB4C_MLB_MLBCLK                       (1UL << 4)
#define PIN_PB5C_MLB_MLBDAT                        (37L)        /**< MLB signal: MLBDAT on PB5 mux C*/
#define MUX_PB5C_MLB_MLBDAT                        (2L)         /**< MLB signal line function value: MLBDAT */
#define PORT_PB5C_MLB_MLBDAT                       (1UL << 5)
#define PIN_PD10D_MLB_MLBSIG                       (106L)       /**< MLB signal: MLBSIG on PD10 mux D*/
#define MUX_PD10D_MLB_MLBSIG                       (3L)         /**< MLB signal line function value: MLBSIG */
#define PORT_PD10D_MLB_MLBSIG                      (1UL << 10)
/* ========== PIO definition for PMC peripheral ========== */
#define PIN_PA6B_PMC_PCK0                          (6L)         /**< PMC signal: PCK0 on PA6 mux B*/
#define MUX_PA6B_PMC_PCK0                          (1L)         /**< PMC signal line function value: PCK0 */
#define PORT_PA6B_PMC_PCK0                         (1UL << 6)
#define PIN_PB12D_PMC_PCK0                         (44L)        /**< PMC signal: PCK0 on PB12 mux D*/
#define MUX_PB12D_PMC_PCK0                         (3L)         /**< PMC signal line function value: PCK0 */
#define PORT_PB12D_PMC_PCK0                        (1UL << 12)
#define PIN_PB13B_PMC_PCK0                         (45L)        /**< PMC signal: PCK0 on PB13 mux B*/
#define MUX_PB13B_PMC_PCK0                         (1L)         /**< PMC signal line function value: PCK0 */
#define PORT_PB13B_PMC_PCK0                        (1UL << 13)
#define PIN_PA17B_PMC_PCK1                         (17L)        /**< PMC signal: PCK1 on PA17 mux B*/
#define MUX_PA17B_PMC_PCK1                         (1L)         /**< PMC signal line function value: PCK1 */
#define PORT_PA17B_PMC_PCK1                        (1UL << 17)
#define PIN_PA21B_PMC_PCK1                         (21L)        /**< PMC signal: PCK1 on PA21 mux B*/
#define MUX_PA21B_PMC_PCK1                         (1L)         /**< PMC signal line function value: PCK1 */
#define PORT_PA21B_PMC_PCK1                        (1UL << 21)
#define PIN_PA3C_PMC_PCK2                          (3L)         /**< PMC signal: PCK2 on PA3 mux C*/
#define MUX_PA3C_PMC_PCK2                          (2L)         /**< PMC signal line function value: PCK2 */
#define PORT_PA3C_PMC_PCK2                         (1UL << 3)
#define PIN_PA18B_PMC_PCK2                         (18L)        /**< PMC signal: PCK2 on PA18 mux B*/
#define MUX_PA18B_PMC_PCK2                         (1L)         /**< PMC signal line function value: PCK2 */
#define PORT_PA18B_PMC_PCK2                        (1UL << 18)
#define PIN_PA31B_PMC_PCK2                         (31L)        /**< PMC signal: PCK2 on PA31 mux B*/
#define MUX_PA31B_PMC_PCK2                         (1L)         /**< PMC signal line function value: PCK2 */
#define PORT_PA31B_PMC_PCK2                        (1UL << 31)
#define PIN_PB3B_PMC_PCK2                          (35L)        /**< PMC signal: PCK2 on PB3 mux B*/
#define MUX_PB3B_PMC_PCK2                          (1L)         /**< PMC signal line function value: PCK2 */
#define PORT_PB3B_PMC_PCK2                         (1UL << 3)
#define PIN_PD31C_PMC_PCK2                         (127L)       /**< PMC signal: PCK2 on PD31 mux C*/
#define MUX_PD31C_PMC_PCK2                         (2L)         /**< PMC signal line function value: PCK2 */
#define PORT_PD31C_PMC_PCK2                        (1UL << 31)
/* ========== PIO definition for PWMC0 peripheral ========== */
#define PIN_PA10B_PWMC0_PWMEXTRG0                  (10L)        /**< PWMC0 signal: PWMC0_PWMEXTRG0 on PA10 mux B*/
#define MUX_PA10B_PWMC0_PWMEXTRG0                  (1L)         /**< PWMC0 signal line function value: PWMC0_PWMEXTRG0 */
#define PORT_PA10B_PWMC0_PWMEXTRG0                 (1UL << 10)
#define PIN_PA22B_PWMC0_PWMEXTRG1                  (22L)        /**< PWMC0 signal: PWMC0_PWMEXTRG1 on PA22 mux B*/
#define MUX_PA22B_PWMC0_PWMEXTRG1                  (1L)         /**< PWMC0 signal line function value: PWMC0_PWMEXTRG1 */
#define PORT_PA22B_PWMC0_PWMEXTRG1                 (1UL << 22)
#define PIN_PA9C_PWMC0_PWMFI0                      (9L)         /**< PWMC0 signal: PWMC0_PWMFI0 on PA9 mux C*/
#define MUX_PA9C_PWMC0_PWMFI0                      (2L)         /**< PWMC0 signal line function value: PWMC0_PWMFI0 */
#define PORT_PA9C_PWMC0_PWMFI0                     (1UL << 9)
#define PIN_PD8B_PWMC0_PWMFI1                      (104L)       /**< PWMC0 signal: PWMC0_PWMFI1 on PD8 mux B*/
#define MUX_PD8B_PWMC0_PWMFI1                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWMFI1 */
#define PORT_PD8B_PWMC0_PWMFI1                     (1UL << 8)
#define PIN_PD9B_PWMC0_PWMFI2                      (105L)       /**< PWMC0 signal: PWMC0_PWMFI2 on PD9 mux B*/
#define MUX_PD9B_PWMC0_PWMFI2                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWMFI2 */
#define PORT_PD9B_PWMC0_PWMFI2                     (1UL << 9)
#define PIN_PA0A_PWMC0_PWMH0                       (0L)         /**< PWMC0 signal: PWMC0_PWMH0 on PA0 mux A*/
#define MUX_PA0A_PWMC0_PWMH0                       (0L)         /**< PWMC0 signal line function value: PWMC0_PWMH0 */
#define PORT_PA0A_PWMC0_PWMH0                      (1UL << 0)
#define PIN_PA11B_PWMC0_PWMH0                      (11L)        /**< PWMC0 signal: PWMC0_PWMH0 on PA11 mux B*/
#define MUX_PA11B_PWMC0_PWMH0                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWMH0 */
#define PORT_PA11B_PWMC0_PWMH0                     (1UL << 11)
#define PIN_PA23B_PWMC0_PWMH0                      (23L)        /**< PWMC0 signal: PWMC0_PWMH0 on PA23 mux B*/
#define MUX_PA23B_PWMC0_PWMH0                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWMH0 */
#define PORT_PA23B_PWMC0_PWMH0                     (1UL << 23)
#define PIN_PB0A_PWMC0_PWMH0                       (32L)        /**< PWMC0 signal: PWMC0_PWMH0 on PB0 mux A*/
#define MUX_PB0A_PWMC0_PWMH0                       (0L)         /**< PWMC0 signal line function value: PWMC0_PWMH0 */
#define PORT_PB0A_PWMC0_PWMH0                      (1UL << 0)
#define PIN_PD11B_PWMC0_PWMH0                      (107L)       /**< PWMC0 signal: PWMC0_PWMH0 on PD11 mux B*/
#define MUX_PD11B_PWMC0_PWMH0                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWMH0 */
#define PORT_PD11B_PWMC0_PWMH0                     (1UL << 11)
#define PIN_PD20A_PWMC0_PWMH0                      (116L)       /**< PWMC0 signal: PWMC0_PWMH0 on PD20 mux A*/
#define MUX_PD20A_PWMC0_PWMH0                      (0L)         /**< PWMC0 signal line function value: PWMC0_PWMH0 */
#define PORT_PD20A_PWMC0_PWMH0                     (1UL << 20)
#define PIN_PA2A_PWMC0_PWMH1                       (2L)         /**< PWMC0 signal: PWMC0_PWMH1 on PA2 mux A*/
#define MUX_PA2A_PWMC0_PWMH1                       (0L)         /**< PWMC0 signal line function value: PWMC0_PWMH1 */
#define PORT_PA2A_PWMC0_PWMH1                      (1UL << 2)
#define PIN_PA12B_PWMC0_PWMH1                      (12L)        /**< PWMC0 signal: PWMC0_PWMH1 on PA12 mux B*/
#define MUX_PA12B_PWMC0_PWMH1                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWMH1 */
#define PORT_PA12B_PWMC0_PWMH1                     (1UL << 12)
#define PIN_PA24B_PWMC0_PWMH1                      (24L)        /**< PWMC0 signal: PWMC0_PWMH1 on PA24 mux B*/
#define MUX_PA24B_PWMC0_PWMH1                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWMH1 */
#define PORT_PA24B_PWMC0_PWMH1                     (1UL << 24)
#define PIN_PB1A_PWMC0_PWMH1                       (33L)        /**< PWMC0 signal: PWMC0_PWMH1 on PB1 mux A*/
#define MUX_PB1A_PWMC0_PWMH1                       (0L)         /**< PWMC0 signal line function value: PWMC0_PWMH1 */
#define PORT_PB1A_PWMC0_PWMH1                      (1UL << 1)
#define PIN_PD21A_PWMC0_PWMH1                      (117L)       /**< PWMC0 signal: PWMC0_PWMH1 on PD21 mux A*/
#define MUX_PD21A_PWMC0_PWMH1                      (0L)         /**< PWMC0 signal line function value: PWMC0_PWMH1 */
#define PORT_PD21A_PWMC0_PWMH1                     (1UL << 21)
#define PIN_PA13B_PWMC0_PWMH2                      (13L)        /**< PWMC0 signal: PWMC0_PWMH2 on PA13 mux B*/
#define MUX_PA13B_PWMC0_PWMH2                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWMH2 */
#define PORT_PA13B_PWMC0_PWMH2                     (1UL << 13)
#define PIN_PA25B_PWMC0_PWMH2                      (25L)        /**< PWMC0 signal: PWMC0_PWMH2 on PA25 mux B*/
#define MUX_PA25B_PWMC0_PWMH2                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWMH2 */
#define PORT_PA25B_PWMC0_PWMH2                     (1UL << 25)
#define PIN_PB4B_PWMC0_PWMH2                       (36L)        /**< PWMC0 signal: PWMC0_PWMH2 on PB4 mux B*/
#define MUX_PB4B_PWMC0_PWMH2                       (1L)         /**< PWMC0 signal line function value: PWMC0_PWMH2 */
#define PORT_PB4B_PWMC0_PWMH2                      (1UL << 4)
#define PIN_PD22A_PWMC0_PWMH2                      (118L)       /**< PWMC0 signal: PWMC0_PWMH2 on PD22 mux A*/
#define MUX_PD22A_PWMC0_PWMH2                      (0L)         /**< PWMC0 signal line function value: PWMC0_PWMH2 */
#define PORT_PD22A_PWMC0_PWMH2                     (1UL << 22)
#define PIN_PA7B_PWMC0_PWMH3                       (7L)         /**< PWMC0 signal: PWMC0_PWMH3 on PA7 mux B*/
#define MUX_PA7B_PWMC0_PWMH3                       (1L)         /**< PWMC0 signal line function value: PWMC0_PWMH3 */
#define PORT_PA7B_PWMC0_PWMH3                      (1UL << 7)
#define PIN_PA14B_PWMC0_PWMH3                      (14L)        /**< PWMC0 signal: PWMC0_PWMH3 on PA14 mux B*/
#define MUX_PA14B_PWMC0_PWMH3                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWMH3 */
#define PORT_PA14B_PWMC0_PWMH3                     (1UL << 14)
#define PIN_PA17C_PWMC0_PWMH3                      (17L)        /**< PWMC0 signal: PWMC0_PWMH3 on PA17 mux C*/
#define MUX_PA17C_PWMC0_PWMH3                      (2L)         /**< PWMC0 signal line function value: PWMC0_PWMH3 */
#define PORT_PA17C_PWMC0_PWMH3                     (1UL << 17)
#define PIN_PD23A_PWMC0_PWMH3                      (119L)       /**< PWMC0 signal: PWMC0_PWMH3 on PD23 mux A*/
#define MUX_PD23A_PWMC0_PWMH3                      (0L)         /**< PWMC0 signal line function value: PWMC0_PWMH3 */
#define PORT_PD23A_PWMC0_PWMH3                     (1UL << 23)
#define PIN_PA1A_PWMC0_PWML0                       (1L)         /**< PWMC0 signal: PWMC0_PWML0 on PA1 mux A*/
#define MUX_PA1A_PWMC0_PWML0                       (0L)         /**< PWMC0 signal line function value: PWMC0_PWML0 */
#define PORT_PA1A_PWMC0_PWML0                      (1UL << 1)
#define PIN_PA19B_PWMC0_PWML0                      (19L)        /**< PWMC0 signal: PWMC0_PWML0 on PA19 mux B*/
#define MUX_PA19B_PWMC0_PWML0                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWML0 */
#define PORT_PA19B_PWMC0_PWML0                     (1UL << 19)
#define PIN_PB5B_PWMC0_PWML0                       (37L)        /**< PWMC0 signal: PWMC0_PWML0 on PB5 mux B*/
#define MUX_PB5B_PWMC0_PWML0                       (1L)         /**< PWMC0 signal line function value: PWMC0_PWML0 */
#define PORT_PB5B_PWMC0_PWML0                      (1UL << 5)
#define PIN_PD10B_PWMC0_PWML0                      (106L)       /**< PWMC0 signal: PWMC0_PWML0 on PD10 mux B*/
#define MUX_PD10B_PWMC0_PWML0                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWML0 */
#define PORT_PD10B_PWMC0_PWML0                     (1UL << 10)
#define PIN_PD24A_PWMC0_PWML0                      (120L)       /**< PWMC0 signal: PWMC0_PWML0 on PD24 mux A*/
#define MUX_PD24A_PWMC0_PWML0                      (0L)         /**< PWMC0 signal line function value: PWMC0_PWML0 */
#define PORT_PD24A_PWMC0_PWML0                     (1UL << 24)
#define PIN_PA20B_PWMC0_PWML1                      (20L)        /**< PWMC0 signal: PWMC0_PWML1 on PA20 mux B*/
#define MUX_PA20B_PWMC0_PWML1                      (1L)         /**< PWMC0 signal line function value: PWMC0_PWML1 */
#define PORT_PA20B_PWMC0_PWML1                     (1UL << 20)
#define PIN_PB12A_PWMC0_PWML1                      (44L)        /**< PWMC0 signal: PWMC0_PWML1 on PB12 mux A*/
#define MUX_PB12A_PWMC0_PWML1                      (0L)         /**< PWMC0 signal line function value: PWMC0_PWML1 */
#define PORT_PB12A_PWMC0_PWML1                     (1UL << 12)
#define PIN_PD25A_PWMC0_PWML1                      (121L)       /**< PWMC0 signal: PWMC0_PWML1 on PD25 mux A*/
#define MUX_PD25A_PWMC0_PWML1                      (0L)         /**< PWMC0 signal line function value: PWMC0_PWML1 */
#define PORT_PD25A_PWMC0_PWML1                     (1UL << 25)
#define PIN_PA16C_PWMC0_PWML2                      (16L)        /**< PWMC0 signal: PWMC0_PWML2 on PA16 mux C*/
#define MUX_PA16C_PWMC0_PWML2                      (2L)         /**< PWMC0 signal line function value: PWMC0_PWML2 */
#define PORT_PA16C_PWMC0_PWML2                     (1UL << 16)
#define PIN_PA30A_PWMC0_PWML2                      (30L)        /**< PWMC0 signal: PWMC0_PWML2 on PA30 mux A*/
#define MUX_PA30A_PWMC0_PWML2                      (0L)         /**< PWMC0 signal line function value: PWMC0_PWML2 */
#define PORT_PA30A_PWMC0_PWML2                     (1UL << 30)
#define PIN_PB13A_PWMC0_PWML2                      (45L)        /**< PWMC0 signal: PWMC0_PWML2 on PB13 mux A*/
#define MUX_PB13A_PWMC0_PWML2                      (0L)         /**< PWMC0 signal line function value: PWMC0_PWML2 */
#define PORT_PB13A_PWMC0_PWML2                     (1UL << 13)
#define PIN_PD26A_PWMC0_PWML2                      (122L)       /**< PWMC0 signal: PWMC0_PWML2 on PD26 mux A*/
#define MUX_PD26A_PWMC0_PWML2                      (0L)         /**< PWMC0 signal line function value: PWMC0_PWML2 */
#define PORT_PD26A_PWMC0_PWML2                     (1UL << 26)
#define PIN_PA15C_PWMC0_PWML3                      (15L)        /**< PWMC0 signal: PWMC0_PWML3 on PA15 mux C*/
#define MUX_PA15C_PWMC0_PWML3                      (2L)         /**< PWMC0 signal line function value: PWMC0_PWML3 */
#define PORT_PA15C_PWMC0_PWML3                     (1UL << 15)
#define PIN_PD27A_PWMC0_PWML3                      (123L)       /**< PWMC0 signal: PWMC0_PWML3 on PD27 mux A*/
#define MUX_PD27A_PWMC0_PWML3                      (0L)         /**< PWMC0 signal line function value: PWMC0_PWML3 */
#define PORT_PD27A_PWMC0_PWML3                     (1UL << 27)
/* ========== PIO definition for PWMC1 peripheral ========== */
#define PIN_PA30B_PWMC1_PWMEXTRG0                  (30L)        /**< PWMC1 signal: PWMC1_PWMEXTRG0 on PA30 mux B*/
#define MUX_PA30B_PWMC1_PWMEXTRG0                  (1L)         /**< PWMC1 signal line function value: PWMC1_PWMEXTRG0 */
#define PORT_PA30B_PWMC1_PWMEXTRG0                 (1UL << 30)
#define PIN_PA18A_PWMC1_PWMEXTRG1                  (18L)        /**< PWMC1 signal: PWMC1_PWMEXTRG1 on PA18 mux A*/
#define MUX_PA18A_PWMC1_PWMEXTRG1                  (0L)         /**< PWMC1 signal line function value: PWMC1_PWMEXTRG1 */
#define PORT_PA18A_PWMC1_PWMEXTRG1                 (1UL << 18)
#define PIN_PA21C_PWMC1_PWMFI0                     (21L)        /**< PWMC1 signal: PWMC1_PWMFI0 on PA21 mux C*/
#define MUX_PA21C_PWMC1_PWMFI0                     (2L)         /**< PWMC1 signal line function value: PWMC1_PWMFI0 */
#define PORT_PA21C_PWMC1_PWMFI0                    (1UL << 21)
#define PIN_PA26D_PWMC1_PWMFI1                     (26L)        /**< PWMC1 signal: PWMC1_PWMFI1 on PA26 mux D*/
#define MUX_PA26D_PWMC1_PWMFI1                     (3L)         /**< PWMC1 signal line function value: PWMC1_PWMFI1 */
#define PORT_PA26D_PWMC1_PWMFI1                    (1UL << 26)
#define PIN_PA28D_PWMC1_PWMFI2                     (28L)        /**< PWMC1 signal: PWMC1_PWMFI2 on PA28 mux D*/
#define MUX_PA28D_PWMC1_PWMFI2                     (3L)         /**< PWMC1 signal line function value: PWMC1_PWMFI2 */
#define PORT_PA28D_PWMC1_PWMFI2                    (1UL << 28)
#define PIN_PA12C_PWMC1_PWMH0                      (12L)        /**< PWMC1 signal: PWMC1_PWMH0 on PA12 mux C*/
#define MUX_PA12C_PWMC1_PWMH0                      (2L)         /**< PWMC1 signal line function value: PWMC1_PWMH0 */
#define PORT_PA12C_PWMC1_PWMH0                     (1UL << 12)
#define PIN_PD1B_PWMC1_PWMH0                       (97L)        /**< PWMC1 signal: PWMC1_PWMH0 on PD1 mux B*/
#define MUX_PD1B_PWMC1_PWMH0                       (1L)         /**< PWMC1 signal line function value: PWMC1_PWMH0 */
#define PORT_PD1B_PWMC1_PWMH0                      (1UL << 1)
#define PIN_PA14C_PWMC1_PWMH1                      (14L)        /**< PWMC1 signal: PWMC1_PWMH1 on PA14 mux C*/
#define MUX_PA14C_PWMC1_PWMH1                      (2L)         /**< PWMC1 signal line function value: PWMC1_PWMH1 */
#define PORT_PA14C_PWMC1_PWMH1                     (1UL << 14)
#define PIN_PD3B_PWMC1_PWMH1                       (99L)        /**< PWMC1 signal: PWMC1_PWMH1 on PD3 mux B*/
#define MUX_PD3B_PWMC1_PWMH1                       (1L)         /**< PWMC1 signal line function value: PWMC1_PWMH1 */
#define PORT_PD3B_PWMC1_PWMH1                      (1UL << 3)
#define PIN_PA31D_PWMC1_PWMH2                      (31L)        /**< PWMC1 signal: PWMC1_PWMH2 on PA31 mux D*/
#define MUX_PA31D_PWMC1_PWMH2                      (3L)         /**< PWMC1 signal line function value: PWMC1_PWMH2 */
#define PORT_PA31D_PWMC1_PWMH2                     (1UL << 31)
#define PIN_PD5B_PWMC1_PWMH2                       (101L)       /**< PWMC1 signal: PWMC1_PWMH2 on PD5 mux B*/
#define MUX_PD5B_PWMC1_PWMH2                       (1L)         /**< PWMC1 signal line function value: PWMC1_PWMH2 */
#define PORT_PD5B_PWMC1_PWMH2                      (1UL << 5)
#define PIN_PA8A_PWMC1_PWMH3                       (8L)         /**< PWMC1 signal: PWMC1_PWMH3 on PA8 mux A*/
#define MUX_PA8A_PWMC1_PWMH3                       (0L)         /**< PWMC1 signal line function value: PWMC1_PWMH3 */
#define PORT_PA8A_PWMC1_PWMH3                      (1UL << 8)
#define PIN_PD7B_PWMC1_PWMH3                       (103L)       /**< PWMC1 signal: PWMC1_PWMH3 on PD7 mux B*/
#define MUX_PD7B_PWMC1_PWMH3                       (1L)         /**< PWMC1 signal line function value: PWMC1_PWMH3 */
#define PORT_PD7B_PWMC1_PWMH3                      (1UL << 7)
#define PIN_PA11C_PWMC1_PWML0                      (11L)        /**< PWMC1 signal: PWMC1_PWML0 on PA11 mux C*/
#define MUX_PA11C_PWMC1_PWML0                      (2L)         /**< PWMC1 signal line function value: PWMC1_PWML0 */
#define PORT_PA11C_PWMC1_PWML0                     (1UL << 11)
#define PIN_PD0B_PWMC1_PWML0                       (96L)        /**< PWMC1 signal: PWMC1_PWML0 on PD0 mux B*/
#define MUX_PD0B_PWMC1_PWML0                       (1L)         /**< PWMC1 signal line function value: PWMC1_PWML0 */
#define PORT_PD0B_PWMC1_PWML0                      (1UL << 0)
#define PIN_PA13C_PWMC1_PWML1                      (13L)        /**< PWMC1 signal: PWMC1_PWML1 on PA13 mux C*/
#define MUX_PA13C_PWMC1_PWML1                      (2L)         /**< PWMC1 signal line function value: PWMC1_PWML1 */
#define PORT_PA13C_PWMC1_PWML1                     (1UL << 13)
#define PIN_PD2B_PWMC1_PWML1                       (98L)        /**< PWMC1 signal: PWMC1_PWML1 on PD2 mux B*/
#define MUX_PD2B_PWMC1_PWML1                       (1L)         /**< PWMC1 signal line function value: PWMC1_PWML1 */
#define PORT_PD2B_PWMC1_PWML1                      (1UL << 2)
#define PIN_PA23D_PWMC1_PWML2                      (23L)        /**< PWMC1 signal: PWMC1_PWML2 on PA23 mux D*/
#define MUX_PA23D_PWMC1_PWML2                      (3L)         /**< PWMC1 signal line function value: PWMC1_PWML2 */
#define PORT_PA23D_PWMC1_PWML2                     (1UL << 23)
#define PIN_PD4B_PWMC1_PWML2                       (100L)       /**< PWMC1 signal: PWMC1_PWML2 on PD4 mux B*/
#define MUX_PD4B_PWMC1_PWML2                       (1L)         /**< PWMC1 signal line function value: PWMC1_PWML2 */
#define PORT_PD4B_PWMC1_PWML2                      (1UL << 4)
#define PIN_PA5A_PWMC1_PWML3                       (5L)         /**< PWMC1 signal: PWMC1_PWML3 on PA5 mux A*/
#define MUX_PA5A_PWMC1_PWML3                       (0L)         /**< PWMC1 signal line function value: PWMC1_PWML3 */
#define PORT_PA5A_PWMC1_PWML3                      (1UL << 5)
#define PIN_PD6B_PWMC1_PWML3                       (102L)       /**< PWMC1 signal: PWMC1_PWML3 on PD6 mux B*/
#define MUX_PD6B_PWMC1_PWML3                       (1L)         /**< PWMC1 signal line function value: PWMC1_PWML3 */
#define PORT_PD6B_PWMC1_PWML3                      (1UL << 6)
/* ========== PIO definition for QSPI peripheral ========== */
#define PIN_PA11A_QSPI_QCS                         (11L)        /**< QSPI signal: QCS on PA11 mux A*/
#define MUX_PA11A_QSPI_QCS                         (0L)         /**< QSPI signal line function value: QCS */
#define PORT_PA11A_QSPI_QCS                        (1UL << 11)
#define PIN_PA13A_QSPI_QIO0                        (13L)        /**< QSPI signal: QIO0 on PA13 mux A*/
#define MUX_PA13A_QSPI_QIO0                        (0L)         /**< QSPI signal line function value: QIO0 */
#define PORT_PA13A_QSPI_QIO0                       (1UL << 13)
#define PIN_PA12A_QSPI_QIO1                        (12L)        /**< QSPI signal: QIO1 on PA12 mux A*/
#define MUX_PA12A_QSPI_QIO1                        (0L)         /**< QSPI signal line function value: QIO1 */
#define PORT_PA12A_QSPI_QIO1                       (1UL << 12)
#define PIN_PA17A_QSPI_QIO2                        (17L)        /**< QSPI signal: QIO2 on PA17 mux A*/
#define MUX_PA17A_QSPI_QIO2                        (0L)         /**< QSPI signal line function value: QIO2 */
#define PORT_PA17A_QSPI_QIO2                       (1UL << 17)
#define PIN_PD31A_QSPI_QIO3                        (127L)       /**< QSPI signal: QIO3 on PD31 mux A*/
#define MUX_PD31A_QSPI_QIO3                        (0L)         /**< QSPI signal line function value: QIO3 */
#define PORT_PD31A_QSPI_QIO3                       (1UL << 31)
#define PIN_PA14A_QSPI_QSCK                        (14L)        /**< QSPI signal: QSCK on PA14 mux A*/
#define MUX_PA14A_QSPI_QSCK                        (0L)         /**< QSPI signal line function value: QSCK */
#define PORT_PA14A_QSPI_QSCK                       (1UL << 14)
/* ========== PIO definition for RTC peripheral ========== */
#define PIN_PB0X1_RTC_RTCOUT0                      (32L)        /**< RTC signal: RTCOUT0 on PB0 mux X1*/
#define PORT_PB0X1_RTC_RTCOUT0                     (1UL << 0)
#define PIN_PB1X1_RTC_RTCOUT1                      (33L)        /**< RTC signal: RTCOUT1 on PB1 mux X1*/
#define PORT_PB1X1_RTC_RTCOUT1                     (1UL << 1)
/* ========== PIO definition for SSC peripheral ========== */
#define PIN_PA10C_SSC_RD                           (10L)        /**< SSC signal: RD on PA10 mux C*/
#define MUX_PA10C_SSC_RD                           (2L)         /**< SSC signal line function value: RD */
#define PORT_PA10C_SSC_RD                          (1UL << 10)
#define PIN_PD24B_SSC_RF                           (120L)       /**< SSC signal: RF on PD24 mux B*/
#define MUX_PD24B_SSC_RF                           (1L)         /**< SSC signal line function value: RF */
#define PORT_PD24B_SSC_RF                          (1UL << 24)
#define PIN_PA22A_SSC_RK                           (22L)        /**< SSC signal: RK on PA22 mux A*/
#define MUX_PA22A_SSC_RK                           (0L)         /**< SSC signal line function value: RK */
#define PORT_PA22A_SSC_RK                          (1UL << 22)
#define PIN_PB5D_SSC_TD                            (37L)        /**< SSC signal: TD on PB5 mux D*/
#define MUX_PB5D_SSC_TD                            (3L)         /**< SSC signal line function value: TD */
#define PORT_PB5D_SSC_TD                           (1UL << 5)
#define PIN_PD10C_SSC_TD                           (106L)       /**< SSC signal: TD on PD10 mux C*/
#define MUX_PD10C_SSC_TD                           (2L)         /**< SSC signal line function value: TD */
#define PORT_PD10C_SSC_TD                          (1UL << 10)
#define PIN_PD26B_SSC_TD                           (122L)       /**< SSC signal: TD on PD26 mux B*/
#define MUX_PD26B_SSC_TD                           (1L)         /**< SSC signal line function value: TD */
#define PORT_PD26B_SSC_TD                          (1UL << 26)
#define PIN_PB0D_SSC_TF                            (32L)        /**< SSC signal: TF on PB0 mux D*/
#define MUX_PB0D_SSC_TF                            (3L)         /**< SSC signal line function value: TF */
#define PORT_PB0D_SSC_TF                           (1UL << 0)
#define PIN_PB1D_SSC_TK                            (33L)        /**< SSC signal: TK on PB1 mux D*/
#define MUX_PB1D_SSC_TK                            (3L)         /**< SSC signal line function value: TK */
#define PORT_PB1D_SSC_TK                           (1UL << 1)
/* ========== PIO definition for TC0 peripheral ========== */
#define PIN_PA4B_TC0_TCLK0                         (4L)         /**< TC0 signal: TCLK0 on PA4 mux B*/
#define MUX_PA4B_TC0_TCLK0                         (1L)         /**< TC0 signal line function value: TCLK0 */
#define PORT_PA4B_TC0_TCLK0                        (1UL << 4)
#define PIN_PA28B_TC0_TCLK1                        (28L)        /**< TC0 signal: TCLK1 on PA28 mux B*/
#define MUX_PA28B_TC0_TCLK1                        (1L)         /**< TC0 signal line function value: TCLK1 */
#define PORT_PA28B_TC0_TCLK1                       (1UL << 28)
#define PIN_PA29B_TC0_TCLK2                        (29L)        /**< TC0 signal: TCLK2 on PA29 mux B*/
#define MUX_PA29B_TC0_TCLK2                        (1L)         /**< TC0 signal line function value: TCLK2 */
#define PORT_PA29B_TC0_TCLK2                       (1UL << 29)
#define PIN_PA0B_TC0_TIOA0                         (0L)         /**< TC0 signal: TIOA0 on PA0 mux B*/
#define MUX_PA0B_TC0_TIOA0                         (1L)         /**< TC0 signal line function value: TIOA0 */
#define PORT_PA0B_TC0_TIOA0                        (1UL << 0)
#define PIN_PA15B_TC0_TIOA1                        (15L)        /**< TC0 signal: TIOA1 on PA15 mux B*/
#define MUX_PA15B_TC0_TIOA1                        (1L)         /**< TC0 signal line function value: TIOA1 */
#define PORT_PA15B_TC0_TIOA1                       (1UL << 15)
#define PIN_PA26B_TC0_TIOA2                        (26L)        /**< TC0 signal: TIOA2 on PA26 mux B*/
#define MUX_PA26B_TC0_TIOA2                        (1L)         /**< TC0 signal line function value: TIOA2 */
#define PORT_PA26B_TC0_TIOA2                       (1UL << 26)
#define PIN_PA1B_TC0_TIOB0                         (1L)         /**< TC0 signal: TIOB0 on PA1 mux B*/
#define MUX_PA1B_TC0_TIOB0                         (1L)         /**< TC0 signal line function value: TIOB0 */
#define PORT_PA1B_TC0_TIOB0                        (1UL << 1)
#define PIN_PA16B_TC0_TIOB1                        (16L)        /**< TC0 signal: TIOB1 on PA16 mux B*/
#define MUX_PA16B_TC0_TIOB1                        (1L)         /**< TC0 signal line function value: TIOB1 */
#define PORT_PA16B_TC0_TIOB1                       (1UL << 16)
#define PIN_PA27B_TC0_TIOB2                        (27L)        /**< TC0 signal: TIOB2 on PA27 mux B*/
#define MUX_PA27B_TC0_TIOB2                        (1L)         /**< TC0 signal line function value: TIOB2 */
#define PORT_PA27B_TC0_TIOB2                       (1UL << 27)
/* ========== PIO definition for TC3 peripheral ========== */
#define PIN_PD24C_TC3_TCLK11                       (120L)       /**< TC3 signal: TCLK11 on PD24 mux C*/
#define MUX_PD24C_TC3_TCLK11                       (2L)         /**< TC3 signal line function value: TCLK11 */
#define PORT_PD24C_TC3_TCLK11                      (1UL << 24)
#define PIN_PD21C_TC3_TIOA11                       (117L)       /**< TC3 signal: TIOA11 on PD21 mux C*/
#define MUX_PD21C_TC3_TIOA11                       (2L)         /**< TC3 signal line function value: TIOA11 */
#define PORT_PD21C_TC3_TIOA11                      (1UL << 21)
#define PIN_PD22C_TC3_TIOB11                       (118L)       /**< TC3 signal: TIOB11 on PD22 mux C*/
#define MUX_PD22C_TC3_TIOB11                       (2L)         /**< TC3 signal line function value: TIOB11 */
#define PORT_PD22C_TC3_TIOB11                      (1UL << 22)
/* ========== PIO definition for TWI0 peripheral ========== */
#define PIN_PA4A_TWI0_TWCK0                        (4L)         /**< TWI0 signal: TWCK0 on PA4 mux A*/
#define MUX_PA4A_TWI0_TWCK0                        (0L)         /**< TWI0 signal line function value: TWCK0 */
#define PORT_PA4A_TWI0_TWCK0                       (1UL << 4)
#define PIN_PA3A_TWI0_TWD0                         (3L)         /**< TWI0 signal: TWD0 on PA3 mux A*/
#define MUX_PA3A_TWI0_TWD0                         (0L)         /**< TWI0 signal line function value: TWD0 */
#define PORT_PA3A_TWI0_TWD0                        (1UL << 3)
/* ========== PIO definition for TWI1 peripheral ========== */
#define PIN_PB5A_TWI1_TWCK1                        (37L)        /**< TWI1 signal: TWCK1 on PB5 mux A*/
#define MUX_PB5A_TWI1_TWCK1                        (0L)         /**< TWI1 signal line function value: TWCK1 */
#define PORT_PB5A_TWI1_TWCK1                       (1UL << 5)
#define PIN_PB4A_TWI1_TWD1                         (36L)        /**< TWI1 signal: TWD1 on PB4 mux A*/
#define MUX_PB4A_TWI1_TWD1                         (0L)         /**< TWI1 signal line function value: TWD1 */
#define PORT_PB4A_TWI1_TWD1                        (1UL << 4)
/* ========== PIO definition for UART0 peripheral ========== */
#define PIN_PA9A_UART0_URXD0                       (9L)         /**< UART0 signal: URXD0 on PA9 mux A*/
#define MUX_PA9A_UART0_URXD0                       (0L)         /**< UART0 signal line function value: URXD0 */
#define PORT_PA9A_UART0_URXD0                      (1UL << 9)
#define PIN_PA10A_UART0_UTXD0                      (10L)        /**< UART0 signal: UTXD0 on PA10 mux A*/
#define MUX_PA10A_UART0_UTXD0                      (0L)         /**< UART0 signal line function value: UTXD0 */
#define PORT_PA10A_UART0_UTXD0                     (1UL << 10)
/* ========== PIO definition for UART1 peripheral ========== */
#define PIN_PA5C_UART1_URXD1                       (5L)         /**< UART1 signal: URXD1 on PA5 mux C*/
#define MUX_PA5C_UART1_URXD1                       (2L)         /**< UART1 signal line function value: URXD1 */
#define PORT_PA5C_UART1_URXD1                      (1UL << 5)
#define PIN_PA4C_UART1_UTXD1                       (4L)         /**< UART1 signal: UTXD1 on PA4 mux C*/
#define MUX_PA4C_UART1_UTXD1                       (2L)         /**< UART1 signal line function value: UTXD1 */
#define PORT_PA4C_UART1_UTXD1                      (1UL << 4)
#define PIN_PA6C_UART1_UTXD1                       (6L)         /**< UART1 signal: UTXD1 on PA6 mux C*/
#define MUX_PA6C_UART1_UTXD1                       (2L)         /**< UART1 signal line function value: UTXD1 */
#define PORT_PA6C_UART1_UTXD1                      (1UL << 6)
#define PIN_PD26D_UART1_UTXD1                      (122L)       /**< UART1 signal: UTXD1 on PD26 mux D*/
#define MUX_PD26D_UART1_UTXD1                      (3L)         /**< UART1 signal line function value: UTXD1 */
#define PORT_PD26D_UART1_UTXD1                     (1UL << 26)
/* ========== PIO definition for UART2 peripheral ========== */
#define PIN_PD25C_UART2_URXD2                      (121L)       /**< UART2 signal: URXD2 on PD25 mux C*/
#define MUX_PD25C_UART2_URXD2                      (2L)         /**< UART2 signal line function value: URXD2 */
#define PORT_PD25C_UART2_URXD2                     (1UL << 25)
#define PIN_PD26C_UART2_UTXD2                      (122L)       /**< UART2 signal: UTXD2 on PD26 mux C*/
#define MUX_PD26C_UART2_UTXD2                      (2L)         /**< UART2 signal line function value: UTXD2 */
#define PORT_PD26C_UART2_UTXD2                     (1UL << 26)
/* ========== PIO definition for UART3 peripheral ========== */
#define PIN_PD28A_UART3_URXD3                      (124L)       /**< UART3 signal: URXD3 on PD28 mux A*/
#define MUX_PD28A_UART3_URXD3                      (0L)         /**< UART3 signal line function value: URXD3 */
#define PORT_PD28A_UART3_URXD3                     (1UL << 28)
#define PIN_PD30A_UART3_UTXD3                      (126L)       /**< UART3 signal: UTXD3 on PD30 mux A*/
#define MUX_PD30A_UART3_UTXD3                      (0L)         /**< UART3 signal line function value: UTXD3 */
#define PORT_PD30A_UART3_UTXD3                     (1UL << 30)
#define PIN_PD31B_UART3_UTXD3                      (127L)       /**< UART3 signal: UTXD3 on PD31 mux B*/
#define MUX_PD31B_UART3_UTXD3                      (1L)         /**< UART3 signal line function value: UTXD3 */
#define PORT_PD31B_UART3_UTXD3                     (1UL << 31)
/* ========== PIO definition for UART4 peripheral ========== */
#define PIN_PD18C_UART4_URXD4                      (114L)       /**< UART4 signal: URXD4 on PD18 mux C*/
#define MUX_PD18C_UART4_URXD4                      (2L)         /**< UART4 signal line function value: URXD4 */
#define PORT_PD18C_UART4_URXD4                     (1UL << 18)
#define PIN_PD3C_UART4_UTXD4                       (99L)        /**< UART4 signal: UTXD4 on PD3 mux C*/
#define MUX_PD3C_UART4_UTXD4                       (2L)         /**< UART4 signal line function value: UTXD4 */
#define PORT_PD3C_UART4_UTXD4                      (1UL << 3)
#define PIN_PD19C_UART4_UTXD4                      (115L)       /**< UART4 signal: UTXD4 on PD19 mux C*/
#define MUX_PD19C_UART4_UTXD4                      (2L)         /**< UART4 signal line function value: UTXD4 */
#define PORT_PD19C_UART4_UTXD4                     (1UL << 19)
/* ========== PIO definition for USART0 peripheral ========== */
#define PIN_PB2C_USART0_CTS0                       (34L)        /**< USART0 signal: CTS0 on PB2 mux C*/
#define MUX_PB2C_USART0_CTS0                       (2L)         /**< USART0 signal line function value: CTS0 */
#define PORT_PB2C_USART0_CTS0                      (1UL << 2)
#define PIN_PD0D_USART0_DCD0                       (96L)        /**< USART0 signal: DCD0 on PD0 mux D*/
#define MUX_PD0D_USART0_DCD0                       (3L)         /**< USART0 signal line function value: DCD0 */
#define PORT_PD0D_USART0_DCD0                      (1UL << 0)
#define PIN_PD2D_USART0_DSR0                       (98L)        /**< USART0 signal: DSR0 on PD2 mux D*/
#define MUX_PD2D_USART0_DSR0                       (3L)         /**< USART0 signal line function value: DSR0 */
#define PORT_PD2D_USART0_DSR0                      (1UL << 2)
#define PIN_PD1D_USART0_DTR0                       (97L)        /**< USART0 signal: DTR0 on PD1 mux D*/
#define MUX_PD1D_USART0_DTR0                       (3L)         /**< USART0 signal line function value: DTR0 */
#define PORT_PD1D_USART0_DTR0                      (1UL << 1)
#define PIN_PD3D_USART0_RI0                        (99L)        /**< USART0 signal: RI0 on PD3 mux D*/
#define MUX_PD3D_USART0_RI0                        (3L)         /**< USART0 signal line function value: RI0 */
#define PORT_PD3D_USART0_RI0                       (1UL << 3)
#define PIN_PB3C_USART0_RTS0                       (35L)        /**< USART0 signal: RTS0 on PB3 mux C*/
#define MUX_PB3C_USART0_RTS0                       (2L)         /**< USART0 signal line function value: RTS0 */
#define PORT_PB3C_USART0_RTS0                      (1UL << 3)
#define PIN_PB0C_USART0_RXD0                       (32L)        /**< USART0 signal: RXD0 on PB0 mux C*/
#define MUX_PB0C_USART0_RXD0                       (2L)         /**< USART0 signal line function value: RXD0 */
#define PORT_PB0C_USART0_RXD0                      (1UL << 0)
#define PIN_PB13C_USART0_SCK0                      (45L)        /**< USART0 signal: SCK0 on PB13 mux C*/
#define MUX_PB13C_USART0_SCK0                      (2L)         /**< USART0 signal line function value: SCK0 */
#define PORT_PB13C_USART0_SCK0                     (1UL << 13)
#define PIN_PB1C_USART0_TXD0                       (33L)        /**< USART0 signal: TXD0 on PB1 mux C*/
#define MUX_PB1C_USART0_TXD0                       (2L)         /**< USART0 signal line function value: TXD0 */
#define PORT_PB1C_USART0_TXD0                      (1UL << 1)
/* ========== PIO definition for USART1 peripheral ========== */
#define PIN_PA25A_USART1_CTS1                      (25L)        /**< USART1 signal: CTS1 on PA25 mux A*/
#define MUX_PA25A_USART1_CTS1                      (0L)         /**< USART1 signal line function value: CTS1 */
#define PORT_PA25A_USART1_CTS1                     (1UL << 25)
#define PIN_PA26A_USART1_DCD1                      (26L)        /**< USART1 signal: DCD1 on PA26 mux A*/
#define MUX_PA26A_USART1_DCD1                      (0L)         /**< USART1 signal line function value: DCD1 */
#define PORT_PA26A_USART1_DCD1                     (1UL << 26)
#define PIN_PA28A_USART1_DSR1                      (28L)        /**< USART1 signal: DSR1 on PA28 mux A*/
#define MUX_PA28A_USART1_DSR1                      (0L)         /**< USART1 signal line function value: DSR1 */
#define PORT_PA28A_USART1_DSR1                     (1UL << 28)
#define PIN_PA27A_USART1_DTR1                      (27L)        /**< USART1 signal: DTR1 on PA27 mux A*/
#define MUX_PA27A_USART1_DTR1                      (0L)         /**< USART1 signal line function value: DTR1 */
#define PORT_PA27A_USART1_DTR1                     (1UL << 27)
#define PIN_PA3B_USART1_LONCOL1                    (3L)         /**< USART1 signal: LONCOL1 on PA3 mux B*/
#define MUX_PA3B_USART1_LONCOL1                    (1L)         /**< USART1 signal line function value: LONCOL1 */
#define PORT_PA3B_USART1_LONCOL1                   (1UL << 3)
#define PIN_PA29A_USART1_RI1                       (29L)        /**< USART1 signal: RI1 on PA29 mux A*/
#define MUX_PA29A_USART1_RI1                       (0L)         /**< USART1 signal line function value: RI1 */
#define PORT_PA29A_USART1_RI1                      (1UL << 29)
#define PIN_PA24A_USART1_RTS1                      (24L)        /**< USART1 signal: RTS1 on PA24 mux A*/
#define MUX_PA24A_USART1_RTS1                      (0L)         /**< USART1 signal line function value: RTS1 */
#define PORT_PA24A_USART1_RTS1                     (1UL << 24)
#define PIN_PA21A_USART1_RXD1                      (21L)        /**< USART1 signal: RXD1 on PA21 mux A*/
#define MUX_PA21A_USART1_RXD1                      (0L)         /**< USART1 signal line function value: RXD1 */
#define PORT_PA21A_USART1_RXD1                     (1UL << 21)
#define PIN_PA23A_USART1_SCK1                      (23L)        /**< USART1 signal: SCK1 on PA23 mux A*/
#define MUX_PA23A_USART1_SCK1                      (0L)         /**< USART1 signal line function value: SCK1 */
#define PORT_PA23A_USART1_SCK1                     (1UL << 23)
#define PIN_PB4D_USART1_TXD1                       (36L)        /**< USART1 signal: TXD1 on PB4 mux D*/
#define MUX_PB4D_USART1_TXD1                       (3L)         /**< USART1 signal line function value: TXD1 */
#define PORT_PB4D_USART1_TXD1                      (1UL << 4)
/* ========== PIO definition for USART2 peripheral ========== */
#define PIN_PD19B_USART2_CTS2                      (115L)       /**< USART2 signal: CTS2 on PD19 mux B*/
#define MUX_PD19B_USART2_CTS2                      (1L)         /**< USART2 signal line function value: CTS2 */
#define PORT_PD19B_USART2_CTS2                     (1UL << 19)
#define PIN_PD4D_USART2_DCD2                       (100L)       /**< USART2 signal: DCD2 on PD4 mux D*/
#define MUX_PD4D_USART2_DCD2                       (3L)         /**< USART2 signal line function value: DCD2 */
#define PORT_PD4D_USART2_DCD2                      (1UL << 4)
#define PIN_PD6D_USART2_DSR2                       (102L)       /**< USART2 signal: DSR2 on PD6 mux D*/
#define MUX_PD6D_USART2_DSR2                       (3L)         /**< USART2 signal line function value: DSR2 */
#define PORT_PD6D_USART2_DSR2                      (1UL << 6)
#define PIN_PD5D_USART2_DTR2                       (101L)       /**< USART2 signal: DTR2 on PD5 mux D*/
#define MUX_PD5D_USART2_DTR2                       (3L)         /**< USART2 signal line function value: DTR2 */
#define PORT_PD5D_USART2_DTR2                      (1UL << 5)
#define PIN_PD7D_USART2_RI2                        (103L)       /**< USART2 signal: RI2 on PD7 mux D*/
#define MUX_PD7D_USART2_RI2                        (3L)         /**< USART2 signal line function value: RI2 */
#define PORT_PD7D_USART2_RI2                       (1UL << 7)
#define PIN_PD18B_USART2_RTS2                      (114L)       /**< USART2 signal: RTS2 on PD18 mux B*/
#define MUX_PD18B_USART2_RTS2                      (1L)         /**< USART2 signal line function value: RTS2 */
#define PORT_PD18B_USART2_RTS2                     (1UL << 18)
#define PIN_PD15B_USART2_RXD2                      (111L)       /**< USART2 signal: RXD2 on PD15 mux B*/
#define MUX_PD15B_USART2_RXD2                      (1L)         /**< USART2 signal line function value: RXD2 */
#define PORT_PD15B_USART2_RXD2                     (1UL << 15)
#define PIN_PD17B_USART2_SCK2                      (113L)       /**< USART2 signal: SCK2 on PD17 mux B*/
#define MUX_PD17B_USART2_SCK2                      (1L)         /**< USART2 signal line function value: SCK2 */
#define PORT_PD17B_USART2_SCK2                     (1UL << 17)
#define PIN_PD16B_USART2_TXD2                      (112L)       /**< USART2 signal: TXD2 on PD16 mux B*/
#define MUX_PD16B_USART2_TXD2                      (1L)         /**< USART2 signal line function value: TXD2 */
#define PORT_PD16B_USART2_TXD2                     (1UL << 16)
/* ========== PIO definition for OSCILLATOR peripheral ========== */
#define PIN_PB9X1_OSCILLATOR_XIN                   (41L)        /**< OSCILLATOR signal: XIN on PB9 mux X1*/
#define PORT_PB9X1_OSCILLATOR_XIN                  (1UL << 9)
#define PIN_PB8X1_OSCILLATOR_XOUT                  (40L)        /**< OSCILLATOR signal: XOUT on PB8 mux X1*/
#define PORT_PB8X1_OSCILLATOR_XOUT                 (1UL << 8)
#define PIN_PA7X1_OSCILLATOR_XIN32                 (7L)         /**< OSCILLATOR signal: XIN32 on PA7 mux X1*/
#define PORT_PA7X1_OSCILLATOR_XIN32                (1UL << 7)
#define PIN_PA8X1_OSCILLATOR_XOUT32                (8L)         /**< OSCILLATOR signal: XOUT32 on PA8 mux X1*/
#define PORT_PA8X1_OSCILLATOR_XOUT32               (1UL << 8)
/* ========== PIO definition for PORT peripheral ========== */
#define PIN_PA3X1_PORT_PORTDC0                     (3L)         /**< PORT signal: PORTDC0 on PA3 mux X1*/
#define PORT_PA3X1_PORT_PORTDC0                    (1UL << 3)
#define PIN_PA4X1_PORT_PORTDC1                     (4L)         /**< PORT signal: PORTDC1 on PA4 mux X1*/
#define PORT_PA4X1_PORT_PORTDC1                    (1UL << 4)
#define PIN_PA5X1_PORT_PORTDC2                     (5L)         /**< PORT signal: PORTDC2 on PA5 mux X1*/
#define PORT_PA5X1_PORT_PORTDC2                    (1UL << 5)
#define PIN_PA9X1_PORT_PORTDC3                     (9L)         /**< PORT signal: PORTDC3 on PA9 mux X1*/
#define PORT_PA9X1_PORT_PORTDC3                    (1UL << 9)
#define PIN_PA10X1_PORT_PORTDC4                    (10L)        /**< PORT signal: PORTDC4 on PA10 mux X1*/
#define PORT_PA10X1_PORT_PORTDC4                   (1UL << 10)
#define PIN_PA11X1_PORT_PORTDC5                    (11L)        /**< PORT signal: PORTDC5 on PA11 mux X1*/
#define PORT_PA11X1_PORT_PORTDC5                   (1UL << 11)
#define PIN_PA12X1_PORT_PORTDC6                    (12L)        /**< PORT signal: PORTDC6 on PA12 mux X1*/
#define PORT_PA12X1_PORT_PORTDC6                   (1UL << 12)
#define PIN_PA13X1_PORT_PORTDC7                    (13L)        /**< PORT signal: PORTDC7 on PA13 mux X1*/
#define PORT_PA13X1_PORT_PORTDC7                   (1UL << 13)
#define PIN_PA14X1_PORT_PORTDCEN1                  (14L)        /**< PORT signal: PORTDCEN1 on PA14 mux X1*/
#define PORT_PA14X1_PORT_PORTDCEN1                 (1UL << 14)
#define PIN_PA21X1_PORT_PORTDCEN2                  (21L)        /**< PORT signal: PORTDCEN2 on PA21 mux X1*/
#define PORT_PA21X1_PORT_PORTDCEN2                 (1UL << 21)
#define PIN_PA22X1_PORT_PORTDCCLK                  (22L)        /**< PORT signal: PORTDCCLK on PA22 mux X1*/
#define PORT_PA22X1_PORT_PORTDCCLK                 (1UL << 22)
/* ========== PIO definition for DEBUG peripheral ========== */
#define PIN_PB4X1_DEBUG_TDI                        (36L)        /**< DEBUG signal: TDI on PB4 mux X1*/
#define PORT_PB4X1_DEBUG_TDI                       (1UL << 4)
#define PIN_PB5X1_DEBUG_TDO                        (37L)        /**< DEBUG signal: TDO on PB5 mux X1*/
#define PORT_PB5X1_DEBUG_TDO                       (1UL << 5)
#define PIN_PB5X1_DEBUG_TRACESWO                   (37L)        /**< DEBUG signal: TRACESWO on PB5 mux X1*/
#define PORT_PB5X1_DEBUG_TRACESWO                  (1UL << 5)
#define PIN_PB6X1_DEBUG_TMS                        (38L)        /**< DEBUG signal: TMS on PB6 mux X1*/
#define PORT_PB6X1_DEBUG_TMS                       (1UL << 6)
#define PIN_PB6X1_DEBUG_SWDIO                      (38L)        /**< DEBUG signal: SWDIO on PB6 mux X1*/
#define PORT_PB6X1_DEBUG_SWDIO                     (1UL << 6)
#define PIN_PB7X1_DEBUG_TCK                        (39L)        /**< DEBUG signal: TCK on PB7 mux X1*/
#define PORT_PB7X1_DEBUG_TCK                       (1UL << 7)
#define PIN_PB7X1_DEBUG_SWDCLK                     (39L)        /**< DEBUG signal: SWDCLK on PB7 mux X1*/
#define PORT_PB7X1_DEBUG_SWDCLK                    (1UL << 7)
/* ========== PIO definition for FLASH peripheral ========== */
#define PIN_PB12X1_FLASH_ERASE                     (44L)        /**< FLASH signal: ERASE on PB12 mux X1*/
#define PORT_PB12X1_FLASH_ERASE                    (1UL << 12)
/* ========== PIO definition for TRACE peripheral ========== */
#define PIN_PD8D_TRACE_TRACECLK                    (104L)       /**< TRACE signal: TRACECLK on PD8 mux D*/
#define MUX_PD8D_TRACE_TRACECLK                    (3L)         /**< TRACE signal line function value: TRACECLK */
#define PORT_PD8D_TRACE_TRACECLK                   (1UL << 8)
#define PIN_PD4C_TRACE_TRACED0                     (100L)       /**< TRACE signal: TRACED0 on PD4 mux C*/
#define MUX_PD4C_TRACE_TRACED0                     (2L)         /**< TRACE signal line function value: TRACED0 */
#define PORT_PD4C_TRACE_TRACED0                    (1UL << 4)
#define PIN_PD5C_TRACE_TRACED1                     (101L)       /**< TRACE signal: TRACED1 on PD5 mux C*/
#define MUX_PD5C_TRACE_TRACED1                     (2L)         /**< TRACE signal line function value: TRACED1 */
#define PORT_PD5C_TRACE_TRACED1                    (1UL << 5)
#define PIN_PD6C_TRACE_TRACED2                     (102L)       /**< TRACE signal: TRACED2 on PD6 mux C*/
#define MUX_PD6C_TRACE_TRACED2                     (2L)         /**< TRACE signal line function value: TRACED2 */
#define PORT_PD6C_TRACE_TRACED2                    (1UL << 6)
#define PIN_PD7C_TRACE_TRACED3                     (103L)       /**< TRACE signal: TRACED3 on PD7 mux C*/
#define MUX_PD7C_TRACE_TRACED3                     (2L)         /**< TRACE signal line function value: TRACED3 */
#define PORT_PD7C_TRACE_TRACED3                    (1UL << 7)
/* ========== PIO definition for WKUP peripheral ========== */
#define PIN_PA0X1_WKUP_WKUP0                       (0L)         /**< WKUP signal: WKUP0 on PA0 mux X1*/
#define PORT_PA0X1_WKUP_WKUP0                      (1UL << 0)
#define PIN_PA1X1_WKUP_WKUP1                       (1L)         /**< WKUP signal: WKUP1 on PA1 mux X1*/
#define PORT_PA1X1_WKUP_WKUP1                      (1UL << 1)
#define PIN_PA2X1_WKUP_WKUP2                       (2L)         /**< WKUP signal: WKUP2 on PA2 mux X1*/
#define PORT_PA2X1_WKUP_WKUP2                      (1UL << 2)
#define PIN_PA4X1_WKUP_WKUP3                       (4L)         /**< WKUP signal: WKUP3 on PA4 mux X1*/
#define PORT_PA4X1_WKUP_WKUP3                      (1UL << 4)
#define PIN_PA5X1_WKUP_WKUP4                       (5L)         /**< WKUP signal: WKUP4 on PA5 mux X1*/
#define PORT_PA5X1_WKUP_WKUP4                      (1UL << 5)
#define PIN_PD28X1_WKUP_WKUP5                      (124L)       /**< WKUP signal: WKUP5 on PD28 mux X1*/
#define PORT_PD28X1_WKUP_WKUP5                     (1UL << 28)
#define PIN_PA9X1_WKUP_WKUP6                       (9L)         /**< WKUP signal: WKUP6 on PA9 mux X1*/
#define PORT_PA9X1_WKUP_WKUP6                      (1UL << 9)
#define PIN_PA11X1_WKUP_WKUP7                      (11L)        /**< WKUP signal: WKUP7 on PA11 mux X1*/
#define PORT_PA11X1_WKUP_WKUP7                     (1UL << 11)
#define PIN_PA14X1_WKUP_WKUP8                      (14L)        /**< WKUP signal: WKUP8 on PA14 mux X1*/
#define PORT_PA14X1_WKUP_WKUP8                     (1UL << 14)
#define PIN_PA19X1_WKUP_WKUP9                      (19L)        /**< WKUP signal: WKUP9 on PA19 mux X1*/
#define PORT_PA19X1_WKUP_WKUP9                     (1UL << 19)
#define PIN_PA20X1_WKUP_WKUP10                     (20L)        /**< WKUP signal: WKUP10 on PA20 mux X1*/
#define PORT_PA20X1_WKUP_WKUP10                    (1UL << 20)
#define PIN_PA30X1_WKUP_WKUP11                     (30L)        /**< WKUP signal: WKUP11 on PA30 mux X1*/
#define PORT_PA30X1_WKUP_WKUP11                    (1UL << 30)
#define PIN_PB3X1_WKUP_WKUP12                      (35L)        /**< WKUP signal: WKUP12 on PB3 mux X1*/
#define PORT_PB3X1_WKUP_WKUP12                     (1UL << 3)
#define PIN_PB5X1_WKUP_WKUP13                      (37L)        /**< WKUP signal: WKUP13 on PB5 mux X1*/
#define PORT_PB5X1_WKUP_WKUP13                     (1UL << 5)

#endif /* _PIC32CZ2038CA70064_GPIO_H_ */
