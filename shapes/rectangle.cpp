#include "rectangle.h"

Rectangle::Rectangle(double width, double height)
    : m_width{width}, m_height{height}
{}

void Rectangle::setWidth(double width)
{
    m_width = width;
}

void Rectangle::setHeight(double height)
{
    m_height = height;
}

double Rectangle::getWidth() const
{
    return m_width;
}

double Rectangle::getHeight() const
{
    return m_height;
}

double Rectangle::getArea() const
{
    return m_width * m_height;
}
