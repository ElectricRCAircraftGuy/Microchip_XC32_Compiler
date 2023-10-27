/**
 * \brief Component description for PIC32CZ/CA70 SUPC
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
#ifndef _PIC32CZ_CA70_SUPC_COMPONENT_H_
#define _PIC32CZ_CA70_SUPC_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_SUPC Supply Controller
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR SUPC */
/* ========================================================================== */

/* -------- SUPC_CR : (SUPC Offset: 0x00) (/W 32) Supply Controller Control Register -------- */

typedef union
{
  struct
  {
    uint32_t :2;                        /**< bit:   0..1  Reserved                                      */
    uint32_t VROFF:1;                   /**< bit:      2  Voltage Regulator Off                         */
    uint32_t XTALSEL:1;                 /**< bit:      3  Crystal Oscillator Select                     */
    uint32_t :20;                       /**< bit:  4..23  Reserved                                      */
    uint32_t KEY:8;                     /**< bit: 24..31  Password                                      */
  };
  uint32_t w;
} __SUPC_CR_bits_t;

#define SUPC_CR_VROFF_Pos                     (2)                                            /**< (SUPC_CR) Voltage Regulator Off Position */
#define SUPC_CR_VROFF_Msk                     (0x1U << SUPC_CR_VROFF_Pos)                    /**< (SUPC_CR) Voltage Regulator Off Mask */
#define   SUPC_CR_VROFF_NO_EFFECT_Val         (0x0U)                                         /**< (SUPC_CR) No effect.  */
#define   SUPC_CR_VROFF_STOP_VREG_Val         (0x1U)                                         /**< (SUPC_CR) If KEY is correct, VROFF asserts the vddcore_nreset and stops the voltage regulator.  */
#define SUPC_CR_VROFF_NO_EFFECT               (SUPC_CR_VROFF_NO_EFFECT_Val << SUPC_CR_VROFF_Pos)  /**< (SUPC_CR) No effect. Position  */
#define SUPC_CR_VROFF_STOP_VREG               (SUPC_CR_VROFF_STOP_VREG_Val << SUPC_CR_VROFF_Pos)  /**< (SUPC_CR) If KEY is correct, VROFF asserts the vddcore_nreset and stops the voltage regulator. Position  */
#define SUPC_CR_XTALSEL_Pos                   (3)                                            /**< (SUPC_CR) Crystal Oscillator Select Position */
#define SUPC_CR_XTALSEL_Msk                   (0x1U << SUPC_CR_XTALSEL_Pos)                  /**< (SUPC_CR) Crystal Oscillator Select Mask */
#define   SUPC_CR_XTALSEL_NO_EFFECT_Val       (0x0U)                                         /**< (SUPC_CR) No effect.  */
#define   SUPC_CR_XTALSEL_CRYSTAL_SEL_Val     (0x1U)                                         /**< (SUPC_CR) If KEY is correct, XTALSEL switches the slow clock on the crystal oscillator output.  */
#define SUPC_CR_XTALSEL_NO_EFFECT             (SUPC_CR_XTALSEL_NO_EFFECT_Val << SUPC_CR_XTALSEL_Pos)  /**< (SUPC_CR) No effect. Position  */
#define SUPC_CR_XTALSEL_CRYSTAL_SEL           (SUPC_CR_XTALSEL_CRYSTAL_SEL_Val << SUPC_CR_XTALSEL_Pos)  /**< (SUPC_CR) If KEY is correct, XTALSEL switches the slow clock on the crystal oscillator output. Position  */
#define SUPC_CR_KEY_Pos                       (24)                                           /**< (SUPC_CR) Password Position */
#define SUPC_CR_KEY_Msk                       (0xFFU << SUPC_CR_KEY_Pos)                     /**< (SUPC_CR) Password Mask */
#define SUPC_CR_KEY(value)                    (SUPC_CR_KEY_Msk & ((value) << SUPC_CR_KEY_Pos))
#define   SUPC_CR_KEY_PASSWD_Val              (0xA5U)                                        /**< (SUPC_CR) Writing any other value in this field aborts the write operation.  */
#define SUPC_CR_KEY_PASSWD                    (SUPC_CR_KEY_PASSWD_Val << SUPC_CR_KEY_Pos)    /**< (SUPC_CR) Writing any other value in this field aborts the write operation. Position  */
#define SUPC_CR_Msk                           (0xFF00000CUL)                                 /**< (SUPC_CR) Register Mask  */

/* -------- SUPC_SMMR : (SUPC Offset: 0x04) (R/W 32) Supply Controller Supply Monitor Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t SMTH:4;                    /**< bit:   0..3  Supply Monitor Threshold                      */
    uint32_t :4;                        /**< bit:   4..7  Reserved                                      */
    uint32_t SMSMPL:3;                  /**< bit:  8..10  Supply Monitor Sampling Period                */
    uint32_t :1;                        /**< bit:     11  Reserved                                      */
    uint32_t SMRSTEN:1;                 /**< bit:     12  Supply Monitor Reset Enable                   */
    uint32_t SMIEN:1;                   /**< bit:     13  Supply Monitor Interrupt Enable               */
    uint32_t :18;                       /**< bit: 14..31  Reserved                                      */
  };
  uint32_t w;
} __SUPC_SMMR_bits_t;

#define SUPC_SMMR_SMTH_Pos                    (0)                                            /**< (SUPC_SMMR) Supply Monitor Threshold Position */
#define SUPC_SMMR_SMTH_Msk                    (0xFU << SUPC_SMMR_SMTH_Pos)                   /**< (SUPC_SMMR) Supply Monitor Threshold Mask */
#define SUPC_SMMR_SMTH(value)                 (SUPC_SMMR_SMTH_Msk & ((value) << SUPC_SMMR_SMTH_Pos))
#define SUPC_SMMR_SMSMPL_Pos                  (8)                                            /**< (SUPC_SMMR) Supply Monitor Sampling Period Position */
#define SUPC_SMMR_SMSMPL_Msk                  (0x7U << SUPC_SMMR_SMSMPL_Pos)                 /**< (SUPC_SMMR) Supply Monitor Sampling Period Mask */
#define SUPC_SMMR_SMSMPL(value)               (SUPC_SMMR_SMSMPL_Msk & ((value) << SUPC_SMMR_SMSMPL_Pos))
#define   SUPC_SMMR_SMSMPL_SMD_Val            (0x0U)                                         /**< (SUPC_SMMR) Supply Monitor disabled  */
#define   SUPC_SMMR_SMSMPL_CSM_Val            (0x1U)                                         /**< (SUPC_SMMR) Continuous Supply Monitor  */
#define   SUPC_SMMR_SMSMPL_32SLCK_Val         (0x2U)                                         /**< (SUPC_SMMR) Supply Monitor enabled one SLCK period every 32 SLCK periods  */
#define   SUPC_SMMR_SMSMPL_256SLCK_Val        (0x3U)                                         /**< (SUPC_SMMR) Supply Monitor enabled one SLCK period every 256 SLCK periods  */
#define   SUPC_SMMR_SMSMPL_2048SLCK_Val       (0x4U)                                         /**< (SUPC_SMMR) Supply Monitor enabled one SLCK period every 2,048 SLCK periods  */
#define SUPC_SMMR_SMSMPL_SMD                  (SUPC_SMMR_SMSMPL_SMD_Val << SUPC_SMMR_SMSMPL_Pos)  /**< (SUPC_SMMR) Supply Monitor disabled Position  */
#define SUPC_SMMR_SMSMPL_CSM                  (SUPC_SMMR_SMSMPL_CSM_Val << SUPC_SMMR_SMSMPL_Pos)  /**< (SUPC_SMMR) Continuous Supply Monitor Position  */
#define SUPC_SMMR_SMSMPL_32SLCK               (SUPC_SMMR_SMSMPL_32SLCK_Val << SUPC_SMMR_SMSMPL_Pos)  /**< (SUPC_SMMR) Supply Monitor enabled one SLCK period every 32 SLCK periods Position  */
#define SUPC_SMMR_SMSMPL_256SLCK              (SUPC_SMMR_SMSMPL_256SLCK_Val << SUPC_SMMR_SMSMPL_Pos)  /**< (SUPC_SMMR) Supply Monitor enabled one SLCK period every 256 SLCK periods Position  */
#define SUPC_SMMR_SMSMPL_2048SLCK             (SUPC_SMMR_SMSMPL_2048SLCK_Val << SUPC_SMMR_SMSMPL_Pos)  /**< (SUPC_SMMR) Supply Monitor enabled one SLCK period every 2,048 SLCK periods Position  */
#define SUPC_SMMR_SMRSTEN_Pos                 (12)                                           /**< (SUPC_SMMR) Supply Monitor Reset Enable Position */
#define SUPC_SMMR_SMRSTEN_Msk                 (0x1U << SUPC_SMMR_SMRSTEN_Pos)                /**< (SUPC_SMMR) Supply Monitor Reset Enable Mask */
#define   SUPC_SMMR_SMRSTEN_NOT_ENABLE_Val    (0x0U)                                         /**< (SUPC_SMMR) The core reset signal vddcore_nreset is not affected when a supply monitor detection occurs.  */
#define   SUPC_SMMR_SMRSTEN_ENABLE_Val        (0x1U)                                         /**< (SUPC_SMMR) The core reset signal, vddcore_nreset is asserted when a supply monitor detection occurs.  */
#define SUPC_SMMR_SMRSTEN_NOT_ENABLE          (SUPC_SMMR_SMRSTEN_NOT_ENABLE_Val << SUPC_SMMR_SMRSTEN_Pos)  /**< (SUPC_SMMR) The core reset signal vddcore_nreset is not affected when a supply monitor detection occurs. Position  */
#define SUPC_SMMR_SMRSTEN_ENABLE              (SUPC_SMMR_SMRSTEN_ENABLE_Val << SUPC_SMMR_SMRSTEN_Pos)  /**< (SUPC_SMMR) The core reset signal, vddcore_nreset is asserted when a supply monitor detection occurs. Position  */
#define SUPC_SMMR_SMIEN_Pos                   (13)                                           /**< (SUPC_SMMR) Supply Monitor Interrupt Enable Position */
#define SUPC_SMMR_SMIEN_Msk                   (0x1U << SUPC_SMMR_SMIEN_Pos)                  /**< (SUPC_SMMR) Supply Monitor Interrupt Enable Mask */
#define   SUPC_SMMR_SMIEN_NOT_ENABLE_Val      (0x0U)                                         /**< (SUPC_SMMR) The SUPC interrupt signal is not affected when a supply monitor detection occurs.  */
#define   SUPC_SMMR_SMIEN_ENABLE_Val          (0x1U)                                         /**< (SUPC_SMMR) The SUPC interrupt signal is asserted when a supply monitor detection occurs.  */
#define SUPC_SMMR_SMIEN_NOT_ENABLE            (SUPC_SMMR_SMIEN_NOT_ENABLE_Val << SUPC_SMMR_SMIEN_Pos)  /**< (SUPC_SMMR) The SUPC interrupt signal is not affected when a supply monitor detection occurs. Position  */
#define SUPC_SMMR_SMIEN_ENABLE                (SUPC_SMMR_SMIEN_ENABLE_Val << SUPC_SMMR_SMIEN_Pos)  /**< (SUPC_SMMR) The SUPC interrupt signal is asserted when a supply monitor detection occurs. Position  */
#define SUPC_SMMR_Msk                         (0x0000370FUL)                                 /**< (SUPC_SMMR) Register Mask  */

