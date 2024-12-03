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
int main(int argc, char **argv)
{
    ComponentManager cm = ComponentManager();
    EntityManager em = EntityManager();

    ComponentType positionType = cm.RegisterComponent<Position>();
    ComponentType rotationType = cm.RegisterComponent<Rotation>();

    ComponentType components[2] = {positionType, rotationType};
    Entity entity = em.CreateEntity(ComponentSet(components, 2));

    std::cout << positionType.ToString() << "; " << rotationType.ToString() << "\n";
    std::cout << "Entity: " << entity.ToString() << "; Components: " << em.GetArchetype(entity).components.ToString() << "\n";
}