#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> arr;
queue<int> index_que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b, m, c;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back({ temp,0 });

		if (temp == 0)
		{
			index_que.push(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr[i].second = temp;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;

		queue<int> check = index_que;

		while (!check.empty())
		{
			int index = check.front();
			check.pop();

			swap(temp, arr[index].second);
		}

		cout << temp << " ";
	}
}