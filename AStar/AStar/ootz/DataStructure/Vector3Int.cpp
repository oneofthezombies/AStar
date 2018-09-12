#include "stdafx.h"
#include "Vector3Int.hpp"

#include <iostream>

#include "Vector3.hpp"

namespace ootz
{

Vector3Int Vector3Int::Zero()
{
    return Vector3Int(0, 0, 0);
}

Vector3Int Vector3Int::One()
{
    return Vector3Int(1, 1, 1);
}

Vector3Int::Vector3Int()
    : x(0)
    , y(0)
    , z(0)
{
}

Vector3Int::Vector3Int(const Int x, const Int y, const Int z)
    : x(x)
    , y(y)
    , z(z)
{
}

Vector3 Vector3Int::ToVector3() const
{
    return Vector3(
        static_cast<float>(x),
        static_cast<float>(y),
        static_cast<float>(z));
}

Vector3Int& Vector3Int::operator+=(const Vector3Int& other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vector3Int& Vector3Int::operator-=(const Vector3Int& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

bool operator==(const Vector3Int& lhs, const Vector3Int& rhs)
{
    return lhs.x == rhs.x
        && lhs.y == rhs.y
        && lhs.z == rhs.z;
}

bool operator!=(const Vector3Int& lhs, const Vector3Int& rhs)
{
    return !(lhs == rhs);
}

Vector3Int operator+(const Vector3Int& lhs, const Vector3Int& rhs)
{
    return Vector3Int(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vector3Int operator-(const Vector3Int& lhs, const Vector3Int& rhs)
{
    return Vector3Int(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Vector3Int operator*(const Vector3Int& lhs, const Int rhs)
{
    return  Vector3Int(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

Vector3Int operator*(const Int lhs, const Vector3Int& rhs)
{
    return rhs * lhs;
}

std::ostream& operator<<(std::ostream& os, const Vector3Int& val)
{
    os << val.x << ' ' << val.y << ' ' << val.z;
    return os;
}

} // namespace ootz