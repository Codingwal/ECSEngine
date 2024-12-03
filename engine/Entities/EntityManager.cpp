#include "EntityManager.hpp"

Entity EntityManager::CreateEntity(ComponentSet components)
{
    Entity entity = entityCount++;
    Archetype &archetype = GetOrCreateArchetype(components);
    entityToArchetype.insert(std::pair<Entity, Archetype *>(entity, &archetype));
    // archetype.AddEntity(entity);
    return entity;
}
void EntityManager::DestroyEntity(Entity entity)
{
    // entityToArchetype[entity]->RemoveEntity(entity);
    entityToArchetype.erase(entity);
}

Archetype &EntityManager::GetArchetype(Entity entity)
{
    return *entityToArchetype[entity];
}

Archetype &EntityManager::GetOrCreateArchetype(ComponentSet components)
{
    for (auto &archetype : archetypes)
    {
        if (archetype.components == components)
        {
            return archetype;
        }
    }
    // Archetype archetype = Archetype(components);
    archetypes.push_back(Archetype(components));
    return archetypes.at(archetypes.size() - 1);
}
