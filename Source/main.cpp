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

int main()
{
    MatLib::Linked_List<int> list;

    for (int i = 0 ; i < 50 ; i++ )
    {
        list.addToBack(i);
    }
}
