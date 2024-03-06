#ifndef SQUARE_H
#define SQUARE_H

#include "../land.h"

class Square : public Land
{
private:
    double side;
public:
    Square();
    Square(double side);
    void setSide(double side);
    double getSide() const;
    LandType getType() const override;
    double getArea() const override;
};

#endif // SQUARE_H
