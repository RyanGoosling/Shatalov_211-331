#include <iostream>
#include "Matr.h"
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int row_arr, col_arr, row_matr, col_matr;
    int numtask = 1, temp = 2, choise = 0;
    bool random = false;
    int* arr = nullptr;

    cout << "Number of rows = ";
    cin >> row_arr;
    cout << "Number of columns = ";
    cin >> col_arr;

    col_matr = col_arr;
    row_matr = row_arr;

    arr = new int[col_arr * row_arr];
    for (int i = 0; i < row_arr * col_arr; i++)
        arr[i] = 1 + rand() % 20;

    Matr MatrA(row_arr, col_arr, arr);
    Matr MatrB(row_arr, col_arr);

    while (numtask != 0) {
        cout << "\n\nChoose number of task\n";
        cout << "1. Input matrix\n" << "2. Print matrix\n" 
             << "3. Overriding an array\n" << "4. Print array\n" 
             << "5. Summing of matrices\n" << "6. Multiplication of matrices\n" 
             << "Default. Clear console\n" << "0. Exit\n\n";
        cin >> numtask;
        //system("cls"); // Чистит экран
        switch (numtask)
        {
        case 1:
            cout << "1. MatrA\n2. MatrB\n";
            cin >> choise;
            cout << "1. AutoInput\n2. Manual Input\n3. From array\n";
            cin >> temp;
            if (temp == 1) random = true;
            if (temp != 3)
            {
                cout << "Number of rows = ";
                cin >> row_matr;
                cout << "Number of columns = ";
                cin >> col_matr;
            }
            if (choise == 1)
            {
                if (temp == 3)
                    MatrA.input(row_arr, col_arr, arr);
                else MatrA.input(row_matr, col_matr, random);
            }
            else
            {
                if (temp == 3)
                    MatrB.input(row_arr, col_arr, arr); //rows and columns = array
                else MatrB.input(row_matr, col_matr, random); //rows and columns can dont equal array
            }
            break;
        case 2:
            cout << "1. MatrA\n2. MatrB\n3. Both\n";
            cin >> temp;
            if (temp == 1)
                 MatrA.print();
            else  
                if (temp == 2) MatrB.print();
                else 
                {
                    MatrA.print();
                    MatrB.print();
                }
            break;
        case 3:
            cout << "Number of rows = ";
            cin >> row_arr;
            cout << "Number of columns = ";
            cin >> col_arr;
            delete[] arr;
            arr = new int[col_arr * row_arr];

            cout << "1. AutoInput\n2. Manual Input\n";
            cin >> temp;
            if (temp == 1)
                 for (int i = 0; i < row_arr * col_arr; i++)
                    arr[i] = 1 + rand() % 20;
            else for (int i = 0; i < row_arr * col_arr; i++)
                    cin >> arr[i];
            break;
        case 4:
            for (int i = 0; i < row_arr; i++)
            {
                for (int j = 0; j < col_arr; j++)
                    cout << arr[i * col_arr + j] << "\t";
                cout << endl;
            }
            cout << endl;
            break;
        case 5:
            cout << "1. MatrA + MatrB\n2. MatrA + arr\n";
            cin >> temp;
            if (temp == 1)
                 MatrA.sum(MatrB);
            else MatrA.sum(row_arr, col_arr, arr);
            break;
        case 6:
            cout << "1. MatrA * MatrB\n2. MatrA * arr\n";
            cin >> temp;
            if (temp == 1)
                MatrA.mult(MatrB);
            else MatrA.mult(row_arr, col_arr, arr);
            break;
        default: system("cls");
            break;
        }
    }
    return 0;
}


/*
+ Matrix(int i, int j); -//констуктор, i - количество строк, j - количество столбцов, 
+  элементы определяются 0;

+ Matrix(int i, int j, const double * arr); //констуктор, i - количество строк, 
+ j - количество столбцов, элементы определяются массивом arr;

+ Matrix sum(const double * arr) или void sum(const double * arr) - 
+ сложения матриц, результат возвращается или записывается в текущую матрицу соответственно;

+ Matrix mult(const double * arr) или void mult(const double * arr) - 
+ умножения двух матриц, результат возвращается или записывается в текущую матрицу соответственно;

+ void input(int i, int j) - ввести матрицу с клавиатуры c заданными размерами, 
+ i - количество строк, j - количество столбцов;

+ void input(int i, int j, double * arr) - инициализировать матрицу заданным массивом arr, 
+ i - количество строк, j - количество столбцов.
*/