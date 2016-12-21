#include "Container/Linked_List.h"
#include "Container/Vector.h"
#include "Container/Tree_Map.h"
#include "System/Clock.h"

#include <map>
#include <cstdlib>

int main()
{
    MatLib::Tree_Map<int, std::string> tree;
    std::map<int, std::string> tree2;

    int itrs = 10000;

    MatLib::Clock clockMat;
    for (int i = 0 ; i < itrs ;i++)
    {
        tree.insert(i, "Test");
        tree.get(i);
    }
    std::cout << clockMat.getElapsedTime() << std::endl;

    MatLib::Clock clockStd;
    for (int i = 0 ; i < itrs ;i++)
    {
        tree2.insert(std::make_pair(i, "Test"));
        tree2.at(i);
    }
    std::cout << clockStd.getElapsedTime() << std::endl;

    return EXIT_SUCCESS;
}
