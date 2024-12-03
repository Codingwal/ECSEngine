#include "EntityManager.hpp"
#include <iostream>
#include <cassert>

Entity EntityManager::CreateEntity(ComponentType components[], int count)
{
    assert(entityCount < MAX_ENTITY_COUNT && "Invalid entity");
    Entity entity = Entity(entityCount++);
    int32_t archetypeIndex = GetOrCreateArchetype(components, count);
    archetypes[archetypeIndex].AddEntity(entity);
    entityToArchetype.insert(std::pair<Entity, uint32_t>(entity, archetypeIndex));
    return entity;
}
void EntityManager::DestroyEntity(Entity entity)
{
    GetArchetype(entity).RemoveEntity(entity);
    entityToArchetype.erase(entity);
}

void *EntityManager::GetComponentRef(Entity entity, ComponentID component) const
{
    auto &archetype = archetypes[GetArchetypeIndex(entity)];
    assert(archetype.HasComponent(component) && "The archetype does not contain this component");
    return archetype.GetDataRef(entity, component);
}

Archetype &EntityManager::GetArchetype(Entity entity)
{
    assert(entityToArchetype.count(entity) && "Invalid entity");
    return archetypes.at(entityToArchetype.at(entity));
}
uint32_t EntityManager::GetArchetypeIndex(Entity entity) const
{
    assert(entityToArchetype.count(entity) && "Invalid entity");
    return entityToArchetype.at(entity);
}

std::string EntityManager::EntitiesToString() const
{
    std::string string = "Entities: (<ID>: <ComponentSet>)\n";
    for (const std::pair<const Entity, uint32_t> &pair : entityToArchetype)
    {
        string.append(pair.first.ToString());
        string.append(": ");
        string.append(archetypes.at(pair.second).GetComponentSet().ToString());
        string.append("\n");
    }
    return string;
}
void EntityManager::AddComponents(Entity entity, ComponentType components[], size_t count)
{
    // Create or get an archetype with all required components
    Archetype &oldArchetype = GetArchetype(entity);
    auto componentTypes = oldArchetype.GetComponentTypes();
    componentTypes.insert(componentTypes.end(), components, components + count); // Append the new components
    uint32_t newArchetypeIndex = GetOrCreateArchetype(componentTypes.data(), componentTypes.size());

    ChangeArchetype(entity, newArchetypeIndex);
}
void EntityManager::RemoveComponents(Entity entity, ComponentType components[], size_t count)
{
    // Get old components
    Archetype &oldArchetype = GetArchetype(entity);
    auto componentTypes = oldArchetype.GetComponentTypes();

    // Remove all specified components
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < componentTypes.size(); j++)
        {
            if (components[i] == componentTypes[j])
            {
                componentTypes.erase(componentTypes.begin() + j);
                break;
            }
        }
    }

    uint32_t newArchetypeIndex = GetOrCreateArchetype(componentTypes.data(), componentTypes.size());
    ChangeArchetype(entity, newArchetypeIndex);
}
std::string EntityManager::ArchetypesToString() const
{
    std::string string = "Archetypes:\n";
    for (const auto &archetype : archetypes)
    {
        string += archetype.ToString() + "\n";
    }
    return string;
}

void EntityManager::ChangeArchetype(Entity entity, uint32_t newArchetypeIndex)
{
    Archetype &oldArchetype = GetArchetype(entity);
    Archetype &newArchetype = archetypes[newArchetypeIndex];
    newArchetype.AddEntity(entity);
    oldArchetype.CopyEntityData(newArchetype, entity, entity);
    oldArchetype.RemoveEntity(entity);
    entityToArchetype[entity] = newArchetypeIndex;
}

uint32_t EntityManager::GetOrCreateArchetype(ComponentType components[], int count)
{
    ComponentSet set = ComponentSet(components, count);
    for (int i = 0; i < archetypes.size(); i++)
    {
        if (archetypes[i].Matches(set))
        {
            return i;
        }
    }

    archetypes.push_back(Archetype(components, count));
    return archetypes.size() - 1;
}
