#ifndef LAND_H
#define LAND_H
#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <list>

#include "shape.h"
#include "fraction.h"
#include "holder.h"

using HolderIterator = std::map<Holder*,Fraction*>::iterator;
using HolderConstIterator = std::map<Holder*,Fraction*>::const_iterator;
using HolderAndFraction = std::pair<Holder*,Fraction*>;
using QueueIterator = std::list<HolderAndFraction>::iterator;
using QueueConstIterator = std::list<HolderAndFraction>::const_iterator;


class Land
{
private:
    IShape* _shape;
    std::string _addres;
    double _area;
    std::map<Holder*,Fraction*> _holders;
    std::list<HolderAndFraction> _addQueue;

    void addHolder(Holder* holder, Fraction* fraction);

public:
    Land(const std::string& addres, IShape* shape);
    Land(const Land& other) = delete;
    Land(Land&& other);
    Land& operator=(const Land& other) = delete;
    Land& operator=(Land&& other) = delete;

    void add(Holder* holder, Fraction* fraction);
    bool commit();
    void free();
    void clear();

    void setAddres(const std::string& addres);
    void setShape(IShape* shape);
    void calculateArea();

    const IShape* getShape() const;
    const std::string& getAddres() const;
    double getArea() const;
    double getRoundArea() const;
    const Fraction* getFraction(Holder* holder) const;
    double getHolderArea(Holder* holder) const;
    const std::map<Holder*,Fraction*>& getHolders() const;

    ~Land();

};
#endif // LAND_H