/* -------- SUPC_MR : (SUPC Offset: 0x08) (R/W 32) Supply Controller Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t :12;                       /**< bit:  0..11  Reserved                                      */
    uint32_t BODRSTEN:1;                /**< bit:     12  Brownout Detector Reset Enable                */
    uint32_t BODDIS:1;                  /**< bit:     13  Brownout Detector Disable                     */
    uint32_t ONREG:1;                   /**< bit:     14  Voltage Regulator Enable                      */
    uint32_t :2;                        /**< bit: 15..16  Reserved                                      */
    uint32_t BKUPRETON:1;               /**< bit:     17  SRAM On In Backup Mode                        */
    uint32_t :2;                        /**< bit: 18..19  Reserved                                      */
    uint32_t OSCBYPASS:1;               /**< bit:     20  Oscillator Bypass                             */
    uint32_t :3;                        /**< bit: 21..23  Reserved                                      */
    uint32_t KEY:8;                     /**< bit: 24..31  Password Key                                  */
  };
  uint32_t w;
} __SUPC_MR_bits_t;

#define SUPC_MR_BODRSTEN_Pos                  (12)                                           /**< (SUPC_MR) Brownout Detector Reset Enable Position */
#define SUPC_MR_BODRSTEN_Msk                  (0x1U << SUPC_MR_BODRSTEN_Pos)                 /**< (SUPC_MR) Brownout Detector Reset Enable Mask */
#define   SUPC_MR_BODRSTEN_NOT_ENABLE_Val     (0x0U)                                         /**< (SUPC_MR) The core reset signal vddcore_nreset is not affected when a brownout detection occurs.  */
#define   SUPC_MR_BODRSTEN_ENABLE_Val         (0x1U)                                         /**< (SUPC_MR) The core reset signal, vddcore_nreset is asserted when a brownout detection occurs.  */
#define SUPC_MR_BODRSTEN_NOT_ENABLE           (SUPC_MR_BODRSTEN_NOT_ENABLE_Val << SUPC_MR_BODRSTEN_Pos)  /**< (SUPC_MR) The core reset signal vddcore_nreset is not affected when a brownout detection occurs. Position  */
#define SUPC_MR_BODRSTEN_ENABLE               (SUPC_MR_BODRSTEN_ENABLE_Val << SUPC_MR_BODRSTEN_Pos)  /**< (SUPC_MR) The core reset signal, vddcore_nreset is asserted when a brownout detection occurs. Position  */
#define SUPC_MR_BODDIS_Pos                    (13)                                           /**< (SUPC_MR) Brownout Detector Disable Position */
#define SUPC_MR_BODDIS_Msk                    (0x1U << SUPC_MR_BODDIS_Pos)                   /**< (SUPC_MR) Brownout Detector Disable Mask */
#define   SUPC_MR_BODDIS_ENABLE_Val           (0x0U)                                         /**< (SUPC_MR) The core brownout detector is enabled.  */
#define   SUPC_MR_BODDIS_DISABLE_Val          (0x1U)                                         /**< (SUPC_MR) The core brownout detector is disabled.  */
#define SUPC_MR_BODDIS_ENABLE                 (SUPC_MR_BODDIS_ENABLE_Val << SUPC_MR_BODDIS_Pos)  /**< (SUPC_MR) The core brownout detector is enabled. Position  */
#define SUPC_MR_BODDIS_DISABLE                (SUPC_MR_BODDIS_DISABLE_Val << SUPC_MR_BODDIS_Pos)  /**< (SUPC_MR) The core brownout detector is disabled. Position  */
#define SUPC_MR_ONREG_Pos                     (14)                                           /**< (SUPC_MR) Voltage Regulator Enable Position */
#define SUPC_MR_ONREG_Msk                     (0x1U << SUPC_MR_ONREG_Pos)                    /**< (SUPC_MR) Voltage Regulator Enable Mask */
#define   SUPC_MR_ONREG_ONREG_UNUSED_Val      (0x0U)                                         /**< (SUPC_MR) Internal voltage regulator is not used (external power supply is used).  */
#define   SUPC_MR_ONREG_ONREG_USED_Val        (0x1U)                                         /**< (SUPC_MR) Internal voltage regulator is used.  */
#define SUPC_MR_ONREG_ONREG_UNUSED            (SUPC_MR_ONREG_ONREG_UNUSED_Val << SUPC_MR_ONREG_Pos)  /**< (SUPC_MR) Internal voltage regulator is not used (external power supply is used). Position  */
#define SUPC_MR_ONREG_ONREG_USED              (SUPC_MR_ONREG_ONREG_USED_Val << SUPC_MR_ONREG_Pos)  /**< (SUPC_MR) Internal voltage regulator is used. Position  */
#define SUPC_MR_BKUPRETON_Pos                 (17)                                           /**< (SUPC_MR) SRAM On In Backup Mode Position */
#define SUPC_MR_BKUPRETON_Msk                 (0x1U << SUPC_MR_BKUPRETON_Pos)                /**< (SUPC_MR) SRAM On In Backup Mode Mask */
#define SUPC_MR_OSCBYPASS_Pos                 (20)                                           /**< (SUPC_MR) Oscillator Bypass Position */
#define SUPC_MR_OSCBYPASS_Msk                 (0x1U << SUPC_MR_OSCBYPASS_Pos)                /**< (SUPC_MR) Oscillator Bypass Mask */
#define   SUPC_MR_OSCBYPASS_NO_EFFECT_Val     (0x0U)                                         /**< (SUPC_MR) No effect. Clock selection depends on the value of XTALSEL (SUPC_CR).  */
#define   SUPC_MR_OSCBYPASS_BYPASS_Val        (0x1U)                                         /**< (SUPC_MR) The 32 kHz crystal oscillator is bypassed if XTALSEL (SUPC_CR) is set. OSCBYPASS must be set prior to setting XTALSEL.  */
#define SUPC_MR_OSCBYPASS_NO_EFFECT           (SUPC_MR_OSCBYPASS_NO_EFFECT_Val << SUPC_MR_OSCBYPASS_Pos)  /**< (SUPC_MR) No effect. Clock selection depends on the value of XTALSEL (SUPC_CR). Position  */
#define SUPC_MR_OSCBYPASS_BYPASS              (SUPC_MR_OSCBYPASS_BYPASS_Val << SUPC_MR_OSCBYPASS_Pos)  /**< (SUPC_MR) The 32 kHz crystal oscillator is bypassed if XTALSEL (SUPC_CR) is set. OSCBYPASS must be set prior to setting XTALSEL. Position  */
#define SUPC_MR_KEY_Pos                       (24)                                           /**< (SUPC_MR) Password Key Position */
#define SUPC_MR_KEY_Msk                       (0xFFU << SUPC_MR_KEY_Pos)                     /**< (SUPC_MR) Password Key Mask */
#define SUPC_MR_KEY(value)                    (SUPC_MR_KEY_Msk & ((value) << SUPC_MR_KEY_Pos))
#define   SUPC_MR_KEY_PASSWD_Val              (0xA5U)                                        /**< (SUPC_MR) Writing any other value in this field aborts the write operation.  */
#define SUPC_MR_KEY_PASSWD                    (SUPC_MR_KEY_PASSWD_Val << SUPC_MR_KEY_Pos)    /**< (SUPC_MR) Writing any other value in this field aborts the write operation. Position  */
#define SUPC_MR_Msk                           (0xFF127000UL)                                 /**< (SUPC_MR) Register Mask  */

/* -------- SUPC_WUMR : (SUPC Offset: 0x0c) (R/W 32) Supply Controller Wakeup Mode Register -------- */

typedef union
{
  struct
  {
    uint32_t :1;                        /**< bit:      0  Reserved                                      */
    uint32_t SMEN:1;                    /**< bit:      1  Supply Monitor Wakeup Enable                  */
    uint32_t RTTEN:1;                   /**< bit:      2  Real-time Timer Wakeup Enable                 */
    uint32_t RTCEN:1;                   /**< bit:      3  Real-time Clock Wakeup Enable                 */
    uint32_t :1;                        /**< bit:      4  Reserved                                      */
    uint32_t LPDBCEN0:1;                /**< bit:      5  Low-power Debouncer Enable WKUP0              */
    uint32_t LPDBCEN1:1;                /**< bit:      6  Low-power Debouncer Enable WKUP1              */
    uint32_t LPDBCCLR:1;                /**< bit:      7  Low-power Debouncer Clear                     */
    uint32_t :4;                        /**< bit:  8..11  Reserved                                      */
    uint32_t WKUPDBC:3;                 /**< bit: 12..14  Wakeup Inputs Debouncer Period                */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t LPDBC:3;                   /**< bit: 16..18  Low-power Debouncer Period                    */
    uint32_t :13;                       /**< bit: 19..31  Reserved                                      */
  };
  struct
  {
    uint32_t :5;                        /**< bit:   0..4  Reserved                                      */
    uint32_t LPDBCEN:2;                 /**< bit:   5..6  Low-power Debouncer Enable WKUPx              */
    uint32_t :25;                       /**< bit:  7..31  Reserved                                      */
  };
  uint32_t w;
} __SUPC_WUMR_bits_t;

