#pragma once

#include "Archetype.hpp"
#include "Base/Structs.hpp"
#include <vector>
#include <map>

namespace ECSEngine
{
    // @brief Owns and manages all entities and archetypes
    class EntityManager
    {
    public:
        Entity CreateEntity(ComponentType components[], size_t count);
        void DestroyEntity(Entity entity);
        void AddComponents(Entity entity, ComponentType components[], size_t count);
        void RemoveComponents(Entity entity, ComponentType components[], size_t count);

        void *GetComponentRef(Entity entity, ComponentID component) const;
        Archetype &GetArchetype(Entity entity);

        int GetEntityCount() { return entityCount; }
        std::string EntitiesToString() const;
        std::string ArchetypesToString() const;

    private:
        void ChangeArchetype(Entity entity, size_t newArchetypeIndex);
        size_t GetOrCreateArchetype(ComponentType components[], size_t count);
        size_t GetArchetypeIndex(Entity entity) const;

    private:
        int entityCount = 0;
        std::vector<Archetype> archetypes;
        std::map<Entity, size_t> entityToArchetype;

        friend class EntityQuery;
    };
}