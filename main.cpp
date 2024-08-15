#include <iostream>

#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "shapes/square.h"
#include "shapes/triangle.h"

#include "land.h"
#include "holder.h"

int main()
{
    Land triangle {"ул.Ленина 181", new Triangle(500, 400, 300)};
    Land circle {"ул.Ленина 182", new Circle(600.0)};
    Land rectangle {"ул.Ленина 183", new Rectangle(40, 30)};
    Land square {"ул.Ленина 184", new Square(300)};

    Holder ivan{"Иванов Иван Иванович"};
    Holder konstantin{"Константин Сергеевич"};
    Holder anton{"Антон"};

    ivan.addLand(&triangle, Fraction(1,3));
    konstantin.addLand(&triangle, Fraction(1,3));
    anton.addLand(&triangle, Fraction(1,3));

    ivan.addLand(&circle, Fraction(2,3));
    konstantin.addLand(&circle, Fraction(1,3));

    anton.addLand(&rectangle, Fraction(1));

    ivan.addLand(&square, Fraction(2,3));

    std::cout << triangle.getAddres() << " площадью " << triangle.getArea() << " кв.м земли\n" ;
    std::cout << circle.getAddres() << " площадью " << circle.getArea() << " кв.м земли\n" ;
    std::cout << rectangle.getAddres() << " площадью " << rectangle.getArea() << " кв.м земли\n" ;
    std::cout << square.getAddres() << " площадью " << square.getArea() << " кв.м земли\n" ;
    std::cout << "\n" ;
    std::cout << ivan.getFio() << " владеет " << ivan.getArea() << " кв.м земли\n" ;
    std::cout << konstantin.getFio() << " владеет " << konstantin.getArea() << " кв.м земли\n" ;
    std::cout << anton.getFio() << " владеет " << anton.getArea() << " кв.м земли\n" ;
}
