#include "land.h"

Land::Land(const std::string& addres, IShape* shape)
    : _shape{shape}, _addres{addres}, _area{getRoundArea()}
{}

Land::Land(Land&& other)
{
    _addres = std::move(other._addres);
    _shape = other._shape;
    _area = other._area;
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
    calculateArea();
    for (HolderAndPart pair : _holders)
    {
        pair.second->calculateArea(_area);
    }
}

void Land::calculateArea()
{
    _area = std::round(_shape->getArea() * 100) / 100;
}

const std::string& Land::getAddres() const
{
    return _addres;
}

const IShape *Land::getShape() const
{
    return _shape;
}

double Land::getArea() const
{
    return _area;
}

double Land::getRoundArea() const
{
    return std::round(_shape->getArea() * 100) / 100;
}

const Part* Land::getPart(unsigned int passport) const
{
    HolderConstIterator holder {_holders.find(passport)};
    if (holder == _holders.end()) { return nullptr; }
    return holder->second;
}

double Land::getHolderArea(unsigned int passport) const
{
    const Part* part {getPart(passport)};
    if (!part) { return 0; }
    return part->getArea();
}

const std::map<unsigned int, Part*>& Land::getHolders() const
{
    return _holders;
}

double Land::sumParts() const
{
    double sum {0};
    for (HolderAndPart pair : _holders)
    {
        sum += pair.second->getArea();
    };
    return sum;
}

Land::~Land()
{
    delete _shape;
    for (HolderAndPart pair : _holders)
    {
        delete pair.second;
    };
}

