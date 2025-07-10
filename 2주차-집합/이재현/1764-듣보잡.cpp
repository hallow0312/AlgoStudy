#include"bits/stdc++.h"
using namespace std;
int n, m, index;
vector<string> v1;
vector<string> v2;
vector<string> ans;
void Answer()
{
	set<string> set1(v1.begin(), v1.end());
	set<string> set2(v2.begin(), v2.end());


	for (const string& s : set1)
	{
		if (set2.find(s) != set2.end())
			ans.push_back(s);
	}

	sort(ans.begin(), ans.end());


	cout << ans.size() << '\n';
	for (const string& s : ans)
		cout << s << '\n';
}
void Init()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v1.push_back(s);
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		v2.push_back(s);
	}
	Answer();

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Init();
	return 0;
}