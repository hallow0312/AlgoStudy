#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DIVIDE  1000000007
#define SIZE  4000000 
#define LL long long 
LL Dynamic[SIZE];
int n, k;
bool IsEven(int num){ return num % 2 == 0; }
LL Factorial(int x)
{
	if (x <= 1)return 1;
	if (Dynamic[x] != 0)return Dynamic[x]%DIVIDE;

	return Dynamic[x] = (Factorial(x - 1) * x)%DIVIDE;
}
LL CustomPow(LL x, LL e)
{
	if (e == 0) return 1;
	if (e == 1) return x % DIVIDE;

	LL tmp = CustomPow(x, e / 2);
	tmp = tmp * tmp % DIVIDE;

	if (e % 2 == 1) tmp = tmp * x % DIVIDE;

	return tmp;
}
void Answer()
{
	LL a = Factorial(n);
	LL b = Factorial(k) * Factorial(n - k) % DIVIDE;

	LL result = (a * CustomPow(b, DIVIDE - 2)) % DIVIDE;
	cout << result << '\n';
}
void Init()
{
	memset(Dynamic, 0, sizeof(Dynamic));
	cin >> n >> k;
	Answer();
}
int main()
{
	IOS_BASE
	Init();
	return 0;
}