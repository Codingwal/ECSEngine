#include <stdio.h>
#include <iostream>
#include "Core/Structs.hpp"
#include "World.hpp"

struct Position
{
    float x, y, z;
    Position(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    std::string ToString()
    {
        return "Position: {" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "}";
    }
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

    ComponentType posRot[2] = {positionType, rotationType};
    ComponentType posScl[2] = {positionType, scaleType};
    ComponentType pos[1] = {positionType};

    Entity e1 = world.entityManager.CreateEntity(posRot, 2);
    Entity e2 = world.entityManager.CreateEntity(posScl, 2);
    Entity e3 = world.entityManager.CreateEntity(posRot, 2);

    Position *posPtr = (Position *)world.entityManager.GetComponentRef(e1, rotationType.id);
    *posPtr = Position(10, 5, 3);

    std::cout << (*(Position *)world.entityManager.GetComponentRef(e1, rotationType.id)).ToString() << "\n";

    std::cout << world.entityManager.EntitiesToString() << "\n";
    std::cout << world.entityManager.ArchetypesToString() << "\n";
}