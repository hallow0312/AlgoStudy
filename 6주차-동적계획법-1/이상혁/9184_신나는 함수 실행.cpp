#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> dp;

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	if (a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}

	string as = to_string(a);
	string bs = to_string(b);
	string cs = to_string(c);
	string key = as + " " + bs + " " + cs;

	if (dp.find(key) != dp.end())
	{
		return dp[key];
	}

	if (a < b && b < c)
	{
		dp[key] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

		return dp[key];
	}

	dp[key] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

	return dp[key];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
}