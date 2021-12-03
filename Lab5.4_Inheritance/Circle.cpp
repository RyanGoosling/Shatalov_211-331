#include "Circle.h"

const double pie = 3.14159265358979;

Circle::Circle()
{
	//this->Position::set_position(0, 0);
	this->m_rad = 0;
}

Circle::Circle(int rad)
{
	//this->Position::set_position(0, 0);
	this->m_rad = rad;
}

Circle::Circle(int x, int y, int rad)
{
	this->Position::set_position(x, y);
	this->m_rad = rad;
}

Circle::Circle(const Circle& orig)
{
	this->Position::set_position(orig.Position::get_y(), orig.Position::get_x());

	this->m_rad = orig.m_rad;
}

void Circle::set_circle(int x, int y, int rad)
{
	this->Position::set_position(x, y);
	this->m_rad = rad;
}

void Circle::set_radius(int rad)
{
	this->m_rad = rad;
}

void Circle::print() const
{
	this->Position::print();
	std::cout << "size = " << get_radius() << std::endl;
}

int Circle::get_radius() const
{
	return this->m_rad;
}

double Circle::area_circle() const
{
	double area = pie * m_rad * m_rad;
	return area;
}

double Circle::perimeter_circle() const
{
	double perimeter = 2 * pie * m_rad;
	return perimeter;
}
