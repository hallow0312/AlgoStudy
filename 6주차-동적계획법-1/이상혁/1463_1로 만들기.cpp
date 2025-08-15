#include <iostream>
using namespace std;

int n;

int arr[1000001] = {};

void find_min()
{
	for (int i = 2; i <= n; i++)
	{
		arr[i] = INT32_MAX;

		if (i % 3 == 0)
		{
			arr[i] = min(arr[i / 3] + 1, arr[i]);
		}
		if (i % 2 == 0)
		{
			arr[i] = min(arr[i / 2] + 1, arr[i]);
		}

		arr[i] = min(arr[i - 1] + 1, arr[i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	find_min();

	cout << arr[n] << "\n";
}