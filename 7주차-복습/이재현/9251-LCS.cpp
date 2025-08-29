#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SIZE 1001
int n, Dynamic[SIZE][SIZE];
string a, b;

int Answer()
{
	for (int i = 1; i <= a.length(); i++)
	{
		for (int j = 1; j <= b.length(); j++)
		{
			if (a[i - 1] == b[j - 1])Dynamic[i][j] = Dynamic[i - 1][j - 1] + 1;
			else Dynamic[i][j] = std::max(Dynamic[i - 1][j], Dynamic[i][j - 1]);
		}
	}
	return Dynamic[a.length()][b.length()];
}
void Init()
{
	cin >> a >> b;
	memset(Dynamic, 0, sizeof(Dynamic));
	cout<<Answer();
}
int main()
{
	IOS_BASE
	Init();
}