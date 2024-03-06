#include <iostream>

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

    Holder h1{"Иванов Иван Иванович"};
    Holder h2{"Константин Сергеевич"};
    Holder h3{"Антон"};

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
    Land *l_ptr{ Land::fromCadastaralID(vector[0].land) };
    if(l_ptr)
    {
        std::cout << "Участок №" << l_ptr->getCadastralID() << " площадью " << l_ptr->getArea() << " получен по кадастровому номеру" << '\n' ;
    }
    Holder *h_ptr{ Holder::fromPassport(vector[0].holder) };
    if(h_ptr)
    {
        std::cout << "Гражданин " << h_ptr->getFio() << " получен по номеру паспорта" << '\n' ;
    }
}
