#include"bits/stdc++.h"
using namespace std;
set<string>set1;

void Init()
{
	string s;
	string temp;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		temp = "";
		for (int j = i; j < s.length(); j++)
		{
			temp +=s[j];
			
			set1.insert(temp);
		}
	}
	cout << set1.size() << '\n';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	Init();
	return 0;
}
