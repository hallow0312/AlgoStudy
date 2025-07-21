#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
queue<int>que;
int n;
void Test(string s)
{
	if (s == "push")
	{
		int m;
		cin >> m;
		que.push(m);
	}
	else if (s == "pop")
	{
		if (que.empty())cout << -1 << '\n';
		else
		{
			int num = que.front();
			cout << num << '\n';
			que.pop();
		}
	}
	else if (s == "size")
	{
		cout << que.size() << '\n';
	}
	else if (s == "empty")
	{
		if (que.empty())cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	else if (s == "front")
	{
		if (que.empty())cout << -1 << '\n';
		else cout << que.front() << '\n';
	}
	else  if (s == "back")
	{
		if (que.empty())cout << -1 << '\n';
		else  cout << que.back() << '\n';
	}
}

void Init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		Test(s);
	}
}

int main()
{
	IOS_BASE;
	Init();
	return 0;
}