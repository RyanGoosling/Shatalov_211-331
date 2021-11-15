#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int lesson()
{
	string str;
	fstream fs;
	fs.open("Name.txt", fstream::in | fstream::out | fstream::trunc);
	fs<<1000.15<<endl<<124<<endl<<"string <3"<<endl;
	fs.close();
	return 0;
}

string file_format_funct(const string file_path_full)
{
	int temp_find = 0;
	string format;
	for (temp_find = file_path_full.rfind(".") + 1; temp_find <= size(file_path_full); temp_find++)
		format += file_path_full[temp_find];
	return format;
}

string file_name_funct(const string file_path_full)
{
	string name;
	int temp_find_b = file_path_full.rfind(char(92)) + 1; //char(92) = \ 
	int temp_find_e = file_path_full.rfind(".");
	for (temp_find_b; temp_find_b < temp_find_e; temp_find_b++)
		name += file_path_full[temp_find_b];
	return name;
}

string file_path_funct(const string file_path_full)
{
	string path;
	for (int i = 0; i < file_path_full.rfind(char(92)); i++)
		path += file_path_full[i];
	return path;
}

char file_disk(const string file_path_full)
{
	char disk = file_path_full[0];
	return disk;
}

string file_rename(string file_path_full, string new_name)
{
	string temp;
	for (int i = 0; i < file_path_full.rfind(char(92)); i++)
		temp += file_path_full[i];
	temp += char(92) + new_name + "." + file_format_funct(file_path_full);
	return temp;
}

bool file_copy(const string file_path_full)
{
	fstream orig;
	ofstream copy;
	string temp_str, temp_path;
	orig.open(file_path_full);
	if (!orig) return false;
	temp_path = file_path_funct(file_path_full) + "\\" + file_name_funct(file_path_full) + "_copy." + file_format_funct(file_path_full);
	copy.open(temp_path);
	if (!copy) return false;
	while (getline(orig, temp_str))
	{
		copy << temp_str <<endl;
	}
	orig.close();
	copy.close();
	return true;
}

int main()
{
	int i = 0, choise = 1, temp_find = 0;
	string address, file_format, file_name, file_path, file_new_name;
	bool temp_check = true;
	while (choise != 0) {
		cout << "Choose number of task\n"; //    D:\Prog\Shatalov_331\Lab3.1_StaticArray\Lab3.1_StaticArray.cpp
		cout << "1. Task 1: File format\n" << "2. Task 2: File name\n" << "3. Task 3: File path\n" << "4. Task 4: Disk\n" 
			<<"5. Task 5: File rename\n" << "6. Task 6: Creat copy\n" << "0. Exit\n";
		cin >> choise; // D:\\Prog\\Shatalov_331\\Zaprosy_SQL_urok_1.txt
		system("pause"); // Для продолжения...
		system("cls"); // Чистит экран
		switch (choise)
		{
		case 1:
			cout << "Enter file location\n";
			cin >> address;
			cout << file_format_funct(address) << endl;
			break;
		case 2:
			cout << "Enter file location\n";
			cin >> address;
			cout << file_name_funct(address) << endl;
			break;
		case 3:
			cout << "Enter file location\n";
			cin >> address;
			cout << file_path_funct(address) << endl;
			break;
		case 4:
			cout << "Enter file location\n";
			cin >> address;
			cout << file_disk(address) << endl;
			break;
		case 5:
			cout << "Enter file location\n";
			cin >> address;
			cout << "Enter new name\n";
			cin >> file_new_name;
			cout << file_rename(address, file_new_name) << endl;
			break;
		case 6:
			cout << "Enter file location using double \\ \n";
			cin >> address;
			temp_check = file_copy(address);
			if (temp_check == false)
				cout << "Error copy\n";
			break;
		default:
			break;
		}
	}
	return 0;
}

//последняя точка
//между посл / и точкой
//вернуть до последнего /
//1 символ
//вытащить с начало до посл / + новое имя + .спп
//Rfind первое вх с конца (отсчёт от 0 до н)
//find_first_of 1 вхождение одного из символа подстроки
//in ввод out вывод app запись в конце trunc перезапись файла
//расположение(полный путь) + "\" + имя(полный путь) + "_copy." + расширение 

