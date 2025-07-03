#include"bits/stdc++.h"
using namespace std;
#define SIZE 5
int buffer[SIZE];

void Sorting()
{
	sort(buffer, buffer + SIZE);

}
void Init()
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		cin >> buffer[i];
		sum += buffer[i];
	}
	cout << sum / SIZE << '\n';
	Sorting();
	cout << buffer[2] << '\n';
}
int main()
{
	Init();

	return 0;
}