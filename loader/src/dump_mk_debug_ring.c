/**
 * @copyright
 * Copyright (C) 2020 Assured Information Security, Inc.
 *
 * @copyright
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * @copyright
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * @copyright
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <debug.h>
#include <debug_ring_t.h>
#include <dump_mk_debug_ring.h>
#include <platform.h>
#include <types.h>

/**
 * <!-- description -->
 *   @brief Outputs information about the mk debug ring. Note that this does
 *     not actually output the debug ring itself, but information about it.
 *
 * <!-- inputs/outputs -->
 *   @param debug_ring the mk debug ring to output information about
 */
void
dump_mk_debug_ring(struct debug_ring_t const *const debug_ring) NOEXCEPT
{
    platform_expects(NULLPTR != debug_ring);

    bfdebug("mk debug ring:");
    bfdebug_ptr(" - addr", debug_ring);
    bfdebug_x64(" - size", HYPERVISOR_DEBUG_RING_SIZE);
    bfdebug_x64(" - epos", debug_ring->epos);
    bfdebug_x64(" - spos", debug_ring->spos);
}
