#include <iostream>
#include <stack>
#include <string>

using namespace std;


 //last in — first out, «последним пришёл — первым ушёл»

 /*дано 1 + 5 * 4 - 3
 обр нотация 1 5 4 * + 3 -
 stack<int> st;
	//push - готовый empalce созадает 
	st.push(12);
	st.push(-22);
	st.emplace(152);
	st.push(312);
	// 12 <- -22 <- 152 <- 312
	
	cout <<"st.top = "<< st.top()<<endl;
	cout << "st.size = " << st.size() << endl;
	st.pop();
	cout << "st.top after pop = " << st.top() << endl;
	cout << "st.empty = " << st.empty() << endl;
	stack<int> st2;
	st2 = st;
	st2.pop();
	st2.push(-32);
	cout << (st < st2);
	*/

int main()
{
	bool flag = true;
	stack<char> exp; //expression
	string orig;
	cout << "Enter expression:\n";
	cin >> orig;
	for (int i = 0; i < orig.size(); i++)
	{
		if ((orig[i] == '(') or (orig[i] == '{') or (orig[i] == '['))
			exp.push(orig[i]);
		else 
		{
			if (orig[i] == ')')
				if (exp.top() == '(')
					exp.pop();
				else
				{
					flag = false;
					break;
				}

			if (orig[i] == ']')
				if (exp.top() == '[')
					exp.pop();
				else 
				{
					flag = false;
					break;
				}

			if (orig[i] == '}')
				if (exp.top() == '{')
					exp.pop();
				else 
				{
					flag = false;
					break;
				}
		}
	}
	if (flag)
		cout << "\nYes\n";
	else cout << "\nNo\n";

	return 0;
}