#define SUPC_WUMR_SMEN_Pos                    (1)                                            /**< (SUPC_WUMR) Supply Monitor Wakeup Enable Position */
#define SUPC_WUMR_SMEN_Msk                    (0x1U << SUPC_WUMR_SMEN_Pos)                   /**< (SUPC_WUMR) Supply Monitor Wakeup Enable Mask */
#define   SUPC_WUMR_SMEN_NOT_ENABLE_Val       (0x0U)                                         /**< (SUPC_WUMR) The supply monitor detection has no wakeup effect.  */
#define   SUPC_WUMR_SMEN_ENABLE_Val           (0x1U)                                         /**< (SUPC_WUMR) The supply monitor detection forces the wakeup of the core power supply.  */
#define SUPC_WUMR_SMEN_NOT_ENABLE             (SUPC_WUMR_SMEN_NOT_ENABLE_Val << SUPC_WUMR_SMEN_Pos)  /**< (SUPC_WUMR) The supply monitor detection has no wakeup effect. Position  */
#define SUPC_WUMR_SMEN_ENABLE                 (SUPC_WUMR_SMEN_ENABLE_Val << SUPC_WUMR_SMEN_Pos)  /**< (SUPC_WUMR) The supply monitor detection forces the wakeup of the core power supply. Position  */
#define SUPC_WUMR_RTTEN_Pos                   (2)                                            /**< (SUPC_WUMR) Real-time Timer Wakeup Enable Position */
#define SUPC_WUMR_RTTEN_Msk                   (0x1U << SUPC_WUMR_RTTEN_Pos)                  /**< (SUPC_WUMR) Real-time Timer Wakeup Enable Mask */
#define   SUPC_WUMR_RTTEN_NOT_ENABLE_Val      (0x0U)                                         /**< (SUPC_WUMR) The RTT alarm signal has no wakeup effect.  */
#define   SUPC_WUMR_RTTEN_ENABLE_Val          (0x1U)                                         /**< (SUPC_WUMR) The RTT alarm signal forces the wakeup of the core power supply.  */
#define SUPC_WUMR_RTTEN_NOT_ENABLE            (SUPC_WUMR_RTTEN_NOT_ENABLE_Val << SUPC_WUMR_RTTEN_Pos)  /**< (SUPC_WUMR) The RTT alarm signal has no wakeup effect. Position  */
#define SUPC_WUMR_RTTEN_ENABLE                (SUPC_WUMR_RTTEN_ENABLE_Val << SUPC_WUMR_RTTEN_Pos)  /**< (SUPC_WUMR) The RTT alarm signal forces the wakeup of the core power supply. Position  */
#define SUPC_WUMR_RTCEN_Pos                   (3)                                            /**< (SUPC_WUMR) Real-time Clock Wakeup Enable Position */
#define SUPC_WUMR_RTCEN_Msk                   (0x1U << SUPC_WUMR_RTCEN_Pos)                  /**< (SUPC_WUMR) Real-time Clock Wakeup Enable Mask */
#define   SUPC_WUMR_RTCEN_NOT_ENABLE_Val      (0x0U)                                         /**< (SUPC_WUMR) The RTC alarm signal has no wakeup effect.  */
#define   SUPC_WUMR_RTCEN_ENABLE_Val          (0x1U)                                         /**< (SUPC_WUMR) The RTC alarm signal forces the wakeup of the core power supply.  */
#define SUPC_WUMR_RTCEN_NOT_ENABLE            (SUPC_WUMR_RTCEN_NOT_ENABLE_Val << SUPC_WUMR_RTCEN_Pos)  /**< (SUPC_WUMR) The RTC alarm signal has no wakeup effect. Position  */
#define SUPC_WUMR_RTCEN_ENABLE                (SUPC_WUMR_RTCEN_ENABLE_Val << SUPC_WUMR_RTCEN_Pos)  /**< (SUPC_WUMR) The RTC alarm signal forces the wakeup of the core power supply. Position  */
#define SUPC_WUMR_LPDBCEN0_Pos                (5)                                            /**< (SUPC_WUMR) Low-power Debouncer Enable WKUP0 Position */
#define SUPC_WUMR_LPDBCEN0_Msk                (0x1U << SUPC_WUMR_LPDBCEN0_Pos)               /**< (SUPC_WUMR) Low-power Debouncer Enable WKUP0 Mask */
#define   SUPC_WUMR_LPDBCEN0_NOT_ENABLE_Val   (0x0U)                                         /**< (SUPC_WUMR) The WKUP0 input pin is not connected to the low-power debouncer.  */
#define   SUPC_WUMR_LPDBCEN0_ENABLE_Val       (0x1U)                                         /**< (SUPC_WUMR) The WKUP0 input pin is connected to the low-power debouncer and forces a system wakeup.  */
#define SUPC_WUMR_LPDBCEN0_NOT_ENABLE         (SUPC_WUMR_LPDBCEN0_NOT_ENABLE_Val << SUPC_WUMR_LPDBCEN0_Pos)  /**< (SUPC_WUMR) The WKUP0 input pin is not connected to the low-power debouncer. Position  */
#define SUPC_WUMR_LPDBCEN0_ENABLE             (SUPC_WUMR_LPDBCEN0_ENABLE_Val << SUPC_WUMR_LPDBCEN0_Pos)  /**< (SUPC_WUMR) The WKUP0 input pin is connected to the low-power debouncer and forces a system wakeup. Position  */
#define SUPC_WUMR_LPDBCEN1_Pos                (6)                                            /**< (SUPC_WUMR) Low-power Debouncer Enable WKUP1 Position */
#define SUPC_WUMR_LPDBCEN1_Msk                (0x1U << SUPC_WUMR_LPDBCEN1_Pos)               /**< (SUPC_WUMR) Low-power Debouncer Enable WKUP1 Mask */
#define   SUPC_WUMR_LPDBCEN1_NOT_ENABLE_Val   (0x0U)                                         /**< (SUPC_WUMR) The WKUP1 input pin is not connected to the low-power debouncer.  */
#define   SUPC_WUMR_LPDBCEN1_ENABLE_Val       (0x1U)                                         /**< (SUPC_WUMR) The WKUP1 input pin is connected to the low-power debouncer and forces a system wakeup.  */
#define SUPC_WUMR_LPDBCEN1_NOT_ENABLE         (SUPC_WUMR_LPDBCEN1_NOT_ENABLE_Val << SUPC_WUMR_LPDBCEN1_Pos)  /**< (SUPC_WUMR) The WKUP1 input pin is not connected to the low-power debouncer. Position  */
#define SUPC_WUMR_LPDBCEN1_ENABLE             (SUPC_WUMR_LPDBCEN1_ENABLE_Val << SUPC_WUMR_LPDBCEN1_Pos)  /**< (SUPC_WUMR) The WKUP1 input pin is connected to the low-power debouncer and forces a system wakeup. Position  */
#define SUPC_WUMR_LPDBCCLR_Pos                (7)                                            /**< (SUPC_WUMR) Low-power Debouncer Clear Position */
#define SUPC_WUMR_LPDBCCLR_Msk                (0x1U << SUPC_WUMR_LPDBCCLR_Pos)               /**< (SUPC_WUMR) Low-power Debouncer Clear Mask */
#define   SUPC_WUMR_LPDBCCLR_NOT_ENABLE_Val   (0x0U)                                         /**< (SUPC_WUMR) A low-power debounce event does not create an immediate clear on the first half of GPBR registers.  */
#define   SUPC_WUMR_LPDBCCLR_ENABLE_Val       (0x1U)                                         /**< (SUPC_WUMR) A low-power debounce event on WKUP0 or WKUP1 generates an immediate clear on the first half of GPBR registers.  */
#define SUPC_WUMR_LPDBCCLR_NOT_ENABLE         (SUPC_WUMR_LPDBCCLR_NOT_ENABLE_Val << SUPC_WUMR_LPDBCCLR_Pos)  /**< (SUPC_WUMR) A low-power debounce event does not create an immediate clear on the first half of GPBR registers. Position  */
#define SUPC_WUMR_LPDBCCLR_ENABLE             (SUPC_WUMR_LPDBCCLR_ENABLE_Val << SUPC_WUMR_LPDBCCLR_Pos)  /**< (SUPC_WUMR) A low-power debounce event on WKUP0 or WKUP1 generates an immediate clear on the first half of GPBR registers. Position  */
#define SUPC_WUMR_WKUPDBC_Pos                 (12)                                           /**< (SUPC_WUMR) Wakeup Inputs Debouncer Period Position */
#define SUPC_WUMR_WKUPDBC_Msk                 (0x7U << SUPC_WUMR_WKUPDBC_Pos)                /**< (SUPC_WUMR) Wakeup Inputs Debouncer Period Mask */
#define SUPC_WUMR_WKUPDBC(value)              (SUPC_WUMR_WKUPDBC_Msk & ((value) << SUPC_WUMR_WKUPDBC_Pos))
#define   SUPC_WUMR_WKUPDBC_IMMEDIATE_Val     (0x0U)                                         /**< (SUPC_WUMR) Immediate, no debouncing, detected active at least on one Slow Clock edge.  */
#define   SUPC_WUMR_WKUPDBC_3_SLCK_Val        (0x1U)                                         /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 3 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_32_SLCK_Val       (0x2U)                                         /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 32 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_512_SLCK_Val      (0x3U)                                         /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 512 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_4096_SLCK_Val     (0x4U)                                         /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 4,096 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_32768_SLCK_Val    (0x5U)                                         /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 32,768 SLCK periods  */
#define SUPC_WUMR_WKUPDBC_IMMEDIATE           (SUPC_WUMR_WKUPDBC_IMMEDIATE_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) Immediate, no debouncing, detected active at least on one Slow Clock edge. Position  */
#define SUPC_WUMR_WKUPDBC_3_SLCK              (SUPC_WUMR_WKUPDBC_3_SLCK_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 3 SLCK periods Position  */
#define SUPC_WUMR_WKUPDBC_32_SLCK             (SUPC_WUMR_WKUPDBC_32_SLCK_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 32 SLCK periods Position  */
#define SUPC_WUMR_WKUPDBC_512_SLCK            (SUPC_WUMR_WKUPDBC_512_SLCK_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 512 SLCK periods Position  */
#define SUPC_WUMR_WKUPDBC_4096_SLCK           (SUPC_WUMR_WKUPDBC_4096_SLCK_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 4,096 SLCK periods Position  */
#define SUPC_WUMR_WKUPDBC_32768_SLCK          (SUPC_WUMR_WKUPDBC_32768_SLCK_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 32,768 SLCK periods Position  */
#define SUPC_WUMR_LPDBC_Pos                   (16)                                           /**< (SUPC_WUMR) Low-power Debouncer Period Position */
#define SUPC_WUMR_LPDBC_Msk                   (0x7U << SUPC_WUMR_LPDBC_Pos)                  /**< (SUPC_WUMR) Low-power Debouncer Period Mask */
#define SUPC_WUMR_LPDBC(value)                (SUPC_WUMR_LPDBC_Msk & ((value) << SUPC_WUMR_LPDBC_Pos))
#define   SUPC_WUMR_LPDBC_DISABLE_Val         (0x0U)                                         /**< (SUPC_WUMR) Disables the low-power debouncers.  */
#define   SUPC_WUMR_LPDBC_2_RTCOUT_Val        (0x1U)                                         /**< (SUPC_WUMR) WKUP0/1 in active state for at least 2 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_3_RTCOUT_Val        (0x2U)                                         /**< (SUPC_WUMR) WKUP0/1 in active state for at least 3 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_4_RTCOUT_Val        (0x3U)                                         /**< (SUPC_WUMR) WKUP0/1 in active state for at least 4 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_5_RTCOUT_Val        (0x4U)                                         /**< (SUPC_WUMR) WKUP0/1 in active state for at least 5 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_6_RTCOUT_Val        (0x5U)                                         /**< (SUPC_WUMR) WKUP0/1 in active state for at least 6 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_7_RTCOUT_Val        (0x6U)                                         /**< (SUPC_WUMR) WKUP0/1 in active state for at least 7 RTCOUTx clock periods  */
#define   SUPC_WUMR_LPDBC_8_RTCOUT_Val        (0x7U)                                         /**< (SUPC_WUMR) WKUP0/1 in active state for at least 8 RTCOUTx clock periods  */
#define SUPC_WUMR_LPDBC_DISABLE               (SUPC_WUMR_LPDBC_DISABLE_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) Disables the low-power debouncers. Position  */
#define SUPC_WUMR_LPDBC_2_RTCOUT              (SUPC_WUMR_LPDBC_2_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 2 RTCOUTx clock periods Position  */
#define SUPC_WUMR_LPDBC_3_RTCOUT              (SUPC_WUMR_LPDBC_3_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 3 RTCOUTx clock periods Position  */
#define SUPC_WUMR_LPDBC_4_RTCOUT              (SUPC_WUMR_LPDBC_4_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 4 RTCOUTx clock periods Position  */
#define SUPC_WUMR_LPDBC_5_RTCOUT              (SUPC_WUMR_LPDBC_5_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 5 RTCOUTx clock periods Position  */
#define SUPC_WUMR_LPDBC_6_RTCOUT              (SUPC_WUMR_LPDBC_6_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 6 RTCOUTx clock periods Position  */
#define SUPC_WUMR_LPDBC_7_RTCOUT              (SUPC_WUMR_LPDBC_7_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 7 RTCOUTx clock periods Position  */
#define SUPC_WUMR_LPDBC_8_RTCOUT              (SUPC_WUMR_LPDBC_8_RTCOUT_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 8 RTCOUTx clock periods Position  */
#define SUPC_WUMR_Msk                         (0x000770EEUL)                                 /**< (SUPC_WUMR) Register Mask  */
#define SUPC_WUMR_LPDBCEN_Pos                 (5)                                            /**< (SUPC_WUMR Position) Low-power Debouncer Enable WKUPx */
#define SUPC_WUMR_LPDBCEN_Msk                 (0x3U << SUPC_WUMR_LPDBCEN_Pos)                /**< (SUPC_WUMR Mask) LPDBCEN */
#define SUPC_WUMR_LPDBCEN(value)              (SUPC_WUMR_LPDBCEN_Msk & ((value) << SUPC_WUMR_LPDBCEN_Pos))

