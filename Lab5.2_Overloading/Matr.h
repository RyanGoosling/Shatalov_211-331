#pragma once
class Matr
{
private:
	int col;
	int row;
	int* elem;

public:

	Matr();
	Matr(int i, int j);
	Matr(int i, int j, const int* arr);

	~Matr();

	Matr(const Matr& orig);

	void sum(int row, int col, const int* arr);
	bool sum(Matr second);

	bool mult(int row, int col, const int* arr);
	bool mult(Matr second);

	void input(int i, int j, bool flag);
	void input(int i, int j, const int* arr);

	void print();
};

