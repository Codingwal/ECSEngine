#pragma once

#include <Engine/World/World.hpp>
#include <Engine/ECS/Components.hpp>
#include <math.h>

using namespace ECSEngine;
class MovementSystem : public ISystem
{
    void Update(World &world, float deltaTime)
    {
        auto &query = world.GetEntityQuery<Transform>();
        for (Entity entity : query.GetEntities())
        {
            auto &transform = world.GetComponentDataRef<Transform>(entity);
            transform.position.x += deltaTime;
        }
    }
};