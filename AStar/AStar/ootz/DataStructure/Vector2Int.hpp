#pragma once

#include "../Type.hpp"

namespace ootz
{

struct Vector2Int
{
    // static properties
    // ...

    // properties
    Int x;
    Int y;

    // constructors
    Vector2Int();
    Vector2Int(const Int x, const Int y);

    // public methods
    // ...

    // static methods
    static Vector2Int Zero();
    static Vector2Int One();

    // operators
    Vector2Int& operator+=(const Vector2Int& other);
    Vector2Int& operator-=(const Vector2Int& other);

    friend Vector2Int operator+(const Vector2Int& lhs, const Vector2Int& rhs);
    friend Vector2Int operator-(const Vector2Int& lhs, const Vector2Int& rhs);
    friend Vector2Int operator*(const Vector2Int& lhs, const Int rhs);
    friend Vector2Int operator*(const Int lhs, const Vector2Int& rhs);
};

Vector2Int operator+(const Vector2Int& lhs, const Vector2Int& rhs);
Vector2Int operator-(const Vector2Int& lhs, const Vector2Int& rhs);
Vector2Int operator*(const Vector2Int& lhs, const Int rhs);
Vector2Int operator*(const Int lhs, const Vector2Int& rhs);

} // namespace ootz