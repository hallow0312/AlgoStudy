#include <iostream>
using namespace std;

int n;

int arr[10001] = {};
int sum[10001][3] = {};

int find(int target, int count)
{
	if (target <= 0 || count <= 0)
	{
		return 0;
	}

	if (sum[target][count] != -1)
	{
		return sum[target][count];
	}

	int temp = arr[target] + find(target - 1, count - 1);
	for (int i = target - 2; i >= 1; i--)
	{
		temp = max(temp, arr[target] + find(i, 2));
	}

	sum[target][count] = temp;

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
		sum[i][0] = -1;
		sum[i][1] = -1;
		sum[i][2] = -1;
	}

	int temp = max(find(n, 2), find(n - 1, 2));

	cout << temp << "\n";
}