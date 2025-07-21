#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
queue<int>que;
int n, k;
void Test()
{
	int temp = 0;

	vector<int>vec;
	while (!que.empty())
	{
		temp++;
		if (temp % k == 0)
		{
			vec.push_back(que.front());
			que.pop();
			
		}
		else
		{

			que.push(que.front());
			que.pop();
		}
	}
	cout << '<';
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
		if (i != vec.size() - 1)cout << ", ";
	}
	cout << '>';
}

void Init()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		que.push(i);
	}
	Test();
	
	

}

int main()
{
	IOS_BASE;
	Init();
	return 0;
}