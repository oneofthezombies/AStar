#pragma once

#include "Type.hpp"

namespace ootz
{

struct Vector3Int
{
    // static properties
    // ...

    // properties
    Int x;
    Int y;
    Int z;

    // constructors
    Vector3Int();
    Vector3Int(const Int x, const Int y, const Int z);

    // public methods
    Vector3 ToVector3() const;

    // static methods
    static Vector3Int Zero();
    static Vector3Int One();

    // operators
    Vector3Int& operator+=(const Vector3Int& other);
    Vector3Int& operator-=(const Vector3Int& other);

    friend bool operator==(const Vector3Int& lhs, const Vector3Int& rhs);
    friend bool operator!=(const Vector3Int& lhs, const Vector3Int& rhs);
    friend Vector3Int operator+(const Vector3Int& lhs, const Vector3Int& rhs);
    friend Vector3Int operator-(const Vector3Int& lhs, const Vector3Int& rhs);
    friend Vector3Int operator*(const Vector3Int& lhs, const Int rhs);
    friend Vector3Int operator*(const Int lhs, const Vector3Int& rhs);
};

bool operator==(const Vector3Int& lhs, const Vector3Int& rhs);
bool operator!=(const Vector3Int& lhs, const Vector3Int& rhs);
Vector3Int operator+(const Vector3Int& lhs, const Vector3Int& rhs);
Vector3Int operator-(const Vector3Int& lhs, const Vector3Int& rhs);
Vector3Int operator*(const Vector3Int& lhs, const Int rhs);
Vector3Int operator*(const Int lhs, const Vector3Int& rhs);

} // namespace ootz