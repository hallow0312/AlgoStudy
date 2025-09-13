#include<iostream>
#include<algorithm>
#include<vector>
#include <cassert>
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n, b;
vector<int>vec;

void Init()
{
	cin >> n;
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		cin >> a;
		cout<< binary_search(vec.begin(), vec.end(), a) <<'\n';
	}

}
int main()
{
	IOS_BASE
	Init();
	return 0;
}