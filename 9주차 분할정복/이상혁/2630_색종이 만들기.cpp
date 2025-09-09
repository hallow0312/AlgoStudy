#include <iostream>
using namespace std;

int n;

int arr[129][129] = {};

int white = 0, black = 0;

void divide(int x, int y, int size)
{
	if (size <= 0)
	{
		return;
	}

	int target = arr[x][y];

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (arr[i][j] == target)
			{
				continue;
			}

			divide(x, y, size / 2);
			divide(x + size / 2, y, size / 2);
			divide(x, y + size / 2, size / 2);
			divide(x + size / 2, y + size / 2, size / 2);

			return;
		}
	}

	if (target == 0)
	{
		white++;
	}
	else
	{
		black++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	divide(1, 1, n);

	cout << white << "\n" << black << "\n";
}