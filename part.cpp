#include "part.h"

Part::Part(Fraction fraction, double landArea)
{
    _area = fraction * landArea;
    double roundArea{ std::floor(_area * 100) / 100 };
    _remains = _area - roundArea;
    _area = roundArea;
}

Part::Part(double area)
    : _area{std::floor(area * 100) / 100}, _remains{0}
{}

double Part::getArea() const
{
    return _area;
}

double Part::getRemains() const
{
    return _remains;
}
