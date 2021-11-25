#include "Matr3Diag.h"
#include <iostream>
#include <ctime>

Matr3Diag::Matr3Diag()
{
	this->size = 0; // size = 5 = 5x5
	this->elem = nullptr;
}

Matr3Diag::Matr3Diag(int n)
{
	this->size = n;
	this->elem = new int[this->size * 3];
	for (int i = 0; i < 3 * n; i++)
		this->elem[i] = i + 1;
	this->elem[n - 1] = 0;
	this->elem[2 * n] = 0;
}

Matr3Diag::~Matr3Diag()
{
	if (this->elem != nullptr)
		delete[] elem;
}

Matr3Diag::Matr3Diag(const Matr3Diag& orig)
{
	this->size = orig.size;
	this->elem = new int[3 * this->size];
	for (int i = 0; i < 3 * this->size; i++)
		this->elem[i] = orig.elem[i];
}

void Matr3Diag::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
			std::cout << i * this->size + j << ": " << get_elem(i, j)<<"\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int Matr3Diag::get_elem(int i, int j) const
{
	if (i == j)
		return this->elem[this->size + i];
	if (i == j - 1)
		return this->elem[i];
	if (i == j + 1)
		return this->elem[2 * this->size + i];
	else return 0;
}

void Matr3Diag::input(int n)
{
	if (this->elem != nullptr)
		delete[] this->elem;
	this->size = n;
	this->elem = new int[this->size * 3];
	int random;
	std::cout << "1. Manual\n" << "2. Random\n";
	std::cin >> random;
	if (random == 2)
		 for (int i = 0; i < 3 * n; i++)
			this->elem[i] = i + 1; // rework
	else for (int i = 0; i < 3 * n; i++)
			std::cin >> this->elem[i];
	this->elem[n - 1] = 0;
	this->elem[2*n] = 0;
}

void Matr3Diag::check_memory() const
{
	std::cout << "\t" << this->elem << "\n";
}

void Matr3Diag::ex() const
{
	int temp;
	std::cin >> temp;
	if (temp == 1)
	for (int i = 0; i < this->size * 3; i++)
		std::cout << this->elem[i]<<"\t";
	else for (int i = 0; i < this->size; i++)
			for (int j = 0; j < this->size; j++)
				std::cout << get_elem(i, j) << "\t";
} // тест вывода и внутреннего представления матрицы

int Matr3Diag::tr() const
{
	int tr = 0;
	for (int i = 0; i < this->size; i++)
		tr += this->elem[this->size + i];
	return tr;
}

void Matr3Diag::det()
{
	int** matr = new int* [this->size];

	for (int i = 0; i < this->size; i++)
		matr[i] = new int[this->size];

	for (int i = 0; i < this->size; i++)
		for (int j = 0; j < this->size; j++)
			matr[i][j] = get_elem(i, j);

	int det = determinant(matr, this->size);//(matr, this->row)
	std::cout << det << std::endl;
}

int** Matr3Diag::submatrix(int** matrix, unsigned int n, unsigned int x, unsigned int y) {
	int** submatrix = new int* [n - 1];
	int subi = 0;

	for (unsigned int i = 0; i < n; i++)
	{
		submatrix[subi] = new int[n - 1];
		int subj = 0;
		if (i == y) {
			continue;
		}
		for (unsigned int j = 0; j < n; j++)
		{
			if (j == x)
				continue;
			submatrix[subi][subj] = matrix[i][j];
			subj++;
		}
		subi++;
	}

	return submatrix;
}

int Matr3Diag::determinant(int** matrix, unsigned int n) {
	int det = 0;
	if (n == 2)
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	for (unsigned int x = 0; x < n; ++x)
		det += ((x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix(matrix, n, x, 0), n - 1));

	return det;
}

int Matr3Diag::get_size() const
{
	return this->size;
}

void Matr3Diag::operator+=(const Matr3Diag& temp)
{
	if (this->size == temp.size)
	{
		for (int i = 0; i < 3 * this->size; i++)
			this->elem[i] += temp.elem[i];
	}
} // меняет класс

void Matr3Diag::operator-=(const Matr3Diag& temp)
{
	if (this->size == temp.size)
	{
		for (int i = 0; i < 3 * this->size; i++)
			this->elem[i] -= temp.elem[i];
	}
}

void Matr3Diag::operator*=(const Matr3Diag& temp)
{
	int* res = new int[this->size * this->size];
	for (int i = 0; i < this->size * this->size; i++)
		res[i] = 0;
	if (this->size == temp.size)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
					res[i * this->size + j] += get_elem(i, k) * temp.get_elem(k, j);
			}
		}
	}
	
	/*for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
			std::cout << res[i * this->size + j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;*/

	delete[] this->elem;

	this->elem = new int[this->size * this->size];

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			this->elem[i * this->size + j] = res[i * this->size + j];
			std::cout <<i*this->size + j<<": " << this->elem[i * this->size + j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	delete[] res;
}

Matr3Diag Matr3Diag::operator-()
{
	for (int i = 0; i < 3 * this->size; i++)
		this->elem[i] *= (-1);
	return Matr3Diag();
}

std::ostream& operator<<(std::ostream& out, const Matr3Diag& temp)
{
	for (int i = 0; i < temp.size; i++)
	{
		for (int j = 0; j < temp.size; j++)
			out << temp.get_elem(i, j) << "\t";
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Matr3Diag& temp)
{
	if (temp.elem != nullptr)
		delete[] temp.elem;
	std::cout << "Enter size\n";
	in >> temp.size;
	temp.elem = new int[temp.size * 3];
	for (int i = 0; i < 3 * temp.size; i++)
		temp.elem[i] = i + 1;
	temp.elem[temp.size - 1] = 0;
	temp.elem[2 * temp.size] = 0;
	return in;
}

Matr3Diag operator+(const Matr3Diag& MatrB, const Matr3Diag& MatrA)
{
	Matr3Diag res(MatrA);
	if (MatrA.get_size() != MatrB.get_size())
	{
		return res;
	}
	
	res+=MatrB;//поэлементно переделать
	return res;
}

Matr3Diag operator-(const Matr3Diag& MatrA, const Matr3Diag& MatrB)
{
	Matr3Diag res(MatrA);
	if (MatrA.get_size() != MatrB.get_size())
	{
		return res;
	}

	res -= MatrB;//поэлементно переделать probably
	return res;
}

Matr3Diag operator*(const Matr3Diag& MatrA, const Matr3Diag& MatrB)
{
	Matr3Diag res(MatrA);
	if (MatrA.get_size() != MatrB.get_size())
	{
		return res;
	}

	res *= MatrB;
	return res;
}
