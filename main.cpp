#include <iostream>
#include "engine/Interface/World.cpp"
#include "Components.hpp"
#include "engine/EntityQuery/EntityQueryGeneric.hpp"

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

    const float precision = 1000;
    const float seconds = 10;
    const float dt = 1 / precision;

    EntityQueryGeneric<Velocity, Acceleration> velAccQuery(world);
    EntityQueryGeneric<Position, Velocity> posVelQuery(world);
    for (int i = 0; i < precision * seconds; i++)
    {
        // Update velocity
        for (Entity entity : velAccQuery.GetEntities())
        {
            world.GetComponentDataRef<Velocity>(entity).value += world.GetComponentData<Acceleration>(entity).value * dt;
        }

        // Update position
        for (Entity entity : posVelQuery.GetEntities())
        {
            world.GetComponentDataRef<Position>(entity).value += world.GetComponentData<Velocity>(entity).value * dt;
        }
    }

    for (Entity entity : EntityQueryGeneric<Position, Velocity>(world).GetEntities())
    {
        std::cout << entity.ToString() << ": " << world.GetComponentData<Position>(entity).ToString() << "; " << world.GetComponentData<Velocity>(entity).ToString() << "\n";
    }
}