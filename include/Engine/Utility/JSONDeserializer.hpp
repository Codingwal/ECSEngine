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
}

#include "JSONDeserializer.tpp"