/**
 * \brief Component description for PIC32CZ/CA70 TC
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
#ifndef _PIC32CZ_CA70_TC_COMPONENT_H_
#define _PIC32CZ_CA70_TC_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_TC Timer Counter
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR TC */
/* ========================================================================== */

/* -------- TC_CCR : (TC Offset: 0x00) (/W 32) Channel Control Register (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t CLKEN:1;                   /**< bit:      0  Counter Clock Enable Command                  */
    uint32_t CLKDIS:1;                  /**< bit:      1  Counter Clock Disable Command                 */
    uint32_t SWTRG:1;                   /**< bit:      2  Software Trigger Command                      */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  uint32_t w;
} __TC_CCR_bits_t;

#define TC_CCR_CLKEN_Pos                      (0)                                            /**< (TC_CCR) Counter Clock Enable Command Position */
#define TC_CCR_CLKEN_Msk                      (0x1U << TC_CCR_CLKEN_Pos)                     /**< (TC_CCR) Counter Clock Enable Command Mask */
#define TC_CCR_CLKDIS_Pos                     (1)                                            /**< (TC_CCR) Counter Clock Disable Command Position */
#define TC_CCR_CLKDIS_Msk                     (0x1U << TC_CCR_CLKDIS_Pos)                    /**< (TC_CCR) Counter Clock Disable Command Mask */
#define TC_CCR_SWTRG_Pos                      (2)                                            /**< (TC_CCR) Software Trigger Command Position */
#define TC_CCR_SWTRG_Msk                      (0x1U << TC_CCR_SWTRG_Pos)                     /**< (TC_CCR) Software Trigger Command Mask */
#define TC_CCR_Msk                            (0x00000007UL)                                 /**< (TC_CCR) Register Mask  */

/* -------- TC_CMR : (TC Offset: 0x04) (R/W 32) Channel Mode Register (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t TCCLKS:3;                  /**< bit:   0..2  Clock Selection                               */
    uint32_t CLKI:1;                    /**< bit:      3  Clock Invert                                  */
    uint32_t BURST:2;                   /**< bit:   4..5  Burst Signal Selection                        */
    uint32_t :9;                        /**< bit:  6..14  Reserved                                      */
    uint32_t WAVE:1;                    /**< bit:     15  Waveform Mode                                 */
    uint32_t :16;                       /**< bit: 16..31  Reserved                                      */
  };
  struct
  { // Capture mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t LDBSTOP:1;                 /**< bit:      6  Counter Clock Stopped with RB Loading         */
    uint32_t LDBDIS:1;                  /**< bit:      7  Counter Clock Disable with RB Loading         */
    uint32_t ETRGEDG:2;                 /**< bit:   8..9  External Trigger Edge Selection               */
    uint32_t ABETRG:1;                  /**< bit:     10  TIOAx or TIOBx External Trigger Selection     */
    uint32_t :3;                        /**< bit: 11..13  Reserved                                      */
    uint32_t CPCTRG:1;                  /**< bit:     14  RC Compare Trigger Enable                     */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t LDRA:2;                    /**< bit: 16..17  RA Loading Edge Selection                     */
    uint32_t LDRB:2;                    /**< bit: 18..19  RB Loading Edge Selection                     */
    uint32_t SBSMPLR:3;                 /**< bit: 20..22  Loading Edge Subsampling Ratio                */
    uint32_t :9;                        /**< bit: 23..31  Reserved                                      */
  };
  struct
  { // Waveform mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t CPCSTOP:1;                 /**< bit:      6  Counter Clock Stopped with RC Compare         */
    uint32_t CPCDIS:1;                  /**< bit:      7  Counter Clock Disable with RC Loading         */
    uint32_t EEVTEDG:2;                 /**< bit:   8..9  External Event Edge Selection                 */
    uint32_t EEVT:2;                    /**< bit: 10..11  External Event Selection                      */
    uint32_t ENETRG:1;                  /**< bit:     12  External Event Trigger Enable                 */
    uint32_t WAVSEL:2;                  /**< bit: 13..14  Waveform Selection                            */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t ACPA:2;                    /**< bit: 16..17  RA Compare Effect on TIOAx                    */
    uint32_t ACPC:2;                    /**< bit: 18..19  RC Compare Effect on TIOAx                    */
    uint32_t AEEVT:2;                   /**< bit: 20..21  External Event Effect on TIOAx                */
    uint32_t ASWTRG:2;                  /**< bit: 22..23  Software Trigger Effect on TIOAx              */
    uint32_t BCPB:2;                    /**< bit: 24..25  RB Compare Effect on TIOBx                    */
    uint32_t BCPC:2;                    /**< bit: 26..27  RC Compare Effect on TIOBx                    */
    uint32_t BEEVT:2;                   /**< bit: 28..29  External Event Effect on TIOBx                */
    uint32_t BSWTRG:2;                  /**< bit: 30..31  Software Trigger Effect on TIOBx              */
  };
  uint32_t w;
} __TC_CMR_bits_t;

