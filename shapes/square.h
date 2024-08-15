#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public IShape
{
private:
    double _side;

public:
    Square(double side);

    void setSide(double side);
    double getSide() const;

    double getArea() const override;
};

#endif // SQUARE_H
