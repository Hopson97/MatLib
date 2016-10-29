#include <iostream>

#include <vector>
#include <list>
#include <forward_list>

#include "../System/Clock.h"
#include "../Container/Linked_List.h"
#include "../Container/Vector.h"

#include "../Memory/Unique_Pointer.h"

/*
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

    void stuff() { }
};
*/
size_t TRIALS = 100;
size_t ELEMENTS = 1000000;

/*
 * This will test not only performance, but also the functionality of the containers eg if their
 * "rule of 6" works.
 */

 /*
template <typename T>
void testContainerTime ( const std::string& which )
{
    MatLib::Clock clock;
    for ( size_t i = 0 ; i < TRIALS ; i++ )
    {
        T t;
        for ( size_t e = 0 ; e < ELEMENTS ; e++ )
        {
            t.emplace_back( i, i, i );
        }
        T t2 = t;
        t.clear();
        t2[ t2.size() / 2 ];
        t2.clear();
    }
    double time = clock.getElapsedTime();

    std::cout   << "Time for " << which << " Container: " << time
                << std::endl;
    std::cout   << "With " << TRIALS << " trials and " << ELEMENTS << " elements, this makes the average time for a trial: "
                << time / TRIALS << std::endl << std::endl;
}
*/
/*
void startTimeTest()
{
    std::cout   << std::endl
                << "This is trial that will create a container, emplace "
                << ELEMENTS
                << " into it, and repeat this process "
                << TRIALS
                << " times."
                << std::endl;

    testContainerTime<MatLib::Vector<Vertex>>       ( "MatLib::Vector" );
    testContainerTime<MatLib::Linked_List<Vertex>>  ( "MatLib::Linked_List" );

    testContainerTime<std::vector<Vertex>>          ( "std::vector" );

    std::cout << "Finished. Press anything to exit." << std::endl;
    std::cin.ignore();

}
*/
