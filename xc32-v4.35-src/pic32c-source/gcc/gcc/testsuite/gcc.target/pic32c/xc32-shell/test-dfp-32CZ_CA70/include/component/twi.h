/**
 * \brief Component description for PIC32CZ/CA70 TWI
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
#ifndef _PIC32CZ_CA70_TWI_COMPONENT_H_
#define _PIC32CZ_CA70_TWI_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_TWI Two-wire Interface
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR TWI */
/* ========================================================================== */

/* -------- TWI_CR : (TWI Offset: 0x00) (/W 32) Control Register -------- */

typedef union
{
  struct
  {
    uint32_t START:1;                   /**< bit:      0  Send a START Condition                        */
    uint32_t STOP:1;                    /**< bit:      1  Send a STOP Condition                         */
    uint32_t MSEN:1;                    /**< bit:      2  TWI Master Mode Enabled                       */
    uint32_t MSDIS:1;                   /**< bit:      3  TWI Master Mode Disabled                      */
    uint32_t SVEN:1;                    /**< bit:      4  TWI Slave Mode Enabled                        */
    uint32_t SVDIS:1;                   /**< bit:      5  TWI Slave Mode Disabled                       */
    uint32_t QUICK:1;                   /**< bit:      6  SMBus Quick Command                           */
    uint32_t SWRST:1;                   /**< bit:      7  Software Reset                                */
    uint32_t HSEN:1;                    /**< bit:      8  TWI High-Speed Mode Enabled                   */
    uint32_t HSDIS:1;                   /**< bit:      9  TWI High-Speed Mode Disabled                  */
    uint32_t SMBEN:1;                   /**< bit:     10  SMBus Mode Enabled                            */
    uint32_t SMBDIS:1;                  /**< bit:     11  SMBus Mode Disabled                           */
    uint32_t PECEN:1;                   /**< bit:     12  Packet Error Checking Enable                  */
    uint32_t PECDIS:1;                  /**< bit:     13  Packet Error Checking Disable                 */
    uint32_t PECRQ:1;                   /**< bit:     14  PEC Request                                   */
    uint32_t CLEAR:1;                   /**< bit:     15  Bus CLEAR Command                             */
    uint32_t ACMEN:1;                   /**< bit:     16  Alternative Command Mode Enable               */
    uint32_t ACMDIS:1;                  /**< bit:     17  Alternative Command Mode Disable              */
    uint32_t :6;                        /**< bit: 18..23  Reserved                                      */
    uint32_t THRCLR:1;                  /**< bit:     24  Transmit Holding Register Clear               */
    uint32_t :1;                        /**< bit:     25  Reserved                                      */
    uint32_t LOCKCLR:1;                 /**< bit:     26  Lock Clear                                    */
    uint32_t :1;                        /**< bit:     27  Reserved                                      */
    uint32_t FIFOEN:1;                  /**< bit:     28  FIFO Enable                                   */
    uint32_t FIFODIS:1;                 /**< bit:     29  FIFO Disable                                  */
    uint32_t :2;                        /**< bit: 30..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_CR_bits_t;

#define TWI_CR_START_Pos                      (0)                                            /**< (TWI_CR) Send a START Condition Position */
#define TWI_CR_START_Msk                      (0x1U << TWI_CR_START_Pos)                     /**< (TWI_CR) Send a START Condition Mask */
#define TWI_CR_STOP_Pos                       (1)                                            /**< (TWI_CR) Send a STOP Condition Position */
#define TWI_CR_STOP_Msk                       (0x1U << TWI_CR_STOP_Pos)                      /**< (TWI_CR) Send a STOP Condition Mask */
#define TWI_CR_MSEN_Pos                       (2)                                            /**< (TWI_CR) TWI Master Mode Enabled Position */
#define TWI_CR_MSEN_Msk                       (0x1U << TWI_CR_MSEN_Pos)                      /**< (TWI_CR) TWI Master Mode Enabled Mask */
#define TWI_CR_MSDIS_Pos                      (3)                                            /**< (TWI_CR) TWI Master Mode Disabled Position */
#define TWI_CR_MSDIS_Msk                      (0x1U << TWI_CR_MSDIS_Pos)                     /**< (TWI_CR) TWI Master Mode Disabled Mask */
#define TWI_CR_SVEN_Pos                       (4)                                            /**< (TWI_CR) TWI Slave Mode Enabled Position */
#define TWI_CR_SVEN_Msk                       (0x1U << TWI_CR_SVEN_Pos)                      /**< (TWI_CR) TWI Slave Mode Enabled Mask */
#define TWI_CR_SVDIS_Pos                      (5)                                            /**< (TWI_CR) TWI Slave Mode Disabled Position */
#define TWI_CR_SVDIS_Msk                      (0x1U << TWI_CR_SVDIS_Pos)                     /**< (TWI_CR) TWI Slave Mode Disabled Mask */
#define TWI_CR_QUICK_Pos                      (6)                                            /**< (TWI_CR) SMBus Quick Command Position */
#define TWI_CR_QUICK_Msk                      (0x1U << TWI_CR_QUICK_Pos)                     /**< (TWI_CR) SMBus Quick Command Mask */
#define TWI_CR_SWRST_Pos                      (7)                                            /**< (TWI_CR) Software Reset Position */
#define TWI_CR_SWRST_Msk                      (0x1U << TWI_CR_SWRST_Pos)                     /**< (TWI_CR) Software Reset Mask */
#define TWI_CR_HSEN_Pos                       (8)                                            /**< (TWI_CR) TWI High-Speed Mode Enabled Position */
#define TWI_CR_HSEN_Msk                       (0x1U << TWI_CR_HSEN_Pos)                      /**< (TWI_CR) TWI High-Speed Mode Enabled Mask */
#define TWI_CR_HSDIS_Pos                      (9)                                            /**< (TWI_CR) TWI High-Speed Mode Disabled Position */
#define TWI_CR_HSDIS_Msk                      (0x1U << TWI_CR_HSDIS_Pos)                     /**< (TWI_CR) TWI High-Speed Mode Disabled Mask */
#define TWI_CR_SMBEN_Pos                      (10)                                           /**< (TWI_CR) SMBus Mode Enabled Position */
#define TWI_CR_SMBEN_Msk                      (0x1U << TWI_CR_SMBEN_Pos)                     /**< (TWI_CR) SMBus Mode Enabled Mask */
#define TWI_CR_SMBDIS_Pos                     (11)                                           /**< (TWI_CR) SMBus Mode Disabled Position */
#define TWI_CR_SMBDIS_Msk                     (0x1U << TWI_CR_SMBDIS_Pos)                    /**< (TWI_CR) SMBus Mode Disabled Mask */
#define TWI_CR_PECEN_Pos                      (12)                                           /**< (TWI_CR) Packet Error Checking Enable Position */
#define TWI_CR_PECEN_Msk                      (0x1U << TWI_CR_PECEN_Pos)                     /**< (TWI_CR) Packet Error Checking Enable Mask */
#define TWI_CR_PECDIS_Pos                     (13)                                           /**< (TWI_CR) Packet Error Checking Disable Position */
#define TWI_CR_PECDIS_Msk                     (0x1U << TWI_CR_PECDIS_Pos)                    /**< (TWI_CR) Packet Error Checking Disable Mask */
#define TWI_CR_PECRQ_Pos                      (14)                                           /**< (TWI_CR) PEC Request Position */
#define TWI_CR_PECRQ_Msk                      (0x1U << TWI_CR_PECRQ_Pos)                     /**< (TWI_CR) PEC Request Mask */
#define TWI_CR_CLEAR_Pos                      (15)                                           /**< (TWI_CR) Bus CLEAR Command Position */
#define TWI_CR_CLEAR_Msk                      (0x1U << TWI_CR_CLEAR_Pos)                     /**< (TWI_CR) Bus CLEAR Command Mask */
#define TWI_CR_ACMEN_Pos                      (16)                                           /**< (TWI_CR) Alternative Command Mode Enable Position */
#define TWI_CR_ACMEN_Msk                      (0x1U << TWI_CR_ACMEN_Pos)                     /**< (TWI_CR) Alternative Command Mode Enable Mask */
#define TWI_CR_ACMDIS_Pos                     (17)                                           /**< (TWI_CR) Alternative Command Mode Disable Position */
#define TWI_CR_ACMDIS_Msk                     (0x1U << TWI_CR_ACMDIS_Pos)                    /**< (TWI_CR) Alternative Command Mode Disable Mask */
#define TWI_CR_THRCLR_Pos                     (24)                                           /**< (TWI_CR) Transmit Holding Register Clear Position */
#define TWI_CR_THRCLR_Msk                     (0x1U << TWI_CR_THRCLR_Pos)                    /**< (TWI_CR) Transmit Holding Register Clear Mask */
#define TWI_CR_LOCKCLR_Pos                    (26)                                           /**< (TWI_CR) Lock Clear Position */
#define TWI_CR_LOCKCLR_Msk                    (0x1U << TWI_CR_LOCKCLR_Pos)                   /**< (TWI_CR) Lock Clear Mask */
#define TWI_CR_FIFOEN_Pos                     (28)                                           /**< (TWI_CR) FIFO Enable Position */
#define TWI_CR_FIFOEN_Msk                     (0x1U << TWI_CR_FIFOEN_Pos)                    /**< (TWI_CR) FIFO Enable Mask */
#define TWI_CR_FIFODIS_Pos                    (29)                                           /**< (TWI_CR) FIFO Disable Position */
#define TWI_CR_FIFODIS_Msk                    (0x1U << TWI_CR_FIFODIS_Pos)                   /**< (TWI_CR) FIFO Disable Mask */
#define TWI_CR_Msk                            (0x3503FFFFUL)                                 /**< (TWI_CR) Register Mask  */

/* -------- TWI_MMR : (TWI Offset: 0x04) (R/W 32) Master Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t :8;                        /**< bit:   0..7  Reserved                                      */
    uint32_t IADRSZ:2;                  /**< bit:   8..9  Internal Device Address Size                  */
    uint32_t :2;                        /**< bit: 10..11  Reserved                                      */
    uint32_t MREAD:1;                   /**< bit:     12  Master Read Direction                         */
    uint32_t :3;                        /**< bit: 13..15  Reserved                                      */
    uint32_t DADR:7;                    /**< bit: 16..22  Device Address                                */
    uint32_t :9;                        /**< bit: 23..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_MMR_bits_t;

#define TWI_MMR_IADRSZ_Pos                    (8)                                            /**< (TWI_MMR) Internal Device Address Size Position */
#define TWI_MMR_IADRSZ_Msk                    (0x3U << TWI_MMR_IADRSZ_Pos)                   /**< (TWI_MMR) Internal Device Address Size Mask */
#define TWI_MMR_IADRSZ(value)                 (TWI_MMR_IADRSZ_Msk & ((value) << TWI_MMR_IADRSZ_Pos))
#define   TWI_MMR_IADRSZ_NONE_Val             (0x0U)                                         /**< (TWI_MMR) No internal device address  */
#define   TWI_MMR_IADRSZ_1_BYTE_Val           (0x1U)                                         /**< (TWI_MMR) One-byte internal device address  */
#define   TWI_MMR_IADRSZ_2_BYTE_Val           (0x2U)                                         /**< (TWI_MMR) Two-byte internal device address  */
#define   TWI_MMR_IADRSZ_3_BYTE_Val           (0x3U)                                         /**< (TWI_MMR) Three-byte internal device address  */
#define TWI_MMR_IADRSZ_NONE                   (TWI_MMR_IADRSZ_NONE_Val << TWI_MMR_IADRSZ_Pos)  /**< (TWI_MMR) No internal device address Position  */
#define TWI_MMR_IADRSZ_1_BYTE                 (TWI_MMR_IADRSZ_1_BYTE_Val << TWI_MMR_IADRSZ_Pos)  /**< (TWI_MMR) One-byte internal device address Position  */
#define TWI_MMR_IADRSZ_2_BYTE                 (TWI_MMR_IADRSZ_2_BYTE_Val << TWI_MMR_IADRSZ_Pos)  /**< (TWI_MMR) Two-byte internal device address Position  */
#define TWI_MMR_IADRSZ_3_BYTE                 (TWI_MMR_IADRSZ_3_BYTE_Val << TWI_MMR_IADRSZ_Pos)  /**< (TWI_MMR) Three-byte internal device address Position  */
#define TWI_MMR_MREAD_Pos                     (12)                                           /**< (TWI_MMR) Master Read Direction Position */
#define TWI_MMR_MREAD_Msk                     (0x1U << TWI_MMR_MREAD_Pos)                    /**< (TWI_MMR) Master Read Direction Mask */
#define TWI_MMR_DADR_Pos                      (16)                                           /**< (TWI_MMR) Device Address Position */
#define TWI_MMR_DADR_Msk                      (0x7FU << TWI_MMR_DADR_Pos)                    /**< (TWI_MMR) Device Address Mask */
#define TWI_MMR_DADR(value)                   (TWI_MMR_DADR_Msk & ((value) << TWI_MMR_DADR_Pos))
#define TWI_MMR_Msk                           (0x007F1300UL)                                 /**< (TWI_MMR) Register Mask  */

/* -------- TWI_SMR : (TWI Offset: 0x08) (R/W 32) Slave Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t NACKEN:1;                  /**< bit:      0  Slave Receiver Data Phase NACK enable         */
    uint32_t :1;                        /**< bit:      1  Reserved                                      */
    uint32_t SMDA:1;                    /**< bit:      2  SMBus Default Address                         */
    uint32_t SMHH:1;                    /**< bit:      3  SMBus Host Header                             */
    uint32_t :2;                        /**< bit:   4..5  Reserved                                      */
    uint32_t SCLWSDIS:1;                /**< bit:      6  Clock Wait State Disable                      */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t MASK:7;                    /**< bit:  8..14  Slave Address Mask                            */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t SADR:7;                    /**< bit: 16..22  Slave Address                                 */
    uint32_t :5;                        /**< bit: 23..27  Reserved                                      */
    uint32_t SADR1EN:1;                 /**< bit:     28  Slave Address 1 Enable                        */
    uint32_t SADR2EN:1;                 /**< bit:     29  Slave Address 2 Enable                        */
    uint32_t SADR3EN:1;                 /**< bit:     30  Slave Address 3 Enable                        */
    uint32_t DATAMEN:1;                 /**< bit:     31  Data Matching Enable                          */
  };
  uint32_t w;
} __TWI_SMR_bits_t;

