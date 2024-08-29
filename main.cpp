#include <iostream>

#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "shapes/square.h"
#include "shapes/triangle.h"

#include "land.h"
#include "holder.h"

#include "fraction.h"
#include "fixedpart.h"

int main()
{
    Land triangle {"ул.Ленина 181", new Triangle(5, 4, 3)};
    Land circle {"ул.Ленина 182", new Circle(2)};
    Land rectangle {"ул.Ленина 183", new Rectangle(1, 2)};
    Land square {"ул.Ленина 184", new Square(3)};

    Holder ivan{"Иванов Иван Иванович"};
    Holder konstantin{"Константин Сергеевич"};
    Holder anton{"Антон"};

    ivan.addLand(&rectangle, new Fraction(1,3));
    konstantin.addLand(&rectangle, new Fraction(1,3));
    anton.addLand(&rectangle, new Fraction(1,3));

    ivan.addLand(&triangle, new Fraction(2,3));
    konstantin.addLand(&triangle, new Fraction(1,3));

    anton.addLand(&circle, new Fraction(1));

    ivan.addLand(&square, new FixedPart(5));
    konstantin.addLand(&square, new FixedPart(4));

    std::cout << triangle.getAddres() << " площадью " << triangle.getArea() << " га. земли\n" ;
    std::cout << circle.getAddres() << " площадью " << circle.getArea() << " га. земли\n";
    std::cout << rectangle.getAddres() << " площадью " << rectangle.getArea() << " га. земли\n" ;
    std::cout << square.getAddres() << " площадью " << square.getArea() << " га. земли\n" ;
    std::cout << "\n" ;
    std::cout << ivan.getFio() << " владеет " << ivan.getArea() << " га. земли\n" ;
    std::cout << konstantin.getFio() << " владеет " << konstantin.getArea() << " га. земли\n" ;
    std::cout << anton.getFio() << " владеет " << anton.getArea() << " га. земли\n";
}
