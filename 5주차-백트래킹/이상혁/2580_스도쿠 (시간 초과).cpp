#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int zero_count = 0;

int arr[9][9];

int start_index(int value)
{
	switch (value % 3)
	{
	case 0:
		return value;
	case 1:
		return value - 1;
	case 2:
		return value - 2;
	}
}

int insert_sdc(int x, int y)
{
	int return_value = 0;

	vector<int> garo, sero;

	for (int i = 0; i < 9; i++)
	{
		garo.push_back(arr[x][i]);
		sero.push_back(arr[i][y]);
	}

	sort(garo.begin(), garo.end());
	sort(sero.begin(), sero.end());

	int target = 1;

Restart:

	for (target; target <= 9; target++)
	{
		if (!binary_search(garo.begin(), garo.end(), target) &&
			!binary_search(sero.begin(), sero.end(), target))
		{
			return_value = target;
			break;
		}
	}

	int start_x = start_index(x);
	int start_y = start_index(y);

	for (int i = start_x; i < start_x + 3; i++)
	{
		for (int j = start_y; j < start_y + 3; j++)
		{
			if (arr[i][j] == return_value)
			{
				target++;
				goto Restart;
			}
		}
	}

	return return_value;
}

void sdc_batch()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (zero_count == 0)
			{
				return;
			}

			if (arr[i][j] != 0)
			{
				continue;
			}

			arr[i][j] = insert_sdc(i, j);
			zero_count--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 0)
			{
				zero_count++;
			}
		}
	}

	sdc_batch();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}