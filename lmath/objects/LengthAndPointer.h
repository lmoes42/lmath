// Generally used as output from a function.
// For instance the way you're supposed to use sieve is
// auto [primesLength, primes] = sieve(42);
struct LengthAndPointer
{
    size_t length;
    size_t *memoryAdress;
};
