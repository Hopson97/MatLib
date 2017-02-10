#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

namespace MatLib
{
    template<typename T>
    void swap(T& l, T& r)
    {
        T& temp = l;
        l = r;
        r = temp;
    }
}

#endif // UTILITIES_H_INCLUDED
