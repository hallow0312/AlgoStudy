#include <iostream>
using namespace std;

int n;

int arr[1001] = {};
int sum[1001][2] = {};

int find_front(int target)
{
	if (target <= 0)
	{
		return 0;
	}

	if (sum[target][0] != 0)
	{
		return sum[target][0];
	}

	int temp = 1;

	for (int i = target - 1; i >= 1; i--)
	{
		if (arr[target] > arr[i])
		{
			temp = max(temp, find_front(i) + 1);
		}
	}

	sum[target][0] = temp;

	return temp;
}

int find_back(int target)
{
	if (target > n)
	{
		return 0;
	}

	if (sum[target][1] != 0)
	{
		return sum[target][1];
	}

	int temp = 1;

	for (int i = target + 1; i <= n; i++)
	{
		if (arr[target] > arr[i])
		{
			temp = max(temp, find_back(i) + 1);
		}
	}

	sum[target][1] = temp;

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

	int temp = 0;

	for (int i = 1; i <= n; i++)
	{
		temp = max(temp, find_front(i) + find_back(i) - 1);
	}

	cout << temp << "\n";
}