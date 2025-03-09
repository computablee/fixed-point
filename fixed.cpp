#include "fixed.hpp"
#include <cassert>
#include <cstdint>
#include <climits>
#include <iostream>
#include <cmath>

namespace fixedpoint
{
    fixed& operator+=(fixed& l, fixed r)
    {
        l = fixed(static_cast<std::int64_t>(l) + static_cast<std::int64_t>(r));
        return l;
    }

    fixed operator+(fixed l, fixed r)
    {
        return fixed(static_cast<std::int64_t>(l) + static_cast<std::int64_t>(r));
    }

    fixed& operator-=(fixed& l, fixed r)
    {
        l = fixed(static_cast<std::int64_t>(l) - static_cast<std::int64_t>(r));
        return l;
    }

    fixed operator-(fixed l, fixed r)
    {
        return fixed(static_cast<std::int64_t>(l) - static_cast<std::int64_t>(r));
    }

    fixed& operator*=(fixed& l, fixed r)
    {
        l = fixed((static_cast<std::int64_t>(l) >> 16) * (static_cast<std::int64_t>(r) >> 16));
        return l;
    }

    fixed operator*(fixed l, fixed r)
    {
        return fixed((static_cast<std::int64_t>(l) >> 16) * (static_cast<std::int64_t>(r) >> 16));
    }

    std::int32_t to_integer(fixed f)
    {
        return static_cast<std::int64_t>(f) >> 32;
    }

    float to_float(fixed f)
    {
        const auto f_conv = static_cast<std::int64_t>(f);
        return static_cast<float>(f_conv >> 32) +
            (static_cast<float>(f_conv & UINT32_MAX) / (1ull << 32ull));
    }

    fixed from_integer(std::int32_t i)
    {
        return static_cast<fixed>(static_cast<std::int64_t>(i) << 32ull);
    }

    fixed from_float(float f)
    {
        float ipart;
        const float fpart = std::modf(f, &ipart);
        
        assert(ipart <= static_cast<float>(INT_MAX));
        assert(ipart >= static_cast<float>(INT_MIN));
        
        const std::int32_t iipart = static_cast<std::int32_t>(ipart);
        const std::uint32_t ifpart = static_cast<std::uint32_t>(std::abs(fpart) * (1ull << 32ull));

        return static_cast<fixed>((static_cast<std::int64_t>(iipart) << 32) +
            (static_cast<std::int64_t>(ifpart) * (fpart < 0 ? -1 : 1)));
    }

    fixed& operator/=(fixed& l, fixed r)
    {
        l = fixed(((static_cast<__int128>(l) << 64) / static_cast<__int128>(r)) >> 32);
        return l;
    }

    fixed operator/(fixed l, fixed r)
    {
        return fixed(((static_cast<__int128>(l) << 64) / static_cast<__int128>(r)) >> 32);
    }
}