#define TC_CMR_TCCLKS_Pos                     (0)                                            /**< (TC_CMR) Clock Selection Position */
#define TC_CMR_TCCLKS_Msk                     (0x7U << TC_CMR_TCCLKS_Pos)                    /**< (TC_CMR) Clock Selection Mask */
#define TC_CMR_TCCLKS(value)                  (TC_CMR_TCCLKS_Msk & ((value) << TC_CMR_TCCLKS_Pos))
#define   TC_CMR_TCCLKS_TIMER_CLOCK1_Val      (0x0U)                                         /**< (TC_CMR) Clock selected: internal PCK6 clock signal (from PMC)  */
#define   TC_CMR_TCCLKS_TIMER_CLOCK2_Val      (0x1U)                                         /**< (TC_CMR) Clock selected: internal MCK/8 clock signal (from PMC)  */
#define   TC_CMR_TCCLKS_TIMER_CLOCK3_Val      (0x2U)                                         /**< (TC_CMR) Clock selected: internal MCK/32 clock signal (from PMC)  */
#define   TC_CMR_TCCLKS_TIMER_CLOCK4_Val      (0x3U)                                         /**< (TC_CMR) Clock selected: internal MCK/128 clock signal (from PMC)  */
#define   TC_CMR_TCCLKS_TIMER_CLOCK5_Val      (0x4U)                                         /**< (TC_CMR) Clock selected: internal SLCK clock signal (from PMC)  */
#define   TC_CMR_TCCLKS_XC0_Val               (0x5U)                                         /**< (TC_CMR) Clock selected: XC0  */
#define   TC_CMR_TCCLKS_XC1_Val               (0x6U)                                         /**< (TC_CMR) Clock selected: XC1  */
#define   TC_CMR_TCCLKS_XC2_Val               (0x7U)                                         /**< (TC_CMR) Clock selected: XC2  */
#define TC_CMR_TCCLKS_TIMER_CLOCK1            (TC_CMR_TCCLKS_TIMER_CLOCK1_Val << TC_CMR_TCCLKS_Pos)  /**< (TC_CMR) Clock selected: internal PCK6 clock signal (from PMC) Position  */
#define TC_CMR_TCCLKS_TIMER_CLOCK2            (TC_CMR_TCCLKS_TIMER_CLOCK2_Val << TC_CMR_TCCLKS_Pos)  /**< (TC_CMR) Clock selected: internal MCK/8 clock signal (from PMC) Position  */
#define TC_CMR_TCCLKS_TIMER_CLOCK3            (TC_CMR_TCCLKS_TIMER_CLOCK3_Val << TC_CMR_TCCLKS_Pos)  /**< (TC_CMR) Clock selected: internal MCK/32 clock signal (from PMC) Position  */
#define TC_CMR_TCCLKS_TIMER_CLOCK4            (TC_CMR_TCCLKS_TIMER_CLOCK4_Val << TC_CMR_TCCLKS_Pos)  /**< (TC_CMR) Clock selected: internal MCK/128 clock signal (from PMC) Position  */
#define TC_CMR_TCCLKS_TIMER_CLOCK5            (TC_CMR_TCCLKS_TIMER_CLOCK5_Val << TC_CMR_TCCLKS_Pos)  /**< (TC_CMR) Clock selected: internal SLCK clock signal (from PMC) Position  */
#define TC_CMR_TCCLKS_XC0                     (TC_CMR_TCCLKS_XC0_Val << TC_CMR_TCCLKS_Pos)   /**< (TC_CMR) Clock selected: XC0 Position  */
#define TC_CMR_TCCLKS_XC1                     (TC_CMR_TCCLKS_XC1_Val << TC_CMR_TCCLKS_Pos)   /**< (TC_CMR) Clock selected: XC1 Position  */
#define TC_CMR_TCCLKS_XC2                     (TC_CMR_TCCLKS_XC2_Val << TC_CMR_TCCLKS_Pos)   /**< (TC_CMR) Clock selected: XC2 Position  */
#define TC_CMR_CLKI_Pos                       (3)                                            /**< (TC_CMR) Clock Invert Position */
#define TC_CMR_CLKI_Msk                       (0x1U << TC_CMR_CLKI_Pos)                      /**< (TC_CMR) Clock Invert Mask */
#define TC_CMR_BURST_Pos                      (4)                                            /**< (TC_CMR) Burst Signal Selection Position */
#define TC_CMR_BURST_Msk                      (0x3U << TC_CMR_BURST_Pos)                     /**< (TC_CMR) Burst Signal Selection Mask */
#define TC_CMR_BURST(value)                   (TC_CMR_BURST_Msk & ((value) << TC_CMR_BURST_Pos))
#define   TC_CMR_BURST_NONE_Val               (0x0U)                                         /**< (TC_CMR) The clock is not gated by an external signal.  */
#define   TC_CMR_BURST_XC0_Val                (0x1U)                                         /**< (TC_CMR) XC0 is ANDed with the selected clock.  */
#define   TC_CMR_BURST_XC1_Val                (0x2U)                                         /**< (TC_CMR) XC1 is ANDed with the selected clock.  */
#define   TC_CMR_BURST_XC2_Val                (0x3U)                                         /**< (TC_CMR) XC2 is ANDed with the selected clock.  */
#define TC_CMR_BURST_NONE                     (TC_CMR_BURST_NONE_Val << TC_CMR_BURST_Pos)    /**< (TC_CMR) The clock is not gated by an external signal. Position  */
#define TC_CMR_BURST_XC0                      (TC_CMR_BURST_XC0_Val << TC_CMR_BURST_Pos)     /**< (TC_CMR) XC0 is ANDed with the selected clock. Position  */
#define TC_CMR_BURST_XC1                      (TC_CMR_BURST_XC1_Val << TC_CMR_BURST_Pos)     /**< (TC_CMR) XC1 is ANDed with the selected clock. Position  */
#define TC_CMR_BURST_XC2                      (TC_CMR_BURST_XC2_Val << TC_CMR_BURST_Pos)     /**< (TC_CMR) XC2 is ANDed with the selected clock. Position  */
#define TC_CMR_WAVE_Pos                       (15)                                           /**< (TC_CMR) Waveform Mode Position */
#define TC_CMR_WAVE_Msk                       (0x1U << TC_CMR_WAVE_Pos)                      /**< (TC_CMR) Waveform Mode Mask */
/* Capture mode */
#define TC_CMR_LDBSTOP_Pos                    (6)                                            /**< (TC_CMR) Counter Clock Stopped with RB Loading Position */
#define TC_CMR_LDBSTOP_Msk                    (0x1U << TC_CMR_LDBSTOP_Pos)                   /**< (TC_CMR) Counter Clock Stopped with RB Loading Mask */
#define TC_CMR_LDBDIS_Pos                     (7)                                            /**< (TC_CMR) Counter Clock Disable with RB Loading Position */
#define TC_CMR_LDBDIS_Msk                     (0x1U << TC_CMR_LDBDIS_Pos)                    /**< (TC_CMR) Counter Clock Disable with RB Loading Mask */
#define TC_CMR_ETRGEDG_Pos                    (8)                                            /**< (TC_CMR) External Trigger Edge Selection Position */
#define TC_CMR_ETRGEDG_Msk                    (0x3U << TC_CMR_ETRGEDG_Pos)                   /**< (TC_CMR) External Trigger Edge Selection Mask */
#define TC_CMR_ETRGEDG(value)                 (TC_CMR_ETRGEDG_Msk & ((value) << TC_CMR_ETRGEDG_Pos))
#define   TC_CMR_ETRGEDG_NONE_Val             (0x0U)                                         /**< (TC_CMR) The clock is not gated by an external signal.  */
#define   TC_CMR_ETRGEDG_RISING_Val           (0x1U)                                         /**< (TC_CMR) Rising edge  */
#define   TC_CMR_ETRGEDG_FALLING_Val          (0x2U)                                         /**< (TC_CMR) Falling edge  */
#define   TC_CMR_ETRGEDG_EDGE_Val             (0x3U)                                         /**< (TC_CMR) Each edge  */
#define TC_CMR_ETRGEDG_NONE                   (TC_CMR_ETRGEDG_NONE_Val << TC_CMR_ETRGEDG_Pos)  /**< (TC_CMR) The clock is not gated by an external signal. Position  */
#define TC_CMR_ETRGEDG_RISING                 (TC_CMR_ETRGEDG_RISING_Val << TC_CMR_ETRGEDG_Pos)  /**< (TC_CMR) Rising edge Position  */
#define TC_CMR_ETRGEDG_FALLING                (TC_CMR_ETRGEDG_FALLING_Val << TC_CMR_ETRGEDG_Pos)  /**< (TC_CMR) Falling edge Position  */
#define TC_CMR_ETRGEDG_EDGE                   (TC_CMR_ETRGEDG_EDGE_Val << TC_CMR_ETRGEDG_Pos)  /**< (TC_CMR) Each edge Position  */
#define TC_CMR_ABETRG_Pos                     (10)                                           /**< (TC_CMR) TIOAx or TIOBx External Trigger Selection Position */
#define TC_CMR_ABETRG_Msk                     (0x1U << TC_CMR_ABETRG_Pos)                    /**< (TC_CMR) TIOAx or TIOBx External Trigger Selection Mask */
#define TC_CMR_CPCTRG_Pos                     (14)                                           /**< (TC_CMR) RC Compare Trigger Enable Position */
#define TC_CMR_CPCTRG_Msk                     (0x1U << TC_CMR_CPCTRG_Pos)                    /**< (TC_CMR) RC Compare Trigger Enable Mask */
#define TC_CMR_LDRA_Pos                       (16)                                           /**< (TC_CMR) RA Loading Edge Selection Position */
#define TC_CMR_LDRA_Msk                       (0x3U << TC_CMR_LDRA_Pos)                      /**< (TC_CMR) RA Loading Edge Selection Mask */
#define TC_CMR_LDRA(value)                    (TC_CMR_LDRA_Msk & ((value) << TC_CMR_LDRA_Pos))
#define   TC_CMR_LDRA_NONE_Val                (0x0U)                                         /**< (TC_CMR) None  */
#define   TC_CMR_LDRA_RISING_Val              (0x1U)                                         /**< (TC_CMR) Rising edge of TIOAx  */
#define   TC_CMR_LDRA_FALLING_Val             (0x2U)                                         /**< (TC_CMR) Falling edge of TIOAx  */
#define   TC_CMR_LDRA_EDGE_Val                (0x3U)                                         /**< (TC_CMR) Each edge of TIOAx  */
#define TC_CMR_LDRA_NONE                      (TC_CMR_LDRA_NONE_Val << TC_CMR_LDRA_Pos)      /**< (TC_CMR) None Position  */
#define TC_CMR_LDRA_RISING                    (TC_CMR_LDRA_RISING_Val << TC_CMR_LDRA_Pos)    /**< (TC_CMR) Rising edge of TIOAx Position  */
#define TC_CMR_LDRA_FALLING                   (TC_CMR_LDRA_FALLING_Val << TC_CMR_LDRA_Pos)   /**< (TC_CMR) Falling edge of TIOAx Position  */
#define TC_CMR_LDRA_EDGE                      (TC_CMR_LDRA_EDGE_Val << TC_CMR_LDRA_Pos)      /**< (TC_CMR) Each edge of TIOAx Position  */
#define TC_CMR_LDRB_Pos                       (18)                                           /**< (TC_CMR) RB Loading Edge Selection Position */
#define TC_CMR_LDRB_Msk                       (0x3U << TC_CMR_LDRB_Pos)                      /**< (TC_CMR) RB Loading Edge Selection Mask */
#define TC_CMR_LDRB(value)                    (TC_CMR_LDRB_Msk & ((value) << TC_CMR_LDRB_Pos))
#define   TC_CMR_LDRB_NONE_Val                (0x0U)                                         /**< (TC_CMR) None  */
#define   TC_CMR_LDRB_RISING_Val              (0x1U)                                         /**< (TC_CMR) Rising edge of TIOAx  */
#define   TC_CMR_LDRB_FALLING_Val             (0x2U)                                         /**< (TC_CMR) Falling edge of TIOAx  */
#define   TC_CMR_LDRB_EDGE_Val                (0x3U)                                         /**< (TC_CMR) Each edge of TIOAx  */
#define TC_CMR_LDRB_NONE                      (TC_CMR_LDRB_NONE_Val << TC_CMR_LDRB_Pos)      /**< (TC_CMR) None Position  */
#define TC_CMR_LDRB_RISING                    (TC_CMR_LDRB_RISING_Val << TC_CMR_LDRB_Pos)    /**< (TC_CMR) Rising edge of TIOAx Position  */
#define TC_CMR_LDRB_FALLING                   (TC_CMR_LDRB_FALLING_Val << TC_CMR_LDRB_Pos)   /**< (TC_CMR) Falling edge of TIOAx Position  */
#define TC_CMR_LDRB_EDGE                      (TC_CMR_LDRB_EDGE_Val << TC_CMR_LDRB_Pos)      /**< (TC_CMR) Each edge of TIOAx Position  */
#define TC_CMR_SBSMPLR_Pos                    (20)                                           /**< (TC_CMR) Loading Edge Subsampling Ratio Position */
#define TC_CMR_SBSMPLR_Msk                    (0x7U << TC_CMR_SBSMPLR_Pos)                   /**< (TC_CMR) Loading Edge Subsampling Ratio Mask */
#define TC_CMR_SBSMPLR(value)                 (TC_CMR_SBSMPLR_Msk & ((value) << TC_CMR_SBSMPLR_Pos))
#define   TC_CMR_SBSMPLR_ONE_Val              (0x0U)                                         /**< (TC_CMR) Load a Capture Register each selected edge  */
#define   TC_CMR_SBSMPLR_HALF_Val             (0x1U)                                         /**< (TC_CMR) Load a Capture Register every 2 selected edges  */
#define   TC_CMR_SBSMPLR_FOURTH_Val           (0x2U)                                         /**< (TC_CMR) Load a Capture Register every 4 selected edges  */
#define   TC_CMR_SBSMPLR_EIGHTH_Val           (0x3U)                                         /**< (TC_CMR) Load a Capture Register every 8 selected edges  */
#define   TC_CMR_SBSMPLR_SIXTEENTH_Val        (0x4U)                                         /**< (TC_CMR) Load a Capture Register every 16 selected edges  */
#define TC_CMR_SBSMPLR_ONE                    (TC_CMR_SBSMPLR_ONE_Val << TC_CMR_SBSMPLR_Pos)  /**< (TC_CMR) Load a Capture Register each selected edge Position  */
#define TC_CMR_SBSMPLR_HALF                   (TC_CMR_SBSMPLR_HALF_Val << TC_CMR_SBSMPLR_Pos)  /**< (TC_CMR) Load a Capture Register every 2 selected edges Position  */
#define TC_CMR_SBSMPLR_FOURTH                 (TC_CMR_SBSMPLR_FOURTH_Val << TC_CMR_SBSMPLR_Pos)  /**< (TC_CMR) Load a Capture Register every 4 selected edges Position  */
#define TC_CMR_SBSMPLR_EIGHTH                 (TC_CMR_SBSMPLR_EIGHTH_Val << TC_CMR_SBSMPLR_Pos)  /**< (TC_CMR) Load a Capture Register every 8 selected edges Position  */
#define TC_CMR_SBSMPLR_SIXTEENTH              (TC_CMR_SBSMPLR_SIXTEENTH_Val << TC_CMR_SBSMPLR_Pos)  /**< (TC_CMR) Load a Capture Register every 16 selected edges Position  */
/* Waveform mode */
#define TC_CMR_CPCSTOP_Pos                    (6)                                            /**< (TC_CMR) Counter Clock Stopped with RC Compare Position */
#define TC_CMR_CPCSTOP_Msk                    (0x1U << TC_CMR_CPCSTOP_Pos)                   /**< (TC_CMR) Counter Clock Stopped with RC Compare Mask */
#define TC_CMR_CPCDIS_Pos                     (7)                                            /**< (TC_CMR) Counter Clock Disable with RC Loading Position */
#define TC_CMR_CPCDIS_Msk                     (0x1U << TC_CMR_CPCDIS_Pos)                    /**< (TC_CMR) Counter Clock Disable with RC Loading Mask */
#define TC_CMR_EEVTEDG_Pos                    (8)                                            /**< (TC_CMR) External Event Edge Selection Position */
#define TC_CMR_EEVTEDG_Msk                    (0x3U << TC_CMR_EEVTEDG_Pos)                   /**< (TC_CMR) External Event Edge Selection Mask */
#define TC_CMR_EEVTEDG(value)                 (TC_CMR_EEVTEDG_Msk & ((value) << TC_CMR_EEVTEDG_Pos))
#define   TC_CMR_EEVTEDG_NONE_Val             (0x0U)                                         /**< (TC_CMR) None  */
#define   TC_CMR_EEVTEDG_RISING_Val           (0x1U)                                         /**< (TC_CMR) Rising edge  */
#define   TC_CMR_EEVTEDG_FALLING_Val          (0x2U)                                         /**< (TC_CMR) Falling edge  */
#define   TC_CMR_EEVTEDG_EDGE_Val             (0x3U)                                         /**< (TC_CMR) Each edges  */
#define TC_CMR_EEVTEDG_NONE                   (TC_CMR_EEVTEDG_NONE_Val << TC_CMR_EEVTEDG_Pos)  /**< (TC_CMR) None Position  */
#define TC_CMR_EEVTEDG_RISING                 (TC_CMR_EEVTEDG_RISING_Val << TC_CMR_EEVTEDG_Pos)  /**< (TC_CMR) Rising edge Position  */
#define TC_CMR_EEVTEDG_FALLING                (TC_CMR_EEVTEDG_FALLING_Val << TC_CMR_EEVTEDG_Pos)  /**< (TC_CMR) Falling edge Position  */
#define TC_CMR_EEVTEDG_EDGE                   (TC_CMR_EEVTEDG_EDGE_Val << TC_CMR_EEVTEDG_Pos)  /**< (TC_CMR) Each edges Position  */
#define TC_CMR_EEVT_Pos                       (10)                                           /**< (TC_CMR) External Event Selection Position */
#define TC_CMR_EEVT_Msk                       (0x3U << TC_CMR_EEVT_Pos)                      /**< (TC_CMR) External Event Selection Mask */
#define TC_CMR_EEVT(value)                    (TC_CMR_EEVT_Msk & ((value) << TC_CMR_EEVT_Pos))
#define   TC_CMR_EEVT_TIOB_Val                (0x0U)                                         /**< (TC_CMR) TIOB  */
#define   TC_CMR_EEVT_XC0_Val                 (0x1U)                                         /**< (TC_CMR) XC0  */
#define   TC_CMR_EEVT_XC1_Val                 (0x2U)                                         /**< (TC_CMR) XC1  */
#define   TC_CMR_EEVT_XC2_Val                 (0x3U)                                         /**< (TC_CMR) XC2  */
#define TC_CMR_EEVT_TIOB                      (TC_CMR_EEVT_TIOB_Val << TC_CMR_EEVT_Pos)      /**< (TC_CMR) TIOB Position  */
#define TC_CMR_EEVT_XC0                       (TC_CMR_EEVT_XC0_Val << TC_CMR_EEVT_Pos)       /**< (TC_CMR) XC0 Position  */
#define TC_CMR_EEVT_XC1                       (TC_CMR_EEVT_XC1_Val << TC_CMR_EEVT_Pos)       /**< (TC_CMR) XC1 Position  */
#define TC_CMR_EEVT_XC2                       (TC_CMR_EEVT_XC2_Val << TC_CMR_EEVT_Pos)       /**< (TC_CMR) XC2 Position  */
#define TC_CMR_ENETRG_Pos                     (12)                                           /**< (TC_CMR) External Event Trigger Enable Position */
#define TC_CMR_ENETRG_Msk                     (0x1U << TC_CMR_ENETRG_Pos)                    /**< (TC_CMR) External Event Trigger Enable Mask */
#define TC_CMR_WAVSEL_Pos                     (13)                                           /**< (TC_CMR) Waveform Selection Position */
#define TC_CMR_WAVSEL_Msk                     (0x3U << TC_CMR_WAVSEL_Pos)                    /**< (TC_CMR) Waveform Selection Mask */
#define TC_CMR_WAVSEL(value)                  (TC_CMR_WAVSEL_Msk & ((value) << TC_CMR_WAVSEL_Pos))
#define   TC_CMR_WAVSEL_UP_Val                (0x0U)                                         /**< (TC_CMR) UP mode without automatic trigger on RC Compare  */
#define   TC_CMR_WAVSEL_UPDOWN_Val            (0x1U)                                         /**< (TC_CMR) UPDOWN mode without automatic trigger on RC Compare  */
#define   TC_CMR_WAVSEL_UP_RC_Val             (0x2U)                                         /**< (TC_CMR) UP mode with automatic trigger on RC Compare  */
#define   TC_CMR_WAVSEL_UPDOWN_RC_Val         (0x3U)                                         /**< (TC_CMR) UPDOWN mode with automatic trigger on RC Compare  */
#define TC_CMR_WAVSEL_UP                      (TC_CMR_WAVSEL_UP_Val << TC_CMR_WAVSEL_Pos)    /**< (TC_CMR) UP mode without automatic trigger on RC Compare Position  */
#define TC_CMR_WAVSEL_UPDOWN                  (TC_CMR_WAVSEL_UPDOWN_Val << TC_CMR_WAVSEL_Pos)  /**< (TC_CMR) UPDOWN mode without automatic trigger on RC Compare Position  */
#define TC_CMR_WAVSEL_UP_RC                   (TC_CMR_WAVSEL_UP_RC_Val << TC_CMR_WAVSEL_Pos)  /**< (TC_CMR) UP mode with automatic trigger on RC Compare Position  */
#define TC_CMR_WAVSEL_UPDOWN_RC               (TC_CMR_WAVSEL_UPDOWN_RC_Val << TC_CMR_WAVSEL_Pos)  /**< (TC_CMR) UPDOWN mode with automatic trigger on RC Compare Position  */
#define TC_CMR_ACPA_Pos                       (16)                                           /**< (TC_CMR) RA Compare Effect on TIOAx Position */
#define TC_CMR_ACPA_Msk                       (0x3U << TC_CMR_ACPA_Pos)                      /**< (TC_CMR) RA Compare Effect on TIOAx Mask */
#define TC_CMR_ACPA(value)                    (TC_CMR_ACPA_Msk & ((value) << TC_CMR_ACPA_Pos))
#define   TC_CMR_ACPA_NONE_Val                (0x0U)                                         /**< (TC_CMR) NONE  */
#define   TC_CMR_ACPA_SET_Val                 (0x1U)                                         /**< (TC_CMR) SET  */
#define   TC_CMR_ACPA_CLEAR_Val               (0x2U)                                         /**< (TC_CMR) CLEAR  */
#define   TC_CMR_ACPA_TOGGLE_Val              (0x3U)                                         /**< (TC_CMR) TOGGLE  */
#define TC_CMR_ACPA_NONE                      (TC_CMR_ACPA_NONE_Val << TC_CMR_ACPA_Pos)      /**< (TC_CMR) NONE Position  */
#define TC_CMR_ACPA_SET                       (TC_CMR_ACPA_SET_Val << TC_CMR_ACPA_Pos)       /**< (TC_CMR) SET Position  */
#define TC_CMR_ACPA_CLEAR                     (TC_CMR_ACPA_CLEAR_Val << TC_CMR_ACPA_Pos)     /**< (TC_CMR) CLEAR Position  */
#define TC_CMR_ACPA_TOGGLE                    (TC_CMR_ACPA_TOGGLE_Val << TC_CMR_ACPA_Pos)    /**< (TC_CMR) TOGGLE Position  */
#define TC_CMR_ACPC_Pos                       (18)                                           /**< (TC_CMR) RC Compare Effect on TIOAx Position */
#define TC_CMR_ACPC_Msk                       (0x3U << TC_CMR_ACPC_Pos)                      /**< (TC_CMR) RC Compare Effect on TIOAx Mask */
#define TC_CMR_ACPC(value)                    (TC_CMR_ACPC_Msk & ((value) << TC_CMR_ACPC_Pos))
#define   TC_CMR_ACPC_NONE_Val                (0x0U)                                         /**< (TC_CMR) NONE  */
#define   TC_CMR_ACPC_SET_Val                 (0x1U)                                         /**< (TC_CMR) SET  */
#define   TC_CMR_ACPC_CLEAR_Val               (0x2U)                                         /**< (TC_CMR) CLEAR  */
#define   TC_CMR_ACPC_TOGGLE_Val              (0x3U)                                         /**< (TC_CMR) TOGGLE  */
#define TC_CMR_ACPC_NONE                      (TC_CMR_ACPC_NONE_Val << TC_CMR_ACPC_Pos)      /**< (TC_CMR) NONE Position  */
#define TC_CMR_ACPC_SET                       (TC_CMR_ACPC_SET_Val << TC_CMR_ACPC_Pos)       /**< (TC_CMR) SET Position  */
#define TC_CMR_ACPC_CLEAR                     (TC_CMR_ACPC_CLEAR_Val << TC_CMR_ACPC_Pos)     /**< (TC_CMR) CLEAR Position  */
#define TC_CMR_ACPC_TOGGLE                    (TC_CMR_ACPC_TOGGLE_Val << TC_CMR_ACPC_Pos)    /**< (TC_CMR) TOGGLE Position  */
#define TC_CMR_AEEVT_Pos                      (20)                                           /**< (TC_CMR) External Event Effect on TIOAx Position */
#define TC_CMR_AEEVT_Msk                      (0x3U << TC_CMR_AEEVT_Pos)                     /**< (TC_CMR) External Event Effect on TIOAx Mask */
#define TC_CMR_AEEVT(value)                   (TC_CMR_AEEVT_Msk & ((value) << TC_CMR_AEEVT_Pos))
#define   TC_CMR_AEEVT_NONE_Val               (0x0U)                                         /**< (TC_CMR) NONE  */
#define   TC_CMR_AEEVT_SET_Val                (0x1U)                                         /**< (TC_CMR) SET  */
#define   TC_CMR_AEEVT_CLEAR_Val              (0x2U)                                         /**< (TC_CMR) CLEAR  */
#define   TC_CMR_AEEVT_TOGGLE_Val             (0x3U)                                         /**< (TC_CMR) TOGGLE  */
#define TC_CMR_AEEVT_NONE                     (TC_CMR_AEEVT_NONE_Val << TC_CMR_AEEVT_Pos)    /**< (TC_CMR) NONE Position  */
#define TC_CMR_AEEVT_SET                      (TC_CMR_AEEVT_SET_Val << TC_CMR_AEEVT_Pos)     /**< (TC_CMR) SET Position  */
#define TC_CMR_AEEVT_CLEAR                    (TC_CMR_AEEVT_CLEAR_Val << TC_CMR_AEEVT_Pos)   /**< (TC_CMR) CLEAR Position  */
#define TC_CMR_AEEVT_TOGGLE                   (TC_CMR_AEEVT_TOGGLE_Val << TC_CMR_AEEVT_Pos)  /**< (TC_CMR) TOGGLE Position  */
#define TC_CMR_ASWTRG_Pos                     (22)                                           /**< (TC_CMR) Software Trigger Effect on TIOAx Position */
#define TC_CMR_ASWTRG_Msk                     (0x3U << TC_CMR_ASWTRG_Pos)                    /**< (TC_CMR) Software Trigger Effect on TIOAx Mask */
#define TC_CMR_ASWTRG(value)                  (TC_CMR_ASWTRG_Msk & ((value) << TC_CMR_ASWTRG_Pos))
#define   TC_CMR_ASWTRG_NONE_Val              (0x0U)                                         /**< (TC_CMR) NONE  */
#define   TC_CMR_ASWTRG_SET_Val               (0x1U)                                         /**< (TC_CMR) SET  */
#define   TC_CMR_ASWTRG_CLEAR_Val             (0x2U)                                         /**< (TC_CMR) CLEAR  */
#define   TC_CMR_ASWTRG_TOGGLE_Val            (0x3U)                                         /**< (TC_CMR) TOGGLE  */
#define TC_CMR_ASWTRG_NONE                    (TC_CMR_ASWTRG_NONE_Val << TC_CMR_ASWTRG_Pos)  /**< (TC_CMR) NONE Position  */
#define TC_CMR_ASWTRG_SET                     (TC_CMR_ASWTRG_SET_Val << TC_CMR_ASWTRG_Pos)   /**< (TC_CMR) SET Position  */
#define TC_CMR_ASWTRG_CLEAR                   (TC_CMR_ASWTRG_CLEAR_Val << TC_CMR_ASWTRG_Pos)  /**< (TC_CMR) CLEAR Position  */
#define TC_CMR_ASWTRG_TOGGLE                  (TC_CMR_ASWTRG_TOGGLE_Val << TC_CMR_ASWTRG_Pos)  /**< (TC_CMR) TOGGLE Position  */
#define TC_CMR_BCPB_Pos                       (24)                                           /**< (TC_CMR) RB Compare Effect on TIOBx Position */
#define TC_CMR_BCPB_Msk                       (0x3U << TC_CMR_BCPB_Pos)                      /**< (TC_CMR) RB Compare Effect on TIOBx Mask */
#define TC_CMR_BCPB(value)                    (TC_CMR_BCPB_Msk & ((value) << TC_CMR_BCPB_Pos))
#define   TC_CMR_BCPB_NONE_Val                (0x0U)                                         /**< (TC_CMR) NONE  */
#define   TC_CMR_BCPB_SET_Val                 (0x1U)                                         /**< (TC_CMR) SET  */
#define   TC_CMR_BCPB_CLEAR_Val               (0x2U)                                         /**< (TC_CMR) CLEAR  */
#define   TC_CMR_BCPB_TOGGLE_Val              (0x3U)                                         /**< (TC_CMR) TOGGLE  */
#define TC_CMR_BCPB_NONE                      (TC_CMR_BCPB_NONE_Val << TC_CMR_BCPB_Pos)      /**< (TC_CMR) NONE Position  */
#define TC_CMR_BCPB_SET                       (TC_CMR_BCPB_SET_Val << TC_CMR_BCPB_Pos)       /**< (TC_CMR) SET Position  */
#define TC_CMR_BCPB_CLEAR                     (TC_CMR_BCPB_CLEAR_Val << TC_CMR_BCPB_Pos)     /**< (TC_CMR) CLEAR Position  */
#define TC_CMR_BCPB_TOGGLE                    (TC_CMR_BCPB_TOGGLE_Val << TC_CMR_BCPB_Pos)    /**< (TC_CMR) TOGGLE Position  */
#define TC_CMR_BCPC_Pos                       (26)                                           /**< (TC_CMR) RC Compare Effect on TIOBx Position */
#define TC_CMR_BCPC_Msk                       (0x3U << TC_CMR_BCPC_Pos)                      /**< (TC_CMR) RC Compare Effect on TIOBx Mask */
#define TC_CMR_BCPC(value)                    (TC_CMR_BCPC_Msk & ((value) << TC_CMR_BCPC_Pos))
#define   TC_CMR_BCPC_NONE_Val                (0x0U)                                         /**< (TC_CMR) NONE  */
#define   TC_CMR_BCPC_SET_Val                 (0x1U)                                         /**< (TC_CMR) SET  */
#define   TC_CMR_BCPC_CLEAR_Val               (0x2U)                                         /**< (TC_CMR) CLEAR  */
#define   TC_CMR_BCPC_TOGGLE_Val              (0x3U)                                         /**< (TC_CMR) TOGGLE  */
#define TC_CMR_BCPC_NONE                      (TC_CMR_BCPC_NONE_Val << TC_CMR_BCPC_Pos)      /**< (TC_CMR) NONE Position  */
#define TC_CMR_BCPC_SET                       (TC_CMR_BCPC_SET_Val << TC_CMR_BCPC_Pos)       /**< (TC_CMR) SET Position  */
#define TC_CMR_BCPC_CLEAR                     (TC_CMR_BCPC_CLEAR_Val << TC_CMR_BCPC_Pos)     /**< (TC_CMR) CLEAR Position  */
#define TC_CMR_BCPC_TOGGLE                    (TC_CMR_BCPC_TOGGLE_Val << TC_CMR_BCPC_Pos)    /**< (TC_CMR) TOGGLE Position  */
#define TC_CMR_BEEVT_Pos                      (28)                                           /**< (TC_CMR) External Event Effect on TIOBx Position */
#define TC_CMR_BEEVT_Msk                      (0x3U << TC_CMR_BEEVT_Pos)                     /**< (TC_CMR) External Event Effect on TIOBx Mask */
#define TC_CMR_BEEVT(value)                   (TC_CMR_BEEVT_Msk & ((value) << TC_CMR_BEEVT_Pos))
#define   TC_CMR_BEEVT_NONE_Val               (0x0U)                                         /**< (TC_CMR) NONE  */
#define   TC_CMR_BEEVT_SET_Val                (0x1U)                                         /**< (TC_CMR) SET  */
#define   TC_CMR_BEEVT_CLEAR_Val              (0x2U)                                         /**< (TC_CMR) CLEAR  */
#define   TC_CMR_BEEVT_TOGGLE_Val             (0x3U)                                         /**< (TC_CMR) TOGGLE  */
#define TC_CMR_BEEVT_NONE                     (TC_CMR_BEEVT_NONE_Val << TC_CMR_BEEVT_Pos)    /**< (TC_CMR) NONE Position  */
#define TC_CMR_BEEVT_SET                      (TC_CMR_BEEVT_SET_Val << TC_CMR_BEEVT_Pos)     /**< (TC_CMR) SET Position  */
#define TC_CMR_BEEVT_CLEAR                    (TC_CMR_BEEVT_CLEAR_Val << TC_CMR_BEEVT_Pos)   /**< (TC_CMR) CLEAR Position  */
#define TC_CMR_BEEVT_TOGGLE                   (TC_CMR_BEEVT_TOGGLE_Val << TC_CMR_BEEVT_Pos)  /**< (TC_CMR) TOGGLE Position  */
#define TC_CMR_BSWTRG_Pos                     (30)                                           /**< (TC_CMR) Software Trigger Effect on TIOBx Position */
#define TC_CMR_BSWTRG_Msk                     (0x3U << TC_CMR_BSWTRG_Pos)                    /**< (TC_CMR) Software Trigger Effect on TIOBx Mask */
#define TC_CMR_BSWTRG(value)                  (TC_CMR_BSWTRG_Msk & ((value) << TC_CMR_BSWTRG_Pos))
#define   TC_CMR_BSWTRG_NONE_Val              (0x0U)                                         /**< (TC_CMR) NONE  */
#define   TC_CMR_BSWTRG_SET_Val               (0x1U)                                         /**< (TC_CMR) SET  */
#define   TC_CMR_BSWTRG_CLEAR_Val             (0x2U)                                         /**< (TC_CMR) CLEAR  */
#define   TC_CMR_BSWTRG_TOGGLE_Val            (0x3U)                                         /**< (TC_CMR) TOGGLE  */
#define TC_CMR_BSWTRG_NONE                    (TC_CMR_BSWTRG_NONE_Val << TC_CMR_BSWTRG_Pos)  /**< (TC_CMR) NONE Position  */
#define TC_CMR_BSWTRG_SET                     (TC_CMR_BSWTRG_SET_Val << TC_CMR_BSWTRG_Pos)   /**< (TC_CMR) SET Position  */
#define TC_CMR_BSWTRG_CLEAR                   (TC_CMR_BSWTRG_CLEAR_Val << TC_CMR_BSWTRG_Pos)  /**< (TC_CMR) CLEAR Position  */
#define TC_CMR_BSWTRG_TOGGLE                  (TC_CMR_BSWTRG_TOGGLE_Val << TC_CMR_BSWTRG_Pos)  /**< (TC_CMR) TOGGLE Position  */

