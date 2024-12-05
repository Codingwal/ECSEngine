#pragma once

namespace ECSEngine
{
    template <typename T1, typename... Ts>
    inline void World::CreateEntityHelper(ComponentType components[], size_t index)
    {
        components[index] = componentManager.GetOrRegisterComponent<T1>(); // Get and store the component id
        if constexpr (sizeof...(Ts) > 0)                                   // Only continue the recursion if there are unhandled components left
            CreateEntityHelper<Ts...>(components, --index);                // Recursion: call again for all components except the one handled in this iteration
    }
    template <typename... Ts>
    inline Entity World::CreateEntity()
    {
        size_t componentCount = sizeof...(Ts);                     // Template arguments count
        ComponentType components[componentCount];                  // Create an array with enough space for all components
        CreateEntityHelper<Ts...>(components, componentCount - 1); // Start recursive array-initialization
        return CreateEntity(components, componentCount);           // Create the entity with the now filled components array
    }

    template <typename T>
    inline void World::AddComponent(Entity entity)
    {
        ComponentType componentType = componentManager.GetOrRegisterComponent<T>();
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
        *(T *)entityManager.GetComponentRef(entity, componentManager.GetOrRegisterComponent<T>().id) = data;
    }

    template <typename T>
    inline const T &World::GetComponentData(Entity entity) const
    {
        return *(T *)entityManager.GetComponentRef(entity, componentManager.GetComponentType<T>().id);
    }
    template <typename T>
    inline T &World::GetComponentDataRef(Entity entity) const
    {
        return *(T *)entityManager.GetComponentRef(entity, componentManager.GetComponentType<T>().id);
    }
}