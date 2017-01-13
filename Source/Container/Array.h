#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

namespace MatLib
{
    template <typename T, int elements>
    class Heap_Array
    {
        public:
            Heap_Array()
            {
                m_array = new T();
            }

            template <typename... Args>
            Heap_Array(Args... args)
            {
                m_array = new T(std::forward<Args>(args)...);
            }

            T& operator[] (uint32_t index)
            {
                return m_array[index];
            }

            void at(uint32_t index)
            {
                if (index < 0 || index > elements - 1)
                {
                    throw std::out_of_range("Out of range");
                }
                else
                {
                    return m_array[index];
                }
            }

            size_t size()
            {
                return elements;
            }

        private:
            T* m_array;
    };


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
                    throw std::out_of_range("Out of range");
                }
                else
                {
                    return m_array[index];
                }
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
