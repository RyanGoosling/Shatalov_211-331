#pragma once
#include "Position.h"

class Circle :
    public Position
{
private:

    int m_rad;

public:

    Circle();
    Circle(int rad);
    Circle(int x, int y, int rad);
    Circle(const Circle& orig);

    void set_circle(int x, int y, int rad);
    void set_radius(int rad);

    void print() const;
    int get_radius() const;

    double area_circle() const;
    double perimeter_circle() const;
};

