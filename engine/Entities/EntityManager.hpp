#pragma once

#include "Archetype.hpp"
#include "../Core/Structs.hpp"
#include <vector>
#include <map>

// @brief Owns and manages all entities and archetypes
class EntityManager
{
public:
    Entity CreateEntity(ComponentType components[], int count);
    void DestroyEntity(Entity entity);
    void AddComponents(Entity entity, ComponentType components[], size_t count);
    void RemoveComponents(Entity entity, ComponentType components[], size_t count);

    void *GetComponentRef(Entity entity, ComponentID component) const;
    Archetype &GetArchetype(Entity entity);

    std::string EntitiesToString() const;
    std::string ArchetypesToString() const;

private:
    void ChangeArchetype(Entity entity, uint32_t newArchetypeIndex);
    uint32_t GetOrCreateArchetype(ComponentType components[], int count);
    uint32_t GetArchetypeIndex(Entity entity) const;

private:
    int entityCount = 0;
    std::vector<Archetype> archetypes;
    std::map<Entity, uint32_t> entityToArchetype;

    friend class EntityQuery;
};