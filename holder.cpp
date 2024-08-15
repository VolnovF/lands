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

bool Holder::addLand(Land* land, Fraction part)
{
    if (land->addHolder(_passport, part))
    {
        _lands.push_back(land);
    }
    else
    {
        return false;
    }
}

std::string Holder::getFio() const
{
    return _fio;
}

long double Holder::getArea()
{
    long double sum {0};
    for (auto land : _lands)
    {
        sum += land->getHolderArea(_passport);
    };
    return sum;
}

void Holder::setFio(std::string fio)
{
    _fio = fio;
}


bool Land::addHolder(unsigned int passport, Fraction part)
{
    if(sumParts() + part.value() > 1)
    {
        return false;
    }
    _holders.insert(std::make_pair(passport, part));
    return true;
}
