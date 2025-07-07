#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

multimap<int, int> num_map;
vector<int> arr;

int n, m;

void input_nums();
void print_nums();

int main()
{
	input_nums();
	print_nums();
}

void input_nums()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		auto iter = num_map.find(input);
		if (iter == num_map.end())
		{
			num_map.insert(make_pair(input, 1));
		}
		else
		{
			iter->second++;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}
}

void print_nums()
{
	for (int i = 0; i < m; i++)
	{
		auto iter = num_map.find(arr[i]);
		if (iter == num_map.end())
		{
			cout << "0 ";
		}
		else
		{
			cout << iter->second << " ";
		}
	}
}