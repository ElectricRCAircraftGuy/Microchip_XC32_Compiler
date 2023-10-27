/*-------------------------------------------------------------------------
 * XC builtins header
 *
 * Copyright (c) 2020, Microchip Technology Inc. and its subsidiaries ("Microchip")
 * All rights reserved.
 * 
 * This software is developed by Microchip Technology Inc. and its
 * subsidiaries ("Microchip").
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 * 1.      Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 * 2.      Redistributions in binary form must reproduce the above 
 *         copyright notice, this list of conditions and the following 
 *         disclaimer in the documentation and/or other materials provided 
 *         with the distribution.  Publication is not required when this file
 *         is used in an embedded application.
 * 3.      Microchip's name may not be used to endorse or promote products
 *         derived from this software without specific prior written 
 *         permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _PIC32M_BUILTINS_H
#define _PIC32M_BUILTINS_H 1

#ifndef __cplusplus

#include <stdint.h>

uint32_t __builtin_mips_get_fcsr (void);
void __builtin_mips_set_fcsr (uint32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_addq_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_addq_s_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_addq_s_w (int32_t, int32_t);
int8_t __attribute__ ((vector_size(4))) __builtin_mips_addu_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int8_t __attribute__ ((vector_size(4))) __builtin_mips_addu_s_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_subq_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_subq_s_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_subq_s_w (int32_t, int32_t);
int8_t __attribute__ ((vector_size(4))) __builtin_mips_subu_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int8_t __attribute__ ((vector_size(4))) __builtin_mips_subu_s_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_addsc (int32_t, int32_t);
int32_t __builtin_mips_addwc (int32_t, int32_t);
int32_t __builtin_mips_modsub (int32_t, int32_t);
int32_t __builtin_mips_raddu_w_qb (int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_absq_s_ph (int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_absq_s_w (int32_t);
int8_t __attribute__ ((vector_size(4))) __builtin_mips_precrq_qb_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_precrq_ph_w (int32_t, int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_precrq_rs_ph_w (int32_t, int32_t);
int8_t __attribute__ ((vector_size(4))) __builtin_mips_precrqu_s_qb_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_preceq_w_phl (int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_preceq_w_phr (int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_precequ_ph_qbl (int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_precequ_ph_qbr (int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_precequ_ph_qbla (int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_precequ_ph_qbra (int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_preceu_ph_qbl (int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_preceu_ph_qbr (int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_preceu_ph_qbla (int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_preceu_ph_qbra (int8_t __attribute__ ((vector_size(4))));
int8_t __attribute__ ((vector_size(4))) __builtin_mips_shll_qb (int8_t __attribute__ ((vector_size(4))), int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_shll_ph (int16_t __attribute__ ((vector_size(4))), int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_shll_s_ph (int16_t __attribute__ ((vector_size(4))), int32_t);
int32_t __builtin_mips_shll_s_w (int32_t, int32_t);
int8_t __attribute__ ((vector_size(4))) __builtin_mips_shrl_qb (int8_t __attribute__ ((vector_size(4))), int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_shra_ph (int16_t __attribute__ ((vector_size(4))), int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_shra_r_ph (int16_t __attribute__ ((vector_size(4))), int32_t);
int32_t __builtin_mips_shra_r_w (int32_t, int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_muleu_s_ph_qbl (int8_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_muleu_s_ph_qbr (int8_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_mulq_rs_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_muleq_s_w_phl (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_muleq_s_w_phr (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_bitrev (int32_t);
int32_t __builtin_mips_insv (int32_t, int32_t);
int8_t __attribute__ ((vector_size(4))) __builtin_mips_repl_qb (int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_repl_ph (int32_t);
void __builtin_mips_cmpu_eq_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
void __builtin_mips_cmpu_lt_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
void __builtin_mips_cmpu_le_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_cmpgu_eq_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_cmpgu_lt_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_cmpgu_le_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
void __builtin_mips_cmp_eq_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
void __builtin_mips_cmp_lt_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
void __builtin_mips_cmp_le_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int8_t __attribute__ ((vector_size(4))) __builtin_mips_pick_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_pick_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_packrl_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
void __builtin_mips_wrdsp (int32_t, int32_t);
int32_t __builtin_mips_rddsp (int32_t);
int32_t __builtin_mips_lbux (void *, int32_t);
int32_t __builtin_mips_lhx (void *, int32_t);
int32_t __builtin_mips_lwx (void *, int32_t);
int8_t __attribute__ ((vector_size(4))) __builtin_mips_absq_s_qb (int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_addu_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_addu_s_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int8_t __attribute__ ((vector_size(4))) __builtin_mips_adduh_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int8_t __attribute__ ((vector_size(4))) __builtin_mips_adduh_r_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_append (int32_t, int32_t, int32_t);
int32_t __builtin_mips_balign (int32_t, int32_t, int32_t);
int32_t __builtin_mips_cmpgdu_eq_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_cmpgdu_lt_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_cmpgdu_le_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_mul_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_mul_s_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_mulq_rs_w (int32_t, int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_mulq_s_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_mulq_s_w (int32_t, int32_t);
int8_t __attribute__ ((vector_size(4))) __builtin_mips_precr_qb_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_precr_sra_ph_w (int32_t, int32_t, int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_precr_sra_r_ph_w (int32_t, int32_t, int32_t);
int32_t __builtin_mips_prepend (int32_t, int32_t, int32_t);
int8_t __attribute__ ((vector_size(4))) __builtin_mips_shra_qb (int8_t __attribute__ ((vector_size(4))), int32_t);
int8_t __attribute__ ((vector_size(4))) __builtin_mips_shra_r_qb (int8_t __attribute__ ((vector_size(4))), int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_shrl_ph (int16_t __attribute__ ((vector_size(4))), int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_subu_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_subu_s_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int8_t __attribute__ ((vector_size(4))) __builtin_mips_subuh_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int8_t __attribute__ ((vector_size(4))) __builtin_mips_subuh_r_qb (int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_addqh_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_addqh_r_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_addqh_w (int32_t, int32_t);
int32_t __builtin_mips_addqh_r_w (int32_t, int32_t);
int16_t __attribute__ ((vector_size(4))) __builtin_mips_subqh_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int16_t __attribute__ ((vector_size(4))) __builtin_mips_subqh_r_ph (int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_subqh_w (int32_t, int32_t);
int32_t __builtin_mips_subqh_r_w (int32_t, int32_t);
int64_t __builtin_mips_dpau_h_qbl (int64_t, int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpau_h_qbr (int64_t, int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpsu_h_qbl (int64_t, int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpsu_h_qbr (int64_t, int8_t __attribute__ ((vector_size(4))), int8_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpaq_s_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpsq_s_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_mulsaq_s_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpaq_sa_l_w (int64_t, int32_t, int32_t);
int64_t __builtin_mips_dpsq_sa_l_w (int64_t, int32_t, int32_t);
int64_t __builtin_mips_maq_s_w_phl (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_maq_s_w_phr (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_maq_sa_w_phl (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_maq_sa_w_phr (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int32_t __builtin_mips_extr_w (int64_t, int32_t);
int32_t __builtin_mips_extr_r_w (int64_t, int32_t);
int32_t __builtin_mips_extr_rs_w (int64_t, int32_t);
int32_t __builtin_mips_extr_s_h (int64_t, int32_t);
int32_t __builtin_mips_extp (int64_t, int32_t);
int32_t __builtin_mips_extpdp (int64_t, int32_t);
int64_t __builtin_mips_shilo (int64_t, int32_t);
int64_t __builtin_mips_mthlip (int64_t, int32_t);
int64_t __builtin_mips_madd (int64_t, int32_t, int32_t);
int64_t __builtin_mips_maddu (int64_t, uint32_t, uint32_t);
int64_t __builtin_mips_msub (int64_t, int32_t, int32_t);
int64_t __builtin_mips_msubu (int64_t, uint32_t, uint32_t);
int64_t __builtin_mips_mult (int32_t, int32_t);
int64_t __builtin_mips_multu (uint32_t, uint32_t);
int64_t __builtin_mips_dpa_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dps_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_mulsa_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpax_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpsx_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpaqx_s_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpaqx_sa_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpsqx_s_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
int64_t __builtin_mips_dpsqx_sa_w_ph (int64_t, int16_t __attribute__ ((vector_size(4))), int16_t __attribute__ ((vector_size(4))));
void __builtin_mips_cache (int32_t, const volatile void *);
uint32_t __builtin_mfc0 (uint32_t, uint32_t);
void __builtin_mtc0 (uint32_t, uint32_t, uint32_t);
uint32_t __builtin_mxc0 (uint32_t, uint32_t, uint32_t);
uint32_t __builtin_bcc0 (uint32_t, uint32_t, uint32_t);
uint32_t __builtin_bsc0 (uint32_t, uint32_t, uint32_t);
uint32_t __builtin_bcsc0 (uint32_t, uint32_t, uint32_t, uint32_t);
uint32_t __builtin_unique_id (const int8_t * , int32_t);
uint32_t __builtin_section_begin (const int8_t * );
uint32_t __builtin_section_end (const int8_t * );
uint32_t __builtin_section_size (const int8_t * );
uint32_t __builtin_get_isr_state (void);
void __builtin_set_isr_state (uint32_t);
uint32_t __builtin_disable_interrupts (void);
uint32_t __builtin_enable_interrupts (void);
void __builtin_software_breakpoint (void);

#endif /* __cplusplus */
#endif /* _PIC32M_BUILTINS_H */
