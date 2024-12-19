#pragma once

#include "Math/Math.hpp"

namespace ECSEngine
{
    struct Transform
    {
        Float3 position;
        Float3 rotation;
        Float3 scale;
        Transform(Float3 pos, Float3 rot, Float3 scl) : position(pos), rotation(rot), scale(scl) {}
    };
    struct TransformMatrix
    {
        Float4x4 matrix;
    };
    struct PhysicsObject
    {
        Float3 velocity;
        PhysicsObject(Float3 vel) : velocity(vel) {}
    };
}