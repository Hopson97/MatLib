#include "String.h"

namespace MatLib
{
    String& String::operator=(const String& other)
    {
        *m_string = *other.m_string;
        return *this;
    }

    String::String(const char* str)
    :   m_string ()
    {

    }


    void String::operator<<(std::ostream& stream)
    {
        stream << *m_string;
    }


}
