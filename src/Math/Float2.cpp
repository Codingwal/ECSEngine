#include "Math/FloatX.hpp"

Float2::Float2(float _x, float _y)
{
    x = _x;
    y = _y;
}
Float2::Float2(float value)
{
    x = value;
    y = value;
}
float &Float2::operator[](int i)
{
    switch (i)
    {
    case 0:
        return x;
    case 1:
        return y;
    default:
        std::cerr << "Invalid index " << i << "in Float4.\n";
        return x;
    }
}
const float &Float2::operator[](int i) const
{
    switch (i)
    {
    case 0:
        return x;
    case 1:
        return y;
    default:
        std::cerr << "Invalid index " << i << "in Float4.\n";
        return x;
    }
}
Float2 &Float2::operator+=(const Float2 &other)
{
    x += other.x;
    y += other.y;
    return *this;
}
Float2 &Float2::operator-=(const Float2 &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}
Float2 &Float2::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}
Float2 &Float2::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    return *this;
}
Float2 operator+(const Float2 &lhs, const Float2 &rhs)
{
    return Float2(lhs.x + rhs.x, lhs.y + rhs.y);
}
Float2 operator-(const Float2 &lhs, const Float2 &rhs)
{
    return Float2(lhs.x - rhs.x, lhs.y - rhs.y);
}
Float2 operator*(const Float2 &lhs, float scalar)
{
    return Float2(lhs.x * scalar, lhs.y * scalar);
}
Float2 operator/(const Float2 &lhs, float scalar)
{
    return Float2(lhs.x / scalar, lhs.y / scalar);
}
std::ostream &operator<<(std::ostream &os, const Float2 &v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}
