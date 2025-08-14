#include <iostream>
using namespace std;

int n;

int arr[100001] = {};

int find(int target)
{
	int value = INT32_MIN;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = max(arr[i - 1] + arr[i], arr[i]);
		value = max(arr[i], value);
	}

	return value;
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

	cout << find(n) << "\n";
}