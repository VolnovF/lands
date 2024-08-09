#include "holder.h"

unsigned int Holder::nextUniqueID()
{
    return counter++;
}

Holder::Holder(std::string fio)
    : m_fio{fio}
{
    m_passport = nextUniqueID();
}

bool Holder::addLand(Land &land, Fraction part)
{
    if (land.addHolder(m_passport, part))
    {
        m_lands.push_back(land);
    }
    else
    {
        return false;
    }
}

std::string Holder::getFio() const
{
    return m_fio;
}

long double Holder::getArea()
{
    long double sum {0};
    for (auto land : m_lands)
    {
        sum += land.get().getHolderArea(m_passport);
    };
    return sum;
}

void Holder::setFio(std::string fio)
{
    m_fio = fio;
}


bool Land::addHolder(unsigned int passport, Fraction part)
{
    if(sumParts() + part.value() > 1)
    {
        return false;
    }
    m_holders.insert(std::make_pair(passport, part));
    return true;
}
