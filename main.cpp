#include <iostream>
#include <string> 
#include <utility>
#include <random>
#include <ctime>

class Land;
class Holder;
class CadastralChamber;

enum class LandType
{
    circle,
    triangle,
    square,
    rectangle,
    maxTypes
};

int getRandomInt(int min, int max)
{
    static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
    return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
}

class Land
{
private:
    LandType type{LandType::maxTypes};
    double area{};
public:
    Land(): type{ LandType::maxTypes }, area{ 0 }
    {
    }
    Land(LandType buf_type, double buf_area)
    {
        setType(buf_type);
        setArea(buf_area);
    }
    Land(bool rand): type{ LandType::maxTypes }, area{ 0 }
    {
        if (rand)
        {
            randomize();
        }
    }

    void randomize()
    {
		setType( static_cast<LandType>(getRandomInt(0, static_cast<int>(LandType::maxTypes) - 1)) );
		setArea( getRandomInt(1, 9999) / 100.0 );
    }
    void setType(LandType type) { this->type = type; }
    void setType(int type)
    {
        if (type < static_cast<int>(LandType::maxTypes))
        {
                    this->type = static_cast<LandType>(type);
                    return;
        }
    }
    void setArea(double area)
    {
        if (area >= 0)
        {
            this->area = area;
        }
    }
    LandType getType() const { return type; }
    double getArea() const { return area; }
    void input()
    {
        std::cout << "Введите тип участка\n"
            << "\tкруг - 0\n"
            << "\tтреугольник - 1\n"
            << "\tквадрат - 2\n"
            << "\tпрямоугольник - 3\n"
            << ": ";
        int type{};

        std::cin >> type;
        setType(type);
        std::cout << "Введите площадь участка: ";

        double area{};
        std::cin >> area;
        setArea(area);
        
        std::cout << '\n';
    }
    void print() const
    {
        switch ( static_cast<int>(type) )
        {
        case 0:
            std::cout << "Круглый ";
            break;
        case 1:
            std::cout << "Треугольный ";
            break;
        case 2:
            std::cout << "Квадратный ";
            break;
        case 3:
            std::cout << "Прямоугольный ";
            break;
        default:
            std::cout << "??? ";
            break;
        };
        std::cout << "участок площадью " << area << " кв.км\n";
    }
};

class Holder
{
    friend class CadastralChamber;
private:
    std::string fio;
    size_t size;
    Land** lands;
public:
    Holder()
        : fio { "" }, size{ 0 }, lands { nullptr }
    {
    }
    Holder(std::string buf_fio, size_t buf_size, bool rand = false)
        : fio {buf_fio}, size{ buf_size }, lands { new Land*[buf_size] }
    {
        for (size_t i = 0; i < size; i++)
        {
            lands[i] = new Land(rand);
        }
    }
    Holder(std::string buf_fio, size_t buf_size, Land** buf_lands)
        : fio {buf_fio}, size{ buf_size }, lands { new Land*[buf_size] }
    {
        for (size_t i = 0; i < size; i++)
        {
            lands[i] = new Land(*buf_lands[i]);
            delete buf_lands[i];
        }
        delete[] buf_lands;
    }
    
    Holder(Holder&& r) noexcept
        : fio{ r.fio }, size{ r.size }, lands{ r.lands }
    {
        r.lands = nullptr;
        r.size = 0;
    }
    Holder& operator=(Holder&& r) noexcept
    {
        if (&r == this)
        {
            return *this;
        }
        if(lands)
        {
            this->~Holder();
        }
        fio = r.fio;
        size = r.size;
        lands = r.lands;
        r.lands = nullptr;
        r.size = 0;
        return *this;
    }
    Holder(const Holder& l) noexcept
        : fio{ l.fio }, size{ l.size }, lands { new Land*[l.size] }
    {
        for (size_t i = 0; i < size; i++)
        {
            lands[i] = new Land();
            *lands[i] = *l.lands[i];
        }
    }
    Holder& operator=(Holder& l) noexcept
    {
        if (&l == this)
        {
            return *this;
        }
        if(lands)
        {
            this->~Holder();
        }
        size = l.size;
        fio = l.fio;
        lands = new Land*[size];
        for (size_t i = 0; i < size; i++)
        {
            lands[i] = new Land();
            *lands[i] = *l.lands[i];
        }
        return *this;
    }
    
    ~Holder()
    {
        if(!lands)
        {
            return;
        }
        for (size_t i = 0; i < size; i++)
        {
            delete lands[i];
        }
        delete[] lands;
        size = 0;
    }

    void setLand(size_t i, LandType type, double area)
    {
        lands[i]->setType(type);
        lands[i]->setArea(area);
    }
    std::string getFIO() const { return fio; }
    void setFIO(std::string fio) { this->fio = fio; }
    size_t getSize() { return size; }
    double getLandArea(size_t i) const 
    { 
        return lands[i]->getArea();
    }
    LandType getLandType(size_t i) const 
    { 
        return lands[i]->getType();
    }
    void randomizeAllLands()
    {
        for (size_t i = 0; i < size; i++)
        {
			lands[i]->randomize();
		};
    }
    void printAllLands() const
    {
        if(!lands)
        {
            std::cout << "Собственник " << fio << " не найден\n";
            return;
        }
        std::cout << "Собственник " << fio <<'\n';
        for (size_t i = 0; i < size; i++)
        {
            std::cout << '#' << i << ' ';
            lands[i]->print();
        }
    }
    void inputAllLands()
    {
        for (size_t i {0}; i < size; i++)
        {
            lands[i]->input();
        }
    }
    double getArea() const
    {
        double sumArea{0};
        for (size_t i = 0; i < size; i++)
        {
            sumArea += lands[i]->getArea();
        }
        return sumArea;
    }
};

