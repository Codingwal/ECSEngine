#include "ComponentManager.hpp"
#include <cassert>

ComponentType ComponentManager::RegisterComponentInternal(const char *name)
{
    // Skip already registered components
    if (registeredComponents.count(name))
        return GetComponentTypeInternal(name);

    ComponentType type = ComponentType(highestComponentId++);
    registeredComponents.insert(std::pair(name, type));
    return type;
}
ComponentType ComponentManager::GetComponentTypeInternal(const char *name)
{
    assert(registeredComponents.count(name) && "Component has not been registered");
    return registeredComponents[name];
}