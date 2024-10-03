#ifndef HOLDER_H
#define HOLDER_H

#include <string>
#include <vector>
#include <algorithm>

class Land;

using LandIterator = std::vector<Land*>::iterator;

class Holder
{
private:
    friend class Land;

    std::string _fio;
    std::vector<Land*> _lands;

    static Holder* _chamber;

    void addLand(Land* land);
    void deleteLand(Land* land);

public:
    Holder(std::string fio);
    Holder(const Holder& other) = delete;
    Holder(Holder&& other);
    Holder& operator=(const Holder& other) = delete;
    Holder& operator=(Holder&& other) = delete;

    static Holder* getChamber();

    void setFio(const std::string& fio);

    std::string getFio() const;
    double getArea(); //определение в land.cpp

    ~Holder() = default;
};

#endif // HOLDER_H
