#include "World.hpp"

World::World()
{
    componentManager.RegisterComponent<Entity>();
}