#define TWI_SMR_NACKEN_Pos                    (0)                                            /**< (TWI_SMR) Slave Receiver Data Phase NACK enable Position */
#define TWI_SMR_NACKEN_Msk                    (0x1U << TWI_SMR_NACKEN_Pos)                   /**< (TWI_SMR) Slave Receiver Data Phase NACK enable Mask */
#define TWI_SMR_SMDA_Pos                      (2)                                            /**< (TWI_SMR) SMBus Default Address Position */
#define TWI_SMR_SMDA_Msk                      (0x1U << TWI_SMR_SMDA_Pos)                     /**< (TWI_SMR) SMBus Default Address Mask */
#define TWI_SMR_SMHH_Pos                      (3)                                            /**< (TWI_SMR) SMBus Host Header Position */
#define TWI_SMR_SMHH_Msk                      (0x1U << TWI_SMR_SMHH_Pos)                     /**< (TWI_SMR) SMBus Host Header Mask */
#define TWI_SMR_SCLWSDIS_Pos                  (6)                                            /**< (TWI_SMR) Clock Wait State Disable Position */
#define TWI_SMR_SCLWSDIS_Msk                  (0x1U << TWI_SMR_SCLWSDIS_Pos)                 /**< (TWI_SMR) Clock Wait State Disable Mask */
#define TWI_SMR_MASK_Pos                      (8)                                            /**< (TWI_SMR) Slave Address Mask Position */
#define TWI_SMR_MASK_Msk                      (0x7FU << TWI_SMR_MASK_Pos)                    /**< (TWI_SMR) Slave Address Mask Mask */
#define TWI_SMR_MASK(value)                   (TWI_SMR_MASK_Msk & ((value) << TWI_SMR_MASK_Pos))
#define TWI_SMR_SADR_Pos                      (16)                                           /**< (TWI_SMR) Slave Address Position */
#define TWI_SMR_SADR_Msk                      (0x7FU << TWI_SMR_SADR_Pos)                    /**< (TWI_SMR) Slave Address Mask */
#define TWI_SMR_SADR(value)                   (TWI_SMR_SADR_Msk & ((value) << TWI_SMR_SADR_Pos))
#define TWI_SMR_SADR1EN_Pos                   (28)                                           /**< (TWI_SMR) Slave Address 1 Enable Position */
#define TWI_SMR_SADR1EN_Msk                   (0x1U << TWI_SMR_SADR1EN_Pos)                  /**< (TWI_SMR) Slave Address 1 Enable Mask */
#define TWI_SMR_SADR2EN_Pos                   (29)                                           /**< (TWI_SMR) Slave Address 2 Enable Position */
#define TWI_SMR_SADR2EN_Msk                   (0x1U << TWI_SMR_SADR2EN_Pos)                  /**< (TWI_SMR) Slave Address 2 Enable Mask */
#define TWI_SMR_SADR3EN_Pos                   (30)                                           /**< (TWI_SMR) Slave Address 3 Enable Position */
#define TWI_SMR_SADR3EN_Msk                   (0x1U << TWI_SMR_SADR3EN_Pos)                  /**< (TWI_SMR) Slave Address 3 Enable Mask */
#define TWI_SMR_DATAMEN_Pos                   (31)                                           /**< (TWI_SMR) Data Matching Enable Position */
#define TWI_SMR_DATAMEN_Msk                   (0x1U << TWI_SMR_DATAMEN_Pos)                  /**< (TWI_SMR) Data Matching Enable Mask */
#define TWI_SMR_Msk                           (0xF07F7F4DUL)                                 /**< (TWI_SMR) Register Mask  */

