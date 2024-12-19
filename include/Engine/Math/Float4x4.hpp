#pragma once

#include "Float4.hpp"

struct Float4x4
{
public:
    Float4x4() = default;
    Float4x4(Float4 _v1, Float4 _v2, Float4 _v3, Float4 _v4);
    static Float4x4 Identity();
    Float4 &operator[](int i);
    friend Float4 operator*(Float4x4 m, Float4 v);
    friend Float4x4 operator*(Float4x4 lhs, Float4x4 rhs);
    inline friend std::ostream &operator<<(std::ostream &os, Float4x4 mat);

public:
    Float4 v1, v2, v3, v4;
};