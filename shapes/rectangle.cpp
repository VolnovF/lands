#include "rectangle.h"

Rectangle::Rectangle(double width, double height)
    : _width{width}, _height{height}
{}

void Rectangle::setWidth(double width)
{
    _width = width;
}

void Rectangle::setHeight(double height)
{
    _height = height;
}

double Rectangle::getWidth() const
{
    return _width;
}

double Rectangle::getHeight() const
{
    return _height;
}

double Rectangle::getArea() const
{
    return _width * _height;
}
