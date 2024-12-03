#include "EntityManager.hpp"
#include <iostream>

Entity EntityManager::CreateEntity(ComponentType components[], int count)
{
    Entity entity = Entity(entityCount++);
    Archetype &archetype = GetOrCreateArchetype(components, count);
    archetype.AddEntity(entity);
    entityToArchetype.insert(std::pair<Entity, uint32_t>(entity, archetypes.size() - 1));
    return entity;
}
void EntityManager::DestroyEntity(Entity entity)
{
    GetArchetype(entity).RemoveEntity(entity);
    entityToArchetype.erase(entity);
}

Archetype &EntityManager::GetArchetype(Entity entity)
{
    return archetypes.at(entityToArchetype.at(entity));
}
uint32_t EntityManager::GetArchetypeIndex(Entity entity) const
{
    return entityToArchetype.at(entity);
}

std::string EntityManager::EntitiesToString() const
{
    std::string string = "";
    for (const std::pair<const Entity, uint32_t> &pair : entityToArchetype)
    {
        string.append(pair.first.ToString());
        string.append(": ");
        string.append(archetypes.at(pair.second).componentSet.ToString());
        string.append("\n");
    }
    return string;
}

Archetype &EntityManager::GetOrCreateArchetype(ComponentType components[], int count)
{
    ComponentSet set = ComponentSet(components, count);
    for (auto &archetype : archetypes)
    {
        if (archetype.componentSet == set)
        {
            return archetype;
        }
    }

    archetypes.push_back(Archetype(components, count));
    return archetypes.at(archetypes.size() - 1);
}
