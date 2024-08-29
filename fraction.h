#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "part.h"

class Fraction : public Part
{
private:
    int _numerator;
    int _denominator;

public:
    Fraction();
    Fraction(int numerator, int denominator = 1);

    int getNumerator() const;
    int getDenominator() const;

    void calculateArea(double LandArea) override;

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
