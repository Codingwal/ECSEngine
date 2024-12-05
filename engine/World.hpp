#pragma once

#include "Entities/EntityManager.hpp"
#include "Components/ComponentManager.hpp"

namespace ECSEngine
{
    // @brief An ECS world. Each world has its own entities, components, systems and their respective managers
    class World
    {
    public:
        World();

        template <typename... Ts>
        Entity CreateEntity();
        Entity CreateEntity(ComponentType components[], int count);
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

    public:
        EntityManager entityManager;
        ComponentManager componentManager;

    private:
        template <typename T1, typename... Ts>
        inline void CreateEntityHelper(ComponentType components[], size_t index);
    };
}

#include "WorldImplementation.tpp"