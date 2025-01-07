#include "Utility/JSONSerializer.hpp"

namespace ECSEngine
{
    JSONSerializer::JSONSerializer(const std::string &fileName)
    {
        file.open(fileName, std::ios::binary);
    }
    JSONSerializer::~JSONSerializer()
    {
        file.close();
    }
    void JSONSerializer::Serialize(int value)
    {
        file << std::to_string(value);
    }
    void JSONSerializer::Serialize(float value)
    {
        file << std::to_string(value);
    }
    void JSONSerializer::Serialize(const std::string &value)
    {
        file << '\"' << value << '\"';
    }
}