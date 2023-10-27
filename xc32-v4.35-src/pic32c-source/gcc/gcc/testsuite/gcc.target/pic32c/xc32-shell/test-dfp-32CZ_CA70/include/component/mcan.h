/**
 * \brief Component description for PIC32CZ/CA70 MCAN
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
#ifndef _PIC32CZ_CA70_MCAN_COMPONENT_H_
#define _PIC32CZ_CA70_MCAN_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_MCAN Controller Area Network
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR MCAN */
/* ========================================================================== */

/* -------- MCAN_CREL : (MCAN Offset: 0x00) (R/ 32) Core Release Register -------- */

typedef union
{
  struct
  {
    uint32_t DAY:8;                     /**< bit:   0..7  Timestamp Day                                 */
    uint32_t MON:8;                     /**< bit:  8..15  Timestamp Month                               */
    uint32_t YEAR:4;                    /**< bit: 16..19  Timestamp Year                                */
    uint32_t SUBSTEP:4;                 /**< bit: 20..23  Sub-step of Core Release                      */
    uint32_t STEP:4;                    /**< bit: 24..27  Step of Core Release                          */
    uint32_t REL:4;                     /**< bit: 28..31  Core Release                                  */
  };
  uint32_t w;
} __MCAN_CREL_bits_t;

#define MCAN_CREL_DAY_Pos                     (0)                                            /**< (MCAN_CREL) Timestamp Day Position */
#define MCAN_CREL_DAY_Msk                     (0xFFU << MCAN_CREL_DAY_Pos)                   /**< (MCAN_CREL) Timestamp Day Mask */
#define MCAN_CREL_DAY(value)                  (MCAN_CREL_DAY_Msk & ((value) << MCAN_CREL_DAY_Pos))
#define MCAN_CREL_MON_Pos                     (8)                                            /**< (MCAN_CREL) Timestamp Month Position */
#define MCAN_CREL_MON_Msk                     (0xFFU << MCAN_CREL_MON_Pos)                   /**< (MCAN_CREL) Timestamp Month Mask */
#define MCAN_CREL_MON(value)                  (MCAN_CREL_MON_Msk & ((value) << MCAN_CREL_MON_Pos))
#define MCAN_CREL_YEAR_Pos                    (16)                                           /**< (MCAN_CREL) Timestamp Year Position */
#define MCAN_CREL_YEAR_Msk                    (0xFU << MCAN_CREL_YEAR_Pos)                   /**< (MCAN_CREL) Timestamp Year Mask */
#define MCAN_CREL_YEAR(value)                 (MCAN_CREL_YEAR_Msk & ((value) << MCAN_CREL_YEAR_Pos))
#define MCAN_CREL_SUBSTEP_Pos                 (20)                                           /**< (MCAN_CREL) Sub-step of Core Release Position */
#define MCAN_CREL_SUBSTEP_Msk                 (0xFU << MCAN_CREL_SUBSTEP_Pos)                /**< (MCAN_CREL) Sub-step of Core Release Mask */
#define MCAN_CREL_SUBSTEP(value)              (MCAN_CREL_SUBSTEP_Msk & ((value) << MCAN_CREL_SUBSTEP_Pos))
#define MCAN_CREL_STEP_Pos                    (24)                                           /**< (MCAN_CREL) Step of Core Release Position */
#define MCAN_CREL_STEP_Msk                    (0xFU << MCAN_CREL_STEP_Pos)                   /**< (MCAN_CREL) Step of Core Release Mask */
#define MCAN_CREL_STEP(value)                 (MCAN_CREL_STEP_Msk & ((value) << MCAN_CREL_STEP_Pos))
#define MCAN_CREL_REL_Pos                     (28)                                           /**< (MCAN_CREL) Core Release Position */
#define MCAN_CREL_REL_Msk                     (0xFU << MCAN_CREL_REL_Pos)                    /**< (MCAN_CREL) Core Release Mask */
#define MCAN_CREL_REL(value)                  (MCAN_CREL_REL_Msk & ((value) << MCAN_CREL_REL_Pos))
#define MCAN_CREL_Msk                         (0xFFFFFFFFUL)                                 /**< (MCAN_CREL) Register Mask  */

/* -------- MCAN_ENDN : (MCAN Offset: 0x04) (R/ 32) Endian Register -------- */

typedef union
{
  struct
  {
    uint32_t ETV:32;                    /**< bit:  0..31  Endianness Test Value                         */
  };
  uint32_t w;
} __MCAN_ENDN_bits_t;

#define MCAN_ENDN_ETV_Pos                     (0)                                            /**< (MCAN_ENDN) Endianness Test Value Position */
#define MCAN_ENDN_ETV_Msk                     (0xFFFFFFFFU << MCAN_ENDN_ETV_Pos)             /**< (MCAN_ENDN) Endianness Test Value Mask */
#define MCAN_ENDN_ETV(value)                  (MCAN_ENDN_ETV_Msk & ((value) << MCAN_ENDN_ETV_Pos))
#define MCAN_ENDN_Msk                         (0xFFFFFFFFUL)                                 /**< (MCAN_ENDN) Register Mask  */

/* -------- MCAN_CUST : (MCAN Offset: 0x08) (R/W 32) Customer Register -------- */

typedef union
{
  struct
  {
    uint32_t CSV:32;                    /**< bit:  0..31  Customer-specific Value                       */
  };
  uint32_t w;
} __MCAN_CUST_bits_t;

#define MCAN_CUST_CSV_Pos                     (0)                                            /**< (MCAN_CUST) Customer-specific Value Position */
#define MCAN_CUST_CSV_Msk                     (0xFFFFFFFFU << MCAN_CUST_CSV_Pos)             /**< (MCAN_CUST) Customer-specific Value Mask */
#define MCAN_CUST_CSV(value)                  (MCAN_CUST_CSV_Msk & ((value) << MCAN_CUST_CSV_Pos))
#define MCAN_CUST_Msk                         (0xFFFFFFFFUL)                                 /**< (MCAN_CUST) Register Mask  */

/* -------- MCAN_DBTP : (MCAN Offset: 0x0c) (R/W 32) Data Bit Timing and Prescaler Register -------- */

