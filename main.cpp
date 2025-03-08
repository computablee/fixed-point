#include "fixed.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <climits>

using fixedpoint::fixed;

int main(void)
{
    std::srand(std::time(0));

    for (auto i = 0; i < 10000000; i++)
    {
        float fa = std::rand() / INT_MAX;
        float fb = std::rand() / INT_MAX;

        auto a = fixedpoint::from_float(fa);
        auto b = fixedpoint::from_float(fb);

        auto fc = fa + fb;
        auto c = a + b;

        assert(fixedpoint::to_float(c) > fc - 0.00001
            && fixedpoint::to_float(c) < fc + 0.00001);

        a += b;

        assert(c == a);
    }
    
    std::cout << "Addition tests passed." << std::endl;

    for (auto i = 0; i < 10000000; i++)
    {
        float fa = std::rand() / INT_MAX;
        float fb = std::rand() / INT_MAX;

        auto a = fixedpoint::from_float(fa);
        auto b = fixedpoint::from_float(fb);

        auto fc = fa - fb;
        auto c = a - b;

        assert(fixedpoint::to_float(c) > fc - 0.00001
            && fixedpoint::to_float(c) < fc + 0.00001);

        a -= b;
    
        assert(c == a);
    }

    std::cout << "Subtraction tests passed." << std::endl;

    for (auto i = 0; i < 10000000; i++)
    {
        float fa = std::rand() / INT_MAX;
        float fb = std::rand() / INT_MAX;

        auto a = fixedpoint::from_float(fa);
        auto b = fixedpoint::from_float(fb);

        auto fc = fa * fb;
        auto c = a * b;

        assert(fixedpoint::to_float(c) > fc - 0.00001
            && fixedpoint::to_float(c) < fc + 0.00001);

        a *= b;
    
        assert(c == a);
    }

    std::cout << "Multiplication tests passed." << std::endl;

    return 0;
}