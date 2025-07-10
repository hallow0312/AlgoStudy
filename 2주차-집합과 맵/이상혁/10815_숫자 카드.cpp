#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> input;
vector<int> arr;

void input_nums();
void find_nums();

int main()
{
	input_nums();
	find_nums();
}

void input_nums()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		input.insert(make_pair(temp, temp));
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
}

void find_nums()
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (input.count(arr[i]) > 0)
		{
			cout << "1 ";
		}
		else
		{
			cout << "0 ";
		}
	}
}