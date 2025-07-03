#include"bits/stdc++.h"
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt[10001] = { 0 };
	int n, count;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> count;
		cnt[count]++;
	}

	for (int i = 1; i < 10001; i++)
		for (int j = 0; j < cnt[i]; j++)
			cout << i << '\n';

	return 0;
}