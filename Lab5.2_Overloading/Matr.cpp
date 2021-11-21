#include "Matr.h"
#include <iostream>
#include <ctime>

Matr::Matr()
{
	row = 0;
	col = 0;
	elem = nullptr;
}

Matr::~Matr()
{
	if (this->elem != nullptr)
		delete[] this->elem;
}

Matr::Matr(int i, int j)
{
	this->row = i;
	this->col = j;
	elem = new int[row * col];
	for (int k = 0; k < row * col; k++)
		elem[k] = 0;
}

Matr::Matr(int i, int j, const int* arr)
{
	this->row = i;
	this->col = j;
	elem = new int[row * col];
	for (int k = 0; k < row * col; k++)
		elem[k] = arr[k];
}

Matr::Matr(const Matr& orig)
{
	this->row = orig.row;
	this->col = orig.col;

	if (orig.elem != nullptr)
		this->elem = new int[this->row * this->col];
	else this->elem = nullptr;

	if (this->elem != nullptr)
		for (int i = 0; i < this->row * this->col; i++)
			this->elem[i] = orig.elem[i];
}

void Matr::sum(int row, int col, const int* arr)
{
	if ((row * col) != (this->row * this->col))
	{
		std::cout << "\nError: matrices dont equal\n";
		return;
	}

	int* res = new int[this->row * this->col];

	for (int i = 0; i < this->row * this->col; i++)
		res[i] = this->elem[i] + arr[i];

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << res[i * this->col + j] << "\t"; //<<i * this->col + j <<": "
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool Matr::sum(Matr second)
{
	if ((this->row != second.row) && (this->col != second.col))
	{
		std::cout << "Error: Matrix sizes are not equal\n";
		return false;
	}
	int* res = new int[this->row * this->col];

	for (int i = 0; i < this->row * this->col; i++)
		res[i] = this->elem[i] + second.elem[i];

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << res[i * this->col + j] << "\t"; //<<i * this->col + j <<": "
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return true;
}

bool Matr::mult(int row, int col, const int* arr)
{
	if (this->col != row)
	{
		std::cout << "\nError: first col dont equal second row\n";
		return false;
	}

	int* res = new int[this->row * col];
	int i, j, k;

	for (i = 0; i < this->row * col; i++)
		res[i] = 0;
	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < col; j++)
		{
			for (k = 0; k < this->col; k++)
				res[i * col + j] += this->elem[i * this->col + k] * arr[k * col + j];
		}
	}

	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < col; j++)
			std::cout << res[i * col + j] << " ";
		std::cout << std::endl;
	}
	delete[] res;

	return true;
}

bool Matr::mult(Matr second)
{
	if (this->col != second.row)
	{
		std::cout << "\nError: first col dont equal second row\n";
		return false;
	}

	int* res = new int[this->row * second.col];
	int i, j, k;

	for (i = 0; i < this->row * second.col; i++)
		res[i] = 0;
	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < second.col; j++)
		{
			for (k = 0; k < this->col; k++)
				res[i * second.col + j] += this->elem[i * this->col + k] * second.elem[k * second.col + j];
		}
	}

	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < second.col; j++)
			std::cout << res[i * second.col + j] << " ";
		std::cout << std::endl;
	}
	delete[] res;

	return true;
}

void Matr::input(int i, int j, bool flag)
{
	srand(time(0));
	this->row = i;
	this->col = j;
	if (this->elem != nullptr)
		delete[]this->elem;
	this->elem = new int[this->row * this->col];
	if (flag)
		for (int k = 0; k < this->row * this->col; k++)
			elem[k] = 1 + rand() % 20;
	else for (int k = 0; k < this->row * this->col; k++)
			std::cin >> this->elem[k];
}

void Matr::input(int i, int j, const int* arr)
{
	this->row = i;
	this->col = j;
	if (this->elem != nullptr)
		delete[]this->elem;
	this->elem = new int[this->row * this->col];
	for (int k = 0; k < this->row * this->col; k++)
		this->elem[k] = arr[k];
}

void Matr::print()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << this->elem[i * this->col + j] << "\t"; //<<i * this->col + j <<": "
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
