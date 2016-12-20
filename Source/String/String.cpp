#include "String.h"

namespace MatLib
{
    String& String::operator=(const String& other)
    {
        *m_string = *other.m_string;
        return *this;
    }

    String::String(char* str)
    :   m_string (str)
    {

    }

    const char* String::data() const
    {
        return m_string;
    }

    std::ostream& operator<<(std::ostream& stream, const String& str)
    {
        stream << str.data();
        return stream;
    }
}
