#include"bits/stdc++.h"
using namespace std;

int n;
vector<pair<int, string>>vec;
bool Compare(pair<int, string>a1, pair<int, string>a2)
{
	return a1.first < a2.first;
}
void Init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		string s; 
		cin >> a >> s;
		vec.push_back({ a,s });
	}
	stable_sort(vec.begin(), vec.end(), Compare);
	for (auto& element : vec)
	{
		cout << element.first << ' ' << element.second << '\n';
	}
}
int main()
{
	Init();

	return 0;
 }