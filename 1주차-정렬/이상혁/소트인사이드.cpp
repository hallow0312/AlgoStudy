#include <iostream>
#include <algorithm>
using namespace std;

char* arr;

int main()
{
	string temp;
	cin >> temp;

	arr = new char[temp.size()];

	for (int i = 0; i < temp.size(); i++)
	{
		arr[i] = temp[i];
	}

	sort(arr, arr + temp.size(), greater<>());

	for (int i = 0; i < temp.size(); i++)
	{
		cout << arr[i];
	}
}