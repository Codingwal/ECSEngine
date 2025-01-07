#include "Formatter.hpp"

namespace ECSEngine
{
    template <typename T>
    inline void JSONDeserializer::Deserialize(T &dest)
    {
        CheckType(ObjectType::OBJECT);

        Consume('{');
        dest.Deserialize(*this);
        SkipWhitespaces();
        Consume('}');
    }

    template <typename T>
    inline void JSONDeserializer::Deserialize(const std::string &key, T &dest)
    {
        SkipWhitespaces();

        if (str.at(pos) == ',')
            pos++;

        SkipWhitespaces();
        Consume('"');

        // Parse key
        std::string k;
        for (; str.at(pos) != '"'; pos++)
        {
            k.push_back(str.at(pos));
        }

        if (k != key)
        {
            Error(Formatter() << "Expected key \"" << key << "\" but found \"" << k << "\"\n");
        }

        Consume('"');
        Consume(':');
        SkipWhitespaces();
        Deserialize(dest);
    }
    template <typename T>
    inline void JSONDeserializer::Deserialize(std::vector<T> &dest)
    {
        CheckType(ObjectType::ARRAY);

        Consume('[');
        dest.clear();
        SkipWhitespaces();
        while (str[pos] != ']')
        {
            dest.resize(dest.size() + 1); // Make space for a new element
            Deserialize(dest[dest.size() - 1]);

            if (str[pos] == ',')
                pos++;

            SkipWhitespaces();
        }
        Consume(']');
    }
}