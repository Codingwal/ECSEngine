#include "Math/FloatX.hpp"

Float3::Float3(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}
Float3::Float3(float value)
{
    x = value;
    y = value;
    z = value;
}
Float3::Float3(Float2 vec, float _z)
{
    x = vec.x;
    y = vec.y;
    z = _z;
}
float &Float3::operator[](int i)
{
    switch (i)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    default:
        std::cerr << "Invalid index " << i << "in Float4.\n";
        return x;
    }
}
const float &Float3::operator[](int i)const
{
    switch (i)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    default:
        std::cerr << "Invalid index " << i << "in Float4.\n";
        return x;
    }
}
Float3 &Float3::operator+=(const Float3 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}
Float3 &Float3::operator-=(const Float3 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}
Float3 &Float3::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}
Float3 &Float3::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}
Float3 operator+(const Float3 &lhs, const Float3 &rhs)
{
    return Float3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}
Float3 operator-(const Float3 &lhs, const Float3 &rhs)
{
    return Float3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}
Float3 operator*(const Float3 &lhs, float scalar)
{
    return Float3(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
}
Float3 operator/(const Float3 &lhs, float scalar)
{
    return Float3(lhs.x / scalar, lhs.y / scalar, lhs.z / scalar);
}
std::ostream &operator<<(std::ostream &os, const Float3 &v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}