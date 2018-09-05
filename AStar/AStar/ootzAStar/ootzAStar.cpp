#include "stdafx.h"
#include "ootzAStar.hpp"

#include <unordered_set>
#include <unordered_map>

#include <boost/functional/hash.hpp>

namespace ootz
{

Size GridGraph::NodeHash::operator()(const Node& key) const
{
    Size seed = 0;
    boost::hash_combine(seed, key.x);
    boost::hash_combine(seed, key.y);
    boost::hash_combine(seed, key.z);
    return seed;
}

GridGraph::GridGraph(
    const UInt numNodeX,
    const UInt numNodeZ,
    const float nodeSize,
    const Vector3& center)
    : nodeSize_(nodeSize)
    , center_(center)
{
    assert(nodeSize != 0.0f && "node size is zero");

    const UInt numNode = numNodeX * numNodeZ;

    const UInts nums = Utility::Range<UInt>(numNode);

    const UInt widthWithoutCenter = numNodeX - 1;
    const UInt depthWithoutCenter = numNodeZ - 1;

    const UInt halfWidth = widthWithoutCenter / 2;
    const UInt halfDepth = depthWithoutCenter / 2;

    const float fhalfWidth = static_cast<float>(halfWidth);
    const float fhalfDepth = static_cast<float>(halfDepth);

    const Vector3 offset = center - Vector3(fhalfWidth, 0.0f, fhalfDepth) * nodeSize;

    //std::for_each(
    //    nums.begin(), nums.end(),
    //    [this, &numNodeX, &numNodeZ, &nodeSize, &offset](const uint32_t n)
    //{
    //    const uint32_t xIdx = n / numNodeX;
    //    const uint32_t zIdx = n % numNodeZ;

    //    const float fXIdx = static_cast<float>(xIdx);
    //    const float fZIdx = static_cast<float>(zIdx);

    //    //cells_.emplace(Vector3(fXIdx, 0.0f, fZIdx) * nodeSize + offset, Cell());
    //});
}

std::deque<Vector3> GridGraph::AStar(const Vector3& start, const Vector3& goal)
{
    std::unordered_set<Node, NodeHash> closedSet;
    std::unordered_set<Node, NodeHash> openSet;
    openSet.emplace(GetNearestNode(start));

    std::unordered_map<Node, Node, NodeHash> cameFrom;
    std::unordered_map<Node, UInt, NodeHash> gScore;
    gScore.emplace(start, std::numeric_limits<UInt>().max());

    std::unordered_map<Node, UInt, NodeHash> fScore;

    return std::deque<Vector3>();
}

void GridGraph::AddNonReachable(const Vector3& coord)
{
}

std::vector<Cell> GridGraph::GetNeighbors(const Vector3& position)
{
    std::vector<Vector3> neighbors(Vector3::EightDirections());
    std::for_each(neighbors.begin(), neighbors.end(),
        [&position, this](Vector3& neighbor)
    {
        neighbor *= nodeSize_;
        neighbor += position;
    });

    return std::vector<Cell>();
}

UInt GridGraph::HeuristicCostEstimate(const Vector3& start, const Vector3& goal)
{
    return UInt();
}

GridGraph::Node GridGraph::GetNearestNode(const Vector3& position)
{
    const Vector3 relativePos(position - center_);
    const Vector3 scaledPos(relativePos / nodeSize_);
    return scaledPos.Round().ToVector3Int();
}



} // namespace ootz