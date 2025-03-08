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
        l = fixed(static_cast<long>(l) + static_cast<long>(r));
        return l;
    }

    fixed operator+(fixed l, fixed r)
    {
        return fixed(static_cast<long>(l) + static_cast<long>(r));
    }

    fixed& operator-=(fixed& l, fixed r)
    {
        l = fixed(static_cast<long>(l) - static_cast<long>(r));
        return l;
    }

    fixed operator-(fixed l, fixed r)
    {
        return fixed(static_cast<long>(l) - static_cast<long>(r));
    }

    fixed& operator*=(fixed& l, fixed r)
    {
        l = fixed((static_cast<long>(l) >> 16) * (static_cast<long>(r) >> 16));
        return l;
    }

    fixed operator*(fixed l, fixed r)
    {
        return fixed((static_cast<long>(l) >> 16) * (static_cast<long>(r) >> 16));
    }

    int to_integer(fixed f)
    {
        return static_cast<long>(f) >> 32;
    }

    float to_float(fixed f)
    {
        const auto f_conv = static_cast<long>(f);
        return static_cast<float>(f_conv >> 32) +
            (static_cast<float>(f_conv & UINT32_MAX) / (1ull << 32ull));
    }

    fixed from_integer(int i)
    {
        return static_cast<fixed>(static_cast<long>(i) << 32ull);
    }

    fixed from_float(float f)
    {
        assert(f <= INT_MAX);
        assert(f >= INT_MIN);

        float ipart;
        const float fpart = std::modf(f, &ipart);
        
        const int iipart = static_cast<int>(ipart);
        const unsigned int ifpart = static_cast<unsigned int>(std::abs(fpart) * (1ull << 32ull));

        return static_cast<fixed>((static_cast<long>(iipart) << 32) +
            (static_cast<long>(ifpart) * (fpart < 0 ? -1 : 1)));
    }
}