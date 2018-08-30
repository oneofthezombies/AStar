#pragma once

namespace ootz
{

using float3 = XMFLOAT3;

class AStar
{
private:


public:
};

struct Cell
{
    float3 coord;

    Cell();
};

class GridGraph
{
private:
    std::vector<Cell> m_Cells;

public:

};

} // namespace ootz