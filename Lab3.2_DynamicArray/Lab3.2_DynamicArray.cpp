#include <iostream>

using namespace std;

void input_mas(int*& temp_mas, int& size)
{
    cin >> size;
    if (temp_mas != nullptr)
        delete[] temp_mas;

    temp_mas = new int[size];

    for (unsigned int i = 0; i < size; i++)
        cin >> temp_mas[i];
}

void print_mas(int* temp_mas, int size)
{
    for (int i = 0; i < size; i++)
        cout << temp_mas[i] << " ";
    cout << endl;
}

int main()
{
    int* mas = nullptr; //нулевой указатель
    int size_of_mas = 0;
    //cin >> size_of_mas;
    input_mas(mas, size_of_mas);
    //mas = new int[size_of_mas]; //выделение памяти

    //for (unsigned int i = 0; i < 10; i++)
      //cin >> mas[i];

    print_mas(mas, size_of_mas);
    delete[] mas; // освобождение памяти
    return 0;
}