typedef union
{
  struct
  {
    uint32_t DSJW:3;                    /**< bit:   0..2  Data (Re) Synchronization Jump Width          */
    uint32_t :1;                        /**< bit:      3  Reserved                                      */
    uint32_t DTSEG2:4;                  /**< bit:   4..7  Data Time Segment After Sample Point          */
    uint32_t DTSEG1:5;                  /**< bit:  8..12  Data Time Segment Before Sample Point         */
    uint32_t :3;                        /**< bit: 13..15  Reserved                                      */
    uint32_t DBRP:5;                    /**< bit: 16..20  Data Bit Rate Prescaler                       */
    uint32_t :2;                        /**< bit: 21..22  Reserved                                      */
    uint32_t TDC:1;                     /**< bit:     23  Transmitter Delay Compensation                */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_DBTP_bits_t;

#define MCAN_DBTP_DSJW_Pos                    (0)                                            /**< (MCAN_DBTP) Data (Re) Synchronization Jump Width Position */
#define MCAN_DBTP_DSJW_Msk                    (0x7U << MCAN_DBTP_DSJW_Pos)                   /**< (MCAN_DBTP) Data (Re) Synchronization Jump Width Mask */
#define MCAN_DBTP_DSJW(value)                 (MCAN_DBTP_DSJW_Msk & ((value) << MCAN_DBTP_DSJW_Pos))
#define MCAN_DBTP_DTSEG2_Pos                  (4)                                            /**< (MCAN_DBTP) Data Time Segment After Sample Point Position */
#define MCAN_DBTP_DTSEG2_Msk                  (0xFU << MCAN_DBTP_DTSEG2_Pos)                 /**< (MCAN_DBTP) Data Time Segment After Sample Point Mask */
#define MCAN_DBTP_DTSEG2(value)               (MCAN_DBTP_DTSEG2_Msk & ((value) << MCAN_DBTP_DTSEG2_Pos))
#define MCAN_DBTP_DTSEG1_Pos                  (8)                                            /**< (MCAN_DBTP) Data Time Segment Before Sample Point Position */
#define MCAN_DBTP_DTSEG1_Msk                  (0x1FU << MCAN_DBTP_DTSEG1_Pos)                /**< (MCAN_DBTP) Data Time Segment Before Sample Point Mask */
#define MCAN_DBTP_DTSEG1(value)               (MCAN_DBTP_DTSEG1_Msk & ((value) << MCAN_DBTP_DTSEG1_Pos))
#define MCAN_DBTP_DBRP_Pos                    (16)                                           /**< (MCAN_DBTP) Data Bit Rate Prescaler Position */
#define MCAN_DBTP_DBRP_Msk                    (0x1FU << MCAN_DBTP_DBRP_Pos)                  /**< (MCAN_DBTP) Data Bit Rate Prescaler Mask */
#define MCAN_DBTP_DBRP(value)                 (MCAN_DBTP_DBRP_Msk & ((value) << MCAN_DBTP_DBRP_Pos))
#define MCAN_DBTP_TDC_Pos                     (23)                                           /**< (MCAN_DBTP) Transmitter Delay Compensation Position */
#define MCAN_DBTP_TDC_Msk                     (0x1U << MCAN_DBTP_TDC_Pos)                    /**< (MCAN_DBTP) Transmitter Delay Compensation Mask */
#define   MCAN_DBTP_TDC_DISABLED_Val          (0x0U)                                         /**< (MCAN_DBTP) Transmitter Delay Compensation disabled.  */
#define   MCAN_DBTP_TDC_ENABLED_Val           (0x1U)                                         /**< (MCAN_DBTP) Transmitter Delay Compensation enabled.  */
#define MCAN_DBTP_TDC_DISABLED                (MCAN_DBTP_TDC_DISABLED_Val << MCAN_DBTP_TDC_Pos)  /**< (MCAN_DBTP) Transmitter Delay Compensation disabled. Position  */
#define MCAN_DBTP_TDC_ENABLED                 (MCAN_DBTP_TDC_ENABLED_Val << MCAN_DBTP_TDC_Pos)  /**< (MCAN_DBTP) Transmitter Delay Compensation enabled. Position  */
#define MCAN_DBTP_Msk                         (0x009F1FF7UL)                                 /**< (MCAN_DBTP) Register Mask  */

/* -------- MCAN_TEST : (MCAN Offset: 0x10) (R/W 32) Test Register -------- */

typedef union
{
  struct
  {
    uint32_t :4;                        /**< bit:   0..3  Reserved                                      */
    uint32_t LBCK:1;                    /**< bit:      4  Loop Back Mode (read/write)                   */
    uint32_t TX:2;                      /**< bit:   5..6  Control of Transmit Pin (read/write)          */
    uint32_t RX:1;                      /**< bit:      7  Receive Pin (read-only)                       */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_TEST_bits_t;

#define MCAN_TEST_LBCK_Pos                    (4)                                            /**< (MCAN_TEST) Loop Back Mode (read/write) Position */
#define MCAN_TEST_LBCK_Msk                    (0x1U << MCAN_TEST_LBCK_Pos)                   /**< (MCAN_TEST) Loop Back Mode (read/write) Mask */
#define   MCAN_TEST_LBCK_DISABLED_Val         (0x0U)                                         /**< (MCAN_TEST) Reset value. Loop Back mode is disabled.  */
#define   MCAN_TEST_LBCK_ENABLED_Val          (0x1U)                                         /**< (MCAN_TEST) Loop Back mode is enabled (see Section 6.1.9).  */
#define MCAN_TEST_LBCK_DISABLED               (MCAN_TEST_LBCK_DISABLED_Val << MCAN_TEST_LBCK_Pos)  /**< (MCAN_TEST) Reset value. Loop Back mode is disabled. Position  */
#define MCAN_TEST_LBCK_ENABLED                (MCAN_TEST_LBCK_ENABLED_Val << MCAN_TEST_LBCK_Pos)  /**< (MCAN_TEST) Loop Back mode is enabled (see Section 6.1.9). Position  */
#define MCAN_TEST_TX_Pos                      (5)                                            /**< (MCAN_TEST) Control of Transmit Pin (read/write) Position */
#define MCAN_TEST_TX_Msk                      (0x3U << MCAN_TEST_TX_Pos)                     /**< (MCAN_TEST) Control of Transmit Pin (read/write) Mask */
#define MCAN_TEST_TX(value)                   (MCAN_TEST_TX_Msk & ((value) << MCAN_TEST_TX_Pos))
#define   MCAN_TEST_TX_RESET_Val              (0x0U)                                         /**< (MCAN_TEST) Reset value, CANTX controlled by the CAN Core, updated at the end of the CAN bit time.  */
#define   MCAN_TEST_TX_SAMPLE_POINT_MONITORING_Val (0x1U)                                         /**< (MCAN_TEST) Sample Point can be monitored at pin CANTX.  */
#define   MCAN_TEST_TX_DOMINANT_Val           (0x2U)                                         /**< (MCAN_TEST) Dominant ('0') level at pin CANTX.  */
#define   MCAN_TEST_TX_RECESSIVE_Val          (0x3U)                                         /**< (MCAN_TEST) Recessive ('1') at pin CANTX.  */
#define MCAN_TEST_TX_RESET                    (MCAN_TEST_TX_RESET_Val << MCAN_TEST_TX_Pos)   /**< (MCAN_TEST) Reset value, CANTX controlled by the CAN Core, updated at the end of the CAN bit time. Position  */
#define MCAN_TEST_TX_SAMPLE_POINT_MONITORING  (MCAN_TEST_TX_SAMPLE_POINT_MONITORING_Val << MCAN_TEST_TX_Pos)  /**< (MCAN_TEST) Sample Point can be monitored at pin CANTX. Position  */
#define MCAN_TEST_TX_DOMINANT                 (MCAN_TEST_TX_DOMINANT_Val << MCAN_TEST_TX_Pos)  /**< (MCAN_TEST) Dominant ('0') level at pin CANTX. Position  */
#define MCAN_TEST_TX_RECESSIVE                (MCAN_TEST_TX_RECESSIVE_Val << MCAN_TEST_TX_Pos)  /**< (MCAN_TEST) Recessive ('1') at pin CANTX. Position  */
#define MCAN_TEST_RX_Pos                      (7)                                            /**< (MCAN_TEST) Receive Pin (read-only) Position */
#define MCAN_TEST_RX_Msk                      (0x1U << MCAN_TEST_RX_Pos)                     /**< (MCAN_TEST) Receive Pin (read-only) Mask */
#define MCAN_TEST_Msk                         (0x000000F0UL)                                 /**< (MCAN_TEST) Register Mask  */

/* -------- MCAN_RWD : (MCAN Offset: 0x14) (R/W 32) RAM Watchdog Register -------- */

typedef union
{
  struct
  {
    uint32_t WDC:8;                     /**< bit:   0..7  Watchdog Configuration (read/write)           */
    uint32_t WDV:8;                     /**< bit:  8..15  Watchdog Value (read-only)                    */
    uint32_t :16;                       /**< bit: 16..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_RWD_bits_t;

#define MCAN_RWD_WDC_Pos                      (0)                                            /**< (MCAN_RWD) Watchdog Configuration (read/write) Position */
#define MCAN_RWD_WDC_Msk                      (0xFFU << MCAN_RWD_WDC_Pos)                    /**< (MCAN_RWD) Watchdog Configuration (read/write) Mask */
#define MCAN_RWD_WDC(value)                   (MCAN_RWD_WDC_Msk & ((value) << MCAN_RWD_WDC_Pos))
#define MCAN_RWD_WDV_Pos                      (8)                                            /**< (MCAN_RWD) Watchdog Value (read-only) Position */
#define MCAN_RWD_WDV_Msk                      (0xFFU << MCAN_RWD_WDV_Pos)                    /**< (MCAN_RWD) Watchdog Value (read-only) Mask */
#define MCAN_RWD_WDV(value)                   (MCAN_RWD_WDV_Msk & ((value) << MCAN_RWD_WDV_Pos))
#define MCAN_RWD_Msk                          (0x0000FFFFUL)                                 /**< (MCAN_RWD) Register Mask  */

/* -------- MCAN_CCCR : (MCAN Offset: 0x18) (R/W 32) CC Control Register -------- */

typedef union
{
  struct
  {
    uint32_t INIT:1;                    /**< bit:      0  Initialization (read/write)                   */
    uint32_t CCE:1;                     /**< bit:      1  Configuration Change Enable (read/write, write protection) */
    uint32_t ASM:1;                     /**< bit:      2  Restricted Operation Mode (read/write, write protection against '1') */
    uint32_t CSA:1;                     /**< bit:      3  Clock Stop Acknowledge (read-only)            */
    uint32_t CSR:1;                     /**< bit:      4  Clock Stop Request (read/write)               */
    uint32_t MON:1;                     /**< bit:      5  Bus Monitoring Mode (read/write, write protection against '1') */
    uint32_t DAR:1;                     /**< bit:      6  Disable Automatic Retransmission (read/write, write protection) */
    uint32_t TEST:1;                    /**< bit:      7  Test Mode Enable (read/write, write protection against '1') */
    uint32_t FDOE:1;                    /**< bit:      8  CAN FD Operation Enable (read/write, write protection) */
    uint32_t BRSE:1;                    /**< bit:      9  Bit Rate Switching Enable (read/write, write protection) */
    uint32_t :2;                        /**< bit: 10..11  Reserved                                      */
    uint32_t PXHD:1;                    /**< bit:     12  Protocol Exception Event Handling (read/write, write protection) */
    uint32_t EFBI:1;                    /**< bit:     13  Edge Filtering during Bus Integration (read/write, write protection) */
    uint32_t TXP:1;                     /**< bit:     14  Transmit Pause (read/write, write protection) */
    uint32_t NISO:1;                    /**< bit:     15  Non-ISO Operation                             */
    uint32_t :16;                       /**< bit: 16..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_CCCR_bits_t;

#define MCAN_CCCR_INIT_Pos                    (0)                                            /**< (MCAN_CCCR) Initialization (read/write) Position */
#define MCAN_CCCR_INIT_Msk                    (0x1U << MCAN_CCCR_INIT_Pos)                   /**< (MCAN_CCCR) Initialization (read/write) Mask */
#define   MCAN_CCCR_INIT_DISABLED_Val         (0x0U)                                         /**< (MCAN_CCCR) Normal operation.  */
#define   MCAN_CCCR_INIT_ENABLED_Val          (0x1U)                                         /**< (MCAN_CCCR) Initialization is started.  */
#define MCAN_CCCR_INIT_DISABLED               (MCAN_CCCR_INIT_DISABLED_Val << MCAN_CCCR_INIT_Pos)  /**< (MCAN_CCCR) Normal operation. Position  */
#define MCAN_CCCR_INIT_ENABLED                (MCAN_CCCR_INIT_ENABLED_Val << MCAN_CCCR_INIT_Pos)  /**< (MCAN_CCCR) Initialization is started. Position  */
#define MCAN_CCCR_CCE_Pos                     (1)                                            /**< (MCAN_CCCR) Configuration Change Enable (read/write, write protection) Position */
#define MCAN_CCCR_CCE_Msk                     (0x1U << MCAN_CCCR_CCE_Pos)                    /**< (MCAN_CCCR) Configuration Change Enable (read/write, write protection) Mask */
#define   MCAN_CCCR_CCE_PROTECTED_Val         (0x0U)                                         /**< (MCAN_CCCR) The processor has no write access to the protected configuration registers.  */
#define   MCAN_CCCR_CCE_CONFIGURABLE_Val      (0x1U)                                         /**< (MCAN_CCCR) The processor has write access to the protected configuration registers (while MCAN_CCCR.INIT = '1').  */
#define MCAN_CCCR_CCE_PROTECTED               (MCAN_CCCR_CCE_PROTECTED_Val << MCAN_CCCR_CCE_Pos)  /**< (MCAN_CCCR) The processor has no write access to the protected configuration registers. Position  */
#define MCAN_CCCR_CCE_CONFIGURABLE            (MCAN_CCCR_CCE_CONFIGURABLE_Val << MCAN_CCCR_CCE_Pos)  /**< (MCAN_CCCR) The processor has write access to the protected configuration registers (while MCAN_CCCR.INIT = '1'). Position  */
#define MCAN_CCCR_ASM_Pos                     (2)                                            /**< (MCAN_CCCR) Restricted Operation Mode (read/write, write protection against '1') Position */
#define MCAN_CCCR_ASM_Msk                     (0x1U << MCAN_CCCR_ASM_Pos)                    /**< (MCAN_CCCR) Restricted Operation Mode (read/write, write protection against '1') Mask */
#define   MCAN_CCCR_ASM_NORMAL_Val            (0x0U)                                         /**< (MCAN_CCCR) Normal CAN operation.  */
#define   MCAN_CCCR_ASM_RESTRICTED_Val        (0x1U)                                         /**< (MCAN_CCCR) Restricted Operation mode active.  */
#define MCAN_CCCR_ASM_NORMAL                  (MCAN_CCCR_ASM_NORMAL_Val << MCAN_CCCR_ASM_Pos)  /**< (MCAN_CCCR) Normal CAN operation. Position  */
#define MCAN_CCCR_ASM_RESTRICTED              (MCAN_CCCR_ASM_RESTRICTED_Val << MCAN_CCCR_ASM_Pos)  /**< (MCAN_CCCR) Restricted Operation mode active. Position  */
#define MCAN_CCCR_CSA_Pos                     (3)                                            /**< (MCAN_CCCR) Clock Stop Acknowledge (read-only) Position */
#define MCAN_CCCR_CSA_Msk                     (0x1U << MCAN_CCCR_CSA_Pos)                    /**< (MCAN_CCCR) Clock Stop Acknowledge (read-only) Mask */
#define MCAN_CCCR_CSR_Pos                     (4)                                            /**< (MCAN_CCCR) Clock Stop Request (read/write) Position */
#define MCAN_CCCR_CSR_Msk                     (0x1U << MCAN_CCCR_CSR_Pos)                    /**< (MCAN_CCCR) Clock Stop Request (read/write) Mask */
#define   MCAN_CCCR_CSR_NO_CLOCK_STOP_Val     (0x0U)                                         /**< (MCAN_CCCR) No clock stop is requested.  */
#define   MCAN_CCCR_CSR_CLOCK_STOP_Val        (0x1U)                                         /**< (MCAN_CCCR) Clock stop requested. When clock stop is requested, first INIT and then CSA will be set after all pend-ing transfer requests have been completed and the CAN bus reached idle.  */
#define MCAN_CCCR_CSR_NO_CLOCK_STOP           (MCAN_CCCR_CSR_NO_CLOCK_STOP_Val << MCAN_CCCR_CSR_Pos)  /**< (MCAN_CCCR) No clock stop is requested. Position  */
#define MCAN_CCCR_CSR_CLOCK_STOP              (MCAN_CCCR_CSR_CLOCK_STOP_Val << MCAN_CCCR_CSR_Pos)  /**< (MCAN_CCCR) Clock stop requested. When clock stop is requested, first INIT and then CSA will be set after all pend-ing transfer requests have been completed and the CAN bus reached idle. Position  */
#define MCAN_CCCR_MON_Pos                     (5)                                            /**< (MCAN_CCCR) Bus Monitoring Mode (read/write, write protection against '1') Position */
#define MCAN_CCCR_MON_Msk                     (0x1U << MCAN_CCCR_MON_Pos)                    /**< (MCAN_CCCR) Bus Monitoring Mode (read/write, write protection against '1') Mask */
#define   MCAN_CCCR_MON_DISABLED_Val          (0x0U)                                         /**< (MCAN_CCCR) Bus Monitoring mode is disabled.  */
#define   MCAN_CCCR_MON_ENABLED_Val           (0x1U)                                         /**< (MCAN_CCCR) Bus Monitoring mode is enabled.  */
#define MCAN_CCCR_MON_DISABLED                (MCAN_CCCR_MON_DISABLED_Val << MCAN_CCCR_MON_Pos)  /**< (MCAN_CCCR) Bus Monitoring mode is disabled. Position  */
#define MCAN_CCCR_MON_ENABLED                 (MCAN_CCCR_MON_ENABLED_Val << MCAN_CCCR_MON_Pos)  /**< (MCAN_CCCR) Bus Monitoring mode is enabled. Position  */
#define MCAN_CCCR_DAR_Pos                     (6)                                            /**< (MCAN_CCCR) Disable Automatic Retransmission (read/write, write protection) Position */
#define MCAN_CCCR_DAR_Msk                     (0x1U << MCAN_CCCR_DAR_Pos)                    /**< (MCAN_CCCR) Disable Automatic Retransmission (read/write, write protection) Mask */
#define   MCAN_CCCR_DAR_AUTO_RETX_Val         (0x0U)                                         /**< (MCAN_CCCR) Automatic retransmission of messages not transmitted successfully enabled.  */
#define   MCAN_CCCR_DAR_NO_AUTO_RETX_Val      (0x1U)                                         /**< (MCAN_CCCR) Automatic retransmission disabled.  */
#define MCAN_CCCR_DAR_AUTO_RETX               (MCAN_CCCR_DAR_AUTO_RETX_Val << MCAN_CCCR_DAR_Pos)  /**< (MCAN_CCCR) Automatic retransmission of messages not transmitted successfully enabled. Position  */
#define MCAN_CCCR_DAR_NO_AUTO_RETX            (MCAN_CCCR_DAR_NO_AUTO_RETX_Val << MCAN_CCCR_DAR_Pos)  /**< (MCAN_CCCR) Automatic retransmission disabled. Position  */
#define MCAN_CCCR_TEST_Pos                    (7)                                            /**< (MCAN_CCCR) Test Mode Enable (read/write, write protection against '1') Position */
#define MCAN_CCCR_TEST_Msk                    (0x1U << MCAN_CCCR_TEST_Pos)                   /**< (MCAN_CCCR) Test Mode Enable (read/write, write protection against '1') Mask */
#define   MCAN_CCCR_TEST_DISABLED_Val         (0x0U)                                         /**< (MCAN_CCCR) Normal operation, MCAN_TEST register holds reset values.  */
#define   MCAN_CCCR_TEST_ENABLED_Val          (0x1U)                                         /**< (MCAN_CCCR) Test mode, write access to MCAN_TEST register enabled.  */
#define MCAN_CCCR_TEST_DISABLED               (MCAN_CCCR_TEST_DISABLED_Val << MCAN_CCCR_TEST_Pos)  /**< (MCAN_CCCR) Normal operation, MCAN_TEST register holds reset values. Position  */
#define MCAN_CCCR_TEST_ENABLED                (MCAN_CCCR_TEST_ENABLED_Val << MCAN_CCCR_TEST_Pos)  /**< (MCAN_CCCR) Test mode, write access to MCAN_TEST register enabled. Position  */
#define MCAN_CCCR_FDOE_Pos                    (8)                                            /**< (MCAN_CCCR) CAN FD Operation Enable (read/write, write protection) Position */
#define MCAN_CCCR_FDOE_Msk                    (0x1U << MCAN_CCCR_FDOE_Pos)                   /**< (MCAN_CCCR) CAN FD Operation Enable (read/write, write protection) Mask */
#define   MCAN_CCCR_FDOE_DISABLED_Val         (0x0U)                                         /**< (MCAN_CCCR) FD operation disabled.  */
#define   MCAN_CCCR_FDOE_ENABLED_Val          (0x1U)                                         /**< (MCAN_CCCR) FD operation enabled.  */
#define MCAN_CCCR_FDOE_DISABLED               (MCAN_CCCR_FDOE_DISABLED_Val << MCAN_CCCR_FDOE_Pos)  /**< (MCAN_CCCR) FD operation disabled. Position  */
#define MCAN_CCCR_FDOE_ENABLED                (MCAN_CCCR_FDOE_ENABLED_Val << MCAN_CCCR_FDOE_Pos)  /**< (MCAN_CCCR) FD operation enabled. Position  */
#define MCAN_CCCR_BRSE_Pos                    (9)                                            /**< (MCAN_CCCR) Bit Rate Switching Enable (read/write, write protection) Position */
#define MCAN_CCCR_BRSE_Msk                    (0x1U << MCAN_CCCR_BRSE_Pos)                   /**< (MCAN_CCCR) Bit Rate Switching Enable (read/write, write protection) Mask */
#define   MCAN_CCCR_BRSE_DISABLED_Val         (0x0U)                                         /**< (MCAN_CCCR) Bit rate switching for transmissions disabled.  */
#define   MCAN_CCCR_BRSE_ENABLED_Val          (0x1U)                                         /**< (MCAN_CCCR) Bit rate switching for transmissions enabled.  */
#define MCAN_CCCR_BRSE_DISABLED               (MCAN_CCCR_BRSE_DISABLED_Val << MCAN_CCCR_BRSE_Pos)  /**< (MCAN_CCCR) Bit rate switching for transmissions disabled. Position  */
#define MCAN_CCCR_BRSE_ENABLED                (MCAN_CCCR_BRSE_ENABLED_Val << MCAN_CCCR_BRSE_Pos)  /**< (MCAN_CCCR) Bit rate switching for transmissions enabled. Position  */
#define MCAN_CCCR_PXHD_Pos                    (12)                                           /**< (MCAN_CCCR) Protocol Exception Event Handling (read/write, write protection) Position */
#define MCAN_CCCR_PXHD_Msk                    (0x1U << MCAN_CCCR_PXHD_Pos)                   /**< (MCAN_CCCR) Protocol Exception Event Handling (read/write, write protection) Mask */
#define MCAN_CCCR_EFBI_Pos                    (13)                                           /**< (MCAN_CCCR) Edge Filtering during Bus Integration (read/write, write protection) Position */
#define MCAN_CCCR_EFBI_Msk                    (0x1U << MCAN_CCCR_EFBI_Pos)                   /**< (MCAN_CCCR) Edge Filtering during Bus Integration (read/write, write protection) Mask */
#define MCAN_CCCR_TXP_Pos                     (14)                                           /**< (MCAN_CCCR) Transmit Pause (read/write, write protection) Position */
#define MCAN_CCCR_TXP_Msk                     (0x1U << MCAN_CCCR_TXP_Pos)                    /**< (MCAN_CCCR) Transmit Pause (read/write, write protection) Mask */
#define MCAN_CCCR_NISO_Pos                    (15)                                           /**< (MCAN_CCCR) Non-ISO Operation Position */
#define MCAN_CCCR_NISO_Msk                    (0x1U << MCAN_CCCR_NISO_Pos)                   /**< (MCAN_CCCR) Non-ISO Operation Mask */
#define MCAN_CCCR_Msk                         (0x0000F3FFUL)                                 /**< (MCAN_CCCR) Register Mask  */

/* -------- MCAN_NBTP : (MCAN Offset: 0x1c) (R/W 32) Nominal Bit Timing and Prescaler Register -------- */

typedef union
{
  struct
  {
    uint32_t NTSEG2:7;                  /**< bit:   0..6  Nominal Time Segment After Sample Point       */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t NTSEG1:8;                  /**< bit:  8..15  Nominal Time Segment Before Sample Point      */
    uint32_t NBRP:9;                    /**< bit: 16..24  Nominal Bit Rate Prescaler                    */
    uint32_t NSJW:7;                    /**< bit: 25..31  Nominal (Re) Synchronization Jump Width       */
  };
  uint32_t w;
} __MCAN_NBTP_bits_t;

#define MCAN_NBTP_NTSEG2_Pos                  (0)                                            /**< (MCAN_NBTP) Nominal Time Segment After Sample Point Position */
#define MCAN_NBTP_NTSEG2_Msk                  (0x7FU << MCAN_NBTP_NTSEG2_Pos)                /**< (MCAN_NBTP) Nominal Time Segment After Sample Point Mask */
#define MCAN_NBTP_NTSEG2(value)               (MCAN_NBTP_NTSEG2_Msk & ((value) << MCAN_NBTP_NTSEG2_Pos))
#define MCAN_NBTP_NTSEG1_Pos                  (8)                                            /**< (MCAN_NBTP) Nominal Time Segment Before Sample Point Position */
#define MCAN_NBTP_NTSEG1_Msk                  (0xFFU << MCAN_NBTP_NTSEG1_Pos)                /**< (MCAN_NBTP) Nominal Time Segment Before Sample Point Mask */
#define MCAN_NBTP_NTSEG1(value)               (MCAN_NBTP_NTSEG1_Msk & ((value) << MCAN_NBTP_NTSEG1_Pos))
#define MCAN_NBTP_NBRP_Pos                    (16)                                           /**< (MCAN_NBTP) Nominal Bit Rate Prescaler Position */
#define MCAN_NBTP_NBRP_Msk                    (0x1FFU << MCAN_NBTP_NBRP_Pos)                 /**< (MCAN_NBTP) Nominal Bit Rate Prescaler Mask */
#define MCAN_NBTP_NBRP(value)                 (MCAN_NBTP_NBRP_Msk & ((value) << MCAN_NBTP_NBRP_Pos))
#define MCAN_NBTP_NSJW_Pos                    (25)                                           /**< (MCAN_NBTP) Nominal (Re) Synchronization Jump Width Position */
#define MCAN_NBTP_NSJW_Msk                    (0x7FU << MCAN_NBTP_NSJW_Pos)                  /**< (MCAN_NBTP) Nominal (Re) Synchronization Jump Width Mask */
#define MCAN_NBTP_NSJW(value)                 (MCAN_NBTP_NSJW_Msk & ((value) << MCAN_NBTP_NSJW_Pos))
#define MCAN_NBTP_Msk                         (0xFFFFFF7FUL)                                 /**< (MCAN_NBTP) Register Mask  */

/* -------- MCAN_TSCC : (MCAN Offset: 0x20) (R/W 32) Timestamp Counter Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t TSS:2;                     /**< bit:   0..1  Timestamp Select                              */
    uint32_t :14;                       /**< bit:  2..15  Reserved                                      */
    uint32_t TCP:4;                     /**< bit: 16..19  Timestamp Counter Prescaler                   */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_TSCC_bits_t;

#define MCAN_TSCC_TSS_Pos                     (0)                                            /**< (MCAN_TSCC) Timestamp Select Position */
#define MCAN_TSCC_TSS_Msk                     (0x3U << MCAN_TSCC_TSS_Pos)                    /**< (MCAN_TSCC) Timestamp Select Mask */
#define MCAN_TSCC_TSS(value)                  (MCAN_TSCC_TSS_Msk & ((value) << MCAN_TSCC_TSS_Pos))
#define   MCAN_TSCC_TSS_ALWAYS_0_Val          (0x0U)                                         /**< (MCAN_TSCC) Timestamp counter value always 0x0000  */
#define   MCAN_TSCC_TSS_TCP_INC_Val           (0x1U)                                         /**< (MCAN_TSCC) Timestamp counter value incremented according to TCP  */
#define   MCAN_TSCC_TSS_EXT_TIMESTAMP_Val     (0x2U)                                         /**< (MCAN_TSCC) External timestamp counter value used  */
#define MCAN_TSCC_TSS_ALWAYS_0                (MCAN_TSCC_TSS_ALWAYS_0_Val << MCAN_TSCC_TSS_Pos)  /**< (MCAN_TSCC) Timestamp counter value always 0x0000 Position  */
#define MCAN_TSCC_TSS_TCP_INC                 (MCAN_TSCC_TSS_TCP_INC_Val << MCAN_TSCC_TSS_Pos)  /**< (MCAN_TSCC) Timestamp counter value incremented according to TCP Position  */
#define MCAN_TSCC_TSS_EXT_TIMESTAMP           (MCAN_TSCC_TSS_EXT_TIMESTAMP_Val << MCAN_TSCC_TSS_Pos)  /**< (MCAN_TSCC) External timestamp counter value used Position  */
#define MCAN_TSCC_TCP_Pos                     (16)                                           /**< (MCAN_TSCC) Timestamp Counter Prescaler Position */
#define MCAN_TSCC_TCP_Msk                     (0xFU << MCAN_TSCC_TCP_Pos)                    /**< (MCAN_TSCC) Timestamp Counter Prescaler Mask */
#define MCAN_TSCC_TCP(value)                  (MCAN_TSCC_TCP_Msk & ((value) << MCAN_TSCC_TCP_Pos))
#define MCAN_TSCC_Msk                         (0x000F0003UL)                                 /**< (MCAN_TSCC) Register Mask  */

/* -------- MCAN_TSCV : (MCAN Offset: 0x24) (R/W 32) Timestamp Counter Value Register -------- */

typedef union
{
  struct
  {
    uint32_t TSC:16;                    /**< bit:  0..15  Timestamp Counter (cleared on write)          */
    uint32_t :16;                       /**< bit: 16..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_TSCV_bits_t;

#define MCAN_TSCV_TSC_Pos                     (0)                                            /**< (MCAN_TSCV) Timestamp Counter (cleared on write) Position */
#define MCAN_TSCV_TSC_Msk                     (0xFFFFU << MCAN_TSCV_TSC_Pos)                 /**< (MCAN_TSCV) Timestamp Counter (cleared on write) Mask */
#define MCAN_TSCV_TSC(value)                  (MCAN_TSCV_TSC_Msk & ((value) << MCAN_TSCV_TSC_Pos))
#define MCAN_TSCV_Msk                         (0x0000FFFFUL)                                 /**< (MCAN_TSCV) Register Mask  */

/* -------- MCAN_TOCC : (MCAN Offset: 0x28) (R/W 32) Timeout Counter Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t ETOC:1;                    /**< bit:      0  Enable Timeout Counter                        */
    uint32_t TOS:2;                     /**< bit:   1..2  Timeout Select                                */
    uint32_t :13;                       /**< bit:  3..15  Reserved                                      */
    uint32_t TOP:16;                    /**< bit: 16..31  Timeout Period                                */
  };
  uint32_t w;
} __MCAN_TOCC_bits_t;

#define MCAN_TOCC_ETOC_Pos                    (0)                                            /**< (MCAN_TOCC) Enable Timeout Counter Position */
#define MCAN_TOCC_ETOC_Msk                    (0x1U << MCAN_TOCC_ETOC_Pos)                   /**< (MCAN_TOCC) Enable Timeout Counter Mask */
#define   MCAN_TOCC_ETOC_NO_TIMEOUT_Val       (0x0U)                                         /**< (MCAN_TOCC) Timeout Counter disabled.  */
#define   MCAN_TOCC_ETOC_TOS_CONTROLLED_Val   (0x1U)                                         /**< (MCAN_TOCC) Timeout Counter enabled.  */
#define MCAN_TOCC_ETOC_NO_TIMEOUT             (MCAN_TOCC_ETOC_NO_TIMEOUT_Val << MCAN_TOCC_ETOC_Pos)  /**< (MCAN_TOCC) Timeout Counter disabled. Position  */
#define MCAN_TOCC_ETOC_TOS_CONTROLLED         (MCAN_TOCC_ETOC_TOS_CONTROLLED_Val << MCAN_TOCC_ETOC_Pos)  /**< (MCAN_TOCC) Timeout Counter enabled. Position  */
#define MCAN_TOCC_TOS_Pos                     (1)                                            /**< (MCAN_TOCC) Timeout Select Position */
#define MCAN_TOCC_TOS_Msk                     (0x3U << MCAN_TOCC_TOS_Pos)                    /**< (MCAN_TOCC) Timeout Select Mask */
#define MCAN_TOCC_TOS(value)                  (MCAN_TOCC_TOS_Msk & ((value) << MCAN_TOCC_TOS_Pos))
#define   MCAN_TOCC_TOS_CONTINUOUS_Val        (0x0U)                                         /**< (MCAN_TOCC) Continuous operation  */
#define   MCAN_TOCC_TOS_TX_EV_TIMEOUT_Val     (0x1U)                                         /**< (MCAN_TOCC) Timeout controlled by Tx Event FIFO  */
#define   MCAN_TOCC_TOS_RX0_EV_TIMEOUT_Val    (0x2U)                                         /**< (MCAN_TOCC) Timeout controlled by Receive FIFO 0  */
#define   MCAN_TOCC_TOS_RX1_EV_TIMEOUT_Val    (0x3U)                                         /**< (MCAN_TOCC) Timeout controlled by Receive FIFO 1  */
#define MCAN_TOCC_TOS_CONTINUOUS              (MCAN_TOCC_TOS_CONTINUOUS_Val << MCAN_TOCC_TOS_Pos)  /**< (MCAN_TOCC) Continuous operation Position  */
#define MCAN_TOCC_TOS_TX_EV_TIMEOUT           (MCAN_TOCC_TOS_TX_EV_TIMEOUT_Val << MCAN_TOCC_TOS_Pos)  /**< (MCAN_TOCC) Timeout controlled by Tx Event FIFO Position  */
#define MCAN_TOCC_TOS_RX0_EV_TIMEOUT          (MCAN_TOCC_TOS_RX0_EV_TIMEOUT_Val << MCAN_TOCC_TOS_Pos)  /**< (MCAN_TOCC) Timeout controlled by Receive FIFO 0 Position  */
#define MCAN_TOCC_TOS_RX1_EV_TIMEOUT          (MCAN_TOCC_TOS_RX1_EV_TIMEOUT_Val << MCAN_TOCC_TOS_Pos)  /**< (MCAN_TOCC) Timeout controlled by Receive FIFO 1 Position  */
#define MCAN_TOCC_TOP_Pos                     (16)                                           /**< (MCAN_TOCC) Timeout Period Position */
#define MCAN_TOCC_TOP_Msk                     (0xFFFFU << MCAN_TOCC_TOP_Pos)                 /**< (MCAN_TOCC) Timeout Period Mask */
#define MCAN_TOCC_TOP(value)                  (MCAN_TOCC_TOP_Msk & ((value) << MCAN_TOCC_TOP_Pos))
#define MCAN_TOCC_Msk                         (0xFFFF0007UL)                                 /**< (MCAN_TOCC) Register Mask  */

/* -------- MCAN_TOCV : (MCAN Offset: 0x2c) (R/W 32) Timeout Counter Value Register -------- */

typedef union
{
  struct
  {
    uint32_t TOC:16;                    /**< bit:  0..15  Timeout Counter (cleared on write)            */
    uint32_t :16;                       /**< bit: 16..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_TOCV_bits_t;

#define MCAN_TOCV_TOC_Pos                     (0)                                            /**< (MCAN_TOCV) Timeout Counter (cleared on write) Position */
#define MCAN_TOCV_TOC_Msk                     (0xFFFFU << MCAN_TOCV_TOC_Pos)                 /**< (MCAN_TOCV) Timeout Counter (cleared on write) Mask */
#define MCAN_TOCV_TOC(value)                  (MCAN_TOCV_TOC_Msk & ((value) << MCAN_TOCV_TOC_Pos))
#define MCAN_TOCV_Msk                         (0x0000FFFFUL)                                 /**< (MCAN_TOCV) Register Mask  */

/* -------- MCAN_ECR : (MCAN Offset: 0x40) (R/ 32) Error Counter Register -------- */

typedef union
{
  struct
  {
    uint32_t TEC:8;                     /**< bit:   0..7  Transmit Error Counter                        */
    uint32_t REC:7;                     /**< bit:  8..14  Receive Error Counter                         */
    uint32_t RP:1;                      /**< bit:     15  Receive Error Passive                         */
    uint32_t CEL:8;                     /**< bit: 16..23  CAN Error Logging (cleared on read)           */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_ECR_bits_t;

#define MCAN_ECR_TEC_Pos                      (0)                                            /**< (MCAN_ECR) Transmit Error Counter Position */
#define MCAN_ECR_TEC_Msk                      (0xFFU << MCAN_ECR_TEC_Pos)                    /**< (MCAN_ECR) Transmit Error Counter Mask */
#define MCAN_ECR_TEC(value)                   (MCAN_ECR_TEC_Msk & ((value) << MCAN_ECR_TEC_Pos))
#define MCAN_ECR_REC_Pos                      (8)                                            /**< (MCAN_ECR) Receive Error Counter Position */
#define MCAN_ECR_REC_Msk                      (0x7FU << MCAN_ECR_REC_Pos)                    /**< (MCAN_ECR) Receive Error Counter Mask */
#define MCAN_ECR_REC(value)                   (MCAN_ECR_REC_Msk & ((value) << MCAN_ECR_REC_Pos))
#define MCAN_ECR_RP_Pos                       (15)                                           /**< (MCAN_ECR) Receive Error Passive Position */
#define MCAN_ECR_RP_Msk                       (0x1U << MCAN_ECR_RP_Pos)                      /**< (MCAN_ECR) Receive Error Passive Mask */
#define MCAN_ECR_CEL_Pos                      (16)                                           /**< (MCAN_ECR) CAN Error Logging (cleared on read) Position */
#define MCAN_ECR_CEL_Msk                      (0xFFU << MCAN_ECR_CEL_Pos)                    /**< (MCAN_ECR) CAN Error Logging (cleared on read) Mask */
#define MCAN_ECR_CEL(value)                   (MCAN_ECR_CEL_Msk & ((value) << MCAN_ECR_CEL_Pos))
#define MCAN_ECR_Msk                          (0x00FFFFFFUL)                                 /**< (MCAN_ECR) Register Mask  */

/* -------- MCAN_PSR : (MCAN Offset: 0x44) (R/ 32) Protocol Status Register -------- */

typedef union
{
  struct
  {
    uint32_t LEC:3;                     /**< bit:   0..2  Last Error Code (set to 111 on read)          */
    uint32_t ACT:2;                     /**< bit:   3..4  Activity                                      */
    uint32_t EP:1;                      /**< bit:      5  Error Passive                                 */
    uint32_t EW:1;                      /**< bit:      6  Warning Status                                */
    uint32_t BO:1;                      /**< bit:      7  Bus_Off Status                                */
    uint32_t DLEC:3;                    /**< bit:  8..10  Data Phase Last Error Code (set to 111 on read) */
    uint32_t RESI:1;                    /**< bit:     11  ESI Flag of Last Received CAN FD Message (cleared on read) */
    uint32_t RBRS:1;                    /**< bit:     12  BRS Flag of Last Received CAN FD Message (cleared on read) */
    uint32_t RFDF:1;                    /**< bit:     13  Received a CAN FD Message (cleared on read)   */
    uint32_t PXE:1;                     /**< bit:     14  Protocol Exception Event (cleared on read)    */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t TDCV:7;                    /**< bit: 16..22  Transmitter Delay Compensation Value          */
    uint32_t :9;                        /**< bit: 23..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_PSR_bits_t;

#define MCAN_PSR_LEC_Pos                      (0)                                            /**< (MCAN_PSR) Last Error Code (set to 111 on read) Position */
#define MCAN_PSR_LEC_Msk                      (0x7U << MCAN_PSR_LEC_Pos)                     /**< (MCAN_PSR) Last Error Code (set to 111 on read) Mask */
#define MCAN_PSR_LEC(value)                   (MCAN_PSR_LEC_Msk & ((value) << MCAN_PSR_LEC_Pos))
#define   MCAN_PSR_LEC_NO_ERROR_Val           (0x0U)                                         /**< (MCAN_PSR) No error occurred since LEC has been reset by successful reception or transmission.  */
#define   MCAN_PSR_LEC_STUFF_ERROR_Val        (0x1U)                                         /**< (MCAN_PSR) More than 5 equal bits in a sequence have occurred in a part of a received message where this is not allowed.  */
#define   MCAN_PSR_LEC_FORM_ERROR_Val         (0x2U)                                         /**< (MCAN_PSR) A fixed format part of a received frame has the wrong format.  */
#define   MCAN_PSR_LEC_ACK_ERROR_Val          (0x3U)                                         /**< (MCAN_PSR) The message transmitted by the MCAN was not acknowledged by another node.  */
#define   MCAN_PSR_LEC_BIT1_ERROR_Val         (0x4U)                                         /**< (MCAN_PSR) During transmission of a message (with the exception of the arbitration field), the device tried to send a recessive level (bit of logical value '1'), but the monitored bus value was dominant.  */
#define   MCAN_PSR_LEC_BIT0_ERROR_Val         (0x5U)                                         /**< (MCAN_PSR) During transmission of a message (or acknowledge bit, or active error flag, or overload flag), the device tried to send a dominant level (data or identifier bit logical value '0'), but the monitored bus value was recessive. During Bus_Off recovery, this status is set each time a sequence of 11 recessive bits has been monitored. This enables the processor to monitor the proceeding of the Bus_Off recovery sequence (indicating the bus is not stuck at dominant or continuously disturbed).  */
#define   MCAN_PSR_LEC_CRC_ERROR_Val          (0x6U)                                         /**< (MCAN_PSR) The CRC check sum of a received message was incorrect. The CRC of an incoming message does not match the CRC calculated from the received data.  */
#define   MCAN_PSR_LEC_NO_CHANGE_Val          (0x7U)                                         /**< (MCAN_PSR) Any read access to the Protocol Status Register re-initializes the LEC to '7'. When the LEC shows value '7', no CAN bus event was detected since the last processor read access to the Protocol Status Register.  */
#define MCAN_PSR_LEC_NO_ERROR                 (MCAN_PSR_LEC_NO_ERROR_Val << MCAN_PSR_LEC_Pos)  /**< (MCAN_PSR) No error occurred since LEC has been reset by successful reception or transmission. Position  */
#define MCAN_PSR_LEC_STUFF_ERROR              (MCAN_PSR_LEC_STUFF_ERROR_Val << MCAN_PSR_LEC_Pos)  /**< (MCAN_PSR) More than 5 equal bits in a sequence have occurred in a part of a received message where this is not allowed. Position  */
#define MCAN_PSR_LEC_FORM_ERROR               (MCAN_PSR_LEC_FORM_ERROR_Val << MCAN_PSR_LEC_Pos)  /**< (MCAN_PSR) A fixed format part of a received frame has the wrong format. Position  */
#define MCAN_PSR_LEC_ACK_ERROR                (MCAN_PSR_LEC_ACK_ERROR_Val << MCAN_PSR_LEC_Pos)  /**< (MCAN_PSR) The message transmitted by the MCAN was not acknowledged by another node. Position  */
#define MCAN_PSR_LEC_BIT1_ERROR               (MCAN_PSR_LEC_BIT1_ERROR_Val << MCAN_PSR_LEC_Pos)  /**< (MCAN_PSR) During transmission of a message (with the exception of the arbitration field), the device tried to send a recessive level (bit of logical value '1'), but the monitored bus value was dominant. Position  */
#define MCAN_PSR_LEC_BIT0_ERROR               (MCAN_PSR_LEC_BIT0_ERROR_Val << MCAN_PSR_LEC_Pos)  /**< (MCAN_PSR) During transmission of a message (or acknowledge bit, or active error flag, or overload flag), the device tried to send a dominant level (data or identifier bit logical value '0'), but the monitored bus value was recessive. During Bus_Off recovery, this status is set each time a sequence of 11 recessive bits has been monitored. This enables the processor to monitor the proceeding of the Bus_Off recovery sequence (indicating the bus is not stuck at dominant or continuously disturbed). Position  */
#define MCAN_PSR_LEC_CRC_ERROR                (MCAN_PSR_LEC_CRC_ERROR_Val << MCAN_PSR_LEC_Pos)  /**< (MCAN_PSR) The CRC check sum of a received message was incorrect. The CRC of an incoming message does not match the CRC calculated from the received data. Position  */
#define MCAN_PSR_LEC_NO_CHANGE                (MCAN_PSR_LEC_NO_CHANGE_Val << MCAN_PSR_LEC_Pos)  /**< (MCAN_PSR) Any read access to the Protocol Status Register re-initializes the LEC to '7'. When the LEC shows value '7', no CAN bus event was detected since the last processor read access to the Protocol Status Register. Position  */
#define MCAN_PSR_ACT_Pos                      (3)                                            /**< (MCAN_PSR) Activity Position */
#define MCAN_PSR_ACT_Msk                      (0x3U << MCAN_PSR_ACT_Pos)                     /**< (MCAN_PSR) Activity Mask */
#define MCAN_PSR_ACT(value)                   (MCAN_PSR_ACT_Msk & ((value) << MCAN_PSR_ACT_Pos))
#define   MCAN_PSR_ACT_SYNCHRONIZING_Val      (0x0U)                                         /**< (MCAN_PSR) Node is synchronizing on CAN communication  */
#define   MCAN_PSR_ACT_IDLE_Val               (0x1U)                                         /**< (MCAN_PSR) Node is neither receiver nor transmitter  */
#define   MCAN_PSR_ACT_RECEIVER_Val           (0x2U)                                         /**< (MCAN_PSR) Node is operating as receiver  */
#define   MCAN_PSR_ACT_TRANSMITTER_Val        (0x3U)                                         /**< (MCAN_PSR) Node is operating as transmitter  */
#define MCAN_PSR_ACT_SYNCHRONIZING            (MCAN_PSR_ACT_SYNCHRONIZING_Val << MCAN_PSR_ACT_Pos)  /**< (MCAN_PSR) Node is synchronizing on CAN communication Position  */
#define MCAN_PSR_ACT_IDLE                     (MCAN_PSR_ACT_IDLE_Val << MCAN_PSR_ACT_Pos)    /**< (MCAN_PSR) Node is neither receiver nor transmitter Position  */
#define MCAN_PSR_ACT_RECEIVER                 (MCAN_PSR_ACT_RECEIVER_Val << MCAN_PSR_ACT_Pos)  /**< (MCAN_PSR) Node is operating as receiver Position  */
#define MCAN_PSR_ACT_TRANSMITTER              (MCAN_PSR_ACT_TRANSMITTER_Val << MCAN_PSR_ACT_Pos)  /**< (MCAN_PSR) Node is operating as transmitter Position  */
#define MCAN_PSR_EP_Pos                       (5)                                            /**< (MCAN_PSR) Error Passive Position */
#define MCAN_PSR_EP_Msk                       (0x1U << MCAN_PSR_EP_Pos)                      /**< (MCAN_PSR) Error Passive Mask */
#define MCAN_PSR_EW_Pos                       (6)                                            /**< (MCAN_PSR) Warning Status Position */
#define MCAN_PSR_EW_Msk                       (0x1U << MCAN_PSR_EW_Pos)                      /**< (MCAN_PSR) Warning Status Mask */
#define MCAN_PSR_BO_Pos                       (7)                                            /**< (MCAN_PSR) Bus_Off Status Position */
#define MCAN_PSR_BO_Msk                       (0x1U << MCAN_PSR_BO_Pos)                      /**< (MCAN_PSR) Bus_Off Status Mask */
#define MCAN_PSR_DLEC_Pos                     (8)                                            /**< (MCAN_PSR) Data Phase Last Error Code (set to 111 on read) Position */
#define MCAN_PSR_DLEC_Msk                     (0x7U << MCAN_PSR_DLEC_Pos)                    /**< (MCAN_PSR) Data Phase Last Error Code (set to 111 on read) Mask */
#define MCAN_PSR_DLEC(value)                  (MCAN_PSR_DLEC_Msk & ((value) << MCAN_PSR_DLEC_Pos))
#define MCAN_PSR_RESI_Pos                     (11)                                           /**< (MCAN_PSR) ESI Flag of Last Received CAN FD Message (cleared on read) Position */
#define MCAN_PSR_RESI_Msk                     (0x1U << MCAN_PSR_RESI_Pos)                    /**< (MCAN_PSR) ESI Flag of Last Received CAN FD Message (cleared on read) Mask */
#define MCAN_PSR_RBRS_Pos                     (12)                                           /**< (MCAN_PSR) BRS Flag of Last Received CAN FD Message (cleared on read) Position */
#define MCAN_PSR_RBRS_Msk                     (0x1U << MCAN_PSR_RBRS_Pos)                    /**< (MCAN_PSR) BRS Flag of Last Received CAN FD Message (cleared on read) Mask */
#define MCAN_PSR_RFDF_Pos                     (13)                                           /**< (MCAN_PSR) Received a CAN FD Message (cleared on read) Position */
#define MCAN_PSR_RFDF_Msk                     (0x1U << MCAN_PSR_RFDF_Pos)                    /**< (MCAN_PSR) Received a CAN FD Message (cleared on read) Mask */
#define MCAN_PSR_PXE_Pos                      (14)                                           /**< (MCAN_PSR) Protocol Exception Event (cleared on read) Position */
#define MCAN_PSR_PXE_Msk                      (0x1U << MCAN_PSR_PXE_Pos)                     /**< (MCAN_PSR) Protocol Exception Event (cleared on read) Mask */
#define MCAN_PSR_TDCV_Pos                     (16)                                           /**< (MCAN_PSR) Transmitter Delay Compensation Value Position */
#define MCAN_PSR_TDCV_Msk                     (0x7FU << MCAN_PSR_TDCV_Pos)                   /**< (MCAN_PSR) Transmitter Delay Compensation Value Mask */
#define MCAN_PSR_TDCV(value)                  (MCAN_PSR_TDCV_Msk & ((value) << MCAN_PSR_TDCV_Pos))
#define MCAN_PSR_Msk                          (0x007F7FFFUL)                                 /**< (MCAN_PSR) Register Mask  */

/* -------- MCAN_TDCR : (MCAN Offset: 0x48) (R/W 32) Transmit Delay Compensation Register -------- */

typedef union
{
  struct
  {
    uint32_t TDCF:7;                    /**< bit:   0..6  Transmitter Delay Compensation Filter         */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t TDCO:7;                    /**< bit:  8..14  Transmitter Delay Compensation Offset         */
    uint32_t :17;                       /**< bit: 15..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_TDCR_bits_t;

#define MCAN_TDCR_TDCF_Pos                    (0)                                            /**< (MCAN_TDCR) Transmitter Delay Compensation Filter Position */
#define MCAN_TDCR_TDCF_Msk                    (0x7FU << MCAN_TDCR_TDCF_Pos)                  /**< (MCAN_TDCR) Transmitter Delay Compensation Filter Mask */
#define MCAN_TDCR_TDCF(value)                 (MCAN_TDCR_TDCF_Msk & ((value) << MCAN_TDCR_TDCF_Pos))
#define MCAN_TDCR_TDCO_Pos                    (8)                                            /**< (MCAN_TDCR) Transmitter Delay Compensation Offset Position */
#define MCAN_TDCR_TDCO_Msk                    (0x7FU << MCAN_TDCR_TDCO_Pos)                  /**< (MCAN_TDCR) Transmitter Delay Compensation Offset Mask */
#define MCAN_TDCR_TDCO(value)                 (MCAN_TDCR_TDCO_Msk & ((value) << MCAN_TDCR_TDCO_Pos))
#define MCAN_TDCR_Msk                         (0x00007F7FUL)                                 /**< (MCAN_TDCR) Register Mask  */

/* -------- MCAN_IR : (MCAN Offset: 0x50) (R/W 32) Interrupt Register -------- */

typedef union
{
  struct
  {
    uint32_t RF0N:1;                    /**< bit:      0  Receive FIFO 0 New Message                    */
    uint32_t RF0W:1;                    /**< bit:      1  Receive FIFO 0 Watermark Reached              */
    uint32_t RF0F:1;                    /**< bit:      2  Receive FIFO 0 Full                           */
    uint32_t RF0L:1;                    /**< bit:      3  Receive FIFO 0 Message Lost                   */
    uint32_t RF1N:1;                    /**< bit:      4  Receive FIFO 1 New Message                    */
    uint32_t RF1W:1;                    /**< bit:      5  Receive FIFO 1 Watermark Reached              */
    uint32_t RF1F:1;                    /**< bit:      6  Receive FIFO 1 Full                           */
    uint32_t RF1L:1;                    /**< bit:      7  Receive FIFO 1 Message Lost                   */
    uint32_t HPM:1;                     /**< bit:      8  High Priority Message                         */
    uint32_t TC:1;                      /**< bit:      9  Transmission Completed                        */
    uint32_t TCF:1;                     /**< bit:     10  Transmission Cancellation Finished            */
    uint32_t TFE:1;                     /**< bit:     11  Tx FIFO Empty                                 */
    uint32_t TEFN:1;                    /**< bit:     12  Tx Event FIFO New Entry                       */
    uint32_t TEFW:1;                    /**< bit:     13  Tx Event FIFO Watermark Reached               */
    uint32_t TEFF:1;                    /**< bit:     14  Tx Event FIFO Full                            */
    uint32_t TEFL:1;                    /**< bit:     15  Tx Event FIFO Element Lost                    */
    uint32_t TSW:1;                     /**< bit:     16  Timestamp Wraparound                          */
    uint32_t MRAF:1;                    /**< bit:     17  Message RAM Access Failure                    */
    uint32_t TOO:1;                     /**< bit:     18  Timeout Occurred                              */
    uint32_t DRX:1;                     /**< bit:     19  Message stored to Dedicated Receive Buffer    */
    uint32_t BEC:1;                     /**< bit:     20  Bit Error Corrected                           */
    uint32_t BEU:1;                     /**< bit:     21  Bit Error Uncorrected                         */
    uint32_t ELO:1;                     /**< bit:     22  Error Logging Overflow                        */
    uint32_t EP:1;                      /**< bit:     23  Error Passive                                 */
    uint32_t EW:1;                      /**< bit:     24  Warning Status                                */
    uint32_t BO:1;                      /**< bit:     25  Bus_Off Status                                */
    uint32_t WDI:1;                     /**< bit:     26  Watchdog Interrupt                            */
    uint32_t PEA:1;                     /**< bit:     27  Protocol Error in Arbitration Phase           */
    uint32_t PED:1;                     /**< bit:     28  Protocol Error in Data Phase                  */
    uint32_t ARA:1;                     /**< bit:     29  Access to Reserved Address                    */
    uint32_t :2;                        /**< bit: 30..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_IR_bits_t;

#define MCAN_IR_RF0N_Pos                      (0)                                            /**< (MCAN_IR) Receive FIFO 0 New Message Position */
#define MCAN_IR_RF0N_Msk                      (0x1U << MCAN_IR_RF0N_Pos)                     /**< (MCAN_IR) Receive FIFO 0 New Message Mask */
#define MCAN_IR_RF0W_Pos                      (1)                                            /**< (MCAN_IR) Receive FIFO 0 Watermark Reached Position */
#define MCAN_IR_RF0W_Msk                      (0x1U << MCAN_IR_RF0W_Pos)                     /**< (MCAN_IR) Receive FIFO 0 Watermark Reached Mask */
#define MCAN_IR_RF0F_Pos                      (2)                                            /**< (MCAN_IR) Receive FIFO 0 Full Position */
#define MCAN_IR_RF0F_Msk                      (0x1U << MCAN_IR_RF0F_Pos)                     /**< (MCAN_IR) Receive FIFO 0 Full Mask */
#define MCAN_IR_RF0L_Pos                      (3)                                            /**< (MCAN_IR) Receive FIFO 0 Message Lost Position */
#define MCAN_IR_RF0L_Msk                      (0x1U << MCAN_IR_RF0L_Pos)                     /**< (MCAN_IR) Receive FIFO 0 Message Lost Mask */
#define MCAN_IR_RF1N_Pos                      (4)                                            /**< (MCAN_IR) Receive FIFO 1 New Message Position */
#define MCAN_IR_RF1N_Msk                      (0x1U << MCAN_IR_RF1N_Pos)                     /**< (MCAN_IR) Receive FIFO 1 New Message Mask */
#define MCAN_IR_RF1W_Pos                      (5)                                            /**< (MCAN_IR) Receive FIFO 1 Watermark Reached Position */
#define MCAN_IR_RF1W_Msk                      (0x1U << MCAN_IR_RF1W_Pos)                     /**< (MCAN_IR) Receive FIFO 1 Watermark Reached Mask */
#define MCAN_IR_RF1F_Pos                      (6)                                            /**< (MCAN_IR) Receive FIFO 1 Full Position */
#define MCAN_IR_RF1F_Msk                      (0x1U << MCAN_IR_RF1F_Pos)                     /**< (MCAN_IR) Receive FIFO 1 Full Mask */
#define MCAN_IR_RF1L_Pos                      (7)                                            /**< (MCAN_IR) Receive FIFO 1 Message Lost Position */
#define MCAN_IR_RF1L_Msk                      (0x1U << MCAN_IR_RF1L_Pos)                     /**< (MCAN_IR) Receive FIFO 1 Message Lost Mask */
#define MCAN_IR_HPM_Pos                       (8)                                            /**< (MCAN_IR) High Priority Message Position */
#define MCAN_IR_HPM_Msk                       (0x1U << MCAN_IR_HPM_Pos)                      /**< (MCAN_IR) High Priority Message Mask */
#define MCAN_IR_TC_Pos                        (9)                                            /**< (MCAN_IR) Transmission Completed Position */
#define MCAN_IR_TC_Msk                        (0x1U << MCAN_IR_TC_Pos)                       /**< (MCAN_IR) Transmission Completed Mask */
#define MCAN_IR_TCF_Pos                       (10)                                           /**< (MCAN_IR) Transmission Cancellation Finished Position */
#define MCAN_IR_TCF_Msk                       (0x1U << MCAN_IR_TCF_Pos)                      /**< (MCAN_IR) Transmission Cancellation Finished Mask */
#define MCAN_IR_TFE_Pos                       (11)                                           /**< (MCAN_IR) Tx FIFO Empty Position */
#define MCAN_IR_TFE_Msk                       (0x1U << MCAN_IR_TFE_Pos)                      /**< (MCAN_IR) Tx FIFO Empty Mask */
#define MCAN_IR_TEFN_Pos                      (12)                                           /**< (MCAN_IR) Tx Event FIFO New Entry Position */
#define MCAN_IR_TEFN_Msk                      (0x1U << MCAN_IR_TEFN_Pos)                     /**< (MCAN_IR) Tx Event FIFO New Entry Mask */
#define MCAN_IR_TEFW_Pos                      (13)                                           /**< (MCAN_IR) Tx Event FIFO Watermark Reached Position */
#define MCAN_IR_TEFW_Msk                      (0x1U << MCAN_IR_TEFW_Pos)                     /**< (MCAN_IR) Tx Event FIFO Watermark Reached Mask */
#define MCAN_IR_TEFF_Pos                      (14)                                           /**< (MCAN_IR) Tx Event FIFO Full Position */
#define MCAN_IR_TEFF_Msk                      (0x1U << MCAN_IR_TEFF_Pos)                     /**< (MCAN_IR) Tx Event FIFO Full Mask */
#define MCAN_IR_TEFL_Pos                      (15)                                           /**< (MCAN_IR) Tx Event FIFO Element Lost Position */
#define MCAN_IR_TEFL_Msk                      (0x1U << MCAN_IR_TEFL_Pos)                     /**< (MCAN_IR) Tx Event FIFO Element Lost Mask */
#define MCAN_IR_TSW_Pos                       (16)                                           /**< (MCAN_IR) Timestamp Wraparound Position */
#define MCAN_IR_TSW_Msk                       (0x1U << MCAN_IR_TSW_Pos)                      /**< (MCAN_IR) Timestamp Wraparound Mask */
#define MCAN_IR_MRAF_Pos                      (17)                                           /**< (MCAN_IR) Message RAM Access Failure Position */
#define MCAN_IR_MRAF_Msk                      (0x1U << MCAN_IR_MRAF_Pos)                     /**< (MCAN_IR) Message RAM Access Failure Mask */
#define MCAN_IR_TOO_Pos                       (18)                                           /**< (MCAN_IR) Timeout Occurred Position */
#define MCAN_IR_TOO_Msk                       (0x1U << MCAN_IR_TOO_Pos)                      /**< (MCAN_IR) Timeout Occurred Mask */
#define MCAN_IR_DRX_Pos                       (19)                                           /**< (MCAN_IR) Message stored to Dedicated Receive Buffer Position */
#define MCAN_IR_DRX_Msk                       (0x1U << MCAN_IR_DRX_Pos)                      /**< (MCAN_IR) Message stored to Dedicated Receive Buffer Mask */
#define MCAN_IR_BEC_Pos                       (20)                                           /**< (MCAN_IR) Bit Error Corrected Position */
#define MCAN_IR_BEC_Msk                       (0x1U << MCAN_IR_BEC_Pos)                      /**< (MCAN_IR) Bit Error Corrected Mask */
#define MCAN_IR_BEU_Pos                       (21)                                           /**< (MCAN_IR) Bit Error Uncorrected Position */
#define MCAN_IR_BEU_Msk                       (0x1U << MCAN_IR_BEU_Pos)                      /**< (MCAN_IR) Bit Error Uncorrected Mask */
#define MCAN_IR_ELO_Pos                       (22)                                           /**< (MCAN_IR) Error Logging Overflow Position */
#define MCAN_IR_ELO_Msk                       (0x1U << MCAN_IR_ELO_Pos)                      /**< (MCAN_IR) Error Logging Overflow Mask */
#define MCAN_IR_EP_Pos                        (23)                                           /**< (MCAN_IR) Error Passive Position */
#define MCAN_IR_EP_Msk                        (0x1U << MCAN_IR_EP_Pos)                       /**< (MCAN_IR) Error Passive Mask */
#define MCAN_IR_EW_Pos                        (24)                                           /**< (MCAN_IR) Warning Status Position */
#define MCAN_IR_EW_Msk                        (0x1U << MCAN_IR_EW_Pos)                       /**< (MCAN_IR) Warning Status Mask */
#define MCAN_IR_BO_Pos                        (25)                                           /**< (MCAN_IR) Bus_Off Status Position */
#define MCAN_IR_BO_Msk                        (0x1U << MCAN_IR_BO_Pos)                       /**< (MCAN_IR) Bus_Off Status Mask */
#define MCAN_IR_WDI_Pos                       (26)                                           /**< (MCAN_IR) Watchdog Interrupt Position */
#define MCAN_IR_WDI_Msk                       (0x1U << MCAN_IR_WDI_Pos)                      /**< (MCAN_IR) Watchdog Interrupt Mask */
#define MCAN_IR_PEA_Pos                       (27)                                           /**< (MCAN_IR) Protocol Error in Arbitration Phase Position */
#define MCAN_IR_PEA_Msk                       (0x1U << MCAN_IR_PEA_Pos)                      /**< (MCAN_IR) Protocol Error in Arbitration Phase Mask */
#define MCAN_IR_PED_Pos                       (28)                                           /**< (MCAN_IR) Protocol Error in Data Phase Position */
#define MCAN_IR_PED_Msk                       (0x1U << MCAN_IR_PED_Pos)                      /**< (MCAN_IR) Protocol Error in Data Phase Mask */
#define MCAN_IR_ARA_Pos                       (29)                                           /**< (MCAN_IR) Access to Reserved Address Position */
#define MCAN_IR_ARA_Msk                       (0x1U << MCAN_IR_ARA_Pos)                      /**< (MCAN_IR) Access to Reserved Address Mask */
#define MCAN_IR_Msk                           (0x3FFFFFFFUL)                                 /**< (MCAN_IR) Register Mask  */

/* -------- MCAN_IE : (MCAN Offset: 0x54) (R/W 32) Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t RF0NE:1;                   /**< bit:      0  Receive FIFO 0 New Message Interrupt Enable   */
    uint32_t RF0WE:1;                   /**< bit:      1  Receive FIFO 0 Watermark Reached Interrupt Enable */
    uint32_t RF0FE:1;                   /**< bit:      2  Receive FIFO 0 Full Interrupt Enable          */
    uint32_t RF0LE:1;                   /**< bit:      3  Receive FIFO 0 Message Lost Interrupt Enable  */
    uint32_t RF1NE:1;                   /**< bit:      4  Receive FIFO 1 New Message Interrupt Enable   */
    uint32_t RF1WE:1;                   /**< bit:      5  Receive FIFO 1 Watermark Reached Interrupt Enable */
    uint32_t RF1FE:1;                   /**< bit:      6  Receive FIFO 1 Full Interrupt Enable          */
    uint32_t RF1LE:1;                   /**< bit:      7  Receive FIFO 1 Message Lost Interrupt Enable  */
    uint32_t HPME:1;                    /**< bit:      8  High Priority Message Interrupt Enable        */
    uint32_t TCE:1;                     /**< bit:      9  Transmission Completed Interrupt Enable       */
    uint32_t TCFE:1;                    /**< bit:     10  Transmission Cancellation Finished Interrupt Enable */
    uint32_t TFEE:1;                    /**< bit:     11  Tx FIFO Empty Interrupt Enable                */
    uint32_t TEFNE:1;                   /**< bit:     12  Tx Event FIFO New Entry Interrupt Enable      */
    uint32_t TEFWE:1;                   /**< bit:     13  Tx Event FIFO Watermark Reached Interrupt Enable */
    uint32_t TEFFE:1;                   /**< bit:     14  Tx Event FIFO Full Interrupt Enable           */
    uint32_t TEFLE:1;                   /**< bit:     15  Tx Event FIFO Event Lost Interrupt Enable     */
    uint32_t TSWE:1;                    /**< bit:     16  Timestamp Wraparound Interrupt Enable         */
    uint32_t MRAFE:1;                   /**< bit:     17  Message RAM Access Failure Interrupt Enable   */
    uint32_t TOOE:1;                    /**< bit:     18  Timeout Occurred Interrupt Enable             */
    uint32_t DRXE:1;                    /**< bit:     19  Message stored to Dedicated Receive Buffer Interrupt Enable */
    uint32_t BECE:1;                    /**< bit:     20  Bit Error Corrected Interrupt Enable          */
    uint32_t BEUE:1;                    /**< bit:     21  Bit Error Uncorrected Interrupt Enable        */
    uint32_t ELOE:1;                    /**< bit:     22  Error Logging Overflow Interrupt Enable       */
    uint32_t EPE:1;                     /**< bit:     23  Error Passive Interrupt Enable                */
    uint32_t EWE:1;                     /**< bit:     24  Warning Status Interrupt Enable               */
    uint32_t BOE:1;                     /**< bit:     25  Bus_Off Status Interrupt Enable               */
    uint32_t WDIE:1;                    /**< bit:     26  Watchdog Interrupt Enable                     */
    uint32_t PEAE:1;                    /**< bit:     27  Protocol Error in Arbitration Phase Enable    */
    uint32_t PEDE:1;                    /**< bit:     28  Protocol Error in Data Phase Enable           */
    uint32_t ARAE:1;                    /**< bit:     29  Access to Reserved Address Enable             */
    uint32_t :2;                        /**< bit: 30..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_IE_bits_t;

#define MCAN_IE_RF0NE_Pos                     (0)                                            /**< (MCAN_IE) Receive FIFO 0 New Message Interrupt Enable Position */
#define MCAN_IE_RF0NE_Msk                     (0x1U << MCAN_IE_RF0NE_Pos)                    /**< (MCAN_IE) Receive FIFO 0 New Message Interrupt Enable Mask */
#define MCAN_IE_RF0WE_Pos                     (1)                                            /**< (MCAN_IE) Receive FIFO 0 Watermark Reached Interrupt Enable Position */
#define MCAN_IE_RF0WE_Msk                     (0x1U << MCAN_IE_RF0WE_Pos)                    /**< (MCAN_IE) Receive FIFO 0 Watermark Reached Interrupt Enable Mask */
#define MCAN_IE_RF0FE_Pos                     (2)                                            /**< (MCAN_IE) Receive FIFO 0 Full Interrupt Enable Position */
#define MCAN_IE_RF0FE_Msk                     (0x1U << MCAN_IE_RF0FE_Pos)                    /**< (MCAN_IE) Receive FIFO 0 Full Interrupt Enable Mask */
#define MCAN_IE_RF0LE_Pos                     (3)                                            /**< (MCAN_IE) Receive FIFO 0 Message Lost Interrupt Enable Position */
#define MCAN_IE_RF0LE_Msk                     (0x1U << MCAN_IE_RF0LE_Pos)                    /**< (MCAN_IE) Receive FIFO 0 Message Lost Interrupt Enable Mask */
#define MCAN_IE_RF1NE_Pos                     (4)                                            /**< (MCAN_IE) Receive FIFO 1 New Message Interrupt Enable Position */
#define MCAN_IE_RF1NE_Msk                     (0x1U << MCAN_IE_RF1NE_Pos)                    /**< (MCAN_IE) Receive FIFO 1 New Message Interrupt Enable Mask */
#define MCAN_IE_RF1WE_Pos                     (5)                                            /**< (MCAN_IE) Receive FIFO 1 Watermark Reached Interrupt Enable Position */
#define MCAN_IE_RF1WE_Msk                     (0x1U << MCAN_IE_RF1WE_Pos)                    /**< (MCAN_IE) Receive FIFO 1 Watermark Reached Interrupt Enable Mask */
#define MCAN_IE_RF1FE_Pos                     (6)                                            /**< (MCAN_IE) Receive FIFO 1 Full Interrupt Enable Position */
#define MCAN_IE_RF1FE_Msk                     (0x1U << MCAN_IE_RF1FE_Pos)                    /**< (MCAN_IE) Receive FIFO 1 Full Interrupt Enable Mask */
#define MCAN_IE_RF1LE_Pos                     (7)                                            /**< (MCAN_IE) Receive FIFO 1 Message Lost Interrupt Enable Position */
#define MCAN_IE_RF1LE_Msk                     (0x1U << MCAN_IE_RF1LE_Pos)                    /**< (MCAN_IE) Receive FIFO 1 Message Lost Interrupt Enable Mask */
#define MCAN_IE_HPME_Pos                      (8)                                            /**< (MCAN_IE) High Priority Message Interrupt Enable Position */
#define MCAN_IE_HPME_Msk                      (0x1U << MCAN_IE_HPME_Pos)                     /**< (MCAN_IE) High Priority Message Interrupt Enable Mask */
#define MCAN_IE_TCE_Pos                       (9)                                            /**< (MCAN_IE) Transmission Completed Interrupt Enable Position */
#define MCAN_IE_TCE_Msk                       (0x1U << MCAN_IE_TCE_Pos)                      /**< (MCAN_IE) Transmission Completed Interrupt Enable Mask */
#define MCAN_IE_TCFE_Pos                      (10)                                           /**< (MCAN_IE) Transmission Cancellation Finished Interrupt Enable Position */
#define MCAN_IE_TCFE_Msk                      (0x1U << MCAN_IE_TCFE_Pos)                     /**< (MCAN_IE) Transmission Cancellation Finished Interrupt Enable Mask */
#define MCAN_IE_TFEE_Pos                      (11)                                           /**< (MCAN_IE) Tx FIFO Empty Interrupt Enable Position */
#define MCAN_IE_TFEE_Msk                      (0x1U << MCAN_IE_TFEE_Pos)                     /**< (MCAN_IE) Tx FIFO Empty Interrupt Enable Mask */
#define MCAN_IE_TEFNE_Pos                     (12)                                           /**< (MCAN_IE) Tx Event FIFO New Entry Interrupt Enable Position */
#define MCAN_IE_TEFNE_Msk                     (0x1U << MCAN_IE_TEFNE_Pos)                    /**< (MCAN_IE) Tx Event FIFO New Entry Interrupt Enable Mask */
#define MCAN_IE_TEFWE_Pos                     (13)                                           /**< (MCAN_IE) Tx Event FIFO Watermark Reached Interrupt Enable Position */
#define MCAN_IE_TEFWE_Msk                     (0x1U << MCAN_IE_TEFWE_Pos)                    /**< (MCAN_IE) Tx Event FIFO Watermark Reached Interrupt Enable Mask */
#define MCAN_IE_TEFFE_Pos                     (14)                                           /**< (MCAN_IE) Tx Event FIFO Full Interrupt Enable Position */
#define MCAN_IE_TEFFE_Msk                     (0x1U << MCAN_IE_TEFFE_Pos)                    /**< (MCAN_IE) Tx Event FIFO Full Interrupt Enable Mask */
#define MCAN_IE_TEFLE_Pos                     (15)                                           /**< (MCAN_IE) Tx Event FIFO Event Lost Interrupt Enable Position */
#define MCAN_IE_TEFLE_Msk                     (0x1U << MCAN_IE_TEFLE_Pos)                    /**< (MCAN_IE) Tx Event FIFO Event Lost Interrupt Enable Mask */
#define MCAN_IE_TSWE_Pos                      (16)                                           /**< (MCAN_IE) Timestamp Wraparound Interrupt Enable Position */
#define MCAN_IE_TSWE_Msk                      (0x1U << MCAN_IE_TSWE_Pos)                     /**< (MCAN_IE) Timestamp Wraparound Interrupt Enable Mask */
#define MCAN_IE_MRAFE_Pos                     (17)                                           /**< (MCAN_IE) Message RAM Access Failure Interrupt Enable Position */
#define MCAN_IE_MRAFE_Msk                     (0x1U << MCAN_IE_MRAFE_Pos)                    /**< (MCAN_IE) Message RAM Access Failure Interrupt Enable Mask */
#define MCAN_IE_TOOE_Pos                      (18)                                           /**< (MCAN_IE) Timeout Occurred Interrupt Enable Position */
#define MCAN_IE_TOOE_Msk                      (0x1U << MCAN_IE_TOOE_Pos)                     /**< (MCAN_IE) Timeout Occurred Interrupt Enable Mask */
#define MCAN_IE_DRXE_Pos                      (19)                                           /**< (MCAN_IE) Message stored to Dedicated Receive Buffer Interrupt Enable Position */
#define MCAN_IE_DRXE_Msk                      (0x1U << MCAN_IE_DRXE_Pos)                     /**< (MCAN_IE) Message stored to Dedicated Receive Buffer Interrupt Enable Mask */
#define MCAN_IE_BECE_Pos                      (20)                                           /**< (MCAN_IE) Bit Error Corrected Interrupt Enable Position */
#define MCAN_IE_BECE_Msk                      (0x1U << MCAN_IE_BECE_Pos)                     /**< (MCAN_IE) Bit Error Corrected Interrupt Enable Mask */
#define MCAN_IE_BEUE_Pos                      (21)                                           /**< (MCAN_IE) Bit Error Uncorrected Interrupt Enable Position */
#define MCAN_IE_BEUE_Msk                      (0x1U << MCAN_IE_BEUE_Pos)                     /**< (MCAN_IE) Bit Error Uncorrected Interrupt Enable Mask */
#define MCAN_IE_ELOE_Pos                      (22)                                           /**< (MCAN_IE) Error Logging Overflow Interrupt Enable Position */
#define MCAN_IE_ELOE_Msk                      (0x1U << MCAN_IE_ELOE_Pos)                     /**< (MCAN_IE) Error Logging Overflow Interrupt Enable Mask */
#define MCAN_IE_EPE_Pos                       (23)                                           /**< (MCAN_IE) Error Passive Interrupt Enable Position */
#define MCAN_IE_EPE_Msk                       (0x1U << MCAN_IE_EPE_Pos)                      /**< (MCAN_IE) Error Passive Interrupt Enable Mask */
#define MCAN_IE_EWE_Pos                       (24)                                           /**< (MCAN_IE) Warning Status Interrupt Enable Position */
#define MCAN_IE_EWE_Msk                       (0x1U << MCAN_IE_EWE_Pos)                      /**< (MCAN_IE) Warning Status Interrupt Enable Mask */
#define MCAN_IE_BOE_Pos                       (25)                                           /**< (MCAN_IE) Bus_Off Status Interrupt Enable Position */
#define MCAN_IE_BOE_Msk                       (0x1U << MCAN_IE_BOE_Pos)                      /**< (MCAN_IE) Bus_Off Status Interrupt Enable Mask */
#define MCAN_IE_WDIE_Pos                      (26)                                           /**< (MCAN_IE) Watchdog Interrupt Enable Position */
#define MCAN_IE_WDIE_Msk                      (0x1U << MCAN_IE_WDIE_Pos)                     /**< (MCAN_IE) Watchdog Interrupt Enable Mask */
#define MCAN_IE_PEAE_Pos                      (27)                                           /**< (MCAN_IE) Protocol Error in Arbitration Phase Enable Position */
#define MCAN_IE_PEAE_Msk                      (0x1U << MCAN_IE_PEAE_Pos)                     /**< (MCAN_IE) Protocol Error in Arbitration Phase Enable Mask */
#define MCAN_IE_PEDE_Pos                      (28)                                           /**< (MCAN_IE) Protocol Error in Data Phase Enable Position */
#define MCAN_IE_PEDE_Msk                      (0x1U << MCAN_IE_PEDE_Pos)                     /**< (MCAN_IE) Protocol Error in Data Phase Enable Mask */
#define MCAN_IE_ARAE_Pos                      (29)                                           /**< (MCAN_IE) Access to Reserved Address Enable Position */
#define MCAN_IE_ARAE_Msk                      (0x1U << MCAN_IE_ARAE_Pos)                     /**< (MCAN_IE) Access to Reserved Address Enable Mask */
#define MCAN_IE_Msk                           (0x3FFFFFFFUL)                                 /**< (MCAN_IE) Register Mask  */

/* -------- MCAN_ILS : (MCAN Offset: 0x58) (R/W 32) Interrupt Line Select Register -------- */

typedef union
{
  struct
  {
    uint32_t RF0NL:1;                   /**< bit:      0  Receive FIFO 0 New Message Interrupt Line     */
    uint32_t RF0WL:1;                   /**< bit:      1  Receive FIFO 0 Watermark Reached Interrupt Line */
    uint32_t RF0FL:1;                   /**< bit:      2  Receive FIFO 0 Full Interrupt Line            */
    uint32_t RF0LL:1;                   /**< bit:      3  Receive FIFO 0 Message Lost Interrupt Line    */
    uint32_t RF1NL:1;                   /**< bit:      4  Receive FIFO 1 New Message Interrupt Line     */
    uint32_t RF1WL:1;                   /**< bit:      5  Receive FIFO 1 Watermark Reached Interrupt Line */
    uint32_t RF1FL:1;                   /**< bit:      6  Receive FIFO 1 Full Interrupt Line            */
    uint32_t RF1LL:1;                   /**< bit:      7  Receive FIFO 1 Message Lost Interrupt Line    */
    uint32_t HPML:1;                    /**< bit:      8  High Priority Message Interrupt Line          */
    uint32_t TCL:1;                     /**< bit:      9  Transmission Completed Interrupt Line         */
    uint32_t TCFL:1;                    /**< bit:     10  Transmission Cancellation Finished Interrupt Line */
    uint32_t TFEL:1;                    /**< bit:     11  Tx FIFO Empty Interrupt Line                  */
    uint32_t TEFNL:1;                   /**< bit:     12  Tx Event FIFO New Entry Interrupt Line        */
    uint32_t TEFWL:1;                   /**< bit:     13  Tx Event FIFO Watermark Reached Interrupt Line */
    uint32_t TEFFL:1;                   /**< bit:     14  Tx Event FIFO Full Interrupt Line             */
    uint32_t TEFLL:1;                   /**< bit:     15  Tx Event FIFO Event Lost Interrupt Line       */
    uint32_t TSWL:1;                    /**< bit:     16  Timestamp Wraparound Interrupt Line           */
    uint32_t MRAFL:1;                   /**< bit:     17  Message RAM Access Failure Interrupt Line     */
    uint32_t TOOL:1;                    /**< bit:     18  Timeout Occurred Interrupt Line               */
    uint32_t DRXL:1;                    /**< bit:     19  Message stored to Dedicated Receive Buffer Interrupt Line */
    uint32_t BECL:1;                    /**< bit:     20  Bit Error Corrected Interrupt Line            */
    uint32_t BEUL:1;                    /**< bit:     21  Bit Error Uncorrected Interrupt Line          */
    uint32_t ELOL:1;                    /**< bit:     22  Error Logging Overflow Interrupt Line         */
    uint32_t EPL:1;                     /**< bit:     23  Error Passive Interrupt Line                  */
    uint32_t EWL:1;                     /**< bit:     24  Warning Status Interrupt Line                 */
    uint32_t BOL:1;                     /**< bit:     25  Bus_Off Status Interrupt Line                 */
    uint32_t WDIL:1;                    /**< bit:     26  Watchdog Interrupt Line                       */
    uint32_t PEAL:1;                    /**< bit:     27  Protocol Error in Arbitration Phase Line      */
    uint32_t PEDL:1;                    /**< bit:     28  Protocol Error in Data Phase Line             */
    uint32_t ARAL:1;                    /**< bit:     29  Access to Reserved Address Line               */
    uint32_t :2;                        /**< bit: 30..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_ILS_bits_t;

#define MCAN_ILS_RF0NL_Pos                    (0)                                            /**< (MCAN_ILS) Receive FIFO 0 New Message Interrupt Line Position */
#define MCAN_ILS_RF0NL_Msk                    (0x1U << MCAN_ILS_RF0NL_Pos)                   /**< (MCAN_ILS) Receive FIFO 0 New Message Interrupt Line Mask */
#define MCAN_ILS_RF0WL_Pos                    (1)                                            /**< (MCAN_ILS) Receive FIFO 0 Watermark Reached Interrupt Line Position */
#define MCAN_ILS_RF0WL_Msk                    (0x1U << MCAN_ILS_RF0WL_Pos)                   /**< (MCAN_ILS) Receive FIFO 0 Watermark Reached Interrupt Line Mask */
#define MCAN_ILS_RF0FL_Pos                    (2)                                            /**< (MCAN_ILS) Receive FIFO 0 Full Interrupt Line Position */
#define MCAN_ILS_RF0FL_Msk                    (0x1U << MCAN_ILS_RF0FL_Pos)                   /**< (MCAN_ILS) Receive FIFO 0 Full Interrupt Line Mask */
#define MCAN_ILS_RF0LL_Pos                    (3)                                            /**< (MCAN_ILS) Receive FIFO 0 Message Lost Interrupt Line Position */
#define MCAN_ILS_RF0LL_Msk                    (0x1U << MCAN_ILS_RF0LL_Pos)                   /**< (MCAN_ILS) Receive FIFO 0 Message Lost Interrupt Line Mask */
#define MCAN_ILS_RF1NL_Pos                    (4)                                            /**< (MCAN_ILS) Receive FIFO 1 New Message Interrupt Line Position */
#define MCAN_ILS_RF1NL_Msk                    (0x1U << MCAN_ILS_RF1NL_Pos)                   /**< (MCAN_ILS) Receive FIFO 1 New Message Interrupt Line Mask */
#define MCAN_ILS_RF1WL_Pos                    (5)                                            /**< (MCAN_ILS) Receive FIFO 1 Watermark Reached Interrupt Line Position */
#define MCAN_ILS_RF1WL_Msk                    (0x1U << MCAN_ILS_RF1WL_Pos)                   /**< (MCAN_ILS) Receive FIFO 1 Watermark Reached Interrupt Line Mask */
#define MCAN_ILS_RF1FL_Pos                    (6)                                            /**< (MCAN_ILS) Receive FIFO 1 Full Interrupt Line Position */
#define MCAN_ILS_RF1FL_Msk                    (0x1U << MCAN_ILS_RF1FL_Pos)                   /**< (MCAN_ILS) Receive FIFO 1 Full Interrupt Line Mask */
#define MCAN_ILS_RF1LL_Pos                    (7)                                            /**< (MCAN_ILS) Receive FIFO 1 Message Lost Interrupt Line Position */
#define MCAN_ILS_RF1LL_Msk                    (0x1U << MCAN_ILS_RF1LL_Pos)                   /**< (MCAN_ILS) Receive FIFO 1 Message Lost Interrupt Line Mask */
#define MCAN_ILS_HPML_Pos                     (8)                                            /**< (MCAN_ILS) High Priority Message Interrupt Line Position */
#define MCAN_ILS_HPML_Msk                     (0x1U << MCAN_ILS_HPML_Pos)                    /**< (MCAN_ILS) High Priority Message Interrupt Line Mask */
#define MCAN_ILS_TCL_Pos                      (9)                                            /**< (MCAN_ILS) Transmission Completed Interrupt Line Position */
#define MCAN_ILS_TCL_Msk                      (0x1U << MCAN_ILS_TCL_Pos)                     /**< (MCAN_ILS) Transmission Completed Interrupt Line Mask */
#define MCAN_ILS_TCFL_Pos                     (10)                                           /**< (MCAN_ILS) Transmission Cancellation Finished Interrupt Line Position */
#define MCAN_ILS_TCFL_Msk                     (0x1U << MCAN_ILS_TCFL_Pos)                    /**< (MCAN_ILS) Transmission Cancellation Finished Interrupt Line Mask */
#define MCAN_ILS_TFEL_Pos                     (11)                                           /**< (MCAN_ILS) Tx FIFO Empty Interrupt Line Position */
#define MCAN_ILS_TFEL_Msk                     (0x1U << MCAN_ILS_TFEL_Pos)                    /**< (MCAN_ILS) Tx FIFO Empty Interrupt Line Mask */
#define MCAN_ILS_TEFNL_Pos                    (12)                                           /**< (MCAN_ILS) Tx Event FIFO New Entry Interrupt Line Position */
#define MCAN_ILS_TEFNL_Msk                    (0x1U << MCAN_ILS_TEFNL_Pos)                   /**< (MCAN_ILS) Tx Event FIFO New Entry Interrupt Line Mask */
#define MCAN_ILS_TEFWL_Pos                    (13)                                           /**< (MCAN_ILS) Tx Event FIFO Watermark Reached Interrupt Line Position */
#define MCAN_ILS_TEFWL_Msk                    (0x1U << MCAN_ILS_TEFWL_Pos)                   /**< (MCAN_ILS) Tx Event FIFO Watermark Reached Interrupt Line Mask */
#define MCAN_ILS_TEFFL_Pos                    (14)                                           /**< (MCAN_ILS) Tx Event FIFO Full Interrupt Line Position */
#define MCAN_ILS_TEFFL_Msk                    (0x1U << MCAN_ILS_TEFFL_Pos)                   /**< (MCAN_ILS) Tx Event FIFO Full Interrupt Line Mask */
#define MCAN_ILS_TEFLL_Pos                    (15)                                           /**< (MCAN_ILS) Tx Event FIFO Event Lost Interrupt Line Position */
#define MCAN_ILS_TEFLL_Msk                    (0x1U << MCAN_ILS_TEFLL_Pos)                   /**< (MCAN_ILS) Tx Event FIFO Event Lost Interrupt Line Mask */
#define MCAN_ILS_TSWL_Pos                     (16)                                           /**< (MCAN_ILS) Timestamp Wraparound Interrupt Line Position */
#define MCAN_ILS_TSWL_Msk                     (0x1U << MCAN_ILS_TSWL_Pos)                    /**< (MCAN_ILS) Timestamp Wraparound Interrupt Line Mask */
#define MCAN_ILS_MRAFL_Pos                    (17)                                           /**< (MCAN_ILS) Message RAM Access Failure Interrupt Line Position */
#define MCAN_ILS_MRAFL_Msk                    (0x1U << MCAN_ILS_MRAFL_Pos)                   /**< (MCAN_ILS) Message RAM Access Failure Interrupt Line Mask */
#define MCAN_ILS_TOOL_Pos                     (18)                                           /**< (MCAN_ILS) Timeout Occurred Interrupt Line Position */
#define MCAN_ILS_TOOL_Msk                     (0x1U << MCAN_ILS_TOOL_Pos)                    /**< (MCAN_ILS) Timeout Occurred Interrupt Line Mask */
#define MCAN_ILS_DRXL_Pos                     (19)                                           /**< (MCAN_ILS) Message stored to Dedicated Receive Buffer Interrupt Line Position */
#define MCAN_ILS_DRXL_Msk                     (0x1U << MCAN_ILS_DRXL_Pos)                    /**< (MCAN_ILS) Message stored to Dedicated Receive Buffer Interrupt Line Mask */
#define MCAN_ILS_BECL_Pos                     (20)                                           /**< (MCAN_ILS) Bit Error Corrected Interrupt Line Position */
#define MCAN_ILS_BECL_Msk                     (0x1U << MCAN_ILS_BECL_Pos)                    /**< (MCAN_ILS) Bit Error Corrected Interrupt Line Mask */
#define MCAN_ILS_BEUL_Pos                     (21)                                           /**< (MCAN_ILS) Bit Error Uncorrected Interrupt Line Position */
#define MCAN_ILS_BEUL_Msk                     (0x1U << MCAN_ILS_BEUL_Pos)                    /**< (MCAN_ILS) Bit Error Uncorrected Interrupt Line Mask */
#define MCAN_ILS_ELOL_Pos                     (22)                                           /**< (MCAN_ILS) Error Logging Overflow Interrupt Line Position */
#define MCAN_ILS_ELOL_Msk                     (0x1U << MCAN_ILS_ELOL_Pos)                    /**< (MCAN_ILS) Error Logging Overflow Interrupt Line Mask */
#define MCAN_ILS_EPL_Pos                      (23)                                           /**< (MCAN_ILS) Error Passive Interrupt Line Position */
#define MCAN_ILS_EPL_Msk                      (0x1U << MCAN_ILS_EPL_Pos)                     /**< (MCAN_ILS) Error Passive Interrupt Line Mask */
#define MCAN_ILS_EWL_Pos                      (24)                                           /**< (MCAN_ILS) Warning Status Interrupt Line Position */
#define MCAN_ILS_EWL_Msk                      (0x1U << MCAN_ILS_EWL_Pos)                     /**< (MCAN_ILS) Warning Status Interrupt Line Mask */
#define MCAN_ILS_BOL_Pos                      (25)                                           /**< (MCAN_ILS) Bus_Off Status Interrupt Line Position */
#define MCAN_ILS_BOL_Msk                      (0x1U << MCAN_ILS_BOL_Pos)                     /**< (MCAN_ILS) Bus_Off Status Interrupt Line Mask */
#define MCAN_ILS_WDIL_Pos                     (26)                                           /**< (MCAN_ILS) Watchdog Interrupt Line Position */
#define MCAN_ILS_WDIL_Msk                     (0x1U << MCAN_ILS_WDIL_Pos)                    /**< (MCAN_ILS) Watchdog Interrupt Line Mask */
#define MCAN_ILS_PEAL_Pos                     (27)                                           /**< (MCAN_ILS) Protocol Error in Arbitration Phase Line Position */
#define MCAN_ILS_PEAL_Msk                     (0x1U << MCAN_ILS_PEAL_Pos)                    /**< (MCAN_ILS) Protocol Error in Arbitration Phase Line Mask */
#define MCAN_ILS_PEDL_Pos                     (28)                                           /**< (MCAN_ILS) Protocol Error in Data Phase Line Position */
#define MCAN_ILS_PEDL_Msk                     (0x1U << MCAN_ILS_PEDL_Pos)                    /**< (MCAN_ILS) Protocol Error in Data Phase Line Mask */
#define MCAN_ILS_ARAL_Pos                     (29)                                           /**< (MCAN_ILS) Access to Reserved Address Line Position */
#define MCAN_ILS_ARAL_Msk                     (0x1U << MCAN_ILS_ARAL_Pos)                    /**< (MCAN_ILS) Access to Reserved Address Line Mask */
#define MCAN_ILS_Msk                          (0x3FFFFFFFUL)                                 /**< (MCAN_ILS) Register Mask  */

/* -------- MCAN_ILE : (MCAN Offset: 0x5c) (R/W 32) Interrupt Line Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t EINT0:1;                   /**< bit:      0  Enable Interrupt Line 0                       */
    uint32_t EINT1:1;                   /**< bit:      1  Enable Interrupt Line 1                       */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  struct
  {
    uint32_t EINT:2;                    /**< bit:   0..1  Enable Interrupt Line x                       */
    uint32_t :30;                       /**< bit:  2..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_ILE_bits_t;

#define MCAN_ILE_EINT0_Pos                    (0)                                            /**< (MCAN_ILE) Enable Interrupt Line 0 Position */
#define MCAN_ILE_EINT0_Msk                    (0x1U << MCAN_ILE_EINT0_Pos)                   /**< (MCAN_ILE) Enable Interrupt Line 0 Mask */
#define MCAN_ILE_EINT1_Pos                    (1)                                            /**< (MCAN_ILE) Enable Interrupt Line 1 Position */
#define MCAN_ILE_EINT1_Msk                    (0x1U << MCAN_ILE_EINT1_Pos)                   /**< (MCAN_ILE) Enable Interrupt Line 1 Mask */
#define MCAN_ILE_Msk                          (0x00000003UL)                                 /**< (MCAN_ILE) Register Mask  */
#define MCAN_ILE_EINT_Pos                     (0)                                            /**< (MCAN_ILE Position) Enable Interrupt Line x */
#define MCAN_ILE_EINT_Msk                     (0x3U << MCAN_ILE_EINT_Pos)                    /**< (MCAN_ILE Mask) EINT */
#define MCAN_ILE_EINT(value)                  (MCAN_ILE_EINT_Msk & ((value) << MCAN_ILE_EINT_Pos))

/* -------- MCAN_GFC : (MCAN Offset: 0x80) (R/W 32) Global Filter Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t RRFE:1;                    /**< bit:      0  Reject Remote Frames Extended                 */
    uint32_t RRFS:1;                    /**< bit:      1  Reject Remote Frames Standard                 */
    uint32_t ANFE:2;                    /**< bit:   2..3  Accept Non-matching Frames Extended           */
    uint32_t ANFS:2;                    /**< bit:   4..5  Accept Non-matching Frames Standard           */
    uint32_t :26;                       /**< bit:  6..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_GFC_bits_t;

#define MCAN_GFC_RRFE_Pos                     (0)                                            /**< (MCAN_GFC) Reject Remote Frames Extended Position */
#define MCAN_GFC_RRFE_Msk                     (0x1U << MCAN_GFC_RRFE_Pos)                    /**< (MCAN_GFC) Reject Remote Frames Extended Mask */
#define   MCAN_GFC_RRFE_FILTER_Val            (0x0U)                                         /**< (MCAN_GFC) Filter remote frames with 29-bit extended IDs.  */
#define   MCAN_GFC_RRFE_REJECT_Val            (0x1U)                                         /**< (MCAN_GFC) Reject all remote frames with 29-bit extended IDs.  */
#define MCAN_GFC_RRFE_FILTER                  (MCAN_GFC_RRFE_FILTER_Val << MCAN_GFC_RRFE_Pos)  /**< (MCAN_GFC) Filter remote frames with 29-bit extended IDs. Position  */
#define MCAN_GFC_RRFE_REJECT                  (MCAN_GFC_RRFE_REJECT_Val << MCAN_GFC_RRFE_Pos)  /**< (MCAN_GFC) Reject all remote frames with 29-bit extended IDs. Position  */
#define MCAN_GFC_RRFS_Pos                     (1)                                            /**< (MCAN_GFC) Reject Remote Frames Standard Position */
#define MCAN_GFC_RRFS_Msk                     (0x1U << MCAN_GFC_RRFS_Pos)                    /**< (MCAN_GFC) Reject Remote Frames Standard Mask */
#define   MCAN_GFC_RRFS_FILTER_Val            (0x0U)                                         /**< (MCAN_GFC) Filter remote frames with 11-bit standard IDs.  */
#define   MCAN_GFC_RRFS_REJECT_Val            (0x1U)                                         /**< (MCAN_GFC) Reject all remote frames with 11-bit standard IDs.  */
#define MCAN_GFC_RRFS_FILTER                  (MCAN_GFC_RRFS_FILTER_Val << MCAN_GFC_RRFS_Pos)  /**< (MCAN_GFC) Filter remote frames with 11-bit standard IDs. Position  */
#define MCAN_GFC_RRFS_REJECT                  (MCAN_GFC_RRFS_REJECT_Val << MCAN_GFC_RRFS_Pos)  /**< (MCAN_GFC) Reject all remote frames with 11-bit standard IDs. Position  */
#define MCAN_GFC_ANFE_Pos                     (2)                                            /**< (MCAN_GFC) Accept Non-matching Frames Extended Position */
#define MCAN_GFC_ANFE_Msk                     (0x3U << MCAN_GFC_ANFE_Pos)                    /**< (MCAN_GFC) Accept Non-matching Frames Extended Mask */
#define MCAN_GFC_ANFE(value)                  (MCAN_GFC_ANFE_Msk & ((value) << MCAN_GFC_ANFE_Pos))
#define   MCAN_GFC_ANFE_RX_FIFO_0_Val         (0x0U)                                         /**< (MCAN_GFC) Accept in Rx FIFO 0  */
#define   MCAN_GFC_ANFE_RX_FIFO_1_Val         (0x1U)                                         /**< (MCAN_GFC) Accept in Rx FIFO 1  */
#define MCAN_GFC_ANFE_RX_FIFO_0               (MCAN_GFC_ANFE_RX_FIFO_0_Val << MCAN_GFC_ANFE_Pos)  /**< (MCAN_GFC) Accept in Rx FIFO 0 Position  */
#define MCAN_GFC_ANFE_RX_FIFO_1               (MCAN_GFC_ANFE_RX_FIFO_1_Val << MCAN_GFC_ANFE_Pos)  /**< (MCAN_GFC) Accept in Rx FIFO 1 Position  */
#define MCAN_GFC_ANFS_Pos                     (4)                                            /**< (MCAN_GFC) Accept Non-matching Frames Standard Position */
#define MCAN_GFC_ANFS_Msk                     (0x3U << MCAN_GFC_ANFS_Pos)                    /**< (MCAN_GFC) Accept Non-matching Frames Standard Mask */
#define MCAN_GFC_ANFS(value)                  (MCAN_GFC_ANFS_Msk & ((value) << MCAN_GFC_ANFS_Pos))
#define   MCAN_GFC_ANFS_RX_FIFO_0_Val         (0x0U)                                         /**< (MCAN_GFC) Accept in Rx FIFO 0  */
#define   MCAN_GFC_ANFS_RX_FIFO_1_Val         (0x1U)                                         /**< (MCAN_GFC) Accept in Rx FIFO 1  */
#define MCAN_GFC_ANFS_RX_FIFO_0               (MCAN_GFC_ANFS_RX_FIFO_0_Val << MCAN_GFC_ANFS_Pos)  /**< (MCAN_GFC) Accept in Rx FIFO 0 Position  */
#define MCAN_GFC_ANFS_RX_FIFO_1               (MCAN_GFC_ANFS_RX_FIFO_1_Val << MCAN_GFC_ANFS_Pos)  /**< (MCAN_GFC) Accept in Rx FIFO 1 Position  */
#define MCAN_GFC_Msk                          (0x0000003FUL)                                 /**< (MCAN_GFC) Register Mask  */

/* -------- MCAN_SIDFC : (MCAN Offset: 0x84) (R/W 32) Standard ID Filter Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t FLSSA:14;                  /**< bit:  2..15  Filter List Standard Start Address            */
    uint32_t LSS:8;                     /**< bit: 16..23  List Size Standard                            */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_SIDFC_bits_t;

#define MCAN_SIDFC_FLSSA_Pos                  (2)                                            /**< (MCAN_SIDFC) Filter List Standard Start Address Position */
#define MCAN_SIDFC_FLSSA_Msk                  (0x3FFFU << MCAN_SIDFC_FLSSA_Pos)              /**< (MCAN_SIDFC) Filter List Standard Start Address Mask */
#define MCAN_SIDFC_FLSSA(value)               (MCAN_SIDFC_FLSSA_Msk & ((value) << MCAN_SIDFC_FLSSA_Pos))
#define MCAN_SIDFC_LSS_Pos                    (16)                                           /**< (MCAN_SIDFC) List Size Standard Position */
#define MCAN_SIDFC_LSS_Msk                    (0xFFU << MCAN_SIDFC_LSS_Pos)                  /**< (MCAN_SIDFC) List Size Standard Mask */
#define MCAN_SIDFC_LSS(value)                 (MCAN_SIDFC_LSS_Msk & ((value) << MCAN_SIDFC_LSS_Pos))
#define MCAN_SIDFC_Msk                        (0x00FFFFFCUL)                                 /**< (MCAN_SIDFC) Register Mask  */

/* -------- MCAN_XIDFC : (MCAN Offset: 0x88) (R/W 32) Extended ID Filter Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t FLESA:14;                  /**< bit:  2..15  Filter List Extended Start Address            */
    uint32_t LSE:7;                     /**< bit: 16..22  List Size Extended                            */
    uint32_t :9;                        /**< bit: 23..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_XIDFC_bits_t;

#define MCAN_XIDFC_FLESA_Pos                  (2)                                            /**< (MCAN_XIDFC) Filter List Extended Start Address Position */
#define MCAN_XIDFC_FLESA_Msk                  (0x3FFFU << MCAN_XIDFC_FLESA_Pos)              /**< (MCAN_XIDFC) Filter List Extended Start Address Mask */
#define MCAN_XIDFC_FLESA(value)               (MCAN_XIDFC_FLESA_Msk & ((value) << MCAN_XIDFC_FLESA_Pos))
#define MCAN_XIDFC_LSE_Pos                    (16)                                           /**< (MCAN_XIDFC) List Size Extended Position */
#define MCAN_XIDFC_LSE_Msk                    (0x7FU << MCAN_XIDFC_LSE_Pos)                  /**< (MCAN_XIDFC) List Size Extended Mask */
#define MCAN_XIDFC_LSE(value)                 (MCAN_XIDFC_LSE_Msk & ((value) << MCAN_XIDFC_LSE_Pos))
#define MCAN_XIDFC_Msk                        (0x007FFFFCUL)                                 /**< (MCAN_XIDFC) Register Mask  */

/* -------- MCAN_XIDAM : (MCAN Offset: 0x90) (R/W 32) Extended ID AND Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t EIDM:29;                   /**< bit:  0..28  Extended ID Mask                              */
    uint32_t :3;                        /**< bit: 29..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_XIDAM_bits_t;

#define MCAN_XIDAM_EIDM_Pos                   (0)                                            /**< (MCAN_XIDAM) Extended ID Mask Position */
#define MCAN_XIDAM_EIDM_Msk                   (0x1FFFFFFFU << MCAN_XIDAM_EIDM_Pos)           /**< (MCAN_XIDAM) Extended ID Mask Mask */
#define MCAN_XIDAM_EIDM(value)                (MCAN_XIDAM_EIDM_Msk & ((value) << MCAN_XIDAM_EIDM_Pos))
#define MCAN_XIDAM_Msk                        (0x1FFFFFFFUL)                                 /**< (MCAN_XIDAM) Register Mask  */

/* -------- MCAN_HPMS : (MCAN Offset: 0x94) (R/ 32) High Priority Message Status Register -------- */

typedef union
{
  struct
  {
    uint32_t BIDX:6;                    /**< bit:   0..5  Buffer Index                                  */
    uint32_t MSI:2;                     /**< bit:   6..7  Message Storage Indicator                     */
    uint32_t FIDX:7;                    /**< bit:  8..14  Filter Index                                  */
    uint32_t FLST:1;                    /**< bit:     15  Filter List                                   */
    uint32_t :16;                       /**< bit: 16..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_HPMS_bits_t;

#define MCAN_HPMS_BIDX_Pos                    (0)                                            /**< (MCAN_HPMS) Buffer Index Position */
#define MCAN_HPMS_BIDX_Msk                    (0x3FU << MCAN_HPMS_BIDX_Pos)                  /**< (MCAN_HPMS) Buffer Index Mask */
#define MCAN_HPMS_BIDX(value)                 (MCAN_HPMS_BIDX_Msk & ((value) << MCAN_HPMS_BIDX_Pos))
#define MCAN_HPMS_MSI_Pos                     (6)                                            /**< (MCAN_HPMS) Message Storage Indicator Position */
#define MCAN_HPMS_MSI_Msk                     (0x3U << MCAN_HPMS_MSI_Pos)                    /**< (MCAN_HPMS) Message Storage Indicator Mask */
#define MCAN_HPMS_MSI(value)                  (MCAN_HPMS_MSI_Msk & ((value) << MCAN_HPMS_MSI_Pos))
#define   MCAN_HPMS_MSI_NO_FIFO_SEL_Val       (0x0U)                                         /**< (MCAN_HPMS) No FIFO selected.  */
#define   MCAN_HPMS_MSI_LOST_Val              (0x1U)                                         /**< (MCAN_HPMS) FIFO message lost.  */
#define   MCAN_HPMS_MSI_FIFO_0_Val            (0x2U)                                         /**< (MCAN_HPMS) Message stored in FIFO 0.  */
#define   MCAN_HPMS_MSI_FIFO_1_Val            (0x3U)                                         /**< (MCAN_HPMS) Message stored in FIFO 1.  */
#define MCAN_HPMS_MSI_NO_FIFO_SEL             (MCAN_HPMS_MSI_NO_FIFO_SEL_Val << MCAN_HPMS_MSI_Pos)  /**< (MCAN_HPMS) No FIFO selected. Position  */
#define MCAN_HPMS_MSI_LOST                    (MCAN_HPMS_MSI_LOST_Val << MCAN_HPMS_MSI_Pos)  /**< (MCAN_HPMS) FIFO message lost. Position  */
#define MCAN_HPMS_MSI_FIFO_0                  (MCAN_HPMS_MSI_FIFO_0_Val << MCAN_HPMS_MSI_Pos)  /**< (MCAN_HPMS) Message stored in FIFO 0. Position  */
#define MCAN_HPMS_MSI_FIFO_1                  (MCAN_HPMS_MSI_FIFO_1_Val << MCAN_HPMS_MSI_Pos)  /**< (MCAN_HPMS) Message stored in FIFO 1. Position  */
#define MCAN_HPMS_FIDX_Pos                    (8)                                            /**< (MCAN_HPMS) Filter Index Position */
#define MCAN_HPMS_FIDX_Msk                    (0x7FU << MCAN_HPMS_FIDX_Pos)                  /**< (MCAN_HPMS) Filter Index Mask */
#define MCAN_HPMS_FIDX(value)                 (MCAN_HPMS_FIDX_Msk & ((value) << MCAN_HPMS_FIDX_Pos))
#define MCAN_HPMS_FLST_Pos                    (15)                                           /**< (MCAN_HPMS) Filter List Position */
#define MCAN_HPMS_FLST_Msk                    (0x1U << MCAN_HPMS_FLST_Pos)                   /**< (MCAN_HPMS) Filter List Mask */
#define MCAN_HPMS_Msk                         (0x0000FFFFUL)                                 /**< (MCAN_HPMS) Register Mask  */

/* -------- MCAN_NDAT1 : (MCAN Offset: 0x98) (R/W 32) New Data 1 Register -------- */

typedef union
{
  struct
  {
    uint32_t ND0:1;                     /**< bit:      0  New Data                                      */
    uint32_t ND1:1;                     /**< bit:      1  New Data                                      */
    uint32_t ND2:1;                     /**< bit:      2  New Data                                      */
    uint32_t ND3:1;                     /**< bit:      3  New Data                                      */
    uint32_t ND4:1;                     /**< bit:      4  New Data                                      */
    uint32_t ND5:1;                     /**< bit:      5  New Data                                      */
    uint32_t ND6:1;                     /**< bit:      6  New Data                                      */
    uint32_t ND7:1;                     /**< bit:      7  New Data                                      */
    uint32_t ND8:1;                     /**< bit:      8  New Data                                      */
    uint32_t ND9:1;                     /**< bit:      9  New Data                                      */
    uint32_t ND10:1;                    /**< bit:     10  New Data                                      */
    uint32_t ND11:1;                    /**< bit:     11  New Data                                      */
    uint32_t ND12:1;                    /**< bit:     12  New Data                                      */
    uint32_t ND13:1;                    /**< bit:     13  New Data                                      */
    uint32_t ND14:1;                    /**< bit:     14  New Data                                      */
    uint32_t ND15:1;                    /**< bit:     15  New Data                                      */
    uint32_t ND16:1;                    /**< bit:     16  New Data                                      */
    uint32_t ND17:1;                    /**< bit:     17  New Data                                      */
    uint32_t ND18:1;                    /**< bit:     18  New Data                                      */
    uint32_t ND19:1;                    /**< bit:     19  New Data                                      */
    uint32_t ND20:1;                    /**< bit:     20  New Data                                      */
    uint32_t ND21:1;                    /**< bit:     21  New Data                                      */
    uint32_t ND22:1;                    /**< bit:     22  New Data                                      */
    uint32_t ND23:1;                    /**< bit:     23  New Data                                      */
    uint32_t ND24:1;                    /**< bit:     24  New Data                                      */
    uint32_t ND25:1;                    /**< bit:     25  New Data                                      */
    uint32_t ND26:1;                    /**< bit:     26  New Data                                      */
    uint32_t ND27:1;                    /**< bit:     27  New Data                                      */
    uint32_t ND28:1;                    /**< bit:     28  New Data                                      */
    uint32_t ND29:1;                    /**< bit:     29  New Data                                      */
    uint32_t ND30:1;                    /**< bit:     30  New Data                                      */
    uint32_t ND31:1;                    /**< bit:     31  New Data                                      */
  };
  struct
  {
    uint32_t ND:32;                     /**< bit:  0..31  New Data                                      */
  };
  uint32_t w;
} __MCAN_NDAT1_bits_t;

#define MCAN_NDAT1_ND0_Pos                    (0)                                            /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND0_Msk                    (0x1U << MCAN_NDAT1_ND0_Pos)                   /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND1_Pos                    (1)                                            /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND1_Msk                    (0x1U << MCAN_NDAT1_ND1_Pos)                   /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND2_Pos                    (2)                                            /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND2_Msk                    (0x1U << MCAN_NDAT1_ND2_Pos)                   /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND3_Pos                    (3)                                            /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND3_Msk                    (0x1U << MCAN_NDAT1_ND3_Pos)                   /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND4_Pos                    (4)                                            /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND4_Msk                    (0x1U << MCAN_NDAT1_ND4_Pos)                   /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND5_Pos                    (5)                                            /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND5_Msk                    (0x1U << MCAN_NDAT1_ND5_Pos)                   /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND6_Pos                    (6)                                            /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND6_Msk                    (0x1U << MCAN_NDAT1_ND6_Pos)                   /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND7_Pos                    (7)                                            /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND7_Msk                    (0x1U << MCAN_NDAT1_ND7_Pos)                   /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND8_Pos                    (8)                                            /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND8_Msk                    (0x1U << MCAN_NDAT1_ND8_Pos)                   /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND9_Pos                    (9)                                            /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND9_Msk                    (0x1U << MCAN_NDAT1_ND9_Pos)                   /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND10_Pos                   (10)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND10_Msk                   (0x1U << MCAN_NDAT1_ND10_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND11_Pos                   (11)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND11_Msk                   (0x1U << MCAN_NDAT1_ND11_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND12_Pos                   (12)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND12_Msk                   (0x1U << MCAN_NDAT1_ND12_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND13_Pos                   (13)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND13_Msk                   (0x1U << MCAN_NDAT1_ND13_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND14_Pos                   (14)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND14_Msk                   (0x1U << MCAN_NDAT1_ND14_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND15_Pos                   (15)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND15_Msk                   (0x1U << MCAN_NDAT1_ND15_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND16_Pos                   (16)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND16_Msk                   (0x1U << MCAN_NDAT1_ND16_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND17_Pos                   (17)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND17_Msk                   (0x1U << MCAN_NDAT1_ND17_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND18_Pos                   (18)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND18_Msk                   (0x1U << MCAN_NDAT1_ND18_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND19_Pos                   (19)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND19_Msk                   (0x1U << MCAN_NDAT1_ND19_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND20_Pos                   (20)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND20_Msk                   (0x1U << MCAN_NDAT1_ND20_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND21_Pos                   (21)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND21_Msk                   (0x1U << MCAN_NDAT1_ND21_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND22_Pos                   (22)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND22_Msk                   (0x1U << MCAN_NDAT1_ND22_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND23_Pos                   (23)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND23_Msk                   (0x1U << MCAN_NDAT1_ND23_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND24_Pos                   (24)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND24_Msk                   (0x1U << MCAN_NDAT1_ND24_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND25_Pos                   (25)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND25_Msk                   (0x1U << MCAN_NDAT1_ND25_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND26_Pos                   (26)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND26_Msk                   (0x1U << MCAN_NDAT1_ND26_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND27_Pos                   (27)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND27_Msk                   (0x1U << MCAN_NDAT1_ND27_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND28_Pos                   (28)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND28_Msk                   (0x1U << MCAN_NDAT1_ND28_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND29_Pos                   (29)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND29_Msk                   (0x1U << MCAN_NDAT1_ND29_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND30_Pos                   (30)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND30_Msk                   (0x1U << MCAN_NDAT1_ND30_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_ND31_Pos                   (31)                                           /**< (MCAN_NDAT1) New Data Position */
#define MCAN_NDAT1_ND31_Msk                   (0x1U << MCAN_NDAT1_ND31_Pos)                  /**< (MCAN_NDAT1) New Data Mask */
#define MCAN_NDAT1_Msk                        (0xFFFFFFFFUL)                                 /**< (MCAN_NDAT1) Register Mask  */
#define MCAN_NDAT1_ND_Pos                     (0)                                            /**< (MCAN_NDAT1 Position) New Data */
#define MCAN_NDAT1_ND_Msk                     (0xFFFFFFFFU << MCAN_NDAT1_ND_Pos)             /**< (MCAN_NDAT1 Mask) ND */
#define MCAN_NDAT1_ND(value)                  (MCAN_NDAT1_ND_Msk & ((value) << MCAN_NDAT1_ND_Pos))

/* -------- MCAN_NDAT2 : (MCAN Offset: 0x9c) (R/W 32) New Data 2 Register -------- */

typedef union
{
  struct
  {
    uint32_t ND32:1;                    /**< bit:      0  New Data                                      */
    uint32_t ND33:1;                    /**< bit:      1  New Data                                      */
    uint32_t ND34:1;                    /**< bit:      2  New Data                                      */
    uint32_t ND35:1;                    /**< bit:      3  New Data                                      */
    uint32_t ND36:1;                    /**< bit:      4  New Data                                      */
    uint32_t ND37:1;                    /**< bit:      5  New Data                                      */
    uint32_t ND38:1;                    /**< bit:      6  New Data                                      */
    uint32_t ND39:1;                    /**< bit:      7  New Data                                      */
    uint32_t ND40:1;                    /**< bit:      8  New Data                                      */
    uint32_t ND41:1;                    /**< bit:      9  New Data                                      */
    uint32_t ND42:1;                    /**< bit:     10  New Data                                      */
    uint32_t ND43:1;                    /**< bit:     11  New Data                                      */
    uint32_t ND44:1;                    /**< bit:     12  New Data                                      */
    uint32_t ND45:1;                    /**< bit:     13  New Data                                      */
    uint32_t ND46:1;                    /**< bit:     14  New Data                                      */
    uint32_t ND47:1;                    /**< bit:     15  New Data                                      */
    uint32_t ND48:1;                    /**< bit:     16  New Data                                      */
    uint32_t ND49:1;                    /**< bit:     17  New Data                                      */
    uint32_t ND50:1;                    /**< bit:     18  New Data                                      */
    uint32_t ND51:1;                    /**< bit:     19  New Data                                      */
    uint32_t ND52:1;                    /**< bit:     20  New Data                                      */
    uint32_t ND53:1;                    /**< bit:     21  New Data                                      */
    uint32_t ND54:1;                    /**< bit:     22  New Data                                      */
    uint32_t ND55:1;                    /**< bit:     23  New Data                                      */
    uint32_t ND56:1;                    /**< bit:     24  New Data                                      */
    uint32_t ND57:1;                    /**< bit:     25  New Data                                      */
    uint32_t ND58:1;                    /**< bit:     26  New Data                                      */
    uint32_t ND59:1;                    /**< bit:     27  New Data                                      */
    uint32_t ND60:1;                    /**< bit:     28  New Data                                      */
    uint32_t ND61:1;                    /**< bit:     29  New Data                                      */
    uint32_t ND62:1;                    /**< bit:     30  New Data                                      */
    uint32_t ND63:1;                    /**< bit:     31  New Data                                      */
  };
  struct
  {
    uint32_t ND:32;                     /**< bit:  0..31  New Data                                      */
  };
  uint32_t w;
} __MCAN_NDAT2_bits_t;

#define MCAN_NDAT2_ND32_Pos                   (0)                                            /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND32_Msk                   (0x1U << MCAN_NDAT2_ND32_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND33_Pos                   (1)                                            /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND33_Msk                   (0x1U << MCAN_NDAT2_ND33_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND34_Pos                   (2)                                            /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND34_Msk                   (0x1U << MCAN_NDAT2_ND34_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND35_Pos                   (3)                                            /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND35_Msk                   (0x1U << MCAN_NDAT2_ND35_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND36_Pos                   (4)                                            /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND36_Msk                   (0x1U << MCAN_NDAT2_ND36_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND37_Pos                   (5)                                            /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND37_Msk                   (0x1U << MCAN_NDAT2_ND37_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND38_Pos                   (6)                                            /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND38_Msk                   (0x1U << MCAN_NDAT2_ND38_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND39_Pos                   (7)                                            /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND39_Msk                   (0x1U << MCAN_NDAT2_ND39_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND40_Pos                   (8)                                            /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND40_Msk                   (0x1U << MCAN_NDAT2_ND40_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND41_Pos                   (9)                                            /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND41_Msk                   (0x1U << MCAN_NDAT2_ND41_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND42_Pos                   (10)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND42_Msk                   (0x1U << MCAN_NDAT2_ND42_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND43_Pos                   (11)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND43_Msk                   (0x1U << MCAN_NDAT2_ND43_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND44_Pos                   (12)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND44_Msk                   (0x1U << MCAN_NDAT2_ND44_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND45_Pos                   (13)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND45_Msk                   (0x1U << MCAN_NDAT2_ND45_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND46_Pos                   (14)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND46_Msk                   (0x1U << MCAN_NDAT2_ND46_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND47_Pos                   (15)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND47_Msk                   (0x1U << MCAN_NDAT2_ND47_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND48_Pos                   (16)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND48_Msk                   (0x1U << MCAN_NDAT2_ND48_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND49_Pos                   (17)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND49_Msk                   (0x1U << MCAN_NDAT2_ND49_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND50_Pos                   (18)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND50_Msk                   (0x1U << MCAN_NDAT2_ND50_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND51_Pos                   (19)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND51_Msk                   (0x1U << MCAN_NDAT2_ND51_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND52_Pos                   (20)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND52_Msk                   (0x1U << MCAN_NDAT2_ND52_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND53_Pos                   (21)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND53_Msk                   (0x1U << MCAN_NDAT2_ND53_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND54_Pos                   (22)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND54_Msk                   (0x1U << MCAN_NDAT2_ND54_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND55_Pos                   (23)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND55_Msk                   (0x1U << MCAN_NDAT2_ND55_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND56_Pos                   (24)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND56_Msk                   (0x1U << MCAN_NDAT2_ND56_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND57_Pos                   (25)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND57_Msk                   (0x1U << MCAN_NDAT2_ND57_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND58_Pos                   (26)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND58_Msk                   (0x1U << MCAN_NDAT2_ND58_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND59_Pos                   (27)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND59_Msk                   (0x1U << MCAN_NDAT2_ND59_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND60_Pos                   (28)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND60_Msk                   (0x1U << MCAN_NDAT2_ND60_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND61_Pos                   (29)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND61_Msk                   (0x1U << MCAN_NDAT2_ND61_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND62_Pos                   (30)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND62_Msk                   (0x1U << MCAN_NDAT2_ND62_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_ND63_Pos                   (31)                                           /**< (MCAN_NDAT2) New Data Position */
#define MCAN_NDAT2_ND63_Msk                   (0x1U << MCAN_NDAT2_ND63_Pos)                  /**< (MCAN_NDAT2) New Data Mask */
#define MCAN_NDAT2_Msk                        (0xFFFFFFFFUL)                                 /**< (MCAN_NDAT2) Register Mask  */
#define MCAN_NDAT2_ND_Pos                     (0)                                            /**< (MCAN_NDAT2 Position) New Data */
#define MCAN_NDAT2_ND_Msk                     (0xFFFFFFFFU << MCAN_NDAT2_ND_Pos)             /**< (MCAN_NDAT2 Mask) ND */
#define MCAN_NDAT2_ND(value)                  (MCAN_NDAT2_ND_Msk & ((value) << MCAN_NDAT2_ND_Pos))

/* -------- MCAN_RXF0C : (MCAN Offset: 0xa0) (R/W 32) Receive FIFO 0 Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t F0SA:14;                   /**< bit:  2..15  Receive FIFO 0 Start Address                  */
    uint32_t F0S:7;                     /**< bit: 16..22  Receive FIFO 0 Start Address                  */
    uint32_t :1;                        /**< bit:     23  Reserved                                      */
    uint32_t F0WM:7;                    /**< bit: 24..30  Receive FIFO 0 Watermark                      */
    uint32_t F0OM:1;                    /**< bit:     31  FIFO 0 Operation Mode                         */
  };
  uint32_t w;
} __MCAN_RXF0C_bits_t;

#define MCAN_RXF0C_F0SA_Pos                   (2)                                            /**< (MCAN_RXF0C) Receive FIFO 0 Start Address Position */
#define MCAN_RXF0C_F0SA_Msk                   (0x3FFFU << MCAN_RXF0C_F0SA_Pos)               /**< (MCAN_RXF0C) Receive FIFO 0 Start Address Mask */
#define MCAN_RXF0C_F0SA(value)                (MCAN_RXF0C_F0SA_Msk & ((value) << MCAN_RXF0C_F0SA_Pos))
#define MCAN_RXF0C_F0S_Pos                    (16)                                           /**< (MCAN_RXF0C) Receive FIFO 0 Start Address Position */
#define MCAN_RXF0C_F0S_Msk                    (0x7FU << MCAN_RXF0C_F0S_Pos)                  /**< (MCAN_RXF0C) Receive FIFO 0 Start Address Mask */
#define MCAN_RXF0C_F0S(value)                 (MCAN_RXF0C_F0S_Msk & ((value) << MCAN_RXF0C_F0S_Pos))
#define MCAN_RXF0C_F0WM_Pos                   (24)                                           /**< (MCAN_RXF0C) Receive FIFO 0 Watermark Position */
#define MCAN_RXF0C_F0WM_Msk                   (0x7FU << MCAN_RXF0C_F0WM_Pos)                 /**< (MCAN_RXF0C) Receive FIFO 0 Watermark Mask */
#define MCAN_RXF0C_F0WM(value)                (MCAN_RXF0C_F0WM_Msk & ((value) << MCAN_RXF0C_F0WM_Pos))
#define MCAN_RXF0C_F0OM_Pos                   (31)                                           /**< (MCAN_RXF0C) FIFO 0 Operation Mode Position */
#define MCAN_RXF0C_F0OM_Msk                   (0x1U << MCAN_RXF0C_F0OM_Pos)                  /**< (MCAN_RXF0C) FIFO 0 Operation Mode Mask */
#define MCAN_RXF0C_Msk                        (0xFF7FFFFCUL)                                 /**< (MCAN_RXF0C) Register Mask  */

/* -------- MCAN_RXF0S : (MCAN Offset: 0xa4) (R/ 32) Receive FIFO 0 Status Register -------- */

typedef union
{
  struct
  {
    uint32_t F0FL:7;                    /**< bit:   0..6  Receive FIFO 0 Fill Level                     */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t F0GI:6;                    /**< bit:  8..13  Receive FIFO 0 Get Index                      */
    uint32_t :2;                        /**< bit: 14..15  Reserved                                      */
    uint32_t F0PI:6;                    /**< bit: 16..21  Receive FIFO 0 Put Index                      */
    uint32_t :2;                        /**< bit: 22..23  Reserved                                      */
    uint32_t F0F:1;                     /**< bit:     24  Receive FIFO 0 Fill Level                     */
    uint32_t RF0L:1;                    /**< bit:     25  Receive FIFO 0 Message Lost                   */
    uint32_t :6;                        /**< bit: 26..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_RXF0S_bits_t;

#define MCAN_RXF0S_F0FL_Pos                   (0)                                            /**< (MCAN_RXF0S) Receive FIFO 0 Fill Level Position */
#define MCAN_RXF0S_F0FL_Msk                   (0x7FU << MCAN_RXF0S_F0FL_Pos)                 /**< (MCAN_RXF0S) Receive FIFO 0 Fill Level Mask */
#define MCAN_RXF0S_F0FL(value)                (MCAN_RXF0S_F0FL_Msk & ((value) << MCAN_RXF0S_F0FL_Pos))
#define MCAN_RXF0S_F0GI_Pos                   (8)                                            /**< (MCAN_RXF0S) Receive FIFO 0 Get Index Position */
#define MCAN_RXF0S_F0GI_Msk                   (0x3FU << MCAN_RXF0S_F0GI_Pos)                 /**< (MCAN_RXF0S) Receive FIFO 0 Get Index Mask */
#define MCAN_RXF0S_F0GI(value)                (MCAN_RXF0S_F0GI_Msk & ((value) << MCAN_RXF0S_F0GI_Pos))
#define MCAN_RXF0S_F0PI_Pos                   (16)                                           /**< (MCAN_RXF0S) Receive FIFO 0 Put Index Position */
#define MCAN_RXF0S_F0PI_Msk                   (0x3FU << MCAN_RXF0S_F0PI_Pos)                 /**< (MCAN_RXF0S) Receive FIFO 0 Put Index Mask */
#define MCAN_RXF0S_F0PI(value)                (MCAN_RXF0S_F0PI_Msk & ((value) << MCAN_RXF0S_F0PI_Pos))
#define MCAN_RXF0S_F0F_Pos                    (24)                                           /**< (MCAN_RXF0S) Receive FIFO 0 Fill Level Position */
#define MCAN_RXF0S_F0F_Msk                    (0x1U << MCAN_RXF0S_F0F_Pos)                   /**< (MCAN_RXF0S) Receive FIFO 0 Fill Level Mask */
#define MCAN_RXF0S_RF0L_Pos                   (25)                                           /**< (MCAN_RXF0S) Receive FIFO 0 Message Lost Position */
#define MCAN_RXF0S_RF0L_Msk                   (0x1U << MCAN_RXF0S_RF0L_Pos)                  /**< (MCAN_RXF0S) Receive FIFO 0 Message Lost Mask */
#define MCAN_RXF0S_Msk                        (0x033F3F7FUL)                                 /**< (MCAN_RXF0S) Register Mask  */

/* -------- MCAN_RXF0A : (MCAN Offset: 0xa8) (R/W 32) Receive FIFO 0 Acknowledge Register -------- */

typedef union
{
  struct
  {
    uint32_t F0AI:6;                    /**< bit:   0..5  Receive FIFO 0 Acknowledge Index              */
    uint32_t :26;                       /**< bit:  6..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_RXF0A_bits_t;

#define MCAN_RXF0A_F0AI_Pos                   (0)                                            /**< (MCAN_RXF0A) Receive FIFO 0 Acknowledge Index Position */
#define MCAN_RXF0A_F0AI_Msk                   (0x3FU << MCAN_RXF0A_F0AI_Pos)                 /**< (MCAN_RXF0A) Receive FIFO 0 Acknowledge Index Mask */
#define MCAN_RXF0A_F0AI(value)                (MCAN_RXF0A_F0AI_Msk & ((value) << MCAN_RXF0A_F0AI_Pos))
#define MCAN_RXF0A_Msk                        (0x0000003FUL)                                 /**< (MCAN_RXF0A) Register Mask  */

/* -------- MCAN_RXBC : (MCAN Offset: 0xac) (R/W 32) Receive Rx Buffer Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t RBSA:14;                   /**< bit:  2..15  Receive Buffer Start Address                  */
    uint32_t :16;                       /**< bit: 16..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_RXBC_bits_t;

#define MCAN_RXBC_RBSA_Pos                    (2)                                            /**< (MCAN_RXBC) Receive Buffer Start Address Position */
#define MCAN_RXBC_RBSA_Msk                    (0x3FFFU << MCAN_RXBC_RBSA_Pos)                /**< (MCAN_RXBC) Receive Buffer Start Address Mask */
#define MCAN_RXBC_RBSA(value)                 (MCAN_RXBC_RBSA_Msk & ((value) << MCAN_RXBC_RBSA_Pos))
#define MCAN_RXBC_Msk                         (0x0000FFFCUL)                                 /**< (MCAN_RXBC) Register Mask  */

/* -------- MCAN_RXF1C : (MCAN Offset: 0xb0) (R/W 32) Receive FIFO 1 Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t F1SA:14;                   /**< bit:  2..15  Receive FIFO 1 Start Address                  */
    uint32_t F1S:7;                     /**< bit: 16..22  Receive FIFO 1 Start Address                  */
    uint32_t :1;                        /**< bit:     23  Reserved                                      */
    uint32_t F1WM:7;                    /**< bit: 24..30  Receive FIFO 1 Watermark                      */
    uint32_t F1OM:1;                    /**< bit:     31  FIFO 1 Operation Mode                         */
  };
  uint32_t w;
} __MCAN_RXF1C_bits_t;

#define MCAN_RXF1C_F1SA_Pos                   (2)                                            /**< (MCAN_RXF1C) Receive FIFO 1 Start Address Position */
#define MCAN_RXF1C_F1SA_Msk                   (0x3FFFU << MCAN_RXF1C_F1SA_Pos)               /**< (MCAN_RXF1C) Receive FIFO 1 Start Address Mask */
#define MCAN_RXF1C_F1SA(value)                (MCAN_RXF1C_F1SA_Msk & ((value) << MCAN_RXF1C_F1SA_Pos))
#define MCAN_RXF1C_F1S_Pos                    (16)                                           /**< (MCAN_RXF1C) Receive FIFO 1 Start Address Position */
#define MCAN_RXF1C_F1S_Msk                    (0x7FU << MCAN_RXF1C_F1S_Pos)                  /**< (MCAN_RXF1C) Receive FIFO 1 Start Address Mask */
#define MCAN_RXF1C_F1S(value)                 (MCAN_RXF1C_F1S_Msk & ((value) << MCAN_RXF1C_F1S_Pos))
#define MCAN_RXF1C_F1WM_Pos                   (24)                                           /**< (MCAN_RXF1C) Receive FIFO 1 Watermark Position */
#define MCAN_RXF1C_F1WM_Msk                   (0x7FU << MCAN_RXF1C_F1WM_Pos)                 /**< (MCAN_RXF1C) Receive FIFO 1 Watermark Mask */
#define MCAN_RXF1C_F1WM(value)                (MCAN_RXF1C_F1WM_Msk & ((value) << MCAN_RXF1C_F1WM_Pos))
#define MCAN_RXF1C_F1OM_Pos                   (31)                                           /**< (MCAN_RXF1C) FIFO 1 Operation Mode Position */
#define MCAN_RXF1C_F1OM_Msk                   (0x1U << MCAN_RXF1C_F1OM_Pos)                  /**< (MCAN_RXF1C) FIFO 1 Operation Mode Mask */
#define MCAN_RXF1C_Msk                        (0xFF7FFFFCUL)                                 /**< (MCAN_RXF1C) Register Mask  */

/* -------- MCAN_RXF1S : (MCAN Offset: 0xb4) (R/ 32) Receive FIFO 1 Status Register -------- */

typedef union
{
  struct
  {
    uint32_t F1FL:7;                    /**< bit:   0..6  Receive FIFO 1 Fill Level                     */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t F1GI:6;                    /**< bit:  8..13  Receive FIFO 1 Get Index                      */
    uint32_t :2;                        /**< bit: 14..15  Reserved                                      */
    uint32_t F1PI:6;                    /**< bit: 16..21  Receive FIFO 1 Put Index                      */
    uint32_t :2;                        /**< bit: 22..23  Reserved                                      */
    uint32_t F1F:1;                     /**< bit:     24  Receive FIFO 1 Fill Level                     */
    uint32_t RF1L:1;                    /**< bit:     25  Receive FIFO 1 Message Lost                   */
    uint32_t :4;                        /**< bit: 26..29  Reserved                                      */
    uint32_t DMS:2;                     /**< bit: 30..31  Debug Message Status                          */
  };
  uint32_t w;
} __MCAN_RXF1S_bits_t;

#define MCAN_RXF1S_F1FL_Pos                   (0)                                            /**< (MCAN_RXF1S) Receive FIFO 1 Fill Level Position */
#define MCAN_RXF1S_F1FL_Msk                   (0x7FU << MCAN_RXF1S_F1FL_Pos)                 /**< (MCAN_RXF1S) Receive FIFO 1 Fill Level Mask */
#define MCAN_RXF1S_F1FL(value)                (MCAN_RXF1S_F1FL_Msk & ((value) << MCAN_RXF1S_F1FL_Pos))
#define MCAN_RXF1S_F1GI_Pos                   (8)                                            /**< (MCAN_RXF1S) Receive FIFO 1 Get Index Position */
#define MCAN_RXF1S_F1GI_Msk                   (0x3FU << MCAN_RXF1S_F1GI_Pos)                 /**< (MCAN_RXF1S) Receive FIFO 1 Get Index Mask */
#define MCAN_RXF1S_F1GI(value)                (MCAN_RXF1S_F1GI_Msk & ((value) << MCAN_RXF1S_F1GI_Pos))
#define MCAN_RXF1S_F1PI_Pos                   (16)                                           /**< (MCAN_RXF1S) Receive FIFO 1 Put Index Position */
#define MCAN_RXF1S_F1PI_Msk                   (0x3FU << MCAN_RXF1S_F1PI_Pos)                 /**< (MCAN_RXF1S) Receive FIFO 1 Put Index Mask */
#define MCAN_RXF1S_F1PI(value)                (MCAN_RXF1S_F1PI_Msk & ((value) << MCAN_RXF1S_F1PI_Pos))
#define MCAN_RXF1S_F1F_Pos                    (24)                                           /**< (MCAN_RXF1S) Receive FIFO 1 Fill Level Position */
#define MCAN_RXF1S_F1F_Msk                    (0x1U << MCAN_RXF1S_F1F_Pos)                   /**< (MCAN_RXF1S) Receive FIFO 1 Fill Level Mask */
#define MCAN_RXF1S_RF1L_Pos                   (25)                                           /**< (MCAN_RXF1S) Receive FIFO 1 Message Lost Position */
#define MCAN_RXF1S_RF1L_Msk                   (0x1U << MCAN_RXF1S_RF1L_Pos)                  /**< (MCAN_RXF1S) Receive FIFO 1 Message Lost Mask */
#define MCAN_RXF1S_DMS_Pos                    (30)                                           /**< (MCAN_RXF1S) Debug Message Status Position */
#define MCAN_RXF1S_DMS_Msk                    (0x3U << MCAN_RXF1S_DMS_Pos)                   /**< (MCAN_RXF1S) Debug Message Status Mask */
#define MCAN_RXF1S_DMS(value)                 (MCAN_RXF1S_DMS_Msk & ((value) << MCAN_RXF1S_DMS_Pos))
#define   MCAN_RXF1S_DMS_IDLE_Val             (0x0U)                                         /**< (MCAN_RXF1S) Idle state, wait for reception of debug messages, DMA request is cleared.  */
#define   MCAN_RXF1S_DMS_MSG_A_Val            (0x1U)                                         /**< (MCAN_RXF1S) Debug message A received.  */
#define   MCAN_RXF1S_DMS_MSG_AB_Val           (0x2U)                                         /**< (MCAN_RXF1S) Debug messages A, B received.  */
#define   MCAN_RXF1S_DMS_MSG_ABC_Val          (0x3U)                                         /**< (MCAN_RXF1S) Debug messages A, B, C received, DMA request is set.  */
#define MCAN_RXF1S_DMS_IDLE                   (MCAN_RXF1S_DMS_IDLE_Val << MCAN_RXF1S_DMS_Pos)  /**< (MCAN_RXF1S) Idle state, wait for reception of debug messages, DMA request is cleared. Position  */
#define MCAN_RXF1S_DMS_MSG_A                  (MCAN_RXF1S_DMS_MSG_A_Val << MCAN_RXF1S_DMS_Pos)  /**< (MCAN_RXF1S) Debug message A received. Position  */
#define MCAN_RXF1S_DMS_MSG_AB                 (MCAN_RXF1S_DMS_MSG_AB_Val << MCAN_RXF1S_DMS_Pos)  /**< (MCAN_RXF1S) Debug messages A, B received. Position  */
#define MCAN_RXF1S_DMS_MSG_ABC                (MCAN_RXF1S_DMS_MSG_ABC_Val << MCAN_RXF1S_DMS_Pos)  /**< (MCAN_RXF1S) Debug messages A, B, C received, DMA request is set. Position  */
#define MCAN_RXF1S_Msk                        (0xC33F3F7FUL)                                 /**< (MCAN_RXF1S) Register Mask  */

/* -------- MCAN_RXF1A : (MCAN Offset: 0xb8) (R/W 32) Receive FIFO 1 Acknowledge Register -------- */

typedef union
{
  struct
  {
    uint32_t F1AI:6;                    /**< bit:   0..5  Receive FIFO 1 Acknowledge Index              */
    uint32_t :26;                       /**< bit:  6..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_RXF1A_bits_t;

#define MCAN_RXF1A_F1AI_Pos                   (0)                                            /**< (MCAN_RXF1A) Receive FIFO 1 Acknowledge Index Position */
#define MCAN_RXF1A_F1AI_Msk                   (0x3FU << MCAN_RXF1A_F1AI_Pos)                 /**< (MCAN_RXF1A) Receive FIFO 1 Acknowledge Index Mask */
#define MCAN_RXF1A_F1AI(value)                (MCAN_RXF1A_F1AI_Msk & ((value) << MCAN_RXF1A_F1AI_Pos))
#define MCAN_RXF1A_Msk                        (0x0000003FUL)                                 /**< (MCAN_RXF1A) Register Mask  */

/* -------- MCAN_RXESC : (MCAN Offset: 0xbc) (R/W 32) Receive Buffer / FIFO Element Size Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t F0DS:3;                    /**< bit:   0..2  Receive FIFO 0 Data Field Size                */
    uint32_t :1;                        /**< bit:      3  Reserved                                      */
    uint32_t F1DS:3;                    /**< bit:   4..6  Receive FIFO 1 Data Field Size                */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t RBDS:3;                    /**< bit:  8..10  Receive Buffer Data Field Size                */
    uint32_t :21;                       /**< bit: 11..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_RXESC_bits_t;

#define MCAN_RXESC_F0DS_Pos                   (0)                                            /**< (MCAN_RXESC) Receive FIFO 0 Data Field Size Position */
#define MCAN_RXESC_F0DS_Msk                   (0x7U << MCAN_RXESC_F0DS_Pos)                  /**< (MCAN_RXESC) Receive FIFO 0 Data Field Size Mask */
#define MCAN_RXESC_F0DS(value)                (MCAN_RXESC_F0DS_Msk & ((value) << MCAN_RXESC_F0DS_Pos))
#define   MCAN_RXESC_F0DS_8_BYTE_Val          (0x0U)                                         /**< (MCAN_RXESC) 8-byte data field  */
#define   MCAN_RXESC_F0DS_12_BYTE_Val         (0x1U)                                         /**< (MCAN_RXESC) 12-byte data field  */
#define   MCAN_RXESC_F0DS_16_BYTE_Val         (0x2U)                                         /**< (MCAN_RXESC) 16-byte data field  */
#define   MCAN_RXESC_F0DS_20_BYTE_Val         (0x3U)                                         /**< (MCAN_RXESC) 20-byte data field  */
#define   MCAN_RXESC_F0DS_24_BYTE_Val         (0x4U)                                         /**< (MCAN_RXESC) 24-byte data field  */
#define   MCAN_RXESC_F0DS_32_BYTE_Val         (0x5U)                                         /**< (MCAN_RXESC) 32-byte data field  */
#define   MCAN_RXESC_F0DS_48_BYTE_Val         (0x6U)                                         /**< (MCAN_RXESC) 48-byte data field  */
#define   MCAN_RXESC_F0DS_64_BYTE_Val         (0x7U)                                         /**< (MCAN_RXESC) 64-byte data field  */
#define MCAN_RXESC_F0DS_8_BYTE                (MCAN_RXESC_F0DS_8_BYTE_Val << MCAN_RXESC_F0DS_Pos)  /**< (MCAN_RXESC) 8-byte data field Position  */
#define MCAN_RXESC_F0DS_12_BYTE               (MCAN_RXESC_F0DS_12_BYTE_Val << MCAN_RXESC_F0DS_Pos)  /**< (MCAN_RXESC) 12-byte data field Position  */
#define MCAN_RXESC_F0DS_16_BYTE               (MCAN_RXESC_F0DS_16_BYTE_Val << MCAN_RXESC_F0DS_Pos)  /**< (MCAN_RXESC) 16-byte data field Position  */
#define MCAN_RXESC_F0DS_20_BYTE               (MCAN_RXESC_F0DS_20_BYTE_Val << MCAN_RXESC_F0DS_Pos)  /**< (MCAN_RXESC) 20-byte data field Position  */
#define MCAN_RXESC_F0DS_24_BYTE               (MCAN_RXESC_F0DS_24_BYTE_Val << MCAN_RXESC_F0DS_Pos)  /**< (MCAN_RXESC) 24-byte data field Position  */
#define MCAN_RXESC_F0DS_32_BYTE               (MCAN_RXESC_F0DS_32_BYTE_Val << MCAN_RXESC_F0DS_Pos)  /**< (MCAN_RXESC) 32-byte data field Position  */
#define MCAN_RXESC_F0DS_48_BYTE               (MCAN_RXESC_F0DS_48_BYTE_Val << MCAN_RXESC_F0DS_Pos)  /**< (MCAN_RXESC) 48-byte data field Position  */
#define MCAN_RXESC_F0DS_64_BYTE               (MCAN_RXESC_F0DS_64_BYTE_Val << MCAN_RXESC_F0DS_Pos)  /**< (MCAN_RXESC) 64-byte data field Position  */
#define MCAN_RXESC_F1DS_Pos                   (4)                                            /**< (MCAN_RXESC) Receive FIFO 1 Data Field Size Position */
#define MCAN_RXESC_F1DS_Msk                   (0x7U << MCAN_RXESC_F1DS_Pos)                  /**< (MCAN_RXESC) Receive FIFO 1 Data Field Size Mask */
#define MCAN_RXESC_F1DS(value)                (MCAN_RXESC_F1DS_Msk & ((value) << MCAN_RXESC_F1DS_Pos))
#define   MCAN_RXESC_F1DS_8_BYTE_Val          (0x0U)                                         /**< (MCAN_RXESC) 8-byte data field  */
#define   MCAN_RXESC_F1DS_12_BYTE_Val         (0x1U)                                         /**< (MCAN_RXESC) 12-byte data field  */
#define   MCAN_RXESC_F1DS_16_BYTE_Val         (0x2U)                                         /**< (MCAN_RXESC) 16-byte data field  */
#define   MCAN_RXESC_F1DS_20_BYTE_Val         (0x3U)                                         /**< (MCAN_RXESC) 20-byte data field  */
#define   MCAN_RXESC_F1DS_24_BYTE_Val         (0x4U)                                         /**< (MCAN_RXESC) 24-byte data field  */
#define   MCAN_RXESC_F1DS_32_BYTE_Val         (0x5U)                                         /**< (MCAN_RXESC) 32-byte data field  */
#define   MCAN_RXESC_F1DS_48_BYTE_Val         (0x6U)                                         /**< (MCAN_RXESC) 48-byte data field  */
#define   MCAN_RXESC_F1DS_64_BYTE_Val         (0x7U)                                         /**< (MCAN_RXESC) 64-byte data field  */
#define MCAN_RXESC_F1DS_8_BYTE                (MCAN_RXESC_F1DS_8_BYTE_Val << MCAN_RXESC_F1DS_Pos)  /**< (MCAN_RXESC) 8-byte data field Position  */
#define MCAN_RXESC_F1DS_12_BYTE               (MCAN_RXESC_F1DS_12_BYTE_Val << MCAN_RXESC_F1DS_Pos)  /**< (MCAN_RXESC) 12-byte data field Position  */
#define MCAN_RXESC_F1DS_16_BYTE               (MCAN_RXESC_F1DS_16_BYTE_Val << MCAN_RXESC_F1DS_Pos)  /**< (MCAN_RXESC) 16-byte data field Position  */
#define MCAN_RXESC_F1DS_20_BYTE               (MCAN_RXESC_F1DS_20_BYTE_Val << MCAN_RXESC_F1DS_Pos)  /**< (MCAN_RXESC) 20-byte data field Position  */
#define MCAN_RXESC_F1DS_24_BYTE               (MCAN_RXESC_F1DS_24_BYTE_Val << MCAN_RXESC_F1DS_Pos)  /**< (MCAN_RXESC) 24-byte data field Position  */
#define MCAN_RXESC_F1DS_32_BYTE               (MCAN_RXESC_F1DS_32_BYTE_Val << MCAN_RXESC_F1DS_Pos)  /**< (MCAN_RXESC) 32-byte data field Position  */
#define MCAN_RXESC_F1DS_48_BYTE               (MCAN_RXESC_F1DS_48_BYTE_Val << MCAN_RXESC_F1DS_Pos)  /**< (MCAN_RXESC) 48-byte data field Position  */
#define MCAN_RXESC_F1DS_64_BYTE               (MCAN_RXESC_F1DS_64_BYTE_Val << MCAN_RXESC_F1DS_Pos)  /**< (MCAN_RXESC) 64-byte data field Position  */
#define MCAN_RXESC_RBDS_Pos                   (8)                                            /**< (MCAN_RXESC) Receive Buffer Data Field Size Position */
#define MCAN_RXESC_RBDS_Msk                   (0x7U << MCAN_RXESC_RBDS_Pos)                  /**< (MCAN_RXESC) Receive Buffer Data Field Size Mask */
#define MCAN_RXESC_RBDS(value)                (MCAN_RXESC_RBDS_Msk & ((value) << MCAN_RXESC_RBDS_Pos))
#define   MCAN_RXESC_RBDS_8_BYTE_Val          (0x0U)                                         /**< (MCAN_RXESC) 8-byte data field  */
#define   MCAN_RXESC_RBDS_12_BYTE_Val         (0x1U)                                         /**< (MCAN_RXESC) 12-byte data field  */
#define   MCAN_RXESC_RBDS_16_BYTE_Val         (0x2U)                                         /**< (MCAN_RXESC) 16-byte data field  */
#define   MCAN_RXESC_RBDS_20_BYTE_Val         (0x3U)                                         /**< (MCAN_RXESC) 20-byte data field  */
#define   MCAN_RXESC_RBDS_24_BYTE_Val         (0x4U)                                         /**< (MCAN_RXESC) 24-byte data field  */
#define   MCAN_RXESC_RBDS_32_BYTE_Val         (0x5U)                                         /**< (MCAN_RXESC) 32-byte data field  */
#define   MCAN_RXESC_RBDS_48_BYTE_Val         (0x6U)                                         /**< (MCAN_RXESC) 48-byte data field  */
#define   MCAN_RXESC_RBDS_64_BYTE_Val         (0x7U)                                         /**< (MCAN_RXESC) 64-byte data field  */
#define MCAN_RXESC_RBDS_8_BYTE                (MCAN_RXESC_RBDS_8_BYTE_Val << MCAN_RXESC_RBDS_Pos)  /**< (MCAN_RXESC) 8-byte data field Position  */
#define MCAN_RXESC_RBDS_12_BYTE               (MCAN_RXESC_RBDS_12_BYTE_Val << MCAN_RXESC_RBDS_Pos)  /**< (MCAN_RXESC) 12-byte data field Position  */
#define MCAN_RXESC_RBDS_16_BYTE               (MCAN_RXESC_RBDS_16_BYTE_Val << MCAN_RXESC_RBDS_Pos)  /**< (MCAN_RXESC) 16-byte data field Position  */
#define MCAN_RXESC_RBDS_20_BYTE               (MCAN_RXESC_RBDS_20_BYTE_Val << MCAN_RXESC_RBDS_Pos)  /**< (MCAN_RXESC) 20-byte data field Position  */
#define MCAN_RXESC_RBDS_24_BYTE               (MCAN_RXESC_RBDS_24_BYTE_Val << MCAN_RXESC_RBDS_Pos)  /**< (MCAN_RXESC) 24-byte data field Position  */
#define MCAN_RXESC_RBDS_32_BYTE               (MCAN_RXESC_RBDS_32_BYTE_Val << MCAN_RXESC_RBDS_Pos)  /**< (MCAN_RXESC) 32-byte data field Position  */
#define MCAN_RXESC_RBDS_48_BYTE               (MCAN_RXESC_RBDS_48_BYTE_Val << MCAN_RXESC_RBDS_Pos)  /**< (MCAN_RXESC) 48-byte data field Position  */
#define MCAN_RXESC_RBDS_64_BYTE               (MCAN_RXESC_RBDS_64_BYTE_Val << MCAN_RXESC_RBDS_Pos)  /**< (MCAN_RXESC) 64-byte data field Position  */
#define MCAN_RXESC_Msk                        (0x00000777UL)                                 /**< (MCAN_RXESC) Register Mask  */

/* -------- MCAN_TXBC : (MCAN Offset: 0xc0) (R/W 32) Transmit Buffer Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t TBSA:14;                   /**< bit:  2..15  Tx Buffers Start Address                      */
    uint32_t NDTB:6;                    /**< bit: 16..21  Number of Dedicated Transmit Buffers          */
    uint32_t :2;                        /**< bit: 22..23  Reserved                                      */
    uint32_t TFQS:6;                    /**< bit: 24..29  Transmit FIFO/Queue Size                      */
    uint32_t TFQM:1;                    /**< bit:     30  Tx FIFO/Queue Mode                            */
    uint32_t :1;                        /**< bit:     31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_TXBC_bits_t;

#define MCAN_TXBC_TBSA_Pos                    (2)                                            /**< (MCAN_TXBC) Tx Buffers Start Address Position */
#define MCAN_TXBC_TBSA_Msk                    (0x3FFFU << MCAN_TXBC_TBSA_Pos)                /**< (MCAN_TXBC) Tx Buffers Start Address Mask */
#define MCAN_TXBC_TBSA(value)                 (MCAN_TXBC_TBSA_Msk & ((value) << MCAN_TXBC_TBSA_Pos))
#define MCAN_TXBC_NDTB_Pos                    (16)                                           /**< (MCAN_TXBC) Number of Dedicated Transmit Buffers Position */
#define MCAN_TXBC_NDTB_Msk                    (0x3FU << MCAN_TXBC_NDTB_Pos)                  /**< (MCAN_TXBC) Number of Dedicated Transmit Buffers Mask */
#define MCAN_TXBC_NDTB(value)                 (MCAN_TXBC_NDTB_Msk & ((value) << MCAN_TXBC_NDTB_Pos))
#define MCAN_TXBC_TFQS_Pos                    (24)                                           /**< (MCAN_TXBC) Transmit FIFO/Queue Size Position */
#define MCAN_TXBC_TFQS_Msk                    (0x3FU << MCAN_TXBC_TFQS_Pos)                  /**< (MCAN_TXBC) Transmit FIFO/Queue Size Mask */
#define MCAN_TXBC_TFQS(value)                 (MCAN_TXBC_TFQS_Msk & ((value) << MCAN_TXBC_TFQS_Pos))
#define MCAN_TXBC_TFQM_Pos                    (30)                                           /**< (MCAN_TXBC) Tx FIFO/Queue Mode Position */
#define MCAN_TXBC_TFQM_Msk                    (0x1U << MCAN_TXBC_TFQM_Pos)                   /**< (MCAN_TXBC) Tx FIFO/Queue Mode Mask */
#define MCAN_TXBC_Msk                         (0x7F3FFFFCUL)                                 /**< (MCAN_TXBC) Register Mask  */

/* -------- MCAN_TXFQS : (MCAN Offset: 0xc4) (R/ 32) Transmit FIFO/Queue Status Register -------- */

typedef union
{
  struct
  {
    uint32_t TFFL:6;                    /**< bit:   0..5  Tx FIFO Free Level                            */
    uint32_t :2;                        /**< bit:   6..7  Reserved                                      */
    uint32_t TFGI:5;                    /**< bit:  8..12  Tx FIFO Get Index                             */
    uint32_t :3;                        /**< bit: 13..15  Reserved                                      */
    uint32_t TFQPI:5;                   /**< bit: 16..20  Tx FIFO/Queue Put Index                       */
    uint32_t TFQF:1;                    /**< bit:     21  Tx FIFO/Queue Full                            */
    uint32_t :10;                       /**< bit: 22..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_TXFQS_bits_t;

#define MCAN_TXFQS_TFFL_Pos                   (0)                                            /**< (MCAN_TXFQS) Tx FIFO Free Level Position */
#define MCAN_TXFQS_TFFL_Msk                   (0x3FU << MCAN_TXFQS_TFFL_Pos)                 /**< (MCAN_TXFQS) Tx FIFO Free Level Mask */
#define MCAN_TXFQS_TFFL(value)                (MCAN_TXFQS_TFFL_Msk & ((value) << MCAN_TXFQS_TFFL_Pos))
#define MCAN_TXFQS_TFGI_Pos                   (8)                                            /**< (MCAN_TXFQS) Tx FIFO Get Index Position */
#define MCAN_TXFQS_TFGI_Msk                   (0x1FU << MCAN_TXFQS_TFGI_Pos)                 /**< (MCAN_TXFQS) Tx FIFO Get Index Mask */
#define MCAN_TXFQS_TFGI(value)                (MCAN_TXFQS_TFGI_Msk & ((value) << MCAN_TXFQS_TFGI_Pos))
#define MCAN_TXFQS_TFQPI_Pos                  (16)                                           /**< (MCAN_TXFQS) Tx FIFO/Queue Put Index Position */
#define MCAN_TXFQS_TFQPI_Msk                  (0x1FU << MCAN_TXFQS_TFQPI_Pos)                /**< (MCAN_TXFQS) Tx FIFO/Queue Put Index Mask */
#define MCAN_TXFQS_TFQPI(value)               (MCAN_TXFQS_TFQPI_Msk & ((value) << MCAN_TXFQS_TFQPI_Pos))
#define MCAN_TXFQS_TFQF_Pos                   (21)                                           /**< (MCAN_TXFQS) Tx FIFO/Queue Full Position */
#define MCAN_TXFQS_TFQF_Msk                   (0x1U << MCAN_TXFQS_TFQF_Pos)                  /**< (MCAN_TXFQS) Tx FIFO/Queue Full Mask */
#define MCAN_TXFQS_Msk                        (0x003F1F3FUL)                                 /**< (MCAN_TXFQS) Register Mask  */

/* -------- MCAN_TXESC : (MCAN Offset: 0xc8) (R/W 32) Transmit Buffer Element Size Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t TBDS:3;                    /**< bit:   0..2  Tx Buffer Data Field Size                     */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_TXESC_bits_t;

#define MCAN_TXESC_TBDS_Pos                   (0)                                            /**< (MCAN_TXESC) Tx Buffer Data Field Size Position */
#define MCAN_TXESC_TBDS_Msk                   (0x7U << MCAN_TXESC_TBDS_Pos)                  /**< (MCAN_TXESC) Tx Buffer Data Field Size Mask */
#define MCAN_TXESC_TBDS(value)                (MCAN_TXESC_TBDS_Msk & ((value) << MCAN_TXESC_TBDS_Pos))
#define   MCAN_TXESC_TBDS_8_BYTE_Val          (0x0U)                                         /**< (MCAN_TXESC) 8-byte data field  */
#define   MCAN_TXESC_TBDS_12_BYTE_Val         (0x1U)                                         /**< (MCAN_TXESC) 12-byte data field  */
#define   MCAN_TXESC_TBDS_16_BYTE_Val         (0x2U)                                         /**< (MCAN_TXESC) 16-byte data field  */
#define   MCAN_TXESC_TBDS_20_BYTE_Val         (0x3U)                                         /**< (MCAN_TXESC) 20-byte data field  */
#define   MCAN_TXESC_TBDS_24_BYTE_Val         (0x4U)                                         /**< (MCAN_TXESC) 24-byte data field  */
#define   MCAN_TXESC_TBDS_32_BYTE_Val         (0x5U)                                         /**< (MCAN_TXESC) 32-byte data field  */
#define   MCAN_TXESC_TBDS_48_BYTE_Val         (0x6U)                                         /**< (MCAN_TXESC) 48- byte data field  */
#define   MCAN_TXESC_TBDS_64_BYTE_Val         (0x7U)                                         /**< (MCAN_TXESC) 64-byte data field  */
#define MCAN_TXESC_TBDS_8_BYTE                (MCAN_TXESC_TBDS_8_BYTE_Val << MCAN_TXESC_TBDS_Pos)  /**< (MCAN_TXESC) 8-byte data field Position  */
#define MCAN_TXESC_TBDS_12_BYTE               (MCAN_TXESC_TBDS_12_BYTE_Val << MCAN_TXESC_TBDS_Pos)  /**< (MCAN_TXESC) 12-byte data field Position  */
#define MCAN_TXESC_TBDS_16_BYTE               (MCAN_TXESC_TBDS_16_BYTE_Val << MCAN_TXESC_TBDS_Pos)  /**< (MCAN_TXESC) 16-byte data field Position  */
#define MCAN_TXESC_TBDS_20_BYTE               (MCAN_TXESC_TBDS_20_BYTE_Val << MCAN_TXESC_TBDS_Pos)  /**< (MCAN_TXESC) 20-byte data field Position  */
#define MCAN_TXESC_TBDS_24_BYTE               (MCAN_TXESC_TBDS_24_BYTE_Val << MCAN_TXESC_TBDS_Pos)  /**< (MCAN_TXESC) 24-byte data field Position  */
#define MCAN_TXESC_TBDS_32_BYTE               (MCAN_TXESC_TBDS_32_BYTE_Val << MCAN_TXESC_TBDS_Pos)  /**< (MCAN_TXESC) 32-byte data field Position  */
#define MCAN_TXESC_TBDS_48_BYTE               (MCAN_TXESC_TBDS_48_BYTE_Val << MCAN_TXESC_TBDS_Pos)  /**< (MCAN_TXESC) 48- byte data field Position  */
#define MCAN_TXESC_TBDS_64_BYTE               (MCAN_TXESC_TBDS_64_BYTE_Val << MCAN_TXESC_TBDS_Pos)  /**< (MCAN_TXESC) 64-byte data field Position  */
#define MCAN_TXESC_Msk                        (0x00000007UL)                                 /**< (MCAN_TXESC) Register Mask  */

/* -------- MCAN_TXBRP : (MCAN Offset: 0xcc) (R/ 32) Transmit Buffer Request Pending Register -------- */

typedef union
{
  struct
  {
    uint32_t TRP0:1;                    /**< bit:      0  Transmission Request Pending for Buffer 0     */
    uint32_t TRP1:1;                    /**< bit:      1  Transmission Request Pending for Buffer 1     */
    uint32_t TRP2:1;                    /**< bit:      2  Transmission Request Pending for Buffer 2     */
    uint32_t TRP3:1;                    /**< bit:      3  Transmission Request Pending for Buffer 3     */
    uint32_t TRP4:1;                    /**< bit:      4  Transmission Request Pending for Buffer 4     */
    uint32_t TRP5:1;                    /**< bit:      5  Transmission Request Pending for Buffer 5     */
    uint32_t TRP6:1;                    /**< bit:      6  Transmission Request Pending for Buffer 6     */
    uint32_t TRP7:1;                    /**< bit:      7  Transmission Request Pending for Buffer 7     */
    uint32_t TRP8:1;                    /**< bit:      8  Transmission Request Pending for Buffer 8     */
    uint32_t TRP9:1;                    /**< bit:      9  Transmission Request Pending for Buffer 9     */
    uint32_t TRP10:1;                   /**< bit:     10  Transmission Request Pending for Buffer 10    */
    uint32_t TRP11:1;                   /**< bit:     11  Transmission Request Pending for Buffer 11    */
    uint32_t TRP12:1;                   /**< bit:     12  Transmission Request Pending for Buffer 12    */
    uint32_t TRP13:1;                   /**< bit:     13  Transmission Request Pending for Buffer 13    */
    uint32_t TRP14:1;                   /**< bit:     14  Transmission Request Pending for Buffer 14    */
    uint32_t TRP15:1;                   /**< bit:     15  Transmission Request Pending for Buffer 15    */
    uint32_t TRP16:1;                   /**< bit:     16  Transmission Request Pending for Buffer 16    */
    uint32_t TRP17:1;                   /**< bit:     17  Transmission Request Pending for Buffer 17    */
    uint32_t TRP18:1;                   /**< bit:     18  Transmission Request Pending for Buffer 18    */
    uint32_t TRP19:1;                   /**< bit:     19  Transmission Request Pending for Buffer 19    */
    uint32_t TRP20:1;                   /**< bit:     20  Transmission Request Pending for Buffer 20    */
    uint32_t TRP21:1;                   /**< bit:     21  Transmission Request Pending for Buffer 21    */
    uint32_t TRP22:1;                   /**< bit:     22  Transmission Request Pending for Buffer 22    */
    uint32_t TRP23:1;                   /**< bit:     23  Transmission Request Pending for Buffer 23    */
    uint32_t TRP24:1;                   /**< bit:     24  Transmission Request Pending for Buffer 24    */
    uint32_t TRP25:1;                   /**< bit:     25  Transmission Request Pending for Buffer 25    */
    uint32_t TRP26:1;                   /**< bit:     26  Transmission Request Pending for Buffer 26    */
    uint32_t TRP27:1;                   /**< bit:     27  Transmission Request Pending for Buffer 27    */
    uint32_t TRP28:1;                   /**< bit:     28  Transmission Request Pending for Buffer 28    */
    uint32_t TRP29:1;                   /**< bit:     29  Transmission Request Pending for Buffer 29    */
    uint32_t TRP30:1;                   /**< bit:     30  Transmission Request Pending for Buffer 30    */
    uint32_t TRP31:1;                   /**< bit:     31  Transmission Request Pending for Buffer 31    */
  };
  struct
  {
    uint32_t TRP:32;                    /**< bit:  0..31  Transmission Request Pending for Buffer 3x    */
  };
  uint32_t w;
} __MCAN_TXBRP_bits_t;

#define MCAN_TXBRP_TRP0_Pos                   (0)                                            /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 0 Position */
#define MCAN_TXBRP_TRP0_Msk                   (0x1U << MCAN_TXBRP_TRP0_Pos)                  /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 0 Mask */
#define MCAN_TXBRP_TRP1_Pos                   (1)                                            /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 1 Position */
#define MCAN_TXBRP_TRP1_Msk                   (0x1U << MCAN_TXBRP_TRP1_Pos)                  /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 1 Mask */
#define MCAN_TXBRP_TRP2_Pos                   (2)                                            /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 2 Position */
#define MCAN_TXBRP_TRP2_Msk                   (0x1U << MCAN_TXBRP_TRP2_Pos)                  /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 2 Mask */
#define MCAN_TXBRP_TRP3_Pos                   (3)                                            /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 3 Position */
#define MCAN_TXBRP_TRP3_Msk                   (0x1U << MCAN_TXBRP_TRP3_Pos)                  /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 3 Mask */
#define MCAN_TXBRP_TRP4_Pos                   (4)                                            /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 4 Position */
#define MCAN_TXBRP_TRP4_Msk                   (0x1U << MCAN_TXBRP_TRP4_Pos)                  /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 4 Mask */
#define MCAN_TXBRP_TRP5_Pos                   (5)                                            /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 5 Position */
#define MCAN_TXBRP_TRP5_Msk                   (0x1U << MCAN_TXBRP_TRP5_Pos)                  /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 5 Mask */
#define MCAN_TXBRP_TRP6_Pos                   (6)                                            /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 6 Position */
#define MCAN_TXBRP_TRP6_Msk                   (0x1U << MCAN_TXBRP_TRP6_Pos)                  /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 6 Mask */
#define MCAN_TXBRP_TRP7_Pos                   (7)                                            /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 7 Position */
#define MCAN_TXBRP_TRP7_Msk                   (0x1U << MCAN_TXBRP_TRP7_Pos)                  /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 7 Mask */
#define MCAN_TXBRP_TRP8_Pos                   (8)                                            /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 8 Position */
#define MCAN_TXBRP_TRP8_Msk                   (0x1U << MCAN_TXBRP_TRP8_Pos)                  /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 8 Mask */
#define MCAN_TXBRP_TRP9_Pos                   (9)                                            /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 9 Position */
#define MCAN_TXBRP_TRP9_Msk                   (0x1U << MCAN_TXBRP_TRP9_Pos)                  /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 9 Mask */
#define MCAN_TXBRP_TRP10_Pos                  (10)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 10 Position */
#define MCAN_TXBRP_TRP10_Msk                  (0x1U << MCAN_TXBRP_TRP10_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 10 Mask */
#define MCAN_TXBRP_TRP11_Pos                  (11)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 11 Position */
#define MCAN_TXBRP_TRP11_Msk                  (0x1U << MCAN_TXBRP_TRP11_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 11 Mask */
#define MCAN_TXBRP_TRP12_Pos                  (12)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 12 Position */
#define MCAN_TXBRP_TRP12_Msk                  (0x1U << MCAN_TXBRP_TRP12_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 12 Mask */
#define MCAN_TXBRP_TRP13_Pos                  (13)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 13 Position */
#define MCAN_TXBRP_TRP13_Msk                  (0x1U << MCAN_TXBRP_TRP13_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 13 Mask */
#define MCAN_TXBRP_TRP14_Pos                  (14)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 14 Position */
#define MCAN_TXBRP_TRP14_Msk                  (0x1U << MCAN_TXBRP_TRP14_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 14 Mask */
#define MCAN_TXBRP_TRP15_Pos                  (15)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 15 Position */
#define MCAN_TXBRP_TRP15_Msk                  (0x1U << MCAN_TXBRP_TRP15_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 15 Mask */
#define MCAN_TXBRP_TRP16_Pos                  (16)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 16 Position */
#define MCAN_TXBRP_TRP16_Msk                  (0x1U << MCAN_TXBRP_TRP16_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 16 Mask */
#define MCAN_TXBRP_TRP17_Pos                  (17)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 17 Position */
#define MCAN_TXBRP_TRP17_Msk                  (0x1U << MCAN_TXBRP_TRP17_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 17 Mask */
#define MCAN_TXBRP_TRP18_Pos                  (18)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 18 Position */
#define MCAN_TXBRP_TRP18_Msk                  (0x1U << MCAN_TXBRP_TRP18_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 18 Mask */
#define MCAN_TXBRP_TRP19_Pos                  (19)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 19 Position */
#define MCAN_TXBRP_TRP19_Msk                  (0x1U << MCAN_TXBRP_TRP19_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 19 Mask */
#define MCAN_TXBRP_TRP20_Pos                  (20)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 20 Position */
#define MCAN_TXBRP_TRP20_Msk                  (0x1U << MCAN_TXBRP_TRP20_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 20 Mask */
#define MCAN_TXBRP_TRP21_Pos                  (21)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 21 Position */
#define MCAN_TXBRP_TRP21_Msk                  (0x1U << MCAN_TXBRP_TRP21_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 21 Mask */
#define MCAN_TXBRP_TRP22_Pos                  (22)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 22 Position */
#define MCAN_TXBRP_TRP22_Msk                  (0x1U << MCAN_TXBRP_TRP22_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 22 Mask */
#define MCAN_TXBRP_TRP23_Pos                  (23)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 23 Position */
#define MCAN_TXBRP_TRP23_Msk                  (0x1U << MCAN_TXBRP_TRP23_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 23 Mask */
#define MCAN_TXBRP_TRP24_Pos                  (24)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 24 Position */
#define MCAN_TXBRP_TRP24_Msk                  (0x1U << MCAN_TXBRP_TRP24_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 24 Mask */
#define MCAN_TXBRP_TRP25_Pos                  (25)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 25 Position */
#define MCAN_TXBRP_TRP25_Msk                  (0x1U << MCAN_TXBRP_TRP25_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 25 Mask */
#define MCAN_TXBRP_TRP26_Pos                  (26)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 26 Position */
#define MCAN_TXBRP_TRP26_Msk                  (0x1U << MCAN_TXBRP_TRP26_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 26 Mask */
#define MCAN_TXBRP_TRP27_Pos                  (27)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 27 Position */
#define MCAN_TXBRP_TRP27_Msk                  (0x1U << MCAN_TXBRP_TRP27_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 27 Mask */
#define MCAN_TXBRP_TRP28_Pos                  (28)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 28 Position */
#define MCAN_TXBRP_TRP28_Msk                  (0x1U << MCAN_TXBRP_TRP28_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 28 Mask */
#define MCAN_TXBRP_TRP29_Pos                  (29)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 29 Position */
#define MCAN_TXBRP_TRP29_Msk                  (0x1U << MCAN_TXBRP_TRP29_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 29 Mask */
#define MCAN_TXBRP_TRP30_Pos                  (30)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 30 Position */
#define MCAN_TXBRP_TRP30_Msk                  (0x1U << MCAN_TXBRP_TRP30_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 30 Mask */
#define MCAN_TXBRP_TRP31_Pos                  (31)                                           /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 31 Position */
#define MCAN_TXBRP_TRP31_Msk                  (0x1U << MCAN_TXBRP_TRP31_Pos)                 /**< (MCAN_TXBRP) Transmission Request Pending for Buffer 31 Mask */
#define MCAN_TXBRP_Msk                        (0xFFFFFFFFUL)                                 /**< (MCAN_TXBRP) Register Mask  */
#define MCAN_TXBRP_TRP_Pos                    (0)                                            /**< (MCAN_TXBRP Position) Transmission Request Pending for Buffer 3x */
#define MCAN_TXBRP_TRP_Msk                    (0xFFFFFFFFU << MCAN_TXBRP_TRP_Pos)            /**< (MCAN_TXBRP Mask) TRP */
#define MCAN_TXBRP_TRP(value)                 (MCAN_TXBRP_TRP_Msk & ((value) << MCAN_TXBRP_TRP_Pos))

/* -------- MCAN_TXBAR : (MCAN Offset: 0xd0) (R/W 32) Transmit Buffer Add Request Register -------- */

typedef union
{
  struct
  {
    uint32_t AR0:1;                     /**< bit:      0  Add Request for Transmit Buffer 0             */
    uint32_t AR1:1;                     /**< bit:      1  Add Request for Transmit Buffer 1             */
    uint32_t AR2:1;                     /**< bit:      2  Add Request for Transmit Buffer 2             */
    uint32_t AR3:1;                     /**< bit:      3  Add Request for Transmit Buffer 3             */
    uint32_t AR4:1;                     /**< bit:      4  Add Request for Transmit Buffer 4             */
    uint32_t AR5:1;                     /**< bit:      5  Add Request for Transmit Buffer 5             */
    uint32_t AR6:1;                     /**< bit:      6  Add Request for Transmit Buffer 6             */
    uint32_t AR7:1;                     /**< bit:      7  Add Request for Transmit Buffer 7             */
    uint32_t AR8:1;                     /**< bit:      8  Add Request for Transmit Buffer 8             */
    uint32_t AR9:1;                     /**< bit:      9  Add Request for Transmit Buffer 9             */
    uint32_t AR10:1;                    /**< bit:     10  Add Request for Transmit Buffer 10            */
    uint32_t AR11:1;                    /**< bit:     11  Add Request for Transmit Buffer 11            */
    uint32_t AR12:1;                    /**< bit:     12  Add Request for Transmit Buffer 12            */
    uint32_t AR13:1;                    /**< bit:     13  Add Request for Transmit Buffer 13            */
    uint32_t AR14:1;                    /**< bit:     14  Add Request for Transmit Buffer 14            */
    uint32_t AR15:1;                    /**< bit:     15  Add Request for Transmit Buffer 15            */
    uint32_t AR16:1;                    /**< bit:     16  Add Request for Transmit Buffer 16            */
    uint32_t AR17:1;                    /**< bit:     17  Add Request for Transmit Buffer 17            */
    uint32_t AR18:1;                    /**< bit:     18  Add Request for Transmit Buffer 18            */
    uint32_t AR19:1;                    /**< bit:     19  Add Request for Transmit Buffer 19            */
    uint32_t AR20:1;                    /**< bit:     20  Add Request for Transmit Buffer 20            */
    uint32_t AR21:1;                    /**< bit:     21  Add Request for Transmit Buffer 21            */
    uint32_t AR22:1;                    /**< bit:     22  Add Request for Transmit Buffer 22            */
    uint32_t AR23:1;                    /**< bit:     23  Add Request for Transmit Buffer 23            */
    uint32_t AR24:1;                    /**< bit:     24  Add Request for Transmit Buffer 24            */
    uint32_t AR25:1;                    /**< bit:     25  Add Request for Transmit Buffer 25            */
    uint32_t AR26:1;                    /**< bit:     26  Add Request for Transmit Buffer 26            */
    uint32_t AR27:1;                    /**< bit:     27  Add Request for Transmit Buffer 27            */
    uint32_t AR28:1;                    /**< bit:     28  Add Request for Transmit Buffer 28            */
    uint32_t AR29:1;                    /**< bit:     29  Add Request for Transmit Buffer 29            */
    uint32_t AR30:1;                    /**< bit:     30  Add Request for Transmit Buffer 30            */
    uint32_t AR31:1;                    /**< bit:     31  Add Request for Transmit Buffer 31            */
  };
  struct
  {
    uint32_t AR:32;                     /**< bit:  0..31  Add Request for Transmit Buffer 3x            */
  };
  uint32_t w;
} __MCAN_TXBAR_bits_t;

#define MCAN_TXBAR_AR0_Pos                    (0)                                            /**< (MCAN_TXBAR) Add Request for Transmit Buffer 0 Position */
#define MCAN_TXBAR_AR0_Msk                    (0x1U << MCAN_TXBAR_AR0_Pos)                   /**< (MCAN_TXBAR) Add Request for Transmit Buffer 0 Mask */
#define MCAN_TXBAR_AR1_Pos                    (1)                                            /**< (MCAN_TXBAR) Add Request for Transmit Buffer 1 Position */
#define MCAN_TXBAR_AR1_Msk                    (0x1U << MCAN_TXBAR_AR1_Pos)                   /**< (MCAN_TXBAR) Add Request for Transmit Buffer 1 Mask */
#define MCAN_TXBAR_AR2_Pos                    (2)                                            /**< (MCAN_TXBAR) Add Request for Transmit Buffer 2 Position */
#define MCAN_TXBAR_AR2_Msk                    (0x1U << MCAN_TXBAR_AR2_Pos)                   /**< (MCAN_TXBAR) Add Request for Transmit Buffer 2 Mask */
#define MCAN_TXBAR_AR3_Pos                    (3)                                            /**< (MCAN_TXBAR) Add Request for Transmit Buffer 3 Position */
#define MCAN_TXBAR_AR3_Msk                    (0x1U << MCAN_TXBAR_AR3_Pos)                   /**< (MCAN_TXBAR) Add Request for Transmit Buffer 3 Mask */
#define MCAN_TXBAR_AR4_Pos                    (4)                                            /**< (MCAN_TXBAR) Add Request for Transmit Buffer 4 Position */
#define MCAN_TXBAR_AR4_Msk                    (0x1U << MCAN_TXBAR_AR4_Pos)                   /**< (MCAN_TXBAR) Add Request for Transmit Buffer 4 Mask */
#define MCAN_TXBAR_AR5_Pos                    (5)                                            /**< (MCAN_TXBAR) Add Request for Transmit Buffer 5 Position */
#define MCAN_TXBAR_AR5_Msk                    (0x1U << MCAN_TXBAR_AR5_Pos)                   /**< (MCAN_TXBAR) Add Request for Transmit Buffer 5 Mask */
#define MCAN_TXBAR_AR6_Pos                    (6)                                            /**< (MCAN_TXBAR) Add Request for Transmit Buffer 6 Position */
#define MCAN_TXBAR_AR6_Msk                    (0x1U << MCAN_TXBAR_AR6_Pos)                   /**< (MCAN_TXBAR) Add Request for Transmit Buffer 6 Mask */
#define MCAN_TXBAR_AR7_Pos                    (7)                                            /**< (MCAN_TXBAR) Add Request for Transmit Buffer 7 Position */
#define MCAN_TXBAR_AR7_Msk                    (0x1U << MCAN_TXBAR_AR7_Pos)                   /**< (MCAN_TXBAR) Add Request for Transmit Buffer 7 Mask */
#define MCAN_TXBAR_AR8_Pos                    (8)                                            /**< (MCAN_TXBAR) Add Request for Transmit Buffer 8 Position */
#define MCAN_TXBAR_AR8_Msk                    (0x1U << MCAN_TXBAR_AR8_Pos)                   /**< (MCAN_TXBAR) Add Request for Transmit Buffer 8 Mask */
#define MCAN_TXBAR_AR9_Pos                    (9)                                            /**< (MCAN_TXBAR) Add Request for Transmit Buffer 9 Position */
#define MCAN_TXBAR_AR9_Msk                    (0x1U << MCAN_TXBAR_AR9_Pos)                   /**< (MCAN_TXBAR) Add Request for Transmit Buffer 9 Mask */
#define MCAN_TXBAR_AR10_Pos                   (10)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 10 Position */
#define MCAN_TXBAR_AR10_Msk                   (0x1U << MCAN_TXBAR_AR10_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 10 Mask */
#define MCAN_TXBAR_AR11_Pos                   (11)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 11 Position */
#define MCAN_TXBAR_AR11_Msk                   (0x1U << MCAN_TXBAR_AR11_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 11 Mask */
#define MCAN_TXBAR_AR12_Pos                   (12)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 12 Position */
#define MCAN_TXBAR_AR12_Msk                   (0x1U << MCAN_TXBAR_AR12_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 12 Mask */
#define MCAN_TXBAR_AR13_Pos                   (13)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 13 Position */
#define MCAN_TXBAR_AR13_Msk                   (0x1U << MCAN_TXBAR_AR13_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 13 Mask */
#define MCAN_TXBAR_AR14_Pos                   (14)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 14 Position */
#define MCAN_TXBAR_AR14_Msk                   (0x1U << MCAN_TXBAR_AR14_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 14 Mask */
#define MCAN_TXBAR_AR15_Pos                   (15)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 15 Position */
#define MCAN_TXBAR_AR15_Msk                   (0x1U << MCAN_TXBAR_AR15_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 15 Mask */
#define MCAN_TXBAR_AR16_Pos                   (16)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 16 Position */
#define MCAN_TXBAR_AR16_Msk                   (0x1U << MCAN_TXBAR_AR16_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 16 Mask */
#define MCAN_TXBAR_AR17_Pos                   (17)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 17 Position */
#define MCAN_TXBAR_AR17_Msk                   (0x1U << MCAN_TXBAR_AR17_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 17 Mask */
#define MCAN_TXBAR_AR18_Pos                   (18)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 18 Position */
#define MCAN_TXBAR_AR18_Msk                   (0x1U << MCAN_TXBAR_AR18_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 18 Mask */
#define MCAN_TXBAR_AR19_Pos                   (19)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 19 Position */
#define MCAN_TXBAR_AR19_Msk                   (0x1U << MCAN_TXBAR_AR19_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 19 Mask */
#define MCAN_TXBAR_AR20_Pos                   (20)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 20 Position */
#define MCAN_TXBAR_AR20_Msk                   (0x1U << MCAN_TXBAR_AR20_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 20 Mask */
#define MCAN_TXBAR_AR21_Pos                   (21)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 21 Position */
#define MCAN_TXBAR_AR21_Msk                   (0x1U << MCAN_TXBAR_AR21_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 21 Mask */
#define MCAN_TXBAR_AR22_Pos                   (22)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 22 Position */
#define MCAN_TXBAR_AR22_Msk                   (0x1U << MCAN_TXBAR_AR22_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 22 Mask */
#define MCAN_TXBAR_AR23_Pos                   (23)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 23 Position */
#define MCAN_TXBAR_AR23_Msk                   (0x1U << MCAN_TXBAR_AR23_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 23 Mask */
#define MCAN_TXBAR_AR24_Pos                   (24)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 24 Position */
#define MCAN_TXBAR_AR24_Msk                   (0x1U << MCAN_TXBAR_AR24_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 24 Mask */
#define MCAN_TXBAR_AR25_Pos                   (25)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 25 Position */
#define MCAN_TXBAR_AR25_Msk                   (0x1U << MCAN_TXBAR_AR25_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 25 Mask */
#define MCAN_TXBAR_AR26_Pos                   (26)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 26 Position */
#define MCAN_TXBAR_AR26_Msk                   (0x1U << MCAN_TXBAR_AR26_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 26 Mask */
#define MCAN_TXBAR_AR27_Pos                   (27)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 27 Position */
#define MCAN_TXBAR_AR27_Msk                   (0x1U << MCAN_TXBAR_AR27_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 27 Mask */
#define MCAN_TXBAR_AR28_Pos                   (28)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 28 Position */
#define MCAN_TXBAR_AR28_Msk                   (0x1U << MCAN_TXBAR_AR28_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 28 Mask */
#define MCAN_TXBAR_AR29_Pos                   (29)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 29 Position */
#define MCAN_TXBAR_AR29_Msk                   (0x1U << MCAN_TXBAR_AR29_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 29 Mask */
#define MCAN_TXBAR_AR30_Pos                   (30)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 30 Position */
#define MCAN_TXBAR_AR30_Msk                   (0x1U << MCAN_TXBAR_AR30_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 30 Mask */
#define MCAN_TXBAR_AR31_Pos                   (31)                                           /**< (MCAN_TXBAR) Add Request for Transmit Buffer 31 Position */
#define MCAN_TXBAR_AR31_Msk                   (0x1U << MCAN_TXBAR_AR31_Pos)                  /**< (MCAN_TXBAR) Add Request for Transmit Buffer 31 Mask */
#define MCAN_TXBAR_Msk                        (0xFFFFFFFFUL)                                 /**< (MCAN_TXBAR) Register Mask  */
#define MCAN_TXBAR_AR_Pos                     (0)                                            /**< (MCAN_TXBAR Position) Add Request for Transmit Buffer 3x */
#define MCAN_TXBAR_AR_Msk                     (0xFFFFFFFFU << MCAN_TXBAR_AR_Pos)             /**< (MCAN_TXBAR Mask) AR */
#define MCAN_TXBAR_AR(value)                  (MCAN_TXBAR_AR_Msk & ((value) << MCAN_TXBAR_AR_Pos))

/* -------- MCAN_TXBCR : (MCAN Offset: 0xd4) (R/W 32) Transmit Buffer Cancellation Request Register -------- */

typedef union
{
  struct
  {
    uint32_t CR0:1;                     /**< bit:      0  Cancellation Request for Transmit Buffer 0    */
    uint32_t CR1:1;                     /**< bit:      1  Cancellation Request for Transmit Buffer 1    */
    uint32_t CR2:1;                     /**< bit:      2  Cancellation Request for Transmit Buffer 2    */
    uint32_t CR3:1;                     /**< bit:      3  Cancellation Request for Transmit Buffer 3    */
    uint32_t CR4:1;                     /**< bit:      4  Cancellation Request for Transmit Buffer 4    */
    uint32_t CR5:1;                     /**< bit:      5  Cancellation Request for Transmit Buffer 5    */
    uint32_t CR6:1;                     /**< bit:      6  Cancellation Request for Transmit Buffer 6    */
    uint32_t CR7:1;                     /**< bit:      7  Cancellation Request for Transmit Buffer 7    */
    uint32_t CR8:1;                     /**< bit:      8  Cancellation Request for Transmit Buffer 8    */
    uint32_t CR9:1;                     /**< bit:      9  Cancellation Request for Transmit Buffer 9    */
    uint32_t CR10:1;                    /**< bit:     10  Cancellation Request for Transmit Buffer 10   */
    uint32_t CR11:1;                    /**< bit:     11  Cancellation Request for Transmit Buffer 11   */
    uint32_t CR12:1;                    /**< bit:     12  Cancellation Request for Transmit Buffer 12   */
    uint32_t CR13:1;                    /**< bit:     13  Cancellation Request for Transmit Buffer 13   */
    uint32_t CR14:1;                    /**< bit:     14  Cancellation Request for Transmit Buffer 14   */
    uint32_t CR15:1;                    /**< bit:     15  Cancellation Request for Transmit Buffer 15   */
    uint32_t CR16:1;                    /**< bit:     16  Cancellation Request for Transmit Buffer 16   */
    uint32_t CR17:1;                    /**< bit:     17  Cancellation Request for Transmit Buffer 17   */
    uint32_t CR18:1;                    /**< bit:     18  Cancellation Request for Transmit Buffer 18   */
    uint32_t CR19:1;                    /**< bit:     19  Cancellation Request for Transmit Buffer 19   */
    uint32_t CR20:1;                    /**< bit:     20  Cancellation Request for Transmit Buffer 20   */
    uint32_t CR21:1;                    /**< bit:     21  Cancellation Request for Transmit Buffer 21   */
    uint32_t CR22:1;                    /**< bit:     22  Cancellation Request for Transmit Buffer 22   */
    uint32_t CR23:1;                    /**< bit:     23  Cancellation Request for Transmit Buffer 23   */
    uint32_t CR24:1;                    /**< bit:     24  Cancellation Request for Transmit Buffer 24   */
    uint32_t CR25:1;                    /**< bit:     25  Cancellation Request for Transmit Buffer 25   */
    uint32_t CR26:1;                    /**< bit:     26  Cancellation Request for Transmit Buffer 26   */
    uint32_t CR27:1;                    /**< bit:     27  Cancellation Request for Transmit Buffer 27   */
    uint32_t CR28:1;                    /**< bit:     28  Cancellation Request for Transmit Buffer 28   */
    uint32_t CR29:1;                    /**< bit:     29  Cancellation Request for Transmit Buffer 29   */
    uint32_t CR30:1;                    /**< bit:     30  Cancellation Request for Transmit Buffer 30   */
    uint32_t CR31:1;                    /**< bit:     31  Cancellation Request for Transmit Buffer 31   */
  };
  struct
  {
    uint32_t CR:32;                     /**< bit:  0..31  Cancellation Request for Transmit Buffer 3x   */
  };
  uint32_t w;
} __MCAN_TXBCR_bits_t;

#define MCAN_TXBCR_CR0_Pos                    (0)                                            /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 0 Position */
#define MCAN_TXBCR_CR0_Msk                    (0x1U << MCAN_TXBCR_CR0_Pos)                   /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 0 Mask */
#define MCAN_TXBCR_CR1_Pos                    (1)                                            /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 1 Position */
#define MCAN_TXBCR_CR1_Msk                    (0x1U << MCAN_TXBCR_CR1_Pos)                   /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 1 Mask */
#define MCAN_TXBCR_CR2_Pos                    (2)                                            /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 2 Position */
#define MCAN_TXBCR_CR2_Msk                    (0x1U << MCAN_TXBCR_CR2_Pos)                   /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 2 Mask */
#define MCAN_TXBCR_CR3_Pos                    (3)                                            /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 3 Position */
#define MCAN_TXBCR_CR3_Msk                    (0x1U << MCAN_TXBCR_CR3_Pos)                   /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 3 Mask */
#define MCAN_TXBCR_CR4_Pos                    (4)                                            /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 4 Position */
#define MCAN_TXBCR_CR4_Msk                    (0x1U << MCAN_TXBCR_CR4_Pos)                   /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 4 Mask */
#define MCAN_TXBCR_CR5_Pos                    (5)                                            /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 5 Position */
#define MCAN_TXBCR_CR5_Msk                    (0x1U << MCAN_TXBCR_CR5_Pos)                   /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 5 Mask */
#define MCAN_TXBCR_CR6_Pos                    (6)                                            /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 6 Position */
#define MCAN_TXBCR_CR6_Msk                    (0x1U << MCAN_TXBCR_CR6_Pos)                   /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 6 Mask */
#define MCAN_TXBCR_CR7_Pos                    (7)                                            /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 7 Position */
#define MCAN_TXBCR_CR7_Msk                    (0x1U << MCAN_TXBCR_CR7_Pos)                   /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 7 Mask */
#define MCAN_TXBCR_CR8_Pos                    (8)                                            /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 8 Position */
#define MCAN_TXBCR_CR8_Msk                    (0x1U << MCAN_TXBCR_CR8_Pos)                   /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 8 Mask */
#define MCAN_TXBCR_CR9_Pos                    (9)                                            /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 9 Position */
#define MCAN_TXBCR_CR9_Msk                    (0x1U << MCAN_TXBCR_CR9_Pos)                   /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 9 Mask */
#define MCAN_TXBCR_CR10_Pos                   (10)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 10 Position */
#define MCAN_TXBCR_CR10_Msk                   (0x1U << MCAN_TXBCR_CR10_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 10 Mask */
#define MCAN_TXBCR_CR11_Pos                   (11)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 11 Position */
#define MCAN_TXBCR_CR11_Msk                   (0x1U << MCAN_TXBCR_CR11_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 11 Mask */
#define MCAN_TXBCR_CR12_Pos                   (12)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 12 Position */
#define MCAN_TXBCR_CR12_Msk                   (0x1U << MCAN_TXBCR_CR12_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 12 Mask */
#define MCAN_TXBCR_CR13_Pos                   (13)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 13 Position */
#define MCAN_TXBCR_CR13_Msk                   (0x1U << MCAN_TXBCR_CR13_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 13 Mask */
#define MCAN_TXBCR_CR14_Pos                   (14)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 14 Position */
#define MCAN_TXBCR_CR14_Msk                   (0x1U << MCAN_TXBCR_CR14_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 14 Mask */
#define MCAN_TXBCR_CR15_Pos                   (15)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 15 Position */
#define MCAN_TXBCR_CR15_Msk                   (0x1U << MCAN_TXBCR_CR15_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 15 Mask */
#define MCAN_TXBCR_CR16_Pos                   (16)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 16 Position */
#define MCAN_TXBCR_CR16_Msk                   (0x1U << MCAN_TXBCR_CR16_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 16 Mask */
#define MCAN_TXBCR_CR17_Pos                   (17)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 17 Position */
#define MCAN_TXBCR_CR17_Msk                   (0x1U << MCAN_TXBCR_CR17_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 17 Mask */
#define MCAN_TXBCR_CR18_Pos                   (18)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 18 Position */
#define MCAN_TXBCR_CR18_Msk                   (0x1U << MCAN_TXBCR_CR18_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 18 Mask */
#define MCAN_TXBCR_CR19_Pos                   (19)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 19 Position */
#define MCAN_TXBCR_CR19_Msk                   (0x1U << MCAN_TXBCR_CR19_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 19 Mask */
#define MCAN_TXBCR_CR20_Pos                   (20)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 20 Position */
#define MCAN_TXBCR_CR20_Msk                   (0x1U << MCAN_TXBCR_CR20_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 20 Mask */
#define MCAN_TXBCR_CR21_Pos                   (21)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 21 Position */
#define MCAN_TXBCR_CR21_Msk                   (0x1U << MCAN_TXBCR_CR21_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 21 Mask */
#define MCAN_TXBCR_CR22_Pos                   (22)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 22 Position */
#define MCAN_TXBCR_CR22_Msk                   (0x1U << MCAN_TXBCR_CR22_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 22 Mask */
#define MCAN_TXBCR_CR23_Pos                   (23)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 23 Position */
#define MCAN_TXBCR_CR23_Msk                   (0x1U << MCAN_TXBCR_CR23_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 23 Mask */
#define MCAN_TXBCR_CR24_Pos                   (24)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 24 Position */
#define MCAN_TXBCR_CR24_Msk                   (0x1U << MCAN_TXBCR_CR24_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 24 Mask */
#define MCAN_TXBCR_CR25_Pos                   (25)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 25 Position */
#define MCAN_TXBCR_CR25_Msk                   (0x1U << MCAN_TXBCR_CR25_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 25 Mask */
#define MCAN_TXBCR_CR26_Pos                   (26)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 26 Position */
#define MCAN_TXBCR_CR26_Msk                   (0x1U << MCAN_TXBCR_CR26_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 26 Mask */
#define MCAN_TXBCR_CR27_Pos                   (27)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 27 Position */
#define MCAN_TXBCR_CR27_Msk                   (0x1U << MCAN_TXBCR_CR27_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 27 Mask */
#define MCAN_TXBCR_CR28_Pos                   (28)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 28 Position */
#define MCAN_TXBCR_CR28_Msk                   (0x1U << MCAN_TXBCR_CR28_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 28 Mask */
#define MCAN_TXBCR_CR29_Pos                   (29)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 29 Position */
#define MCAN_TXBCR_CR29_Msk                   (0x1U << MCAN_TXBCR_CR29_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 29 Mask */
#define MCAN_TXBCR_CR30_Pos                   (30)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 30 Position */
#define MCAN_TXBCR_CR30_Msk                   (0x1U << MCAN_TXBCR_CR30_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 30 Mask */
#define MCAN_TXBCR_CR31_Pos                   (31)                                           /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 31 Position */
#define MCAN_TXBCR_CR31_Msk                   (0x1U << MCAN_TXBCR_CR31_Pos)                  /**< (MCAN_TXBCR) Cancellation Request for Transmit Buffer 31 Mask */
#define MCAN_TXBCR_Msk                        (0xFFFFFFFFUL)                                 /**< (MCAN_TXBCR) Register Mask  */
#define MCAN_TXBCR_CR_Pos                     (0)                                            /**< (MCAN_TXBCR Position) Cancellation Request for Transmit Buffer 3x */
#define MCAN_TXBCR_CR_Msk                     (0xFFFFFFFFU << MCAN_TXBCR_CR_Pos)             /**< (MCAN_TXBCR Mask) CR */
#define MCAN_TXBCR_CR(value)                  (MCAN_TXBCR_CR_Msk & ((value) << MCAN_TXBCR_CR_Pos))

/* -------- MCAN_TXBTO : (MCAN Offset: 0xd8) (R/ 32) Transmit Buffer Transmission Occurred Register -------- */

typedef union
{
  struct
  {
    uint32_t TO0:1;                     /**< bit:      0  Transmission Occurred for Buffer 0            */
    uint32_t TO1:1;                     /**< bit:      1  Transmission Occurred for Buffer 1            */
    uint32_t TO2:1;                     /**< bit:      2  Transmission Occurred for Buffer 2            */
    uint32_t TO3:1;                     /**< bit:      3  Transmission Occurred for Buffer 3            */
    uint32_t TO4:1;                     /**< bit:      4  Transmission Occurred for Buffer 4            */
    uint32_t TO5:1;                     /**< bit:      5  Transmission Occurred for Buffer 5            */
    uint32_t TO6:1;                     /**< bit:      6  Transmission Occurred for Buffer 6            */
    uint32_t TO7:1;                     /**< bit:      7  Transmission Occurred for Buffer 7            */
    uint32_t TO8:1;                     /**< bit:      8  Transmission Occurred for Buffer 8            */
    uint32_t TO9:1;                     /**< bit:      9  Transmission Occurred for Buffer 9            */
    uint32_t TO10:1;                    /**< bit:     10  Transmission Occurred for Buffer 10           */
    uint32_t TO11:1;                    /**< bit:     11  Transmission Occurred for Buffer 11           */
    uint32_t TO12:1;                    /**< bit:     12  Transmission Occurred for Buffer 12           */
    uint32_t TO13:1;                    /**< bit:     13  Transmission Occurred for Buffer 13           */
    uint32_t TO14:1;                    /**< bit:     14  Transmission Occurred for Buffer 14           */
    uint32_t TO15:1;                    /**< bit:     15  Transmission Occurred for Buffer 15           */
    uint32_t TO16:1;                    /**< bit:     16  Transmission Occurred for Buffer 16           */
    uint32_t TO17:1;                    /**< bit:     17  Transmission Occurred for Buffer 17           */
    uint32_t TO18:1;                    /**< bit:     18  Transmission Occurred for Buffer 18           */
    uint32_t TO19:1;                    /**< bit:     19  Transmission Occurred for Buffer 19           */
    uint32_t TO20:1;                    /**< bit:     20  Transmission Occurred for Buffer 20           */
    uint32_t TO21:1;                    /**< bit:     21  Transmission Occurred for Buffer 21           */
    uint32_t TO22:1;                    /**< bit:     22  Transmission Occurred for Buffer 22           */
    uint32_t TO23:1;                    /**< bit:     23  Transmission Occurred for Buffer 23           */
    uint32_t TO24:1;                    /**< bit:     24  Transmission Occurred for Buffer 24           */
    uint32_t TO25:1;                    /**< bit:     25  Transmission Occurred for Buffer 25           */
    uint32_t TO26:1;                    /**< bit:     26  Transmission Occurred for Buffer 26           */
    uint32_t TO27:1;                    /**< bit:     27  Transmission Occurred for Buffer 27           */
    uint32_t TO28:1;                    /**< bit:     28  Transmission Occurred for Buffer 28           */
    uint32_t TO29:1;                    /**< bit:     29  Transmission Occurred for Buffer 29           */
    uint32_t TO30:1;                    /**< bit:     30  Transmission Occurred for Buffer 30           */
    uint32_t TO31:1;                    /**< bit:     31  Transmission Occurred for Buffer 31           */
  };
  struct
  {
    uint32_t TO:32;                     /**< bit:  0..31  Transmission Occurred for Buffer 3x           */
  };
  uint32_t w;
} __MCAN_TXBTO_bits_t;

#define MCAN_TXBTO_TO0_Pos                    (0)                                            /**< (MCAN_TXBTO) Transmission Occurred for Buffer 0 Position */
#define MCAN_TXBTO_TO0_Msk                    (0x1U << MCAN_TXBTO_TO0_Pos)                   /**< (MCAN_TXBTO) Transmission Occurred for Buffer 0 Mask */
#define MCAN_TXBTO_TO1_Pos                    (1)                                            /**< (MCAN_TXBTO) Transmission Occurred for Buffer 1 Position */
#define MCAN_TXBTO_TO1_Msk                    (0x1U << MCAN_TXBTO_TO1_Pos)                   /**< (MCAN_TXBTO) Transmission Occurred for Buffer 1 Mask */
#define MCAN_TXBTO_TO2_Pos                    (2)                                            /**< (MCAN_TXBTO) Transmission Occurred for Buffer 2 Position */
#define MCAN_TXBTO_TO2_Msk                    (0x1U << MCAN_TXBTO_TO2_Pos)                   /**< (MCAN_TXBTO) Transmission Occurred for Buffer 2 Mask */
#define MCAN_TXBTO_TO3_Pos                    (3)                                            /**< (MCAN_TXBTO) Transmission Occurred for Buffer 3 Position */
#define MCAN_TXBTO_TO3_Msk                    (0x1U << MCAN_TXBTO_TO3_Pos)                   /**< (MCAN_TXBTO) Transmission Occurred for Buffer 3 Mask */
#define MCAN_TXBTO_TO4_Pos                    (4)                                            /**< (MCAN_TXBTO) Transmission Occurred for Buffer 4 Position */
#define MCAN_TXBTO_TO4_Msk                    (0x1U << MCAN_TXBTO_TO4_Pos)                   /**< (MCAN_TXBTO) Transmission Occurred for Buffer 4 Mask */
#define MCAN_TXBTO_TO5_Pos                    (5)                                            /**< (MCAN_TXBTO) Transmission Occurred for Buffer 5 Position */
#define MCAN_TXBTO_TO5_Msk                    (0x1U << MCAN_TXBTO_TO5_Pos)                   /**< (MCAN_TXBTO) Transmission Occurred for Buffer 5 Mask */
#define MCAN_TXBTO_TO6_Pos                    (6)                                            /**< (MCAN_TXBTO) Transmission Occurred for Buffer 6 Position */
#define MCAN_TXBTO_TO6_Msk                    (0x1U << MCAN_TXBTO_TO6_Pos)                   /**< (MCAN_TXBTO) Transmission Occurred for Buffer 6 Mask */
#define MCAN_TXBTO_TO7_Pos                    (7)                                            /**< (MCAN_TXBTO) Transmission Occurred for Buffer 7 Position */
#define MCAN_TXBTO_TO7_Msk                    (0x1U << MCAN_TXBTO_TO7_Pos)                   /**< (MCAN_TXBTO) Transmission Occurred for Buffer 7 Mask */
#define MCAN_TXBTO_TO8_Pos                    (8)                                            /**< (MCAN_TXBTO) Transmission Occurred for Buffer 8 Position */
#define MCAN_TXBTO_TO8_Msk                    (0x1U << MCAN_TXBTO_TO8_Pos)                   /**< (MCAN_TXBTO) Transmission Occurred for Buffer 8 Mask */
#define MCAN_TXBTO_TO9_Pos                    (9)                                            /**< (MCAN_TXBTO) Transmission Occurred for Buffer 9 Position */
#define MCAN_TXBTO_TO9_Msk                    (0x1U << MCAN_TXBTO_TO9_Pos)                   /**< (MCAN_TXBTO) Transmission Occurred for Buffer 9 Mask */
#define MCAN_TXBTO_TO10_Pos                   (10)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 10 Position */
#define MCAN_TXBTO_TO10_Msk                   (0x1U << MCAN_TXBTO_TO10_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 10 Mask */
#define MCAN_TXBTO_TO11_Pos                   (11)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 11 Position */
#define MCAN_TXBTO_TO11_Msk                   (0x1U << MCAN_TXBTO_TO11_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 11 Mask */
#define MCAN_TXBTO_TO12_Pos                   (12)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 12 Position */
#define MCAN_TXBTO_TO12_Msk                   (0x1U << MCAN_TXBTO_TO12_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 12 Mask */
#define MCAN_TXBTO_TO13_Pos                   (13)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 13 Position */
#define MCAN_TXBTO_TO13_Msk                   (0x1U << MCAN_TXBTO_TO13_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 13 Mask */
#define MCAN_TXBTO_TO14_Pos                   (14)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 14 Position */
#define MCAN_TXBTO_TO14_Msk                   (0x1U << MCAN_TXBTO_TO14_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 14 Mask */
#define MCAN_TXBTO_TO15_Pos                   (15)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 15 Position */
#define MCAN_TXBTO_TO15_Msk                   (0x1U << MCAN_TXBTO_TO15_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 15 Mask */
#define MCAN_TXBTO_TO16_Pos                   (16)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 16 Position */
#define MCAN_TXBTO_TO16_Msk                   (0x1U << MCAN_TXBTO_TO16_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 16 Mask */
#define MCAN_TXBTO_TO17_Pos                   (17)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 17 Position */
#define MCAN_TXBTO_TO17_Msk                   (0x1U << MCAN_TXBTO_TO17_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 17 Mask */
#define MCAN_TXBTO_TO18_Pos                   (18)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 18 Position */
#define MCAN_TXBTO_TO18_Msk                   (0x1U << MCAN_TXBTO_TO18_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 18 Mask */
#define MCAN_TXBTO_TO19_Pos                   (19)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 19 Position */
#define MCAN_TXBTO_TO19_Msk                   (0x1U << MCAN_TXBTO_TO19_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 19 Mask */
#define MCAN_TXBTO_TO20_Pos                   (20)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 20 Position */
#define MCAN_TXBTO_TO20_Msk                   (0x1U << MCAN_TXBTO_TO20_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 20 Mask */
#define MCAN_TXBTO_TO21_Pos                   (21)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 21 Position */
#define MCAN_TXBTO_TO21_Msk                   (0x1U << MCAN_TXBTO_TO21_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 21 Mask */
#define MCAN_TXBTO_TO22_Pos                   (22)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 22 Position */
#define MCAN_TXBTO_TO22_Msk                   (0x1U << MCAN_TXBTO_TO22_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 22 Mask */
#define MCAN_TXBTO_TO23_Pos                   (23)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 23 Position */
#define MCAN_TXBTO_TO23_Msk                   (0x1U << MCAN_TXBTO_TO23_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 23 Mask */
#define MCAN_TXBTO_TO24_Pos                   (24)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 24 Position */
#define MCAN_TXBTO_TO24_Msk                   (0x1U << MCAN_TXBTO_TO24_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 24 Mask */
#define MCAN_TXBTO_TO25_Pos                   (25)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 25 Position */
#define MCAN_TXBTO_TO25_Msk                   (0x1U << MCAN_TXBTO_TO25_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 25 Mask */
#define MCAN_TXBTO_TO26_Pos                   (26)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 26 Position */
#define MCAN_TXBTO_TO26_Msk                   (0x1U << MCAN_TXBTO_TO26_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 26 Mask */
#define MCAN_TXBTO_TO27_Pos                   (27)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 27 Position */
#define MCAN_TXBTO_TO27_Msk                   (0x1U << MCAN_TXBTO_TO27_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 27 Mask */
#define MCAN_TXBTO_TO28_Pos                   (28)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 28 Position */
#define MCAN_TXBTO_TO28_Msk                   (0x1U << MCAN_TXBTO_TO28_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 28 Mask */
#define MCAN_TXBTO_TO29_Pos                   (29)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 29 Position */
#define MCAN_TXBTO_TO29_Msk                   (0x1U << MCAN_TXBTO_TO29_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 29 Mask */
#define MCAN_TXBTO_TO30_Pos                   (30)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 30 Position */
#define MCAN_TXBTO_TO30_Msk                   (0x1U << MCAN_TXBTO_TO30_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 30 Mask */
#define MCAN_TXBTO_TO31_Pos                   (31)                                           /**< (MCAN_TXBTO) Transmission Occurred for Buffer 31 Position */
#define MCAN_TXBTO_TO31_Msk                   (0x1U << MCAN_TXBTO_TO31_Pos)                  /**< (MCAN_TXBTO) Transmission Occurred for Buffer 31 Mask */
#define MCAN_TXBTO_Msk                        (0xFFFFFFFFUL)                                 /**< (MCAN_TXBTO) Register Mask  */
#define MCAN_TXBTO_TO_Pos                     (0)                                            /**< (MCAN_TXBTO Position) Transmission Occurred for Buffer 3x */
#define MCAN_TXBTO_TO_Msk                     (0xFFFFFFFFU << MCAN_TXBTO_TO_Pos)             /**< (MCAN_TXBTO Mask) TO */
#define MCAN_TXBTO_TO(value)                  (MCAN_TXBTO_TO_Msk & ((value) << MCAN_TXBTO_TO_Pos))

/* -------- MCAN_TXBCF : (MCAN Offset: 0xdc) (R/ 32) Transmit Buffer Cancellation Finished Register -------- */

typedef union
{
  struct
  {
    uint32_t CF0:1;                     /**< bit:      0  Cancellation Finished for Transmit Buffer 0   */
    uint32_t CF1:1;                     /**< bit:      1  Cancellation Finished for Transmit Buffer 1   */
    uint32_t CF2:1;                     /**< bit:      2  Cancellation Finished for Transmit Buffer 2   */
    uint32_t CF3:1;                     /**< bit:      3  Cancellation Finished for Transmit Buffer 3   */
    uint32_t CF4:1;                     /**< bit:      4  Cancellation Finished for Transmit Buffer 4   */
    uint32_t CF5:1;                     /**< bit:      5  Cancellation Finished for Transmit Buffer 5   */
    uint32_t CF6:1;                     /**< bit:      6  Cancellation Finished for Transmit Buffer 6   */
    uint32_t CF7:1;                     /**< bit:      7  Cancellation Finished for Transmit Buffer 7   */
    uint32_t CF8:1;                     /**< bit:      8  Cancellation Finished for Transmit Buffer 8   */
    uint32_t CF9:1;                     /**< bit:      9  Cancellation Finished for Transmit Buffer 9   */
    uint32_t CF10:1;                    /**< bit:     10  Cancellation Finished for Transmit Buffer 10  */
    uint32_t CF11:1;                    /**< bit:     11  Cancellation Finished for Transmit Buffer 11  */
    uint32_t CF12:1;                    /**< bit:     12  Cancellation Finished for Transmit Buffer 12  */
    uint32_t CF13:1;                    /**< bit:     13  Cancellation Finished for Transmit Buffer 13  */
    uint32_t CF14:1;                    /**< bit:     14  Cancellation Finished for Transmit Buffer 14  */
    uint32_t CF15:1;                    /**< bit:     15  Cancellation Finished for Transmit Buffer 15  */
    uint32_t CF16:1;                    /**< bit:     16  Cancellation Finished for Transmit Buffer 16  */
    uint32_t CF17:1;                    /**< bit:     17  Cancellation Finished for Transmit Buffer 17  */
    uint32_t CF18:1;                    /**< bit:     18  Cancellation Finished for Transmit Buffer 18  */
    uint32_t CF19:1;                    /**< bit:     19  Cancellation Finished for Transmit Buffer 19  */
    uint32_t CF20:1;                    /**< bit:     20  Cancellation Finished for Transmit Buffer 20  */
    uint32_t CF21:1;                    /**< bit:     21  Cancellation Finished for Transmit Buffer 21  */
    uint32_t CF22:1;                    /**< bit:     22  Cancellation Finished for Transmit Buffer 22  */
    uint32_t CF23:1;                    /**< bit:     23  Cancellation Finished for Transmit Buffer 23  */
    uint32_t CF24:1;                    /**< bit:     24  Cancellation Finished for Transmit Buffer 24  */
    uint32_t CF25:1;                    /**< bit:     25  Cancellation Finished for Transmit Buffer 25  */
    uint32_t CF26:1;                    /**< bit:     26  Cancellation Finished for Transmit Buffer 26  */
    uint32_t CF27:1;                    /**< bit:     27  Cancellation Finished for Transmit Buffer 27  */
    uint32_t CF28:1;                    /**< bit:     28  Cancellation Finished for Transmit Buffer 28  */
    uint32_t CF29:1;                    /**< bit:     29  Cancellation Finished for Transmit Buffer 29  */
    uint32_t CF30:1;                    /**< bit:     30  Cancellation Finished for Transmit Buffer 30  */
    uint32_t CF31:1;                    /**< bit:     31  Cancellation Finished for Transmit Buffer 31  */
  };
  struct
  {
    uint32_t CF:32;                     /**< bit:  0..31  Cancellation Finished for Transmit Buffer 3x  */
  };
  uint32_t w;
} __MCAN_TXBCF_bits_t;

#define MCAN_TXBCF_CF0_Pos                    (0)                                            /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 0 Position */
#define MCAN_TXBCF_CF0_Msk                    (0x1U << MCAN_TXBCF_CF0_Pos)                   /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 0 Mask */
#define MCAN_TXBCF_CF1_Pos                    (1)                                            /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 1 Position */
#define MCAN_TXBCF_CF1_Msk                    (0x1U << MCAN_TXBCF_CF1_Pos)                   /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 1 Mask */
#define MCAN_TXBCF_CF2_Pos                    (2)                                            /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 2 Position */
#define MCAN_TXBCF_CF2_Msk                    (0x1U << MCAN_TXBCF_CF2_Pos)                   /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 2 Mask */
#define MCAN_TXBCF_CF3_Pos                    (3)                                            /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 3 Position */
#define MCAN_TXBCF_CF3_Msk                    (0x1U << MCAN_TXBCF_CF3_Pos)                   /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 3 Mask */
#define MCAN_TXBCF_CF4_Pos                    (4)                                            /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 4 Position */
#define MCAN_TXBCF_CF4_Msk                    (0x1U << MCAN_TXBCF_CF4_Pos)                   /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 4 Mask */
#define MCAN_TXBCF_CF5_Pos                    (5)                                            /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 5 Position */
#define MCAN_TXBCF_CF5_Msk                    (0x1U << MCAN_TXBCF_CF5_Pos)                   /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 5 Mask */
#define MCAN_TXBCF_CF6_Pos                    (6)                                            /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 6 Position */
#define MCAN_TXBCF_CF6_Msk                    (0x1U << MCAN_TXBCF_CF6_Pos)                   /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 6 Mask */
#define MCAN_TXBCF_CF7_Pos                    (7)                                            /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 7 Position */
#define MCAN_TXBCF_CF7_Msk                    (0x1U << MCAN_TXBCF_CF7_Pos)                   /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 7 Mask */
#define MCAN_TXBCF_CF8_Pos                    (8)                                            /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 8 Position */
#define MCAN_TXBCF_CF8_Msk                    (0x1U << MCAN_TXBCF_CF8_Pos)                   /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 8 Mask */
#define MCAN_TXBCF_CF9_Pos                    (9)                                            /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 9 Position */
#define MCAN_TXBCF_CF9_Msk                    (0x1U << MCAN_TXBCF_CF9_Pos)                   /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 9 Mask */
#define MCAN_TXBCF_CF10_Pos                   (10)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 10 Position */
#define MCAN_TXBCF_CF10_Msk                   (0x1U << MCAN_TXBCF_CF10_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 10 Mask */
#define MCAN_TXBCF_CF11_Pos                   (11)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 11 Position */
#define MCAN_TXBCF_CF11_Msk                   (0x1U << MCAN_TXBCF_CF11_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 11 Mask */
#define MCAN_TXBCF_CF12_Pos                   (12)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 12 Position */
#define MCAN_TXBCF_CF12_Msk                   (0x1U << MCAN_TXBCF_CF12_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 12 Mask */
#define MCAN_TXBCF_CF13_Pos                   (13)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 13 Position */
#define MCAN_TXBCF_CF13_Msk                   (0x1U << MCAN_TXBCF_CF13_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 13 Mask */
#define MCAN_TXBCF_CF14_Pos                   (14)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 14 Position */
#define MCAN_TXBCF_CF14_Msk                   (0x1U << MCAN_TXBCF_CF14_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 14 Mask */
#define MCAN_TXBCF_CF15_Pos                   (15)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 15 Position */
#define MCAN_TXBCF_CF15_Msk                   (0x1U << MCAN_TXBCF_CF15_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 15 Mask */
#define MCAN_TXBCF_CF16_Pos                   (16)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 16 Position */
#define MCAN_TXBCF_CF16_Msk                   (0x1U << MCAN_TXBCF_CF16_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 16 Mask */
#define MCAN_TXBCF_CF17_Pos                   (17)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 17 Position */
#define MCAN_TXBCF_CF17_Msk                   (0x1U << MCAN_TXBCF_CF17_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 17 Mask */
#define MCAN_TXBCF_CF18_Pos                   (18)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 18 Position */
#define MCAN_TXBCF_CF18_Msk                   (0x1U << MCAN_TXBCF_CF18_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 18 Mask */
#define MCAN_TXBCF_CF19_Pos                   (19)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 19 Position */
#define MCAN_TXBCF_CF19_Msk                   (0x1U << MCAN_TXBCF_CF19_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 19 Mask */
#define MCAN_TXBCF_CF20_Pos                   (20)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 20 Position */
#define MCAN_TXBCF_CF20_Msk                   (0x1U << MCAN_TXBCF_CF20_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 20 Mask */
#define MCAN_TXBCF_CF21_Pos                   (21)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 21 Position */
#define MCAN_TXBCF_CF21_Msk                   (0x1U << MCAN_TXBCF_CF21_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 21 Mask */
#define MCAN_TXBCF_CF22_Pos                   (22)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 22 Position */
#define MCAN_TXBCF_CF22_Msk                   (0x1U << MCAN_TXBCF_CF22_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 22 Mask */
#define MCAN_TXBCF_CF23_Pos                   (23)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 23 Position */
#define MCAN_TXBCF_CF23_Msk                   (0x1U << MCAN_TXBCF_CF23_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 23 Mask */
#define MCAN_TXBCF_CF24_Pos                   (24)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 24 Position */
#define MCAN_TXBCF_CF24_Msk                   (0x1U << MCAN_TXBCF_CF24_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 24 Mask */
#define MCAN_TXBCF_CF25_Pos                   (25)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 25 Position */
#define MCAN_TXBCF_CF25_Msk                   (0x1U << MCAN_TXBCF_CF25_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 25 Mask */
#define MCAN_TXBCF_CF26_Pos                   (26)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 26 Position */
#define MCAN_TXBCF_CF26_Msk                   (0x1U << MCAN_TXBCF_CF26_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 26 Mask */
#define MCAN_TXBCF_CF27_Pos                   (27)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 27 Position */
#define MCAN_TXBCF_CF27_Msk                   (0x1U << MCAN_TXBCF_CF27_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 27 Mask */
#define MCAN_TXBCF_CF28_Pos                   (28)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 28 Position */
#define MCAN_TXBCF_CF28_Msk                   (0x1U << MCAN_TXBCF_CF28_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 28 Mask */
#define MCAN_TXBCF_CF29_Pos                   (29)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 29 Position */
#define MCAN_TXBCF_CF29_Msk                   (0x1U << MCAN_TXBCF_CF29_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 29 Mask */
#define MCAN_TXBCF_CF30_Pos                   (30)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 30 Position */
#define MCAN_TXBCF_CF30_Msk                   (0x1U << MCAN_TXBCF_CF30_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 30 Mask */
#define MCAN_TXBCF_CF31_Pos                   (31)                                           /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 31 Position */
#define MCAN_TXBCF_CF31_Msk                   (0x1U << MCAN_TXBCF_CF31_Pos)                  /**< (MCAN_TXBCF) Cancellation Finished for Transmit Buffer 31 Mask */
#define MCAN_TXBCF_Msk                        (0xFFFFFFFFUL)                                 /**< (MCAN_TXBCF) Register Mask  */
#define MCAN_TXBCF_CF_Pos                     (0)                                            /**< (MCAN_TXBCF Position) Cancellation Finished for Transmit Buffer 3x */
#define MCAN_TXBCF_CF_Msk                     (0xFFFFFFFFU << MCAN_TXBCF_CF_Pos)             /**< (MCAN_TXBCF Mask) CF */
#define MCAN_TXBCF_CF(value)                  (MCAN_TXBCF_CF_Msk & ((value) << MCAN_TXBCF_CF_Pos))

/* -------- MCAN_TXBTIE : (MCAN Offset: 0xe0) (R/W 32) Transmit Buffer Transmission Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t TIE0:1;                    /**< bit:      0  Transmission Interrupt Enable for Buffer 0    */
    uint32_t TIE1:1;                    /**< bit:      1  Transmission Interrupt Enable for Buffer 1    */
    uint32_t TIE2:1;                    /**< bit:      2  Transmission Interrupt Enable for Buffer 2    */
    uint32_t TIE3:1;                    /**< bit:      3  Transmission Interrupt Enable for Buffer 3    */
    uint32_t TIE4:1;                    /**< bit:      4  Transmission Interrupt Enable for Buffer 4    */
    uint32_t TIE5:1;                    /**< bit:      5  Transmission Interrupt Enable for Buffer 5    */
    uint32_t TIE6:1;                    /**< bit:      6  Transmission Interrupt Enable for Buffer 6    */
    uint32_t TIE7:1;                    /**< bit:      7  Transmission Interrupt Enable for Buffer 7    */
    uint32_t TIE8:1;                    /**< bit:      8  Transmission Interrupt Enable for Buffer 8    */
    uint32_t TIE9:1;                    /**< bit:      9  Transmission Interrupt Enable for Buffer 9    */
    uint32_t TIE10:1;                   /**< bit:     10  Transmission Interrupt Enable for Buffer 10   */
    uint32_t TIE11:1;                   /**< bit:     11  Transmission Interrupt Enable for Buffer 11   */
    uint32_t TIE12:1;                   /**< bit:     12  Transmission Interrupt Enable for Buffer 12   */
    uint32_t TIE13:1;                   /**< bit:     13  Transmission Interrupt Enable for Buffer 13   */
    uint32_t TIE14:1;                   /**< bit:     14  Transmission Interrupt Enable for Buffer 14   */
    uint32_t TIE15:1;                   /**< bit:     15  Transmission Interrupt Enable for Buffer 15   */
    uint32_t TIE16:1;                   /**< bit:     16  Transmission Interrupt Enable for Buffer 16   */
    uint32_t TIE17:1;                   /**< bit:     17  Transmission Interrupt Enable for Buffer 17   */
    uint32_t TIE18:1;                   /**< bit:     18  Transmission Interrupt Enable for Buffer 18   */
    uint32_t TIE19:1;                   /**< bit:     19  Transmission Interrupt Enable for Buffer 19   */
    uint32_t TIE20:1;                   /**< bit:     20  Transmission Interrupt Enable for Buffer 20   */
    uint32_t TIE21:1;                   /**< bit:     21  Transmission Interrupt Enable for Buffer 21   */
    uint32_t TIE22:1;                   /**< bit:     22  Transmission Interrupt Enable for Buffer 22   */
    uint32_t TIE23:1;                   /**< bit:     23  Transmission Interrupt Enable for Buffer 23   */
    uint32_t TIE24:1;                   /**< bit:     24  Transmission Interrupt Enable for Buffer 24   */
    uint32_t TIE25:1;                   /**< bit:     25  Transmission Interrupt Enable for Buffer 25   */
    uint32_t TIE26:1;                   /**< bit:     26  Transmission Interrupt Enable for Buffer 26   */
    uint32_t TIE27:1;                   /**< bit:     27  Transmission Interrupt Enable for Buffer 27   */
    uint32_t TIE28:1;                   /**< bit:     28  Transmission Interrupt Enable for Buffer 28   */
    uint32_t TIE29:1;                   /**< bit:     29  Transmission Interrupt Enable for Buffer 29   */
    uint32_t TIE30:1;                   /**< bit:     30  Transmission Interrupt Enable for Buffer 30   */
    uint32_t TIE31:1;                   /**< bit:     31  Transmission Interrupt Enable for Buffer 31   */
  };
  struct
  {
    uint32_t TIE:32;                    /**< bit:  0..31  Transmission Interrupt Enable for Buffer 3x   */
  };
  uint32_t w;
} __MCAN_TXBTIE_bits_t;

#define MCAN_TXBTIE_TIE0_Pos                  (0)                                            /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 0 Position */
#define MCAN_TXBTIE_TIE0_Msk                  (0x1U << MCAN_TXBTIE_TIE0_Pos)                 /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 0 Mask */
#define MCAN_TXBTIE_TIE1_Pos                  (1)                                            /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 1 Position */
#define MCAN_TXBTIE_TIE1_Msk                  (0x1U << MCAN_TXBTIE_TIE1_Pos)                 /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 1 Mask */
#define MCAN_TXBTIE_TIE2_Pos                  (2)                                            /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 2 Position */
#define MCAN_TXBTIE_TIE2_Msk                  (0x1U << MCAN_TXBTIE_TIE2_Pos)                 /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 2 Mask */
#define MCAN_TXBTIE_TIE3_Pos                  (3)                                            /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 3 Position */
#define MCAN_TXBTIE_TIE3_Msk                  (0x1U << MCAN_TXBTIE_TIE3_Pos)                 /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 3 Mask */
#define MCAN_TXBTIE_TIE4_Pos                  (4)                                            /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 4 Position */
#define MCAN_TXBTIE_TIE4_Msk                  (0x1U << MCAN_TXBTIE_TIE4_Pos)                 /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 4 Mask */
#define MCAN_TXBTIE_TIE5_Pos                  (5)                                            /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 5 Position */
#define MCAN_TXBTIE_TIE5_Msk                  (0x1U << MCAN_TXBTIE_TIE5_Pos)                 /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 5 Mask */
#define MCAN_TXBTIE_TIE6_Pos                  (6)                                            /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 6 Position */
#define MCAN_TXBTIE_TIE6_Msk                  (0x1U << MCAN_TXBTIE_TIE6_Pos)                 /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 6 Mask */
#define MCAN_TXBTIE_TIE7_Pos                  (7)                                            /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 7 Position */
#define MCAN_TXBTIE_TIE7_Msk                  (0x1U << MCAN_TXBTIE_TIE7_Pos)                 /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 7 Mask */
#define MCAN_TXBTIE_TIE8_Pos                  (8)                                            /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 8 Position */
#define MCAN_TXBTIE_TIE8_Msk                  (0x1U << MCAN_TXBTIE_TIE8_Pos)                 /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 8 Mask */
#define MCAN_TXBTIE_TIE9_Pos                  (9)                                            /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 9 Position */
#define MCAN_TXBTIE_TIE9_Msk                  (0x1U << MCAN_TXBTIE_TIE9_Pos)                 /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 9 Mask */
#define MCAN_TXBTIE_TIE10_Pos                 (10)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 10 Position */
#define MCAN_TXBTIE_TIE10_Msk                 (0x1U << MCAN_TXBTIE_TIE10_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 10 Mask */
#define MCAN_TXBTIE_TIE11_Pos                 (11)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 11 Position */
#define MCAN_TXBTIE_TIE11_Msk                 (0x1U << MCAN_TXBTIE_TIE11_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 11 Mask */
#define MCAN_TXBTIE_TIE12_Pos                 (12)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 12 Position */
#define MCAN_TXBTIE_TIE12_Msk                 (0x1U << MCAN_TXBTIE_TIE12_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 12 Mask */
#define MCAN_TXBTIE_TIE13_Pos                 (13)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 13 Position */
#define MCAN_TXBTIE_TIE13_Msk                 (0x1U << MCAN_TXBTIE_TIE13_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 13 Mask */
#define MCAN_TXBTIE_TIE14_Pos                 (14)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 14 Position */
#define MCAN_TXBTIE_TIE14_Msk                 (0x1U << MCAN_TXBTIE_TIE14_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 14 Mask */
#define MCAN_TXBTIE_TIE15_Pos                 (15)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 15 Position */
#define MCAN_TXBTIE_TIE15_Msk                 (0x1U << MCAN_TXBTIE_TIE15_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 15 Mask */
#define MCAN_TXBTIE_TIE16_Pos                 (16)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 16 Position */
#define MCAN_TXBTIE_TIE16_Msk                 (0x1U << MCAN_TXBTIE_TIE16_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 16 Mask */
#define MCAN_TXBTIE_TIE17_Pos                 (17)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 17 Position */
#define MCAN_TXBTIE_TIE17_Msk                 (0x1U << MCAN_TXBTIE_TIE17_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 17 Mask */
#define MCAN_TXBTIE_TIE18_Pos                 (18)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 18 Position */
#define MCAN_TXBTIE_TIE18_Msk                 (0x1U << MCAN_TXBTIE_TIE18_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 18 Mask */
#define MCAN_TXBTIE_TIE19_Pos                 (19)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 19 Position */
#define MCAN_TXBTIE_TIE19_Msk                 (0x1U << MCAN_TXBTIE_TIE19_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 19 Mask */
#define MCAN_TXBTIE_TIE20_Pos                 (20)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 20 Position */
#define MCAN_TXBTIE_TIE20_Msk                 (0x1U << MCAN_TXBTIE_TIE20_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 20 Mask */
#define MCAN_TXBTIE_TIE21_Pos                 (21)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 21 Position */
#define MCAN_TXBTIE_TIE21_Msk                 (0x1U << MCAN_TXBTIE_TIE21_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 21 Mask */
#define MCAN_TXBTIE_TIE22_Pos                 (22)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 22 Position */
#define MCAN_TXBTIE_TIE22_Msk                 (0x1U << MCAN_TXBTIE_TIE22_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 22 Mask */
#define MCAN_TXBTIE_TIE23_Pos                 (23)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 23 Position */
#define MCAN_TXBTIE_TIE23_Msk                 (0x1U << MCAN_TXBTIE_TIE23_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 23 Mask */
#define MCAN_TXBTIE_TIE24_Pos                 (24)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 24 Position */
#define MCAN_TXBTIE_TIE24_Msk                 (0x1U << MCAN_TXBTIE_TIE24_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 24 Mask */
#define MCAN_TXBTIE_TIE25_Pos                 (25)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 25 Position */
#define MCAN_TXBTIE_TIE25_Msk                 (0x1U << MCAN_TXBTIE_TIE25_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 25 Mask */
#define MCAN_TXBTIE_TIE26_Pos                 (26)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 26 Position */
#define MCAN_TXBTIE_TIE26_Msk                 (0x1U << MCAN_TXBTIE_TIE26_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 26 Mask */
#define MCAN_TXBTIE_TIE27_Pos                 (27)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 27 Position */
#define MCAN_TXBTIE_TIE27_Msk                 (0x1U << MCAN_TXBTIE_TIE27_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 27 Mask */
#define MCAN_TXBTIE_TIE28_Pos                 (28)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 28 Position */
#define MCAN_TXBTIE_TIE28_Msk                 (0x1U << MCAN_TXBTIE_TIE28_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 28 Mask */
#define MCAN_TXBTIE_TIE29_Pos                 (29)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 29 Position */
#define MCAN_TXBTIE_TIE29_Msk                 (0x1U << MCAN_TXBTIE_TIE29_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 29 Mask */
#define MCAN_TXBTIE_TIE30_Pos                 (30)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 30 Position */
#define MCAN_TXBTIE_TIE30_Msk                 (0x1U << MCAN_TXBTIE_TIE30_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 30 Mask */
#define MCAN_TXBTIE_TIE31_Pos                 (31)                                           /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 31 Position */
#define MCAN_TXBTIE_TIE31_Msk                 (0x1U << MCAN_TXBTIE_TIE31_Pos)                /**< (MCAN_TXBTIE) Transmission Interrupt Enable for Buffer 31 Mask */
#define MCAN_TXBTIE_Msk                       (0xFFFFFFFFUL)                                 /**< (MCAN_TXBTIE) Register Mask  */
#define MCAN_TXBTIE_TIE_Pos                   (0)                                            /**< (MCAN_TXBTIE Position) Transmission Interrupt Enable for Buffer 3x */
#define MCAN_TXBTIE_TIE_Msk                   (0xFFFFFFFFU << MCAN_TXBTIE_TIE_Pos)           /**< (MCAN_TXBTIE Mask) TIE */
#define MCAN_TXBTIE_TIE(value)                (MCAN_TXBTIE_TIE_Msk & ((value) << MCAN_TXBTIE_TIE_Pos))

/* -------- MCAN_TXBCIE : (MCAN Offset: 0xe4) (R/W 32) Transmit Buffer Cancellation Finished Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t CFIE0:1;                   /**< bit:      0  Cancellation Finished Interrupt Enable for Transmit Buffer 0 */
    uint32_t CFIE1:1;                   /**< bit:      1  Cancellation Finished Interrupt Enable for Transmit Buffer 1 */
    uint32_t CFIE2:1;                   /**< bit:      2  Cancellation Finished Interrupt Enable for Transmit Buffer 2 */
    uint32_t CFIE3:1;                   /**< bit:      3  Cancellation Finished Interrupt Enable for Transmit Buffer 3 */
    uint32_t CFIE4:1;                   /**< bit:      4  Cancellation Finished Interrupt Enable for Transmit Buffer 4 */
    uint32_t CFIE5:1;                   /**< bit:      5  Cancellation Finished Interrupt Enable for Transmit Buffer 5 */
    uint32_t CFIE6:1;                   /**< bit:      6  Cancellation Finished Interrupt Enable for Transmit Buffer 6 */
    uint32_t CFIE7:1;                   /**< bit:      7  Cancellation Finished Interrupt Enable for Transmit Buffer 7 */
    uint32_t CFIE8:1;                   /**< bit:      8  Cancellation Finished Interrupt Enable for Transmit Buffer 8 */
    uint32_t CFIE9:1;                   /**< bit:      9  Cancellation Finished Interrupt Enable for Transmit Buffer 9 */
    uint32_t CFIE10:1;                  /**< bit:     10  Cancellation Finished Interrupt Enable for Transmit Buffer 10 */
    uint32_t CFIE11:1;                  /**< bit:     11  Cancellation Finished Interrupt Enable for Transmit Buffer 11 */
    uint32_t CFIE12:1;                  /**< bit:     12  Cancellation Finished Interrupt Enable for Transmit Buffer 12 */
    uint32_t CFIE13:1;                  /**< bit:     13  Cancellation Finished Interrupt Enable for Transmit Buffer 13 */
    uint32_t CFIE14:1;                  /**< bit:     14  Cancellation Finished Interrupt Enable for Transmit Buffer 14 */
    uint32_t CFIE15:1;                  /**< bit:     15  Cancellation Finished Interrupt Enable for Transmit Buffer 15 */
    uint32_t CFIE16:1;                  /**< bit:     16  Cancellation Finished Interrupt Enable for Transmit Buffer 16 */
    uint32_t CFIE17:1;                  /**< bit:     17  Cancellation Finished Interrupt Enable for Transmit Buffer 17 */
    uint32_t CFIE18:1;                  /**< bit:     18  Cancellation Finished Interrupt Enable for Transmit Buffer 18 */
    uint32_t CFIE19:1;                  /**< bit:     19  Cancellation Finished Interrupt Enable for Transmit Buffer 19 */
    uint32_t CFIE20:1;                  /**< bit:     20  Cancellation Finished Interrupt Enable for Transmit Buffer 20 */
    uint32_t CFIE21:1;                  /**< bit:     21  Cancellation Finished Interrupt Enable for Transmit Buffer 21 */
    uint32_t CFIE22:1;                  /**< bit:     22  Cancellation Finished Interrupt Enable for Transmit Buffer 22 */
    uint32_t CFIE23:1;                  /**< bit:     23  Cancellation Finished Interrupt Enable for Transmit Buffer 23 */
    uint32_t CFIE24:1;                  /**< bit:     24  Cancellation Finished Interrupt Enable for Transmit Buffer 24 */
    uint32_t CFIE25:1;                  /**< bit:     25  Cancellation Finished Interrupt Enable for Transmit Buffer 25 */
    uint32_t CFIE26:1;                  /**< bit:     26  Cancellation Finished Interrupt Enable for Transmit Buffer 26 */
    uint32_t CFIE27:1;                  /**< bit:     27  Cancellation Finished Interrupt Enable for Transmit Buffer 27 */
    uint32_t CFIE28:1;                  /**< bit:     28  Cancellation Finished Interrupt Enable for Transmit Buffer 28 */
    uint32_t CFIE29:1;                  /**< bit:     29  Cancellation Finished Interrupt Enable for Transmit Buffer 29 */
    uint32_t CFIE30:1;                  /**< bit:     30  Cancellation Finished Interrupt Enable for Transmit Buffer 30 */
    uint32_t CFIE31:1;                  /**< bit:     31  Cancellation Finished Interrupt Enable for Transmit Buffer 31 */
  };
  struct
  {
    uint32_t CFIE:32;                   /**< bit:  0..31  Cancellation Finished Interrupt Enable for Transmit Buffer 3x */
  };
  uint32_t w;
} __MCAN_TXBCIE_bits_t;

#define MCAN_TXBCIE_CFIE0_Pos                 (0)                                            /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 0 Position */
#define MCAN_TXBCIE_CFIE0_Msk                 (0x1U << MCAN_TXBCIE_CFIE0_Pos)                /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 0 Mask */
#define MCAN_TXBCIE_CFIE1_Pos                 (1)                                            /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 1 Position */
#define MCAN_TXBCIE_CFIE1_Msk                 (0x1U << MCAN_TXBCIE_CFIE1_Pos)                /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 1 Mask */
#define MCAN_TXBCIE_CFIE2_Pos                 (2)                                            /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 2 Position */
#define MCAN_TXBCIE_CFIE2_Msk                 (0x1U << MCAN_TXBCIE_CFIE2_Pos)                /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 2 Mask */
#define MCAN_TXBCIE_CFIE3_Pos                 (3)                                            /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 3 Position */
#define MCAN_TXBCIE_CFIE3_Msk                 (0x1U << MCAN_TXBCIE_CFIE3_Pos)                /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 3 Mask */
#define MCAN_TXBCIE_CFIE4_Pos                 (4)                                            /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 4 Position */
#define MCAN_TXBCIE_CFIE4_Msk                 (0x1U << MCAN_TXBCIE_CFIE4_Pos)                /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 4 Mask */
#define MCAN_TXBCIE_CFIE5_Pos                 (5)                                            /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 5 Position */
#define MCAN_TXBCIE_CFIE5_Msk                 (0x1U << MCAN_TXBCIE_CFIE5_Pos)                /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 5 Mask */
#define MCAN_TXBCIE_CFIE6_Pos                 (6)                                            /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 6 Position */
#define MCAN_TXBCIE_CFIE6_Msk                 (0x1U << MCAN_TXBCIE_CFIE6_Pos)                /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 6 Mask */
#define MCAN_TXBCIE_CFIE7_Pos                 (7)                                            /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 7 Position */
#define MCAN_TXBCIE_CFIE7_Msk                 (0x1U << MCAN_TXBCIE_CFIE7_Pos)                /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 7 Mask */
#define MCAN_TXBCIE_CFIE8_Pos                 (8)                                            /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 8 Position */
#define MCAN_TXBCIE_CFIE8_Msk                 (0x1U << MCAN_TXBCIE_CFIE8_Pos)                /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 8 Mask */
#define MCAN_TXBCIE_CFIE9_Pos                 (9)                                            /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 9 Position */
#define MCAN_TXBCIE_CFIE9_Msk                 (0x1U << MCAN_TXBCIE_CFIE9_Pos)                /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 9 Mask */
#define MCAN_TXBCIE_CFIE10_Pos                (10)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 10 Position */
#define MCAN_TXBCIE_CFIE10_Msk                (0x1U << MCAN_TXBCIE_CFIE10_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 10 Mask */
#define MCAN_TXBCIE_CFIE11_Pos                (11)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 11 Position */
#define MCAN_TXBCIE_CFIE11_Msk                (0x1U << MCAN_TXBCIE_CFIE11_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 11 Mask */
#define MCAN_TXBCIE_CFIE12_Pos                (12)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 12 Position */
#define MCAN_TXBCIE_CFIE12_Msk                (0x1U << MCAN_TXBCIE_CFIE12_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 12 Mask */
#define MCAN_TXBCIE_CFIE13_Pos                (13)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 13 Position */
#define MCAN_TXBCIE_CFIE13_Msk                (0x1U << MCAN_TXBCIE_CFIE13_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 13 Mask */
#define MCAN_TXBCIE_CFIE14_Pos                (14)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 14 Position */
#define MCAN_TXBCIE_CFIE14_Msk                (0x1U << MCAN_TXBCIE_CFIE14_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 14 Mask */
#define MCAN_TXBCIE_CFIE15_Pos                (15)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 15 Position */
#define MCAN_TXBCIE_CFIE15_Msk                (0x1U << MCAN_TXBCIE_CFIE15_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 15 Mask */
#define MCAN_TXBCIE_CFIE16_Pos                (16)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 16 Position */
#define MCAN_TXBCIE_CFIE16_Msk                (0x1U << MCAN_TXBCIE_CFIE16_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 16 Mask */
#define MCAN_TXBCIE_CFIE17_Pos                (17)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 17 Position */
#define MCAN_TXBCIE_CFIE17_Msk                (0x1U << MCAN_TXBCIE_CFIE17_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 17 Mask */
#define MCAN_TXBCIE_CFIE18_Pos                (18)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 18 Position */
#define MCAN_TXBCIE_CFIE18_Msk                (0x1U << MCAN_TXBCIE_CFIE18_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 18 Mask */
#define MCAN_TXBCIE_CFIE19_Pos                (19)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 19 Position */
#define MCAN_TXBCIE_CFIE19_Msk                (0x1U << MCAN_TXBCIE_CFIE19_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 19 Mask */
#define MCAN_TXBCIE_CFIE20_Pos                (20)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 20 Position */
#define MCAN_TXBCIE_CFIE20_Msk                (0x1U << MCAN_TXBCIE_CFIE20_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 20 Mask */
#define MCAN_TXBCIE_CFIE21_Pos                (21)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 21 Position */
#define MCAN_TXBCIE_CFIE21_Msk                (0x1U << MCAN_TXBCIE_CFIE21_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 21 Mask */
#define MCAN_TXBCIE_CFIE22_Pos                (22)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 22 Position */
#define MCAN_TXBCIE_CFIE22_Msk                (0x1U << MCAN_TXBCIE_CFIE22_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 22 Mask */
#define MCAN_TXBCIE_CFIE23_Pos                (23)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 23 Position */
#define MCAN_TXBCIE_CFIE23_Msk                (0x1U << MCAN_TXBCIE_CFIE23_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 23 Mask */
#define MCAN_TXBCIE_CFIE24_Pos                (24)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 24 Position */
#define MCAN_TXBCIE_CFIE24_Msk                (0x1U << MCAN_TXBCIE_CFIE24_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 24 Mask */
#define MCAN_TXBCIE_CFIE25_Pos                (25)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 25 Position */
#define MCAN_TXBCIE_CFIE25_Msk                (0x1U << MCAN_TXBCIE_CFIE25_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 25 Mask */
#define MCAN_TXBCIE_CFIE26_Pos                (26)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 26 Position */
#define MCAN_TXBCIE_CFIE26_Msk                (0x1U << MCAN_TXBCIE_CFIE26_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 26 Mask */
#define MCAN_TXBCIE_CFIE27_Pos                (27)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 27 Position */
#define MCAN_TXBCIE_CFIE27_Msk                (0x1U << MCAN_TXBCIE_CFIE27_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 27 Mask */
#define MCAN_TXBCIE_CFIE28_Pos                (28)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 28 Position */
#define MCAN_TXBCIE_CFIE28_Msk                (0x1U << MCAN_TXBCIE_CFIE28_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 28 Mask */
#define MCAN_TXBCIE_CFIE29_Pos                (29)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 29 Position */
#define MCAN_TXBCIE_CFIE29_Msk                (0x1U << MCAN_TXBCIE_CFIE29_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 29 Mask */
#define MCAN_TXBCIE_CFIE30_Pos                (30)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 30 Position */
#define MCAN_TXBCIE_CFIE30_Msk                (0x1U << MCAN_TXBCIE_CFIE30_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 30 Mask */
#define MCAN_TXBCIE_CFIE31_Pos                (31)                                           /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 31 Position */
#define MCAN_TXBCIE_CFIE31_Msk                (0x1U << MCAN_TXBCIE_CFIE31_Pos)               /**< (MCAN_TXBCIE) Cancellation Finished Interrupt Enable for Transmit Buffer 31 Mask */
#define MCAN_TXBCIE_Msk                       (0xFFFFFFFFUL)                                 /**< (MCAN_TXBCIE) Register Mask  */
#define MCAN_TXBCIE_CFIE_Pos                  (0)                                            /**< (MCAN_TXBCIE Position) Cancellation Finished Interrupt Enable for Transmit Buffer 3x */
#define MCAN_TXBCIE_CFIE_Msk                  (0xFFFFFFFFU << MCAN_TXBCIE_CFIE_Pos)          /**< (MCAN_TXBCIE Mask) CFIE */
#define MCAN_TXBCIE_CFIE(value)               (MCAN_TXBCIE_CFIE_Msk & ((value) << MCAN_TXBCIE_CFIE_Pos))

/* -------- MCAN_TXEFC : (MCAN Offset: 0xf0) (R/W 32) Transmit Event FIFO Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t EFSA:14;                   /**< bit:  2..15  Event FIFO Start Address                      */
    uint32_t EFS:6;                     /**< bit: 16..21  Event FIFO Size                               */
    uint32_t :2;                        /**< bit: 22..23  Reserved                                      */
    uint32_t EFWM:6;                    /**< bit: 24..29  Event FIFO Watermark                          */
    uint32_t :2;                        /**< bit: 30..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_TXEFC_bits_t;

#define MCAN_TXEFC_EFSA_Pos                   (2)                                            /**< (MCAN_TXEFC) Event FIFO Start Address Position */
#define MCAN_TXEFC_EFSA_Msk                   (0x3FFFU << MCAN_TXEFC_EFSA_Pos)               /**< (MCAN_TXEFC) Event FIFO Start Address Mask */
#define MCAN_TXEFC_EFSA(value)                (MCAN_TXEFC_EFSA_Msk & ((value) << MCAN_TXEFC_EFSA_Pos))
#define MCAN_TXEFC_EFS_Pos                    (16)                                           /**< (MCAN_TXEFC) Event FIFO Size Position */
#define MCAN_TXEFC_EFS_Msk                    (0x3FU << MCAN_TXEFC_EFS_Pos)                  /**< (MCAN_TXEFC) Event FIFO Size Mask */
#define MCAN_TXEFC_EFS(value)                 (MCAN_TXEFC_EFS_Msk & ((value) << MCAN_TXEFC_EFS_Pos))
#define MCAN_TXEFC_EFWM_Pos                   (24)                                           /**< (MCAN_TXEFC) Event FIFO Watermark Position */
#define MCAN_TXEFC_EFWM_Msk                   (0x3FU << MCAN_TXEFC_EFWM_Pos)                 /**< (MCAN_TXEFC) Event FIFO Watermark Mask */
#define MCAN_TXEFC_EFWM(value)                (MCAN_TXEFC_EFWM_Msk & ((value) << MCAN_TXEFC_EFWM_Pos))
#define MCAN_TXEFC_Msk                        (0x3F3FFFFCUL)                                 /**< (MCAN_TXEFC) Register Mask  */

/* -------- MCAN_TXEFS : (MCAN Offset: 0xf4) (R/ 32) Transmit Event FIFO Status Register -------- */

typedef union
{
  struct
  {
    uint32_t EFFL:6;                    /**< bit:   0..5  Event FIFO Fill Level                         */
    uint32_t :2;                        /**< bit:   6..7  Reserved                                      */
    uint32_t EFGI:5;                    /**< bit:  8..12  Event FIFO Get Index                          */
    uint32_t :3;                        /**< bit: 13..15  Reserved                                      */
    uint32_t EFPI:5;                    /**< bit: 16..20  Event FIFO Put Index                          */
    uint32_t :3;                        /**< bit: 21..23  Reserved                                      */
    uint32_t EFF:1;                     /**< bit:     24  Event FIFO Full                               */
    uint32_t TEFL:1;                    /**< bit:     25  Tx Event FIFO Element Lost                    */
    uint32_t :6;                        /**< bit: 26..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_TXEFS_bits_t;

#define MCAN_TXEFS_EFFL_Pos                   (0)                                            /**< (MCAN_TXEFS) Event FIFO Fill Level Position */
#define MCAN_TXEFS_EFFL_Msk                   (0x3FU << MCAN_TXEFS_EFFL_Pos)                 /**< (MCAN_TXEFS) Event FIFO Fill Level Mask */
#define MCAN_TXEFS_EFFL(value)                (MCAN_TXEFS_EFFL_Msk & ((value) << MCAN_TXEFS_EFFL_Pos))
#define MCAN_TXEFS_EFGI_Pos                   (8)                                            /**< (MCAN_TXEFS) Event FIFO Get Index Position */
#define MCAN_TXEFS_EFGI_Msk                   (0x1FU << MCAN_TXEFS_EFGI_Pos)                 /**< (MCAN_TXEFS) Event FIFO Get Index Mask */
#define MCAN_TXEFS_EFGI(value)                (MCAN_TXEFS_EFGI_Msk & ((value) << MCAN_TXEFS_EFGI_Pos))
#define MCAN_TXEFS_EFPI_Pos                   (16)                                           /**< (MCAN_TXEFS) Event FIFO Put Index Position */
#define MCAN_TXEFS_EFPI_Msk                   (0x1FU << MCAN_TXEFS_EFPI_Pos)                 /**< (MCAN_TXEFS) Event FIFO Put Index Mask */
#define MCAN_TXEFS_EFPI(value)                (MCAN_TXEFS_EFPI_Msk & ((value) << MCAN_TXEFS_EFPI_Pos))
#define MCAN_TXEFS_EFF_Pos                    (24)                                           /**< (MCAN_TXEFS) Event FIFO Full Position */
#define MCAN_TXEFS_EFF_Msk                    (0x1U << MCAN_TXEFS_EFF_Pos)                   /**< (MCAN_TXEFS) Event FIFO Full Mask */
#define MCAN_TXEFS_TEFL_Pos                   (25)                                           /**< (MCAN_TXEFS) Tx Event FIFO Element Lost Position */
#define MCAN_TXEFS_TEFL_Msk                   (0x1U << MCAN_TXEFS_TEFL_Pos)                  /**< (MCAN_TXEFS) Tx Event FIFO Element Lost Mask */
#define MCAN_TXEFS_Msk                        (0x031F1F3FUL)                                 /**< (MCAN_TXEFS) Register Mask  */

/* -------- MCAN_TXEFA : (MCAN Offset: 0xf8) (R/W 32) Transmit Event FIFO Acknowledge Register -------- */

typedef union
{
  struct
  {
    uint32_t EFAI:5;                    /**< bit:   0..4  Event FIFO Acknowledge Index                  */
    uint32_t :27;                       /**< bit:  5..31  Reserved                                      */
  };
  uint32_t w;
} __MCAN_TXEFA_bits_t;

#define MCAN_TXEFA_EFAI_Pos                   (0)                                            /**< (MCAN_TXEFA) Event FIFO Acknowledge Index Position */
#define MCAN_TXEFA_EFAI_Msk                   (0x1FU << MCAN_TXEFA_EFAI_Pos)                 /**< (MCAN_TXEFA) Event FIFO Acknowledge Index Mask */
#define MCAN_TXEFA_EFAI(value)                (MCAN_TXEFA_EFAI_Msk & ((value) << MCAN_TXEFA_EFAI_Pos))
#define MCAN_TXEFA_Msk                        (0x0000001FUL)                                 /**< (MCAN_TXEFA) Register Mask  */

/** \brief MCAN register offsets definitions */
#define MCAN_CREL_OFFSET             (0x00)         /**< (MCAN_CREL) Core Release Register Offset */
#define MCAN_ENDN_OFFSET             (0x04)         /**< (MCAN_ENDN) Endian Register Offset */
#define MCAN_CUST_OFFSET             (0x08)         /**< (MCAN_CUST) Customer Register Offset */
#define MCAN_DBTP_OFFSET             (0x0C)         /**< (MCAN_DBTP) Data Bit Timing and Prescaler Register Offset */
#define MCAN_TEST_OFFSET             (0x10)         /**< (MCAN_TEST) Test Register Offset */
#define MCAN_RWD_OFFSET              (0x14)         /**< (MCAN_RWD) RAM Watchdog Register Offset */
#define MCAN_CCCR_OFFSET             (0x18)         /**< (MCAN_CCCR) CC Control Register Offset */
#define MCAN_NBTP_OFFSET             (0x1C)         /**< (MCAN_NBTP) Nominal Bit Timing and Prescaler Register Offset */
#define MCAN_TSCC_OFFSET             (0x20)         /**< (MCAN_TSCC) Timestamp Counter Configuration Register Offset */
#define MCAN_TSCV_OFFSET             (0x24)         /**< (MCAN_TSCV) Timestamp Counter Value Register Offset */
#define MCAN_TOCC_OFFSET             (0x28)         /**< (MCAN_TOCC) Timeout Counter Configuration Register Offset */
#define MCAN_TOCV_OFFSET             (0x2C)         /**< (MCAN_TOCV) Timeout Counter Value Register Offset */
#define MCAN_ECR_OFFSET              (0x40)         /**< (MCAN_ECR) Error Counter Register Offset */
#define MCAN_PSR_OFFSET              (0x44)         /**< (MCAN_PSR) Protocol Status Register Offset */
#define MCAN_TDCR_OFFSET             (0x48)         /**< (MCAN_TDCR) Transmit Delay Compensation Register Offset */
#define MCAN_IR_OFFSET               (0x50)         /**< (MCAN_IR) Interrupt Register Offset */
#define MCAN_IE_OFFSET               (0x54)         /**< (MCAN_IE) Interrupt Enable Register Offset */
#define MCAN_ILS_OFFSET              (0x58)         /**< (MCAN_ILS) Interrupt Line Select Register Offset */
#define MCAN_ILE_OFFSET              (0x5C)         /**< (MCAN_ILE) Interrupt Line Enable Register Offset */
#define MCAN_GFC_OFFSET              (0x80)         /**< (MCAN_GFC) Global Filter Configuration Register Offset */
#define MCAN_SIDFC_OFFSET            (0x84)         /**< (MCAN_SIDFC) Standard ID Filter Configuration Register Offset */
#define MCAN_XIDFC_OFFSET            (0x88)         /**< (MCAN_XIDFC) Extended ID Filter Configuration Register Offset */
#define MCAN_XIDAM_OFFSET            (0x90)         /**< (MCAN_XIDAM) Extended ID AND Mask Register Offset */
#define MCAN_HPMS_OFFSET             (0x94)         /**< (MCAN_HPMS) High Priority Message Status Register Offset */
#define MCAN_NDAT1_OFFSET            (0x98)         /**< (MCAN_NDAT1) New Data 1 Register Offset */
#define MCAN_NDAT2_OFFSET            (0x9C)         /**< (MCAN_NDAT2) New Data 2 Register Offset */
#define MCAN_RXF0C_OFFSET            (0xA0)         /**< (MCAN_RXF0C) Receive FIFO 0 Configuration Register Offset */
#define MCAN_RXF0S_OFFSET            (0xA4)         /**< (MCAN_RXF0S) Receive FIFO 0 Status Register Offset */
#define MCAN_RXF0A_OFFSET            (0xA8)         /**< (MCAN_RXF0A) Receive FIFO 0 Acknowledge Register Offset */
#define MCAN_RXBC_OFFSET             (0xAC)         /**< (MCAN_RXBC) Receive Rx Buffer Configuration Register Offset */
#define MCAN_RXF1C_OFFSET            (0xB0)         /**< (MCAN_RXF1C) Receive FIFO 1 Configuration Register Offset */
#define MCAN_RXF1S_OFFSET            (0xB4)         /**< (MCAN_RXF1S) Receive FIFO 1 Status Register Offset */
#define MCAN_RXF1A_OFFSET            (0xB8)         /**< (MCAN_RXF1A) Receive FIFO 1 Acknowledge Register Offset */
#define MCAN_RXESC_OFFSET            (0xBC)         /**< (MCAN_RXESC) Receive Buffer / FIFO Element Size Configuration Register Offset */
#define MCAN_TXBC_OFFSET             (0xC0)         /**< (MCAN_TXBC) Transmit Buffer Configuration Register Offset */
#define MCAN_TXFQS_OFFSET            (0xC4)         /**< (MCAN_TXFQS) Transmit FIFO/Queue Status Register Offset */
#define MCAN_TXESC_OFFSET            (0xC8)         /**< (MCAN_TXESC) Transmit Buffer Element Size Configuration Register Offset */
#define MCAN_TXBRP_OFFSET            (0xCC)         /**< (MCAN_TXBRP) Transmit Buffer Request Pending Register Offset */
#define MCAN_TXBAR_OFFSET            (0xD0)         /**< (MCAN_TXBAR) Transmit Buffer Add Request Register Offset */
#define MCAN_TXBCR_OFFSET            (0xD4)         /**< (MCAN_TXBCR) Transmit Buffer Cancellation Request Register Offset */
#define MCAN_TXBTO_OFFSET            (0xD8)         /**< (MCAN_TXBTO) Transmit Buffer Transmission Occurred Register Offset */
#define MCAN_TXBCF_OFFSET            (0xDC)         /**< (MCAN_TXBCF) Transmit Buffer Cancellation Finished Register Offset */
#define MCAN_TXBTIE_OFFSET           (0xE0)         /**< (MCAN_TXBTIE) Transmit Buffer Transmission Interrupt Enable Register Offset */
#define MCAN_TXBCIE_OFFSET           (0xE4)         /**< (MCAN_TXBCIE) Transmit Buffer Cancellation Finished Interrupt Enable Register Offset */
#define MCAN_TXEFC_OFFSET            (0xF0)         /**< (MCAN_TXEFC) Transmit Event FIFO Configuration Register Offset */
#define MCAN_TXEFS_OFFSET            (0xF4)         /**< (MCAN_TXEFS) Transmit Event FIFO Status Register Offset */
#define MCAN_TXEFA_OFFSET            (0xF8)         /**< (MCAN_TXEFA) Transmit Event FIFO Acknowledge Register Offset */

/** \brief MCAN register API structure */
typedef struct
{
  __I   __MCAN_CREL_bits_t             MCAN_CREL;     /**< Offset: 0x00 (R/   32) Core Release Register */
  __I   __MCAN_ENDN_bits_t             MCAN_ENDN;     /**< Offset: 0x04 (R/   32) Endian Register */
  __IO  __MCAN_CUST_bits_t             MCAN_CUST;     /**< Offset: 0x08 (R/W  32) Customer Register */
  __IO  __MCAN_DBTP_bits_t             MCAN_DBTP;     /**< Offset: 0x0C (R/W  32) Data Bit Timing and Prescaler Register */
  __IO  __MCAN_TEST_bits_t             MCAN_TEST;     /**< Offset: 0x10 (R/W  32) Test Register */
  __IO  __MCAN_RWD_bits_t              MCAN_RWD;      /**< Offset: 0x14 (R/W  32) RAM Watchdog Register */
  __IO  __MCAN_CCCR_bits_t             MCAN_CCCR;     /**< Offset: 0x18 (R/W  32) CC Control Register */
  __IO  __MCAN_NBTP_bits_t             MCAN_NBTP;     /**< Offset: 0x1C (R/W  32) Nominal Bit Timing and Prescaler Register */
  __IO  __MCAN_TSCC_bits_t             MCAN_TSCC;     /**< Offset: 0x20 (R/W  32) Timestamp Counter Configuration Register */
  __IO  __MCAN_TSCV_bits_t             MCAN_TSCV;     /**< Offset: 0x24 (R/W  32) Timestamp Counter Value Register */
  __IO  __MCAN_TOCC_bits_t             MCAN_TOCC;     /**< Offset: 0x28 (R/W  32) Timeout Counter Configuration Register */
  __IO  __MCAN_TOCV_bits_t             MCAN_TOCV;     /**< Offset: 0x2C (R/W  32) Timeout Counter Value Register */
  __I   uint8_t                        Reserved1[0x10];
  __I   __MCAN_ECR_bits_t              MCAN_ECR;      /**< Offset: 0x40 (R/   32) Error Counter Register */
  __I   __MCAN_PSR_bits_t              MCAN_PSR;      /**< Offset: 0x44 (R/   32) Protocol Status Register */
  __IO  __MCAN_TDCR_bits_t             MCAN_TDCR;     /**< Offset: 0x48 (R/W  32) Transmit Delay Compensation Register */
  __I   uint8_t                        Reserved2[0x04];
  __IO  __MCAN_IR_bits_t               MCAN_IR;       /**< Offset: 0x50 (R/W  32) Interrupt Register */
  __IO  __MCAN_IE_bits_t               MCAN_IE;       /**< Offset: 0x54 (R/W  32) Interrupt Enable Register */
  __IO  __MCAN_ILS_bits_t              MCAN_ILS;      /**< Offset: 0x58 (R/W  32) Interrupt Line Select Register */
  __IO  __MCAN_ILE_bits_t              MCAN_ILE;      /**< Offset: 0x5C (R/W  32) Interrupt Line Enable Register */
  __I   uint8_t                        Reserved3[0x20];
  __IO  __MCAN_GFC_bits_t              MCAN_GFC;      /**< Offset: 0x80 (R/W  32) Global Filter Configuration Register */
  __IO  __MCAN_SIDFC_bits_t            MCAN_SIDFC;    /**< Offset: 0x84 (R/W  32) Standard ID Filter Configuration Register */
  __IO  __MCAN_XIDFC_bits_t            MCAN_XIDFC;    /**< Offset: 0x88 (R/W  32) Extended ID Filter Configuration Register */
  __I   uint8_t                        Reserved4[0x04];
  __IO  __MCAN_XIDAM_bits_t            MCAN_XIDAM;    /**< Offset: 0x90 (R/W  32) Extended ID AND Mask Register */
  __I   __MCAN_HPMS_bits_t             MCAN_HPMS;     /**< Offset: 0x94 (R/   32) High Priority Message Status Register */
  __IO  __MCAN_NDAT1_bits_t            MCAN_NDAT1;    /**< Offset: 0x98 (R/W  32) New Data 1 Register */
  __IO  __MCAN_NDAT2_bits_t            MCAN_NDAT2;    /**< Offset: 0x9C (R/W  32) New Data 2 Register */
  __IO  __MCAN_RXF0C_bits_t            MCAN_RXF0C;    /**< Offset: 0xA0 (R/W  32) Receive FIFO 0 Configuration Register */
  __I   __MCAN_RXF0S_bits_t            MCAN_RXF0S;    /**< Offset: 0xA4 (R/   32) Receive FIFO 0 Status Register */
  __IO  __MCAN_RXF0A_bits_t            MCAN_RXF0A;    /**< Offset: 0xA8 (R/W  32) Receive FIFO 0 Acknowledge Register */
  __IO  __MCAN_RXBC_bits_t             MCAN_RXBC;     /**< Offset: 0xAC (R/W  32) Receive Rx Buffer Configuration Register */
  __IO  __MCAN_RXF1C_bits_t            MCAN_RXF1C;    /**< Offset: 0xB0 (R/W  32) Receive FIFO 1 Configuration Register */
  __I   __MCAN_RXF1S_bits_t            MCAN_RXF1S;    /**< Offset: 0xB4 (R/   32) Receive FIFO 1 Status Register */
  __IO  __MCAN_RXF1A_bits_t            MCAN_RXF1A;    /**< Offset: 0xB8 (R/W  32) Receive FIFO 1 Acknowledge Register */
  __IO  __MCAN_RXESC_bits_t            MCAN_RXESC;    /**< Offset: 0xBC (R/W  32) Receive Buffer / FIFO Element Size Configuration Register */
  __IO  __MCAN_TXBC_bits_t             MCAN_TXBC;     /**< Offset: 0xC0 (R/W  32) Transmit Buffer Configuration Register */
  __I   __MCAN_TXFQS_bits_t            MCAN_TXFQS;    /**< Offset: 0xC4 (R/   32) Transmit FIFO/Queue Status Register */
  __IO  __MCAN_TXESC_bits_t            MCAN_TXESC;    /**< Offset: 0xC8 (R/W  32) Transmit Buffer Element Size Configuration Register */
  __I   __MCAN_TXBRP_bits_t            MCAN_TXBRP;    /**< Offset: 0xCC (R/   32) Transmit Buffer Request Pending Register */
  __IO  __MCAN_TXBAR_bits_t            MCAN_TXBAR;    /**< Offset: 0xD0 (R/W  32) Transmit Buffer Add Request Register */
  __IO  __MCAN_TXBCR_bits_t            MCAN_TXBCR;    /**< Offset: 0xD4 (R/W  32) Transmit Buffer Cancellation Request Register */
  __I   __MCAN_TXBTO_bits_t            MCAN_TXBTO;    /**< Offset: 0xD8 (R/   32) Transmit Buffer Transmission Occurred Register */
  __I   __MCAN_TXBCF_bits_t            MCAN_TXBCF;    /**< Offset: 0xDC (R/   32) Transmit Buffer Cancellation Finished Register */
  __IO  __MCAN_TXBTIE_bits_t           MCAN_TXBTIE;   /**< Offset: 0xE0 (R/W  32) Transmit Buffer Transmission Interrupt Enable Register */
  __IO  __MCAN_TXBCIE_bits_t           MCAN_TXBCIE;   /**< Offset: 0xE4 (R/W  32) Transmit Buffer Cancellation Finished Interrupt Enable Register */
  __I   uint8_t                        Reserved5[0x08];
  __IO  __MCAN_TXEFC_bits_t            MCAN_TXEFC;    /**< Offset: 0xF0 (R/W  32) Transmit Event FIFO Configuration Register */
  __I   __MCAN_TXEFS_bits_t            MCAN_TXEFS;    /**< Offset: 0xF4 (R/   32) Transmit Event FIFO Status Register */
  __IO  __MCAN_TXEFA_bits_t            MCAN_TXEFA;    /**< Offset: 0xF8 (R/W  32) Transmit Event FIFO Acknowledge Register */
} mcan_registers_t;
/** @}  end of Controller Area Network */

#endif /* _PIC32CZ_CA70_MCAN_COMPONENT_H_ */
