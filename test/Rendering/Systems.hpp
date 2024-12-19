#pragma once

#include <Engine/World/World.hpp>
#include <Engine/ECS/Components.hpp>
#include <math.h>

using namespace ECSEngine;
class CollisionSystem : public ISystem
{
    void Update(World &world, float deltaTime)
    {
        auto &query = world.GetEntityQuery<Transform, PhysicsObject>();
        for (Entity entity : query.GetEntities())
        {
            auto &transform = world.GetComponentDataRef<Transform>(entity);
            auto &obj = world.GetComponentDataRef<PhysicsObject>(entity);
            if (transform.position.x > 1 || transform.position.x < -1)
            {
                obj.velocity *= -1;
                transform.position += obj.velocity * deltaTime;
            }
        }
    }
};