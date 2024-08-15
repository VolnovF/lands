#include "land.h"

Land::Land(const std::string& addres, IShape* shape)
    : _shape{shape}, _addres{addres}
{}

Land::Land(Land&& other)
{
    _addres = std::move(other._addres);
    _shape = other._shape;
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

const Fraction* Land::getFraction(unsigned int passport) const
{
    auto holder {_holders.find(passport)};
    if (holder == _holders.end())
    {
        return nullptr;
    }
    return &(holder->second);
}

long double Land::getHolderArea(unsigned int passport) const
{
    const Fraction* fraction {getFraction(passport)};
    if (!fraction) { return 0; }
    return _shape->getArea() * fraction->long_value();
}

const std::map<unsigned int, Fraction>& Land::getHolders() const
{
    return _holders;
}

double Land::sumParts() const
{
    double sum {0};
    for (auto const& [passport, part] : _holders)
    {
        sum += part.value();
    };
    return sum;
}

Land::~Land()
{
    delete _shape;
}

