#include"bits/stdc++.h"
using namespace std;
int n, m;
set<int>s1;
set<int>s2;
void Answer()
{
	int sum = 0;
	for (int num : s1)
	{
		if (s2.find(num) != s2.end())continue;
		sum++;
	}
	for (int num : s2)
	{
		if (s1.find(num) != s1.end())continue;
		sum++;
	}
	cout << sum << '\n';
}
void Init()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		s1.insert(num);
	}
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		s2.insert(num);
	}
	Answer();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Init();

	return 0;
}