#include "stdafx.h"
#include "ootzAStar.h"

namespace ootz
{

Cell::Cell()
    : coord(Vector3::Zero())
{
}

Cell::Cell(const float x, const float y, const float z)
    : coord(x, y, z)
{
}

Cell::Cell(const Vector3& coord)
    : coord(coord)
{
}

GridGraph::GridGraph(
    const uint32_t numWidth, 
    const uint32_t numDepth, 
    const float stride, 
    const Vector3& center)
{
    const uint32_t numTotal = numWidth * numDepth;

    std::vector<uint32_t> nums(numTotal);
    std::iota(nums.begin(), nums.end(), 0);

    const uint32_t numWidthWithoutCenter = numWidth - 1;
    const uint32_t numDepthWithoutCenter = numDepth - 1;
    const uint32_t numHalfWidth = numWidthWithoutCenter / 2;
    const uint32_t numHalfDepth = numDepthWithoutCenter / 2;

    const Vector3 offset = center - Vector3(numHalfWidth, 0.0f, numHalfDepth) * stride;

    std::transform(
        nums.begin(), nums.end(), 
        std::back_inserter(cells_), 
        [&numWidth, &numDepth, &stride, &offset](const uint32_t n)
    {
        const uint32_t xi = n / numWidth;
        const uint32_t zi = n % numDepth;

        return Vector3(xi, 0.0f, zi) * stride + offset;
    });
}

} // namespace ootz