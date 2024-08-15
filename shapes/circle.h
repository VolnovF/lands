#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "math.h"

class Circle : public Shape
{
private:
    double _diameter;

public:
    Circle(double diameter);

    void setDiameter(double diameter);
    double getDiameter() const;

    double getArea() const override;
};

#endif // CIRCLE_H
