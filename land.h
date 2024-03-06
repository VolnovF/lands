#ifndef LAND_H
#define LAND_H

#include <iostream>
#include <map>

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
    static inline std::map<unsigned int,Land*> map{};

public:
    friend std::ostream& operator<< (std::ostream &out, const Land &land);
    virtual ~Land();

    virtual LandType getType() const = 0;
    virtual double getArea() const = 0;
    unsigned int getCadastralID() const;
    bool registrate();
    static Land* fromCadastaralID(unsigned int id);
};

#endif // LAND_H
