#include <iostream>

#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "shapes/square.h"
#include "shapes/triangle.h"

#include "land.h"
#include "holder.h"

int main()
{
    Land triangle {"ул.Ленина 181", new Triangle(5, 4, 3)};
    Land circle {"ул.Ленина 182", new Circle(2)};
    Land rectangle {"ул.Ленина 183", new Rectangle(1, 2)};
    Land square {"ул.Ленина 184", new Square(1)};

    Holder ivan{"Иванов Иван Иванович"};
    Holder konstantin{"Константин Сергеевич"};
    Holder anton{"Антон"};

    rectangle.add(&ivan, Fraction(1,3));
    rectangle.add(&konstantin, Fraction(1,3));
    rectangle.add(&anton, Fraction(1,3));
    std::cout << rectangle.commit() << ' ';

    triangle.add(&ivan, Fraction(97,99));
    triangle.add(&konstantin, Fraction(2,99));
    std::cout << triangle.commit() << ' ';

    circle.add(&anton, Fraction(1));
    std::cout << circle.commit() << ' ';

    square.add(&ivan, Fraction(5,12));
    square.add(&konstantin, Fraction(7,12));
    std::cout << square.commit() << '\n';

    std::cout << triangle.getAddres() << " площадью " << triangle.getArea() << " га. земли\n" ;
    std::cout << circle.getAddres() << " площадью " << circle.getArea() << " га. земли\n";
    std::cout << rectangle.getAddres() << " площадью " << rectangle.getArea() << " га. земли\n" ;
    std::cout << square.getAddres() << " площадью " << square.getArea() << " га. земли\n" ;
    std::cout << "Всего: " << triangle.getArea() + circle.getArea() + rectangle.getArea() + square.getArea() << " га. земли\n" ;
    std::cout << "\n" ;
    std::cout << ivan.getFio() << " владеет " << ivan.getArea() << " га. земли\n" ;
    std::cout << konstantin.getFio() << " владеет " << konstantin.getArea() << " га. земли\n" ;
    std::cout << anton.getFio() << " владеет " << anton.getArea() << " га. земли\n";
    std::cout << "Всего: " << ivan.getArea() + konstantin.getArea() + anton.getArea() << " га. земли\n" ;
}
