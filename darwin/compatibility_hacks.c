/*
 * Copyright (c) 2016 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 * 
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#if !TARGET_OS_IPHONE

#define WEAK_SYMBOL_LD_CMD(sym, version) \
        __asm__(".section __TEXT,__const\n\t" \
                ".globl $ld$weak$os" #version "$_" #sym "\n\t" \
                "$ld$weak$os" #version "$_" #sym ":\n\t" \
                "    .byte 0\n\t" \
                ".previous")

#define ADDED_IN_10_12(sym) WEAK_SYMBOL_LD_CMD(sym, 10.11)
#define ADDED_IN_10_13(sym) WEAK_SYMBOL_LD_CMD(sym, 10.12)

ADDED_IN_10_12(getentropy);

ADDED_IN_10_12(clock_getres);
ADDED_IN_10_12(clock_gettime);
ADDED_IN_10_12(clock_settime);

ADDED_IN_10_12(basename_r);
ADDED_IN_10_12(dirname_r);

ADDED_IN_10_12(mkostemp);
ADDED_IN_10_12(mkostemps);

ADDED_IN_10_12(timingsafe_bcmp);

ADDED_IN_10_13(utimensat);

#endif /* TARGET_OS_IPHONE */
