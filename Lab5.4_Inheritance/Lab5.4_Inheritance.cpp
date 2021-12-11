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

    cout << "dot: ";
    dot.print();

    dot.set_position(55, 66);

    x = dot.get_x();
    y = line.get_y();

    cout <<"x from dot = " << x << "\n" <<"y from line = " << y << endl << endl;

    Square SqA;
    Square SqB(6);
    
    cout << "SqA: ";
    SqA.print();
    cout << "SqB: ";
    SqB.print();

    cout <<"SqB area = "<< SqB.area_square() << "\n" <<"SqB perimeter = " << SqB.perimeter_square() << endl << endl;

    Circle CirA;
    Circle CirB(5);

    cout << "CirA: ";
    CirA.print();
    cout << "CirB: ";
    CirB.print();

    cout << "CirB area = " << CirB.area_circle() << "\n" << "CirB perimeter = " << CirB.perimeter_circle()<<endl<<endl;

    CircleInSquare CSQa; // ((Cicrle)CSQa).SameNameOfMethod()
    CircleInSquare CSQb(1, 1, 5, 6); // два раза класс позиция

    cout << "CSQa: ";
    CSQa.print();
    cout << "CSQb: ";
    CSQb.print();

    cout <<"CSQb sum of perimeters = " << CSQb.perimeter_circleinsquare()<<endl;
    return 0;
}
