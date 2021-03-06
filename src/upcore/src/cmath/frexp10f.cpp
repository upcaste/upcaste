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

#include <up/cmath.hpp>
#include <up/ieee754.hpp>

namespace up { namespace math
{
    LIBUPCOREAPI UPNONNULLALL
    float frexp10(float x, int* e) noexcept {
        int e2, e10;
        float s;

        // get base 2 exponent
#if (FLT_MANT_DIG == 24) && (FLT_RADIX == 2)
        ieee754_binary32 raw;
        raw.f = x;
        if (!raw.ieee.exponent && !raw.ieee.mantissa) {
            *e = 0;
            return 0.0f;
        }
        e2 = static_cast<int>(raw.ieee.exponent) - ieee754_binary32_bias;
        if (e2 == (ieee754_binary32_bias + 1)) {
            return raw.ieee.mantissa ? FLT_NAN : x;
        }
#else
    error "single-precision floating-point format not yet supported!"
#endif

        // determine base 10 exponent
#if INT_MAX >= ((1 << 30) - 1)
        e10 = (e2 * 19728) >> 16;
#else
        e10 = static_cast<int>(e2 * (FLT_LN2 / FLT_LN10));
#endif
        
        // compute significand and fine-tune exponent
        x = raw.ieee.negative ? -x : x;
        s = x / pow10f(e10);

        while (s < 1.0f) {
            --e10;
            s = x / pow10f(e10);
        }

        while (s >= 10.0f) {
            ++e10;
            s = x / pow10f(e10);
        }

        *e = e10;
        return raw.ieee.negative ? -s : s;
    }
}}
