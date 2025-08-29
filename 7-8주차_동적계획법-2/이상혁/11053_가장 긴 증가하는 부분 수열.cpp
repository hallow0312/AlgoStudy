#include <iostream>
using namespace std;

int n;

int arr[1001] = {};
int sum[1001] = {};

int find(int target)
{
	if (target <= 0)
	{
		return 0;
	}

	if (sum[target] != 0)
	{
		return sum[target];
	}

	int temp = 1;

	for (int i = target - 1; i >= 1; i--)
	{
		if (arr[target] > arr[i])
		{
			temp = max(temp, find(i) + 1);
		}
	}

	sum[target] = temp;

	return temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int temp = find(n);

	for (int i = n - 1; i >= 1; i--)
	{
		temp = max(temp, find(i));
	}

	cout << temp << "\n";
}