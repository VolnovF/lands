#ifndef LAND_H
#define LAND_H

#include <iostream>

enum class LandType
{
    circle,
    triangle,
    square,
    rectangle,
    maxTypes
};

class Land
{
private:
    unsigned int cadastralID{0};
    static inline unsigned nextUniqueID{1};
public:
    virtual LandType getType() const = 0;
    virtual double getArea() const = 0;
    friend std::ostream& operator<< (std::ostream &out, const Land &land);
    virtual ~Land() = default;

    unsigned int getCadastralID();
    bool registrate();
};

#endif // LAND_H
