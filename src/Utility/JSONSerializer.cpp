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
        file << value;
    }
    void JSONSerializer::Serialize(float value)
    {
        file << value;
    }
    void JSONSerializer::Serialize(const std::string &value)
    {
        file << '\"' << value << '\"';
    }
    void JSONSerializer::Serialize(bool value)
    {
        if (value)
            file << "true";
        else
            file << "false";
    }
}