#include<iostream>
#include<algorithm>
#include<vector>
#include <cassert>
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define LL long long 
int n, b;
vector<LL>vec;
bool Counting(LL num)
{
	LL tmp = 0;
	for (const auto& index : vec)
	{
		if (index > num)
			tmp += (index - num);
	}
	return tmp >= b;
}
void CustomBinary()
{
	LL left = 1;
	LL right = vec.back();
	LL middle;
	LL cache = 0;
	while (left <= right)
	{

		middle = (left + right) / 2;
		if (Counting(middle))
		{
			cache = middle;
			left = middle + 1;
		}
		else right = middle - 1;

	}
	cout << cache << '\n';
}
void Init()
{
	cin >> n >> b;
	LL a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	CustomBinary();
}
int main()
{
	IOS_BASE
		Init();
	return 0;
}