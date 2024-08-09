#include "fraction.h"

Fraction::Fraction()
{}

Fraction::Fraction(int numerator, int denominator)
    : m_numerator{numerator}, m_denominator{denominator}
{
    if (!m_denominator)
    {
        exit(EXIT_FAILURE);
    }
}

double Fraction::value() const
{
    return (double)m_numerator / m_denominator;
}

double Fraction::long_value() const
{
    return (long double)m_numerator / m_denominator;
}

Fraction Fraction::operator+(const Fraction& other)
{
    return Fraction
    {
        m_numerator * other.m_denominator + other.m_numerator * m_denominator,
        m_denominator * other.m_denominator
    };
}

Fraction Fraction::operator-(const Fraction& other)
{
    return Fraction
    {
        m_numerator * other.m_denominator - other.m_numerator * m_denominator,
        m_denominator * other.m_denominator
    };
}

Fraction Fraction::operator*(const Fraction& other)
{
    return Fraction
    {
        m_numerator * other.m_numerator,
        m_denominator * other.m_denominator
    };
}

Fraction Fraction::operator/(const Fraction& other)
{
    return Fraction
    {
        m_numerator * other.m_denominator,
        m_denominator * other.m_numerator
    };
}

bool Fraction::operator==(const Fraction &other) const
{
    return value() == other.value();
}

bool Fraction::operator==(double other_value) const
{
    return value() == other_value;
}


bool Fraction::operator>(const Fraction &other) const
{
    return value() > other.value();
}

bool Fraction::operator>(double other_value) const
{
    return value() == other_value;
}

bool Fraction::operator<(const Fraction &other) const
{
    return value() < other.value();
}

bool Fraction::operator<(double other_value) const
{
    return value() == other_value;
}

bool Fraction::operator>=(const Fraction &other) const
{
    return value() >= other.value();
}

bool Fraction::operator>=(double other_value) const
{
    return value() == other_value;
}

bool Fraction::operator<=(const Fraction &other) const
{
    return value() <= other.value();
}

bool Fraction::operator<=(double other_value) const
{
    return value() == other_value;
}

Fraction::operator double() const
{
    return value();
}

Fraction::operator long double() const
{
    return long_value();
}

std::ostream& operator<< (std::ostream &out, const Fraction &fraction)
{
    out << fraction.m_numerator << '/' << fraction.m_denominator;
    return out;
}
