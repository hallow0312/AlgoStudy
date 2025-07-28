#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define SIZE 21
int num;
int Dynamic[SIZE] = { 0, };

int Fibonacci(int n)
{
	if (n <= 0)
	{
		return Dynamic[n] = 0;
	}
	if (n <= 1)
	{
		return Dynamic[n] = 1;
	}

	if (Dynamic[n] != 0)
		return Dynamic[n];
	Dynamic[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
	return Dynamic[n];
}

void Init()
{
	cin >> num;
	cout << Fibonacci(num);
}

int  main()
{
	Init();
	return 0;
}