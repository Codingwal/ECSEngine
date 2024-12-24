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
    struct JsonData;
    union JsonValue
    {
        int i;
        float f;
        std::vector<JsonData *> list;
        std::map<std::string, JsonData *> objects;
    };
    enum JsonDataType
    {
        Int,
        Float,
        List,
        Object
    };
    struct JsonData
    {
        JsonDataType type;
        JsonValue value;
    };
    class JsonParser
    {
        using StringIt = std::string::iterator;

    public:
        static JsonData *ParseJson(ArenaAllocator &arena, const std::string &fileName)
        {
            std::string text = ReadFile(fileName);
            size_t i = 0;
            return ParseObject(arena, text, i);
        }

    private:
        static std::string ReadFile(const std::string &fileName)
        {
            std::ifstream file(fileName);
            std::string output;
            std::string text;
            while (std::getline(file, text))
            {
                output.append(text);
            }
            file.close();
            return output;
        }

        static JsonData *ParseObject(ArenaAllocator &arena, std::string &text, size_t &i)
        {
            // Skip whitespace
            for (; isspace(text[i]); i++)
            {
            }

            JsonData *data = arena.Allocate<JsonData>();

            // Parse object
            if (text[i] == '{') // Object
            {
                std::cout << "Object\n";

                data->type = JsonDataType::Object;
                data->value.objects = std::map<std::string, ECSEngine::JsonData *>();

                i++;
                while (true)
                {
                    // Skip whitespace
                    for (; isspace(text[i]); i++)
                    {
                    }

                    // Parse key
                    assert(text[i] == '\"');
                    i++; // Consume '\"'
                    size_t startIndex = i;
                    for (; text[i] != '\"'; i++) // Increment until the end of the string is reached
                    {
                    }
                    std::string key = text.substr(startIndex, i - startIndex);
                    std::cout << "Key: \"" << key << "\"\n";
                    i++;                      // Consume '\""
                    assert(text[i++] == ':'); // Consume ':'

                    // Parse value
                    std::cout << "Start ParseObject\n";
                    data->value.objects.insert(std::pair(key, ParseObject(arena, text, i)));
                    std::cout << "Finished ParseObject\n";

                    // Skip whitespace
                    for (; isspace(text[i]); i++)
                    {
                        std::cout << "Skipping " << (int)text[i] << "\n";
                    }

                    if (text[i] == '}')
                        break;
                    assert(text[i] == ',');
                    i++;
                }
            }
            else if (text[i] == '[') // List
            {
                std::cout << "List\n";

                data->type = JsonDataType::List;
                data->value.list = std::vector<ECSEngine::JsonData *>();
            }
            else // Primitive
            {
                std::cout << "Primitive\n";

                // bool floatingPoint = false;
                size_t startIndex = i;
                for (; isdigit(text[i]); i++)
                {
                    // if (i == '.')
                    // floatingPoint = true;
                }
                // if (floatingPoint)
                // data->value.f = std::stof(text.substr(startIndex));
                // else
                data->type = JsonDataType::Int;
                data->value.i = std::stoi(text.substr(startIndex));
                std::cout << "Value: " << data->value.i << "\n";
            }
            return data;
        }
    };
}