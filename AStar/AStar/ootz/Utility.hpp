#pragma once

#include <iostream>
#include <numeric>
#include <iterator>

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

    template<class Ty>
    static void Swap(Ty& lhs, Ty& rhs)
    {
        Ty temp = lhs;
        lhs = rhs;
        rhs = temp;
    }

    template<class Ty, class Comp>
    static void BubbleSort(List<Ty>& list, const Comp& compare)
    {
        for (int n = list.size(); n > 0; --n)
        {
            for (int i = 0; i < n - 1; ++i)
            {
                if (compare(list[i + 1], list[i]))
                    Swap(list[i + 1], list[i]);
            }
        }
    }

    template<class Ty>
    static void BubbleSort(List<Ty>& list)
    {
        BubbleSort(list, std::less<Ty>{});
    }

    template<class Ty, class Comp>
    static void SelectionSort(List<Ty>& list, const Comp& compare)
    {
        for (int n = 0; n < list.size(); ++n)
        {
            int less_i = n;
            for (int i = n; i < list.size(); ++i)
            {
                if (compare(list[i], list[less_i]))
                    less_i = i;
            }

            Swap(list[n], list[less_i]);
        }
    }

    template<class Ty>
    static void SelectionSort(List<Ty>& list)
    {
        SelectionSort(list, std::less<Ty>{});
    }

    template<class Ty, class Comp>
    static void InsertionSort(List<Ty>& list, const Comp& compare)
    {
        auto findPlace = [](List<Ty>& list, const Size size, const Comp& compare) -> Size
        {
            int i = size - 1;
            for (; i >= 0; --i)
            {
                if (!compare(list[size], list[i]))
                    break;
            }
            ++i;
            return i;
        };

        auto shiftRight = [](List<Ty>& list, const Size first, const Size last, const Size count)
        {
            const auto first_ = list.begin() + first;
            std::move(first_, list.begin() + last, first_ + count);
        };

        for (int n = 1; n < list.size(); ++n)
        {
            auto i = findPlace(list, n, compare);

            Ty temp = list[n];
            shiftRight(list, i, n, 1);
            list[i] = temp;
        }
    }

    template<class Ty>
    static void InsertionSort(List<Ty>& list)
    {
        InsertionSort(list, std::less<Ty>{});
    }
};

std::ostream& Endl(std::ostream& os);

} // namespace ootz