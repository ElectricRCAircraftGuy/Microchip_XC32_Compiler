/**
 * \brief Component description for PIC32CZ/CA70 GPBR
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
#ifndef _PIC32CZ_CA70_GPBR_COMPONENT_H_
#define _PIC32CZ_CA70_GPBR_COMPONENT_H_

/** \addtogroup PIC32CZ_CA70_GPBR General Purpose Backup Registers
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR GPBR */
/* ========================================================================== */

/* -------- GPBR_SYS_GPBR : (GPBR Offset: 0x00) (R/W 32) General Purpose Backup Register 0 -------- */

typedef union
{
  struct
  {
    uint32_t GPBR_VALUE:32;             /**< bit:  0..31  Value of GPBR x                               */
  };
  uint32_t w;
} __GPBR_SYS_GPBR_bits_t;

#define GPBR_SYS_GPBR_GPBR_VALUE_Pos          (0)                                            /**< (GPBR_SYS_GPBR) Value of GPBR x Position */
#define GPBR_SYS_GPBR_GPBR_VALUE_Msk          (0xFFFFFFFFU << GPBR_SYS_GPBR_GPBR_VALUE_Pos)  /**< (GPBR_SYS_GPBR) Value of GPBR x Mask */
#define GPBR_SYS_GPBR_GPBR_VALUE(value)       (GPBR_SYS_GPBR_GPBR_VALUE_Msk & ((value) << GPBR_SYS_GPBR_GPBR_VALUE_Pos))
#define GPBR_SYS_GPBR_Msk                     (0xFFFFFFFFUL)                                 /**< (GPBR_SYS_GPBR) Register Mask  */

/** \brief GPBR register offsets definitions */
#define GPBR_SYS_GPBR_OFFSET         (0x00)         /**< (GPBR_SYS_GPBR) General Purpose Backup Register 0 Offset */

/** \brief GPBR register API structure */
typedef struct
{
  __IO  __GPBR_SYS_GPBR_bits_t         SYS_GPBR[8];   /**< Offset: 0x00 (R/W  32) General Purpose Backup Register 0 */
} gpbr_registers_t;
/** @}  end of General Purpose Backup Registers */

#endif /* _PIC32CZ_CA70_GPBR_COMPONENT_H_ */
