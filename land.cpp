#include "land.h"

Land::Land(const std::string& addres, IShape* shape)
    : _currentShape{shape},
    _newShape(shape),
    _addres{addres},
    _area{shape->getRoundArea()}
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

double Land::calculatePartArea(Fraction fraction)
{
    return _newShape->getRoundArea() * fraction.value();
}

void Land::addHolder(Holder* holder, double part)
{
    _holders.insert(std::make_pair(holder, part));
}

void Land::addHolder(HolderAndPart pair)
{
    _holders.insert(pair);
}

void Land::deleteAllHolders()
{
    for (HolderAndPart pair : _holders)
    {
        pair.first->deleteLand(this);
    }
    _holders.erase(_holders.begin(), _holders.end());
}

void Land::changeShape(IShape* shape)
{
    if (!shape) {return;}
    _newShape = shape;
    clearQueue();
}

void Land::add(Holder *holder, Fraction fraction)
{
    _addQueue.push_front(std::make_pair(holder, calculatePartArea(fraction)));
}

void Land::add(Holder *holder, double area)
{
    _addQueue.push_front(std::make_pair(holder, area));;
}

bool Land::commit()
{
    double sumArea{0};
    bool shapeChanged {_currentShape != _newShape};
    for (HolderAndPart pair : _addQueue)
    {
        sumArea += pair.second;
    }
    double difference{std::abs(_newShape->getRoundArea() - sumArea)};
    if (difference > 0.0000001)
    {
        clearQueue();
        return false;
    }
    if (shapeChanged)
    {
        _currentShape = _newShape;
        calculateArea();
        deleteAllHolders();
    }
    for (HolderAndPart pair : _addQueue)
    {
        addHolder(pair);
        pair.first->addLand(this);
    }
    clearQueue();
    return true;
}

void Land::clearQueue()
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

const double *Land::getPart(Holder* holder) const
{
    HolderConstIterator holderIter {_holders.find(holder)};
    if (holderIter == _holders.end()) { return nullptr; }
    return &(holderIter->second);
}

double Land::getHolderArea(Holder* holder) const
{
    const double* part {getPart(holder)};
    if (!part) { return 0; }
    return *part;
}

const std::map<Holder*, double>& Land::getHolders() const
{
    return _holders;
}

Land::~Land()
{
    if (_currentShape != _newShape) {delete _newShape;}
    delete _currentShape;
    clearQueue();
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
