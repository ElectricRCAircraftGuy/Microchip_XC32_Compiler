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
 *         with the distribution.
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


#ifndef _PIC32C_BUILTINS_H
#define _PIC32C_BUILTINS_H 1

#ifndef __cplusplus

#include <stdint.h>

uint32_t  __builtin_arm_ldfscr(
        void);
void  __builtin_arm_stfscr(
        uint32_t);
uint32_t  __builtin_arm_cmse_nonsecure_caller(
        void);
#ifdef __ARM_FP
__simd128_uint8_t  __builtin_arm_crypto_aesd(
        __simd128_uint8_t,
        __simd128_uint8_t);
__simd128_uint8_t  __builtin_arm_crypto_aese(
        __simd128_uint8_t,
        __simd128_uint8_t);
__simd128_uint8_t  __builtin_arm_crypto_aesimc(
        __simd128_uint8_t);
__simd128_uint8_t  __builtin_arm_crypto_aesmc(
        __simd128_uint8_t);
__simd128_uint32_t  __builtin_arm_crypto_sha1h(
        __simd128_uint32_t);
__simd128_uint32_t  __builtin_arm_crypto_sha1su1(
        __simd128_uint32_t,
        __simd128_uint32_t);
__simd128_uint32_t  __builtin_arm_crypto_sha256su0(
        __simd128_uint32_t,
        __simd128_uint32_t);
__simd128_uint32_t  __builtin_arm_crypto_sha1c(
        __simd128_uint32_t,
        __simd128_uint32_t,
        __simd128_uint32_t);
__simd128_uint32_t  __builtin_arm_crypto_sha1m(
        __simd128_uint32_t,
        __simd128_uint32_t,
        __simd128_uint32_t);
__simd128_uint32_t  __builtin_arm_crypto_sha1p(
        __simd128_uint32_t,
        __simd128_uint32_t,
        __simd128_uint32_t);
__simd128_uint32_t  __builtin_arm_crypto_sha1su0(
        __simd128_uint32_t,
        __simd128_uint32_t,
        __simd128_uint32_t);
__simd128_uint32_t  __builtin_arm_crypto_sha256h(
        __simd128_uint32_t,
        __simd128_uint32_t,
        __simd128_uint32_t);
__simd128_uint32_t  __builtin_arm_crypto_sha256h2(
        __simd128_uint32_t,
        __simd128_uint32_t,
        __simd128_uint32_t);
__simd128_uint32_t  __builtin_arm_crypto_sha256su1(
        __simd128_uint32_t,
        __simd128_uint32_t,
        __simd128_uint32_t);
#endif /* __ARM_FP */
void  __builtin_arm_lane_check(
        int32_t,
        int32_t);
