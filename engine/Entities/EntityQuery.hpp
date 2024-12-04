#include <vector>
#include "Archetype.hpp"
#include "EntityManager.hpp"

// @brief EntityQueries are used to get all entities that have all components (and optionally more) specified
class EntityQuery
{
public:
    // @brief Used for iterating over all entities of an entity query
    class Iterator
    {
    public:
        Iterator(uint32_t archetypeCount)
            : archetypeIndex(archetypeCount)
        {
        }
        Iterator(const std::vector<Archetype *> _archetypes) : archetypes(_archetypes), archetypeIndex(0), indexInArchetype(0) {}
        Iterator &operator++();
        Entity operator*();
        friend bool operator!=(const Iterator &lhs, const Iterator &rhs);

    private:
        std::vector<Archetype *> archetypes;
        uint32_t archetypeIndex;
        uint32_t indexInArchetype;
    };

    // @brief The iterable returned by EntityQuery::GetEntities
    class Iterable
    {
    public:
        Iterable(const std::vector<Archetype *> &_archetypes) : archetypes(_archetypes) {}
        Iterator begin();
        Iterator end();

    private:
        std::vector<Archetype *> archetypes;
    };

public:
    EntityQuery(ComponentSet _components) : components(_components) {}
    Iterable GetEntities(EntityManager &em);

private:
    ComponentSet components;
};