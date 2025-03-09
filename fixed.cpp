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
        l = fixed((static_cast<__int128>(l) * static_cast<__int128>(r)) >> 32);
        return l;
    }

    fixed operator*(fixed l, fixed r)
    {
        return fixed((static_cast<__int128>(l) * static_cast<__int128>(r)) >> 32);
    }

    fixed& operator/=(fixed& l, fixed r)
    {
        l = fixed((static_cast<__int128>(l) << 32) / static_cast<__int128>(r));
        return l;
    }

    fixed operator/(fixed l, fixed r)
    {
        return fixed((static_cast<__int128>(l) << 32) / static_cast<__int128>(r));
    }

    fixed operator+(fixed f)
    {
        return f;
    }

    fixed operator-(fixed f)
    {
        return fixed(-static_cast<std::int64_t>(f));
    }

    fixed operator~(fixed f)
    {
        return fixed(~static_cast<std::int64_t>(f));
    }

    fixed& operator&=(fixed& l, fixed r)
    {
        l = fixed(static_cast<std::int64_t>(l) & static_cast<std::int64_t>(r));
        return l;
    }

    fixed operator&(fixed l, fixed r)
    {
        return fixed(static_cast<std::int64_t>(l) & static_cast<std::int64_t>(r));
    }

    fixed& operator|=(fixed& l, fixed r)
    {
        l = fixed(static_cast<std::int64_t>(l) | static_cast<std::int64_t>(r));
        return l;
    }

    fixed operator|(fixed l, fixed r)
    {
        return fixed(static_cast<std::int64_t>(l) | static_cast<std::int64_t>(r));
    }

    fixed& operator^=(fixed& l, fixed r)
    {
        l = fixed(static_cast<std::int64_t>(l) ^ static_cast<std::int64_t>(r));
        return l;
    }

    fixed operator^(fixed l, fixed r)
    {
        return fixed(static_cast<std::int64_t>(l) ^ static_cast<std::int64_t>(r));
    }

    template <typename IntType>
    fixed& operator<<=(fixed& l, IntType r)
    {
        l = fixed(static_cast<std::int64_t>(l) << r);
        return l;
    }

    template<>
    fixed& operator<<=(fixed& l, fixed r)
    {
        l = fixed(static_cast<std::int64_t>(l) << to_integer(r));
        return l;
    }

    template fixed& operator<<=<char>(fixed& l, char r);
    template fixed& operator<<=<signed char>(fixed& l, signed char r);
    template fixed& operator<<=<unsigned char>(fixed& l, unsigned char r);
    template fixed& operator<<=<short>(fixed& l, short r);
    template fixed& operator<<=<unsigned short>(fixed& l, unsigned short r);
    template fixed& operator<<=<int>(fixed& l, int r);
    template fixed& operator<<=<unsigned int>(fixed& l, unsigned int r);
    template fixed& operator<<=<long>(fixed& l, long r);
    template fixed& operator<<=<unsigned long>(fixed& l, unsigned long r);
    template fixed& operator<<=<long long>(fixed& l, long long r);
    template fixed& operator<<=<unsigned long long>(fixed& l, unsigned long long r);

    template <typename IntType>
    fixed operator<<(fixed l, IntType r)
    {
        return fixed(static_cast<std::int64_t>(l) << r);
    }

    template<>
    fixed operator<<(fixed l, fixed r)
    {
        return fixed(static_cast<std::int64_t>(l) << to_integer(r));
    }

    template fixed operator<<<char>(fixed l, char r);
    template fixed operator<<<signed char>(fixed l, signed char r);
    template fixed operator<<<unsigned char>(fixed l, unsigned char r);
    template fixed operator<<<short>(fixed l, short r);
    template fixed operator<<<unsigned short>(fixed l, unsigned short r);
    template fixed operator<<<int>(fixed l, int r);
    template fixed operator<<<unsigned int>(fixed l, unsigned int r);
    template fixed operator<<<long>(fixed l, long r);
    template fixed operator<<<unsigned long>(fixed l, unsigned long r);
    template fixed operator<<<long long>(fixed l, long long r);
    template fixed operator<<<unsigned long long>(fixed l, unsigned long long r);

    template <typename IntType>
    fixed& operator>>=(fixed& l, IntType r)
    {
        l = fixed(static_cast<std::int64_t>(l) >> r);
        return l;
    }

    template<>
    fixed& operator>>=(fixed& l, fixed r)
    {
        l = fixed(static_cast<std::int64_t>(l) >> to_integer(r));
        return l;
    }

    template fixed& operator>>=<char>(fixed& l, char r);
    template fixed& operator>>=<signed char>(fixed& l, signed char r);
    template fixed& operator>>=<unsigned char>(fixed& l, unsigned char r);
    template fixed& operator>>=<short>(fixed& l, short r);
    template fixed& operator>>=<unsigned short>(fixed& l, unsigned short r);
    template fixed& operator>>=<int>(fixed& l, int r);
    template fixed& operator>>=<unsigned int>(fixed& l, unsigned int r);
    template fixed& operator>>=<long>(fixed& l, long r);
    template fixed& operator>>=<unsigned long>(fixed& l, unsigned long r);
    template fixed& operator>>=<long long>(fixed& l, long long r);
    template fixed& operator>>=<unsigned long long>(fixed& l, unsigned long long r);

    template <typename IntType>
    fixed operator>>(fixed l, IntType r)
    {
        return fixed(static_cast<std::int64_t>(l) >> r);
    }

    template<>
    fixed operator>>(fixed l, fixed r)
    {
        return fixed(static_cast<std::int64_t>(l) >> to_integer(r));
    }

    template fixed operator>><char>(fixed l, char r);
    template fixed operator>><signed char>(fixed l, signed char r);
    template fixed operator>><unsigned char>(fixed l, unsigned char r);
    template fixed operator>><short>(fixed l, short r);
    template fixed operator>><unsigned short>(fixed l, unsigned short r);
    template fixed operator>><int>(fixed l, int r);
    template fixed operator>><unsigned int>(fixed l, unsigned int r);
    template fixed operator>><long>(fixed l, long r);
    template fixed operator>><unsigned long>(fixed l, unsigned long r);
    template fixed operator>><long long>(fixed l, long long r);
    template fixed operator>><unsigned long long>(fixed l, unsigned long long r);

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

    double to_double(fixed f)
    {
        const auto f_conv = static_cast<std::int64_t>(f);
        return static_cast<double>(f_conv >> 32) +
            (static_cast<double>(f_conv & UINT32_MAX) / (1ull << 32ull));
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

    fixed from_double(double f)
    {
        double ipart;
        const double fpart = std::modf(f, &ipart);
        
        assert(ipart <= static_cast<double>(INT_MAX));
        assert(ipart >= static_cast<double>(INT_MIN));
        
        const std::int32_t iipart = static_cast<std::int32_t>(ipart);
        const std::uint32_t ifpart = static_cast<std::uint32_t>(std::abs(fpart) * (1ull << 32ull));

        return static_cast<fixed>((static_cast<std::int64_t>(iipart) << 32) +
            (static_cast<std::int64_t>(ifpart) * (fpart < 0 ? -1 : 1)));
    }
}