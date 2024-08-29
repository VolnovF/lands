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
    other._passport = 0;
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

unsigned int Holder::getPassport() const
{
    return _passport;
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

void Holder::deleteLand(unsigned int id)
{
    for (LandIterator land {_lands.begin()}; land < _lands.end(); land++)
    {
        if ((*land)->getId() == id)
        {
            (*land)->deleteHolder(_passport);
            _lands.erase(land);
        }
    };
}

bool Land::addHolder(unsigned int passport, Part* part)
{
    auto d = _holders.begin();
    if(!part) { return false;}
    if(sumParts() > _area) { return false; }
    part->calculateArea(_area);
    _holders.insert(std::make_pair(passport, part));
    return true;
}

void Land::deleteHolder(unsigned int passport)
{
    HolderIterator holder {_holders.find(passport)};
    if (holder == _holders.end()) { return; }
    delete holder->second;
    _holders.erase(holder);
}


