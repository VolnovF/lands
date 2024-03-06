#ifndef HOLDER_H
#define HOLDER_H

#include <string>
#include <map>

class Holder
{
private:
    std::string fio;
    unsigned int passport;
    static inline unsigned int nextUniqueID{1};
    static inline std::map<unsigned int,Holder*> map{};
public:
    Holder(std::string c_fio);
    ~Holder();

    std::string getFio() const;
    void setFio(std::string fio);
    unsigned int getPassport() const;
    static Holder* fromPassport(unsigned int id);
};

#endif // HOLDER_H
