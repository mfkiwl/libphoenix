/*
 * Phoenix-RTOS
 *
 * libphoenix
 *
 * Architecture dependent part (arch/armv7r)
 *
 * Copyright 2017, 2024 Phoenix Systems
 * Author: Pawel Pisarczyk, Lukasz Leczkowski
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */

#ifndef _LIBPHOENIX_ARCH_ARMV7R_ARCH_H_
#define _LIBPHOENIX_ARCH_ARMV7R_ARCH_H_

#define __ARCH_STDINT <arch/armv7r/stdint.h>
#define __ARCH_LIMITS <arch/armv7r/limits.h>

#define __MEMCPY
#define __MEMCMP
#define __MEMSET
#define __STRLEN
#define __STRNLEN
#define __STRCMP
#define __STRNCMP
#define __STRCPY
#define __STRNCPY
#define __MEMMOVE


#if defined(__ARM_PCS_VFP) || (defined(__VFP_FP__) && !defined(__SOFTFP__))
#if defined(__ARM_FP) && (__ARM_FP & 8) != 0
#define __IEEE754_SQRT
#define __ieee754_sqrt(x) ({ double a = (x); __asm__ volatile ("vsqrt.f64 %P0, %P1" : "=w"(a) : "w"(a)); a; })
#endif

#define __IEEE754_SQRTF
#define __ieee754_sqrtf(x) ({ float a = (x); __asm__ volatile ("vsqrt.f32 %0, %1" : "=t"(a) : "t"(a)); a; })
#endif


#define _PAGE_SIZE 0x1000
#define SIZE_PAGE  _Pragma("GCC warning \"'SIZE_PAGE' is deprecated. Use _PAGE_SIZE from arch.h or PAGE_SIZE from limits.h (POSIX only)\"") _PAGE_SIZE

#define __LIBPHOENIX_ARCH_TLS_SUPPORTED

#endif
