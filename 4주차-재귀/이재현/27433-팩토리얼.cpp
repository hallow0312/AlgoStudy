#include"bits/stdc++.h"
using namespace std;
#define LL long long int 
int num;
LL Factorial(int n)
{
	if (n == 0)return  1;
	
	
	return n * Factorial(n-1);

}
void Init()
{
	cin >> num;
	cout << Factorial(num) << '\n';
}

int  main()
{
	Init();
	return 0;
}