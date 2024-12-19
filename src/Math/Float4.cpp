#include "Math/FloatX.hpp"
#include <math.h>

Float4::Float4(float _x, float _y, float _z, float _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}
Float4::Float4(float value)
{
    x = value;
    y = value;
    z = value;
    w = value;
}
Float4::Float4(Float3 vec, float _w)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = _w;
}
float &Float4::operator[](int i)
{
    switch (i)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    case 3:
        return w;
    default:
        std::cerr << "Invalid index " << i << "in Float4.\n";
        return x;
    }
}
const float &Float4::operator[](int i) const
{
    switch (i)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    case 3:
        return w;
    default:
        std::cerr << "Invalid index " << i << "in Float4.\n";
        return x;
    }
}

float Float4::Magnitude() const
{
    return sqrt(x * x + y * y + z * z + w * w);
}
float Float4::MagnitudeSqr() const
{
    return x * x + y * y + z * z + w * w;
}
Float4 Float4::Normalized() const
{
    float s = Magnitude();
    return Float4(x / s, y / s, z / s, w / s);
}

Float4 &Float4::operator+=(const Float4 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}
Float4 &Float4::operator-=(const Float4 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}
Float4 &Float4::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}
Float4 &Float4::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
    return *this;
}
Float4 operator+(const Float4 &lhs, const Float4 &rhs)
{
    return Float4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}
Float4 operator-(const Float4 &lhs, const Float4 &rhs)
{
    return Float4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}
Float4 operator*(const Float4 &vec, float scalar)
{
    return Float4(vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar);
}
Float4 operator/(const Float4 &vec, float scalar)
{
    return Float4(vec.x / scalar, vec.y / scalar, vec.z / scalar, vec.w / scalar);
}
std::ostream &operator<<(std::ostream &os, const Float4 &vec)
{
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
    return os;
}