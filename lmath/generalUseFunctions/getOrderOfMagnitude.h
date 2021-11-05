TwoTuple const getOrderOfMagnitude(size_t n)
{
    size_t orderOfMagnitude = 1,
           length = 0;

    while (n > orderOfMagnitude)
    {
        orderOfMagnitude *= 10;
        ++length;
    }

    TwoTuple ret = {length, orderOfMagnitude / 10};
    return ret;
}
