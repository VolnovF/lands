#ifndef SHAPE_H
#define SHAPE_H

#include <cmath>
#include <round.h>

class IShape
{
protected:
    IShape() = default;

public:
    virtual double getArea() const = 0;
    virtual double getRoundArea() const;
    virtual double getFloorArea() const;

    virtual ~IShape() = default;
};

#endif // SHAPE_H
