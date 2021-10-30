bool mrp(size_t n){
    if (n == 2 || n == 3 || n == 5)
        return true;
    else if (!(n & 1) || n < 2)
        return false;

    size_t r = 0, s = n-1;
    while(!(s & 1))
    {
        ++r;
        s /= 2;
    }

    // This works until 3,215,031,751
    size_t const toTest[4] = {2, 3, 5, 7};
    for (auto const &test: toTest)
    {
        bool check = true;
        size_t x = (size_t) pow(test,s,n); // pow(a,s)%n;
        if(x == 1 || x == n-1)
            continue;

        for(size_t j = 0; j < r - 1; j++)
        {
            x = pow(x, 2, n);//pow(x,2)%n;
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
