#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

namespace MatLib
{
    template <typename T, int elements>
    class Array
    {
        public:
            T& operator[] (uint32_t index)
            {
                return m_array[index];
            }

            void at(uint32_t index)
            {
                if (index < 0 || index > elements - 1)
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

            size_t size()
            {
                return elements;
            }

        private:
            T m_array[elements];
    };
}

#endif // ARRAY_H_INCLUDED
