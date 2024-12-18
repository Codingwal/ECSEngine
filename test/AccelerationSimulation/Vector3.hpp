#pragma once

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
    Vector3 &operator+=(const Vector3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
    Vector3 &operator-=(const Vector3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }
    friend Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs)
    {
        return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }
    friend Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs)
    {
        return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }
    friend Vector3 operator*(const Vector3 &lhs, float scalar)
    {
        return Vector3(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
    }
    friend Vector3 operator/(const Vector3 &lhs, float scalar)
    {
        return Vector3(lhs.x / scalar, lhs.y / scalar, lhs.z / scalar);
    }

    std::string ToString() const
    {
        return "{" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "}";
    }
};