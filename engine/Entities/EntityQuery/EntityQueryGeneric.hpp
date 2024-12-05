#pragma once

#include <vector>
#include "../Archetype.hpp"
#include "../EntityManager.hpp"
#include "../../World.hpp"
#include "EntityQuery.hpp"
#include "Implementation.hpp"

namespace ECSEngine
{
    // @brief A generic version of EntityQuery. Does not add any functionality but is more convinient.
    template <typename... Ts>
    class EntityQueryGeneric : public EntityQuery
    {
    public:
        EntityQueryGeneric(World &_world)
            : EntityQuery(_world)
        {
            Implementation::EntityQueryCtorHelper<Ts...>(components, _world);
        }
    };
}