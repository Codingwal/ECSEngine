#pragma once

#include "Math/Math.hpp"

namespace ECSEngine
{
    struct Transform
    {
        Float3 position;
        Float3 rotation;
        Float3 scale;
        Transform(Float3 pos) : position(pos), scale(Float3(1)), rotation(Float3()) {}
    };
    struct TransformMatrix
    {
        Float4x4 matrix;
    };
}