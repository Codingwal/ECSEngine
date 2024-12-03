#include "ComponentManager.hpp"
#include "../Core/Error.hpp"

ComponentType ComponentManager::RegisterComponentInternal(const char *name)
{
    Assert(!registeredComponents.count(name), "Component has already been registered");
    ComponentType type = ComponentType(highestComponentId++);
    registeredComponents.insert(std::pair(name, type));
    return type;
}
ComponentType ComponentManager::GetComponentTypeInternal(const char *name)
{
    Assert(registeredComponents.count(name), "Component has not been registered");
    return registeredComponents[name];
}