#pragma once

#include "Math/Math.hpp"

namespace ECSEngine
{
    struct Transform
    {
        Float3 position;
        Float3 rotation;
        Float3 scale;
    };
    struct TransformMatrix
    {
        Float4x4 matrix;
    };
}