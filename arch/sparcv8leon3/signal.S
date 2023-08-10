/*
 * Phoenix-RTOS
 *
 * libphoenix
 *
 * Signal trampoline (sparcv8leon3)
 *
 * Copyright 2022 Phoenix Systems
 * Author: Lukasz Leczkowski
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */


#define __ASSEMBLY__


.section ".text"
.align 4

.globl _signal_trampoline
.type _signal_trampoline, #function
_signal_trampoline:
	save %sp, -0x60, %sp

	call _signal_handler
	ld [%i0], %o0 /* signal number */

	/* oldmask in %o0 */
	ld [%i0 + 0x04], %o1 /* cpu_context * */
	ldd [%i0 + 0x08], %o2 /* pc, sp */
	call sigreturn
	ld  [%i0 + 0x10], %o4 /* psr */
.size _signal_trampoline, .-_signal_trampoline
