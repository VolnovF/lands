#include "square.h"

Square::Square()
    : side{0}
{}

Square::Square(double side)
{
    this->side = side;
}

void Square::setSide(double side)
{
    this->side = side;
}

double Square::getSide() const
{
    return side;
}

LandType Square::getType() const
{
    return LandType::square;
}

double Square::getArea() const
{
    return side*side;
}
