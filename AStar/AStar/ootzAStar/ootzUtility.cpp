#include "stdafx.h"
#include "ootzUtility.hpp"

#include "ootzVector3.hpp"
#include "ootzVector3Int.hpp"

namespace ootz
{

std::ostream& Endl(std::ostream& os)
{
    os << '\n';
    return os;
}

std::ostream& operator<<(std::ostream& os, const Vector3& val)
{
    os << val.x << ' ' << val.y << ' ' << val.z;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Vector3Int& val)
{
    os << val.x << ' ' << val.y << ' ' << val.z;
    return os;
}

} // namespace ootz