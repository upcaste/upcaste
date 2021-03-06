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

#ifndef UP_DETAIL_ATOMIC_FLAG_GCC_X86_X64_INL
#define UP_DETAIL_ATOMIC_FLAG_GCC_X86_X64_INL

#ifndef UP_ATOMIC_HPP
#   error "Do not include this file directly, instead include <up/atomic.hpp>"
#endif

#ifndef ATOMIC_FLAG_INIT
#   define ATOMIC_FLAG_INIT { 0 }
#endif

#define UP_DETAIL_ATOMIC_FLAG_OPERATIONS(Volatile) \
    UPALWAYSINLINE \
    void clear(memory_order order = memory_order_seq_cst) Volatile noexcept { \
        if (order != memory_order_seq_cst) { \
            __asm__ __volatile__ ( "" : : : "memory" ); \
            state = 0; \
        } \
        else { \
            __asm__ __volatile__ ( \
                "lock; xchgb %1, %0" \
                : "+m" (state) \
                : "r" ((char)0) \
                : "%1", "memory" \
            ); \
        } \
    } \
    UPALWAYSINLINE \
    bool test_and_set(memory_order = memory_order_seq_cst) Volatile noexcept { \
        char expected = 0; \
        bool result; \
        __asm__ __volatile__ ( \
            "lock; cmpxchgb %[desired], %[state]\n\t" \
            "setb %[result]" \
            : [state] "+m" (state), "+a" (expected), [result] "=q" (result) \
            : [desired] "q" ((char)1) \
            : "cc", "memory" \
        ); \
        return result; \
    } \
    UPALWAYSINLINE \
    bool test_test_and_set(memory_order order = memory_order_seq_cst) Volatile noexcept { \
        if (order != memory_order_seq_cst) { \
            char s = state; \
            __asm__ __volatile__ ( "" : : : "memory" ); \
            if (s == 1) { \
                return true; \
            } \
        } \
        return test_and_set(order); \
    }

namespace up
{
    struct LIBUPCOREAPI atomic_flag
    {
        char state;
#if !defined(UP_NO_DEFAULTED_FUNCTIONS) && !defined(UP_NO_DELETED_FUNCTIONS) && !defined(UP_NO_CONSTEXPR)
        UPALWAYSINLINE atomic_flag() = default;
        UPALWAYSINLINE constexpr atomic_flag(char value) noexcept : state(value) { }
        atomic_flag(atomic_flag const&) = delete;
        atomic_flag operator=(atomic_flag const&) = delete;
        atomic_flag operator=(atomic_flag const&) volatile = delete;
#endif
        UP_DETAIL_ATOMIC_FLAG_OPERATIONS(UP_DETAIL_NOT_VOLATILE)
        UP_DETAIL_ATOMIC_FLAG_OPERATIONS(UP_DETAIL_VOLATILE)
    };
}

#undef UP_DETAIL_ATOMIC_FLAG_OPERATIONS

#endif
