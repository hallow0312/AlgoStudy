#include<bits/stdc++.h>
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int n, cnt;
#define SIZE 16
int buffer[SIZE];
int ABS(int num)
{
    return num >= 0 ? num : -num;
}
bool Check(int row, int col)
{
    for (int i = 1; i <= row; i++)
    {
        if (buffer[i] == col || ABS(buffer[i] - col) == ABS(i - row))
            return false;
    }
    return true;
}
void NQueen(int k)
{
    if (k == n+1)
    {
        cnt++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (Check(k,i))
        {
            buffer[k] = i;
            NQueen(k + 1);
            buffer[k] = 0;
        }
    }

}

void Init()
{
    cnt = 0;
    memset(buffer, 0, sizeof(buffer));
    cin >> n;
    NQueen(1);
    cout << cnt << '\n';
}

int main()
{
    IOS_BASE
    Init();

    return 0;
}
