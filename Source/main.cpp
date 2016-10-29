#include "Tests/performance_test.h"

#include "Memory/Shared_Pointer.h"

#include <iostream>

struct Test_Object
{
    Test_Object()
    {
        std::cout << "CREATED" << std::endl;
    }

    ~Test_Object()
    {
        std::cout << "DESTROYED" << std::endl;
    }
};

int main()
{
    MatLib::Shared_Pointer<Test_Object> obj = MatLib::makeShared<Test_Object>();
}
