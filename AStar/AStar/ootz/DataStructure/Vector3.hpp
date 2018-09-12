#pragma once

#include "../Type.hpp"

namespace ootz
{

struct Vector3Int;

struct Vector3
{
    // static properties
    // ...

    // properties
    float x;
    float y;
    float z;

    // constructors
    Vector3();
    Vector3(const float x, const float y, const float z);

    // public methods
    Vector3 Round() const;
    Vector3Int ToVector3Int() const;

    // static methods
    static Vector3 Zero();
    static Vector3 One();
    static List<Vector3> EightDirections();

    // operators
    Vector3& operator+=(const Vector3& other);
    Vector3& operator-=(const Vector3& other);
    Vector3& operator*=(const float other);

    friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
    friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
    friend Vector3 operator*(const Vector3& lhs, const float rhs);
    friend Vector3 operator*(const float lhs, const Vector3& rhs);
    friend Vector3 operator/(const Vector3& lhs, const float rhs);
};

Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
Vector3 operator*(const Vector3& lhs, const float rhs);
Vector3 operator*(const float lhs, const Vector3& rhs);
Vector3 operator/(const Vector3& lhs, const float rhs);

std::ostream& operator<<(std::ostream& os, const Vector3& val);

} // namespace ootz