#include <string>
#include <iostream>

void Assert(bool condition, std::string errorMessage)
{
    if (!condition)
    {
        std::cout << "[FATAL]: Assertion failed: " << errorMessage << "\n";
        throw std::exception();
    }
}
void Assert(bool condition)
{
    if (!condition)
    {
        std::cout << "[FATAL]: Assertion failed.\n";
        throw std::exception();
    }
}