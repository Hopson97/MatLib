#include "Container/Linked_List.h"

#include <iostream>

struct Object
{
    Object(int x, int y) {}
};

int main()
{
    MatLib::Linked_List<int> list;

    for (int i = 0 ; i < 5 ; i++)
    {
        list.push_back(i);
    }

    //list.erase(list.begin() + 3);
/*
    for (auto it = list.begin() ; it != list.end() ; it++)
    {
        std::cout << *it << "\n";
    }

    for (auto& i : list)
    {
        std::cout << i << "\n";
    }
*/
    std::cout << "\nSuccess! Press anything to continue\n" << std::endl;
    std::cin.ignore();
}
