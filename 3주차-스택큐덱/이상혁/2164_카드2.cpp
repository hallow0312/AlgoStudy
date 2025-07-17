#include <iostream>
#include <queue>
using namespace std;

queue<int> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		que.push(i + 1);
	}

	int last;
	bool is_push = false;

	while (!que.empty())
	{
		last = que.front();

		if (is_push)
		{
			que.push(que.front());
			que.pop();
		}
		else
		{
			que.pop();
		}

		is_push = !is_push;
	}

	cout << last << "\n";
}