#include"bits/stdc++.h"
using namespace  std;
#define IOS_BASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int n, m;

queue<int>que;
stack<int>stk;
vector<bool>vec;
void Init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (vec[i] == 1)continue;
		else stk.push(num);
	}
	while (!stk.empty())
	{
		que.push(stk.top());
		stk.pop();
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		que.push(num);
		cout << que.front() << ' ';
		que.pop();
	}
}
int main()
{
	IOS_BASE;
	Init();
	return 0;
}