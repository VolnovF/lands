#include "circle.h"

Circle::Circle(double diameter)
    : Shape(), m_diameter{diameter}
{}

void Circle::setDiameter(double diameter)
{
    m_diameter = diameter;
}

double Circle::getDiameter() const
{
    return m_diameter;
}

double Circle::getArea() const
{
    return M_PI * std::pow(m_diameter/2, 2);
}
