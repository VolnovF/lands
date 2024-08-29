#include "part.h"

Part::Part(double area)
    : _area{area}
{
    if (_area < 0.0) { exit(EXIT_FAILURE); }
}

double Part::getArea() const
{
    return _area;
}

void Part::calculateArea(double LandArea)
{
    if (_area > LandArea) { exit(EXIT_FAILURE); }
}
