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

using HolderIterator = std::map<Holder*,double>::iterator;
using HolderConstIterator = std::map<Holder*,double>::const_iterator;
using HolderAndPart = std::pair<Holder*,double>;
using QueueIterator = std::list<HolderAndPart>::iterator;
using QueueConstIterator = std::list<HolderAndPart>::const_iterator;

constexpr int countDecimalPlaces {2};

double floor(double decimal, int countDecimalPlaces = 0);

class Land
{
private:
    IShape* _currentShape;
    IShape* _newShape {nullptr};
    std::string _addres;
    double _area;
    std::map<Holder*,double> _holders;
    std::list<HolderAndPart> _addQueue;

    double calculatePartArea(Fraction fraction);
    void addHolder(Holder* holder, double part);
    void addHolder(HolderAndPart pair);
    void deleteAllHolders();

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
    void clearQueue();

    void setAddres(const std::string& addres);
    void calculateArea();

    const IShape* getShape() const;
    const std::string& getAddres() const;
    double getArea() const;
    //double getRoundArea() const;
    const double* getPart(Holder* holder) const;
    double getHolderArea(Holder* holder) const;
    const std::map<Holder*,double>& getHolders() const;

    ~Land();

};
#endif // LAND_H
