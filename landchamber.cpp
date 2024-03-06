#include "landchamber.h"

bool operator==(const Ownership& a, const Ownership& b)
{
    if(a.land == b.land && a.holder == b.holder)
        return true;
    else
        return false;
}

LandChamber::LandChamber()
{}

bool LandChamber::registrateOwnership(Land *land, Holder *holder)
{
    bool isFirstHolder{ land->registrate() };
    Ownership temp{land->getCadastralID(), holder->getPassport()};
    if(isFirstHolder)
    {
        ownerships.push_back(temp);
        return true;
    }
    else if(contains(temp))
    {
        return false;
    }
    else
    {
        ownerships.push_back(temp);
        return true;
    }
}

bool LandChamber::registrateOwnership(unsigned int land, unsigned int holder)
{
    Ownership temp{land, holder};
    if(contains(temp))
    {
        return false;
    }
    else
    {
        ownerships.push_back(temp);
        return true;
    }
}

const std::vector<Ownership> &LandChamber::allOwnerships()
{
    return ownerships;
}

bool LandChamber::contains(const Ownership &ownreship)
{
    for (auto i : ownerships) {
        if(i == ownreship)
        {
            return true;
        }
    }
    return false;
}

bool LandChamber::contains(Land *land, Holder *holder)
{
    if(!land->getCadastralID())
    {
        return false;
    }
    Ownership temp{land->getCadastralID(), holder->getPassport()};
    for (auto i : ownerships) {
        if(i == temp)
        {
            return true;
        }
    }
    return false;
}

bool LandChamber::contains(unsigned int land, unsigned int holder)
{
    Ownership temp{land, holder};
    for (auto i : ownerships) {
        if(i == temp)
        {
            return true;
        }
    }
    return false;
}
