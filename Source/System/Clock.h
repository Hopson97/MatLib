#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>

namespace MatLib
{

class Clock
{
    typedef std::chrono::high_resolution_clock::time_point Time_Point;

    public:
        Clock();
        void reset();
        double getElapsedTime() const;;

    private:
        Time_Point getTimeNow() const;

        Time_Point start;
};

}//Namespace MatLib

#endif // CLOCK_H
