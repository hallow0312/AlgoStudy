
#include <bits/stdc++.h>
using namespace std;



void Init()
{
	int n;
	set<string, greater<string>> answer;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s, m;
		cin >> s >> m;
		if (m == "enter")
		{
			answer.insert(s);
		}
		else if (m == "leave")
		{
			if (answer.find(s) != answer.end())
			{
				answer.erase(answer.find(s));
			}
		}
	}
	for (auto a : answer)
	{
		cout << a << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	Init();
	return 0;
}
