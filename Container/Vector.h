#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

namespace MatLib
{
template<typename T>
class Vector
{
    public:
        Vector () = default;

        Vector ( size_t initialSize )
        :   m_maxSize   ( initialSize)
        {
            if ( !m_maxSize == 0 )
                m_p_data = (T*) malloc ( sizeof ( T ) * m_maxSize );
        }

        ~Vector()
        {
            clear();
        }

        void clear()
        {
            for ( size_t i = 0 ; i < m_size ; i++ )
            {
                m_p_data[i].~T();
            }
            if ( m_p_data )
                free( m_p_data );

            m_p_data = nullptr;
            m_maxSize = 0;
        }

        void push_back( T& data )
        {
            if ( m_size >= m_maxSize) doubleSize();
            new ( m_p_data + m_size ) T ( data );
            m_size++;
        }

        template<typename... Args>
        void emplace_back ( Args... args )
        {
            if ( m_size >= m_maxSize) doubleSize();
            new ( m_p_data + m_size ) T ( std::forward<Args>(args)... );
            m_size++;
        }

        size_t size ()
        {
            return m_size;
        }

        T& operator []( size_t index )
        {
            return m_p_data[index];
        }

    private:
        void doubleSize()
        {
            if ( m_size == 0 ) m_maxSize = 1;
            else
            {
                m_maxSize *= 2;
            }

            T* newArray = (T*) malloc ( sizeof(T) * m_maxSize );

            for ( size_t i = 0 ; i < m_size ; i++ )
            {
                new ( newArray + i ) T( std::move ( m_p_data[i] ) );
                m_p_data[i].~T();
            }

            free ( m_p_data );
            m_p_data = nullptr;
            m_p_data = newArray;
        }


        size_t  m_size      = 0;
        size_t  m_maxSize   = 0;

        T*      m_p_data    = nullptr;
};


}//Namespace MatLib

#endif // VECTOR_H_INCLUDED