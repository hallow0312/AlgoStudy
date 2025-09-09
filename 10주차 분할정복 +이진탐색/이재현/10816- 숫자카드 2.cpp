#include<iostream>
#include<algorithm>
#include<vector>
#include <cassert>
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define LL long long 
int n, m;
vector<LL>vec; 

void Init()
{
	cin >> n;
	LL a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		cout << upper_bound(vec.begin(), vec.end(), a)
			- lower_bound(vec.begin(), vec.end(), a) << ' ';
	}
}
int main()
{
	IOS_BASE
	Init();
	return 0;
}