#pragma once

#include "ootzMath.h"

namespace ootz
{

class AStar
{
public:
    static std::vector<Vector3> FindPath(const GridGraph& graph, const Vector3& start, const Vector3& goal);
};

enum class Attributes
{
    kReachable,
    kNonReachable,
};

struct Cell
{
    Attributes attributes = Attributes::kReachable;

    Cell();
};

class GridGraph
{
private:
    const float stride_;
    std::unordered_map<Vector3, Cell> cells_;

public:
    GridGraph(
        const uint32_t numWidth, 
        const uint32_t numDepth, 
        const float stride, 
        const Vector3& center);

    void AddNonReachable(const Vector3& coord);
    std::vector<Cell> GetNeighbors(const Vector3& position);
};

} // namespace ootz