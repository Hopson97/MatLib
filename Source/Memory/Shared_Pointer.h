#ifndef SHARED_POINTER_H_INCLUDED
#define SHARED_POINTER_H_INCLUDED

#include <utility>
#include <iostream>

namespace MatLib
{
    template<typename T>
    class Shared_Pointer
    {
        public:
            Shared_Pointer () = default;

            Shared_Pointer  (T* obj)
            :   m_pointer   (obj)
            ,   m_refCount  (new int())
            {
                *m_refCount = 1;
            }

            ~Shared_Pointer()
            {
                testForDel();
            };

            explicit operator bool()
            {
                return m_pointer;
            }

            Shared_Pointer& operator =(Shared_Pointer other)
            {
                testForDel();
                m_refCount = other.m_refCount;

                return *this;
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



            int getReferenceCount()
            {
                return *m_refCount;
            }


        private:
            void testForDel()
            {
                if (m_refCount)
                {
                    *m_refCount -= 1;
                    if (*m_refCount == 0)
                    {
                        delete m_refCount;
                        delete m_pointer;
                    }
                }
            }



            T*      m_pointer      = nullptr;
            int*    m_refCount  = nullptr;
    };


    template <typename T, typename... Args>
    Shared_Pointer<T> makeShared( Args&&... args)
    {
        return Shared_Pointer<T>( new T ( std::forward<Args>( args )...) );
    }
}





#endif // SHARED_POINTER_H_INCLUDED
