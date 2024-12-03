#pragma once

#include <string>
#include <cstdint>
#include "Constants.hpp"
#include <bitset>

struct Entity
{
    int32_t id;
    Entity() = default;
    Entity(int _id)
    {
        id = _id;
    }
    friend bool operator<(const Entity &lhs, const Entity &rhs)
    {
        return lhs.id < rhs.id;
    }
    std::string ToString()
    {
        return std::to_string(id);
    }
};
struct ComponentType
{
    int8_t id;
    ComponentType() = default;
    ComponentType(int _id)
    {
        id = _id;
    }
    ComponentType(const ComponentType &other)
    {
        id = other.id;
    }
    std::string ToString()
    {
        return std::to_string(id);
    }
};
struct ComponentSet
{
    std::bitset<MAX_COMPONENT_COUNT> set;
    ComponentSet() = default;
    ComponentSet(ComponentType *components, int size)
    {
        for (int i = 0; i < size; i++)
        {
            set.set(components[i].id, true);
        }
    }
    friend inline bool operator==(const ComponentSet &lhs, const ComponentSet &rhs)
    {
        return lhs.set == rhs.set;
    }
    std::string ToString()
    {
        return set.to_string();
    }
};