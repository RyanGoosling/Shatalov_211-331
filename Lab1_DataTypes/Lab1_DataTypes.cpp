#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    //task 1
    cout << "1. \n";
    cout << "Shatalov Vadim Pavlovich 211-331\n";
    
    //task 2
    cout << "\n2. \n";
    cout << "size of int = " << sizeof(int)
         << ", min int = " << int(0b10000000000000000000000000000000) 
         << ", max int = " << 0b01111111111111111111111111111111;

    cout << ". \n \n size of unsigned = " << sizeof(unsigned int)
         << ", min unsigned = " << 0 
         << ", max unsigned = " << 0b11111111111111111111111111111111;

    cout << ". \n \n size of short = " << sizeof(short)
         << ", min short = " << short(0b1000000000000000) 
         << ", max short = " << 0b111111111111111;

    cout << ". \n \n size of unsigned short = " << sizeof(short)
         << ", min unsigned short = " << 0 
         << ", max unsigned short = " << 0b1111111111111111;

    cout << ". \n \n size of long = " << sizeof(long)
         << ", min long = " << int(0b10000000000000000000000000000000) 
         << ", max long = " << 0b01111111111111111111111111111111;

    cout << ". \n \n size of long long = " << sizeof(long long)
         << ", min long long = " << long long(0b1000000000000000000000000000000000000000000000000000000000000000)
         << ", max long long = " << long long(0b111111111111111111111111111111111111111111111111111111111111111);

    cout << ". \n \n size of double = " << sizeof(double)
        << ", min double = " << long long(0b1000000000000000000000000000000000000000000000000000000000000000)
        << ", max double = " << long long(0b111111111111111111111111111111111111111111111111111111111111111); //т. к. на double приходится равное кол-во байт как и на long long

    cout << ". \n \n size of char = " << sizeof(char)
         << ", min char = " << 0 << ", max shar = " << 0b11111111;

    cout << ". \n \n size of bool = " << sizeof(bool);
    cout << ", min bool = " << 0 << ", max bool = " << 0b11111111 <<". \n";

    //task 3
    cout << "\n3. \n";
    int n;
    cout << "Enter an integer \n";
    cin >> n;
    cout << "Binary: " << bitset<8 * sizeof(n)>(n) << endl;
    cout << "Hex: " << hex << n << dec << endl;
    cout << "Bool: " << bool(n) << endl;
    cout << "Double: " << double(n) << endl;
    cout << "Char: " << char(n) << endl;

    //task 4
    cout << "\n4. \n";
    double a, b;
    cout << "Enter odds: \n";
    cin >> a >> b;
    cout << a << " * x = " << b << "\nx = " << b << " / " << a;
    cout << "\nx = " << b / a << "\nAnswer: " << b / a;
    
    //task 5
    double x, y;
    cout << "\n\n5. \n";
    cout << "Enter the coordinates of a line segment:\n";
    cin >> x >> y;
    cout << "The middle of the segment is at the point with the coordinate: " << (x + y) / 2;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
