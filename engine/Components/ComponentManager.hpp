#pragma once

#include <map>
#include "../Core/Structs.hpp"
#include <typeinfo>

class ComponentManager
{
public:
    template <typename T>
    ComponentType GetOrRegisterComponent();
    template <typename T>
    ComponentType GetComponentType() const;
    ComponentType GetComponentType(ComponentID id) const;

private:
    ComponentType GetOrRegisterComponentInternal(const char *name, size_t size);
    ComponentType GetComponentTypeInternal(const char *name) const;

private:
    int highestComponentId = 0;
    std::map<const char *, ComponentType> registeredComponents;
};

template <typename T>
ComponentType ComponentManager::GetOrRegisterComponent()
{
    return GetOrRegisterComponentInternal(typeid(T).name(), sizeof(T));
}
template <typename T>
ComponentType ComponentManager::GetComponentType() const
{
    return GetComponentTypeInternal(typeid(T).name());
}