/* -------- SUPC_WUIR : (SUPC Offset: 0x10) (R/W 32) Supply Controller Wakeup Inputs Register -------- */

typedef union
{
  struct
  {
    uint32_t WKUPEN0:1;                 /**< bit:      0  Wakeup Input Enable 0 to 0                    */
    uint32_t WKUPEN1:1;                 /**< bit:      1  Wakeup Input Enable 0 to 1                    */
    uint32_t WKUPEN2:1;                 /**< bit:      2  Wakeup Input Enable 0 to 2                    */
    uint32_t WKUPEN3:1;                 /**< bit:      3  Wakeup Input Enable 0 to 3                    */
    uint32_t WKUPEN4:1;                 /**< bit:      4  Wakeup Input Enable 0 to 4                    */
    uint32_t WKUPEN5:1;                 /**< bit:      5  Wakeup Input Enable 0 to 5                    */
    uint32_t WKUPEN6:1;                 /**< bit:      6  Wakeup Input Enable 0 to 6                    */
    uint32_t WKUPEN7:1;                 /**< bit:      7  Wakeup Input Enable 0 to 7                    */
    uint32_t WKUPEN8:1;                 /**< bit:      8  Wakeup Input Enable 0 to 8                    */
    uint32_t WKUPEN9:1;                 /**< bit:      9  Wakeup Input Enable 0 to 9                    */
    uint32_t WKUPEN10:1;                /**< bit:     10  Wakeup Input Enable 0 to 10                   */
    uint32_t WKUPEN11:1;                /**< bit:     11  Wakeup Input Enable 0 to 11                   */
    uint32_t WKUPEN12:1;                /**< bit:     12  Wakeup Input Enable 0 to 12                   */
    uint32_t WKUPEN13:1;                /**< bit:     13  Wakeup Input Enable 0 to 13                   */
    uint32_t :2;                        /**< bit: 14..15  Reserved                                      */
    uint32_t WKUPT0:1;                  /**< bit:     16  Wakeup Input Type 0 to 0                      */
    uint32_t WKUPT1:1;                  /**< bit:     17  Wakeup Input Type 0 to 1                      */
    uint32_t WKUPT2:1;                  /**< bit:     18  Wakeup Input Type 0 to 2                      */
    uint32_t WKUPT3:1;                  /**< bit:     19  Wakeup Input Type 0 to 3                      */
    uint32_t WKUPT4:1;                  /**< bit:     20  Wakeup Input Type 0 to 4                      */
    uint32_t WKUPT5:1;                  /**< bit:     21  Wakeup Input Type 0 to 5                      */
    uint32_t WKUPT6:1;                  /**< bit:     22  Wakeup Input Type 0 to 6                      */
    uint32_t WKUPT7:1;                  /**< bit:     23  Wakeup Input Type 0 to 7                      */
    uint32_t WKUPT8:1;                  /**< bit:     24  Wakeup Input Type 0 to 8                      */
    uint32_t WKUPT9:1;                  /**< bit:     25  Wakeup Input Type 0 to 9                      */
    uint32_t WKUPT10:1;                 /**< bit:     26  Wakeup Input Type 0 to 10                     */
    uint32_t WKUPT11:1;                 /**< bit:     27  Wakeup Input Type 0 to 11                     */
    uint32_t WKUPT12:1;                 /**< bit:     28  Wakeup Input Type 0 to 12                     */
    uint32_t WKUPT13:1;                 /**< bit:     29  Wakeup Input Type 0 to 13                     */
    uint32_t :2;                        /**< bit: 30..31  Reserved                                      */
  };
  struct
  {
    uint32_t WKUPEN:14;                 /**< bit:  0..13  Wakeup Input Enable x to x                    */
    uint32_t :2;                        /**< bit: 14..15  Reserved                                      */
    uint32_t WKUPT:14;                  /**< bit: 16..29  Wakeup Input Type x to x3                     */
    uint32_t :2;                        /**< bit: 30..31  Reserved                                      */
  };
  uint32_t w;
} __SUPC_WUIR_bits_t;

