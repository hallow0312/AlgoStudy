#include <iostream>
using namespace std;

int fibo(int num)
{
	if (num == 0)
	{
		return 0;
	}
	else if (num == 1)
	{
		return 1;
	}
	
	return fibo(num - 2) + fibo(num - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	cout << fibo(n) << "\n";
}