#include "square.h"

Square::Square(double side)
    : m_side{side}
{}

void Square::setSide(double side)
{
    m_side = side;
}

double Square::getSide() const
{
    return m_side;
}

double Square::getArea() const
{
    return m_side*m_side;
}
