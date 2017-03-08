#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Vector.h"

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
                m_stack.erase(m_stack.size() - 1);
            }

            T& top()
            {
                return m_stack.get(m_stack.size() - 1);
            }

        private:
            Vector<T> m_stack;

    };
}

#endif // STACK_H_INCLUDED
