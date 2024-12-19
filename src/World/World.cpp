#include "World/World.hpp"
#include <iostream>
#include "World/Systems.hpp"

namespace ECSEngine
{
    World::World() : entityQueries()
    {
        componentManager.GetOrRegisterComponent<Entity>();
        systemManager.RegisterSystem<UpdateTransformMatrix>();
        systemManager.RegisterSystem<GraphicsSystem>();
        renderer.Init("C:/Users/flori/Documents/Coding/C++/ECSEngine/include/Engine/ressources/");
    }
    World::~World()
    {
        renderer.Dispose();
    }
    void World::Run()
    {
        bool stop = false;
        float time = 0;
        while (!renderer.ShouldStop())
        {
            float newTime = renderer.GetTime();
            float deltaTime = newTime - time;
            time = newTime;

            systemManager.Update(*this, deltaTime);
            renderer.Update();
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