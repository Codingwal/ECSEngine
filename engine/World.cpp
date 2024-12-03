#include "World.hpp"
#include <iostream>

World::World()
{
    componentManager.RegisterComponent<Entity>();
}