/* -------- TC_SMMR : (TC Offset: 0x08) (R/W 32) Stepper Motor Mode Register (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t GCEN:1;                    /**< bit:      0  Gray Count Enable                             */
    uint32_t DOWN:1;                    /**< bit:      1  Down Count                                    */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  uint32_t w;
} __TC_SMMR_bits_t;

#define TC_SMMR_GCEN_Pos                      (0)                                            /**< (TC_SMMR) Gray Count Enable Position */
#define TC_SMMR_GCEN_Msk                      (0x1U << TC_SMMR_GCEN_Pos)                     /**< (TC_SMMR) Gray Count Enable Mask */
#define TC_SMMR_DOWN_Pos                      (1)                                            /**< (TC_SMMR) Down Count Position */
#define TC_SMMR_DOWN_Msk                      (0x1U << TC_SMMR_DOWN_Pos)                     /**< (TC_SMMR) Down Count Mask */
#define TC_SMMR_Msk                           (0x00000003UL)                                 /**< (TC_SMMR) Register Mask  */

/* -------- TC_RAB : (TC Offset: 0x0c) (R/ 32) Register AB (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t RAB:32;                    /**< bit:  0..31  Register A or Register B                      */
  };
  uint32_t w;
} __TC_RAB_bits_t;

#define TC_RAB_RAB_Pos                        (0)                                            /**< (TC_RAB) Register A or Register B Position */
#define TC_RAB_RAB_Msk                        (0xFFFFFFFFU << TC_RAB_RAB_Pos)                /**< (TC_RAB) Register A or Register B Mask */
#define TC_RAB_RAB(value)                     (TC_RAB_RAB_Msk & ((value) << TC_RAB_RAB_Pos))
#define TC_RAB_Msk                            (0xFFFFFFFFUL)                                 /**< (TC_RAB) Register Mask  */

