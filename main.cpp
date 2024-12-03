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
    ComponentType scl[1] = {scaleType};

    Entity e = world.entityManager.CreateEntity(posRot, 2);

    *(Position *)world.entityManager.GetComponentRef(e, positionType.id) = Position(10, 5, 3); // SetComponentData(e, Position(10, 5, 3))

    std::cout << world.entityManager.EntitiesToString() << "\n";
    std::cout << world.entityManager.ArchetypesToString() << "\n";

    world.entityManager.AddComponents(e, scl, 1);

    std::cout << (*(Position *)world.entityManager.GetComponentRef(e, positionType.id)).ToString() << "\n"; // print(GetComponentData<Position>(e))

    std::cout << world.entityManager.EntitiesToString() << "\n";
    std::cout << world.entityManager.ArchetypesToString() << "\n";
}