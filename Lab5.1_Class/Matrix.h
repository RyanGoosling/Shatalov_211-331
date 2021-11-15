#pragma once
class Matrix
{
private: //доступно только классу Матрикс
	int row, col;
	int* elem;
	int** matr;

protected:
	//доступно внутри класса и наследникам 

public:
	//доступно всем из/для любой части кода
	
	Matrix();//конструктор поумолчанию, то что создаёт объект, память под элемент
	Matrix(int row_temp, int col_temp);
	Matrix(int n); //Перегрузка для объявления двумерного массива
	~Matrix();//деструктор, уничтажает память под объект, которую выделяли
	Matrix(const Matrix& orig); //конструктор копирования

	void set_row(int temp);

	void check_memory();

	int get_elem(int i, int j);

	int get_rows();

	int get_columns();

	void print();

	void print(bool flag);

	void input(int new_row, int new_col);

	void auto_input(int new_row, int new_col);

	int trace();

	void mult_by_num(double num);

	bool mult(Matrix first, Matrix second);

	bool sum(Matrix second);

	int** submatrix(int** matrix, unsigned int n, unsigned int x, unsigned int y);

	int determinant(int** matrix, unsigned int n);

	void det();
};

