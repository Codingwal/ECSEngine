#include "Interface/World.hpp"
#include <iostream>

namespace ECSEngine
{
    World::World() : entityQueries()
    {
        componentManager.GetOrRegisterComponent<Entity>();
    }

    Entity World::CreateDefaultEntity(ComponentType components[], int count)
    {
        return entityManager.CreateEntity(components, count);
    }

    void World::DestroyEntity(Entity entity)
    {
        return entityManager.DestroyEntity(entity);
    }
}