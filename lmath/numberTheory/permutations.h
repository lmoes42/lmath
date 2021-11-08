TwoDDynamicArray permutations(DynamicArray A)
{
    TwoDDynamicArray ret;
    auto length = A.noElements;
    size_t c[length];

    for (size_t i = 0; i != length; ++i)
        c[i]   = 0;

    ret.append(A);

    size_t i = 0;

    while (i < length)
    {
        if (c[i] < i)
        {

            DynamicArray An;
            for (size_t i = 0; i != length; ++i)
                An.append(A.at(i));

            if (!(i & 1))
                An.swap(0, i);
            else
                An.swap(c[i], i);

            ret.append(An);
            A = An;
            ++c[i];
            i = 0;
        }
        else
        {
            c[i] = 0;
            ++i;
        }
    }

    return ret;
}

