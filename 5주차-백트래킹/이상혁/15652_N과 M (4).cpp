#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> arr;

void select(int start)
{
	if (arr.size() == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i <= n; i++)
	{
		arr.push_back(i);
		select(i);
		arr.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	select(1);
}