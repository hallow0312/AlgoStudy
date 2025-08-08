#include <iostream>
using namespace std;

int n;

int arr[501][501] = {};
int sum[501][501] = {};

void find_max(int line, int idx)
{
	if (line < 0 || sum[line][idx] != 0)
	{
		return;
	}

	if (idx == 0)
	{
		find_max(line - 1, idx);
		sum[line][idx] = arr[line][idx] + sum[line - 1][idx];
	}
	else if (idx == line)
	{
		find_max(line - 1, idx - 1);
		sum[line][idx] = arr[line][idx] + sum[line - 1][idx - 1];
	}
	else
	{
		find_max(line - 1, idx);
		find_max(line - 1, idx - 1);
		sum[line][idx] = arr[line][idx] + max(sum[line - 1][idx], sum[line - 1][idx - 1]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> arr[i][j];
		}
	}

	sum[0][0] = arr[0][0];

	for (int i = 0; i < n; i++)
	{
		find_max(n, i);
	}

	int value = sum[n][0];
	for (int i = 1; i < n; i++)
	{
		if (sum[n][i] > value)
		{
			value = sum[n][i];
		}
	}

	cout << value << "\n";
}