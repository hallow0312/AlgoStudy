#include"bits/stdc++.h"
using namespace std;
vector<pair<int, int>> v;
int n;
bool Compare(pair<int, int>num1, pair<int, int>num2)
{
	  if (num1.second == num2.second) {
        return num1.first < num2.first;
    }
    else {
        return num1.second < num2.second;
    }
}
void Init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end(),Compare);

	for (int i = 0; i < n; i++)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}
int main() {
	Init();
	return 0;
}