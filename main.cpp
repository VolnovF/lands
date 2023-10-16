#include <iostream>
#include <string> 
#include <vector>
#include <random>
#include <ctime>

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
    LandType m_type{LandType::maxTypes};
    double m_area{};
public:
    Land(LandType type, double area)
    {
        setType(type);
        setArea(area);
    }
    Land(bool rand = 0): m_type{ LandType::maxTypes }, m_area{ 0 }
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
    void setType(LandType type)
    {
        m_type = type;
    }
    void setType(int type)
    {
        if (type < static_cast<int>(LandType::maxTypes))
        {
                    m_type = static_cast<LandType>(type);
                    return;
        }
    }
    void setArea(double area)
    {
        if (area >= 0)
        {
            m_area = area;
        }
    }
    LandType getType() const { return m_type; }
    double getArea() const { return m_area; }
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
        switch ( static_cast<int>(m_type) )
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
        std::cout << "участок площадью " << m_area << " кв. км\n";
    }
};

class Holder
{
private:
    std::string m_fio;
    const size_t m_size;
    Land* m_lands;
public:
    Holder(std::string fio, size_t size, bool rand = 0)
        : m_fio {fio}, m_size{ size }, m_lands { new Land[size] }
    {
        if (rand)
        {
            for (size_t i = 0; i < size; i++)
            {
                m_lands[i].randomize();
            }
        }
    }
    Holder(std::string fio, size_t size, Land lands[])
        : m_fio {fio}, m_size{ size }, m_lands { lands }
    {
    }

    void setLand(size_t i, LandType type, double area)
    {
        m_lands[i].setType(type);
        m_lands[i].setArea(area);
    }
    std::string getFIO() const { return m_fio; }
    double getLandArea(size_t i) const { return m_lands[i].getArea(); }
    LandType getLandType(size_t i) const { return m_lands[i].getType(); }
    void randomizeAllLands()
    {
        for (size_t i = 0; i < m_size; i++)
        {
			m_lands[i].randomize();
		};
    }
    void printAllLands() const
    {
        std::cout << "Собственник " << m_fio << '\n';
        for (size_t i = 0; i < m_size; i++)
        {
            std::cout << '#' << i << ' ';
            m_lands[i].print();
        }
    }
    void inputAllLands()
    {
        for (size_t i {0}; i < m_size; i++)
        {
            m_lands[i].input();
        }
    }
    double getArea() const
    {
        double sumArea{0};
        for (size_t i = 0; i < m_size; i++)
        {
            sumArea += m_lands[i].getArea();
        }
        return sumArea;
    }
};

class CadastralChamber
{
private:
    std::string m_name;
    const size_t m_size;
    Holder* m_holders;
public:
    CadastralChamber(std::string name, size_t size, Holder holders[])
        : m_name {name}, m_size{ size }, m_holders { holders }
    {
    }
    
    double getArea() const 
    {
        double sum{0};
        for (size_t i = 0; i < m_size; i++)
        {
            sum += m_holders[i].getArea();
        }
        return sum;
    }
    double getHolderArea(size_t i) const { return m_holders[i].getArea(); }
    std::string getHolderFIO(size_t i) const { return m_holders[i].getFIO(); } 
    double getLandArea(size_t i, size_t j) const { return m_holders[i].getLandArea(j); }
    LandType getLandType(size_t i, size_t j) const { return m_holders[i].getLandType(j); }
    void printAllHolders()
    {
        std::cout << "         Кадастровая палата \"" << m_name << "\"\n";
        for (size_t i = 0; i < m_size; i++)
        {
            std::cout << "id:" << i << "  ";
            m_holders[i].printAllLands();
        };
    }
    void setLand(size_t i, size_t j, LandType type, double area)
    {
        m_holders[i].setLand(j, type, area);
    }

    ~CadastralChamber()
    {
        delete[] m_holders;
    }
};


int main()
{      
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Holder A("A", 3, new Land[3]{
        Land(LandType::circle, 5.0),
        Land(LandType::rectangle, 10.0),
        Land(LandType::square, 15.0)
    });

    Holder B("B", 3, true);
    Holder C("C", 5, true);

    CadastralChamber Chamber("Chamber", 4, new Holder[4]{
        A,
        B,
        C,
        Holder("C", 10, true)
    });
    Chamber.printAllHolders();

    return 0;
}
