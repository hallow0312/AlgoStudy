#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int  n;

bool Answer(string letter)
{
	stack<char>s;
	for (int i = 0; i<letter.length(); i++)
	{
		if (letter[i] == '(')
		{
			s.push(letter[i]);
		}
		else if (letter[i] == ')')
		{
			if (s.empty())return false;
			s.pop();
		}
	}
	return s.empty();
}
void  Init()
{
	cin >> n;
	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (Answer(temp))cout << "YES" << '\n';
		else  cout << "NO" << '\n';
	}

}
int main()
{
	IOS_BASE;
	Init();

	return 0;
}