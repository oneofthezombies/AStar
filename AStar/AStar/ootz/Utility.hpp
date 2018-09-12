#pragma once

#include <iostream>
#include <numeric>

#include "Type.hpp"

namespace ootz
{

class Utility
{
public:

    // [ start, start + step, start + step * 2, ..., stop )
    // e.g.) Range(0, 6, 2) = [0, 2, 4]
    template<
        class RetTy = Int,
        class T1 = RetTy,
        class T2 = RetTy,
        class T3 = RetTy,
        typename = IsIntegral<RetTy, T1, T2, T3>>
    static auto Range(const T1& start, const T2& stop, const T3& step) -> List<RetTy>
    {
        List<RetTy> ret;

        for (RetTy i = start; i < stop; i += step)
            ret.emplace_back(i);

        return ret;
    }

    // [ start, start + 1, ..., start + count )
    // e.g.) Range(1, 3) = [1, 2, 3]
    template<
        class RetTy = Int,
        class T1 = RetTy,
        class T2 = RetTy,
        typename = IsIntegral<RetTy, T1, T2>>
    static auto Range(const T1& start, const T2& count) -> List<RetTy>
    {
        List<RetTy> ret(count);
        std::iota(ret.begin(), ret.end(), start);
        return ret;
    }

    // [ 0, 1, ..., count )
    // e.g.) Range(3) = [0, 1, 2]
    template<
        class RetTy = Int,
        class T = RetTy,
        typename = IsIntegral<RetTy, T>>
    static auto Range(const T& count) -> List<RetTy>
    {
        return Range<RetTy>(0, count);
    }
};

std::ostream& Endl(std::ostream& os);

} // namespace ootz