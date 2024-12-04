#include <vector>
#include "Archetype.hpp"
#include "EntityManager.hpp"
#include "../World.hpp"

// @brief EntityQueries are used to get all entities that have all components (and optionally more) specified
class EntityQuery
{
public:
    // @brief Used for iterating over all entities of an entity query
    class Iterator
    {
    public:
        Iterator(size_t archetypeCount)
            : archetypeIndex(archetypeCount)
        {
        }
        Iterator(const std::vector<Archetype *> _archetypes) : archetypes(_archetypes), archetypeIndex(0), indexInArchetype(0) {}
        Iterator &operator++();
        Entity operator*();
        friend bool operator!=(const Iterator &lhs, const Iterator &rhs);

    private:
        std::vector<Archetype *> archetypes;
        size_t archetypeIndex;
        size_t indexInArchetype;
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
    EntityQuery(World &_world) : world(_world), components() {}
    EntityQuery(ComponentSet _components, World &_world) : components(_components), world(_world) {}
    Iterable GetEntities();

protected:
    ComponentSet components;
    World &world;
};