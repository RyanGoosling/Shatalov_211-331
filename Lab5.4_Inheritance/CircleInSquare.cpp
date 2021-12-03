#include "CircleInSquare.h"
#include <iostream>

CircleInSquare::CircleInSquare()
{
	//this->Position::set_position(0, 0);
	//this->set_radius(0);
	//this->set_size(0);
}

CircleInSquare::CircleInSquare(int x, int y, int rad, int size)
{
	this->Position::set_position(x, y);
	this->set_radius(rad);
	this->set_size(size);
}

CircleInSquare::CircleInSquare(int rad, int size)
{
	this->set_radius(rad);
	this->set_size(size);
}

CircleInSquare::CircleInSquare(const CircleInSquare& orig)
{
	this->Position::set_position(orig.Position::get_y(), orig.Position::get_x());

	this->set_size(orig.get_size());
	this->set_radius(orig.get_radius());
}

void CircleInSquare::set_cirlceinsquare(int x, int y, int rad, int size)
{
	this->Position::set_position(x, y);
	this->set_radius(rad);
	this->set_size(size);
}

void CircleInSquare::print() const
{
	//std::cout<<std::endl;
	this->Position::print();
	std::cout<<"size = " << this->get_size()<<", radius = " << this->get_radius()<<std::endl;
}

double CircleInSquare::perimeter_circleinsquare() const
{
	double perimeter = perimeter_circle() + perimeter_square() * 1.0;
	return perimeter;
}
