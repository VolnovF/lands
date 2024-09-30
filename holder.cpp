#include "holder.h"

Holder* Holder::_chamber = nullptr;

Holder::Holder(std::string fio)
    : _fio{fio}
{}

Holder::Holder(Holder &&other)
{
    _fio = std::move(other._fio);
    _lands = std::move(other._lands);
}

Holder* Holder::getChamber()
{
    if(!_chamber)
    {
        _chamber = new Holder("Земельная палата");
    }
    return _chamber;
}

std::string Holder::getFio() const
{
    return _fio;
}

void Holder::setFio(std::string fio)
{
    _fio = fio;
}

void Holder::addLand(Land* land)
{
    _lands.push_back(land);
}

void Holder::deleteLand(Land *land)
{
    auto find {std::find(_lands.begin(), _lands.end(), land)};
    if (find == _lands.end()) {return;}
    _lands.erase(find);
}


