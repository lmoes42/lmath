bool isPermutation(size_t a, size_t b)
{
    if (b > 10 * a || b > 10 * a || (b % 9) != (a % 9))
        return 0;

    auto [aLength, aDigits] = toDigits(a);
    auto [bLength, bDigits] = toDigits(b);

    if (aLength != bLength)
        return 0;

    quickSort(aLength, aDigits);
    quickSort(aLength, bDigits);

    for (size_t i = 0; i != aLength; ++i)
    {
        if (aDigits[i] != bDigits[i])
            return 0;
    }

    delete[] aDigits;
    delete[] bDigits;

    return 1;
}
