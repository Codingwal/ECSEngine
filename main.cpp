#include <stdio.h>
#include <iostream>
#include "Core/Structs.hpp"
#include "World.hpp"

struct Position
{
    float x, y, z;
};
struct Rotation
{
    float x, y, z;
};
struct Scale
{
    float x, y, z;
};
int main(int argc, char **argv)
{
    World world = World();

    ComponentType positionType = world.componentManager.RegisterComponent<Position>();
    ComponentType rotationType = world.componentManager.RegisterComponent<Rotation>();
    ComponentType scaleType = world.componentManager.RegisterComponent<Scale>();

    ComponentType components[2] = {positionType, scaleType};

    world.entityManager.CreateEntity(ComponentSet(components, 2));
    world.entityManager.CreateEntity(ComponentSet(components, 1));
    world.entityManager.CreateEntity(ComponentSet(components, 2));

    std::cout << world.entityManager.EntitiesToString() << "\n";
}