#ifndef HOLDER_H
#define HOLDER_H

#include <string>

class Holder
{
private:
    std::string fio;
    unsigned int passport;
    static inline unsigned int nextUniqueID{1};
public:
    Holder(std::string c_fio);

    std::string getFio() const;
    void setFio(std::string fio);
    unsigned int getPassport() const;
};

#endif // HOLDER_H
