#include "Point.h"

Point::Point()
{
	this->m_x = 0;
	this->m_y = 0;
}

Point::Point(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

void Point::setx(int x)
{
	this->m_x = x;
}

void Point::sety(int y)
{
	this->m_y = y;
}

void Point::set(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

int Point::getx() const
{
	return this->m_x;
}

int Point::gety() const
{
	return this->m_y;
}

int Point::get() const
{
	return (m_x, m_y);
}

std::ostream& operator<<(std::ostream& out, const Point& temp)
{
	out << temp.getx() << " " << temp.gety() << std::endl;
	return out;
}
