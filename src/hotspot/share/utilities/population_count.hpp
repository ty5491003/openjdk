/*
 * Copyright (c) 2019, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_UTILITIES_POPULATION_COUNT_HPP
#define SHARE_UTILITIES_POPULATION_COUNT_HPP

#include "utilities/debug.hpp"
#include "utilities/globalDefinitions.hpp"

// Returns the population count of x, i.e., the number of bits set in x.
//
// Adapted from Hacker's Delight, 2nd Edition, Figure 5-2.
//
// Ideally this should be dispatched per platform to use optimized
// instructions when available, such as POPCNT on modern x86/AMD. Our builds
// still target and support older architectures that might lack support for
// these, however. For example, with current build configurations,
// __builtin_popcount(x) would generate a call to a similar but slower 64-bit
// version of this 32-bit implementation.
static uint32_t population_count(uint32_t x) {
  x -= ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  return (((x + (x >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

#endif // SHARE_UTILITIES_POPULATION_COUNT_HPP
