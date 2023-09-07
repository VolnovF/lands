#include <iostream>
#include <array>

enum class LandType
{
    circle,
    triangle,
    square,
    rectangle,
    maxTypes
};

class Land
{
private:
    LandType m_type{};
    double m_area{};
public:
    Land( int type, double area ):
        m_type{ static_cast<LandType>(type) }, m_area{ area } 
    {
    }
    Land():
        m_type{ LandType::maxTypes }, m_area{ 0 }
    {
    }
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
        if (type < static_cast<int>(LandType::maxTypes))
        {
            m_type = static_cast<LandType>(type);
        }
        std::cout << "Введите площадь участка: ";
        double area{};
        std::cin >> area;
        if (area > 0)
        {
            m_area = area;
        }
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
    Land *m_lands{nullptr};
    size_t m_countLands{};
public:
    void inputAllLands()
    {
        for (size_t i {0}; i < m_countLands; i++)
        {
            m_lands[i].input();
        }
    }
    Holder(size_t size) : m_countLands{size}
    {
        m_lands = new Land[size];
    }
    Holder(Land lands[])
    {
        m_lands = new Land[lands.size()]{lands};
    }
    void printLand(size_t land)
    {
        if (land >= m_countLands)
        {
            std::cout << "Land number " << land << " does not exist";
            return;
        }
        m_lands[land].print();
    }
    size_t getCountLands() { return m_countLands; }

    /*~Holder()
    {
        delete[] m_lands;
    }*/
};


int main()
{
    /*Land p{0, 2.0};
    p.print();*/
    
    std::array<Land, 3> ptr{};

    //Holder h{2};
    Holder h{
        {4.0, 6.0},
        {4.0, 7.0}
    };
    h.printLand(0);
    h.printLand(1);
    std::cout << h.getCountLands();

    return 0;
}
