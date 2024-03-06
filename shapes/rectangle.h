#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../land.h"

class Rectangle : public Land
{
private:
    double width, height;
public:
    Rectangle();
    Rectangle(double width, double height);
    void setSides(double width, double height);
    double getWidth() const;
    double getHeight() const;
    LandType getType() const override;
    double getArea() const override;
};

#endif // RECTANGLE_H
