#pragma once

#include <vector>
#include "../Core/Archetype.hpp"
#include "../Core/EntityManager.hpp"
#include "../Interface/World.hpp"

namespace ECSEngine
{
    // @brief EntityQueries are used to get all entities that have all components (and optionally more) specified
    class EntityQuery
    {
    public:
        // @brief Used for iterating over all entities of an entity query
        class Iterator
        {
        public:
            Iterator(size_t archetypeCount)
                : archetypeIndex(archetypeCount), archetypes(nullptr)
            {
            }
            Iterator(const std::vector<Archetype *> *_archetypes) : archetypes(_archetypes), archetypeIndex(0), indexInArchetype(0) {}
            Iterator &operator++();
            Entity operator*();
            friend bool operator!=(const Iterator &lhs, const Iterator &rhs);

        private:
            size_t archetypeIndex;
            size_t indexInArchetype;
            const std::vector<Archetype *> *archetypes;
        };

        // @brief The iterable returned by EntityQuery::GetEntities
        class Iterable
        {
        public:
            Iterable(const std::vector<Archetype *> &_archetypes) : archetypes(_archetypes) {}
            Iterator begin();
            Iterator end();

        private:
            const std::vector<Archetype *> &archetypes;
        };

    public:
        EntityQuery(World &_world) : world(_world), components() {}
        EntityQuery(ComponentSet _components, World &_world);
        Iterable GetEntities();

    public:
        void Update();

    protected:
        ComponentSet components;

    private:
        World &world;
        size_t archetypeCount = 0;
        std::vector<Archetype *> archetypes;
    };
}