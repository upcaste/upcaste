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

#ifndef UP_CFLOAT_HPP
#define UP_CFLOAT_HPP

#include <up/prolog.hpp>
#include <float.h>

#define FLT_DEGREES     5.7295779513082320876798154814105e+01f
#define FLT_RADIANS     1.7453292519943295769236907684886e-02f
#define FLT_E           2.7182818284590452353602874713527e-00f
#define FLT_LOG2E       1.4426950408889634073599246810019e-00f
#define FLT_LOG10E      4.3429448190325182765112891891661e-01f
#define FLT_LN2         6.9314718055994530941723212145818e-01f
#define FLT_LN10        2.3025850929940456840179914546844e-00f
#define FLT_2PI         6.2831853071795864769252867665590e-00f
#define FLT_PI          3.1415926535897932384626433832795e-00f
#define FLT_PI_2        1.5707963267948966192313216916398e-00f
#define FLT_PI_4        7.8539816339744830961566084581988e-01f
#define FLT_1_2PI       1.5915494309189533576888376337251e-01f
#define FLT_1_PI        3.1830988618379067153776752674503e-01f
#define FLT_2_PI        6.3661977236758134307553505349006e-01f
#define FLT_2_SQRTPI    1.1283791670955125738961589031215e-00f
#define FLT_SQRT2       1.4142135623730950488016887242097e-00f
#define FLT_1_SQRT2     7.0710678118654752440084436210485e-01f

#define DBL_DEGREES     5.7295779513082320876798154814105e+001
#define DBL_RADIANS     1.7453292519943295769236907684886e-002
#define DBL_E           2.7182818284590452353602874713527
#define DBL_LOG2E       1.4426950408889634073599246810019
#define DBL_LOG10E      4.3429448190325182765112891891661e-001
#define DBL_LN2         6.9314718055994530941723212145818e-001
#define DBL_LN10        2.3025850929940456840179914546844
#define DBL_2PI         6.2831853071795864769252867665590
#define DBL_PI          3.1415926535897932384626433832795
#define DBL_PI_2        1.5707963267948966192313216916398
#define DBL_PI_4        7.8539816339744830961566084581988e-001
#define DBL_1_2PI       1.5915494309189533576888376337251e-001
#define DBL_1_PI        3.1830988618379067153776752674503e-001
#define DBL_2_PI        6.3661977236758134307553505349006e-001
#define DBL_2_SQRTPI    1.1283791670955125738961589031215
#define DBL_SQRT2       1.4142135623730950488016887242097
#define DBL_1_SQRT2     7.0710678118654752440084436210485e-001

#define LDBL_DEGREES    5.7295779513082320876798154814105e+001l
#define LDBL_RADIANS    1.7453292519943295769236907684886e-002l
#define LDBL_E          2.7182818284590452353602874713527l
#define LDBL_LOG2E      1.4426950408889634073599246810019l
#define LDBL_LOG10E     4.3429448190325182765112891891661e-001l
#define LDBL_LN2        6.9314718055994530941723212145818e-001l
#define LDBL_LN10       2.3025850929940456840179914546844l
#define LDBL_2PI        6.2831853071795864769252867665590l
#define LDBL_PI         3.1415926535897932384626433832795l
#define LDBL_PI_2       1.5707963267948966192313216916398l
#define LDBL_PI_4       7.8539816339744830961566084581988e-001l
#define LDBL_1_2PI      1.5915494309189533576888376337251e-001l
#define LDBL_1_PI       3.1830988618379067153776752674503e-001l
#define LDBL_2_PI       6.3661977236758134307553505349006e-001l
#define LDBL_2_SQRTPI   1.1283791670955125738961589031215l
#define LDBL_SQRT2      1.4142135623730950488016887242097l
#define LDBL_1_SQRT2    7.0710678118654752440084436210485e-001l

#if UP_COMPILER == UP_COMPILER_CLANG
#   include <up/detail/cfloat_gcc.inl>
#elif UP_COMPILER == UP_COMPILER_GCC
#   include <up/detail/cfloat_gcc.inl>
#elif UP_COMPILER == UP_COMPILER_MSVC
#   include <up/detail/cfloat_msvc.inl>
#else
#   error "Compiler not currently supported!"
#endif

#endif
