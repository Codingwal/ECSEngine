#pragma once

#include "../Core/EntityManager.hpp"
#include "../Core/ComponentManager.hpp"
#include "../Core/SystemManager.hpp"
#include "../EntityQuery/EntityQuery.hpp"
#include <unordered_map>

namespace ECSEngine
{
    // @brief An ECS world. Each world has its own entities, components, systems and their respective managers
    class World
    {
    public:
        World();

        template <typename... Ts>
        inline Entity CreateEntity();
        inline Entity CreateEntity(ComponentType components[], int count);
        inline void DestroyEntity(Entity entity);

        template <typename T>
        inline void AddComponent(Entity entity);
        template <typename T>
        inline void RemoveComponent(Entity entity);

        template <typename T>
        inline void SetComponentData(Entity entity, T data);
        template <typename T>
        inline const T &GetComponentData(Entity entity) const;
        template <typename T>
        inline T &GetComponentDataRef(Entity entity) const;

        template <typename... Ts>
        inline EntityQuery &GetEntityQuery();

    public:
        EntityManager entityManager;
        ComponentManager componentManager;
        SystemManager systemManager;
        std::unordered_map<ComponentSet, EntityQuery> entityQueries;

    private:
        template <typename T1, typename... Ts>
        inline void CreateEntityHelper(ComponentType components[], size_t index);
    };
}

#include "WorldImplementation.tpp"