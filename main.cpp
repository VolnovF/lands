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
    Land(int type, double area)
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
		setType( getRandomInt(0, static_cast<int>(LandType::maxTypes) - 1) );
		setArea( getRandomInt(1, 9999) / 100.0 );
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
    int getType() const { return static_cast<int>(m_type); }
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
    //void 
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
        : m_fio {fio}, m_size{ size }, m_lands { new Land[size] }
    {
        for (size_t i = 0; i < m_size; i++)
        {
            setLand(i, lands[i].getType(), lands[i].getArea());
        }
    }

    void setLand(size_t i, int type, double area)
    {
        m_lands[i].setType(type);
        m_lands[i].setArea(area);
    }
    void randomizeAllLands()
    {
        for (size_t i = 0; i < m_size; i++)
        {
			m_lands[i].randomize();
		};
    }
    void printAllLands()
    {
        std::cout << "    Собственник " << m_fio << '\n';
        for (size_t i = 0; i < m_size; i++)
        {
            std::cout << '#' << i + 1 << ' ';
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
    double getArea()
    {
        double sumArea{0};
        for (size_t i = 0; i < m_size; i++)
        {
            sumArea += m_lands[i].getArea();
        }
        return sumArea;
    }

    ~Holder()
    {
        delete[] m_lands;  
    }

};

class CadastralChamber
{
private:

public:
    CadastralChamber()
    {

    }
};


int main()
{      
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    /*Holder misterA(2);
    misterA.setLand(0, 2, 5.0);
    misterA.setLand(1, 1, 10.0);
    misterA.printLands();
    std::cout << '\n';*/

    Holder misterB("B", 2, new Land[2]{
        Land(0, 5.0),
        Land(1, 10.0)
    });
    misterB.printAllLands();

    Holder A("VFT", 3, true);
    A.printAllLands();
    std::cout << '\n' << A.getArea();

    // TO DO:
    // 1) Holder.randomLands
    // 2) Площадь земель Ho  lder-а
    // 3) класс земельной палаты

    return 0;
}
