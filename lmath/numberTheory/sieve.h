LengthAndPointer sieve(size_t n)
{
// Sieve of Eratosthenes, takes an integer
// and returns a size_t representing length and a pointer, use as
// auto const [primesLength, primes] = sieve(42);

    size_t *boolar = new size_t[n];
    size_t i, j;
    boolar[0] = 0;
    boolar[1] = 0;

    // Mark all elements greater than 1 as true.
    for (int loop = 2; loop < n; ++loop)
        boolar[loop] = 1;

    i = 1;
    size_t bound = 0;
    while (bound * bound < n)
        ++bound;

    // Mark all multiples as false.
    while (++i < bound)
    {
        if (boolar[i])
        {
            for (j = i*i; j < n; j += i)
                boolar[j] = 0;
        }
    }

    // Determine how many elements are marked true.
    size_t numberOfPrimes = 0;
    for (i = 0; i < n; ++i)
    {
        if (boolar[i])
            ++numberOfPrimes;
    }

    // Create an array of the indexes of numbers
    // which were still marked true.

    size_t *primes =  new size_t[numberOfPrimes];
    size_t counter = 0;
    for (i = 0; i < n; ++i)
    {
        if (boolar[i])
            primes[counter++] = i;
    }

    delete[] boolar;

    LengthAndPointer ret = {numberOfPrimes, primes};
    return ret;
}
