#include"bits/stdc++.h"
using namespace std;
vector<pair<int, int>> v;
int n;
void Init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}
int main() {
	Init();
	return 0;
}