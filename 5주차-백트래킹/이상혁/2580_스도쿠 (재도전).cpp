#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> zero_pos;

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

bool check_can_insert(int x, int y, int target)
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[x][i] == target || arr[i][y] == target)
		{
			return false;
		}
	}

	int start_x = start_index(x);
	int start_y = start_index(y);

	for (int i = start_x; i < start_x + 3; i++)
	{
		for (int j = start_y; j < start_y + 3; j++)
		{
			if (arr[i][j] == target)
			{
				return false;
			}
		}
	}

	return true;
}

void sdc_batch(int idx)
{
	if (idx == zero_pos.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}

		exit(0);
	}

	int x = zero_pos[idx].first;
	int y = zero_pos[idx].second;

	for (int i = 1; i <= 9; i++)
	{
		if (check_can_insert(x, y, i))
		{
			arr[x][y] = i;
			sdc_batch(idx + 1);
			arr[x][y] = 0;
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
				zero_pos.push_back({ i,j });
			}
		}
	}

	sdc_batch(0);
}