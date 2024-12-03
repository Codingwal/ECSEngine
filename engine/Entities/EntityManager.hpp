#pragma once

#include "Archetype.hpp"
#include "../Core/Structs.hpp"
#include <vector>
#include <map>

class EntityManager
{
public:
    EntityManager() = default;
    Entity CreateEntity(ComponentSet components);
    void DestroyEntity(Entity entity);
    Archetype &GetArchetype(Entity entity);
    std::string EntitiesToString() const;

private:
    Archetype &GetOrCreateArchetype(ComponentSet components);
    uint32_t GetArchetypeIndex(Entity entity) const;

private:
    int entityCount;
    std::vector<Archetype> archetypes;
    std::map<Entity, uint32_t> entityToArchetype;
};