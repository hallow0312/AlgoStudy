#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int n;
deque<int>deq;
void Test(int num)
{
	int  x = 0;
	switch (num)
	{
	case 1:
		
		cin >> x;
		deq.push_front(x);
		break;
	case 2:
		
		cin >>x;
		deq.push_back(x);
		break;
	case 3:
		if (deq.empty())cout << -1 << '\n';
		else
		{
			cout << deq.front() << '\n';
			deq.pop_front();
		}
		break;
	case 4:
		if (deq.empty())cout << -1 << '\n';
		else
		{
			cout << deq.back() << '\n';
			deq.pop_back();
		}
		break;
	case 5:
		cout << deq.size() << '\n';
		break;
	case 6:
		if (deq.empty())cout << 1 << '\n';
		else cout << 0 << '\n';
		break;
	case 7:
		if (deq.empty())cout << -1 << '\n';
		else
			cout << deq.front() << '\n';
		break;
	case 8:
		if (deq.empty())cout << -1 << '\n';
		else
			cout << deq.back() << '\n';
		break;
	}
}
void Init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		Test(m);
	}
}
int main()
{
	IOS_BASE;
	Init();
	return 0;
}