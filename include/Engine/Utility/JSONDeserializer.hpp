#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace ECSEngine
{
    class JSONDeserializer
    {
    public:
        JSONDeserializer(std::string fileName);

        template <typename T>
        void Deserialize(T &dest);

        void Deserialize(int &dest);
        void Deserialize(float &dest);

        template <typename T>
        void Deserialize(std::string key, T &dest);

    private:
        void SkipWhitespaces();
        void Consume(char c);
        void PrintStringToParse();

    private:
        std::string str;
        size_t pos = 0;
    };

    template <typename T>
    inline void JSONDeserializer::Deserialize(T &dest)
    {
        SkipWhitespaces();
        Consume('{');
        dest.Deserialize(*this);
        SkipWhitespaces();
        Consume('}');
    }

    template <typename T>
    inline void JSONDeserializer::Deserialize(std::string key, T &dest)
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
            std::cerr << "Expected key \"" << key << "\" but found \"" << k << "\"\n";
        }

        Consume('"');
        Consume(':');
        Deserialize(dest);
    }
}