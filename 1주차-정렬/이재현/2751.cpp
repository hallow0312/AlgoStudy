#include"bits/stdc++.h"
using namespace std;
#define SIZE 1000001
int buffer[SIZE];
int  n;
void Sorting()
{
	sort(buffer, buffer + n);

}
void Init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> buffer[i];
	}
	Sorting();
	for (int i = 0; i < n; i++)
	{
		cout << buffer[i] << '\n';
	}
}
int main()
{
	Init();

	return 0;
}