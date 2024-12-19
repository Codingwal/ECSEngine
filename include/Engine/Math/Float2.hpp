#pragma once

#include <iostream>

struct Float2
{
public:
    Float2() = default;
    Float2(float _x, float _y);
    explicit Float2(float value);
    float &operator[](int i);
    Float2 &operator+=(const Float2 &other);
    Float2 &operator-=(const Float2 &other);
    Float2 &operator*=(float scalar);
    Float2 &operator/=(float scalar);
    friend Float2 operator+(const Float2 &lhs, const Float2 &rhs);
    friend Float2 operator-(const Float2 &lhs, const Float2 &rhs);
    friend Float2 operator*(const Float2 &vec, float scalar);
    friend Float2 operator/(const Float2 &vec, float scalar);
    friend std::ostream &operator<<(std::ostream &os, Float2 vec);

public:
    float x, y, z, w;
};