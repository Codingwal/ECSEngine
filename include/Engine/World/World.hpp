#pragma once

#include "ECS/EntityManager.hpp"
#include "ECS/ComponentManager.hpp"
#include "ECS/SystemManager.hpp"
#include "EntityQuery/EntityQuery.hpp"
#include <unordered_map>

namespace ECSEngine
{
    // @brief An ECS world. Each world has its own entities, components, systems and their respective managers
    class World
    {
    public:
        World();

        Entity CreateDefaultEntity(ComponentType components[], int count);
        template <typename... Ts>
        Entity CreateEntity();
        void DestroyEntity(Entity entity);

        template <typename T>
        void AddComponent(Entity entity);
        template <typename T>
        void RemoveComponent(Entity entity);

        template <typename T>
        void SetComponentData(Entity entity, T data);
        template <typename T>
        const T &GetComponentData(Entity entity) const;
        template <typename T>
        T &GetComponentDataRef(Entity entity) const;

        template <typename... Ts>
        EntityQuery &GetEntityQuery();

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