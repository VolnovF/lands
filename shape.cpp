#include "shape.h"

double IShape::getRoundArea() const
{
    return (std::floor(getArea()) * 100) / 100;
}
