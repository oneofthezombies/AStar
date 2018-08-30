#include "stdafx.h"
#include "ootzMath.h"

namespace ootz
{

Vector3 Vector3::Zero()
{
    return Vector3(0.0f, 0.0f, 0.0f);
}

Vector3 Vector3::One()
{
    return Vector3(1.0f, 1.0f, 1.0f);
}

std::vector<Vector3> Vector3::EightDirections()
{
    return std::vector<Vector3>
    {
        Vector3(0.0f, 0.0f, 1.0f),
        Vector3(1.0f, 0.0f, 1.0f),
        Vector3(1.0f, 0.0f, 0.0f),
        Vector3(1.0f, 0.0f, -1.0f),
        Vector3(0.0f, 0.0f, -1.0f),
        Vector3(-1.0f, 0.0f, -1.0f),
        Vector3(-1.0f, 0.0f, 0.0f),
        Vector3(-1.0f, 0.0f, 1.0f)
    };
}

Vector3::Vector3()
    : XMFLOAT3(0.0f, 0.0f, 0.0f)
{
}

Vector3::Vector3(const float x, const float y, const float z)
    : XMFLOAT3(x, y, z)
{
}

Vector3::Vector3(const XMFLOAT3& other)
    : XMFLOAT3(other)
{
}

Vector3& Vector3::operator+=(const Vector3& rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;

    return *this;
}

Vector3& Vector3::operator*=(const float rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;

    return *this;
}

Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Vector3 operator*(const Vector3& lhs, const float rhs)
{
    return Vector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

Vector3 operator*(const float lhs, const Vector3& rhs)
{
    return rhs * lhs;
}

Vector2Int Vector2Int::Zero()
{
    return Vector2Int(0, 0);
}

Vector2Int Vector2Int::One()
{
    return Vector2Int(1, 1);
}

Vector2Int::Vector2Int()
    : XMINT2(0, 0)
{
}

Vector2Int::Vector2Int(const int32_t x, const int32_t y)
    : XMINT2(x, y)
{
}

Vector2Int::Vector2Int(const XMINT2& other)
    : XMINT2(other)
{
}

Vector2Int& Vector2Int::operator+=(const Vector2Int& rhs)
{
    x += rhs.x;
    y += rhs.y;

    return *this;
}

Vector2Int& Vector2Int::operator-=(const Vector2Int& rhs)
{
    x -= rhs.x;
    y -= rhs.y;

    return *this;
}

Vector2Int operator+(const Vector2Int& lhs, const Vector2Int& rhs)
{
    return Vector2Int(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector2Int operator-(const Vector2Int& lhs, const Vector2Int& rhs)
{
    return Vector2Int(lhs.x - rhs.x, lhs.y - rhs.y);
}

Vector2Int operator*(const Vector2Int& lhs, const int32_t rhs)
{
    return Vector2Int(lhs.x * rhs, lhs.y * rhs);
}

Vector2Int operator*(const int32_t lhs, const Vector2Int & rhs)
{
    return rhs * lhs;
}

} // namespace ootz