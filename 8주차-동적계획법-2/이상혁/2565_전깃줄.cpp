#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[501] = {};

vector<pair<int, int>> wires;

int find(int target)
{
	if (target >= wires.size())
	{
		return 0;
	}

	if (arr[target] != 0)
	{
		return arr[target];
	}

	int temp = 1;

	for (int i = target + 1; i < wires.size(); i++)
	{
		if (wires[target].second < wires[i].second)
		{
			temp = max(temp, find(i) + 1);
		}
	}

	arr[target] = temp;

	return temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		wires.push_back(temp);
	}

	sort(wires.begin(), wires.end());

	int temp = find(0);

	for (int i = 1; i < n; i++)
	{
		temp = max(temp, find(i));
	}

	cout << n - temp << "\n";
}