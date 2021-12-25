#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

bool palindrom(string word)
{
	bool flag = true;
	deque<char> pal;

	for (int i = 0; i < word.size(); i++)
		pal.push_back(word[i]); //ввод слова побуквенно 

	while (pal.size() > 1)
	{
		if (pal.front() == pal.back())
		{
			pal.pop_back();
			pal.pop_front();
		}
		else
		{
			flag = false;
			break;
		}
		
	}

	/*cout << endl;
	deque<char>::const_iterator iter;
	for (iter = pal.begin(); iter != pal.end(); iter++)
		cout << *iter << " ";
	cout << endl;*/

	return flag;
}

struct point 
{
	double x, y;
};

bool cmp(point A, point B) //компаратор для сортировки точек слева направо
{
	return A.x < B.x || A.x == B.x && A.y < B.y;
}

bool cw(point A, point B, point C)  //clockwise - по часовой стрелке
{
	return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x) < 0; // (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x)    A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)
}

bool ccw(point A, point B, point C) //counterclockwise - против чаосовой стрелке
{
	return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x) > 0;
}

void convex_hull(deque<point>& A) 
{
	if (A.size() == 1)  return;

	sort(A.begin(), A.end(), &cmp); //слева направо с увеличением у

	point p1 = A[0], p2 = A.back();
	deque<point> up, down;
	up.push_back(p1);
	down.push_back(p1);

	for (unsigned int i = 1; i < A.size(); ++i) 
	{
		if (i == A.size() - 1 || cw(p1, A[i], p2)) 
		{
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], A[i]))
				up.pop_back();
			up.push_back(A[i]);
		}
		if (i == A.size() - 1 || ccw(p1, A[i], p2)) 
		{
			while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], A[i]))
				down.pop_back();
			down.push_back(A[i]);
		}
	}
	A.clear();

	for (size_t i = 0; i < up.size(); ++i)
		A.push_back(up[i]);
	for (size_t i = down.size() - 2; i > 0; --i)
		A.push_back(down[i]);
}

/*
1 4
2 7
4 7
7 4
5 1
2 2

3 4 
5 4
*/

int main()
{
	
	int numtask = 1, n, x, y;
	deque<point> pts;
		/*= {
		{2, 2},
		{3, 4},
		{1, 4},
		{2, 7},
		{4, 7},
		{5, 4},
		{5, 1},
		{7, 4}
	}*/
	point temp;
	string orig;

	while (numtask != 0)
	{
		cout << "1. Palindrom\n2. Convex hull\n0. Exit\n";
		cin >> numtask;
		cout << endl;
		switch (numtask)
		{
		case 1:
			cin >> orig;
			if (palindrom(orig))
				cout << "Yes\n\n";
			else cout << "No\n\n";
			break;

		case 2: 
			cout << "Enter number of points:\n";
			cin >> n;
			cout << "Enter coordinate of points:\n";
			for (int i = 0; i < n; i++)
			{
				cin>>x>>y;
				temp.x = x;
				temp.y = y;
				pts.emplace_back(temp);
			}

			convex_hull(pts);
			cout << "\nConvex hull:\n";
			for (const auto& point : pts) //const auto& автоматически заменяет расписывание итератора easy-to-write метод
				cout << point.x << " " << point.y << endl;
			cout << endl;
			break;
		default: //system("cls");
			break;
		}
	}
	
	return 0;
}











int lesson()
{
	int n;
	char command; //+-*
	int name;
	deque<int> queue;
	cin >> n;

	while (n > 0)
	{
		cin >> command;
		switch (command)
		{
		case '-':
			cout << queue.front()<<" ";
			queue.pop_front();
			n--;
			break;
		case '+':
			cin >> name;
			queue.push_back(name);
			n--;
			break;
		case '*':
			cin >> name;
			queue.insert(queue.begin() + (queue.size() / 2 + (queue.size() % 2)), name);
			// begin - указатель начала, size - размер 
			n--;
			break;
		default:
			break;
		}
	}
	cout << endl;
	deque<int>::const_iterator iter;
	for (iter = queue.begin(); iter != queue.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	return 0;
}

/*
Гоблины Мглистых гор очень любях ходить к своим шаманам.
Так как гоблинов много, к шаманам часто образуются очень
длинные очереди. А поскольку много гоблинов в одном месте
быстро образуют шумную толку, которая мешает шаманам
проводить сложные медицинские манипуляции, последние решили
установить некоторые правила касательно порядка в очереди.
Обычные гоблины при посещении шаманов должны вставать
в конец очереди. Привилегированные же гоблины, знающие
особый пароль, встают ровно в ее середину, причем при
нечетной длине очереди они встают сразу за центром.
Так как гоблины также широко известны своим
непочтительным отношением ко всяческим правилам и законам,
шаманы попросили вас написать программу, которая бы
отслеживала порядок гоблинов в очереди.
*/
//Входные 7 + 1 + 2 - + 3 * 4 - -;
/*
7 команд
+ 1 обычный 1й пришел 1
+ 2 обычный 2й пришёл 1 2
-   гоблин     вышел  2
+ 3 обычный 3й пришёл 2 3
* 4 привлег 4й пришёл 2 4 3
-  вышел 4 3
-  вышел 3
Выходные данные - кто вышел из очереди по порядку
1 2 4
*/