#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <cstddef>
#include <algorithm>

namespace MatLib
{
template<typename T>
class Vector
{
    using Pointer = T*;

    public:
        Vector () = default;

        Vector (size_t initialSize)
        :   m_maxSize   ( initialSize)
        {
            if (!m_maxSize == 0)
                m_p_data = (Pointer) malloc (sizeof(T) * m_maxSize);
        }

        Vector ( Vector&& other ) //Move constructor
        :   m_maxSize   (other.m_maxSize )
        ,   m_size      (other.m_size )
        ,   m_p_data    (other.m_p_data )
        {
            other.m_p_data  = nullptr;
            other.m_size    = 0;
            other.m_maxSize = 0;
        }


        Vector& operator =(Vector&& other ) //Move assignment
        {
            m_p_data    (other.m_p_data);
            m_maxSize   (other.m_maxSize);
            m_size      (other.m_size);

            other.m_p_data  = nullptr;
            other.m_size    = 0;
            other.m_maxSize = 0;

            return *this;
        }

        Vector ( Vector& other )  //Copy constructor
        {
            *this = other;//Uses the copy assignment for this class
        }

        Vector& operator =(Vector& other)   //Copy assignment
        {
            clear();
            for (size_t i = 0 ; i < other.size() ; i++)
            {
                push_back( other[i] );
            }
            return *this;
        }

        ~Vector()
        {
            clear();
        }

        void clear()
        {
            for (size_t i = 0 ; i < m_size ; i++)
            {
                m_p_data[i]->~T();
            }
            if (m_p_data)
                free(m_p_data);

            m_p_data = nullptr;
            m_maxSize = 0;
            m_size = 0;
        }

        void push_back(T& data)
        {
            if (m_size >= m_maxSize) doubleSize();
            new (m_p_data + m_size) T (data);
            m_size++;
        }

        void push_back(T&& data)
        {
            if (m_size >= m_maxSize) doubleSize();
            new (m_p_data + m_size) T (data);
            m_size++;
        }

        template<typename... Args>
        void emplace_back (Args&&... args)
        {
            if ( m_size >= m_maxSize) doubleSize();
            new (m_p_data + m_size) T (std::forward<Args>(args)...);
            m_size++;
        }

        size_t size () const { return m_size; }

        T& get       (size_t index)       { return m_p_data[index]; }
        const T& get (size_t index) const { return m_p_data[index]; }

    private:

        void doubleSize()
        {
            if ( m_size == 0 ) m_maxSize = 1;
            else
            {
                m_maxSize *= 2;
            }

            Pointer newArray = (T*) malloc (sizeof(T) * m_maxSize);

            for (size_t i = 0 ; i < m_size ; i++)
            {
                new (newArray + i) T(m_p_data[i]);
                m_p_data[i].~T();
            }

            free (m_p_data);
            m_p_data = nullptr;
            m_p_data = newArray;
        }



        size_t  m_maxSize   = 0;
        size_t  m_size      = 0;

        Pointer* m_p_data = nullptr;
};


}//Namespace MatLib

#endif // VECTOR_H_INCLUDED
