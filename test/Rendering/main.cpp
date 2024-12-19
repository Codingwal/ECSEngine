#include <Engine/World/World.hpp>
#include <Engine/Math/Math.hpp>
#include <iostream>
#include <Engine/ECS/Components.hpp>
#include "Systems.hpp"

int main(int argc, char **argv)
{
    using namespace ECSEngine;

    World world = World();

    Entity entity = world.CreateEntity<Transform, TransformMatrix>();
    world.SetComponentData(entity, Transform(Float3(-0.7, 0, 0)));

    world.systemManager.RegisterSystem<MovementSystem>();

    world.Run(100000);
}