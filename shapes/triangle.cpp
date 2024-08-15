#include "math.h"
#include "triangle.h"

Triangle::Triangle(double a, double b, double c)
    : _a{a}, _b{b}, _c{c}
{}

void Triangle::setA(double a)
{
    _a = a;
}

double Triangle::getA() const
{
    return _a;
}

void Triangle::setB(double b)
{
    _b = b;
}
double Triangle::getB() const
{
    return _b;
}

void Triangle::setC(double c)
{
    _c = c;
}
double Triangle::getC() const
{
    return _c;
}

double Triangle::getArea() const
{
    double p{ (_a + _b + _c)/2 };
    return std::sqrt( p * (p-_a) * (p-_b) * (p-_c) );
}


