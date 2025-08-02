#include <bits/stdc++.h>
using namespace std;

#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1000000001
#define SIZE 12

int n;
int oper[4];
int buffer[SIZE];
int minResult, maxResult;

void Answer(int num, int cur)
{
    if (cur == n)
    {
        minResult = min(minResult, num);
        maxResult = max(maxResult, num);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (oper[i] <= 0) continue;

        oper[i]--;
        int result = 0;

        switch (i)
        {
        case 0: result = num + buffer[cur]; break;
        case 1: result = num - buffer[cur]; break;
        case 2: result = num * buffer[cur]; break;
        case 3:
            if (buffer[cur] == 0)
            {
                oper[i]++;
                continue;
            }
            result = num / buffer[cur]; 
            break;
        }

        Answer(result, cur + 1);
        oper[i]++;
    }
}

void Init()
{
    minResult = INF;
    maxResult = -INF;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> buffer[i];
    for (int i = 0; i < 4; i++)
        cin >> oper[i];

    Answer(buffer[0], 1);

    cout << maxResult << '\n';
    cout << minResult << '\n';
}

int main()
{
    IOS_BASE
        Init();
    return 0;
}