#define SUPC_WUIR_WKUPEN0_Pos                 (0)                                            /**< (SUPC_WUIR) Wakeup Input Enable 0 to 0 Position */
#define SUPC_WUIR_WKUPEN0_Msk                 (0x1U << SUPC_WUIR_WKUPEN0_Pos)                /**< (SUPC_WUIR) Wakeup Input Enable 0 to 0 Mask */
#define   SUPC_WUIR_WKUPEN0_DISABLE_Val       (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN0_ENABLE_Val        (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN0_DISABLE             (SUPC_WUIR_WKUPEN0_DISABLE_Val << SUPC_WUIR_WKUPEN0_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN0_ENABLE              (SUPC_WUIR_WKUPEN0_ENABLE_Val << SUPC_WUIR_WKUPEN0_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN1_Pos                 (1)                                            /**< (SUPC_WUIR) Wakeup Input Enable 0 to 1 Position */
#define SUPC_WUIR_WKUPEN1_Msk                 (0x1U << SUPC_WUIR_WKUPEN1_Pos)                /**< (SUPC_WUIR) Wakeup Input Enable 0 to 1 Mask */
#define   SUPC_WUIR_WKUPEN1_DISABLE_Val       (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN1_ENABLE_Val        (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN1_DISABLE             (SUPC_WUIR_WKUPEN1_DISABLE_Val << SUPC_WUIR_WKUPEN1_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN1_ENABLE              (SUPC_WUIR_WKUPEN1_ENABLE_Val << SUPC_WUIR_WKUPEN1_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN2_Pos                 (2)                                            /**< (SUPC_WUIR) Wakeup Input Enable 0 to 2 Position */
#define SUPC_WUIR_WKUPEN2_Msk                 (0x1U << SUPC_WUIR_WKUPEN2_Pos)                /**< (SUPC_WUIR) Wakeup Input Enable 0 to 2 Mask */
#define   SUPC_WUIR_WKUPEN2_DISABLE_Val       (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN2_ENABLE_Val        (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN2_DISABLE             (SUPC_WUIR_WKUPEN2_DISABLE_Val << SUPC_WUIR_WKUPEN2_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN2_ENABLE              (SUPC_WUIR_WKUPEN2_ENABLE_Val << SUPC_WUIR_WKUPEN2_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN3_Pos                 (3)                                            /**< (SUPC_WUIR) Wakeup Input Enable 0 to 3 Position */
#define SUPC_WUIR_WKUPEN3_Msk                 (0x1U << SUPC_WUIR_WKUPEN3_Pos)                /**< (SUPC_WUIR) Wakeup Input Enable 0 to 3 Mask */
#define   SUPC_WUIR_WKUPEN3_DISABLE_Val       (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN3_ENABLE_Val        (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN3_DISABLE             (SUPC_WUIR_WKUPEN3_DISABLE_Val << SUPC_WUIR_WKUPEN3_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN3_ENABLE              (SUPC_WUIR_WKUPEN3_ENABLE_Val << SUPC_WUIR_WKUPEN3_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN4_Pos                 (4)                                            /**< (SUPC_WUIR) Wakeup Input Enable 0 to 4 Position */
#define SUPC_WUIR_WKUPEN4_Msk                 (0x1U << SUPC_WUIR_WKUPEN4_Pos)                /**< (SUPC_WUIR) Wakeup Input Enable 0 to 4 Mask */
#define   SUPC_WUIR_WKUPEN4_DISABLE_Val       (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN4_ENABLE_Val        (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN4_DISABLE             (SUPC_WUIR_WKUPEN4_DISABLE_Val << SUPC_WUIR_WKUPEN4_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN4_ENABLE              (SUPC_WUIR_WKUPEN4_ENABLE_Val << SUPC_WUIR_WKUPEN4_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN5_Pos                 (5)                                            /**< (SUPC_WUIR) Wakeup Input Enable 0 to 5 Position */
#define SUPC_WUIR_WKUPEN5_Msk                 (0x1U << SUPC_WUIR_WKUPEN5_Pos)                /**< (SUPC_WUIR) Wakeup Input Enable 0 to 5 Mask */
#define   SUPC_WUIR_WKUPEN5_DISABLE_Val       (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN5_ENABLE_Val        (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN5_DISABLE             (SUPC_WUIR_WKUPEN5_DISABLE_Val << SUPC_WUIR_WKUPEN5_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN5_ENABLE              (SUPC_WUIR_WKUPEN5_ENABLE_Val << SUPC_WUIR_WKUPEN5_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN6_Pos                 (6)                                            /**< (SUPC_WUIR) Wakeup Input Enable 0 to 6 Position */
#define SUPC_WUIR_WKUPEN6_Msk                 (0x1U << SUPC_WUIR_WKUPEN6_Pos)                /**< (SUPC_WUIR) Wakeup Input Enable 0 to 6 Mask */
#define   SUPC_WUIR_WKUPEN6_DISABLE_Val       (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN6_ENABLE_Val        (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN6_DISABLE             (SUPC_WUIR_WKUPEN6_DISABLE_Val << SUPC_WUIR_WKUPEN6_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN6_ENABLE              (SUPC_WUIR_WKUPEN6_ENABLE_Val << SUPC_WUIR_WKUPEN6_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN7_Pos                 (7)                                            /**< (SUPC_WUIR) Wakeup Input Enable 0 to 7 Position */
#define SUPC_WUIR_WKUPEN7_Msk                 (0x1U << SUPC_WUIR_WKUPEN7_Pos)                /**< (SUPC_WUIR) Wakeup Input Enable 0 to 7 Mask */
#define   SUPC_WUIR_WKUPEN7_DISABLE_Val       (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN7_ENABLE_Val        (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN7_DISABLE             (SUPC_WUIR_WKUPEN7_DISABLE_Val << SUPC_WUIR_WKUPEN7_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN7_ENABLE              (SUPC_WUIR_WKUPEN7_ENABLE_Val << SUPC_WUIR_WKUPEN7_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN8_Pos                 (8)                                            /**< (SUPC_WUIR) Wakeup Input Enable 0 to 8 Position */
#define SUPC_WUIR_WKUPEN8_Msk                 (0x1U << SUPC_WUIR_WKUPEN8_Pos)                /**< (SUPC_WUIR) Wakeup Input Enable 0 to 8 Mask */
#define   SUPC_WUIR_WKUPEN8_DISABLE_Val       (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN8_ENABLE_Val        (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN8_DISABLE             (SUPC_WUIR_WKUPEN8_DISABLE_Val << SUPC_WUIR_WKUPEN8_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN8_ENABLE              (SUPC_WUIR_WKUPEN8_ENABLE_Val << SUPC_WUIR_WKUPEN8_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN9_Pos                 (9)                                            /**< (SUPC_WUIR) Wakeup Input Enable 0 to 9 Position */
#define SUPC_WUIR_WKUPEN9_Msk                 (0x1U << SUPC_WUIR_WKUPEN9_Pos)                /**< (SUPC_WUIR) Wakeup Input Enable 0 to 9 Mask */
#define   SUPC_WUIR_WKUPEN9_DISABLE_Val       (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN9_ENABLE_Val        (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN9_DISABLE             (SUPC_WUIR_WKUPEN9_DISABLE_Val << SUPC_WUIR_WKUPEN9_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN9_ENABLE              (SUPC_WUIR_WKUPEN9_ENABLE_Val << SUPC_WUIR_WKUPEN9_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN10_Pos                (10)                                           /**< (SUPC_WUIR) Wakeup Input Enable 0 to 10 Position */
#define SUPC_WUIR_WKUPEN10_Msk                (0x1U << SUPC_WUIR_WKUPEN10_Pos)               /**< (SUPC_WUIR) Wakeup Input Enable 0 to 10 Mask */
#define   SUPC_WUIR_WKUPEN10_DISABLE_Val      (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN10_ENABLE_Val       (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN10_DISABLE            (SUPC_WUIR_WKUPEN10_DISABLE_Val << SUPC_WUIR_WKUPEN10_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN10_ENABLE             (SUPC_WUIR_WKUPEN10_ENABLE_Val << SUPC_WUIR_WKUPEN10_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN11_Pos                (11)                                           /**< (SUPC_WUIR) Wakeup Input Enable 0 to 11 Position */
#define SUPC_WUIR_WKUPEN11_Msk                (0x1U << SUPC_WUIR_WKUPEN11_Pos)               /**< (SUPC_WUIR) Wakeup Input Enable 0 to 11 Mask */
#define   SUPC_WUIR_WKUPEN11_DISABLE_Val      (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN11_ENABLE_Val       (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN11_DISABLE            (SUPC_WUIR_WKUPEN11_DISABLE_Val << SUPC_WUIR_WKUPEN11_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN11_ENABLE             (SUPC_WUIR_WKUPEN11_ENABLE_Val << SUPC_WUIR_WKUPEN11_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN12_Pos                (12)                                           /**< (SUPC_WUIR) Wakeup Input Enable 0 to 12 Position */
#define SUPC_WUIR_WKUPEN12_Msk                (0x1U << SUPC_WUIR_WKUPEN12_Pos)               /**< (SUPC_WUIR) Wakeup Input Enable 0 to 12 Mask */
#define   SUPC_WUIR_WKUPEN12_DISABLE_Val      (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN12_ENABLE_Val       (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN12_DISABLE            (SUPC_WUIR_WKUPEN12_DISABLE_Val << SUPC_WUIR_WKUPEN12_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN12_ENABLE             (SUPC_WUIR_WKUPEN12_ENABLE_Val << SUPC_WUIR_WKUPEN12_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN13_Pos                (13)                                           /**< (SUPC_WUIR) Wakeup Input Enable 0 to 13 Position */
#define SUPC_WUIR_WKUPEN13_Msk                (0x1U << SUPC_WUIR_WKUPEN13_Pos)               /**< (SUPC_WUIR) Wakeup Input Enable 0 to 13 Mask */
#define   SUPC_WUIR_WKUPEN13_DISABLE_Val      (0x0U)                                         /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect.  */
#define   SUPC_WUIR_WKUPEN13_ENABLE_Val       (0x1U)                                         /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPEN13_DISABLE            (SUPC_WUIR_WKUPEN13_DISABLE_Val << SUPC_WUIR_WKUPEN13_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input has no wakeup effect. Position  */
#define SUPC_WUIR_WKUPEN13_ENABLE             (SUPC_WUIR_WKUPEN13_ENABLE_Val << SUPC_WUIR_WKUPEN13_Pos)  /**< (SUPC_WUIR) The corresponding wakeup input is enabled for a wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT0_Pos                  (16)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 0 Position */
#define SUPC_WUIR_WKUPT0_Msk                  (0x1U << SUPC_WUIR_WKUPT0_Pos)                 /**< (SUPC_WUIR) Wakeup Input Type 0 to 0 Mask */
#define   SUPC_WUIR_WKUPT0_LOW_Val            (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT0_HIGH_Val           (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT0_LOW                  (SUPC_WUIR_WKUPT0_LOW_Val << SUPC_WUIR_WKUPT0_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT0_HIGH                 (SUPC_WUIR_WKUPT0_HIGH_Val << SUPC_WUIR_WKUPT0_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT1_Pos                  (17)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 1 Position */
#define SUPC_WUIR_WKUPT1_Msk                  (0x1U << SUPC_WUIR_WKUPT1_Pos)                 /**< (SUPC_WUIR) Wakeup Input Type 0 to 1 Mask */
#define   SUPC_WUIR_WKUPT1_LOW_Val            (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT1_HIGH_Val           (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT1_LOW                  (SUPC_WUIR_WKUPT1_LOW_Val << SUPC_WUIR_WKUPT1_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT1_HIGH                 (SUPC_WUIR_WKUPT1_HIGH_Val << SUPC_WUIR_WKUPT1_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT2_Pos                  (18)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 2 Position */
#define SUPC_WUIR_WKUPT2_Msk                  (0x1U << SUPC_WUIR_WKUPT2_Pos)                 /**< (SUPC_WUIR) Wakeup Input Type 0 to 2 Mask */
#define   SUPC_WUIR_WKUPT2_LOW_Val            (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT2_HIGH_Val           (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT2_LOW                  (SUPC_WUIR_WKUPT2_LOW_Val << SUPC_WUIR_WKUPT2_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT2_HIGH                 (SUPC_WUIR_WKUPT2_HIGH_Val << SUPC_WUIR_WKUPT2_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT3_Pos                  (19)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 3 Position */
#define SUPC_WUIR_WKUPT3_Msk                  (0x1U << SUPC_WUIR_WKUPT3_Pos)                 /**< (SUPC_WUIR) Wakeup Input Type 0 to 3 Mask */
#define   SUPC_WUIR_WKUPT3_LOW_Val            (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT3_HIGH_Val           (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT3_LOW                  (SUPC_WUIR_WKUPT3_LOW_Val << SUPC_WUIR_WKUPT3_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT3_HIGH                 (SUPC_WUIR_WKUPT3_HIGH_Val << SUPC_WUIR_WKUPT3_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT4_Pos                  (20)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 4 Position */
#define SUPC_WUIR_WKUPT4_Msk                  (0x1U << SUPC_WUIR_WKUPT4_Pos)                 /**< (SUPC_WUIR) Wakeup Input Type 0 to 4 Mask */
#define   SUPC_WUIR_WKUPT4_LOW_Val            (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT4_HIGH_Val           (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT4_LOW                  (SUPC_WUIR_WKUPT4_LOW_Val << SUPC_WUIR_WKUPT4_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT4_HIGH                 (SUPC_WUIR_WKUPT4_HIGH_Val << SUPC_WUIR_WKUPT4_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT5_Pos                  (21)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 5 Position */
#define SUPC_WUIR_WKUPT5_Msk                  (0x1U << SUPC_WUIR_WKUPT5_Pos)                 /**< (SUPC_WUIR) Wakeup Input Type 0 to 5 Mask */
#define   SUPC_WUIR_WKUPT5_LOW_Val            (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT5_HIGH_Val           (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT5_LOW                  (SUPC_WUIR_WKUPT5_LOW_Val << SUPC_WUIR_WKUPT5_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT5_HIGH                 (SUPC_WUIR_WKUPT5_HIGH_Val << SUPC_WUIR_WKUPT5_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT6_Pos                  (22)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 6 Position */
#define SUPC_WUIR_WKUPT6_Msk                  (0x1U << SUPC_WUIR_WKUPT6_Pos)                 /**< (SUPC_WUIR) Wakeup Input Type 0 to 6 Mask */
#define   SUPC_WUIR_WKUPT6_LOW_Val            (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT6_HIGH_Val           (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT6_LOW                  (SUPC_WUIR_WKUPT6_LOW_Val << SUPC_WUIR_WKUPT6_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT6_HIGH                 (SUPC_WUIR_WKUPT6_HIGH_Val << SUPC_WUIR_WKUPT6_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT7_Pos                  (23)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 7 Position */
#define SUPC_WUIR_WKUPT7_Msk                  (0x1U << SUPC_WUIR_WKUPT7_Pos)                 /**< (SUPC_WUIR) Wakeup Input Type 0 to 7 Mask */
#define   SUPC_WUIR_WKUPT7_LOW_Val            (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT7_HIGH_Val           (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT7_LOW                  (SUPC_WUIR_WKUPT7_LOW_Val << SUPC_WUIR_WKUPT7_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT7_HIGH                 (SUPC_WUIR_WKUPT7_HIGH_Val << SUPC_WUIR_WKUPT7_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT8_Pos                  (24)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 8 Position */
#define SUPC_WUIR_WKUPT8_Msk                  (0x1U << SUPC_WUIR_WKUPT8_Pos)                 /**< (SUPC_WUIR) Wakeup Input Type 0 to 8 Mask */
#define   SUPC_WUIR_WKUPT8_LOW_Val            (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT8_HIGH_Val           (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT8_LOW                  (SUPC_WUIR_WKUPT8_LOW_Val << SUPC_WUIR_WKUPT8_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT8_HIGH                 (SUPC_WUIR_WKUPT8_HIGH_Val << SUPC_WUIR_WKUPT8_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT9_Pos                  (25)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 9 Position */
#define SUPC_WUIR_WKUPT9_Msk                  (0x1U << SUPC_WUIR_WKUPT9_Pos)                 /**< (SUPC_WUIR) Wakeup Input Type 0 to 9 Mask */
#define   SUPC_WUIR_WKUPT9_LOW_Val            (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT9_HIGH_Val           (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT9_LOW                  (SUPC_WUIR_WKUPT9_LOW_Val << SUPC_WUIR_WKUPT9_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT9_HIGH                 (SUPC_WUIR_WKUPT9_HIGH_Val << SUPC_WUIR_WKUPT9_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT10_Pos                 (26)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 10 Position */
#define SUPC_WUIR_WKUPT10_Msk                 (0x1U << SUPC_WUIR_WKUPT10_Pos)                /**< (SUPC_WUIR) Wakeup Input Type 0 to 10 Mask */
#define   SUPC_WUIR_WKUPT10_LOW_Val           (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT10_HIGH_Val          (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT10_LOW                 (SUPC_WUIR_WKUPT10_LOW_Val << SUPC_WUIR_WKUPT10_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT10_HIGH                (SUPC_WUIR_WKUPT10_HIGH_Val << SUPC_WUIR_WKUPT10_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT11_Pos                 (27)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 11 Position */
#define SUPC_WUIR_WKUPT11_Msk                 (0x1U << SUPC_WUIR_WKUPT11_Pos)                /**< (SUPC_WUIR) Wakeup Input Type 0 to 11 Mask */
#define   SUPC_WUIR_WKUPT11_LOW_Val           (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT11_HIGH_Val          (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT11_LOW                 (SUPC_WUIR_WKUPT11_LOW_Val << SUPC_WUIR_WKUPT11_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT11_HIGH                (SUPC_WUIR_WKUPT11_HIGH_Val << SUPC_WUIR_WKUPT11_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT12_Pos                 (28)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 12 Position */
#define SUPC_WUIR_WKUPT12_Msk                 (0x1U << SUPC_WUIR_WKUPT12_Pos)                /**< (SUPC_WUIR) Wakeup Input Type 0 to 12 Mask */
#define   SUPC_WUIR_WKUPT12_LOW_Val           (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT12_HIGH_Val          (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT12_LOW                 (SUPC_WUIR_WKUPT12_LOW_Val << SUPC_WUIR_WKUPT12_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT12_HIGH                (SUPC_WUIR_WKUPT12_HIGH_Val << SUPC_WUIR_WKUPT12_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT13_Pos                 (29)                                           /**< (SUPC_WUIR) Wakeup Input Type 0 to 13 Position */
#define SUPC_WUIR_WKUPT13_Msk                 (0x1U << SUPC_WUIR_WKUPT13_Pos)                /**< (SUPC_WUIR) Wakeup Input Type 0 to 13 Mask */
#define   SUPC_WUIR_WKUPT13_LOW_Val           (0x0U)                                         /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply.  */
#define   SUPC_WUIR_WKUPT13_HIGH_Val          (0x1U)                                         /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply.  */
#define SUPC_WUIR_WKUPT13_LOW                 (SUPC_WUIR_WKUPT13_LOW_Val << SUPC_WUIR_WKUPT13_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corre-sponding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_WKUPT13_HIGH                (SUPC_WUIR_WKUPT13_HIGH_Val << SUPC_WUIR_WKUPT13_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the cor-responding wakeup input forces the wakeup of the core power supply. Position  */
#define SUPC_WUIR_Msk                         (0x3FFF3FFFUL)                                 /**< (SUPC_WUIR) Register Mask  */
#define SUPC_WUIR_WKUPEN_Pos                  (0)                                            /**< (SUPC_WUIR Position) Wakeup Input Enable x to x */
#define SUPC_WUIR_WKUPEN_Msk                  (0x3FFFU << SUPC_WUIR_WKUPEN_Pos)              /**< (SUPC_WUIR Mask) WKUPEN */
#define SUPC_WUIR_WKUPEN(value)               (SUPC_WUIR_WKUPEN_Msk & ((value) << SUPC_WUIR_WKUPEN_Pos))
#define SUPC_WUIR_WKUPT_Pos                   (16)                                           /**< (SUPC_WUIR Position) Wakeup Input Type x to x3 */
#define SUPC_WUIR_WKUPT_Msk                   (0x3FFFU << SUPC_WUIR_WKUPT_Pos)               /**< (SUPC_WUIR Mask) WKUPT */
#define SUPC_WUIR_WKUPT(value)                (SUPC_WUIR_WKUPT_Msk & ((value) << SUPC_WUIR_WKUPT_Pos))

