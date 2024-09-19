#ifndef LAND_H
#define LAND_H
#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <list>

#include "shape.h"
#include "part.h"
#include "holder.h"

using HolderIterator = std::map<Holder*,Part>::iterator;
using HolderConstIterator = std::map<Holder*,Part>::const_iterator;
using HolderAndPart = std::pair<Holder*,Part>;
using QueueIterator = std::list<HolderAndPart>::iterator;
using QueueConstIterator = std::list<HolderAndPart>::const_iterator;


class Land
{
private:
    IShape* _currentShape;
    IShape* _newShape {nullptr};
    std::string _addres;
    double _area;
    std::map<Holder*,Part> _holders;
    std::list<HolderAndPart> _addQueue;

    void addHolder(Holder* holder, Part part);
    void addHolder(HolderAndPart pair);

public:
    Land(const std::string& addres, IShape* shape);
    Land(const Land& other) = delete;
    Land(Land&& other);
    Land& operator=(const Land& other) = delete;
    Land& operator=(Land&& other) = delete;

    void changeShape(IShape* shape);
    void add(Holder* holder, Fraction fraction);
    void add(Holder* holder, double area);
    bool commit();
    void clear();

    void setAddres(const std::string& addres);
    void calculateArea();

    const IShape* getShape() const;
    const std::string& getAddres() const;
    double getArea() const;
    //double getRoundArea() const;
    const Part* getPart(Holder* holder) const;
    double getHolderArea(Holder* holder) const;
    const std::map<Holder*,Part>& getHolders() const;

    ~Land();

};
#endif // LAND_H
