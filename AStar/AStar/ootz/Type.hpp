#pragma once

#include <vector>

namespace ootz
{

using Int = int32_t;
using UInt = uint32_t;
using Int64 = int64_t;
using UInt64 = uint64_t;
using Size = std::size_t;

struct Vector2;
struct Vector3;
struct Vector2Int;
struct Vector3Int;

using Ints = std::vector<Int>;
using UInts = std::vector<UInt>;
using Floats = std::vector<float>;
using Vector2s = std::vector<Vector2>;
using Vector3s = std::vector<Vector3>;
using Vector2Ints = std::vector<Vector2Int>;
using Vector3Ints = std::vector<Vector3Int>;

template<typename ...Ts>
using IsIntegral = std::enable_if_t<std::is_integral_v<Ts>>;

template<typename ...Ts>
using IsUnsigned = std::enable_if_t<std::is_unsigned_v<Ts>>;

} // namespace ootz