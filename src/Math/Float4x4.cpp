#include "Math/Float4x4.hpp"
#include <math.h>

Float4x4::Float4x4(Float4 _v1, Float4 _v2, Float4 _v3, Float4 _v4)
{
    v1 = _v1;
    v2 = _v2;
    v3 = _v3;
    v4 = _v4;
}

Float4x4::Float4x4(float v1x, float v1y, float v1z, float v1w,
                   float v2x, float v2y, float v2z, float v2w,
                   float v3x, float v3y, float v3z, float v3w,
                   float v4x, float v4y, float v4z, float v4w)
{
    v1 = Float4(v1x, v1y, v1z, v1w);
    v2 = Float4(v2x, v2y, v2z, v2w);
    v3 = Float4(v3x, v3y, v3z, v3w);
    v4 = Float4(v4x, v4y, v4z, v4w);
}
Float4 &Float4x4::operator[](int i)
{
    switch (i)
    {
    case 0:
        return v1;
    case 1:
        return v2;
    case 2:
        return v3;
    case 3:
        return v4;
    default:
        std::cerr << "Invalid index " << i << "in Float4x4.\n";
        return v1;
    }
}
const Float4 &Float4x4::operator[](int i) const
{
    switch (i)
    {
    case 0:
        return v1;
    case 1:
        return v2;
    case 2:
        return v3;
    case 3:
        return v4;
    default:
        std::cerr << "Invalid index " << i << "in Float4x4.\n";
        return v1;
    }
}

std::array<float, 16> Float4x4::ToColumnMajorArray()
{
    return std::array<float, 16>() = {
               v1[0], v1[1], v1[2], v1[3], // v1
               v2[0], v2[1], v2[2], v2[3], // v2
               v3[0], v3[1], v3[2], v3[3], // v3
               v4[0], v4[1], v4[2], v4[3], // v4
           };
}
Float4x4 Float4x4::Identity()
{
    Float4x4 mat = Float4x4();
    mat[0][0] = 1;
    mat[1][1] = 1;
    mat[2][2] = 1;
    mat[3][3] = 1;
    return mat;
}
Float4x4 Float4x4::Translate(Float4x4 mat, const Float3 &vec)
{
    mat[3] = mat[0] * vec[0] + mat[1] * vec[1] + mat[2] * vec[2] + mat[3];
    return mat;
}
Float4x4 Float4x4::Scale(Float4x4 mat, const Float3 &vec)
{
    mat[0] *= vec.x;
    mat[1] *= vec.y;
    mat[2] *= vec.z;
    return mat;
}
// Copied from https://github.com/g-truc/glm/blob/78f686b4be6c623df829db58b974bf8d79461987/glm/gtc/matrix_transform.inl
Float4x4 Float4x4::Rotate(Float4x4 mat, float angle, Float3 axis)
{
    const float a = angle;
    const float c = cos(a);
    const float s = sin(a);

    axis = axis.Normalized();
    Float3 tmp = axis * (1 - c);

    Float4x4 rotate = Float4x4();
    rotate[0][0] = c + tmp[0] * axis[0];
    rotate[0][1] = 0 + tmp[0] * axis[1] + s * axis[2];
    rotate[0][2] = 0 + tmp[0] * axis[2] - s * axis[1];

    rotate[1][0] = 0 + tmp[1] * axis[0] - s * axis[2];
    rotate[1][1] = c + tmp[1] * axis[1];
    rotate[1][2] = 0 + tmp[1] * axis[2] + s * axis[0];

    rotate[2][0] = 0 + tmp[2] * axis[0] + s * axis[1];
    rotate[2][1] = 0 + tmp[2] * axis[1] - s * axis[0];
    rotate[2][2] = c + tmp[2] * axis[2];

    Float4x4 result = Float4x4();
    result[0] = mat[0] * rotate[0][0] + mat[1] * rotate[0][1] + mat[2] * rotate[0][2];
    result[1] = mat[0] * rotate[1][0] + mat[1] * rotate[1][1] + mat[2] * rotate[1][2];
    result[2] = mat[0] * rotate[2][0] + mat[1] * rotate[2][1] + mat[2] * rotate[2][2];
    result[3] = mat[3];

    return result;
}

Float4 operator*(const Float4x4 &m, const Float4 &v)
{
    return Float4(m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * v[3],
                  m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * v[3],
                  m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * v[3],
                  m[0][3] * v[0] + m[1][3] * v[1] + m[2][3] * v[2] + m[3][3] * v[3]);
}
Float4x4 operator*(const Float4x4 &lhs, const Float4x4 &rhs)
{
    return Float4x4(lhs * rhs[0], lhs * rhs[1], lhs * rhs[2], lhs * rhs[3]);
}
std::ostream &operator<<(std::ostream &os, const Float4x4 &mat)
{
    os << "|" << mat[0][0] << ", " << mat[1][0] << ", " << mat[2][0] << ", " << mat[3][0] << "|\n"
       << "|" << mat[0][1] << ", " << mat[1][1] << ", " << mat[2][1] << ", " << mat[3][1] << "|\n"
       << "|" << mat[0][2] << ", " << mat[1][2] << ", " << mat[2][2] << ", " << mat[3][2] << "|\n"
       << "|" << mat[0][3] << ", " << mat[1][3] << ", " << mat[2][3] << ", " << mat[3][3] << "|\n";
    return os;
}
