#include "Tests/performance_test.h"

#include "Memory/Shared_Pointer.h"
#include "Utilities/Function.h"
#include "Memory/Unique_Pointer.h"
#include "Container/Vector.h"
#include <iostream>
#include <String.h>
#include <vector>



void test()
{
    std::cout << "f" << std::endl;
}

int main()
{
    MatLib::Function<void(void)> function(&test);
    function();

}
