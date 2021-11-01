#include "lmath/numberTheory/pollardrho.h"

size_t defaultPollardFunction(size_t x)
{
    return x * x + 1;
}

DynamicArray naiveFactorise(size_t n)
{
    DynamicArray factors;
    size_t const bound = (int) sqrt(n);
    for (size_t primeidx = 0; primeidx != numpr && primeidx < bound + 1 && n - 1; ++primeidx)
    {
        size_t const prime = primeNumbersHeader[primeidx];
        if (!(n % prime))
        {
            while (!(n % prime))
            {
                factors.append(prime);
                n /= prime;
            }
        }
    }
    if (n - 1)
    {
        std::cerr << "lmath/numberTheory/factorise.h\n"
            <<
            "OverflowError in factorisation: "
            << n
            << " too large.\n";
        throw n;
    }

    return factors;
}

DynamicArray factorise(size_t n)
{
    return naiveFactorise(n);

    // Work in progress
    DynamicArray factors;
    while (n - 1)
    {
        size_t const factor = pollardrho(n, &defaultPollardFunction);
        if (factor)
        {
            if (mrp(factor))
            {
                while (!(n % factor))
                {
                    factors.append(factor);
                    n /= factor;
                }
            }
            else
            {
                DynamicArray newFactors = factorise(factor);
                for (size_t i = 0; i != newFactors.noElements; ++i)
                {
                    size_t const currentFactor = newFactors.at(i);
                    while (!(n % currentFactor))
                    {
                        factors.append(currentFactor);
                        n /= currentFactor;
                    }
                }
                newFactors.destroy();
            }
        }
        else
        {
            DynamicArray newFactors = naiveFactorise(n);
            for (size_t i = 0; i != newFactors.noElements; ++i)
            {
                size_t const currentFactor = newFactors.at(i);
                while (!(n % currentFactor))
                {
                    factors.append(currentFactor);
                    n /= currentFactor;
                }
            }
            newFactors.destroy();
        }

    }
    if (n - 1)
    {
        if (mrp(n))
        {
            factors.append(n);
            return factors;
        }
    }
    return factors;
}
