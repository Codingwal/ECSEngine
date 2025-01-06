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
    class JsonParser
    {
    public:
        JsonParser(std::string fileName);
        ~JsonParser();
        template <typename T>
        void Serialize(T &data)
        {
            file << "{\n";
            data.Serialize(*this);
            file.seekp(file.tellp() - 2); // Remove last comma
            file << "\n}";
        }
        void Serialize(int value)
        {
            file << std::to_string(value);
        }
        void Serialize(float value)
        {
            file << std::to_string(value);
        }

        template <typename T>
        void Serialize(std::string key, T &value)
        {
            file << "\"" << key << "\": ";
            Serialize(value);
            file << ",\n";
        }

    private:
        std::ofstream file;
    };
}