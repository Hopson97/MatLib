#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <cstdint>

namespace MatLib
{
    template <typename T, int Elements>
    class Array
    {
        public:
            /*
            class Iterator
            {
                public:
                    friend class Array;

                    Iterator(uint64_t index, T arr[Elements])
                    :   m_index (index)
                    ,   m_p_array (arr)
                    { }

                    friend bool operator!=(typename Array<T, Elements>::Iterator left, typename Array<T, Elements>::Iterator right)
                    {
                        return left.m_index != right.m_index;
                    }

                    T& operator *() const
                    {
                        return m_p_array[m_index];
                    }

                    Iterator& operator++()
                    {
                        m_index++;
                        return *this;
                    }

                    Iterator& operator++(int)
                    {
                        m_index++;
                        return *this;
                    }

                    Iterator& operator--()
                    {
                        m_index--;
                        return *this;
                    }

                    Iterator& operator--(int)
                    {
                        m_index--;
                        return *this;
                    }

                    Iterator& operator+ (int x)
                    {
                        m_index += x;

                        return *this;
                    }

                private:
                    uint64_t m_index;
                    T m_p_array[Elements];
            };
*/
            T& operator[] (uint32_t index)
            {
                return m_array[index];
            }

            void at(uint32_t index)
            {
                if (index < 0 || index > Elements - 1)
                {
                    //throw std::out_of_range("Out of range");
                }
                else
                {
                    return m_array[index];
                }
            }

            T* data()
            {
                return m_array;
            }

            int size() { return Elements; }
/*
            Iterator begin()
            {
                return Iterator(0, m_array );
            }

            Iterator end()
            {
                return Iterator{Elements, m_array};
            }
*/
        private:
            T m_array[Elements];
    };
}

#endif // ARRAY_H_INCLUDED
