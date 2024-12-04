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
struct Velocity
{
    Vector3 value;
    Velocity(Vector3 _value)
    {
        value = _value;
    }
    Velocity(float x, float y, float z)
    {
        value = Vector3(x, y, z);
    }
    std::string ToString() const
    {
        return "Velocity: " + value.ToString();
    }
};
struct Acceleration
{
    Vector3 value;
    Acceleration(Vector3 _value)
    {
        value = _value;
    }
    Acceleration(float x, float y, float z)
    {
        value = Vector3(x, y, z);
    }
    std::string ToString() const
    {
        return "Acceleration: " + value.ToString();
    }
};