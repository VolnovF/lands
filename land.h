#ifndef LAND_H
#define LAND_H
#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <list>

#include "round.h"
#include "shape.h"
#include "fraction.h"
#include "holder.h"

using HolderIterator = std::map<Holder*,double>::iterator;
using HolderConstIterator = std::map<Holder*,double>::const_iterator;
using HolderAndPart = std::pair<Holder*,double>;
using ListIterator = std::list<HolderAndPart>::iterator;
using ListConstIterator = std::list<HolderAndPart>::const_iterator;

class Land
{
private:
    IShape* _currentShape;
    IShape* _newShape {nullptr};
    std::string _addres;
    double _area;
    std::map<Holder*,double> _holders;
    std::list<HolderAndPart> _addList;

    void replaceShape();
    double calculatePartArea(Fraction fraction);
    double listSumArea();
    void distributeRemains(double remains);
    bool askHolder(const Holder* holder, double areaBefore, double areaAfter);
    void moveListToHolders();

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
    void clearList();

    void setAddres(const std::string& addres);

    const IShape* getShape() const;
    const std::string& getAddres() const;
    double getArea() const;
    double getHolderArea(Holder* holder) const;
    const std::map<Holder*,double>& getHolders() const;

    ~Land();

};
#endif // LAND_H
