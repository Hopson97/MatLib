#ifndef INITIALIZER_LIST_H_INCLUDED
#define INITIALIZER_LIST_H_INCLUDED

template <typename T>
class Initializer_List
{
    public:
        Initializer_List() = default;

    private:
        T* data;

};

#endif // INITIALIZER_LIST_H_INCLUDED
