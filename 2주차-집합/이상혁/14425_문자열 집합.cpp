#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_multimap<string, string> input;
vector<string> arr;

void input_words();
void find_words();

int main()
{
	input_words();
	find_words();
}

void input_words()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 0; i < m; i++)
	{
		string temp;
		cin >> temp;
		input.insert(make_pair(temp, temp));
	}
}

void find_words()
{
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += input.count(arr[i]);
	}
	cout << sum;
}