#include "land.h"

void Land::addHolder(Holder* holder, Fraction* fraction)
{
    _holders.insert(std::make_pair(holder, fraction));
}

Land::Land(const std::string& addres, IShape* shape)
    : _shape{shape}, _addres{addres}, _area{(std::floor(shape->getArea()) * 100) / 100}
{}

Land::Land(Land&& other)
{
    _shape = other._shape;
    other._shape = nullptr;
    _addres = std::move(other._addres);
    _area = other._area;
    other._area = 0;
    _holders = std::move(other._holders);
    _addQueue = std::move(other._addQueue);
}

void Land::add(Holder *holder, Fraction *fraction)
{
    _addQueue.push_front(std::make_pair(holder, fraction));
}

bool Land::commit()
{
    double sumArea{0};
    double sumRemains{0};
    for (HolderAndFraction pair : _addQueue)
    {
        pair.second->calculateArea(_area);
        sumArea += pair.second->getArea();
        sumRemains += pair.second->getRemains();
    }
    double difference{std::abs(_area - sumArea - sumRemains)};
    if (difference > 0.0000001)
    {
        clear();
        return false;
    }
    for (HolderAndFraction pair : _addQueue)
    {
        addHolder(pair.first, pair.second);
        pair.first->addLand(this);
    }
    free();
    return true;
}

void Land::free()
{
    _addQueue.erase(_addQueue.begin(), _addQueue.end());
}

void Land::clear()
{
    for (HolderAndFraction pair : _addQueue)
    {
        delete pair.second;
    }
    free();
}

void Land::setAddres(const std::string& addres)
{
    _addres = addres;
}

void Land::setShape(IShape* shape)
{
    delete _shape;
    _shape = shape;
    calculateArea();
    for (HolderAndFraction pair : _holders)
    {
        pair.second->calculateArea(_area);
    }
}

void Land::calculateArea()
{
    _area = (std::floor(_shape->getArea()) * 100) / 100;
}

const IShape *Land::getShape() const
{
    return _shape;
}

const std::string& Land::getAddres() const
{
    return _addres;
}

double Land::getArea() const
{
    return _area;
}

double Land::getRoundArea() const
{
    return (std::floor(_shape->getArea()) * 100) / 100;
}

const Fraction *Land::getFraction(Holder* holder) const
{
    HolderConstIterator holderIter {_holders.find(holder)};
    if (holderIter == _holders.end()) { return nullptr; }
    return holderIter->second;
}

double Land::getHolderArea(Holder* holder) const
{
    const Fraction* part {getFraction(holder)};
    if (!part) { return 0; }
    return part->getArea() + part->getRemains();
}

const std::map<Holder*, Fraction*>& Land::getHolders() const
{
    return _holders;
}

Land::~Land()
{
    delete _shape;
    for (HolderAndFraction pair : _holders)
    {
        delete pair.second;
    };
    clear();
}

double Holder::getArea()
{
    long double sum {0};
    for (Land* land : _lands)
    {
        sum += land->getHolderArea(this);
    };
    return sum;
}
