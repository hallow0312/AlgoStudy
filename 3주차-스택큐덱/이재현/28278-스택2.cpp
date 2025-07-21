#include"bits/stdc++.h"
using namespace std;
int n, m;
stack<int>s;
void Answer()
{
	cin >> m;
	int x;
	switch (m)
	{
	case  1:
		cin >> x;
		s.push(x);
		break;
	case 2:
		if (!s.empty())
		{
			cout << s.top()<<'\n';
			s.pop();
		}
		else  cout <<  -1 << '\n';
		break;
	case 3:
		cout << s.size() << '\n';
		break;
	case 4:
		if (s.empty())cout << 1 << '\n';
		else cout << 0 << '\n';
		break;
	case 5:
		if (!s.empty())cout << s.top() << '\n';
		else cout << -1 << '\n';
		break;
	}
}
void  Init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Answer();
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Init();
}