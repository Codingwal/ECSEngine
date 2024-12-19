#pragma once

#include "Constants.hpp"

#include "FloatX.hpp"
#include "Float4x4.hpp"

class Math
{
    Math() = delete;

public:
    static float ToRadians(float degrees)
    {
        return degrees / 180.0f * PI;
    }
    static float ToDegrees(float radians)
    {
        return radians * 180.0f / PI;
    }
};