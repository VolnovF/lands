#include "math.h"
#include "triangle.h"

Triangle::Triangle()
    : a{0}, b{0}, c{0}
{}
Triangle::Triangle(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

void Triangle::setSides(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

double Triangle::getA() const
{
    return a;
}
double Triangle::getB() const
{
    return b;
}
double Triangle::getC() const
{
    return c;
}

LandType Triangle::getType() const
{
    return LandType::triangle;
}
double Triangle::getArea() const
{
    double s{ (a+b+c)/2 };
    return std::sqrt( s*(s-a)*(s-b)*(s-c) );
}


