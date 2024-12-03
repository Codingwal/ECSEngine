#include <stdio.h>
#include <iostream>
#include "Core/Structs.hpp"
#include "Components/ComponentManager.hpp"
#include "Entities/EntityManager.hpp"

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
    ComponentManager cm = ComponentManager();
    EntityManager em = EntityManager();

    ComponentType positionType = cm.RegisterComponent<Position>();
    ComponentType rotationType = cm.RegisterComponent<Rotation>();
    ComponentType scaleType = cm.RegisterComponent<Scale>();

    ComponentType components[2] = {positionType, scaleType};
    Entity entity = em.CreateEntity(ComponentSet(components, 2));

    std::cout << "Entity: " << entity.ToString() << "; Components: " << em.GetArchetype(entity).components.ToString() << "\n";
}