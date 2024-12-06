#include <iostream>
#include "engine/Interface/World.cpp"
#include "Components.hpp"
#include "Systems.hpp"

int main(int argc, char **argv)
{
    using namespace ECSEngine;

    World world = World();

    Entity e = world.CreateEntity<Position, Velocity, Acceleration>();
    world.SetComponentData(e, Acceleration(1, 1, 1));

    e = world.CreateEntity<Position, Velocity, Acceleration>();
    world.SetComponentData(e, Acceleration(2, 2, 2));

    e = world.CreateEntity<Position, Velocity>();
    world.SetComponentData(e, Velocity(5, 5, 5));

    world.systemManager.RegisterSystem<PositionSystem>();
    world.systemManager.RegisterSystem<VelocitySystem>();

    const float precision = 100;
    const float seconds = 10;
    const float dt = 1 / precision;

    for (int i = 0; i < precision * seconds; i++)
    {
        world.systemManager.Update(world, dt);
    }

    for (Entity entity : EntityQueryGeneric<Position, Velocity>(world).GetEntities())
    {
        std::cout << entity.ToString() << ": " << world.GetComponentData<Position>(entity).ToString() << "; " << world.GetComponentData<Velocity>(entity).ToString() << "\n";
    }
}