#include "Position.h"
#include <iostream>

Position::Position()
{
	m_x = 0;
	m_y = 0;
}

Position::~Position()
{

}

Position::Position(const Position& orig)
{
	this->m_x = orig.m_x;
	this->m_y = orig.m_y;
}

Position::Position(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Position::set_position(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

void Position::set_x(int x)
{
	this->m_x = x;
}

void Position::set_y(int y)
{
	this->m_y = y;
}

int Position::get_x() const
{
	return this->m_x;
}

int Position::get_y() const
{
	return this->m_y;
}

void Position::print() const
{
	std::cout << "x = " << this->m_x << ", y = " << this->m_y << std::endl;
}


