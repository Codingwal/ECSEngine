#include <stdio.h>
#include <iostream>
#include "Core/Structs.hpp"
#include "World.hpp"
#include "Components.hpp"
#include "Entities/EntityQuery.hpp"

int main(int argc, char **argv)
{
    World world = World();

    ComponentType positionType = world.componentManager.RegisterComponent<Position>();
    ComponentType rotationType = world.componentManager.RegisterComponent<Rotation>();
    ComponentType scaleType = world.componentManager.RegisterComponent<Scale>();

    ComponentType posRot[2] = {positionType, rotationType};
    ComponentType rot[1] = {rotationType};

    world.SetComponentData(world.CreateEntity(posRot, 2), Rotation(10, 5, 3));
    world.SetComponentData(world.CreateEntity(posRot, 2), Position(1, 1, 1));
    world.SetComponentData(world.CreateEntity(&positionType, 1), Position(1, 1, 1));
    world.SetComponentData(world.CreateEntity(&rotationType, 1), Rotation(9, 9, 9));

    EntityQuery rotQuery = EntityQuery(ComponentSet(rot, 1));
    for (Entity entity : rotQuery.GetEntities(world.entityManager))
    {
        std::cout << entity.ToString() << ": " << world.GetComponentData<Rotation>(entity).ToString() << "\n";
    }
}