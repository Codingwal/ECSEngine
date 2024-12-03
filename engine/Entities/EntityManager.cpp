#include "EntityManager.hpp"
#include <iostream>

Entity EntityManager::CreateEntity(ComponentSet components)
{
    Entity entity = Entity(entityCount++);
    Archetype &archetype = GetOrCreateArchetype(components);
    entityToArchetype.insert(std::pair<Entity, Archetype *>(entity, &archetype));
    archetype.AddEntity(entity);
    return entity;
}
void EntityManager::DestroyEntity(Entity entity)
{
    entityToArchetype[entity]->RemoveEntity(entity);
    entityToArchetype.erase(entity);
}

Archetype &EntityManager::GetArchetype(Entity entity) const
{
    return *entityToArchetype.at(entity);
}

std::string EntityManager::EntitiesToString() const
{
    std::string string = "";
    for (const std::pair<const Entity, Archetype *> &pair : entityToArchetype)
    {
        string.append(pair.first.ToString());
        string.append(": ");
        string.append(pair.second->components.ToString());
        string.append("\n");
    }
    return string;
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
    std::cout << EntitiesToString() << "\n";
    Archetype archetype = Archetype(components);
    archetypes.push_back(archetype);
    std::cout << EntitiesToString() << "\n";
    return archetypes.at(archetypes.size() - 1);
}
