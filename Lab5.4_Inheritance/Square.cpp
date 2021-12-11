#include "Square.h"
#include <iostream>

Square::Square()
{
	//this->Position::set_position(0, 0);
	this->m_size = 0;
}

Square::Square(const Square& orig):Position(orig)
{
	//this->Position::set_position(orig.Position::get_y(), orig.Position::get_x());

	this->m_size = orig.m_size;
}

Square::Square(int x, int y, int size):Position(x, y)
{
	//this->Position::set_position(x, y);
	this->m_size = size;
}

Square::Square(int size)
{
	//this->Position::set_position(0, 0);
	this->m_size = size;
}

void Square::set_square(int x, int y, int size)
{
	this->Position::set_position(x, y);
	this->m_size = size;
}

int Square::get_size() const
{
	return this->m_size;
}

void Square::set_size(int size)
{
	this->m_size = size;
}

void Square::print() const
{
	this->Position::print();
	std::cout << "size = " << get_size() << std::endl;
}

int Square::area_square() const
{
	int area = m_size * m_size;
	return area;
}

int Square::perimeter_square() const
{
	int perimeter = 4 * m_size;
	return perimeter;
}
