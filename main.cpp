#include <stdio.h>
#include <iostream>
#include "Core/Structs.hpp"
#include "World.hpp"
#include "Components.hpp"

int main(int argc, char **argv)
{
    World world = World();

    ComponentType positionType = world.componentManager.RegisterComponent<Position>();
    ComponentType rotationType = world.componentManager.RegisterComponent<Rotation>();
    ComponentType scaleType = world.componentManager.RegisterComponent<Scale>();

    ComponentType posRot[2] = {positionType, rotationType};
    ComponentType pos[1] = {positionType};

    Entity e = world.CreateEntity(posRot, 2);

    world.SetComponentData(e, Rotation(10, 5, 3));

    world.RemoveComponent<Position>(e);

    world.AddComponent<Scale>(e);
    world.SetComponentData(e, Scale(1, 1, 1));

    std::cout << world.GetComponentData<Rotation>(e).ToString() << "\n";
    std::cout << world.GetComponentData<Scale>(e).ToString() << "\n\n";

    std::cout << world.entityManager.EntitiesToString() << "\n";
    std::cout << world.entityManager.ArchetypesToString() << "\n";
}