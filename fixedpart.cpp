#include "fixedpart.h"

FixedPart::FixedPart(double area)
    : Part(std::round(area * 100) / 100)
{}

void FixedPart::setArea(double area)
{
    _area = std::round(area * 100) / 100;
}
