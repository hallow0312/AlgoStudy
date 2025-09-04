#include <iostream>
#include <vector>
using namespace std;

int n, m, k;

vector<vector<int>> arr1, arr2;

int multi(int x, int y, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr1[x][i] * arr2[i][y];
	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		vector<int> temp;

		for (int j = 0; j < m; j++)
		{
			int value;
			cin >> value;
			temp.push_back(value);
		}

		arr1.push_back(temp);
	}

	cin >> m >> k;

	for (int i = 0; i < m; i++)
	{
		vector<int> temp;

		for (int j = 0; j < k; j++)
		{
			int value;
			cin >> value;
			temp.push_back(value);
		}

		arr2.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << multi(i, j, m) << " ";
		}

		cout << "\n";
	}
}