// Fancier than array, not as fancy as vector,
// never have to worry about memory again
// (unless you're the one writing this AAAAAAAH)
class TwoDDynamicArray
{
    size_t length     = 2;
    DynamicArray *elements  = new DynamicArray[length];
    DynamicArray * resize(DynamicArray *elements, size_t length, size_t newLength)
    {
        DynamicArray *newElements = new DynamicArray[newLength];
        for (size_t idx = 0; idx != length; ++idx)
            newElements[idx] = elements[idx];

        delete[] elements;
        return newElements;
    }

    public:
        size_t noElements = 0;
        void append(DynamicArray element)
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

        DynamicArray at(size_t n)
        {
            if (n < noElements)
                return elements[n];
            std::cerr << "Index out of range\n";
            throw n;
        }

        size_t at(size_t n, size_t k)
        {
            if (n < noElements)
                return elements[n].at(k);
            std::cerr << "Index out of range\n";
            throw n;
        }


        /* bool isElement(DynamicArray n) */
        /* { */
        /*     for (size_t searchidx = 0; searchidx != noElements; ++searchidx) */
        /*     { */
        /*         if (elements[searchidx] == n) */
        /*             return 1; */
        /*     } */
        /*     return 0; */
        /* } */


        /* DynamicArray max(size_t (*g)(DynamicArray)) */
        /* { */
        /*     DynamicArray maxi = (*g)(elements[0]); */
        /*     for (size_t idx = 1; idx != noElements; ++idx) */
        /*     { */
        /*         size_t const el = (*g)(elements[idx]); */
        /*         maxi = (maxi < el ? el : maxi); */
        /*     } */
        /*     return maxi; */
        /* } */

        /* DynamicArray min(size_t (*g)(DynamicArray)) */
        /* { */
        /*     DynamicArray mini = (*g)(elements[0]); */
        /*     for (size_t idx = 1; idx != noElements; ++idx) */
        /*     { */
        /*         size_t const el = (*g)(elements[idx]); */
        /*         mini = (mini > el ? el : mini); */
        /*     } */
        /*     return mini; */
        /* } */

        void assign(size_t numberOfSlots, DynamicArray arr)
        {
            for (size_t it = 0; it != numberOfSlots; ++it)
                append(arr);
        }

        void changeIndex(size_t index, DynamicArray value)
        {
            if (index < noElements)
                elements[index] = value;
            else
                std::cerr << "Index " << index << " doesn't exist\n";
        }

        void print()
        {
            for (size_t idx = 0; idx != noElements; ++idx)
            {
                for (size_t idxy = 0; idxy != at(idx).noElements; ++idxy)
                {
                    std::cout << at(idx, idxy) << ' ';
                }
                std::cout << '\n';
            }
        }

        /* void print(size_t start) */
        /* { */
        /*     for (size_t idx = start; idx != noElements; ++idx) */
        /*     { */
        /*         elements[idx].print(withNewline); */
        /*         std::cout << '\n'; */
        /*     } */
        /* } */

        void destroy()
        {
            for (size_t idx = 0; idx != noElements; ++idx)
                elements[idx].destroy();
            delete[] elements;
        }

        /* void sort(size_t (*g)(DynamicArray)) */
        /* { */
        /*     quickSort(noElements, elements, (*g)); */
        /* } */

        /* void sort(fnpointer to sort by) */
        /* { */
        /*     elements = quicksort(noElements, elements); */
        /* } */
};
