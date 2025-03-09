#include <cstdint>

namespace fixedpoint
{
    enum class fixed : std::int64_t {};

    fixed& operator+=(fixed& l, fixed r);

    fixed operator+(fixed l, fixed r);

    fixed& operator-=(fixed& l, fixed r);

    fixed operator-(fixed l, fixed r);

    fixed& operator*=(fixed& l, fixed r);

    fixed operator*(fixed l, fixed r);

    fixed& operator/=(fixed& l, fixed r);

    fixed operator/(fixed l, fixed r);

    std::int32_t to_integer(fixed f);

    float to_float(fixed f);

    fixed from_integer(std::int32_t i);

    fixed from_float(float f);
}