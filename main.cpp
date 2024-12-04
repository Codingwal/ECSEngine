#include <stdio.h>
#include <iostream>
#include "Core/Structs.hpp"
#include "World.hpp"
#include "Components.hpp"
#include "Entities/EntityQuery.hpp"

int main(int argc, char **argv)
{
    World world = World();

    ComponentType posType = world.componentManager.GetOrRegisterComponent<Position>();
    ComponentType rotType = world.componentManager.GetOrRegisterComponent<Rotation>();
    ComponentType sclType = world.componentManager.GetOrRegisterComponent<Scale>();

    ComponentType posRotScl[] = {posType, rotType, sclType};
    ComponentType rotScl[] = {rotType, sclType};

    Entity e;
    e = world.CreateEntity(posRotScl, 3);
    world.SetComponentData(e, Rotation(90, 0, 90));
    world.SetComponentData(e, Scale(2, 2, 2));
    e = world.CreateEntity(posRotScl, 3);
    world.SetComponentData(e, Rotation(180, 0, 90));
    world.SetComponentData(e, Position(10, 0, 10));
    e = world.CreateEntity(rotScl, 2);
    world.SetComponentData(e, Scale(1, 1, 1));

    EntityQuery rotQuery = EntityQuery(ComponentSet(&rotType, 1));
    for (Entity entity : rotQuery.GetEntities(world.entityManager))
    {
        std::cout << entity.ToString() << ": " << world.GetComponentData<Rotation>(entity).ToString() << "\n";
    }
}