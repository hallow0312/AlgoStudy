#include <iostream>
using namespace std;

int n;
long long fac = 1;

void facto()
{
	for (int i = 0; i < n; i++)
	{
		fac *= i + 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	facto();

	cout << fac << "\n";
}