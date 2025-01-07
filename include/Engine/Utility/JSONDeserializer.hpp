#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace ECSEngine
{
    class JSONDeserializer
    {
    public:
        JSONDeserializer(const std::string &fileName);

        template <typename T>
        void Deserialize(T &dest);

        void Deserialize(int &dest);
        void Deserialize(float &dest);
        void Deserialize(std::string &dest);
        void Deserialize(bool &dest);

        template <typename T>
        void Deserialize(const std::string &key, T &dest);

    private:
        enum ObjectType
        {
            OBJECT,
            INT,
            FLOAT,
            STRING,
            BOOL,
        };

    private:
        void
        SkipWhitespaces();
        void Consume(char c);
        void PrintStringToParse();
        void Error(std::string msg);
        void CheckType(ObjectType expectedType);

    private:
        std::string str;
        size_t pos = 0;
    };
}

#include "JSONDeserializer.tpp"