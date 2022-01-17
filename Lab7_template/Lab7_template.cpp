#include <iostream>
#include <string>

using namespace std;

struct pers
{
    string surname, name;
    int age;
};

bool cmp(pers& a, pers& b)
{
    if (a.surname < b.surname) return true;
    if (a.surname > b.surname) return false;
    if (a.name < b.name) return true;
    if (a.name > b.name) return false;
    return a.age < b.age;
}

template <typename T>
bool cmp(T a, T b)
{
    return a < b;
}

template <typename T>
void buble(T& arr, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (!(cmp(arr[j], arr[j + 1])))
                swap(arr[j], arr[j + 1]);
}

//template <typename T>
void qsortRecursive(pers* mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    pers mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (cmp(mas[i], mid)) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (!(cmp(mas[j], mid))) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            pers tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(&mas[i], size - i);
    }
}

pers d[] =
{
    {"White", "John", 17}, {"Brown", "Mike", 24}, {"Green", "Alex", 34}, 
    {"Red", "Josh", 15}, {"Brown", "Anna", 49}, {"Green", "Alex", 21}
};

int main()
{
    int n = 5;

    int a[5] = {1, 5, 15, 7, 8};
    buble(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    double b[5] = { 1.5, 4.8, 12.4, 10.2, 8.9 };
    buble(b, n);
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;

    char c[5] = { 'c', 'a', 'r', 't', 'u' };
    buble(c, n);
    for (int i = 0; i < n; i++) cout << c[i] << " ";
    cout << "\n\n";

    for (int i = 0; i < 6; i++)
        cout << d[i].surname << " " << d[i].name << " " << d[i].age << endl;
    cout << "\n\n";
    buble(d, 6);
    for (int i = 0; i < 6; i++)
        cout << d[i].surname << " " << d[i].name << " " << d[i].age << endl;

    return 0;
}

/*
+   на 3: быстрая сортировка любого встроенного типа данных.
    на 4: Быстрая сортировка любого встроенного типа данных и пар <Фамилия, возраст> по одному из аргументов на ваш выбор. Встроенными структурами и сортировкой пользоваться нельзя.
+-  на 5: Быстрая сортировка любого встроенного типа данных и структуры данных <Surname, Name, Age> по каждому из полей. Встроенными структурами и сортировкой пользоваться нельзя.
*/