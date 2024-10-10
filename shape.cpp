#include "shape.h"

double IShape::getRoundArea() const
{
    return Round(getArea());
}

double IShape::getFloorArea() const
{
    return Floor(getArea());
}
