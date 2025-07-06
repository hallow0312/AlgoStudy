#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, int> a_map;
unordered_map<int, int> b_map;

vector<int> a_arr;
vector<int> b_arr;

int n, m;
int a_minus_b = 0;
int b_minus_a = 0;

void input_set();
void set_minus();

int main()
{
	input_set();
	set_minus();
	cout << (a_arr.size() - a_minus_b) + (b_arr.size() - b_minus_a);
}

void input_set()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int element;
		cin >> element;
		a_arr.push_back(element);
		a_map.insert(make_pair(element, element));
	}
	for (int i = 0; i < m; i++)
	{
		int element;
		cin >> element;
		b_arr.push_back(element);
		b_map.insert(make_pair(element, element));
	}
}

void set_minus()
{
	for (int i = 0; i < a_arr.size(); i++)
	{
		if (b_map.find(a_arr[i]) != b_map.end())
		{
			b_minus_a++;
		}
	}
	for (int i = 0; i < b_arr.size(); i++)
	{
		if (a_map.find(b_arr[i]) != a_map.end())
		{
			a_minus_b++;
		}
	}
}