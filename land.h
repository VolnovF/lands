#ifndef LAND_H
#define LAND_H

#include <iostream>
#include <string>
#include <map>

#include "shape.h"
#include "fraction.h"

class Holder;

class Land
{
private:
    std::string m_addres;
    Shape* m_shape;
    std::map<unsigned int,Fraction> m_holders;

public:
    Land(const std::string& addres, Shape* shape);

    void setShape(Shape* shape);
    double getArea() const;
    long double getHolderArea(unsigned int passport) const;
    double sumParts() const;

    ~Land();

    bool addHolder(unsigned int passport, Fraction part);
};

#endif // LAND_H
