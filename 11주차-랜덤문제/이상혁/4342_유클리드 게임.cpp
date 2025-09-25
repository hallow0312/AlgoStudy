#include <iostream>
using namespace std;

long long a, b;

bool find_winner(long long a, long long b, bool donghyeok)
{
	if (a % b == 0)
	{
		return donghyeok;
	}

	if (a >= 2 * b)
	{
		return donghyeok;
	}

	return find_winner(b, a % b, !donghyeok);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> a >> b;

		if (a == 0 && b == 0)
		{
			break;
		}

		if (a < b)
		{
			swap(a, b);
		}

		if (find_winner(a, b, true))
		{
			cout << "A wins\n";
		}
		else
		{
			cout << "B wins\n";
		}
	}
}