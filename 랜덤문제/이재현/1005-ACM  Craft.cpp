#include <iostream>
#include <cstring>
#define LL long long 
using namespace std;

LL m, n;

void Init()
{
    cin >> m >> n;

    LL layer = (min(m, n) - 1) / 2;
    LL cnt = layer * 4;
    LL re_m = m - layer * 2;
    LL re_n = n - layer * 2;
    LL x = 1 + layer;
    LL y = 1 + layer;

    if (re_m == 1 && re_n == 1) {}
    else if (re_m == 1)  y += (re_n - 1);
    else if (re_n == 1)
    {
        cnt += 1;
        x += (re_m - 1);
    }
    else if (re_m == 2) {

        cnt += 2;
        x++;
    }
    else if (re_n == 2) {

        cnt += 3;
        x++;
    }

    cout << cnt << '\n';
    cout << x << ' ' << y << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Init();
    return 0;
}
