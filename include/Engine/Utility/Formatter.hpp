#pragma once

#include <sstream>

class Formatter
{
public:
    template <typename T>
    Formatter &operator<<(const T &value)
    {
        stream << value;
        return *this;
    }

    std::string str() const { return stream.str(); }
    operator std::string() const { return stream.str(); }

private:
    std::stringstream stream;
};