/* -------- TC_CV : (TC Offset: 0x10) (R/ 32) Counter Value (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t CV:32;                     /**< bit:  0..31  Counter Value                                 */
  };
  uint32_t w;
} __TC_CV_bits_t;

#define TC_CV_CV_Pos                          (0)                                            /**< (TC_CV) Counter Value Position */
#define TC_CV_CV_Msk                          (0xFFFFFFFFU << TC_CV_CV_Pos)                  /**< (TC_CV) Counter Value Mask */
#define TC_CV_CV(value)                       (TC_CV_CV_Msk & ((value) << TC_CV_CV_Pos))
#define TC_CV_Msk                             (0xFFFFFFFFUL)                                 /**< (TC_CV) Register Mask  */

/* -------- TC_RA : (TC Offset: 0x14) (R/W 32) Register A (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t RA:32;                     /**< bit:  0..31  Register A                                    */
  };
  uint32_t w;
} __TC_RA_bits_t;

#define TC_RA_RA_Pos                          (0)                                            /**< (TC_RA) Register A Position */
#define TC_RA_RA_Msk                          (0xFFFFFFFFU << TC_RA_RA_Pos)                  /**< (TC_RA) Register A Mask */
#define TC_RA_RA(value)                       (TC_RA_RA_Msk & ((value) << TC_RA_RA_Pos))
#define TC_RA_Msk                             (0xFFFFFFFFUL)                                 /**< (TC_RA) Register Mask  */

/* -------- TC_RB : (TC Offset: 0x18) (R/W 32) Register B (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t RB:32;                     /**< bit:  0..31  Register B                                    */
  };
  uint32_t w;
} __TC_RB_bits_t;

#define TC_RB_RB_Pos                          (0)                                            /**< (TC_RB) Register B Position */
#define TC_RB_RB_Msk                          (0xFFFFFFFFU << TC_RB_RB_Pos)                  /**< (TC_RB) Register B Mask */
#define TC_RB_RB(value)                       (TC_RB_RB_Msk & ((value) << TC_RB_RB_Pos))
#define TC_RB_Msk                             (0xFFFFFFFFUL)                                 /**< (TC_RB) Register Mask  */

/* -------- TC_RC : (TC Offset: 0x1c) (R/W 32) Register C (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t RC:32;                     /**< bit:  0..31  Register C                                    */
  };
  uint32_t w;
} __TC_RC_bits_t;

