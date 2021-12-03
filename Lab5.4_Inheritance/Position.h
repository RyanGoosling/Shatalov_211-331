#pragma once
#include <iostream>

class Position
{
private:

	int m_x;
	int m_y;

public:

	Position();
	~Position();
	Position(const Position& orig);
	Position(int x, int y);

	void set_position(int x, int y);
	void set_x(int x);
	void set_y(int y);

	int get_x() const;
	int get_y() const;
	void print() const;
};

