#include <stdio.h>
#include <iostream>
#include "Core/Structs.hpp"
#include "World.hpp"
#include "Components.hpp"
#include "Entities/EntityQueryGeneric.hpp"

int main(int argc, char **argv)
{
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

    for (int i = 0; i < precision * seconds; i++)
    {
        // Update velocity
        for (Entity entity : EntityQueryGeneric<Velocity, Acceleration>(world).GetEntities())
        {
            Velocity v = world.GetComponentData<Velocity>(entity);
            Acceleration a = world.GetComponentData<Acceleration>(entity);
            v.value += a.value * dt;
            world.SetComponentData(entity, v);
        }

        // Update position
        for (Entity entity : EntityQueryGeneric<Position, Velocity>(world).GetEntities())
        {
            Position p = world.GetComponentData<Position>(entity);
            Velocity v = world.GetComponentData<Velocity>(entity);
            p.value += v.value * dt;
            world.SetComponentData(entity, p);
        }
    }

    for (Entity entity : EntityQueryGeneric<Position, Velocity>(world).GetEntities())
    {
        std::cout << entity.ToString() << ": " << world.GetComponentData<Position>(entity).ToString() << "; " << world.GetComponentData<Velocity>(entity).ToString() << "\n";
    }
}