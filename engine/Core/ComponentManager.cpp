#include "ComponentManager.hpp"
#include <cassert>
#include <iostream>

namespace ECSEngine
{
    ComponentType ComponentManager::GetComponentType(ComponentID id) const
    {
        for (const std::pair<const char *, ComponentType> &pair : registeredComponents)
        {
            if (pair.second.id == id)
            {
                return pair.second;
            }
        }
        assert(false && "Invalid ComponentID");
    }

    ComponentType ComponentManager::GetOrRegisterComponentInternal(const char *name, size_t size)
    {
        // Skip already registered components
        if (registeredComponents.count(name))
            return GetComponentTypeInternal(name);

        ComponentType type = ComponentType(highestComponentId++, size);
        registeredComponents.emplace(name, type);
        return type;
    }
    ComponentType ComponentManager::GetComponentTypeInternal(const char *name) const
    {
        assert(registeredComponents.count(name) && "Component has not been registered");
        return registeredComponents.at(name);
    }
}