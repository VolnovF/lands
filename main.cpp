#include <iostream>

#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "shapes/square.h"
#include "shapes/triangle.h"

#include "land.h"
#include "holder.h"

int main()
{
    Land triangle {"6га", new Triangle(5, 4, 3)};
    Land circle {"круг", new Circle(2)};
    Land rectangle {"2га", new Rectangle(1, 2)};
    Land square {"1га", new Square(1)};

    Holder ivan{"1"};
    Holder konstantin{"2"};
    Holder anton{"3"};

    triangle.add(&ivan, Fraction(97,99));
    triangle.add(&konstantin, Fraction(2,99));
    triangle.commit();

    circle.add(&anton, Fraction(1));
    circle.commit();

    rectangle.add(&ivan, Fraction(1,3));
    rectangle.add(&konstantin, Fraction(1,3));
    rectangle.add(&anton, Fraction(1,3));
    rectangle.commit();

    square.add(&ivan, 0.7);
    square.add(&konstantin, 0.3);
    square.commit();

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
    std::cout << "Всего: " << ivan.getArea() + konstantin.getArea() + anton.getArea() << " га. земли\n" ;
}
