#include <iostream>

#include "System/Clock.h"
#include "Container/Linked_List.h"
#include "Container/Vector.h"
#include "Container/Forward_List.h"

#include "Memory/Unique_Pointer.h"


//Test Class
struct Vertex
{
    Vertex() = default;
    Vertex( int x, int y, int z )
    :   x ( x )
    ,   y ( y )
    ,   z ( z ) {}

    float x, y, z;

    void print()
    {
        std::cout   << " X: " << x
                    << " Y: " << y
                    << " Z: " << z << std::endl << std::endl;
    }
};

size_t TRIALS = 230;
size_t ELEMENTS = 2'147'000;

template <typename T>
void testContainerTime ( const std::string& which )
{
    std::cout   << std::endl
                << "This is trial that will create a container, emplace "
                << ELEMENTS
                << " into it, and repeat this process "
                << TRIALS
                << " times."
                << std::endl;

    MatLib::Clock clock;
    for ( size_t i = 0 ; i < TRIALS ; i++ )
    {
        T t;
        for ( size_t e = 0 ; e < ELEMENTS ; e++ )
        {
            t.emplace_back( i, i, i );
            //t[i];
        }
        t.clear();
    }
    double time = clock.getElapsedTime();

    std::cout   << "Time for " << which << " Container: " << time << std::endl;
    std::cout   << "With " << TRIALS << " trials and " << ELEMENTS << " elements, this makes the average time for a trial: "
                << time / TRIALS << std::endl;
}


int main()
{
    testContainerTime<MatLib::Vector<Vertex>>       ( "MatLib::Vector" );
    testContainerTime<MatLib::Linked_List<Vertex>>  ( "MatLib::Linked_List" );
    testContainerTime<MatLib::Forward_List<Vertex>> ( "MatLib::Forward_List" );

    std::cout << "Finished. Press anything to exit." << std::endl;
    std::cin.ignore();

    return 0;
}
