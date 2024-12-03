#include <string>

struct Vector3
{
    float x, y, z;
    Vector3() = default;
    Vector3(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    std::string ToString() const
    {
        return "{" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "}";
    }
};