#pragma once

#include <string>
#include <cstdint>
#include "Constants.hpp"
#include <bitset>
#include <iostream>

struct Entity
{
    int32_t id;
    Entity() = default;
    Entity(int _id)
    {
        id = _id;
    }
    friend const bool operator<(const Entity &lhs, const Entity &rhs)
    {
        return lhs.id < rhs.id;
    }
    std::string ToString() const
    {
        return "Entity: {id: " + std::to_string(id) + "}";
    }
};
using ComponentID = int8_t;
struct ComponentType
{
    ComponentID id;
    size_t size;
    ComponentType() = default;
    ComponentType(ComponentID _id, size_t _size)
    {
        id = _id;
        size = _size;
    }
    ComponentType(const ComponentType &other)
    {
        id = other.id;
        size = other.size;
    }
    friend bool operator==(const ComponentType &lhs, const ComponentType &rhs)
    {
        return lhs.id == rhs.id;
    }
    std::string ToString()
    {
        return "Component: {id: " + std::to_string(id) + ", size: " + std::to_string(size) + "}";
    }
};
struct ComponentSet
{
    std::bitset<MAX_COMPONENT_COUNT> set;
    ComponentSet() = default;
    ComponentSet(ComponentType *components, int size)
    {
        set.set(0, true); // All entities have the "Entity" component
        for (int i = 0; i < size; i++)
        {
            set.set(components[i].id, true);
        }
    }
    bool HasComponents(ComponentSet &other) const
    {
        return (set & other.set) == other.set;
    }
    friend inline bool operator==(const ComponentSet &lhs, const ComponentSet &rhs)
    {
        return lhs.set == rhs.set;
    }
    std::string ToString() const
    {
        return set.to_string();
    }
};