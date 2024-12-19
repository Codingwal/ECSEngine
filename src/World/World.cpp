#include "World/World.hpp"
#include <iostream>
#include "World/Systems.hpp"

namespace ECSEngine
{
    World::World() : entityQueries()
    {
        renderer.Init("C:/Users/flori/Documents/Coding/C++/ECSEngine/include/Engine/ressources/");

        componentManager.GetOrRegisterComponent<Entity>();

        systemManager.RegisterSystem<UpdateTransformMatrix>();
        systemManager.RegisterSystem<GraphicsSystem>();
        systemManager.RegisterSystem<PhysicsSystem>();
    }
    World::~World()
    {
        renderer.Dispose();
    }
    void World::Run(int maxFrameCount)
    {
        int frames;
        bool stop = false;
        float time = 0;
        while (!renderer.ShouldStop() && frames < maxFrameCount)
        {
            float newTime = renderer.GetTime();
            float deltaTime = newTime - time;
            time = newTime;

            systemManager.Update(*this, deltaTime);
            renderer.Update();

            frames++;
        }
    }

    Entity World::CreateDefaultEntity(ComponentType components[], int count)
    {
        return entityManager.CreateEntity(components, count);
    }

    void World::DestroyEntity(Entity entity)
    {
        return entityManager.DestroyEntity(entity);
    }
}