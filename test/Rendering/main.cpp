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

    Entity entity = world.CreateEntity<Transform, TransformMatrix>();
    world.SetComponentData(entity, Transform(Float3(0, 0, -5), Float3(-0, 0, 0), Float3(1)));

    entity = world.CreateEntity<Transform, TransformMatrix>();
    world.SetComponentData(entity, Transform(Float3(0, 0, -10), Float3(-0, 0, 0), Float3(1)));

    entity = world.CreateEntity<Transform, TransformMatrix>();
    world.SetComponentData(entity, Transform(Float3(0, 0, -15), Float3(-0, 0, 0), Float3(1)));

    entity = world.CreateEntity<Transform, TransformMatrix>();
    world.SetComponentData(entity, Transform(Float3(0, 0, -20), Float3(-0, 0, 0), Float3(1)));

    entity = world.CreateEntity<Transform, TransformMatrix>();
    world.SetComponentData(entity, Transform(Float3(0, 0, -25), Float3(-0, 0, 0), Float3(1)));

    world.systemManager.RegisterSystem<CollisionSystem>();

    world.Run(1000000);
}