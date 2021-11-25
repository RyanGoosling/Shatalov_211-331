#pragma once
#include<iostream>
class Matr3Diag
{
private:
	int size;
	int* elem;

	int** submatrix(int** matrix, unsigned int n, unsigned int x, unsigned int y);
	int determinant(int** matrix, unsigned int n);

public:
	Matr3Diag();
	Matr3Diag(int n);
	~Matr3Diag();
	Matr3Diag(const Matr3Diag& orig);

	int get_size() const;
	void print() const;
	int get_elem(int i, int j) const;
	void input(int n);
	
	void check_memory() const;
	void ex() const;
	
	int tr() const;
	void det();

	void operator+= (const Matr3Diag& temp);
	void operator-= (const Matr3Diag& temp);
	void operator*= (const Matr3Diag& temp);
	Matr3Diag operator- ();
	friend std::ostream& operator<< (std::ostream& out, const Matr3Diag& temp);
	friend std::istream& operator>> (std::istream& in, Matr3Diag& temp);
};

Matr3Diag operator+ (const Matr3Diag& MatrB, const Matr3Diag& MatrA);
Matr3Diag operator- (const Matr3Diag& MatrA, const Matr3Diag& MatrB);
Matr3Diag operator* (const Matr3Diag& MatrA, const Matr3Diag& MatrB);
	/*
		Перегрузка операторов
			- внутри класса (в ходе работы объект меняется,
				+=, -=, унарный -, ...)
			- в качестве дружественной функции 
				(необходим доступ к приватным членам класса)
			- вне класса
	*/