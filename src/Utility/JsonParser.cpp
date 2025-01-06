#include "Utility/JsonParser.hpp"

namespace ECSEngine
{
    JsonParser::JsonParser(std::string fileName)
    {
        file.open(fileName, std::ios::binary);
    }
    JsonParser::~JsonParser()
    {
        file.close();
    }
}