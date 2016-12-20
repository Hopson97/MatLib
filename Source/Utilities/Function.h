#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

namespace MatLib
{
    template<typename Ret, typename... Args>
    class Function;

    template<typename Ret, typename... Args>
    class Function<Ret(Args...)>
    {
        using Func = Ret(*)(Args...);

        public:
            Function(Func func)
            :   m_function(func)
            { }
/*
            template<typename T>
            Function(Ret(T::*func)(Args...), T& obj)
            :   m_function (func)
            {

            }
*/
            Ret operator()()
            {
                return m_function();
            }

        private:
            Func m_function;

    };


}

#endif // FUNCTION_H_INCLUDED
