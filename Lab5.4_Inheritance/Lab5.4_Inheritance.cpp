#include <iostream>
#include "Position.h"
#include "Square.h"
#include "Circle.h"
#include "CircleInSquare.h"

using namespace std;

int main()
{
    Position dot(1, 2);
    Position line(3, 4);
    int x, y;

    dot.set_x(11);
    line.set_y(44);

    dot.set_position(55, 66);

    x = dot.get_x();
    y = line.get_y();

    cout << x << " " << y<<endl<<endl;

    Square SqA;
    Square SqB(6);

    SqA.print();
    SqB.print();

    cout << SqB.area_square() << " " << SqB.perimeter_square()<<endl<<endl;

    Circle CirA;
    Circle CirB(5);

    CirA.print();
    CirB.print();

    cout << CirB.area_circle() << " " << CirB.perimeter_circle()<<endl<<endl;

    CircleInSquare CSQa; // ((Cicrle)CSQa).SameNameOfMethod()
    CircleInSquare CSQb(1, 1, 5, 6);

    CSQa.print();
    CSQb.print();

    cout << CSQb.perimeter_circleinsquare();
    return 0;
}
