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
    Shape* _shape;
    std::string _addres;
    std::map<unsigned int,Fraction> _holders;

public:
    Land(const std::string& addres, Shape* shape);

    void setAddres(const std::string& addres);
    void setShape(Shape* shape);

    const std::string& getAddres() const;
    double getArea() const;
    const Fraction* getFraction(unsigned int passport) const;
    long double getHolderArea(unsigned int passport) const;
    const std::map<unsigned int,Fraction>& getHolders() const;

    double sumParts() const;

    ~Land();

    bool addHolder(unsigned int passport, Fraction part); //определение в holder.cpp
};

#endif // LAND_H
