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
    ComponentType posScl[2] = {positionType, scaleType};

    Entity e1 = world.entityManager.CreateEntity(posRot, 2);
    Entity e2 = world.entityManager.CreateEntity(posScl, 2);
    Entity e3 = world.entityManager.CreateEntity(posRot, 2);

    *(Position *)world.entityManager.GetComponentRef(e3, positionType.id) = Position(10, 5, 3);

    std::cout << (*(Position *)world.entityManager.GetComponentRef(e3, positionType.id)).ToString() << "\n";

    world.entityManager.DestroyEntity(e1);

    std::cout << (*(Position *)world.entityManager.GetComponentRef(e3, positionType.id)).ToString() << "\n";

    // std::cout << world.entityManager.EntitiesToString() << "\n";
    // std::cout << world.entityManager.ArchetypesToString() << "\n";
}