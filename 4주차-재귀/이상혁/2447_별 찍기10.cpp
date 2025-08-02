#include <iostream>
using namespace std;

int n;
string* arr;

void remove(int len, int x, int y)
{
	if (len == 1)
	{
		return;
	}

	int length = len / 3;
	int idx_x = x + length;
	int idx_y = y + length;

	for (int i = idx_x; i < idx_x + length; i++)
	{
		for (int j = idx_y; j < idx_y + length; j++)
		{
			arr[i][j] = ' ';
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			remove(length, x + (i * length), y + (j * length));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	arr = new string[n];

	for (int i = 0; i < n; i++)
	{
		arr[i].insert(0, n, '*');
	}

	remove(n, 0, 0);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}
}