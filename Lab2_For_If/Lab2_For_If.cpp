#include <iostream>
using namespace std;

 unsigned long long fact(int n)
{
    if (n == 0) return 1;
    return n * fact(n - 1);
}

void task1()
{
    cout << "Task 1\n";
    cout << "n = ";
    int i, n, j;
    cin >> n;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= i; j++) cout << j;
        cout << endl;
    }
}

void task2()
{
    cout << "Task 2\n"; 
    unsigned long long res = 1, k = 1, n;
    cout << "n = ";
    cin >> n;
    switch (n)
    {
    case 0: cout << 1 << endl;
        break;
    case 1: cout << 1 << " " << 1 << endl;
        break;
    default: 
        cout << 1 << "   ";
        for (k = 1; k <= n; k++)
        {
            res = (res * (n - k + 1)) / k;
            //res = res * ((n - (k-1)) / (k));
            cout << res << "   ";
        }
        cout << endl;
        break;
    }

   /* for (k = 0; k <= n; k++)
    {
        cout << (fact(n) / (fact(n - k) * fact(k)))<<"  "; //фаткориал не идеален
    }
    cout << endl;*/
}

void task3()
{
    double sum=0, x=0, count=0;
    cout << "Enter negative number to exit\n";
    cout << "Enter numbers\n";
    while (x!=-1)  //-1 не символ
    {
        cin >> x;
        if (x > 0)
        {
            sum += x;
            count++;
        }
        else break;
    }
    cout << "Average = " << sum / (count) << endl;
}


int main()
{
    int numtask = 1;
    while (numtask != 0) {
        cout << "Choose number of task\n" ;
        cout << "1. Task 1\n" << "2. Task 2\n" << "3. Task 3\n" << "0. Exit\n";
        cin >> numtask;
        system("pause"); // Для продолжения...
        system("cls"); // Чистит экран
        switch (numtask)
        {
        //case 0: break;
        case 1:
            task1();
            break;
        case 2: 
            task2();
            break;
        case 3:
            task3();
            break;
        default: return 0;
            break;
        }
    }
    return 0;
}