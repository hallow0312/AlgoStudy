#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool check(string temp)
{
	stack<char> stk;

	for (char i : temp)
	{
		if (i == '(' || i == '[')
		{
			stk.push(i);
		}
		else if (i == ')')
		{
			if (!stk.empty() && stk.top() == '(')
			{
				stk.pop();
			}
			else
			{
				return false;
			}
		}
		else if (i == ']')
		{
			if (!stk.empty() && stk.top() == '[')
			{
				stk.pop();
			}
			else
			{
				return false;
			}
		}
	}

	if (!stk.empty())
	{
		return false;
	}

	return true;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		string temp;
		getline(cin, temp);

		if (temp == ".")
		{
			break;
		}

		if (check(temp))
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
}

int main()
{
	input();
}