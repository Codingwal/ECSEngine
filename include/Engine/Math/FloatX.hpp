#pragma once

#include <iostream>

struct Float2
{
public:
    Float2() = default;
    Float2(float _x, float _y);
    explicit Float2(float value);

    float &operator[](int i);
    const float &operator[](int i) const;

    float Magnitude() const;
    float MagnitudeSqr() const;
    Float2 Normalized() const;

    Float2 &operator+=(const Float2 &other);
    Float2 &operator-=(const Float2 &other);
    Float2 &operator*=(float scalar);
    Float2 &operator/=(float scalar);

    friend Float2 operator+(const Float2 &lhs, const Float2 &rhs);
    friend Float2 operator-(const Float2 &lhs, const Float2 &rhs);
    friend Float2 operator*(const Float2 &vec, float scalar);
    friend Float2 operator/(const Float2 &vec, float scalar);
    friend std::ostream &operator<<(std::ostream &os, const Float2 &vec);

public:
    float x, y;
};

struct Float3
{
public:
    Float3() = default;
    Float3(float _x, float _y, float _z);
    explicit Float3(float value);
    Float3(Float2 vec, float _z);

    float &operator[](int i);
    const float &operator[](int i) const;

    float Magnitude() const;
    float MagnitudeSqr() const;
    Float3 Normalized() const;

    Float3 &operator+=(const Float3 &other);
    Float3 &operator-=(const Float3 &other);
    Float3 &operator*=(float scalar);
    Float3 &operator/=(float scalar);

    friend Float3 operator+(const Float3 &lhs, const Float3 &rhs);
    friend Float3 operator-(const Float3 &lhs, const Float3 &rhs);
    friend Float3 operator*(const Float3 &vec, float scalar);
    friend Float3 operator/(const Float3 &vec, float scalar);
    friend std::ostream &operator<<(std::ostream &os, const Float3 &vec);

public:
    float x, y, z;
};

struct Float4
{
public:
    Float4() = default;
    Float4(float _x, float _y, float _z, float _w);
    explicit Float4(float value);
    Float4(Float3 vec, float _w);

    float &operator[](int i);
    const float &operator[](int i) const;

    float Magnitude() const;
    float MagnitudeSqr() const;
    Float4 Normalized() const;

    Float4 &operator+=(const Float4 &other);
    Float4 &operator-=(const Float4 &other);
    Float4 &operator*=(float scalar);
    Float4 &operator/=(float scalar);

    friend Float4 operator+(const Float4 &lhs, const Float4 &rhs);
    friend Float4 operator-(const Float4 &lhs, const Float4 &rhs);
    friend Float4 operator*(const Float4 &vec, float scalar);
    friend Float4 operator/(const Float4 &vec, float scalar);
    friend std::ostream &operator<<(std::ostream &os, const Float4 &vec);

public:
    float x, y, z, w;
};