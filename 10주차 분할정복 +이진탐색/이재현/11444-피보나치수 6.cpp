#include<iostream>
#include<map>
using namespace std;
#define DIVIDE 1000000007
#define LL long long 
LL n;
map<LL, LL>cache; 
LL Fibonacci(LL num);
bool IsEven(LL num) { return num % 2 == 0; }
LL Even(LL num)
{
    if (cache.count(num))return cache[num];

    return cache[num] = (Fibonacci(num / 2) * ((2 * (Fibonacci(num / 2 - 1)) + Fibonacci(num / 2)))) % DIVIDE;
}
LL ODD(LL num)
{
    if (cache.count(num))return cache[num];

    return cache[num] = ((Fibonacci(num / 2 + 1) * Fibonacci(num / 2 + 1) + (Fibonacci(num / 2) * Fibonacci(num / 2))) % DIVIDE);
}
LL Fibonacci(LL num)
{
    if (cache.count(num)) return cache[num];

   
    return cache[num] = IsEven(num) ? Even(num) : ODD(num);
}

void Init()
{
    cache[0] = 0;
    cache[1] = 1;
    cin >> n;
    cout << Fibonacci(n) << '\n';
}

int main()
{
    Init();
    return 0;
}
