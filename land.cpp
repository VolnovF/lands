#include "land.h"

Land::Land(const std::string& addres, IShape* shape)
    : _shape{shape}, _addres{addres}
{}

Land::Land(Land&& other)
{
    _addres = std::move(other._addres);
    _shape = other._shape;
    other._shape = nullptr;
    _holders = std::move(other._holders);
}

void Land::setAddres(const std::string& addres)
{
    _addres = addres;
}

void Land::setShape(IShape* shape)
{
    delete _shape;
    _shape = shape;
    for (HolderAndPart pair : _holders)
    {
        pair.second.calculateArea(_shape->getArea());
    }
}

const std::string& Land::getAddres() const
{
    return _addres;
}

const IShape *Land::getShape()
{
    return _shape;
}

double Land::getArea() const
{
    return _shape->getArea();
}

const Fraction* Land::getPart(unsigned int passport) const
{
    HolderConstIterator holder {_holders.find(passport)};
    if (holder == _holders.end()) { return nullptr; }
    return &(holder->second);
}

double Land::getHolderArea(unsigned int passport) const
{
    const Fraction* fraction {getPart(passport)};
    if (!fraction) { return 0; }
    return fraction->getArea();
}

const std::map<unsigned int, Fraction>& Land::getHolders() const
{
    return _holders;
}

double Land::sumParts() const
{
    double sum {0};
    for (HolderAndPart pair : _holders)
    {
        sum += pair.second.value();
    };
    return sum;
}

Land::~Land()
{
    delete _shape;
}

