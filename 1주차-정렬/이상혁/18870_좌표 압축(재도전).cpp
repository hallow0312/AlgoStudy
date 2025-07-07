#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> input_arr;
vector<int> result_arr;

void input_nums();
void print_nums();

int main()
{
	input_nums();
	sort(result_arr.begin(), result_arr.end());
	result_arr.erase(unique(result_arr.begin(), result_arr.end()), result_arr.end());
	print_nums();
}

void input_nums()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		input_arr.push_back(temp);
		result_arr.push_back(temp);
	}
}

void print_nums()
{
	for (int i = 0; i < n; i++)
	{
		auto iter = lower_bound(result_arr.begin(), result_arr.end(), input_arr[i]);
		cout << iter - result_arr.begin() << " ";
	}
}