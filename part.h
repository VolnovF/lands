#ifndef PART_H
#define PART_H

#include <cstdlib>

class Part
{
protected:
    double _area;

public:
    Part() = default;
    Part(double area);

    double getArea() const;
    virtual void calculateArea(double LandArea);

    virtual ~Part() = default;
};

#endif // PART_H
