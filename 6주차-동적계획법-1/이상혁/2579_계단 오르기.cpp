#include <iostream>
using namespace std;

int n;
int score[300] = {};
int sum[300][3] = {};

int find_max(int target, int count)
{
	if (target < 0 || count <= 0)
	{
		return 0;
	}

	if (sum[target][count] != 0)
	{
		return sum[target][count];
	}

	sum[target][count] = score[target] + max(find_max(target - 1, count - 1), find_max(target - 2, 2));

	return sum[target][count];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}

	sum[0][0] = score[0];
	sum[0][1] = score[0];
	sum[0][2] = score[0];

	cout << find_max(n - 1, 2) << "\n";
}