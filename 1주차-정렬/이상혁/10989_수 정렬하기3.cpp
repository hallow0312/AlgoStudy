#include <iostream>
using namespace std;

int n;
int arr[10001] = {};

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
		arr[temp]++;
	}

	for (int i = 0; i <= 10000; i++)
	{
		if (arr[i] > 0)
		{
			for (int j = 0; j < arr[i]; j++)
			{
				cout << i << "\n";
			}
		}
	}
}