#include "holder.h"

Holder::Holder(std::string c_fio)
    : fio{c_fio}, passport{nextUniqueID}
{
    nextUniqueID++;
    map[passport] = this;
}

Holder::~Holder()
{
    map.erase(passport);
}

std::string Holder::getFio() const
{
    return fio;
}

void Holder::setFio(std::string fio)
{
    this->fio = fio;
}

unsigned int Holder::getPassport() const
{
    return passport;
}

Holder *Holder::fromPassport(unsigned int id)
{
    if (map.count(id))
    {
        return map[id];
    }
    else
    {
        return nullptr;
    }
}


