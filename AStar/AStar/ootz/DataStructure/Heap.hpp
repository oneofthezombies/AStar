#pragma once

#include "ootz/Type.hpp"

namespace ootz
{

template<class Ty, class Comp>
class Heap
{
private:
    List<Ty> heap_;
    Comp compare_;

private:
    void MakeHeap()
    {

    }

public:
    Heap()
        : compare_(std::less<Ty>{})
    {
    }

    Heap(const List<Ty>& list)
        : compare_(std::less<Ty>{})
        : heap_(list)
    {
        MakeHeap();
    }
};

} // namespace ootz