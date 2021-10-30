#include "lmath/commonFunctions/commonFunctions.h"
size_t min(size_t a, size_t b)
{
    return (a < b ? a : b);
}

size_t max(size_t a, size_t b)
{
    return (a > b ? a : b);
}

size_t abs(size_t a)
{
    return (a > 0 ? a : -a);
}

float sqrt(float x)
{
    float x0 = x;
    for (size_t i = 0; i != 10; ++i)
        x0 = (x0 + x/x0)/2;
    return x0;
}

size_t gcd(size_t a, size_t b)
{
    size_t r0 = (a > b ? a : b),
           rn = (a < b ? a : b),
           temp;

    while (rn)
    {
        temp = r0;
        r0   = rn;
        rn   = temp % rn;
    }

    return r0;
}

size_t pow(size_t base, size_t exp)
{
    size_t outp = 1;
    while(exp > 0)
    {
        if ((exp & 1))
            outp = (outp * base);

        exp = exp >> 1;
        base = base*base;
    }
    return outp;
}

size_t pow(size_t base, size_t exp, size_t mod)
{
    size_t outp = 1;
    while(exp > 0)
    {
        if ((exp & 1))
            outp = (outp * base) % mod;

        exp = exp >> 1;
        base = (base*base) % mod;
    }
    return outp;
}
