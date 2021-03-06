﻿//
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

//
//  Do not edit! This file is automatically generated.
//

#ifndef UP_NUMERIC_GENERIC_UINT4_OPERATIONS_INL
#define UP_NUMERIC_GENERIC_UINT4_OPERATIONS_INL

namespace up { namespace math
{
    //
    // Constructor Bindings
    //

    namespace detail
    {
        template< >
        struct constructors<uint4>
        {
            static UPALWAYSINLINE
            uint4 load(uint32_t const* p) noexcept {
                uint4 result;
                result.x = p[0];
                result.y = p[1];
                result.z = p[2];
                result.w = p[3];
                return result;
            }

            static UPALWAYSINLINE
            uint4 load(size_t offset, uint32_t const* p) noexcept {
                uint32_t const* q = p + (offset * 4);
                uint4 result;
                result.x = q[0];
                result.y = q[1];
                result.z = q[2];
                result.w = q[3];
                return result;
            }

            static UPALWAYSINLINE
            uint4 loadunaligned(uint32_t const* p) noexcept {
                uint4 result;
                result.x = p[0];
                result.y = p[1];
                result.z = p[2];
                result.w = p[3];
                return result;
            }

            static UPALWAYSINLINE
            uint4 loadunaligned(size_t offset, uint32_t const* p) noexcept {
                uint32_t const* q = p + (offset * 4);
                uint4 result;
                result.x = q[0];
                result.y = q[1];
                result.z = q[2];
                result.w = q[3];
                return result;
            }

            static UPALWAYSINLINE
            uint4 loadreverse(uint32_t const* p) noexcept {
                uint4 result;
                result.x = p[3];
                result.y = p[2];
                result.z = p[1];
                result.w = p[0];
                return result;
            }

            static UPALWAYSINLINE
            uint4 loadreverse(size_t offset, uint32_t const* p) noexcept {
                uint32_t const* q = p + (offset * 4);
                uint4 result;
                result.x = q[3];
                result.y = q[2];
                result.z = q[1];
                result.w = q[0];
                return result;
            }

            static UPALWAYSINLINE
            uint4 loadscalar(uint32_t const* p) noexcept {
                uint4 result;
                result.x = *p; result.y = result.z = result.w = 0.0u;
                return result;
            }

            static UPALWAYSINLINE
            uint4 loadscalar(size_t offset, uint32_t const* p) noexcept {
                uint4 result;
                result.x = *(p + offset); result.y = result.z = result.w = 0.0u;
                return result;
            }

            static UPALWAYSINLINE
            uint4 make(uint32_t x) noexcept {
                uint4 result;
                result.x = x; result.y = result.z = result.w = 0.0u;
                return result;
            }

            static UPALWAYSINLINE
            uint4 make(uint32_t x, uint32_t y, uint32_t z, uint32_t w) noexcept {
                uint4 result;
                result.x = x;
                result.y = y;
                result.z = z;
                result.w = w;
                return result;
            }

            static UPALWAYSINLINE
            uint4 replicate(uint32_t value) noexcept {
                uint4 result;
                result.x = result.y = result.z = result.w = value;
                return result;
            }

            static UPALWAYSINLINE
            uint4 replicate(uint32_t const* p) noexcept {
                uint4 result;
                result.x = result.y = result.z = result.w = *p;
                return result;
            }

            static UPALWAYSINLINE
            uint4 replicate(size_t offset, uint32_t const* p) noexcept {
                uint4 result;
                result.x = result.y = result.z = result.w = *(p + offset);
                return result;
            }

            static UPALWAYSINLINE
            uint4 zero() noexcept {
                uint4 result;
                result.x = result.y = result.z = result.w = 0.0u;
                return result;
            }
        };
    }

    //
    // Load / Store Functions
    //

    inline UPALWAYSINLINE
    uint4 load(uint4 const* p) noexcept {
        return *p;
    }

