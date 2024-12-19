#pragma once

#include <iostream>
#include "Math/Float2.hpp"

struct Float3
{
public:
    Float3() = default;
    Float3(float _x, float _y, float _z);
    explicit Float3(float value);
    Float3(Float2 vec, float _w);
    float &operator[](int i);
    Float3 &operator+=(const Float3 &other);
    Float3 &operator-=(const Float3 &other);
    Float3 &operator*=(float scalar);
    Float3 &operator/=(float scalar);
    friend Float3 operator+(const Float3 &lhs, const Float3 &rhs);
    friend Float3 operator-(const Float3 &lhs, const Float3 &rhs);
    friend Float3 operator*(const Float3 &vec, float scalar);
    friend Float3 operator/(const Float3 &vec, float scalar);
    friend std::ostream &operator<<(std::ostream &os, Float3 vec);

public:
    float x, y, z, w;
};