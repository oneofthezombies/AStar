#include "stdafx.h"
#include "ootzVector2Int.hpp"

namespace ootz
{

Vector2Int Vector2Int::Zero()
{
    return Vector2Int(0, 0);
}

Vector2Int Vector2Int::One()
{
    return Vector2Int(1, 1);
}

Vector2Int::Vector2Int()
    : x(0)
    , y(0)
{
}

Vector2Int::Vector2Int(const Int x, const Int y)
    : x(x)
    , y(y)
{
}

Vector2Int& Vector2Int::operator+=(const Vector2Int& other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vector2Int& Vector2Int::operator-=(const Vector2Int& other)
{
    x -= other.x;
    y -= other.y;

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

Vector2Int operator*(const Vector2Int& lhs, const Int rhs)
{
    return Vector2Int(lhs.x * rhs, lhs.y * rhs);
}

Vector2Int operator*(const Int lhs, const Vector2Int& rhs)
{
    return rhs * lhs;
}

} // namespace ootz