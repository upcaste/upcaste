//
//  Upcaste Performance Libraries
//  Copyright (C) 2012-2013 Jesse W. Towner
//
//  Permission is hereby granted, free of charge, to any person obtaining
//  a copy of this software and associated documentation files (the
//  "Software"), to deal in the Software without restriction, including
//  without limitation the rights to use, copy, modify, merge, publish,
//  distribute, sublicense, and/or sell copies of the Software, and to
//  permit persons to whom the Software is furnished to do so, subject to
//  the following conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
//  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
//  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#include "linear_region_internal.hpp"
#include <up/cassert.hpp>
#include <up/cerrno.hpp>

namespace up
{
    LIBUPCOREAPI UPNONNULLALL UPALLOC UPWARNRESULT
    void* linear_region_head_allocate(linear_region* r, size_t n) noexcept {
        assert(linear_region_validate(r) && (n > 0));
        
        size_t const align_adjust = r->alignment - 1;
        size_t const aligned_n = (n + align_adjust) & ~align_adjust;
        void* const retval = r->head;

        if (UPUNLIKELY(aligned_n > static_cast<size_t>(r->tail - r->head))) {
            errno = ENOMEM;
            return nullptr;
        }

        r->head += aligned_n;
        return retval;
    }
}
