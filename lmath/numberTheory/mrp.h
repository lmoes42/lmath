// This works until 3,215,031,751, need to add 11 for larger numbers
bool mrp(size_t n, std::initializer_list<size_t> const toTest = {2, 3, 5, 7}){

    // See if we actually need to apply the test
    if (n < 10)
        return (n == 2 || n == 3 || n == 5 || n == 7);
    else if (!(n & 1))
        return false;

    // Miller Rabin test
    size_t r = 0, s = n - 1;

    while (!(s & 1))
    {
        ++r;
        s /= 2;
    }

    for (auto const &test: toTest)
    {
        bool check = true;
        size_t x   = pow(test, s, n);

        if(x == 1 || x == n - 1)
            continue;

        for (size_t j = 0; j < r - 1; j++)
        {
            x = pow(x, 2, n);
            if(x == n - 1)
            {
                check = false;
                break;
            }
        }

        if (check)
            return false;
    }
    return true;
}
