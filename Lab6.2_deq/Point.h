#pragma once
#include <iostream>

class Point
{
private:
	int m_x;
	int m_y;

public:
	Point();
	Point(int x, int y);

	void setx(int x);
	void sety(int y);
	void set(int x, int y);

	int getx() const;
	int gety() const;
	int get() const;

	friend std::ostream& operator<< (std::ostream& out, const Point& temp);
};