#ifdef __ARM_FP
__simd64_float32_t  __builtin_neon_vaddv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vaddv4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd128_int16_t  __builtin_neon_vaddlsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vaddlsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vaddlsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vaddluv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vaddluv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vaddluv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vaddwsv8qi(
        __simd128_int16_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vaddwsv4hi(
        __simd128_int32_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vaddwsv2si(
        __simd128_int64_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vaddwuv8qi(
        __simd128_int16_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vaddwuv4hi(
        __simd128_int32_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vaddwuv2si(
        __simd128_int64_t,
        __simd64_int32_t);
__simd64_int8_t  __builtin_neon_vhadduv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vhadduv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vhadduv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vhadduv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vhadduv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vhadduv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vhaddsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vhaddsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vhaddsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vhaddsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vhaddsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vhaddsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vrhadduv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vrhadduv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vrhadduv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vrhadduv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vrhadduv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vrhadduv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vrhaddsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vrhaddsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vrhaddsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vrhaddsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vrhaddsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vrhaddsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vqaddsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vqaddsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqaddsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vqaddsdi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vqaddsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vqaddsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqaddsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vqaddsv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vqadduv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vqadduv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqadduv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vqaddudi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vqadduv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vqadduv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqadduv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vqadduv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vaddhnv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd64_int16_t  __builtin_neon_vaddhnv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int32_t  __builtin_neon_vaddhnv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vraddhnv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd64_int16_t  __builtin_neon_vraddhnv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int32_t  __builtin_neon_vraddhnv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_float32_t  __builtin_neon_vmulfv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vmulfv4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vmulpv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int8_t  __builtin_neon_vmulpv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd64_int8_t  __builtin_neon_vmlav8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vmlav4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vmlav2si(
        __simd64_int32_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vmlav2sf(
        __simd64_float32_t,
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_int8_t  __builtin_neon_vmlav16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vmlav8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vmlav4si(
        __simd128_int32_t,
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_float32_t  __builtin_neon_vmlav4sf(
        __simd128_float32_t,
        __simd128_float32_t,
        __simd128_float32_t);
__simd128_int16_t  __builtin_neon_vmlalsv8qi(
        __simd128_int16_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vmlalsv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vmlalsv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vmlaluv8qi(
        __simd128_int16_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vmlaluv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vmlaluv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vfmav2sf(
        __simd64_float32_t,
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vfmav4sf(
        __simd128_float32_t,
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_float32_t  __builtin_neon_vfmsv2sf(
        __simd64_float32_t,
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vfmsv4sf(
        __simd128_float32_t,
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vmlsv8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vmlsv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vmlsv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vmlsv2sf(
        __simd64_float32_t,
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_int8_t  __builtin_neon_vmlsv16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vmlsv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vmlsv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_float32_t  __builtin_neon_vmlsv4sf(
        __simd128_float32_t,
        __simd128_float32_t,
        __simd128_float32_t);
__simd128_int16_t  __builtin_neon_vmlslsv8qi(
        __simd128_int16_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vmlslsv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vmlslsv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vmlsluv8qi(
        __simd128_int16_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vmlsluv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vmlsluv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_int16_t  __builtin_neon_vqdmulhv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqdmulhv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vqdmulhv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqdmulhv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int16_t  __builtin_neon_vqrdmulhv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqrdmulhv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vqrdmulhv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqrdmulhv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int32_t  __builtin_neon_vqdmlalv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vqdmlalv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int32_t  __builtin_neon_vqdmlslv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vqdmlslv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_int16_t  __builtin_neon_vqrdmlahv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqrdmlahv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vqrdmlahv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqrdmlahv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int16_t  __builtin_neon_vqrdmlshv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqrdmlshv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vqrdmlshv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqrdmlshv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int16_t  __builtin_neon_vmullpv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vmullpv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vmullpv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vmullsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vmullsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vmullsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vmulluv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vmulluv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vmulluv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int32_t  __builtin_neon_vmulls_nv4hi(
        __simd64_int16_t,
        int16_t);
__simd128_int64_t  __builtin_neon_vmulls_nv2si(
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmullu_nv4hi(
        __simd64_int16_t,
        int16_t);
__simd128_int64_t  __builtin_neon_vmullu_nv2si(
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmulls_lanev4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vmulls_lanev2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmullu_lanev4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vmullu_lanev2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqdmull_nv4hi(
        __simd64_int16_t,
        int16_t);
__simd128_int64_t  __builtin_neon_vqdmull_nv2si(
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqdmull_lanev4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vqdmull_lanev2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqdmulh_nv4hi(
        __simd64_int16_t,
        int16_t);
__simd64_int32_t  __builtin_neon_vqdmulh_nv2si(
        __simd64_int32_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vqdmulh_nv8hi(
        __simd128_int16_t,
        int16_t);
__simd128_int32_t  __builtin_neon_vqdmulh_nv4si(
        __simd128_int32_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqrdmulh_nv4hi(
        __simd64_int16_t,
        int16_t);
__simd64_int32_t  __builtin_neon_vqrdmulh_nv2si(
        __simd64_int32_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vqrdmulh_nv8hi(
        __simd128_int16_t,
        int16_t);
__simd128_int32_t  __builtin_neon_vqrdmulh_nv4si(
        __simd128_int32_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqdmulh_lanev4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqdmulh_lanev2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vqdmulh_lanev8hi(
        __simd128_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqdmulh_lanev4si(
        __simd128_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqrdmulh_lanev4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqrdmulh_lanev2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vqrdmulh_lanev8hi(
        __simd128_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqrdmulh_lanev4si(
        __simd128_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqrdmlah_lanev4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqrdmlah_lanev2si(
        __simd64_int32_t,
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vqrdmlah_lanev8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqrdmlah_lanev4si(
        __simd128_int32_t,
        __simd128_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqrdmlsh_lanev4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqrdmlsh_lanev2si(
        __simd64_int32_t,
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vqrdmlsh_lanev8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqrdmlsh_lanev4si(
        __simd128_int32_t,
        __simd128_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqdmullv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vqdmullv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_int8_t  __builtin_neon_vshlsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vshlsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vshlsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vshlsdi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vshlsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vshlsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vshlsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vshlsv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vshluv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vshluv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vshluv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vshludi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vshluv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vshluv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vshluv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vshluv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vrshlsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vrshlsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vrshlsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vrshlsdi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vrshlsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vrshlsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vrshlsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vrshlsv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vrshluv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vrshluv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vrshluv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vrshludi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vrshluv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vrshluv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vrshluv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vrshluv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vqshlsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vqshlsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqshlsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vqshlsdi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vqshlsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vqshlsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqshlsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vqshlsv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vqshluv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vqshluv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqshluv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vqshludi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vqshluv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vqshluv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqshluv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vqshluv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vqrshlsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vqrshlsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqrshlsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vqrshlsdi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vqrshlsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vqrshlsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqrshlsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vqrshlsv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vqrshluv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vqrshluv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqrshluv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vqrshludi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vqrshluv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vqrshluv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqrshluv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vqrshluv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vshrs_nv8qi(
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vshrs_nv4hi(
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vshrs_nv2si(
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vshrs_ndi(
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vshrs_nv16qi(
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vshrs_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vshrs_nv4si(
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vshrs_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vshru_nv8qi(
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vshru_nv4hi(
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vshru_nv2si(
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vshru_ndi(
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vshru_nv16qi(
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vshru_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vshru_nv4si(
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vshru_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vrshrs_nv8qi(
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vrshrs_nv4hi(
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vrshrs_nv2si(
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vrshrs_ndi(
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vrshrs_nv16qi(
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vrshrs_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vrshrs_nv4si(
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vrshrs_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vrshru_nv8qi(
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vrshru_nv4hi(
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vrshru_nv2si(
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vrshru_ndi(
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vrshru_nv16qi(
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vrshru_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vrshru_nv4si(
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vrshru_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vshrn_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vshrn_nv4si(
        __simd128_int32_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vshrn_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vrshrn_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vrshrn_nv4si(
        __simd128_int32_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vrshrn_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vqshrns_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqshrns_nv4si(
        __simd128_int32_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqshrns_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vqshrnu_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqshrnu_nv4si(
        __simd128_int32_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqshrnu_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vqrshrns_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqrshrns_nv4si(
        __simd128_int32_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqrshrns_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vqrshrnu_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqrshrnu_nv4si(
        __simd128_int32_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqrshrnu_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vqshrun_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqshrun_nv4si(
        __simd128_int32_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqshrun_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vqrshrun_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqrshrun_nv4si(
        __simd128_int32_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqrshrun_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vshl_nv8qi(
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vshl_nv4hi(
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vshl_nv2si(
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vshl_ndi(
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vshl_nv16qi(
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vshl_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vshl_nv4si(
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vshl_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vqshl_s_nv8qi(
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqshl_s_nv4hi(
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqshl_s_nv2si(
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vqshl_s_ndi(
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vqshl_s_nv16qi(
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vqshl_s_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqshl_s_nv4si(
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vqshl_s_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vqshl_u_nv8qi(
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqshl_u_nv4hi(
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqshl_u_nv2si(
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vqshl_u_ndi(
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vqshl_u_nv16qi(
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vqshl_u_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqshl_u_nv4si(
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vqshl_u_nv2di(
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vqshlu_nv8qi(
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vqshlu_nv4hi(
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vqshlu_nv2si(
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vqshlu_ndi(
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vqshlu_nv16qi(
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vqshlu_nv8hi(
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqshlu_nv4si(
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vqshlu_nv2di(
        __simd128_int64_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vshlls_nv8qi(
        __simd64_int8_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vshlls_nv4hi(
        __simd64_int16_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vshlls_nv2si(
        __simd64_int32_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vshllu_nv8qi(
        __simd64_int8_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vshllu_nv4hi(
        __simd64_int16_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vshllu_nv2si(
        __simd64_int32_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vsras_nv8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vsras_nv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vsras_nv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vsras_ndi(
        int64_t,
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vsras_nv16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vsras_nv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vsras_nv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vsras_nv2di(
        __simd128_int64_t,
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vsrau_nv8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vsrau_nv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vsrau_nv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vsrau_ndi(
        int64_t,
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vsrau_nv16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vsrau_nv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vsrau_nv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vsrau_nv2di(
        __simd128_int64_t,
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vrsras_nv8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vrsras_nv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vrsras_nv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vrsras_ndi(
        int64_t,
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vrsras_nv16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vrsras_nv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vrsras_nv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vrsras_nv2di(
        __simd128_int64_t,
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vrsrau_nv8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vrsrau_nv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vrsrau_nv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vrsrau_ndi(
        int64_t,
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vrsrau_nv16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vrsrau_nv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vrsrau_nv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vrsrau_nv2di(
        __simd128_int64_t,
        __simd128_int64_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vsubv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vsubv4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd128_int16_t  __builtin_neon_vsublsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vsublsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vsublsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vsubluv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vsubluv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vsubluv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vsubwsv8qi(
        __simd128_int16_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vsubwsv4hi(
        __simd128_int32_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vsubwsv2si(
        __simd128_int64_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vsubwuv8qi(
        __simd128_int16_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vsubwuv4hi(
        __simd128_int32_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vsubwuv2si(
        __simd128_int64_t,
        __simd64_int32_t);
__simd64_int8_t  __builtin_neon_vqsubsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vqsubsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqsubsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vqsubsdi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vqsubsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vqsubsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqsubsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vqsubsv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vqsubuv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vqsubuv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqsubuv2si(
        __simd64_int32_t,
        __simd64_int32_t);
int64_t  __builtin_neon_vqsubudi(
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vqsubuv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vqsubuv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqsubuv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int64_t  __builtin_neon_vqsubuv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vhsubsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vhsubsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vhsubsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vhsubsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vhsubsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vhsubsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vhsubuv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vhsubuv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vhsubuv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vhsubuv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vhsubuv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vhsubuv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vsubhnv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd64_int16_t  __builtin_neon_vsubhnv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int32_t  __builtin_neon_vsubhnv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vrsubhnv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd64_int16_t  __builtin_neon_vrsubhnv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int32_t  __builtin_neon_vrsubhnv2di(
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vceqv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vceqv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vceqv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_int32_t  __builtin_neon_vceqv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_int8_t  __builtin_neon_vceqv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vceqv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vceqv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int32_t  __builtin_neon_vceqv4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vcgev8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vcgev4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vcgev2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_int32_t  __builtin_neon_vcgev2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_int8_t  __builtin_neon_vcgev16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vcgev8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vcgev4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int32_t  __builtin_neon_vcgev4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vcgeuv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vcgeuv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vcgeuv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vcgeuv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vcgeuv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vcgeuv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vcgtv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vcgtv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vcgtv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_int32_t  __builtin_neon_vcgtv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_int8_t  __builtin_neon_vcgtv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vcgtv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vcgtv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int32_t  __builtin_neon_vcgtv4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vcgtuv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vcgtuv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vcgtuv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vcgtuv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vcgtuv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vcgtuv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int32_t  __builtin_neon_vcagev2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_int32_t  __builtin_neon_vcagev4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_int32_t  __builtin_neon_vcagtv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_int32_t  __builtin_neon_vcagtv4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vtstv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vtstv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vtstv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vtstv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vtstv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vtstv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vabdsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vabdsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vabdsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vabdsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vabdsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vabdsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vabduv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vabduv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vabduv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vabduv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vabduv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vabduv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_float32_t  __builtin_neon_vabdfv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vabdfv4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd128_int16_t  __builtin_neon_vabdlsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vabdlsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vabdlsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vabdluv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vabdluv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vabdluv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_int8_t  __builtin_neon_vabasv8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vabasv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vabasv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vabasv16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vabasv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vabasv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vabauv8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vabauv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vabauv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vabauv16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vabauv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vabauv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_int16_t  __builtin_neon_vabalsv8qi(
        __simd128_int16_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vabalsv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vabalsv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vabaluv8qi(
        __simd128_int16_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vabaluv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vabaluv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_int8_t  __builtin_neon_vmaxsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vmaxsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vmaxsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vmaxsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vmaxsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vmaxsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vmaxuv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vmaxuv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vmaxuv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vmaxuv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vmaxuv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vmaxuv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_float32_t  __builtin_neon_vmaxfv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vmaxfv4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vminsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vminsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vminsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vminsv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vminsv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vminsv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vminuv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vminuv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vminuv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vminuv16qi(
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vminuv8hi(
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vminuv4si(
        __simd128_int32_t,
        __simd128_int32_t);
__simd64_float32_t  __builtin_neon_vminfv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vminfv4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vpmaxsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vpmaxsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vpmaxsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_int8_t  __builtin_neon_vpmaxuv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vpmaxuv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vpmaxuv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vpmaxfv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd64_int8_t  __builtin_neon_vpminsv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vpminsv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vpminsv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_int8_t  __builtin_neon_vpminuv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vpminuv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vpminuv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vpminfv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd64_int8_t  __builtin_neon_vpaddv8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vpaddv4hi(
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vpaddv2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vpaddv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd64_int16_t  __builtin_neon_vpaddlsv8qi(
        __simd64_int8_t);
__simd64_int32_t  __builtin_neon_vpaddlsv4hi(
        __simd64_int16_t);
int64_t  __builtin_neon_vpaddlsv2si(
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vpaddlsv16qi(
        __simd128_int8_t);
__simd128_int32_t  __builtin_neon_vpaddlsv8hi(
        __simd128_int16_t);
__simd128_int64_t  __builtin_neon_vpaddlsv4si(
        __simd128_int32_t);
__simd64_int16_t  __builtin_neon_vpaddluv8qi(
        __simd64_int8_t);
__simd64_int32_t  __builtin_neon_vpaddluv4hi(
        __simd64_int16_t);
int64_t  __builtin_neon_vpaddluv2si(
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vpaddluv16qi(
        __simd128_int8_t);
__simd128_int32_t  __builtin_neon_vpaddluv8hi(
        __simd128_int16_t);
__simd128_int64_t  __builtin_neon_vpaddluv4si(
        __simd128_int32_t);
__simd64_int16_t  __builtin_neon_vpadalsv8qi(
        __simd64_int16_t,
        __simd64_int8_t);
__simd64_int32_t  __builtin_neon_vpadalsv4hi(
        __simd64_int32_t,
        __simd64_int16_t);
int64_t  __builtin_neon_vpadalsv2si(
        int64_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vpadalsv16qi(
        __simd128_int16_t,
        __simd128_int8_t);
__simd128_int32_t  __builtin_neon_vpadalsv8hi(
        __simd128_int32_t,
        __simd128_int16_t);
__simd128_int64_t  __builtin_neon_vpadalsv4si(
        __simd128_int64_t,
        __simd128_int32_t);
__simd64_int16_t  __builtin_neon_vpadaluv8qi(
        __simd64_int16_t,
        __simd64_int8_t);
__simd64_int32_t  __builtin_neon_vpadaluv4hi(
        __simd64_int32_t,
        __simd64_int16_t);
int64_t  __builtin_neon_vpadaluv2si(
        int64_t,
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vpadaluv16qi(
        __simd128_int16_t,
        __simd128_int8_t);
__simd128_int32_t  __builtin_neon_vpadaluv8hi(
        __simd128_int32_t,
        __simd128_int16_t);
__simd128_int64_t  __builtin_neon_vpadaluv4si(
        __simd128_int64_t,
        __simd128_int32_t);
__simd64_float32_t  __builtin_neon_vrecpsv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vrecpsv4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_float32_t  __builtin_neon_vrsqrtsv2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vrsqrtsv4sf(
        __simd128_float32_t,
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vsri_nv8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vsri_nv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vsri_nv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vsri_ndi(
        int64_t,
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vsri_nv16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vsri_nv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vsri_nv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vsri_nv2di(
        __simd128_int64_t,
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vsli_nv8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vsli_nv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vsli_nv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
int64_t  __builtin_neon_vsli_ndi(
        int64_t,
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vsli_nv16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vsli_nv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vsli_nv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vsli_nv2di(
        __simd128_int64_t,
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vabsv8qi(
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vabsv4hi(
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vabsv2si(
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vabsv2sf(
        __simd64_float32_t);
__simd128_int8_t  __builtin_neon_vabsv16qi(
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vabsv8hi(
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vabsv4si(
        __simd128_int32_t);
__simd128_float32_t  __builtin_neon_vabsv4sf(
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vqabsv8qi(
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vqabsv4hi(
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqabsv2si(
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vqabsv16qi(
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vqabsv8hi(
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqabsv4si(
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vnegv8qi(
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vnegv4hi(
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vnegv2si(
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vnegv2sf(
        __simd64_float32_t);
__simd128_int8_t  __builtin_neon_vnegv16qi(
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vnegv8hi(
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vnegv4si(
        __simd128_int32_t);
__simd128_float32_t  __builtin_neon_vnegv4sf(
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vqnegv8qi(
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vqnegv4hi(
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vqnegv2si(
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vqnegv16qi(
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vqnegv8hi(
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vqnegv4si(
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vclsv8qi(
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vclsv4hi(
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vclsv2si(
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vclsv16qi(
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vclsv8hi(
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vclsv4si(
        __simd128_int32_t);
__simd64_int8_t  __builtin_neon_vclzv8qi(
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vclzv4hi(
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vclzv2si(
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vclzv16qi(
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vclzv8hi(
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vclzv4si(
        __simd128_int32_t);
__simd64_uint16_t  __builtin_neon_bswapv4hi_uu(
        __simd64_uint16_t);
__simd128_uint16_t  __builtin_neon_bswapv8hi_uu(
        __simd128_uint16_t);
__simd64_uint32_t  __builtin_neon_bswapv2si_uu(
        __simd64_uint32_t);
__simd128_uint32_t  __builtin_neon_bswapv4si_uu(
        __simd128_uint32_t);
__simd128_uint64_t  __builtin_neon_bswapv2di_uu(
        __simd128_uint64_t);
__simd64_int8_t  __builtin_neon_vcntv8qi(
        __simd64_int8_t);
__simd128_int8_t  __builtin_neon_vcntv16qi(
        __simd128_int8_t);
__simd64_int32_t  __builtin_neon_vrecpev2si(
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vrecpev2sf(
        __simd64_float32_t);
__simd128_int32_t  __builtin_neon_vrecpev4si(
        __simd128_int32_t);
__simd128_float32_t  __builtin_neon_vrecpev4sf(
        __simd128_float32_t);
__simd64_int32_t  __builtin_neon_vrsqrtev2si(
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vrsqrtev2sf(
        __simd64_float32_t);
__simd128_int32_t  __builtin_neon_vrsqrtev4si(
        __simd128_int32_t);
__simd128_float32_t  __builtin_neon_vrsqrtev4sf(
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vmvnv8qi(
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vmvnv4hi(
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vmvnv2si(
        __simd64_int32_t);
__simd128_int8_t  __builtin_neon_vmvnv16qi(
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vmvnv8hi(
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vmvnv4si(
        __simd128_int32_t);
int32_t  __builtin_neon_vget_lanev8qi(
        __simd64_int8_t,
        int32_t);
int32_t  __builtin_neon_vget_lanev4hi(
        __simd64_int16_t,
        int32_t);
int32_t  __builtin_neon_vget_lanev2si(
        __simd64_int32_t,
        int32_t);
float  __builtin_neon_vget_lanev2sf(
        __simd64_float32_t,
        int32_t);
int64_t  __builtin_neon_vget_lanedi(
        int64_t,
        int32_t);
int32_t  __builtin_neon_vget_lanev16qi(
        __simd128_int8_t,
        int32_t);
int32_t  __builtin_neon_vget_lanev8hi(
        __simd128_int16_t,
        int32_t);
int32_t  __builtin_neon_vget_lanev4si(
        __simd128_int32_t,
        int32_t);
float  __builtin_neon_vget_lanev4sf(
        __simd128_float32_t,
        int32_t);
int64_t  __builtin_neon_vget_lanev2di(
        __simd128_int64_t,
        int32_t);
int32_t  __builtin_neon_vget_laneuv8qi(
        __simd64_int8_t,
        int32_t);
int32_t  __builtin_neon_vget_laneuv4hi(
        __simd64_int16_t,
        int32_t);
int32_t  __builtin_neon_vget_laneuv2si(
        __simd64_int32_t,
        int32_t);
int32_t  __builtin_neon_vget_laneuv16qi(
        __simd128_int8_t,
        int32_t);
int32_t  __builtin_neon_vget_laneuv8hi(
        __simd128_int16_t,
        int32_t);
int32_t  __builtin_neon_vget_laneuv4si(
        __simd128_int32_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vset_lanev8qi(
        int8_t,
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vset_lanev4hi(
        int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vset_lanev2si(
        int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vset_lanev2sf(
        float,
        __simd64_float32_t,
        int32_t);
int64_t  __builtin_neon_vset_lanedi(
        int64_t,
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vset_lanev16qi(
        int8_t,
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vset_lanev8hi(
        int16_t,
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vset_lanev4si(
        int32_t,
        __simd128_int32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vset_lanev4sf(
        float,
        __simd128_float32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vset_lanev2di(
        int64_t,
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vcreatev8qi(
        int64_t);
__simd64_int16_t  __builtin_neon_vcreatev4hi(
        int64_t);
__simd64_int32_t  __builtin_neon_vcreatev2si(
        int64_t);
__simd64_float32_t  __builtin_neon_vcreatev2sf(
        int64_t);
int64_t  __builtin_neon_vcreatedi(
        int64_t);
__simd64_int8_t  __builtin_neon_vdup_nv8qi(
        int8_t);
__simd64_int16_t  __builtin_neon_vdup_nv4hi(
        int16_t);
__simd64_int32_t  __builtin_neon_vdup_nv2si(
        int32_t);
__simd64_float32_t  __builtin_neon_vdup_nv2sf(
        float);
int64_t  __builtin_neon_vdup_ndi(
        int64_t);
__simd128_int8_t  __builtin_neon_vdup_nv16qi(
        int8_t);
__simd128_int16_t  __builtin_neon_vdup_nv8hi(
        int16_t);
__simd128_int32_t  __builtin_neon_vdup_nv4si(
        int32_t);
__simd128_float32_t  __builtin_neon_vdup_nv4sf(
        float);
__simd128_int64_t  __builtin_neon_vdup_nv2di(
        int64_t);
__simd64_int8_t  __builtin_neon_vdup_lanev8qi(
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vdup_lanev4hi(
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vdup_lanev2si(
        __simd64_int32_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vdup_lanev2sf(
        __simd64_float32_t,
        int32_t);
int64_t  __builtin_neon_vdup_lanedi(
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vdup_lanev16qi(
        __simd64_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vdup_lanev8hi(
        __simd64_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vdup_lanev4si(
        __simd64_int32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vdup_lanev4sf(
        __simd64_float32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vdup_lanev2di(
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vcombinev8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd128_int16_t  __builtin_neon_vcombinev4hi(
        __simd64_int16_t,
        __simd64_int16_t);
#if defined (__ARM_FP16_FORMAT_IEEE) || defined (__ARM_FP16_FORMAT_ALTERNATIVE)
__simd128_float16_t  __builtin_neon_vcombinev4hf(
        __simd64_float16_t,
        __simd64_float16_t);
#endif /* __ARM_FP16_FORMAT ... */
__simd128_int32_t  __builtin_neon_vcombinev2si(
        __simd64_int32_t,
        __simd64_int32_t);
__simd128_float32_t  __builtin_neon_vcombinev2sf(
        __simd64_float32_t,
        __simd64_float32_t);
__simd128_int64_t  __builtin_neon_vcombinedi(
        int64_t,
        int64_t);
__simd64_int8_t  __builtin_neon_vget_highv16qi(
        __simd128_int8_t);
__simd64_int16_t  __builtin_neon_vget_highv8hi(
        __simd128_int16_t);
#if defined (__ARM_FP16_FORMAT_IEEE) || defined (__ARM_FP16_FORMAT_ALTERNATIVE)
__simd64_float16_t  __builtin_neon_vget_highv8hf(
        __simd128_float16_t);
#endif /* __ARM_FP16_FORMAT ... */
__simd64_int32_t  __builtin_neon_vget_highv4si(
        __simd128_int32_t);
__simd64_float32_t  __builtin_neon_vget_highv4sf(
        __simd128_float32_t);
int64_t  __builtin_neon_vget_highv2di(
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vget_lowv16qi(
        __simd128_int8_t);
__simd64_int16_t  __builtin_neon_vget_lowv8hi(
        __simd128_int16_t);
#if defined (__ARM_FP16_FORMAT_IEEE) || defined (__ARM_FP16_FORMAT_ALTERNATIVE)
__simd64_float16_t  __builtin_neon_vget_lowv8hf(
        __simd128_float16_t);
#endif /* __ARM_FP16_FORMAT ... */
__simd64_int32_t  __builtin_neon_vget_lowv4si(
        __simd128_int32_t);
__simd64_float32_t  __builtin_neon_vget_lowv4sf(
        __simd128_float32_t);
int64_t  __builtin_neon_vget_lowv2di(
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vmovnv8hi(
        __simd128_int16_t);
__simd64_int16_t  __builtin_neon_vmovnv4si(
        __simd128_int32_t);
__simd64_int32_t  __builtin_neon_vmovnv2di(
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vqmovnsv8hi(
        __simd128_int16_t);
__simd64_int16_t  __builtin_neon_vqmovnsv4si(
        __simd128_int32_t);
__simd64_int32_t  __builtin_neon_vqmovnsv2di(
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vqmovnuv8hi(
        __simd128_int16_t);
__simd64_int16_t  __builtin_neon_vqmovnuv4si(
        __simd128_int32_t);
__simd64_int32_t  __builtin_neon_vqmovnuv2di(
        __simd128_int64_t);
__simd64_int8_t  __builtin_neon_vqmovunv8hi(
        __simd128_int16_t);
__simd64_int16_t  __builtin_neon_vqmovunv4si(
        __simd128_int32_t);
__simd64_int32_t  __builtin_neon_vqmovunv2di(
        __simd128_int64_t);
__simd128_int16_t  __builtin_neon_vmovlsv8qi(
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vmovlsv4hi(
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vmovlsv2si(
        __simd64_int32_t);
__simd128_int16_t  __builtin_neon_vmovluv8qi(
        __simd64_int8_t);
__simd128_int32_t  __builtin_neon_vmovluv4hi(
        __simd64_int16_t);
__simd128_int64_t  __builtin_neon_vmovluv2si(
        __simd64_int32_t);
__simd64_int16_t  __builtin_neon_vmul_lanev4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vmul_lanev2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vmul_lanev2sf(
        __simd64_float32_t,
        __simd64_float32_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vmul_lanev8hi(
        __simd128_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmul_lanev4si(
        __simd128_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vmul_lanev4sf(
        __simd128_float32_t,
        __simd64_float32_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vmla_lanev4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vmla_lanev2si(
        __simd64_int32_t,
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vmla_lanev2sf(
        __simd64_float32_t,
        __simd64_float32_t,
        __simd64_float32_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vmla_lanev8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmla_lanev4si(
        __simd128_int32_t,
        __simd128_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vmla_lanev4sf(
        __simd128_float32_t,
        __simd128_float32_t,
        __simd64_float32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmlals_lanev4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vmlals_lanev2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmlalu_lanev4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vmlalu_lanev2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqdmlal_lanev4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vqdmlal_lanev2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vmls_lanev4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vmls_lanev2si(
        __simd64_int32_t,
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vmls_lanev2sf(
        __simd64_float32_t,
        __simd64_float32_t,
        __simd64_float32_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vmls_lanev8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmls_lanev4si(
        __simd128_int32_t,
        __simd128_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vmls_lanev4sf(
        __simd128_float32_t,
        __simd128_float32_t,
        __simd64_float32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmlsls_lanev4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vmlsls_lanev2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmlslu_lanev4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vmlslu_lanev2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqdmlsl_lanev4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vqdmlsl_lanev2si(
        __simd128_int64_t,
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vmul_nv4hi(
        __simd64_int16_t,
        int16_t);
__simd64_int32_t  __builtin_neon_vmul_nv2si(
        __simd64_int32_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vmul_nv2sf(
        __simd64_float32_t,
        float);
__simd128_int16_t  __builtin_neon_vmul_nv8hi(
        __simd128_int16_t,
        int16_t);
__simd128_int32_t  __builtin_neon_vmul_nv4si(
        __simd128_int32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vmul_nv4sf(
        __simd128_float32_t,
        float);
__simd64_int16_t  __builtin_neon_vmla_nv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int16_t);
__simd64_int32_t  __builtin_neon_vmla_nv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vmla_nv2sf(
        __simd64_float32_t,
        __simd64_float32_t,
        float);
__simd128_int16_t  __builtin_neon_vmla_nv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        int16_t);
__simd128_int32_t  __builtin_neon_vmla_nv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vmla_nv4sf(
        __simd128_float32_t,
        __simd128_float32_t,
        float);
__simd128_int32_t  __builtin_neon_vmlals_nv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        int16_t);
__simd128_int64_t  __builtin_neon_vmlals_nv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmlalu_nv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        int16_t);
__simd128_int64_t  __builtin_neon_vmlalu_nv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqdmlal_nv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        int16_t);
__simd128_int64_t  __builtin_neon_vqdmlal_nv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vmls_nv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int16_t);
__simd64_int32_t  __builtin_neon_vmls_nv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vmls_nv2sf(
        __simd64_float32_t,
        __simd64_float32_t,
        float);
__simd128_int16_t  __builtin_neon_vmls_nv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        int16_t);
__simd128_int32_t  __builtin_neon_vmls_nv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vmls_nv4sf(
        __simd128_float32_t,
        __simd128_float32_t,
        float);
__simd128_int32_t  __builtin_neon_vmlsls_nv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        int16_t);
__simd128_int64_t  __builtin_neon_vmlsls_nv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vmlslu_nv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        int16_t);
__simd128_int64_t  __builtin_neon_vmlslu_nv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vqdmlsl_nv4hi(
        __simd128_int32_t,
        __simd64_int16_t,
        int16_t);
__simd128_int64_t  __builtin_neon_vqdmlsl_nv2si(
        __simd128_int64_t,
        __simd64_int32_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vextv8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vextv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vextv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vextv2sf(
        __simd64_float32_t,
        __simd64_float32_t,
        int32_t);
int64_t  __builtin_neon_vextdi(
        int64_t,
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vextv16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vextv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vextv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vextv4sf(
        __simd128_float32_t,
        __simd128_float32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vextv2di(
        __simd128_int64_t,
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vrev64v8qi(
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vrev64v4hi(
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vrev64v2si(
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vrev64v2sf(
        __simd64_float32_t);
__simd128_int8_t  __builtin_neon_vrev64v16qi(
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vrev64v8hi(
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vrev64v4si(
        __simd128_int32_t);
__simd128_float32_t  __builtin_neon_vrev64v4sf(
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vrev32v8qi(
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vrev32v4hi(
        __simd64_int16_t);
__simd128_int8_t  __builtin_neon_vrev32v16qi(
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vrev32v8hi(
        __simd128_int16_t);
__simd64_int8_t  __builtin_neon_vrev16v8qi(
        __simd64_int8_t);
__simd128_int8_t  __builtin_neon_vrev16v16qi(
        __simd128_int8_t);
__simd64_float32_t  __builtin_neon_vcvtsv2si(
        __simd64_int32_t);
__simd64_int32_t  __builtin_neon_vcvtsv2sf(
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vcvtsv4si(
        __simd128_int32_t);
__simd128_int32_t  __builtin_neon_vcvtsv4sf(
        __simd128_float32_t);
__simd64_float32_t  __builtin_neon_vcvtuv2si(
        __simd64_int32_t);
__simd64_int32_t  __builtin_neon_vcvtuv2sf(
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vcvtuv4si(
        __simd128_int32_t);
__simd128_int32_t  __builtin_neon_vcvtuv4sf(
        __simd128_float32_t);
__simd64_float32_t  __builtin_neon_vcvts_nv2si(
        __simd64_int32_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vcvts_nv2sf(
        __simd64_float32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vcvts_nv4si(
        __simd128_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vcvts_nv4sf(
        __simd128_float32_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vcvtu_nv2si(
        __simd64_int32_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vcvtu_nv2sf(
        __simd64_float32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vcvtu_nv4si(
        __simd128_int32_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vcvtu_nv4sf(
        __simd128_float32_t,
        int32_t);
#if defined (__ARM_FP16_FORMAT_IEEE) || defined (__ARM_FP16_FORMAT_ALTERNATIVE)
__simd128_float32_t  __builtin_neon_vcvtv4sfv4hf(
        __simd64_float16_t);
__simd64_float16_t  __builtin_neon_vcvtv4hfv4sf(
        __simd128_float32_t);
#endif /* __ARM_FP16_FORMAT ... */
__simd64_int8_t  __builtin_neon_vbslv8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int16_t  __builtin_neon_vbslv4hi(
        __simd64_int16_t,
        __simd64_int16_t,
        __simd64_int16_t);
__simd64_int32_t  __builtin_neon_vbslv2si(
        __simd64_int32_t,
        __simd64_int32_t,
        __simd64_int32_t);
__simd64_float32_t  __builtin_neon_vbslv2sf(
        __simd64_int32_t,
        __simd64_float32_t,
        __simd64_float32_t);
int64_t  __builtin_neon_vbsldi(
        int64_t,
        int64_t,
        int64_t);
__simd128_int8_t  __builtin_neon_vbslv16qi(
        __simd128_int8_t,
        __simd128_int8_t,
        __simd128_int8_t);
__simd128_int16_t  __builtin_neon_vbslv8hi(
        __simd128_int16_t,
        __simd128_int16_t,
        __simd128_int16_t);
__simd128_int32_t  __builtin_neon_vbslv4si(
        __simd128_int32_t,
        __simd128_int32_t,
        __simd128_int32_t);
__simd128_float32_t  __builtin_neon_vbslv4sf(
        __simd128_int32_t,
        __simd128_float32_t,
        __simd128_float32_t);
__simd128_int64_t  __builtin_neon_vbslv2di(
        __simd128_int64_t,
        __simd128_int64_t,
        __simd128_int64_t);
__simd64_float32_t  __builtin_neon_copysignfv2sf(
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_copysignfv4sf(
        __simd128_float32_t);
__simd64_float32_t  __builtin_neon_vrintnv2sf(
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vrintnv4sf(
        __simd128_float32_t);
__simd64_float32_t  __builtin_neon_vrintav2sf(
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vrintav4sf(
        __simd128_float32_t);
__simd64_float32_t  __builtin_neon_vrintpv2sf(
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vrintpv4sf(
        __simd128_float32_t);
__simd64_float32_t  __builtin_neon_vrintmv2sf(
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vrintmv4sf(
        __simd128_float32_t);
__simd64_float32_t  __builtin_neon_vrintzv2sf(
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vrintzv4sf(
        __simd128_float32_t);
__simd64_float32_t  __builtin_neon_vrintxv2sf(
        __simd64_float32_t);
__simd128_float32_t  __builtin_neon_vrintxv4sf(
        __simd128_float32_t);
__simd64_int32_t  __builtin_neon_vcvtav2sfv2si(
        __simd64_float32_t);
__simd128_int32_t  __builtin_neon_vcvtav4sfv4si(
        __simd128_float32_t);
__simd64_int32_t  __builtin_neon_vcvtauv2sfv2si(
        __simd64_float32_t);
__simd128_int32_t  __builtin_neon_vcvtauv4sfv4si(
        __simd128_float32_t);
__simd64_int32_t  __builtin_neon_vcvtpv2sfv2si(
        __simd64_float32_t);
__simd128_int32_t  __builtin_neon_vcvtpv4sfv4si(
        __simd128_float32_t);
__simd64_int32_t  __builtin_neon_vcvtpuv2sfv2si(
        __simd64_float32_t);
__simd128_int32_t  __builtin_neon_vcvtpuv4sfv4si(
        __simd128_float32_t);
__simd64_int32_t  __builtin_neon_vcvtmv2sfv2si(
        __simd64_float32_t);
__simd128_int32_t  __builtin_neon_vcvtmv4sfv4si(
        __simd128_float32_t);
__simd64_int32_t  __builtin_neon_vcvtmuv2sfv2si(
        __simd64_float32_t);
__simd128_int32_t  __builtin_neon_vcvtmuv4sfv4si(
        __simd128_float32_t);
__simd64_int8_t  __builtin_neon_vtbl1v8qi(
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int8_t  __builtin_neon_vtbx1v8qi(
        __simd64_int8_t,
        __simd64_int8_t,
        __simd64_int8_t);
__simd64_int8_t  __builtin_neon_vld1v8qi(
        const int8_t *);
__simd64_int16_t  __builtin_neon_vld1v4hi(
        const int16_t *);
__simd64_int32_t  __builtin_neon_vld1v2si(
        const int32_t *);
__simd64_float32_t  __builtin_neon_vld1v2sf(
        const float *);
int64_t  __builtin_neon_vld1di(
        const int64_t *);
__simd128_int8_t  __builtin_neon_vld1v16qi(
        const int8_t *);
__simd128_int16_t  __builtin_neon_vld1v8hi(
        const int16_t *);
__simd128_int32_t  __builtin_neon_vld1v4si(
        const int32_t *);
__simd128_float32_t  __builtin_neon_vld1v4sf(
        const float *);
__simd128_int64_t  __builtin_neon_vld1v2di(
        const int64_t *);
__simd64_int8_t  __builtin_neon_vld1_lanev8qi(
        const int8_t *,
        __simd64_int8_t,
        int32_t);
__simd64_int16_t  __builtin_neon_vld1_lanev4hi(
        const int16_t *,
        __simd64_int16_t,
        int32_t);
__simd64_int32_t  __builtin_neon_vld1_lanev2si(
        const int32_t *,
        __simd64_int32_t,
        int32_t);
__simd64_float32_t  __builtin_neon_vld1_lanev2sf(
        const float *,
        __simd64_float32_t,
        int32_t);
int64_t  __builtin_neon_vld1_lanedi(
        const int64_t *,
        int64_t,
        int32_t);
__simd128_int8_t  __builtin_neon_vld1_lanev16qi(
        const int8_t *,
        __simd128_int8_t,
        int32_t);
__simd128_int16_t  __builtin_neon_vld1_lanev8hi(
        const int16_t *,
        __simd128_int16_t,
        int32_t);
__simd128_int32_t  __builtin_neon_vld1_lanev4si(
        const int32_t *,
        __simd128_int32_t,
        int32_t);
__simd128_float32_t  __builtin_neon_vld1_lanev4sf(
        const float *,
        __simd128_float32_t,
        int32_t);
__simd128_int64_t  __builtin_neon_vld1_lanev2di(
        const int64_t *,
        __simd128_int64_t,
        int32_t);
__simd64_int8_t  __builtin_neon_vld1_dupv8qi(
        const int8_t *);
__simd64_int16_t  __builtin_neon_vld1_dupv4hi(
        const int16_t *);
__simd64_int32_t  __builtin_neon_vld1_dupv2si(
        const int32_t *);
__simd64_float32_t  __builtin_neon_vld1_dupv2sf(
        const float *);
int64_t  __builtin_neon_vld1_dupdi(
        const int64_t *);
__simd128_int8_t  __builtin_neon_vld1_dupv16qi(
        const int8_t *);
__simd128_int16_t  __builtin_neon_vld1_dupv8hi(
        const int16_t *);
__simd128_int32_t  __builtin_neon_vld1_dupv4si(
        const int32_t *);
__simd128_float32_t  __builtin_neon_vld1_dupv4sf(
        const float *);
__simd128_int64_t  __builtin_neon_vld1_dupv2di(
        const int64_t *);
void  __builtin_neon_vst1v8qi(
        int8_t *,
        __simd64_int8_t);
void  __builtin_neon_vst1v4hi(
        int16_t *,
        __simd64_int16_t);
void  __builtin_neon_vst1v2si(
        int32_t *,
        __simd64_int32_t);
void  __builtin_neon_vst1v2sf(
        float *,
        __simd64_float32_t);
void  __builtin_neon_vst1di(
        int64_t *,
        int64_t);
void  __builtin_neon_vst1v16qi(
        int8_t *,
        __simd128_int8_t);
void  __builtin_neon_vst1v8hi(
        int16_t *,
        __simd128_int16_t);
void  __builtin_neon_vst1v4si(
        int32_t *,
        __simd128_int32_t);
void  __builtin_neon_vst1v4sf(
        float *,
        __simd128_float32_t);
void  __builtin_neon_vst1v2di(
        int64_t *,
        __simd128_int64_t);
void  __builtin_neon_vst1_lanev8qi(
        int8_t *,
        __simd64_int8_t,
        int32_t);
void  __builtin_neon_vst1_lanev4hi(
        int16_t *,
        __simd64_int16_t,
        int32_t);
void  __builtin_neon_vst1_lanev2si(
        int32_t *,
        __simd64_int32_t,
        int32_t);
void  __builtin_neon_vst1_lanev2sf(
        float *,
        __simd64_float32_t,
        int32_t);
void  __builtin_neon_vst1_lanedi(
        int64_t *,
        int64_t,
        int32_t);
void  __builtin_neon_vst1_lanev16qi(
        int8_t *,
        __simd128_int8_t,
        int32_t);
void  __builtin_neon_vst1_lanev8hi(
        int16_t *,
        __simd128_int16_t,
        int32_t);
void  __builtin_neon_vst1_lanev4si(
        int32_t *,
        __simd128_int32_t,
        int32_t);
void  __builtin_neon_vst1_lanev4sf(
        float *,
        __simd128_float32_t,
        int32_t);
void  __builtin_neon_vst1_lanev2di(
        int64_t *,
        __simd128_int64_t,
        int32_t);
#endif /* __ARM_FP */
uint32_t  __builtin_arm_crc32b(
        uint32_t,
        uint8_t);
uint32_t  __builtin_arm_crc32h(
        uint32_t,
        uint16_t);
uint32_t  __builtin_arm_crc32w(
        uint32_t,
        uint32_t);
uint32_t  __builtin_arm_crc32cb(
        uint32_t,
        uint8_t);
uint32_t  __builtin_arm_crc32ch(
        uint32_t,
        uint16_t);
uint32_t  __builtin_arm_crc32cw(
        uint32_t,
        uint32_t);
void  __builtin_arm_cdp(
        uint32_t,
        uint32_t,
        uint32_t,
        uint32_t,
        uint32_t,
        uint32_t);
void  __builtin_arm_cdp2(
        uint32_t,
        uint32_t,
        uint32_t,
        uint32_t,
        uint32_t,
        uint32_t);
void  __builtin_arm_ldc(
        uint32_t,
        uint32_t,
        const int32_t *);
void  __builtin_arm_ldc2(
        uint32_t,
        uint32_t,
        const int32_t *);
void  __builtin_arm_ldcl(
        uint32_t,
        uint32_t,
        const int32_t *);
void  __builtin_arm_ldc2l(
        uint32_t,
        uint32_t,
        const int32_t *);
void  __builtin_arm_stc(
        uint32_t,
        uint32_t,
        int32_t *);
void  __builtin_arm_stc2(
        uint32_t,
        uint32_t,
        int32_t *);
void  __builtin_arm_stcl(
        uint32_t,
        uint32_t,
        int32_t *);
void  __builtin_arm_stc2l(
        uint32_t,
        uint32_t,
        int32_t *);
void  __builtin_arm_mcr(
        uint32_t,
        uint32_t,
        int32_t,
        uint32_t,
        uint32_t,
        uint32_t);
void  __builtin_arm_mcr2(
        uint32_t,
        uint32_t,
        int32_t,
        uint32_t,
        uint32_t,
        uint32_t);
int32_t  __builtin_arm_mrc(
        uint32_t,
        uint32_t,
        uint32_t,
        uint32_t,
        uint32_t);
int32_t  __builtin_arm_mrc2(
        uint32_t,
        uint32_t,
        uint32_t,
        uint32_t,
        uint32_t);
void  __builtin_arm_mcrr(
        uint32_t,
        uint32_t,
        int64_t,
        uint32_t);
void  __builtin_arm_mcrr2(
        uint32_t,
        uint32_t,
        int64_t,
        uint32_t);
int64_t  __builtin_arm_mrrc(
        uint32_t,
        uint32_t,
        uint32_t);
int64_t  __builtin_arm_mrrc2(
        uint32_t,
        uint32_t,
        uint32_t);
void  __builtin_nop(
        void);
void  __builtin_software_breakpoint(
        void);

#endif /* __cplusplus */
#endif /* _PIC32C_BUILTINS_H */ 
