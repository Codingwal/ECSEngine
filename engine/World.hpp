#pragma once

#include "Entities/EntityManager.hpp"
#include "Components/ComponentManager.hpp"

class World
{
public:
    EntityManager entityManager;
    ComponentManager componentManager;
};