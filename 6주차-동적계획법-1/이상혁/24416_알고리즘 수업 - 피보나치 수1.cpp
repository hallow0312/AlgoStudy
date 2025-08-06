#include <iostream>
using namespace std;

int n;

int count1 = 0, count2 = 0;

int arr[41] = { 0,1,1,0 };

int fibo1(int target)
{
	if (target == 1 || target == 2)
	{
		count1++;

		return 1;
	}

	return fibo1(target - 2) + fibo1(target - 1);
}

int fibo2(int target)
{
	for (int i = 3; i <= target; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
		count2++;
	}

	return arr[target];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	fibo1(n);
	fibo2(n);

	cout << count1 << " " << count2 << "\n";
}