#include <Engine/Graphics/Renderer.hpp>
#include <Engine/Math/Math.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    Float4 vec4(2, 3, 4, 1);
    Float4x4 matrix = Float4x4::Identity();
    std::cout << vec4 << "\n";

    vec4 = matrix * vec4;
    std::cout << vec4 << "\n";

    matrix[3][0] = 5;
    matrix[3][1] = 2;
    matrix[3][2] = 4;
    std::cout << matrix << "\n";

    vec4 = matrix * vec4;
    std::cout << vec4 << "\n";

    // Renderer renderer;
    // renderer.Init();
    // renderer.Run();
    // renderer.Dispose();
}