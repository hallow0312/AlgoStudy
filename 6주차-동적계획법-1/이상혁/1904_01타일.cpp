#include <iostream>
using namespace std;

int n;

int arr[1000000] = { 1,2, };

int find_num(int target)
{
	for (int i = 2; i < target; i++)
	{
		arr[i] = (arr[i - 2] + arr[i - 1]) % 15746;
	}

	return arr[target - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	cout << find_num(n) << "\n";
}