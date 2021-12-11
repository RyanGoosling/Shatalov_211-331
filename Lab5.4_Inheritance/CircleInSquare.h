#pragma once
#include "Square.h"
#include "Circle.h"

class CircleInSquare :
	virtual public Circle, Square
{
public:

	CircleInSquare();
	CircleInSquare(int x, int y, int rad, int size);
	CircleInSquare(int rad, int size);
	CircleInSquare(const CircleInSquare& orig);

	void set_cirlceinsquare(int x, int y, int rad, int size);
	void print() const;

	double perimeter_circleinsquare() const;
};

