#include <iostream>
#include <algorithm>
using namespace std;

void input_nums(int& n, int*& arr);

void print_nums(int n, int* arr);

int main()
{
	int n;
	int* arr;

	input_nums(n, arr);

	sort(arr, arr + n);

	print_nums(n, arr);
}

void input_nums(int& n, int*& arr)
{
	cin >> n;

	arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void print_nums(int n, int* arr)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n"; // '\n' 사용 이유: endl보다 성능적으로 좋다고 들은 적 있음
	}
}