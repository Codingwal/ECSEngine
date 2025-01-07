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

        // Skip ',' if present
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
}