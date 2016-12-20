#ifndef STRING_H
#define STRING_H

#include <ostream>

namespace MatLib
{
    class String
    {
        public:
            String() = default;
            String(char* str);

            String& operator= (const String& other);

            const char* data() const;

        private:
            char* m_string;
    };

    std::ostream& operator<<(std::ostream& stream, const String& str);
}

#endif // STRING_H
