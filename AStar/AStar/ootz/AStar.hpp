#pragma once

#include <map>
#include <deque>

#include "Type.hpp"
#include "Utility.hpp"
#include "Vector3.hpp"
#include "Vector3Int.hpp"

namespace ootz
{

enum class Attributes
{
    kReachable,
    kNonReachable,
};

struct Cell
{
    Attributes attributes = Attributes::kReachable;

    Cell()
    {
    }
};

class GridGraph
{
public:
    using FScore = UInt;
    using Node = Vector3Int;

    struct NodeHash
    {
        Size operator()(const Node& value) const;
    };

private:
    const float nodeSize_;
    const Vector3 center_;
    std::map<FScore, Node> nodes_;

public:
    GridGraph(
        const UInt numNodeX,
        const UInt numNodeZ,
        const float nodeSize = 1.0f,
        const Vector3& center = Vector3::Zero());

    std::deque<Vector3> AStar(const Vector3& start, const Vector3& goal);
    void AddNonReachable(const Vector3& coord);
    std::vector<Cell> GetNeighbors(const Vector3& position);
    UInt HeuristicCostEstimate(const Vector3& start, const Vector3& goal);
    Node GetNearestNode(const Vector3& position);
};

} // namespace ootz