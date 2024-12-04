#include "EntityQuery.hpp"

// Iterator

EntityQuery::Iterator &EntityQuery::Iterator::operator++()
{
    ++indexInArchetype;
    if (indexInArchetype >= archetypes[archetypeIndex]->EntityCount())
    {
        indexInArchetype = 0;
        ++archetypeIndex;
    }
    return *this;
}

Entity EntityQuery::Iterator::operator*()
{
    return archetypes[archetypeIndex]->RowToEntity(indexInArchetype);
}

bool operator!=(const EntityQuery::Iterator &lhs, const EntityQuery::Iterator &rhs)
{
    return lhs.archetypeIndex != rhs.archetypeIndex;
}

// Iterable

EntityQuery::Iterator EntityQuery::Iterable::begin()
{
    return Iterator(archetypes);
}

EntityQuery::Iterator EntityQuery::Iterable::end()
{
    return Iterator(archetypes.size());
}

// EntityQuery

EntityQuery::Iterable EntityQuery::GetEntities()
{
    std::vector<Archetype *> archetypes;
    for (auto &archetype : world.entityManager.archetypes)
    {
        if (archetype.HasComponents(components))
        {
            archetypes.push_back(&archetype);
        }
    }
    return Iterable(archetypes);
}
