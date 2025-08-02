#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> arr;

void select(vector<int> slt, int idx)
{
	if (slt.size() == m)
	{
		for (int i = 0; i < slt.size(); i++)
		{
			cout << slt[i] << " ";
		}
		cout << "\n";
		return;
	}

	if (idx >= arr.size())
	{
		return;
	}

	vector<int> temp = slt;
	temp.push_back(arr[idx]);

	select(temp, idx + 1);
	select(slt, idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		arr.push_back(i + 1);
	}

	vector<int> slt1, slt2;
	slt1.push_back(arr[0]);
	select(slt1, 1);
	select(slt2, 1);
}