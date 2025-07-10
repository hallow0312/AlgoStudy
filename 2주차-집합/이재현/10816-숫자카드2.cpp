#include"bits/stdc++.h"
using namespace std;
vector<int>vec;
int n, m;
vector<int>ans;
int FindCount(int num)
{
	return upper_bound(vec.begin(), vec.end(), num)
		- lower_bound(vec.begin(), vec.end(), num);
}
void Init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		ans.push_back(FindCount(num));
	}
	for (int num : ans)
	{
		cout << num << ' ';
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Init();

	return 0;
}