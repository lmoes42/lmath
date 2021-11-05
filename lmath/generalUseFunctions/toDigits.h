LengthAndPointer const toDigits(size_t n)
{
    auto [length, orderOfMagnitude] = getOrderOfMagnitude(n);

    size_t * digitArray = new size_t[length];
    size_t idx = 0;

    while (orderOfMagnitude)
    {
        digitArray[idx++] = n / orderOfMagnitude;
        n %= orderOfMagnitude;
        orderOfMagnitude /= 10;
    }

    LengthAndPointer ret = {idx, digitArray};
    return ret;
}
