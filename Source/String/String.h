#ifndef STRING_H
#define STRING_H

#include <ostream>

namespace MatLib
{

class String
{
    public:
        String() = default;
        String(const char* str);

        String& operator= (const String& other);

        void operator << (std::ostream& stream);


    protected:

    private:
        char* m_string;
};

}

#endif // STRING_H
