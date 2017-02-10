#include "Container/Linked_List.h"
#include "Utilities/Utilities.h"

#include <iostream>

int main()
{
    MatLib::Linked_List<int> list;
    MatLib::Linked_List<int> list2;

    for (int i = 0 ; i < 5 ; i++)
    {
       list.push_back(i);
    }

    for (int i = 5 ; i > 0 ; i--)
    {
        list2.push_back(i);
    }


    for (auto& i : list)
    {
        std::cout << i << "\n";
    }

    /MatLib::swap(list, list2);

    std::cout << "\n";

    for (auto& i : list2)
    {
        std::cout << i << "\n";
    }

    std::cout << "\nSuccess! Press anything to continue\n" << std::endl;
    std::cin.ignore();
}
