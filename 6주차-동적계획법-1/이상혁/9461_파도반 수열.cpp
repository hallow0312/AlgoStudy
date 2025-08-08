#include <iostream>
using namespace std;

int n;

long long arr[101] = { 0,1,1,1,0 };

long long wave(int target)
{
	for (int i = 3; i <= target; i++)
	{
		arr[i] = arr[i - 3] + arr[i - 2];
	}

	return arr[target];
}

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
		cout << wave(temp) << "\n";
	}
}