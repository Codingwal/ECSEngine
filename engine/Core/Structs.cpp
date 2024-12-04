#include "Structs.hpp"

// Entity

const bool operator<(const Entity &lhs, const Entity &rhs)
{
    return lhs.id < rhs.id;
}

std::string Entity::ToString() const
{
    return "Entity: {id: " + std::to_string(id) + "}";
}

// ComponentType

ComponentType::ComponentType(const ComponentType &other)
{
    id = other.id;
    size = other.size;
}

bool operator==(const ComponentType &lhs, const ComponentType &rhs)
{
    return lhs.id == rhs.id;
}

std::string ComponentType::ToString()
{
    return "Component: {id: " + std::to_string(id) + ", size: " + std::to_string(size) + "}";
}

// ComponentSet

ComponentSet::ComponentSet(ComponentType *components, size_t size)
{
    set.set(0, true); // All entities have the "Entity" component
    for (size_t i = 0; i < size; i++)
    {
        set.set(components[i].id, true);
    }
}

bool ComponentSet::HasComponents(ComponentSet &other) const
{
    return (set & other.set) == other.set;
}

bool operator==(const ComponentSet &lhs, const ComponentSet &rhs)
{
    return lhs.set == rhs.set;
}

std::string ComponentSet::ToString() const
{
    return set.to_string();
}
