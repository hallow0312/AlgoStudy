#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
#define LL long long
const LL MAX = 15000007;
const LL MOD = 1e9 + 7;
int n, m; bitset<MAX + 1> s;

void Init()
{
    
    cin >> n >> m;
    int x = min(n, m);
    LL result = 1;
    for (LL i = 2; i <= x; i++)
    {
        if (s[i])continue;

        LL cnt = 0;
        LL prime = i;
        while (prime <= x)
        {
            cnt += (n / prime) * (m / prime);
            prime *= i;
        }
        LL base = i;
        while (cnt > 0)
        {
            if (cnt & 1)result = (result * base) % MOD;
            cnt >>= 1;
            base = (base * base) % MOD;
        }
        for (LL j = i * i; j <= x; j += i)
            s[j] = 1;
    }
    cout << result << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Init();

    return 0;
}