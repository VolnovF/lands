#include "holder.h"

Holder::Holder(std::string fio)
    : _fio{fio}
{}

Holder::Holder(Holder &&other)
{
    _fio = std::move(other._fio);
    _lands = std::move(other._lands);
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


