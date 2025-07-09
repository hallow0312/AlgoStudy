#include<bits/stdc++.h>
using namespace std;
int n, m;
int index;
void  Init()
{
	index = 0;
	set<string>_set;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		_set.insert(s);
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if (_set.find(s) == _set.end())continue;
		index++;
	}
	cout << index << '\n';
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	Init();
	return 0;
}