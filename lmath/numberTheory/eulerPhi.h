size_t eulerPhi(size_t n)
{
    if (mrp(n))
        return n - 1;

    TwoDDynamicArray factors = factorise(n, withMultiplicities);
    size_t const bound = factors.noElements;
    size_t ret = 1;

    for (size_t primeIdx = 0; primeIdx != bound; ++primeIdx)
    {
        size_t const prime        = factors.at(primeIdx, 0);
        size_t const multiplicity = factors.at(primeIdx, 1);

        ret *= prime - 1;

        for (size_t i = 1; i != multiplicity; ++i)
            ret *= prime;
    }

    factors.destroy();
    return ret;
}
