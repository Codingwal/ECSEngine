#pragma once

#include "ECS/SystemManager.hpp"
#include "ECS/Components.hpp"

namespace ECSEngine
{
    class World;
    class UpdateTransformMatrix : public ECSEngine::ISystem
    {
        void Update(World &world, float deltaTime);
    };
    class GraphicsSystem : public ECSEngine::ISystem
    {
        void Update(World &world, float deltaTime);
    };
    class PhysicsSystem : public ECSEngine::ISystem
    {
        void Update(World &world, float deltaTime);
    };
}