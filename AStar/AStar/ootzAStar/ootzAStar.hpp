#pragma once

#include <algorithm>
#include <deque>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

#include "ootzMath.hpp"
#include "ootzUtility.hpp"

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
private:
    const float nodeSize_;
    //std::unordered_map<Vector3Int, Cell> cells_;

public:
    GridGraph(
        const UInt numNodeX,
        const UInt numNodeZ,
        const float nodeSize = 1.0f,
        const Vector3& center = Vector3::Zero())
        : nodeSize_(nodeSize)
    {
        const UInt numNode = numNodeX * numNodeZ;

        const std::vector<UInt> nums = Utility::Range<UInt>(numNode);

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

    std::deque<Vector3> AStar(const Vector3& start, const Vector3& goal)
    {
        //std::unordered_set<Vector3> closedSet;
        //
        //std::unordered_set<Vector3> openSet;
        //openSet.insert(start);

        //std::unordered_map<Vector3, Vector3> cameFrom;

        //std::unordered_map<Vector3, uint32_t> gScore;

        ////gScore.emplace(start, std::numeric_limits<uint32_t>().max());

        //std::unordered_map<Vector3, uint32_t> fScore;


    }

    void AddNonReachable(const Vector3& coord)
    {
    }

    std::vector<Cell> GetNeighbors(const Vector3& position)
    {
        std::vector<Vector3> neighbors(Vector3::EightDirections());
        std::for_each(neighbors.begin(), neighbors.end(),
            [&position, this](Vector3& neighbor)
        {
            neighbor *= nodeSize_;
            neighbor += position;
        });
    }

    uint32_t HeuristicCostEstimate(const Vector3& start, const Vector3& goal)
    {

    }
};







} // namespace ootz