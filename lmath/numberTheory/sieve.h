LengthAndPointer sieve(size_t n)
{
/* Sieve of Eratosthenes, takes an integer
 * and returns a pointer to an array containing
 * all primes up to that integer, with
 * the first element the number
 * of primes in the array;
 * works up to the 10.000.000th prime */

    size_t *boolar =  new size_t[n];
    size_t i, j;
    boolar[0] = 0;
    boolar[1] = 0;

    /* Mark all elements greater than 1 as true. */
    for (int loop = 2; loop < n; ++loop)
        boolar[loop] = 1;

    /* Mark all multiples as false. */
    i = 1;
    size_t bound = 0;
    while (bound * bound < n) ++bound;
    while (++i < bound)
    {
        if (boolar[i])
        {
            for (j = i*i; j < n; j += i)
                boolar[j] = 0;
        }
    }

    /* Determine how many elements are marked true. */
    size_t number_of_primes = 0;
    for (i = 0; i < n; ++i)
    {
        if (boolar[i])
            ++number_of_primes;
    }

    /* Create an array of the indexes of numbers
     * which were still marked true.
     * Change line below for greater integers.*/

    size_t *primes =  new size_t[number_of_primes];
    size_t counter = 0;
    for (i = 0; i < n; ++i){
        if (boolar[i])
            primes[counter++] = i;
    }

    delete[] boolar;

    LengthAndPointer ret = {number_of_primes, primes};
    return ret;
}
