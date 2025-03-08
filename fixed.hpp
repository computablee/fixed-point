namespace fixedpoint
{
    enum class fixed : long {};

    fixed& operator+=(fixed& l, fixed r);

    fixed operator+(fixed l, fixed r);

    fixed& operator-=(fixed& l, fixed r);

    fixed operator-(fixed l, fixed r);

    fixed& operator*=(fixed& l, fixed r);

    fixed operator*(fixed l, fixed r);

    int to_integer(fixed f);

    float to_float(fixed f);

    fixed from_integer(int i);

    fixed from_float(float f);
}