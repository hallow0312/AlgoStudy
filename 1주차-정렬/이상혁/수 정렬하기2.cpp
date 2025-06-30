#include <iostream>
#include <algorithm>
using namespace std;

int n;
int* arr;

void input_nums();

void print_nums();

int main()
{
	input_nums();

	sort(arr, arr + n);

	print_nums();
}

void input_nums()
{
	cin >> n;

	arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void print_nums()
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}
}