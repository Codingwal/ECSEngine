#include "EntityManager.hpp"
#include <iostream>

Entity EntityManager::CreateEntity(ComponentType components[], int count)
{
    Entity entity = Entity(entityCount++);
    int32_t archetypeIndex = GetOrCreateArchetype(components, count);
    archetypes[archetypeIndex].AddEntity(entity);
    entityToArchetype.insert(std::pair<Entity, uint32_t>(entity, archetypeIndex));
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
    std::string string = "Entities: (<ID>: <ComponentSet>)";
    for (const std::pair<const Entity, uint32_t> &pair : entityToArchetype)
    {
        string.append(pair.first.ToString());
        string.append(": ");
        string.append(archetypes.at(pair.second).componentSet.ToString());
        string.append("\n");
    }
    return string;
}

uint32_t EntityManager::GetOrCreateArchetype(ComponentType components[], int count)
{
    ComponentSet set = ComponentSet(components, count);
    for (int i = 0; i < archetypes.size(); i++)
    {
        if (archetypes[i].componentSet == set)
        {
            return i;
        }
    }

    archetypes.push_back(Archetype(components, count));
    return archetypes.size() - 1;
}
