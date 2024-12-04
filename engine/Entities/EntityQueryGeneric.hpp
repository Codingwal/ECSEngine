#include <vector>
#include "Archetype.hpp"
#include "EntityManager.hpp"
#include "../World.hpp"
#include "EntityQuery.hpp"

template <typename T1, typename... Ts>
inline void EntityQueryCtorHelper(ComponentSet &components, World &world)
{
    components.set[world.componentManager.GetOrRegisterComponent<T1>().id] = true;
    if constexpr (sizeof...(Ts) > 0)
        EntityQueryCtorHelper<Ts...>(components, world);
}

template <typename... Ts>
class EntityQueryGeneric : public EntityQuery
{
public:
    EntityQueryGeneric(World &_world)
        : EntityQuery(_world)
    {
        EntityQueryCtorHelper<Ts...>(components, _world);
    }
};