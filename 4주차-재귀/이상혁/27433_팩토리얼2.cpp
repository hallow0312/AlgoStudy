#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long fac = 1;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		fac *= i + 1;
	}

	cout << fac << "\n";
}