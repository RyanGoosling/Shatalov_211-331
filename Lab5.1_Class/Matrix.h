#pragma once
class Matrix
{
private: //�������� ������ ������ �������
	int row, col;
	int* elem;
	int** matr;

protected:
	//�������� ������ ������ � ����������� 

public:
	//�������� ���� ��/��� ����� ����� ����
	
	Matrix();//����������� �����������, �� ��� ������ ������, ������ ��� �������
	Matrix(int row_temp, int col_temp);
	Matrix(int n); //���������� ��� ���������� ���������� �������
	~Matrix();//����������, ���������� ������ ��� ������, ������� ��������
	Matrix(const Matrix& orig); //����������� �����������

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

