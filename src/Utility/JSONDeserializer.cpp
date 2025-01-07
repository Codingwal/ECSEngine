#include "Utility/JSONDeserializer.hpp"

namespace ECSEngine
{
    JSONDeserializer::JSONDeserializer(std::string fileName)
    {
        std::ifstream file(fileName);
        std::string line;
        while (std::getline(file, line))
        {
            str.append(line);
        }
        file.close();
    }
    void JSONDeserializer::Deserialize(int &dest)
    {
        size_t valueSize;
        dest = std::stoi(str.substr(pos), &valueSize);
        pos += valueSize;
    }
    void JSONDeserializer::Deserialize(float &dest)
    {
        size_t valueSize;
        dest = std::stof(str.substr(pos), &valueSize);
        pos += valueSize;
    }
    void JSONDeserializer::SkipWhitespaces()
    {
        for (; std::isspace(str.at(pos)); pos++)
        {
        }
    }
    void JSONDeserializer::Consume(char c)
    {
        if (str.at(pos++) != c)
        {
            std::cerr << "Expected char '" << c << "' but found '" << str.at(pos - 1) << "'\n";
        }
    }
    void JSONDeserializer::PrintStringToParse()
    {
        std::cout << "String to parse: \"" << &str[pos] << "\"\n";
    }
}