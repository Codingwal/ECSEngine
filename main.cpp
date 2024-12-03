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

    Entity e = world.entityManager.CreateEntity(posRot, 2);

    *(Rotation *)world.entityManager.GetComponentRef(e, rotationType.id) = Rotation(10, 5, 3); // SetComponentData(e, Rotation(10, 5, 3))

    std::cout << world.entityManager.EntitiesToString() << "\n";
    std::cout << world.entityManager.ArchetypesToString() << "\n";

    world.entityManager.RemoveComponents(e, pos, 1);

    std::cout << "print\n";
    std::cout << world.entityManager.EntitiesToString() << "\n";
    std::cout << world.entityManager.ArchetypesToString() << "\n";

    std::cout << "print(GetComponentData<Rotation>(e))\n";
    std::cout << (*(Rotation *)world.entityManager.GetComponentRef(e, rotationType.id)).ToString() << "\n"; // print(GetComponentData<Rotation>(e))

    std::cout << world.entityManager.EntitiesToString() << "\n";
    std::cout << world.entityManager.ArchetypesToString() << "\n";
}