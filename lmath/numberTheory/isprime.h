bool isprime(size_t n){

    if (!(n & 1))
        return n == 2;
    if (!( (n-1) % 6 == 0 || (n+1) % 6 == 0))
        return n == 3;


    size_t i, temp;
    size_t const bound = sqrt(n+1);

    for (i = 2; i < numpr && (temp = primeNumbersHeader[i]) < bound; ++i)
    {
        if (!(n % temp))
            return 0;
    }

    for (i = 10007; i < bound; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}
