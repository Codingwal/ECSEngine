#include <vector>
#include "Archetype.hpp"
#include "EntityManager.hpp"

class EntityQuery
{
public:
    class Iterator
    {
    public:
        Iterator(uint32_t archetypeCount)
            : archetypeIndex(archetypeCount)
        {
        }
        Iterator(const std::vector<Archetype *> _archetypes)
            : archetypes(_archetypes), archetypeIndex(0), indexInArchetype(0)
        {
        }
        Iterator &operator++()
        {
            ++indexInArchetype;
            if (indexInArchetype >= archetypes[archetypeIndex]->EntityCount())
            {
                indexInArchetype = 0;
                ++archetypeIndex;
            }
            return *this;
        }
        Entity operator*()
        {
            return archetypes[archetypeIndex]->RowToEntity(indexInArchetype);
        }
        friend bool operator!=(const Iterator &lhs, const Iterator &rhs)
        {
            return lhs.archetypeIndex != rhs.archetypeIndex;
        }

    private:
        std::vector<Archetype *> archetypes;
        uint32_t archetypeIndex;
        uint32_t indexInArchetype;
    };
    class Iterable
    {
    public:
        Iterable(const std::vector<Archetype *> &_archetypes)
            : archetypes(_archetypes)
        {
        }
        Iterator begin()
        {
            return Iterator(archetypes);
        }
        Iterator end()
        {
            return Iterator(archetypes.size());
        }

    private:
        std::vector<Archetype *> archetypes;
    };

public:
    EntityQuery(ComponentSet _components)
        : components(_components)
    {
    }
    Iterable GetEntities(EntityManager &em)
    {
        std::vector<Archetype *> archetypes;
        for (auto &archetype : em.archetypes)
        {
            if (archetype.HasComponents(components))
            {
                archetypes.push_back(&archetype);
            }
        }
        return Iterable(archetypes);
    }

private:
    ComponentSet components;
};