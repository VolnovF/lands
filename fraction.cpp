#include "fraction.h"

Fraction::Fraction()
{}

Fraction::Fraction(int numerator, int denominator)
    : _numerator{numerator}, _denominator{denominator}
{
    if (!_denominator)
    {
        exit(EXIT_FAILURE);
    }
}

int Fraction::getNumerator() const
{
    return _numerator;
}

int Fraction::getDenominator() const
{
    return _denominator;
}

double Fraction::getArea() const
{
    return _area;
}

double Fraction::getRemains() const
{
    return _remains;
}

double Fraction::calculateArea(double area)
{
    _area = *this * area;
    double roundArea{ std::floor(_area * 100) / 100 };
    _remains = _area - roundArea;
    _area = roundArea;
    return _area;
}

double Fraction::value() const
{
    return (double)_numerator / _denominator;
}

double Fraction::long_value() const
{
    return (long double)_numerator / _denominator;
}

Fraction Fraction::operator+(const Fraction& other) const
{
    return Fraction
        {
            _numerator * other._denominator + other._numerator * _denominator,
            _denominator * other._denominator
        };
}

double Fraction::operator+(double decimal) const
{
    return  ((decimal * _denominator) + _numerator) / _denominator;
}

Fraction Fraction::operator-(const Fraction& other) const
{
    return Fraction
        {
            _numerator * other._denominator - other._numerator * _denominator,
            _denominator * other._denominator
        };
}

double Fraction::operator-(double decimal) const
{
    return  ((decimal * _denominator) - _numerator) / _denominator;
}

Fraction Fraction::operator*(const Fraction& other) const
{
    return Fraction
        {
            _numerator * other._numerator,
            _denominator * other._denominator
        };
}

double Fraction::operator*(double decimal) const
{
    return decimal * _numerator / _denominator;
}

Fraction Fraction::operator/(const Fraction& other) const
{
    return Fraction
        {
            _numerator * other._denominator,
            _denominator * other._numerator
        };
}

double Fraction::operator/(double decimal) const
{
    return  _numerator / (decimal * _denominator);
}

bool Fraction::operator==(const Fraction &other) const
{
    return value() == other.value();
}

bool Fraction::operator==(double decimal) const
{
    return value() == decimal;
}

bool Fraction::operator>(const Fraction &other) const
{
    return value() > other.value();
}

bool Fraction::operator>(double decimal) const
{
    return value() == decimal;
}

bool Fraction::operator<(const Fraction &other) const
{
    return value() < other.value();
}

bool Fraction::operator<(double decimal) const
{
    return value() == decimal;
}

bool Fraction::operator>=(const Fraction &other) const
{
    return value() >= other.value();
}

bool Fraction::operator>=(double decimal) const
{
    return value() == decimal;
}

bool Fraction::operator<=(const Fraction &other) const
{
    return value() <= other.value();
}

bool Fraction::operator<=(double decimal) const
{
    return value() == decimal;
}

Fraction::operator double() const
{
    std::cout << "operator double()\n"; //
    return value();
}

Fraction::operator long double() const
{
    return long_value();
}

std::ostream& operator<< (std::ostream &out, const Fraction &fraction)
{
    out << fraction._numerator << '/' << fraction._denominator;
    return out;
}
