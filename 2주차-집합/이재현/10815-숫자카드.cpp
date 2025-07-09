#include<bits/stdc++.h>
using namespace std;
#define SIZE 500001
int n, m;

void  Init()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<int>vec;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}
	cin >> m;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < m; i++)
	{
		int  a;
		cin >> a;
		if (binary_search(vec.begin(), vec.end(), a))
		{
			cout << 1 << ' ';
		}
		else cout << 0 << ' ';
	}
}
int main()
{
	Init();
	return 0;
}
