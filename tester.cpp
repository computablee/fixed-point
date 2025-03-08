#include "fixed.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <climits>

using fixedpoint::fixed;

constexpr double precision = 0.0000000001;
constexpr double mult_precision = 0.005;

int main(void)
{
    std::srand(std::time(0));

    std::cout << std::setprecision(20);

    for (auto i = 0; i < 10000000; i++)
    {
        const float fa = static_cast<float>(std::rand()) / SHRT_MAX;
        const float fb = static_cast<float>(std::rand()) / SHRT_MAX;

        auto a = fixedpoint::from_float(fa);
        const auto b = fixedpoint::from_float(fb);

        const auto fc = fa + fb;
        const auto c = a + b;
        const auto result = fixedpoint::to_float(c);

        assert(result > fc - precision
            && result < fc + precision);

        a += b;

        assert(c == a);
    }
    
    std::cout << "Addition tests passed." << std::endl;

    for (auto i = 0; i < 10000000; i++)
    {
        const float fa = static_cast<float>(std::rand()) / SHRT_MAX;
        const float fb = static_cast<float>(std::rand()) / SHRT_MAX;

        auto a = fixedpoint::from_float(fa);
        const auto b = fixedpoint::from_float(fb);

        const auto fc = fa - fb;
        const auto c = a - b;
        const auto result = fixedpoint::to_float(c);

        assert(result > fc - precision
            && result < fc + precision);

        a -= b;

        assert(c == a);
    }

    std::cout << "Subtraction tests passed." << std::endl;

    for (auto i = 0; i < 10000000; i++)
    {
        const float fa = static_cast<float>(std::rand()) / (1 << 24);
        const float fb = static_cast<float>(std::rand()) / (1 << 24);

        auto a = fixedpoint::from_float(fa);
        const auto b = fixedpoint::from_float(fb);

        const auto fc = fa * fb;
        const auto c = a * b;
        const auto result = fixedpoint::to_float(c);

        assert(result > fc - mult_precision
            && result < fc + mult_precision);

        a *= b;

        assert(c == a);
    }

    std::cout << "Multiplication tests passed." << std::endl;

    return 0;
}