/* -------- TWI_IADR : (TWI Offset: 0x0c) (R/W 32) Internal Address Register -------- */

typedef union
{
  struct
  {
    uint32_t IADR:24;                   /**< bit:  0..23  Internal Address                              */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_IADR_bits_t;

#define TWI_IADR_IADR_Pos                     (0)                                            /**< (TWI_IADR) Internal Address Position */
#define TWI_IADR_IADR_Msk                     (0xFFFFFFU << TWI_IADR_IADR_Pos)               /**< (TWI_IADR) Internal Address Mask */
#define TWI_IADR_IADR(value)                  (TWI_IADR_IADR_Msk & ((value) << TWI_IADR_IADR_Pos))
#define TWI_IADR_Msk                          (0x00FFFFFFUL)                                 /**< (TWI_IADR) Register Mask  */

/* -------- TWI_CWGR : (TWI Offset: 0x10) (R/W 32) Clock Waveform Generator Register -------- */

typedef union
{
  struct
  {
    uint32_t CLDIV:8;                   /**< bit:   0..7  Clock Low Divider                             */
    uint32_t CHDIV:8;                   /**< bit:  8..15  Clock High Divider                            */
    uint32_t CKDIV:3;                   /**< bit: 16..18  Clock Divider                                 */
    uint32_t :5;                        /**< bit: 19..23  Reserved                                      */
    uint32_t HOLD:6;                    /**< bit: 24..29  TWD Hold Time Versus TWCK Falling             */
    uint32_t :2;                        /**< bit: 30..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_CWGR_bits_t;

#define TWI_CWGR_CLDIV_Pos                    (0)                                            /**< (TWI_CWGR) Clock Low Divider Position */
#define TWI_CWGR_CLDIV_Msk                    (0xFFU << TWI_CWGR_CLDIV_Pos)                  /**< (TWI_CWGR) Clock Low Divider Mask */
#define TWI_CWGR_CLDIV(value)                 (TWI_CWGR_CLDIV_Msk & ((value) << TWI_CWGR_CLDIV_Pos))
#define TWI_CWGR_CHDIV_Pos                    (8)                                            /**< (TWI_CWGR) Clock High Divider Position */
#define TWI_CWGR_CHDIV_Msk                    (0xFFU << TWI_CWGR_CHDIV_Pos)                  /**< (TWI_CWGR) Clock High Divider Mask */
#define TWI_CWGR_CHDIV(value)                 (TWI_CWGR_CHDIV_Msk & ((value) << TWI_CWGR_CHDIV_Pos))
#define TWI_CWGR_CKDIV_Pos                    (16)                                           /**< (TWI_CWGR) Clock Divider Position */
#define TWI_CWGR_CKDIV_Msk                    (0x7U << TWI_CWGR_CKDIV_Pos)                   /**< (TWI_CWGR) Clock Divider Mask */
#define TWI_CWGR_CKDIV(value)                 (TWI_CWGR_CKDIV_Msk & ((value) << TWI_CWGR_CKDIV_Pos))
#define TWI_CWGR_HOLD_Pos                     (24)                                           /**< (TWI_CWGR) TWD Hold Time Versus TWCK Falling Position */
#define TWI_CWGR_HOLD_Msk                     (0x3FU << TWI_CWGR_HOLD_Pos)                   /**< (TWI_CWGR) TWD Hold Time Versus TWCK Falling Mask */
#define TWI_CWGR_HOLD(value)                  (TWI_CWGR_HOLD_Msk & ((value) << TWI_CWGR_HOLD_Pos))
#define TWI_CWGR_Msk                          (0x3F07FFFFUL)                                 /**< (TWI_CWGR) Register Mask  */

/* -------- TWI_SR : (TWI Offset: 0x20) (R/ 32) Status Register -------- */

typedef union
{
  struct
  {
    uint32_t TXCOMP:1;                  /**< bit:      0  Transmission Completed (cleared by writing TWI_THR) */
    uint32_t RXRDY:1;                   /**< bit:      1  Receive Holding Register Ready (cleared by reading TWI_RHR) */
    uint32_t TXRDY:1;                   /**< bit:      2  Transmit Holding Register Ready (cleared by writing TWI_THR) */
    uint32_t SVREAD:1;                  /**< bit:      3  Slave Read                                    */
    uint32_t SVACC:1;                   /**< bit:      4  Slave Access                                  */
    uint32_t GACC:1;                    /**< bit:      5  General Call Access (cleared on read)         */
    uint32_t OVRE:1;                    /**< bit:      6  Overrun Error (cleared on read)               */
    uint32_t UNRE:1;                    /**< bit:      7  Underrun Error (cleared on read)              */
    uint32_t NACK:1;                    /**< bit:      8  Not Acknowledged (cleared on read)            */
    uint32_t ARBLST:1;                  /**< bit:      9  Arbitration Lost (cleared on read)            */
    uint32_t SCLWS:1;                   /**< bit:     10  Clock Wait State                              */
    uint32_t EOSACC:1;                  /**< bit:     11  End Of Slave Access (cleared on read)         */
    uint32_t :4;                        /**< bit: 12..15  Reserved                                      */
    uint32_t MCACK:1;                   /**< bit:     16  Master Code Acknowledge (cleared on read)     */
    uint32_t :1;                        /**< bit:     17  Reserved                                      */
    uint32_t TOUT:1;                    /**< bit:     18  Timeout Error (cleared on read)               */
    uint32_t PECERR:1;                  /**< bit:     19  PEC Error (cleared on read)                   */
    uint32_t SMBDAM:1;                  /**< bit:     20  SMBus Default Address Match (cleared on read) */
    uint32_t SMBHHM:1;                  /**< bit:     21  SMBus Host Header Address Match (cleared on read) */
    uint32_t :2;                        /**< bit: 22..23  Reserved                                      */
    uint32_t SCL:1;                     /**< bit:     24  SCL Line Value                                */
    uint32_t SDA:1;                     /**< bit:     25  SDA Line Value                                */
    uint32_t :6;                        /**< bit: 26..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_SR_bits_t;

#define TWI_SR_TXCOMP_Pos                     (0)                                            /**< (TWI_SR) Transmission Completed (cleared by writing TWI_THR) Position */
#define TWI_SR_TXCOMP_Msk                     (0x1U << TWI_SR_TXCOMP_Pos)                    /**< (TWI_SR) Transmission Completed (cleared by writing TWI_THR) Mask */
#define TWI_SR_RXRDY_Pos                      (1)                                            /**< (TWI_SR) Receive Holding Register Ready (cleared by reading TWI_RHR) Position */
#define TWI_SR_RXRDY_Msk                      (0x1U << TWI_SR_RXRDY_Pos)                     /**< (TWI_SR) Receive Holding Register Ready (cleared by reading TWI_RHR) Mask */
#define TWI_SR_TXRDY_Pos                      (2)                                            /**< (TWI_SR) Transmit Holding Register Ready (cleared by writing TWI_THR) Position */
#define TWI_SR_TXRDY_Msk                      (0x1U << TWI_SR_TXRDY_Pos)                     /**< (TWI_SR) Transmit Holding Register Ready (cleared by writing TWI_THR) Mask */
#define TWI_SR_SVREAD_Pos                     (3)                                            /**< (TWI_SR) Slave Read Position */
#define TWI_SR_SVREAD_Msk                     (0x1U << TWI_SR_SVREAD_Pos)                    /**< (TWI_SR) Slave Read Mask */
#define TWI_SR_SVACC_Pos                      (4)                                            /**< (TWI_SR) Slave Access Position */
#define TWI_SR_SVACC_Msk                      (0x1U << TWI_SR_SVACC_Pos)                     /**< (TWI_SR) Slave Access Mask */
#define TWI_SR_GACC_Pos                       (5)                                            /**< (TWI_SR) General Call Access (cleared on read) Position */
#define TWI_SR_GACC_Msk                       (0x1U << TWI_SR_GACC_Pos)                      /**< (TWI_SR) General Call Access (cleared on read) Mask */
#define TWI_SR_OVRE_Pos                       (6)                                            /**< (TWI_SR) Overrun Error (cleared on read) Position */
#define TWI_SR_OVRE_Msk                       (0x1U << TWI_SR_OVRE_Pos)                      /**< (TWI_SR) Overrun Error (cleared on read) Mask */
#define TWI_SR_UNRE_Pos                       (7)                                            /**< (TWI_SR) Underrun Error (cleared on read) Position */
#define TWI_SR_UNRE_Msk                       (0x1U << TWI_SR_UNRE_Pos)                      /**< (TWI_SR) Underrun Error (cleared on read) Mask */
#define TWI_SR_NACK_Pos                       (8)                                            /**< (TWI_SR) Not Acknowledged (cleared on read) Position */
#define TWI_SR_NACK_Msk                       (0x1U << TWI_SR_NACK_Pos)                      /**< (TWI_SR) Not Acknowledged (cleared on read) Mask */
#define TWI_SR_ARBLST_Pos                     (9)                                            /**< (TWI_SR) Arbitration Lost (cleared on read) Position */
#define TWI_SR_ARBLST_Msk                     (0x1U << TWI_SR_ARBLST_Pos)                    /**< (TWI_SR) Arbitration Lost (cleared on read) Mask */
#define TWI_SR_SCLWS_Pos                      (10)                                           /**< (TWI_SR) Clock Wait State Position */
#define TWI_SR_SCLWS_Msk                      (0x1U << TWI_SR_SCLWS_Pos)                     /**< (TWI_SR) Clock Wait State Mask */
#define TWI_SR_EOSACC_Pos                     (11)                                           /**< (TWI_SR) End Of Slave Access (cleared on read) Position */
#define TWI_SR_EOSACC_Msk                     (0x1U << TWI_SR_EOSACC_Pos)                    /**< (TWI_SR) End Of Slave Access (cleared on read) Mask */
#define TWI_SR_MCACK_Pos                      (16)                                           /**< (TWI_SR) Master Code Acknowledge (cleared on read) Position */
#define TWI_SR_MCACK_Msk                      (0x1U << TWI_SR_MCACK_Pos)                     /**< (TWI_SR) Master Code Acknowledge (cleared on read) Mask */
#define TWI_SR_TOUT_Pos                       (18)                                           /**< (TWI_SR) Timeout Error (cleared on read) Position */
#define TWI_SR_TOUT_Msk                       (0x1U << TWI_SR_TOUT_Pos)                      /**< (TWI_SR) Timeout Error (cleared on read) Mask */
#define TWI_SR_PECERR_Pos                     (19)                                           /**< (TWI_SR) PEC Error (cleared on read) Position */
#define TWI_SR_PECERR_Msk                     (0x1U << TWI_SR_PECERR_Pos)                    /**< (TWI_SR) PEC Error (cleared on read) Mask */
#define TWI_SR_SMBDAM_Pos                     (20)                                           /**< (TWI_SR) SMBus Default Address Match (cleared on read) Position */
#define TWI_SR_SMBDAM_Msk                     (0x1U << TWI_SR_SMBDAM_Pos)                    /**< (TWI_SR) SMBus Default Address Match (cleared on read) Mask */
#define TWI_SR_SMBHHM_Pos                     (21)                                           /**< (TWI_SR) SMBus Host Header Address Match (cleared on read) Position */
#define TWI_SR_SMBHHM_Msk                     (0x1U << TWI_SR_SMBHHM_Pos)                    /**< (TWI_SR) SMBus Host Header Address Match (cleared on read) Mask */
#define TWI_SR_SCL_Pos                        (24)                                           /**< (TWI_SR) SCL Line Value Position */
#define TWI_SR_SCL_Msk                        (0x1U << TWI_SR_SCL_Pos)                       /**< (TWI_SR) SCL Line Value Mask */
#define TWI_SR_SDA_Pos                        (25)                                           /**< (TWI_SR) SDA Line Value Position */
#define TWI_SR_SDA_Msk                        (0x1U << TWI_SR_SDA_Pos)                       /**< (TWI_SR) SDA Line Value Mask */
#define TWI_SR_Msk                            (0x033D0FFFUL)                                 /**< (TWI_SR) Register Mask  */

/* -------- TWI_IER : (TWI Offset: 0x24) (/W 32) Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t TXCOMP:1;                  /**< bit:      0  Transmission Completed Interrupt Enable       */
    uint32_t RXRDY:1;                   /**< bit:      1  Receive Holding Register Ready Interrupt Enable */
    uint32_t TXRDY:1;                   /**< bit:      2  Transmit Holding Register Ready Interrupt Enable */
    uint32_t :1;                        /**< bit:      3  Reserved                                      */
    uint32_t SVACC:1;                   /**< bit:      4  Slave Access Interrupt Enable                 */
    uint32_t GACC:1;                    /**< bit:      5  General Call Access Interrupt Enable          */
    uint32_t OVRE:1;                    /**< bit:      6  Overrun Error Interrupt Enable                */
    uint32_t UNRE:1;                    /**< bit:      7  Underrun Error Interrupt Enable               */
    uint32_t NACK:1;                    /**< bit:      8  Not Acknowledge Interrupt Enable              */
    uint32_t ARBLST:1;                  /**< bit:      9  Arbitration Lost Interrupt Enable             */
    uint32_t SCL_WS:1;                  /**< bit:     10  Clock Wait State Interrupt Enable             */
    uint32_t EOSACC:1;                  /**< bit:     11  End Of Slave Access Interrupt Enable          */
    uint32_t :4;                        /**< bit: 12..15  Reserved                                      */
    uint32_t MCACK:1;                   /**< bit:     16  Master Code Acknowledge Interrupt Enable      */
    uint32_t :1;                        /**< bit:     17  Reserved                                      */
    uint32_t TOUT:1;                    /**< bit:     18  Timeout Error Interrupt Enable                */
    uint32_t PECERR:1;                  /**< bit:     19  PEC Error Interrupt Enable                    */
    uint32_t SMBDAM:1;                  /**< bit:     20  SMBus Default Address Match Interrupt Enable  */
    uint32_t SMBHHM:1;                  /**< bit:     21  SMBus Host Header Address Match Interrupt Enable */
    uint32_t :10;                       /**< bit: 22..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_IER_bits_t;

#define TWI_IER_TXCOMP_Pos                    (0)                                            /**< (TWI_IER) Transmission Completed Interrupt Enable Position */
#define TWI_IER_TXCOMP_Msk                    (0x1U << TWI_IER_TXCOMP_Pos)                   /**< (TWI_IER) Transmission Completed Interrupt Enable Mask */
#define TWI_IER_RXRDY_Pos                     (1)                                            /**< (TWI_IER) Receive Holding Register Ready Interrupt Enable Position */
#define TWI_IER_RXRDY_Msk                     (0x1U << TWI_IER_RXRDY_Pos)                    /**< (TWI_IER) Receive Holding Register Ready Interrupt Enable Mask */
#define TWI_IER_TXRDY_Pos                     (2)                                            /**< (TWI_IER) Transmit Holding Register Ready Interrupt Enable Position */
#define TWI_IER_TXRDY_Msk                     (0x1U << TWI_IER_TXRDY_Pos)                    /**< (TWI_IER) Transmit Holding Register Ready Interrupt Enable Mask */
#define TWI_IER_SVACC_Pos                     (4)                                            /**< (TWI_IER) Slave Access Interrupt Enable Position */
#define TWI_IER_SVACC_Msk                     (0x1U << TWI_IER_SVACC_Pos)                    /**< (TWI_IER) Slave Access Interrupt Enable Mask */
#define TWI_IER_GACC_Pos                      (5)                                            /**< (TWI_IER) General Call Access Interrupt Enable Position */
#define TWI_IER_GACC_Msk                      (0x1U << TWI_IER_GACC_Pos)                     /**< (TWI_IER) General Call Access Interrupt Enable Mask */
#define TWI_IER_OVRE_Pos                      (6)                                            /**< (TWI_IER) Overrun Error Interrupt Enable Position */
#define TWI_IER_OVRE_Msk                      (0x1U << TWI_IER_OVRE_Pos)                     /**< (TWI_IER) Overrun Error Interrupt Enable Mask */
#define TWI_IER_UNRE_Pos                      (7)                                            /**< (TWI_IER) Underrun Error Interrupt Enable Position */
#define TWI_IER_UNRE_Msk                      (0x1U << TWI_IER_UNRE_Pos)                     /**< (TWI_IER) Underrun Error Interrupt Enable Mask */
#define TWI_IER_NACK_Pos                      (8)                                            /**< (TWI_IER) Not Acknowledge Interrupt Enable Position */
#define TWI_IER_NACK_Msk                      (0x1U << TWI_IER_NACK_Pos)                     /**< (TWI_IER) Not Acknowledge Interrupt Enable Mask */
#define TWI_IER_ARBLST_Pos                    (9)                                            /**< (TWI_IER) Arbitration Lost Interrupt Enable Position */
#define TWI_IER_ARBLST_Msk                    (0x1U << TWI_IER_ARBLST_Pos)                   /**< (TWI_IER) Arbitration Lost Interrupt Enable Mask */
#define TWI_IER_SCL_WS_Pos                    (10)                                           /**< (TWI_IER) Clock Wait State Interrupt Enable Position */
#define TWI_IER_SCL_WS_Msk                    (0x1U << TWI_IER_SCL_WS_Pos)                   /**< (TWI_IER) Clock Wait State Interrupt Enable Mask */
#define TWI_IER_EOSACC_Pos                    (11)                                           /**< (TWI_IER) End Of Slave Access Interrupt Enable Position */
#define TWI_IER_EOSACC_Msk                    (0x1U << TWI_IER_EOSACC_Pos)                   /**< (TWI_IER) End Of Slave Access Interrupt Enable Mask */
#define TWI_IER_MCACK_Pos                     (16)                                           /**< (TWI_IER) Master Code Acknowledge Interrupt Enable Position */
#define TWI_IER_MCACK_Msk                     (0x1U << TWI_IER_MCACK_Pos)                    /**< (TWI_IER) Master Code Acknowledge Interrupt Enable Mask */
#define TWI_IER_TOUT_Pos                      (18)                                           /**< (TWI_IER) Timeout Error Interrupt Enable Position */
#define TWI_IER_TOUT_Msk                      (0x1U << TWI_IER_TOUT_Pos)                     /**< (TWI_IER) Timeout Error Interrupt Enable Mask */
#define TWI_IER_PECERR_Pos                    (19)                                           /**< (TWI_IER) PEC Error Interrupt Enable Position */
#define TWI_IER_PECERR_Msk                    (0x1U << TWI_IER_PECERR_Pos)                   /**< (TWI_IER) PEC Error Interrupt Enable Mask */
#define TWI_IER_SMBDAM_Pos                    (20)                                           /**< (TWI_IER) SMBus Default Address Match Interrupt Enable Position */
#define TWI_IER_SMBDAM_Msk                    (0x1U << TWI_IER_SMBDAM_Pos)                   /**< (TWI_IER) SMBus Default Address Match Interrupt Enable Mask */
#define TWI_IER_SMBHHM_Pos                    (21)                                           /**< (TWI_IER) SMBus Host Header Address Match Interrupt Enable Position */
#define TWI_IER_SMBHHM_Msk                    (0x1U << TWI_IER_SMBHHM_Pos)                   /**< (TWI_IER) SMBus Host Header Address Match Interrupt Enable Mask */
#define TWI_IER_Msk                           (0x003D0FF7UL)                                 /**< (TWI_IER) Register Mask  */

/* -------- TWI_IDR : (TWI Offset: 0x28) (/W 32) Interrupt Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t TXCOMP:1;                  /**< bit:      0  Transmission Completed Interrupt Disable      */
    uint32_t RXRDY:1;                   /**< bit:      1  Receive Holding Register Ready Interrupt Disable */
    uint32_t TXRDY:1;                   /**< bit:      2  Transmit Holding Register Ready Interrupt Disable */
    uint32_t :1;                        /**< bit:      3  Reserved                                      */
    uint32_t SVACC:1;                   /**< bit:      4  Slave Access Interrupt Disable                */
    uint32_t GACC:1;                    /**< bit:      5  General Call Access Interrupt Disable         */
    uint32_t OVRE:1;                    /**< bit:      6  Overrun Error Interrupt Disable               */
    uint32_t UNRE:1;                    /**< bit:      7  Underrun Error Interrupt Disable              */
    uint32_t NACK:1;                    /**< bit:      8  Not Acknowledge Interrupt Disable             */
    uint32_t ARBLST:1;                  /**< bit:      9  Arbitration Lost Interrupt Disable            */
    uint32_t SCL_WS:1;                  /**< bit:     10  Clock Wait State Interrupt Disable            */
    uint32_t EOSACC:1;                  /**< bit:     11  End Of Slave Access Interrupt Disable         */
    uint32_t :4;                        /**< bit: 12..15  Reserved                                      */
    uint32_t MCACK:1;                   /**< bit:     16  Master Code Acknowledge Interrupt Disable     */
    uint32_t :1;                        /**< bit:     17  Reserved                                      */
    uint32_t TOUT:1;                    /**< bit:     18  Timeout Error Interrupt Disable               */
    uint32_t PECERR:1;                  /**< bit:     19  PEC Error Interrupt Disable                   */
    uint32_t SMBDAM:1;                  /**< bit:     20  SMBus Default Address Match Interrupt Disable */
    uint32_t SMBHHM:1;                  /**< bit:     21  SMBus Host Header Address Match Interrupt Disable */
    uint32_t :10;                       /**< bit: 22..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_IDR_bits_t;

#define TWI_IDR_TXCOMP_Pos                    (0)                                            /**< (TWI_IDR) Transmission Completed Interrupt Disable Position */
#define TWI_IDR_TXCOMP_Msk                    (0x1U << TWI_IDR_TXCOMP_Pos)                   /**< (TWI_IDR) Transmission Completed Interrupt Disable Mask */
#define TWI_IDR_RXRDY_Pos                     (1)                                            /**< (TWI_IDR) Receive Holding Register Ready Interrupt Disable Position */
#define TWI_IDR_RXRDY_Msk                     (0x1U << TWI_IDR_RXRDY_Pos)                    /**< (TWI_IDR) Receive Holding Register Ready Interrupt Disable Mask */
#define TWI_IDR_TXRDY_Pos                     (2)                                            /**< (TWI_IDR) Transmit Holding Register Ready Interrupt Disable Position */
#define TWI_IDR_TXRDY_Msk                     (0x1U << TWI_IDR_TXRDY_Pos)                    /**< (TWI_IDR) Transmit Holding Register Ready Interrupt Disable Mask */
#define TWI_IDR_SVACC_Pos                     (4)                                            /**< (TWI_IDR) Slave Access Interrupt Disable Position */
#define TWI_IDR_SVACC_Msk                     (0x1U << TWI_IDR_SVACC_Pos)                    /**< (TWI_IDR) Slave Access Interrupt Disable Mask */
#define TWI_IDR_GACC_Pos                      (5)                                            /**< (TWI_IDR) General Call Access Interrupt Disable Position */
#define TWI_IDR_GACC_Msk                      (0x1U << TWI_IDR_GACC_Pos)                     /**< (TWI_IDR) General Call Access Interrupt Disable Mask */
#define TWI_IDR_OVRE_Pos                      (6)                                            /**< (TWI_IDR) Overrun Error Interrupt Disable Position */
#define TWI_IDR_OVRE_Msk                      (0x1U << TWI_IDR_OVRE_Pos)                     /**< (TWI_IDR) Overrun Error Interrupt Disable Mask */
#define TWI_IDR_UNRE_Pos                      (7)                                            /**< (TWI_IDR) Underrun Error Interrupt Disable Position */
#define TWI_IDR_UNRE_Msk                      (0x1U << TWI_IDR_UNRE_Pos)                     /**< (TWI_IDR) Underrun Error Interrupt Disable Mask */
#define TWI_IDR_NACK_Pos                      (8)                                            /**< (TWI_IDR) Not Acknowledge Interrupt Disable Position */
#define TWI_IDR_NACK_Msk                      (0x1U << TWI_IDR_NACK_Pos)                     /**< (TWI_IDR) Not Acknowledge Interrupt Disable Mask */
#define TWI_IDR_ARBLST_Pos                    (9)                                            /**< (TWI_IDR) Arbitration Lost Interrupt Disable Position */
#define TWI_IDR_ARBLST_Msk                    (0x1U << TWI_IDR_ARBLST_Pos)                   /**< (TWI_IDR) Arbitration Lost Interrupt Disable Mask */
#define TWI_IDR_SCL_WS_Pos                    (10)                                           /**< (TWI_IDR) Clock Wait State Interrupt Disable Position */
#define TWI_IDR_SCL_WS_Msk                    (0x1U << TWI_IDR_SCL_WS_Pos)                   /**< (TWI_IDR) Clock Wait State Interrupt Disable Mask */
#define TWI_IDR_EOSACC_Pos                    (11)                                           /**< (TWI_IDR) End Of Slave Access Interrupt Disable Position */
#define TWI_IDR_EOSACC_Msk                    (0x1U << TWI_IDR_EOSACC_Pos)                   /**< (TWI_IDR) End Of Slave Access Interrupt Disable Mask */
#define TWI_IDR_MCACK_Pos                     (16)                                           /**< (TWI_IDR) Master Code Acknowledge Interrupt Disable Position */
#define TWI_IDR_MCACK_Msk                     (0x1U << TWI_IDR_MCACK_Pos)                    /**< (TWI_IDR) Master Code Acknowledge Interrupt Disable Mask */
#define TWI_IDR_TOUT_Pos                      (18)                                           /**< (TWI_IDR) Timeout Error Interrupt Disable Position */
#define TWI_IDR_TOUT_Msk                      (0x1U << TWI_IDR_TOUT_Pos)                     /**< (TWI_IDR) Timeout Error Interrupt Disable Mask */
#define TWI_IDR_PECERR_Pos                    (19)                                           /**< (TWI_IDR) PEC Error Interrupt Disable Position */
#define TWI_IDR_PECERR_Msk                    (0x1U << TWI_IDR_PECERR_Pos)                   /**< (TWI_IDR) PEC Error Interrupt Disable Mask */
#define TWI_IDR_SMBDAM_Pos                    (20)                                           /**< (TWI_IDR) SMBus Default Address Match Interrupt Disable Position */
#define TWI_IDR_SMBDAM_Msk                    (0x1U << TWI_IDR_SMBDAM_Pos)                   /**< (TWI_IDR) SMBus Default Address Match Interrupt Disable Mask */
#define TWI_IDR_SMBHHM_Pos                    (21)                                           /**< (TWI_IDR) SMBus Host Header Address Match Interrupt Disable Position */
#define TWI_IDR_SMBHHM_Msk                    (0x1U << TWI_IDR_SMBHHM_Pos)                   /**< (TWI_IDR) SMBus Host Header Address Match Interrupt Disable Mask */
#define TWI_IDR_Msk                           (0x003D0FF7UL)                                 /**< (TWI_IDR) Register Mask  */

/* -------- TWI_IMR : (TWI Offset: 0x2c) (R/ 32) Interrupt Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t TXCOMP:1;                  /**< bit:      0  Transmission Completed Interrupt Mask         */
    uint32_t RXRDY:1;                   /**< bit:      1  Receive Holding Register Ready Interrupt Mask */
    uint32_t TXRDY:1;                   /**< bit:      2  Transmit Holding Register Ready Interrupt Mask */
    uint32_t :1;                        /**< bit:      3  Reserved                                      */
    uint32_t SVACC:1;                   /**< bit:      4  Slave Access Interrupt Mask                   */
    uint32_t GACC:1;                    /**< bit:      5  General Call Access Interrupt Mask            */
    uint32_t OVRE:1;                    /**< bit:      6  Overrun Error Interrupt Mask                  */
    uint32_t UNRE:1;                    /**< bit:      7  Underrun Error Interrupt Mask                 */
    uint32_t NACK:1;                    /**< bit:      8  Not Acknowledge Interrupt Mask                */
    uint32_t ARBLST:1;                  /**< bit:      9  Arbitration Lost Interrupt Mask               */
    uint32_t SCL_WS:1;                  /**< bit:     10  Clock Wait State Interrupt Mask               */
    uint32_t EOSACC:1;                  /**< bit:     11  End Of Slave Access Interrupt Mask            */
    uint32_t :4;                        /**< bit: 12..15  Reserved                                      */
    uint32_t MCACK:1;                   /**< bit:     16  Master Code Acknowledge Interrupt Mask        */
    uint32_t :1;                        /**< bit:     17  Reserved                                      */
    uint32_t TOUT:1;                    /**< bit:     18  Timeout Error Interrupt Mask                  */
    uint32_t PECERR:1;                  /**< bit:     19  PEC Error Interrupt Mask                      */
    uint32_t SMBDAM:1;                  /**< bit:     20  SMBus Default Address Match Interrupt Mask    */
    uint32_t SMBHHM:1;                  /**< bit:     21  SMBus Host Header Address Match Interrupt Mask */
    uint32_t :10;                       /**< bit: 22..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_IMR_bits_t;

#define TWI_IMR_TXCOMP_Pos                    (0)                                            /**< (TWI_IMR) Transmission Completed Interrupt Mask Position */
#define TWI_IMR_TXCOMP_Msk                    (0x1U << TWI_IMR_TXCOMP_Pos)                   /**< (TWI_IMR) Transmission Completed Interrupt Mask Mask */
#define TWI_IMR_RXRDY_Pos                     (1)                                            /**< (TWI_IMR) Receive Holding Register Ready Interrupt Mask Position */
#define TWI_IMR_RXRDY_Msk                     (0x1U << TWI_IMR_RXRDY_Pos)                    /**< (TWI_IMR) Receive Holding Register Ready Interrupt Mask Mask */
#define TWI_IMR_TXRDY_Pos                     (2)                                            /**< (TWI_IMR) Transmit Holding Register Ready Interrupt Mask Position */
#define TWI_IMR_TXRDY_Msk                     (0x1U << TWI_IMR_TXRDY_Pos)                    /**< (TWI_IMR) Transmit Holding Register Ready Interrupt Mask Mask */
#define TWI_IMR_SVACC_Pos                     (4)                                            /**< (TWI_IMR) Slave Access Interrupt Mask Position */
#define TWI_IMR_SVACC_Msk                     (0x1U << TWI_IMR_SVACC_Pos)                    /**< (TWI_IMR) Slave Access Interrupt Mask Mask */
#define TWI_IMR_GACC_Pos                      (5)                                            /**< (TWI_IMR) General Call Access Interrupt Mask Position */
#define TWI_IMR_GACC_Msk                      (0x1U << TWI_IMR_GACC_Pos)                     /**< (TWI_IMR) General Call Access Interrupt Mask Mask */
#define TWI_IMR_OVRE_Pos                      (6)                                            /**< (TWI_IMR) Overrun Error Interrupt Mask Position */
#define TWI_IMR_OVRE_Msk                      (0x1U << TWI_IMR_OVRE_Pos)                     /**< (TWI_IMR) Overrun Error Interrupt Mask Mask */
#define TWI_IMR_UNRE_Pos                      (7)                                            /**< (TWI_IMR) Underrun Error Interrupt Mask Position */
#define TWI_IMR_UNRE_Msk                      (0x1U << TWI_IMR_UNRE_Pos)                     /**< (TWI_IMR) Underrun Error Interrupt Mask Mask */
#define TWI_IMR_NACK_Pos                      (8)                                            /**< (TWI_IMR) Not Acknowledge Interrupt Mask Position */
#define TWI_IMR_NACK_Msk                      (0x1U << TWI_IMR_NACK_Pos)                     /**< (TWI_IMR) Not Acknowledge Interrupt Mask Mask */
#define TWI_IMR_ARBLST_Pos                    (9)                                            /**< (TWI_IMR) Arbitration Lost Interrupt Mask Position */
#define TWI_IMR_ARBLST_Msk                    (0x1U << TWI_IMR_ARBLST_Pos)                   /**< (TWI_IMR) Arbitration Lost Interrupt Mask Mask */
#define TWI_IMR_SCL_WS_Pos                    (10)                                           /**< (TWI_IMR) Clock Wait State Interrupt Mask Position */
#define TWI_IMR_SCL_WS_Msk                    (0x1U << TWI_IMR_SCL_WS_Pos)                   /**< (TWI_IMR) Clock Wait State Interrupt Mask Mask */
#define TWI_IMR_EOSACC_Pos                    (11)                                           /**< (TWI_IMR) End Of Slave Access Interrupt Mask Position */
#define TWI_IMR_EOSACC_Msk                    (0x1U << TWI_IMR_EOSACC_Pos)                   /**< (TWI_IMR) End Of Slave Access Interrupt Mask Mask */
#define TWI_IMR_MCACK_Pos                     (16)                                           /**< (TWI_IMR) Master Code Acknowledge Interrupt Mask Position */
#define TWI_IMR_MCACK_Msk                     (0x1U << TWI_IMR_MCACK_Pos)                    /**< (TWI_IMR) Master Code Acknowledge Interrupt Mask Mask */
#define TWI_IMR_TOUT_Pos                      (18)                                           /**< (TWI_IMR) Timeout Error Interrupt Mask Position */
#define TWI_IMR_TOUT_Msk                      (0x1U << TWI_IMR_TOUT_Pos)                     /**< (TWI_IMR) Timeout Error Interrupt Mask Mask */
#define TWI_IMR_PECERR_Pos                    (19)                                           /**< (TWI_IMR) PEC Error Interrupt Mask Position */
#define TWI_IMR_PECERR_Msk                    (0x1U << TWI_IMR_PECERR_Pos)                   /**< (TWI_IMR) PEC Error Interrupt Mask Mask */
#define TWI_IMR_SMBDAM_Pos                    (20)                                           /**< (TWI_IMR) SMBus Default Address Match Interrupt Mask Position */
#define TWI_IMR_SMBDAM_Msk                    (0x1U << TWI_IMR_SMBDAM_Pos)                   /**< (TWI_IMR) SMBus Default Address Match Interrupt Mask Mask */
#define TWI_IMR_SMBHHM_Pos                    (21)                                           /**< (TWI_IMR) SMBus Host Header Address Match Interrupt Mask Position */
#define TWI_IMR_SMBHHM_Msk                    (0x1U << TWI_IMR_SMBHHM_Pos)                   /**< (TWI_IMR) SMBus Host Header Address Match Interrupt Mask Mask */
#define TWI_IMR_Msk                           (0x003D0FF7UL)                                 /**< (TWI_IMR) Register Mask  */

/* -------- TWI_RHR : (TWI Offset: 0x30) (R/ 32) Receive Holding Register -------- */

typedef union
{
  struct
  {
    uint32_t RXDATA:8;                  /**< bit:   0..7  Master or Slave Receive Holding Data          */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_RHR_bits_t;

#define TWI_RHR_RXDATA_Pos                    (0)                                            /**< (TWI_RHR) Master or Slave Receive Holding Data Position */
#define TWI_RHR_RXDATA_Msk                    (0xFFU << TWI_RHR_RXDATA_Pos)                  /**< (TWI_RHR) Master or Slave Receive Holding Data Mask */
#define TWI_RHR_RXDATA(value)                 (TWI_RHR_RXDATA_Msk & ((value) << TWI_RHR_RXDATA_Pos))
#define TWI_RHR_Msk                           (0x000000FFUL)                                 /**< (TWI_RHR) Register Mask  */

/* -------- TWI_THR : (TWI Offset: 0x34) (/W 32) Transmit Holding Register -------- */

typedef union
{
  struct
  {
    uint32_t TXDATA:8;                  /**< bit:   0..7  Master or Slave Transmit Holding Data         */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_THR_bits_t;

#define TWI_THR_TXDATA_Pos                    (0)                                            /**< (TWI_THR) Master or Slave Transmit Holding Data Position */
#define TWI_THR_TXDATA_Msk                    (0xFFU << TWI_THR_TXDATA_Pos)                  /**< (TWI_THR) Master or Slave Transmit Holding Data Mask */
#define TWI_THR_TXDATA(value)                 (TWI_THR_TXDATA_Msk & ((value) << TWI_THR_TXDATA_Pos))
#define TWI_THR_Msk                           (0x000000FFUL)                                 /**< (TWI_THR) Register Mask  */

/* -------- TWI_SMBTR : (TWI Offset: 0x38) (R/W 32) SMBus Timing Register -------- */

typedef union
{
  struct
  {
    uint32_t PRESC:4;                   /**< bit:   0..3  SMBus Clock Prescaler                         */
    uint32_t :4;                        /**< bit:   4..7  Reserved                                      */
    uint32_t TLOWS:8;                   /**< bit:  8..15  Slave Clock Stretch Maximum Cycles            */
    uint32_t TLOWM:8;                   /**< bit: 16..23  Master Clock Stretch Maximum Cycles           */
    uint32_t THMAX:8;                   /**< bit: 24..31  Clock High Maximum Cycles                     */
  };
  uint32_t w;
} __TWI_SMBTR_bits_t;

#define TWI_SMBTR_PRESC_Pos                   (0)                                            /**< (TWI_SMBTR) SMBus Clock Prescaler Position */
#define TWI_SMBTR_PRESC_Msk                   (0xFU << TWI_SMBTR_PRESC_Pos)                  /**< (TWI_SMBTR) SMBus Clock Prescaler Mask */
#define TWI_SMBTR_PRESC(value)                (TWI_SMBTR_PRESC_Msk & ((value) << TWI_SMBTR_PRESC_Pos))
#define TWI_SMBTR_TLOWS_Pos                   (8)                                            /**< (TWI_SMBTR) Slave Clock Stretch Maximum Cycles Position */
#define TWI_SMBTR_TLOWS_Msk                   (0xFFU << TWI_SMBTR_TLOWS_Pos)                 /**< (TWI_SMBTR) Slave Clock Stretch Maximum Cycles Mask */
#define TWI_SMBTR_TLOWS(value)                (TWI_SMBTR_TLOWS_Msk & ((value) << TWI_SMBTR_TLOWS_Pos))
#define TWI_SMBTR_TLOWM_Pos                   (16)                                           /**< (TWI_SMBTR) Master Clock Stretch Maximum Cycles Position */
#define TWI_SMBTR_TLOWM_Msk                   (0xFFU << TWI_SMBTR_TLOWM_Pos)                 /**< (TWI_SMBTR) Master Clock Stretch Maximum Cycles Mask */
#define TWI_SMBTR_TLOWM(value)                (TWI_SMBTR_TLOWM_Msk & ((value) << TWI_SMBTR_TLOWM_Pos))
#define TWI_SMBTR_THMAX_Pos                   (24)                                           /**< (TWI_SMBTR) Clock High Maximum Cycles Position */
#define TWI_SMBTR_THMAX_Msk                   (0xFFU << TWI_SMBTR_THMAX_Pos)                 /**< (TWI_SMBTR) Clock High Maximum Cycles Mask */
#define TWI_SMBTR_THMAX(value)                (TWI_SMBTR_THMAX_Msk & ((value) << TWI_SMBTR_THMAX_Pos))
#define TWI_SMBTR_Msk                         (0xFFFFFF0FUL)                                 /**< (TWI_SMBTR) Register Mask  */

/* -------- TWI_FILTR : (TWI Offset: 0x44) (R/W 32) Filter Register -------- */

typedef union
{
  struct
  {
    uint32_t FILT:1;                    /**< bit:      0  RX Digital Filter                             */
    uint32_t PADFEN:1;                  /**< bit:      1  PAD Filter Enable                             */
    uint32_t PADFCFG:1;                 /**< bit:      2  PAD Filter Config                             */
    uint32_t :5;                        /**< bit:   3..7  Reserved                                      */
    uint32_t THRES:3;                   /**< bit:  8..10  Digital Filter Threshold                      */
    uint32_t :21;                       /**< bit: 11..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_FILTR_bits_t;

#define TWI_FILTR_FILT_Pos                    (0)                                            /**< (TWI_FILTR) RX Digital Filter Position */
#define TWI_FILTR_FILT_Msk                    (0x1U << TWI_FILTR_FILT_Pos)                   /**< (TWI_FILTR) RX Digital Filter Mask */
#define TWI_FILTR_PADFEN_Pos                  (1)                                            /**< (TWI_FILTR) PAD Filter Enable Position */
#define TWI_FILTR_PADFEN_Msk                  (0x1U << TWI_FILTR_PADFEN_Pos)                 /**< (TWI_FILTR) PAD Filter Enable Mask */
#define TWI_FILTR_PADFCFG_Pos                 (2)                                            /**< (TWI_FILTR) PAD Filter Config Position */
#define TWI_FILTR_PADFCFG_Msk                 (0x1U << TWI_FILTR_PADFCFG_Pos)                /**< (TWI_FILTR) PAD Filter Config Mask */
#define TWI_FILTR_THRES_Pos                   (8)                                            /**< (TWI_FILTR) Digital Filter Threshold Position */
#define TWI_FILTR_THRES_Msk                   (0x7U << TWI_FILTR_THRES_Pos)                  /**< (TWI_FILTR) Digital Filter Threshold Mask */
#define TWI_FILTR_THRES(value)                (TWI_FILTR_THRES_Msk & ((value) << TWI_FILTR_THRES_Pos))
#define TWI_FILTR_Msk                         (0x00000707UL)                                 /**< (TWI_FILTR) Register Mask  */

/* -------- TWI_SWMR : (TWI Offset: 0x4c) (R/W 32) SleepWalking Matching Register -------- */

typedef union
{
  struct
  {
    uint32_t SADR1:7;                   /**< bit:   0..6  Slave Address 1                               */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t SADR2:7;                   /**< bit:  8..14  Slave Address 2                               */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t SADR3:7;                   /**< bit: 16..22  Slave Address 3                               */
    uint32_t :1;                        /**< bit:     23  Reserved                                      */
    uint32_t DATAM:8;                   /**< bit: 24..31  Data Match                                    */
  };
  uint32_t w;
} __TWI_SWMR_bits_t;

#define TWI_SWMR_SADR1_Pos                    (0)                                            /**< (TWI_SWMR) Slave Address 1 Position */
#define TWI_SWMR_SADR1_Msk                    (0x7FU << TWI_SWMR_SADR1_Pos)                  /**< (TWI_SWMR) Slave Address 1 Mask */
#define TWI_SWMR_SADR1(value)                 (TWI_SWMR_SADR1_Msk & ((value) << TWI_SWMR_SADR1_Pos))
#define TWI_SWMR_SADR2_Pos                    (8)                                            /**< (TWI_SWMR) Slave Address 2 Position */
#define TWI_SWMR_SADR2_Msk                    (0x7FU << TWI_SWMR_SADR2_Pos)                  /**< (TWI_SWMR) Slave Address 2 Mask */
#define TWI_SWMR_SADR2(value)                 (TWI_SWMR_SADR2_Msk & ((value) << TWI_SWMR_SADR2_Pos))
#define TWI_SWMR_SADR3_Pos                    (16)                                           /**< (TWI_SWMR) Slave Address 3 Position */
#define TWI_SWMR_SADR3_Msk                    (0x7FU << TWI_SWMR_SADR3_Pos)                  /**< (TWI_SWMR) Slave Address 3 Mask */
#define TWI_SWMR_SADR3(value)                 (TWI_SWMR_SADR3_Msk & ((value) << TWI_SWMR_SADR3_Pos))
#define TWI_SWMR_DATAM_Pos                    (24)                                           /**< (TWI_SWMR) Data Match Position */
#define TWI_SWMR_DATAM_Msk                    (0xFFU << TWI_SWMR_DATAM_Pos)                  /**< (TWI_SWMR) Data Match Mask */
#define TWI_SWMR_DATAM(value)                 (TWI_SWMR_DATAM_Msk & ((value) << TWI_SWMR_DATAM_Pos))
#define TWI_SWMR_Msk                          (0xFF7F7F7FUL)                                 /**< (TWI_SWMR) Register Mask  */

/* -------- TWI_DR : (TWI Offset: 0xd0) (R/ 32) Debug Register -------- */

typedef union
{
  struct
  {
    uint32_t SWEN:1;                    /**< bit:      0  SleepWalking Enable                           */
    uint32_t CLKRQ:1;                   /**< bit:      1  Clock Request                                 */
    uint32_t SWMATCH:1;                 /**< bit:      2  SleepWalking Match                            */
    uint32_t TRP:1;                     /**< bit:      3  Transfer Pending                              */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  uint32_t w;
} __TWI_DR_bits_t;

#define TWI_DR_SWEN_Pos                       (0)                                            /**< (TWI_DR) SleepWalking Enable Position */
#define TWI_DR_SWEN_Msk                       (0x1U << TWI_DR_SWEN_Pos)                      /**< (TWI_DR) SleepWalking Enable Mask */
#define TWI_DR_CLKRQ_Pos                      (1)                                            /**< (TWI_DR) Clock Request Position */
#define TWI_DR_CLKRQ_Msk                      (0x1U << TWI_DR_CLKRQ_Pos)                     /**< (TWI_DR) Clock Request Mask */
#define TWI_DR_SWMATCH_Pos                    (2)                                            /**< (TWI_DR) SleepWalking Match Position */
#define TWI_DR_SWMATCH_Msk                    (0x1U << TWI_DR_SWMATCH_Pos)                   /**< (TWI_DR) SleepWalking Match Mask */
#define TWI_DR_TRP_Pos                        (3)                                            /**< (TWI_DR) Transfer Pending Position */
#define TWI_DR_TRP_Msk                        (0x1U << TWI_DR_TRP_Pos)                       /**< (TWI_DR) Transfer Pending Mask */
#define TWI_DR_Msk                            (0x0000000FUL)                                 /**< (TWI_DR) Register Mask  */

/* -------- TWI_WPMR : (TWI Offset: 0xe4) (R/W 32) Write Protection Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t WPEN:1;                    /**< bit:      0  Write Protection Enable                       */
    uint32_t :7;                        /**< bit:   1..7  Reserved                                      */
    uint32_t WPKEY:24;                  /**< bit:  8..31  Write Protection Key                          */
  };
  uint32_t w;
} __TWI_WPMR_bits_t;

#define TWI_WPMR_WPEN_Pos                     (0)                                            /**< (TWI_WPMR) Write Protection Enable Position */
#define TWI_WPMR_WPEN_Msk                     (0x1U << TWI_WPMR_WPEN_Pos)                    /**< (TWI_WPMR) Write Protection Enable Mask */
#define TWI_WPMR_WPKEY_Pos                    (8)                                            /**< (TWI_WPMR) Write Protection Key Position */
#define TWI_WPMR_WPKEY_Msk                    (0xFFFFFFU << TWI_WPMR_WPKEY_Pos)              /**< (TWI_WPMR) Write Protection Key Mask */
#define TWI_WPMR_WPKEY(value)                 (TWI_WPMR_WPKEY_Msk & ((value) << TWI_WPMR_WPKEY_Pos))
#define   TWI_WPMR_WPKEY_PASSWD_Val           (0x545749U)                                    /**< (TWI_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0  */
#define TWI_WPMR_WPKEY_PASSWD                 (TWI_WPMR_WPKEY_PASSWD_Val << TWI_WPMR_WPKEY_Pos)  /**< (TWI_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0 Position  */
#define TWI_WPMR_Msk                          (0xFFFFFF01UL)                                 /**< (TWI_WPMR) Register Mask  */

/* -------- TWI_WPSR : (TWI Offset: 0xe8) (R/ 32) Write Protection Status Register -------- */

typedef union
{
  struct
  {
    uint32_t WPVS:1;                    /**< bit:      0  Write Protection Violation Status             */
    uint32_t :7;                        /**< bit:   1..7  Reserved                                      */
    uint32_t WPVSRC:24;                 /**< bit:  8..31  Write Protection Violation Source             */
  };
  uint32_t w;
} __TWI_WPSR_bits_t;

#define TWI_WPSR_WPVS_Pos                     (0)                                            /**< (TWI_WPSR) Write Protection Violation Status Position */
#define TWI_WPSR_WPVS_Msk                     (0x1U << TWI_WPSR_WPVS_Pos)                    /**< (TWI_WPSR) Write Protection Violation Status Mask */
#define TWI_WPSR_WPVSRC_Pos                   (8)                                            /**< (TWI_WPSR) Write Protection Violation Source Position */
#define TWI_WPSR_WPVSRC_Msk                   (0xFFFFFFU << TWI_WPSR_WPVSRC_Pos)             /**< (TWI_WPSR) Write Protection Violation Source Mask */
#define TWI_WPSR_WPVSRC(value)                (TWI_WPSR_WPVSRC_Msk & ((value) << TWI_WPSR_WPVSRC_Pos))
#define TWI_WPSR_Msk                          (0xFFFFFF01UL)                                 /**< (TWI_WPSR) Register Mask  */

/** \brief TWI register offsets definitions */
#define TWI_CR_OFFSET                (0x00)         /**< (TWI_CR) Control Register Offset */
#define TWI_MMR_OFFSET               (0x04)         /**< (TWI_MMR) Master Mode Register Offset */
#define TWI_SMR_OFFSET               (0x08)         /**< (TWI_SMR) Slave Mode Register Offset */
#define TWI_IADR_OFFSET              (0x0C)         /**< (TWI_IADR) Internal Address Register Offset */
#define TWI_CWGR_OFFSET              (0x10)         /**< (TWI_CWGR) Clock Waveform Generator Register Offset */
#define TWI_SR_OFFSET                (0x20)         /**< (TWI_SR) Status Register Offset */
#define TWI_IER_OFFSET               (0x24)         /**< (TWI_IER) Interrupt Enable Register Offset */
#define TWI_IDR_OFFSET               (0x28)         /**< (TWI_IDR) Interrupt Disable Register Offset */
#define TWI_IMR_OFFSET               (0x2C)         /**< (TWI_IMR) Interrupt Mask Register Offset */
#define TWI_RHR_OFFSET               (0x30)         /**< (TWI_RHR) Receive Holding Register Offset */
#define TWI_THR_OFFSET               (0x34)         /**< (TWI_THR) Transmit Holding Register Offset */
#define TWI_SMBTR_OFFSET             (0x38)         /**< (TWI_SMBTR) SMBus Timing Register Offset */
#define TWI_FILTR_OFFSET             (0x44)         /**< (TWI_FILTR) Filter Register Offset */
#define TWI_SWMR_OFFSET              (0x4C)         /**< (TWI_SWMR) SleepWalking Matching Register Offset */
#define TWI_DR_OFFSET                (0xD0)         /**< (TWI_DR) Debug Register Offset */
#define TWI_WPMR_OFFSET              (0xE4)         /**< (TWI_WPMR) Write Protection Mode Register Offset */
#define TWI_WPSR_OFFSET              (0xE8)         /**< (TWI_WPSR) Write Protection Status Register Offset */

/** \brief TWI register API structure */
typedef struct
{
  __O   __TWI_CR_bits_t                TWI_CR;        /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  __TWI_MMR_bits_t               TWI_MMR;       /**< Offset: 0x04 (R/W  32) Master Mode Register */
  __IO  __TWI_SMR_bits_t               TWI_SMR;       /**< Offset: 0x08 (R/W  32) Slave Mode Register */
  __IO  __TWI_IADR_bits_t              TWI_IADR;      /**< Offset: 0x0C (R/W  32) Internal Address Register */
  __IO  __TWI_CWGR_bits_t              TWI_CWGR;      /**< Offset: 0x10 (R/W  32) Clock Waveform Generator Register */
  __I   uint8_t                        Reserved1[0x0C];
  __I   __TWI_SR_bits_t                TWI_SR;        /**< Offset: 0x20 (R/   32) Status Register */
  __O   __TWI_IER_bits_t               TWI_IER;       /**< Offset: 0x24 ( /W  32) Interrupt Enable Register */
  __O   __TWI_IDR_bits_t               TWI_IDR;       /**< Offset: 0x28 ( /W  32) Interrupt Disable Register */
  __I   __TWI_IMR_bits_t               TWI_IMR;       /**< Offset: 0x2C (R/   32) Interrupt Mask Register */
  __I   __TWI_RHR_bits_t               TWI_RHR;       /**< Offset: 0x30 (R/   32) Receive Holding Register */
  __O   __TWI_THR_bits_t               TWI_THR;       /**< Offset: 0x34 ( /W  32) Transmit Holding Register */
  __IO  __TWI_SMBTR_bits_t             TWI_SMBTR;     /**< Offset: 0x38 (R/W  32) SMBus Timing Register */
  __I   uint8_t                        Reserved2[0x08];
  __IO  __TWI_FILTR_bits_t             TWI_FILTR;     /**< Offset: 0x44 (R/W  32) Filter Register */
  __I   uint8_t                        Reserved3[0x04];
  __IO  __TWI_SWMR_bits_t              TWI_SWMR;      /**< Offset: 0x4C (R/W  32) SleepWalking Matching Register */
  __I   uint8_t                        Reserved4[0x80];
  __I   __TWI_DR_bits_t                TWI_DR;        /**< Offset: 0xD0 (R/   32) Debug Register */
  __I   uint8_t                        Reserved5[0x10];
  __IO  __TWI_WPMR_bits_t              TWI_WPMR;      /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   __TWI_WPSR_bits_t              TWI_WPSR;      /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} twi_registers_t;
/** @}  end of Two-wire Interface */

#endif /* _PIC32CZ_CA70_TWI_COMPONENT_H_ */
