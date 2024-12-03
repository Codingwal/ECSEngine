#pragma once

#include <map>
#include "../Core/Structs.hpp"
#include <typeinfo>

class ComponentManager
{
public:
    ComponentManager() = default;

    template <typename T>
    ComponentType RegisterComponent()
    {
        auto name = typeid(T).name();
        return RegisterComponentInternal(name);
    }
    template <typename T>
    ComponentType GetComponentType()
    {
        return GetComponentTypeInternal(typeid(T).name());
    }

private:
    ComponentType RegisterComponentInternal(const char *name);
    ComponentType GetComponentTypeInternal(const char *name);

private:
    int highestComponentId;
    std::map<const char *, ComponentType> registeredComponents;
};