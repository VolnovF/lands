#include "circle.h"

Circle::Circle(double diameter)
    : Shape(), _diameter{diameter}
{}

void Circle::setDiameter(double diameter)
{
    _diameter = diameter;
}

double Circle::getDiameter() const
{
    return _diameter;
}

double Circle::getArea() const
{
    return M_PI * std::pow(_diameter/2, 2);
}
