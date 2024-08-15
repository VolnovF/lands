#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public IShape
{
private:
    double _width, _height;

public:
    Rectangle(double width, double height);

    void setWidth(double width);
    void setHeight(double height);
    double getWidth() const;
    double getHeight() const;

    double getArea() const override;
};

#endif // RECTANGLE_H
