TwoDDynamicArray permutations(DynamicArray A)
{
    int n = A.noElements;
    TwoDDynamicArray outp;
    DynamicArray c;
    c.assign(n,0);

    outp.append(A);

    size_t i = 0;
    while (i < n)
    {
        if (c.at(i) < i)
        {
            if ( !(i & 1) ) std::swap(A.at(0),A.at(i));
            else swap(A.at(c.at(i),i),A.at(i));
            outp.push_back(A);
            ++c.at(i);
            i = 0;
        }
        else
        {
            c.changeIndex(i,0);
            ++i;
        }
    }
    return outp;
}

