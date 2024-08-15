#include "square.h"

Square::Square(double side)
    : _side{side}
{}

void Square::setSide(double side)
{
    _side = side;
}

double Square::getSide() const
{
    return _side;
}

double Square::getArea() const
{
    return _side*_side;
}