    inline UPALWAYSINLINE
    uint4 load(size_t offset, uint4 const* p) noexcept {
        return *(p + offset);
    }

    inline UPALWAYSINLINE
    uint4 loadreverse(uint4 const* p) noexcept {
        uint4 result;
        result.x = p->w;
        result.y = p->z;
        result.z = p->y;
        result.w = p->x;
        return result;
    }

    inline UPALWAYSINLINE
    uint4 loadreverse(size_t offset, uint4 const* p) noexcept {
        uint4 const* q = p + offset;
        uint4 result;
        result.x = q->w;
        result.y = q->z;
        result.z = q->y;
        result.w = q->x;
        return result;
    }

    //
    // Accessor Functions
    //

    inline UPALWAYSINLINE
    uint32_t get(uint4 const& v, size_t n) noexcept {
        return v.u[n];
    }

    inline UPALWAYSINLINE
    uint32_t getx(uint4 const& v) noexcept {
        return v.x;
    }

    inline UPALWAYSINLINE
    uint32_t gety(uint4 const& v) noexcept {
        return v.y;
    }

    inline UPALWAYSINLINE
    uint32_t getz(uint4 const& v) noexcept {
        return v.z;
    }

    inline UPALWAYSINLINE
    uint32_t getw(uint4 const& v) noexcept {
        return v.w;
    }

    inline UPALWAYSINLINE
    uint4 put(uint4 const& v, uint32_t value, size_t n) noexcept {
        uint4 result = v;
        result.u[n] = value;
        return result;
    }

    inline UPALWAYSINLINE
    uint4 putx(uint4 const& v, uint32_t x) noexcept {
        uint4 result;
        result.x = x;
        result.y = v.y;
        result.z = v.z;
        result.w = v.w;
        return result;
    }

    inline UPALWAYSINLINE
    uint4 puty(uint4 const& v, uint32_t y) noexcept {
        uint4 result;
        result.x = v.x;
        result.y = y;
        result.z = v.z;
        result.w = v.w;
        return result;
    }

    inline UPALWAYSINLINE
    uint4 putz(uint4 const& v, uint32_t z) noexcept {
        uint4 result;
        result.x = v.x;
        result.y = v.y;
        result.z = z;
        result.w = v.w;
        return result;
    }

    inline UPALWAYSINLINE
    uint4 putw(uint4 const& v, uint32_t w) noexcept {
        uint4 result;
        result.x = v.x;
        result.y = v.y;
        result.z = v.z;
        result.w = w;
        return result;
    }

    inline UPALWAYSINLINE
    uint4 splat(uint4 const& v, size_t n) noexcept {
        uint4 result;

        switch (n) {
        case 0: result.x = result.y = result.z = result.w = v.x; break;
        case 1: result.x = result.y = result.z = result.w = v.y; break;
        case 2: result.x = result.y = result.z = result.w = v.z; break;
        case 3: result.x = result.y = result.z = result.w = v.w; break;
        default: result = uniform<uint4>::zero; break;
        }

        return result;
    }

    inline UPALWAYSINLINE
    uint4 splatx(uint4 const& v) noexcept {
        uint4 result;
        result.x = v.x;
        result.y = v.x;
        result.z = v.x;
        result.w = v.x;
        return result;
    }

    inline UPALWAYSINLINE
    uint4 splaty(uint4 const& v) noexcept {
        uint4 result;
        result.x = v.y;
        result.y = v.y;
        result.z = v.y;
        result.w = v.y;
        return result;
    }

    inline UPALWAYSINLINE
    uint4 splatz(uint4 const& v) noexcept {
        uint4 result;
        result.x = v.z;
        result.y = v.z;
        result.z = v.z;
        result.w = v.z;
        return result;
    }

    inline UPALWAYSINLINE
    uint4 splatw(uint4 const& v) noexcept {
        uint4 result;
        result.x = v.w;
        result.y = v.w;
        result.z = v.w;
        result.w = v.w;
        return result;
    }

