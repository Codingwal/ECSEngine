#include "Utility/JSONDeserializer.hpp"
#include <sstream>

namespace ECSEngine
{
    JSONDeserializer::JSONDeserializer(const std::string &fileName)
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
        if (str[pos] == '\"')
            Error(Formatter() << "Expected integer but found string");

        size_t valueSize;
        dest = std::stoi(str.substr(pos), &valueSize);
        pos += valueSize;

        if (str[pos] == '.')
            Error(Formatter() << "Expected integer but found floating point value");
    }
    void JSONDeserializer::Deserialize(float &dest)
    {
        if (str[pos] == '\"')
            Error(Formatter() << "Expected floating point value but found string");

        size_t valueSize;
        dest = std::stof(str.substr(pos), &valueSize);
        pos += valueSize;
    }
    void JSONDeserializer::Deserialize(std::string &dest)
    {
        Consume('\"');
        dest.clear();
        for (; str[pos] != '\"'; pos++)
        {
            dest.push_back(str[pos]);
        }
        Consume('\"');
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
            Error(Formatter() << "Expected char '" << c << "' but found '" << str.at(pos - 1) << "'");
        }
    }
    void JSONDeserializer::PrintStringToParse()
    {
        std::cout << "String to parse: \"" << &str[pos] << "\"\n";
    }
    void JSONDeserializer::Error(std::string msg)
    {
        throw std::runtime_error(Formatter() << "ERROR: JSONDeserializer: " << msg << " at position " << pos << ".\n"
                                             << "String left to parse: \"" << &str[pos] << "\"\n");
    }
}