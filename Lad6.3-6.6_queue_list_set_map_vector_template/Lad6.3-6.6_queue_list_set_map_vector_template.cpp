#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <unordered_set>
#include <set>
#include <string>
#include <fstream>

using namespace std;

void task_queue()
{
	//Напечатать в порядке возрастания первые n натуральных чисел, в разложение которых на простые множители входят только 2, 3 и 5.

	deque<int> q2 = { 2 }, q3 = { 3 }, q5 = { 5 };
	int n, res;
	cout << "Enter n: ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		
		res = min(q2.front(), min(q3.front(), q5.front()));

		cout << res << " ";

		q2.push_back(2 * res);
		q3.push_back(3 * res);
		q5.push_back(5 * res);

		if (res == q2.front())
			q2.pop_front();
		if (res == q3.front())
			q3.pop_front();
		if (res == q5.front())
			q5.pop_front();
	} 

	cout << endl<<endl;

	/*queue<int> myqueue;
	myqueue.push(45);
	myqueue.push(5);
	myqueue.push(65);
	myqueue.push(49);

	cout << "\nmyqueue.size() = " << myqueue.size();
	cout << "\nmyqueue.front() = " << myqueue.front();
	cout << "\nmyqueue.back() = " << myqueue.back();
	myqueue.pop();
	cout << "\nmyqueue.front() = " << myqueue.front();*/
	//for (const auto& int : myqueue) //итератор отсутствует, можно вывести только первый элемент
	   // cout << "D";
}

void task_set() //5 2 3 7 5
{
	/*
	Преподаватель на экзамене дал студентам тест. Один из студентов решил узнать правильные ответы. 
	Для этого он отправлял тест много раз с нескольких аккаунтов. Преподаватель решил это пресечь. 
	Для этого преподаватель не стал засчитывать результаты теста, отправленного повторно с одного и того же аккаунта. 
	Нужно автоматизировать этот процесс. 
	Вход: ФИ + балл
	*/

	set<pair<string, int>> res;
	int n, score;
	bool flag = true;
	string name;
	cout << "Enter number: ";
	cin >> n;
	cout << "Enter result:\n";
	for (int i = 0; i < n; i++)
	{
		flag = true;
		cin >> name >> score;
		for (auto it = res.begin(); it != res.end(); it++)
			if (it->first == name)
				flag = false;
		if (flag)
			res.insert(pair<string, int>(name,score));
	}
	
	cout << endl;

	for (auto it = res.begin(); it != res.end(); it++)
		cout << it->first << " " <<it->second<< endl;

	/*set<int> myset; //автоматически сортирует повозрастанию только уникальные
	myset.insert(78);
	myset.insert(797);
	myset.insert(569);
	myset.insert(78);

	for (auto it = myset.begin(); it != myset.end(); it++)
		cout << *it << " " << endl;*/

}

void task_list()
{
	/*
	На вход подается список студентов в формате <номер группы> <пробел> <Фамилия>. 
	Нужно вывести список студентов по группам, причем в том порядке, как они были записаны в исходном списке. 
	*/
	/*list<int> mylist;
	mylist.push_back(64);
	mylist.push_back(51);
	mylist.push_back(236);
	mylist.insert(mylist.begin()++, 887);
	
	for (auto it = mylist.begin(); it != mylist.end(); it++)
		cout << *it << " " << endl;*/

	list<pair<int, string>> ex;
	string last_name;
	int group, n;
	cout << "Enter number: ";
	cin >> n;
	cout << "Enter list of students:\n";

	for (int i = 0; i < n; i++)
	{
		cin >> group >> last_name;
		ex.emplace_back(pair<int, string>(group, last_name));
	}

	for (auto it = ex.begin(); it != ex.end(); it++)
		cout << it->first << " " <<it->second<< endl;
}

string ign(string word)
{
	char symbol[10] = { ',', '.', '!', '?', ';', ':', '%','(', ')', '\"'};

	for (int j = 0; j < 10; j++)
		if (word.find(symbol[j]) != -1)
			word.erase(word.find(symbol[j]), 1);

	return word;
}

void task_map()
{
	/*
	Подсчет количества слов в тексте и вывод частоты их встречи в процентном соотношении 
	(подсчет частоты встречи слов в тексте в процентах).
	*/

	string word;
	ifstream text;
	text.open("text.txt");
	map<string, double> counter;
	int n = 0;

	word = "das,dsa!lfds";

	//cout << ign(word) << endl;

	if (!text)
		cout << "Error";

	while (text>>word)
	{
		counter[ign(word)]++;
		n++;
	}
	for (auto it = counter.begin(); it != counter.end(); it++)
		cout << it->first << "\t\t" << round(it->second / n * 10000) / 100 << "%\n";
	
	text.close();
	/*map<string, int> mymap;
	mymap.emplace(pair<string, int>("Ivan", 1991));
	mymap.emplace(pair<string, int>("Petr", 1998));
	mymap["Fedr"] = 2001;
	for (auto it = mymap.begin(); it != mymap.end(); it++)
		cout << it->first << " " <<it->second<< endl;
	string temp;
	cin >> temp;
	mymap[temp] += 5;
	for (auto it = mymap.begin(); it != mymap.end(); it++)
		cout << it->first << " " << it->second << endl;*/
}

template<typename TypesOfCPP>
void printvec(vector<TypesOfCPP> vec)
{
	for (int i = 0; i != vec.size(); i++)
		cout << " " << vec[i].first << " " << vec.at(i).second<<endl;
}

void task_vector()
{
	vector<pair<int, int>> coord;
	//coord.reserve(5);
	//coord[2] = pair<int, int>(2, 7);
	coord.push_back(pair<int, int>(2, 7));
	coord.push_back(pair<int, int>(5, 1));
	coord.push_back(pair<int, int>(2, 9));
	printvec(coord);
}

int main()
{
	int numtask = 1;
	while (numtask != 0)
	{
		cout << "1. Queue\n2. Set\n3. List\n4. Map\n0. Exit\n";
		cin >> numtask;
		cout << endl;
		switch (numtask)
		{
		case 1: task_queue();
			break;

		case 2: task_set();
			break;

		case 3: task_list();
			break;

		case 4: task_map();
			break;

		default: system("cls");
			break;
		}
	}
	//task_vector();
	return 0;;
}