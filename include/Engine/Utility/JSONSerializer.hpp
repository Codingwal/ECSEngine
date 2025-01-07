#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace ECSEngine
{
    class JSONSerializer
    {
    public:
        JSONSerializer(const std::string &fileName);
        ~JSONSerializer();

        template <typename T>
        void Serialize(const T &data);

        void Serialize(int data);
        void Serialize(float data);
        void Serialize(const std::string &data);
        void Serialize(bool data);

        template <typename T>
        void Serialize(const std::string &key, const T &data);

    private:
        std::ofstream file;
    };
}

#include "JSONSerializer.tpp"