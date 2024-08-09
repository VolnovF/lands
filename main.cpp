#include <iostream>

#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "shapes/square.h"
#include "shapes/triangle.h"

#include "land.h"
#include "holder.h"

int main()
{
    Land l1 {"ул.Ленина 184", new Triangle(500, 40, 300)};
    Land l2 {"ул.Ленина 184", new Circle(600.0)};
    Land l3 {"ул.Ленина 184", new Rectangle(40, 30)};
    Land l4 {"ул.Ленина 184", new Square(300)};

    Holder h1{"Иванов Иван Иванович"};
    Holder h2{"Константин Сергеевич"};
    Holder h3{"Антон"};

    h1.addLand(l1, Fraction(1,3));
    h2.addLand(l1, Fraction(1,3));
    h3.addLand(l1, Fraction(1,3));

    h1.addLand(l2, Fraction(2,3));
    h2.addLand(l2, Fraction(1,3));

    h3.addLand(l3, Fraction(1));

    h1.addLand(l4, Fraction(2,3));

    std::cout << h1.getFio() << "Владеет " << h1.getArea() << " кв.м земли\n" ;
    std::cout << h2.getFio() << "Владеет " << h2.getArea() << " кв.м земли\n" ;
    std::cout << h3.getFio() << "Владеет " << h3.getArea() << " кв.м земли\n" ;
}
