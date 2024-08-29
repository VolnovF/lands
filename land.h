#ifndef LAND_H
#define LAND_H

#include <iostream>
#include <cmath>
#include <utility>
#include <string>
#include <map>

#include "shape.h"
#include "part.h"

using HolderIterator = std::map<unsigned int,Part*>::iterator;
using HolderConstIterator = std::map<unsigned int,Part*>::const_iterator;
using HolderAndPart = std::pair<unsigned int,Part*>;

class Holder;

class Land
{
private:
    unsigned int _id;
    IShape* _shape;
    std::string _addres;
    double _area;
    std::map<unsigned int,Part*> _holders;
    static inline unsigned int counter{1};

    unsigned int nextUniqueID();

public:
    Land(const std::string& addres, IShape* shape);
    Land(const Land& other) = delete;
    Land(Land&& other);
    Land& operator=(const Land& other) = delete;
    Land& operator=(Land&& other) = delete;

    void setAddres(const std::string& addres);
    void setShape(IShape* shape);
    void calculateArea();

    unsigned int getId() const;
    const std::string& getAddres() const;
    const IShape* getShape() const;
    double getArea() const;
    double getRoundArea() const;
    const Part* getPart(unsigned int passport) const;
    double getHolderArea(unsigned int passport) const;
    const std::map<unsigned int,Part*>& getHolders() const;

    double sumParts() const;

    ~Land();

    bool addHolder(unsigned int passport, Part* part); //определение в holder.cpp
    void deleteHolder(unsigned int passport); //определение в holder.cpp
};

#endif // LAND_H
