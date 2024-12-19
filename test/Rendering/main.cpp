#include <Engine/Graphics/Renderer.hpp>
#include <Engine/Math/Math.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    Float4x4 matrix = Float4x4::Identity();
    matrix = Float4x4::Translate(matrix, Float3(1, 2, 3));

    auto arr = matrix.ToColumnMajorArray();
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ", ";
        if (i % 4 == 3)
            std::cout << "\n";
    }

    // Renderer renderer;
    // renderer.Init();
    // renderer.Run();
    // renderer.Dispose();
}