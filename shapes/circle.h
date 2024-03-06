#ifndef CIRCLE_H
#define CIRCLE_H

#include "../land.h"
#include "math.h"

class Circle : public Land
{
private:
    double diameter;
public:
    Circle();
    Circle(double diameter);
    void setDiameter(double diameter);
    double getDiameter() const;
    LandType getType() const override;
    double getArea() const override;
};

#endif // CIRCLE_H
