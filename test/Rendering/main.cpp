#include <Engine/Graphics/Renderer.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    Renderer renderer;
    renderer.Init();
    renderer.Run();
    renderer.Dispose();
}