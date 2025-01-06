#include <Engine/World/World.hpp>
#include <Engine/Math/Math.hpp>
#include <iostream>
#include <Engine/ECS/Components.hpp>
#include "Systems.hpp"
#include <stdlib.h>

#include <Engine/Utility/JsonParser.hpp>

float RandomFloat(float min, float max)
{
    float range = max - min;
    float value = rand();
    value /= 100;
    value = fmod(value, range);
    return value + min;
}
struct Int3
{
    int x;
    int y;
    int z;
    void Serialize(JsonParser &s)
    {
        s.Serialize("x", x);
        s.Serialize("y", y);
        s.Serialize("z", z);
    }
};
struct Data
{
    int someValue;
    Int3 someVector;
    void Serialize(JsonParser &s)
    {
        s.Serialize("someValue", someValue);
        s.Serialize("someVector", someVector);
    }
};
int main(int argc, char **argv)
{
    using namespace ECSEngine;

    Data data = Data{.someValue = 5, .someVector = Int3{.x = 1, .y = 2, .z = 3}};

    JsonParser jsonParser("C:/Users/flori/Documents/Coding/C++/ECSEngine/include/Engine/ressources/meshes/Test2.json");
    jsonParser.Serialize(data);
}