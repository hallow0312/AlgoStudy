#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> arr;

int value = 0;

void bs(int start, int end)
{
	if (start > end)
	{
		return;
	}

	int mid = (start + end) / 2;
	long long sum = 0;

	for (int i = 0; i < n; i++)
	{
		int temp = arr[i] - mid;

		if (temp > 0)
		{
			sum += temp;
		}
	}

	if (sum >= m)
	{
		value = max(value, mid);
		bs(mid + 1, end);
	}
	else
	{
		bs(start, mid - 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int max_value = INT32_MIN;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);

		max_value = max(max_value, temp);
	}

	bs(0, max_value);

	cout << value << "\n";
}