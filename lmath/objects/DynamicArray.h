// Fancier than array, not as fancy as vector,
// never have to worry about memory again
// (unless you're the one writing this AAAAAAAH)
class DynamicArray
{
    size_t length     = 2;
    size_t *elements  = new size_t[length];
    size_t * resize(size_t *elements, size_t length, size_t newLength)
    {
        size_t *newElements = new size_t[newLength];
        for (size_t idx = 0; idx != length; ++idx)
            newElements[idx] = elements[idx];

        delete[] elements;
        return newElements;
    }

    public:
        size_t noElements = 0;
        void append(size_t element)
        {
            if (noElements < length)
                elements[noElements++] = element;
            else
            {
                elements = resize(elements, length, 2 * length);
                elements[noElements++] = element;
                length *= 2;
            }
        }

        size_t at(size_t n)
        {
            if (n < noElements)
                return elements[n];
            std::cerr << "Index out of range\n";
            throw n;
        }


        bool isElement(size_t n)
        {
            for (size_t searchidx = 0; searchidx != noElements; ++searchidx)
            {
                if (elements[searchidx] == n)
                    return 1;
            }
            return 0;
        }


        size_t max()
        {
            size_t maxi = elements[0];
            for (size_t idx = 1; idx != noElements; ++idx)
            {
                size_t const el = elements[idx];
                maxi = (maxi < el ? el : maxi);
            }
            return maxi;
        }

        size_t min()
        {
            size_t mini = elements[0];
            for (size_t idx = 1; idx != noElements; ++idx)
            {
                size_t const el = elements[idx];
                mini = (mini > el ? el : mini);
            }
            return mini;
        }

        void assign(size_t numberOfSlots, size_t integer)
        {
            for (size_t it = 0; it != numberOfSlots; ++it)
                append(integer);
        }

        void changeIndex(size_t index, size_t value)
        {
            if (index < noElements)
                elements[index] = value;
            else
                std::cerr << "Index " << index << " doesn't exist\n";
        }

        void print()
        {
            for (size_t idx = 0; idx != noElements; ++idx)
                std::cout << elements[idx] << '\n';
        }

        void print(size_t start)
        {
            for (size_t idx = start; idx != noElements; ++idx)
                std::cout << elements[idx] << '\n';
        }

        void print(size_t start, size_t end)
        {
            size_t const bound = (end < noElements ? end : noElements);
            for (size_t idx = start; idx != bound; ++idx)
                std::cout << elements[idx] << '\n';
        }

        void destroy()
        {
            delete[] elements;
        }

        void sort()
        {
            quickSort(noElements, elements);
        }

        void sort(size_t (*g)(size_t))
        {
            quickSort(noElements, elements, (*g));
        }

        /* void sort(fnpointer to sort by) */
        /* { */
        /*     elements = quicksort(noElements, elements); */
        /* } */
};
