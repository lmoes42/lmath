size_t * resizeArray(size_t newLength, size_t numberOfElements, size_t * ptr)
{
    size_t * newptr = new size_t[newLength];
    for (size_t i = 0; i != numberOfElements; ++i)
        newptr[i] = ptr[i];

    delete[] ptr;

    return newptr;
}

