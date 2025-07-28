#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int  n;


void  Init()
{
	stack<int>s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (k == 0)s.pop();
		else s.push(k);
	}
	int sum = 0;
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum << '\n';
}
int main()
{
	IOS_BASE;
	Init();

	return 0;
}