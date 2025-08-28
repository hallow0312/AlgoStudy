#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int Dynamic[101][100001];
int  n, k;
struct Bag
{
	int w, v;
};
vector<Bag>vec;
int Answer()
{
	for (int i = 1; i <= n; i++)
	{
		int w = vec[i-1].w;
		int v = vec[i-1].v;
		for (int j = 1; j <= k; j++)
		{
			if (w > j)Dynamic[i][j] = Dynamic[i - 1][j];
			else Dynamic[i][j] = max(v + Dynamic[i - 1][j - w], Dynamic[i - 1][j]);
		}
	}
	return Dynamic[n][k];
}
void Init()
{
	cin >> n >> k;
	memset(Dynamic, 0, sizeof(Dynamic));
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		vec.push_back({ w,v });
	}
	cout << Answer() << '\n';
}
int main()
{
	IOS_BASE
	Init();
}