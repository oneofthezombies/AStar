#include "stdafx.h"

#include <random>
#include <iostream>

#include "ootz/AStar.hpp"
#include "ootz/DataStructure/Tree.hpp"
#include "ootz/Math.hpp"
using namespace ootz;

int main()
{
    Combination comb(4);
    auto res = comb(2);
    for (auto indices : res)
    {
        for (auto i : indices)
        {
            std::cout << i << ", ";
        }
        std::cout << Endl;
    }

    system("pause");
    return 0;
}

