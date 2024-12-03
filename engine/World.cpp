#include "World.hpp"
#include <iostream>

World::World()
{
    componentManager.RegisterComponent<Entity>();
}

Entity World::CreateEntity(ComponentType components[], int count)
{
    return entityManager.CreateEntity(components, count);
}

void World::DestroyEntity(Entity entity)
{
    return entityManager.DestroyEntity(entity);
}
