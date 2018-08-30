#pragma once

namespace ootz
{

struct Vector3 : public XMFLOAT3
{
    static Vector3 Zero();
    static Vector3 One();
    static std::vector<Vector3> EightDirections();

    Vector3();
    Vector3(const float x, const float y, const float z);
    Vector3(const XMFLOAT3& other);

    Vector3& operator+=(const Vector3& rhs);
    Vector3& operator-=(const Vector3& rhs);
    Vector3& operator*=(const float rhs);

    friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
    friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
    friend Vector3 operator*(const Vector3& lhs, const float rhs);
    friend Vector3 operator*(const float lhs, const Vector3& rhs);
};

Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
Vector3 operator*(const Vector3& lhs, const float rhs);
Vector3 operator*(const float lhs, const Vector3& rhs);

struct Vector2Int : public XMINT2
{
    static Vector2Int Zero();
    static Vector2Int One();

    Vector2Int();
    Vector2Int(const int32_t x, const int32_t y);
    Vector2Int(const XMINT2& other);

    Vector2Int& operator+=(const Vector2Int& rhs);
    Vector2Int& operator-=(const Vector2Int& rhs);

    friend Vector2Int operator+(const Vector2Int& lhs, const Vector2Int& rhs);
    friend Vector2Int operator-(const Vector2Int& lhs, const Vector2Int& rhs);
    friend Vector2Int operator*(const Vector2Int& lhs, const int32_t rhs);
    friend Vector2Int operator*(const int32_t lhs, const Vector2Int& rhs);
};

Vector2Int operator+(const Vector2Int& lhs, const Vector2Int& rhs);
Vector2Int operator-(const Vector2Int& lhs, const Vector2Int& rhs);
Vector2Int operator*(const Vector2Int& lhs, const int32_t rhs);
Vector2Int operator*(const int32_t lhs, const Vector2Int& rhs);

class Math
{
public:
    
};

} // namespace ootz