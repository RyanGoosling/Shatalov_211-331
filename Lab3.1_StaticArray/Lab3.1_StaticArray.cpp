#include <iostream>
#include <ctime>

using namespace std;

void print_mas(int temp_mas[], int n) // *temp_mas
{
    for (int i = 0; i < n; i++)
        cout << temp_mas[i] << " ";
    cout << endl;
}

void print_mas_c(char temp_mas[], int n)
{
    for (int i = 0; i < n; i++)
        cout << temp_mas[i] << " ";
    cout << endl;
}

int lesson()
{
    int n; //& - указатель на * - разыменование 
    int mas[10], mas1[10], mas2[10];
    for (int i = 0; i < 10; i++) mas[i] = i;
    int number_int = 12;
    double number_double = 123.456;
    int* ptr_number_int = &number_int; // указывает на первый бит инта
    double* ptr_number_double = &number_double;

    cout << number_int << " " << ptr_number_int << endl;
    cout << number_double << " " << ptr_number_double << endl;

    for (int i = 0; i < 10; i++)
        cout << mas[i] << " " << *(mas + i) << " " << &mas[i] << " " << mas + i << endl; //mas[0] = *mas mas[4] = *(mas+4)

    //print_mas(mas);

    return 0;
}

void buble(int arr[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void counting(char arr_c[], int n)
{
    int elements = 26, i, j = 0;
    int arr_count[26] = { 0 };
    for (i = 0; i < n; i++)
    {
        j = (arr_c[i] - 'a'); // char - char = int
        arr_count[j] += 1;
    }
    i = 0;
    j = 0;
    while (j <= elements)
    {
        if (arr_count[j] > 0)
        {
            arr_c[i] = char('a' + j);
            i++;
            arr_count[j]--;
        }
        else j++;
    }
}
//функция, сливающая массивы
void Merge(int* arr, int first_el, int last_el)
{
    int middle, start, final, i;
    int mas[1000];
    middle = (first_el + last_el) / 2; //вычисление среднего элемента
    start = first_el; //начало левой части
    final = middle + 1; //начало правой части
    for (i = first_el; i <= last_el; i++) //выполнять от начала до конца
        if ((start <= middle) && ((final > last_el) || (arr[start] < arr[final])))
        {
            mas[i] = arr[start];
            start++;
        }
        else
        {
            mas[i] = arr[final];
            final++;
        }
    //возвращение результата в список
    for (i = first_el; i <= last_el; i++) arr[i] = mas[i];
}

//рекурсивная процедура сортировки
void MergeSort(int* arr, int first_el, int last_el)
{
    {
        if (first_el < last_el)
        {
            MergeSort(arr, first_el, (first_el + last_el) / 2); //сортировка левой части
            MergeSort(arr, (first_el + last_el) / 2 + 1, last_el); //сортировка правой части
            Merge(arr, first_el, last_el); //слияние двух частей
        }
    }
}


int main()
{
    int n, arr[1000], generator_num = 1, generator_char = 1, choise = 1, i;
    char arr_c[1000];
    while (choise != 0) {
        cout << "1. Numeric array\n" << "2. Character array\n" << "0. Exit from generator\n";
        cin >> choise;
        if (choise == 0) break;
        switch (choise) {
        default: cout << "System selection - 1.\n";
        case 1: cout << "1. Random array\n" << "2. Own array\n";
            cin >> generator_num;
            switch (generator_num) {
            default: cout << "Choise of system - 1\n";
            case 1: cout << "1: ";
                cout << "Enter n\n";
                cin >> n;//рандом в плюсах псевдослучайно
                srand(time(0)); //srand() дает функции random новое начальное значение, начальную точку
                for (i = 0; i < n; i++) //ctime() возвращает указатель на строку следующего формата день месяц дата часы : минуты:секунды год
                    arr[i] = 1 + rand() % 1000;// от 1 до 1000 включительно
                print_mas(arr, n);
                break;
            case 2: cout << "2: ";
                cout << "Enter n\n";
                cin >> n;
                for (i = 0; i < n; i++)
                    cin >> arr[i];
                print_mas(arr, n);
                break;
            }
            break;
        case 2: cout << "1. Random array\n" << "2. Own array\n"; //'a' - 97, 'z' - 122 delta = 25
            cin >> generator_char;
            switch (generator_char) {
            default: cout << "Choise of system - 1\n";
            case 1: cout << "1: ";
                cout << "Enter n\n";
                cin >> n;
                srand(time(0));
                for (i = 0; i < n; i++)
                    arr_c[i] = char(97 + rand() % 25); //от 97 символа до 122 (97 + 25)
                print_mas_c(arr_c, n);
                break;
            case 2: cout << "2: ";
                cout << "Enter n\n";
                cin >> n;
                for (i = 0; i < n; i++)
                    cin >> arr_c[i];
                print_mas_c(arr_c, n);
                break;
            }
            break;
        }
    }

    int numtask = 1;
    while (numtask != 0) {
        cout << "Choose number of task\n";
        cout << "1. Task 1: Buble\n" << "2. Task 2: Couting\n" << "3. Task 3: Merge\n" << "0. Exit\n";
        cin >> numtask;
        //system("pause"); // Для продолжения...
        //system("cls"); // Чистит экран
        switch (numtask)
        {
        case 1:
            buble(arr, n);
            print_mas(arr, n);
            break;
        case 2:
            counting(arr_c, n);
            print_mas_c(arr_c, n);
            break;
        case 3:
            MergeSort(arr, 0, n - 1);
            print_mas(arr, n);
            break;
        default: return 0;
            break;
        }
    }
    return 0;
}