#include <iostream>
#include "Matr3Diag.h"

using namespace std;

int main()
{
    Matr3Diag MatrA(5);
    Matr3Diag MatrB(5);
    /*MatrA.input(5);
   // MatrA.print();
    cout << "A=\n" << MatrA<<endl;

    MatrA += MatrA;
    MatrA.print();
    
    (MatrA+MatrA).print();
    //MatrA.print();
    MatrA -= MatrA;
    cout << MatrA;
    cin >> MatrB;
    (MatrB - MatrB).print();
    cout << MatrB;*/
    
    int numtask = 1, choise = 0;
    int size_matr = 0;
    while (numtask != 0) {
        cout << "\n1. Input matrix\n" << "2. Print matrix\n" 
             << "3. Size of matrix\n" << "4. Trace of matrix\n"
             << "5. Determinant of matrix\n"
             << ". +=\n"<<". +\n"     << ". -=\n" << ". -\n"
             << ". * of matrices\n"   << ". * to num\n"
             << "Default: Clear screen\n" << "0. Exit\n\n";
        cin >> numtask;
        switch (numtask)
        {
        case 1:
            cout << "Enter for .input (1) or cin (2)\n";
            cin >> choise;
            if (choise == 1)
            {
                cout << "Enter size of matrix: ";
                cin >> size_matr;
                cout << "1. MatrA\n2. MatrB\n";
                cin >> choise;
                if (choise == 1)
                    MatrA.input(size_matr);
                else MatrB.input(size_matr);
            }
            else
            {
                cout << "1. MatrA\n2. MatrB\n";
                cin >> choise;
                if (choise == 1)
                    cin >> MatrA;
                else cin >> MatrB;
            }

            break;
        case 2:
            cout << "Enter for .print (1) or cout (2)\n";
            cin >> choise;
            if (choise == 1)
            {
                cout << "1. MatrA\n2. MatrB\n";
                cin >> choise;
                if (choise == 1)
                    MatrA.print();
                else MatrB.print();
            }
            else
            {
                cout << "1. MatrA\n2. MatrB\n";
                cin >> choise;
                if (choise == 1)
                    cout << MatrA;
                else cout << MatrB;
            }
            break;
        case 3:
            cout << "1. MatrA\n2. MatrB\n";
            cin >> choise;
            if (choise == 1)
                cout << MatrA.get_size() << endl;
            else cout << MatrB.get_size() << endl;
            break;
        case 4:
            cout << "1. MatrA\n2. MatrB\n";
            cin >> choise;
            if (choise == 1)
                cout << MatrA.tr() << endl;
            else cout << MatrB.tr() << endl;
            break;
        case 5:
            MatrB.det();
            break;
        case 6:
            MatrA *= MatrA;
            MatrA.print();
            break;
        case 7:
            (-MatrB).print();
            break;
        case 66:
            MatrB.ex();
            break;
        case 666:
            MatrA.check_memory();
            MatrB.check_memory();
            break;
        default: system("cls");
            break;
        }
    }

    return 0;
}

/*
+ tr(след матрицы - сумма диагональных элементов), 
+ det (определитель),
input() - запрашивает размер и элементы;
+ input(int size) - запрашивает элементы или заполняет автоматически
+ print( печать)  - как матрицу, вместе с 0
+ columns (количество столбцов), - возвращает количество столбцов
+ перегрузить операторы >> - работает как input()
+ << - работает как print
+ + поэлементное сложение матриц
+ - (бинарный) - поэлементное вычитание
- (унарный) - у ненулевых элементов меняем знак 
* бинарное - умножение матриц ("страшная формула" из лабы 3)
* бинарное - умножение на число
+ унарные операторы +=, -= изменить поэлементно текущую матрицу на матрицу - аргумент 
|1 2|         |9 8|                    |1 2|                       |1+9     2+8|
|3 4|    +=   |7 6|   =>     вместо    |3 4|    будет храниться    |3+7     4+6|
В унарных результат записывается в текущий объект, а в бинарных результат возвращаем (текущий объект не меняется).
*/