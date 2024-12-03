#pragma once

#include "Entities/EntityManager.hpp"
#include "Components/ComponentManager.hpp"

class World
{
public:
    World();

    Entity CreateEntity(ComponentType components[], int count);
    void DestroyEntity(Entity entity);
    template <typename T>
    void AddComponent(Entity entity);
    template <typename T>
    void RemoveComponent(Entity entity);
    template <typename T>
    void SetComponentData(Entity entity, T data);
    template <typename T>
    T &GetComponentData(Entity entity);

public:
    EntityManager entityManager;
    ComponentManager componentManager;
};

template <typename T>
inline void World::AddComponent(Entity entity)
{
    ComponentType componentType = componentManager.GetComponentType<T>();
    entityManager.AddComponents(entity, &componentType, 1);
}

template <typename T>
inline void World::RemoveComponent(Entity entity)
{
    ComponentType componentType = componentManager.GetComponentType<T>();
    entityManager.RemoveComponents(entity, &componentType, 1);
}

template <typename T>
inline void World::SetComponentData(Entity entity, T data)
{
    *(T *)entityManager.GetComponentRef(entity, componentManager.GetComponentType<T>().id) = data;
}

template <typename T>
inline T &World::GetComponentData(Entity entity)
{
    return *(T *)entityManager.GetComponentRef(entity, componentManager.GetComponentType<T>().id);
}
