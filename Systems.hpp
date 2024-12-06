#pragma once

#include "Interface/World.hpp"
#include "Components.hpp"
#include "EntityQuery/EntityQueryGeneric.hpp"

using namespace ECSEngine;

class VelocitySystem : public ISystem
{
    void Update(World &world, float deltaTime)
    {
        EntityQueryGeneric<Velocity, Acceleration> query(world);
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
        EntityQueryGeneric<Position, Velocity> query(world);
        for (Entity entity : query.GetEntities())
        {
            world.GetComponentDataRef<Position>(entity).value += world.GetComponentData<Velocity>(entity).value * deltaTime;
        }
    }
};