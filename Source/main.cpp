#include "Container/Linked_List.h"
#include "Container/Vector.h"
#include "Container/Tree_Map.h"
#include "Container/Array.h"
#include "System/Clock.h"

#include <map>
#include <cstdlib>
#include <vector>

#include <cstdlib>
#include <ctime>

int getRandomInteger(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

class Integer
{
public:
    int i = 0;
    Integer(int i){ this->i = i; }
};

int main()
{
    MatLib::Heap_Array<Integer, 5353> arrayOfMine (5);

    return EXIT_SUCCESS;
}
