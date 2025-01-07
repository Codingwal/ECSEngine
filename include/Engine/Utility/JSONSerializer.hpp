#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace ECSEngine
{
    class JSONSerializer
    {
    public:
        JSONSerializer(std::string fileName);
        ~JSONSerializer();

        template <typename T>
        void Serialize(T &data);
        void Serialize(int data);
        void Serialize(float data);

        template <typename T>
        void Serialize(std::string key, T &data);

    private:
        std::ofstream file;
    };
}

#include "JSONSerializer.tpp"