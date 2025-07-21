#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
stack<int>stk;
queue<int>que;
int n;


void Wait(int num)
{
	stk.push(num);
}
void Line(int num)
{
	que.push(num);
}
void Init()
{
	cin >> n;
	int cookie = 1;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		Line(m);
	}
		
	while(!que.empty())
	{
		if (que.front() == cookie) {
			que.pop();
			cookie++;
		}
		else {
			stk.push(que.front());
			que.pop();
		}

		
		while (!stk.empty() && stk.top() == cookie) {
			stk.pop();
			cookie++;
		}
	}
	while (!stk.empty())
	{
		if (stk.top() == cookie)
		{
			stk.pop();
			cookie++;
		}
		else
			break;
	}
	if (stk.empty())cout << "Nice" << '\n';
	else  cout << "Sad" << '\n';
}
int main()
{
	IOS_BASE;
	Init();
	return 0;
}