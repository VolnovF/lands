#ifndef LANDCHAMBER_H
#define LANDCHAMBER_H

#include <vector>

#include <land.h>
#include <holder.h>

struct Ownership
{
    unsigned int land;
    unsigned int holder;
};
bool operator==(const Ownership& a, const Ownership& b);

class LandChamber
{
private:
    std::vector<Ownership> ownerships;
public:
    LandChamber();

    bool registrateOwnership(Land* land, Holder* holder);
    bool registrateOwnership(unsigned int land, unsigned int holder);
    const std::vector<Ownership>& allOwnerships();
    bool contains(const Ownership& ownreship);
    bool contains(Land* land, Holder* holder);
    bool contains(unsigned int land, unsigned int holder);
};

#endif // LANDCHAMBER_H
