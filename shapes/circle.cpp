#include "circle.h"

Circle::Circle()
    : diameter{0}
{}

Circle::Circle(double diameter)
{
    this->diameter = diameter;
}

void Circle::setDiameter(double diameter)
{
    this->diameter = diameter;
}

double Circle::getDiameter() const
{
    return diameter;
}

LandType Circle::getType() const
{
    return LandType::circle;
}

double Circle::getArea() const
{
    return M_PI * std::pow(diameter/2, 2);
}
