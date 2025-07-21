#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
map<char, char>cache =
{
	{')','('},
	{'}','{'},
	{']','['}
};
bool Find(string s)
{
	stack<char>stk;
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (c == '(' || c == '[' || c == '{')
			stk.push(c);
		else if (c == ')' || c == ']' || c == '}')
		{
			if (stk.empty() || stk.top() != cache[c])return false;
			else stk.pop();
			
		}
	}
	
	return stk.empty();
}
void Init()
{
	string s;

	getline(cin, s);
	while (s != ".")
	{
		if (s == ".")break;

		if (Find(s))cout << "yes" << '\n';
		else  cout << "no" <<'\n';
	
		getline(cin, s);
	}
	

}
int main()
{
	IOS_BASE;
	Init();
	return 0;
}