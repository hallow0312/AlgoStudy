#include <iostream>
#include <stack>
using namespace std;

bool check_ghwalho(string temp)
{
	stack<char> stk;

	for (char i : temp)
	{
		if (i == '(')
		{
			stk.push('(');
		}
		else if (i == ')')
		{
			if (stk.empty())
			{
				return false;
			}
			stk.pop();
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

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string temp;
		cin >> temp;
		if (check_ghwalho(temp))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}

int main()
{
	input();
}