#include <iostream>
using namespace std;

int n;

int arr[15] = { -1, };

int total = 0;

bool check_queen(int idx, int value)
{
	for (int i = 0; i < idx; i++)
	{
		if (arr[i] == value || abs(arr[i] - value) == abs(i - idx))
		{
			return false;
		}
	}

	if (idx == n - 1)
	{
		total++;
	}

	return true;
}

void queen_batch(int idx)
{
	for (int i = 0; i < n; i++)
	{
		if (check_queen(idx, i))
		{
			arr[idx] = i;
			queen_batch(idx + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	queen_batch(0);

	cout << total << "\n";
}