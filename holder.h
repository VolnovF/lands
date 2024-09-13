 #ifndef HOLDER_H
#define HOLDER_H

#include <string>
#include <vector>

class Land;

using LandIterator = std::vector<Land*>::iterator;

class Holder
{
private:
    friend class Land;

    std::string _fio;
    std::vector<Land*> _lands;

    void addLand(Land* land);

public:
    Holder(std::string fio);
    Holder(const Holder& other) = delete;
    Holder(Holder&& other);
    Holder& operator=(const Holder& other) = delete;
    Holder& operator=(Holder&& other) = delete;

    void setFio(std::string fio);

    std::string getFio() const;
    double getArea(); //определение в land.cpp

    ~Holder() = default;
};

#endif // HOLDER_H
