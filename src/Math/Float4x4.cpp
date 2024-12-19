#include "Math/Float4x4.hpp"

Float4x4::Float4x4(Float4 _v1, Float4 _v2, Float4 _v3, Float4 _v4)
{
    v1 = _v1;
    v2 = _v2;
    v3 = _v3;
    v4 = _v4;
}
Float4x4 Float4x4::Identity()
{
    Float4x4 mat = Float4x4();
    mat.v1.x = 1;
    mat.v2.y = 1;
    mat.v3.z = 1;
    mat.v4.w = 1;
    return mat;
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
Float4 operator*(Float4x4 m, Float4 v)
{
    return Float4(m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * v[3],
                  m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * v[3],
                  m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * v[3],
                  m[0][3] * v[0] + m[1][3] * v[1] + m[2][3] * v[2] + m[3][3] * v[3]);
}
Float4x4 operator*(Float4x4 lhs, Float4x4 rhs)
{
    return Float4x4(lhs * rhs[0], lhs * rhs[1], lhs * rhs[2], lhs * rhs[3]);
}
inline std::ostream &operator<<(std::ostream &os, Float4x4 mat)
{
    os << "|" << mat[0][0] << ", " << mat[1][0] << ", " << mat[2][0] << ", " << mat[3][0] << "|\n"
       << "|" << mat[0][1] << ", " << mat[1][1] << ", " << mat[2][1] << ", " << mat[3][1] << "|\n"
       << "|" << mat[0][2] << ", " << mat[1][2] << ", " << mat[2][2] << ", " << mat[3][2] << "|\n"
       << "|" << mat[0][3] << ", " << mat[1][3] << ", " << mat[2][3] << ", " << mat[3][3] << "|\n";
    return os;
}
