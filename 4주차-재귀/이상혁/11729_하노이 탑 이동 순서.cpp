#include <iostream>
#include <cmath>
using namespace std;

int n;

void tower(int size, int start, int end, int namuzi)
{
	if (size == 1)
	{
		cout << start << " " << end << "\n";
		return;
	}

	tower(size - 1, start, namuzi, end);
	cout << start << " " << end << "\n";
	tower(size - 1, namuzi, end, start);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	cout << (int)pow(2, n) - 1 << "\n";

	tower(n, 1, 3, 2);
}