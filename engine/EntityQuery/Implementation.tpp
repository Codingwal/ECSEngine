#pragma once

#include "../Interface/World.hpp"

namespace ECSEngine
{
    namespace Implementation
    {
        template <typename T1, typename... Ts>
        static inline void EntityQueryCtorHelper(ComponentSet &components, World &world)
        {
            components.set[world.componentManager.GetOrRegisterComponent<T1>().id] = true;
            if constexpr (sizeof...(Ts) > 0)
                EntityQueryCtorHelper<Ts...>(components, world);
        }
    }
}