#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<long long> arr;

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
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		long long temp;
		cin >> temp;

		if (binary_search(arr.begin(), arr.end(), temp))
		{
			cout << "1\n";
			continue;
		}

		cout << "0\n";
	}
}