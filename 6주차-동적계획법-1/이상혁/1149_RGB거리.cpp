#include <iostream>
using namespace std;

int n;

int arr[1000][3] = {};
int rgb[1000][3] = {};

void find_min(int target, int color)
{
	if (target < 0 || arr[target][color] != 0)
	{
		return;
	}

	switch (color)
	{
	case 0:
		find_min(target - 1, 1);
		find_min(target - 1, 2);
		arr[target][color] = rgb[target][color] + min(arr[target - 1][1], arr[target - 1][2]);
		break;

	case 1:
		find_min(target - 1, 0);
		find_min(target - 1, 2);
		arr[target][color] = rgb[target][color] + min(arr[target - 1][0], arr[target - 1][2]);
		break;

	case 2:
		find_min(target - 1, 0);
		find_min(target - 1, 1);
		arr[target][color] = rgb[target][color] + min(arr[target - 1][0], arr[target - 1][1]);
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
		for (int j = 0; j < 3; j++)
		{
			cin >> rgb[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		arr[0][i] = rgb[0][i];
	}

	for (int i = 0; i < 3; i++)
	{
		find_min(n - 1, i);
	}

	int value = INT32_MAX;

	for (int i = 0; i < 3; i++)
	{
		if (arr[n - 1][i] < value)
		{
			value = arr[n - 1][i];
		}
	}

	cout << value << "\n";
}