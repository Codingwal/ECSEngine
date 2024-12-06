#pragma once

#include <vector>

namespace ECSEngine
{
    class World;

    class ISystem
    {
    public:
        virtual void Update(World &world, float deltaTime) = 0;
    };

    class SystemManager
    {
    public:
        ~SystemManager();
        template <typename T>
        void RegisterSystem()
        {
            systems.push_back(new T());
        }
        void Update(World &world, float deltaTime);

    private:
        std::vector<ISystem *> systems;
    };
}