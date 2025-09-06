#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define LL long long 
int a, b, c;
bool IsEven(int num){ return num % 2 == 0; }
LL Answer(int x, int count, int divide)
{
	if (count == 0)return 1;
	if (count == 1)return x % divide;

	LL half = Answer(x, count / 2, divide);
	LL result = 1LL* (half * half) % divide;
	
	if (!IsEven(count))
		result = 1LL * (result * x) % divide;
	
	return result;
}
void Init()
{
	cin >> a >> b >> c;
	cout<<Answer(a, b, c)<<'\n';
}
int main()
{
	IOS_BASE
		Init();
	return 0;
}