#define TC_RC_RC_Pos                          (0)                                            /**< (TC_RC) Register C Position */
#define TC_RC_RC_Msk                          (0xFFFFFFFFU << TC_RC_RC_Pos)                  /**< (TC_RC) Register C Mask */
#define TC_RC_RC(value)                       (TC_RC_RC_Msk & ((value) << TC_RC_RC_Pos))
#define TC_RC_Msk                             (0xFFFFFFFFUL)                                 /**< (TC_RC) Register Mask  */

/* -------- TC_SR : (TC Offset: 0x20) (R/ 32) Status Register (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t COVFS:1;                   /**< bit:      0  Counter Overflow Status (cleared on read)     */
    uint32_t LOVRS:1;                   /**< bit:      1  Load Overrun Status (cleared on read)         */
    uint32_t CPAS:1;                    /**< bit:      2  RA Compare Status (cleared on read)           */
    uint32_t CPBS:1;                    /**< bit:      3  RB Compare Status (cleared on read)           */
    uint32_t CPCS:1;                    /**< bit:      4  RC Compare Status (cleared on read)           */
    uint32_t LDRAS:1;                   /**< bit:      5  RA Loading Status (cleared on read)           */
    uint32_t LDRBS:1;                   /**< bit:      6  RB Loading Status (cleared on read)           */
    uint32_t ETRGS:1;                   /**< bit:      7  External Trigger Status (cleared on read)     */
    uint32_t :8;                        /**< bit:  8..15  Reserved                                      */
    uint32_t CLKSTA:1;                  /**< bit:     16  Clock Enabling Status                         */
    uint32_t MTIOA:1;                   /**< bit:     17  TIOAx Mirror                                  */
    uint32_t MTIOB:1;                   /**< bit:     18  TIOBx Mirror                                  */
    uint32_t :13;                       /**< bit: 19..31  Reserved                                      */
  };
  uint32_t w;
} __TC_SR_bits_t;

#define TC_SR_COVFS_Pos                       (0)                                            /**< (TC_SR) Counter Overflow Status (cleared on read) Position */
#define TC_SR_COVFS_Msk                       (0x1U << TC_SR_COVFS_Pos)                      /**< (TC_SR) Counter Overflow Status (cleared on read) Mask */
#define TC_SR_LOVRS_Pos                       (1)                                            /**< (TC_SR) Load Overrun Status (cleared on read) Position */
#define TC_SR_LOVRS_Msk                       (0x1U << TC_SR_LOVRS_Pos)                      /**< (TC_SR) Load Overrun Status (cleared on read) Mask */
#define TC_SR_CPAS_Pos                        (2)                                            /**< (TC_SR) RA Compare Status (cleared on read) Position */
#define TC_SR_CPAS_Msk                        (0x1U << TC_SR_CPAS_Pos)                       /**< (TC_SR) RA Compare Status (cleared on read) Mask */
#define TC_SR_CPBS_Pos                        (3)                                            /**< (TC_SR) RB Compare Status (cleared on read) Position */
#define TC_SR_CPBS_Msk                        (0x1U << TC_SR_CPBS_Pos)                       /**< (TC_SR) RB Compare Status (cleared on read) Mask */
#define TC_SR_CPCS_Pos                        (4)                                            /**< (TC_SR) RC Compare Status (cleared on read) Position */
#define TC_SR_CPCS_Msk                        (0x1U << TC_SR_CPCS_Pos)                       /**< (TC_SR) RC Compare Status (cleared on read) Mask */
#define TC_SR_LDRAS_Pos                       (5)                                            /**< (TC_SR) RA Loading Status (cleared on read) Position */
#define TC_SR_LDRAS_Msk                       (0x1U << TC_SR_LDRAS_Pos)                      /**< (TC_SR) RA Loading Status (cleared on read) Mask */
#define TC_SR_LDRBS_Pos                       (6)                                            /**< (TC_SR) RB Loading Status (cleared on read) Position */
#define TC_SR_LDRBS_Msk                       (0x1U << TC_SR_LDRBS_Pos)                      /**< (TC_SR) RB Loading Status (cleared on read) Mask */
#define TC_SR_ETRGS_Pos                       (7)                                            /**< (TC_SR) External Trigger Status (cleared on read) Position */
#define TC_SR_ETRGS_Msk                       (0x1U << TC_SR_ETRGS_Pos)                      /**< (TC_SR) External Trigger Status (cleared on read) Mask */
#define TC_SR_CLKSTA_Pos                      (16)                                           /**< (TC_SR) Clock Enabling Status Position */
#define TC_SR_CLKSTA_Msk                      (0x1U << TC_SR_CLKSTA_Pos)                     /**< (TC_SR) Clock Enabling Status Mask */
#define TC_SR_MTIOA_Pos                       (17)                                           /**< (TC_SR) TIOAx Mirror Position */
#define TC_SR_MTIOA_Msk                       (0x1U << TC_SR_MTIOA_Pos)                      /**< (TC_SR) TIOAx Mirror Mask */
#define TC_SR_MTIOB_Pos                       (18)                                           /**< (TC_SR) TIOBx Mirror Position */
#define TC_SR_MTIOB_Msk                       (0x1U << TC_SR_MTIOB_Pos)                      /**< (TC_SR) TIOBx Mirror Mask */
#define TC_SR_Msk                             (0x000700FFUL)                                 /**< (TC_SR) Register Mask  */

/* -------- TC_IER : (TC Offset: 0x24) (/W 32) Interrupt Enable Register (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t COVFS:1;                   /**< bit:      0  Counter Overflow                              */
    uint32_t LOVRS:1;                   /**< bit:      1  Load Overrun                                  */
    uint32_t CPAS:1;                    /**< bit:      2  RA Compare                                    */
    uint32_t CPBS:1;                    /**< bit:      3  RB Compare                                    */
    uint32_t CPCS:1;                    /**< bit:      4  RC Compare                                    */
    uint32_t LDRAS:1;                   /**< bit:      5  RA Loading                                    */
    uint32_t LDRBS:1;                   /**< bit:      6  RB Loading                                    */
    uint32_t ETRGS:1;                   /**< bit:      7  External Trigger                              */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  uint32_t w;
} __TC_IER_bits_t;

#define TC_IER_COVFS_Pos                      (0)                                            /**< (TC_IER) Counter Overflow Position */
#define TC_IER_COVFS_Msk                      (0x1U << TC_IER_COVFS_Pos)                     /**< (TC_IER) Counter Overflow Mask */
#define TC_IER_LOVRS_Pos                      (1)                                            /**< (TC_IER) Load Overrun Position */
#define TC_IER_LOVRS_Msk                      (0x1U << TC_IER_LOVRS_Pos)                     /**< (TC_IER) Load Overrun Mask */
#define TC_IER_CPAS_Pos                       (2)                                            /**< (TC_IER) RA Compare Position */
#define TC_IER_CPAS_Msk                       (0x1U << TC_IER_CPAS_Pos)                      /**< (TC_IER) RA Compare Mask */
#define TC_IER_CPBS_Pos                       (3)                                            /**< (TC_IER) RB Compare Position */
#define TC_IER_CPBS_Msk                       (0x1U << TC_IER_CPBS_Pos)                      /**< (TC_IER) RB Compare Mask */
#define TC_IER_CPCS_Pos                       (4)                                            /**< (TC_IER) RC Compare Position */
#define TC_IER_CPCS_Msk                       (0x1U << TC_IER_CPCS_Pos)                      /**< (TC_IER) RC Compare Mask */
#define TC_IER_LDRAS_Pos                      (5)                                            /**< (TC_IER) RA Loading Position */
#define TC_IER_LDRAS_Msk                      (0x1U << TC_IER_LDRAS_Pos)                     /**< (TC_IER) RA Loading Mask */
#define TC_IER_LDRBS_Pos                      (6)                                            /**< (TC_IER) RB Loading Position */
#define TC_IER_LDRBS_Msk                      (0x1U << TC_IER_LDRBS_Pos)                     /**< (TC_IER) RB Loading Mask */
#define TC_IER_ETRGS_Pos                      (7)                                            /**< (TC_IER) External Trigger Position */
#define TC_IER_ETRGS_Msk                      (0x1U << TC_IER_ETRGS_Pos)                     /**< (TC_IER) External Trigger Mask */
#define TC_IER_Msk                            (0x000000FFUL)                                 /**< (TC_IER) Register Mask  */

/* -------- TC_IDR : (TC Offset: 0x28) (/W 32) Interrupt Disable Register (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t COVFS:1;                   /**< bit:      0  Counter Overflow                              */
    uint32_t LOVRS:1;                   /**< bit:      1  Load Overrun                                  */
    uint32_t CPAS:1;                    /**< bit:      2  RA Compare                                    */
    uint32_t CPBS:1;                    /**< bit:      3  RB Compare                                    */
    uint32_t CPCS:1;                    /**< bit:      4  RC Compare                                    */
    uint32_t LDRAS:1;                   /**< bit:      5  RA Loading                                    */
    uint32_t LDRBS:1;                   /**< bit:      6  RB Loading                                    */
    uint32_t ETRGS:1;                   /**< bit:      7  External Trigger                              */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  uint32_t w;
} __TC_IDR_bits_t;

#define TC_IDR_COVFS_Pos                      (0)                                            /**< (TC_IDR) Counter Overflow Position */
#define TC_IDR_COVFS_Msk                      (0x1U << TC_IDR_COVFS_Pos)                     /**< (TC_IDR) Counter Overflow Mask */
#define TC_IDR_LOVRS_Pos                      (1)                                            /**< (TC_IDR) Load Overrun Position */
#define TC_IDR_LOVRS_Msk                      (0x1U << TC_IDR_LOVRS_Pos)                     /**< (TC_IDR) Load Overrun Mask */
#define TC_IDR_CPAS_Pos                       (2)                                            /**< (TC_IDR) RA Compare Position */
#define TC_IDR_CPAS_Msk                       (0x1U << TC_IDR_CPAS_Pos)                      /**< (TC_IDR) RA Compare Mask */
#define TC_IDR_CPBS_Pos                       (3)                                            /**< (TC_IDR) RB Compare Position */
#define TC_IDR_CPBS_Msk                       (0x1U << TC_IDR_CPBS_Pos)                      /**< (TC_IDR) RB Compare Mask */
#define TC_IDR_CPCS_Pos                       (4)                                            /**< (TC_IDR) RC Compare Position */
#define TC_IDR_CPCS_Msk                       (0x1U << TC_IDR_CPCS_Pos)                      /**< (TC_IDR) RC Compare Mask */
#define TC_IDR_LDRAS_Pos                      (5)                                            /**< (TC_IDR) RA Loading Position */
#define TC_IDR_LDRAS_Msk                      (0x1U << TC_IDR_LDRAS_Pos)                     /**< (TC_IDR) RA Loading Mask */
#define TC_IDR_LDRBS_Pos                      (6)                                            /**< (TC_IDR) RB Loading Position */
#define TC_IDR_LDRBS_Msk                      (0x1U << TC_IDR_LDRBS_Pos)                     /**< (TC_IDR) RB Loading Mask */
#define TC_IDR_ETRGS_Pos                      (7)                                            /**< (TC_IDR) External Trigger Position */
#define TC_IDR_ETRGS_Msk                      (0x1U << TC_IDR_ETRGS_Pos)                     /**< (TC_IDR) External Trigger Mask */
#define TC_IDR_Msk                            (0x000000FFUL)                                 /**< (TC_IDR) Register Mask  */

