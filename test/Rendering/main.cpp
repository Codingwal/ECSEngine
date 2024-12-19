#include <Engine/Graphics/Renderer.hpp>
#include <Engine/Math/Math.hpp>
#include <iostream>

#define PI 3.1415926535

int main(int argc, char **argv)
{
    Float4x4 mat = Float4x4::Identity();
    mat = Float4x4::Rotate(mat, (float)90 / (float)180 * PI, Float3(0, 0, 1));
    std::cout << "\n"
              << mat << "\n";

    Float4 vec = Float4(2, 0, 0, 1);
    vec = mat * vec;
    std::cout << "\n"
              << vec << "\n";

    Renderer renderer;
    renderer.Init("C:/Users/flori/Documents/Coding/C++/ECSEngine/include/Engine/ressources/");
    renderer.Run();
    renderer.Dispose();
}