#include "land.h"

std::ostream& operator<< (std::ostream &out, const Land &land)
{
    switch ( land.getType() )
    {
    case LandType::circle:
        out << "Круглый";
        break;
    case LandType::triangle:
        out << "Треугольный";
        break;
    case LandType::square:
        out << "Квадратный";
        break;
    case LandType::rectangle:
        out << "Прямоугольный";
        break;
    default:
        out << "???";
        break;
    };
    out << " участок площадью " << land.getArea() << " кв.м";
    return out;
}

Land::~Land()
{
    if(cadastralID)
    {
        map.erase(cadastralID);
    }
}

unsigned int Land::getCadastralID() const
{
    return cadastralID;
}

bool Land::registrate()
{
    if(cadastralID)
    {
        return false;
    }
    else
    {
        cadastralID = nextUniqueID;
        nextUniqueID++;
        map[cadastralID] = this;
        return true;
    }
}

Land *Land::fromCadastaralID(unsigned int id)
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
