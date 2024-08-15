 #ifndef HOLDER_H
#define HOLDER_H

#include <string>
#include <vector>

#include "land.h"

class Holder
{
private:
    std::string _fio;
    unsigned int _passport;
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

    bool addLand(Land* land, Fraction part);

    ~Holder() = default;
};

#endif // HOLDER_H
