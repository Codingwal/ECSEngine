#pragma once

#include <string>
#include <cstdint>
#include "Constants.hpp"
#include <bitset>
#include <iostream>

// @brief Identifies an Entity
struct Entity
{
    Entity() = default;
    Entity(uint32_t _id) : id(_id) {}
    friend const bool operator<(const Entity &lhs, const Entity &rhs);
    std::string ToString() const;

    uint32_t id;
};

// @brief The unique ID of a component
using ComponentID = uint8_t;

// @brief Contains information about a component
struct ComponentType
{
    ComponentType() = default;
    ComponentType(ComponentID _id, size_t _size) : id(_id), size(_size) {}
    ComponentType(const ComponentType &other);
    friend bool operator==(const ComponentType &lhs, const ComponentType &rhs);
    std::string ToString();

    ComponentID id;
    size_t size;
};

// @brief Describes an arbitrary combination of components
struct ComponentSet
{
    ComponentSet() = default;
    ComponentSet(ComponentType *components, size_t size);
    bool HasComponents(ComponentSet &other) const;
    friend bool operator==(const ComponentSet &lhs, const ComponentSet &rhs);
    std::string ToString() const;

    std::bitset<MAX_COMPONENT_COUNT> set = {};
};