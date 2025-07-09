
#include <bits/stdc++.h>
using namespace std;
int n, m;


void Init()
{
	map<string,int>_map;
	vector<string>vec;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		vec.push_back(s);
		_map[s] = i;
	}
	string s;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (s[0] >= 65 && s[0] <= 90)
		{
			cout << _map[s] << '\n';
		}
		else
		{
			cout << vec[stoi(s)-1] << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	Init();
	return 0;
}
