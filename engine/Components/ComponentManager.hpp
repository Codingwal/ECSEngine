#pragma once

#include <map>
#include "../Core/Structs.hpp"
#include <typeinfo>

class ComponentManager
{
public:
    template <typename T>
    ComponentType RegisterComponent()
    {
        return RegisterComponentInternal(typeid(T).name(), sizeof(T));
    }
    template <typename T>
    ComponentType GetComponentType() const
    {
        return GetComponentTypeInternal(typeid(T).name());
    }
    ComponentType GetComponentType(ComponentID id) const;

private:
    ComponentType RegisterComponentInternal(const char *name, size_t size);
    ComponentType GetComponentTypeInternal(const char *name) const;

private:
    int highestComponentId = 0;
    std::map<const char *, ComponentType> registeredComponents;
};