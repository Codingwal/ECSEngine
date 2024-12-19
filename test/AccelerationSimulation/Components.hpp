#pragma once

#include <iostream>
#include <Engine/Math/Math.hpp>

struct Position
{
    Float3 value;
    Position(Float3 _value)
    {
        value = _value;
    }
    Position(float x, float y, float z)
    {
        value = Float3(x, y, z);
    }
    friend std::ostream &operator<<(std::ostream &os, const Position &pos)
    {
        os << "Position: " << pos.value;
        return os;
    }
};
struct Velocity
{
    Float3 value;
    Velocity(Float3 _value)
    {
        value = _value;
    }
    Velocity(float x, float y, float z)
    {
        value = Float3(x, y, z);
    }
    friend std::ostream &operator<<(std::ostream &os, const Velocity &vel)
    {
        os << "Velocity: " << vel.value;
        return os;
    }
};
struct Acceleration
{
    Float3 value;
    Acceleration(Float3 _value)
    {
        value = _value;
    }
    Acceleration(float x, float y, float z)
    {
        value = Float3(x, y, z);
    }
    friend std::ostream &operator<<(std::ostream &os, const Acceleration &acc)
    {
        os << "Acceleration: " << acc.value;
        return os;
    }
};