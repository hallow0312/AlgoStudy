#include <iostream>
#include <string>
using namespace std;

int n;

string arr[2187];

int zero = 0, one = 0, two = 0;

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

			divide(x, y, size / 3);
			divide(x, y + size / 3, size / 3);
			divide(x, y + size / 3 * 2, size / 3);

			divide(x + size / 3, y, size / 3);
			divide(x + size / 3, y + size / 3, size / 3);
			divide(x + size / 3, y + size / 3 * 2, size / 3);

			divide(x + size / 3 * 2, y, size / 3);
			divide(x + size / 3 * 2, y + size / 3, size / 3);
			divide(x + size / 3 * 2, y + size / 3 * 2, size / 3);

			return;
		}
	}

	switch (target)
	{
	case '0':
		zero++;
		break;

	case '1':
		one++;
		break;

	case '2':
		two++;
		break;
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
		string value;

		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			value += to_string(temp + 1)[0];
		}

		arr[i] = value;
	}

	divide(0, 0, n);

	cout << zero << "\n" << one << "\n" << two << "\n";
}