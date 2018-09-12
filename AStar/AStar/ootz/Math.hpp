#pragma once

#include "Utility.hpp"

namespace ootz
{

class Combination
{
private:
    using Indices = List<UInt>;

private:
    Indices indices_;

private:
    void CombRec(const UInt n, const UInt r, Indices& indices, List<Indices>& ret)
    {
        if (r == 0)
        {
            ret.emplace_back(indices);
            return;
        }

        if (n == 0)
            return;

        indices.emplace_back(indices_[indices_.size() - n]);
        CombRec(n - 1, r - 1, indices, ret);

        indices.pop_back();
        CombRec(n - 1, r, indices, ret);
    }

public:
    Combination(const UInt n)
        : indices_(Utility::Range<UInt>(n))
    {
    }

    List<Indices> operator()(const UInt r)
    {
        List<Indices> ret;
        Indices indices;
        CombRec(static_cast<UInt>(indices_.size()), r, indices, ret);
        return ret;
    }
};

} // namespace ootz