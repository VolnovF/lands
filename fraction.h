#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstdlib>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction();
    Fraction(int numerator, int denominator = 1);

    double value() const;
    double long_value() const;
    Fraction operator+(const Fraction& other);
    Fraction operator-(const Fraction& other);
    Fraction operator*(const Fraction& other);
    Fraction operator/(const Fraction& other);
    bool operator==(const Fraction& other) const;
    bool operator==(double other_value) const;
    bool operator>(const Fraction& other) const;
    bool operator>(double other_value) const;
    bool operator<(const Fraction& other) const;
    bool operator<(double other_value) const;
    bool operator>=(const Fraction& other) const;
    bool operator>=(double other_value) const;
    bool operator<=(const Fraction& other) const;
    bool operator<=(double other_value) const;
    operator double() const;
    operator long double() const;

    friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
};

#endif // FRACTION_H
