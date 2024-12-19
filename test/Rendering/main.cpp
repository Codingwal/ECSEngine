#include <Engine/Graphics/Renderer.hpp>
#include <Engine/Math/Math.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    Renderer renderer;
    renderer.Init("C:/Users/flori/Documents/Coding/C++/ECSEngine/include/Engine/ressources/");
    renderer.Run();
    renderer.Dispose();
    
}