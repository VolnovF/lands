#include "land.h"

Land::Land(const std::string& addres, IShape* shape)
    : _currentShape{shape},
    _newShape(shape),
    _addres{addres},
    _area{shape->getRoundArea()}
{
    addHolder(Holder::getChamber(), _area);
}

Land::Land(Land&& other)
{
    _currentShape = other._currentShape;
    other._currentShape = nullptr;
    _newShape = other._newShape;
    other._newShape = nullptr;
    _addres = std::move(other._addres);
    _area = other._area;
    other._area = 0;
    _holders = std::move(other._holders);
    _addList = std::move(other._addList);
}

void Land::replaceShape()
{
    delete _currentShape;
    _currentShape = _newShape;
    _area = _currentShape->getRoundArea();
}

double Land::calculatePartArea(Fraction fraction)
{
    return Floor(_newShape->getRoundArea() * fraction.value());
}

double Land::listSumArea()
{
    double sum{0};
    for (HolderAndPart pair : _addList)
    {
        sum += pair.second;
    }
    return sum;
}

void Land::addHolder(Holder* holder, double part)
{
    _holders.insert(std::make_pair(holder, Floor(part)));
    holder->addLand(this);
}

void Land::addHolder(HolderAndPart pair)
{
    _holders.insert(pair);
    pair.first->addLand(this);
}

void Land::distributeRemains(double remains)
{
    if (remains <= 0)
        return;
    double partOfRemains { Round(remains/_holders.size()) };
    if (partOfRemains == 0)
        partOfRemains = 0.01;
    for (HolderIterator iter = _holders.begin(); iter != _holders.end(); iter++)
    {
        if(askHolder(iter->first, iter->second, iter->second+partOfRemains))
        {
            iter->second += partOfRemains;
            remains -= partOfRemains;
        }
        if(remains <= 0)
            return;
        else if (partOfRemains > remains)
            partOfRemains = remains;
    }
    addHolder(Holder::getChamber(), remains);
}

bool Land::askHolder(const Holder* holder, double areaBefore, double areaAfter)
{
    std::cout << holder->getFio() << ", вашу долю в участке " << this->getAddres() <<
        " можно увеличить с " << areaBefore << " га. до " << areaAfter << " га.\n";
    char response;
    while (true) {
        std::cout << "Вы согласны? (y/n): ";
        std::cin >> response;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //response = 'y'; //!
        if (response == 'y')
            return true;
        else if (response == 'n')
            return false;
    }
}

void Land::moveListToHolders()
{
    for (HolderAndPart pair : _addList)
    {
        addHolder(pair);
    }
    clearList();
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
    if (!shape)
        return;
    _newShape = shape;
    if (_currentShape == _newShape)
        return;
    clearList();
}

void Land::add(Holder *holder, Fraction fraction)
{
    _addList.push_front(std::make_pair(holder, calculatePartArea(fraction)));
}

void Land::add(Holder *holder, double area)
{
    _addList.push_front(std::make_pair(holder, area));;
}

bool Land::commit()
{
    double sumArea {listSumArea()};
    double remains {Round(_newShape->getRoundArea() - sumArea)};
    if (remains < 0)
    {
        clearList();
        return false;
    }
    if (_currentShape != _newShape)
        replaceShape();
    deleteAllHolders();
    moveListToHolders();
    if (remains > 0)
        distributeRemains(remains);
    return true;
}

void Land::clearList()
{
    _addList.erase(_addList.begin(), _addList.end());
}

void Land::setAddres(const std::string& addres)
{
    _addres = addres;
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
    if (holderIter == _holders.end())
        return nullptr;
    return &(holderIter->second);
}

double Land::getHolderArea(Holder* holder) const
{
    const double* part {getPart(holder)};
    if (!part)
        return 0;
    return *part;
}

const std::map<Holder*, double>& Land::getHolders() const
{
    return _holders;
}

Land::~Land()
{
    if (_currentShape != _newShape)
        delete _newShape;
    delete _currentShape;
    clearList();
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
