#include "holder.h"

unsigned int Holder::nextUniqueID()
{
    return counter++;
}

Holder::Holder(std::string fio)
    : _fio{fio}
{
    _passport = nextUniqueID();
}

Holder::Holder(Holder &&other)
{
    _fio = std::move(other._fio);
    _passport = other._passport;
    _lands = std::move(other._lands);
}

std::string Holder::getFio() const
{
    return _fio;
}

long double Holder::getArea()
{
    long double sum {0};
    for (Land* land : _lands)
    {
        sum += land->getHolderArea(_passport);
    };
    return sum;
}

void Holder::setFio(std::string fio)
{
    _fio = fio;
}

bool Holder::addLand(Land* land, Part* part)
{
    bool result{ land->addHolder(_passport, part) };
    if (result)
    {
        _lands.push_back(land);
    }
    return result;
}

bool Land::addHolder(unsigned int passport, Part* part)
{
    if(!part) { return false;}
    if(sumParts() > _area) { return false; }
    part->calculateArea(_area);
    _holders.insert(std::make_pair(passport, part));
    return true;
}
