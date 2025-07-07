#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> d_arr;
unordered_map<string, int> b_map;
vector<string> dbj_arr;

int n, m;

void input_dbj();
void find_dbj();
void print_dbj();

int main()
{
	input_dbj();
	find_dbj();
	sort(dbj_arr.begin(), dbj_arr.end());
	print_dbj();
}

void input_dbj()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		d_arr.push_back(name);
	}
	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> name;
		b_map.insert(make_pair(name, 1));
	}
}

void find_dbj()
{
	for (int i = 0; i < d_arr.size(); i++)
	{
		if (b_map.find(d_arr[i]) != b_map.end())
		{
			dbj_arr.push_back(d_arr[i]);
		}
	}
}

void print_dbj()
{
	int dbj_count = dbj_arr.size();
	cout << dbj_count << "\n";
	for (int i = 0; i < dbj_count; i++)
	{
		cout << dbj_arr[i] << "\n";
	}
}