/* -------- TC_IMR : (TC Offset: 0x2c) (R/ 32) Interrupt Mask Register (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t COVFS:1;                   /**< bit:      0  Counter Overflow                              */
    uint32_t LOVRS:1;                   /**< bit:      1  Load Overrun                                  */
    uint32_t CPAS:1;                    /**< bit:      2  RA Compare                                    */
    uint32_t CPBS:1;                    /**< bit:      3  RB Compare                                    */
    uint32_t CPCS:1;                    /**< bit:      4  RC Compare                                    */
    uint32_t LDRAS:1;                   /**< bit:      5  RA Loading                                    */
    uint32_t LDRBS:1;                   /**< bit:      6  RB Loading                                    */
    uint32_t ETRGS:1;                   /**< bit:      7  External Trigger                              */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  uint32_t w;
} __TC_IMR_bits_t;

#define TC_IMR_COVFS_Pos                      (0)                                            /**< (TC_IMR) Counter Overflow Position */
#define TC_IMR_COVFS_Msk                      (0x1U << TC_IMR_COVFS_Pos)                     /**< (TC_IMR) Counter Overflow Mask */
#define TC_IMR_LOVRS_Pos                      (1)                                            /**< (TC_IMR) Load Overrun Position */
#define TC_IMR_LOVRS_Msk                      (0x1U << TC_IMR_LOVRS_Pos)                     /**< (TC_IMR) Load Overrun Mask */
#define TC_IMR_CPAS_Pos                       (2)                                            /**< (TC_IMR) RA Compare Position */
#define TC_IMR_CPAS_Msk                       (0x1U << TC_IMR_CPAS_Pos)                      /**< (TC_IMR) RA Compare Mask */
#define TC_IMR_CPBS_Pos                       (3)                                            /**< (TC_IMR) RB Compare Position */
#define TC_IMR_CPBS_Msk                       (0x1U << TC_IMR_CPBS_Pos)                      /**< (TC_IMR) RB Compare Mask */
#define TC_IMR_CPCS_Pos                       (4)                                            /**< (TC_IMR) RC Compare Position */
#define TC_IMR_CPCS_Msk                       (0x1U << TC_IMR_CPCS_Pos)                      /**< (TC_IMR) RC Compare Mask */
#define TC_IMR_LDRAS_Pos                      (5)                                            /**< (TC_IMR) RA Loading Position */
#define TC_IMR_LDRAS_Msk                      (0x1U << TC_IMR_LDRAS_Pos)                     /**< (TC_IMR) RA Loading Mask */
#define TC_IMR_LDRBS_Pos                      (6)                                            /**< (TC_IMR) RB Loading Position */
#define TC_IMR_LDRBS_Msk                      (0x1U << TC_IMR_LDRBS_Pos)                     /**< (TC_IMR) RB Loading Mask */
#define TC_IMR_ETRGS_Pos                      (7)                                            /**< (TC_IMR) External Trigger Position */
#define TC_IMR_ETRGS_Msk                      (0x1U << TC_IMR_ETRGS_Pos)                     /**< (TC_IMR) External Trigger Mask */
#define TC_IMR_Msk                            (0x000000FFUL)                                 /**< (TC_IMR) Register Mask  */

/* -------- TC_EMR : (TC Offset: 0x30) (R/W 32) Extended Mode Register (channel = 0) -------- */

typedef union
{
  struct
  {
    uint32_t TRIGSRCA:2;                /**< bit:   0..1  Trigger Source for Input A                    */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t TRIGSRCB:2;                /**< bit:   4..5  Trigger Source for Input B                    */
    uint32_t :2;                        /**< bit:   6..7  Reserved                                      */
    uint32_t NODIVCLK:1;                /**< bit:      8  No Divided Clock                              */
    uint32_t :23;                       /**< bit:  9..31  Reserved                                      */
  };
  uint32_t w;
} __TC_EMR_bits_t;

#define TC_EMR_TRIGSRCA_Pos                   (0)                                            /**< (TC_EMR) Trigger Source for Input A Position */
#define TC_EMR_TRIGSRCA_Msk                   (0x3U << TC_EMR_TRIGSRCA_Pos)                  /**< (TC_EMR) Trigger Source for Input A Mask */
#define TC_EMR_TRIGSRCA(value)                (TC_EMR_TRIGSRCA_Msk & ((value) << TC_EMR_TRIGSRCA_Pos))
#define   TC_EMR_TRIGSRCA_EXTERNAL_TIOAx_Val  (0x0U)                                         /**< (TC_EMR) The trigger/capture input A is driven by external pin TIOAx  */
#define   TC_EMR_TRIGSRCA_PWMx_Val            (0x1U)                                         /**< (TC_EMR) The trigger/capture input A is driven internally by PWMx  */
#define TC_EMR_TRIGSRCA_EXTERNAL_TIOAx        (TC_EMR_TRIGSRCA_EXTERNAL_TIOAx_Val << TC_EMR_TRIGSRCA_Pos)  /**< (TC_EMR) The trigger/capture input A is driven by external pin TIOAx Position  */
#define TC_EMR_TRIGSRCA_PWMx                  (TC_EMR_TRIGSRCA_PWMx_Val << TC_EMR_TRIGSRCA_Pos)  /**< (TC_EMR) The trigger/capture input A is driven internally by PWMx Position  */
#define TC_EMR_TRIGSRCB_Pos                   (4)                                            /**< (TC_EMR) Trigger Source for Input B Position */
#define TC_EMR_TRIGSRCB_Msk                   (0x3U << TC_EMR_TRIGSRCB_Pos)                  /**< (TC_EMR) Trigger Source for Input B Mask */
#define TC_EMR_TRIGSRCB(value)                (TC_EMR_TRIGSRCB_Msk & ((value) << TC_EMR_TRIGSRCB_Pos))
#define   TC_EMR_TRIGSRCB_EXTERNAL_TIOBx_Val  (0x0U)                                         /**< (TC_EMR) The trigger/capture input B is driven by external pin TIOBx  */
#define   TC_EMR_TRIGSRCB_PWMx_Val            (0x1U)                                         /**< (TC_EMR) For TC0 to TC10: The trigger/capture input B is driven internally by the comparator output (see Figure 7-16) of the PWMx.For TC11: The trigger/capture input B is driven internally by the GTSUCOMP signal of the Ethernet MAC (GMAC).  */
#define TC_EMR_TRIGSRCB_EXTERNAL_TIOBx        (TC_EMR_TRIGSRCB_EXTERNAL_TIOBx_Val << TC_EMR_TRIGSRCB_Pos)  /**< (TC_EMR) The trigger/capture input B is driven by external pin TIOBx Position  */
#define TC_EMR_TRIGSRCB_PWMx                  (TC_EMR_TRIGSRCB_PWMx_Val << TC_EMR_TRIGSRCB_Pos)  /**< (TC_EMR) For TC0 to TC10: The trigger/capture input B is driven internally by the comparator output (see Figure 7-16) of the PWMx.For TC11: The trigger/capture input B is driven internally by the GTSUCOMP signal of the Ethernet MAC (GMAC). Position  */
#define TC_EMR_NODIVCLK_Pos                   (8)                                            /**< (TC_EMR) No Divided Clock Position */
#define TC_EMR_NODIVCLK_Msk                   (0x1U << TC_EMR_NODIVCLK_Pos)                  /**< (TC_EMR) No Divided Clock Mask */
#define TC_EMR_Msk                            (0x00000133UL)                                 /**< (TC_EMR) Register Mask  */

/* -------- TC_BCR : (TC Offset: 0xc0) (/W 32) Block Control Register -------- */

typedef union
{
  struct
  {
    uint32_t SYNC:1;                    /**< bit:      0  Synchro Command                               */
    uint32_t :31;                       /**< bit:  1..31  Reserved                                      */
  };
  uint32_t w;
} __TC_BCR_bits_t;

#define TC_BCR_SYNC_Pos                       (0)                                            /**< (TC_BCR) Synchro Command Position */
#define TC_BCR_SYNC_Msk                       (0x1U << TC_BCR_SYNC_Pos)                      /**< (TC_BCR) Synchro Command Mask */
#define TC_BCR_Msk                            (0x00000001UL)                                 /**< (TC_BCR) Register Mask  */

/* -------- TC_BMR : (TC Offset: 0xc4) (R/W 32) Block Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t TC0XC0S:2;                 /**< bit:   0..1  External Clock Signal 0 Selection             */
    uint32_t TC1XC1S:2;                 /**< bit:   2..3  External Clock Signal 1 Selection             */
    uint32_t TC2XC2S:2;                 /**< bit:   4..5  External Clock Signal 2 Selection             */
    uint32_t :2;                        /**< bit:   6..7  Reserved                                      */
    uint32_t QDEN:1;                    /**< bit:      8  Quadrature Decoder Enabled                    */
    uint32_t POSEN:1;                   /**< bit:      9  Position Enabled                              */
    uint32_t SPEEDEN:1;                 /**< bit:     10  Speed Enabled                                 */
    uint32_t QDTRANS:1;                 /**< bit:     11  Quadrature Decoding Transparent               */
    uint32_t EDGPHA:1;                  /**< bit:     12  Edge on PHA Count Mode                        */
    uint32_t INVA:1;                    /**< bit:     13  Inverted PHA                                  */
    uint32_t INVB:1;                    /**< bit:     14  Inverted PHB                                  */
    uint32_t INVIDX:1;                  /**< bit:     15  Inverted Index                                */
    uint32_t SWAP:1;                    /**< bit:     16  Swap PHA and PHB                              */
    uint32_t IDXPHB:1;                  /**< bit:     17  Index Pin is PHB Pin                          */
    uint32_t :2;                        /**< bit: 18..19  Reserved                                      */
    uint32_t MAXFILT:6;                 /**< bit: 20..25  Maximum Filter                                */
    uint32_t :6;                        /**< bit: 26..31  Reserved                                      */
  };
  uint32_t w;
} __TC_BMR_bits_t;

