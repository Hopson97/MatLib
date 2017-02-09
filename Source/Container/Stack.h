#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <Vector.h>

namespace MatLib
{
    template<typename T>
    class Stack
    {
        public:
            void push(T& data)
            {
                m_stack.push_back(data);
            }

            void pop()
            {
                m_stack.
            }

        private:
            Vector<T> m_stack;

    };
}

#endif // STACK_H_INCLUDED
