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
        CheckType(ObjectType::INT);

        size_t valueSize;
        dest = std::stoi(str.substr(pos), &valueSize);
        pos += valueSize;

        if (str[pos] == '.')
            Error(Formatter() << "Expected integer but found floating point value");
    }
    void JSONDeserializer::Deserialize(float &dest)
    {
        CheckType(ObjectType::FLOAT);

        size_t valueSize;
        dest = std::stof(str.substr(pos), &valueSize);
        pos += valueSize;
    }
    void JSONDeserializer::Deserialize(std::string &dest)
    {
        CheckType(ObjectType::STRING);

        Consume('\"');
        dest.clear();
        for (; str[pos] != '\"'; pos++)
        {
            dest.push_back(str[pos]);
        }
        Consume('\"');
    }
    void JSONDeserializer::Deserialize(bool &dest)
    {
        CheckType(ObjectType::BOOL);

        std::string tmp;
        for (; std::isalpha(str[pos]); pos++)
        {
            tmp.push_back(str[pos]);
        }
        if (tmp == "true")
            dest = true;
        else if (tmp == "false")
            dest = false;
        else
            Error(Formatter() << "Invalid boolean \"" << tmp << "\" (should be \"true\" or \"false\")");
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
    void JSONDeserializer::CheckType(ObjectType expectedType)
    {
        auto TypeToString = [](ObjectType type)
        {
            switch (type)
            {
            case ObjectType::OBJECT:
                return "object";
            case ObjectType::INT:
                return "integer";
            case ObjectType::FLOAT:
                return "floating point value";
            case ObjectType::STRING:
                return "string";
            case ObjectType::BOOL:
                return "boolean";
            default:
                throw std::exception();
            }
        };
        ObjectType actualType;
        switch (str[pos])
        {
        case '{':
            actualType = ObjectType::OBJECT;
            break;
        case '\"':
            actualType = ObjectType::STRING;
            break;
        case 't':
            actualType = ObjectType::BOOL;
            break;
        case 'f':
            actualType = ObjectType::BOOL;
            break;
        default:
            if (std::isdigit(str[pos]))
                actualType = ObjectType::INT;
            else
                Error(Formatter() << "Expected " << TypeToString(expectedType) << " but found an invalid object");
        }

        if (actualType != expectedType                                                // Expected a different type than actually present
            && !(actualType == ObjectType::INT && expectedType == ObjectType::FLOAT)) // Floats and integers are not differentiated at this point
            Error(Formatter() << "Expected " << TypeToString(expectedType) << " but found " << TypeToString(actualType));
    }
    void JSONDeserializer::Error(std::string msg)
    {
        throw std::runtime_error(Formatter() << "ERROR: JSONDeserializer: " << msg << " at position " << pos << ".\n"
                                             << "String left to parse: \"" << &str[pos] << "\"\n");
    }
}