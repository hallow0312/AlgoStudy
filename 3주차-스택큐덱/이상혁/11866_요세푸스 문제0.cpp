#include <iostream>
#include <queue>
using namespace std;

queue<int> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		que.push(i + 1);
	}

	cout << "<";

	while (!que.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			que.push(que.front());
			que.pop();
		}

		cout << que.front();
		que.pop();

		if (!que.empty())
		{
			cout << ", ";
		}
	}

	cout << ">";
}