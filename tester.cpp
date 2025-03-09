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
constexpr double neg_precision = 0.0000001;

constexpr int test_iterations = 10000000;

int main(void)
{
    std::srand(std::time(0));

    std::cout << std::setprecision(20);

    for (auto i = 0; i < test_iterations; i++)
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

    for (auto i = 0; i < test_iterations; i++)
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

    for (auto i = 0; i < test_iterations; i++)
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

    for (auto i = 0; i < test_iterations; i++)
    {
        const float fa = static_cast<float>(std::rand()) / (1 << 24);
        const float fb = static_cast<float>(std::rand()) / (1 << 24);

        auto a = fixedpoint::from_float(fa);
        const auto b = fixedpoint::from_float(fb);

        const auto fc = fa / fb;
        const auto c = a / b;
        const auto result = fixedpoint::to_float(c);

        assert(result > fc - mult_precision
            && result < fc + mult_precision);

        a /= b;

        assert(c == a);
    }

    std::cout << "Division tests passed." << std::endl;

    for (auto i = 0; i < test_iterations; i++)
    {
        const double fa = static_cast<double>(std::rand()) / SHRT_MAX;
        const auto a = fixedpoint::from_double(fa);

        const auto fc = -fa;
        const auto result = fixedpoint::to_double(-a);

        assert(result > fc - neg_precision
            && result < fc + neg_precision);
    }

    std::cout << "Negation tests passed." << std::endl;

    return 0;
}