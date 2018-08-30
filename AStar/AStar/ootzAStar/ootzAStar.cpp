#include "stdafx.h"
#include "ootzAStar.h"

namespace ootz
{

Cell::Cell()
{
}

GridGraph::GridGraph(
    const uint32_t numWidth, 
    const uint32_t numDepth, 
    const float stride, 
    const Vector3& center)
    : stride_(stride)
{
    const uint32_t numTotal = numWidth * numDepth;

    std::vector<uint32_t> nums(numTotal);
    std::iota(nums.begin(), nums.end(), 0);

    const uint32_t numWidthWithoutCenter = numWidth - 1;
    const uint32_t numDepthWithoutCenter = numDepth - 1;

    const uint32_t numHalfWidth = numWidthWithoutCenter / 2;
    const uint32_t numHalfDepth = numDepthWithoutCenter / 2;

    const float fNumHalfWidth = static_cast<float>(numHalfWidth);
    const float fNumHalfWidth = static_cast<float>(numHalfDepth);

    const Vector3 offset = center - Vector3(numHalfWidth, 0.0f, numHalfDepth) * stride;

    std::for_each(
        nums.begin(), nums.end(), 
        [this, &numWidth, &numDepth, &stride, &offset](const uint32_t n)
    {
        const uint32_t xIdx = n / numWidth;
        const uint32_t zIdx = n % numDepth;

        const float fXIdx = static_cast<float>(xIdx);
        const float fXIdx = static_cast<float>(zIdx);

        cells_.emplace(Vector3(fXIdx, 0.0f, fXIdx) * stride + offset, Cell());
    });
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
        neighbor *= stride_;
        neighbor += position;
    });

    
}

std::vector<Vector3> AStar::FindPath(const GridGraph& graph, const Vector3& start, const Vector3& goal)
{
    std::unordered_set<Vector3> openSet;
    std::unordered_set<Vector3> closedSet;


}

} // namespace ootz