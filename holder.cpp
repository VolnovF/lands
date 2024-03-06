#include "holder.h"

Holder::Holder(std::string c_fio)
    : fio{c_fio}, passport{nextUniqueID}
{
    nextUniqueID++;
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


