#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int n, m;

queue<int> que;
deque<int> dq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			que.push(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (!que.empty() && que.front() == i)
		{
			dq.push_front(temp);
			que.pop();
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		dq.push_back(temp);
		cout << dq.front() << " ";
		dq.pop_front();
	}
}