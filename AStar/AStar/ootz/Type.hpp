#pragma once

#include <vector>

namespace ootz
{

using Int = int32_t;
using UInt = uint32_t;
using Int64 = int64_t;
using UInt64 = uint64_t;
using Size = std::size_t;

template<typename T>
using List = std::vector<T>;

template<typename ...Ts>
using IsIntegral = std::enable_if_t<std::is_integral_v<Ts>>;

template<typename ...Ts>
using IsUnsigned = std::enable_if_t<std::is_unsigned_v<Ts>>;

} // namespace ootz