#include <string>
#include "Vector3.hpp"

struct Position
{
    Vector3 value;
    Position(Vector3 _value)
    {
        value = _value;
    }
    Position(float x, float y, float z)
    {
        value = Vector3(x, y, z);
    }
    std::string ToString() const
    {
        return "Position: " + value.ToString();
    }
};
struct Rotation
{
    Vector3 value;
    Rotation(Vector3 _value)
    {
        value = _value;
    }
    Rotation(float x, float y, float z)
    {
        value = Vector3(x, y, z);
    }
    std::string ToString() const
    {
        return "Rotation: " + value.ToString();
    }
};
struct Scale
{
    Vector3 value;
    Scale(Vector3 _value)
    {
        value = _value;
    }
    Scale(float x, float y, float z)
    {
        value = Vector3(x, y, z);
    }
    std::string ToString() const
    {
        return "Scale: " + value.ToString();
    }
};