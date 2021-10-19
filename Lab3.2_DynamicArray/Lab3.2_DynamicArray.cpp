#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

void input_mas(int*& temp_mas, int& size)
{
    cout << "Input size of array.\n";
    cin >> size;
    if (temp_mas != nullptr)
        delete[] temp_mas;

    temp_mas = new int[size];
    srand(time(0));
    for (unsigned int i = 0; i < size; i++)
        //cin >> temp_mas[i];
        temp_mas[i] = 1 + rand() % 1000;
}

void print_mas(int* temp_mas, int size)
{
    for (int i = 0; i < size; i++)
        cout << temp_mas[i] << " ";
    cout << endl;
}

int sum(int x)
{
    int sum = 0,temp_x = x, i = 0, count = 0,coef;
    while (temp_x > 0) 
    {
        count++;
        temp_x /= 10;
    }
    count--; //before 1 - n, after 0 - (n-1)
    coef = count % 2;
    while (x > 0)
    {
        if ((i % 2) == coef)
        {
            sum += x % 10;
        }
        i++;
        x /= 10;
    }
    return sum;
}

void buble(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size - i - 1; j++)
            if (sum(arr[j]) > sum(arr[j + 1]))
                swap(arr[j], arr[j + 1]);
}

void last_digit(int arr[], int size)
{
    int i, j, tmp;
    for (i = 0; i < size; i++)
        for (j = 0; j < size - i - 1; j++) 
        {
            if ((arr[j] % 10) > (arr[j + 1] % 10))
                swap(arr[j], arr[j + 1]);
            if (((arr[j] % 10) == (arr[j + 1] % 10)) && (arr[j] < arr[j + 1]))
                swap(arr[j], arr[j + 1]);
        }
}

bool comp(const int& a, const int& b) 
{
    if (a % 10 == b % 10) return (a > b);
    else return a % 10 < b % 10;
}

int main()
{
    int* mas = nullptr; //нулевой указатель
    int size_of_mas = 0;
    //mas = new int[size_of_mas]; //выделение памяти
    int numtask = 1;
    while (numtask != 0) {
        cout << "Choose number of task\n";
        cout << "1. Task 1: Input array\n" << "2. Task 2: Output array\n" << "3. Task 3: Sort parity\n"<< "4. Task 4: Sort by last digit\n" << "0. Exit\n";
        cin >> numtask;
        //system("pause"); // Для продолжения...
        //system("cls"); // Чистит экран
        switch (numtask)
        {
        case 1:
            input_mas(mas, size_of_mas);
            //print_mas(mas, size_of_mas);
            break;
        case 2:
            print_mas(mas, size_of_mas);
            break;
        case 3:
            buble(mas, size_of_mas);
            break;
        case 4: 
            last_digit(mas, size_of_mas);
            //sort(mas, mas + size_of_mas, comp);//(array, array + last index, operator true or false)
            //print_mas(mas, size_of_mas);
            break;
        default: 
            break;
        }
    }
    delete[] mas; // освобождение памяти
    return 0;
}