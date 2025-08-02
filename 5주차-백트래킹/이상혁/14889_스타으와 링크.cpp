#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int min_v = INT32_MAX;

int arr[21][21] = {};

vector<int> sunsu1;

void calc()
{
	vector<int> sunsu2;

	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < sunsu1.size(); i++)
	{
		for (int j = i + 1; j < sunsu1.size(); j++)
		{
			sum1 += arr[sunsu1[i]][sunsu1[j]] + arr[sunsu1[j]][sunsu1[i]];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!binary_search(sunsu1.begin(), sunsu1.end(), i))
		{
			sunsu2.push_back(i);
		}
	}

	for (int i = 0; i < sunsu2.size(); i++)
	{
		for (int j = i + 1; j < sunsu2.size(); j++)
		{
			sum2 += arr[sunsu2[i]][sunsu2[j]] + arr[sunsu2[j]][sunsu2[i]];
		}
	}

	if (abs(sum1 - sum2) < min_v)
	{
		min_v = abs(sum1 - sum2);
	}
}

void select(int start)
{
	if (sunsu1.size() == n / 2)
	{
		calc();
		return;
	}

	for (int i = start; i <= n; i++)
	{
		sunsu1.push_back(i);
		select(i + 1);
		sunsu1.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	select(1);

	cout << min_v << "\n";
}