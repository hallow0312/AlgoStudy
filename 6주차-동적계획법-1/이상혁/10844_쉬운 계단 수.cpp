#include <iostream>
using namespace std;

int n;

int arr[101][10] = {};

int find(int target)
{
	for (int i = 2; i <= target; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				arr[i][j] = arr[i - 1][j + 1] % 1000000000;
			}
			else if (j == 9)
			{
				arr[i][j] = arr[i - 1][j - 1] % 1000000000;
			}
			else
			{
				arr[i][j] = arr[i - 1][j - 1] % 1000000000 + arr[i - 1][j + 1] % 1000000000;
			}
		}
	}

	int value = 0;
	for (int i = 0; i <= 9; i++)
	{
		value += (arr[target][i]) % 1000000000;
		value %= 1000000000;
	}

	return value;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= 9; i++)
	{
		arr[1][i] = 1;
	}

	cout << find(n) % 1000000000 << "\n";
}