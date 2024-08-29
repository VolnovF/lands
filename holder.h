 #ifndef HOLDER_H
#define HOLDER_H

#include <string>
#include <vector>

#include "land.h"

using LandIterator = std::vector<Land*>::iterator;

class Holder
{
private:
    unsigned int _passport;
    std::string _fio;
    std::vector<Land*> _lands;
    static inline unsigned int counter{1};

    unsigned int nextUniqueID();

public:
    Holder(std::string fio);
    Holder(const Holder& other) = delete;
    Holder(Holder&& other);
    Holder& operator=(const Holder& other) = delete;
    Holder& operator=(Holder&& other) = delete;

    void setFio(std::string fio);

    std::string getFio() const;
    long double getArea();
    unsigned int getPassport() const;

    bool addLand(Land* land, Part* part);
    void deleteLand(unsigned int id);

    ~Holder() = default;
};

#endif // HOLDER_H
