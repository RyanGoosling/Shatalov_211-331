#pragma once
#include "Position.h"

class Square :
    virtual public Position
{
private:

    int m_size;

public:

    Square();
    Square(const Square& orig);
    Square(int x, int y, int size);
    Square(int size);

    void set_square(int x, int y, int size);
    //void extreme_point();

    int get_size() const;
    void set_size(int size);
    void print() const;

    int area_square() const;
    int perimeter_square() const;

};

