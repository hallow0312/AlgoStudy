#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
queue<int>que;
int n;
void Test()
{
	while (que.size() > 1)
	{
		que.pop();
		if (que.size() <= 1)break;

		int num = que.front();
		que.push(num);

		que.pop();
	}
}

void Init()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		que.push(i);
	}

	Test();
	cout << que.front() << '\n';

}

int main()
{
	IOS_BASE;
	Init();
	return 0;
}