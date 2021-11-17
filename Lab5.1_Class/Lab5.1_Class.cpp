#include <iostream>
#include "Matrix.h"
#include <ctime>

using namespace std;

/*
struct Student
{
    string fio;
    string birthday;
    int group_number;
    int* score;
};*/

/*void init_Student(Student& temp)
{
    temp.fio = "qwerty";
    temp.birthday = "12.15.2022";
    temp.group_number = 331;
    temp.score = new int[3];
    for (int i = 0; i < 3; i++)
        temp.score[i] = 3 + (i + 1) % 2;
}*/

int main()
{
    //бд с ФИО дата рождения, группа, успеваемость
    /* 
    1 Способ
    string fio[100], birthday[100];
    Возможны ошибки, необходимо следить за индексами*/
    /*
    2 способ - создать свой собственный тип данных
    создается посредством struct, которая задается перед main, как функция
    Не чистится память автоматически, постоянно нужно передавать в структуру,
    если перед инициализацией объекта нужно что-то задать, то мы не можем
    */
    /*Student ivanov, petrov, sadonovich;
    Student group331[27]; //таблица из 27 строк
    init_Student(ivanov);
    cout << "Ivanov.fio = " << ivanov.fio;

    delete[] ivanov.score;*/

    /*
    3 Способ
    Классы:  проект, добавить, класс
    */
    srand(time(0));
    int row_arr, col_arr, num = 1;
    int numtask = 1;            
    int choise = 0;

    cout << "Number of rows = ";
    cin >> row_arr;
    cout << "Number of columns = ";
    cin >> col_arr;

    Matrix MatrA(row_arr, col_arr); //создание объкта MatrA класса Matrix
    Matrix MatrB(row_arr, col_arr);

    while (numtask != 0) {
        cout << "\n\nChoose number of task\n";
        cout << "1. AutoInput matrix\n" << "2. Output rows\n" << "3. Output columns\n" 
            << "4. Manual Input matrix\n" <<"5. Output matrix\n" <<"6. Get element of matrix\n" 
            <<"7. Trace of matrix\n"<<"8. Summing of matrices\n"<<"9. Multiplication of matrices\n" 
            <<"10. Multiplication of matrix to number\n" << "11. Det of matrix\n" <<"Default. Clear console\n" << "0. Exit\n\n";
        cin >> numtask;
        //system("cls"); // Чистит экран
        switch (numtask)
        {
        case 1:
            cout << "Enter 1. Number of rows = ";
            cin >> row_arr; 
            cout <<"2. Number of columns = ";
            cin >> col_arr;
            cout << "For 1st or 2nd matrix?\n";
            cin >> choise;
            if (choise == 1)
                 MatrA.auto_input(row_arr, col_arr);
            else MatrB.auto_input(row_arr, col_arr);
            break;
        case 2:
            cout << "MatrA.get_rows() = " << MatrA.get_rows() << endl;
            break;
        case 3:
            cout << "MatrA.get_columns() = " << MatrA.get_columns() << endl;
            break;
        case 4:
            cout << "1. Common Matrix;\n2. Square Matrix.\n";
            cin >> choise;
            if (choise == 1)
            {
                cout << "Enter: 1. Number of rows = ";
                cin >> row_arr;
                cout << "2. Number of columns = ";
                cin >> col_arr;
                MatrA.input(row_arr, col_arr);
            }
            else 
            {
                cout << "Enter 1. Number of rows and columns: ";
                cin >> row_arr;
                MatrA.input(row_arr);
            }
            break;
        case 5:
            MatrA.print();
            MatrB.print();
            break;
        case 6:
            cout << "Enter 1. Number of rows = ";
            cin >> row_arr;
            cout << "2. Number of columns = ";
            cin >> col_arr;
            cout << "MatrA.get_elem("<<row_arr<<", "<<col_arr<< ") = " 
                << MatrA.get_elem(row_arr, col_arr) << endl;
            break;
        case 7:
            cout << "MatrA.trace() = " << MatrA.trace() << endl;
            cout << "Output the matrix?\n1: yes;\t0: no;\n";
            cin >> choise;
            if (choise == 1) 
                MatrA.print();
            break;
        case 8:
            MatrA.sum(MatrB);
            break;
        case 9:
            MatrA.mult(MatrB);
            break;
        case 10:
            cout << "Enter number for multiplication\n";
            cin >> num;
            MatrA.mult_by_num(num);
            cout << "Output the matrix?\n1: yes;\t0: no;\n";
            cin >> choise;
            if (choise == 1)
                MatrA.print();
            break;
        case 11:
            MatrA.det();
            break;
        case 666:
            MatrA.check_memory();
            MatrB.check_memory();
            break;
        default: system("cls");
            break;
        }
    }
}
/*
+ int get_rows() - количество строк
+ int get_columns() - количество столбцов,
+ void input() - ввести матрицу с клавиатуры,
+ void print() - печать матрицы в консоль
+ matr* sum(const matr * mat2) или sum(const matr * mat2) - сложения матриц,
+ matr* mult(const matr * mat2) или void mult(const matr * mat2) - умножения двух матриц,
+ double trace() - след матрицы (сумма диагональных элементов квадратной матрицы),
+ double det()  - определитель матрицы (для квадратных),
+ matr* mult_by_num(double num)  или void mult_by_num(double num)   - умножение матрицы на число
+ double get_elem(int i, int j) - вернуть (i,j) элемент
*/