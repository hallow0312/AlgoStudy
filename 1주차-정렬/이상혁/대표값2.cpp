#include <iostream>
#include <algorithm>
using namespace std;

void input_nums(int* arr);

int avg_nums(int* arr);
int middle_nums(int* arr);

int main()
{
	int arr[5];

	input_nums(arr);

	sort(arr, arr + 5);

	cout << avg_nums(arr) << "\n" << middle_nums(arr);
}

void input_nums(int* arr)
{
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
}

int avg_nums(int* arr)
{
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		sum += arr[i];
	}

	return sum / 5;
}

int middle_nums(int* arr)
{
	return arr[2];
}