#include <iostream>
using namespace std;

int k, n;
int arr[10000] = {};

long long max_value = 0;

void bs(long long start, long long end)
{
	if (start > end)
	{
		return;
	}

	long long mid = (start + end) / 2;
	long long sum = 0;

	for (int i = 0; i < k; i++)
	{
		sum += arr[i] / mid;
	}

	if (sum < n)
	{
		bs(start, mid - 1);
	}
	else
	{
		max_value = max(max_value, mid);
		bs(mid + 1, end);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k >> n;

	long long sum = 0;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	long long end = sum / n;

	bs(1, end);

	cout << max_value << "\n";
}