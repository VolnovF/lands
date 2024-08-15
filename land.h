#ifndef LAND_H
#define LAND_H

#include <iostream>
#include <utility>
#include <string>
#include <map>

#include "shape.h"
#include "fraction.h"

class Holder;

class Land
{
private:
    IShape* _shape;
    std::string _addres;
    std::map<unsigned int,Fraction> _holders;

public:
    Land(const std::string& addres, IShape* shape);
    Land(const Land& other) = delete;
    Land(Land&& other);
    Land& operator=(const Land& other) = delete;
    Land& operator=(Land&& other) = delete;

    void setAddres(const std::string& addres);
    void setShape(IShape* shape);

    const std::string& getAddres() const;
    const IShape* getShape();
    double getArea() const;
    const Fraction* getFraction(unsigned int passport) const;
    long double getHolderArea(unsigned int passport) const;
    const std::map<unsigned int,Fraction>& getHolders() const;

    double sumParts() const;

    ~Land();

    bool addHolder(unsigned int passport, Fraction part); //определение в holder.cpp
};

#endif // LAND_H
