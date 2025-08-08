#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n;

int max_value = INT32_MIN;

int arr[100000] = {};
unordered_map<string, int> map;

void make_small_data()
{
	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			string key = to_string(arr[j]) + " " + to_string(arr[j + i]);
			int value = arr[j] + arr[j + i];

			if (i == 0)
			{
				value = arr[j];
			}

			map[key] = value;
		}
	}
}

int find_target(int start, int end)
{
	string key = to_string(arr[start]) + " " + to_string(arr[end]);
	int mid = (start + end) / 2;

	if (map.find(key) != map.end())
	{
		return map[key];
	}

	map[key] = find_target(start, mid) + find_target(mid + 1, end);
	
	return map[key];
}

void find_max()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int temp = find_target(i, j);

			if (temp > max_value)
			{
				max_value = temp;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	make_small_data();

	find_max();

	cout << max_value << "\n";
}