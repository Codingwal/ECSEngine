#pragma once

#include "Interface/World.hpp"
#include "Components.hpp"

using namespace ECSEngine;

class VelocitySystem : public ISystem
{
    void Update(World &world, float deltaTime)
    {
        auto &query = world.GetEntityQuery<Velocity, Acceleration>();
        for (Entity entity : query.GetEntities())
        {
            world.GetComponentDataRef<Velocity>(entity).value += world.GetComponentData<Acceleration>(entity).value * deltaTime;
        }
    }
};

class PositionSystem : public ISystem
{
    void Update(World &world, float deltaTime)
    {
        auto &query = world.GetEntityQuery<Position, Velocity>();
        for (Entity entity : query.GetEntities())
        {
            world.GetComponentDataRef<Position>(entity).value += world.GetComponentData<Velocity>(entity).value * deltaTime;
        }
    }
};