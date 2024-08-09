#include "math.h"
#include "triangle.h"

Triangle::Triangle(double a, double b, double c)
    : m_a{a}, m_b{b}, m_c{c}
{}

void Triangle::setA(double a)
{
    m_a = a;
}

double Triangle::getA() const
{
    return m_a;
}

void Triangle::setB(double b)
{
    m_b = b;
}
double Triangle::getB() const
{
    return m_b;
}

void Triangle::setC(double c)
{
    m_c = c;
}
double Triangle::getC() const
{
    return m_c;
}

double Triangle::getArea() const
{
    double s{ (m_a + m_b + m_c)/2 };
    return std::sqrt( s * (s-m_a) * (s-m_b) * (s-m_c) );
}


