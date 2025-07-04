#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int* arr;

void input_info();

int main()
{
	input_info();

	sort(arr, arr + n, greater<>());

	cout << arr[k - 1];
}

void input_info()
{
	cin >> n >> k;

	arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}