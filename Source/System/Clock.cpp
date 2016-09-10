#include "clock.h"

#include <cmath>

namespace MatLib
{

typedef std::chrono::high_resolution_clock::time_point Time_Point;

Clock::Clock()
{
    reset();
}

void Clock::reset()
{
    start = getTimeNow();
}

double Clock::getElapsedTime() const
{
    Time_Point endTIme = getTimeNow();
    return std::chrono::duration_cast<std::chrono::microseconds>
           (endTIme - start).count() * pow (10, -6);
}

Time_Point Clock::getTimeNow() const
{
    return std::chrono::high_resolution_clock::now();
}


}//Namespace MatLib
