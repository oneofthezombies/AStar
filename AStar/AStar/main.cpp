#include "stdafx.h"

#include <random>
#include <iostream>
#include <string>

#include "ootz/AStar.hpp"
#include "ootz/DataStructure/Tree.hpp"
#include "ootz/Math.hpp"
using namespace ootz;

int main()
{
    //Combination comb(4);
    //auto res = comb(3);
    //for (auto indices : res)
    //{
    //    for (auto i : indices)
    //    {
    //        std::cout << i << ", ";
    //    }
    //    std::cout << Endl;
    //}

    List<int> a = { 3, 5, 4, 2, 1 };
    //Utility::BubbleSort(a);
    //Utility::SelectionSort(a);
    Utility::InsertionSort(a);

    for (auto i : a)
    {
        std::cout << i << ", ";
    }

    system("pause");
    return 0;
}

