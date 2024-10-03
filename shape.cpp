#include "shape.h"

double IShape::getRoundArea() const
{
    return (std::round(getArea()) * 100) / 100;
}

double IShape::getFloorArea() const
{
    return (std::floor(getArea()) * 100) / 100;
}
