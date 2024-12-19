#pragma once

#include "FloatX.hpp"
#include <array>

struct Float4x4
{
public:
    Float4x4() = default;
    Float4x4(Float4 _v1, Float4 _v2, Float4 _v3, Float4 _v4);
    Float4x4(float v1x, float v1y, float v1z, float v1w,
             float v2x, float v2y, float v2z, float v2w,
             float v3x, float v3y, float v3z, float v3w,
             float v4x, float v4y, float v4z, float v4w);

    Float4 &
    operator[](int i);
    const Float4 &operator[](int i) const;
    std::array<float, 16> ToColumnMajorArray();

    static Float4x4 Identity();
    static Float4x4 Translate(Float4x4 mat, const Float3 &vec);
    static Float4x4 Scale(Float4x4 mat, const Float3 &vec);
    static Float4x4 Rotate(Float4x4 mat, float angle, Float3 axis);

    friend Float4 operator*(const Float4x4 &m, const Float4 &v);
    friend Float4x4 operator*(const Float4x4 &lhs, const Float4x4 &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Float4x4 &mat);

public:
    Float4 v1, v2, v3, v4;
};