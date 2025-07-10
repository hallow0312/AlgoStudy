#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

map<string, string> eng_map;
map<string, string> num_map;

int n, m;

void input_poketmon();

bool check_int(const string& check);

int main()
{
	input_poketmon();
}

void input_poketmon()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		eng_map.insert(make_pair(name, to_string(i + 1)));
		num_map.insert(make_pair(to_string(i + 1), name));
	}
	for (int i = 0; i < m; i++)
	{
		string input;
		cin >> input;
		if (check_int(input))
		{
			cout << num_map.find(input)->second << "\n";
		}
		else
		{
			cout << eng_map.find(input)->second << "\n";
		}
	}
}

bool check_int(const string& check)
{
	for (int i = 0; i < check.size(); i++)
	{
		if (!isdigit(check[i]))
		{
			return false;
		}
	}
	return true;
}