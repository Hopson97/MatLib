#ifndef Unique_Pointer_H_INCLUDED
#define Unique_Pointer_H_INCLUDED

namespace MatLib
{
    template <typename T>
    class Unique_Pointer
    {
        public:
            //Copy constructor and copy assignment are not allowed
            Unique_Pointer  ( const Unique_Pointer& other ) = delete;
            void operator = ( Unique_Pointer& other ) = delete;

            Unique_Pointer() = default;

            Unique_Pointer ( Unique_Pointer&& other )
            {
                m_pointer  = other.m_pointer;
                other.m_pointer = nullptr;
            }

            Unique_Pointer( T* obj )
            {
                m_pointer = obj;
            }

            void operator = ( Unique_Pointer&& other )
            {
                m_pointer = other.m_pointer;
                other.m_pointer = nullptr;
            }

            ~Unique_Pointer()
            {
                delete m_pointer;
            }

            explicit operator bool()
            {
                return m_pointer;
            }

            T& operator *()
            {
                return *m_pointer;
            }

            T& operator ->()
            {
                return *m_pointer;
            }


            T* get()
            {
                return m_pointer;
            }
        private:
            T* m_pointer = nullptr;
    };

    template <typename T, typename... Args>
    Unique_Pointer<T> make_unique( Args&&... args)
    {
        return Unique_Pointer<T>( new T ( std::forward<Args>( args )...) );
    }


}//Namespace MatLib


#endif // Unique_Pointer_H_INCLUDED