/* -------- SUPC_SR : (SUPC Offset: 0x14) (R/ 32) Supply Controller Status Register -------- */

typedef union
{
  struct
  {
    uint32_t :1;                        /**< bit:      0  Reserved                                      */
    uint32_t WKUPS:1;                   /**< bit:      1  WKUP Wakeup Status (cleared on read)          */
    uint32_t SMWS:1;                    /**< bit:      2  Supply Monitor Detection Wakeup Status (cleared on read) */
    uint32_t BODRSTS:1;                 /**< bit:      3  Brownout Detector Reset Status (cleared on read) */
    uint32_t SMRSTS:1;                  /**< bit:      4  Supply Monitor Reset Status (cleared on read) */
    uint32_t SMS:1;                     /**< bit:      5  Supply Monitor Status (cleared on read)       */
    uint32_t SMOS:1;                    /**< bit:      6  Supply Monitor Output Status                  */
    uint32_t OSCSEL:1;                  /**< bit:      7  32-kHz Oscillator Selection Status            */
    uint32_t :5;                        /**< bit:  8..12  Reserved                                      */
    uint32_t LPDBCS0:1;                 /**< bit:     13  Low-power Debouncer Wakeup Status on WKUP0 (cleared on read) */
    uint32_t LPDBCS1:1;                 /**< bit:     14  Low-power Debouncer Wakeup Status on WKUP1 (cleared on read) */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t WKUPIS0:1;                 /**< bit:     16  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS1:1;                 /**< bit:     17  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS2:1;                 /**< bit:     18  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS3:1;                 /**< bit:     19  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS4:1;                 /**< bit:     20  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS5:1;                 /**< bit:     21  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS6:1;                 /**< bit:     22  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS7:1;                 /**< bit:     23  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS8:1;                 /**< bit:     24  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS9:1;                 /**< bit:     25  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS10:1;                /**< bit:     26  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS11:1;                /**< bit:     27  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS12:1;                /**< bit:     28  WKUPx Input Status (cleared on read)          */
    uint32_t WKUPIS13:1;                /**< bit:     29  WKUPx Input Status (cleared on read)          */
    uint32_t :2;                        /**< bit: 30..31  Reserved                                      */
  };
  struct
  {
    uint32_t :13;                       /**< bit:  0..12  Reserved                                      */
    uint32_t LPDBCS:2;                  /**< bit: 13..14  Low-power Debouncer Wakeup Status on WKUPx (cleared on read) */
    uint32_t :1;                        /**< bit:     15  Reserved                                      */
    uint32_t WKUPIS:14;                 /**< bit: 16..29  WKUPx Input Status (cleared on read)          */
    uint32_t :2;                        /**< bit: 30..31  Reserved                                      */
  };
  uint32_t w;
} __SUPC_SR_bits_t;

