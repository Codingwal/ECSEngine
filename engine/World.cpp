#include "World.hpp"
#include <iostream>

namespace ECSEngine
{
    World::World()
    {
        componentManager.GetOrRegisterComponent<Entity>();
    }

    Entity World::CreateEntity(ComponentType components[], int count)
    {
        return entityManager.CreateEntity(components, count);
    }

    void World::DestroyEntity(Entity entity)
    {
        return entityManager.DestroyEntity(entity);
    }
}