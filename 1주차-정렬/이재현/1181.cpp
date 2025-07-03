#include"bits/stdc++.h"
using namespace std;
int n;
#define SIZE 20001
vector<string> vec;
bool Compare(string a, string b)
{
	if (a.length() == b.length())return a < b;
	
	return a.length() < b.length();
}
void Init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		vec.push_back(s);
	}
	sort(vec.begin(), vec.end(), Compare);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (auto element : vec)
	{
		cout << element << '\n';
	}
}
int main()
{
	Init();
	return 0;
}