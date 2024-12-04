#include <stdio.h>
#include <iostream>
#include "Core/Structs.hpp"
#include "World.hpp"
#include "Components.hpp"
#include "Entities/EntityQueryGeneric.hpp"

int main(int argc, char **argv)
{
    World world = World();

    Entity e;
    e = world.CreateEntity<Position, Rotation, Scale>();
    world.SetComponentData(e, Rotation(90, 0, 90));
    world.SetComponentData(e, Scale(2, 2, 2));
    e = world.CreateEntity<Position, Rotation, Scale>();
    world.SetComponentData(e, Rotation(180, 0, 90));
    world.SetComponentData(e, Position(10, 0, 10));
    e = world.CreateEntity<Rotation, Scale>();
    world.SetComponentData(e, Scale(1, 1, 1));

    for (Entity entity : EntityQueryGeneric<Rotation>(world).GetEntities())
    {
        std::cout << entity.ToString() << ": " << world.GetComponentData<Rotation>(entity).ToString() << "\n";
    }
}