#define SUPC_SR_WKUPS_Pos                     (1)                                            /**< (SUPC_SR) WKUP Wakeup Status (cleared on read) Position */
#define SUPC_SR_WKUPS_Msk                     (0x1U << SUPC_SR_WKUPS_Pos)                    /**< (SUPC_SR) WKUP Wakeup Status (cleared on read) Mask */
#define   SUPC_SR_WKUPS_NO_Val                (0x0U)                                         /**< (SUPC_SR) No wakeup due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR.  */
#define   SUPC_SR_WKUPS_PRESENT_Val           (0x1U)                                         /**< (SUPC_SR) At least one wakeup due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPS_NO                      (SUPC_SR_WKUPS_NO_Val << SUPC_SR_WKUPS_Pos)    /**< (SUPC_SR) No wakeup due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPS_PRESENT                 (SUPC_SR_WKUPS_PRESENT_Val << SUPC_SR_WKUPS_Pos)  /**< (SUPC_SR) At least one wakeup due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_SMWS_Pos                      (2)                                            /**< (SUPC_SR) Supply Monitor Detection Wakeup Status (cleared on read) Position */
#define SUPC_SR_SMWS_Msk                      (0x1U << SUPC_SR_SMWS_Pos)                     /**< (SUPC_SR) Supply Monitor Detection Wakeup Status (cleared on read) Mask */
#define   SUPC_SR_SMWS_NO_Val                 (0x0U)                                         /**< (SUPC_SR) No wakeup due to a supply monitor detection has occurred since the last read of SUPC_SR.  */
#define   SUPC_SR_SMWS_PRESENT_Val            (0x1U)                                         /**< (SUPC_SR) At least one wakeup due to a supply monitor detection has occurred since the last read of SUPC_SR.  */
#define SUPC_SR_SMWS_NO                       (SUPC_SR_SMWS_NO_Val << SUPC_SR_SMWS_Pos)      /**< (SUPC_SR) No wakeup due to a supply monitor detection has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_SMWS_PRESENT                  (SUPC_SR_SMWS_PRESENT_Val << SUPC_SR_SMWS_Pos)  /**< (SUPC_SR) At least one wakeup due to a supply monitor detection has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_BODRSTS_Pos                   (3)                                            /**< (SUPC_SR) Brownout Detector Reset Status (cleared on read) Position */
#define SUPC_SR_BODRSTS_Msk                   (0x1U << SUPC_SR_BODRSTS_Pos)                  /**< (SUPC_SR) Brownout Detector Reset Status (cleared on read) Mask */
#define   SUPC_SR_BODRSTS_NO_Val              (0x0U)                                         /**< (SUPC_SR) No core brownout rising edge event has been detected since the last read of the SUPC_SR.  */
#define   SUPC_SR_BODRSTS_PRESENT_Val         (0x1U)                                         /**< (SUPC_SR) At least one brownout output rising edge event has been detected since the last read of the SUPC_SR.  */
#define SUPC_SR_BODRSTS_NO                    (SUPC_SR_BODRSTS_NO_Val << SUPC_SR_BODRSTS_Pos)  /**< (SUPC_SR) No core brownout rising edge event has been detected since the last read of the SUPC_SR. Position  */
#define SUPC_SR_BODRSTS_PRESENT               (SUPC_SR_BODRSTS_PRESENT_Val << SUPC_SR_BODRSTS_Pos)  /**< (SUPC_SR) At least one brownout output rising edge event has been detected since the last read of the SUPC_SR. Position  */
#define SUPC_SR_SMRSTS_Pos                    (4)                                            /**< (SUPC_SR) Supply Monitor Reset Status (cleared on read) Position */
#define SUPC_SR_SMRSTS_Msk                    (0x1U << SUPC_SR_SMRSTS_Pos)                   /**< (SUPC_SR) Supply Monitor Reset Status (cleared on read) Mask */
#define   SUPC_SR_SMRSTS_NO_Val               (0x0U)                                         /**< (SUPC_SR) No supply monitor detection has generated a core reset since the last read of the SUPC_SR.  */
#define   SUPC_SR_SMRSTS_PRESENT_Val          (0x1U)                                         /**< (SUPC_SR) At least one supply monitor detection has generated a core reset since the last read of the SUPC_SR.  */
#define SUPC_SR_SMRSTS_NO                     (SUPC_SR_SMRSTS_NO_Val << SUPC_SR_SMRSTS_Pos)  /**< (SUPC_SR) No supply monitor detection has generated a core reset since the last read of the SUPC_SR. Position  */
#define SUPC_SR_SMRSTS_PRESENT                (SUPC_SR_SMRSTS_PRESENT_Val << SUPC_SR_SMRSTS_Pos)  /**< (SUPC_SR) At least one supply monitor detection has generated a core reset since the last read of the SUPC_SR. Position  */
#define SUPC_SR_SMS_Pos                       (5)                                            /**< (SUPC_SR) Supply Monitor Status (cleared on read) Position */
#define SUPC_SR_SMS_Msk                       (0x1U << SUPC_SR_SMS_Pos)                      /**< (SUPC_SR) Supply Monitor Status (cleared on read) Mask */
#define   SUPC_SR_SMS_NO_Val                  (0x0U)                                         /**< (SUPC_SR) No supply monitor detection since the last read of SUPC_SR.  */
#define   SUPC_SR_SMS_PRESENT_Val             (0x1U)                                         /**< (SUPC_SR) At least one supply monitor detection since the last read of SUPC_SR.  */
#define SUPC_SR_SMS_NO                        (SUPC_SR_SMS_NO_Val << SUPC_SR_SMS_Pos)        /**< (SUPC_SR) No supply monitor detection since the last read of SUPC_SR. Position  */
#define SUPC_SR_SMS_PRESENT                   (SUPC_SR_SMS_PRESENT_Val << SUPC_SR_SMS_Pos)   /**< (SUPC_SR) At least one supply monitor detection since the last read of SUPC_SR. Position  */
#define SUPC_SR_SMOS_Pos                      (6)                                            /**< (SUPC_SR) Supply Monitor Output Status Position */
#define SUPC_SR_SMOS_Msk                      (0x1U << SUPC_SR_SMOS_Pos)                     /**< (SUPC_SR) Supply Monitor Output Status Mask */
#define   SUPC_SR_SMOS_HIGH_Val               (0x0U)                                         /**< (SUPC_SR) The supply monitor detected VDDIO higher than its threshold at its last measurement.  */
#define   SUPC_SR_SMOS_LOW_Val                (0x1U)                                         /**< (SUPC_SR) The supply monitor detected VDDIO lower than its threshold at its last measurement.  */
#define SUPC_SR_SMOS_HIGH                     (SUPC_SR_SMOS_HIGH_Val << SUPC_SR_SMOS_Pos)    /**< (SUPC_SR) The supply monitor detected VDDIO higher than its threshold at its last measurement. Position  */
#define SUPC_SR_SMOS_LOW                      (SUPC_SR_SMOS_LOW_Val << SUPC_SR_SMOS_Pos)     /**< (SUPC_SR) The supply monitor detected VDDIO lower than its threshold at its last measurement. Position  */
#define SUPC_SR_OSCSEL_Pos                    (7)                                            /**< (SUPC_SR) 32-kHz Oscillator Selection Status Position */
#define SUPC_SR_OSCSEL_Msk                    (0x1U << SUPC_SR_OSCSEL_Pos)                   /**< (SUPC_SR) 32-kHz Oscillator Selection Status Mask */
#define   SUPC_SR_OSCSEL_RC_Val               (0x0U)                                         /**< (SUPC_SR) The slow clock, SLCK, is generated by the embedded 32 kHz RC oscillator.  */
#define   SUPC_SR_OSCSEL_CRYST_Val            (0x1U)                                         /**< (SUPC_SR) The slow clock, SLCK, is generated by the 32 kHz crystal oscillator.  */
#define SUPC_SR_OSCSEL_RC                     (SUPC_SR_OSCSEL_RC_Val << SUPC_SR_OSCSEL_Pos)  /**< (SUPC_SR) The slow clock, SLCK, is generated by the embedded 32 kHz RC oscillator. Position  */
#define SUPC_SR_OSCSEL_CRYST                  (SUPC_SR_OSCSEL_CRYST_Val << SUPC_SR_OSCSEL_Pos)  /**< (SUPC_SR) The slow clock, SLCK, is generated by the 32 kHz crystal oscillator. Position  */
#define SUPC_SR_LPDBCS0_Pos                   (13)                                           /**< (SUPC_SR) Low-power Debouncer Wakeup Status on WKUP0 (cleared on read) Position */
#define SUPC_SR_LPDBCS0_Msk                   (0x1U << SUPC_SR_LPDBCS0_Pos)                  /**< (SUPC_SR) Low-power Debouncer Wakeup Status on WKUP0 (cleared on read) Mask */
#define   SUPC_SR_LPDBCS0_NO_Val              (0x0U)                                         /**< (SUPC_SR) No wakeup due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR.  */
#define   SUPC_SR_LPDBCS0_PRESENT_Val         (0x1U)                                         /**< (SUPC_SR) At least one wakeup due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR.  */
#define SUPC_SR_LPDBCS0_NO                    (SUPC_SR_LPDBCS0_NO_Val << SUPC_SR_LPDBCS0_Pos)  /**< (SUPC_SR) No wakeup due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_LPDBCS0_PRESENT               (SUPC_SR_LPDBCS0_PRESENT_Val << SUPC_SR_LPDBCS0_Pos)  /**< (SUPC_SR) At least one wakeup due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_LPDBCS1_Pos                   (14)                                           /**< (SUPC_SR) Low-power Debouncer Wakeup Status on WKUP1 (cleared on read) Position */
#define SUPC_SR_LPDBCS1_Msk                   (0x1U << SUPC_SR_LPDBCS1_Pos)                  /**< (SUPC_SR) Low-power Debouncer Wakeup Status on WKUP1 (cleared on read) Mask */
#define   SUPC_SR_LPDBCS1_NO_Val              (0x0U)                                         /**< (SUPC_SR) No wakeup due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR.  */
#define   SUPC_SR_LPDBCS1_PRESENT_Val         (0x1U)                                         /**< (SUPC_SR) At least one wakeup due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR.  */
#define SUPC_SR_LPDBCS1_NO                    (SUPC_SR_LPDBCS1_NO_Val << SUPC_SR_LPDBCS1_Pos)  /**< (SUPC_SR) No wakeup due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_LPDBCS1_PRESENT               (SUPC_SR_LPDBCS1_PRESENT_Val << SUPC_SR_LPDBCS1_Pos)  /**< (SUPC_SR) At least one wakeup due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS0_Pos                   (16)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS0_Msk                   (0x1U << SUPC_SR_WKUPIS0_Pos)                  /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS0_DIS_Val             (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS0_EN_Val              (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS0_DIS                   (SUPC_SR_WKUPIS0_DIS_Val << SUPC_SR_WKUPIS0_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS0_EN                    (SUPC_SR_WKUPIS0_EN_Val << SUPC_SR_WKUPIS0_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS1_Pos                   (17)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS1_Msk                   (0x1U << SUPC_SR_WKUPIS1_Pos)                  /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS1_DIS_Val             (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS1_EN_Val              (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS1_DIS                   (SUPC_SR_WKUPIS1_DIS_Val << SUPC_SR_WKUPIS1_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS1_EN                    (SUPC_SR_WKUPIS1_EN_Val << SUPC_SR_WKUPIS1_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS2_Pos                   (18)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS2_Msk                   (0x1U << SUPC_SR_WKUPIS2_Pos)                  /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS2_DIS_Val             (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS2_EN_Val              (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS2_DIS                   (SUPC_SR_WKUPIS2_DIS_Val << SUPC_SR_WKUPIS2_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS2_EN                    (SUPC_SR_WKUPIS2_EN_Val << SUPC_SR_WKUPIS2_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS3_Pos                   (19)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS3_Msk                   (0x1U << SUPC_SR_WKUPIS3_Pos)                  /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS3_DIS_Val             (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS3_EN_Val              (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS3_DIS                   (SUPC_SR_WKUPIS3_DIS_Val << SUPC_SR_WKUPIS3_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS3_EN                    (SUPC_SR_WKUPIS3_EN_Val << SUPC_SR_WKUPIS3_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS4_Pos                   (20)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS4_Msk                   (0x1U << SUPC_SR_WKUPIS4_Pos)                  /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS4_DIS_Val             (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS4_EN_Val              (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS4_DIS                   (SUPC_SR_WKUPIS4_DIS_Val << SUPC_SR_WKUPIS4_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS4_EN                    (SUPC_SR_WKUPIS4_EN_Val << SUPC_SR_WKUPIS4_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS5_Pos                   (21)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS5_Msk                   (0x1U << SUPC_SR_WKUPIS5_Pos)                  /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS5_DIS_Val             (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS5_EN_Val              (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS5_DIS                   (SUPC_SR_WKUPIS5_DIS_Val << SUPC_SR_WKUPIS5_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS5_EN                    (SUPC_SR_WKUPIS5_EN_Val << SUPC_SR_WKUPIS5_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS6_Pos                   (22)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS6_Msk                   (0x1U << SUPC_SR_WKUPIS6_Pos)                  /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS6_DIS_Val             (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS6_EN_Val              (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS6_DIS                   (SUPC_SR_WKUPIS6_DIS_Val << SUPC_SR_WKUPIS6_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS6_EN                    (SUPC_SR_WKUPIS6_EN_Val << SUPC_SR_WKUPIS6_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS7_Pos                   (23)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS7_Msk                   (0x1U << SUPC_SR_WKUPIS7_Pos)                  /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS7_DIS_Val             (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS7_EN_Val              (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS7_DIS                   (SUPC_SR_WKUPIS7_DIS_Val << SUPC_SR_WKUPIS7_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS7_EN                    (SUPC_SR_WKUPIS7_EN_Val << SUPC_SR_WKUPIS7_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS8_Pos                   (24)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS8_Msk                   (0x1U << SUPC_SR_WKUPIS8_Pos)                  /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS8_DIS_Val             (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS8_EN_Val              (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS8_DIS                   (SUPC_SR_WKUPIS8_DIS_Val << SUPC_SR_WKUPIS8_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS8_EN                    (SUPC_SR_WKUPIS8_EN_Val << SUPC_SR_WKUPIS8_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS9_Pos                   (25)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS9_Msk                   (0x1U << SUPC_SR_WKUPIS9_Pos)                  /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS9_DIS_Val             (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS9_EN_Val              (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS9_DIS                   (SUPC_SR_WKUPIS9_DIS_Val << SUPC_SR_WKUPIS9_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS9_EN                    (SUPC_SR_WKUPIS9_EN_Val << SUPC_SR_WKUPIS9_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS10_Pos                  (26)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS10_Msk                  (0x1U << SUPC_SR_WKUPIS10_Pos)                 /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS10_DIS_Val            (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS10_EN_Val             (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS10_DIS                  (SUPC_SR_WKUPIS10_DIS_Val << SUPC_SR_WKUPIS10_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS10_EN                   (SUPC_SR_WKUPIS10_EN_Val << SUPC_SR_WKUPIS10_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS11_Pos                  (27)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS11_Msk                  (0x1U << SUPC_SR_WKUPIS11_Pos)                 /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS11_DIS_Val            (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS11_EN_Val             (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS11_DIS                  (SUPC_SR_WKUPIS11_DIS_Val << SUPC_SR_WKUPIS11_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS11_EN                   (SUPC_SR_WKUPIS11_EN_Val << SUPC_SR_WKUPIS11_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS12_Pos                  (28)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS12_Msk                  (0x1U << SUPC_SR_WKUPIS12_Pos)                 /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS12_DIS_Val            (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS12_EN_Val             (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS12_DIS                  (SUPC_SR_WKUPIS12_DIS_Val << SUPC_SR_WKUPIS12_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS12_EN                   (SUPC_SR_WKUPIS12_EN_Val << SUPC_SR_WKUPIS12_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS13_Pos                  (29)                                           /**< (SUPC_SR) WKUPx Input Status (cleared on read) Position */
#define SUPC_SR_WKUPIS13_Msk                  (0x1U << SUPC_SR_WKUPIS13_Pos)                 /**< (SUPC_SR) WKUPx Input Status (cleared on read) Mask */
#define   SUPC_SR_WKUPIS13_DIS_Val            (0x0U)                                         /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event.  */
#define   SUPC_SR_WKUPIS13_EN_Val             (0x1U)                                         /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS13_DIS                  (SUPC_SR_WKUPIS13_DIS_Val << SUPC_SR_WKUPIS13_Pos)  /**< (SUPC_SR) The corresponding wakeup input is disabled, or was inactive at the time the debouncer triggered a wakeup event. Position  */
#define SUPC_SR_WKUPIS13_EN                   (SUPC_SR_WKUPIS13_EN_Val << SUPC_SR_WKUPIS13_Pos)  /**< (SUPC_SR) The corresponding wakeup input was active at the time the debouncer triggered a wakeup event since the last read of SUPC_SR. Position  */
#define SUPC_SR_Msk                           (0x3FFF60FEUL)                                 /**< (SUPC_SR) Register Mask  */
#define SUPC_SR_LPDBCS_Pos                    (13)                                           /**< (SUPC_SR Position) Low-power Debouncer Wakeup Status on WKUPx (cleared on read) */
#define SUPC_SR_LPDBCS_Msk                    (0x3U << SUPC_SR_LPDBCS_Pos)                   /**< (SUPC_SR Mask) LPDBCS */
#define SUPC_SR_LPDBCS(value)                 (SUPC_SR_LPDBCS_Msk & ((value) << SUPC_SR_LPDBCS_Pos))
#define SUPC_SR_WKUPIS_Pos                    (16)                                           /**< (SUPC_SR Position) WKUPx Input Status (cleared on read) */
#define SUPC_SR_WKUPIS_Msk                    (0x3FFFU << SUPC_SR_WKUPIS_Pos)                /**< (SUPC_SR Mask) WKUPIS */
#define SUPC_SR_WKUPIS(value)                 (SUPC_SR_WKUPIS_Msk & ((value) << SUPC_SR_WKUPIS_Pos))

