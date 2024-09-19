#ifndef PART_H
#define PART_H

#include "fraction.h"

class Part
{
private:
    double _area;
    double _remains;
public:
    Part(Fraction fraction, double landArea);
    Part(double area);

    double getArea() const;
    double getRemains() const;
};

#endif // PART_H
