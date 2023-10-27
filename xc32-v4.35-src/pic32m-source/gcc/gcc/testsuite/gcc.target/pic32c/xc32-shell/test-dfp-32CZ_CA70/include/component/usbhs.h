/**
 * \brief Component description for PIC32CZ/CA70 USBHS
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
#ifndef _PIC32CZ_CA70_USBHS_COMPONENT_H_
#define _PIC32CZ_CA70_USBHS_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_USBHS USB High-Speed Interface
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR USBHS */
/* ========================================================================== */

/* -------- USBHS_DEVDMANXTDSC : (USBHS Offset: 0x00) (R/W 32) Device DMA Channel Next Descriptor Address Register (n = 1) -------- */

typedef union
{
  struct
  {
    uint32_t NXT_DSC_ADD:32;            /**< bit:  0..31  Next Descriptor Address                       */
  };
  uint32_t w;
} __USBHS_DEVDMANXTDSC_bits_t;

#define USBHS_DEVDMANXTDSC_NXT_DSC_ADD_Pos    (0)                                            /**< (USBHS_DEVDMANXTDSC) Next Descriptor Address Position */
#define USBHS_DEVDMANXTDSC_NXT_DSC_ADD_Msk    (0xFFFFFFFFU << USBHS_DEVDMANXTDSC_NXT_DSC_ADD_Pos)  /**< (USBHS_DEVDMANXTDSC) Next Descriptor Address Mask */
#define USBHS_DEVDMANXTDSC_NXT_DSC_ADD(value) (USBHS_DEVDMANXTDSC_NXT_DSC_ADD_Msk & ((value) << USBHS_DEVDMANXTDSC_NXT_DSC_ADD_Pos))
#define USBHS_DEVDMANXTDSC_Msk                (0xFFFFFFFFUL)                                 /**< (USBHS_DEVDMANXTDSC) Register Mask  */

/* -------- USBHS_DEVDMAADDRESS : (USBHS Offset: 0x04) (R/W 32) Device DMA Channel Address Register (n = 1) -------- */

typedef union
{
  struct
  {
    uint32_t BUFF_ADD:32;               /**< bit:  0..31  Buffer Address                                */
  };
  uint32_t w;
} __USBHS_DEVDMAADDRESS_bits_t;

#define USBHS_DEVDMAADDRESS_BUFF_ADD_Pos      (0)                                            /**< (USBHS_DEVDMAADDRESS) Buffer Address Position */
#define USBHS_DEVDMAADDRESS_BUFF_ADD_Msk      (0xFFFFFFFFU << USBHS_DEVDMAADDRESS_BUFF_ADD_Pos)  /**< (USBHS_DEVDMAADDRESS) Buffer Address Mask */
#define USBHS_DEVDMAADDRESS_BUFF_ADD(value)   (USBHS_DEVDMAADDRESS_BUFF_ADD_Msk & ((value) << USBHS_DEVDMAADDRESS_BUFF_ADD_Pos))
#define USBHS_DEVDMAADDRESS_Msk               (0xFFFFFFFFUL)                                 /**< (USBHS_DEVDMAADDRESS) Register Mask  */

/* -------- USBHS_DEVDMACONTROL : (USBHS Offset: 0x08) (R/W 32) Device DMA Channel Control Register (n = 1) -------- */

typedef union
{
  struct
  {
    uint32_t CHANN_ENB:1;               /**< bit:      0  Channel Enable Command                        */
    uint32_t LDNXT_DSC:1;               /**< bit:      1  Load Next Channel Transfer Descriptor Enable Command */
    uint32_t END_TR_EN:1;               /**< bit:      2  End of Transfer Enable Control (OUT transfers only) */
    uint32_t END_B_EN:1;                /**< bit:      3  End of Buffer Enable Control                  */
    uint32_t END_TR_IT:1;               /**< bit:      4  End of Transfer Interrupt Enable              */
    uint32_t END_BUFFIT:1;              /**< bit:      5  End of Buffer Interrupt Enable                */
    uint32_t DESC_LD_IT:1;              /**< bit:      6  Descriptor Loaded Interrupt Enable            */
    uint32_t BURST_LCK:1;               /**< bit:      7  Burst Lock Enable                             */
    uint32_t :8;                        /**< bit:  8..15  Reserved                                      */
    uint32_t BUFF_LENGTH:16;            /**< bit: 16..31  Buffer Byte Length (Write-only)               */
  };
  uint32_t w;
} __USBHS_DEVDMACONTROL_bits_t;

#define USBHS_DEVDMACONTROL_CHANN_ENB_Pos     (0)                                            /**< (USBHS_DEVDMACONTROL) Channel Enable Command Position */
#define USBHS_DEVDMACONTROL_CHANN_ENB_Msk     (0x1U << USBHS_DEVDMACONTROL_CHANN_ENB_Pos)    /**< (USBHS_DEVDMACONTROL) Channel Enable Command Mask */
#define USBHS_DEVDMACONTROL_LDNXT_DSC_Pos     (1)                                            /**< (USBHS_DEVDMACONTROL) Load Next Channel Transfer Descriptor Enable Command Position */
#define USBHS_DEVDMACONTROL_LDNXT_DSC_Msk     (0x1U << USBHS_DEVDMACONTROL_LDNXT_DSC_Pos)    /**< (USBHS_DEVDMACONTROL) Load Next Channel Transfer Descriptor Enable Command Mask */
#define USBHS_DEVDMACONTROL_END_TR_EN_Pos     (2)                                            /**< (USBHS_DEVDMACONTROL) End of Transfer Enable Control (OUT transfers only) Position */
#define USBHS_DEVDMACONTROL_END_TR_EN_Msk     (0x1U << USBHS_DEVDMACONTROL_END_TR_EN_Pos)    /**< (USBHS_DEVDMACONTROL) End of Transfer Enable Control (OUT transfers only) Mask */
#define USBHS_DEVDMACONTROL_END_B_EN_Pos      (3)                                            /**< (USBHS_DEVDMACONTROL) End of Buffer Enable Control Position */
#define USBHS_DEVDMACONTROL_END_B_EN_Msk      (0x1U << USBHS_DEVDMACONTROL_END_B_EN_Pos)     /**< (USBHS_DEVDMACONTROL) End of Buffer Enable Control Mask */
#define USBHS_DEVDMACONTROL_END_TR_IT_Pos     (4)                                            /**< (USBHS_DEVDMACONTROL) End of Transfer Interrupt Enable Position */
#define USBHS_DEVDMACONTROL_END_TR_IT_Msk     (0x1U << USBHS_DEVDMACONTROL_END_TR_IT_Pos)    /**< (USBHS_DEVDMACONTROL) End of Transfer Interrupt Enable Mask */
#define USBHS_DEVDMACONTROL_END_BUFFIT_Pos    (5)                                            /**< (USBHS_DEVDMACONTROL) End of Buffer Interrupt Enable Position */
#define USBHS_DEVDMACONTROL_END_BUFFIT_Msk    (0x1U << USBHS_DEVDMACONTROL_END_BUFFIT_Pos)   /**< (USBHS_DEVDMACONTROL) End of Buffer Interrupt Enable Mask */
#define USBHS_DEVDMACONTROL_DESC_LD_IT_Pos    (6)                                            /**< (USBHS_DEVDMACONTROL) Descriptor Loaded Interrupt Enable Position */
#define USBHS_DEVDMACONTROL_DESC_LD_IT_Msk    (0x1U << USBHS_DEVDMACONTROL_DESC_LD_IT_Pos)   /**< (USBHS_DEVDMACONTROL) Descriptor Loaded Interrupt Enable Mask */
#define USBHS_DEVDMACONTROL_BURST_LCK_Pos     (7)                                            /**< (USBHS_DEVDMACONTROL) Burst Lock Enable Position */
#define USBHS_DEVDMACONTROL_BURST_LCK_Msk     (0x1U << USBHS_DEVDMACONTROL_BURST_LCK_Pos)    /**< (USBHS_DEVDMACONTROL) Burst Lock Enable Mask */
#define USBHS_DEVDMACONTROL_BUFF_LENGTH_Pos   (16)                                           /**< (USBHS_DEVDMACONTROL) Buffer Byte Length (Write-only) Position */
#define USBHS_DEVDMACONTROL_BUFF_LENGTH_Msk   (0xFFFFU << USBHS_DEVDMACONTROL_BUFF_LENGTH_Pos)  /**< (USBHS_DEVDMACONTROL) Buffer Byte Length (Write-only) Mask */
#define USBHS_DEVDMACONTROL_BUFF_LENGTH(value) (USBHS_DEVDMACONTROL_BUFF_LENGTH_Msk & ((value) << USBHS_DEVDMACONTROL_BUFF_LENGTH_Pos))
#define USBHS_DEVDMACONTROL_Msk               (0xFFFF00FFUL)                                 /**< (USBHS_DEVDMACONTROL) Register Mask  */

/* -------- USBHS_DEVDMASTATUS : (USBHS Offset: 0x0c) (R/W 32) Device DMA Channel Status Register (n = 1) -------- */

typedef union
{
  struct
  {
    uint32_t CHANN_ENB:1;               /**< bit:      0  Channel Enable Status                         */
    uint32_t CHANN_ACT:1;               /**< bit:      1  Channel Active Status                         */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t END_TR_ST:1;               /**< bit:      4  End of Channel Transfer Status                */
    uint32_t END_BF_ST:1;               /**< bit:      5  End of Channel Buffer Status                  */
    uint32_t DESC_LDST:1;               /**< bit:      6  Descriptor Loaded Status                      */
    uint32_t :9;                        /**< bit:  7..15  Reserved                                      */
    uint32_t BUFF_COUNT:16;             /**< bit: 16..31  Buffer Byte Count                             */
  };
  uint32_t w;
} __USBHS_DEVDMASTATUS_bits_t;

#define USBHS_DEVDMASTATUS_CHANN_ENB_Pos      (0)                                            /**< (USBHS_DEVDMASTATUS) Channel Enable Status Position */
#define USBHS_DEVDMASTATUS_CHANN_ENB_Msk      (0x1U << USBHS_DEVDMASTATUS_CHANN_ENB_Pos)     /**< (USBHS_DEVDMASTATUS) Channel Enable Status Mask */
#define USBHS_DEVDMASTATUS_CHANN_ACT_Pos      (1)                                            /**< (USBHS_DEVDMASTATUS) Channel Active Status Position */
#define USBHS_DEVDMASTATUS_CHANN_ACT_Msk      (0x1U << USBHS_DEVDMASTATUS_CHANN_ACT_Pos)     /**< (USBHS_DEVDMASTATUS) Channel Active Status Mask */
#define USBHS_DEVDMASTATUS_END_TR_ST_Pos      (4)                                            /**< (USBHS_DEVDMASTATUS) End of Channel Transfer Status Position */
#define USBHS_DEVDMASTATUS_END_TR_ST_Msk      (0x1U << USBHS_DEVDMASTATUS_END_TR_ST_Pos)     /**< (USBHS_DEVDMASTATUS) End of Channel Transfer Status Mask */
#define USBHS_DEVDMASTATUS_END_BF_ST_Pos      (5)                                            /**< (USBHS_DEVDMASTATUS) End of Channel Buffer Status Position */
#define USBHS_DEVDMASTATUS_END_BF_ST_Msk      (0x1U << USBHS_DEVDMASTATUS_END_BF_ST_Pos)     /**< (USBHS_DEVDMASTATUS) End of Channel Buffer Status Mask */
#define USBHS_DEVDMASTATUS_DESC_LDST_Pos      (6)                                            /**< (USBHS_DEVDMASTATUS) Descriptor Loaded Status Position */
#define USBHS_DEVDMASTATUS_DESC_LDST_Msk      (0x1U << USBHS_DEVDMASTATUS_DESC_LDST_Pos)     /**< (USBHS_DEVDMASTATUS) Descriptor Loaded Status Mask */
#define USBHS_DEVDMASTATUS_BUFF_COUNT_Pos     (16)                                           /**< (USBHS_DEVDMASTATUS) Buffer Byte Count Position */
#define USBHS_DEVDMASTATUS_BUFF_COUNT_Msk     (0xFFFFU << USBHS_DEVDMASTATUS_BUFF_COUNT_Pos)  /**< (USBHS_DEVDMASTATUS) Buffer Byte Count Mask */
#define USBHS_DEVDMASTATUS_BUFF_COUNT(value)  (USBHS_DEVDMASTATUS_BUFF_COUNT_Msk & ((value) << USBHS_DEVDMASTATUS_BUFF_COUNT_Pos))
#define USBHS_DEVDMASTATUS_Msk                (0xFFFF0073UL)                                 /**< (USBHS_DEVDMASTATUS) Register Mask  */

/* -------- USBHS_HSTDMANXTDSC : (USBHS Offset: 0x00) (R/W 32) Host DMA Channel Next Descriptor Address Register (n = 1) -------- */

typedef union
{
  struct
  {
    uint32_t NXT_DSC_ADD:32;            /**< bit:  0..31  Next Descriptor Address                       */
  };
  uint32_t w;
} __USBHS_HSTDMANXTDSC_bits_t;

#define USBHS_HSTDMANXTDSC_NXT_DSC_ADD_Pos    (0)                                            /**< (USBHS_HSTDMANXTDSC) Next Descriptor Address Position */
#define USBHS_HSTDMANXTDSC_NXT_DSC_ADD_Msk    (0xFFFFFFFFU << USBHS_HSTDMANXTDSC_NXT_DSC_ADD_Pos)  /**< (USBHS_HSTDMANXTDSC) Next Descriptor Address Mask */
#define USBHS_HSTDMANXTDSC_NXT_DSC_ADD(value) (USBHS_HSTDMANXTDSC_NXT_DSC_ADD_Msk & ((value) << USBHS_HSTDMANXTDSC_NXT_DSC_ADD_Pos))
#define USBHS_HSTDMANXTDSC_Msk                (0xFFFFFFFFUL)                                 /**< (USBHS_HSTDMANXTDSC) Register Mask  */

/* -------- USBHS_HSTDMAADDRESS : (USBHS Offset: 0x04) (R/W 32) Host DMA Channel Address Register (n = 1) -------- */

typedef union
{
  struct
  {
    uint32_t BUFF_ADD:32;               /**< bit:  0..31  Buffer Address                                */
  };
  uint32_t w;
} __USBHS_HSTDMAADDRESS_bits_t;

#define USBHS_HSTDMAADDRESS_BUFF_ADD_Pos      (0)                                            /**< (USBHS_HSTDMAADDRESS) Buffer Address Position */
#define USBHS_HSTDMAADDRESS_BUFF_ADD_Msk      (0xFFFFFFFFU << USBHS_HSTDMAADDRESS_BUFF_ADD_Pos)  /**< (USBHS_HSTDMAADDRESS) Buffer Address Mask */
#define USBHS_HSTDMAADDRESS_BUFF_ADD(value)   (USBHS_HSTDMAADDRESS_BUFF_ADD_Msk & ((value) << USBHS_HSTDMAADDRESS_BUFF_ADD_Pos))
#define USBHS_HSTDMAADDRESS_Msk               (0xFFFFFFFFUL)                                 /**< (USBHS_HSTDMAADDRESS) Register Mask  */

/* -------- USBHS_HSTDMACONTROL : (USBHS Offset: 0x08) (R/W 32) Host DMA Channel Control Register (n = 1) -------- */

typedef union
{
  struct
  {
    uint32_t CHANN_ENB:1;               /**< bit:      0  Channel Enable Command                        */
    uint32_t LDNXT_DSC:1;               /**< bit:      1  Load Next Channel Transfer Descriptor Enable Command */
    uint32_t END_TR_EN:1;               /**< bit:      2  End of Transfer Enable Control (OUT transfers only) */
    uint32_t END_B_EN:1;                /**< bit:      3  End of Buffer Enable Control                  */
    uint32_t END_TR_IT:1;               /**< bit:      4  End of Transfer Interrupt Enable              */
    uint32_t END_BUFFIT:1;              /**< bit:      5  End of Buffer Interrupt Enable                */
    uint32_t DESC_LD_IT:1;              /**< bit:      6  Descriptor Loaded Interrupt Enable            */
    uint32_t BURST_LCK:1;               /**< bit:      7  Burst Lock Enable                             */
    uint32_t :8;                        /**< bit:  8..15  Reserved                                      */
    uint32_t BUFF_LENGTH:16;            /**< bit: 16..31  Buffer Byte Length (Write-only)               */
  };
  uint32_t w;
} __USBHS_HSTDMACONTROL_bits_t;

#define USBHS_HSTDMACONTROL_CHANN_ENB_Pos     (0)                                            /**< (USBHS_HSTDMACONTROL) Channel Enable Command Position */
#define USBHS_HSTDMACONTROL_CHANN_ENB_Msk     (0x1U << USBHS_HSTDMACONTROL_CHANN_ENB_Pos)    /**< (USBHS_HSTDMACONTROL) Channel Enable Command Mask */
#define USBHS_HSTDMACONTROL_LDNXT_DSC_Pos     (1)                                            /**< (USBHS_HSTDMACONTROL) Load Next Channel Transfer Descriptor Enable Command Position */
#define USBHS_HSTDMACONTROL_LDNXT_DSC_Msk     (0x1U << USBHS_HSTDMACONTROL_LDNXT_DSC_Pos)    /**< (USBHS_HSTDMACONTROL) Load Next Channel Transfer Descriptor Enable Command Mask */
#define USBHS_HSTDMACONTROL_END_TR_EN_Pos     (2)                                            /**< (USBHS_HSTDMACONTROL) End of Transfer Enable Control (OUT transfers only) Position */
#define USBHS_HSTDMACONTROL_END_TR_EN_Msk     (0x1U << USBHS_HSTDMACONTROL_END_TR_EN_Pos)    /**< (USBHS_HSTDMACONTROL) End of Transfer Enable Control (OUT transfers only) Mask */
#define USBHS_HSTDMACONTROL_END_B_EN_Pos      (3)                                            /**< (USBHS_HSTDMACONTROL) End of Buffer Enable Control Position */
#define USBHS_HSTDMACONTROL_END_B_EN_Msk      (0x1U << USBHS_HSTDMACONTROL_END_B_EN_Pos)     /**< (USBHS_HSTDMACONTROL) End of Buffer Enable Control Mask */
#define USBHS_HSTDMACONTROL_END_TR_IT_Pos     (4)                                            /**< (USBHS_HSTDMACONTROL) End of Transfer Interrupt Enable Position */
#define USBHS_HSTDMACONTROL_END_TR_IT_Msk     (0x1U << USBHS_HSTDMACONTROL_END_TR_IT_Pos)    /**< (USBHS_HSTDMACONTROL) End of Transfer Interrupt Enable Mask */
#define USBHS_HSTDMACONTROL_END_BUFFIT_Pos    (5)                                            /**< (USBHS_HSTDMACONTROL) End of Buffer Interrupt Enable Position */
#define USBHS_HSTDMACONTROL_END_BUFFIT_Msk    (0x1U << USBHS_HSTDMACONTROL_END_BUFFIT_Pos)   /**< (USBHS_HSTDMACONTROL) End of Buffer Interrupt Enable Mask */
#define USBHS_HSTDMACONTROL_DESC_LD_IT_Pos    (6)                                            /**< (USBHS_HSTDMACONTROL) Descriptor Loaded Interrupt Enable Position */
#define USBHS_HSTDMACONTROL_DESC_LD_IT_Msk    (0x1U << USBHS_HSTDMACONTROL_DESC_LD_IT_Pos)   /**< (USBHS_HSTDMACONTROL) Descriptor Loaded Interrupt Enable Mask */
#define USBHS_HSTDMACONTROL_BURST_LCK_Pos     (7)                                            /**< (USBHS_HSTDMACONTROL) Burst Lock Enable Position */
#define USBHS_HSTDMACONTROL_BURST_LCK_Msk     (0x1U << USBHS_HSTDMACONTROL_BURST_LCK_Pos)    /**< (USBHS_HSTDMACONTROL) Burst Lock Enable Mask */
#define USBHS_HSTDMACONTROL_BUFF_LENGTH_Pos   (16)                                           /**< (USBHS_HSTDMACONTROL) Buffer Byte Length (Write-only) Position */
#define USBHS_HSTDMACONTROL_BUFF_LENGTH_Msk   (0xFFFFU << USBHS_HSTDMACONTROL_BUFF_LENGTH_Pos)  /**< (USBHS_HSTDMACONTROL) Buffer Byte Length (Write-only) Mask */
#define USBHS_HSTDMACONTROL_BUFF_LENGTH(value) (USBHS_HSTDMACONTROL_BUFF_LENGTH_Msk & ((value) << USBHS_HSTDMACONTROL_BUFF_LENGTH_Pos))
#define USBHS_HSTDMACONTROL_Msk               (0xFFFF00FFUL)                                 /**< (USBHS_HSTDMACONTROL) Register Mask  */

/* -------- USBHS_HSTDMASTATUS : (USBHS Offset: 0x0c) (R/W 32) Host DMA Channel Status Register (n = 1) -------- */

typedef union
{
  struct
  {
    uint32_t CHANN_ENB:1;               /**< bit:      0  Channel Enable Status                         */
    uint32_t CHANN_ACT:1;               /**< bit:      1  Channel Active Status                         */
    uint32_t :2;                        /**< bit:   2..3  Reserved                                      */
    uint32_t END_TR_ST:1;               /**< bit:      4  End of Channel Transfer Status                */
    uint32_t END_BF_ST:1;               /**< bit:      5  End of Channel Buffer Status                  */
    uint32_t DESC_LDST:1;               /**< bit:      6  Descriptor Loaded Status                      */
    uint32_t :9;                        /**< bit:  7..15  Reserved                                      */
    uint32_t BUFF_COUNT:16;             /**< bit: 16..31  Buffer Byte Count                             */
  };
  uint32_t w;
} __USBHS_HSTDMASTATUS_bits_t;

#define USBHS_HSTDMASTATUS_CHANN_ENB_Pos      (0)                                            /**< (USBHS_HSTDMASTATUS) Channel Enable Status Position */
#define USBHS_HSTDMASTATUS_CHANN_ENB_Msk      (0x1U << USBHS_HSTDMASTATUS_CHANN_ENB_Pos)     /**< (USBHS_HSTDMASTATUS) Channel Enable Status Mask */
#define USBHS_HSTDMASTATUS_CHANN_ACT_Pos      (1)                                            /**< (USBHS_HSTDMASTATUS) Channel Active Status Position */
#define USBHS_HSTDMASTATUS_CHANN_ACT_Msk      (0x1U << USBHS_HSTDMASTATUS_CHANN_ACT_Pos)     /**< (USBHS_HSTDMASTATUS) Channel Active Status Mask */
#define USBHS_HSTDMASTATUS_END_TR_ST_Pos      (4)                                            /**< (USBHS_HSTDMASTATUS) End of Channel Transfer Status Position */
#define USBHS_HSTDMASTATUS_END_TR_ST_Msk      (0x1U << USBHS_HSTDMASTATUS_END_TR_ST_Pos)     /**< (USBHS_HSTDMASTATUS) End of Channel Transfer Status Mask */
#define USBHS_HSTDMASTATUS_END_BF_ST_Pos      (5)                                            /**< (USBHS_HSTDMASTATUS) End of Channel Buffer Status Position */
#define USBHS_HSTDMASTATUS_END_BF_ST_Msk      (0x1U << USBHS_HSTDMASTATUS_END_BF_ST_Pos)     /**< (USBHS_HSTDMASTATUS) End of Channel Buffer Status Mask */
#define USBHS_HSTDMASTATUS_DESC_LDST_Pos      (6)                                            /**< (USBHS_HSTDMASTATUS) Descriptor Loaded Status Position */
#define USBHS_HSTDMASTATUS_DESC_LDST_Msk      (0x1U << USBHS_HSTDMASTATUS_DESC_LDST_Pos)     /**< (USBHS_HSTDMASTATUS) Descriptor Loaded Status Mask */
#define USBHS_HSTDMASTATUS_BUFF_COUNT_Pos     (16)                                           /**< (USBHS_HSTDMASTATUS) Buffer Byte Count Position */
#define USBHS_HSTDMASTATUS_BUFF_COUNT_Msk     (0xFFFFU << USBHS_HSTDMASTATUS_BUFF_COUNT_Pos)  /**< (USBHS_HSTDMASTATUS) Buffer Byte Count Mask */
#define USBHS_HSTDMASTATUS_BUFF_COUNT(value)  (USBHS_HSTDMASTATUS_BUFF_COUNT_Msk & ((value) << USBHS_HSTDMASTATUS_BUFF_COUNT_Pos))
#define USBHS_HSTDMASTATUS_Msk                (0xFFFF0073UL)                                 /**< (USBHS_HSTDMASTATUS) Register Mask  */

/* -------- USBHS_DEVCTRL : (USBHS Offset: 0x00) (R/W 32) Device General Control Register -------- */

typedef union
{
  struct
  {
    uint32_t UADD:7;                    /**< bit:   0..6  USB Address                                   */
    uint32_t ADDEN:1;                   /**< bit:      7  Address Enable                                */
    uint32_t DETACH:1;                  /**< bit:      8  Detach                                        */
    uint32_t RMWKUP:1;                  /**< bit:      9  Remote Wake-Up                                */
    uint32_t SPDCONF:2;                 /**< bit: 10..11  Mode Configuration                            */
    uint32_t LS:1;                      /**< bit:     12  Low-Speed Mode Force                          */
    uint32_t TSTJ:1;                    /**< bit:     13  Test mode J                                   */
    uint32_t TSTK:1;                    /**< bit:     14  Test mode K                                   */
    uint32_t TSTPCKT:1;                 /**< bit:     15  Test packet mode                              */
    uint32_t OPMODE2:1;                 /**< bit:     16  Specific Operational mode                     */
    uint32_t :15;                       /**< bit: 17..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_DEVCTRL_bits_t;

#define USBHS_DEVCTRL_UADD_Pos                (0)                                            /**< (USBHS_DEVCTRL) USB Address Position */
#define USBHS_DEVCTRL_UADD_Msk                (0x7FU << USBHS_DEVCTRL_UADD_Pos)              /**< (USBHS_DEVCTRL) USB Address Mask */
#define USBHS_DEVCTRL_UADD(value)             (USBHS_DEVCTRL_UADD_Msk & ((value) << USBHS_DEVCTRL_UADD_Pos))
#define USBHS_DEVCTRL_ADDEN_Pos               (7)                                            /**< (USBHS_DEVCTRL) Address Enable Position */
#define USBHS_DEVCTRL_ADDEN_Msk               (0x1U << USBHS_DEVCTRL_ADDEN_Pos)              /**< (USBHS_DEVCTRL) Address Enable Mask */
#define USBHS_DEVCTRL_DETACH_Pos              (8)                                            /**< (USBHS_DEVCTRL) Detach Position */
#define USBHS_DEVCTRL_DETACH_Msk              (0x1U << USBHS_DEVCTRL_DETACH_Pos)             /**< (USBHS_DEVCTRL) Detach Mask */
#define USBHS_DEVCTRL_RMWKUP_Pos              (9)                                            /**< (USBHS_DEVCTRL) Remote Wake-Up Position */
#define USBHS_DEVCTRL_RMWKUP_Msk              (0x1U << USBHS_DEVCTRL_RMWKUP_Pos)             /**< (USBHS_DEVCTRL) Remote Wake-Up Mask */
#define USBHS_DEVCTRL_SPDCONF_Pos             (10)                                           /**< (USBHS_DEVCTRL) Mode Configuration Position */
#define USBHS_DEVCTRL_SPDCONF_Msk             (0x3U << USBHS_DEVCTRL_SPDCONF_Pos)            /**< (USBHS_DEVCTRL) Mode Configuration Mask */
#define USBHS_DEVCTRL_SPDCONF(value)          (USBHS_DEVCTRL_SPDCONF_Msk & ((value) << USBHS_DEVCTRL_SPDCONF_Pos))
#define   USBHS_DEVCTRL_SPDCONF_NORMAL_Val    (0x0U)                                         /**< (USBHS_DEVCTRL) The peripheral starts in Full-speed mode and performs a high-speed reset to switch to High-speed mode if the host is high-speed-capable.  */
#define   USBHS_DEVCTRL_SPDCONF_LOW_POWER_Val (0x1U)                                         /**< (USBHS_DEVCTRL) For a better consumption, if high speed is not needed.  */
#define   USBHS_DEVCTRL_SPDCONF_HIGH_SPEED_Val (0x2U)                                         /**< (USBHS_DEVCTRL) Forced high speed.  */
#define   USBHS_DEVCTRL_SPDCONF_FORCED_FS_Val (0x3U)                                         /**< (USBHS_DEVCTRL) The peripheral remains in Full-speed mode whatever the host speed capability.  */
#define USBHS_DEVCTRL_SPDCONF_NORMAL          (USBHS_DEVCTRL_SPDCONF_NORMAL_Val << USBHS_DEVCTRL_SPDCONF_Pos)  /**< (USBHS_DEVCTRL) The peripheral starts in Full-speed mode and performs a high-speed reset to switch to High-speed mode if the host is high-speed-capable. Position  */
#define USBHS_DEVCTRL_SPDCONF_LOW_POWER       (USBHS_DEVCTRL_SPDCONF_LOW_POWER_Val << USBHS_DEVCTRL_SPDCONF_Pos)  /**< (USBHS_DEVCTRL) For a better consumption, if high speed is not needed. Position  */
#define USBHS_DEVCTRL_SPDCONF_HIGH_SPEED      (USBHS_DEVCTRL_SPDCONF_HIGH_SPEED_Val << USBHS_DEVCTRL_SPDCONF_Pos)  /**< (USBHS_DEVCTRL) Forced high speed. Position  */
#define USBHS_DEVCTRL_SPDCONF_FORCED_FS       (USBHS_DEVCTRL_SPDCONF_FORCED_FS_Val << USBHS_DEVCTRL_SPDCONF_Pos)  /**< (USBHS_DEVCTRL) The peripheral remains in Full-speed mode whatever the host speed capability. Position  */
#define USBHS_DEVCTRL_LS_Pos                  (12)                                           /**< (USBHS_DEVCTRL) Low-Speed Mode Force Position */
#define USBHS_DEVCTRL_LS_Msk                  (0x1U << USBHS_DEVCTRL_LS_Pos)                 /**< (USBHS_DEVCTRL) Low-Speed Mode Force Mask */
#define USBHS_DEVCTRL_TSTJ_Pos                (13)                                           /**< (USBHS_DEVCTRL) Test mode J Position */
#define USBHS_DEVCTRL_TSTJ_Msk                (0x1U << USBHS_DEVCTRL_TSTJ_Pos)               /**< (USBHS_DEVCTRL) Test mode J Mask */
#define USBHS_DEVCTRL_TSTK_Pos                (14)                                           /**< (USBHS_DEVCTRL) Test mode K Position */
#define USBHS_DEVCTRL_TSTK_Msk                (0x1U << USBHS_DEVCTRL_TSTK_Pos)               /**< (USBHS_DEVCTRL) Test mode K Mask */
#define USBHS_DEVCTRL_TSTPCKT_Pos             (15)                                           /**< (USBHS_DEVCTRL) Test packet mode Position */
#define USBHS_DEVCTRL_TSTPCKT_Msk             (0x1U << USBHS_DEVCTRL_TSTPCKT_Pos)            /**< (USBHS_DEVCTRL) Test packet mode Mask */
#define USBHS_DEVCTRL_OPMODE2_Pos             (16)                                           /**< (USBHS_DEVCTRL) Specific Operational mode Position */
#define USBHS_DEVCTRL_OPMODE2_Msk             (0x1U << USBHS_DEVCTRL_OPMODE2_Pos)            /**< (USBHS_DEVCTRL) Specific Operational mode Mask */
#define USBHS_DEVCTRL_Msk                     (0x0001FFFFUL)                                 /**< (USBHS_DEVCTRL) Register Mask  */

/* -------- USBHS_DEVISR : (USBHS Offset: 0x04) (R/ 32) Device Global Interrupt Status Register -------- */

typedef union
{
  struct
  {
    uint32_t SUSP:1;                    /**< bit:      0  Suspend Interrupt                             */
    uint32_t MSOF:1;                    /**< bit:      1  Micro Start of Frame Interrupt                */
    uint32_t SOF:1;                     /**< bit:      2  Start of Frame Interrupt                      */
    uint32_t EORST:1;                   /**< bit:      3  End of Reset Interrupt                        */
    uint32_t WAKEUP:1;                  /**< bit:      4  Wake-Up Interrupt                             */
    uint32_t EORSM:1;                   /**< bit:      5  End of Resume Interrupt                       */
    uint32_t UPRSM:1;                   /**< bit:      6  Upstream Resume Interrupt                     */
    uint32_t :5;                        /**< bit:  7..11  Reserved                                      */
    uint32_t PEP_0:1;                   /**< bit:     12  Endpoint 0 Interrupt                          */
    uint32_t PEP_1:1;                   /**< bit:     13  Endpoint 1 Interrupt                          */
    uint32_t PEP_2:1;                   /**< bit:     14  Endpoint 2 Interrupt                          */
    uint32_t PEP_3:1;                   /**< bit:     15  Endpoint 3 Interrupt                          */
    uint32_t PEP_4:1;                   /**< bit:     16  Endpoint 4 Interrupt                          */
    uint32_t PEP_5:1;                   /**< bit:     17  Endpoint 5 Interrupt                          */
    uint32_t PEP_6:1;                   /**< bit:     18  Endpoint 6 Interrupt                          */
    uint32_t PEP_7:1;                   /**< bit:     19  Endpoint 7 Interrupt                          */
    uint32_t PEP_8:1;                   /**< bit:     20  Endpoint 8 Interrupt                          */
    uint32_t PEP_9:1;                   /**< bit:     21  Endpoint 9 Interrupt                          */
    uint32_t :3;                        /**< bit: 22..24  Reserved                                      */
    uint32_t DMA_1:1;                   /**< bit:     25  DMA Channel 1 Interrupt                       */
    uint32_t DMA_2:1;                   /**< bit:     26  DMA Channel 2 Interrupt                       */
    uint32_t DMA_3:1;                   /**< bit:     27  DMA Channel 3 Interrupt                       */
    uint32_t DMA_4:1;                   /**< bit:     28  DMA Channel 4 Interrupt                       */
    uint32_t DMA_5:1;                   /**< bit:     29  DMA Channel 5 Interrupt                       */
    uint32_t DMA_6:1;                   /**< bit:     30  DMA Channel 6 Interrupt                       */
    uint32_t DMA_7:1;                   /**< bit:     31  DMA Channel 7 Interrupt                       */
  };
  struct
  {
    uint32_t :12;                       /**< bit:  0..11  Reserved                                      */
    uint32_t PEP_:10;                   /**< bit: 12..21  Endpoint x Interrupt                          */
    uint32_t :3;                        /**< bit: 22..24  Reserved                                      */
    uint32_t DMA_:7;                    /**< bit: 25..31  DMA Channel 7 Interrupt                       */
  };
  uint32_t w;
} __USBHS_DEVISR_bits_t;

#define USBHS_DEVISR_SUSP_Pos                 (0)                                            /**< (USBHS_DEVISR) Suspend Interrupt Position */
#define USBHS_DEVISR_SUSP_Msk                 (0x1U << USBHS_DEVISR_SUSP_Pos)                /**< (USBHS_DEVISR) Suspend Interrupt Mask */
#define USBHS_DEVISR_MSOF_Pos                 (1)                                            /**< (USBHS_DEVISR) Micro Start of Frame Interrupt Position */
#define USBHS_DEVISR_MSOF_Msk                 (0x1U << USBHS_DEVISR_MSOF_Pos)                /**< (USBHS_DEVISR) Micro Start of Frame Interrupt Mask */
#define USBHS_DEVISR_SOF_Pos                  (2)                                            /**< (USBHS_DEVISR) Start of Frame Interrupt Position */
#define USBHS_DEVISR_SOF_Msk                  (0x1U << USBHS_DEVISR_SOF_Pos)                 /**< (USBHS_DEVISR) Start of Frame Interrupt Mask */
#define USBHS_DEVISR_EORST_Pos                (3)                                            /**< (USBHS_DEVISR) End of Reset Interrupt Position */
#define USBHS_DEVISR_EORST_Msk                (0x1U << USBHS_DEVISR_EORST_Pos)               /**< (USBHS_DEVISR) End of Reset Interrupt Mask */
#define USBHS_DEVISR_WAKEUP_Pos               (4)                                            /**< (USBHS_DEVISR) Wake-Up Interrupt Position */
#define USBHS_DEVISR_WAKEUP_Msk               (0x1U << USBHS_DEVISR_WAKEUP_Pos)              /**< (USBHS_DEVISR) Wake-Up Interrupt Mask */
#define USBHS_DEVISR_EORSM_Pos                (5)                                            /**< (USBHS_DEVISR) End of Resume Interrupt Position */
#define USBHS_DEVISR_EORSM_Msk                (0x1U << USBHS_DEVISR_EORSM_Pos)               /**< (USBHS_DEVISR) End of Resume Interrupt Mask */
#define USBHS_DEVISR_UPRSM_Pos                (6)                                            /**< (USBHS_DEVISR) Upstream Resume Interrupt Position */
#define USBHS_DEVISR_UPRSM_Msk                (0x1U << USBHS_DEVISR_UPRSM_Pos)               /**< (USBHS_DEVISR) Upstream Resume Interrupt Mask */
#define USBHS_DEVISR_PEP_0_Pos                (12)                                           /**< (USBHS_DEVISR) Endpoint 0 Interrupt Position */
#define USBHS_DEVISR_PEP_0_Msk                (0x1U << USBHS_DEVISR_PEP_0_Pos)               /**< (USBHS_DEVISR) Endpoint 0 Interrupt Mask */
#define USBHS_DEVISR_PEP_1_Pos                (13)                                           /**< (USBHS_DEVISR) Endpoint 1 Interrupt Position */
#define USBHS_DEVISR_PEP_1_Msk                (0x1U << USBHS_DEVISR_PEP_1_Pos)               /**< (USBHS_DEVISR) Endpoint 1 Interrupt Mask */
#define USBHS_DEVISR_PEP_2_Pos                (14)                                           /**< (USBHS_DEVISR) Endpoint 2 Interrupt Position */
#define USBHS_DEVISR_PEP_2_Msk                (0x1U << USBHS_DEVISR_PEP_2_Pos)               /**< (USBHS_DEVISR) Endpoint 2 Interrupt Mask */
#define USBHS_DEVISR_PEP_3_Pos                (15)                                           /**< (USBHS_DEVISR) Endpoint 3 Interrupt Position */
#define USBHS_DEVISR_PEP_3_Msk                (0x1U << USBHS_DEVISR_PEP_3_Pos)               /**< (USBHS_DEVISR) Endpoint 3 Interrupt Mask */
#define USBHS_DEVISR_PEP_4_Pos                (16)                                           /**< (USBHS_DEVISR) Endpoint 4 Interrupt Position */
#define USBHS_DEVISR_PEP_4_Msk                (0x1U << USBHS_DEVISR_PEP_4_Pos)               /**< (USBHS_DEVISR) Endpoint 4 Interrupt Mask */
#define USBHS_DEVISR_PEP_5_Pos                (17)                                           /**< (USBHS_DEVISR) Endpoint 5 Interrupt Position */
#define USBHS_DEVISR_PEP_5_Msk                (0x1U << USBHS_DEVISR_PEP_5_Pos)               /**< (USBHS_DEVISR) Endpoint 5 Interrupt Mask */
#define USBHS_DEVISR_PEP_6_Pos                (18)                                           /**< (USBHS_DEVISR) Endpoint 6 Interrupt Position */
#define USBHS_DEVISR_PEP_6_Msk                (0x1U << USBHS_DEVISR_PEP_6_Pos)               /**< (USBHS_DEVISR) Endpoint 6 Interrupt Mask */
#define USBHS_DEVISR_PEP_7_Pos                (19)                                           /**< (USBHS_DEVISR) Endpoint 7 Interrupt Position */
#define USBHS_DEVISR_PEP_7_Msk                (0x1U << USBHS_DEVISR_PEP_7_Pos)               /**< (USBHS_DEVISR) Endpoint 7 Interrupt Mask */
#define USBHS_DEVISR_PEP_8_Pos                (20)                                           /**< (USBHS_DEVISR) Endpoint 8 Interrupt Position */
#define USBHS_DEVISR_PEP_8_Msk                (0x1U << USBHS_DEVISR_PEP_8_Pos)               /**< (USBHS_DEVISR) Endpoint 8 Interrupt Mask */
#define USBHS_DEVISR_PEP_9_Pos                (21)                                           /**< (USBHS_DEVISR) Endpoint 9 Interrupt Position */
#define USBHS_DEVISR_PEP_9_Msk                (0x1U << USBHS_DEVISR_PEP_9_Pos)               /**< (USBHS_DEVISR) Endpoint 9 Interrupt Mask */
#define USBHS_DEVISR_DMA_1_Pos                (25)                                           /**< (USBHS_DEVISR) DMA Channel 1 Interrupt Position */
#define USBHS_DEVISR_DMA_1_Msk                (0x1U << USBHS_DEVISR_DMA_1_Pos)               /**< (USBHS_DEVISR) DMA Channel 1 Interrupt Mask */
#define USBHS_DEVISR_DMA_2_Pos                (26)                                           /**< (USBHS_DEVISR) DMA Channel 2 Interrupt Position */
#define USBHS_DEVISR_DMA_2_Msk                (0x1U << USBHS_DEVISR_DMA_2_Pos)               /**< (USBHS_DEVISR) DMA Channel 2 Interrupt Mask */
#define USBHS_DEVISR_DMA_3_Pos                (27)                                           /**< (USBHS_DEVISR) DMA Channel 3 Interrupt Position */
#define USBHS_DEVISR_DMA_3_Msk                (0x1U << USBHS_DEVISR_DMA_3_Pos)               /**< (USBHS_DEVISR) DMA Channel 3 Interrupt Mask */
#define USBHS_DEVISR_DMA_4_Pos                (28)                                           /**< (USBHS_DEVISR) DMA Channel 4 Interrupt Position */
#define USBHS_DEVISR_DMA_4_Msk                (0x1U << USBHS_DEVISR_DMA_4_Pos)               /**< (USBHS_DEVISR) DMA Channel 4 Interrupt Mask */
#define USBHS_DEVISR_DMA_5_Pos                (29)                                           /**< (USBHS_DEVISR) DMA Channel 5 Interrupt Position */
#define USBHS_DEVISR_DMA_5_Msk                (0x1U << USBHS_DEVISR_DMA_5_Pos)               /**< (USBHS_DEVISR) DMA Channel 5 Interrupt Mask */
#define USBHS_DEVISR_DMA_6_Pos                (30)                                           /**< (USBHS_DEVISR) DMA Channel 6 Interrupt Position */
#define USBHS_DEVISR_DMA_6_Msk                (0x1U << USBHS_DEVISR_DMA_6_Pos)               /**< (USBHS_DEVISR) DMA Channel 6 Interrupt Mask */
#define USBHS_DEVISR_DMA_7_Pos                (31)                                           /**< (USBHS_DEVISR) DMA Channel 7 Interrupt Position */
#define USBHS_DEVISR_DMA_7_Msk                (0x1U << USBHS_DEVISR_DMA_7_Pos)               /**< (USBHS_DEVISR) DMA Channel 7 Interrupt Mask */
#define USBHS_DEVISR_Msk                      (0xFE3FF07FUL)                                 /**< (USBHS_DEVISR) Register Mask  */
#define USBHS_DEVISR_PEP__Pos                 (12)                                           /**< (USBHS_DEVISR Position) Endpoint x Interrupt */
#define USBHS_DEVISR_PEP__Msk                 (0x3FFU << USBHS_DEVISR_PEP__Pos)              /**< (USBHS_DEVISR Mask) PEP_ */
#define USBHS_DEVISR_PEP_(value)              (USBHS_DEVISR_PEP__Msk & ((value) << USBHS_DEVISR_PEP__Pos))
#define USBHS_DEVISR_DMA__Pos                 (25)                                           /**< (USBHS_DEVISR Position) DMA Channel 7 Interrupt */
#define USBHS_DEVISR_DMA__Msk                 (0x7FU << USBHS_DEVISR_DMA__Pos)               /**< (USBHS_DEVISR Mask) DMA_ */
#define USBHS_DEVISR_DMA_(value)              (USBHS_DEVISR_DMA__Msk & ((value) << USBHS_DEVISR_DMA__Pos))

/* -------- USBHS_DEVICR : (USBHS Offset: 0x08) (/W 32) Device Global Interrupt Clear Register -------- */

typedef union
{
  struct
  {
    uint32_t SUSPC:1;                   /**< bit:      0  Suspend Interrupt Clear                       */
    uint32_t MSOFC:1;                   /**< bit:      1  Micro Start of Frame Interrupt Clear          */
    uint32_t SOFC:1;                    /**< bit:      2  Start of Frame Interrupt Clear                */
    uint32_t EORSTC:1;                  /**< bit:      3  End of Reset Interrupt Clear                  */
    uint32_t WAKEUPC:1;                 /**< bit:      4  Wake-Up Interrupt Clear                       */
    uint32_t EORSMC:1;                  /**< bit:      5  End of Resume Interrupt Clear                 */
    uint32_t UPRSMC:1;                  /**< bit:      6  Upstream Resume Interrupt Clear               */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_DEVICR_bits_t;

#define USBHS_DEVICR_SUSPC_Pos                (0)                                            /**< (USBHS_DEVICR) Suspend Interrupt Clear Position */
#define USBHS_DEVICR_SUSPC_Msk                (0x1U << USBHS_DEVICR_SUSPC_Pos)               /**< (USBHS_DEVICR) Suspend Interrupt Clear Mask */
#define USBHS_DEVICR_MSOFC_Pos                (1)                                            /**< (USBHS_DEVICR) Micro Start of Frame Interrupt Clear Position */
#define USBHS_DEVICR_MSOFC_Msk                (0x1U << USBHS_DEVICR_MSOFC_Pos)               /**< (USBHS_DEVICR) Micro Start of Frame Interrupt Clear Mask */
#define USBHS_DEVICR_SOFC_Pos                 (2)                                            /**< (USBHS_DEVICR) Start of Frame Interrupt Clear Position */
#define USBHS_DEVICR_SOFC_Msk                 (0x1U << USBHS_DEVICR_SOFC_Pos)                /**< (USBHS_DEVICR) Start of Frame Interrupt Clear Mask */
#define USBHS_DEVICR_EORSTC_Pos               (3)                                            /**< (USBHS_DEVICR) End of Reset Interrupt Clear Position */
#define USBHS_DEVICR_EORSTC_Msk               (0x1U << USBHS_DEVICR_EORSTC_Pos)              /**< (USBHS_DEVICR) End of Reset Interrupt Clear Mask */
#define USBHS_DEVICR_WAKEUPC_Pos              (4)                                            /**< (USBHS_DEVICR) Wake-Up Interrupt Clear Position */
#define USBHS_DEVICR_WAKEUPC_Msk              (0x1U << USBHS_DEVICR_WAKEUPC_Pos)             /**< (USBHS_DEVICR) Wake-Up Interrupt Clear Mask */
#define USBHS_DEVICR_EORSMC_Pos               (5)                                            /**< (USBHS_DEVICR) End of Resume Interrupt Clear Position */
#define USBHS_DEVICR_EORSMC_Msk               (0x1U << USBHS_DEVICR_EORSMC_Pos)              /**< (USBHS_DEVICR) End of Resume Interrupt Clear Mask */
#define USBHS_DEVICR_UPRSMC_Pos               (6)                                            /**< (USBHS_DEVICR) Upstream Resume Interrupt Clear Position */
#define USBHS_DEVICR_UPRSMC_Msk               (0x1U << USBHS_DEVICR_UPRSMC_Pos)              /**< (USBHS_DEVICR) Upstream Resume Interrupt Clear Mask */
#define USBHS_DEVICR_Msk                      (0x0000007FUL)                                 /**< (USBHS_DEVICR) Register Mask  */

/* -------- USBHS_DEVIFR : (USBHS Offset: 0x0c) (/W 32) Device Global Interrupt Set Register -------- */

typedef union
{
  struct
  {
    uint32_t SUSPS:1;                   /**< bit:      0  Suspend Interrupt Set                         */
    uint32_t MSOFS:1;                   /**< bit:      1  Micro Start of Frame Interrupt Set            */
    uint32_t SOFS:1;                    /**< bit:      2  Start of Frame Interrupt Set                  */
    uint32_t EORSTS:1;                  /**< bit:      3  End of Reset Interrupt Set                    */
    uint32_t WAKEUPS:1;                 /**< bit:      4  Wake-Up Interrupt Set                         */
    uint32_t EORSMS:1;                  /**< bit:      5  End of Resume Interrupt Set                   */
    uint32_t UPRSMS:1;                  /**< bit:      6  Upstream Resume Interrupt Set                 */
    uint32_t :18;                       /**< bit:  7..24  Reserved                                      */
    uint32_t DMA_1:1;                   /**< bit:     25  DMA Channel 1 Interrupt Set                   */
    uint32_t DMA_2:1;                   /**< bit:     26  DMA Channel 2 Interrupt Set                   */
    uint32_t DMA_3:1;                   /**< bit:     27  DMA Channel 3 Interrupt Set                   */
    uint32_t DMA_4:1;                   /**< bit:     28  DMA Channel 4 Interrupt Set                   */
    uint32_t DMA_5:1;                   /**< bit:     29  DMA Channel 5 Interrupt Set                   */
    uint32_t DMA_6:1;                   /**< bit:     30  DMA Channel 6 Interrupt Set                   */
    uint32_t DMA_7:1;                   /**< bit:     31  DMA Channel 7 Interrupt Set                   */
  };
  struct
  {
    uint32_t :25;                       /**< bit:  0..24  Reserved                                      */
    uint32_t DMA_:7;                    /**< bit: 25..31  DMA Channel 7 Interrupt Set                   */
  };
  uint32_t w;
} __USBHS_DEVIFR_bits_t;

#define USBHS_DEVIFR_SUSPS_Pos                (0)                                            /**< (USBHS_DEVIFR) Suspend Interrupt Set Position */
#define USBHS_DEVIFR_SUSPS_Msk                (0x1U << USBHS_DEVIFR_SUSPS_Pos)               /**< (USBHS_DEVIFR) Suspend Interrupt Set Mask */
#define USBHS_DEVIFR_MSOFS_Pos                (1)                                            /**< (USBHS_DEVIFR) Micro Start of Frame Interrupt Set Position */
#define USBHS_DEVIFR_MSOFS_Msk                (0x1U << USBHS_DEVIFR_MSOFS_Pos)               /**< (USBHS_DEVIFR) Micro Start of Frame Interrupt Set Mask */
#define USBHS_DEVIFR_SOFS_Pos                 (2)                                            /**< (USBHS_DEVIFR) Start of Frame Interrupt Set Position */
#define USBHS_DEVIFR_SOFS_Msk                 (0x1U << USBHS_DEVIFR_SOFS_Pos)                /**< (USBHS_DEVIFR) Start of Frame Interrupt Set Mask */
#define USBHS_DEVIFR_EORSTS_Pos               (3)                                            /**< (USBHS_DEVIFR) End of Reset Interrupt Set Position */
#define USBHS_DEVIFR_EORSTS_Msk               (0x1U << USBHS_DEVIFR_EORSTS_Pos)              /**< (USBHS_DEVIFR) End of Reset Interrupt Set Mask */
#define USBHS_DEVIFR_WAKEUPS_Pos              (4)                                            /**< (USBHS_DEVIFR) Wake-Up Interrupt Set Position */
#define USBHS_DEVIFR_WAKEUPS_Msk              (0x1U << USBHS_DEVIFR_WAKEUPS_Pos)             /**< (USBHS_DEVIFR) Wake-Up Interrupt Set Mask */
#define USBHS_DEVIFR_EORSMS_Pos               (5)                                            /**< (USBHS_DEVIFR) End of Resume Interrupt Set Position */
#define USBHS_DEVIFR_EORSMS_Msk               (0x1U << USBHS_DEVIFR_EORSMS_Pos)              /**< (USBHS_DEVIFR) End of Resume Interrupt Set Mask */
#define USBHS_DEVIFR_UPRSMS_Pos               (6)                                            /**< (USBHS_DEVIFR) Upstream Resume Interrupt Set Position */
#define USBHS_DEVIFR_UPRSMS_Msk               (0x1U << USBHS_DEVIFR_UPRSMS_Pos)              /**< (USBHS_DEVIFR) Upstream Resume Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_1_Pos                (25)                                           /**< (USBHS_DEVIFR) DMA Channel 1 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_1_Msk                (0x1U << USBHS_DEVIFR_DMA_1_Pos)               /**< (USBHS_DEVIFR) DMA Channel 1 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_2_Pos                (26)                                           /**< (USBHS_DEVIFR) DMA Channel 2 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_2_Msk                (0x1U << USBHS_DEVIFR_DMA_2_Pos)               /**< (USBHS_DEVIFR) DMA Channel 2 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_3_Pos                (27)                                           /**< (USBHS_DEVIFR) DMA Channel 3 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_3_Msk                (0x1U << USBHS_DEVIFR_DMA_3_Pos)               /**< (USBHS_DEVIFR) DMA Channel 3 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_4_Pos                (28)                                           /**< (USBHS_DEVIFR) DMA Channel 4 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_4_Msk                (0x1U << USBHS_DEVIFR_DMA_4_Pos)               /**< (USBHS_DEVIFR) DMA Channel 4 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_5_Pos                (29)                                           /**< (USBHS_DEVIFR) DMA Channel 5 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_5_Msk                (0x1U << USBHS_DEVIFR_DMA_5_Pos)               /**< (USBHS_DEVIFR) DMA Channel 5 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_6_Pos                (30)                                           /**< (USBHS_DEVIFR) DMA Channel 6 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_6_Msk                (0x1U << USBHS_DEVIFR_DMA_6_Pos)               /**< (USBHS_DEVIFR) DMA Channel 6 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_7_Pos                (31)                                           /**< (USBHS_DEVIFR) DMA Channel 7 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_7_Msk                (0x1U << USBHS_DEVIFR_DMA_7_Pos)               /**< (USBHS_DEVIFR) DMA Channel 7 Interrupt Set Mask */
#define USBHS_DEVIFR_Msk                      (0xFE00007FUL)                                 /**< (USBHS_DEVIFR) Register Mask  */
#define USBHS_DEVIFR_DMA__Pos                 (25)                                           /**< (USBHS_DEVIFR Position) DMA Channel 7 Interrupt Set */
#define USBHS_DEVIFR_DMA__Msk                 (0x7FU << USBHS_DEVIFR_DMA__Pos)               /**< (USBHS_DEVIFR Mask) DMA_ */
#define USBHS_DEVIFR_DMA_(value)              (USBHS_DEVIFR_DMA__Msk & ((value) << USBHS_DEVIFR_DMA__Pos))

/* -------- USBHS_DEVIMR : (USBHS Offset: 0x10) (R/ 32) Device Global Interrupt Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t SUSPE:1;                   /**< bit:      0  Suspend Interrupt Mask                        */
    uint32_t MSOFE:1;                   /**< bit:      1  Micro Start of Frame Interrupt Mask           */
    uint32_t SOFE:1;                    /**< bit:      2  Start of Frame Interrupt Mask                 */
    uint32_t EORSTE:1;                  /**< bit:      3  End of Reset Interrupt Mask                   */
    uint32_t WAKEUPE:1;                 /**< bit:      4  Wake-Up Interrupt Mask                        */
    uint32_t EORSME:1;                  /**< bit:      5  End of Resume Interrupt Mask                  */
    uint32_t UPRSME:1;                  /**< bit:      6  Upstream Resume Interrupt Mask                */
    uint32_t :5;                        /**< bit:  7..11  Reserved                                      */
    uint32_t PEP_0:1;                   /**< bit:     12  Endpoint 0 Interrupt Mask                     */
    uint32_t PEP_1:1;                   /**< bit:     13  Endpoint 1 Interrupt Mask                     */
    uint32_t PEP_2:1;                   /**< bit:     14  Endpoint 2 Interrupt Mask                     */
    uint32_t PEP_3:1;                   /**< bit:     15  Endpoint 3 Interrupt Mask                     */
    uint32_t PEP_4:1;                   /**< bit:     16  Endpoint 4 Interrupt Mask                     */
    uint32_t PEP_5:1;                   /**< bit:     17  Endpoint 5 Interrupt Mask                     */
    uint32_t PEP_6:1;                   /**< bit:     18  Endpoint 6 Interrupt Mask                     */
    uint32_t PEP_7:1;                   /**< bit:     19  Endpoint 7 Interrupt Mask                     */
    uint32_t PEP_8:1;                   /**< bit:     20  Endpoint 8 Interrupt Mask                     */
    uint32_t PEP_9:1;                   /**< bit:     21  Endpoint 9 Interrupt Mask                     */
    uint32_t :3;                        /**< bit: 22..24  Reserved                                      */
    uint32_t DMA_1:1;                   /**< bit:     25  DMA Channel 1 Interrupt Mask                  */
    uint32_t DMA_2:1;                   /**< bit:     26  DMA Channel 2 Interrupt Mask                  */
    uint32_t DMA_3:1;                   /**< bit:     27  DMA Channel 3 Interrupt Mask                  */
    uint32_t DMA_4:1;                   /**< bit:     28  DMA Channel 4 Interrupt Mask                  */
    uint32_t DMA_5:1;                   /**< bit:     29  DMA Channel 5 Interrupt Mask                  */
    uint32_t DMA_6:1;                   /**< bit:     30  DMA Channel 6 Interrupt Mask                  */
    uint32_t DMA_7:1;                   /**< bit:     31  DMA Channel 7 Interrupt Mask                  */
  };
  struct
  {
    uint32_t :12;                       /**< bit:  0..11  Reserved                                      */
    uint32_t PEP_:10;                   /**< bit: 12..21  Endpoint x Interrupt Mask                     */
    uint32_t :3;                        /**< bit: 22..24  Reserved                                      */
    uint32_t DMA_:7;                    /**< bit: 25..31  DMA Channel 7 Interrupt Mask                  */
  };
  uint32_t w;
} __USBHS_DEVIMR_bits_t;

#define USBHS_DEVIMR_SUSPE_Pos                (0)                                            /**< (USBHS_DEVIMR) Suspend Interrupt Mask Position */
#define USBHS_DEVIMR_SUSPE_Msk                (0x1U << USBHS_DEVIMR_SUSPE_Pos)               /**< (USBHS_DEVIMR) Suspend Interrupt Mask Mask */
#define USBHS_DEVIMR_MSOFE_Pos                (1)                                            /**< (USBHS_DEVIMR) Micro Start of Frame Interrupt Mask Position */
#define USBHS_DEVIMR_MSOFE_Msk                (0x1U << USBHS_DEVIMR_MSOFE_Pos)               /**< (USBHS_DEVIMR) Micro Start of Frame Interrupt Mask Mask */
#define USBHS_DEVIMR_SOFE_Pos                 (2)                                            /**< (USBHS_DEVIMR) Start of Frame Interrupt Mask Position */
#define USBHS_DEVIMR_SOFE_Msk                 (0x1U << USBHS_DEVIMR_SOFE_Pos)                /**< (USBHS_DEVIMR) Start of Frame Interrupt Mask Mask */
#define USBHS_DEVIMR_EORSTE_Pos               (3)                                            /**< (USBHS_DEVIMR) End of Reset Interrupt Mask Position */
#define USBHS_DEVIMR_EORSTE_Msk               (0x1U << USBHS_DEVIMR_EORSTE_Pos)              /**< (USBHS_DEVIMR) End of Reset Interrupt Mask Mask */
#define USBHS_DEVIMR_WAKEUPE_Pos              (4)                                            /**< (USBHS_DEVIMR) Wake-Up Interrupt Mask Position */
#define USBHS_DEVIMR_WAKEUPE_Msk              (0x1U << USBHS_DEVIMR_WAKEUPE_Pos)             /**< (USBHS_DEVIMR) Wake-Up Interrupt Mask Mask */
#define USBHS_DEVIMR_EORSME_Pos               (5)                                            /**< (USBHS_DEVIMR) End of Resume Interrupt Mask Position */
#define USBHS_DEVIMR_EORSME_Msk               (0x1U << USBHS_DEVIMR_EORSME_Pos)              /**< (USBHS_DEVIMR) End of Resume Interrupt Mask Mask */
#define USBHS_DEVIMR_UPRSME_Pos               (6)                                            /**< (USBHS_DEVIMR) Upstream Resume Interrupt Mask Position */
#define USBHS_DEVIMR_UPRSME_Msk               (0x1U << USBHS_DEVIMR_UPRSME_Pos)              /**< (USBHS_DEVIMR) Upstream Resume Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_0_Pos                (12)                                           /**< (USBHS_DEVIMR) Endpoint 0 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_0_Msk                (0x1U << USBHS_DEVIMR_PEP_0_Pos)               /**< (USBHS_DEVIMR) Endpoint 0 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_1_Pos                (13)                                           /**< (USBHS_DEVIMR) Endpoint 1 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_1_Msk                (0x1U << USBHS_DEVIMR_PEP_1_Pos)               /**< (USBHS_DEVIMR) Endpoint 1 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_2_Pos                (14)                                           /**< (USBHS_DEVIMR) Endpoint 2 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_2_Msk                (0x1U << USBHS_DEVIMR_PEP_2_Pos)               /**< (USBHS_DEVIMR) Endpoint 2 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_3_Pos                (15)                                           /**< (USBHS_DEVIMR) Endpoint 3 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_3_Msk                (0x1U << USBHS_DEVIMR_PEP_3_Pos)               /**< (USBHS_DEVIMR) Endpoint 3 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_4_Pos                (16)                                           /**< (USBHS_DEVIMR) Endpoint 4 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_4_Msk                (0x1U << USBHS_DEVIMR_PEP_4_Pos)               /**< (USBHS_DEVIMR) Endpoint 4 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_5_Pos                (17)                                           /**< (USBHS_DEVIMR) Endpoint 5 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_5_Msk                (0x1U << USBHS_DEVIMR_PEP_5_Pos)               /**< (USBHS_DEVIMR) Endpoint 5 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_6_Pos                (18)                                           /**< (USBHS_DEVIMR) Endpoint 6 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_6_Msk                (0x1U << USBHS_DEVIMR_PEP_6_Pos)               /**< (USBHS_DEVIMR) Endpoint 6 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_7_Pos                (19)                                           /**< (USBHS_DEVIMR) Endpoint 7 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_7_Msk                (0x1U << USBHS_DEVIMR_PEP_7_Pos)               /**< (USBHS_DEVIMR) Endpoint 7 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_8_Pos                (20)                                           /**< (USBHS_DEVIMR) Endpoint 8 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_8_Msk                (0x1U << USBHS_DEVIMR_PEP_8_Pos)               /**< (USBHS_DEVIMR) Endpoint 8 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_9_Pos                (21)                                           /**< (USBHS_DEVIMR) Endpoint 9 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_9_Msk                (0x1U << USBHS_DEVIMR_PEP_9_Pos)               /**< (USBHS_DEVIMR) Endpoint 9 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_1_Pos                (25)                                           /**< (USBHS_DEVIMR) DMA Channel 1 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_1_Msk                (0x1U << USBHS_DEVIMR_DMA_1_Pos)               /**< (USBHS_DEVIMR) DMA Channel 1 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_2_Pos                (26)                                           /**< (USBHS_DEVIMR) DMA Channel 2 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_2_Msk                (0x1U << USBHS_DEVIMR_DMA_2_Pos)               /**< (USBHS_DEVIMR) DMA Channel 2 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_3_Pos                (27)                                           /**< (USBHS_DEVIMR) DMA Channel 3 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_3_Msk                (0x1U << USBHS_DEVIMR_DMA_3_Pos)               /**< (USBHS_DEVIMR) DMA Channel 3 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_4_Pos                (28)                                           /**< (USBHS_DEVIMR) DMA Channel 4 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_4_Msk                (0x1U << USBHS_DEVIMR_DMA_4_Pos)               /**< (USBHS_DEVIMR) DMA Channel 4 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_5_Pos                (29)                                           /**< (USBHS_DEVIMR) DMA Channel 5 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_5_Msk                (0x1U << USBHS_DEVIMR_DMA_5_Pos)               /**< (USBHS_DEVIMR) DMA Channel 5 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_6_Pos                (30)                                           /**< (USBHS_DEVIMR) DMA Channel 6 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_6_Msk                (0x1U << USBHS_DEVIMR_DMA_6_Pos)               /**< (USBHS_DEVIMR) DMA Channel 6 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_7_Pos                (31)                                           /**< (USBHS_DEVIMR) DMA Channel 7 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_7_Msk                (0x1U << USBHS_DEVIMR_DMA_7_Pos)               /**< (USBHS_DEVIMR) DMA Channel 7 Interrupt Mask Mask */
#define USBHS_DEVIMR_Msk                      (0xFE3FF07FUL)                                 /**< (USBHS_DEVIMR) Register Mask  */
#define USBHS_DEVIMR_PEP__Pos                 (12)                                           /**< (USBHS_DEVIMR Position) Endpoint x Interrupt Mask */
#define USBHS_DEVIMR_PEP__Msk                 (0x3FFU << USBHS_DEVIMR_PEP__Pos)              /**< (USBHS_DEVIMR Mask) PEP_ */
#define USBHS_DEVIMR_PEP_(value)              (USBHS_DEVIMR_PEP__Msk & ((value) << USBHS_DEVIMR_PEP__Pos))
#define USBHS_DEVIMR_DMA__Pos                 (25)                                           /**< (USBHS_DEVIMR Position) DMA Channel 7 Interrupt Mask */
#define USBHS_DEVIMR_DMA__Msk                 (0x7FU << USBHS_DEVIMR_DMA__Pos)               /**< (USBHS_DEVIMR Mask) DMA_ */
#define USBHS_DEVIMR_DMA_(value)              (USBHS_DEVIMR_DMA__Msk & ((value) << USBHS_DEVIMR_DMA__Pos))

/* -------- USBHS_DEVIDR : (USBHS Offset: 0x14) (/W 32) Device Global Interrupt Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t SUSPEC:1;                  /**< bit:      0  Suspend Interrupt Disable                     */
    uint32_t MSOFEC:1;                  /**< bit:      1  Micro Start of Frame Interrupt Disable        */
    uint32_t SOFEC:1;                   /**< bit:      2  Start of Frame Interrupt Disable              */
    uint32_t EORSTEC:1;                 /**< bit:      3  End of Reset Interrupt Disable                */
    uint32_t WAKEUPEC:1;                /**< bit:      4  Wake-Up Interrupt Disable                     */
    uint32_t EORSMEC:1;                 /**< bit:      5  End of Resume Interrupt Disable               */
    uint32_t UPRSMEC:1;                 /**< bit:      6  Upstream Resume Interrupt Disable             */
    uint32_t :5;                        /**< bit:  7..11  Reserved                                      */
    uint32_t PEP_0:1;                   /**< bit:     12  Endpoint 0 Interrupt Disable                  */
    uint32_t PEP_1:1;                   /**< bit:     13  Endpoint 1 Interrupt Disable                  */
    uint32_t PEP_2:1;                   /**< bit:     14  Endpoint 2 Interrupt Disable                  */
    uint32_t PEP_3:1;                   /**< bit:     15  Endpoint 3 Interrupt Disable                  */
    uint32_t PEP_4:1;                   /**< bit:     16  Endpoint 4 Interrupt Disable                  */
    uint32_t PEP_5:1;                   /**< bit:     17  Endpoint 5 Interrupt Disable                  */
    uint32_t PEP_6:1;                   /**< bit:     18  Endpoint 6 Interrupt Disable                  */
    uint32_t PEP_7:1;                   /**< bit:     19  Endpoint 7 Interrupt Disable                  */
    uint32_t PEP_8:1;                   /**< bit:     20  Endpoint 8 Interrupt Disable                  */
    uint32_t PEP_9:1;                   /**< bit:     21  Endpoint 9 Interrupt Disable                  */
    uint32_t :3;                        /**< bit: 22..24  Reserved                                      */
    uint32_t DMA_1:1;                   /**< bit:     25  DMA Channel 1 Interrupt Disable               */
    uint32_t DMA_2:1;                   /**< bit:     26  DMA Channel 2 Interrupt Disable               */
    uint32_t DMA_3:1;                   /**< bit:     27  DMA Channel 3 Interrupt Disable               */
    uint32_t DMA_4:1;                   /**< bit:     28  DMA Channel 4 Interrupt Disable               */
    uint32_t DMA_5:1;                   /**< bit:     29  DMA Channel 5 Interrupt Disable               */
    uint32_t DMA_6:1;                   /**< bit:     30  DMA Channel 6 Interrupt Disable               */
    uint32_t DMA_7:1;                   /**< bit:     31  DMA Channel 7 Interrupt Disable               */
  };
  struct
  {
    uint32_t :12;                       /**< bit:  0..11  Reserved                                      */
    uint32_t PEP_:10;                   /**< bit: 12..21  Endpoint x Interrupt Disable                  */
    uint32_t :3;                        /**< bit: 22..24  Reserved                                      */
    uint32_t DMA_:7;                    /**< bit: 25..31  DMA Channel 7 Interrupt Disable               */
  };
  uint32_t w;
} __USBHS_DEVIDR_bits_t;

#define USBHS_DEVIDR_SUSPEC_Pos               (0)                                            /**< (USBHS_DEVIDR) Suspend Interrupt Disable Position */
#define USBHS_DEVIDR_SUSPEC_Msk               (0x1U << USBHS_DEVIDR_SUSPEC_Pos)              /**< (USBHS_DEVIDR) Suspend Interrupt Disable Mask */
#define USBHS_DEVIDR_MSOFEC_Pos               (1)                                            /**< (USBHS_DEVIDR) Micro Start of Frame Interrupt Disable Position */
#define USBHS_DEVIDR_MSOFEC_Msk               (0x1U << USBHS_DEVIDR_MSOFEC_Pos)              /**< (USBHS_DEVIDR) Micro Start of Frame Interrupt Disable Mask */
#define USBHS_DEVIDR_SOFEC_Pos                (2)                                            /**< (USBHS_DEVIDR) Start of Frame Interrupt Disable Position */
#define USBHS_DEVIDR_SOFEC_Msk                (0x1U << USBHS_DEVIDR_SOFEC_Pos)               /**< (USBHS_DEVIDR) Start of Frame Interrupt Disable Mask */
#define USBHS_DEVIDR_EORSTEC_Pos              (3)                                            /**< (USBHS_DEVIDR) End of Reset Interrupt Disable Position */
#define USBHS_DEVIDR_EORSTEC_Msk              (0x1U << USBHS_DEVIDR_EORSTEC_Pos)             /**< (USBHS_DEVIDR) End of Reset Interrupt Disable Mask */
#define USBHS_DEVIDR_WAKEUPEC_Pos             (4)                                            /**< (USBHS_DEVIDR) Wake-Up Interrupt Disable Position */
#define USBHS_DEVIDR_WAKEUPEC_Msk             (0x1U << USBHS_DEVIDR_WAKEUPEC_Pos)            /**< (USBHS_DEVIDR) Wake-Up Interrupt Disable Mask */
#define USBHS_DEVIDR_EORSMEC_Pos              (5)                                            /**< (USBHS_DEVIDR) End of Resume Interrupt Disable Position */
#define USBHS_DEVIDR_EORSMEC_Msk              (0x1U << USBHS_DEVIDR_EORSMEC_Pos)             /**< (USBHS_DEVIDR) End of Resume Interrupt Disable Mask */
#define USBHS_DEVIDR_UPRSMEC_Pos              (6)                                            /**< (USBHS_DEVIDR) Upstream Resume Interrupt Disable Position */
#define USBHS_DEVIDR_UPRSMEC_Msk              (0x1U << USBHS_DEVIDR_UPRSMEC_Pos)             /**< (USBHS_DEVIDR) Upstream Resume Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_0_Pos                (12)                                           /**< (USBHS_DEVIDR) Endpoint 0 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_0_Msk                (0x1U << USBHS_DEVIDR_PEP_0_Pos)               /**< (USBHS_DEVIDR) Endpoint 0 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_1_Pos                (13)                                           /**< (USBHS_DEVIDR) Endpoint 1 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_1_Msk                (0x1U << USBHS_DEVIDR_PEP_1_Pos)               /**< (USBHS_DEVIDR) Endpoint 1 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_2_Pos                (14)                                           /**< (USBHS_DEVIDR) Endpoint 2 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_2_Msk                (0x1U << USBHS_DEVIDR_PEP_2_Pos)               /**< (USBHS_DEVIDR) Endpoint 2 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_3_Pos                (15)                                           /**< (USBHS_DEVIDR) Endpoint 3 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_3_Msk                (0x1U << USBHS_DEVIDR_PEP_3_Pos)               /**< (USBHS_DEVIDR) Endpoint 3 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_4_Pos                (16)                                           /**< (USBHS_DEVIDR) Endpoint 4 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_4_Msk                (0x1U << USBHS_DEVIDR_PEP_4_Pos)               /**< (USBHS_DEVIDR) Endpoint 4 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_5_Pos                (17)                                           /**< (USBHS_DEVIDR) Endpoint 5 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_5_Msk                (0x1U << USBHS_DEVIDR_PEP_5_Pos)               /**< (USBHS_DEVIDR) Endpoint 5 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_6_Pos                (18)                                           /**< (USBHS_DEVIDR) Endpoint 6 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_6_Msk                (0x1U << USBHS_DEVIDR_PEP_6_Pos)               /**< (USBHS_DEVIDR) Endpoint 6 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_7_Pos                (19)                                           /**< (USBHS_DEVIDR) Endpoint 7 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_7_Msk                (0x1U << USBHS_DEVIDR_PEP_7_Pos)               /**< (USBHS_DEVIDR) Endpoint 7 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_8_Pos                (20)                                           /**< (USBHS_DEVIDR) Endpoint 8 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_8_Msk                (0x1U << USBHS_DEVIDR_PEP_8_Pos)               /**< (USBHS_DEVIDR) Endpoint 8 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_9_Pos                (21)                                           /**< (USBHS_DEVIDR) Endpoint 9 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_9_Msk                (0x1U << USBHS_DEVIDR_PEP_9_Pos)               /**< (USBHS_DEVIDR) Endpoint 9 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_1_Pos                (25)                                           /**< (USBHS_DEVIDR) DMA Channel 1 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_1_Msk                (0x1U << USBHS_DEVIDR_DMA_1_Pos)               /**< (USBHS_DEVIDR) DMA Channel 1 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_2_Pos                (26)                                           /**< (USBHS_DEVIDR) DMA Channel 2 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_2_Msk                (0x1U << USBHS_DEVIDR_DMA_2_Pos)               /**< (USBHS_DEVIDR) DMA Channel 2 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_3_Pos                (27)                                           /**< (USBHS_DEVIDR) DMA Channel 3 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_3_Msk                (0x1U << USBHS_DEVIDR_DMA_3_Pos)               /**< (USBHS_DEVIDR) DMA Channel 3 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_4_Pos                (28)                                           /**< (USBHS_DEVIDR) DMA Channel 4 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_4_Msk                (0x1U << USBHS_DEVIDR_DMA_4_Pos)               /**< (USBHS_DEVIDR) DMA Channel 4 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_5_Pos                (29)                                           /**< (USBHS_DEVIDR) DMA Channel 5 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_5_Msk                (0x1U << USBHS_DEVIDR_DMA_5_Pos)               /**< (USBHS_DEVIDR) DMA Channel 5 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_6_Pos                (30)                                           /**< (USBHS_DEVIDR) DMA Channel 6 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_6_Msk                (0x1U << USBHS_DEVIDR_DMA_6_Pos)               /**< (USBHS_DEVIDR) DMA Channel 6 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_7_Pos                (31)                                           /**< (USBHS_DEVIDR) DMA Channel 7 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_7_Msk                (0x1U << USBHS_DEVIDR_DMA_7_Pos)               /**< (USBHS_DEVIDR) DMA Channel 7 Interrupt Disable Mask */
#define USBHS_DEVIDR_Msk                      (0xFE3FF07FUL)                                 /**< (USBHS_DEVIDR) Register Mask  */
#define USBHS_DEVIDR_PEP__Pos                 (12)                                           /**< (USBHS_DEVIDR Position) Endpoint x Interrupt Disable */
#define USBHS_DEVIDR_PEP__Msk                 (0x3FFU << USBHS_DEVIDR_PEP__Pos)              /**< (USBHS_DEVIDR Mask) PEP_ */
#define USBHS_DEVIDR_PEP_(value)              (USBHS_DEVIDR_PEP__Msk & ((value) << USBHS_DEVIDR_PEP__Pos))
#define USBHS_DEVIDR_DMA__Pos                 (25)                                           /**< (USBHS_DEVIDR Position) DMA Channel 7 Interrupt Disable */
#define USBHS_DEVIDR_DMA__Msk                 (0x7FU << USBHS_DEVIDR_DMA__Pos)               /**< (USBHS_DEVIDR Mask) DMA_ */
#define USBHS_DEVIDR_DMA_(value)              (USBHS_DEVIDR_DMA__Msk & ((value) << USBHS_DEVIDR_DMA__Pos))

/* -------- USBHS_DEVIER : (USBHS Offset: 0x18) (/W 32) Device Global Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t SUSPES:1;                  /**< bit:      0  Suspend Interrupt Enable                      */
    uint32_t MSOFES:1;                  /**< bit:      1  Micro Start of Frame Interrupt Enable         */
    uint32_t SOFES:1;                   /**< bit:      2  Start of Frame Interrupt Enable               */
    uint32_t EORSTES:1;                 /**< bit:      3  End of Reset Interrupt Enable                 */
    uint32_t WAKEUPES:1;                /**< bit:      4  Wake-Up Interrupt Enable                      */
    uint32_t EORSMES:1;                 /**< bit:      5  End of Resume Interrupt Enable                */
    uint32_t UPRSMES:1;                 /**< bit:      6  Upstream Resume Interrupt Enable              */
    uint32_t :5;                        /**< bit:  7..11  Reserved                                      */
    uint32_t PEP_0:1;                   /**< bit:     12  Endpoint 0 Interrupt Enable                   */
    uint32_t PEP_1:1;                   /**< bit:     13  Endpoint 1 Interrupt Enable                   */
    uint32_t PEP_2:1;                   /**< bit:     14  Endpoint 2 Interrupt Enable                   */
    uint32_t PEP_3:1;                   /**< bit:     15  Endpoint 3 Interrupt Enable                   */
    uint32_t PEP_4:1;                   /**< bit:     16  Endpoint 4 Interrupt Enable                   */
    uint32_t PEP_5:1;                   /**< bit:     17  Endpoint 5 Interrupt Enable                   */
    uint32_t PEP_6:1;                   /**< bit:     18  Endpoint 6 Interrupt Enable                   */
    uint32_t PEP_7:1;                   /**< bit:     19  Endpoint 7 Interrupt Enable                   */
    uint32_t PEP_8:1;                   /**< bit:     20  Endpoint 8 Interrupt Enable                   */
    uint32_t PEP_9:1;                   /**< bit:     21  Endpoint 9 Interrupt Enable                   */
    uint32_t :3;                        /**< bit: 22..24  Reserved                                      */
    uint32_t DMA_1:1;                   /**< bit:     25  DMA Channel 1 Interrupt Enable                */
    uint32_t DMA_2:1;                   /**< bit:     26  DMA Channel 2 Interrupt Enable                */
    uint32_t DMA_3:1;                   /**< bit:     27  DMA Channel 3 Interrupt Enable                */
    uint32_t DMA_4:1;                   /**< bit:     28  DMA Channel 4 Interrupt Enable                */
    uint32_t DMA_5:1;                   /**< bit:     29  DMA Channel 5 Interrupt Enable                */
    uint32_t DMA_6:1;                   /**< bit:     30  DMA Channel 6 Interrupt Enable                */
    uint32_t DMA_7:1;                   /**< bit:     31  DMA Channel 7 Interrupt Enable                */
  };
  struct
  {
    uint32_t :12;                       /**< bit:  0..11  Reserved                                      */
    uint32_t PEP_:10;                   /**< bit: 12..21  Endpoint x Interrupt Enable                   */
    uint32_t :3;                        /**< bit: 22..24  Reserved                                      */
    uint32_t DMA_:7;                    /**< bit: 25..31  DMA Channel 7 Interrupt Enable                */
  };
  uint32_t w;
} __USBHS_DEVIER_bits_t;

#define USBHS_DEVIER_SUSPES_Pos               (0)                                            /**< (USBHS_DEVIER) Suspend Interrupt Enable Position */
#define USBHS_DEVIER_SUSPES_Msk               (0x1U << USBHS_DEVIER_SUSPES_Pos)              /**< (USBHS_DEVIER) Suspend Interrupt Enable Mask */
#define USBHS_DEVIER_MSOFES_Pos               (1)                                            /**< (USBHS_DEVIER) Micro Start of Frame Interrupt Enable Position */
#define USBHS_DEVIER_MSOFES_Msk               (0x1U << USBHS_DEVIER_MSOFES_Pos)              /**< (USBHS_DEVIER) Micro Start of Frame Interrupt Enable Mask */
#define USBHS_DEVIER_SOFES_Pos                (2)                                            /**< (USBHS_DEVIER) Start of Frame Interrupt Enable Position */
#define USBHS_DEVIER_SOFES_Msk                (0x1U << USBHS_DEVIER_SOFES_Pos)               /**< (USBHS_DEVIER) Start of Frame Interrupt Enable Mask */
#define USBHS_DEVIER_EORSTES_Pos              (3)                                            /**< (USBHS_DEVIER) End of Reset Interrupt Enable Position */
#define USBHS_DEVIER_EORSTES_Msk              (0x1U << USBHS_DEVIER_EORSTES_Pos)             /**< (USBHS_DEVIER) End of Reset Interrupt Enable Mask */
#define USBHS_DEVIER_WAKEUPES_Pos             (4)                                            /**< (USBHS_DEVIER) Wake-Up Interrupt Enable Position */
#define USBHS_DEVIER_WAKEUPES_Msk             (0x1U << USBHS_DEVIER_WAKEUPES_Pos)            /**< (USBHS_DEVIER) Wake-Up Interrupt Enable Mask */
#define USBHS_DEVIER_EORSMES_Pos              (5)                                            /**< (USBHS_DEVIER) End of Resume Interrupt Enable Position */
#define USBHS_DEVIER_EORSMES_Msk              (0x1U << USBHS_DEVIER_EORSMES_Pos)             /**< (USBHS_DEVIER) End of Resume Interrupt Enable Mask */
#define USBHS_DEVIER_UPRSMES_Pos              (6)                                            /**< (USBHS_DEVIER) Upstream Resume Interrupt Enable Position */
#define USBHS_DEVIER_UPRSMES_Msk              (0x1U << USBHS_DEVIER_UPRSMES_Pos)             /**< (USBHS_DEVIER) Upstream Resume Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_0_Pos                (12)                                           /**< (USBHS_DEVIER) Endpoint 0 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_0_Msk                (0x1U << USBHS_DEVIER_PEP_0_Pos)               /**< (USBHS_DEVIER) Endpoint 0 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_1_Pos                (13)                                           /**< (USBHS_DEVIER) Endpoint 1 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_1_Msk                (0x1U << USBHS_DEVIER_PEP_1_Pos)               /**< (USBHS_DEVIER) Endpoint 1 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_2_Pos                (14)                                           /**< (USBHS_DEVIER) Endpoint 2 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_2_Msk                (0x1U << USBHS_DEVIER_PEP_2_Pos)               /**< (USBHS_DEVIER) Endpoint 2 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_3_Pos                (15)                                           /**< (USBHS_DEVIER) Endpoint 3 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_3_Msk                (0x1U << USBHS_DEVIER_PEP_3_Pos)               /**< (USBHS_DEVIER) Endpoint 3 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_4_Pos                (16)                                           /**< (USBHS_DEVIER) Endpoint 4 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_4_Msk                (0x1U << USBHS_DEVIER_PEP_4_Pos)               /**< (USBHS_DEVIER) Endpoint 4 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_5_Pos                (17)                                           /**< (USBHS_DEVIER) Endpoint 5 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_5_Msk                (0x1U << USBHS_DEVIER_PEP_5_Pos)               /**< (USBHS_DEVIER) Endpoint 5 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_6_Pos                (18)                                           /**< (USBHS_DEVIER) Endpoint 6 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_6_Msk                (0x1U << USBHS_DEVIER_PEP_6_Pos)               /**< (USBHS_DEVIER) Endpoint 6 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_7_Pos                (19)                                           /**< (USBHS_DEVIER) Endpoint 7 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_7_Msk                (0x1U << USBHS_DEVIER_PEP_7_Pos)               /**< (USBHS_DEVIER) Endpoint 7 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_8_Pos                (20)                                           /**< (USBHS_DEVIER) Endpoint 8 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_8_Msk                (0x1U << USBHS_DEVIER_PEP_8_Pos)               /**< (USBHS_DEVIER) Endpoint 8 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_9_Pos                (21)                                           /**< (USBHS_DEVIER) Endpoint 9 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_9_Msk                (0x1U << USBHS_DEVIER_PEP_9_Pos)               /**< (USBHS_DEVIER) Endpoint 9 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_1_Pos                (25)                                           /**< (USBHS_DEVIER) DMA Channel 1 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_1_Msk                (0x1U << USBHS_DEVIER_DMA_1_Pos)               /**< (USBHS_DEVIER) DMA Channel 1 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_2_Pos                (26)                                           /**< (USBHS_DEVIER) DMA Channel 2 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_2_Msk                (0x1U << USBHS_DEVIER_DMA_2_Pos)               /**< (USBHS_DEVIER) DMA Channel 2 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_3_Pos                (27)                                           /**< (USBHS_DEVIER) DMA Channel 3 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_3_Msk                (0x1U << USBHS_DEVIER_DMA_3_Pos)               /**< (USBHS_DEVIER) DMA Channel 3 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_4_Pos                (28)                                           /**< (USBHS_DEVIER) DMA Channel 4 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_4_Msk                (0x1U << USBHS_DEVIER_DMA_4_Pos)               /**< (USBHS_DEVIER) DMA Channel 4 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_5_Pos                (29)                                           /**< (USBHS_DEVIER) DMA Channel 5 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_5_Msk                (0x1U << USBHS_DEVIER_DMA_5_Pos)               /**< (USBHS_DEVIER) DMA Channel 5 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_6_Pos                (30)                                           /**< (USBHS_DEVIER) DMA Channel 6 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_6_Msk                (0x1U << USBHS_DEVIER_DMA_6_Pos)               /**< (USBHS_DEVIER) DMA Channel 6 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_7_Pos                (31)                                           /**< (USBHS_DEVIER) DMA Channel 7 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_7_Msk                (0x1U << USBHS_DEVIER_DMA_7_Pos)               /**< (USBHS_DEVIER) DMA Channel 7 Interrupt Enable Mask */
#define USBHS_DEVIER_Msk                      (0xFE3FF07FUL)                                 /**< (USBHS_DEVIER) Register Mask  */
#define USBHS_DEVIER_PEP__Pos                 (12)                                           /**< (USBHS_DEVIER Position) Endpoint x Interrupt Enable */
#define USBHS_DEVIER_PEP__Msk                 (0x3FFU << USBHS_DEVIER_PEP__Pos)              /**< (USBHS_DEVIER Mask) PEP_ */
#define USBHS_DEVIER_PEP_(value)              (USBHS_DEVIER_PEP__Msk & ((value) << USBHS_DEVIER_PEP__Pos))
#define USBHS_DEVIER_DMA__Pos                 (25)                                           /**< (USBHS_DEVIER Position) DMA Channel 7 Interrupt Enable */
#define USBHS_DEVIER_DMA__Msk                 (0x7FU << USBHS_DEVIER_DMA__Pos)               /**< (USBHS_DEVIER Mask) DMA_ */
#define USBHS_DEVIER_DMA_(value)              (USBHS_DEVIER_DMA__Msk & ((value) << USBHS_DEVIER_DMA__Pos))

/* -------- USBHS_DEVEPT : (USBHS Offset: 0x1c) (R/W 32) Device Endpoint Register -------- */

typedef union
{
  struct
  {
    uint32_t EPEN0:1;                   /**< bit:      0  Endpoint 0 Enable                             */
    uint32_t EPEN1:1;                   /**< bit:      1  Endpoint 1 Enable                             */
    uint32_t EPEN2:1;                   /**< bit:      2  Endpoint 2 Enable                             */
    uint32_t EPEN3:1;                   /**< bit:      3  Endpoint 3 Enable                             */
    uint32_t EPEN4:1;                   /**< bit:      4  Endpoint 4 Enable                             */
    uint32_t EPEN5:1;                   /**< bit:      5  Endpoint 5 Enable                             */
    uint32_t EPEN6:1;                   /**< bit:      6  Endpoint 6 Enable                             */
    uint32_t EPEN7:1;                   /**< bit:      7  Endpoint 7 Enable                             */
    uint32_t EPEN8:1;                   /**< bit:      8  Endpoint 8 Enable                             */
    uint32_t EPEN9:1;                   /**< bit:      9  Endpoint 9 Enable                             */
    uint32_t :6;                        /**< bit: 10..15  Reserved                                      */
    uint32_t EPRST0:1;                  /**< bit:     16  Endpoint 0 Reset                              */
    uint32_t EPRST1:1;                  /**< bit:     17  Endpoint 1 Reset                              */
    uint32_t EPRST2:1;                  /**< bit:     18  Endpoint 2 Reset                              */
    uint32_t EPRST3:1;                  /**< bit:     19  Endpoint 3 Reset                              */
    uint32_t EPRST4:1;                  /**< bit:     20  Endpoint 4 Reset                              */
    uint32_t EPRST5:1;                  /**< bit:     21  Endpoint 5 Reset                              */
    uint32_t EPRST6:1;                  /**< bit:     22  Endpoint 6 Reset                              */
    uint32_t EPRST7:1;                  /**< bit:     23  Endpoint 7 Reset                              */
    uint32_t EPRST8:1;                  /**< bit:     24  Endpoint 8 Reset                              */
    uint32_t EPRST9:1;                  /**< bit:     25  Endpoint 9 Reset                              */
    uint32_t :6;                        /**< bit: 26..31  Reserved                                      */
  };
  struct
  {
    uint32_t EPEN:10;                   /**< bit:   0..9  Endpoint x Enable                             */
    uint32_t :6;                        /**< bit: 10..15  Reserved                                      */
    uint32_t EPRST:10;                  /**< bit: 16..25  Endpoint 9 Reset                              */
    uint32_t :6;                        /**< bit: 26..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_DEVEPT_bits_t;

#define USBHS_DEVEPT_EPEN0_Pos                (0)                                            /**< (USBHS_DEVEPT) Endpoint 0 Enable Position */
#define USBHS_DEVEPT_EPEN0_Msk                (0x1U << USBHS_DEVEPT_EPEN0_Pos)               /**< (USBHS_DEVEPT) Endpoint 0 Enable Mask */
#define USBHS_DEVEPT_EPEN1_Pos                (1)                                            /**< (USBHS_DEVEPT) Endpoint 1 Enable Position */
#define USBHS_DEVEPT_EPEN1_Msk                (0x1U << USBHS_DEVEPT_EPEN1_Pos)               /**< (USBHS_DEVEPT) Endpoint 1 Enable Mask */
#define USBHS_DEVEPT_EPEN2_Pos                (2)                                            /**< (USBHS_DEVEPT) Endpoint 2 Enable Position */
#define USBHS_DEVEPT_EPEN2_Msk                (0x1U << USBHS_DEVEPT_EPEN2_Pos)               /**< (USBHS_DEVEPT) Endpoint 2 Enable Mask */
#define USBHS_DEVEPT_EPEN3_Pos                (3)                                            /**< (USBHS_DEVEPT) Endpoint 3 Enable Position */
#define USBHS_DEVEPT_EPEN3_Msk                (0x1U << USBHS_DEVEPT_EPEN3_Pos)               /**< (USBHS_DEVEPT) Endpoint 3 Enable Mask */
#define USBHS_DEVEPT_EPEN4_Pos                (4)                                            /**< (USBHS_DEVEPT) Endpoint 4 Enable Position */
#define USBHS_DEVEPT_EPEN4_Msk                (0x1U << USBHS_DEVEPT_EPEN4_Pos)               /**< (USBHS_DEVEPT) Endpoint 4 Enable Mask */
#define USBHS_DEVEPT_EPEN5_Pos                (5)                                            /**< (USBHS_DEVEPT) Endpoint 5 Enable Position */
#define USBHS_DEVEPT_EPEN5_Msk                (0x1U << USBHS_DEVEPT_EPEN5_Pos)               /**< (USBHS_DEVEPT) Endpoint 5 Enable Mask */
#define USBHS_DEVEPT_EPEN6_Pos                (6)                                            /**< (USBHS_DEVEPT) Endpoint 6 Enable Position */
#define USBHS_DEVEPT_EPEN6_Msk                (0x1U << USBHS_DEVEPT_EPEN6_Pos)               /**< (USBHS_DEVEPT) Endpoint 6 Enable Mask */
#define USBHS_DEVEPT_EPEN7_Pos                (7)                                            /**< (USBHS_DEVEPT) Endpoint 7 Enable Position */
#define USBHS_DEVEPT_EPEN7_Msk                (0x1U << USBHS_DEVEPT_EPEN7_Pos)               /**< (USBHS_DEVEPT) Endpoint 7 Enable Mask */
#define USBHS_DEVEPT_EPEN8_Pos                (8)                                            /**< (USBHS_DEVEPT) Endpoint 8 Enable Position */
#define USBHS_DEVEPT_EPEN8_Msk                (0x1U << USBHS_DEVEPT_EPEN8_Pos)               /**< (USBHS_DEVEPT) Endpoint 8 Enable Mask */
#define USBHS_DEVEPT_EPEN9_Pos                (9)                                            /**< (USBHS_DEVEPT) Endpoint 9 Enable Position */
#define USBHS_DEVEPT_EPEN9_Msk                (0x1U << USBHS_DEVEPT_EPEN9_Pos)               /**< (USBHS_DEVEPT) Endpoint 9 Enable Mask */
#define USBHS_DEVEPT_EPRST0_Pos               (16)                                           /**< (USBHS_DEVEPT) Endpoint 0 Reset Position */
#define USBHS_DEVEPT_EPRST0_Msk               (0x1U << USBHS_DEVEPT_EPRST0_Pos)              /**< (USBHS_DEVEPT) Endpoint 0 Reset Mask */
#define USBHS_DEVEPT_EPRST1_Pos               (17)                                           /**< (USBHS_DEVEPT) Endpoint 1 Reset Position */
#define USBHS_DEVEPT_EPRST1_Msk               (0x1U << USBHS_DEVEPT_EPRST1_Pos)              /**< (USBHS_DEVEPT) Endpoint 1 Reset Mask */
#define USBHS_DEVEPT_EPRST2_Pos               (18)                                           /**< (USBHS_DEVEPT) Endpoint 2 Reset Position */
#define USBHS_DEVEPT_EPRST2_Msk               (0x1U << USBHS_DEVEPT_EPRST2_Pos)              /**< (USBHS_DEVEPT) Endpoint 2 Reset Mask */
#define USBHS_DEVEPT_EPRST3_Pos               (19)                                           /**< (USBHS_DEVEPT) Endpoint 3 Reset Position */
#define USBHS_DEVEPT_EPRST3_Msk               (0x1U << USBHS_DEVEPT_EPRST3_Pos)              /**< (USBHS_DEVEPT) Endpoint 3 Reset Mask */
#define USBHS_DEVEPT_EPRST4_Pos               (20)                                           /**< (USBHS_DEVEPT) Endpoint 4 Reset Position */
#define USBHS_DEVEPT_EPRST4_Msk               (0x1U << USBHS_DEVEPT_EPRST4_Pos)              /**< (USBHS_DEVEPT) Endpoint 4 Reset Mask */
#define USBHS_DEVEPT_EPRST5_Pos               (21)                                           /**< (USBHS_DEVEPT) Endpoint 5 Reset Position */
#define USBHS_DEVEPT_EPRST5_Msk               (0x1U << USBHS_DEVEPT_EPRST5_Pos)              /**< (USBHS_DEVEPT) Endpoint 5 Reset Mask */
#define USBHS_DEVEPT_EPRST6_Pos               (22)                                           /**< (USBHS_DEVEPT) Endpoint 6 Reset Position */
#define USBHS_DEVEPT_EPRST6_Msk               (0x1U << USBHS_DEVEPT_EPRST6_Pos)              /**< (USBHS_DEVEPT) Endpoint 6 Reset Mask */
#define USBHS_DEVEPT_EPRST7_Pos               (23)                                           /**< (USBHS_DEVEPT) Endpoint 7 Reset Position */
#define USBHS_DEVEPT_EPRST7_Msk               (0x1U << USBHS_DEVEPT_EPRST7_Pos)              /**< (USBHS_DEVEPT) Endpoint 7 Reset Mask */
#define USBHS_DEVEPT_EPRST8_Pos               (24)                                           /**< (USBHS_DEVEPT) Endpoint 8 Reset Position */
#define USBHS_DEVEPT_EPRST8_Msk               (0x1U << USBHS_DEVEPT_EPRST8_Pos)              /**< (USBHS_DEVEPT) Endpoint 8 Reset Mask */
#define USBHS_DEVEPT_EPRST9_Pos               (25)                                           /**< (USBHS_DEVEPT) Endpoint 9 Reset Position */
#define USBHS_DEVEPT_EPRST9_Msk               (0x1U << USBHS_DEVEPT_EPRST9_Pos)              /**< (USBHS_DEVEPT) Endpoint 9 Reset Mask */
#define USBHS_DEVEPT_Msk                      (0x03FF03FFUL)                                 /**< (USBHS_DEVEPT) Register Mask  */
#define USBHS_DEVEPT_EPEN_Pos                 (0)                                            /**< (USBHS_DEVEPT Position) Endpoint x Enable */
#define USBHS_DEVEPT_EPEN_Msk                 (0x3FFU << USBHS_DEVEPT_EPEN_Pos)              /**< (USBHS_DEVEPT Mask) EPEN */
#define USBHS_DEVEPT_EPEN(value)              (USBHS_DEVEPT_EPEN_Msk & ((value) << USBHS_DEVEPT_EPEN_Pos))
#define USBHS_DEVEPT_EPRST_Pos                (16)                                           /**< (USBHS_DEVEPT Position) Endpoint 9 Reset */
#define USBHS_DEVEPT_EPRST_Msk                (0x3FFU << USBHS_DEVEPT_EPRST_Pos)             /**< (USBHS_DEVEPT Mask) EPRST */
#define USBHS_DEVEPT_EPRST(value)             (USBHS_DEVEPT_EPRST_Msk & ((value) << USBHS_DEVEPT_EPRST_Pos))

/* -------- USBHS_DEVFNUM : (USBHS Offset: 0x20) (R/ 32) Device Frame Number Register -------- */

typedef union
{
  struct
  {
    uint32_t MFNUM:3;                   /**< bit:   0..2  Micro Frame Number                            */
    uint32_t FNUM:11;                   /**< bit:  3..13  Frame Number                                  */
    uint32_t :1;                        /**< bit:     14  Reserved                                      */
    uint32_t FNCERR:1;                  /**< bit:     15  Frame Number CRC Error                        */
    uint32_t :16;                       /**< bit: 16..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_DEVFNUM_bits_t;

#define USBHS_DEVFNUM_MFNUM_Pos               (0)                                            /**< (USBHS_DEVFNUM) Micro Frame Number Position */
#define USBHS_DEVFNUM_MFNUM_Msk               (0x7U << USBHS_DEVFNUM_MFNUM_Pos)              /**< (USBHS_DEVFNUM) Micro Frame Number Mask */
#define USBHS_DEVFNUM_MFNUM(value)            (USBHS_DEVFNUM_MFNUM_Msk & ((value) << USBHS_DEVFNUM_MFNUM_Pos))
#define USBHS_DEVFNUM_FNUM_Pos                (3)                                            /**< (USBHS_DEVFNUM) Frame Number Position */
#define USBHS_DEVFNUM_FNUM_Msk                (0x7FFU << USBHS_DEVFNUM_FNUM_Pos)             /**< (USBHS_DEVFNUM) Frame Number Mask */
#define USBHS_DEVFNUM_FNUM(value)             (USBHS_DEVFNUM_FNUM_Msk & ((value) << USBHS_DEVFNUM_FNUM_Pos))
#define USBHS_DEVFNUM_FNCERR_Pos              (15)                                           /**< (USBHS_DEVFNUM) Frame Number CRC Error Position */
#define USBHS_DEVFNUM_FNCERR_Msk              (0x1U << USBHS_DEVFNUM_FNCERR_Pos)             /**< (USBHS_DEVFNUM) Frame Number CRC Error Mask */
#define USBHS_DEVFNUM_Msk                     (0x0000BFFFUL)                                 /**< (USBHS_DEVFNUM) Register Mask  */

/* -------- USBHS_DEVEPTCFG : (USBHS Offset: 0x100) (R/W 32) Device Endpoint Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t :1;                        /**< bit:      0  Reserved                                      */
    uint32_t ALLOC:1;                   /**< bit:      1  Endpoint Memory Allocate                      */
    uint32_t EPBK:2;                    /**< bit:   2..3  Endpoint Banks                                */
    uint32_t EPSIZE:3;                  /**< bit:   4..6  Endpoint Size                                 */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t EPDIR:1;                   /**< bit:      8  Endpoint Direction                            */
    uint32_t AUTOSW:1;                  /**< bit:      9  Automatic Switch                              */
    uint32_t :1;                        /**< bit:     10  Reserved                                      */
    uint32_t EPTYPE:2;                  /**< bit: 11..12  Endpoint Type                                 */
    uint32_t NBTRANS:2;                 /**< bit: 13..14  Number of transactions per microframe for isochronous endpoint */
    uint32_t :17;                       /**< bit: 15..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_DEVEPTCFG_bits_t;

#define USBHS_DEVEPTCFG_ALLOC_Pos             (1)                                            /**< (USBHS_DEVEPTCFG) Endpoint Memory Allocate Position */
#define USBHS_DEVEPTCFG_ALLOC_Msk             (0x1U << USBHS_DEVEPTCFG_ALLOC_Pos)            /**< (USBHS_DEVEPTCFG) Endpoint Memory Allocate Mask */
#define USBHS_DEVEPTCFG_EPBK_Pos              (2)                                            /**< (USBHS_DEVEPTCFG) Endpoint Banks Position */
#define USBHS_DEVEPTCFG_EPBK_Msk              (0x3U << USBHS_DEVEPTCFG_EPBK_Pos)             /**< (USBHS_DEVEPTCFG) Endpoint Banks Mask */
#define USBHS_DEVEPTCFG_EPBK(value)           (USBHS_DEVEPTCFG_EPBK_Msk & ((value) << USBHS_DEVEPTCFG_EPBK_Pos))
#define   USBHS_DEVEPTCFG_EPBK_1_BANK_Val     (0x0U)                                         /**< (USBHS_DEVEPTCFG) Single-bank endpoint  */
#define   USBHS_DEVEPTCFG_EPBK_2_BANK_Val     (0x1U)                                         /**< (USBHS_DEVEPTCFG) Double-bank endpoint  */
#define   USBHS_DEVEPTCFG_EPBK_3_BANK_Val     (0x2U)                                         /**< (USBHS_DEVEPTCFG) Triple-bank endpoint  */
#define USBHS_DEVEPTCFG_EPBK_1_BANK           (USBHS_DEVEPTCFG_EPBK_1_BANK_Val << USBHS_DEVEPTCFG_EPBK_Pos)  /**< (USBHS_DEVEPTCFG) Single-bank endpoint Position  */
#define USBHS_DEVEPTCFG_EPBK_2_BANK           (USBHS_DEVEPTCFG_EPBK_2_BANK_Val << USBHS_DEVEPTCFG_EPBK_Pos)  /**< (USBHS_DEVEPTCFG) Double-bank endpoint Position  */
#define USBHS_DEVEPTCFG_EPBK_3_BANK           (USBHS_DEVEPTCFG_EPBK_3_BANK_Val << USBHS_DEVEPTCFG_EPBK_Pos)  /**< (USBHS_DEVEPTCFG) Triple-bank endpoint Position  */
#define USBHS_DEVEPTCFG_EPSIZE_Pos            (4)                                            /**< (USBHS_DEVEPTCFG) Endpoint Size Position */
#define USBHS_DEVEPTCFG_EPSIZE_Msk            (0x7U << USBHS_DEVEPTCFG_EPSIZE_Pos)           /**< (USBHS_DEVEPTCFG) Endpoint Size Mask */
#define USBHS_DEVEPTCFG_EPSIZE(value)         (USBHS_DEVEPTCFG_EPSIZE_Msk & ((value) << USBHS_DEVEPTCFG_EPSIZE_Pos))
#define   USBHS_DEVEPTCFG_EPSIZE_8_BYTE_Val   (0x0U)                                         /**< (USBHS_DEVEPTCFG) 8 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_16_BYTE_Val  (0x1U)                                         /**< (USBHS_DEVEPTCFG) 16 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_32_BYTE_Val  (0x2U)                                         /**< (USBHS_DEVEPTCFG) 32 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_64_BYTE_Val  (0x3U)                                         /**< (USBHS_DEVEPTCFG) 64 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_128_BYTE_Val (0x4U)                                         /**< (USBHS_DEVEPTCFG) 128 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_256_BYTE_Val (0x5U)                                         /**< (USBHS_DEVEPTCFG) 256 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_512_BYTE_Val (0x6U)                                         /**< (USBHS_DEVEPTCFG) 512 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_1024_BYTE_Val (0x7U)                                         /**< (USBHS_DEVEPTCFG) 1024 bytes  */
#define USBHS_DEVEPTCFG_EPSIZE_8_BYTE         (USBHS_DEVEPTCFG_EPSIZE_8_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos)  /**< (USBHS_DEVEPTCFG) 8 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_16_BYTE        (USBHS_DEVEPTCFG_EPSIZE_16_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos)  /**< (USBHS_DEVEPTCFG) 16 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_32_BYTE        (USBHS_DEVEPTCFG_EPSIZE_32_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos)  /**< (USBHS_DEVEPTCFG) 32 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_64_BYTE        (USBHS_DEVEPTCFG_EPSIZE_64_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos)  /**< (USBHS_DEVEPTCFG) 64 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_128_BYTE       (USBHS_DEVEPTCFG_EPSIZE_128_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos)  /**< (USBHS_DEVEPTCFG) 128 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_256_BYTE       (USBHS_DEVEPTCFG_EPSIZE_256_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos)  /**< (USBHS_DEVEPTCFG) 256 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_512_BYTE       (USBHS_DEVEPTCFG_EPSIZE_512_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos)  /**< (USBHS_DEVEPTCFG) 512 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_1024_BYTE      (USBHS_DEVEPTCFG_EPSIZE_1024_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos)  /**< (USBHS_DEVEPTCFG) 1024 bytes Position  */
#define USBHS_DEVEPTCFG_EPDIR_Pos             (8)                                            /**< (USBHS_DEVEPTCFG) Endpoint Direction Position */
#define USBHS_DEVEPTCFG_EPDIR_Msk             (0x1U << USBHS_DEVEPTCFG_EPDIR_Pos)            /**< (USBHS_DEVEPTCFG) Endpoint Direction Mask */
#define   USBHS_DEVEPTCFG_EPDIR_OUT_Val       (0x0U)                                         /**< (USBHS_DEVEPTCFG) The endpoint direction is OUT.  */
#define   USBHS_DEVEPTCFG_EPDIR_IN_Val        (0x1U)                                         /**< (USBHS_DEVEPTCFG) The endpoint direction is IN (nor for control endpoints).  */
#define USBHS_DEVEPTCFG_EPDIR_OUT             (USBHS_DEVEPTCFG_EPDIR_OUT_Val << USBHS_DEVEPTCFG_EPDIR_Pos)  /**< (USBHS_DEVEPTCFG) The endpoint direction is OUT. Position  */
#define USBHS_DEVEPTCFG_EPDIR_IN              (USBHS_DEVEPTCFG_EPDIR_IN_Val << USBHS_DEVEPTCFG_EPDIR_Pos)  /**< (USBHS_DEVEPTCFG) The endpoint direction is IN (nor for control endpoints). Position  */
#define USBHS_DEVEPTCFG_AUTOSW_Pos            (9)                                            /**< (USBHS_DEVEPTCFG) Automatic Switch Position */
#define USBHS_DEVEPTCFG_AUTOSW_Msk            (0x1U << USBHS_DEVEPTCFG_AUTOSW_Pos)           /**< (USBHS_DEVEPTCFG) Automatic Switch Mask */
#define USBHS_DEVEPTCFG_EPTYPE_Pos            (11)                                           /**< (USBHS_DEVEPTCFG) Endpoint Type Position */
#define USBHS_DEVEPTCFG_EPTYPE_Msk            (0x3U << USBHS_DEVEPTCFG_EPTYPE_Pos)           /**< (USBHS_DEVEPTCFG) Endpoint Type Mask */
#define USBHS_DEVEPTCFG_EPTYPE(value)         (USBHS_DEVEPTCFG_EPTYPE_Msk & ((value) << USBHS_DEVEPTCFG_EPTYPE_Pos))
#define   USBHS_DEVEPTCFG_EPTYPE_CTRL_Val     (0x0U)                                         /**< (USBHS_DEVEPTCFG) Control  */
#define   USBHS_DEVEPTCFG_EPTYPE_ISO_Val      (0x1U)                                         /**< (USBHS_DEVEPTCFG) Isochronous  */
#define   USBHS_DEVEPTCFG_EPTYPE_BLK_Val      (0x2U)                                         /**< (USBHS_DEVEPTCFG) Bulk  */
#define   USBHS_DEVEPTCFG_EPTYPE_INTRPT_Val   (0x3U)                                         /**< (USBHS_DEVEPTCFG) Interrupt  */
#define USBHS_DEVEPTCFG_EPTYPE_CTRL           (USBHS_DEVEPTCFG_EPTYPE_CTRL_Val << USBHS_DEVEPTCFG_EPTYPE_Pos)  /**< (USBHS_DEVEPTCFG) Control Position  */
#define USBHS_DEVEPTCFG_EPTYPE_ISO            (USBHS_DEVEPTCFG_EPTYPE_ISO_Val << USBHS_DEVEPTCFG_EPTYPE_Pos)  /**< (USBHS_DEVEPTCFG) Isochronous Position  */
#define USBHS_DEVEPTCFG_EPTYPE_BLK            (USBHS_DEVEPTCFG_EPTYPE_BLK_Val << USBHS_DEVEPTCFG_EPTYPE_Pos)  /**< (USBHS_DEVEPTCFG) Bulk Position  */
#define USBHS_DEVEPTCFG_EPTYPE_INTRPT         (USBHS_DEVEPTCFG_EPTYPE_INTRPT_Val << USBHS_DEVEPTCFG_EPTYPE_Pos)  /**< (USBHS_DEVEPTCFG) Interrupt Position  */
#define USBHS_DEVEPTCFG_NBTRANS_Pos           (13)                                           /**< (USBHS_DEVEPTCFG) Number of transactions per microframe for isochronous endpoint Position */
#define USBHS_DEVEPTCFG_NBTRANS_Msk           (0x3U << USBHS_DEVEPTCFG_NBTRANS_Pos)          /**< (USBHS_DEVEPTCFG) Number of transactions per microframe for isochronous endpoint Mask */
#define USBHS_DEVEPTCFG_NBTRANS(value)        (USBHS_DEVEPTCFG_NBTRANS_Msk & ((value) << USBHS_DEVEPTCFG_NBTRANS_Pos))
#define   USBHS_DEVEPTCFG_NBTRANS_0_TRANS_Val (0x0U)                                         /**< (USBHS_DEVEPTCFG) Reserved to endpoint that does not have the high-bandwidth isochronous capability.  */
#define   USBHS_DEVEPTCFG_NBTRANS_1_TRANS_Val (0x1U)                                         /**< (USBHS_DEVEPTCFG) Default value: one transaction per microframe.  */
#define   USBHS_DEVEPTCFG_NBTRANS_2_TRANS_Val (0x2U)                                         /**< (USBHS_DEVEPTCFG) Two transactions per microframe. This endpoint should be configured as double-bank.  */
#define   USBHS_DEVEPTCFG_NBTRANS_3_TRANS_Val (0x3U)                                         /**< (USBHS_DEVEPTCFG) Three transactions per microframe. This endpoint should be configured as triple-bank.  */
#define USBHS_DEVEPTCFG_NBTRANS_0_TRANS       (USBHS_DEVEPTCFG_NBTRANS_0_TRANS_Val << USBHS_DEVEPTCFG_NBTRANS_Pos)  /**< (USBHS_DEVEPTCFG) Reserved to endpoint that does not have the high-bandwidth isochronous capability. Position  */
#define USBHS_DEVEPTCFG_NBTRANS_1_TRANS       (USBHS_DEVEPTCFG_NBTRANS_1_TRANS_Val << USBHS_DEVEPTCFG_NBTRANS_Pos)  /**< (USBHS_DEVEPTCFG) Default value: one transaction per microframe. Position  */
#define USBHS_DEVEPTCFG_NBTRANS_2_TRANS       (USBHS_DEVEPTCFG_NBTRANS_2_TRANS_Val << USBHS_DEVEPTCFG_NBTRANS_Pos)  /**< (USBHS_DEVEPTCFG) Two transactions per microframe. This endpoint should be configured as double-bank. Position  */
#define USBHS_DEVEPTCFG_NBTRANS_3_TRANS       (USBHS_DEVEPTCFG_NBTRANS_3_TRANS_Val << USBHS_DEVEPTCFG_NBTRANS_Pos)  /**< (USBHS_DEVEPTCFG) Three transactions per microframe. This endpoint should be configured as triple-bank. Position  */
#define USBHS_DEVEPTCFG_Msk                   (0x00007B7EUL)                                 /**< (USBHS_DEVEPTCFG) Register Mask  */

/* -------- USBHS_DEVEPTISR : (USBHS Offset: 0x130) (R/ 32) Device Endpoint Status Register -------- */

typedef union
{
  struct
  {
    uint32_t TXINI:1;                   /**< bit:      0  Transmitted IN Data Interrupt                 */
    uint32_t RXOUTI:1;                  /**< bit:      1  Received OUT Data Interrupt                   */
    uint32_t RXSTPI:1;                  /**< bit:      2  Received SETUP Interrupt                      */
    uint32_t NAKOUTI:1;                 /**< bit:      3  NAKed OUT Interrupt                           */
    uint32_t NAKINI:1;                  /**< bit:      4  NAKed IN Interrupt                            */
    uint32_t OVERFI:1;                  /**< bit:      5  Overflow Interrupt                            */
    uint32_t STALLEDI:1;                /**< bit:      6  STALLed Interrupt                             */
    uint32_t SHORTPACKET:1;             /**< bit:      7  Short Packet Interrupt                        */
    uint32_t DTSEQ:2;                   /**< bit:   8..9  Data Toggle Sequence                          */
    uint32_t :2;                        /**< bit: 10..11  Reserved                                      */
    uint32_t NBUSYBK:2;                 /**< bit: 12..13  Number of Busy Banks                          */
    uint32_t CURRBK:2;                  /**< bit: 14..15  Current Bank                                  */
    uint32_t RWALL:1;                   /**< bit:     16  Read/Write Allowed                            */
    uint32_t :1;                        /**< bit:     17  Reserved                                      */
    uint32_t CFGOK:1;                   /**< bit:     18  Configuration OK Status                       */
    uint32_t :1;                        /**< bit:     19  Reserved                                      */
    uint32_t BYCT:11;                   /**< bit: 20..30  Byte Count                                    */
    uint32_t :1;                        /**< bit:     31  Reserved                                      */
  };
  struct
  { // Control, Bulk and Interrupt Endpoints mode
    uint32_t :17;                       /**< bit:  0..16  Reserved                                      */
    uint32_t CTRLDIR:1;                 /**< bit:     17  Control Direction                             */
    uint32_t :14;                       /**< bit: 18..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFI:1;                 /**< bit:      2  Underflow Interrupt                           */
    uint32_t HBISOINERRI:1;             /**< bit:      3  High Bandwidth Isochronous IN Underflow Error Interrupt */
    uint32_t HBISOFLUSHI:1;             /**< bit:      4  High Bandwidth Isochronous IN Flush Interrupt */
    uint32_t :1;                        /**< bit:      5  Reserved                                      */
    uint32_t CRCERRI:1;                 /**< bit:      6  CRC Error Interrupt                           */
    uint32_t :3;                        /**< bit:   7..9  Reserved                                      */
    uint32_t ERRORTRANS:1;              /**< bit:     10  High-bandwidth Isochronous OUT Endpoint Transaction Error Interrupt */
    uint32_t :21;                       /**< bit: 11..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_DEVEPTISR_bits_t;

#define USBHS_DEVEPTISR_TXINI_Pos             (0)                                            /**< (USBHS_DEVEPTISR) Transmitted IN Data Interrupt Position */
#define USBHS_DEVEPTISR_TXINI_Msk             (0x1U << USBHS_DEVEPTISR_TXINI_Pos)            /**< (USBHS_DEVEPTISR) Transmitted IN Data Interrupt Mask */
#define USBHS_DEVEPTISR_RXOUTI_Pos            (1)                                            /**< (USBHS_DEVEPTISR) Received OUT Data Interrupt Position */
#define USBHS_DEVEPTISR_RXOUTI_Msk            (0x1U << USBHS_DEVEPTISR_RXOUTI_Pos)           /**< (USBHS_DEVEPTISR) Received OUT Data Interrupt Mask */
#define USBHS_DEVEPTISR_RXSTPI_Pos            (2)                                            /**< (USBHS_DEVEPTISR) Received SETUP Interrupt Position */
#define USBHS_DEVEPTISR_RXSTPI_Msk            (0x1U << USBHS_DEVEPTISR_RXSTPI_Pos)           /**< (USBHS_DEVEPTISR) Received SETUP Interrupt Mask */
#define USBHS_DEVEPTISR_NAKOUTI_Pos           (3)                                            /**< (USBHS_DEVEPTISR) NAKed OUT Interrupt Position */
#define USBHS_DEVEPTISR_NAKOUTI_Msk           (0x1U << USBHS_DEVEPTISR_NAKOUTI_Pos)          /**< (USBHS_DEVEPTISR) NAKed OUT Interrupt Mask */
#define USBHS_DEVEPTISR_NAKINI_Pos            (4)                                            /**< (USBHS_DEVEPTISR) NAKed IN Interrupt Position */
#define USBHS_DEVEPTISR_NAKINI_Msk            (0x1U << USBHS_DEVEPTISR_NAKINI_Pos)           /**< (USBHS_DEVEPTISR) NAKed IN Interrupt Mask */
#define USBHS_DEVEPTISR_OVERFI_Pos            (5)                                            /**< (USBHS_DEVEPTISR) Overflow Interrupt Position */
#define USBHS_DEVEPTISR_OVERFI_Msk            (0x1U << USBHS_DEVEPTISR_OVERFI_Pos)           /**< (USBHS_DEVEPTISR) Overflow Interrupt Mask */
#define USBHS_DEVEPTISR_STALLEDI_Pos          (6)                                            /**< (USBHS_DEVEPTISR) STALLed Interrupt Position */
#define USBHS_DEVEPTISR_STALLEDI_Msk          (0x1U << USBHS_DEVEPTISR_STALLEDI_Pos)         /**< (USBHS_DEVEPTISR) STALLed Interrupt Mask */
#define USBHS_DEVEPTISR_SHORTPACKET_Pos       (7)                                            /**< (USBHS_DEVEPTISR) Short Packet Interrupt Position */
#define USBHS_DEVEPTISR_SHORTPACKET_Msk       (0x1U << USBHS_DEVEPTISR_SHORTPACKET_Pos)      /**< (USBHS_DEVEPTISR) Short Packet Interrupt Mask */
#define USBHS_DEVEPTISR_DTSEQ_Pos             (8)                                            /**< (USBHS_DEVEPTISR) Data Toggle Sequence Position */
#define USBHS_DEVEPTISR_DTSEQ_Msk             (0x3U << USBHS_DEVEPTISR_DTSEQ_Pos)            /**< (USBHS_DEVEPTISR) Data Toggle Sequence Mask */
#define USBHS_DEVEPTISR_DTSEQ(value)          (USBHS_DEVEPTISR_DTSEQ_Msk & ((value) << USBHS_DEVEPTISR_DTSEQ_Pos))
#define   USBHS_DEVEPTISR_DTSEQ_DATA0_Val     (0x0U)                                         /**< (USBHS_DEVEPTISR) Data0 toggle sequence  */
#define   USBHS_DEVEPTISR_DTSEQ_DATA1_Val     (0x1U)                                         /**< (USBHS_DEVEPTISR) Data1 toggle sequence  */
#define   USBHS_DEVEPTISR_DTSEQ_DATA2_Val     (0x2U)                                         /**< (USBHS_DEVEPTISR) Reserved for high-bandwidth isochronous endpoint  */
#define   USBHS_DEVEPTISR_DTSEQ_MDATA_Val     (0x3U)                                         /**< (USBHS_DEVEPTISR) Reserved for high-bandwidth isochronous endpoint  */
#define USBHS_DEVEPTISR_DTSEQ_DATA0           (USBHS_DEVEPTISR_DTSEQ_DATA0_Val << USBHS_DEVEPTISR_DTSEQ_Pos)  /**< (USBHS_DEVEPTISR) Data0 toggle sequence Position  */
#define USBHS_DEVEPTISR_DTSEQ_DATA1           (USBHS_DEVEPTISR_DTSEQ_DATA1_Val << USBHS_DEVEPTISR_DTSEQ_Pos)  /**< (USBHS_DEVEPTISR) Data1 toggle sequence Position  */
#define USBHS_DEVEPTISR_DTSEQ_DATA2           (USBHS_DEVEPTISR_DTSEQ_DATA2_Val << USBHS_DEVEPTISR_DTSEQ_Pos)  /**< (USBHS_DEVEPTISR) Reserved for high-bandwidth isochronous endpoint Position  */
#define USBHS_DEVEPTISR_DTSEQ_MDATA           (USBHS_DEVEPTISR_DTSEQ_MDATA_Val << USBHS_DEVEPTISR_DTSEQ_Pos)  /**< (USBHS_DEVEPTISR) Reserved for high-bandwidth isochronous endpoint Position  */
#define USBHS_DEVEPTISR_NBUSYBK_Pos           (12)                                           /**< (USBHS_DEVEPTISR) Number of Busy Banks Position */
#define USBHS_DEVEPTISR_NBUSYBK_Msk           (0x3U << USBHS_DEVEPTISR_NBUSYBK_Pos)          /**< (USBHS_DEVEPTISR) Number of Busy Banks Mask */
#define USBHS_DEVEPTISR_NBUSYBK(value)        (USBHS_DEVEPTISR_NBUSYBK_Msk & ((value) << USBHS_DEVEPTISR_NBUSYBK_Pos))
#define   USBHS_DEVEPTISR_NBUSYBK_0_BUSY_Val  (0x0U)                                         /**< (USBHS_DEVEPTISR) 0 busy bank (all banks free)  */
#define   USBHS_DEVEPTISR_NBUSYBK_1_BUSY_Val  (0x1U)                                         /**< (USBHS_DEVEPTISR) 1 busy bank  */
#define   USBHS_DEVEPTISR_NBUSYBK_2_BUSY_Val  (0x2U)                                         /**< (USBHS_DEVEPTISR) 2 busy banks  */
#define   USBHS_DEVEPTISR_NBUSYBK_3_BUSY_Val  (0x3U)                                         /**< (USBHS_DEVEPTISR) 3 busy banks  */
#define USBHS_DEVEPTISR_NBUSYBK_0_BUSY        (USBHS_DEVEPTISR_NBUSYBK_0_BUSY_Val << USBHS_DEVEPTISR_NBUSYBK_Pos)  /**< (USBHS_DEVEPTISR) 0 busy bank (all banks free) Position  */
#define USBHS_DEVEPTISR_NBUSYBK_1_BUSY        (USBHS_DEVEPTISR_NBUSYBK_1_BUSY_Val << USBHS_DEVEPTISR_NBUSYBK_Pos)  /**< (USBHS_DEVEPTISR) 1 busy bank Position  */
#define USBHS_DEVEPTISR_NBUSYBK_2_BUSY        (USBHS_DEVEPTISR_NBUSYBK_2_BUSY_Val << USBHS_DEVEPTISR_NBUSYBK_Pos)  /**< (USBHS_DEVEPTISR) 2 busy banks Position  */
#define USBHS_DEVEPTISR_NBUSYBK_3_BUSY        (USBHS_DEVEPTISR_NBUSYBK_3_BUSY_Val << USBHS_DEVEPTISR_NBUSYBK_Pos)  /**< (USBHS_DEVEPTISR) 3 busy banks Position  */
#define USBHS_DEVEPTISR_CURRBK_Pos            (14)                                           /**< (USBHS_DEVEPTISR) Current Bank Position */
#define USBHS_DEVEPTISR_CURRBK_Msk            (0x3U << USBHS_DEVEPTISR_CURRBK_Pos)           /**< (USBHS_DEVEPTISR) Current Bank Mask */
#define USBHS_DEVEPTISR_CURRBK(value)         (USBHS_DEVEPTISR_CURRBK_Msk & ((value) << USBHS_DEVEPTISR_CURRBK_Pos))
#define   USBHS_DEVEPTISR_CURRBK_BANK0_Val    (0x0U)                                         /**< (USBHS_DEVEPTISR) Current bank is bank0  */
#define   USBHS_DEVEPTISR_CURRBK_BANK1_Val    (0x1U)                                         /**< (USBHS_DEVEPTISR) Current bank is bank1  */
#define   USBHS_DEVEPTISR_CURRBK_BANK2_Val    (0x2U)                                         /**< (USBHS_DEVEPTISR) Current bank is bank2  */
#define USBHS_DEVEPTISR_CURRBK_BANK0          (USBHS_DEVEPTISR_CURRBK_BANK0_Val << USBHS_DEVEPTISR_CURRBK_Pos)  /**< (USBHS_DEVEPTISR) Current bank is bank0 Position  */
#define USBHS_DEVEPTISR_CURRBK_BANK1          (USBHS_DEVEPTISR_CURRBK_BANK1_Val << USBHS_DEVEPTISR_CURRBK_Pos)  /**< (USBHS_DEVEPTISR) Current bank is bank1 Position  */
#define USBHS_DEVEPTISR_CURRBK_BANK2          (USBHS_DEVEPTISR_CURRBK_BANK2_Val << USBHS_DEVEPTISR_CURRBK_Pos)  /**< (USBHS_DEVEPTISR) Current bank is bank2 Position  */
#define USBHS_DEVEPTISR_RWALL_Pos             (16)                                           /**< (USBHS_DEVEPTISR) Read/Write Allowed Position */
#define USBHS_DEVEPTISR_RWALL_Msk             (0x1U << USBHS_DEVEPTISR_RWALL_Pos)            /**< (USBHS_DEVEPTISR) Read/Write Allowed Mask */
#define USBHS_DEVEPTISR_CFGOK_Pos             (18)                                           /**< (USBHS_DEVEPTISR) Configuration OK Status Position */
#define USBHS_DEVEPTISR_CFGOK_Msk             (0x1U << USBHS_DEVEPTISR_CFGOK_Pos)            /**< (USBHS_DEVEPTISR) Configuration OK Status Mask */
#define USBHS_DEVEPTISR_BYCT_Pos              (20)                                           /**< (USBHS_DEVEPTISR) Byte Count Position */
#define USBHS_DEVEPTISR_BYCT_Msk              (0x7FFU << USBHS_DEVEPTISR_BYCT_Pos)           /**< (USBHS_DEVEPTISR) Byte Count Mask */
#define USBHS_DEVEPTISR_BYCT(value)           (USBHS_DEVEPTISR_BYCT_Msk & ((value) << USBHS_DEVEPTISR_BYCT_Pos))
/* Control, Bulk and Interrupt Endpoints mode */
#define USBHS_DEVEPTISR_CTRLDIR_Pos           (17)                                           /**< (USBHS_DEVEPTISR) Control Direction Position */
#define USBHS_DEVEPTISR_CTRLDIR_Msk           (0x1U << USBHS_DEVEPTISR_CTRLDIR_Pos)          /**< (USBHS_DEVEPTISR) Control Direction Mask */
/* Isochronous Endpoints mode */
#define USBHS_DEVEPTISR_UNDERFI_Pos           (2)                                            /**< (USBHS_DEVEPTISR) Underflow Interrupt Position */
#define USBHS_DEVEPTISR_UNDERFI_Msk           (0x1U << USBHS_DEVEPTISR_UNDERFI_Pos)          /**< (USBHS_DEVEPTISR) Underflow Interrupt Mask */
#define USBHS_DEVEPTISR_HBISOINERRI_Pos       (3)                                            /**< (USBHS_DEVEPTISR) High Bandwidth Isochronous IN Underflow Error Interrupt Position */
#define USBHS_DEVEPTISR_HBISOINERRI_Msk       (0x1U << USBHS_DEVEPTISR_HBISOINERRI_Pos)      /**< (USBHS_DEVEPTISR) High Bandwidth Isochronous IN Underflow Error Interrupt Mask */
#define USBHS_DEVEPTISR_HBISOFLUSHI_Pos       (4)                                            /**< (USBHS_DEVEPTISR) High Bandwidth Isochronous IN Flush Interrupt Position */
#define USBHS_DEVEPTISR_HBISOFLUSHI_Msk       (0x1U << USBHS_DEVEPTISR_HBISOFLUSHI_Pos)      /**< (USBHS_DEVEPTISR) High Bandwidth Isochronous IN Flush Interrupt Mask */
#define USBHS_DEVEPTISR_CRCERRI_Pos           (6)                                            /**< (USBHS_DEVEPTISR) CRC Error Interrupt Position */
#define USBHS_DEVEPTISR_CRCERRI_Msk           (0x1U << USBHS_DEVEPTISR_CRCERRI_Pos)          /**< (USBHS_DEVEPTISR) CRC Error Interrupt Mask */
#define USBHS_DEVEPTISR_ERRORTRANS_Pos        (10)                                           /**< (USBHS_DEVEPTISR) High-bandwidth Isochronous OUT Endpoint Transaction Error Interrupt Position */
#define USBHS_DEVEPTISR_ERRORTRANS_Msk        (0x1U << USBHS_DEVEPTISR_ERRORTRANS_Pos)       /**< (USBHS_DEVEPTISR) High-bandwidth Isochronous OUT Endpoint Transaction Error Interrupt Mask */

/* -------- USBHS_DEVEPTICR : (USBHS Offset: 0x160) (/W 32) Device Endpoint Clear Register -------- */

typedef union
{
  struct
  {
    uint32_t TXINIC:1;                  /**< bit:      0  Transmitted IN Data Interrupt Clear           */
    uint32_t RXOUTIC:1;                 /**< bit:      1  Received OUT Data Interrupt Clear             */
    uint32_t RXSTPIC:1;                 /**< bit:      2  Received SETUP Interrupt Clear                */
    uint32_t NAKOUTIC:1;                /**< bit:      3  NAKed OUT Interrupt Clear                     */
    uint32_t NAKINIC:1;                 /**< bit:      4  NAKed IN Interrupt Clear                      */
    uint32_t OVERFIC:1;                 /**< bit:      5  Overflow Interrupt Clear                      */
    uint32_t STALLEDIC:1;               /**< bit:      6  STALLed Interrupt Clear                       */
    uint32_t SHORTPACKETC:1;            /**< bit:      7  Short Packet Interrupt Clear                  */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFIC:1;                /**< bit:      2  Underflow Interrupt Clear                     */
    uint32_t HBISOINERRIC:1;            /**< bit:      3  High Bandwidth Isochronous IN Underflow Error Interrupt Clear */
    uint32_t HBISOFLUSHIC:1;            /**< bit:      4  High Bandwidth Isochronous IN Flush Interrupt Clear */
    uint32_t :1;                        /**< bit:      5  Reserved                                      */
    uint32_t CRCERRIC:1;                /**< bit:      6  CRC Error Interrupt Clear                     */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_DEVEPTICR_bits_t;

#define USBHS_DEVEPTICR_TXINIC_Pos            (0)                                            /**< (USBHS_DEVEPTICR) Transmitted IN Data Interrupt Clear Position */
#define USBHS_DEVEPTICR_TXINIC_Msk            (0x1U << USBHS_DEVEPTICR_TXINIC_Pos)           /**< (USBHS_DEVEPTICR) Transmitted IN Data Interrupt Clear Mask */
#define USBHS_DEVEPTICR_RXOUTIC_Pos           (1)                                            /**< (USBHS_DEVEPTICR) Received OUT Data Interrupt Clear Position */
#define USBHS_DEVEPTICR_RXOUTIC_Msk           (0x1U << USBHS_DEVEPTICR_RXOUTIC_Pos)          /**< (USBHS_DEVEPTICR) Received OUT Data Interrupt Clear Mask */
#define USBHS_DEVEPTICR_RXSTPIC_Pos           (2)                                            /**< (USBHS_DEVEPTICR) Received SETUP Interrupt Clear Position */
#define USBHS_DEVEPTICR_RXSTPIC_Msk           (0x1U << USBHS_DEVEPTICR_RXSTPIC_Pos)          /**< (USBHS_DEVEPTICR) Received SETUP Interrupt Clear Mask */
#define USBHS_DEVEPTICR_NAKOUTIC_Pos          (3)                                            /**< (USBHS_DEVEPTICR) NAKed OUT Interrupt Clear Position */
#define USBHS_DEVEPTICR_NAKOUTIC_Msk          (0x1U << USBHS_DEVEPTICR_NAKOUTIC_Pos)         /**< (USBHS_DEVEPTICR) NAKed OUT Interrupt Clear Mask */
#define USBHS_DEVEPTICR_NAKINIC_Pos           (4)                                            /**< (USBHS_DEVEPTICR) NAKed IN Interrupt Clear Position */
#define USBHS_DEVEPTICR_NAKINIC_Msk           (0x1U << USBHS_DEVEPTICR_NAKINIC_Pos)          /**< (USBHS_DEVEPTICR) NAKed IN Interrupt Clear Mask */
#define USBHS_DEVEPTICR_OVERFIC_Pos           (5)                                            /**< (USBHS_DEVEPTICR) Overflow Interrupt Clear Position */
#define USBHS_DEVEPTICR_OVERFIC_Msk           (0x1U << USBHS_DEVEPTICR_OVERFIC_Pos)          /**< (USBHS_DEVEPTICR) Overflow Interrupt Clear Mask */
#define USBHS_DEVEPTICR_STALLEDIC_Pos         (6)                                            /**< (USBHS_DEVEPTICR) STALLed Interrupt Clear Position */
#define USBHS_DEVEPTICR_STALLEDIC_Msk         (0x1U << USBHS_DEVEPTICR_STALLEDIC_Pos)        /**< (USBHS_DEVEPTICR) STALLed Interrupt Clear Mask */
#define USBHS_DEVEPTICR_SHORTPACKETC_Pos      (7)                                            /**< (USBHS_DEVEPTICR) Short Packet Interrupt Clear Position */
#define USBHS_DEVEPTICR_SHORTPACKETC_Msk      (0x1U << USBHS_DEVEPTICR_SHORTPACKETC_Pos)     /**< (USBHS_DEVEPTICR) Short Packet Interrupt Clear Mask */
/* Isochronous Endpoints mode */
#define USBHS_DEVEPTICR_UNDERFIC_Pos          (2)                                            /**< (USBHS_DEVEPTICR) Underflow Interrupt Clear Position */
#define USBHS_DEVEPTICR_UNDERFIC_Msk          (0x1U << USBHS_DEVEPTICR_UNDERFIC_Pos)         /**< (USBHS_DEVEPTICR) Underflow Interrupt Clear Mask */
#define USBHS_DEVEPTICR_HBISOINERRIC_Pos      (3)                                            /**< (USBHS_DEVEPTICR) High Bandwidth Isochronous IN Underflow Error Interrupt Clear Position */
#define USBHS_DEVEPTICR_HBISOINERRIC_Msk      (0x1U << USBHS_DEVEPTICR_HBISOINERRIC_Pos)     /**< (USBHS_DEVEPTICR) High Bandwidth Isochronous IN Underflow Error Interrupt Clear Mask */
#define USBHS_DEVEPTICR_HBISOFLUSHIC_Pos      (4)                                            /**< (USBHS_DEVEPTICR) High Bandwidth Isochronous IN Flush Interrupt Clear Position */
#define USBHS_DEVEPTICR_HBISOFLUSHIC_Msk      (0x1U << USBHS_DEVEPTICR_HBISOFLUSHIC_Pos)     /**< (USBHS_DEVEPTICR) High Bandwidth Isochronous IN Flush Interrupt Clear Mask */
#define USBHS_DEVEPTICR_CRCERRIC_Pos          (6)                                            /**< (USBHS_DEVEPTICR) CRC Error Interrupt Clear Position */
#define USBHS_DEVEPTICR_CRCERRIC_Msk          (0x1U << USBHS_DEVEPTICR_CRCERRIC_Pos)         /**< (USBHS_DEVEPTICR) CRC Error Interrupt Clear Mask */

/* -------- USBHS_DEVEPTIFR : (USBHS Offset: 0x190) (/W 32) Device Endpoint Set Register -------- */

typedef union
{
  struct
  {
    uint32_t TXINIS:1;                  /**< bit:      0  Transmitted IN Data Interrupt Set             */
    uint32_t RXOUTIS:1;                 /**< bit:      1  Received OUT Data Interrupt Set               */
    uint32_t RXSTPIS:1;                 /**< bit:      2  Received SETUP Interrupt Set                  */
    uint32_t NAKOUTIS:1;                /**< bit:      3  NAKed OUT Interrupt Set                       */
    uint32_t NAKINIS:1;                 /**< bit:      4  NAKed IN Interrupt Set                        */
    uint32_t OVERFIS:1;                 /**< bit:      5  Overflow Interrupt Set                        */
    uint32_t STALLEDIS:1;               /**< bit:      6  STALLed Interrupt Set                         */
    uint32_t SHORTPACKETS:1;            /**< bit:      7  Short Packet Interrupt Set                    */
    uint32_t :4;                        /**< bit:  8..11  Reserved                                      */
    uint32_t NBUSYBKS:1;                /**< bit:     12  Number of Busy Banks Interrupt Set            */
    uint32_t :19;                       /**< bit: 13..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFIS:1;                /**< bit:      2  Underflow Interrupt Set                       */
    uint32_t HBISOINERRIS:1;            /**< bit:      3  High Bandwidth Isochronous IN Underflow Error Interrupt Set */
    uint32_t HBISOFLUSHIS:1;            /**< bit:      4  High Bandwidth Isochronous IN Flush Interrupt Set */
    uint32_t :1;                        /**< bit:      5  Reserved                                      */
    uint32_t CRCERRIS:1;                /**< bit:      6  CRC Error Interrupt Set                       */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_DEVEPTIFR_bits_t;

#define USBHS_DEVEPTIFR_TXINIS_Pos            (0)                                            /**< (USBHS_DEVEPTIFR) Transmitted IN Data Interrupt Set Position */
#define USBHS_DEVEPTIFR_TXINIS_Msk            (0x1U << USBHS_DEVEPTIFR_TXINIS_Pos)           /**< (USBHS_DEVEPTIFR) Transmitted IN Data Interrupt Set Mask */
#define USBHS_DEVEPTIFR_RXOUTIS_Pos           (1)                                            /**< (USBHS_DEVEPTIFR) Received OUT Data Interrupt Set Position */
#define USBHS_DEVEPTIFR_RXOUTIS_Msk           (0x1U << USBHS_DEVEPTIFR_RXOUTIS_Pos)          /**< (USBHS_DEVEPTIFR) Received OUT Data Interrupt Set Mask */
#define USBHS_DEVEPTIFR_RXSTPIS_Pos           (2)                                            /**< (USBHS_DEVEPTIFR) Received SETUP Interrupt Set Position */
#define USBHS_DEVEPTIFR_RXSTPIS_Msk           (0x1U << USBHS_DEVEPTIFR_RXSTPIS_Pos)          /**< (USBHS_DEVEPTIFR) Received SETUP Interrupt Set Mask */
#define USBHS_DEVEPTIFR_NAKOUTIS_Pos          (3)                                            /**< (USBHS_DEVEPTIFR) NAKed OUT Interrupt Set Position */
#define USBHS_DEVEPTIFR_NAKOUTIS_Msk          (0x1U << USBHS_DEVEPTIFR_NAKOUTIS_Pos)         /**< (USBHS_DEVEPTIFR) NAKed OUT Interrupt Set Mask */
#define USBHS_DEVEPTIFR_NAKINIS_Pos           (4)                                            /**< (USBHS_DEVEPTIFR) NAKed IN Interrupt Set Position */
#define USBHS_DEVEPTIFR_NAKINIS_Msk           (0x1U << USBHS_DEVEPTIFR_NAKINIS_Pos)          /**< (USBHS_DEVEPTIFR) NAKed IN Interrupt Set Mask */
#define USBHS_DEVEPTIFR_OVERFIS_Pos           (5)                                            /**< (USBHS_DEVEPTIFR) Overflow Interrupt Set Position */
#define USBHS_DEVEPTIFR_OVERFIS_Msk           (0x1U << USBHS_DEVEPTIFR_OVERFIS_Pos)          /**< (USBHS_DEVEPTIFR) Overflow Interrupt Set Mask */
#define USBHS_DEVEPTIFR_STALLEDIS_Pos         (6)                                            /**< (USBHS_DEVEPTIFR) STALLed Interrupt Set Position */
#define USBHS_DEVEPTIFR_STALLEDIS_Msk         (0x1U << USBHS_DEVEPTIFR_STALLEDIS_Pos)        /**< (USBHS_DEVEPTIFR) STALLed Interrupt Set Mask */
#define USBHS_DEVEPTIFR_SHORTPACKETS_Pos      (7)                                            /**< (USBHS_DEVEPTIFR) Short Packet Interrupt Set Position */
#define USBHS_DEVEPTIFR_SHORTPACKETS_Msk      (0x1U << USBHS_DEVEPTIFR_SHORTPACKETS_Pos)     /**< (USBHS_DEVEPTIFR) Short Packet Interrupt Set Mask */
#define USBHS_DEVEPTIFR_NBUSYBKS_Pos          (12)                                           /**< (USBHS_DEVEPTIFR) Number of Busy Banks Interrupt Set Position */
#define USBHS_DEVEPTIFR_NBUSYBKS_Msk          (0x1U << USBHS_DEVEPTIFR_NBUSYBKS_Pos)         /**< (USBHS_DEVEPTIFR) Number of Busy Banks Interrupt Set Mask */
/* Isochronous Endpoints mode */
#define USBHS_DEVEPTIFR_UNDERFIS_Pos          (2)                                            /**< (USBHS_DEVEPTIFR) Underflow Interrupt Set Position */
#define USBHS_DEVEPTIFR_UNDERFIS_Msk          (0x1U << USBHS_DEVEPTIFR_UNDERFIS_Pos)         /**< (USBHS_DEVEPTIFR) Underflow Interrupt Set Mask */
#define USBHS_DEVEPTIFR_HBISOINERRIS_Pos      (3)                                            /**< (USBHS_DEVEPTIFR) High Bandwidth Isochronous IN Underflow Error Interrupt Set Position */
#define USBHS_DEVEPTIFR_HBISOINERRIS_Msk      (0x1U << USBHS_DEVEPTIFR_HBISOINERRIS_Pos)     /**< (USBHS_DEVEPTIFR) High Bandwidth Isochronous IN Underflow Error Interrupt Set Mask */
#define USBHS_DEVEPTIFR_HBISOFLUSHIS_Pos      (4)                                            /**< (USBHS_DEVEPTIFR) High Bandwidth Isochronous IN Flush Interrupt Set Position */
#define USBHS_DEVEPTIFR_HBISOFLUSHIS_Msk      (0x1U << USBHS_DEVEPTIFR_HBISOFLUSHIS_Pos)     /**< (USBHS_DEVEPTIFR) High Bandwidth Isochronous IN Flush Interrupt Set Mask */
#define USBHS_DEVEPTIFR_CRCERRIS_Pos          (6)                                            /**< (USBHS_DEVEPTIFR) CRC Error Interrupt Set Position */
#define USBHS_DEVEPTIFR_CRCERRIS_Msk          (0x1U << USBHS_DEVEPTIFR_CRCERRIS_Pos)         /**< (USBHS_DEVEPTIFR) CRC Error Interrupt Set Mask */

/* -------- USBHS_DEVEPTIMR : (USBHS Offset: 0x1c0) (R/ 32) Device Endpoint Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t TXINE:1;                   /**< bit:      0  Transmitted IN Data Interrupt                 */
    uint32_t RXOUTE:1;                  /**< bit:      1  Received OUT Data Interrupt                   */
    uint32_t RXSTPE:1;                  /**< bit:      2  Received SETUP Interrupt                      */
    uint32_t NAKOUTE:1;                 /**< bit:      3  NAKed OUT Interrupt                           */
    uint32_t NAKINE:1;                  /**< bit:      4  NAKed IN Interrupt                            */
    uint32_t OVERFE:1;                  /**< bit:      5  Overflow Interrupt                            */
    uint32_t STALLEDE:1;                /**< bit:      6  STALLed Interrupt                             */
    uint32_t SHORTPACKETE:1;            /**< bit:      7  Short Packet Interrupt                        */
    uint32_t :4;                        /**< bit:  8..11  Reserved                                      */
    uint32_t NBUSYBKE:1;                /**< bit:     12  Number of Busy Banks Interrupt                */
    uint32_t KILLBK:1;                  /**< bit:     13  Kill IN Bank                                  */
    uint32_t FIFOCON:1;                 /**< bit:     14  FIFO Control                                  */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t EPDISHDMA:1;               /**< bit:     16  Endpoint Interrupts Disable HDMA Request      */
    uint32_t :1;                        /**< bit:     17  Reserved                                      */
    uint32_t RSTDT:1;                   /**< bit:     18  Reset Data Toggle                             */
    uint32_t :13;                       /**< bit: 19..31  Reserved                                      */
  };
  struct
  { // Control, Bulk and Interrupt Endpoints mode
    uint32_t :17;                       /**< bit:  0..16  Reserved                                      */
    uint32_t NYETDIS:1;                 /**< bit:     17  NYET Token Disable                            */
    uint32_t :1;                        /**< bit:     18  Reserved                                      */
    uint32_t STALLRQ:1;                 /**< bit:     19  STALL Request                                 */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFE:1;                 /**< bit:      2  Underflow Interrupt                           */
    uint32_t HBISOINERRE:1;             /**< bit:      3  High Bandwidth Isochronous IN Underflow Error Interrupt */
    uint32_t HBISOFLUSHE:1;             /**< bit:      4  High Bandwidth Isochronous IN Flush Interrupt */
    uint32_t :1;                        /**< bit:      5  Reserved                                      */
    uint32_t CRCERRE:1;                 /**< bit:      6  CRC Error Interrupt                           */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t MDATAE:1;                  /**< bit:      8  MData Interrupt                               */
    uint32_t DATAXE:1;                  /**< bit:      9  DataX Interrupt                               */
    uint32_t ERRORTRANSE:1;             /**< bit:     10  Transaction Error Interrupt                   */
    uint32_t :21;                       /**< bit: 11..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_DEVEPTIMR_bits_t;

#define USBHS_DEVEPTIMR_TXINE_Pos             (0)                                            /**< (USBHS_DEVEPTIMR) Transmitted IN Data Interrupt Position */
#define USBHS_DEVEPTIMR_TXINE_Msk             (0x1U << USBHS_DEVEPTIMR_TXINE_Pos)            /**< (USBHS_DEVEPTIMR) Transmitted IN Data Interrupt Mask */
#define USBHS_DEVEPTIMR_RXOUTE_Pos            (1)                                            /**< (USBHS_DEVEPTIMR) Received OUT Data Interrupt Position */
#define USBHS_DEVEPTIMR_RXOUTE_Msk            (0x1U << USBHS_DEVEPTIMR_RXOUTE_Pos)           /**< (USBHS_DEVEPTIMR) Received OUT Data Interrupt Mask */
#define USBHS_DEVEPTIMR_RXSTPE_Pos            (2)                                            /**< (USBHS_DEVEPTIMR) Received SETUP Interrupt Position */
#define USBHS_DEVEPTIMR_RXSTPE_Msk            (0x1U << USBHS_DEVEPTIMR_RXSTPE_Pos)           /**< (USBHS_DEVEPTIMR) Received SETUP Interrupt Mask */
#define USBHS_DEVEPTIMR_NAKOUTE_Pos           (3)                                            /**< (USBHS_DEVEPTIMR) NAKed OUT Interrupt Position */
#define USBHS_DEVEPTIMR_NAKOUTE_Msk           (0x1U << USBHS_DEVEPTIMR_NAKOUTE_Pos)          /**< (USBHS_DEVEPTIMR) NAKed OUT Interrupt Mask */
#define USBHS_DEVEPTIMR_NAKINE_Pos            (4)                                            /**< (USBHS_DEVEPTIMR) NAKed IN Interrupt Position */
#define USBHS_DEVEPTIMR_NAKINE_Msk            (0x1U << USBHS_DEVEPTIMR_NAKINE_Pos)           /**< (USBHS_DEVEPTIMR) NAKed IN Interrupt Mask */
#define USBHS_DEVEPTIMR_OVERFE_Pos            (5)                                            /**< (USBHS_DEVEPTIMR) Overflow Interrupt Position */
#define USBHS_DEVEPTIMR_OVERFE_Msk            (0x1U << USBHS_DEVEPTIMR_OVERFE_Pos)           /**< (USBHS_DEVEPTIMR) Overflow Interrupt Mask */
#define USBHS_DEVEPTIMR_STALLEDE_Pos          (6)                                            /**< (USBHS_DEVEPTIMR) STALLed Interrupt Position */
#define USBHS_DEVEPTIMR_STALLEDE_Msk          (0x1U << USBHS_DEVEPTIMR_STALLEDE_Pos)         /**< (USBHS_DEVEPTIMR) STALLed Interrupt Mask */
#define USBHS_DEVEPTIMR_SHORTPACKETE_Pos      (7)                                            /**< (USBHS_DEVEPTIMR) Short Packet Interrupt Position */
#define USBHS_DEVEPTIMR_SHORTPACKETE_Msk      (0x1U << USBHS_DEVEPTIMR_SHORTPACKETE_Pos)     /**< (USBHS_DEVEPTIMR) Short Packet Interrupt Mask */
#define USBHS_DEVEPTIMR_NBUSYBKE_Pos          (12)                                           /**< (USBHS_DEVEPTIMR) Number of Busy Banks Interrupt Position */
#define USBHS_DEVEPTIMR_NBUSYBKE_Msk          (0x1U << USBHS_DEVEPTIMR_NBUSYBKE_Pos)         /**< (USBHS_DEVEPTIMR) Number of Busy Banks Interrupt Mask */
#define USBHS_DEVEPTIMR_KILLBK_Pos            (13)                                           /**< (USBHS_DEVEPTIMR) Kill IN Bank Position */
#define USBHS_DEVEPTIMR_KILLBK_Msk            (0x1U << USBHS_DEVEPTIMR_KILLBK_Pos)           /**< (USBHS_DEVEPTIMR) Kill IN Bank Mask */
#define USBHS_DEVEPTIMR_FIFOCON_Pos           (14)                                           /**< (USBHS_DEVEPTIMR) FIFO Control Position */
#define USBHS_DEVEPTIMR_FIFOCON_Msk           (0x1U << USBHS_DEVEPTIMR_FIFOCON_Pos)          /**< (USBHS_DEVEPTIMR) FIFO Control Mask */
#define USBHS_DEVEPTIMR_EPDISHDMA_Pos         (16)                                           /**< (USBHS_DEVEPTIMR) Endpoint Interrupts Disable HDMA Request Position */
#define USBHS_DEVEPTIMR_EPDISHDMA_Msk         (0x1U << USBHS_DEVEPTIMR_EPDISHDMA_Pos)        /**< (USBHS_DEVEPTIMR) Endpoint Interrupts Disable HDMA Request Mask */
#define USBHS_DEVEPTIMR_RSTDT_Pos             (18)                                           /**< (USBHS_DEVEPTIMR) Reset Data Toggle Position */
#define USBHS_DEVEPTIMR_RSTDT_Msk             (0x1U << USBHS_DEVEPTIMR_RSTDT_Pos)            /**< (USBHS_DEVEPTIMR) Reset Data Toggle Mask */
/* Control, Bulk and Interrupt Endpoints mode */
#define USBHS_DEVEPTIMR_NYETDIS_Pos           (17)                                           /**< (USBHS_DEVEPTIMR) NYET Token Disable Position */
#define USBHS_DEVEPTIMR_NYETDIS_Msk           (0x1U << USBHS_DEVEPTIMR_NYETDIS_Pos)          /**< (USBHS_DEVEPTIMR) NYET Token Disable Mask */
#define USBHS_DEVEPTIMR_STALLRQ_Pos           (19)                                           /**< (USBHS_DEVEPTIMR) STALL Request Position */
#define USBHS_DEVEPTIMR_STALLRQ_Msk           (0x1U << USBHS_DEVEPTIMR_STALLRQ_Pos)          /**< (USBHS_DEVEPTIMR) STALL Request Mask */
/* Isochronous Endpoints mode */
#define USBHS_DEVEPTIMR_UNDERFE_Pos           (2)                                            /**< (USBHS_DEVEPTIMR) Underflow Interrupt Position */
#define USBHS_DEVEPTIMR_UNDERFE_Msk           (0x1U << USBHS_DEVEPTIMR_UNDERFE_Pos)          /**< (USBHS_DEVEPTIMR) Underflow Interrupt Mask */
#define USBHS_DEVEPTIMR_HBISOINERRE_Pos       (3)                                            /**< (USBHS_DEVEPTIMR) High Bandwidth Isochronous IN Underflow Error Interrupt Position */
#define USBHS_DEVEPTIMR_HBISOINERRE_Msk       (0x1U << USBHS_DEVEPTIMR_HBISOINERRE_Pos)      /**< (USBHS_DEVEPTIMR) High Bandwidth Isochronous IN Underflow Error Interrupt Mask */
#define USBHS_DEVEPTIMR_HBISOFLUSHE_Pos       (4)                                            /**< (USBHS_DEVEPTIMR) High Bandwidth Isochronous IN Flush Interrupt Position */
#define USBHS_DEVEPTIMR_HBISOFLUSHE_Msk       (0x1U << USBHS_DEVEPTIMR_HBISOFLUSHE_Pos)      /**< (USBHS_DEVEPTIMR) High Bandwidth Isochronous IN Flush Interrupt Mask */
#define USBHS_DEVEPTIMR_CRCERRE_Pos           (6)                                            /**< (USBHS_DEVEPTIMR) CRC Error Interrupt Position */
#define USBHS_DEVEPTIMR_CRCERRE_Msk           (0x1U << USBHS_DEVEPTIMR_CRCERRE_Pos)          /**< (USBHS_DEVEPTIMR) CRC Error Interrupt Mask */
#define USBHS_DEVEPTIMR_MDATAE_Pos            (8)                                            /**< (USBHS_DEVEPTIMR) MData Interrupt Position */
#define USBHS_DEVEPTIMR_MDATAE_Msk            (0x1U << USBHS_DEVEPTIMR_MDATAE_Pos)           /**< (USBHS_DEVEPTIMR) MData Interrupt Mask */
#define USBHS_DEVEPTIMR_DATAXE_Pos            (9)                                            /**< (USBHS_DEVEPTIMR) DataX Interrupt Position */
#define USBHS_DEVEPTIMR_DATAXE_Msk            (0x1U << USBHS_DEVEPTIMR_DATAXE_Pos)           /**< (USBHS_DEVEPTIMR) DataX Interrupt Mask */
#define USBHS_DEVEPTIMR_ERRORTRANSE_Pos       (10)                                           /**< (USBHS_DEVEPTIMR) Transaction Error Interrupt Position */
#define USBHS_DEVEPTIMR_ERRORTRANSE_Msk       (0x1U << USBHS_DEVEPTIMR_ERRORTRANSE_Pos)      /**< (USBHS_DEVEPTIMR) Transaction Error Interrupt Mask */

/* -------- USBHS_DEVEPTIER : (USBHS Offset: 0x1f0) (/W 32) Device Endpoint Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t TXINES:1;                  /**< bit:      0  Transmitted IN Data Interrupt Enable          */
    uint32_t RXOUTES:1;                 /**< bit:      1  Received OUT Data Interrupt Enable            */
    uint32_t RXSTPES:1;                 /**< bit:      2  Received SETUP Interrupt Enable               */
    uint32_t NAKOUTES:1;                /**< bit:      3  NAKed OUT Interrupt Enable                    */
    uint32_t NAKINES:1;                 /**< bit:      4  NAKed IN Interrupt Enable                     */
    uint32_t OVERFES:1;                 /**< bit:      5  Overflow Interrupt Enable                     */
    uint32_t STALLEDES:1;               /**< bit:      6  STALLed Interrupt Enable                      */
    uint32_t SHORTPACKETES:1;           /**< bit:      7  Short Packet Interrupt Enable                 */
    uint32_t :4;                        /**< bit:  8..11  Reserved                                      */
    uint32_t NBUSYBKES:1;               /**< bit:     12  Number of Busy Banks Interrupt Enable         */
    uint32_t KILLBKS:1;                 /**< bit:     13  Kill IN Bank                                  */
    uint32_t FIFOCONS:1;                /**< bit:     14  FIFO Control                                  */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t EPDISHDMAS:1;              /**< bit:     16  Endpoint Interrupts Disable HDMA Request Enable */
    uint32_t :1;                        /**< bit:     17  Reserved                                      */
    uint32_t RSTDTS:1;                  /**< bit:     18  Reset Data Toggle Enable                      */
    uint32_t :13;                       /**< bit: 19..31  Reserved                                      */
  };
  struct
  { // Control, Bulk and Interrupt Endpoints mode
    uint32_t :17;                       /**< bit:  0..16  Reserved                                      */
    uint32_t NYETDISS:1;                /**< bit:     17  NYET Token Disable Enable                     */
    uint32_t :1;                        /**< bit:     18  Reserved                                      */
    uint32_t STALLRQS:1;                /**< bit:     19  STALL Request Enable                          */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFES:1;                /**< bit:      2  Underflow Interrupt Enable                    */
    uint32_t HBISOINERRES:1;            /**< bit:      3  High Bandwidth Isochronous IN Underflow Error Interrupt Enable */
    uint32_t HBISOFLUSHES:1;            /**< bit:      4  High Bandwidth Isochronous IN Flush Interrupt Enable */
    uint32_t :1;                        /**< bit:      5  Reserved                                      */
    uint32_t CRCERRES:1;                /**< bit:      6  CRC Error Interrupt Enable                    */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t MDATAES:1;                 /**< bit:      8  MData Interrupt Enable                        */
    uint32_t DATAXES:1;                 /**< bit:      9  DataX Interrupt Enable                        */
    uint32_t ERRORTRANSES:1;            /**< bit:     10  Transaction Error Interrupt Enable            */
    uint32_t :21;                       /**< bit: 11..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_DEVEPTIER_bits_t;

#define USBHS_DEVEPTIER_TXINES_Pos            (0)                                            /**< (USBHS_DEVEPTIER) Transmitted IN Data Interrupt Enable Position */
#define USBHS_DEVEPTIER_TXINES_Msk            (0x1U << USBHS_DEVEPTIER_TXINES_Pos)           /**< (USBHS_DEVEPTIER) Transmitted IN Data Interrupt Enable Mask */
#define USBHS_DEVEPTIER_RXOUTES_Pos           (1)                                            /**< (USBHS_DEVEPTIER) Received OUT Data Interrupt Enable Position */
#define USBHS_DEVEPTIER_RXOUTES_Msk           (0x1U << USBHS_DEVEPTIER_RXOUTES_Pos)          /**< (USBHS_DEVEPTIER) Received OUT Data Interrupt Enable Mask */
#define USBHS_DEVEPTIER_RXSTPES_Pos           (2)                                            /**< (USBHS_DEVEPTIER) Received SETUP Interrupt Enable Position */
#define USBHS_DEVEPTIER_RXSTPES_Msk           (0x1U << USBHS_DEVEPTIER_RXSTPES_Pos)          /**< (USBHS_DEVEPTIER) Received SETUP Interrupt Enable Mask */
#define USBHS_DEVEPTIER_NAKOUTES_Pos          (3)                                            /**< (USBHS_DEVEPTIER) NAKed OUT Interrupt Enable Position */
#define USBHS_DEVEPTIER_NAKOUTES_Msk          (0x1U << USBHS_DEVEPTIER_NAKOUTES_Pos)         /**< (USBHS_DEVEPTIER) NAKed OUT Interrupt Enable Mask */
#define USBHS_DEVEPTIER_NAKINES_Pos           (4)                                            /**< (USBHS_DEVEPTIER) NAKed IN Interrupt Enable Position */
#define USBHS_DEVEPTIER_NAKINES_Msk           (0x1U << USBHS_DEVEPTIER_NAKINES_Pos)          /**< (USBHS_DEVEPTIER) NAKed IN Interrupt Enable Mask */
#define USBHS_DEVEPTIER_OVERFES_Pos           (5)                                            /**< (USBHS_DEVEPTIER) Overflow Interrupt Enable Position */
#define USBHS_DEVEPTIER_OVERFES_Msk           (0x1U << USBHS_DEVEPTIER_OVERFES_Pos)          /**< (USBHS_DEVEPTIER) Overflow Interrupt Enable Mask */
#define USBHS_DEVEPTIER_STALLEDES_Pos         (6)                                            /**< (USBHS_DEVEPTIER) STALLed Interrupt Enable Position */
#define USBHS_DEVEPTIER_STALLEDES_Msk         (0x1U << USBHS_DEVEPTIER_STALLEDES_Pos)        /**< (USBHS_DEVEPTIER) STALLed Interrupt Enable Mask */
#define USBHS_DEVEPTIER_SHORTPACKETES_Pos     (7)                                            /**< (USBHS_DEVEPTIER) Short Packet Interrupt Enable Position */
#define USBHS_DEVEPTIER_SHORTPACKETES_Msk     (0x1U << USBHS_DEVEPTIER_SHORTPACKETES_Pos)    /**< (USBHS_DEVEPTIER) Short Packet Interrupt Enable Mask */
#define USBHS_DEVEPTIER_NBUSYBKES_Pos         (12)                                           /**< (USBHS_DEVEPTIER) Number of Busy Banks Interrupt Enable Position */
#define USBHS_DEVEPTIER_NBUSYBKES_Msk         (0x1U << USBHS_DEVEPTIER_NBUSYBKES_Pos)        /**< (USBHS_DEVEPTIER) Number of Busy Banks Interrupt Enable Mask */
#define USBHS_DEVEPTIER_KILLBKS_Pos           (13)                                           /**< (USBHS_DEVEPTIER) Kill IN Bank Position */
#define USBHS_DEVEPTIER_KILLBKS_Msk           (0x1U << USBHS_DEVEPTIER_KILLBKS_Pos)          /**< (USBHS_DEVEPTIER) Kill IN Bank Mask */
#define USBHS_DEVEPTIER_FIFOCONS_Pos          (14)                                           /**< (USBHS_DEVEPTIER) FIFO Control Position */
#define USBHS_DEVEPTIER_FIFOCONS_Msk          (0x1U << USBHS_DEVEPTIER_FIFOCONS_Pos)         /**< (USBHS_DEVEPTIER) FIFO Control Mask */
#define USBHS_DEVEPTIER_EPDISHDMAS_Pos        (16)                                           /**< (USBHS_DEVEPTIER) Endpoint Interrupts Disable HDMA Request Enable Position */
#define USBHS_DEVEPTIER_EPDISHDMAS_Msk        (0x1U << USBHS_DEVEPTIER_EPDISHDMAS_Pos)       /**< (USBHS_DEVEPTIER) Endpoint Interrupts Disable HDMA Request Enable Mask */
#define USBHS_DEVEPTIER_RSTDTS_Pos            (18)                                           /**< (USBHS_DEVEPTIER) Reset Data Toggle Enable Position */
#define USBHS_DEVEPTIER_RSTDTS_Msk            (0x1U << USBHS_DEVEPTIER_RSTDTS_Pos)           /**< (USBHS_DEVEPTIER) Reset Data Toggle Enable Mask */
/* Control, Bulk and Interrupt Endpoints mode */
#define USBHS_DEVEPTIER_NYETDISS_Pos          (17)                                           /**< (USBHS_DEVEPTIER) NYET Token Disable Enable Position */
#define USBHS_DEVEPTIER_NYETDISS_Msk          (0x1U << USBHS_DEVEPTIER_NYETDISS_Pos)         /**< (USBHS_DEVEPTIER) NYET Token Disable Enable Mask */
#define USBHS_DEVEPTIER_STALLRQS_Pos          (19)                                           /**< (USBHS_DEVEPTIER) STALL Request Enable Position */
#define USBHS_DEVEPTIER_STALLRQS_Msk          (0x1U << USBHS_DEVEPTIER_STALLRQS_Pos)         /**< (USBHS_DEVEPTIER) STALL Request Enable Mask */
/* Isochronous Endpoints mode */
#define USBHS_DEVEPTIER_UNDERFES_Pos          (2)                                            /**< (USBHS_DEVEPTIER) Underflow Interrupt Enable Position */
#define USBHS_DEVEPTIER_UNDERFES_Msk          (0x1U << USBHS_DEVEPTIER_UNDERFES_Pos)         /**< (USBHS_DEVEPTIER) Underflow Interrupt Enable Mask */
#define USBHS_DEVEPTIER_HBISOINERRES_Pos      (3)                                            /**< (USBHS_DEVEPTIER) High Bandwidth Isochronous IN Underflow Error Interrupt Enable Position */
#define USBHS_DEVEPTIER_HBISOINERRES_Msk      (0x1U << USBHS_DEVEPTIER_HBISOINERRES_Pos)     /**< (USBHS_DEVEPTIER) High Bandwidth Isochronous IN Underflow Error Interrupt Enable Mask */
#define USBHS_DEVEPTIER_HBISOFLUSHES_Pos      (4)                                            /**< (USBHS_DEVEPTIER) High Bandwidth Isochronous IN Flush Interrupt Enable Position */
#define USBHS_DEVEPTIER_HBISOFLUSHES_Msk      (0x1U << USBHS_DEVEPTIER_HBISOFLUSHES_Pos)     /**< (USBHS_DEVEPTIER) High Bandwidth Isochronous IN Flush Interrupt Enable Mask */
#define USBHS_DEVEPTIER_CRCERRES_Pos          (6)                                            /**< (USBHS_DEVEPTIER) CRC Error Interrupt Enable Position */
#define USBHS_DEVEPTIER_CRCERRES_Msk          (0x1U << USBHS_DEVEPTIER_CRCERRES_Pos)         /**< (USBHS_DEVEPTIER) CRC Error Interrupt Enable Mask */
#define USBHS_DEVEPTIER_MDATAES_Pos           (8)                                            /**< (USBHS_DEVEPTIER) MData Interrupt Enable Position */
#define USBHS_DEVEPTIER_MDATAES_Msk           (0x1U << USBHS_DEVEPTIER_MDATAES_Pos)          /**< (USBHS_DEVEPTIER) MData Interrupt Enable Mask */
#define USBHS_DEVEPTIER_DATAXES_Pos           (9)                                            /**< (USBHS_DEVEPTIER) DataX Interrupt Enable Position */
#define USBHS_DEVEPTIER_DATAXES_Msk           (0x1U << USBHS_DEVEPTIER_DATAXES_Pos)          /**< (USBHS_DEVEPTIER) DataX Interrupt Enable Mask */
#define USBHS_DEVEPTIER_ERRORTRANSES_Pos      (10)                                           /**< (USBHS_DEVEPTIER) Transaction Error Interrupt Enable Position */
#define USBHS_DEVEPTIER_ERRORTRANSES_Msk      (0x1U << USBHS_DEVEPTIER_ERRORTRANSES_Pos)     /**< (USBHS_DEVEPTIER) Transaction Error Interrupt Enable Mask */

/* -------- USBHS_DEVEPTIDR : (USBHS Offset: 0x220) (/W 32) Device Endpoint Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t TXINEC:1;                  /**< bit:      0  Transmitted IN Interrupt Clear                */
    uint32_t RXOUTEC:1;                 /**< bit:      1  Received OUT Data Interrupt Clear             */
    uint32_t RXSTPEC:1;                 /**< bit:      2  Received SETUP Interrupt Clear                */
    uint32_t NAKOUTEC:1;                /**< bit:      3  NAKed OUT Interrupt Clear                     */
    uint32_t NAKINEC:1;                 /**< bit:      4  NAKed IN Interrupt Clear                      */
    uint32_t OVERFEC:1;                 /**< bit:      5  Overflow Interrupt Clear                      */
    uint32_t STALLEDEC:1;               /**< bit:      6  STALLed Interrupt Clear                       */
    uint32_t SHORTPACKETEC:1;           /**< bit:      7  Shortpacket Interrupt Clear                   */
    uint32_t :4;                        /**< bit:  8..11  Reserved                                      */
    uint32_t NBUSYBKEC:1;               /**< bit:     12  Number of Busy Banks Interrupt Clear          */
    uint32_t :1;                        /**< bit:     13  Reserved                                      */
    uint32_t FIFOCONC:1;                /**< bit:     14  FIFO Control Clear                            */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t EPDISHDMAC:1;              /**< bit:     16  Endpoint Interrupts Disable HDMA Request Clear */
    uint32_t :15;                       /**< bit: 17..31  Reserved                                      */
  };
  struct
  { // Control, Bulk and Interrupt Endpoints mode
    uint32_t :17;                       /**< bit:  0..16  Reserved                                      */
    uint32_t NYETDISC:1;                /**< bit:     17  NYET Token Disable Clear                      */
    uint32_t :1;                        /**< bit:     18  Reserved                                      */
    uint32_t STALLRQC:1;                /**< bit:     19  STALL Request Clear                           */
    uint32_t :12;                       /**< bit: 20..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFEC:1;                /**< bit:      2  Underflow Interrupt Clear                     */
    uint32_t HBISOINERREC:1;            /**< bit:      3  High Bandwidth Isochronous IN Underflow Error Interrupt Clear */
    uint32_t HBISOFLUSHEC:1;            /**< bit:      4  High Bandwidth Isochronous IN Flush Interrupt Clear */
    uint32_t :3;                        /**< bit:   5..7  Reserved                                      */
    uint32_t MDATAEC:1;                 /**< bit:      8  MData Interrupt Clear                         */
    uint32_t DATAXEC:1;                 /**< bit:      9  DataX Interrupt Clear                         */
    uint32_t ERRORTRANSEC:1;            /**< bit:     10  Transaction Error Interrupt Clear             */
    uint32_t :21;                       /**< bit: 11..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_DEVEPTIDR_bits_t;

#define USBHS_DEVEPTIDR_TXINEC_Pos            (0)                                            /**< (USBHS_DEVEPTIDR) Transmitted IN Interrupt Clear Position */
#define USBHS_DEVEPTIDR_TXINEC_Msk            (0x1U << USBHS_DEVEPTIDR_TXINEC_Pos)           /**< (USBHS_DEVEPTIDR) Transmitted IN Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_RXOUTEC_Pos           (1)                                            /**< (USBHS_DEVEPTIDR) Received OUT Data Interrupt Clear Position */
#define USBHS_DEVEPTIDR_RXOUTEC_Msk           (0x1U << USBHS_DEVEPTIDR_RXOUTEC_Pos)          /**< (USBHS_DEVEPTIDR) Received OUT Data Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_RXSTPEC_Pos           (2)                                            /**< (USBHS_DEVEPTIDR) Received SETUP Interrupt Clear Position */
#define USBHS_DEVEPTIDR_RXSTPEC_Msk           (0x1U << USBHS_DEVEPTIDR_RXSTPEC_Pos)          /**< (USBHS_DEVEPTIDR) Received SETUP Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_NAKOUTEC_Pos          (3)                                            /**< (USBHS_DEVEPTIDR) NAKed OUT Interrupt Clear Position */
#define USBHS_DEVEPTIDR_NAKOUTEC_Msk          (0x1U << USBHS_DEVEPTIDR_NAKOUTEC_Pos)         /**< (USBHS_DEVEPTIDR) NAKed OUT Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_NAKINEC_Pos           (4)                                            /**< (USBHS_DEVEPTIDR) NAKed IN Interrupt Clear Position */
#define USBHS_DEVEPTIDR_NAKINEC_Msk           (0x1U << USBHS_DEVEPTIDR_NAKINEC_Pos)          /**< (USBHS_DEVEPTIDR) NAKed IN Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_OVERFEC_Pos           (5)                                            /**< (USBHS_DEVEPTIDR) Overflow Interrupt Clear Position */
#define USBHS_DEVEPTIDR_OVERFEC_Msk           (0x1U << USBHS_DEVEPTIDR_OVERFEC_Pos)          /**< (USBHS_DEVEPTIDR) Overflow Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_STALLEDEC_Pos         (6)                                            /**< (USBHS_DEVEPTIDR) STALLed Interrupt Clear Position */
#define USBHS_DEVEPTIDR_STALLEDEC_Msk         (0x1U << USBHS_DEVEPTIDR_STALLEDEC_Pos)        /**< (USBHS_DEVEPTIDR) STALLed Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_SHORTPACKETEC_Pos     (7)                                            /**< (USBHS_DEVEPTIDR) Shortpacket Interrupt Clear Position */
#define USBHS_DEVEPTIDR_SHORTPACKETEC_Msk     (0x1U << USBHS_DEVEPTIDR_SHORTPACKETEC_Pos)    /**< (USBHS_DEVEPTIDR) Shortpacket Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_NBUSYBKEC_Pos         (12)                                           /**< (USBHS_DEVEPTIDR) Number of Busy Banks Interrupt Clear Position */
#define USBHS_DEVEPTIDR_NBUSYBKEC_Msk         (0x1U << USBHS_DEVEPTIDR_NBUSYBKEC_Pos)        /**< (USBHS_DEVEPTIDR) Number of Busy Banks Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_FIFOCONC_Pos          (14)                                           /**< (USBHS_DEVEPTIDR) FIFO Control Clear Position */
#define USBHS_DEVEPTIDR_FIFOCONC_Msk          (0x1U << USBHS_DEVEPTIDR_FIFOCONC_Pos)         /**< (USBHS_DEVEPTIDR) FIFO Control Clear Mask */
#define USBHS_DEVEPTIDR_EPDISHDMAC_Pos        (16)                                           /**< (USBHS_DEVEPTIDR) Endpoint Interrupts Disable HDMA Request Clear Position */
#define USBHS_DEVEPTIDR_EPDISHDMAC_Msk        (0x1U << USBHS_DEVEPTIDR_EPDISHDMAC_Pos)       /**< (USBHS_DEVEPTIDR) Endpoint Interrupts Disable HDMA Request Clear Mask */
/* Control, Bulk and Interrupt Endpoints mode */
#define USBHS_DEVEPTIDR_NYETDISC_Pos          (17)                                           /**< (USBHS_DEVEPTIDR) NYET Token Disable Clear Position */
#define USBHS_DEVEPTIDR_NYETDISC_Msk          (0x1U << USBHS_DEVEPTIDR_NYETDISC_Pos)         /**< (USBHS_DEVEPTIDR) NYET Token Disable Clear Mask */
#define USBHS_DEVEPTIDR_STALLRQC_Pos          (19)                                           /**< (USBHS_DEVEPTIDR) STALL Request Clear Position */
#define USBHS_DEVEPTIDR_STALLRQC_Msk          (0x1U << USBHS_DEVEPTIDR_STALLRQC_Pos)         /**< (USBHS_DEVEPTIDR) STALL Request Clear Mask */
/* Isochronous Endpoints mode */
#define USBHS_DEVEPTIDR_UNDERFEC_Pos          (2)                                            /**< (USBHS_DEVEPTIDR) Underflow Interrupt Clear Position */
#define USBHS_DEVEPTIDR_UNDERFEC_Msk          (0x1U << USBHS_DEVEPTIDR_UNDERFEC_Pos)         /**< (USBHS_DEVEPTIDR) Underflow Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_HBISOINERREC_Pos      (3)                                            /**< (USBHS_DEVEPTIDR) High Bandwidth Isochronous IN Underflow Error Interrupt Clear Position */
#define USBHS_DEVEPTIDR_HBISOINERREC_Msk      (0x1U << USBHS_DEVEPTIDR_HBISOINERREC_Pos)     /**< (USBHS_DEVEPTIDR) High Bandwidth Isochronous IN Underflow Error Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_HBISOFLUSHEC_Pos      (4)                                            /**< (USBHS_DEVEPTIDR) High Bandwidth Isochronous IN Flush Interrupt Clear Position */
#define USBHS_DEVEPTIDR_HBISOFLUSHEC_Msk      (0x1U << USBHS_DEVEPTIDR_HBISOFLUSHEC_Pos)     /**< (USBHS_DEVEPTIDR) High Bandwidth Isochronous IN Flush Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_MDATAEC_Pos           (8)                                            /**< (USBHS_DEVEPTIDR) MData Interrupt Clear Position */
#define USBHS_DEVEPTIDR_MDATAEC_Msk           (0x1U << USBHS_DEVEPTIDR_MDATAEC_Pos)          /**< (USBHS_DEVEPTIDR) MData Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_DATAXEC_Pos           (9)                                            /**< (USBHS_DEVEPTIDR) DataX Interrupt Clear Position */
#define USBHS_DEVEPTIDR_DATAXEC_Msk           (0x1U << USBHS_DEVEPTIDR_DATAXEC_Pos)          /**< (USBHS_DEVEPTIDR) DataX Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_ERRORTRANSEC_Pos      (10)                                           /**< (USBHS_DEVEPTIDR) Transaction Error Interrupt Clear Position */
#define USBHS_DEVEPTIDR_ERRORTRANSEC_Msk      (0x1U << USBHS_DEVEPTIDR_ERRORTRANSEC_Pos)     /**< (USBHS_DEVEPTIDR) Transaction Error Interrupt Clear Mask */

/* -------- USBHS_HSTCTRL : (USBHS Offset: 0x400) (R/W 32) Host General Control Register -------- */

typedef union
{
  struct
  {
    uint32_t :8;                        /**< bit:   0..7  Reserved                                      */
    uint32_t SOFE:1;                    /**< bit:      8  Start of Frame Generation Enable              */
    uint32_t RESET:1;                   /**< bit:      9  Send USB Reset                                */
    uint32_t RESUME:1;                  /**< bit:     10  Send USB Resume                               */
    uint32_t :1;                        /**< bit:     11  Reserved                                      */
    uint32_t SPDCONF:2;                 /**< bit: 12..13  Mode Configuration                            */
    uint32_t :18;                       /**< bit: 14..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTCTRL_bits_t;

#define USBHS_HSTCTRL_SOFE_Pos                (8)                                            /**< (USBHS_HSTCTRL) Start of Frame Generation Enable Position */
#define USBHS_HSTCTRL_SOFE_Msk                (0x1U << USBHS_HSTCTRL_SOFE_Pos)               /**< (USBHS_HSTCTRL) Start of Frame Generation Enable Mask */
#define USBHS_HSTCTRL_RESET_Pos               (9)                                            /**< (USBHS_HSTCTRL) Send USB Reset Position */
#define USBHS_HSTCTRL_RESET_Msk               (0x1U << USBHS_HSTCTRL_RESET_Pos)              /**< (USBHS_HSTCTRL) Send USB Reset Mask */
#define USBHS_HSTCTRL_RESUME_Pos              (10)                                           /**< (USBHS_HSTCTRL) Send USB Resume Position */
#define USBHS_HSTCTRL_RESUME_Msk              (0x1U << USBHS_HSTCTRL_RESUME_Pos)             /**< (USBHS_HSTCTRL) Send USB Resume Mask */
#define USBHS_HSTCTRL_SPDCONF_Pos             (12)                                           /**< (USBHS_HSTCTRL) Mode Configuration Position */
#define USBHS_HSTCTRL_SPDCONF_Msk             (0x3U << USBHS_HSTCTRL_SPDCONF_Pos)            /**< (USBHS_HSTCTRL) Mode Configuration Mask */
#define USBHS_HSTCTRL_SPDCONF(value)          (USBHS_HSTCTRL_SPDCONF_Msk & ((value) << USBHS_HSTCTRL_SPDCONF_Pos))
#define   USBHS_HSTCTRL_SPDCONF_NORMAL_Val    (0x0U)                                         /**< (USBHS_HSTCTRL) The host starts in Full-speed mode and performs a high-speed reset to switch to High-speed mode if the downstream peripheral is high-speed capable.  */
#define   USBHS_HSTCTRL_SPDCONF_LOW_POWER_Val (0x1U)                                         /**< (USBHS_HSTCTRL) For a better consumption, if high speed is not needed.  */
#define   USBHS_HSTCTRL_SPDCONF_HIGH_SPEED_Val (0x2U)                                         /**< (USBHS_HSTCTRL) Forced high speed.  */
#define   USBHS_HSTCTRL_SPDCONF_FORCED_FS_Val (0x3U)                                         /**< (USBHS_HSTCTRL) The host remains in Full-speed mode whatever the peripheral speed capability.  */
#define USBHS_HSTCTRL_SPDCONF_NORMAL          (USBHS_HSTCTRL_SPDCONF_NORMAL_Val << USBHS_HSTCTRL_SPDCONF_Pos)  /**< (USBHS_HSTCTRL) The host starts in Full-speed mode and performs a high-speed reset to switch to High-speed mode if the downstream peripheral is high-speed capable. Position  */
#define USBHS_HSTCTRL_SPDCONF_LOW_POWER       (USBHS_HSTCTRL_SPDCONF_LOW_POWER_Val << USBHS_HSTCTRL_SPDCONF_Pos)  /**< (USBHS_HSTCTRL) For a better consumption, if high speed is not needed. Position  */
#define USBHS_HSTCTRL_SPDCONF_HIGH_SPEED      (USBHS_HSTCTRL_SPDCONF_HIGH_SPEED_Val << USBHS_HSTCTRL_SPDCONF_Pos)  /**< (USBHS_HSTCTRL) Forced high speed. Position  */
#define USBHS_HSTCTRL_SPDCONF_FORCED_FS       (USBHS_HSTCTRL_SPDCONF_FORCED_FS_Val << USBHS_HSTCTRL_SPDCONF_Pos)  /**< (USBHS_HSTCTRL) The host remains in Full-speed mode whatever the peripheral speed capability. Position  */
#define USBHS_HSTCTRL_Msk                     (0x00003700UL)                                 /**< (USBHS_HSTCTRL) Register Mask  */

/* -------- USBHS_HSTISR : (USBHS Offset: 0x404) (R/ 32) Host Global Interrupt Status Register -------- */

typedef union
{
  struct
  {
    uint32_t DCONNI:1;                  /**< bit:      0  Device Connection Interrupt                   */
    uint32_t DDISCI:1;                  /**< bit:      1  Device Disconnection Interrupt                */
    uint32_t RSTI:1;                    /**< bit:      2  USB Reset Sent Interrupt                      */
    uint32_t RSMEDI:1;                  /**< bit:      3  Downstream Resume Sent Interrupt              */
    uint32_t RXRSMI:1;                  /**< bit:      4  Upstream Resume Received Interrupt            */
    uint32_t HSOFI:1;                   /**< bit:      5  Host Start of Frame Interrupt                 */
    uint32_t HWUPI:1;                   /**< bit:      6  Host Wake-Up Interrupt                        */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t PEP_0:1;                   /**< bit:      8  Pipe 0 Interrupt                              */
    uint32_t PEP_1:1;                   /**< bit:      9  Pipe 1 Interrupt                              */
    uint32_t PEP_2:1;                   /**< bit:     10  Pipe 2 Interrupt                              */
    uint32_t PEP_3:1;                   /**< bit:     11  Pipe 3 Interrupt                              */
    uint32_t PEP_4:1;                   /**< bit:     12  Pipe 4 Interrupt                              */
    uint32_t PEP_5:1;                   /**< bit:     13  Pipe 5 Interrupt                              */
    uint32_t PEP_6:1;                   /**< bit:     14  Pipe 6 Interrupt                              */
    uint32_t PEP_7:1;                   /**< bit:     15  Pipe 7 Interrupt                              */
    uint32_t PEP_8:1;                   /**< bit:     16  Pipe 8 Interrupt                              */
    uint32_t PEP_9:1;                   /**< bit:     17  Pipe 9 Interrupt                              */
    uint32_t :7;                        /**< bit: 18..24  Reserved                                      */
    uint32_t DMA_1:1;                   /**< bit:     25  DMA Channel 1 Interrupt                       */
    uint32_t DMA_2:1;                   /**< bit:     26  DMA Channel 2 Interrupt                       */
    uint32_t DMA_3:1;                   /**< bit:     27  DMA Channel 3 Interrupt                       */
    uint32_t DMA_4:1;                   /**< bit:     28  DMA Channel 4 Interrupt                       */
    uint32_t DMA_5:1;                   /**< bit:     29  DMA Channel 5 Interrupt                       */
    uint32_t DMA_6:1;                   /**< bit:     30  DMA Channel 6 Interrupt                       */
    uint32_t DMA_7:1;                   /**< bit:     31  DMA Channel 7 Interrupt                       */
  };
  struct
  {
    uint32_t :8;                        /**< bit:   0..7  Reserved                                      */
    uint32_t PEP_:10;                   /**< bit:  8..17  Pipe x Interrupt                              */
    uint32_t :7;                        /**< bit: 18..24  Reserved                                      */
    uint32_t DMA_:7;                    /**< bit: 25..31  DMA Channel 7 Interrupt                       */
  };
  uint32_t w;
} __USBHS_HSTISR_bits_t;

#define USBHS_HSTISR_DCONNI_Pos               (0)                                            /**< (USBHS_HSTISR) Device Connection Interrupt Position */
#define USBHS_HSTISR_DCONNI_Msk               (0x1U << USBHS_HSTISR_DCONNI_Pos)              /**< (USBHS_HSTISR) Device Connection Interrupt Mask */
#define USBHS_HSTISR_DDISCI_Pos               (1)                                            /**< (USBHS_HSTISR) Device Disconnection Interrupt Position */
#define USBHS_HSTISR_DDISCI_Msk               (0x1U << USBHS_HSTISR_DDISCI_Pos)              /**< (USBHS_HSTISR) Device Disconnection Interrupt Mask */
#define USBHS_HSTISR_RSTI_Pos                 (2)                                            /**< (USBHS_HSTISR) USB Reset Sent Interrupt Position */
#define USBHS_HSTISR_RSTI_Msk                 (0x1U << USBHS_HSTISR_RSTI_Pos)                /**< (USBHS_HSTISR) USB Reset Sent Interrupt Mask */
#define USBHS_HSTISR_RSMEDI_Pos               (3)                                            /**< (USBHS_HSTISR) Downstream Resume Sent Interrupt Position */
#define USBHS_HSTISR_RSMEDI_Msk               (0x1U << USBHS_HSTISR_RSMEDI_Pos)              /**< (USBHS_HSTISR) Downstream Resume Sent Interrupt Mask */
#define USBHS_HSTISR_RXRSMI_Pos               (4)                                            /**< (USBHS_HSTISR) Upstream Resume Received Interrupt Position */
#define USBHS_HSTISR_RXRSMI_Msk               (0x1U << USBHS_HSTISR_RXRSMI_Pos)              /**< (USBHS_HSTISR) Upstream Resume Received Interrupt Mask */
#define USBHS_HSTISR_HSOFI_Pos                (5)                                            /**< (USBHS_HSTISR) Host Start of Frame Interrupt Position */
#define USBHS_HSTISR_HSOFI_Msk                (0x1U << USBHS_HSTISR_HSOFI_Pos)               /**< (USBHS_HSTISR) Host Start of Frame Interrupt Mask */
#define USBHS_HSTISR_HWUPI_Pos                (6)                                            /**< (USBHS_HSTISR) Host Wake-Up Interrupt Position */
#define USBHS_HSTISR_HWUPI_Msk                (0x1U << USBHS_HSTISR_HWUPI_Pos)               /**< (USBHS_HSTISR) Host Wake-Up Interrupt Mask */
#define USBHS_HSTISR_PEP_0_Pos                (8)                                            /**< (USBHS_HSTISR) Pipe 0 Interrupt Position */
#define USBHS_HSTISR_PEP_0_Msk                (0x1U << USBHS_HSTISR_PEP_0_Pos)               /**< (USBHS_HSTISR) Pipe 0 Interrupt Mask */
#define USBHS_HSTISR_PEP_1_Pos                (9)                                            /**< (USBHS_HSTISR) Pipe 1 Interrupt Position */
#define USBHS_HSTISR_PEP_1_Msk                (0x1U << USBHS_HSTISR_PEP_1_Pos)               /**< (USBHS_HSTISR) Pipe 1 Interrupt Mask */
#define USBHS_HSTISR_PEP_2_Pos                (10)                                           /**< (USBHS_HSTISR) Pipe 2 Interrupt Position */
#define USBHS_HSTISR_PEP_2_Msk                (0x1U << USBHS_HSTISR_PEP_2_Pos)               /**< (USBHS_HSTISR) Pipe 2 Interrupt Mask */
#define USBHS_HSTISR_PEP_3_Pos                (11)                                           /**< (USBHS_HSTISR) Pipe 3 Interrupt Position */
#define USBHS_HSTISR_PEP_3_Msk                (0x1U << USBHS_HSTISR_PEP_3_Pos)               /**< (USBHS_HSTISR) Pipe 3 Interrupt Mask */
#define USBHS_HSTISR_PEP_4_Pos                (12)                                           /**< (USBHS_HSTISR) Pipe 4 Interrupt Position */
#define USBHS_HSTISR_PEP_4_Msk                (0x1U << USBHS_HSTISR_PEP_4_Pos)               /**< (USBHS_HSTISR) Pipe 4 Interrupt Mask */
#define USBHS_HSTISR_PEP_5_Pos                (13)                                           /**< (USBHS_HSTISR) Pipe 5 Interrupt Position */
#define USBHS_HSTISR_PEP_5_Msk                (0x1U << USBHS_HSTISR_PEP_5_Pos)               /**< (USBHS_HSTISR) Pipe 5 Interrupt Mask */
#define USBHS_HSTISR_PEP_6_Pos                (14)                                           /**< (USBHS_HSTISR) Pipe 6 Interrupt Position */
#define USBHS_HSTISR_PEP_6_Msk                (0x1U << USBHS_HSTISR_PEP_6_Pos)               /**< (USBHS_HSTISR) Pipe 6 Interrupt Mask */
#define USBHS_HSTISR_PEP_7_Pos                (15)                                           /**< (USBHS_HSTISR) Pipe 7 Interrupt Position */
#define USBHS_HSTISR_PEP_7_Msk                (0x1U << USBHS_HSTISR_PEP_7_Pos)               /**< (USBHS_HSTISR) Pipe 7 Interrupt Mask */
#define USBHS_HSTISR_PEP_8_Pos                (16)                                           /**< (USBHS_HSTISR) Pipe 8 Interrupt Position */
#define USBHS_HSTISR_PEP_8_Msk                (0x1U << USBHS_HSTISR_PEP_8_Pos)               /**< (USBHS_HSTISR) Pipe 8 Interrupt Mask */
#define USBHS_HSTISR_PEP_9_Pos                (17)                                           /**< (USBHS_HSTISR) Pipe 9 Interrupt Position */
#define USBHS_HSTISR_PEP_9_Msk                (0x1U << USBHS_HSTISR_PEP_9_Pos)               /**< (USBHS_HSTISR) Pipe 9 Interrupt Mask */
#define USBHS_HSTISR_DMA_1_Pos                (25)                                           /**< (USBHS_HSTISR) DMA Channel 1 Interrupt Position */
#define USBHS_HSTISR_DMA_1_Msk                (0x1U << USBHS_HSTISR_DMA_1_Pos)               /**< (USBHS_HSTISR) DMA Channel 1 Interrupt Mask */
#define USBHS_HSTISR_DMA_2_Pos                (26)                                           /**< (USBHS_HSTISR) DMA Channel 2 Interrupt Position */
#define USBHS_HSTISR_DMA_2_Msk                (0x1U << USBHS_HSTISR_DMA_2_Pos)               /**< (USBHS_HSTISR) DMA Channel 2 Interrupt Mask */
#define USBHS_HSTISR_DMA_3_Pos                (27)                                           /**< (USBHS_HSTISR) DMA Channel 3 Interrupt Position */
#define USBHS_HSTISR_DMA_3_Msk                (0x1U << USBHS_HSTISR_DMA_3_Pos)               /**< (USBHS_HSTISR) DMA Channel 3 Interrupt Mask */
#define USBHS_HSTISR_DMA_4_Pos                (28)                                           /**< (USBHS_HSTISR) DMA Channel 4 Interrupt Position */
#define USBHS_HSTISR_DMA_4_Msk                (0x1U << USBHS_HSTISR_DMA_4_Pos)               /**< (USBHS_HSTISR) DMA Channel 4 Interrupt Mask */
#define USBHS_HSTISR_DMA_5_Pos                (29)                                           /**< (USBHS_HSTISR) DMA Channel 5 Interrupt Position */
#define USBHS_HSTISR_DMA_5_Msk                (0x1U << USBHS_HSTISR_DMA_5_Pos)               /**< (USBHS_HSTISR) DMA Channel 5 Interrupt Mask */
#define USBHS_HSTISR_DMA_6_Pos                (30)                                           /**< (USBHS_HSTISR) DMA Channel 6 Interrupt Position */
#define USBHS_HSTISR_DMA_6_Msk                (0x1U << USBHS_HSTISR_DMA_6_Pos)               /**< (USBHS_HSTISR) DMA Channel 6 Interrupt Mask */
#define USBHS_HSTISR_DMA_7_Pos                (31)                                           /**< (USBHS_HSTISR) DMA Channel 7 Interrupt Position */
#define USBHS_HSTISR_DMA_7_Msk                (0x1U << USBHS_HSTISR_DMA_7_Pos)               /**< (USBHS_HSTISR) DMA Channel 7 Interrupt Mask */
#define USBHS_HSTISR_Msk                      (0xFE03FF7FUL)                                 /**< (USBHS_HSTISR) Register Mask  */
#define USBHS_HSTISR_PEP__Pos                 (8)                                            /**< (USBHS_HSTISR Position) Pipe x Interrupt */
#define USBHS_HSTISR_PEP__Msk                 (0x3FFU << USBHS_HSTISR_PEP__Pos)              /**< (USBHS_HSTISR Mask) PEP_ */
#define USBHS_HSTISR_PEP_(value)              (USBHS_HSTISR_PEP__Msk & ((value) << USBHS_HSTISR_PEP__Pos))
#define USBHS_HSTISR_DMA__Pos                 (25)                                           /**< (USBHS_HSTISR Position) DMA Channel 7 Interrupt */
#define USBHS_HSTISR_DMA__Msk                 (0x7FU << USBHS_HSTISR_DMA__Pos)               /**< (USBHS_HSTISR Mask) DMA_ */
#define USBHS_HSTISR_DMA_(value)              (USBHS_HSTISR_DMA__Msk & ((value) << USBHS_HSTISR_DMA__Pos))

/* -------- USBHS_HSTICR : (USBHS Offset: 0x408) (/W 32) Host Global Interrupt Clear Register -------- */

typedef union
{
  struct
  {
    uint32_t DCONNIC:1;                 /**< bit:      0  Device Connection Interrupt Clear             */
    uint32_t DDISCIC:1;                 /**< bit:      1  Device Disconnection Interrupt Clear          */
    uint32_t RSTIC:1;                   /**< bit:      2  USB Reset Sent Interrupt Clear                */
    uint32_t RSMEDIC:1;                 /**< bit:      3  Downstream Resume Sent Interrupt Clear        */
    uint32_t RXRSMIC:1;                 /**< bit:      4  Upstream Resume Received Interrupt Clear      */
    uint32_t HSOFIC:1;                  /**< bit:      5  Host Start of Frame Interrupt Clear           */
    uint32_t HWUPIC:1;                  /**< bit:      6  Host Wake-Up Interrupt Clear                  */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTICR_bits_t;

#define USBHS_HSTICR_DCONNIC_Pos              (0)                                            /**< (USBHS_HSTICR) Device Connection Interrupt Clear Position */
#define USBHS_HSTICR_DCONNIC_Msk              (0x1U << USBHS_HSTICR_DCONNIC_Pos)             /**< (USBHS_HSTICR) Device Connection Interrupt Clear Mask */
#define USBHS_HSTICR_DDISCIC_Pos              (1)                                            /**< (USBHS_HSTICR) Device Disconnection Interrupt Clear Position */
#define USBHS_HSTICR_DDISCIC_Msk              (0x1U << USBHS_HSTICR_DDISCIC_Pos)             /**< (USBHS_HSTICR) Device Disconnection Interrupt Clear Mask */
#define USBHS_HSTICR_RSTIC_Pos                (2)                                            /**< (USBHS_HSTICR) USB Reset Sent Interrupt Clear Position */
#define USBHS_HSTICR_RSTIC_Msk                (0x1U << USBHS_HSTICR_RSTIC_Pos)               /**< (USBHS_HSTICR) USB Reset Sent Interrupt Clear Mask */
#define USBHS_HSTICR_RSMEDIC_Pos              (3)                                            /**< (USBHS_HSTICR) Downstream Resume Sent Interrupt Clear Position */
#define USBHS_HSTICR_RSMEDIC_Msk              (0x1U << USBHS_HSTICR_RSMEDIC_Pos)             /**< (USBHS_HSTICR) Downstream Resume Sent Interrupt Clear Mask */
#define USBHS_HSTICR_RXRSMIC_Pos              (4)                                            /**< (USBHS_HSTICR) Upstream Resume Received Interrupt Clear Position */
#define USBHS_HSTICR_RXRSMIC_Msk              (0x1U << USBHS_HSTICR_RXRSMIC_Pos)             /**< (USBHS_HSTICR) Upstream Resume Received Interrupt Clear Mask */
#define USBHS_HSTICR_HSOFIC_Pos               (5)                                            /**< (USBHS_HSTICR) Host Start of Frame Interrupt Clear Position */
#define USBHS_HSTICR_HSOFIC_Msk               (0x1U << USBHS_HSTICR_HSOFIC_Pos)              /**< (USBHS_HSTICR) Host Start of Frame Interrupt Clear Mask */
#define USBHS_HSTICR_HWUPIC_Pos               (6)                                            /**< (USBHS_HSTICR) Host Wake-Up Interrupt Clear Position */
#define USBHS_HSTICR_HWUPIC_Msk               (0x1U << USBHS_HSTICR_HWUPIC_Pos)              /**< (USBHS_HSTICR) Host Wake-Up Interrupt Clear Mask */
#define USBHS_HSTICR_Msk                      (0x0000007FUL)                                 /**< (USBHS_HSTICR) Register Mask  */

/* -------- USBHS_HSTIFR : (USBHS Offset: 0x40c) (/W 32) Host Global Interrupt Set Register -------- */

typedef union
{
  struct
  {
    uint32_t DCONNIS:1;                 /**< bit:      0  Device Connection Interrupt Set               */
    uint32_t DDISCIS:1;                 /**< bit:      1  Device Disconnection Interrupt Set            */
    uint32_t RSTIS:1;                   /**< bit:      2  USB Reset Sent Interrupt Set                  */
    uint32_t RSMEDIS:1;                 /**< bit:      3  Downstream Resume Sent Interrupt Set          */
    uint32_t RXRSMIS:1;                 /**< bit:      4  Upstream Resume Received Interrupt Set        */
    uint32_t HSOFIS:1;                  /**< bit:      5  Host Start of Frame Interrupt Set             */
    uint32_t HWUPIS:1;                  /**< bit:      6  Host Wake-Up Interrupt Set                    */
    uint32_t :18;                       /**< bit:  7..24  Reserved                                      */
    uint32_t DMA_1:1;                   /**< bit:     25  DMA Channel 1 Interrupt Set                   */
    uint32_t DMA_2:1;                   /**< bit:     26  DMA Channel 2 Interrupt Set                   */
    uint32_t DMA_3:1;                   /**< bit:     27  DMA Channel 3 Interrupt Set                   */
    uint32_t DMA_4:1;                   /**< bit:     28  DMA Channel 4 Interrupt Set                   */
    uint32_t DMA_5:1;                   /**< bit:     29  DMA Channel 5 Interrupt Set                   */
    uint32_t DMA_6:1;                   /**< bit:     30  DMA Channel 6 Interrupt Set                   */
    uint32_t DMA_7:1;                   /**< bit:     31  DMA Channel 7 Interrupt Set                   */
  };
  struct
  {
    uint32_t :25;                       /**< bit:  0..24  Reserved                                      */
    uint32_t DMA_:7;                    /**< bit: 25..31  DMA Channel 7 Interrupt Set                   */
  };
  uint32_t w;
} __USBHS_HSTIFR_bits_t;

#define USBHS_HSTIFR_DCONNIS_Pos              (0)                                            /**< (USBHS_HSTIFR) Device Connection Interrupt Set Position */
#define USBHS_HSTIFR_DCONNIS_Msk              (0x1U << USBHS_HSTIFR_DCONNIS_Pos)             /**< (USBHS_HSTIFR) Device Connection Interrupt Set Mask */
#define USBHS_HSTIFR_DDISCIS_Pos              (1)                                            /**< (USBHS_HSTIFR) Device Disconnection Interrupt Set Position */
#define USBHS_HSTIFR_DDISCIS_Msk              (0x1U << USBHS_HSTIFR_DDISCIS_Pos)             /**< (USBHS_HSTIFR) Device Disconnection Interrupt Set Mask */
#define USBHS_HSTIFR_RSTIS_Pos                (2)                                            /**< (USBHS_HSTIFR) USB Reset Sent Interrupt Set Position */
#define USBHS_HSTIFR_RSTIS_Msk                (0x1U << USBHS_HSTIFR_RSTIS_Pos)               /**< (USBHS_HSTIFR) USB Reset Sent Interrupt Set Mask */
#define USBHS_HSTIFR_RSMEDIS_Pos              (3)                                            /**< (USBHS_HSTIFR) Downstream Resume Sent Interrupt Set Position */
#define USBHS_HSTIFR_RSMEDIS_Msk              (0x1U << USBHS_HSTIFR_RSMEDIS_Pos)             /**< (USBHS_HSTIFR) Downstream Resume Sent Interrupt Set Mask */
#define USBHS_HSTIFR_RXRSMIS_Pos              (4)                                            /**< (USBHS_HSTIFR) Upstream Resume Received Interrupt Set Position */
#define USBHS_HSTIFR_RXRSMIS_Msk              (0x1U << USBHS_HSTIFR_RXRSMIS_Pos)             /**< (USBHS_HSTIFR) Upstream Resume Received Interrupt Set Mask */
#define USBHS_HSTIFR_HSOFIS_Pos               (5)                                            /**< (USBHS_HSTIFR) Host Start of Frame Interrupt Set Position */
#define USBHS_HSTIFR_HSOFIS_Msk               (0x1U << USBHS_HSTIFR_HSOFIS_Pos)              /**< (USBHS_HSTIFR) Host Start of Frame Interrupt Set Mask */
#define USBHS_HSTIFR_HWUPIS_Pos               (6)                                            /**< (USBHS_HSTIFR) Host Wake-Up Interrupt Set Position */
#define USBHS_HSTIFR_HWUPIS_Msk               (0x1U << USBHS_HSTIFR_HWUPIS_Pos)              /**< (USBHS_HSTIFR) Host Wake-Up Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_1_Pos                (25)                                           /**< (USBHS_HSTIFR) DMA Channel 1 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_1_Msk                (0x1U << USBHS_HSTIFR_DMA_1_Pos)               /**< (USBHS_HSTIFR) DMA Channel 1 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_2_Pos                (26)                                           /**< (USBHS_HSTIFR) DMA Channel 2 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_2_Msk                (0x1U << USBHS_HSTIFR_DMA_2_Pos)               /**< (USBHS_HSTIFR) DMA Channel 2 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_3_Pos                (27)                                           /**< (USBHS_HSTIFR) DMA Channel 3 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_3_Msk                (0x1U << USBHS_HSTIFR_DMA_3_Pos)               /**< (USBHS_HSTIFR) DMA Channel 3 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_4_Pos                (28)                                           /**< (USBHS_HSTIFR) DMA Channel 4 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_4_Msk                (0x1U << USBHS_HSTIFR_DMA_4_Pos)               /**< (USBHS_HSTIFR) DMA Channel 4 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_5_Pos                (29)                                           /**< (USBHS_HSTIFR) DMA Channel 5 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_5_Msk                (0x1U << USBHS_HSTIFR_DMA_5_Pos)               /**< (USBHS_HSTIFR) DMA Channel 5 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_6_Pos                (30)                                           /**< (USBHS_HSTIFR) DMA Channel 6 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_6_Msk                (0x1U << USBHS_HSTIFR_DMA_6_Pos)               /**< (USBHS_HSTIFR) DMA Channel 6 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_7_Pos                (31)                                           /**< (USBHS_HSTIFR) DMA Channel 7 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_7_Msk                (0x1U << USBHS_HSTIFR_DMA_7_Pos)               /**< (USBHS_HSTIFR) DMA Channel 7 Interrupt Set Mask */
#define USBHS_HSTIFR_Msk                      (0xFE00007FUL)                                 /**< (USBHS_HSTIFR) Register Mask  */
#define USBHS_HSTIFR_DMA__Pos                 (25)                                           /**< (USBHS_HSTIFR Position) DMA Channel 7 Interrupt Set */
#define USBHS_HSTIFR_DMA__Msk                 (0x7FU << USBHS_HSTIFR_DMA__Pos)               /**< (USBHS_HSTIFR Mask) DMA_ */
#define USBHS_HSTIFR_DMA_(value)              (USBHS_HSTIFR_DMA__Msk & ((value) << USBHS_HSTIFR_DMA__Pos))

/* -------- USBHS_HSTIMR : (USBHS Offset: 0x410) (R/ 32) Host Global Interrupt Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t DCONNIE:1;                 /**< bit:      0  Device Connection Interrupt Enable            */
    uint32_t DDISCIE:1;                 /**< bit:      1  Device Disconnection Interrupt Enable         */
    uint32_t RSTIE:1;                   /**< bit:      2  USB Reset Sent Interrupt Enable               */
    uint32_t RSMEDIE:1;                 /**< bit:      3  Downstream Resume Sent Interrupt Enable       */
    uint32_t RXRSMIE:1;                 /**< bit:      4  Upstream Resume Received Interrupt Enable     */
    uint32_t HSOFIE:1;                  /**< bit:      5  Host Start of Frame Interrupt Enable          */
    uint32_t HWUPIE:1;                  /**< bit:      6  Host Wake-Up Interrupt Enable                 */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t PEP_0:1;                   /**< bit:      8  Pipe 0 Interrupt Enable                       */
    uint32_t PEP_1:1;                   /**< bit:      9  Pipe 1 Interrupt Enable                       */
    uint32_t PEP_2:1;                   /**< bit:     10  Pipe 2 Interrupt Enable                       */
    uint32_t PEP_3:1;                   /**< bit:     11  Pipe 3 Interrupt Enable                       */
    uint32_t PEP_4:1;                   /**< bit:     12  Pipe 4 Interrupt Enable                       */
    uint32_t PEP_5:1;                   /**< bit:     13  Pipe 5 Interrupt Enable                       */
    uint32_t PEP_6:1;                   /**< bit:     14  Pipe 6 Interrupt Enable                       */
    uint32_t PEP_7:1;                   /**< bit:     15  Pipe 7 Interrupt Enable                       */
    uint32_t PEP_8:1;                   /**< bit:     16  Pipe 8 Interrupt Enable                       */
    uint32_t PEP_9:1;                   /**< bit:     17  Pipe 9 Interrupt Enable                       */
    uint32_t :7;                        /**< bit: 18..24  Reserved                                      */
    uint32_t DMA_1:1;                   /**< bit:     25  DMA Channel 1 Interrupt Enable                */
    uint32_t DMA_2:1;                   /**< bit:     26  DMA Channel 2 Interrupt Enable                */
    uint32_t DMA_3:1;                   /**< bit:     27  DMA Channel 3 Interrupt Enable                */
    uint32_t DMA_4:1;                   /**< bit:     28  DMA Channel 4 Interrupt Enable                */
    uint32_t DMA_5:1;                   /**< bit:     29  DMA Channel 5 Interrupt Enable                */
    uint32_t DMA_6:1;                   /**< bit:     30  DMA Channel 6 Interrupt Enable                */
    uint32_t DMA_7:1;                   /**< bit:     31  DMA Channel 7 Interrupt Enable                */
  };
  struct
  {
    uint32_t :8;                        /**< bit:   0..7  Reserved                                      */
    uint32_t PEP_:10;                   /**< bit:  8..17  Pipe x Interrupt Enable                       */
    uint32_t :7;                        /**< bit: 18..24  Reserved                                      */
    uint32_t DMA_:7;                    /**< bit: 25..31  DMA Channel 7 Interrupt Enable                */
  };
  uint32_t w;
} __USBHS_HSTIMR_bits_t;

#define USBHS_HSTIMR_DCONNIE_Pos              (0)                                            /**< (USBHS_HSTIMR) Device Connection Interrupt Enable Position */
#define USBHS_HSTIMR_DCONNIE_Msk              (0x1U << USBHS_HSTIMR_DCONNIE_Pos)             /**< (USBHS_HSTIMR) Device Connection Interrupt Enable Mask */
#define USBHS_HSTIMR_DDISCIE_Pos              (1)                                            /**< (USBHS_HSTIMR) Device Disconnection Interrupt Enable Position */
#define USBHS_HSTIMR_DDISCIE_Msk              (0x1U << USBHS_HSTIMR_DDISCIE_Pos)             /**< (USBHS_HSTIMR) Device Disconnection Interrupt Enable Mask */
#define USBHS_HSTIMR_RSTIE_Pos                (2)                                            /**< (USBHS_HSTIMR) USB Reset Sent Interrupt Enable Position */
#define USBHS_HSTIMR_RSTIE_Msk                (0x1U << USBHS_HSTIMR_RSTIE_Pos)               /**< (USBHS_HSTIMR) USB Reset Sent Interrupt Enable Mask */
#define USBHS_HSTIMR_RSMEDIE_Pos              (3)                                            /**< (USBHS_HSTIMR) Downstream Resume Sent Interrupt Enable Position */
#define USBHS_HSTIMR_RSMEDIE_Msk              (0x1U << USBHS_HSTIMR_RSMEDIE_Pos)             /**< (USBHS_HSTIMR) Downstream Resume Sent Interrupt Enable Mask */
#define USBHS_HSTIMR_RXRSMIE_Pos              (4)                                            /**< (USBHS_HSTIMR) Upstream Resume Received Interrupt Enable Position */
#define USBHS_HSTIMR_RXRSMIE_Msk              (0x1U << USBHS_HSTIMR_RXRSMIE_Pos)             /**< (USBHS_HSTIMR) Upstream Resume Received Interrupt Enable Mask */
#define USBHS_HSTIMR_HSOFIE_Pos               (5)                                            /**< (USBHS_HSTIMR) Host Start of Frame Interrupt Enable Position */
#define USBHS_HSTIMR_HSOFIE_Msk               (0x1U << USBHS_HSTIMR_HSOFIE_Pos)              /**< (USBHS_HSTIMR) Host Start of Frame Interrupt Enable Mask */
#define USBHS_HSTIMR_HWUPIE_Pos               (6)                                            /**< (USBHS_HSTIMR) Host Wake-Up Interrupt Enable Position */
#define USBHS_HSTIMR_HWUPIE_Msk               (0x1U << USBHS_HSTIMR_HWUPIE_Pos)              /**< (USBHS_HSTIMR) Host Wake-Up Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_0_Pos                (8)                                            /**< (USBHS_HSTIMR) Pipe 0 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_0_Msk                (0x1U << USBHS_HSTIMR_PEP_0_Pos)               /**< (USBHS_HSTIMR) Pipe 0 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_1_Pos                (9)                                            /**< (USBHS_HSTIMR) Pipe 1 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_1_Msk                (0x1U << USBHS_HSTIMR_PEP_1_Pos)               /**< (USBHS_HSTIMR) Pipe 1 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_2_Pos                (10)                                           /**< (USBHS_HSTIMR) Pipe 2 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_2_Msk                (0x1U << USBHS_HSTIMR_PEP_2_Pos)               /**< (USBHS_HSTIMR) Pipe 2 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_3_Pos                (11)                                           /**< (USBHS_HSTIMR) Pipe 3 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_3_Msk                (0x1U << USBHS_HSTIMR_PEP_3_Pos)               /**< (USBHS_HSTIMR) Pipe 3 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_4_Pos                (12)                                           /**< (USBHS_HSTIMR) Pipe 4 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_4_Msk                (0x1U << USBHS_HSTIMR_PEP_4_Pos)               /**< (USBHS_HSTIMR) Pipe 4 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_5_Pos                (13)                                           /**< (USBHS_HSTIMR) Pipe 5 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_5_Msk                (0x1U << USBHS_HSTIMR_PEP_5_Pos)               /**< (USBHS_HSTIMR) Pipe 5 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_6_Pos                (14)                                           /**< (USBHS_HSTIMR) Pipe 6 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_6_Msk                (0x1U << USBHS_HSTIMR_PEP_6_Pos)               /**< (USBHS_HSTIMR) Pipe 6 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_7_Pos                (15)                                           /**< (USBHS_HSTIMR) Pipe 7 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_7_Msk                (0x1U << USBHS_HSTIMR_PEP_7_Pos)               /**< (USBHS_HSTIMR) Pipe 7 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_8_Pos                (16)                                           /**< (USBHS_HSTIMR) Pipe 8 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_8_Msk                (0x1U << USBHS_HSTIMR_PEP_8_Pos)               /**< (USBHS_HSTIMR) Pipe 8 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_9_Pos                (17)                                           /**< (USBHS_HSTIMR) Pipe 9 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_9_Msk                (0x1U << USBHS_HSTIMR_PEP_9_Pos)               /**< (USBHS_HSTIMR) Pipe 9 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_1_Pos                (25)                                           /**< (USBHS_HSTIMR) DMA Channel 1 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_1_Msk                (0x1U << USBHS_HSTIMR_DMA_1_Pos)               /**< (USBHS_HSTIMR) DMA Channel 1 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_2_Pos                (26)                                           /**< (USBHS_HSTIMR) DMA Channel 2 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_2_Msk                (0x1U << USBHS_HSTIMR_DMA_2_Pos)               /**< (USBHS_HSTIMR) DMA Channel 2 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_3_Pos                (27)                                           /**< (USBHS_HSTIMR) DMA Channel 3 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_3_Msk                (0x1U << USBHS_HSTIMR_DMA_3_Pos)               /**< (USBHS_HSTIMR) DMA Channel 3 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_4_Pos                (28)                                           /**< (USBHS_HSTIMR) DMA Channel 4 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_4_Msk                (0x1U << USBHS_HSTIMR_DMA_4_Pos)               /**< (USBHS_HSTIMR) DMA Channel 4 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_5_Pos                (29)                                           /**< (USBHS_HSTIMR) DMA Channel 5 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_5_Msk                (0x1U << USBHS_HSTIMR_DMA_5_Pos)               /**< (USBHS_HSTIMR) DMA Channel 5 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_6_Pos                (30)                                           /**< (USBHS_HSTIMR) DMA Channel 6 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_6_Msk                (0x1U << USBHS_HSTIMR_DMA_6_Pos)               /**< (USBHS_HSTIMR) DMA Channel 6 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_7_Pos                (31)                                           /**< (USBHS_HSTIMR) DMA Channel 7 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_7_Msk                (0x1U << USBHS_HSTIMR_DMA_7_Pos)               /**< (USBHS_HSTIMR) DMA Channel 7 Interrupt Enable Mask */
#define USBHS_HSTIMR_Msk                      (0xFE03FF7FUL)                                 /**< (USBHS_HSTIMR) Register Mask  */
#define USBHS_HSTIMR_PEP__Pos                 (8)                                            /**< (USBHS_HSTIMR Position) Pipe x Interrupt Enable */
#define USBHS_HSTIMR_PEP__Msk                 (0x3FFU << USBHS_HSTIMR_PEP__Pos)              /**< (USBHS_HSTIMR Mask) PEP_ */
#define USBHS_HSTIMR_PEP_(value)              (USBHS_HSTIMR_PEP__Msk & ((value) << USBHS_HSTIMR_PEP__Pos))
#define USBHS_HSTIMR_DMA__Pos                 (25)                                           /**< (USBHS_HSTIMR Position) DMA Channel 7 Interrupt Enable */
#define USBHS_HSTIMR_DMA__Msk                 (0x7FU << USBHS_HSTIMR_DMA__Pos)               /**< (USBHS_HSTIMR Mask) DMA_ */
#define USBHS_HSTIMR_DMA_(value)              (USBHS_HSTIMR_DMA__Msk & ((value) << USBHS_HSTIMR_DMA__Pos))

/* -------- USBHS_HSTIDR : (USBHS Offset: 0x414) (/W 32) Host Global Interrupt Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t DCONNIEC:1;                /**< bit:      0  Device Connection Interrupt Disable           */
    uint32_t DDISCIEC:1;                /**< bit:      1  Device Disconnection Interrupt Disable        */
    uint32_t RSTIEC:1;                  /**< bit:      2  USB Reset Sent Interrupt Disable              */
    uint32_t RSMEDIEC:1;                /**< bit:      3  Downstream Resume Sent Interrupt Disable      */
    uint32_t RXRSMIEC:1;                /**< bit:      4  Upstream Resume Received Interrupt Disable    */
    uint32_t HSOFIEC:1;                 /**< bit:      5  Host Start of Frame Interrupt Disable         */
    uint32_t HWUPIEC:1;                 /**< bit:      6  Host Wake-Up Interrupt Disable                */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t PEP_0:1;                   /**< bit:      8  Pipe 0 Interrupt Disable                      */
    uint32_t PEP_1:1;                   /**< bit:      9  Pipe 1 Interrupt Disable                      */
    uint32_t PEP_2:1;                   /**< bit:     10  Pipe 2 Interrupt Disable                      */
    uint32_t PEP_3:1;                   /**< bit:     11  Pipe 3 Interrupt Disable                      */
    uint32_t PEP_4:1;                   /**< bit:     12  Pipe 4 Interrupt Disable                      */
    uint32_t PEP_5:1;                   /**< bit:     13  Pipe 5 Interrupt Disable                      */
    uint32_t PEP_6:1;                   /**< bit:     14  Pipe 6 Interrupt Disable                      */
    uint32_t PEP_7:1;                   /**< bit:     15  Pipe 7 Interrupt Disable                      */
    uint32_t PEP_8:1;                   /**< bit:     16  Pipe 8 Interrupt Disable                      */
    uint32_t PEP_9:1;                   /**< bit:     17  Pipe 9 Interrupt Disable                      */
    uint32_t :7;                        /**< bit: 18..24  Reserved                                      */
    uint32_t DMA_1:1;                   /**< bit:     25  DMA Channel 1 Interrupt Disable               */
    uint32_t DMA_2:1;                   /**< bit:     26  DMA Channel 2 Interrupt Disable               */
    uint32_t DMA_3:1;                   /**< bit:     27  DMA Channel 3 Interrupt Disable               */
    uint32_t DMA_4:1;                   /**< bit:     28  DMA Channel 4 Interrupt Disable               */
    uint32_t DMA_5:1;                   /**< bit:     29  DMA Channel 5 Interrupt Disable               */
    uint32_t DMA_6:1;                   /**< bit:     30  DMA Channel 6 Interrupt Disable               */
    uint32_t DMA_7:1;                   /**< bit:     31  DMA Channel 7 Interrupt Disable               */
  };
  struct
  {
    uint32_t :8;                        /**< bit:   0..7  Reserved                                      */
    uint32_t PEP_:10;                   /**< bit:  8..17  Pipe x Interrupt Disable                      */
    uint32_t :7;                        /**< bit: 18..24  Reserved                                      */
    uint32_t DMA_:7;                    /**< bit: 25..31  DMA Channel 7 Interrupt Disable               */
  };
  uint32_t w;
} __USBHS_HSTIDR_bits_t;

#define USBHS_HSTIDR_DCONNIEC_Pos             (0)                                            /**< (USBHS_HSTIDR) Device Connection Interrupt Disable Position */
#define USBHS_HSTIDR_DCONNIEC_Msk             (0x1U << USBHS_HSTIDR_DCONNIEC_Pos)            /**< (USBHS_HSTIDR) Device Connection Interrupt Disable Mask */
#define USBHS_HSTIDR_DDISCIEC_Pos             (1)                                            /**< (USBHS_HSTIDR) Device Disconnection Interrupt Disable Position */
#define USBHS_HSTIDR_DDISCIEC_Msk             (0x1U << USBHS_HSTIDR_DDISCIEC_Pos)            /**< (USBHS_HSTIDR) Device Disconnection Interrupt Disable Mask */
#define USBHS_HSTIDR_RSTIEC_Pos               (2)                                            /**< (USBHS_HSTIDR) USB Reset Sent Interrupt Disable Position */
#define USBHS_HSTIDR_RSTIEC_Msk               (0x1U << USBHS_HSTIDR_RSTIEC_Pos)              /**< (USBHS_HSTIDR) USB Reset Sent Interrupt Disable Mask */
#define USBHS_HSTIDR_RSMEDIEC_Pos             (3)                                            /**< (USBHS_HSTIDR) Downstream Resume Sent Interrupt Disable Position */
#define USBHS_HSTIDR_RSMEDIEC_Msk             (0x1U << USBHS_HSTIDR_RSMEDIEC_Pos)            /**< (USBHS_HSTIDR) Downstream Resume Sent Interrupt Disable Mask */
#define USBHS_HSTIDR_RXRSMIEC_Pos             (4)                                            /**< (USBHS_HSTIDR) Upstream Resume Received Interrupt Disable Position */
#define USBHS_HSTIDR_RXRSMIEC_Msk             (0x1U << USBHS_HSTIDR_RXRSMIEC_Pos)            /**< (USBHS_HSTIDR) Upstream Resume Received Interrupt Disable Mask */
#define USBHS_HSTIDR_HSOFIEC_Pos              (5)                                            /**< (USBHS_HSTIDR) Host Start of Frame Interrupt Disable Position */
#define USBHS_HSTIDR_HSOFIEC_Msk              (0x1U << USBHS_HSTIDR_HSOFIEC_Pos)             /**< (USBHS_HSTIDR) Host Start of Frame Interrupt Disable Mask */
#define USBHS_HSTIDR_HWUPIEC_Pos              (6)                                            /**< (USBHS_HSTIDR) Host Wake-Up Interrupt Disable Position */
#define USBHS_HSTIDR_HWUPIEC_Msk              (0x1U << USBHS_HSTIDR_HWUPIEC_Pos)             /**< (USBHS_HSTIDR) Host Wake-Up Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_0_Pos                (8)                                            /**< (USBHS_HSTIDR) Pipe 0 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_0_Msk                (0x1U << USBHS_HSTIDR_PEP_0_Pos)               /**< (USBHS_HSTIDR) Pipe 0 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_1_Pos                (9)                                            /**< (USBHS_HSTIDR) Pipe 1 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_1_Msk                (0x1U << USBHS_HSTIDR_PEP_1_Pos)               /**< (USBHS_HSTIDR) Pipe 1 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_2_Pos                (10)                                           /**< (USBHS_HSTIDR) Pipe 2 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_2_Msk                (0x1U << USBHS_HSTIDR_PEP_2_Pos)               /**< (USBHS_HSTIDR) Pipe 2 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_3_Pos                (11)                                           /**< (USBHS_HSTIDR) Pipe 3 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_3_Msk                (0x1U << USBHS_HSTIDR_PEP_3_Pos)               /**< (USBHS_HSTIDR) Pipe 3 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_4_Pos                (12)                                           /**< (USBHS_HSTIDR) Pipe 4 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_4_Msk                (0x1U << USBHS_HSTIDR_PEP_4_Pos)               /**< (USBHS_HSTIDR) Pipe 4 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_5_Pos                (13)                                           /**< (USBHS_HSTIDR) Pipe 5 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_5_Msk                (0x1U << USBHS_HSTIDR_PEP_5_Pos)               /**< (USBHS_HSTIDR) Pipe 5 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_6_Pos                (14)                                           /**< (USBHS_HSTIDR) Pipe 6 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_6_Msk                (0x1U << USBHS_HSTIDR_PEP_6_Pos)               /**< (USBHS_HSTIDR) Pipe 6 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_7_Pos                (15)                                           /**< (USBHS_HSTIDR) Pipe 7 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_7_Msk                (0x1U << USBHS_HSTIDR_PEP_7_Pos)               /**< (USBHS_HSTIDR) Pipe 7 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_8_Pos                (16)                                           /**< (USBHS_HSTIDR) Pipe 8 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_8_Msk                (0x1U << USBHS_HSTIDR_PEP_8_Pos)               /**< (USBHS_HSTIDR) Pipe 8 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_9_Pos                (17)                                           /**< (USBHS_HSTIDR) Pipe 9 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_9_Msk                (0x1U << USBHS_HSTIDR_PEP_9_Pos)               /**< (USBHS_HSTIDR) Pipe 9 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_1_Pos                (25)                                           /**< (USBHS_HSTIDR) DMA Channel 1 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_1_Msk                (0x1U << USBHS_HSTIDR_DMA_1_Pos)               /**< (USBHS_HSTIDR) DMA Channel 1 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_2_Pos                (26)                                           /**< (USBHS_HSTIDR) DMA Channel 2 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_2_Msk                (0x1U << USBHS_HSTIDR_DMA_2_Pos)               /**< (USBHS_HSTIDR) DMA Channel 2 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_3_Pos                (27)                                           /**< (USBHS_HSTIDR) DMA Channel 3 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_3_Msk                (0x1U << USBHS_HSTIDR_DMA_3_Pos)               /**< (USBHS_HSTIDR) DMA Channel 3 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_4_Pos                (28)                                           /**< (USBHS_HSTIDR) DMA Channel 4 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_4_Msk                (0x1U << USBHS_HSTIDR_DMA_4_Pos)               /**< (USBHS_HSTIDR) DMA Channel 4 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_5_Pos                (29)                                           /**< (USBHS_HSTIDR) DMA Channel 5 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_5_Msk                (0x1U << USBHS_HSTIDR_DMA_5_Pos)               /**< (USBHS_HSTIDR) DMA Channel 5 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_6_Pos                (30)                                           /**< (USBHS_HSTIDR) DMA Channel 6 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_6_Msk                (0x1U << USBHS_HSTIDR_DMA_6_Pos)               /**< (USBHS_HSTIDR) DMA Channel 6 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_7_Pos                (31)                                           /**< (USBHS_HSTIDR) DMA Channel 7 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_7_Msk                (0x1U << USBHS_HSTIDR_DMA_7_Pos)               /**< (USBHS_HSTIDR) DMA Channel 7 Interrupt Disable Mask */
#define USBHS_HSTIDR_Msk                      (0xFE03FF7FUL)                                 /**< (USBHS_HSTIDR) Register Mask  */
#define USBHS_HSTIDR_PEP__Pos                 (8)                                            /**< (USBHS_HSTIDR Position) Pipe x Interrupt Disable */
#define USBHS_HSTIDR_PEP__Msk                 (0x3FFU << USBHS_HSTIDR_PEP__Pos)              /**< (USBHS_HSTIDR Mask) PEP_ */
#define USBHS_HSTIDR_PEP_(value)              (USBHS_HSTIDR_PEP__Msk & ((value) << USBHS_HSTIDR_PEP__Pos))
#define USBHS_HSTIDR_DMA__Pos                 (25)                                           /**< (USBHS_HSTIDR Position) DMA Channel 7 Interrupt Disable */
#define USBHS_HSTIDR_DMA__Msk                 (0x7FU << USBHS_HSTIDR_DMA__Pos)               /**< (USBHS_HSTIDR Mask) DMA_ */
#define USBHS_HSTIDR_DMA_(value)              (USBHS_HSTIDR_DMA__Msk & ((value) << USBHS_HSTIDR_DMA__Pos))

/* -------- USBHS_HSTIER : (USBHS Offset: 0x418) (/W 32) Host Global Interrupt Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t DCONNIES:1;                /**< bit:      0  Device Connection Interrupt Enable            */
    uint32_t DDISCIES:1;                /**< bit:      1  Device Disconnection Interrupt Enable         */
    uint32_t RSTIES:1;                  /**< bit:      2  USB Reset Sent Interrupt Enable               */
    uint32_t RSMEDIES:1;                /**< bit:      3  Downstream Resume Sent Interrupt Enable       */
    uint32_t RXRSMIES:1;                /**< bit:      4  Upstream Resume Received Interrupt Enable     */
    uint32_t HSOFIES:1;                 /**< bit:      5  Host Start of Frame Interrupt Enable          */
    uint32_t HWUPIES:1;                 /**< bit:      6  Host Wake-Up Interrupt Enable                 */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t PEP_0:1;                   /**< bit:      8  Pipe 0 Interrupt Enable                       */
    uint32_t PEP_1:1;                   /**< bit:      9  Pipe 1 Interrupt Enable                       */
    uint32_t PEP_2:1;                   /**< bit:     10  Pipe 2 Interrupt Enable                       */
    uint32_t PEP_3:1;                   /**< bit:     11  Pipe 3 Interrupt Enable                       */
    uint32_t PEP_4:1;                   /**< bit:     12  Pipe 4 Interrupt Enable                       */
    uint32_t PEP_5:1;                   /**< bit:     13  Pipe 5 Interrupt Enable                       */
    uint32_t PEP_6:1;                   /**< bit:     14  Pipe 6 Interrupt Enable                       */
    uint32_t PEP_7:1;                   /**< bit:     15  Pipe 7 Interrupt Enable                       */
    uint32_t PEP_8:1;                   /**< bit:     16  Pipe 8 Interrupt Enable                       */
    uint32_t PEP_9:1;                   /**< bit:     17  Pipe 9 Interrupt Enable                       */
    uint32_t :7;                        /**< bit: 18..24  Reserved                                      */
    uint32_t DMA_1:1;                   /**< bit:     25  DMA Channel 1 Interrupt Enable                */
    uint32_t DMA_2:1;                   /**< bit:     26  DMA Channel 2 Interrupt Enable                */
    uint32_t DMA_3:1;                   /**< bit:     27  DMA Channel 3 Interrupt Enable                */
    uint32_t DMA_4:1;                   /**< bit:     28  DMA Channel 4 Interrupt Enable                */
    uint32_t DMA_5:1;                   /**< bit:     29  DMA Channel 5 Interrupt Enable                */
    uint32_t DMA_6:1;                   /**< bit:     30  DMA Channel 6 Interrupt Enable                */
    uint32_t DMA_7:1;                   /**< bit:     31  DMA Channel 7 Interrupt Enable                */
  };
  struct
  {
    uint32_t :8;                        /**< bit:   0..7  Reserved                                      */
    uint32_t PEP_:10;                   /**< bit:  8..17  Pipe x Interrupt Enable                       */
    uint32_t :7;                        /**< bit: 18..24  Reserved                                      */
    uint32_t DMA_:7;                    /**< bit: 25..31  DMA Channel 7 Interrupt Enable                */
  };
  uint32_t w;
} __USBHS_HSTIER_bits_t;

#define USBHS_HSTIER_DCONNIES_Pos             (0)                                            /**< (USBHS_HSTIER) Device Connection Interrupt Enable Position */
#define USBHS_HSTIER_DCONNIES_Msk             (0x1U << USBHS_HSTIER_DCONNIES_Pos)            /**< (USBHS_HSTIER) Device Connection Interrupt Enable Mask */
#define USBHS_HSTIER_DDISCIES_Pos             (1)                                            /**< (USBHS_HSTIER) Device Disconnection Interrupt Enable Position */
#define USBHS_HSTIER_DDISCIES_Msk             (0x1U << USBHS_HSTIER_DDISCIES_Pos)            /**< (USBHS_HSTIER) Device Disconnection Interrupt Enable Mask */
#define USBHS_HSTIER_RSTIES_Pos               (2)                                            /**< (USBHS_HSTIER) USB Reset Sent Interrupt Enable Position */
#define USBHS_HSTIER_RSTIES_Msk               (0x1U << USBHS_HSTIER_RSTIES_Pos)              /**< (USBHS_HSTIER) USB Reset Sent Interrupt Enable Mask */
#define USBHS_HSTIER_RSMEDIES_Pos             (3)                                            /**< (USBHS_HSTIER) Downstream Resume Sent Interrupt Enable Position */
#define USBHS_HSTIER_RSMEDIES_Msk             (0x1U << USBHS_HSTIER_RSMEDIES_Pos)            /**< (USBHS_HSTIER) Downstream Resume Sent Interrupt Enable Mask */
#define USBHS_HSTIER_RXRSMIES_Pos             (4)                                            /**< (USBHS_HSTIER) Upstream Resume Received Interrupt Enable Position */
#define USBHS_HSTIER_RXRSMIES_Msk             (0x1U << USBHS_HSTIER_RXRSMIES_Pos)            /**< (USBHS_HSTIER) Upstream Resume Received Interrupt Enable Mask */
#define USBHS_HSTIER_HSOFIES_Pos              (5)                                            /**< (USBHS_HSTIER) Host Start of Frame Interrupt Enable Position */
#define USBHS_HSTIER_HSOFIES_Msk              (0x1U << USBHS_HSTIER_HSOFIES_Pos)             /**< (USBHS_HSTIER) Host Start of Frame Interrupt Enable Mask */
#define USBHS_HSTIER_HWUPIES_Pos              (6)                                            /**< (USBHS_HSTIER) Host Wake-Up Interrupt Enable Position */
#define USBHS_HSTIER_HWUPIES_Msk              (0x1U << USBHS_HSTIER_HWUPIES_Pos)             /**< (USBHS_HSTIER) Host Wake-Up Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_0_Pos                (8)                                            /**< (USBHS_HSTIER) Pipe 0 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_0_Msk                (0x1U << USBHS_HSTIER_PEP_0_Pos)               /**< (USBHS_HSTIER) Pipe 0 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_1_Pos                (9)                                            /**< (USBHS_HSTIER) Pipe 1 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_1_Msk                (0x1U << USBHS_HSTIER_PEP_1_Pos)               /**< (USBHS_HSTIER) Pipe 1 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_2_Pos                (10)                                           /**< (USBHS_HSTIER) Pipe 2 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_2_Msk                (0x1U << USBHS_HSTIER_PEP_2_Pos)               /**< (USBHS_HSTIER) Pipe 2 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_3_Pos                (11)                                           /**< (USBHS_HSTIER) Pipe 3 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_3_Msk                (0x1U << USBHS_HSTIER_PEP_3_Pos)               /**< (USBHS_HSTIER) Pipe 3 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_4_Pos                (12)                                           /**< (USBHS_HSTIER) Pipe 4 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_4_Msk                (0x1U << USBHS_HSTIER_PEP_4_Pos)               /**< (USBHS_HSTIER) Pipe 4 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_5_Pos                (13)                                           /**< (USBHS_HSTIER) Pipe 5 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_5_Msk                (0x1U << USBHS_HSTIER_PEP_5_Pos)               /**< (USBHS_HSTIER) Pipe 5 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_6_Pos                (14)                                           /**< (USBHS_HSTIER) Pipe 6 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_6_Msk                (0x1U << USBHS_HSTIER_PEP_6_Pos)               /**< (USBHS_HSTIER) Pipe 6 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_7_Pos                (15)                                           /**< (USBHS_HSTIER) Pipe 7 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_7_Msk                (0x1U << USBHS_HSTIER_PEP_7_Pos)               /**< (USBHS_HSTIER) Pipe 7 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_8_Pos                (16)                                           /**< (USBHS_HSTIER) Pipe 8 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_8_Msk                (0x1U << USBHS_HSTIER_PEP_8_Pos)               /**< (USBHS_HSTIER) Pipe 8 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_9_Pos                (17)                                           /**< (USBHS_HSTIER) Pipe 9 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_9_Msk                (0x1U << USBHS_HSTIER_PEP_9_Pos)               /**< (USBHS_HSTIER) Pipe 9 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_1_Pos                (25)                                           /**< (USBHS_HSTIER) DMA Channel 1 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_1_Msk                (0x1U << USBHS_HSTIER_DMA_1_Pos)               /**< (USBHS_HSTIER) DMA Channel 1 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_2_Pos                (26)                                           /**< (USBHS_HSTIER) DMA Channel 2 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_2_Msk                (0x1U << USBHS_HSTIER_DMA_2_Pos)               /**< (USBHS_HSTIER) DMA Channel 2 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_3_Pos                (27)                                           /**< (USBHS_HSTIER) DMA Channel 3 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_3_Msk                (0x1U << USBHS_HSTIER_DMA_3_Pos)               /**< (USBHS_HSTIER) DMA Channel 3 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_4_Pos                (28)                                           /**< (USBHS_HSTIER) DMA Channel 4 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_4_Msk                (0x1U << USBHS_HSTIER_DMA_4_Pos)               /**< (USBHS_HSTIER) DMA Channel 4 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_5_Pos                (29)                                           /**< (USBHS_HSTIER) DMA Channel 5 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_5_Msk                (0x1U << USBHS_HSTIER_DMA_5_Pos)               /**< (USBHS_HSTIER) DMA Channel 5 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_6_Pos                (30)                                           /**< (USBHS_HSTIER) DMA Channel 6 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_6_Msk                (0x1U << USBHS_HSTIER_DMA_6_Pos)               /**< (USBHS_HSTIER) DMA Channel 6 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_7_Pos                (31)                                           /**< (USBHS_HSTIER) DMA Channel 7 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_7_Msk                (0x1U << USBHS_HSTIER_DMA_7_Pos)               /**< (USBHS_HSTIER) DMA Channel 7 Interrupt Enable Mask */
#define USBHS_HSTIER_Msk                      (0xFE03FF7FUL)                                 /**< (USBHS_HSTIER) Register Mask  */
#define USBHS_HSTIER_PEP__Pos                 (8)                                            /**< (USBHS_HSTIER Position) Pipe x Interrupt Enable */
#define USBHS_HSTIER_PEP__Msk                 (0x3FFU << USBHS_HSTIER_PEP__Pos)              /**< (USBHS_HSTIER Mask) PEP_ */
#define USBHS_HSTIER_PEP_(value)              (USBHS_HSTIER_PEP__Msk & ((value) << USBHS_HSTIER_PEP__Pos))
#define USBHS_HSTIER_DMA__Pos                 (25)                                           /**< (USBHS_HSTIER Position) DMA Channel 7 Interrupt Enable */
#define USBHS_HSTIER_DMA__Msk                 (0x7FU << USBHS_HSTIER_DMA__Pos)               /**< (USBHS_HSTIER Mask) DMA_ */
#define USBHS_HSTIER_DMA_(value)              (USBHS_HSTIER_DMA__Msk & ((value) << USBHS_HSTIER_DMA__Pos))

/* -------- USBHS_HSTPIP : (USBHS Offset: 0x41c) (R/W 32) Host Pipe Register -------- */

typedef union
{
  struct
  {
    uint32_t PEN0:1;                    /**< bit:      0  Pipe 0 Enable                                 */
    uint32_t PEN1:1;                    /**< bit:      1  Pipe 1 Enable                                 */
    uint32_t PEN2:1;                    /**< bit:      2  Pipe 2 Enable                                 */
    uint32_t PEN3:1;                    /**< bit:      3  Pipe 3 Enable                                 */
    uint32_t PEN4:1;                    /**< bit:      4  Pipe 4 Enable                                 */
    uint32_t PEN5:1;                    /**< bit:      5  Pipe 5 Enable                                 */
    uint32_t PEN6:1;                    /**< bit:      6  Pipe 6 Enable                                 */
    uint32_t PEN7:1;                    /**< bit:      7  Pipe 7 Enable                                 */
    uint32_t PEN8:1;                    /**< bit:      8  Pipe 8 Enable                                 */
    uint32_t :7;                        /**< bit:  9..15  Reserved                                      */
    uint32_t PRST0:1;                   /**< bit:     16  Pipe 0 Reset                                  */
    uint32_t PRST1:1;                   /**< bit:     17  Pipe 1 Reset                                  */
    uint32_t PRST2:1;                   /**< bit:     18  Pipe 2 Reset                                  */
    uint32_t PRST3:1;                   /**< bit:     19  Pipe 3 Reset                                  */
    uint32_t PRST4:1;                   /**< bit:     20  Pipe 4 Reset                                  */
    uint32_t PRST5:1;                   /**< bit:     21  Pipe 5 Reset                                  */
    uint32_t PRST6:1;                   /**< bit:     22  Pipe 6 Reset                                  */
    uint32_t PRST7:1;                   /**< bit:     23  Pipe 7 Reset                                  */
    uint32_t PRST8:1;                   /**< bit:     24  Pipe 8 Reset                                  */
    uint32_t :7;                        /**< bit: 25..31  Reserved                                      */
  };
  struct
  {
    uint32_t PEN:9;                     /**< bit:   0..8  Pipe x Enable                                 */
    uint32_t :7;                        /**< bit:  9..15  Reserved                                      */
    uint32_t PRST:9;                    /**< bit: 16..24  Pipe 8 Reset                                  */
    uint32_t :7;                        /**< bit: 25..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTPIP_bits_t;

#define USBHS_HSTPIP_PEN0_Pos                 (0)                                            /**< (USBHS_HSTPIP) Pipe 0 Enable Position */
#define USBHS_HSTPIP_PEN0_Msk                 (0x1U << USBHS_HSTPIP_PEN0_Pos)                /**< (USBHS_HSTPIP) Pipe 0 Enable Mask */
#define USBHS_HSTPIP_PEN1_Pos                 (1)                                            /**< (USBHS_HSTPIP) Pipe 1 Enable Position */
#define USBHS_HSTPIP_PEN1_Msk                 (0x1U << USBHS_HSTPIP_PEN1_Pos)                /**< (USBHS_HSTPIP) Pipe 1 Enable Mask */
#define USBHS_HSTPIP_PEN2_Pos                 (2)                                            /**< (USBHS_HSTPIP) Pipe 2 Enable Position */
#define USBHS_HSTPIP_PEN2_Msk                 (0x1U << USBHS_HSTPIP_PEN2_Pos)                /**< (USBHS_HSTPIP) Pipe 2 Enable Mask */
#define USBHS_HSTPIP_PEN3_Pos                 (3)                                            /**< (USBHS_HSTPIP) Pipe 3 Enable Position */
#define USBHS_HSTPIP_PEN3_Msk                 (0x1U << USBHS_HSTPIP_PEN3_Pos)                /**< (USBHS_HSTPIP) Pipe 3 Enable Mask */
#define USBHS_HSTPIP_PEN4_Pos                 (4)                                            /**< (USBHS_HSTPIP) Pipe 4 Enable Position */
#define USBHS_HSTPIP_PEN4_Msk                 (0x1U << USBHS_HSTPIP_PEN4_Pos)                /**< (USBHS_HSTPIP) Pipe 4 Enable Mask */
#define USBHS_HSTPIP_PEN5_Pos                 (5)                                            /**< (USBHS_HSTPIP) Pipe 5 Enable Position */
#define USBHS_HSTPIP_PEN5_Msk                 (0x1U << USBHS_HSTPIP_PEN5_Pos)                /**< (USBHS_HSTPIP) Pipe 5 Enable Mask */
#define USBHS_HSTPIP_PEN6_Pos                 (6)                                            /**< (USBHS_HSTPIP) Pipe 6 Enable Position */
#define USBHS_HSTPIP_PEN6_Msk                 (0x1U << USBHS_HSTPIP_PEN6_Pos)                /**< (USBHS_HSTPIP) Pipe 6 Enable Mask */
#define USBHS_HSTPIP_PEN7_Pos                 (7)                                            /**< (USBHS_HSTPIP) Pipe 7 Enable Position */
#define USBHS_HSTPIP_PEN7_Msk                 (0x1U << USBHS_HSTPIP_PEN7_Pos)                /**< (USBHS_HSTPIP) Pipe 7 Enable Mask */
#define USBHS_HSTPIP_PEN8_Pos                 (8)                                            /**< (USBHS_HSTPIP) Pipe 8 Enable Position */
#define USBHS_HSTPIP_PEN8_Msk                 (0x1U << USBHS_HSTPIP_PEN8_Pos)                /**< (USBHS_HSTPIP) Pipe 8 Enable Mask */
#define USBHS_HSTPIP_PRST0_Pos                (16)                                           /**< (USBHS_HSTPIP) Pipe 0 Reset Position */
#define USBHS_HSTPIP_PRST0_Msk                (0x1U << USBHS_HSTPIP_PRST0_Pos)               /**< (USBHS_HSTPIP) Pipe 0 Reset Mask */
#define USBHS_HSTPIP_PRST1_Pos                (17)                                           /**< (USBHS_HSTPIP) Pipe 1 Reset Position */
#define USBHS_HSTPIP_PRST1_Msk                (0x1U << USBHS_HSTPIP_PRST1_Pos)               /**< (USBHS_HSTPIP) Pipe 1 Reset Mask */
#define USBHS_HSTPIP_PRST2_Pos                (18)                                           /**< (USBHS_HSTPIP) Pipe 2 Reset Position */
#define USBHS_HSTPIP_PRST2_Msk                (0x1U << USBHS_HSTPIP_PRST2_Pos)               /**< (USBHS_HSTPIP) Pipe 2 Reset Mask */
#define USBHS_HSTPIP_PRST3_Pos                (19)                                           /**< (USBHS_HSTPIP) Pipe 3 Reset Position */
#define USBHS_HSTPIP_PRST3_Msk                (0x1U << USBHS_HSTPIP_PRST3_Pos)               /**< (USBHS_HSTPIP) Pipe 3 Reset Mask */
#define USBHS_HSTPIP_PRST4_Pos                (20)                                           /**< (USBHS_HSTPIP) Pipe 4 Reset Position */
#define USBHS_HSTPIP_PRST4_Msk                (0x1U << USBHS_HSTPIP_PRST4_Pos)               /**< (USBHS_HSTPIP) Pipe 4 Reset Mask */
#define USBHS_HSTPIP_PRST5_Pos                (21)                                           /**< (USBHS_HSTPIP) Pipe 5 Reset Position */
#define USBHS_HSTPIP_PRST5_Msk                (0x1U << USBHS_HSTPIP_PRST5_Pos)               /**< (USBHS_HSTPIP) Pipe 5 Reset Mask */
#define USBHS_HSTPIP_PRST6_Pos                (22)                                           /**< (USBHS_HSTPIP) Pipe 6 Reset Position */
#define USBHS_HSTPIP_PRST6_Msk                (0x1U << USBHS_HSTPIP_PRST6_Pos)               /**< (USBHS_HSTPIP) Pipe 6 Reset Mask */
#define USBHS_HSTPIP_PRST7_Pos                (23)                                           /**< (USBHS_HSTPIP) Pipe 7 Reset Position */
#define USBHS_HSTPIP_PRST7_Msk                (0x1U << USBHS_HSTPIP_PRST7_Pos)               /**< (USBHS_HSTPIP) Pipe 7 Reset Mask */
#define USBHS_HSTPIP_PRST8_Pos                (24)                                           /**< (USBHS_HSTPIP) Pipe 8 Reset Position */
#define USBHS_HSTPIP_PRST8_Msk                (0x1U << USBHS_HSTPIP_PRST8_Pos)               /**< (USBHS_HSTPIP) Pipe 8 Reset Mask */
#define USBHS_HSTPIP_Msk                      (0x01FF01FFUL)                                 /**< (USBHS_HSTPIP) Register Mask  */
#define USBHS_HSTPIP_PEN_Pos                  (0)                                            /**< (USBHS_HSTPIP Position) Pipe x Enable */
#define USBHS_HSTPIP_PEN_Msk                  (0x1FFU << USBHS_HSTPIP_PEN_Pos)               /**< (USBHS_HSTPIP Mask) PEN */
#define USBHS_HSTPIP_PEN(value)               (USBHS_HSTPIP_PEN_Msk & ((value) << USBHS_HSTPIP_PEN_Pos))
#define USBHS_HSTPIP_PRST_Pos                 (16)                                           /**< (USBHS_HSTPIP Position) Pipe 8 Reset */
#define USBHS_HSTPIP_PRST_Msk                 (0x1FFU << USBHS_HSTPIP_PRST_Pos)              /**< (USBHS_HSTPIP Mask) PRST */
#define USBHS_HSTPIP_PRST(value)              (USBHS_HSTPIP_PRST_Msk & ((value) << USBHS_HSTPIP_PRST_Pos))

/* -------- USBHS_HSTFNUM : (USBHS Offset: 0x420) (R/W 32) Host Frame Number Register -------- */

typedef union
{
  struct
  {
    uint32_t MFNUM:3;                   /**< bit:   0..2  Micro Frame Number                            */
    uint32_t FNUM:11;                   /**< bit:  3..13  Frame Number                                  */
    uint32_t :2;                        /**< bit: 14..15  Reserved                                      */
    uint32_t FLENHIGH:8;                /**< bit: 16..23  Frame Length                                  */
    uint32_t :8;                        /**< bit: 24..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTFNUM_bits_t;

#define USBHS_HSTFNUM_MFNUM_Pos               (0)                                            /**< (USBHS_HSTFNUM) Micro Frame Number Position */
#define USBHS_HSTFNUM_MFNUM_Msk               (0x7U << USBHS_HSTFNUM_MFNUM_Pos)              /**< (USBHS_HSTFNUM) Micro Frame Number Mask */
#define USBHS_HSTFNUM_MFNUM(value)            (USBHS_HSTFNUM_MFNUM_Msk & ((value) << USBHS_HSTFNUM_MFNUM_Pos))
#define USBHS_HSTFNUM_FNUM_Pos                (3)                                            /**< (USBHS_HSTFNUM) Frame Number Position */
#define USBHS_HSTFNUM_FNUM_Msk                (0x7FFU << USBHS_HSTFNUM_FNUM_Pos)             /**< (USBHS_HSTFNUM) Frame Number Mask */
#define USBHS_HSTFNUM_FNUM(value)             (USBHS_HSTFNUM_FNUM_Msk & ((value) << USBHS_HSTFNUM_FNUM_Pos))
#define USBHS_HSTFNUM_FLENHIGH_Pos            (16)                                           /**< (USBHS_HSTFNUM) Frame Length Position */
#define USBHS_HSTFNUM_FLENHIGH_Msk            (0xFFU << USBHS_HSTFNUM_FLENHIGH_Pos)          /**< (USBHS_HSTFNUM) Frame Length Mask */
#define USBHS_HSTFNUM_FLENHIGH(value)         (USBHS_HSTFNUM_FLENHIGH_Msk & ((value) << USBHS_HSTFNUM_FLENHIGH_Pos))
#define USBHS_HSTFNUM_Msk                     (0x00FF3FFFUL)                                 /**< (USBHS_HSTFNUM) Register Mask  */

/* -------- USBHS_HSTADDR1 : (USBHS Offset: 0x424) (R/W 32) Host Address 1 Register -------- */

typedef union
{
  struct
  {
    uint32_t HSTADDRP0:7;               /**< bit:   0..6  USB Host Address                              */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t HSTADDRP1:7;               /**< bit:  8..14  USB Host Address                              */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t HSTADDRP2:7;               /**< bit: 16..22  USB Host Address                              */
    uint32_t :1;                        /**< bit:     23  Reserved                                      */
    uint32_t HSTADDRP3:7;               /**< bit: 24..30  USB Host Address                              */
    uint32_t :1;                        /**< bit:     31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTADDR1_bits_t;

#define USBHS_HSTADDR1_HSTADDRP0_Pos          (0)                                            /**< (USBHS_HSTADDR1) USB Host Address Position */
#define USBHS_HSTADDR1_HSTADDRP0_Msk          (0x7FU << USBHS_HSTADDR1_HSTADDRP0_Pos)        /**< (USBHS_HSTADDR1) USB Host Address Mask */
#define USBHS_HSTADDR1_HSTADDRP0(value)       (USBHS_HSTADDR1_HSTADDRP0_Msk & ((value) << USBHS_HSTADDR1_HSTADDRP0_Pos))
#define USBHS_HSTADDR1_HSTADDRP1_Pos          (8)                                            /**< (USBHS_HSTADDR1) USB Host Address Position */
#define USBHS_HSTADDR1_HSTADDRP1_Msk          (0x7FU << USBHS_HSTADDR1_HSTADDRP1_Pos)        /**< (USBHS_HSTADDR1) USB Host Address Mask */
#define USBHS_HSTADDR1_HSTADDRP1(value)       (USBHS_HSTADDR1_HSTADDRP1_Msk & ((value) << USBHS_HSTADDR1_HSTADDRP1_Pos))
#define USBHS_HSTADDR1_HSTADDRP2_Pos          (16)                                           /**< (USBHS_HSTADDR1) USB Host Address Position */
#define USBHS_HSTADDR1_HSTADDRP2_Msk          (0x7FU << USBHS_HSTADDR1_HSTADDRP2_Pos)        /**< (USBHS_HSTADDR1) USB Host Address Mask */
#define USBHS_HSTADDR1_HSTADDRP2(value)       (USBHS_HSTADDR1_HSTADDRP2_Msk & ((value) << USBHS_HSTADDR1_HSTADDRP2_Pos))
#define USBHS_HSTADDR1_HSTADDRP3_Pos          (24)                                           /**< (USBHS_HSTADDR1) USB Host Address Position */
#define USBHS_HSTADDR1_HSTADDRP3_Msk          (0x7FU << USBHS_HSTADDR1_HSTADDRP3_Pos)        /**< (USBHS_HSTADDR1) USB Host Address Mask */
#define USBHS_HSTADDR1_HSTADDRP3(value)       (USBHS_HSTADDR1_HSTADDRP3_Msk & ((value) << USBHS_HSTADDR1_HSTADDRP3_Pos))
#define USBHS_HSTADDR1_Msk                    (0x7F7F7F7FUL)                                 /**< (USBHS_HSTADDR1) Register Mask  */

/* -------- USBHS_HSTADDR2 : (USBHS Offset: 0x428) (R/W 32) Host Address 2 Register -------- */

typedef union
{
  struct
  {
    uint32_t HSTADDRP4:7;               /**< bit:   0..6  USB Host Address                              */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t HSTADDRP5:7;               /**< bit:  8..14  USB Host Address                              */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t HSTADDRP6:7;               /**< bit: 16..22  USB Host Address                              */
    uint32_t :1;                        /**< bit:     23  Reserved                                      */
    uint32_t HSTADDRP7:7;               /**< bit: 24..30  USB Host Address                              */
    uint32_t :1;                        /**< bit:     31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTADDR2_bits_t;

#define USBHS_HSTADDR2_HSTADDRP4_Pos          (0)                                            /**< (USBHS_HSTADDR2) USB Host Address Position */
#define USBHS_HSTADDR2_HSTADDRP4_Msk          (0x7FU << USBHS_HSTADDR2_HSTADDRP4_Pos)        /**< (USBHS_HSTADDR2) USB Host Address Mask */
#define USBHS_HSTADDR2_HSTADDRP4(value)       (USBHS_HSTADDR2_HSTADDRP4_Msk & ((value) << USBHS_HSTADDR2_HSTADDRP4_Pos))
#define USBHS_HSTADDR2_HSTADDRP5_Pos          (8)                                            /**< (USBHS_HSTADDR2) USB Host Address Position */
#define USBHS_HSTADDR2_HSTADDRP5_Msk          (0x7FU << USBHS_HSTADDR2_HSTADDRP5_Pos)        /**< (USBHS_HSTADDR2) USB Host Address Mask */
#define USBHS_HSTADDR2_HSTADDRP5(value)       (USBHS_HSTADDR2_HSTADDRP5_Msk & ((value) << USBHS_HSTADDR2_HSTADDRP5_Pos))
#define USBHS_HSTADDR2_HSTADDRP6_Pos          (16)                                           /**< (USBHS_HSTADDR2) USB Host Address Position */
#define USBHS_HSTADDR2_HSTADDRP6_Msk          (0x7FU << USBHS_HSTADDR2_HSTADDRP6_Pos)        /**< (USBHS_HSTADDR2) USB Host Address Mask */
#define USBHS_HSTADDR2_HSTADDRP6(value)       (USBHS_HSTADDR2_HSTADDRP6_Msk & ((value) << USBHS_HSTADDR2_HSTADDRP6_Pos))
#define USBHS_HSTADDR2_HSTADDRP7_Pos          (24)                                           /**< (USBHS_HSTADDR2) USB Host Address Position */
#define USBHS_HSTADDR2_HSTADDRP7_Msk          (0x7FU << USBHS_HSTADDR2_HSTADDRP7_Pos)        /**< (USBHS_HSTADDR2) USB Host Address Mask */
#define USBHS_HSTADDR2_HSTADDRP7(value)       (USBHS_HSTADDR2_HSTADDRP7_Msk & ((value) << USBHS_HSTADDR2_HSTADDRP7_Pos))
#define USBHS_HSTADDR2_Msk                    (0x7F7F7F7FUL)                                 /**< (USBHS_HSTADDR2) Register Mask  */

/* -------- USBHS_HSTADDR3 : (USBHS Offset: 0x42c) (R/W 32) Host Address 3 Register -------- */

typedef union
{
  struct
  {
    uint32_t HSTADDRP8:7;               /**< bit:   0..6  USB Host Address                              */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t HSTADDRP9:7;               /**< bit:  8..14  USB Host Address                              */
    uint32_t :17;                       /**< bit: 15..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTADDR3_bits_t;

#define USBHS_HSTADDR3_HSTADDRP8_Pos          (0)                                            /**< (USBHS_HSTADDR3) USB Host Address Position */
#define USBHS_HSTADDR3_HSTADDRP8_Msk          (0x7FU << USBHS_HSTADDR3_HSTADDRP8_Pos)        /**< (USBHS_HSTADDR3) USB Host Address Mask */
#define USBHS_HSTADDR3_HSTADDRP8(value)       (USBHS_HSTADDR3_HSTADDRP8_Msk & ((value) << USBHS_HSTADDR3_HSTADDRP8_Pos))
#define USBHS_HSTADDR3_HSTADDRP9_Pos          (8)                                            /**< (USBHS_HSTADDR3) USB Host Address Position */
#define USBHS_HSTADDR3_HSTADDRP9_Msk          (0x7FU << USBHS_HSTADDR3_HSTADDRP9_Pos)        /**< (USBHS_HSTADDR3) USB Host Address Mask */
#define USBHS_HSTADDR3_HSTADDRP9(value)       (USBHS_HSTADDR3_HSTADDRP9_Msk & ((value) << USBHS_HSTADDR3_HSTADDRP9_Pos))
#define USBHS_HSTADDR3_Msk                    (0x00007F7FUL)                                 /**< (USBHS_HSTADDR3) Register Mask  */

/* -------- USBHS_HSTPIPCFG : (USBHS Offset: 0x500) (R/W 32) Host Pipe Configuration Register -------- */

typedef union
{
  struct
  {
    uint32_t :1;                        /**< bit:      0  Reserved                                      */
    uint32_t ALLOC:1;                   /**< bit:      1  Pipe Memory Allocate                          */
    uint32_t PBK:2;                     /**< bit:   2..3  Pipe Banks                                    */
    uint32_t PSIZE:3;                   /**< bit:   4..6  Pipe Size                                     */
    uint32_t :1;                        /**< bit:      7  Reserved                                      */
    uint32_t PTOKEN:2;                  /**< bit:   8..9  Pipe Token                                    */
    uint32_t AUTOSW:1;                  /**< bit:     10  Automatic Switch                              */
    uint32_t :1;                        /**< bit:     11  Reserved                                      */
    uint32_t PTYPE:2;                   /**< bit: 12..13  Pipe Type                                     */
    uint32_t :2;                        /**< bit: 14..15  Reserved                                      */
    uint32_t PEPNUM:4;                  /**< bit: 16..19  Pipe Endpoint Number                          */
    uint32_t :4;                        /**< bit: 20..23  Reserved                                      */
    uint32_t INTFRQ:8;                  /**< bit: 24..31  Pipe Interrupt Request Frequency              */
  };
  struct
  { // Control and Bulk Endpoints mode
    uint32_t :20;                       /**< bit:  0..19  Reserved                                      */
    uint32_t PINGEN:1;                  /**< bit:     20  Ping Enable                                   */
    uint32_t :3;                        /**< bit: 21..23  Reserved                                      */
    uint32_t BINTERVAL:8;               /**< bit: 24..31  bInterval Parameter for the Bulk-Out/Ping Transaction */
  };
  uint32_t w;
} __USBHS_HSTPIPCFG_bits_t;

#define USBHS_HSTPIPCFG_ALLOC_Pos             (1)                                            /**< (USBHS_HSTPIPCFG) Pipe Memory Allocate Position */
#define USBHS_HSTPIPCFG_ALLOC_Msk             (0x1U << USBHS_HSTPIPCFG_ALLOC_Pos)            /**< (USBHS_HSTPIPCFG) Pipe Memory Allocate Mask */
#define USBHS_HSTPIPCFG_PBK_Pos               (2)                                            /**< (USBHS_HSTPIPCFG) Pipe Banks Position */
#define USBHS_HSTPIPCFG_PBK_Msk               (0x3U << USBHS_HSTPIPCFG_PBK_Pos)              /**< (USBHS_HSTPIPCFG) Pipe Banks Mask */
#define USBHS_HSTPIPCFG_PBK(value)            (USBHS_HSTPIPCFG_PBK_Msk & ((value) << USBHS_HSTPIPCFG_PBK_Pos))
#define   USBHS_HSTPIPCFG_PBK_1_BANK_Val      (0x0U)                                         /**< (USBHS_HSTPIPCFG) Single-bank pipe  */
#define   USBHS_HSTPIPCFG_PBK_2_BANK_Val      (0x1U)                                         /**< (USBHS_HSTPIPCFG) Double-bank pipe  */
#define   USBHS_HSTPIPCFG_PBK_3_BANK_Val      (0x2U)                                         /**< (USBHS_HSTPIPCFG) Triple-bank pipe  */
#define USBHS_HSTPIPCFG_PBK_1_BANK            (USBHS_HSTPIPCFG_PBK_1_BANK_Val << USBHS_HSTPIPCFG_PBK_Pos)  /**< (USBHS_HSTPIPCFG) Single-bank pipe Position  */
#define USBHS_HSTPIPCFG_PBK_2_BANK            (USBHS_HSTPIPCFG_PBK_2_BANK_Val << USBHS_HSTPIPCFG_PBK_Pos)  /**< (USBHS_HSTPIPCFG) Double-bank pipe Position  */
#define USBHS_HSTPIPCFG_PBK_3_BANK            (USBHS_HSTPIPCFG_PBK_3_BANK_Val << USBHS_HSTPIPCFG_PBK_Pos)  /**< (USBHS_HSTPIPCFG) Triple-bank pipe Position  */
#define USBHS_HSTPIPCFG_PSIZE_Pos             (4)                                            /**< (USBHS_HSTPIPCFG) Pipe Size Position */
#define USBHS_HSTPIPCFG_PSIZE_Msk             (0x7U << USBHS_HSTPIPCFG_PSIZE_Pos)            /**< (USBHS_HSTPIPCFG) Pipe Size Mask */
#define USBHS_HSTPIPCFG_PSIZE(value)          (USBHS_HSTPIPCFG_PSIZE_Msk & ((value) << USBHS_HSTPIPCFG_PSIZE_Pos))
#define   USBHS_HSTPIPCFG_PSIZE_8_BYTE_Val    (0x0U)                                         /**< (USBHS_HSTPIPCFG) 8 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_16_BYTE_Val   (0x1U)                                         /**< (USBHS_HSTPIPCFG) 16 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_32_BYTE_Val   (0x2U)                                         /**< (USBHS_HSTPIPCFG) 32 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_64_BYTE_Val   (0x3U)                                         /**< (USBHS_HSTPIPCFG) 64 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_128_BYTE_Val  (0x4U)                                         /**< (USBHS_HSTPIPCFG) 128 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_256_BYTE_Val  (0x5U)                                         /**< (USBHS_HSTPIPCFG) 256 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_512_BYTE_Val  (0x6U)                                         /**< (USBHS_HSTPIPCFG) 512 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_1024_BYTE_Val (0x7U)                                         /**< (USBHS_HSTPIPCFG) 1024 bytes  */
#define USBHS_HSTPIPCFG_PSIZE_8_BYTE          (USBHS_HSTPIPCFG_PSIZE_8_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos)  /**< (USBHS_HSTPIPCFG) 8 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_16_BYTE         (USBHS_HSTPIPCFG_PSIZE_16_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos)  /**< (USBHS_HSTPIPCFG) 16 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_32_BYTE         (USBHS_HSTPIPCFG_PSIZE_32_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos)  /**< (USBHS_HSTPIPCFG) 32 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_64_BYTE         (USBHS_HSTPIPCFG_PSIZE_64_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos)  /**< (USBHS_HSTPIPCFG) 64 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_128_BYTE        (USBHS_HSTPIPCFG_PSIZE_128_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos)  /**< (USBHS_HSTPIPCFG) 128 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_256_BYTE        (USBHS_HSTPIPCFG_PSIZE_256_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos)  /**< (USBHS_HSTPIPCFG) 256 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_512_BYTE        (USBHS_HSTPIPCFG_PSIZE_512_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos)  /**< (USBHS_HSTPIPCFG) 512 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_1024_BYTE       (USBHS_HSTPIPCFG_PSIZE_1024_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos)  /**< (USBHS_HSTPIPCFG) 1024 bytes Position  */
#define USBHS_HSTPIPCFG_PTOKEN_Pos            (8)                                            /**< (USBHS_HSTPIPCFG) Pipe Token Position */
#define USBHS_HSTPIPCFG_PTOKEN_Msk            (0x3U << USBHS_HSTPIPCFG_PTOKEN_Pos)           /**< (USBHS_HSTPIPCFG) Pipe Token Mask */
#define USBHS_HSTPIPCFG_PTOKEN(value)         (USBHS_HSTPIPCFG_PTOKEN_Msk & ((value) << USBHS_HSTPIPCFG_PTOKEN_Pos))
#define   USBHS_HSTPIPCFG_PTOKEN_SETUP_Val    (0x0U)                                         /**< (USBHS_HSTPIPCFG) SETUP  */
#define   USBHS_HSTPIPCFG_PTOKEN_IN_Val       (0x1U)                                         /**< (USBHS_HSTPIPCFG) IN  */
#define   USBHS_HSTPIPCFG_PTOKEN_OUT_Val      (0x2U)                                         /**< (USBHS_HSTPIPCFG) OUT  */
#define USBHS_HSTPIPCFG_PTOKEN_SETUP          (USBHS_HSTPIPCFG_PTOKEN_SETUP_Val << USBHS_HSTPIPCFG_PTOKEN_Pos)  /**< (USBHS_HSTPIPCFG) SETUP Position  */
#define USBHS_HSTPIPCFG_PTOKEN_IN             (USBHS_HSTPIPCFG_PTOKEN_IN_Val << USBHS_HSTPIPCFG_PTOKEN_Pos)  /**< (USBHS_HSTPIPCFG) IN Position  */
#define USBHS_HSTPIPCFG_PTOKEN_OUT            (USBHS_HSTPIPCFG_PTOKEN_OUT_Val << USBHS_HSTPIPCFG_PTOKEN_Pos)  /**< (USBHS_HSTPIPCFG) OUT Position  */
#define USBHS_HSTPIPCFG_AUTOSW_Pos            (10)                                           /**< (USBHS_HSTPIPCFG) Automatic Switch Position */
#define USBHS_HSTPIPCFG_AUTOSW_Msk            (0x1U << USBHS_HSTPIPCFG_AUTOSW_Pos)           /**< (USBHS_HSTPIPCFG) Automatic Switch Mask */
#define USBHS_HSTPIPCFG_PTYPE_Pos             (12)                                           /**< (USBHS_HSTPIPCFG) Pipe Type Position */
#define USBHS_HSTPIPCFG_PTYPE_Msk             (0x3U << USBHS_HSTPIPCFG_PTYPE_Pos)            /**< (USBHS_HSTPIPCFG) Pipe Type Mask */
#define USBHS_HSTPIPCFG_PTYPE(value)          (USBHS_HSTPIPCFG_PTYPE_Msk & ((value) << USBHS_HSTPIPCFG_PTYPE_Pos))
#define   USBHS_HSTPIPCFG_PTYPE_CTRL_Val      (0x0U)                                         /**< (USBHS_HSTPIPCFG) Control  */
#define   USBHS_HSTPIPCFG_PTYPE_ISO_Val       (0x1U)                                         /**< (USBHS_HSTPIPCFG) Isochronous  */
#define   USBHS_HSTPIPCFG_PTYPE_BLK_Val       (0x2U)                                         /**< (USBHS_HSTPIPCFG) Bulk  */
#define   USBHS_HSTPIPCFG_PTYPE_INTRPT_Val    (0x3U)                                         /**< (USBHS_HSTPIPCFG) Interrupt  */
#define USBHS_HSTPIPCFG_PTYPE_CTRL            (USBHS_HSTPIPCFG_PTYPE_CTRL_Val << USBHS_HSTPIPCFG_PTYPE_Pos)  /**< (USBHS_HSTPIPCFG) Control Position  */
#define USBHS_HSTPIPCFG_PTYPE_ISO             (USBHS_HSTPIPCFG_PTYPE_ISO_Val << USBHS_HSTPIPCFG_PTYPE_Pos)  /**< (USBHS_HSTPIPCFG) Isochronous Position  */
#define USBHS_HSTPIPCFG_PTYPE_BLK             (USBHS_HSTPIPCFG_PTYPE_BLK_Val << USBHS_HSTPIPCFG_PTYPE_Pos)  /**< (USBHS_HSTPIPCFG) Bulk Position  */
#define USBHS_HSTPIPCFG_PTYPE_INTRPT          (USBHS_HSTPIPCFG_PTYPE_INTRPT_Val << USBHS_HSTPIPCFG_PTYPE_Pos)  /**< (USBHS_HSTPIPCFG) Interrupt Position  */
#define USBHS_HSTPIPCFG_PEPNUM_Pos            (16)                                           /**< (USBHS_HSTPIPCFG) Pipe Endpoint Number Position */
#define USBHS_HSTPIPCFG_PEPNUM_Msk            (0xFU << USBHS_HSTPIPCFG_PEPNUM_Pos)           /**< (USBHS_HSTPIPCFG) Pipe Endpoint Number Mask */
#define USBHS_HSTPIPCFG_PEPNUM(value)         (USBHS_HSTPIPCFG_PEPNUM_Msk & ((value) << USBHS_HSTPIPCFG_PEPNUM_Pos))
#define USBHS_HSTPIPCFG_INTFRQ_Pos            (24)                                           /**< (USBHS_HSTPIPCFG) Pipe Interrupt Request Frequency Position */
#define USBHS_HSTPIPCFG_INTFRQ_Msk            (0xFFU << USBHS_HSTPIPCFG_INTFRQ_Pos)          /**< (USBHS_HSTPIPCFG) Pipe Interrupt Request Frequency Mask */
#define USBHS_HSTPIPCFG_INTFRQ(value)         (USBHS_HSTPIPCFG_INTFRQ_Msk & ((value) << USBHS_HSTPIPCFG_INTFRQ_Pos))
/* Control and Bulk Endpoints mode */
#define USBHS_HSTPIPCFG_PINGEN_Pos            (20)                                           /**< (USBHS_HSTPIPCFG) Ping Enable Position */
#define USBHS_HSTPIPCFG_PINGEN_Msk            (0x1U << USBHS_HSTPIPCFG_PINGEN_Pos)           /**< (USBHS_HSTPIPCFG) Ping Enable Mask */
#define USBHS_HSTPIPCFG_BINTERVAL_Pos         (24)                                           /**< (USBHS_HSTPIPCFG) bInterval Parameter for the Bulk-Out/Ping Transaction Position */
#define USBHS_HSTPIPCFG_BINTERVAL_Msk         (0xFFU << USBHS_HSTPIPCFG_BINTERVAL_Pos)       /**< (USBHS_HSTPIPCFG) bInterval Parameter for the Bulk-Out/Ping Transaction Mask */
#define USBHS_HSTPIPCFG_BINTERVAL(value)      (USBHS_HSTPIPCFG_BINTERVAL_Msk & ((value) << USBHS_HSTPIPCFG_BINTERVAL_Pos))

/* -------- USBHS_HSTPIPISR : (USBHS Offset: 0x530) (R/ 32) Host Pipe Status Register -------- */

typedef union
{
  struct
  {
    uint32_t RXINI:1;                   /**< bit:      0  Received IN Data Interrupt                    */
    uint32_t TXOUTI:1;                  /**< bit:      1  Transmitted OUT Data Interrupt                */
    uint32_t TXSTPI:1;                  /**< bit:      2  Transmitted SETUP Interrupt                   */
    uint32_t PERRI:1;                   /**< bit:      3  Pipe Error Interrupt                          */
    uint32_t NAKEDI:1;                  /**< bit:      4  NAKed Interrupt                               */
    uint32_t OVERFI:1;                  /**< bit:      5  Overflow Interrupt                            */
    uint32_t :1;                        /**< bit:      6  Reserved                                      */
    uint32_t SHORTPACKETI:1;            /**< bit:      7  Short Packet Interrupt                        */
    uint32_t DTSEQ:2;                   /**< bit:   8..9  Data Toggle Sequence                          */
    uint32_t :2;                        /**< bit: 10..11  Reserved                                      */
    uint32_t NBUSYBK:2;                 /**< bit: 12..13  Number of Busy Banks                          */
    uint32_t CURRBK:2;                  /**< bit: 14..15  Current Bank                                  */
    uint32_t RWALL:1;                   /**< bit:     16  Read/Write Allowed                            */
    uint32_t :1;                        /**< bit:     17  Reserved                                      */
    uint32_t CFGOK:1;                   /**< bit:     18  Configuration OK Status                       */
    uint32_t :1;                        /**< bit:     19  Reserved                                      */
    uint32_t PBYCT:11;                  /**< bit: 20..30  Pipe Byte Count                               */
    uint32_t :1;                        /**< bit:     31  Reserved                                      */
  };
  struct
  { // Control, Interrupt and Bulk Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t RXSTALLDI:1;               /**< bit:      6  Received STALLed Interrupt                    */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  struct
  { // Interrupt and Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFI:1;                 /**< bit:      2  Underflow Interrupt                           */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t CRCERRI:1;                 /**< bit:      6  CRC Error Interrupt                           */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTPIPISR_bits_t;

#define USBHS_HSTPIPISR_RXINI_Pos             (0)                                            /**< (USBHS_HSTPIPISR) Received IN Data Interrupt Position */
#define USBHS_HSTPIPISR_RXINI_Msk             (0x1U << USBHS_HSTPIPISR_RXINI_Pos)            /**< (USBHS_HSTPIPISR) Received IN Data Interrupt Mask */
#define USBHS_HSTPIPISR_TXOUTI_Pos            (1)                                            /**< (USBHS_HSTPIPISR) Transmitted OUT Data Interrupt Position */
#define USBHS_HSTPIPISR_TXOUTI_Msk            (0x1U << USBHS_HSTPIPISR_TXOUTI_Pos)           /**< (USBHS_HSTPIPISR) Transmitted OUT Data Interrupt Mask */
#define USBHS_HSTPIPISR_TXSTPI_Pos            (2)                                            /**< (USBHS_HSTPIPISR) Transmitted SETUP Interrupt Position */
#define USBHS_HSTPIPISR_TXSTPI_Msk            (0x1U << USBHS_HSTPIPISR_TXSTPI_Pos)           /**< (USBHS_HSTPIPISR) Transmitted SETUP Interrupt Mask */
#define USBHS_HSTPIPISR_PERRI_Pos             (3)                                            /**< (USBHS_HSTPIPISR) Pipe Error Interrupt Position */
#define USBHS_HSTPIPISR_PERRI_Msk             (0x1U << USBHS_HSTPIPISR_PERRI_Pos)            /**< (USBHS_HSTPIPISR) Pipe Error Interrupt Mask */
#define USBHS_HSTPIPISR_NAKEDI_Pos            (4)                                            /**< (USBHS_HSTPIPISR) NAKed Interrupt Position */
#define USBHS_HSTPIPISR_NAKEDI_Msk            (0x1U << USBHS_HSTPIPISR_NAKEDI_Pos)           /**< (USBHS_HSTPIPISR) NAKed Interrupt Mask */
#define USBHS_HSTPIPISR_OVERFI_Pos            (5)                                            /**< (USBHS_HSTPIPISR) Overflow Interrupt Position */
#define USBHS_HSTPIPISR_OVERFI_Msk            (0x1U << USBHS_HSTPIPISR_OVERFI_Pos)           /**< (USBHS_HSTPIPISR) Overflow Interrupt Mask */
#define USBHS_HSTPIPISR_SHORTPACKETI_Pos      (7)                                            /**< (USBHS_HSTPIPISR) Short Packet Interrupt Position */
#define USBHS_HSTPIPISR_SHORTPACKETI_Msk      (0x1U << USBHS_HSTPIPISR_SHORTPACKETI_Pos)     /**< (USBHS_HSTPIPISR) Short Packet Interrupt Mask */
#define USBHS_HSTPIPISR_DTSEQ_Pos             (8)                                            /**< (USBHS_HSTPIPISR) Data Toggle Sequence Position */
#define USBHS_HSTPIPISR_DTSEQ_Msk             (0x3U << USBHS_HSTPIPISR_DTSEQ_Pos)            /**< (USBHS_HSTPIPISR) Data Toggle Sequence Mask */
#define USBHS_HSTPIPISR_DTSEQ(value)          (USBHS_HSTPIPISR_DTSEQ_Msk & ((value) << USBHS_HSTPIPISR_DTSEQ_Pos))
#define   USBHS_HSTPIPISR_DTSEQ_DATA0_Val     (0x0U)                                         /**< (USBHS_HSTPIPISR) Data0 toggle sequence  */
#define   USBHS_HSTPIPISR_DTSEQ_DATA1_Val     (0x1U)                                         /**< (USBHS_HSTPIPISR) Data1 toggle sequence  */
#define USBHS_HSTPIPISR_DTSEQ_DATA0           (USBHS_HSTPIPISR_DTSEQ_DATA0_Val << USBHS_HSTPIPISR_DTSEQ_Pos)  /**< (USBHS_HSTPIPISR) Data0 toggle sequence Position  */
#define USBHS_HSTPIPISR_DTSEQ_DATA1           (USBHS_HSTPIPISR_DTSEQ_DATA1_Val << USBHS_HSTPIPISR_DTSEQ_Pos)  /**< (USBHS_HSTPIPISR) Data1 toggle sequence Position  */
#define USBHS_HSTPIPISR_NBUSYBK_Pos           (12)                                           /**< (USBHS_HSTPIPISR) Number of Busy Banks Position */
#define USBHS_HSTPIPISR_NBUSYBK_Msk           (0x3U << USBHS_HSTPIPISR_NBUSYBK_Pos)          /**< (USBHS_HSTPIPISR) Number of Busy Banks Mask */
#define USBHS_HSTPIPISR_NBUSYBK(value)        (USBHS_HSTPIPISR_NBUSYBK_Msk & ((value) << USBHS_HSTPIPISR_NBUSYBK_Pos))
#define   USBHS_HSTPIPISR_NBUSYBK_0_BUSY_Val  (0x0U)                                         /**< (USBHS_HSTPIPISR) 0 busy bank (all banks free)  */
#define   USBHS_HSTPIPISR_NBUSYBK_1_BUSY_Val  (0x1U)                                         /**< (USBHS_HSTPIPISR) 1 busy bank  */
#define   USBHS_HSTPIPISR_NBUSYBK_2_BUSY_Val  (0x2U)                                         /**< (USBHS_HSTPIPISR) 2 busy banks  */
#define   USBHS_HSTPIPISR_NBUSYBK_3_BUSY_Val  (0x3U)                                         /**< (USBHS_HSTPIPISR) 3 busy banks  */
#define USBHS_HSTPIPISR_NBUSYBK_0_BUSY        (USBHS_HSTPIPISR_NBUSYBK_0_BUSY_Val << USBHS_HSTPIPISR_NBUSYBK_Pos)  /**< (USBHS_HSTPIPISR) 0 busy bank (all banks free) Position  */
#define USBHS_HSTPIPISR_NBUSYBK_1_BUSY        (USBHS_HSTPIPISR_NBUSYBK_1_BUSY_Val << USBHS_HSTPIPISR_NBUSYBK_Pos)  /**< (USBHS_HSTPIPISR) 1 busy bank Position  */
#define USBHS_HSTPIPISR_NBUSYBK_2_BUSY        (USBHS_HSTPIPISR_NBUSYBK_2_BUSY_Val << USBHS_HSTPIPISR_NBUSYBK_Pos)  /**< (USBHS_HSTPIPISR) 2 busy banks Position  */
#define USBHS_HSTPIPISR_NBUSYBK_3_BUSY        (USBHS_HSTPIPISR_NBUSYBK_3_BUSY_Val << USBHS_HSTPIPISR_NBUSYBK_Pos)  /**< (USBHS_HSTPIPISR) 3 busy banks Position  */
#define USBHS_HSTPIPISR_CURRBK_Pos            (14)                                           /**< (USBHS_HSTPIPISR) Current Bank Position */
#define USBHS_HSTPIPISR_CURRBK_Msk            (0x3U << USBHS_HSTPIPISR_CURRBK_Pos)           /**< (USBHS_HSTPIPISR) Current Bank Mask */
#define USBHS_HSTPIPISR_CURRBK(value)         (USBHS_HSTPIPISR_CURRBK_Msk & ((value) << USBHS_HSTPIPISR_CURRBK_Pos))
#define   USBHS_HSTPIPISR_CURRBK_BANK0_Val    (0x0U)                                         /**< (USBHS_HSTPIPISR) Current bank is bank0  */
#define   USBHS_HSTPIPISR_CURRBK_BANK1_Val    (0x1U)                                         /**< (USBHS_HSTPIPISR) Current bank is bank1  */
#define   USBHS_HSTPIPISR_CURRBK_BANK2_Val    (0x2U)                                         /**< (USBHS_HSTPIPISR) Current bank is bank2  */
#define USBHS_HSTPIPISR_CURRBK_BANK0          (USBHS_HSTPIPISR_CURRBK_BANK0_Val << USBHS_HSTPIPISR_CURRBK_Pos)  /**< (USBHS_HSTPIPISR) Current bank is bank0 Position  */
#define USBHS_HSTPIPISR_CURRBK_BANK1          (USBHS_HSTPIPISR_CURRBK_BANK1_Val << USBHS_HSTPIPISR_CURRBK_Pos)  /**< (USBHS_HSTPIPISR) Current bank is bank1 Position  */
#define USBHS_HSTPIPISR_CURRBK_BANK2          (USBHS_HSTPIPISR_CURRBK_BANK2_Val << USBHS_HSTPIPISR_CURRBK_Pos)  /**< (USBHS_HSTPIPISR) Current bank is bank2 Position  */
#define USBHS_HSTPIPISR_RWALL_Pos             (16)                                           /**< (USBHS_HSTPIPISR) Read/Write Allowed Position */
#define USBHS_HSTPIPISR_RWALL_Msk             (0x1U << USBHS_HSTPIPISR_RWALL_Pos)            /**< (USBHS_HSTPIPISR) Read/Write Allowed Mask */
#define USBHS_HSTPIPISR_CFGOK_Pos             (18)                                           /**< (USBHS_HSTPIPISR) Configuration OK Status Position */
#define USBHS_HSTPIPISR_CFGOK_Msk             (0x1U << USBHS_HSTPIPISR_CFGOK_Pos)            /**< (USBHS_HSTPIPISR) Configuration OK Status Mask */
#define USBHS_HSTPIPISR_PBYCT_Pos             (20)                                           /**< (USBHS_HSTPIPISR) Pipe Byte Count Position */
#define USBHS_HSTPIPISR_PBYCT_Msk             (0x7FFU << USBHS_HSTPIPISR_PBYCT_Pos)          /**< (USBHS_HSTPIPISR) Pipe Byte Count Mask */
#define USBHS_HSTPIPISR_PBYCT(value)          (USBHS_HSTPIPISR_PBYCT_Msk & ((value) << USBHS_HSTPIPISR_PBYCT_Pos))
/* Control, Interrupt and Bulk Endpoints mode */
#define USBHS_HSTPIPISR_RXSTALLDI_Pos         (6)                                            /**< (USBHS_HSTPIPISR) Received STALLed Interrupt Position */
#define USBHS_HSTPIPISR_RXSTALLDI_Msk         (0x1U << USBHS_HSTPIPISR_RXSTALLDI_Pos)        /**< (USBHS_HSTPIPISR) Received STALLed Interrupt Mask */
/* Interrupt and Isochronous Endpoints mode */
#define USBHS_HSTPIPISR_UNDERFI_Pos           (2)                                            /**< (USBHS_HSTPIPISR) Underflow Interrupt Position */
#define USBHS_HSTPIPISR_UNDERFI_Msk           (0x1U << USBHS_HSTPIPISR_UNDERFI_Pos)          /**< (USBHS_HSTPIPISR) Underflow Interrupt Mask */
/* Isochronous Endpoints mode */
#define USBHS_HSTPIPISR_CRCERRI_Pos           (6)                                            /**< (USBHS_HSTPIPISR) CRC Error Interrupt Position */
#define USBHS_HSTPIPISR_CRCERRI_Msk           (0x1U << USBHS_HSTPIPISR_CRCERRI_Pos)          /**< (USBHS_HSTPIPISR) CRC Error Interrupt Mask */

/* -------- USBHS_HSTPIPICR : (USBHS Offset: 0x560) (/W 32) Host Pipe Clear Register -------- */

typedef union
{
  struct
  {
    uint32_t RXINIC:1;                  /**< bit:      0  Received IN Data Interrupt Clear              */
    uint32_t TXOUTIC:1;                 /**< bit:      1  Transmitted OUT Data Interrupt Clear          */
    uint32_t TXSTPIC:1;                 /**< bit:      2  Transmitted SETUP Interrupt Clear             */
    uint32_t :1;                        /**< bit:      3  Reserved                                      */
    uint32_t NAKEDIC:1;                 /**< bit:      4  NAKed Interrupt Clear                         */
    uint32_t OVERFIC:1;                 /**< bit:      5  Overflow Interrupt Clear                      */
    uint32_t :1;                        /**< bit:      6  Reserved                                      */
    uint32_t SHORTPACKETIC:1;           /**< bit:      7  Short Packet Interrupt Clear                  */
    uint32_t :24;                       /**< bit:  8..31  Reserved                                      */
  };
  struct
  { // Control, Interrupt and Bulk Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t RXSTALLDIC:1;              /**< bit:      6  Received STALLed Interrupt Clear              */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  struct
  { // Interrupt and Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFIC:1;                /**< bit:      2  Underflow Interrupt Clear                     */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t CRCERRIC:1;                /**< bit:      6  CRC Error Interrupt Clear                     */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTPIPICR_bits_t;

#define USBHS_HSTPIPICR_RXINIC_Pos            (0)                                            /**< (USBHS_HSTPIPICR) Received IN Data Interrupt Clear Position */
#define USBHS_HSTPIPICR_RXINIC_Msk            (0x1U << USBHS_HSTPIPICR_RXINIC_Pos)           /**< (USBHS_HSTPIPICR) Received IN Data Interrupt Clear Mask */
#define USBHS_HSTPIPICR_TXOUTIC_Pos           (1)                                            /**< (USBHS_HSTPIPICR) Transmitted OUT Data Interrupt Clear Position */
#define USBHS_HSTPIPICR_TXOUTIC_Msk           (0x1U << USBHS_HSTPIPICR_TXOUTIC_Pos)          /**< (USBHS_HSTPIPICR) Transmitted OUT Data Interrupt Clear Mask */
#define USBHS_HSTPIPICR_TXSTPIC_Pos           (2)                                            /**< (USBHS_HSTPIPICR) Transmitted SETUP Interrupt Clear Position */
#define USBHS_HSTPIPICR_TXSTPIC_Msk           (0x1U << USBHS_HSTPIPICR_TXSTPIC_Pos)          /**< (USBHS_HSTPIPICR) Transmitted SETUP Interrupt Clear Mask */
#define USBHS_HSTPIPICR_NAKEDIC_Pos           (4)                                            /**< (USBHS_HSTPIPICR) NAKed Interrupt Clear Position */
#define USBHS_HSTPIPICR_NAKEDIC_Msk           (0x1U << USBHS_HSTPIPICR_NAKEDIC_Pos)          /**< (USBHS_HSTPIPICR) NAKed Interrupt Clear Mask */
#define USBHS_HSTPIPICR_OVERFIC_Pos           (5)                                            /**< (USBHS_HSTPIPICR) Overflow Interrupt Clear Position */
#define USBHS_HSTPIPICR_OVERFIC_Msk           (0x1U << USBHS_HSTPIPICR_OVERFIC_Pos)          /**< (USBHS_HSTPIPICR) Overflow Interrupt Clear Mask */
#define USBHS_HSTPIPICR_SHORTPACKETIC_Pos     (7)                                            /**< (USBHS_HSTPIPICR) Short Packet Interrupt Clear Position */
#define USBHS_HSTPIPICR_SHORTPACKETIC_Msk     (0x1U << USBHS_HSTPIPICR_SHORTPACKETIC_Pos)    /**< (USBHS_HSTPIPICR) Short Packet Interrupt Clear Mask */
/* Control, Interrupt and Bulk Endpoints mode */
#define USBHS_HSTPIPICR_RXSTALLDIC_Pos        (6)                                            /**< (USBHS_HSTPIPICR) Received STALLed Interrupt Clear Position */
#define USBHS_HSTPIPICR_RXSTALLDIC_Msk        (0x1U << USBHS_HSTPIPICR_RXSTALLDIC_Pos)       /**< (USBHS_HSTPIPICR) Received STALLed Interrupt Clear Mask */
/* Interrupt and Isochronous Endpoints mode */
#define USBHS_HSTPIPICR_UNDERFIC_Pos          (2)                                            /**< (USBHS_HSTPIPICR) Underflow Interrupt Clear Position */
#define USBHS_HSTPIPICR_UNDERFIC_Msk          (0x1U << USBHS_HSTPIPICR_UNDERFIC_Pos)         /**< (USBHS_HSTPIPICR) Underflow Interrupt Clear Mask */
/* Isochronous Endpoints mode */
#define USBHS_HSTPIPICR_CRCERRIC_Pos          (6)                                            /**< (USBHS_HSTPIPICR) CRC Error Interrupt Clear Position */
#define USBHS_HSTPIPICR_CRCERRIC_Msk          (0x1U << USBHS_HSTPIPICR_CRCERRIC_Pos)         /**< (USBHS_HSTPIPICR) CRC Error Interrupt Clear Mask */

/* -------- USBHS_HSTPIPIFR : (USBHS Offset: 0x590) (/W 32) Host Pipe Set Register -------- */

typedef union
{
  struct
  {
    uint32_t RXINIS:1;                  /**< bit:      0  Received IN Data Interrupt Set                */
    uint32_t TXOUTIS:1;                 /**< bit:      1  Transmitted OUT Data Interrupt Set            */
    uint32_t TXSTPIS:1;                 /**< bit:      2  Transmitted SETUP Interrupt Set               */
    uint32_t PERRIS:1;                  /**< bit:      3  Pipe Error Interrupt Set                      */
    uint32_t NAKEDIS:1;                 /**< bit:      4  NAKed Interrupt Set                           */
    uint32_t OVERFIS:1;                 /**< bit:      5  Overflow Interrupt Set                        */
    uint32_t :1;                        /**< bit:      6  Reserved                                      */
    uint32_t SHORTPACKETIS:1;           /**< bit:      7  Short Packet Interrupt Set                    */
    uint32_t :4;                        /**< bit:  8..11  Reserved                                      */
    uint32_t NBUSYBKS:1;                /**< bit:     12  Number of Busy Banks Set                      */
    uint32_t :19;                       /**< bit: 13..31  Reserved                                      */
  };
  struct
  { // Control, Interrupt and Bulk Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t RXSTALLDIS:1;              /**< bit:      6  Received STALLed Interrupt Set                */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  struct
  { // Interrupt and Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFIS:1;                /**< bit:      2  Underflow Interrupt Set                       */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t CRCERRIS:1;                /**< bit:      6  CRC Error Interrupt Set                       */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTPIPIFR_bits_t;

#define USBHS_HSTPIPIFR_RXINIS_Pos            (0)                                            /**< (USBHS_HSTPIPIFR) Received IN Data Interrupt Set Position */
#define USBHS_HSTPIPIFR_RXINIS_Msk            (0x1U << USBHS_HSTPIPIFR_RXINIS_Pos)           /**< (USBHS_HSTPIPIFR) Received IN Data Interrupt Set Mask */
#define USBHS_HSTPIPIFR_TXOUTIS_Pos           (1)                                            /**< (USBHS_HSTPIPIFR) Transmitted OUT Data Interrupt Set Position */
#define USBHS_HSTPIPIFR_TXOUTIS_Msk           (0x1U << USBHS_HSTPIPIFR_TXOUTIS_Pos)          /**< (USBHS_HSTPIPIFR) Transmitted OUT Data Interrupt Set Mask */
#define USBHS_HSTPIPIFR_TXSTPIS_Pos           (2)                                            /**< (USBHS_HSTPIPIFR) Transmitted SETUP Interrupt Set Position */
#define USBHS_HSTPIPIFR_TXSTPIS_Msk           (0x1U << USBHS_HSTPIPIFR_TXSTPIS_Pos)          /**< (USBHS_HSTPIPIFR) Transmitted SETUP Interrupt Set Mask */
#define USBHS_HSTPIPIFR_PERRIS_Pos            (3)                                            /**< (USBHS_HSTPIPIFR) Pipe Error Interrupt Set Position */
#define USBHS_HSTPIPIFR_PERRIS_Msk            (0x1U << USBHS_HSTPIPIFR_PERRIS_Pos)           /**< (USBHS_HSTPIPIFR) Pipe Error Interrupt Set Mask */
#define USBHS_HSTPIPIFR_NAKEDIS_Pos           (4)                                            /**< (USBHS_HSTPIPIFR) NAKed Interrupt Set Position */
#define USBHS_HSTPIPIFR_NAKEDIS_Msk           (0x1U << USBHS_HSTPIPIFR_NAKEDIS_Pos)          /**< (USBHS_HSTPIPIFR) NAKed Interrupt Set Mask */
#define USBHS_HSTPIPIFR_OVERFIS_Pos           (5)                                            /**< (USBHS_HSTPIPIFR) Overflow Interrupt Set Position */
#define USBHS_HSTPIPIFR_OVERFIS_Msk           (0x1U << USBHS_HSTPIPIFR_OVERFIS_Pos)          /**< (USBHS_HSTPIPIFR) Overflow Interrupt Set Mask */
#define USBHS_HSTPIPIFR_SHORTPACKETIS_Pos     (7)                                            /**< (USBHS_HSTPIPIFR) Short Packet Interrupt Set Position */
#define USBHS_HSTPIPIFR_SHORTPACKETIS_Msk     (0x1U << USBHS_HSTPIPIFR_SHORTPACKETIS_Pos)    /**< (USBHS_HSTPIPIFR) Short Packet Interrupt Set Mask */
#define USBHS_HSTPIPIFR_NBUSYBKS_Pos          (12)                                           /**< (USBHS_HSTPIPIFR) Number of Busy Banks Set Position */
#define USBHS_HSTPIPIFR_NBUSYBKS_Msk          (0x1U << USBHS_HSTPIPIFR_NBUSYBKS_Pos)         /**< (USBHS_HSTPIPIFR) Number of Busy Banks Set Mask */
/* Control, Interrupt and Bulk Endpoints mode */
#define USBHS_HSTPIPIFR_RXSTALLDIS_Pos        (6)                                            /**< (USBHS_HSTPIPIFR) Received STALLed Interrupt Set Position */
#define USBHS_HSTPIPIFR_RXSTALLDIS_Msk        (0x1U << USBHS_HSTPIPIFR_RXSTALLDIS_Pos)       /**< (USBHS_HSTPIPIFR) Received STALLed Interrupt Set Mask */
/* Interrupt and Isochronous Endpoints mode */
#define USBHS_HSTPIPIFR_UNDERFIS_Pos          (2)                                            /**< (USBHS_HSTPIPIFR) Underflow Interrupt Set Position */
#define USBHS_HSTPIPIFR_UNDERFIS_Msk          (0x1U << USBHS_HSTPIPIFR_UNDERFIS_Pos)         /**< (USBHS_HSTPIPIFR) Underflow Interrupt Set Mask */
/* Isochronous Endpoints mode */
#define USBHS_HSTPIPIFR_CRCERRIS_Pos          (6)                                            /**< (USBHS_HSTPIPIFR) CRC Error Interrupt Set Position */
#define USBHS_HSTPIPIFR_CRCERRIS_Msk          (0x1U << USBHS_HSTPIPIFR_CRCERRIS_Pos)         /**< (USBHS_HSTPIPIFR) CRC Error Interrupt Set Mask */

/* -------- USBHS_HSTPIPIMR : (USBHS Offset: 0x5c0) (R/ 32) Host Pipe Mask Register -------- */

typedef union
{
  struct
  {
    uint32_t RXINE:1;                   /**< bit:      0  Received IN Data Interrupt Enable             */
    uint32_t TXOUTE:1;                  /**< bit:      1  Transmitted OUT Data Interrupt Enable         */
    uint32_t TXSTPE:1;                  /**< bit:      2  Transmitted SETUP Interrupt Enable            */
    uint32_t PERRE:1;                   /**< bit:      3  Pipe Error Interrupt Enable                   */
    uint32_t NAKEDE:1;                  /**< bit:      4  NAKed Interrupt Enable                        */
    uint32_t OVERFIE:1;                 /**< bit:      5  Overflow Interrupt Enable                     */
    uint32_t :1;                        /**< bit:      6  Reserved                                      */
    uint32_t SHORTPACKETIE:1;           /**< bit:      7  Short Packet Interrupt Enable                 */
    uint32_t :4;                        /**< bit:  8..11  Reserved                                      */
    uint32_t NBUSYBKE:1;                /**< bit:     12  Number of Busy Banks Interrupt Enable         */
    uint32_t :1;                        /**< bit:     13  Reserved                                      */
    uint32_t FIFOCON:1;                 /**< bit:     14  FIFO Control                                  */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t PDISHDMA:1;                /**< bit:     16  Pipe Interrupts Disable HDMA Request Enable   */
    uint32_t PFREEZE:1;                 /**< bit:     17  Pipe Freeze                                   */
    uint32_t RSTDT:1;                   /**< bit:     18  Reset Data Toggle                             */
    uint32_t :13;                       /**< bit: 19..31  Reserved                                      */
  };
  struct
  { // Control, Interrupt and Bulk Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t RXSTALLDE:1;               /**< bit:      6  Received STALLed Interrupt Enable             */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  struct
  { // Interrupt and Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFIE:1;                /**< bit:      2  Underflow Interrupt Enable                    */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t CRCERRE:1;                 /**< bit:      6  CRC Error Interrupt Enable                    */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTPIPIMR_bits_t;

#define USBHS_HSTPIPIMR_RXINE_Pos             (0)                                            /**< (USBHS_HSTPIPIMR) Received IN Data Interrupt Enable Position */
#define USBHS_HSTPIPIMR_RXINE_Msk             (0x1U << USBHS_HSTPIPIMR_RXINE_Pos)            /**< (USBHS_HSTPIPIMR) Received IN Data Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_TXOUTE_Pos            (1)                                            /**< (USBHS_HSTPIPIMR) Transmitted OUT Data Interrupt Enable Position */
#define USBHS_HSTPIPIMR_TXOUTE_Msk            (0x1U << USBHS_HSTPIPIMR_TXOUTE_Pos)           /**< (USBHS_HSTPIPIMR) Transmitted OUT Data Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_TXSTPE_Pos            (2)                                            /**< (USBHS_HSTPIPIMR) Transmitted SETUP Interrupt Enable Position */
#define USBHS_HSTPIPIMR_TXSTPE_Msk            (0x1U << USBHS_HSTPIPIMR_TXSTPE_Pos)           /**< (USBHS_HSTPIPIMR) Transmitted SETUP Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_PERRE_Pos             (3)                                            /**< (USBHS_HSTPIPIMR) Pipe Error Interrupt Enable Position */
#define USBHS_HSTPIPIMR_PERRE_Msk             (0x1U << USBHS_HSTPIPIMR_PERRE_Pos)            /**< (USBHS_HSTPIPIMR) Pipe Error Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_NAKEDE_Pos            (4)                                            /**< (USBHS_HSTPIPIMR) NAKed Interrupt Enable Position */
#define USBHS_HSTPIPIMR_NAKEDE_Msk            (0x1U << USBHS_HSTPIPIMR_NAKEDE_Pos)           /**< (USBHS_HSTPIPIMR) NAKed Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_OVERFIE_Pos           (5)                                            /**< (USBHS_HSTPIPIMR) Overflow Interrupt Enable Position */
#define USBHS_HSTPIPIMR_OVERFIE_Msk           (0x1U << USBHS_HSTPIPIMR_OVERFIE_Pos)          /**< (USBHS_HSTPIPIMR) Overflow Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_SHORTPACKETIE_Pos     (7)                                            /**< (USBHS_HSTPIPIMR) Short Packet Interrupt Enable Position */
#define USBHS_HSTPIPIMR_SHORTPACKETIE_Msk     (0x1U << USBHS_HSTPIPIMR_SHORTPACKETIE_Pos)    /**< (USBHS_HSTPIPIMR) Short Packet Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_NBUSYBKE_Pos          (12)                                           /**< (USBHS_HSTPIPIMR) Number of Busy Banks Interrupt Enable Position */
#define USBHS_HSTPIPIMR_NBUSYBKE_Msk          (0x1U << USBHS_HSTPIPIMR_NBUSYBKE_Pos)         /**< (USBHS_HSTPIPIMR) Number of Busy Banks Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_FIFOCON_Pos           (14)                                           /**< (USBHS_HSTPIPIMR) FIFO Control Position */
#define USBHS_HSTPIPIMR_FIFOCON_Msk           (0x1U << USBHS_HSTPIPIMR_FIFOCON_Pos)          /**< (USBHS_HSTPIPIMR) FIFO Control Mask */
#define USBHS_HSTPIPIMR_PDISHDMA_Pos          (16)                                           /**< (USBHS_HSTPIPIMR) Pipe Interrupts Disable HDMA Request Enable Position */
#define USBHS_HSTPIPIMR_PDISHDMA_Msk          (0x1U << USBHS_HSTPIPIMR_PDISHDMA_Pos)         /**< (USBHS_HSTPIPIMR) Pipe Interrupts Disable HDMA Request Enable Mask */
#define USBHS_HSTPIPIMR_PFREEZE_Pos           (17)                                           /**< (USBHS_HSTPIPIMR) Pipe Freeze Position */
#define USBHS_HSTPIPIMR_PFREEZE_Msk           (0x1U << USBHS_HSTPIPIMR_PFREEZE_Pos)          /**< (USBHS_HSTPIPIMR) Pipe Freeze Mask */
#define USBHS_HSTPIPIMR_RSTDT_Pos             (18)                                           /**< (USBHS_HSTPIPIMR) Reset Data Toggle Position */
#define USBHS_HSTPIPIMR_RSTDT_Msk             (0x1U << USBHS_HSTPIPIMR_RSTDT_Pos)            /**< (USBHS_HSTPIPIMR) Reset Data Toggle Mask */
/* Control, Interrupt and Bulk Endpoints mode */
#define USBHS_HSTPIPIMR_RXSTALLDE_Pos         (6)                                            /**< (USBHS_HSTPIPIMR) Received STALLed Interrupt Enable Position */
#define USBHS_HSTPIPIMR_RXSTALLDE_Msk         (0x1U << USBHS_HSTPIPIMR_RXSTALLDE_Pos)        /**< (USBHS_HSTPIPIMR) Received STALLed Interrupt Enable Mask */
/* Interrupt and Isochronous Endpoints mode */
#define USBHS_HSTPIPIMR_UNDERFIE_Pos          (2)                                            /**< (USBHS_HSTPIPIMR) Underflow Interrupt Enable Position */
#define USBHS_HSTPIPIMR_UNDERFIE_Msk          (0x1U << USBHS_HSTPIPIMR_UNDERFIE_Pos)         /**< (USBHS_HSTPIPIMR) Underflow Interrupt Enable Mask */
/* Isochronous Endpoints mode */
#define USBHS_HSTPIPIMR_CRCERRE_Pos           (6)                                            /**< (USBHS_HSTPIPIMR) CRC Error Interrupt Enable Position */
#define USBHS_HSTPIPIMR_CRCERRE_Msk           (0x1U << USBHS_HSTPIPIMR_CRCERRE_Pos)          /**< (USBHS_HSTPIPIMR) CRC Error Interrupt Enable Mask */

/* -------- USBHS_HSTPIPIER : (USBHS Offset: 0x5f0) (/W 32) Host Pipe Enable Register -------- */

typedef union
{
  struct
  {
    uint32_t RXINES:1;                  /**< bit:      0  Received IN Data Interrupt Enable             */
    uint32_t TXOUTES:1;                 /**< bit:      1  Transmitted OUT Data Interrupt Enable         */
    uint32_t TXSTPES:1;                 /**< bit:      2  Transmitted SETUP Interrupt Enable            */
    uint32_t PERRES:1;                  /**< bit:      3  Pipe Error Interrupt Enable                   */
    uint32_t NAKEDES:1;                 /**< bit:      4  NAKed Interrupt Enable                        */
    uint32_t OVERFIES:1;                /**< bit:      5  Overflow Interrupt Enable                     */
    uint32_t :1;                        /**< bit:      6  Reserved                                      */
    uint32_t SHORTPACKETIES:1;          /**< bit:      7  Short Packet Interrupt Enable                 */
    uint32_t :4;                        /**< bit:  8..11  Reserved                                      */
    uint32_t NBUSYBKES:1;               /**< bit:     12  Number of Busy Banks Enable                   */
    uint32_t :3;                        /**< bit: 13..15  Reserved                                      */
    uint32_t PDISHDMAS:1;               /**< bit:     16  Pipe Interrupts Disable HDMA Request Enable   */
    uint32_t PFREEZES:1;                /**< bit:     17  Pipe Freeze Enable                            */
    uint32_t RSTDTS:1;                  /**< bit:     18  Reset Data Toggle Enable                      */
    uint32_t :13;                       /**< bit: 19..31  Reserved                                      */
  };
  struct
  { // Control, Interrupt and Bulk Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t RXSTALLDES:1;              /**< bit:      6  Received STALLed Interrupt Enable             */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  struct
  { // Interrupt and Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFIES:1;               /**< bit:      2  Underflow Interrupt Enable                    */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t CRCERRES:1;                /**< bit:      6  CRC Error Interrupt Enable                    */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTPIPIER_bits_t;

#define USBHS_HSTPIPIER_RXINES_Pos            (0)                                            /**< (USBHS_HSTPIPIER) Received IN Data Interrupt Enable Position */
#define USBHS_HSTPIPIER_RXINES_Msk            (0x1U << USBHS_HSTPIPIER_RXINES_Pos)           /**< (USBHS_HSTPIPIER) Received IN Data Interrupt Enable Mask */
#define USBHS_HSTPIPIER_TXOUTES_Pos           (1)                                            /**< (USBHS_HSTPIPIER) Transmitted OUT Data Interrupt Enable Position */
#define USBHS_HSTPIPIER_TXOUTES_Msk           (0x1U << USBHS_HSTPIPIER_TXOUTES_Pos)          /**< (USBHS_HSTPIPIER) Transmitted OUT Data Interrupt Enable Mask */
#define USBHS_HSTPIPIER_TXSTPES_Pos           (2)                                            /**< (USBHS_HSTPIPIER) Transmitted SETUP Interrupt Enable Position */
#define USBHS_HSTPIPIER_TXSTPES_Msk           (0x1U << USBHS_HSTPIPIER_TXSTPES_Pos)          /**< (USBHS_HSTPIPIER) Transmitted SETUP Interrupt Enable Mask */
#define USBHS_HSTPIPIER_PERRES_Pos            (3)                                            /**< (USBHS_HSTPIPIER) Pipe Error Interrupt Enable Position */
#define USBHS_HSTPIPIER_PERRES_Msk            (0x1U << USBHS_HSTPIPIER_PERRES_Pos)           /**< (USBHS_HSTPIPIER) Pipe Error Interrupt Enable Mask */
#define USBHS_HSTPIPIER_NAKEDES_Pos           (4)                                            /**< (USBHS_HSTPIPIER) NAKed Interrupt Enable Position */
#define USBHS_HSTPIPIER_NAKEDES_Msk           (0x1U << USBHS_HSTPIPIER_NAKEDES_Pos)          /**< (USBHS_HSTPIPIER) NAKed Interrupt Enable Mask */
#define USBHS_HSTPIPIER_OVERFIES_Pos          (5)                                            /**< (USBHS_HSTPIPIER) Overflow Interrupt Enable Position */
#define USBHS_HSTPIPIER_OVERFIES_Msk          (0x1U << USBHS_HSTPIPIER_OVERFIES_Pos)         /**< (USBHS_HSTPIPIER) Overflow Interrupt Enable Mask */
#define USBHS_HSTPIPIER_SHORTPACKETIES_Pos    (7)                                            /**< (USBHS_HSTPIPIER) Short Packet Interrupt Enable Position */
#define USBHS_HSTPIPIER_SHORTPACKETIES_Msk    (0x1U << USBHS_HSTPIPIER_SHORTPACKETIES_Pos)   /**< (USBHS_HSTPIPIER) Short Packet Interrupt Enable Mask */
#define USBHS_HSTPIPIER_NBUSYBKES_Pos         (12)                                           /**< (USBHS_HSTPIPIER) Number of Busy Banks Enable Position */
#define USBHS_HSTPIPIER_NBUSYBKES_Msk         (0x1U << USBHS_HSTPIPIER_NBUSYBKES_Pos)        /**< (USBHS_HSTPIPIER) Number of Busy Banks Enable Mask */
#define USBHS_HSTPIPIER_PDISHDMAS_Pos         (16)                                           /**< (USBHS_HSTPIPIER) Pipe Interrupts Disable HDMA Request Enable Position */
#define USBHS_HSTPIPIER_PDISHDMAS_Msk         (0x1U << USBHS_HSTPIPIER_PDISHDMAS_Pos)        /**< (USBHS_HSTPIPIER) Pipe Interrupts Disable HDMA Request Enable Mask */
#define USBHS_HSTPIPIER_PFREEZES_Pos          (17)                                           /**< (USBHS_HSTPIPIER) Pipe Freeze Enable Position */
#define USBHS_HSTPIPIER_PFREEZES_Msk          (0x1U << USBHS_HSTPIPIER_PFREEZES_Pos)         /**< (USBHS_HSTPIPIER) Pipe Freeze Enable Mask */
#define USBHS_HSTPIPIER_RSTDTS_Pos            (18)                                           /**< (USBHS_HSTPIPIER) Reset Data Toggle Enable Position */
#define USBHS_HSTPIPIER_RSTDTS_Msk            (0x1U << USBHS_HSTPIPIER_RSTDTS_Pos)           /**< (USBHS_HSTPIPIER) Reset Data Toggle Enable Mask */
/* Control, Interrupt and Bulk Endpoints mode */
#define USBHS_HSTPIPIER_RXSTALLDES_Pos        (6)                                            /**< (USBHS_HSTPIPIER) Received STALLed Interrupt Enable Position */
#define USBHS_HSTPIPIER_RXSTALLDES_Msk        (0x1U << USBHS_HSTPIPIER_RXSTALLDES_Pos)       /**< (USBHS_HSTPIPIER) Received STALLed Interrupt Enable Mask */
/* Interrupt and Isochronous Endpoints mode */
#define USBHS_HSTPIPIER_UNDERFIES_Pos         (2)                                            /**< (USBHS_HSTPIPIER) Underflow Interrupt Enable Position */
#define USBHS_HSTPIPIER_UNDERFIES_Msk         (0x1U << USBHS_HSTPIPIER_UNDERFIES_Pos)        /**< (USBHS_HSTPIPIER) Underflow Interrupt Enable Mask */
/* Isochronous Endpoints mode */
#define USBHS_HSTPIPIER_CRCERRES_Pos          (6)                                            /**< (USBHS_HSTPIPIER) CRC Error Interrupt Enable Position */
#define USBHS_HSTPIPIER_CRCERRES_Msk          (0x1U << USBHS_HSTPIPIER_CRCERRES_Pos)         /**< (USBHS_HSTPIPIER) CRC Error Interrupt Enable Mask */

/* -------- USBHS_HSTPIPIDR : (USBHS Offset: 0x620) (/W 32) Host Pipe Disable Register -------- */

typedef union
{
  struct
  {
    uint32_t RXINEC:1;                  /**< bit:      0  Received IN Data Interrupt Disable            */
    uint32_t TXOUTEC:1;                 /**< bit:      1  Transmitted OUT Data Interrupt Disable        */
    uint32_t TXSTPEC:1;                 /**< bit:      2  Transmitted SETUP Interrupt Disable           */
    uint32_t PERREC:1;                  /**< bit:      3  Pipe Error Interrupt Disable                  */
    uint32_t NAKEDEC:1;                 /**< bit:      4  NAKed Interrupt Disable                       */
    uint32_t OVERFIEC:1;                /**< bit:      5  Overflow Interrupt Disable                    */
    uint32_t :1;                        /**< bit:      6  Reserved                                      */
    uint32_t SHORTPACKETIEC:1;          /**< bit:      7  Short Packet Interrupt Disable                */
    uint32_t :4;                        /**< bit:  8..11  Reserved                                      */
    uint32_t NBUSYBKEC:1;               /**< bit:     12  Number of Busy Banks Disable                  */
    uint32_t :1;                        /**< bit:     13  Reserved                                      */
    uint32_t FIFOCONC:1;                /**< bit:     14  FIFO Control Disable                          */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t PDISHDMAC:1;               /**< bit:     16  Pipe Interrupts Disable HDMA Request Disable  */
    uint32_t PFREEZEC:1;                /**< bit:     17  Pipe Freeze Disable                           */
    uint32_t :14;                       /**< bit: 18..31  Reserved                                      */
  };
  struct
  { // Control, Interrupt and Bulk Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t RXSTALLDEC:1;              /**< bit:      6  Received STALLed Interrupt Disable            */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  struct
  { // Interrupt and Isochronous Endpoints mode
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t UNDERFIEC:1;               /**< bit:      2  Underflow Interrupt Disable                   */
    uint32_t :29;                       /**< bit:  3..31  Reserved                                      */
  };
  struct
  { // Isochronous Endpoints mode
    uint32_t :6;                        /**< bit:   0..5  Reserved                                      */
    uint32_t CRCERREC:1;                /**< bit:      6  CRC Error Interrupt Disable                   */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTPIPIDR_bits_t;

#define USBHS_HSTPIPIDR_RXINEC_Pos            (0)                                            /**< (USBHS_HSTPIPIDR) Received IN Data Interrupt Disable Position */
#define USBHS_HSTPIPIDR_RXINEC_Msk            (0x1U << USBHS_HSTPIPIDR_RXINEC_Pos)           /**< (USBHS_HSTPIPIDR) Received IN Data Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_TXOUTEC_Pos           (1)                                            /**< (USBHS_HSTPIPIDR) Transmitted OUT Data Interrupt Disable Position */
#define USBHS_HSTPIPIDR_TXOUTEC_Msk           (0x1U << USBHS_HSTPIPIDR_TXOUTEC_Pos)          /**< (USBHS_HSTPIPIDR) Transmitted OUT Data Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_TXSTPEC_Pos           (2)                                            /**< (USBHS_HSTPIPIDR) Transmitted SETUP Interrupt Disable Position */
#define USBHS_HSTPIPIDR_TXSTPEC_Msk           (0x1U << USBHS_HSTPIPIDR_TXSTPEC_Pos)          /**< (USBHS_HSTPIPIDR) Transmitted SETUP Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_PERREC_Pos            (3)                                            /**< (USBHS_HSTPIPIDR) Pipe Error Interrupt Disable Position */
#define USBHS_HSTPIPIDR_PERREC_Msk            (0x1U << USBHS_HSTPIPIDR_PERREC_Pos)           /**< (USBHS_HSTPIPIDR) Pipe Error Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_NAKEDEC_Pos           (4)                                            /**< (USBHS_HSTPIPIDR) NAKed Interrupt Disable Position */
#define USBHS_HSTPIPIDR_NAKEDEC_Msk           (0x1U << USBHS_HSTPIPIDR_NAKEDEC_Pos)          /**< (USBHS_HSTPIPIDR) NAKed Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_OVERFIEC_Pos          (5)                                            /**< (USBHS_HSTPIPIDR) Overflow Interrupt Disable Position */
#define USBHS_HSTPIPIDR_OVERFIEC_Msk          (0x1U << USBHS_HSTPIPIDR_OVERFIEC_Pos)         /**< (USBHS_HSTPIPIDR) Overflow Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_SHORTPACKETIEC_Pos    (7)                                            /**< (USBHS_HSTPIPIDR) Short Packet Interrupt Disable Position */
#define USBHS_HSTPIPIDR_SHORTPACKETIEC_Msk    (0x1U << USBHS_HSTPIPIDR_SHORTPACKETIEC_Pos)   /**< (USBHS_HSTPIPIDR) Short Packet Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_NBUSYBKEC_Pos         (12)                                           /**< (USBHS_HSTPIPIDR) Number of Busy Banks Disable Position */
#define USBHS_HSTPIPIDR_NBUSYBKEC_Msk         (0x1U << USBHS_HSTPIPIDR_NBUSYBKEC_Pos)        /**< (USBHS_HSTPIPIDR) Number of Busy Banks Disable Mask */
#define USBHS_HSTPIPIDR_FIFOCONC_Pos          (14)                                           /**< (USBHS_HSTPIPIDR) FIFO Control Disable Position */
#define USBHS_HSTPIPIDR_FIFOCONC_Msk          (0x1U << USBHS_HSTPIPIDR_FIFOCONC_Pos)         /**< (USBHS_HSTPIPIDR) FIFO Control Disable Mask */
#define USBHS_HSTPIPIDR_PDISHDMAC_Pos         (16)                                           /**< (USBHS_HSTPIPIDR) Pipe Interrupts Disable HDMA Request Disable Position */
#define USBHS_HSTPIPIDR_PDISHDMAC_Msk         (0x1U << USBHS_HSTPIPIDR_PDISHDMAC_Pos)        /**< (USBHS_HSTPIPIDR) Pipe Interrupts Disable HDMA Request Disable Mask */
#define USBHS_HSTPIPIDR_PFREEZEC_Pos          (17)                                           /**< (USBHS_HSTPIPIDR) Pipe Freeze Disable Position */
#define USBHS_HSTPIPIDR_PFREEZEC_Msk          (0x1U << USBHS_HSTPIPIDR_PFREEZEC_Pos)         /**< (USBHS_HSTPIPIDR) Pipe Freeze Disable Mask */
/* Control, Interrupt and Bulk Endpoints mode */
#define USBHS_HSTPIPIDR_RXSTALLDEC_Pos        (6)                                            /**< (USBHS_HSTPIPIDR) Received STALLed Interrupt Disable Position */
#define USBHS_HSTPIPIDR_RXSTALLDEC_Msk        (0x1U << USBHS_HSTPIPIDR_RXSTALLDEC_Pos)       /**< (USBHS_HSTPIPIDR) Received STALLed Interrupt Disable Mask */
/* Interrupt and Isochronous Endpoints mode */
#define USBHS_HSTPIPIDR_UNDERFIEC_Pos         (2)                                            /**< (USBHS_HSTPIPIDR) Underflow Interrupt Disable Position */
#define USBHS_HSTPIPIDR_UNDERFIEC_Msk         (0x1U << USBHS_HSTPIPIDR_UNDERFIEC_Pos)        /**< (USBHS_HSTPIPIDR) Underflow Interrupt Disable Mask */
/* Isochronous Endpoints mode */
#define USBHS_HSTPIPIDR_CRCERREC_Pos          (6)                                            /**< (USBHS_HSTPIPIDR) CRC Error Interrupt Disable Position */
#define USBHS_HSTPIPIDR_CRCERREC_Msk          (0x1U << USBHS_HSTPIPIDR_CRCERREC_Pos)         /**< (USBHS_HSTPIPIDR) CRC Error Interrupt Disable Mask */

/* -------- USBHS_HSTPIPINRQ : (USBHS Offset: 0x650) (R/W 32) Host Pipe IN Request Register -------- */

typedef union
{
  struct
  {
    uint32_t INRQ:8;                    /**< bit:   0..7  IN Request Number before Freeze               */
    uint32_t INMODE:1;                  /**< bit:      8  IN Request Mode                               */
    uint32_t :23;                       /**< bit:  9..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTPIPINRQ_bits_t;

#define USBHS_HSTPIPINRQ_INRQ_Pos             (0)                                            /**< (USBHS_HSTPIPINRQ) IN Request Number before Freeze Position */
#define USBHS_HSTPIPINRQ_INRQ_Msk             (0xFFU << USBHS_HSTPIPINRQ_INRQ_Pos)           /**< (USBHS_HSTPIPINRQ) IN Request Number before Freeze Mask */
#define USBHS_HSTPIPINRQ_INRQ(value)          (USBHS_HSTPIPINRQ_INRQ_Msk & ((value) << USBHS_HSTPIPINRQ_INRQ_Pos))
#define USBHS_HSTPIPINRQ_INMODE_Pos           (8)                                            /**< (USBHS_HSTPIPINRQ) IN Request Mode Position */
#define USBHS_HSTPIPINRQ_INMODE_Msk           (0x1U << USBHS_HSTPIPINRQ_INMODE_Pos)          /**< (USBHS_HSTPIPINRQ) IN Request Mode Mask */
#define USBHS_HSTPIPINRQ_Msk                  (0x000001FFUL)                                 /**< (USBHS_HSTPIPINRQ) Register Mask  */

/* -------- USBHS_HSTPIPERR : (USBHS Offset: 0x680) (R/W 32) Host Pipe Error Register -------- */

typedef union
{
  struct
  {
    uint32_t DATATGL:1;                 /**< bit:      0  Data Toggle Error                             */
    uint32_t DATAPID:1;                 /**< bit:      1  Data PID Error                                */
    uint32_t PID:1;                     /**< bit:      2  Data PID Error                                */
    uint32_t TIMEOUT:1;                 /**< bit:      3  Time-Out Error                                */
    uint32_t CRC16:1;                   /**< bit:      4  CRC16 Error                                   */
    uint32_t COUNTER:2;                 /**< bit:   5..6  Error Counter                                 */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_HSTPIPERR_bits_t;

#define USBHS_HSTPIPERR_DATATGL_Pos           (0)                                            /**< (USBHS_HSTPIPERR) Data Toggle Error Position */
#define USBHS_HSTPIPERR_DATATGL_Msk           (0x1U << USBHS_HSTPIPERR_DATATGL_Pos)          /**< (USBHS_HSTPIPERR) Data Toggle Error Mask */
#define USBHS_HSTPIPERR_DATAPID_Pos           (1)                                            /**< (USBHS_HSTPIPERR) Data PID Error Position */
#define USBHS_HSTPIPERR_DATAPID_Msk           (0x1U << USBHS_HSTPIPERR_DATAPID_Pos)          /**< (USBHS_HSTPIPERR) Data PID Error Mask */
#define USBHS_HSTPIPERR_PID_Pos               (2)                                            /**< (USBHS_HSTPIPERR) Data PID Error Position */
#define USBHS_HSTPIPERR_PID_Msk               (0x1U << USBHS_HSTPIPERR_PID_Pos)              /**< (USBHS_HSTPIPERR) Data PID Error Mask */
#define USBHS_HSTPIPERR_TIMEOUT_Pos           (3)                                            /**< (USBHS_HSTPIPERR) Time-Out Error Position */
#define USBHS_HSTPIPERR_TIMEOUT_Msk           (0x1U << USBHS_HSTPIPERR_TIMEOUT_Pos)          /**< (USBHS_HSTPIPERR) Time-Out Error Mask */
#define USBHS_HSTPIPERR_CRC16_Pos             (4)                                            /**< (USBHS_HSTPIPERR) CRC16 Error Position */
#define USBHS_HSTPIPERR_CRC16_Msk             (0x1U << USBHS_HSTPIPERR_CRC16_Pos)            /**< (USBHS_HSTPIPERR) CRC16 Error Mask */
#define USBHS_HSTPIPERR_COUNTER_Pos           (5)                                            /**< (USBHS_HSTPIPERR) Error Counter Position */
#define USBHS_HSTPIPERR_COUNTER_Msk           (0x3U << USBHS_HSTPIPERR_COUNTER_Pos)          /**< (USBHS_HSTPIPERR) Error Counter Mask */
#define USBHS_HSTPIPERR_COUNTER(value)        (USBHS_HSTPIPERR_COUNTER_Msk & ((value) << USBHS_HSTPIPERR_COUNTER_Pos))
#define USBHS_HSTPIPERR_Msk                   (0x0000007FUL)                                 /**< (USBHS_HSTPIPERR) Register Mask  */

/* -------- USBHS_CTRL : (USBHS Offset: 0x800) (R/W 32) General Control Register -------- */

typedef union
{
  struct
  {
    uint32_t :4;                        /**< bit:   0..3  Reserved                                      */
    uint32_t RDERRE:1;                  /**< bit:      4  Remote Device Connection Error Interrupt Enable */
    uint32_t :3;                        /**< bit:   5..7  Reserved                                      */
    uint32_t VBUSHWC:1;                 /**< bit:      8  VBUS Hardware Control                         */
    uint32_t :5;                        /**< bit:  9..13  Reserved                                      */
    uint32_t FRZCLK:1;                  /**< bit:     14  Freeze USB Clock                              */
    uint32_t USBE:1;                    /**< bit:     15  USBHS Enable                                  */
    uint32_t :8;                        /**< bit: 16..23  Reserved                                      */
    uint32_t UID:1;                     /**< bit:     24  UID Pin Enable                                */
    uint32_t UIMOD:1;                   /**< bit:     25  USBHS Mode                                    */
    uint32_t :6;                        /**< bit: 26..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_CTRL_bits_t;

#define USBHS_CTRL_RDERRE_Pos                 (4)                                            /**< (USBHS_CTRL) Remote Device Connection Error Interrupt Enable Position */
#define USBHS_CTRL_RDERRE_Msk                 (0x1U << USBHS_CTRL_RDERRE_Pos)                /**< (USBHS_CTRL) Remote Device Connection Error Interrupt Enable Mask */
#define USBHS_CTRL_VBUSHWC_Pos                (8)                                            /**< (USBHS_CTRL) VBUS Hardware Control Position */
#define USBHS_CTRL_VBUSHWC_Msk                (0x1U << USBHS_CTRL_VBUSHWC_Pos)               /**< (USBHS_CTRL) VBUS Hardware Control Mask */
#define USBHS_CTRL_FRZCLK_Pos                 (14)                                           /**< (USBHS_CTRL) Freeze USB Clock Position */
#define USBHS_CTRL_FRZCLK_Msk                 (0x1U << USBHS_CTRL_FRZCLK_Pos)                /**< (USBHS_CTRL) Freeze USB Clock Mask */
#define USBHS_CTRL_USBE_Pos                   (15)                                           /**< (USBHS_CTRL) USBHS Enable Position */
#define USBHS_CTRL_USBE_Msk                   (0x1U << USBHS_CTRL_USBE_Pos)                  /**< (USBHS_CTRL) USBHS Enable Mask */
#define USBHS_CTRL_UID_Pos                    (24)                                           /**< (USBHS_CTRL) UID Pin Enable Position */
#define USBHS_CTRL_UID_Msk                    (0x1U << USBHS_CTRL_UID_Pos)                   /**< (USBHS_CTRL) UID Pin Enable Mask */
#define USBHS_CTRL_UIMOD_Pos                  (25)                                           /**< (USBHS_CTRL) USBHS Mode Position */
#define USBHS_CTRL_UIMOD_Msk                  (0x1U << USBHS_CTRL_UIMOD_Pos)                 /**< (USBHS_CTRL) USBHS Mode Mask */
#define   USBHS_CTRL_UIMOD_HOST_Val           (0x0U)                                         /**< (USBHS_CTRL) The module is in USB Host mode.  */
#define   USBHS_CTRL_UIMOD_DEVICE_Val         (0x1U)                                         /**< (USBHS_CTRL) The module is in USB Device mode.  */
#define USBHS_CTRL_UIMOD_HOST                 (USBHS_CTRL_UIMOD_HOST_Val << USBHS_CTRL_UIMOD_Pos)  /**< (USBHS_CTRL) The module is in USB Host mode. Position  */
#define USBHS_CTRL_UIMOD_DEVICE               (USBHS_CTRL_UIMOD_DEVICE_Val << USBHS_CTRL_UIMOD_Pos)  /**< (USBHS_CTRL) The module is in USB Device mode. Position  */
#define USBHS_CTRL_Msk                        (0x0300C110UL)                                 /**< (USBHS_CTRL) Register Mask  */

/* -------- USBHS_SR : (USBHS Offset: 0x804) (R/ 32) General Status Register -------- */

typedef union
{
  struct
  {
    uint32_t :4;                        /**< bit:   0..3  Reserved                                      */
    uint32_t RDERRI:1;                  /**< bit:      4  Remote Device Connection Error Interrupt (Host mode only) */
    uint32_t :7;                        /**< bit:  5..11  Reserved                                      */
    uint32_t SPEED:2;                   /**< bit: 12..13  Speed Status (Device mode only)               */
    uint32_t CLKUSABLE:1;               /**< bit:     14  UTMI Clock Usable                             */
    uint32_t :17;                       /**< bit: 15..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_SR_bits_t;

#define USBHS_SR_RDERRI_Pos                   (4)                                            /**< (USBHS_SR) Remote Device Connection Error Interrupt (Host mode only) Position */
#define USBHS_SR_RDERRI_Msk                   (0x1U << USBHS_SR_RDERRI_Pos)                  /**< (USBHS_SR) Remote Device Connection Error Interrupt (Host mode only) Mask */
#define USBHS_SR_SPEED_Pos                    (12)                                           /**< (USBHS_SR) Speed Status (Device mode only) Position */
#define USBHS_SR_SPEED_Msk                    (0x3U << USBHS_SR_SPEED_Pos)                   /**< (USBHS_SR) Speed Status (Device mode only) Mask */
#define USBHS_SR_SPEED(value)                 (USBHS_SR_SPEED_Msk & ((value) << USBHS_SR_SPEED_Pos))
#define   USBHS_SR_SPEED_FULL_SPEED_Val       (0x0U)                                         /**< (USBHS_SR) Full-Speed mode  */
#define   USBHS_SR_SPEED_HIGH_SPEED_Val       (0x1U)                                         /**< (USBHS_SR) High-Speed mode  */
#define   USBHS_SR_SPEED_LOW_SPEED_Val        (0x2U)                                         /**< (USBHS_SR) Low-Speed mode  */
#define USBHS_SR_SPEED_FULL_SPEED             (USBHS_SR_SPEED_FULL_SPEED_Val << USBHS_SR_SPEED_Pos)  /**< (USBHS_SR) Full-Speed mode Position  */
#define USBHS_SR_SPEED_HIGH_SPEED             (USBHS_SR_SPEED_HIGH_SPEED_Val << USBHS_SR_SPEED_Pos)  /**< (USBHS_SR) High-Speed mode Position  */
#define USBHS_SR_SPEED_LOW_SPEED              (USBHS_SR_SPEED_LOW_SPEED_Val << USBHS_SR_SPEED_Pos)  /**< (USBHS_SR) Low-Speed mode Position  */
#define USBHS_SR_CLKUSABLE_Pos                (14)                                           /**< (USBHS_SR) UTMI Clock Usable Position */
#define USBHS_SR_CLKUSABLE_Msk                (0x1U << USBHS_SR_CLKUSABLE_Pos)               /**< (USBHS_SR) UTMI Clock Usable Mask */
#define USBHS_SR_Msk                          (0x00007010UL)                                 /**< (USBHS_SR) Register Mask  */

/* -------- USBHS_SCR : (USBHS Offset: 0x808) (/W 32) General Status Clear Register -------- */

typedef union
{
  struct
  {
    uint32_t :4;                        /**< bit:   0..3  Reserved                                      */
    uint32_t RDERRIC:1;                 /**< bit:      4  Remote Device Connection Error Interrupt Clear */
    uint32_t :27;                       /**< bit:  5..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_SCR_bits_t;

#define USBHS_SCR_RDERRIC_Pos                 (4)                                            /**< (USBHS_SCR) Remote Device Connection Error Interrupt Clear Position */
#define USBHS_SCR_RDERRIC_Msk                 (0x1U << USBHS_SCR_RDERRIC_Pos)                /**< (USBHS_SCR) Remote Device Connection Error Interrupt Clear Mask */
#define USBHS_SCR_Msk                         (0x00000010UL)                                 /**< (USBHS_SCR) Register Mask  */

/* -------- USBHS_SFR : (USBHS Offset: 0x80c) (/W 32) General Status Set Register -------- */

typedef union
{
  struct
  {
    uint32_t :4;                        /**< bit:   0..3  Reserved                                      */
    uint32_t RDERRIS:1;                 /**< bit:      4  Remote Device Connection Error Interrupt Set  */
    uint32_t :4;                        /**< bit:   5..8  Reserved                                      */
    uint32_t VBUSRQS:1;                 /**< bit:      9  VBUS Request Set                              */
    uint32_t :22;                       /**< bit: 10..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_SFR_bits_t;

#define USBHS_SFR_RDERRIS_Pos                 (4)                                            /**< (USBHS_SFR) Remote Device Connection Error Interrupt Set Position */
#define USBHS_SFR_RDERRIS_Msk                 (0x1U << USBHS_SFR_RDERRIS_Pos)                /**< (USBHS_SFR) Remote Device Connection Error Interrupt Set Mask */
#define USBHS_SFR_VBUSRQS_Pos                 (9)                                            /**< (USBHS_SFR) VBUS Request Set Position */
#define USBHS_SFR_VBUSRQS_Msk                 (0x1U << USBHS_SFR_VBUSRQS_Pos)                /**< (USBHS_SFR) VBUS Request Set Mask */
#define USBHS_SFR_Msk                         (0x00000210UL)                                 /**< (USBHS_SFR) Register Mask  */

/* -------- USBHS_TSTA1 : (USBHS Offset: 0x810) (R/W 32) General Test A1 Register -------- */

typedef union
{
  struct
  {
    uint32_t CounterA:15;               /**< bit:  0..14  Counter A                                     */
    uint32_t LoadCntA:1;                /**< bit:     15  Load CounterA                                 */
    uint32_t CounterB:6;                /**< bit: 16..21  Counter B                                     */
    uint32_t :1;                        /**< bit:     22  Reserved                                      */
    uint32_t LoadCntB:1;                /**< bit:     23  Load CounterB                                 */
    uint32_t SOFCntMa1:7;               /**< bit: 24..30  SOF Counter Max                               */
    uint32_t LoadSOFCnt:1;              /**< bit:     31  Load SOF Counter                              */
  };
  uint32_t w;
} __USBHS_TSTA1_bits_t;

#define USBHS_TSTA1_CounterA_Pos              (0)                                            /**< (USBHS_TSTA1) Counter A Position */
#define USBHS_TSTA1_CounterA_Msk              (0x7FFFU << USBHS_TSTA1_CounterA_Pos)          /**< (USBHS_TSTA1) Counter A Mask */
#define USBHS_TSTA1_CounterA(value)           (USBHS_TSTA1_CounterA_Msk & ((value) << USBHS_TSTA1_CounterA_Pos))
#define USBHS_TSTA1_LoadCntA_Pos              (15)                                           /**< (USBHS_TSTA1) Load CounterA Position */
#define USBHS_TSTA1_LoadCntA_Msk              (0x1U << USBHS_TSTA1_LoadCntA_Pos)             /**< (USBHS_TSTA1) Load CounterA Mask */
#define USBHS_TSTA1_CounterB_Pos              (16)                                           /**< (USBHS_TSTA1) Counter B Position */
#define USBHS_TSTA1_CounterB_Msk              (0x3FU << USBHS_TSTA1_CounterB_Pos)            /**< (USBHS_TSTA1) Counter B Mask */
#define USBHS_TSTA1_CounterB(value)           (USBHS_TSTA1_CounterB_Msk & ((value) << USBHS_TSTA1_CounterB_Pos))
#define USBHS_TSTA1_LoadCntB_Pos              (23)                                           /**< (USBHS_TSTA1) Load CounterB Position */
#define USBHS_TSTA1_LoadCntB_Msk              (0x1U << USBHS_TSTA1_LoadCntB_Pos)             /**< (USBHS_TSTA1) Load CounterB Mask */
#define USBHS_TSTA1_SOFCntMa1_Pos             (24)                                           /**< (USBHS_TSTA1) SOF Counter Max Position */
#define USBHS_TSTA1_SOFCntMa1_Msk             (0x7FU << USBHS_TSTA1_SOFCntMa1_Pos)           /**< (USBHS_TSTA1) SOF Counter Max Mask */
#define USBHS_TSTA1_SOFCntMa1(value)          (USBHS_TSTA1_SOFCntMa1_Msk & ((value) << USBHS_TSTA1_SOFCntMa1_Pos))
#define USBHS_TSTA1_LoadSOFCnt_Pos            (31)                                           /**< (USBHS_TSTA1) Load SOF Counter Position */
#define USBHS_TSTA1_LoadSOFCnt_Msk            (0x1U << USBHS_TSTA1_LoadSOFCnt_Pos)           /**< (USBHS_TSTA1) Load SOF Counter Mask */
#define USBHS_TSTA1_Msk                       (0xFFBFFFFFUL)                                 /**< (USBHS_TSTA1) Register Mask  */

/* -------- USBHS_TSTA2 : (USBHS Offset: 0x814) (R/W 32) General Test A2 Register -------- */

typedef union
{
  struct
  {
    uint32_t FullDetachEn:1;            /**< bit:      0  Full Detach Enable                            */
    uint32_t HSSerialMode:1;            /**< bit:      1  HS Serial Mode                                */
    uint32_t LoopBackMode:1;            /**< bit:      2  Loop-back Mode                                */
    uint32_t DisableGatedClock:1;       /**< bit:      3  Disable Gated Clock                           */
    uint32_t ForceSuspendMTo1:1;        /**< bit:      4  Force SuspendM to 1                           */
    uint32_t ByPassDpll:1;              /**< bit:      5  Bypass DPLL                                   */
    uint32_t HostHSDisconnectDisable:1;  /**< bit:      6  Host HS Disconnect Disable                    */
    uint32_t ForceHSRst_50ms:1;         /**< bit:      7  Force HS Reset to 50 ms                       */
    uint32_t :1;                        /**< bit:      8  Reserved                                      */
    uint32_t RemovePUWhenTX:1;          /**< bit:      9  Remove Pull-up When TX                        */
    uint32_t :22;                       /**< bit: 10..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_TSTA2_bits_t;

#define USBHS_TSTA2_FullDetachEn_Pos          (0)                                            /**< (USBHS_TSTA2) Full Detach Enable Position */
#define USBHS_TSTA2_FullDetachEn_Msk          (0x1U << USBHS_TSTA2_FullDetachEn_Pos)         /**< (USBHS_TSTA2) Full Detach Enable Mask */
#define USBHS_TSTA2_HSSerialMode_Pos          (1)                                            /**< (USBHS_TSTA2) HS Serial Mode Position */
#define USBHS_TSTA2_HSSerialMode_Msk          (0x1U << USBHS_TSTA2_HSSerialMode_Pos)         /**< (USBHS_TSTA2) HS Serial Mode Mask */
#define USBHS_TSTA2_LoopBackMode_Pos          (2)                                            /**< (USBHS_TSTA2) Loop-back Mode Position */
#define USBHS_TSTA2_LoopBackMode_Msk          (0x1U << USBHS_TSTA2_LoopBackMode_Pos)         /**< (USBHS_TSTA2) Loop-back Mode Mask */
#define USBHS_TSTA2_DisableGatedClock_Pos     (3)                                            /**< (USBHS_TSTA2) Disable Gated Clock Position */
#define USBHS_TSTA2_DisableGatedClock_Msk     (0x1U << USBHS_TSTA2_DisableGatedClock_Pos)    /**< (USBHS_TSTA2) Disable Gated Clock Mask */
#define USBHS_TSTA2_ForceSuspendMTo1_Pos      (4)                                            /**< (USBHS_TSTA2) Force SuspendM to 1 Position */
#define USBHS_TSTA2_ForceSuspendMTo1_Msk      (0x1U << USBHS_TSTA2_ForceSuspendMTo1_Pos)     /**< (USBHS_TSTA2) Force SuspendM to 1 Mask */
#define USBHS_TSTA2_ByPassDpll_Pos            (5)                                            /**< (USBHS_TSTA2) Bypass DPLL Position */
#define USBHS_TSTA2_ByPassDpll_Msk            (0x1U << USBHS_TSTA2_ByPassDpll_Pos)           /**< (USBHS_TSTA2) Bypass DPLL Mask */
#define USBHS_TSTA2_HostHSDisconnectDisable_Pos (6)                                            /**< (USBHS_TSTA2) Host HS Disconnect Disable Position */
#define USBHS_TSTA2_HostHSDisconnectDisable_Msk (0x1U << USBHS_TSTA2_HostHSDisconnectDisable_Pos)  /**< (USBHS_TSTA2) Host HS Disconnect Disable Mask */
#define USBHS_TSTA2_ForceHSRst_50ms_Pos       (7)                                            /**< (USBHS_TSTA2) Force HS Reset to 50 ms Position */
#define USBHS_TSTA2_ForceHSRst_50ms_Msk       (0x1U << USBHS_TSTA2_ForceHSRst_50ms_Pos)      /**< (USBHS_TSTA2) Force HS Reset to 50 ms Mask */
#define USBHS_TSTA2_RemovePUWhenTX_Pos        (9)                                            /**< (USBHS_TSTA2) Remove Pull-up When TX Position */
#define USBHS_TSTA2_RemovePUWhenTX_Msk        (0x1U << USBHS_TSTA2_RemovePUWhenTX_Pos)       /**< (USBHS_TSTA2) Remove Pull-up When TX Mask */
#define USBHS_TSTA2_Msk                       (0x000002FFUL)                                 /**< (USBHS_TSTA2) Register Mask  */

/* -------- USBHS_FSM : (USBHS Offset: 0x82c) (R/ 32) General Finite State Machine Register -------- */

typedef union
{
  struct
  {
    uint32_t DRDSTATE:4;                /**< bit:   0..3  Dual Role Device State                        */
    uint32_t :28;                       /**< bit:  4..31  Reserved                                      */
  };
  uint32_t w;
} __USBHS_FSM_bits_t;

#define USBHS_FSM_DRDSTATE_Pos                (0)                                            /**< (USBHS_FSM) Dual Role Device State Position */
#define USBHS_FSM_DRDSTATE_Msk                (0xFU << USBHS_FSM_DRDSTATE_Pos)               /**< (USBHS_FSM) Dual Role Device State Mask */
#define USBHS_FSM_DRDSTATE(value)             (USBHS_FSM_DRDSTATE_Msk & ((value) << USBHS_FSM_DRDSTATE_Pos))
#define   USBHS_FSM_DRDSTATE_A_IDLESTATE_Val  (0x0U)                                         /**< (USBHS_FSM) This is the start state for A-devices (when the ID pin is 0)  */
#define   USBHS_FSM_DRDSTATE_A_WAIT_VRISE_Val (0x1U)                                         /**< (USBHS_FSM) In this state, the A-device waits for the voltage on VBus to rise above the A-device VBus Valid threshold (4.4 V).  */
#define   USBHS_FSM_DRDSTATE_A_WAIT_BCON_Val  (0x2U)                                         /**< (USBHS_FSM) In this state, the A-device waits for the B-device to signal a connection.  */
#define   USBHS_FSM_DRDSTATE_A_HOST_Val       (0x3U)                                         /**< (USBHS_FSM) In this state, the A-device that operates in Host mode is operational.  */
#define   USBHS_FSM_DRDSTATE_A_SUSPEND_Val    (0x4U)                                         /**< (USBHS_FSM) The A-device operating as a host is in the Suspend mode.  */
#define   USBHS_FSM_DRDSTATE_A_PERIPHERAL_Val (0x5U)                                         /**< (USBHS_FSM) The A-device operates as a peripheral.  */
#define   USBHS_FSM_DRDSTATE_A_WAIT_VFALL_Val (0x6U)                                         /**< (USBHS_FSM) In this state, the A-device waits for the voltage on VBus to drop below the A-device Session Valid threshold (1.4 V).  */
#define   USBHS_FSM_DRDSTATE_A_VBUS_ERR_Val   (0x7U)                                         /**< (USBHS_FSM) In this state, the A-device waits for recovery of the over-current condition that caused it to enter this state.  */
#define   USBHS_FSM_DRDSTATE_A_WAIT_DISCHARGE_Val (0x8U)                                         /**< (USBHS_FSM) In this state, the A-device waits for the data USB line to discharge (100 us).  */
#define   USBHS_FSM_DRDSTATE_B_IDLE_Val       (0x9U)                                         /**< (USBHS_FSM) This is the start state for B-device (when the ID pin is 1).  */
#define   USBHS_FSM_DRDSTATE_B_PERIPHERAL_Val (0xAU)                                         /**< (USBHS_FSM) In this state, the B-device acts as the peripheral.  */
#define   USBHS_FSM_DRDSTATE_B_WAIT_BEGIN_HNP_Val (0xBU)                                         /**< (USBHS_FSM) In this state, the B-device is in Suspend mode and waits until 3 ms before initiating the HNP protocol if requested.  */
#define   USBHS_FSM_DRDSTATE_B_WAIT_DISCHARGE_Val (0xCU)                                         /**< (USBHS_FSM) In this state, the B-device waits for the data USB line to discharge (100 us)) before becoming Host.  */
#define   USBHS_FSM_DRDSTATE_B_WAIT_ACON_Val  (0xDU)                                         /**< (USBHS_FSM) In this state, the B-device waits for the A-device to signal a connect before becoming B-Host.  */
#define   USBHS_FSM_DRDSTATE_B_HOST_Val       (0xEU)                                         /**< (USBHS_FSM) In this state, the B-device acts as the Host.  */
#define   USBHS_FSM_DRDSTATE_B_SRP_INIT_Val   (0xFU)                                         /**< (USBHS_FSM) In this state, the B-device attempts to start a session using the SRP protocol.  */
#define USBHS_FSM_DRDSTATE_A_IDLESTATE        (USBHS_FSM_DRDSTATE_A_IDLESTATE_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) This is the start state for A-devices (when the ID pin is 0) Position  */
#define USBHS_FSM_DRDSTATE_A_WAIT_VRISE       (USBHS_FSM_DRDSTATE_A_WAIT_VRISE_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the A-device waits for the voltage on VBus to rise above the A-device VBus Valid threshold (4.4 V). Position  */
#define USBHS_FSM_DRDSTATE_A_WAIT_BCON        (USBHS_FSM_DRDSTATE_A_WAIT_BCON_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the A-device waits for the B-device to signal a connection. Position  */
#define USBHS_FSM_DRDSTATE_A_HOST             (USBHS_FSM_DRDSTATE_A_HOST_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the A-device that operates in Host mode is operational. Position  */
#define USBHS_FSM_DRDSTATE_A_SUSPEND          (USBHS_FSM_DRDSTATE_A_SUSPEND_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) The A-device operating as a host is in the Suspend mode. Position  */
#define USBHS_FSM_DRDSTATE_A_PERIPHERAL       (USBHS_FSM_DRDSTATE_A_PERIPHERAL_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) The A-device operates as a peripheral. Position  */
#define USBHS_FSM_DRDSTATE_A_WAIT_VFALL       (USBHS_FSM_DRDSTATE_A_WAIT_VFALL_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the A-device waits for the voltage on VBus to drop below the A-device Session Valid threshold (1.4 V). Position  */
#define USBHS_FSM_DRDSTATE_A_VBUS_ERR         (USBHS_FSM_DRDSTATE_A_VBUS_ERR_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the A-device waits for recovery of the over-current condition that caused it to enter this state. Position  */
#define USBHS_FSM_DRDSTATE_A_WAIT_DISCHARGE   (USBHS_FSM_DRDSTATE_A_WAIT_DISCHARGE_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the A-device waits for the data USB line to discharge (100 us). Position  */
#define USBHS_FSM_DRDSTATE_B_IDLE             (USBHS_FSM_DRDSTATE_B_IDLE_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) This is the start state for B-device (when the ID pin is 1). Position  */
#define USBHS_FSM_DRDSTATE_B_PERIPHERAL       (USBHS_FSM_DRDSTATE_B_PERIPHERAL_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the B-device acts as the peripheral. Position  */
#define USBHS_FSM_DRDSTATE_B_WAIT_BEGIN_HNP   (USBHS_FSM_DRDSTATE_B_WAIT_BEGIN_HNP_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the B-device is in Suspend mode and waits until 3 ms before initiating the HNP protocol if requested. Position  */
#define USBHS_FSM_DRDSTATE_B_WAIT_DISCHARGE   (USBHS_FSM_DRDSTATE_B_WAIT_DISCHARGE_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the B-device waits for the data USB line to discharge (100 us)) before becoming Host. Position  */
#define USBHS_FSM_DRDSTATE_B_WAIT_ACON        (USBHS_FSM_DRDSTATE_B_WAIT_ACON_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the B-device waits for the A-device to signal a connect before becoming B-Host. Position  */
#define USBHS_FSM_DRDSTATE_B_HOST             (USBHS_FSM_DRDSTATE_B_HOST_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the B-device acts as the Host. Position  */
#define USBHS_FSM_DRDSTATE_B_SRP_INIT         (USBHS_FSM_DRDSTATE_B_SRP_INIT_Val << USBHS_FSM_DRDSTATE_Pos)  /**< (USBHS_FSM) In this state, the B-device attempts to start a session using the SRP protocol. Position  */
#define USBHS_FSM_Msk                         (0x0000000FUL)                                 /**< (USBHS_FSM) Register Mask  */

/** \brief USBHS_DEVDMA register offsets definitions */
#define USBHS_DEVDMANXTDSC_OFFSET    (0x00)         /**< (USBHS_DEVDMANXTDSC) Device DMA Channel Next Descriptor Address Register (n = 1) Offset */
#define USBHS_DEVDMAADDRESS_OFFSET   (0x04)         /**< (USBHS_DEVDMAADDRESS) Device DMA Channel Address Register (n = 1) Offset */
#define USBHS_DEVDMACONTROL_OFFSET   (0x08)         /**< (USBHS_DEVDMACONTROL) Device DMA Channel Control Register (n = 1) Offset */
#define USBHS_DEVDMASTATUS_OFFSET    (0x0C)         /**< (USBHS_DEVDMASTATUS) Device DMA Channel Status Register (n = 1) Offset */
/** \brief USBHS_HSTDMA register offsets definitions */
#define USBHS_HSTDMANXTDSC_OFFSET    (0x00)         /**< (USBHS_HSTDMANXTDSC) Host DMA Channel Next Descriptor Address Register (n = 1) Offset */
#define USBHS_HSTDMAADDRESS_OFFSET   (0x04)         /**< (USBHS_HSTDMAADDRESS) Host DMA Channel Address Register (n = 1) Offset */
#define USBHS_HSTDMACONTROL_OFFSET   (0x08)         /**< (USBHS_HSTDMACONTROL) Host DMA Channel Control Register (n = 1) Offset */
#define USBHS_HSTDMASTATUS_OFFSET    (0x0C)         /**< (USBHS_HSTDMASTATUS) Host DMA Channel Status Register (n = 1) Offset */
/** \brief USBHS register offsets definitions */
#define USBHS_DEVCTRL_OFFSET         (0x00)         /**< (USBHS_DEVCTRL) Device General Control Register Offset */
#define USBHS_DEVISR_OFFSET          (0x04)         /**< (USBHS_DEVISR) Device Global Interrupt Status Register Offset */
#define USBHS_DEVICR_OFFSET          (0x08)         /**< (USBHS_DEVICR) Device Global Interrupt Clear Register Offset */
#define USBHS_DEVIFR_OFFSET          (0x0C)         /**< (USBHS_DEVIFR) Device Global Interrupt Set Register Offset */
#define USBHS_DEVIMR_OFFSET          (0x10)         /**< (USBHS_DEVIMR) Device Global Interrupt Mask Register Offset */
#define USBHS_DEVIDR_OFFSET          (0x14)         /**< (USBHS_DEVIDR) Device Global Interrupt Disable Register Offset */
#define USBHS_DEVIER_OFFSET          (0x18)         /**< (USBHS_DEVIER) Device Global Interrupt Enable Register Offset */
#define USBHS_DEVEPT_OFFSET          (0x1C)         /**< (USBHS_DEVEPT) Device Endpoint Register Offset */
#define USBHS_DEVFNUM_OFFSET         (0x20)         /**< (USBHS_DEVFNUM) Device Frame Number Register Offset */
#define USBHS_DEVEPTCFG_OFFSET       (0x100)        /**< (USBHS_DEVEPTCFG) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTISR_OFFSET       (0x130)        /**< (USBHS_DEVEPTISR) Device Endpoint Status Register Offset */
#define USBHS_DEVEPTICR_OFFSET       (0x160)        /**< (USBHS_DEVEPTICR) Device Endpoint Clear Register Offset */
#define USBHS_DEVEPTIFR_OFFSET       (0x190)        /**< (USBHS_DEVEPTIFR) Device Endpoint Set Register Offset */
#define USBHS_DEVEPTIMR_OFFSET       (0x1C0)        /**< (USBHS_DEVEPTIMR) Device Endpoint Mask Register Offset */
#define USBHS_DEVEPTIER_OFFSET       (0x1F0)        /**< (USBHS_DEVEPTIER) Device Endpoint Enable Register Offset */
#define USBHS_DEVEPTIDR_OFFSET       (0x220)        /**< (USBHS_DEVEPTIDR) Device Endpoint Disable Register Offset */
#define USBHS_HSTCTRL_OFFSET         (0x400)        /**< (USBHS_HSTCTRL) Host General Control Register Offset */
#define USBHS_HSTISR_OFFSET          (0x404)        /**< (USBHS_HSTISR) Host Global Interrupt Status Register Offset */
#define USBHS_HSTICR_OFFSET          (0x408)        /**< (USBHS_HSTICR) Host Global Interrupt Clear Register Offset */
#define USBHS_HSTIFR_OFFSET          (0x40C)        /**< (USBHS_HSTIFR) Host Global Interrupt Set Register Offset */
#define USBHS_HSTIMR_OFFSET          (0x410)        /**< (USBHS_HSTIMR) Host Global Interrupt Mask Register Offset */
#define USBHS_HSTIDR_OFFSET          (0x414)        /**< (USBHS_HSTIDR) Host Global Interrupt Disable Register Offset */
#define USBHS_HSTIER_OFFSET          (0x418)        /**< (USBHS_HSTIER) Host Global Interrupt Enable Register Offset */
#define USBHS_HSTPIP_OFFSET          (0x41C)        /**< (USBHS_HSTPIP) Host Pipe Register Offset */
#define USBHS_HSTFNUM_OFFSET         (0x420)        /**< (USBHS_HSTFNUM) Host Frame Number Register Offset */
#define USBHS_HSTADDR1_OFFSET        (0x424)        /**< (USBHS_HSTADDR1) Host Address 1 Register Offset */
#define USBHS_HSTADDR2_OFFSET        (0x428)        /**< (USBHS_HSTADDR2) Host Address 2 Register Offset */
#define USBHS_HSTADDR3_OFFSET        (0x42C)        /**< (USBHS_HSTADDR3) Host Address 3 Register Offset */
#define USBHS_HSTPIPCFG_OFFSET       (0x500)        /**< (USBHS_HSTPIPCFG) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPISR_OFFSET       (0x530)        /**< (USBHS_HSTPIPISR) Host Pipe Status Register Offset */
#define USBHS_HSTPIPICR_OFFSET       (0x560)        /**< (USBHS_HSTPIPICR) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPIFR_OFFSET       (0x590)        /**< (USBHS_HSTPIPIFR) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIMR_OFFSET       (0x5C0)        /**< (USBHS_HSTPIPIMR) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIER_OFFSET       (0x5F0)        /**< (USBHS_HSTPIPIER) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIDR_OFFSET       (0x620)        /**< (USBHS_HSTPIPIDR) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPINRQ_OFFSET      (0x650)        /**< (USBHS_HSTPIPINRQ) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPERR_OFFSET       (0x680)        /**< (USBHS_HSTPIPERR) Host Pipe Error Register Offset */
#define USBHS_CTRL_OFFSET            (0x800)        /**< (USBHS_CTRL) General Control Register Offset */
#define USBHS_SR_OFFSET              (0x804)        /**< (USBHS_SR) General Status Register Offset */
#define USBHS_SCR_OFFSET             (0x808)        /**< (USBHS_SCR) General Status Clear Register Offset */
#define USBHS_SFR_OFFSET             (0x80C)        /**< (USBHS_SFR) General Status Set Register Offset */
#define USBHS_TSTA1_OFFSET           (0x810)        /**< (USBHS_TSTA1) General Test A1 Register Offset */
#define USBHS_TSTA2_OFFSET           (0x814)        /**< (USBHS_TSTA2) General Test A2 Register Offset */
#define USBHS_FSM_OFFSET             (0x82C)        /**< (USBHS_FSM) General Finite State Machine Register Offset */

/** \brief USBHS_DEVDMA register API structure */
typedef struct
{
  __IO  __USBHS_DEVDMANXTDSC_bits_t    USBHS_DEVDMANXTDSC; /**< Offset: 0x00 (R/W  32) Device DMA Channel Next Descriptor Address Register (n = 1) */
  __IO  __USBHS_DEVDMAADDRESS_bits_t   USBHS_DEVDMAADDRESS; /**< Offset: 0x04 (R/W  32) Device DMA Channel Address Register (n = 1) */
  __IO  __USBHS_DEVDMACONTROL_bits_t   USBHS_DEVDMACONTROL; /**< Offset: 0x08 (R/W  32) Device DMA Channel Control Register (n = 1) */
  __IO  __USBHS_DEVDMASTATUS_bits_t    USBHS_DEVDMASTATUS; /**< Offset: 0x0C (R/W  32) Device DMA Channel Status Register (n = 1) */
} usbhsdevdma_registers_t;

/** \brief USBHS_HSTDMA register API structure */
typedef struct
{
  __IO  __USBHS_HSTDMANXTDSC_bits_t    USBHS_HSTDMANXTDSC; /**< Offset: 0x00 (R/W  32) Host DMA Channel Next Descriptor Address Register (n = 1) */
  __IO  __USBHS_HSTDMAADDRESS_bits_t   USBHS_HSTDMAADDRESS; /**< Offset: 0x04 (R/W  32) Host DMA Channel Address Register (n = 1) */
  __IO  __USBHS_HSTDMACONTROL_bits_t   USBHS_HSTDMACONTROL; /**< Offset: 0x08 (R/W  32) Host DMA Channel Control Register (n = 1) */
  __IO  __USBHS_HSTDMASTATUS_bits_t    USBHS_HSTDMASTATUS; /**< Offset: 0x0C (R/W  32) Host DMA Channel Status Register (n = 1) */
} usbhshstdma_registers_t;

#define USBHSDEVDMA_NUMBER 7
#define USBHSHSTDMA_NUMBER 7
/** \brief USBHS register API structure */
typedef struct
{
  __IO  __USBHS_DEVCTRL_bits_t         USBHS_DEVCTRL; /**< Offset: 0x00 (R/W  32) Device General Control Register */
  __I   __USBHS_DEVISR_bits_t          USBHS_DEVISR;  /**< Offset: 0x04 (R/   32) Device Global Interrupt Status Register */
  __O   __USBHS_DEVICR_bits_t          USBHS_DEVICR;  /**< Offset: 0x08 ( /W  32) Device Global Interrupt Clear Register */
  __O   __USBHS_DEVIFR_bits_t          USBHS_DEVIFR;  /**< Offset: 0x0C ( /W  32) Device Global Interrupt Set Register */
  __I   __USBHS_DEVIMR_bits_t          USBHS_DEVIMR;  /**< Offset: 0x10 (R/   32) Device Global Interrupt Mask Register */
  __O   __USBHS_DEVIDR_bits_t          USBHS_DEVIDR;  /**< Offset: 0x14 ( /W  32) Device Global Interrupt Disable Register */
  __O   __USBHS_DEVIER_bits_t          USBHS_DEVIER;  /**< Offset: 0x18 ( /W  32) Device Global Interrupt Enable Register */
  __IO  __USBHS_DEVEPT_bits_t          USBHS_DEVEPT;  /**< Offset: 0x1C (R/W  32) Device Endpoint Register */
  __I   __USBHS_DEVFNUM_bits_t         USBHS_DEVFNUM; /**< Offset: 0x20 (R/   32) Device Frame Number Register */
  __I   uint8_t                        Reserved1[0xDC];
  __IO  __USBHS_DEVEPTCFG_bits_t       USBHS_DEVEPTCFG[10]; /**< Offset: 0x100 (R/W  32) Device Endpoint Configuration Register */
  __I   uint8_t                        Reserved2[0x08];
  __I   __USBHS_DEVEPTISR_bits_t       USBHS_DEVEPTISR[10]; /**< Offset: 0x130 (R/   32) Device Endpoint Status Register */
  __I   uint8_t                        Reserved3[0x08];
  __O   __USBHS_DEVEPTICR_bits_t       USBHS_DEVEPTICR[10]; /**< Offset: 0x160 ( /W  32) Device Endpoint Clear Register */
  __I   uint8_t                        Reserved4[0x08];
  __O   __USBHS_DEVEPTIFR_bits_t       USBHS_DEVEPTIFR[10]; /**< Offset: 0x190 ( /W  32) Device Endpoint Set Register */
  __I   uint8_t                        Reserved5[0x08];
  __I   __USBHS_DEVEPTIMR_bits_t       USBHS_DEVEPTIMR[10]; /**< Offset: 0x1C0 (R/   32) Device Endpoint Mask Register */
  __I   uint8_t                        Reserved6[0x08];
  __O   __USBHS_DEVEPTIER_bits_t       USBHS_DEVEPTIER[10]; /**< Offset: 0x1F0 ( /W  32) Device Endpoint Enable Register */
  __I   uint8_t                        Reserved7[0x08];
  __O   __USBHS_DEVEPTIDR_bits_t       USBHS_DEVEPTIDR[10]; /**< Offset: 0x220 ( /W  32) Device Endpoint Disable Register */
  __I   uint8_t                        Reserved8[0xC8];
        usbhsdevdma_registers_t        USBHS_DEVDMA[USBHSDEVDMA_NUMBER]; /**< Offset: 0x310 Device DMA Channel Next Descriptor Address Register (n = 1) */
  __I   uint8_t                        Reserved9[0x80];
  __IO  __USBHS_HSTCTRL_bits_t         USBHS_HSTCTRL; /**< Offset: 0x400 (R/W  32) Host General Control Register */
  __I   __USBHS_HSTISR_bits_t          USBHS_HSTISR;  /**< Offset: 0x404 (R/   32) Host Global Interrupt Status Register */
  __O   __USBHS_HSTICR_bits_t          USBHS_HSTICR;  /**< Offset: 0x408 ( /W  32) Host Global Interrupt Clear Register */
  __O   __USBHS_HSTIFR_bits_t          USBHS_HSTIFR;  /**< Offset: 0x40C ( /W  32) Host Global Interrupt Set Register */
  __I   __USBHS_HSTIMR_bits_t          USBHS_HSTIMR;  /**< Offset: 0x410 (R/   32) Host Global Interrupt Mask Register */
  __O   __USBHS_HSTIDR_bits_t          USBHS_HSTIDR;  /**< Offset: 0x414 ( /W  32) Host Global Interrupt Disable Register */
  __O   __USBHS_HSTIER_bits_t          USBHS_HSTIER;  /**< Offset: 0x418 ( /W  32) Host Global Interrupt Enable Register */
  __IO  __USBHS_HSTPIP_bits_t          USBHS_HSTPIP;  /**< Offset: 0x41C (R/W  32) Host Pipe Register */
  __IO  __USBHS_HSTFNUM_bits_t         USBHS_HSTFNUM; /**< Offset: 0x420 (R/W  32) Host Frame Number Register */
  __IO  __USBHS_HSTADDR1_bits_t        USBHS_HSTADDR1; /**< Offset: 0x424 (R/W  32) Host Address 1 Register */
  __IO  __USBHS_HSTADDR2_bits_t        USBHS_HSTADDR2; /**< Offset: 0x428 (R/W  32) Host Address 2 Register */
  __IO  __USBHS_HSTADDR3_bits_t        USBHS_HSTADDR3; /**< Offset: 0x42C (R/W  32) Host Address 3 Register */
  __I   uint8_t                        Reserved10[0xD0];
  __IO  __USBHS_HSTPIPCFG_bits_t       USBHS_HSTPIPCFG[10]; /**< Offset: 0x500 (R/W  32) Host Pipe Configuration Register */
  __I   uint8_t                        Reserved11[0x08];
  __I   __USBHS_HSTPIPISR_bits_t       USBHS_HSTPIPISR[10]; /**< Offset: 0x530 (R/   32) Host Pipe Status Register */
  __I   uint8_t                        Reserved12[0x08];
  __O   __USBHS_HSTPIPICR_bits_t       USBHS_HSTPIPICR[10]; /**< Offset: 0x560 ( /W  32) Host Pipe Clear Register */
  __I   uint8_t                        Reserved13[0x08];
  __O   __USBHS_HSTPIPIFR_bits_t       USBHS_HSTPIPIFR[10]; /**< Offset: 0x590 ( /W  32) Host Pipe Set Register */
  __I   uint8_t                        Reserved14[0x08];
  __I   __USBHS_HSTPIPIMR_bits_t       USBHS_HSTPIPIMR[10]; /**< Offset: 0x5C0 (R/   32) Host Pipe Mask Register */
  __I   uint8_t                        Reserved15[0x08];
  __O   __USBHS_HSTPIPIER_bits_t       USBHS_HSTPIPIER[10]; /**< Offset: 0x5F0 ( /W  32) Host Pipe Enable Register */
  __I   uint8_t                        Reserved16[0x08];
  __O   __USBHS_HSTPIPIDR_bits_t       USBHS_HSTPIPIDR[10]; /**< Offset: 0x620 ( /W  32) Host Pipe Disable Register */
  __I   uint8_t                        Reserved17[0x08];
  __IO  __USBHS_HSTPIPINRQ_bits_t      USBHS_HSTPIPINRQ[10]; /**< Offset: 0x650 (R/W  32) Host Pipe IN Request Register */
  __I   uint8_t                        Reserved18[0x08];
  __IO  __USBHS_HSTPIPERR_bits_t       USBHS_HSTPIPERR[10]; /**< Offset: 0x680 (R/W  32) Host Pipe Error Register */
  __I   uint8_t                        Reserved19[0x68];
        usbhshstdma_registers_t        USBHS_HSTDMA[USBHSHSTDMA_NUMBER]; /**< Offset: 0x710 Host DMA Channel Next Descriptor Address Register (n = 1) */
  __I   uint8_t                        Reserved20[0x80];
  __IO  __USBHS_CTRL_bits_t            USBHS_CTRL;    /**< Offset: 0x800 (R/W  32) General Control Register */
  __I   __USBHS_SR_bits_t              USBHS_SR;      /**< Offset: 0x804 (R/   32) General Status Register */
  __O   __USBHS_SCR_bits_t             USBHS_SCR;     /**< Offset: 0x808 ( /W  32) General Status Clear Register */
  __O   __USBHS_SFR_bits_t             USBHS_SFR;     /**< Offset: 0x80C ( /W  32) General Status Set Register */
  __IO  __USBHS_TSTA1_bits_t           USBHS_TSTA1;   /**< Offset: 0x810 (R/W  32) General Test A1 Register */
  __IO  __USBHS_TSTA2_bits_t           USBHS_TSTA2;   /**< Offset: 0x814 (R/W  32) General Test A2 Register */
  __I   uint8_t                        Reserved21[0x14];
  __I   __USBHS_FSM_bits_t             USBHS_FSM;     /**< Offset: 0x82C (R/   32) General Finite State Machine Register */
} usbhs_registers_t;
/** @}  end of USB High-Speed Interface */

#endif /* _PIC32CZ_CA70_USBHS_COMPONENT_H_ */
