#pragma once

#include "ootzMath.h"

namespace ootz
{

class AStar
{
private:


public:
};

struct Cell
{
    Vector3 coord;

    Cell();
    Cell(const float x, const float y, const float z);
    Cell(const Vector3& coord);
};

class GridGraph
{
private:
    std::vector<Cell> cells_;

public:
    GridGraph(
        const uint32_t numWidth, 
        const uint32_t numDepth, 
        const float stride, 
        const Vector3& center);
};

} // namespace ootz