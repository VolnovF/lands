#include <QCoreApplication>
#include <iostream>
#include <utility>

#include "shapes/triangle.h"
#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "shapes/square.h"
#include "holder.h"
#include "landchamber.h"

int main()
{
    Triangle l1 = Triangle(5, 4, 3);
    Circle l2 = Circle(6.0);
    Rectangle l3 = Rectangle(4, 3);
    Square ld4 = Square(3);

    Holder h1{"1"};
    Holder h2{"2"};
    Holder h3{"3"};

    LandChamber chamber;
    chamber.registrateOwnership(&l1, &h1);
    chamber.registrateOwnership(&l1, &h1);
    chamber.registrateOwnership(&l2, &h2);
    chamber.registrateOwnership(&l2, &h3);
    chamber.registrateOwnership(&l3, &h3);

    auto vector = chamber.allOwnerships();

    for (auto i : chamber.allOwnerships())
    {
        std::cout << "Гражданин №" << i.holder << " владеет участком №" << i.land << '\n' ;
    }
}
