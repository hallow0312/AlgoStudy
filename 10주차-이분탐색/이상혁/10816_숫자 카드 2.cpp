#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;

unordered_map<int, int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (arr.find(temp) != arr.end())
		{
			arr[temp]++;
			continue;
		}

		arr[temp] = 1;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;

		if (arr.find(temp) != arr.end())
		{
			cout << arr[temp] << " ";
			continue;
		}

		cout << "0 ";
	}
}