#define TC_BMR_TC0XC0S_Pos                    (0)                                            /**< (TC_BMR) External Clock Signal 0 Selection Position */
#define TC_BMR_TC0XC0S_Msk                    (0x3U << TC_BMR_TC0XC0S_Pos)                   /**< (TC_BMR) External Clock Signal 0 Selection Mask */
#define TC_BMR_TC0XC0S(value)                 (TC_BMR_TC0XC0S_Msk & ((value) << TC_BMR_TC0XC0S_Pos))
#define   TC_BMR_TC0XC0S_TCLK0_Val            (0x0U)                                         /**< (TC_BMR) Signal connected to XC0: TCLK0  */
#define   TC_BMR_TC0XC0S_TIOA1_Val            (0x2U)                                         /**< (TC_BMR) Signal connected to XC0: TIOA1  */
#define   TC_BMR_TC0XC0S_TIOA2_Val            (0x3U)                                         /**< (TC_BMR) Signal connected to XC0: TIOA2  */
#define TC_BMR_TC0XC0S_TCLK0                  (TC_BMR_TC0XC0S_TCLK0_Val << TC_BMR_TC0XC0S_Pos)  /**< (TC_BMR) Signal connected to XC0: TCLK0 Position  */
#define TC_BMR_TC0XC0S_TIOA1                  (TC_BMR_TC0XC0S_TIOA1_Val << TC_BMR_TC0XC0S_Pos)  /**< (TC_BMR) Signal connected to XC0: TIOA1 Position  */
#define TC_BMR_TC0XC0S_TIOA2                  (TC_BMR_TC0XC0S_TIOA2_Val << TC_BMR_TC0XC0S_Pos)  /**< (TC_BMR) Signal connected to XC0: TIOA2 Position  */
#define TC_BMR_TC1XC1S_Pos                    (2)                                            /**< (TC_BMR) External Clock Signal 1 Selection Position */
#define TC_BMR_TC1XC1S_Msk                    (0x3U << TC_BMR_TC1XC1S_Pos)                   /**< (TC_BMR) External Clock Signal 1 Selection Mask */
#define TC_BMR_TC1XC1S(value)                 (TC_BMR_TC1XC1S_Msk & ((value) << TC_BMR_TC1XC1S_Pos))
#define   TC_BMR_TC1XC1S_TCLK1_Val            (0x0U)                                         /**< (TC_BMR) Signal connected to XC1: TCLK1  */
#define   TC_BMR_TC1XC1S_TIOA0_Val            (0x2U)                                         /**< (TC_BMR) Signal connected to XC1: TIOA0  */
#define   TC_BMR_TC1XC1S_TIOA2_Val            (0x3U)                                         /**< (TC_BMR) Signal connected to XC1: TIOA2  */
#define TC_BMR_TC1XC1S_TCLK1                  (TC_BMR_TC1XC1S_TCLK1_Val << TC_BMR_TC1XC1S_Pos)  /**< (TC_BMR) Signal connected to XC1: TCLK1 Position  */
#define TC_BMR_TC1XC1S_TIOA0                  (TC_BMR_TC1XC1S_TIOA0_Val << TC_BMR_TC1XC1S_Pos)  /**< (TC_BMR) Signal connected to XC1: TIOA0 Position  */
#define TC_BMR_TC1XC1S_TIOA2                  (TC_BMR_TC1XC1S_TIOA2_Val << TC_BMR_TC1XC1S_Pos)  /**< (TC_BMR) Signal connected to XC1: TIOA2 Position  */
#define TC_BMR_TC2XC2S_Pos                    (4)                                            /**< (TC_BMR) External Clock Signal 2 Selection Position */
#define TC_BMR_TC2XC2S_Msk                    (0x3U << TC_BMR_TC2XC2S_Pos)                   /**< (TC_BMR) External Clock Signal 2 Selection Mask */
#define TC_BMR_TC2XC2S(value)                 (TC_BMR_TC2XC2S_Msk & ((value) << TC_BMR_TC2XC2S_Pos))
#define   TC_BMR_TC2XC2S_TCLK2_Val            (0x0U)                                         /**< (TC_BMR) Signal connected to XC2: TCLK2  */
#define   TC_BMR_TC2XC2S_TIOA0_Val            (0x2U)                                         /**< (TC_BMR) Signal connected to XC2: TIOA0  */
#define   TC_BMR_TC2XC2S_TIOA1_Val            (0x3U)                                         /**< (TC_BMR) Signal connected to XC2: TIOA1  */
#define TC_BMR_TC2XC2S_TCLK2                  (TC_BMR_TC2XC2S_TCLK2_Val << TC_BMR_TC2XC2S_Pos)  /**< (TC_BMR) Signal connected to XC2: TCLK2 Position  */
#define TC_BMR_TC2XC2S_TIOA0                  (TC_BMR_TC2XC2S_TIOA0_Val << TC_BMR_TC2XC2S_Pos)  /**< (TC_BMR) Signal connected to XC2: TIOA0 Position  */
#define TC_BMR_TC2XC2S_TIOA1                  (TC_BMR_TC2XC2S_TIOA1_Val << TC_BMR_TC2XC2S_Pos)  /**< (TC_BMR) Signal connected to XC2: TIOA1 Position  */
#define TC_BMR_QDEN_Pos                       (8)                                            /**< (TC_BMR) Quadrature Decoder Enabled Position */
#define TC_BMR_QDEN_Msk                       (0x1U << TC_BMR_QDEN_Pos)                      /**< (TC_BMR) Quadrature Decoder Enabled Mask */
#define TC_BMR_POSEN_Pos                      (9)                                            /**< (TC_BMR) Position Enabled Position */
#define TC_BMR_POSEN_Msk                      (0x1U << TC_BMR_POSEN_Pos)                     /**< (TC_BMR) Position Enabled Mask */
#define TC_BMR_SPEEDEN_Pos                    (10)                                           /**< (TC_BMR) Speed Enabled Position */
#define TC_BMR_SPEEDEN_Msk                    (0x1U << TC_BMR_SPEEDEN_Pos)                   /**< (TC_BMR) Speed Enabled Mask */
#define TC_BMR_QDTRANS_Pos                    (11)                                           /**< (TC_BMR) Quadrature Decoding Transparent Position */
#define TC_BMR_QDTRANS_Msk                    (0x1U << TC_BMR_QDTRANS_Pos)                   /**< (TC_BMR) Quadrature Decoding Transparent Mask */
#define TC_BMR_EDGPHA_Pos                     (12)                                           /**< (TC_BMR) Edge on PHA Count Mode Position */
#define TC_BMR_EDGPHA_Msk                     (0x1U << TC_BMR_EDGPHA_Pos)                    /**< (TC_BMR) Edge on PHA Count Mode Mask */
#define TC_BMR_INVA_Pos                       (13)                                           /**< (TC_BMR) Inverted PHA Position */
#define TC_BMR_INVA_Msk                       (0x1U << TC_BMR_INVA_Pos)                      /**< (TC_BMR) Inverted PHA Mask */
#define TC_BMR_INVB_Pos                       (14)                                           /**< (TC_BMR) Inverted PHB Position */
#define TC_BMR_INVB_Msk                       (0x1U << TC_BMR_INVB_Pos)                      /**< (TC_BMR) Inverted PHB Mask */
#define TC_BMR_INVIDX_Pos                     (15)                                           /**< (TC_BMR) Inverted Index Position */
#define TC_BMR_INVIDX_Msk                     (0x1U << TC_BMR_INVIDX_Pos)                    /**< (TC_BMR) Inverted Index Mask */
#define TC_BMR_SWAP_Pos                       (16)                                           /**< (TC_BMR) Swap PHA and PHB Position */
#define TC_BMR_SWAP_Msk                       (0x1U << TC_BMR_SWAP_Pos)                      /**< (TC_BMR) Swap PHA and PHB Mask */
#define TC_BMR_IDXPHB_Pos                     (17)                                           /**< (TC_BMR) Index Pin is PHB Pin Position */
#define TC_BMR_IDXPHB_Msk                     (0x1U << TC_BMR_IDXPHB_Pos)                    /**< (TC_BMR) Index Pin is PHB Pin Mask */
#define TC_BMR_MAXFILT_Pos                    (20)                                           /**< (TC_BMR) Maximum Filter Position */
#define TC_BMR_MAXFILT_Msk                    (0x3FU << TC_BMR_MAXFILT_Pos)                  /**< (TC_BMR) Maximum Filter Mask */
#define TC_BMR_MAXFILT(value)                 (TC_BMR_MAXFILT_Msk & ((value) << TC_BMR_MAXFILT_Pos))
#define TC_BMR_Msk                            (0x03F3FF3FUL)                                 /**< (TC_BMR) Register Mask  */

/* -------- TC_QIER : (TC Offset: 0xc8) (/W 32) QDEC Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t IDX:1;                     /**< bit:      0  Index                                         */
    uint32_t DIRCHG:1;                  /**< bit:      1  Direction Change                              */
    uint32_t QERR:1;                    /**< bit:      2  Quadrature Error                              */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  uint32_t w;
} __TC_QIER_bits_t;

#define TC_QIER_IDX_Pos                       (0)                                            /**< (TC_QIER) Index Position */
#define TC_QIER_IDX_Msk                       (0x1U << TC_QIER_IDX_Pos)                      /**< (TC_QIER) Index Mask */
#define TC_QIER_DIRCHG_Pos                    (1)                                            /**< (TC_QIER) Direction Change Position */
#define TC_QIER_DIRCHG_Msk                    (0x1U << TC_QIER_DIRCHG_Pos)                   /**< (TC_QIER) Direction Change Mask */
#define TC_QIER_QERR_Pos                      (2)                                            /**< (TC_QIER) Quadrature Error Position */
#define TC_QIER_QERR_Msk                      (0x1U << TC_QIER_QERR_Pos)                     /**< (TC_QIER) Quadrature Error Mask */
#define TC_QIER_Msk                           (0x00000007UL)                                 /**< (TC_QIER) Register Mask  */

/* -------- TC_QIDR : (TC Offset: 0xcc) (/W 32) QDEC Interrupt Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t IDX:1;                     /**< bit:      0  Index                                         */
    uint32_t DIRCHG:1;                  /**< bit:      1  Direction Change                              */
    uint32_t QERR:1;                    /**< bit:      2  Quadrature Error                              */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  uint32_t w;
} __TC_QIDR_bits_t;

#define TC_QIDR_IDX_Pos                       (0)                                            /**< (TC_QIDR) Index Position */
#define TC_QIDR_IDX_Msk                       (0x1U << TC_QIDR_IDX_Pos)                      /**< (TC_QIDR) Index Mask */
#define TC_QIDR_DIRCHG_Pos                    (1)                                            /**< (TC_QIDR) Direction Change Position */
#define TC_QIDR_DIRCHG_Msk                    (0x1U << TC_QIDR_DIRCHG_Pos)                   /**< (TC_QIDR) Direction Change Mask */
#define TC_QIDR_QERR_Pos                      (2)                                            /**< (TC_QIDR) Quadrature Error Position */
#define TC_QIDR_QERR_Msk                      (0x1U << TC_QIDR_QERR_Pos)                     /**< (TC_QIDR) Quadrature Error Mask */
#define TC_QIDR_Msk                           (0x00000007UL)                                 /**< (TC_QIDR) Register Mask  */

/* -------- TC_QIMR : (TC Offset: 0xd0) (R/ 32) QDEC Interrupt Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t IDX:1;                     /**< bit:      0  Index                                         */
    uint32_t DIRCHG:1;                  /**< bit:      1  Direction Change                              */
    uint32_t QERR:1;                    /**< bit:      2  Quadrature Error                              */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  uint32_t w;
} __TC_QIMR_bits_t;

#define TC_QIMR_IDX_Pos                       (0)                                            /**< (TC_QIMR) Index Position */
#define TC_QIMR_IDX_Msk                       (0x1U << TC_QIMR_IDX_Pos)                      /**< (TC_QIMR) Index Mask */
#define TC_QIMR_DIRCHG_Pos                    (1)                                            /**< (TC_QIMR) Direction Change Position */
#define TC_QIMR_DIRCHG_Msk                    (0x1U << TC_QIMR_DIRCHG_Pos)                   /**< (TC_QIMR) Direction Change Mask */
#define TC_QIMR_QERR_Pos                      (2)                                            /**< (TC_QIMR) Quadrature Error Position */
#define TC_QIMR_QERR_Msk                      (0x1U << TC_QIMR_QERR_Pos)                     /**< (TC_QIMR) Quadrature Error Mask */
#define TC_QIMR_Msk                           (0x00000007UL)                                 /**< (TC_QIMR) Register Mask  */

