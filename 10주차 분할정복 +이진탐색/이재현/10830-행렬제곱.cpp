#include<iostream>
#include <memory.h>
using namespace std;
#define SIZE 5
#define DIVIDE 1000
#define LL long long

LL n, b;
LL buffer[SIZE][SIZE];
LL Identity[SIZE][SIZE];


void Multiple(LL result[SIZE][SIZE], LL buffer1[SIZE][SIZE], LL buffer2[SIZE][SIZE])
{
    LL temp[SIZE][SIZE] = { 0 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                temp[i][j] = (temp[i][j] + (buffer1[i][k] * buffer2[k][j]) % DIVIDE) % DIVIDE;
            }
        }
    }
    memcpy(result, temp, sizeof(temp)); 
}


void Solve()
{
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            LL temp[SIZE][SIZE];
            Multiple(temp, Identity, buffer);
            memcpy(Identity, temp, sizeof(temp));
        }

        LL temp[SIZE][SIZE];
        Multiple(temp, buffer, buffer);
        memcpy(buffer, temp, sizeof(temp));

        b /= 2;
    }

   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Identity[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Init()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> buffer[i][j];
        }
        Identity[i][i] = 1;
    }
    Solve();
}

int main()
{
    Init();
    return 0;
}
