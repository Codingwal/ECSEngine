#include "Core/SystemManager.hpp"
#include <iostream>

namespace ECSEngine
{
    SystemManager::~SystemManager()
    {
        for (ISystem *system : systems)
        {
            delete system;
        }
    }

    void SystemManager::Update(World &world, float deltaTime)
    {
        for (const auto &system : systems)
        {
            system->Update(world, deltaTime);
        }
    }
}