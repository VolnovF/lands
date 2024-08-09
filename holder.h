 #ifndef HOLDER_H
#define HOLDER_H

#include <string>
#include <vector>

#include "land.h"

class Holder
{
private:
    std::string m_fio;
    unsigned int m_passport;
    static inline unsigned int counter{1};
    std::vector<std::reference_wrapper<const Land>> m_lands;

    unsigned int nextUniqueID();

public:
    Holder(std::string fio);

    bool addLand(Land& land, Fraction part);
    void setFio(std::string fio);
    std::string getFio() const;
    long double getArea();

    ~Holder() = default;
};

#endif // HOLDER_H