/* -------- TC_QISR : (TC Offset: 0xd4) (R/ 32) QDEC Interrupt Status Register -------- */

typedef union
{
  struct
  {
    uint32_t IDX:1;                     /**< bit:      0  Index                                         */
    uint32_t DIRCHG:1;                  /**< bit:      1  Direction Change                              */
    uint32_t QERR:1;                    /**< bit:      2  Quadrature Error                              */
    uint32_t :5;                        /**< bit:   3..7  Reserved                                      */
    uint32_t DIR:1;                     /**< bit:      8  Direction                                     */
    uint32_t :23;                       /**< bit:  9..31  Reserved                                      */
  };
  uint32_t w;
} __TC_QISR_bits_t;

#define TC_QISR_IDX_Pos                       (0)                                            /**< (TC_QISR) Index Position */
#define TC_QISR_IDX_Msk                       (0x1U << TC_QISR_IDX_Pos)                      /**< (TC_QISR) Index Mask */
#define TC_QISR_DIRCHG_Pos                    (1)                                            /**< (TC_QISR) Direction Change Position */
#define TC_QISR_DIRCHG_Msk                    (0x1U << TC_QISR_DIRCHG_Pos)                   /**< (TC_QISR) Direction Change Mask */
#define TC_QISR_QERR_Pos                      (2)                                            /**< (TC_QISR) Quadrature Error Position */
#define TC_QISR_QERR_Msk                      (0x1U << TC_QISR_QERR_Pos)                     /**< (TC_QISR) Quadrature Error Mask */
#define TC_QISR_DIR_Pos                       (8)                                            /**< (TC_QISR) Direction Position */
#define TC_QISR_DIR_Msk                       (0x1U << TC_QISR_DIR_Pos)                      /**< (TC_QISR) Direction Mask */
#define TC_QISR_Msk                           (0x00000107UL)                                 /**< (TC_QISR) Register Mask  */

/* -------- TC_FMR : (TC Offset: 0xd8) (R/W 32) Fault Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t ENCF0:1;                   /**< bit:      0  Enable Compare Fault Channel 0                */
    uint32_t ENCF1:1;                   /**< bit:      1  Enable Compare Fault Channel 1                */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  struct
  {
    uint32_t ENCF:2;                    /**< bit:   0..1  Enable Compare Fault Channel x                */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  uint32_t w;
} __TC_FMR_bits_t;

#define TC_FMR_ENCF0_Pos                      (0)                                            /**< (TC_FMR) Enable Compare Fault Channel 0 Position */
#define TC_FMR_ENCF0_Msk                      (0x1U << TC_FMR_ENCF0_Pos)                     /**< (TC_FMR) Enable Compare Fault Channel 0 Mask */
#define TC_FMR_ENCF1_Pos                      (1)                                            /**< (TC_FMR) Enable Compare Fault Channel 1 Position */
#define TC_FMR_ENCF1_Msk                      (0x1U << TC_FMR_ENCF1_Pos)                     /**< (TC_FMR) Enable Compare Fault Channel 1 Mask */
#define TC_FMR_Msk                            (0x00000003UL)                                 /**< (TC_FMR) Register Mask  */
#define TC_FMR_ENCF_Pos                       (0)                                            /**< (TC_FMR Position) Enable Compare Fault Channel x */
#define TC_FMR_ENCF_Msk                       (0x3U << TC_FMR_ENCF_Pos)                      /**< (TC_FMR Mask) ENCF */
#define TC_FMR_ENCF(value)                    (TC_FMR_ENCF_Msk & ((value) << TC_FMR_ENCF_Pos))

/* -------- TC_WPMR : (TC Offset: 0xe4) (R/W 32) Write Protection Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t WPEN:1;                    /**< bit:      0  Write Protection Enable                       */
    uint32_t :7;                        /**< bit:   1..7  Reserved                                      */
    uint32_t WPKEY:24;                  /**< bit:  8..31  Write Protection Key                          */
  };
  uint32_t w;
} __TC_WPMR_bits_t;

#define TC_WPMR_WPEN_Pos                      (0)                                            /**< (TC_WPMR) Write Protection Enable Position */
#define TC_WPMR_WPEN_Msk                      (0x1U << TC_WPMR_WPEN_Pos)                     /**< (TC_WPMR) Write Protection Enable Mask */
#define TC_WPMR_WPKEY_Pos                     (8)                                            /**< (TC_WPMR) Write Protection Key Position */
#define TC_WPMR_WPKEY_Msk                     (0xFFFFFFU << TC_WPMR_WPKEY_Pos)               /**< (TC_WPMR) Write Protection Key Mask */
#define TC_WPMR_WPKEY(value)                  (TC_WPMR_WPKEY_Msk & ((value) << TC_WPMR_WPKEY_Pos))
#define   TC_WPMR_WPKEY_PASSWD_Val            (0x54494DU)                                    /**< (TC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0.  */
#define TC_WPMR_WPKEY_PASSWD                  (TC_WPMR_WPKEY_PASSWD_Val << TC_WPMR_WPKEY_Pos)  /**< (TC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. Position  */
#define TC_WPMR_Msk                           (0xFFFFFF01UL)                                 /**< (TC_WPMR) Register Mask  */

/** \brief TC_CHANNEL register offsets definitions */
#define TC_CCR_OFFSET                (0x00)         /**< (TC_CCR) Channel Control Register (channel = 0) Offset */
#define TC_CMR_OFFSET                (0x04)         /**< (TC_CMR) Channel Mode Register (channel = 0) Offset */
#define TC_SMMR_OFFSET               (0x08)         /**< (TC_SMMR) Stepper Motor Mode Register (channel = 0) Offset */
#define TC_RAB_OFFSET                (0x0C)         /**< (TC_RAB) Register AB (channel = 0) Offset */
#define TC_CV_OFFSET                 (0x10)         /**< (TC_CV) Counter Value (channel = 0) Offset */
#define TC_RA_OFFSET                 (0x14)         /**< (TC_RA) Register A (channel = 0) Offset */
#define TC_RB_OFFSET                 (0x18)         /**< (TC_RB) Register B (channel = 0) Offset */
#define TC_RC_OFFSET                 (0x1C)         /**< (TC_RC) Register C (channel = 0) Offset */
#define TC_SR_OFFSET                 (0x20)         /**< (TC_SR) Status Register (channel = 0) Offset */
#define TC_IER_OFFSET                (0x24)         /**< (TC_IER) Interrupt Enable Register (channel = 0) Offset */
#define TC_IDR_OFFSET                (0x28)         /**< (TC_IDR) Interrupt Disable Register (channel = 0) Offset */
#define TC_IMR_OFFSET                (0x2C)         /**< (TC_IMR) Interrupt Mask Register (channel = 0) Offset */
#define TC_EMR_OFFSET                (0x30)         /**< (TC_EMR) Extended Mode Register (channel = 0) Offset */
/** \brief TC register offsets definitions */
#define TC_BCR_OFFSET                (0xC0)         /**< (TC_BCR) Block Control Register Offset */
#define TC_BMR_OFFSET                (0xC4)         /**< (TC_BMR) Block Mode Register Offset */
#define TC_QIER_OFFSET               (0xC8)         /**< (TC_QIER) QDEC Interrupt Enable Register Offset */
#define TC_QIDR_OFFSET               (0xCC)         /**< (TC_QIDR) QDEC Interrupt Disable Register Offset */
#define TC_QIMR_OFFSET               (0xD0)         /**< (TC_QIMR) QDEC Interrupt Mask Register Offset */
#define TC_QISR_OFFSET               (0xD4)         /**< (TC_QISR) QDEC Interrupt Status Register Offset */
#define TC_FMR_OFFSET                (0xD8)         /**< (TC_FMR) Fault Mode Register Offset */
#define TC_WPMR_OFFSET               (0xE4)         /**< (TC_WPMR) Write Protection Mode Register Offset */

/** \brief TC_CHANNEL register API structure */
typedef struct
{
  __O   __TC_CCR_bits_t                TC_CCR;        /**< Offset: 0x00 ( /W  32) Channel Control Register (channel = 0) */
  __IO  __TC_CMR_bits_t                TC_CMR;        /**< Offset: 0x04 (R/W  32) Channel Mode Register (channel = 0) */
  __IO  __TC_SMMR_bits_t               TC_SMMR;       /**< Offset: 0x08 (R/W  32) Stepper Motor Mode Register (channel = 0) */
  __I   __TC_RAB_bits_t                TC_RAB;        /**< Offset: 0x0C (R/   32) Register AB (channel = 0) */
  __I   __TC_CV_bits_t                 TC_CV;         /**< Offset: 0x10 (R/   32) Counter Value (channel = 0) */
  __IO  __TC_RA_bits_t                 TC_RA;         /**< Offset: 0x14 (R/W  32) Register A (channel = 0) */
  __IO  __TC_RB_bits_t                 TC_RB;         /**< Offset: 0x18 (R/W  32) Register B (channel = 0) */
  __IO  __TC_RC_bits_t                 TC_RC;         /**< Offset: 0x1C (R/W  32) Register C (channel = 0) */
  __I   __TC_SR_bits_t                 TC_SR;         /**< Offset: 0x20 (R/   32) Status Register (channel = 0) */
  __O   __TC_IER_bits_t                TC_IER;        /**< Offset: 0x24 ( /W  32) Interrupt Enable Register (channel = 0) */
  __O   __TC_IDR_bits_t                TC_IDR;        /**< Offset: 0x28 ( /W  32) Interrupt Disable Register (channel = 0) */
  __I   __TC_IMR_bits_t                TC_IMR;        /**< Offset: 0x2C (R/   32) Interrupt Mask Register (channel = 0) */
  __IO  __TC_EMR_bits_t                TC_EMR;        /**< Offset: 0x30 (R/W  32) Extended Mode Register (channel = 0) */
  __I   uint8_t                        Reserved1[0x0C];
} tcchannel_registers_t;

#define TCCHANNEL_NUMBER 3
/** \brief TC register API structure */
typedef struct
{
        tcchannel_registers_t          TC_CHANNEL[TCCHANNEL_NUMBER]; /**< Offset: 0x00 Channel Control Register (channel = 0) */
  __O   __TC_BCR_bits_t                TC_BCR;        /**< Offset: 0xC0 ( /W  32) Block Control Register */
  __IO  __TC_BMR_bits_t                TC_BMR;        /**< Offset: 0xC4 (R/W  32) Block Mode Register */
  __O   __TC_QIER_bits_t               TC_QIER;       /**< Offset: 0xC8 ( /W  32) QDEC Interrupt Enable Register */
  __O   __TC_QIDR_bits_t               TC_QIDR;       /**< Offset: 0xCC ( /W  32) QDEC Interrupt Disable Register */
  __I   __TC_QIMR_bits_t               TC_QIMR;       /**< Offset: 0xD0 (R/   32) QDEC Interrupt Mask Register */
  __I   __TC_QISR_bits_t               TC_QISR;       /**< Offset: 0xD4 (R/   32) QDEC Interrupt Status Register */
  __IO  __TC_FMR_bits_t                TC_FMR;        /**< Offset: 0xD8 (R/W  32) Fault Mode Register */
  __I   uint8_t                        Reserved1[0x08];
  __IO  __TC_WPMR_bits_t               TC_WPMR;       /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
} tc_registers_t;
/** @}  end of Timer Counter */

#endif /* _PIC32CZ_CA70_TC_COMPONENT_H_ */
