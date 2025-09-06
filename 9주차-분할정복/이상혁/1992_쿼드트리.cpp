#include <iostream>
using namespace std;

int n;

string arr[65];

void divide(int x, int y, int size)
{
	if (size <= 0)
	{
		return;
	}

	char target = arr[x][y];

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (arr[i][j] == target)
			{
				continue;
			}

			cout << "(";

			divide(x, y, size / 2);
			divide(x, y + size / 2, size / 2);
			divide(x + size / 2, y, size / 2);
			divide(x + size / 2, y + size / 2, size / 2);

			cout << ")";

			return;
		}
	}

	cout << target;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	divide(0, 0, n);
}