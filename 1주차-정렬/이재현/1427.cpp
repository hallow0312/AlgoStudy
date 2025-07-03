#include"bits/stdc++.h"
using namespace std;
vector<int>vec;
bool Compare(int a, int b)
{
	return a > b;
}
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		int a = (int)s[i];
		vec.push_back(a);

	}

	sort(vec.begin(), vec.end(), Compare);
	for (int i = 0; i < vec.size(); i++)
	{
		s[i] = vec[i];
	}
	cout << s;
	return 0;
}