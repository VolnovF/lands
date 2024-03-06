#include "rectangle.h"

Rectangle::Rectangle()
    : width{0}, height{0}
{}

Rectangle::Rectangle(double width, double height)
{
    this->width = width;
    this->height = height;
}

void Rectangle::setSides(double width, double height)
{
    this->width = width;
    this->height = height;
}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getHeight() const
{
    return height;
}

LandType Rectangle::getType() const
{
    return LandType::rectangle;
}

double Rectangle::getArea() const
{
    return width*height;
}
