#include <iostream>
#include <cstring>

using namespace std;

bool palindrom(char* str)
{
	int i, j, size = strlen(str);
	bool flag = false;
	for (i = 0, j = size - 1; i < j; i++, j--)
	{ //(a == a) || (A == a - char(32)) || (a - char(32) == A)
		if (((int(str[i]) >= 65) && (int(str[i]) <= 90)) || (int(str[i]) == 32))
			str[i] += char(32);
		if (((int(str[j]) >= 65) && (int(str[j]) <= 90)) || (int(str[i]) == 32))
			str[j] += char(32);
		if (str[i] == str[j])
			flag = true;
	}
	return flag;
}

void find_substring(const char * str_for_search_in, const char * substring)
{
	int i,j = 0, first_in = 0;
	int in[255] = { 0 };
	bool flag = true;
	for (i = 0; i < strlen(str_for_search_in); i++)
	{
		while ((flag)&&(j < strlen(substring)))
		{
			if (substring[j] == str_for_search_in[i + j])
			{
				if (j == 0)
					first_in = i;
				j++;
			}
			else flag = false;
		}
		if (flag)
			in[first_in] = first_in;
		j = 0;
		flag = true;
		first_in = 0;
	}
	cout << "[ ";
	for (i = 0; i < strlen(str_for_search_in); i++)
		if (in[i] != 0)
			cout << in[i] << " ";
	cout << "]\n";
}

void encrypt(char* str_for_encrypt, int key)
{
	cout << "Before: " << str_for_encrypt << endl;
	for (int i = 0; i < strlen(str_for_encrypt); i++)
		if (str_for_encrypt[i] != char(32))
			str_for_encrypt[i] += char(key);
	cout << "After: " << str_for_encrypt << endl;
}

void name(char* str_for_name)
{
	int i, count = 0;
	char name[255];
	for (i = 0; i < strlen(str_for_name); i++)
	{
		if (str_for_name[i] == char(34))
			count++;
		if ((count % 2) == 1)
			if (str_for_name[i] != char(34))
				cout << str_for_name[i];
			else cout << " ";
	}
	cout << endl;
}

int lesson()
{
	char cstr1[] = "C-style";
	char cstr2[] = { 'C', '-', 's' };
	char cstr3[] = {'\67', '\45', 'C', '-', 's'};
	char cstr4[] = "Hello World!";
	cout << cstr1<<endl;
	system("pause");
	cout <<"\nLengt" << strlen(cstr1);
	cout << "\nCompare" << strcmp(cstr1, cstr4);
	//cout << "\nCopy" << strcpy_s(cstr2,cstr1);
	cout << "\nWTF" << strstr(cstr1, "sty");
	return 0;
} //cppreference.com

int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 0, choise = 1, key = 0;
	char text[255], substring[255];
	while (choise != 0) {
		cout << "Choose number of task\n";
		cout << "11. Input string\n" << "1. Task 1: Palyndrom\n" << "2. Task 2: Find piece of string\n" << "3. Task 3: Ciesar\n" <<"4. Task 4: Name\n" << "0. Exit\n";
		cin >> choise;
		//system("pause"); // Для продолжения...
		//system("cls"); // Чистит экран
		switch (choise)
		{
		case 11:
			cin.ignore(256, '\n'); // remaining input characters up to the next newline character
								   // are ignored
			cin.getline(text, 255);
			break;
		case 1:
			if (palindrom(text)) cout << "Yes\n";
			else cout << "No\n";
			break;
		case 2:
			cout << "Input substring\n";
			cin.ignore(256, '\n');
			cin.getline(substring, 255);
			//scanf("%s", substring);
			find_substring(text, substring);
			break;
		case 3:
			cout << "Enter key = ";
			cin >> key;
			encrypt(text, key);
			break;
		case 4:
			name(text);
			break;
		default:
			break;
		}
	}
	return 0;
}