class CadastralChamber
{
private:
    std::string name;
    size_t size;
    Holder** holders;
public:
    CadastralChamber(std::string buf_name, size_t buf_size, Holder** buf_holders)
        : name {buf_name}, size{ buf_size }, holders { new Holder*[buf_size] }
    {
        for (size_t i = 0; i < size; i++)
        {
            
            holders[i] = new Holder();
            *holders[i] = std::move(*buf_holders[i]);
        }
        delete[] buf_holders;
    }
    
    CadastralChamber(CadastralChamber&& r) noexcept
        : name{ r.name }, size{ r.size }, holders{ r.holders }
    {
        r.holders = nullptr;
        r.size = 0;
    }
    CadastralChamber& operator=(CadastralChamber&& r) noexcept
    {
        if (&r == this)
        {
            return *this;
        }
        if(holders)
        {
            this->~CadastralChamber();
        }
        name = r.name;
        size = r.size;
        holders = r.holders;
        r.holders = nullptr;
        r.size = 0;
        return *this;
    }
    CadastralChamber(const CadastralChamber& l) noexcept
        : name{ l.name }, size{ l.size }, holders { new Holder*[l.size] }
    {
        for (size_t i = 0; i < size; i++)
        {
            holders[i] = new Holder();
            *holders[i] = *l.holders [i];
        }
    }
    CadastralChamber& operator=(CadastralChamber& l) noexcept
    {
        if (&l == this)
        {
            return *this;
        }
        if(holders)
        {
            this->~CadastralChamber();
        }
        size = l.size;       
        name = l.name;
        holders = new Holder*[size];
        for (size_t i = 0; i < size; i++)
        {
            holders[i] = new Holder();
            *holders[i] = *l.holders[i];
        }
        return *this;
    }

    ~CadastralChamber()
    {
        if(!holders)
        {
            return;
        }
        for (size_t i = 0; i < size; i++)
        {
            delete holders[i];
        }
        delete[] holders;
        size = 0;
    }

    double getArea() const 
    {
        double sum{0};
        for (size_t i = 0; i < size; i++)
        {
            sum += holders[i]->getArea();
        }
        return sum;
    }
    std::string getName() const { return name; }
    void setName(std::string name) { this->name = name; }
    double getHolderArea(size_t i) const { return holders[i]->getArea(); }
    std::string getHolderFIO(size_t i) const { return holders[i]->getFIO(); } 
    double getLandArea(size_t i, size_t j) const { return holders[i]->getLandArea(j); }
    LandType getLandType(size_t i, size_t j) const { return holders[i]->getLandType(j); }
    void printAllHolders()
    {
        if(!holders)
        {
            std::cout << "         Кадастровая палата \"" << name << "\" не найдена\n";
            return;
        }
        std::cout << "         Кадастровая палата \"" << name << "\"\n";
        for (size_t i = 0; i < size; i++)
        {
            std::cout << "id:" << i << "  ";
            holders[i]->printAllLands();
        };
    }
    void setLand(size_t i, size_t j, LandType type, double area)
    {
        holders[i]->setLand(j, type, area);
    }
};


int main()
{      
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << std::endl;

    Holder A("A", 3, new Land*[3]{
        new Land(LandType::circle, 5.0),
        new Land(LandType::rectangle, 10.0),
        new Land(LandType::square, 15.0)
    });
    Holder B("B", 3, true);
    Holder C{ A };
    C.setFIO("C");
    Holder D{ std::move(A) };
    D.setFIO("D");
    
    A.printAllLands();
    std::cout << "Площадь земель собственника \"" << A.getFIO() << "\" = " 
        << A.getArea() << " кв.км\n" ;
    B.printAllLands();
    std::cout << "Площадь земель собственника \"" << B.getFIO() << "\" = " 
        << B.getArea() << " кв.км\n" ;
    C.printAllLands();
    std::cout << "Площадь земель собственника \"" << C.getFIO() << "\" = " 
        << C.getArea() << " кв.км\n" ;
    D.printAllLands();
    std::cout << "Площадь земель собственника \"" << D.getFIO() << "\" = " 
        << D.getArea() << " кв.км\n" ;
    std::cout << std::endl;

    CadastralChamber Chamber1("Chamber_1", 5, new Holder*[5]{
        &A,
        &B,
        &C,
        &D,
        new Holder("E", 10, true)
    });
    CadastralChamber Chamber2("Chamber_2", 2, new Holder*[2]{
        new Holder("1", 3, new Land*[3]{
            new Land(LandType::circle, 5.0) ,
            new Land(LandType::rectangle, 10.0),
            new Land(LandType::square, 15.0)
        }),
        new Holder("2", 2, true)
    });
    CadastralChamber Chamber3{ Chamber2 };
    Chamber3.setName("Chamber_3");
    CadastralChamber Chamber4{ std::move(Chamber2) };
    Chamber4.setName("Chamber_4");

    Chamber1.printAllHolders();
    std::cout << "Площадь земель палаты \"" << Chamber1.getName() << "\" = " 
        << Chamber1.getArea() << " кв.км\n" ;
    Chamber2.printAllHolders();
    std::cout << "Площадь земель палаты \"" << Chamber2.getName() << "\" = " 
        << Chamber2.getArea() << " кв.км\n" ;
    Chamber3.printAllHolders();
    std::cout << "Площадь земель палаты \"" << Chamber3.getName() << "\" = " 
        << Chamber3.getArea() << " кв.км\n" ;
    Chamber4.printAllHolders();
    std::cout << "Площадь земель палаты \"" << Chamber4.getName() << "\" = " 
        << Chamber4.getArea() << " кв.км\n" ;
    std::cout << std::endl;

    return 0;
}
