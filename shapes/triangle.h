#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../land.h"

class Triangle : public Land
{
private:
    double a, b, c;
public:
    Triangle();
    Triangle(double constr_a, double constr_b, double constr_c);
    void setSides(double a, double b, double c);
    double getA() const;
    double getB() const;
    double getC() const;
    LandType getType() const override;
    double getArea() const override;

};


#endif // TRIANGLE_H
