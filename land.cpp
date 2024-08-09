#include "land.h"

Land::Land(const std::string& addres, Shape* shape)
    : m_addres{addres}, m_shape{shape}
{}

void Land::setShape(Shape* shape)
{
    delete m_shape;
    m_shape = shape;
}

double Land::getArea() const
{
    return m_shape->getArea();
}

long double Land::getHolderArea(unsigned int passport) const
{
    auto holder {m_holders.find(passport)};
    if (holder == m_holders.end())
    {
        return 0;
    }
    else
    {
        return m_shape->getArea() * holder->second.long_value();
    }
}

double Land::sumParts() const
{
    double sum {0};
    for (auto const& [passport, part] : m_holders)
    {
        sum += part.value();
    };
    return sum;
}

Land::~Land()
{
    delete m_shape;
}

