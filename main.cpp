#include <iostream>

#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "shapes/square.h"
#include "shapes/triangle.h"

#include "land.h"
#include "holder.h"

int main()
{
    Land triangle {"Треугольник", new Triangle(5, 4, 3)};
    Land circle {"Круг", new Circle(2)};
    Land rectangle {"Прямоугольник", new Rectangle(1, 2)};
    Land square {"Квадрат", new Square(1)};

    Holder ivan{"Иван"};
    Holder konstantin{"Константин"};
    Holder anton{"Антон"};

    triangle.add(&ivan, Fraction(97,99));
    triangle.add(&konstantin, Fraction(2,99));
    triangle.commit();

    circle.add(&anton, Fraction(1));
    circle.commit();

    rectangle.changeShape(new Rectangle(2,2));
    rectangle.add(&ivan, Fraction(1,3));
    rectangle.add(&ivan, Fraction(1,3));
    rectangle.add(&anton, Fraction(1,3));
    rectangle.commit();

    square.add(&ivan, 0.7);
    square.add(&konstantin, 0.3);
    square.commit();

    std::cout << std::endl;
    std::cout << triangle.getAddres() << " площадью " << triangle.getArea() << " га. земли\n" ;
    std::cout << circle.getAddres() << " площадью " << circle.getArea() << " га. земли\n";
    std::cout << rectangle.getAddres() << " площадью " << rectangle.getArea() << " га. земли\n" ;
    std::cout << square.getAddres() << " площадью " << square.getArea() << " га. земли\n" ;
    std::cout << "Всего: " << triangle.getArea() + circle.getArea() + rectangle.getArea() + square.getArea() << " га. земли\n" ;
    std::cout << "\n" ;
    std::cout << ivan.getFio() << " владеет " << ivan.getArea() << " га. земли\n" ;
    std::cout << konstantin.getFio() << " владеет " << konstantin.getArea() << " га. земли\n" ;
    std::cout << anton.getFio() << " владеет " << anton.getArea() << " га. земли\n";
    std::cout << Holder::getChamber()->getFio() << " владеет " << Holder::getChamber()->getArea() << " га. земли\n";
    std::cout << "Всего: " << ivan.getArea() + konstantin.getArea() + anton.getArea() + Holder::getChamber()->getArea() << " га. земли\n" ;
}
