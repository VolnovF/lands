#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
#include <cstdlib>

class Fraction
{
private:
    int _numerator;
    int _denominator;
    double _area;
    double _percent;
public:
    Fraction();
    Fraction(int numerator, int denominator = 1);

    int getNumerator() const;
    int getDenominator() const;
    double getArea() const;
    double getPercent() const;

    double calculateArea(double area);
    double value() const;
    double long_value() const;

    Fraction operator+(const Fraction& other) const;
    double operator+(double decimal) const;
    Fraction operator-(const Fraction& other) const;
    double operator-(double decimal) const;
    Fraction operator*(const Fraction& other) const;
    double operator*(double decimal) const;
    Fraction operator/(const Fraction& other) const;
    double operator/(double decimal) const;
    bool operator==(const Fraction& other) const;
    bool operator==(double decimal) const;
    bool operator>(const Fraction& other) const;
    bool operator>(double decimal) const;
    bool operator<(const Fraction& other) const;
    bool operator<(double decimal) const;
    bool operator>=(const Fraction& other) const;
    bool operator>=(double decimal) const;
    bool operator<=(const Fraction& other) const;
    bool operator<=(double decimal) const;
    operator double() const;
    operator long double() const;

    friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
};

#endif // FRACTION_H
