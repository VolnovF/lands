#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public IShape
{
private:
    double _a, _b, _c;

public:
    Triangle(double constr_a, double constr_b, double constr_c);

    void setA(double a);
    double getA() const;
    void setB(double b);
    double getB() const;
    void setC(double c);
    double getC() const;

    double getArea() const override;

};


#endif // TRIANGLE_H
