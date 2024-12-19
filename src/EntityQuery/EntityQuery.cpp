#include "EntityQuery/EntityQuery.hpp"
#include "World/World.hpp"

namespace ECSEngine
{
    // Iterator

    EntityQuery::Iterator &EntityQuery::Iterator::operator++()
    {
        ++indexInArchetype;
        if (indexInArchetype >= archetypes->at(archetypeIndex)->EntityCount())
        {
            indexInArchetype = 0;
            ++archetypeIndex;
        }
        return *this;
    }

    Entity EntityQuery::Iterator::operator*()
    {
        return archetypes->at(archetypeIndex)->RowToEntity(indexInArchetype);
    }

    bool operator!=(const EntityQuery::Iterator &lhs, const EntityQuery::Iterator &rhs)
    {
        return lhs.archetypeIndex != rhs.archetypeIndex;
    }

    // Iterable

    EntityQuery::Iterator EntityQuery::Iterable::begin()
    {
        return Iterator(&archetypes);
    }

    EntityQuery::Iterator EntityQuery::Iterable::end()
    {
        return Iterator(archetypes.size());
    }

    // EntityQuery

    EntityQuery::EntityQuery(ComponentSet _components, World &_world)
        : components(_components), world(_world)
    {
        Update();
    }

    void EntityQuery::Update()
    {
        for (size_t i = archetypeCount; i < world.entityManager.archetypes.size(); i++)
        {
            Archetype &archetype = world.entityManager.archetypes.at(i);
            if (archetype.HasComponents(components))
            {
                archetypes.push_back(&archetype);
            }
        }
        archetypeCount = world.entityManager.archetypes.size();
    }

    EntityQuery::Iterable EntityQuery::GetEntities()
    {
        return Iterable(archetypes);
    }
}