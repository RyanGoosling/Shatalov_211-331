#include "Matrix.h"
#include <iostream>
#include <ctime>

Matrix::Matrix()
{
	row = 0;
	col = 0;
	elem = nullptr;
	matr = nullptr;
}

Matrix::Matrix(int row_temp, int col_temp) 
{	//для одномерного представления матрицы
	this->row = row_temp;
	this->col = col_temp;

	this->matr = nullptr;
	this->elem = new int[row * col];

	for (int i = 0; i < row * col; i++)
		this->elem[i] = 1 + rand() % 20;
}

Matrix::Matrix(int n) 
{
	//для двумерного представления квадратной матрицы
	this->row = n;
	this->col = n;
	this->elem = nullptr;

	this->matr = new int* [row];
	for (int i = 0; i < row; i++)
		matr[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			matr[i][j] = 1 + rand() % 20;
} 

Matrix::~Matrix()
{
	if (this->elem != nullptr)
	{
		delete[] this->elem;
	}

	if (this->matr != nullptr)
	{
		delete[] this->matr;
	}
}

Matrix::Matrix(const Matrix& orig)
{
	this->row = orig.row;
	this->col = orig.col;

	if (orig.elem != nullptr)
		this->elem = new int[this->row * this->col];
	else this->elem = nullptr;

	if (orig.matr != nullptr)
	{
		this->matr = new int* [row];
		for (int i = 0; i < row; i++)
			matr[i] = new int[col];
	}
	else this->matr = nullptr;

	if (this->elem != nullptr)
		for (int i = 0; i < this->row * this->col; i++)
			this->elem[i] = orig.elem[i];

	if (this->matr != nullptr)
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				this->matr[i][j] = orig.matr[i][j];
}

void Matrix::set_row(int temp)
{
	int* temp_arr = this->elem;
	this->elem = new int[temp * this->col];
	for (int i = 0; i < temp * this->col, i < this->row * this->col; i++)
		this->elem[i] = temp_arr[i];
	delete[] temp_arr;
	this->row = temp;
}

void Matrix::check_memory()
{
	std::cout << std::endl <<this->elem <<" "<< this->matr << std::endl;
}

int Matrix::get_elem(int i, int j)
{
	return this->elem[i * col + j];
}

int Matrix::get_rows()
{
	return row;
}

int Matrix::get_columns()
{
	return col;
}

void Matrix::print()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << this->elem[i * this->col + j] << "\t"; //<<i * this->col + j <<": "
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Matrix::print(bool flag)
{
	if (flag)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				std::cout << matr[i][j] << "\t";
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void Matrix::input(int new_row, int new_col)
{
	this->row = new_row;
	this->col = new_col;
	if (this->elem != nullptr)
		delete[]this->elem;
	this->elem = new int[this->row * this->col];
	for (int i = 0; i < this->row * this->col; i++)
		std::cin >> this->elem[i];
}

void Matrix::auto_input(int new_row, int new_col)
{
	srand(time(0));
	this->row = new_row;
	this->col = new_col;

	if (this->elem != nullptr)
	{
		delete[]this->elem;
		this->elem = new int[this->row * this->col];
		for (int i = 0; i < this->row * this->col; i++)
			this->elem[i] = 1 + rand() % 20;
	}

	if (this->matr != nullptr)
	{
		delete[]this->matr;
		this->matr = new int* [row];
		for (int i = 0; i < row; i++)
			matr[i] = new int[col];
		for (int i = 0; i < this->row; i++)
			for (int j = 0; j < this->col; j++)
				this->matr[i][j] = 1 + rand() % 20;
	}
}

int Matrix::trace()
{
	int sum = 0;
	for (int i = 0; i < this->row; i++)
		for (int j = 0; j < this->col; j++)
			if (i == j) 
				sum += elem[i * this->col + j];

	return sum;
}

void Matrix::mult_by_num(double num)
{
	for (int i = 0; i < this->row * this->col; i++)
		this->elem[i] *= num;
}

bool Matrix::mult(const Matrix first, const Matrix second)
{
	if (first.col != second.row)
	{
		std::cout << "Error ";
		return false;
	}

	int* res = new int[first.row * second.col];
	int i, j, k;

	for (i = 0; i < first.row * second.col; i++)
		res[i] = 0;
	for (i = 0; i < first.row; i++)
	{
		for (j = 0; j < second.col; j++)
		{
			for (k = 0; k < first.col; k++)
				res[i * second.col + j] += first.elem[i * first.col + k] * second.elem[k * second.col + j];
		}
	}

	for (i = 0; i < first.row; i++)
	{
		for (j = 0; j < second.col; j++)
			std::cout << res[i * second.col + j] << " ";
		std::cout << std::endl;
	}
	delete[] res;

	return true;
}

bool Matrix::sum(Matrix second)
{
	if ((this->row != second.row) && (this->col != second.col))
	{
		std::cout << "Error: Matrix sizes are not equal\n";
		return false;
	}

	for (int i = 0; i < this->row * this->col; i++)
		this->elem[i] += second.elem[i];

	return true;
}

int** Matrix::submatrix(int** matrix, unsigned int n, unsigned int x, unsigned int y) {
	int** submatrix = new int* [n - 1];
	int subi = 0;

	for (int i = 0; i < n; i++) 
	{
		submatrix[subi] = new int[n - 1];
		int subj = 0;
		if (i == y) {
			continue;
		}
		for (int j = 0; j < n; j++) 
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

int Matrix::determinant(int** matrix, unsigned int n) {
	int det = 0;
	if (n == 2) 
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	for (int x = 0; x < n; ++x) 
		det += ((x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix(matrix, n, x, 0), n - 1));

	return det;
}

void Matrix::det()
{
	int det = determinant(this->matr, this->row);
	std::cout << det <<std::endl;
}