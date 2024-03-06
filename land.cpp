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

unsigned int Land::getCadastralID()
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
        return true;
    }
}
