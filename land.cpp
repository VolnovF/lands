#include "land.h"

void Land::addHolder(Holder* holder, Part part)
{
    _holders.insert(std::make_pair(holder, part));
}

void Land::addHolder(HolderAndPart pair)
{
    _holders.insert(pair);
}

Land::Land(const std::string& addres, IShape* shape)
    : _currentShape{shape}, _newShape(shape), _addres{addres}, _area{shape->getRoundArea()}
{}

Land::Land(Land&& other)
{
    _currentShape = other._currentShape;
    other._currentShape = nullptr;
    _addres = std::move(other._addres);
    _area = other._area;
    other._area = 0;
    _holders = std::move(other._holders);
    _addQueue = std::move(other._addQueue);
}

void Land::changeShape(IShape* shape)
{
    if (!shape) {return;}
    _newShape = shape;
    clear();
}

void Land::add(Holder *holder, Fraction fraction)
{
    _addQueue.push_front(std::make_pair(holder, Part(fraction, _newShape->getRoundArea())));
}

void Land::add(Holder *holder, double area)
{
    _addQueue.push_front(std::make_pair(holder, Part(area)));;
}

bool Land::commit()
{
    double sumArea{0};
    double sumRemains{0};
    for (HolderAndPart pair : _addQueue)
    {
        sumArea += pair.second.getArea();
        sumRemains += pair.second.getRemains();
    }
    double difference{std::abs(_newShape->getRoundArea() - sumArea - sumRemains)};
    if (difference > 0.0000001)
    {
        clear();
        return false;
    }
    _currentShape = _newShape;
    calculateArea();
    for (HolderAndPart pair : _addQueue)
    {
        addHolder(pair);
        pair.first->addLand(this);
    }
    clear();
    return true;
}

void Land::clear()
{
    _addQueue.erase(_addQueue.begin(), _addQueue.end());
}

void Land::setAddres(const std::string& addres)
{
    _addres = addres;
}


void Land::calculateArea()
{
    _area = _currentShape->getRoundArea();
}

const IShape *Land::getShape() const
{
    return _currentShape;
}

const std::string& Land::getAddres() const
{
    return _addres;
}

double Land::getArea() const
{
    return _area;
}

const Part *Land::getPart(Holder* holder) const
{
    HolderConstIterator holderIter {_holders.find(holder)};
    if (holderIter == _holders.end()) { return nullptr; }
    return &(holderIter->second);
}

double Land::getHolderArea(Holder* holder) const
{
    const Part* part {getPart(holder)};
    if (!part) { return 0; }
    return part->getArea() + part->getRemains();
}

const std::map<Holder*, Part>& Land::getHolders() const
{
    return _holders;
}

Land::~Land()
{
    if (_currentShape != _newShape) {delete _newShape;}
    delete _currentShape;
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