    //
    // Relational Functions
    //

    inline UPALWAYSINLINE
    bool all(uint4 const& v) noexcept {
        return ((v.u[0] & v.u[1] & v.u[2] & v.u[3]) & 0x80000000u) != 0;
    }

    inline UPALWAYSINLINE
    bool all(uint4 const& v, int mask) noexcept {
        int result;
        result = static_cast<int>((v.u[0] & 0x80000000u) >> 31);
        result |= static_cast<int>((v.u[1] & 0x80000000u) >> 30);
        result |= static_cast<int>((v.u[2] & 0x80000000u) >> 29);
        result |= static_cast<int>((v.u[3] & 0x80000000u) >> 28);
        return (result & mask) == mask;
    }

    inline UPALWAYSINLINE
    bool any(uint4 const& v) noexcept {
        return ((v.u[0] | v.u[1] | v.u[2] | v.u[3]) & 0x80000000u) != 0;
    }

    inline UPALWAYSINLINE
    bool any(uint4 const& v, int mask) noexcept {
        int result;
        result = static_cast<int>((v.u[0] & 0x80000000u) >> 31);
        result |= static_cast<int>((v.u[1] & 0x80000000u) >> 30);
        result |= static_cast<int>((v.u[2] & 0x80000000u) >> 29);
        result |= static_cast<int>((v.u[3] & 0x80000000u) >> 28);
        return (result & mask) != 0;
    }
    //
    // Relational Operators
    //
    
    inline UPALWAYSINLINE
    bool operator==(uint4 const& v1, uint4 const& v2) noexcept {
        return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z) && (v1.w == v2.w);
    }
    
    inline UPALWAYSINLINE
    bool operator!=(uint4 const& v1, uint4 const& v2) noexcept {
        return (v1.x != v2.x) || (v1.y != v2.y) || (v1.z != v2.z) || (v1.w != v2.w);
    }
    
    inline UPALWAYSINLINE
    bool operator>(uint4 const& v1, uint4 const& v2) noexcept {
        return (v1.x > v2.x) && (v1.y > v2.y) && (v1.z > v2.z) && (v1.w > v2.w);
    }
    
    inline UPALWAYSINLINE
    bool operator>=(uint4 const& v1, uint4 const& v2) noexcept {
        return (v1.x >= v2.x) && (v1.y >= v2.y) && (v1.z >= v2.z) && (v1.w >= v2.w);
    }
    
    inline UPALWAYSINLINE
    bool operator<(uint4 const& v1, uint4 const& v2) noexcept {
        return (v1.x < v2.x) && (v1.y < v2.y) && (v1.z < v2.z) && (v1.w < v2.w);
    }
    
    inline UPALWAYSINLINE
    bool operator<=(uint4 const& v1, uint4 const& v2) noexcept {
        return (v1.x <= v2.x) && (v1.y <= v2.y) && (v1.z <= v2.z) && (v1.w <= v2.w);
    }

    //
    // Arithmetic Functions
    //
    
    inline UPALWAYSINLINE
    uint4 add(uint4 const& v1, uint4 const& v2) noexcept {
        uint4 result;
        result.x = v1.x + v2.x;
        result.y = v1.y + v2.y;
        result.z = v1.z + v2.z;
        result.w = v1.w + v2.w;
        return result;
    }
    
    inline UPALWAYSINLINE    
    uint4 div(uint4 const& v, uint32_t s) noexcept {    
        uint4 result;
        result.x = v.x / s;
        result.y = v.y / s;
        result.z = v.z / s;
        result.w = v.w / s;
        return result;
    }
    
    inline UPALWAYSINLINE
    uint4 div(uint4 const& v1, uint4 const& v2) noexcept {
        uint4 result;
        result.x = v1.x / v2.x;
        result.y = v1.y / v2.y;
        result.z = v1.z / v2.z;
        result.w = v1.w / v2.w;
        return result;
    }
    
