#include<bits/stdc++.h>
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int num;

void Hanoi(int num, int start, int middle, int end)
{
    if (num == 1)
    {
        cout << start << " " << end << '\n';
        return;
    }
    Hanoi(num - 1,start, end ,middle );
    cout << start << " " << end << '\n';
    Hanoi(num - 1, middle, start, end);
        
}
void Init()
{
    cin >> num;
    int result = 1;
    for (int i = 0; i < num; i++)
    {
        result *= 2;
    }
    cout << result - 1 << '\n';
    Hanoi(num, 1, 2, 3);
}

int main()
{
    IOS_BASE
        Init();

    return 0;
}
