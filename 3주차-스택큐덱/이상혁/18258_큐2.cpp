#include <iostream>
#include <queue>
using namespace std;

queue<int> que;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		if (temp == "push")
		{
			int push_int;
			cin >> push_int;
			que.push(push_int);
		}
		else if (temp == "pop")
		{
			if (!que.empty())
			{
				cout << que.front() << "\n";
				que.pop();
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (temp == "size")
		{
			cout << que.size() << "\n";
		}
		else if (temp == "empty")
		{
			if (que.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (temp == "front")
		{
			if (!que.empty())
			{
				cout << que.front() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (temp == "back")
		{
			if (!que.empty())
			{
				cout << que.back() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
	}
}

int main()
{
	input();
}