#pragma once

#include <vector>

#include "ootzUtility.hpp"

namespace ootz
{

struct Vector3
{
    // static properties
    // ...

    // properties
    float x;
    float y;
    float z;

    // constructors
    Vector3()
        : x(0.0f)
        , y(0.0f)
        , z(0.0f)
    {
    }

    Vector3(const float x, const float y, const float z)
        : x(x)
        , y(y)
        , z(z)
    {
    }

    // public methods
    // ...

    // static methods
    static Vector3 Zero()
    {
        return Vector3(0.0f, 0.0f, 0.0f);
    }

    static Vector3 One()
    {
        return Vector3(1.0f, 1.0f, 1.0f);
    }

    static std::vector<Vector3> EightDirections()
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

    // operators
    Vector3& operator+=(const Vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }

    Vector3& operator-=(const Vector3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;

        return *this;
    }

    Vector3& operator*=(const float other)
    {
        x *= other;
        y *= other;
        z *= other;

        return *this;
    }

    friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
    friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
    friend Vector3 operator*(const Vector3& lhs, const float rhs);
    friend Vector3 operator*(const float lhs, const Vector3& rhs);
};

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

struct Vector2Int
{
    // static properties
    // ...

    // properties
    Int x;
    Int y;

    // constructors
    Vector2Int()
        : x(0)
        , y(0)
    {
    }

    Vector2Int(const Int x, const Int y)
        : x(x)
        , y(y)
    {
    }

    // public methods
    // ...

    // static methods
    static Vector2Int Zero()
    {
        return Vector2Int(0, 0);
    }

    static Vector2Int One()
    {
        return Vector2Int(1, 1);
    }

    // operators
    Vector2Int& operator+=(const Vector2Int& other)
    {
        x += other.x;
        y += other.y;

        return *this;
    }

    Vector2Int& operator-=(const Vector2Int& other)
    {
        x -= other.x;
        y -= other.y;

        return *this;
    }

    friend Vector2Int operator+(const Vector2Int& lhs, const Vector2Int& rhs);
    friend Vector2Int operator-(const Vector2Int& lhs, const Vector2Int& rhs);
    friend Vector2Int operator*(const Vector2Int& lhs, const Int rhs);
    friend Vector2Int operator*(const Int lhs, const Vector2Int& rhs);
};

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

struct Vector3Int
{
    // static properties
    // ...

    // properties
    Int x;
    Int y;
    Int z;

    // constructors
    Vector3Int()
        : x(0)
        , y(0)
        , z(0)
    {
    }

    Vector3Int(const Int x, const Int y, const Int z)
        : x(x)
        , y(y)
        , z(z)
    {
    }

    // public methods
    // ...

    // static methods
    static Vector3Int Zero()
    {
        return Vector3Int(0, 0, 0);
    }

    static Vector3Int One()
    {
        return Vector3Int(1, 1, 1);
    }

    // operators
    Vector3Int& operator+=(const Vector3Int& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;

        return *this;
    }

    Vector3Int& operator-=(const Vector3Int& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;

        return *this;
    }

    friend Vector3Int operator+(const Vector3Int& lhs, const Vector3Int& rhs);
    friend Vector3Int operator-(const Vector3Int& lhs, const Vector3Int& rhs);
    friend Vector3Int operator*(const Vector3Int& lhs, const Int rhs);
    friend Vector3Int operator*(const Int lhs, const Vector3Int& rhs);
};

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

} // namespace ootz