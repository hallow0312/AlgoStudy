#include"bits/stdc++.h"
using namespace  std;
int n, k;
vector<int>vec;
bool Compare(int a, int b)
{
	return a > b;
}
void Init()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end(), Compare);
	cout << vec[k - 1] << '\n';
}
int main()
{
	Init();

	return 0;
}