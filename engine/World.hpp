#pragma once

#include "Entities/EntityManager.hpp"
#include "Components/ComponentManager.hpp"

class World
{
public:
    World();
    EntityManager entityManager;
    ComponentManager componentManager;
};