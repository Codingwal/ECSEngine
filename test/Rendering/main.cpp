#include <Engine/World/World.hpp>
#include <Engine/Math/Math.hpp>
#include <iostream>
#include <Engine/ECS/Components.hpp>
#include "Systems.hpp"
#include <stdlib.h>

float RandomFloat(float min, float max)
{
    float range = max - min;
    float value = rand();
    value /= 100;
    value = fmod(value, range);
    return value + min;
}

int main(int argc, char **argv)
{
    using namespace ECSEngine;

    World world = World();

    for (int i = 0; i < 10; i++)
    {
        Entity entity = world.CreateEntity<Transform, TransformMatrix, PhysicsObject>();
        world.SetComponentData(entity, Transform(Float3(0, RandomFloat(-0.9, 0.9), 0), Float3(0, 0, RandomFloat(0, 360)), Float3(RandomFloat(0.2, 0.7))));
        world.SetComponentData(entity, PhysicsObject(Float3(RandomFloat(0, 2), 0, 0)));
    }

    world.systemManager.RegisterSystem<CollisionSystem>();

    world.Run(100000);
}