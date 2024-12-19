#include <Engine/World/World.hpp>
#include <Engine/Math/Math.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    ECSEngine::World world = ECSEngine::World();

    world.Run();
}