#include"bits/stdc++.h"
using namespace  std;
#define IOS_BASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int n;
struct Node
{
	int x, y;
};
deque<Node>deq;
int ABS(int num)
{
	return (num >= 0) ? num : -num;
}
void Bubble()
{

	while (!deq.empty())
	{
		Node node = deq.front();
		cout << node.y << ' ';
		deq.pop_front();
		if (deq.empty())break;

		int cur = node.x;
		if (cur >= 0)
		{
			for (int i = 0; i < cur-1; i++)
			{
				deq.push_back(deq.front());
				deq.pop_front();
			}
		}
		else
		{
			int num = ABS(cur);
			for (int i = 0; i < num; i++)
			{
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}
	}
}
void Init()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int  a;
		cin >> a;
		deq.push_back({ a,i });
	}
	Bubble();
}
int main()
{
	IOS_BASE;
	Init();
	return 0;
}