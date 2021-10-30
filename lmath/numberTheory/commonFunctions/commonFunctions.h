class Fibonacci
{
    size_t f0 = 1,
           temp;

    public:
    size_t index   = 1,
           current = 1;

    size_t next()
    {
        temp     = current;
        current += f0;
        f0       = temp;
        ++index;
        return current;
    }

    size_t prev()
    {
        f0       = current - f0;
        current -= f0;
        --index;
        return current;
    }
};
