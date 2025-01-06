#pragma once

#include <map>
#include <string>
#include <cstdint>
#include <vector>
#include <iostream>
#include <fstream>
#include "ArenaAllocator.hpp"
#include <cassert>

namespace ECSEngine
{
    class JSONSerializer
    {
    public:
        JSONSerializer(std::string fileName);
        ~JSONSerializer();

        template <typename T>
        void Serialize(T &data);
        void Serialize(int value);
        void Serialize(float value);

        template <typename T>
        void Serialize(std::string key, T &value);

    private:
        std::ofstream file;
    };
}

#include "JSONSerializer.tpp"