/** \brief SUPC register offsets definitions */
#define SUPC_CR_OFFSET               (0x00)         /**< (SUPC_CR) Supply Controller Control Register Offset */
#define SUPC_SMMR_OFFSET             (0x04)         /**< (SUPC_SMMR) Supply Controller Supply Monitor Mode Register Offset */
#define SUPC_MR_OFFSET               (0x08)         /**< (SUPC_MR) Supply Controller Mode Register Offset */
#define SUPC_WUMR_OFFSET             (0x0C)         /**< (SUPC_WUMR) Supply Controller Wakeup Mode Register Offset */
#define SUPC_WUIR_OFFSET             (0x10)         /**< (SUPC_WUIR) Supply Controller Wakeup Inputs Register Offset */
#define SUPC_SR_OFFSET               (0x14)         /**< (SUPC_SR) Supply Controller Status Register Offset */

/** \brief SUPC register API structure */
typedef struct
{
  __O   __SUPC_CR_bits_t               SUPC_CR;       /**< Offset: 0x00 ( /W  32) Supply Controller Control Register */
  __IO  __SUPC_SMMR_bits_t             SUPC_SMMR;     /**< Offset: 0x04 (R/W  32) Supply Controller Supply Monitor Mode Register */
  __IO  __SUPC_MR_bits_t               SUPC_MR;       /**< Offset: 0x08 (R/W  32) Supply Controller Mode Register */
  __IO  __SUPC_WUMR_bits_t             SUPC_WUMR;     /**< Offset: 0x0C (R/W  32) Supply Controller Wakeup Mode Register */
  __IO  __SUPC_WUIR_bits_t             SUPC_WUIR;     /**< Offset: 0x10 (R/W  32) Supply Controller Wakeup Inputs Register */
  __I   __SUPC_SR_bits_t               SUPC_SR;       /**< Offset: 0x14 (R/   32) Supply Controller Status Register */
} supc_registers_t;
/** @}  end of Supply Controller */

#endif /* _PIC32CZ_CA70_SUPC_COMPONENT_H_ */
