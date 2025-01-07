#include <Engine/World/World.hpp>
#include <Engine/Math/Math.hpp>
#include <iostream>
#include <Engine/ECS/Components.hpp>
#include "Systems.hpp"
#include <stdlib.h>

#include <Engine/Utility/JSONSerializer.hpp>
#include <Engine/Utility/JSONDeserializer.hpp>

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
    void Serialize(JSONSerializer &s) const
    {
        s.Serialize("x", x);
        s.Serialize("y", y);
        s.Serialize("z", z);
    }
    void Deserialize(JSONDeserializer &d)
    {
        d.Deserialize("x", x);
        d.Deserialize("y", y);
        d.Deserialize("z", z);
    }
};
struct Data
{
    int someValue;
    Int3 someVector;
    void Serialize(JSONSerializer &s) const
    {
        s.Serialize("someValue", someValue);
        s.Serialize("someVector", someVector);
    }
    void Deserialize(JSONDeserializer &d)
    {
        d.Deserialize("someValue", someValue);
        d.Deserialize("someVector", someVector);
    }
};
int main(int argc, char **argv)
{
    using namespace ECSEngine;

    // Data data = Data{.someValue = 5.67483, .someVector = Int3{.x = 1, .y = 2, .z = 3}};
    // JSONSerializer s("C:/Users/flori/Documents/Coding/C++/ECSEngine/include/Engine/ressources/meshes/Test2.json");
    // s.Serialize(data);
    // s.~JSONSerializer();

    Data data;
    JSONDeserializer d("C:/Users/flori/Documents/Coding/C++/ECSEngine/include/Engine/ressources/meshes/Test2.json");
    d.Deserialize(data);

    std::cout << "\n===========================\n\n"
              << data.someValue << "; (" << data.someVector.x << ", " << data.someVector.y << ", " << data.someVector.z << ")\n";
}