// The pollard rho method, taking any polynomial
size_t pollardrho(size_t n, size_t (*g)(size_t))
{
    int x = 2,
        y = 2,
        d = 1;

    while (d == 1)
    {
        x = (*g)(x);
        y = (*g)((*g)(y));
        d = gcd(max(x,y) - min(x,y), n);
    }

    if (d == n)
        return 0;
    return d;
}
