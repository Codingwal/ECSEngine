#pragma once

#include <iostream>
#include "Math/Float3.hpp"

struct Float4
{
public:
    Float4() = default;
    Float4(float _x, float _y, float _z, float _w);
    explicit Float4(float value);
    Float4(Float3 vec, float _w);
    float &operator[](int i);
    Float4 &operator+=(const Float4 &other);
    Float4 &operator-=(const Float4 &other);
    Float4 &operator*=(float scalar);
    Float4 &operator/=(float scalar);
    friend Float4 operator+(const Float4 &lhs, const Float4 &rhs);
    friend Float4 operator-(const Float4 &lhs, const Float4 &rhs);
    friend Float4 operator*(const Float4 &vec, float scalar);
    friend Float4 operator/(const Float4 &vec, float scalar);
    friend std::ostream &operator<<(std::ostream &os, Float4 vec);

public:
    float x, y, z, w;
};