    inline UPALWAYSINLINE    
    uint4 mul(uint4 const& v, uint32_t s) noexcept {    
        uint4 result;
        result.x = v.x * s;
        result.y = v.y * s;
        result.z = v.z * s;
        result.w = v.w * s;
        return result;
    }
    
    inline UPALWAYSINLINE
    uint4 mul(uint4 const& v1, uint4 const& v2) noexcept {
        uint4 result;
        result.x = v1.x * v2.x;
        result.y = v1.y * v2.y;
        result.z = v1.z * v2.z;
        result.w = v1.w * v2.w;
        return result;
    }
    
    inline UPALWAYSINLINE
    uint4 neg(uint4 const& v) noexcept {
        uint4 result;
        result.x = -v.x;
        result.y = -v.y;
        result.z = -v.z;
        result.w = -v.w;
        return result;
    }
    
    inline UPALWAYSINLINE
    uint4 sub(uint4 const& v1, uint4 const& v2) noexcept {
        uint4 result;
        result.x = v1.x - v2.x;
        result.y = v1.y - v2.y;
        result.z = v1.z - v2.z;
        result.w = v1.w - v2.w;
        return result;
    }

    //
    // Arithmetic Operators
    //
    
    inline UPALWAYSINLINE
    uint4 operator+(uint4 const& v) noexcept {
        uint4 result;
        result.x = +v.x;
        result.y = +v.y;
        result.z = +v.z;
        result.w = +v.w;
        return result;
    }
    
    inline UPALWAYSINLINE
    uint4 operator+(uint4 const& v1, uint4 const& v2) noexcept {
        uint4 result;
        result.x = v1.x + v2.x;
        result.y = v1.y + v2.y;
        result.z = v1.z + v2.z;
        result.w = v1.w + v2.w;
        return result;
    }
    
    inline UPALWAYSINLINE
    uint4 operator-(uint4 const& v) noexcept {
        uint4 result;
        result.x = -v.x;
        result.y = -v.y;
        result.z = -v.z;
        result.w = -v.w;
        return result;
    }
    
    inline UPALWAYSINLINE
    uint4 operator-(uint4 const& v1, uint4 const& v2) noexcept {
        uint4 result;
        result.x = v1.x - v2.x;
        result.y = v1.y - v2.y;
        result.z = v1.z - v2.z;
        result.w = v1.w - v2.w;
        return result;
    }
    
    inline UPALWAYSINLINE    
    uint4 operator*(uint4 const& v, uint32_t s) noexcept {    
        uint4 result;
        result.x = v.x * s;
        result.y = v.y * s;
        result.z = v.z * s;
        result.w = v.w * s;
        return result;
    }
    
    inline UPALWAYSINLINE
    uint4 operator*(uint32_t s, uint4 const& v) noexcept {    
        uint4 result;
        result.x = v.x * s;
        result.y = v.y * s;
        result.z = v.z * s;
        result.w = v.w * s;
        return result;
    }
    
    inline UPALWAYSINLINE
    uint4 operator*(uint4 const& v1, uint4 const& v2) noexcept {
        uint4 result;
        result.x = v1.x * v2.x;
        result.y = v1.y * v2.y;
        result.z = v1.z * v2.z;
        result.w = v1.w * v2.w;
        return result;
    }
    
    inline UPALWAYSINLINE    
    uint4 operator/(uint4 const& v, uint32_t s) noexcept {    
        uint4 result;
        result.x = v.x / s;
        result.y = v.y / s;
        result.z = v.z / s;
        result.w = v.w / s;
        return result;
    }
    
    inline UPALWAYSINLINE
    uint4 operator/(uint4 const& v1, uint4 const& v2) noexcept {
        uint4 result;
        result.x = v1.x / v2.x;
        result.y = v1.y / v2.y;
        result.z = v1.z / v2.z;
        result.w = v1.w / v2.w;
        return result;
    }

}}

#endif
