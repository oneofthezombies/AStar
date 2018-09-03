#pragma once

#include <vector>
#include <numeric>

namespace ootz
{

using Int = int32_t;
using UInt = uint32_t;
using Int64 = int64_t;
using UInt64 = uint64_t;

using Ints = std::vector<Int>;
using UInts = std::vector<UInt>;
using Floats = std::vector<float>;

template<typename ...Ts>
using IsIntegral = std::enable_if_t<std::is_integral_v<Ts>>;

template<typename ...Ts>
using IsUnsigned = std::enable_if_t<std::is_unsigned_v<Ts>>;

class Utility
{
public:

    // [ start, start + step, start + step * 2, ..., stop )
    // e.g.) Range(0, 6, 2) = [0, 2, 4]
    template<
        typename RetT = Int,
        typename T1 = RetT,
        typename T2 = RetT,
        typename T3 = RetT,
        typename = IsIntegral<RetT, T1, T2, T3>>
    static auto Range(const T1& start, const T2& stop, const T3& step) -> std::vector<RetT>
    {
        std::vector<RetT> ret;

        for (RetT i = start; i < stop; i += step)
            ret.emplace_back(i);

        return ret;
    }

    // [ start, start + 1, ..., start + count )
    // e.g.) Range(1, 3) = [1, 2, 3]
    template<
        typename RetT = Int,
        typename T1 = RetT,
        typename T2 = RetT,
        typename = IsIntegral<RetT, T1, T2>>
        static auto Range(const T1& start, const T2& count) -> std::vector<RetT>
    {
        return Range<RetT>(start, start + count, 1);
    }

    // [ 0, 1, ..., count )
    // e.g.) Range(3) = [0, 1, 2]
    template<
        typename RetT = Int,
        typename T = RetT,
        typename = IsIntegral<RetT, T>>
        static auto Range(const T& count) -> std::vector<RetT>
    {
        return Range<RetT>(0, count, 1);
    }
};

} // namespace ootz